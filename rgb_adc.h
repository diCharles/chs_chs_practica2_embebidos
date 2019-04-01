/*
 * rgb_adc.h
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */

#ifndef RGB_ADC_H_
#define RGB_ADC_H_



#include "global.h"
#include "ADC.h"

//Defines for function print_ADC_read
#define VREF_ADC 3.3F
#define RESOLUTION_ADC 255U
//For ADCO module configuration
#define ADC_CLK_DIVIDER 0U
#define ADC_CONVERTION_RESOLUTION  0U// 8 bits of ADC resolution
#define ADC_CLOCK_SOURCE 0U
#define ADC_SAMPLES_AVERGAGED 0U
//For function  ADC_convertion_to_rgb
#define PH1   18
#define PH2   36
#define PH3   54
#define PH4   72
#define PH5   90
#define PH6  108
#define PH7  126
#define PH8  144
#define PH9  162
#define PH10 180
#define PH11 198
#define PH12 216
#define PH13 234
#define PH14 255

//For function rgb_sequence_handler
#define SIZE_OF_SEQUENCE_ARRAY 10

/*when called the application rgb_adc will be executed*/
void exe_rgb_adc(void);

/* prints voltage in format decimal XX.YY*/
void print_ADC_read(uint8_t convertion_adc);
/* prints convertion of ADC in pH scale*/
void ADC_convertion_to_rgb(uint8_t convertion_adc);
/* adc ten conversions average */
uint8_t ten_convertions_adc_average();
#endif /* RGB_ADC_H_ */
