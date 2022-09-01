#include "simfiles.h"
#include "waprint.h"
#include "items.h"

int main() {
  int buffer_len = 20;
  struct buffer_wave buffer[buffer_len];
  char file_sim_1[] = "sim_1";
  int file_shift = 0;
  double time_step = 1;
  double global_time  = 0;
  double simulation_time = 222;
  clearFile(file_sim_1);

  struct vpulse vp1;
  while (global_time < simulation_time) {
    if (file_shift == buffer_len) {
      writeBufferToFile(file_sim_1, buffer, buffer_len);
      file_shift = 0;
    } else {
      vp1.setV(buffer, global_time, time_step, file_shift);
      file_shift++;
    }
    global_time = global_time + time_step;
  }
  int x_n = 200, x_range = 25, y_n = 30, y_range = 1, read_file_shift = 0;
  readBufferFromFile(file_sim_1, buffer, read_file_shift, buffer_len);
  waveformPrint(buffer, buffer_len, y_n, y_range);

  return 0;
}
