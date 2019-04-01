/*
 * global.h
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "SPI.h"
#include "GPIO.h"
#include "Bits.h"
#include "LCD_nokia.h"
#include "LCD_nokia_images.h"
#include "stdint.h"
#include "SPI.h"
#include "Delay.h"
#include "buttons.h"
#include "extern_rgb.h"
#include "FlexTImer.h"



extern const uint8_t wallpaper[];


/* init lcd with for all layers, LCD is meant to be called by rgb_adc, rgb_frecuecia
 * rgb_manual and rgb_frecuencia*/
/* also initialize spi bus for ldc */
void init_LDC_for_all_layers();

void print_wallpaper();

#endif /* GLOBAL_H_ */
