/*
 * rgb_secuencia.c
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */


#include "rgb_secuencia.h"
/*when called the application rgb_secuencia will be executed*/

/* this pointer to structure bottons permits consult and  modify button bX and swx state*/
buttons_t * g_botones;
/* will remember how many colors are programmed*/
static uint8_t selected_colors = 0;
/* this pointer stores rgb color sequence programmed*/
static void (*g_ftpr_programmed_colors[PROGRAMABLE_COLORS])(void) = {0};



void exe_rgb_secuencia(void)
{


	static uint8_t it_is_rgb_secuencia_enabled = FALSE;
	if(FALSE == it_is_rgb_secuencia_enabled)
	{
		g_botones=get_buttons();
		it_is_rgb_secuencia_enabled=FALSE;

	}
	LCD_nokia_goto_xy(0,0); /*! It establishes the position to print the messages in the LCD*/
	uint8_t string1[]="SECUENCIA"; /*! String to be printed in the LCD*/
	LCD_nokia_goto_xy(0,0); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/

	determine_action();
}

void determine_action(void)
{
	LCD_nokia_goto_xy(0,3); /*! It establishes the position to print the messages in the LCD*/
	if(PRESSED == g_botones->b0)
	{
		/* DO NOTHING WHEN TTHIS BUTTON IS PRESSED*/

		g_botones->b0=NOT_PRESSED;/*clear button*/
	}
	/*selection of application to execute*/
	else if(PRESSED == g_botones->b1)
	{
		/* blue is selected, print on screen*/
		delay(10000);/* small of 100ms delay to avoid bounce*/
		build_programable_sequence( extern_rgb_blue);/* storages color to be printed user programmed sequence*/

		/* show to user that his color is stored, to be printed in the sequence*/
		uint8_t string1[]="B "; /*! String to be printed in the LCD*/

		LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/

		g_botones->b1=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == g_botones->b2)
	{
		/* red is selected, print on screen*/
		delay(10000);/* small of 100ms delay to avoid bounce*/
		build_programable_sequence( extern_rgb_red);/* storages color to be printed user programmed sequence*/

		/* show to user that his color is stored, to be printed in the sequence*/
		uint8_t string1[]="R "; /*! String to be printed in the LCD*/
		LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/

		g_botones->b2=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == g_botones->b3)
	{
		/*green  is selected, print on screen*/
		delay(10000);/* small of 100ms delay to avoid bounce*/
		build_programable_sequence( extern_rgb_green);/* storages color to be printed user programmed sequence*/

		/* show to user that his color is stored, to be printed in the sequence*/
		uint8_t string1[]="G "; /*! String to be printed in the LCD*/
		LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/

		g_botones->b3=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == g_botones->b4)
	{
		/*YELLOW  is selected, print on screen*/
		delay(10000);/* small of 100ms delay to avoid bounce*/
		build_programable_sequence( extern_rgb_yellow);/* storages color to be printed user programmed sequence*/

		/* show to user that his color is stored, to be printed in the sequence*/
		uint8_t string1[]="Y "; /*! String to be printed in the LCD*/
		LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/

		g_botones->b4=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == g_botones->b5)
	{

		/*PURPLE  is selected, print on screen*/
		delay(10000);/* small of 100ms delay to avoid bounce*/
		build_programable_sequence( extern_rgb_purple);/* storages color to be printed user programmed sequence*/

		/* show to user that his color is stored, to be printed in the sequence*/
		uint8_t string1[]="P "; /*! String to be printed in the LCD*/
		LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/

		g_botones->b5=NOT_PRESSED;
	}
	else if(PRESSED == g_botones->b6)
	{
		/*WHITE  is selected, print on screen*/
		delay(10000);/* small of 100ms delay to avoid bounce*/
		build_programable_sequence( extern_rgb_white);/* storages color to be printed user programmed sequence*/

		/* show to user that his color is stored, to be printed in the sequence*/
		uint8_t string1[]="W "; /*! String to be printed in the LCD*/
		LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/

		g_botones->b6=NOT_PRESSED;
	}
	else if(PRESSED == g_botones->sw3)
	{

		run_programmed_sequence();
		g_botones->sw3=NOT_PRESSED;
	}

}
void build_programable_sequence( void (*fptr_selected_color)(void ))
{
	/* this array will hold the selected color for secuence*/


	if( PROGRAMABLE_COLORS <=selected_colors)
	{
		/* print 10 colors selected warning, there is no more colors to program*/

		/* do not increment selected color*/
	}
	else
	{
		/* assign selected color to program*/
		g_ftpr_programmed_colors[selected_colors] = fptr_selected_color;
		/* increment selected colors, to storage incoming color*/
		selected_colors++;
	}
	/* */
}
void run_programmed_sequence(void)
{
	uint8_t sweep_arr = 0;
	/* displaying programmed colors on extern RGB*/
	while(0 != g_ftpr_programmed_colors[sweep_arr])
	{
		/*  extern rgb will show the programed color in the order it was selected*/
		g_ftpr_programmed_colors[sweep_arr]();
		delay(100000);/* one second delay*/
		sweep_arr++;
	}

	/* clearing array*/
	for(sweep_arr = 0; sweep_arr < PROGRAMABLE_COLORS ; sweep_arr++)
	{
		g_ftpr_programmed_colors[sweep_arr]=0;
		extern_rgb_off();
		selected_colors=0;
		LCD_nokia_clear();/*clear last screen*/
	}

}
