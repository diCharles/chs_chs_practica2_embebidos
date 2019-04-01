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
		uint8_t string2[]="b1->pressed"; /*! String to be printed in the LCD*/
		LCD_nokia_goto_xy(3,3); /*! It establishes the position to print the messages in the LCD*/
		LCD_nokia_send_string(&string2[0]); /*! It print a string stored in an array*/
		 botones_g->b1=NOT_PRESSED;
		 red_anode_intensity+=1;
		 extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
	}
	if(PRESSED == botones_g->b2)
		{
			uint8_t string3[]="b2->pressed"; /*! String to be printed in the LCD*/
			LCD_nokia_goto_xy(3,4); /*! It establishes the position to print the messages in the LCD*/
			LCD_nokia_send_string(&string3[0]); /*! It print a string stored in an array*/
			 botones_g->b2=NOT_PRESSED;
			 green_anode_intensity+=1;
			 extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
		}
	if(PRESSED == botones_g->b3)
			{
				uint8_t string4[]="b2->pressed"; /*! String to be printed in the LCD*/
				LCD_nokia_goto_xy(3,5); /*! It establishes the position to print the messages in the LCD*/
				LCD_nokia_send_string(&string4[0]); /*! It print a string stored in an array*/
				 botones_g->b3=NOT_PRESSED;
				 blue_anode_intensity+=1;
				 extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
			}
}
