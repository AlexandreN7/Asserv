#include <stdio.h>
#include <stdlib.h>
#include "motion.h"
#include "odo.h"
#include "asserv.h"

void moteur(int*,int*,float*,float*);
FILE* fichier = NULL;

int main(void) {
    int tg=0,td=0,i= 0;
    float cg=0,cd=0;
    Speed test = {1,0};


    fichier = fopen("data.txt", "w+");
    motion_init(); // initialisation odo,aserv
    motion_speed(test);
    for(i=0;i<2000;i++) {
        moteur(&tg,&td,&cg,&cd);
        motion_step(tg,td,&cg,&cd);
    }
    fclose(fichier);
    return 0;
}

void moteur(int *tg,int *td,float *cg,float *cd) {// modélisation d'un moteur linéaire E=kW
    *tg =*tg+(*cg);
    *td =*td+(*cd);

    printf("tics_g générés %d ; tics_d générés %d  \n",*tg,*td);
    printf("\n");
}
