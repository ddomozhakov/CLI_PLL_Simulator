#include "simfiles.h"

int main() {
  struct buffer_wave buffer[10];
  char file_dest1[] = "sim_1";
  char file_dest2[] = "sim_2";
  int read_file_shift = 0, n_lens = 5;
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
