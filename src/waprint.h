#ifndef H_WAPRINT
#define H_WAPRINT

#include "simfiles.h"
#include <cmath>
#include <iostream>
#include <ncurses.h>

void waveformPrint(struct buffer_wave *fi, int x_n, int y_n, int y_range);
void screenInit(int **screen, int y_n, int x_n);
void screenSet(int **screen, struct buffer_wave *fi, int y_n, int x_n, int y_range);
void screenPrint(int **screen, int y_n, int x_n);
void fieldSet(struct buffer_wave *fi, int x_n, int x_range, int y_n, int y_range);
void xyPrint(struct buffer_wave *fi, int x_n);

#endif//WAPRINT
