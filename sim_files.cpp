#include "sim_files.h"

void readBufferFromFile(char *file_dest, struct buffer_wave * buffer, int read_file_shift, int n_lens) {
  FILE *file_pointer;
  file_pointer = fopen(file_dest, "r");
  char buffer_string[MAX_FILE_STRING];
  for (int i = 0; i < read_file_shift; i++) {
    fgets(buffer_string, MAX_FILE_STRING, file_pointer);
  }
  for (int i = 0; i < n_lens; i++) {
    fgets(buffer_string, MAX_FILE_STRING, file_pointer);
    char *buffer_string_split = strtok(buffer_string, " ");
    buffer[i].x = atol(buffer_string_split);
    buffer_string_split = strtok(buffer_string, " ");
    buffer[i].x = atol(buffer_string_split);
  }
  fclose(file_pointer);
}

void writeBufferToFile(char *file_dest, struct buffer_wave * buffer, int n_lens) {
  FILE *file_pointer;
  file_pointer = fopen(file_dest, "a");
  for (int i = 0; i < n_lens; i++) {
    fprintf(file_pointer, "%lf %lf\n", buffer[i].x, buffer[i].y);
  }
  fclose(file_pointer);
}

void clearFile(char *file_dest) {
  FILE *file_pointer;
  file_pointer = fopen(file_dest, "w");
  fclose(file_pointer);
}



