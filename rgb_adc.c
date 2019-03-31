/*
 * rgb_adc.c
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */


#include "rgb_adc.h"

/*when called the application rgb_adc will be executed*/
void exe_rgb_adc(void)
{
	uint8_t string1[]="APP ADC RGB"; /*! String to be printed in the LCD*/


		LCD_nokia_goto_xy(0,0); /*! It establishes the position to print the messages in the LCD*/
		LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/
}
