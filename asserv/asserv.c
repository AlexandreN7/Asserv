#include "config.h"
#include "odo.h"
#include "asserv.h"
#include "math.h"
#include "motion.h"// pour avoir les structures
#include <stdio.h>
#include "asserv.h"
//Variable globale//
Speed speed_rampe = {0,0};

void speed_asserv_step(Speed speed_current,Acceleration acc_current, float *cmg, float *cmd) {
    float E_v;
    float E_vt;
    E_v=speed_current.v-speed_rampe.v;
    E_vt=speed_current.vt-speed_rampe.vt;


}

Speed rampe(Speed speed_current,Speed speed_consigne,Acceleration acc_current){
    Speed speed_rampe = {0,0};
    speed_rampe.v= DEFAULT_CONSTRAINT_A_MAX*period + speed_current.v; // génération du premier échelon de l'asserv
    speed_rampe.vt= DEFAULT_CONSTRAINT_AT_MAX*period + speed_current.vt;
return speed_rampe;
}
