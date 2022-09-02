#include "simfiles.h"
#include "waprint.h"
//#include <iostream>

void fieldSet(struct field *fi, int x_n, int x_range, int y_n, int y_range);
void xyPrint(struct field *fi, int x_n);

int main() {
  int x_n = 200, x_range = 25, y_n = 30, y_range = 1;
  struct field waveform[x_n];
  fieldSet(waveform, x_n, x_range, y_n, y_range);

  xyPrint(waveform, x_n);

  waveformPrint(waveform, x_n, x_range, y_n, y_range);
  return 0;
}

void fieldSet(struct field *fi, int x_n, int x_range, int y_n, int y_range) {
  double x_step = double(x_range) / double(x_n);
  for (int i = 0; i < x_n; i++) {
    fi[i].x = x_step * i;
    fi[i].y = sin(pow(fi[i].x, 1.25)) * 0.5 * (y_n / y_range) + y_n / 2;
  }
}

void xyPrint(struct field *fi, int x_n) {
  for (int i = 0; i < x_n; i++) {
    printf("X %lf Y %lf\n", fi[i].x, fi[i].y);
  }
}
