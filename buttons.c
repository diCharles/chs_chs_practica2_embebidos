/*
 * buttons.c
 *
 *  Created on: 27/03/2019
 *      Author: Charles
 */

/* brief:
 *
 * */
/* Brief
 *  Here structure that albergate buttons state it is initialized
 * */
/*
 * About layers:
 * current layer: buttons
 * APP: systemControl
 * MAL: buttons
 * HAl:
 * */
/*About firmware and hardware on this layer:
 * IRQs used:
 * Pins used:
 * Peri*/

#include "buttons.h"
/* initialize buttons and sws states as zero, meaning no one has been pressed*/
static buttons_t buttons_g={NOT_PRESSED,	NOT_PRESSED,NOT_PRESSED,NOT_PRESSED
		,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED};

buttonsPtr get_buttons(void)
{
	/* returns the pointer to struct buttons_g, in this way any stranger could read and modify structure without a get procedure*/
	/* RESPONSABITY MUST BE ASUMED*/

	static uint8_t are_buttons_initialized=FALSE;
	/* initialize buttons only once, get_buttons could be called multiple times, this ensures  to do not reinicialize buttons*/
	if(FALSE == are_buttons_initialized)
	{
		init_buttons();
		PORTA_IRQ_Callback(determine_and_set_button_after_interrupt);
		PORTB_IRQ_Callback(determine_and_set_button_after_interrupt);
		PORTC_IRQ_Callback(determine_and_set_button_after_interrupt);
		are_buttons_initialized=TRUE;
	}
	buttonsPtr ptr=& buttons_g;
	return ( ptr);
}
static void init_buttons(void)
{
	/* ENABLING INTERRUPTS FOR BUTTONS*/
	/* base priority off 10*/
	NVIC_set_basepri_threshold(10);
	NVIC_enable_interrupt_and_priotity(PORTA_IRQ,9);
	NVIC_enable_interrupt_and_priotity(PORTB_IRQ,8);
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ,7);
	NVIC_global_enable_interrupts;
	/* pins on portb , portA and portC are going to be used*/
	GPIO_clock_gating(GPIO_C);
	GPIO_clock_gating(GPIO_B);
	GPIO_clock_gating(GPIO_A);
	/* ALL PINS FOR BUTTONS ARE CONFIGURED AS INPUT WITH INTERRUPT AT FALLIG EDGE*/
	uint32_t input_intr_config = GPIO_MUX1|GPIO_PE|GPIO_PS|INTR_FALLING_EDGE;



	/*initialize PTB2 as input with pull up resistor ,will be analogous to B0*/
	GPIO_pin_control_register(GPIO_B, bit_2, &input_intr_config);
	GPIO_data_direction_pin(GPIO_B, GPIO_PIN_INPUT, bit_2);
	/*initialize PTB3 as input with pull up resistor ,will be analogous to B1*/
	GPIO_pin_control_register(GPIO_B, bit_3, &input_intr_config);
	GPIO_data_direction_pin(GPIO_B, GPIO_PIN_INPUT, bit_3);
	/*initialize PTB10 as input with pull up resistor ,will be analogous to B2*/
	GPIO_pin_control_register(GPIO_B, bit_10, &input_intr_config);
	GPIO_data_direction_pin(GPIO_B, GPIO_PIN_INPUT, bit_10);
	/*initialize PTB11 as input with pull up resistor ,will be analogous to B3*/
	GPIO_pin_control_register(GPIO_B, bit_11, &input_intr_config);
	GPIO_data_direction_pin(GPIO_B, GPIO_PIN_INPUT, bit_11);
	/*initialize PTC11 as input with pull up resistor ,will be analogous to B4*/
	GPIO_pin_control_register(GPIO_C, bit_11, &input_intr_config);
	GPIO_data_direction_pin(GPIO_C, GPIO_PIN_INPUT, bit_11);
	/*initialize PTC10as input with pull up resistor ,will be analogous to B5*/
	GPIO_pin_control_register(GPIO_C, bit_10, &input_intr_config);
	GPIO_data_direction_pin(GPIO_C, GPIO_PIN_INPUT, bit_10);
	/*initialize PTC10as input with pull up resistor ,will be analogous to B6*/
	GPIO_pin_control_register(GPIO_A, bit_2, &input_intr_config);
	GPIO_data_direction_pin(GPIO_A, GPIO_PIN_INPUT, bit_2);
	/*initialize PTC6as input with pull up resistor will be analogous to sw2*/
	GPIO_pin_control_register(GPIO_C, bit_6, &input_intr_config);
	GPIO_data_direction_pin(GPIO_C, GPIO_PIN_INPUT, bit_6);
	/*initialize PTA4 as input with pull up resistor will be analogous to sw3*/
	GPIO_pin_control_register(GPIO_A, bit_4, &input_intr_config);
	GPIO_data_direction_pin(GPIO_A, GPIO_PIN_INPUT, bit_4);



}
void determine_and_set_button_after_interrupt(void)
{
	/* specific pins are being used now (as seen in buttons.h ), in future versions of this file
	 * modularity to use any pin on the board must be implemented
	 */
	/* considering that if the button is pressed the pin state would */
	if( FALSE ==GPIO_read_pin(GPIO_B, bit_2))
	{
		buttons_g.b0=PRESSED;
	}
	else if( FALSE ==GPIO_read_pin(GPIO_B, bit_3))
	{
		buttons_g.b1=PRESSED;
	}
	else if( FALSE ==GPIO_read_pin(GPIO_B, bit_10))
	{
		buttons_g.b2=PRESSED;
	}
	else if( FALSE ==GPIO_read_pin(GPIO_B, bit_11))
	{
		buttons_g.b3=PRESSED;
	}
	else if( FALSE ==GPIO_read_pin(GPIO_C, bit_11))
	{
		buttons_g.b4=PRESSED;
	}
	else if( FALSE ==GPIO_read_pin(GPIO_C, bit_10))
	{
		buttons_g.b5=PRESSED;
	}
	else if( FALSE ==GPIO_read_pin(GPIO_A, bit_2))
	{
		buttons_g.b6=PRESSED;
	}

	else if( FALSE ==GPIO_read_pin(GPIO_C, 6))
	{
		buttons_g.sw2=PRESSED;
	}
	else if( (FALSE ==GPIO_read_pin(GPIO_A, 4)) )
	{
		buttons_g.sw3=PRESSED;
	}




}


