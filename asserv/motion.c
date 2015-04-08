#include "config.h"
#include "motion.h"
#include "odo.h"
#include "asserv.h"

extern Speed speed_current;
extern Acceleration acc_current;

//initialiser l'asservissement
void motion_init() {
    //Position pos_init = {0.0.0};
    odo_init();
}

void motion_step(int tics_g,int tics_d, float *cmd_g, float *cmd_d) {
    odo_step(tics_g,tics_d);
    //asserv_step();
}

void motion_speed(Speed speed) {
    rampe(speed_current,speed,acc_current);


}


