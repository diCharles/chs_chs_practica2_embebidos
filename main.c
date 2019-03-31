/*
 * main
 *
 *  Created on: 27/03/2019
 *      Author: Diego Charles & Ruben Charles
 */
/* Brief
 *  Here the layer sytemControl is called
 * */
/**/
/*
 * About layers:
 * current layer: main
 * APP: systemControl
 * MAL: buttons
 * HAl:
 * */
/*About firmware and hardware on this layer:
 * Interrupt base priority level 10
 * IRQs used: PORTA, PORTB, PORTC
 * Pins used:
 * Peripherals used:
 * */

#include "MK64F12.h"

#include "systemControl.h"
#include "global.h"

int main(void) {



    init_system();
    while(1)
    {
    	execute_current_system_application();
    }
    return 0 ;
}
