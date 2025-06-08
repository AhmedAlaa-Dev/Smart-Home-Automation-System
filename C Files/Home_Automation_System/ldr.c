 /******************************************************************************
 *
 * Module: LDR (Light Dependent Resistor)
 *
 * File Name: ldr.c
 *
 * Description: Source file for the LDR (Light Dependent Resistor) Driver
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/

#include "ldr.h"
#include "adc.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

 /* Description :
 * Function responsible for calculate the light intensity from the ADC digital value.
 */
uint16 LDR_getlightIntensity(void)
{
	uint16 light_intensity_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the ldr is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the light intensity from the ADC value*/
	light_intensity_value = (uint16)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return light_intensity_value;
}

