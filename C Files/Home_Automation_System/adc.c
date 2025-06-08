/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega 32 ADC Driver
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/
#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*Description:
 * Initializes the ADC by setting the reference voltage and prescaler.*/
void ADC_init(void)
{
	// Set the reference voltage to the internal 2.56V reference
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);

	// Set the ADC prescaler to 128 (F_CPU/128) for accurate conversion
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	// Enable the ADC by setting the ADEN bit
	SET_BIT(ADCSRA,ADEN);
}

/* Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */

	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */

	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */

	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */

	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */

	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */

	return ADC; /* Read the digital value from the data register */
}
