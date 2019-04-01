/*
 * extern_rgb.h
 *
 *  Created on: 31/03/2019
 *      Author: Charles
 */

#ifndef EXTERN_RGB_H_
#define EXTERN_RGB_H_

#include "FlexTimer.h"
#include "GPIO.h"
#include "Bits.h"

typedef uint8_t color_intesity_t;
typedef enum{RED,BLUE,GREEN,YELLOW, PURPLE,WHITE}rgb_colors_t;


/* initialize flex timer module and his output pins*/
void init_extern_rgb(void);

/* sets selected color and its intensity, MAXIMUM INTENSITY=255, MINIMUM INTENSITY=0*/
void extern_rgb_color(color_intesity_t red_intensity, color_intesity_t green_intensity, color_intesity_t blue_intensity);

#endif /* EXTERN_RGB_H_ */
