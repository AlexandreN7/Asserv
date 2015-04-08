#include "config.h"
#include "odo.h"
#include "asserv.h"
#include "math.h"
#include "motion.h"// pour avoir les structures
#include <stdio.h>
#include "asserv.h"
//Variable globale//
Speed speed_rampe = {0,0};

Error error_speed_v = {0,0,0};
Error error_speed_vt = {0,0,0};

PID pid_speed_v = {1,1,1};
PID pid_speed_vt = {1,1,1};

void speed_asserv_step(Speed speed_current,Acceleration acc_current, float *cmg, float *cmd) {
    float E_v;
    float E_vt;

    float C_v;
    float C_vt;

    E_v=speed_current.v-speed_rampe.v;
    E_vt=speed_current.vt-speed_rampe.vt;

    error_speed_v.Ed= E_v-error_speed_v.Ep; // écriture des erreurs v
    error_speed_v.Ei= error_speed_v.Ep+E_v;
    error_speed_v.Ep= E_v;

    error_speed_vt.Ed= E_vt-error_speed_vt.Ep; // écriture des erreurs vt
    error_speed_vt.Ei= error_speed_vt.Ep+E_vt;
    error_speed_vt.Ep= E_vt;

    //application de la correction
    C_v = error_speed_v.Ed*pid_speed_v.Kd + error_speed_v.Ei*pid_speed_v.Ki -error_speed_v.Ed*pid_speed_v.Kd;
    C_vt = error_speed_vt.Ed*pid_speed_vt.Kd + error_speed_vt.Ei*pid_speed_vt.Ki -error_speed_vt.Ed*pid_speed_vt.Kd;

    *cmg = (2*period*C_v-C_vt*spacing*period)/2;
    *cmd = (2*period*C_v+C_vt*spacing*period)/2;

    printf("commande droite : %f", *cmd);
    printf("commande gauche : %f", *cmg);

}

Speed rampe(Speed speed_current,Speed speed_consigne,Acceleration acc_current){
    Speed speed_rampe = {0,0};
    speed_rampe.v= DEFAULT_CONSTRAINT_A_MAX*period + speed_current.v; // génération du premier échelon de l'asserv
    speed_rampe.vt= DEFAULT_CONSTRAINT_AT_MAX*period + speed_current.vt;
return speed_rampe;
}
