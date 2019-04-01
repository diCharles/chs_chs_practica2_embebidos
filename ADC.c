/*
 * ADC.c
 *
 *  Created on: 03/03/2019
 *      Author: Rubén Charles
 */

#include "ADC.h"
#include "stdio.h"
#include "MK64F12.h"


#define ADC_CHANNEL 20

void ADC0_single_ended_init(uint8_t clock_divide_select, uint8_t resolution , uint8_t ADC_clock_source, uint8_t number_of_samples)
{
	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;

	if(0 > clock_divide_select || 4 < clock_divide_select)
	{
		//printf("FATAL: The clock divider specified does not exist");
		return ;
	}

	if(0 > resolution || 4 < resolution)
	{
		//printf("FATAL: The resolution specified does not exist");
		return;
	}

	if(0 > ADC_clock_source || 4 < ADC_clock_source)
	{
		//printf("FATAL: The bus clock specified does not exist");
		return;
	}

	if(0 > number_of_samples || 4 < number_of_samples)
	{
		//printf("FATAL: The bus number of samples specified does not exist");
		return;
	}



	ADC0->CFG1 = ADC_CFG1_ADIV(clock_divide_select)|ADC_CFG1_ADLSMP_MASK |ADC_CFG1_MODE(resolution)|ADC_CFG1_ADICLK(ADC_clock_source);
	ADC0->CFG2 = 0;
	ADC0->SC2 = 0;
	ADC0->SC3 = ADC_SC3_AVGE_MASK |ADC_SC3_AVGS(number_of_samples) ;

}

uint8_t ADC_result(void )
{
	ADC0->SC1[0] = ADC_SC1_ADCH(ADC_CHANNEL);//20 is the ADC channel,17 pin ADC0_DM1 of the K64's board
	//Blocks the code until the complete coversion flag (COCO) is equal to 1
	while( (ADC0->SC1[0] & ADC_SC1_COCO_MASK) == 0);
	//Register R contains the result of the conversion

	return (ADC0->R[0] & 0x00000FFF);
}

void ADC1_single_ended_init( uint8_t clock_divide_select, uint8_t resolution , uint8_t ADC_clock_source, uint8_t number_of_samples)
{
	SIM->SCGC3 |= SIM_SCGC3_ADC1_MASK;

		if(0 > clock_divide_select || 4 < clock_divide_select)
		{
			//printf("FATAL: The clock divider specified does not exist");
			return ;
		}

		if(0 > resolution || 4 < resolution)
		{
			//printf("FATAL: The resolution specified does not exist");
			return;
		}

		if(0 > ADC_clock_source || 4 < ADC_clock_source)
		{
			//printf("FATAL: The bus clock specified does not exist");
			return;
		}

		if(0 > number_of_samples || 4 < number_of_samples)
		{
			//printf("FATAL: The bus number of samples specified does not exist");
			return;
		}



		ADC1->CFG1 = ADC_CFG1_ADIV(clock_divide_select)|ADC_CFG1_ADLSMP_MASK |ADC_CFG1_MODE(resolution)|ADC_CFG1_ADICLK(ADC_clock_source);
		ADC1->CFG2 = 0;
		ADC1->SC2 = 0;
		ADC1->SC3 = ADC_SC3_AVGE_MASK |ADC_SC3_AVGS(number_of_samples) ;
}
