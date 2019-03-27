/*
 * systemControl.c
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */


#include "systemControl.h"
#include "rgb_adc.h"
#include "rgb_frecuencia.h"
#include "rgb_manual.h"
#include "rgb_secuencia.h"

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
	else if(PRESSED == botones_g->sw2)
	{
		// GO BACK TO SYSTEM MENU
		g_current_app= system_menu;
		botones_g->sw2=NOT_PRESSED;/* clearing sw flag*/
	}
	return (g_current_app);
}
void system_menu()
{

	//print menu on screen

	/*selection of application to execute*/
	if(PRESSED == botones_g->b1)
	{
		g_selected_app=exe_rgb_secuencia;//user wants to execute this app
		botones_g->b1=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == botones_g->b2)
	{

		g_selected_app = exe_rgb_manual ;//user wants to execute this app
		botones_g->b2=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == botones_g->b3)
	{
		g_selected_app = exe_rgb_frecuencia ;//user wants to execute this app
		botones_g->b3=NOT_PRESSED;/*clearing button flag*/
	}
	else if(PRESSED == botones_g->b4)
	{
		g_selected_app = exe_rgb_adc ;	//user wants to execute this app
		botones_g->b4=NOT_PRESSED;/*clearing button flag*/
	}
}
