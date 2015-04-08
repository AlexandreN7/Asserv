#include <stdio.h>
#include <stdlib.h>
#include "motion.h"
#include "odo.h"

int main(void) {
    int tg,td;
    float cg=0,cd=0;

    motion_init();
    tg=500;
    td=500;
    motion_step(tg,td,&cg,&cd);
    tg=1000;
    td=1000;
    motion_step(tg,td,&cg,&cd);
    tg=1500;
    td=1500;
    motion_step(tg,td,&cg,&cd);
    return 0;
}
