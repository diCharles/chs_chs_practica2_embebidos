/*
 * buttons.h
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "MK64F12.h"
#include "Bits.h"
#include "GPIO.h"
#include "NVIC.h"

/* struct for buttons */
/* any member could be modifyed by interrupts*/
/* specific pins are being used in buttons.c for buttons:
 *
 *  this is the specific pin map
 *  b0
 *  b1
 *  b2
 *  b3
 *  b4
 *  b5
 *  b6
 *  b7
 *  SW2
 *  SW3
 *  */
typedef struct
{
	volatile uint16_t b0:1 ;
	volatile uint16_t b1:1;
	volatile uint16_t b2:1;
	volatile uint16_t b3:1;
	volatile uint16_t b4:1;
	volatile uint16_t b5:1;
	volatile uint16_t b6:1;
	volatile uint16_t sw2:1;
	volatile uint16_t sw3:1;

}buttons_t;

typedef  buttons_t * buttonsPtr;
 typedef enum {NOT_PRESSED,PRESSED}button_state_t;
/*returns buttons_g structure declare in c file*/

buttonsPtr  get_buttons(void);
/* initialize specific pins for buttons*/
static void init_buttons(void);
/* determine wich button of a specific port triggered the interrupt of his corresponding port*/
 void determine_and_set_button_after_interrupt(void);


#endif /* BUTTONS_H_ */
