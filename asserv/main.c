#include <stdio.h>
#include <stdlib.h>
#include "motion.h"
#include "odo.h"

int main(void) {
    float tg,td;
    //float cg=0,cd=0;

    motion_init();
    tg=50000;
    td=100000;
    odo_step(tg,td);
    tg=100000;
    td=100000;
    odo_step(tg,td);
    tg=-150000;
    td=-200000;
    odo_step(tg,td);
    return 0;
}
