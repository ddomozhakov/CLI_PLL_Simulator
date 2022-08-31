#ifndef H_WAPRINT
#define H_WAPRINT

#include <cmath>
#include <iostream>

struct field {
  double x;
  double y;
};

void waveformPrint(struct field *fi, int x_n, int x_range, int y_n, int y_range);
void screenInit(int **screen, int y_n, int x_n);
void screenSet(int **screen, struct field *fi, int y_n, int x_n, int y_range);
void screenPrint(int **screen, int y_n, int x_n);

#endif  //WAPRINT

