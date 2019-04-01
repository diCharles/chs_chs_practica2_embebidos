/*
 * extern_rgb.c
 *
 *  Created on: 31/03/2019
 *      Author: Charles
 */


#include "extern_rgb.h"

/* initialize flex timer module and his output pins*/
void init_extern_rgb(void)
{
	/* initialize flex timer and his output pins PTC1, PTC2. PTC3*/

	/* this is pin is conected to red anode  of external rgb led*/
	gpio_pin_control_register_t pin_control_register_bit_c_1 = GPIO_MUX4;/* setting alternative 4 of pin*/
	GPIO_clock_gating(GPIO_C);
	GPIO_pin_control_register(GPIO_C, bit_1, &pin_control_register_bit_c_1);/* PTC1 is CH0 output pin*/
	GPIO_pin_control_register(GPIO_C, bit_2, &pin_control_register_bit_c_1);/* PTC2 is CH1 output pin*/
	GPIO_pin_control_register(GPIO_C, bit_3, &pin_control_register_bit_c_1);/* PTC3 is CH2 output pin*/
	FlexTimer_Init(CHANNEL_0);/* anode RED*/
	FlexTimer_Init(CHANNEL_1);/* anode GREEN*/
	FlexTimer_Init(CHANNEL_2);/* anode BLUE*/
}

/* sets selected color and its intensity, MAXIMUM INTENSITY=255, MINIMUM INTENSITY=0*/
void extern_rgb_color(color_intesity_t red_intensity, color_intesity_t green_intensity, color_intesity_t blue_intensity)
{

		FlexTimer_update_channel_value(CHANNEL_0,red_intensity);

		FlexTimer_update_channel_value(CHANNEL_1,blue_intensity);

		FlexTimer_update_channel_value(CHANNEL_2,green_intensity);

}
// Z
void extern_rgb_blue(void)
{
	extern_rgb_color(0, 204, 153 );
}

void extern_rgb_red(void)
{
	extern_rgb_color(255, 0, 0);
}

void extern_rgb_green(void)
{
	extern_rgb_color(0, 255, 0);
}

void extern_rgb_yellow(void)
{
	extern_rgb_color(255, 255, 0);
}

void extern_rgb_purple(void)
{
	extern_rgb_color(255, 0, 255);
}

void extern_rgb_white(void)
{
	extern_rgb_color(255,255,255);
}
