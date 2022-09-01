#include "simfiles.h"
#include "waprint.h"
#include "items.h"

int main() {
  int buffer_len = 20;
  struct buffer_wave buffer[buffer_len];
  char file_sim_1[] = "sim_1";
  int file_shift = 0;
  double time_step = 1;
  double global_time = 0;
  double simulation_time = 65;
  clearFile(file_sim_1);

  struct vpulse vp1;
  while (global_time < simulation_time) {
    printf("FI_SH %d BU_LE %d GL_TI %lf\n", file_shift, buffer_len, global_time);

    if (file_shift == buffer_len) {
      writeBufferToFile(file_sim_1, buffer, buffer_len);
      file_shift = 0;
   //   printf("\nTS %d\n", file_shift);
    } else {
      vp1.setV(buffer, global_time, time_step, file_shift);
      file_shift++;
    }
    global_time = global_time + time_step;
  }
  for (int i = 0; i < buffer_len; i++) {
    printf("X%lf, Y%lf\n", buffer[i].x, buffer[i].y);
  }
  return 0;
}