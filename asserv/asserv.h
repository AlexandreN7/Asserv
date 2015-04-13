#include "motion.h"
#ifndef _ASSERV_H_
#define _ASSERV_H_


typedef struct {
    float Ep; // erreur proportionnelle
    float Ed; // dérivée de l'erreur
    float Ei;//somme des erreurs
} Error;

typedef struct {
    float Kp; // erreur proportionnelle
    float Kd; // dérivée de l'erreur
    float Ki;//somme des erreurs
} PID;

void speed_asserv_step(Speed, Acceleration,float *,float*);
void asserv_init();
void init_rampe(Speed,Speed,Acceleration);
void rampe(Speed);

#endif
