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

typedef uint8_t color_intesity_t;/* MAX COLOR INTENSITY OFF 255*/
typedef enum{RED,BLUE,GREEN,YELLOW, PURPLE,WHITE}rgb_colors_t;

#define RED_ANODE_ON 255
#define GREEN_ANODE_ON 255
#define BLUE_ANODE_ON 255

#define RED_ANODE_OFF 0
#define GREEN_ANODE_OFF 0
#define BLUE_ANODE_OFF 0

/* initialize flex timer module and his output pins*/
void init_extern_rgb(void);

/* sets selected color and its intensity, MAXIMUM INTENSITY=255, MINIMUM INTENSITY=0*/
void extern_rgb_color(color_intesity_t red_intensity, color_intesity_t green_intensity, color_intesity_t blue_intensity);

/*this  enables to set extern rgb to only one color*/
void extern_rgb_blue(void);
void extern_rgb_red(void);
void extern_rgb_green(void);
void extern_rgb_yellow(void);
void extern_rgb_purple(void);
void extern_rgb_white(void);

#endif /* EXTERN_RGB_H_ */
