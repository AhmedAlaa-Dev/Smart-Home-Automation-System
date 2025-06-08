/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the PWM Driver
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/
#include "pwm.h"
#include "std_types.h"
#include "common_macros.h"
#include "gpio.h"
#include <avr/io.h>

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/**
 * Function: PWM_Timer0_Start
 * --------------------------
 * Initializes Timer0 in Fast PWM mode with a specified duty cycle (0 to 100%).
 *
 * Parameters:
 *    uint8 duty_cycle - PWM duty cycle as a percentage.
 *
 * Description:
 * - Configures the PWM pin as output.
 * - Sets Timer0 with a prescaler of F_CPU/1024 and non-inverting Fast PWM mode.
 * - Adjusts the output compare register (OCR0) based on the given duty cycle.
 */
void PWM_Timer0_Start(uint8 duty_cycle){
	GPIO_setupPinDirection(PWM_PORT_ID,PWM_PIN_ID,PIN_OUTPUT);

	//Set the inital value of the timer
	TCNT0 = 0;

	//Set the prescaler value 1028
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

	//Set the waveform Generation Mode Bit to Fast PWM
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);

	//Set the PWM mode to be non-inverting
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);

	//Setting the high percentage of the period
	//Note: There's a weird thing if you did it like (d)
	OCR0 = (duty_cycle * MAX_8BIT_VALUE) / 100;
}
