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
	print_ADC_read(200);
}

void print_ADC_read(uint8_t convertion_adc)
{
	uint8_t string2[]="voltaje"; /*! String to be printed in the LCD*/

	/*  convert to obtain vin of adc
	 *  convertion_adc=(( VIN_ADC)*(RESOLUTION_ADC))//VREF_ADC
	 *  VIN_ADC=( (convertion_adc)*(VREF_ADC) ) / RESOLUTION_ADC
	 * */
	float vin_ADC_f= ((float)(convertion_adc)) * (VREF_ADC)  / ((float)(RESOLUTION_ADC ));
	uint8_t decenas= 0;
	uint8_t unidades=((uint32_t)(vin_ADC_f))%10;
	uint8_t decimal1=( (((uint32_t)(vin_ADC_f*10))) )%10;
	uint8_t decimal2=( (((uint32_t)(vin_ADC_f*100))) )%10;

	LCD_nokia_goto_xy(0,2); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string2[0]); /*! It print a string stored in an array*/
	LCD_nokia_goto_xy(25,3);
	LCD_nokia_send_char(decenas+48); /*! It prints a character*/
	LCD_nokia_send_char(unidades+48); /*! It prints a character*/
	LCD_nokia_send_char('.'); /*! It prints a character*/
	LCD_nokia_send_char(decimal1+48); /*! It prints a character*/
	LCD_nokia_send_char(decimal2+48); /*! It prints a character*/
}
void ADC_convertion_to_rgb(uint8_t convertion_adc)
{
	//extern_rgb_color(red_anode_intensity,green_anode_intensity,blue_anode_intensity);
	//if( <(convertion_adc))
}
