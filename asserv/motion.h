#ifndef _MOTION_H_
#define _MOTION_H_

//Deinition des structures
typedef struct {
    float x; // mètre
    float y;
    float t;//radian
} Position;

typedef struct { // vitesse angulaire du robot
    float v; //m/s
    float vt; // rad/s
} Speed;

typedef struct {
    float a; //m/s2
    float at;
    float v_vt;// en rad*m/s2
} Acceleration;



void motion_init();
void motion_pos(Position pos);
void motion_speed(Speed pos);

void motion_step(int tics_g,int tics_d, float *cmd_g, float *cmd_d); // avancement de l'asserv
#endif

