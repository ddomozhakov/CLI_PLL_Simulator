#include "items.h"

void vpulse::setV(struct buffer_wave * buffer, double global_time, double time_step, int wave_shift) {
  if ((state == 1) && (local_time > period/2)) {
    state = 0;
    local_time = 0;
  } else if ((state == 0) && (local_time > period/2)) {
    state = 1;
    local_time = 0;
  }
  buffer[wave_shift].x = global_time;
  buffer[wave_shift].y = state;
  local_time = local_time + time_step;
}


