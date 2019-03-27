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
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"

#include "buttons.h"
#include "systemControl.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    PRINTF("Hello World\n");
    /* SYSTEM INITIALIZATION*/
    init_system();
    while(1)
    {
    	execute_current_system_application();
    }
    return 0 ;
}
