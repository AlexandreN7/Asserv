#include "motion.h"
#ifndef _ASSERV_H_
#define _ASSERV_H_



void speed_asserv_step(Speed, Acceleration,float *,float*);
Speed rampe(Speed,Speed,Acceleration);

#endif
