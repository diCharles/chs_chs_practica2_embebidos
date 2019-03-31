/*
 * rgb_frecuencia.c
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */


#include "rgb_secuencia.h"

/*when called the application rgb_frecuencia will be executed*/
void exe_rgb_frecuencia(void)
{
	uint8_t string1[]="FRECUENCIA"; /*! String to be printed in the LCD*/


	LCD_nokia_goto_xy(0,0); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/
}
