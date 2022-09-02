#ifndef H_SIMFILES
#define H_SIMFILES

#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_STRING 25

struct buffer_wave {
  double x;
  double y;
};

void readBufferFromFile(char *file_dest, struct buffer_wave *buffer, int read_file_shift, int n_lens);
void writeBufferToFile(char *file_dest, struct buffer_wave *buffer, int n_lens);
void clearFile(char *file_dest);


#endif//SIM_FILES