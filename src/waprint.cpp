#include "waprint.h"


void waveformPrint(struct buffer_wave *fi, int x_n, int y_n, int y_range) {
  int **screen = (int **) malloc(y_n * sizeof(int *));
  for (int i = 0; i < y_n; i++) {
    screen[i] = (int *) malloc(x_n * sizeof(int));
  }
  screenInit(screen, y_n, x_n);
  screenSet(screen, fi, y_n, x_n, y_range);
  screenPrint(screen, y_n, x_n);
  for (int i = 0; i < y_n; i++) {
    free(screen[i]);
  }
  free(screen);
}

void screenInit(int **screen, int y_n, int x_n) {
  for (int i = 0; i < y_n; i++) {
    for (int j = 0; j < x_n; j++) {
      screen[i][j] = 0;
    }
  }
}

void screenSet(int **screen, struct buffer_wave *fi, int y_n, int x_n, int y_range) {
  for (int i = 0; i < x_n; i++) {
    if (((int) ((fi[i].y) * 0.5 * (y_n / y_range)) < y_n) && ((int) ((fi[i].y) * 0.5 * (y_n / y_range)) >= 0)) {
      screen[(int) ((fi[i].y) * 0.5 * (y_n / y_range))][i] = 1;
    }
  }
}

void screenPrint(int **screen, int y_n, int x_n) {
  for (int i = y_n - 1; i >= 0; i--) {
    for (int j = 0; j < x_n; j++) {
      if (screen[i][j] == 1) {
        printw("@");
      } else {
        printw(".");
      }
    }
    printw("\n");
  }
}

void fieldSet(struct buffer_wave *fi, int x_n, int x_range, int y_n, int y_range) {
  double x_step = double(x_range) / double(x_n);
  for (int i = 0; i < x_n; i++) {
    fi[i].x = x_step * i;
    fi[i].y = sin(pow(fi[i].x, 1.25)) * 0.5 * (y_n / y_range) + y_n / 2;
  }
}

void xyPrint(struct buffer_wave *fi, int x_n) {
  for (int i = 0; i < x_n; i++) {
    printw("X %lf Y %lf\n", fi[i].x, fi[i].y);
  }
}
