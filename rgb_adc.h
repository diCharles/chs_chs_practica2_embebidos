/*
 * rgb_adc.h
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */

#ifndef RGB_ADC_H_
#define RGB_ADC_H_

#define VREF_ADC 3.3F
#define RESOLUTION_ADC 255U

#include "global.h"
/*when called the application rgb_adc will be executed*/
void exe_rgb_adc(void);

/* prints voltage in format decimal XX.YY*/
void print_ADC_read(uint8_t convertion_adc);
void ADC_convertion_to_rgb(uint8_t convertion_adc);
#endif /* RGB_ADC_H_ */
