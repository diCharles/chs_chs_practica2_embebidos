/*
 * systemControl.c
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */


#include "systemControl.h"


/* pointer to struct that contains buttons state*/
buttons_t * botones_g;

//the defaul app to be executed is system_menu
static fptr g_current_app  = system_menu;
static fptr g_selected_app = system_menu;


void init_system()
{
	/*acquiring  pointer to  struct that contains buttons state */
	botones_g= get_buttons();
	/* init nokia lcd*/
	init_LDC_for_all_layers(0);
	system_menu();

}

void execute_current_system_application()
{
	/*acquiring system application to execute*/
	fptr application= change_system_application();
	/* executing application*/
	application();
}
fptr change_system_application()
{

	if(PRESSED == botones_g->sw3)
	{
		//EXECUTE CURRENT APLICATION
		g_current_app=g_selected_app;
		botones_g->sw3=NOT_PRESSED;/*clearing sw flag*/
	}
	if(PRESSED == botones_g->sw2)
	{
		// GO BACK TO SYSTEM MENU
		g_current_app= system_menu;
		botones_g->sw2=NOT_PRESSED;/* clearing sw flag*/
	}
	return (g_current_app);
}
void system_menu()
{

	print_menu();

	//print menu on screen
	if(PRESSED == botones_g->b0)
	{
		g_selected_app=print_wallpaper;
	}
	/*selection of application to execute*/
	else if(PRESSED == botones_g->b1)
	{
		g_selected_app=exe_rgb_manual;//user wants to execute this app
		botones_g->b1=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == botones_g->b2)
	{

		g_selected_app = exe_rgb_adc ;//user wants to execute this app
		botones_g->b2=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == botones_g->b3)
	{
		g_selected_app = exe_rgb_secuencia ;//user wants to execute this app
		botones_g->b3=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == botones_g->b4)
	{
		g_selected_app = exe_rgb_frecuencia ;	//user wants to execute this app
		botones_g->b4=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == botones_g->b5)
	{
		g_selected_app=print_wallpaper;
		botones_g->b5=NOT_PRESSED;
	}
	else if(PRESSED == botones_g->b6)
	{
		g_selected_app=print_wallpaper;
		botones_g->b6=NOT_PRESSED;
	}
}

void print_menu()
{
	uint8_t string0[]="0 WALLPPR";
	uint8_t string1[]="1 MANUAL"; /*! String to be printed in the LCD*/
	uint8_t string2[]="2 ADC"; /*! String to be printed in the LCD*/
	uint8_t string3[]="3 SECUENCIA"; /*! String to be printed in the LCD*/
	uint8_t string4[]="4 FRECUENCIA"; /*! String to be printed in the LCD*/
	uint8_t string5[]="5 PASSWORD"; /*! String to be printed in the LCD*/
	LCD_nokia_clear();
	LCD_nokia_goto_xy(0,0); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string0[0]); /*! It print a string stored in an array*/
	LCD_nokia_goto_xy(0,1); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/
	LCD_nokia_goto_xy(0,2); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string2[0]); /*! It print a string stored in an array*/
	LCD_nokia_goto_xy(0,3); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string3[0]); /*! It print a string stored in an array*/
	LCD_nokia_goto_xy(0,4); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string4[0]); /*! It print a string stored in an array*/
	LCD_nokia_goto_xy(0,5); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string5[0]); /*! It print a string stored in an array*/

}
