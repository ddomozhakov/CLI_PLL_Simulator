#ifndef H_ITEMS
#define H_ITEMS

#include "simfiles.h"

void vpulse_setV(struct vpulse  &vp, struct buffer_wave *buffer, double global_time, double time_step, int wave_shift);
void cap_setV(struct cap &c, struct buffer_wave *buffer, double global_time, double time_step, int wave_shift);

struct vpulse {
  double local_time = 0;
  int state = 1;
  double v_hi = 1;
  double v_low = 0;
  double period = 50;
};

struct cap {
  double local_time = 0;
  double current_voltage = 0;
  double input_voltage = 0;
  double resistance = 5;
  double capacitance = 5;
  double charge = 0;
};

#endif  //ITEMS
