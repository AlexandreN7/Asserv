#include "config.h"
#include "motion.h"
#include "odo.h"
#include "asserv.h"

//initialiser l'asservissement
void motion_init() {
    Position pos_init = {0.0.0};
    
}

void motion_step(int tics_g, int tics_d, float *cmd_g, float *cmd_d) {
odo_step();
asserv_step();
}


