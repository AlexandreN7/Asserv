#ifndef _CONFIG_H_
#define _CONFIG_H_

// Dossier contenant les valeurs retenus pour l'asservissement
#define NULL 0
#define DEFAULT_CONSTRAINT_V_MAX {0.45, 0.7}
#define DEFAULT_CONSTRAINT_A_MAX {0.5, 1.4, 0.10}


#define DEFAULT_PERIOD 0.005 // période de rafraichissement de l'asserv

#define DEFAULT_STOP_DISTANCE 0.01

//coéfficient du PID

#define DEFAULT_PID_COEFS_DELTA {130,90,20000,0.5}
#define DEFAULT_PID_COEFS_ALPHA {10,5.5,30,0.5,0.9}

#endif //fin
