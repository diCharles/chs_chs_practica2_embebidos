/*
 * buttons.c
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */

#include "buttons.h"
/* initialize buttons and sws states as zero, meaning no one has been pressed*/
 static buttons_t buttons_g={0,0,0,0,0,0,0,0,0};

buttonsPtr get_buttons()
{
	buttonsPtr ptr=& buttons_g;
	return ( ptr);
}