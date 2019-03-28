/*
 * global.c
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */


#include "global.h"
/* configuration of spi for nokia LCD*/
const spi_config_t g_spi_config =
{
		SPI_DISABLE_FIFO,
		SPI_LOW_POLARITY,
		SPI_LOW_PHASE,
		SPI_MSB,
		SPI_0,     /* this struct is only for channel SPI_0*/
		SPI_MASTER,/* channel 0 is set as master*/
		GPIO_MUX2, /* alternative function 2 for SPI in pins clock  and sout*/
		SPI_BAUD_RATE_2,
		SPI_FSIZE_8,
		{GPIO_D, bit_1, bit_2}
};

void init_LDC_for_all_layers()
{
	/* the spi is  fundamental for LCD*/
	SPI_init(&g_spi_config); /*! Configuration function for the LCD port*/
	LCD_nokia_init(); /*! Configuration function for the LCD */

}
void print_wallpaper()
{
	LCD_nokia_clear();/*! It clears the information printed in the LCD*/
	LCD_nokia_bitmap(&wallpaper[0]); /*! It prints an array that hold an image, in this case is the initial picture*/
}
