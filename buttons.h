/*
 * buttons.h
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_
#include "MK64F12.h"

typedef struct
{
	uint16_t b0:1 ;
	uint16_t b1:1;
	uint16_t b2:1;
	uint16_t b3:1;
	uint16_t b4:1;
	uint16_t b5:1;
	uint16_t b6:1;
	uint16_t sw2:1;
	uint16_t sw3:1;

}buttons_t;

typedef  buttons_t * buttonsPtr;
/*returns buttons_g structure declare in c file*/
buttonsPtr  get_buttons();

#endif /* BUTTONS_H_ */
