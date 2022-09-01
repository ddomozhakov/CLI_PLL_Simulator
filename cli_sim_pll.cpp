#include "simfiles.h"
#include "waprint.h"
#include "items.h"

int main() {
  int buffer_len = 250, y_n = 40, y_range = 1, read_file_shift = 0;
  struct buffer_wave buffer[buffer_len];
  struct buffer_wave integr[buffer_len];
  char file_sim_1[] = "sim_1";
  char file_sim_2[] = "sim_2";
  int file_shift = 0;
  double time_step = 0.5;
  double global_time  = 0;
  double simulation_time = 450;
  clearFile(file_sim_1);
  clearFile(file_sim_2);

  struct vpulse vp1;
  struct cap cap1;
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

  for (int i = 0; i < buffer_len; i++) {
    integr[i].y = (integr[i].y + 0.1) * 1.5;
  }

  //readBufferFromFile(file_sim_1, buffer, read_file_shift, buffer_len);
  //readBufferFromFile(file_sim_2, integr, read_file_shift, buffer_len);
  //waveformPrint(buffer, buffer_len, y_n, y_range);
  waveformPrint(integr, buffer_len, y_n, y_range+0.1);


  return 0;
}
