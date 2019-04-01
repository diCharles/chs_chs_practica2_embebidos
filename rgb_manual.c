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
	static uint8_t red_anode_intensity=0;
	static uint8_t green_anode_intensity=0;
	static uint8_t blue_anode_intensity=0;
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
		uint8_t string2[]="b1->blue++"; /*! String to be printed in the LCD*/
		LCD_nokia_goto_xy(3,2); /*! It establishes the position to print the messages in the LCD*/
		LCD_nokia_send_string(&string2[0]); /*! It print a string stored in an array*/

		blue_anode_intensity+=20;

		extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
		botones_g->b1=NOT_PRESSED;
	}
	if(PRESSED == botones_g->b2)
	{
		uint8_t string2[]="b2->blue--"; /*! String to be printed in the LCD*/
		LCD_nokia_goto_xy(3,2); /*! It establishes the position to print the messages in the LCD*/
		LCD_nokia_send_string(&string2[0]); /*! It print a string stored in an array*/

		if(20 >= blue_anode_intensity)
		{
			blue_anode_intensity=0;
		}
		else
		{
			blue_anode_intensity-=20;
		}
		extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
		botones_g->b2=NOT_PRESSED;
	}
	if(PRESSED == botones_g->b3)
	{
		uint8_t string3[]="b3->red++"; /*! String to be printed in the LCD*/
		LCD_nokia_goto_xy(3,3); /*! It establishes the position to print the messages in the LCD*/
		LCD_nokia_send_string(&string3[0]); /*! It print a string stored in an array*/

		red_anode_intensity+=20;
		extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
		botones_g->b3=NOT_PRESSED;
	}
	if(PRESSED == botones_g->b4)
	{
		uint8_t string4[]="b4->red--"; /*! String to be printed in the LCD*/
		LCD_nokia_goto_xy(3,3); /*! It establishes the position to print the messages in the LCD*/
		LCD_nokia_send_string(&string4[0]); /*! It print a string stored in an array*/
		;
		if(20 >= red_anode_intensity)
		{
			red_anode_intensity=0;
		}
		else
		{
			red_anode_intensity-=20;
		}

		extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
		botones_g->b4=NOT_PRESSED;
	}
	if(PRESSED == botones_g->b5)
	{
		uint8_t string5[]="b5->green++"; /*! String to be printed in the LCD*/
		LCD_nokia_goto_xy(3,4); /*! It establishes the position to print the messages in the LCD*/
		LCD_nokia_send_string(&string5[0]); /*! It print a string stored in an array*/

		green_anode_intensity+=20;
		extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
		botones_g->b5=NOT_PRESSED;
	}
	if(PRESSED == botones_g->b6)
	{
		uint8_t string6[]="b6->green--"; /*! String to be printed in the LCD*/
		LCD_nokia_goto_xy(3,4); /*! It establishes the position to print the messages in the LCD*/
		LCD_nokia_send_string(&string6[0]); /*! It print a string stored in an array*/
		if(20 >= green_anode_intensity)
		{
			green_anode_intensity=0;
		}
		else
		{
			green_anode_intensity-=20;
		}

		extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
		botones_g->b6=NOT_PRESSED;
	}
}
