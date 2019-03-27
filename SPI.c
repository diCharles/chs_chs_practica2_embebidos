/*
 * SPI.c
 *
 *  Created on: 18/03/2019
 *      Author: Charles
 */
#include "SPI.h"
#include "GPIO.h"

/*it enable the clock module of the SPI by modifying the MDIS bits*/
static void SPI_enable(spi_channel_t channel)
{
	/* Here the corresponding channel of spi will be enabled*/
	/* SPI_MCR_MDIS_MASK  define is on mk64f12 file*/
	/* there are 3 channels on SPI module*/
	/*  the mask is negated because a zero on MDIS enables channel*/
	/* SPI clck must be called first than this function*/
	/*  what about halt bit in MCR???*/
	switch (channel)
	{
	case SPI_0:

		SPI0->MCR &= ~(SPI_MCR_MDIS_MASK);
		break;
	case SPI_1:

		SPI1->MCR &= ~(SPI_MCR_MDIS_MASK);
		break;
	case SPI_2:

		SPI2->MCR &= ~(SPI_MCR_MDIS_MASK);
		break;
	default:
		break;
	}
}
/*It activate the clock gating*/
static void SPI_clk(spi_channel_t channel)
{
	/*the first function to be called, if it not a hard fault can occur*/
	/* it is very important to avoid magic numbers and save time on a new typedef
	 * typedef for enable clock of SPI can be found on MK64 header file,section of SIM*/
	switch (channel)
	{
	case SPI_0:
		SIM->SCGC6 |= SIM_SCGC6_SPI0_MASK;
		break;
	case SPI_1:

		SIM->SCGC6 |= SIM_SCGC6_SPI1_MASK;
		break;
	case SPI_2:
		SIM->SCGC3 |= SIM_SCGC3_SPI2_MASK;
		break;
	default:
		break;
	}
}
/*It configure the SPI as a master or slave depending on the value of masterOrslave*/
static void SPI_set_master(spi_channel_t channel, spi_master_t masterOrSlave)
{
	/* the define #define SPI_MCR_MSTR_MASK  enables master, must access to register MCR of
	 * every channel to set SPI as master, when the mask ir or-ed (if supported)
	 * but when is and-ed sets SLAVE (if supported)*/
	switch(channel)/** Selecting the GPIO for clock enabling*/
	{
	case SPI_0: /** SPI0  is selected*/
		if(SPI_MASTER== masterOrSlave)
			SPI0->MCR |= SPI_MCR_MSTR_MASK;
		else if(SPI_SLAVE== masterOrSlave)
			SPI0->MCR &= ~SPI_MCR_MSTR_MASK;
		break;
	case  SPI_1: /** SPI1 B is selected*/
		if(SPI_MASTER== masterOrSlave)
			SPI1->MCR |= SPI_MCR_MSTR_MASK;
		else if(SPI_SLAVE== masterOrSlave)
			SPI1->MCR &= ~SPI_MCR_MSTR_MASK;
		break;
	case  SPI_2: /** SPI2 is selected*/
		if(SPI_MASTER== masterOrSlave)
			SPI2->MCR |= SPI_MCR_MSTR_MASK;
		else if(SPI_SLAVE== masterOrSlave)
			SPI2->MCR &= ~SPI_MCR_MSTR_MASK;
		break;

	default: /** set nothing*/

		break;

	}// end switch
}

/*It activate the TX and RX FIFOs of the SPI depending on the value of enableOrdisable*/
static void SPI_fifo(spi_channel_t channel, spi_enable_fifo_t enableOrDisable)
{
	/*Register MCR is used again to enable or disable comunication fifo registers*/
	/*
	Disable Transmit FIFO (bit 13 DIS_TXF in MCR)
	When the TX FIFO is disabled, the transmit part of the module operates as a simplified double-buffered
	SPI. This bit can be written only when the MDIS bit is cleared.
	0 TX FIFO is enabled.
	1 TX FIFO is disabled.
	 */

	/*
	 * Disable Receive FIFO (bit 12 DIS_RXF in MCR)
	   When the RX FIFO is disabled, the receive part of the module operates as a simplified double-buffered
	   SPI. This bit can only be written when the MDIS bit is cleared.
		0 RX FIFO is enabled.
		1 RX FIFO is disabled.
	 * */
	/*#define SPI_MCR_DIS_RXF_MASK                     (0x1000U)
	 *#define SPI_MCR_DIS_TXF_MASK                     (0x2000U)*/

	/*BOTH fifos are going to be enabled or disabled at the same time */
	switch (channel)
	{
	case SPI_0:
		if(SPI_ENABLE_FIFO == enableOrDisable)
		{
			SPI0->MCR &= ~(SPI_MCR_DIS_RXF_MASK);
			SPI0->MCR &= ~(SPI_MCR_DIS_TXF_MASK);
		}
		else if(SPI_DISABLE_FIFO == enableOrDisable)
		{
			SPI0->MCR |= (SPI_MCR_DIS_RXF_MASK);
			SPI0->MCR |= (SPI_MCR_DIS_TXF_MASK);
		}
		break;
	case SPI_1:
		if (SPI_ENABLE_FIFO == enableOrDisable)
		{
			SPI1->MCR &= ~(SPI_MCR_DIS_RXF_MASK);
			SPI1->MCR &= ~(SPI_MCR_DIS_TXF_MASK);
		}
		else if (SPI_DISABLE_FIFO == enableOrDisable)
		{
			SPI1->MCR |= (SPI_MCR_DIS_RXF_MASK);
			SPI1->MCR |= (SPI_MCR_DIS_TXF_MASK);
		}
		break;
	case SPI_2:
		if (SPI_ENABLE_FIFO == enableOrDisable)
		{
			SPI2->MCR &= ~(SPI_MCR_DIS_RXF_MASK);
			SPI2->MCR &= ~(SPI_MCR_DIS_TXF_MASK);
		}
		else if (SPI_DISABLE_FIFO == enableOrDisable)
		{
			SPI2->MCR |= (SPI_MCR_DIS_RXF_MASK);
			SPI2->MCR |= (SPI_MCR_DIS_TXF_MASK);
		}

		break;
	default:
		/* change anything*/
		break;
	}
}
/*It selects the clock polarity depending on the value of cpol*/
static void SPI_clock_polarity(spi_channel_t channel, spi_polarity_t cpol)
{
	/* CTAR[0] is used again,
	 * CPOL bit 26 de CTARn:
	 *
	 * 0 The inactive state value of SCK is low.
		1 The inactive state value of SCK is high.
	 * */
	switch (channel)
	{
	case SPI_0:
		if (SPI_HIGH_POLARITY == cpol)
			SPI0->CTAR[0] |= (SPI_CTAR_CPOL_MASK);/*	1 The inactive state value of SCK is high.*/
		else if (SPI_LOW_POLARITY == cpol)
			SPI0->CTAR[0] &= ~(SPI_CTAR_CPOL_MASK);/*    0 The inactive state value of SCK is low.*/
		break;
	case SPI_1:
		if (SPI_HIGH_POLARITY == cpol)
			SPI1->CTAR[0] |= (SPI_CTAR_CPOL_MASK);/*	1 The inactive state value of SCK is high.*/
		else if (SPI_LOW_POLARITY == cpol)
			SPI1->CTAR[0] &= ~(SPI_CTAR_CPOL_MASK);/*    0 The inactive state value of SCK is low.*/
		break;
	case SPI_2:
		if (SPI_HIGH_POLARITY == cpol)
			SPI2->CTAR[0] |= (SPI_CTAR_CPOL_MASK);/*	1 The inactive state value of SCK is high.*/
		else if (SPI_LOW_POLARITY == cpol)
			SPI2->CTAR[0] &= ~(SPI_CTAR_CPOL_MASK);/*    0 The inactive state value of SCK is low.*/
		break;
	default:
		/*configure nothing*/
		break;
	}
}
/*It selects the frame size depending on the value of frameSize and the macros that are defined above*/
static void SPI_frame_size(spi_channel_t channel, uint32_t frameSize)
{
	/*on manual CTAR reg comes as SPIx_CTARn, this means SPIx_CTAR[n]*/
	/* CTAR means clock and transfer atributes*/
	/* CTAR is an array of two registers*/
	/*Do not write to the CTAR registers while the module is in the Running state.*/
	/*CTAR0 is used only on slave mode*/
	/*frame size of 8 as standard*/
	/*CTAS here is zero so we use CTAR[0]*/
	/*frameSize receives the value from a macro that sets desired frame size in bits 27 to 30 in CTAR[n]*/
	switch (channel)
	{
	case SPI_0:

		SPI0->CTAR[0] &= ~SPI_CTAR_FMSZ_MASK;/* bits of frame size need to be cleared   first with FMZS mask on mk64 header*/
		SPI0->CTAR[0]|=frameSize;// this macro is used for frame sizeSPI_CTAR_FMSZ(frameSize);
		break;
	case SPI_1:
		SPI0->CTAR[1] &= ~SPI_CTAR_FMSZ_MASK;/* bits of frame size need to be cleared   first with FMZS mask on mk64 header*/
		SPI0->CTAR[1]|=frameSize;// this macro is used for frame sizeSPI_CTAR_FMSZ(frameSize);
		break;
	case SPI_2:
		SPI0->CTAR[2] &= ~SPI_CTAR_FMSZ_MASK;/* bits of frame size need to be cleared   first with FMZS mask on mk64 header*/
		SPI0->CTAR[2]|=frameSize;// this macro is used for frame sizeSPI_CTAR_FMSZ(frameSize);
		break;
	default:
		break;
	}
}
/*It selects the clock phase depending on the value of cpha*/
static void SPI_clock_phase(spi_channel_t channel, spi_phase_t cpha)
{
	/* again use of CTAR[0] for select clock phase*/
	/* this will affect when the data is aquired*/
	/*CPHA :1 Data is changed on the leading edge of SCK and captured on the following edge.*/
	/*CPHA :0 0 Data is captured on the leading edge of SCK and changed on the following edge.*/
	switch (channel)
	{
	case SPI_0:
		if (SPI_HIGH_PHASE == cpha)
			SPI0->CTAR[0] |= (SPI_CTAR_CPHA_MASK);
		else if (SPI_LOW_PHASE == cpha)
			SPI0->CTAR[0] &= ~(SPI_CTAR_CPHA_MASK);
		break;
	case SPI_1:
		if (SPI_HIGH_PHASE == cpha)
			SPI1->CTAR[0] |= (SPI_CTAR_CPHA_MASK);
		else if (SPI_LOW_PHASE == cpha)
			SPI1->CTAR[0] &= ~(SPI_CTAR_CPHA_MASK);
		break;
	case SPI_2:
		if (SPI_HIGH_PHASE == cpha)
			SPI2->CTAR[0] |= (SPI_CTAR_CPHA_MASK);
		else if (SPI_LOW_PHASE == cpha)
			SPI2->CTAR[0] &= ~(SPI_CTAR_CPHA_MASK);
		break;
	default:
		/*configure nothing*/
		break;
	}
}
/*It selects the baud rate depending on the value of baudRate and the macros that are defined above*/
static void SPI_baud_rate(spi_channel_t channel, uint32_t baudRate)
{
	/*SPI_CTAR_DBR_MASK  used to double baud rate,  */
	/*SPIn->CTAR[0] |= baudRate used */
	/*	SPIn->CTAR[0] &= ~(SPI_CTAR_BR_MASK) used to ensure that baud rate is computed normaly, not as double*/
	switch(channel)
	{
	case SPI_0:
		SPI0->CTAR[0] &= ~(SPI_CTAR_BR_MASK);
		SPI0->CTAR[0] |= baudRate;
		break;
	case SPI_1:
		SPI1->CTAR[0] &= ~(SPI_CTAR_BR_MASK);
		SPI1->CTAR[0] |= baudRate;
		break;
	case SPI_2:
		SPI2->CTAR[0] &= ~(SPI_CTAR_BR_MASK);
		SPI2->CTAR[0] |= baudRate;
		break;
	}
}
/*It selects if MSB or LSM bits is first transmitted*/
static void SPI_msb_first(spi_channel_t channel, spi_lsb_or_msb_t msb)
{
	/* CTAR[0] is used again to set endianess in registers */
	/*
	 * LSB First (bit LSBFE in CTARn)
		Specifies whether the LSB or MSB of the frame is transferred first.
		0 Data is transferred MSB first.
		1 Data is transferred LSB first.*/
	switch(channel)
	{
	case SPI_0:
		if(SPI_MSB == msb)
			SPI0->CTAR[0] &= ~(SPI_CTAR_LSBFE_MASK);/*0 Data is transferred MSB first.*/
		else if(SPI_LSM == msb)
			SPI0->CTAR[0] |= (SPI_CTAR_LSBFE_MASK);/*1 Data is transferred LSB first.*/
		break;
	case SPI_1:
		if(SPI_MSB == msb)
			SPI1->CTAR[0] &= ~(SPI_CTAR_LSBFE_MASK);/*0 Data is transferred MSB first.*/
		else if(SPI_LSM == msb)
			SPI1->CTAR[0] |= (SPI_CTAR_LSBFE_MASK);/*1 Data is transferred LSB first.*/
		break;
	case SPI_2:
		if(SPI_MSB == msb)
			SPI2->CTAR[0] &= ~(SPI_CTAR_LSBFE_MASK);/*0 Data is transferred MSB first.*/
		else if(SPI_LSM == msb)
			SPI2->CTAR[0] |= (SPI_CTAR_LSBFE_MASK);/*1 Data is transferred LSB first.*/
		break;
	}
}
/*It stars the SPI transmission by modifying the value of HALT bit*/
void SPI_start_tranference(spi_channel_t channel)
{
	/*
	 * Halt bit 0
	The HALT bit starts and stops frame transfers. See Start and Stop of Module transfers
	0 Start transfers.
	1 Stop transfers.
	#define SPI_MCR_HALT_MASK                        (0x1U) is used to configure transfer
	 * */
	switch(channel)
	{
	case SPI_0:
		SPI0->MCR &= ~(SPI_MCR_HALT_MASK);/* channel start frame transmit*/
		break;
	case SPI_1:
		SPI1->MCR &= ~(SPI_MCR_HALT_MASK);/* channel start frame transmit*/
		break;
	case SPI_2:
		SPI2->MCR &= ~(SPI_MCR_HALT_MASK);/* channel start frame transmit*/
		break;
	}
}
/*It stops the SPI transmission by modifying the value of HALT bit*/
void SPI_stop_tranference(spi_channel_t channel)
{
	/*
	 * Halt bit 0
		The HALT bit starts and stops frame transfers. See Start and Stop of Module transfers
		0 Start transfers.
		1 Stop transfers.
		#define SPI_MCR_HALT_MASK                        (0x1U) is used to configure transfer
	 * */
	switch(channel)
	{
	case SPI_0:
		SPI0->MCR |= (SPI_MCR_HALT_MASK);/* channel start frame transmit*/
		break;
	case SPI_1:
		SPI1->MCR |= (SPI_MCR_HALT_MASK);/* channel start frame transmit*/
		break;
	case SPI_2:
		SPI2->MCR |= (SPI_MCR_HALT_MASK);/* channel start frame transmit*/
		break;
	}
}
/*It transmits the information contained in data*/
void SPI_send_one_byte(uint8_t Data)
{
	/*Transfer Complete Flag TFC
		Indicates that all bits in a frame have been shifted out. TCF remains set until it is cleared by writing a 1 to
		it.
		0 Transfer not complete.
		1 Transfer complete.*/
	/*data is loaded into push and the into fifo TX by hardware*/
	SPI0->PUSHR = Data;
	/*here the processor waits to transmission complete flag, bit 31 in SR*/
	/*if it not, data could never reach slave*/
	while(0 == (SPI0->SR & SPI_SR_TCF_MASK));
	/*setting mask again, it is not clear to programmer if hardware sets it back by itself*/
	SPI0->SR |= SPI_SR_TCF_MASK;
}
/*It configures the SPI for transmission, this function as arguments receives a pointer to a constant structure where are all
 * the configuration parameters*/
void SPI_init(const spi_config_t* spi_config_matrix_or_pointer)
{
	/* the clock must go first*/
	SPI_clk(spi_config_matrix_or_pointer->spi_channel);
	/* the enable next*/
	SPI_enable(spi_config_matrix_or_pointer->spi_channel);
	/* the pins are consecutive, they must be configued in mcr register, we´ve got a function for that in GPIO.h*/
	GPIO_clock_gating(spi_config_matrix_or_pointer->spi_gpio_port.gpio_port_name);
	/* remember args          port, pin and configuration of pin by a pointer to a variable*/
	GPIO_pin_control_register(
			spi_config_matrix_or_pointer->spi_gpio_port.gpio_port_name,
			spi_config_matrix_or_pointer->spi_gpio_port.spi_clk,/*this is the pin called clk*/
			&(spi_config_matrix_or_pointer->pin_config) /*both pins in PCR register are set with mux2, alternative fuct2, not a GPIO*/
	);
	GPIO_pin_control_register(
				spi_config_matrix_or_pointer->spi_gpio_port.gpio_port_name,
				spi_config_matrix_or_pointer->spi_gpio_port.spi_sout,/*this is the pin called clk*/
				&(spi_config_matrix_or_pointer->pin_config) /*both pins in PCR register are set with mux2, alternative fuct2, not a GPIO*/
		);
	/* important to set channel as master or slave*/
	SPI_set_master(spi_config_matrix_or_pointer->spi_channel,spi_config_matrix_or_pointer->spi_master);
	/*set spi external caracteristics like phase and polarity ,endianess , baudrate and frame size*/
	SPI_clock_phase(spi_config_matrix_or_pointer->spi_channel,spi_config_matrix_or_pointer->spi_phase);
	SPI_clock_polarity(spi_config_matrix_or_pointer->spi_channel,spi_config_matrix_or_pointer->spi_polarity);
	SPI_msb_first(spi_config_matrix_or_pointer->spi_channel,spi_config_matrix_or_pointer->spi_lsb_or_msb);
	SPI_baud_rate(spi_config_matrix_or_pointer->spi_channel,spi_config_matrix_or_pointer->spi_baudrate);
	SPI_frame_size(spi_config_matrix_or_pointer->spi_channel,spi_config_matrix_or_pointer->spi_frame_size);

	/*and the last internal configuration, the RX and TX fifos for data transmit*/
	SPI_fifo(spi_config_matrix_or_pointer->spi_channel,spi_config_matrix_or_pointer->spi_enable_fifo);




}

