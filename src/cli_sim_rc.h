#ifndef H_CLI_SIM_RC
#define H_CLI_SIM_RC

#include <ncurses.h>

#include "items.h"
#include "simfiles.h"
#include "waprint.h"

double changeOptions(double val, int dir);
void switchOptions(char key, cap *cap, vpulse *vp, int *flag);

#endif  // CLI_SIM_RC
