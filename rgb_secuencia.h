/*
 * rgb_secuencia.h
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */

#ifndef RGB_SECUENCIA_H_
#define RGB_SECUENCIA_H_


#define PROGRAMABLE_COLORS 10U

#include "global.h"
/* pointer tpo buttons structure */

/*when called the application rgb_secuencia will be executed*/
void exe_rgb_secuencia(void);
/* evaluates button states and execute an action to their value*/
void determine_action(void);
/* enables user to program his own led secuence*/
void build_programable_sequence( void (*fptr_selected_color)(void ));
/* when called executes the sequence of extern rgb programed by user, the deletes her*/
void run_programmed_sequence(void);
#endif /* RGB_SECUENCIA_H_ */
