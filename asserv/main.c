#include <stdio.h>
#include <stdlib.h>
#include "motion.h"
#include "odo.h"
#include "asserv.h"

void moteur(int*,int*,float*,float*);

int main(void) {
    int tg,td,i = 0;
    float cg=0,cd=0;
    Speed test = {2,0};

    motion_init(); // initialisation odo,aserv
    motion_speed(test);
    for(i=0;i<1000;i++) {
        moteur(&tg,&td,&cg,&cd);
        motion_step(tg,td,&cg,&cd);
    }
    return 0;
}

void moteur(int *tg,int *td,float *cg,float *cd) {
    *tg = (10)*(*cg);
    *td = (10)*(*cd);

    printf("tics_g générés %d ; tics_d générés %d  \n",*tg,*td);
    printf("\n");
}
