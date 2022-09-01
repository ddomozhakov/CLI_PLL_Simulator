#ifndef H_ITEMS
#define H_ITEMS

#include <iostream>
#include "simfiles.h"
//#include <stdio.h>
//#include <stdlib.h>

struct vpulse {
  double local_time = 0;
  int state = 1;
  double v_hi = 1;
  double v_low = 0;
  double period = 20;
  void setV(struct buffer_wave * buffer, double global_time, double time_step, int wave_shift);
};

#endif  //ITEMS