#include "config.h"
#include "odo.h"
#include "asserv.h"
#include "math.h"
#include "motion.h"// pour avoir les structures
#include <stdio.h>
#include "asserv.h"
//Variable globale//
Speed speed_rampe;
Speed speed_goal;

Error error_speed_v = {0,0,0};
Error error_speed_vt = {0,0,0};

PID pid_speed_v = {10,5,0};
PID pid_speed_vt = {2,0,5};
extern FILE* fichier_v ;
extern FILE* fichier_vt ;
int asserv_done = 0;
float C_v=0,C_vt=0;

void asserv_init(){ // remise à zéro pour une nouvelle consigne
    speed_rampe.v=0;
    speed_rampe.vt=0;
    asserv_done = 0;
    C_v=0;
    C_vt=0;
    /*error_speed_v = {0,0,0};
    error_speed_vt = {0,0,0};*/
}


void speed_asserv_step(Speed speed_current,Acceleration acc_current, float *cmg, float *cmd) {
    float E_v,E_vt;


    E_v=speed_rampe.v-speed_current.v;
    E_vt=speed_rampe.vt-speed_current.vt;


if(E_v<speed_threshold && E_vt<speed_threshold){ // asserv_done = 1 si on a atteint la vitesse voulue
    asserv_done=1;
    printf("asserv terminée !");
    printf("\n");
}

    error_speed_v.Ed= E_v-error_speed_v.Ep; // écriture des erreurs v
    error_speed_v.Ei= error_speed_v.Ep+E_v;
    error_speed_v.Ep= E_v;

    error_speed_vt.Ed= E_vt-error_speed_vt.Ep; // écriture des erreurs vt
    error_speed_vt.Ei= error_speed_vt.Ep+E_vt;
    error_speed_vt.Ep= E_vt;

    //application de la correction
    C_v += error_speed_v.Ep*pid_speed_v.Kp + error_speed_v.Ei*pid_speed_v.Ki -error_speed_v.Ed*pid_speed_v.Kd;
    C_vt += error_speed_vt.Ep*pid_speed_vt.Kp + error_speed_vt.Ei*pid_speed_vt.Ki -error_speed_vt.Ed*pid_speed_vt.Kd;

    //*cmg = (2*period*C_v-C_vt*spacing*period)/2;
    //*cmd = (2*period*C_v+C_vt*spacing*period)/2;
    *cmg = C_v-C_vt;
    *cmd = C_v+C_vt;
    printf("ecart v : %f \n", E_v);
    printf("ecart vt : %f \n", E_vt);
    printf("\n");


    printf("C_v : %f \n", C_v);
    printf("C_vt: %f \n", C_vt);
    printf("\n");


    printf("commande droite : %f \n", *cmd);
    printf("commande gauche : %f \n", *cmg);
    printf("\n");
    fprintf(fichier_v, "%f %f \n ", speed_current.v,speed_rampe.v);
    fprintf(fichier_vt, "%f %f \n ", speed_current.vt,speed_rampe.vt);
    }



void rampe(Speed speed_current){


    if (speed_rampe.v<=speed_goal.v) { // on vérifie si on est sur la pente ou au plat de la rampe
        speed_rampe.v= speed_rampe.v + DEFAULT_CONSTRAINT_A_MAX*period; // génération de l'échelon suivant de l'asserv
    }
    else if (speed_rampe.v>speed_goal.v) {
        speed_rampe.v= speed_rampe.v - DEFAULT_CONSTRAINT_A_MAX*period; // génération de l'échelon suivant de l'asserv
    }

    if (speed_rampe.vt<=speed_goal.vt) { // on vérifie si on est sur la pente ou au plat de la rampe
        speed_rampe.vt= speed_rampe.vt + DEFAULT_CONSTRAINT_AT_MAX*period; // génération de l'échelon suivant de l'asserv
    }
    else if (speed_rampe.vt>speed_goal.vt) {
        speed_rampe.vt= speed_rampe.vt - DEFAULT_CONSTRAINT_AT_MAX*period; // génération de l'échelon suivant de l'asserv
    }
    printf("rampe v: %f \n", speed_rampe.v);
    printf("rampe vt : %f \n", speed_rampe.vt);
    printf("\n");

}

void init_rampe(Speed speed_current,Speed speed_consigne,Acceleration acc_current){
//    #speed_rampe.v= DEFAULT_CONSTRAINT_A_MAX*period + speed_current.v; // génération du premier échelon de l'asserv
  //  #speed_rampe.vt= DEFAULT_CONSTRAINT_AT_MAX*period + speed_current.vt;

    speed_goal.v=speed_consigne.v; // on fixe les objectifs
    speed_goal.vt=speed_consigne.vt;

    printf("speed_goal v : %f \n", speed_goal.v);
    printf("speed_goal vt: %f \n", speed_goal.vt);
    printf("\n");

}

