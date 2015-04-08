#include <stdio.h>
#include <stdlib.h>
#include "motion.h"
#include "odo.h"
#include "asserv.h"

int main(void) {
    int tg,td;
    float cg=0,cd=0;
    Speed test = {0.1,0};

    motion_init();
    motion_speed(test);
    tg=500;
    td=500;
    motion_step(tg,td,&cg,&cd);
    tg=1000;
    td=1000;
    motion_step(tg,td,&cg,&cd);
    tg=10;
    td=10;
    motion_step(tg,td,&cg,&cd);
    return 0;
}
