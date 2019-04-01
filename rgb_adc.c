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

	static uint8_t ADC_was_init = FALSE;

	if(FALSE == ADC_was_init)
	{
		//Initialize ADC only one time - 12 bits ot
		ADC0_single_ended_init(ADC_CLK_DIVIDER, ADC_CONVERTION_RESOLUTION , ADC_CLOCK_SOURCE, ADC_SAMPLES_AVERGAGED);

		ADC_was_init = TRUE;
	}
	LCD_nokia_goto_xy(0,0); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(&string1[0]); /*! It print a string stored in an array*/
	uint8_t adc_convert= ten_convertions_adc_average();
	//uint8_t adc_convert= ADC_result();
	print_ADC_read( adc_convert);
	ADC_convertion_to_rgb(adc_convert);
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

	if( PH1 >convertion_adc)
	{
		//RED
		extern_rgb_color(255,0,0);
	}


	else if( PH2 >convertion_adc)
	{
		//ORANGE
		extern_rgb_color(255, 128, 0);

	}


	else if( PH3 >convertion_adc)
	{
		//CANARIUM YELLOW
		extern_rgb_color(255, 255, 0 );
	}

	else if( PH4 >convertion_adc)
	{
		//LIGHT YELLOW
		extern_rgb_color( 255, 255, 102);

	}

	else if( PH5 >convertion_adc)
	{
		//OLIVE GREEN
		extern_rgb_color(153, 204, 0);
	}

	else if( PH6 >convertion_adc)
	{
		//GREEN FLAG
		extern_rgb_color(51, 153, 51 );
	}

	else if( PH7 >convertion_adc)
	{
		//PISTACHE
		extern_rgb_color(0, 204, 153 );
	}

	else if( PH8 >convertion_adc)
	{
		//AQUA
		extern_rgb_color(0, 255, 255 );
	}

	else if( PH9 >convertion_adc)
	{
		//LIGHT BLUE
		extern_rgb_color( 0, 204, 255);
	}

	else if( PH10 >convertion_adc)
	{
		//___  BLUE
		extern_rgb_color(0, 153, 255 );
	}

	else if( PH11 >convertion_adc)
	{
		//DEEP BLUE
		extern_rgb_color( 0, 0, 255);
	}

	else if( PH12 >convertion_adc)
	{
		//INTENSE BLUE
		extern_rgb_color(0, 0, 153 );
	}

	else if( PH13 >convertion_adc)
	{
		//VIOLET
		extern_rgb_color(153, 0, 204 );
	}

	else if( PH14 >convertion_adc)
	{
		//PURPLE
		extern_rgb_color(102, 0, 204);
	}
}
uint8_t ten_convertions_adc_average()
{
	uint32_t average = 0;/* float of 32 bits*/
	uint8_t cntr= 0;
	/* ten convertions*/
	for(cntr=0;cntr<10;cntr++)
	{
		/*accumulate adc*/
		average += (uint32_t)(ADC_result());
		delay(500);// 10 ms
	}
	average = (uint32_t)((float)average/(float)10);
	return ((uint8_t)average);
}



//




