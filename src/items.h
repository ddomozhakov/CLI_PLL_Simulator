#ifndef H_ITEMS
#define H_ITEMS

#include "simfiles.h"

typedef struct vpulse {
  double local_time;
  int state;
  double v_hi;
  double v_low;
  double period;
} vpulse;

typedef struct cap {
  double local_time;
  double current_voltage;
  double input_voltage;
  double resistance;
  double capacitance;
  double charge;
} cap;

void vpulse_setV(vpulse *vp, struct buffer_wave *buffer, double global_time, double time_step, int wave_shift);
void cap_setV(cap *c, struct buffer_wave *buffer, double global_time, double time_step, int wave_shift);
void cap_init(cap *c);
void vpulse_init(vpulse *vp);

#endif  //ITEMS
