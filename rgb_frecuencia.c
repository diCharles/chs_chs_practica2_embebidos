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
	static uint8_t it_it_frecuencia_init = FALSE;
	if(FALSE == it_it_frecuencia_init)
	{
		/* init flex timer module in input capture mode*/

		it_it_frecuencia_init=FALSE;
	}


	LCD_nokia_goto_xy(0,0); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/
	print_freq_read(46);
}
void print_freq_read(uint32_t frequency)
{
	uint8_t string2[]="frequency"; /*! String to be printed in the LCD*/

	uint32_t decenas= 0;
	uint32_t unidades=(frequency)%10;
	uint32_t decimal1=( (((uint32_t)(frequency*10))) )%10;
	uint32_t decimal2=( (((uint32_t)(frequency*100))) )%10;

	LCD_nokia_goto_xy(0,2); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string2[0]); /*! It print a string stored in an array*/
	LCD_nokia_goto_xy(25,3);
	LCD_nokia_send_char(decenas+48); /*! It prints a character*/
	LCD_nokia_send_char(unidades+48); /*! It prints a character*/
	LCD_nokia_send_char('.'); /*! It prints a character*/
	LCD_nokia_send_char(decimal1+48); /*! It prints a character*/
	LCD_nokia_send_char(decimal2+48); /*! It prints a character*/
}
