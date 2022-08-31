#include "waprint.h"

void waveformPrint(struct field *fi, int x_n, int x_range, int y_n, int y_range) {
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

void screenSet(int **screen, struct field *fi, int y_n, int x_n, int y_range) {
  for (int i = 0; i < x_n; i++) {
    if (((int) (fi[i].y / y_range) < y_n) && ((int) (fi[i].y / y_range) >= 0)) {
      screen[(int) (fi[i].y)][i] = 1;
    }
  }
}

void screenPrint(int **screen, int y_n, int x_n) {
  for (int i = y_n - 1; i >= 0; i--) {
    for (int j = 0; j < x_n; j++) {
      if (screen[i][j] == 1) {
        printf("@");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}
