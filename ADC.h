/*
 * ADC.h
 *
 *  Created on: 03/03/2019
 *      Author: Rubén Charles
 */

#ifndef ADC_H_
#define ADC_H_

#include "MK64F12.h"

void ADC_init();
void ADC0_single_ended_init(uint8_t clock_divide_select, uint8_t resolution , uint8_t ADC_clock_source, uint8_t number_of_samples);
void ADC1_single_ended_init(uint8_t clock_divide_select, uint8_t resolution , uint8_t ADC_clock_source, uint8_t number_of_samples);
uint8_t ADC_result(void);

#endif /* ADC_H_ */
