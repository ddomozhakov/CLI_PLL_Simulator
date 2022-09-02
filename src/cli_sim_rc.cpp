#include <ncurses.h>
#include "simfiles.h"
#include "waprint.h"
#include "items.h"

double changeOptions(double val, int dir);

int main() {
  int buffer_len = 250, y_n = 40, y_range = 1, read_file_shift = 0;
  struct buffer_wave buffer[buffer_len];
  struct buffer_wave integr[buffer_len];
  char file_sim_1[] = "sim_1";
  char file_sim_2[] = "sim_2";
  int file_shift = 0;
  double time_step = 0.5;
  double global_time;
  int flag_wave = 0;
  double simulation_time = 256;
  int counter = 0;

  struct vpulse vp1;
  struct cap cap1;

  char key;
  initscr();
  while (key != 'q') {
    key = getch();
    counter++;
    clear();
    noecho();
    for (int i = 0; i < buffer_len; i++) {
      integr[i].x = 0;
      buffer[i].x = 0;
      integr[i].y = 0;
      buffer[i].y = 0;
    }
    cap1.charge = 0;
    cap1.current_voltage = 0;
    vp1.local_time = 0;
    vp1.state = 1;
    nodelay(stdscr, FALSE);
    global_time = 0;
    file_shift = 0;
    clearFile(file_sim_1);
    clearFile(file_sim_2);
    while (global_time < simulation_time) {
      if (file_shift == buffer_len) {
        writeBufferToFile(file_sim_1, buffer, buffer_len);
        writeBufferToFile(file_sim_2, integr, buffer_len);
        file_shift = 0;
      } else {
        vp1.setV(buffer, global_time, time_step, file_shift);
        cap1.input_voltage = buffer[file_shift].y;
        cap1.setV(integr, global_time, time_step, file_shift);
        file_shift++;
      }
      global_time = global_time + time_step;
    }
    readBufferFromFile(file_sim_1, buffer, read_file_shift, buffer_len);
    readBufferFromFile(file_sim_2, integr, read_file_shift, buffer_len);
    for (int i = 0; i < buffer_len; i++) {
      integr[i].y = (integr[i].y + 0.1) * 1.5;
      buffer[i].y = (buffer[i].y + 0.1) * 1.5;
    }
    if (key == 'a') {
      vp1.period = changeOptions(vp1.period, 1);
    } else if (key == 'z') {
      vp1.period = changeOptions(vp1.period, 0);
    } else if (key == 's') {
      cap1.capacitance = changeOptions(cap1.capacitance, 1);
    } else if (key == 'x') {
      cap1.capacitance = changeOptions(cap1.capacitance, 0);
    } else if (key == 'd') {
      cap1.resistance = changeOptions(cap1.resistance, 1);
    } else if (key == 'c') {
      cap1.resistance = changeOptions(cap1.resistance, 0);
    } else if (key == '1') {
      flag_wave = 1;
    } else if (key == '2') {
      flag_wave = 2;
    }
    if (flag_wave == 1) {
      printw("Input signal\n");
      waveformPrint(buffer, buffer_len, y_n, y_range);
    } else if (flag_wave == 2) {
      printw("Output signal");
      printw("Perind = %.2lf, Capacitance = %.2lf, Resistance = %.2lf\n", vp1.period, cap1.capacitance, cap1.resistance);
      waveformPrint(integr, buffer_len, y_n, y_range+0.1);
    }
    refresh();
  }
  endwin();
  return 0;
}

double changeOptions(double val, int dir) {
  if (dir == 1) {
    if (val < 100) {
      val++;
    }
  } else if (dir == 0) {
    if (val > 1) {
      val--;
    }
  }
  return val;
}

