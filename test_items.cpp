#include "sim_files.h"
#include "waprint.h"

struct vpulse {
  double local_time = 0;
  int state = 1;
  double v_hi = 1;
  double v_low = 0;
  double period = 1e-9;
};


int main() {
  struct buffer_wave buffer[10];
  char file_sim_1[] = "sim_1";

  int read_file_shift = 0;



  readBufferFromFile(file_dest1, buffer, read_file_shift, n_lens);
  clearFile(file_dest2);
  writeBufferToFile(file_dest2, buffer, n_lens);
  struct buffer_wave buffer2[10];
  readBufferFromFile(file_dest2, buffer2, read_file_shift, n_lens);
  for (int j = 0; j < 5; j++) {
    printf("X %lf Y %lf\n", buffer2[j].x, buffer2[j].y);
  }
  return 0;
}

void vpulseInit() {

}
