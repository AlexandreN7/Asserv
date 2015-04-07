#include "config.h"
#include "motion.h"
#include "odo.h"
#include "asserv.h"

//initialiser l'asservissement
void motion_init() {
    //Position pos_init = {0.0.0};
    odo_init();
}

void motion_step(float tics_g,float tics_d, float *cmd_g, float *cmd_d) {
    odo_step(&tics_g,&tics_d);
    //asserv_step();
}


