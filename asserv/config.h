#ifndef _CONFIG_H_
#define _CONFIG_H_

// Dossier contenant les valeurs retenus pour l'asservissement
#define NULL 0
#define DEFAULT_CONSTRAINT_V_MAX 0.45
#define DEFAULT_CONSTRAINT_VT_MAX 0.7
#define DEFAULT_CONSTRAINT_A_MAX 0.5
#define DEFAULT_CONSTRAINT_AT_MAX 0.5
#define DEFAULT_CONSTRAINT_VT_T_MAX 0.10

#define speed_threshold 0.05 // à ajuster au système, attention a ne pas être trop greedy

// Define Odométrie
#define DEFAULT_PERIOD 0.005 // période de rafraichissement de l'asserv
#define tic_by_meter 54640 // a adapter
#define meter_by_tic 0.000018302 // a adapter
#define spacing 0.2732 // en m à adapter
#define period 0.005
#define DEFAULT_STOP_DISTANCE 0.01
#define PI 3.1415
//coefficients du PID

#define DEFAULT_PID_COEFS_DELTA {130,90,20000,0.5}
#define DEFAULT_PID_COEFS_ALPHA {10,5.5,30,0.5,0.9}

#endif //fin
