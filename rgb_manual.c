/*
 * rgb_manual.c
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */

#include "rgb_manual.h"
/*when called the application rgb_manual will be executed*/
void exe_rgb_manual(void)
{
	static uint8_t it_is_rgb_manual_init=FALSE;
	if(FALSE == it_is_rgb_manual_init)
	{

	}
	buttons_t * botones_g = get_buttons();

	uint8_t string1[]="APP MANUAL"; /*! String to be printed in the LCD*/


	LCD_nokia_goto_xy(0,0); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/
	if(PRESSED == botones_g->b1)
	{
		uint8_t string2[]="b1->pressed"; /*! String to be printed in the LCD*/
		LCD_nokia_goto_xy(3,3); /*! It establishes the position to print the messages in the LCD*/
		LCD_nokia_send_string(&string2[0]); /*! It print a string stored in an array*/
		 botones_g->b1=NOT_PRESSED;
	}
}
