/*
 * systemControl.h
 *
 *  Created on: 27/03/2019
 *      Author: Diego Charles & Ruben Charles
 */

/* Brief
 * this layer manages global behavior of practica 2
 * helps to select beetween menus
 * */
/*
 * About layers:
 * current layer: systemControl
 * APP: systemControl
 * MAL: buttons
 * */
/*About firmware and hardware on this layer:
 * IRQs used:
 * Pins used:
 * Peripherals used:
 * */
#ifndef SYSTEMCONTROL_H_
#define SYSTEMCONTROL_H_
#define TOTAL_OF_APLICATIONS 6U

#include "buttons.h"
typedef void (*fptr)();

/* initialize system */
void init_system();

/* when this fuction is called the current application is going to be executed*/
void  execute_current_system_application();

/* this fuction will decide to change the current system application,
 * it will return system aplication to execute*/
fptr change_system_application();

/* shows wallpaper and helps to select an application and returns application to be executed*/
void system_menu();

#endif /* SYSTEMCONTROL_H_ */
