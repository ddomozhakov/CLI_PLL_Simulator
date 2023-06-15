#include "cli_sim_rc.h"

int main() {
  int buffer_len = 250, y_n = 40, y_range = 1, read_file_shift = 0,
      file_shift = 0, flag_wave = 0, counter = 0;
  buffer_wave buffer[buffer_len], integr[buffer_len];
  vpulse vp1;
  cap cap1;
  char file_sim_1[] = "sim_1", file_sim_2[] = "sim_2", key = 'm';
  double time_step = 0.5, global_time = 0, simulation_time = 256;
  vpulseInit(&vp1);
  capInit(&cap1);
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
        vpulseSetV(&vp1, buffer, global_time, time_step, file_shift);
        cap1.input_voltage = buffer[file_shift].y;
        capSetV(&cap1, integr, global_time, time_step, file_shift);
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
    switchOptions(key, &cap1, &vp1, &flag_wave);
    if (flag_wave == 1) {
      printw("Input signal\n");
      waveformPrint(buffer, buffer_len, y_n, y_range);
    } else if (flag_wave == 2) {
      printw("Output signal");
      printw("Perind = %.2lf, Capacitance = %.2lf, Resistance = %.2lf\n",
             vp1.period, cap1.capacitance, cap1.resistance);
      waveformPrint(integr, buffer_len, y_n, y_range + 0.1);
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

void switchOptions(char key, cap *cap, vpulse *vp, int *flag) {
  switch (key) {
    case 'a':
      vp->period = changeOptions(vp->period, 1);
      break;
    case 'z':
      vp->period = changeOptions(vp->period, 0);
      break;
    case 's':
      cap->capacitance = changeOptions(cap->capacitance, 1);
      break;
    case 'x':
      cap->capacitance = changeOptions(cap->capacitance, 0);
      break;
    case 'd':
      cap->resistance = changeOptions(cap->resistance, 1);
      break;
    case 'c':
      cap->resistance = changeOptions(cap->resistance, 0);
      break;
    case '1':
      *flag = 1;
      break;
    case '2':
      *flag = 2;
      break;
  }
}
