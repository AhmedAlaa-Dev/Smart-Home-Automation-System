 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ATmega16 ADC driver
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*10-bit ADC: The resolution of the ADC is 10 bits, meaning the maximum possible digital value is
2^10 − 1 = 1023
*/
#define ADC_MAXIMUM_VALUE    1023

#define INTERNAL_REF 1
#if (INTERNAL_REF == 1)
	#define ADC_REF_VOLT_VALUE   2.56
#else
	#define ADC_REF_VOLT_VALUE   5
#endif
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);


/* Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
