/*
 * main
 *
 *  Created on: 27/03/2019
 *      Author: Diego Charles & Ruben Charles
 */
/* Brief
 *  Here the layer sytemControl is called
 * */
/*
 * About layers:
 * current layer: main
 * APP: systemControl
 * MAL: buttons
 * HAl:
 * */
/*About firmware and hardware on this layer:
 * IRQs used:
 * Pins used:
 * Peripherals used:
 * */

#include "MK64F12.h"

#include "systemControl.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */

    init_system();
    while(1)
    {
    	execute_current_system_application();
    }
    return 0 ;
}
