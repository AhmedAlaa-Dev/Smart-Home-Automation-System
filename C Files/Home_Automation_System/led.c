/******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.c
 *
 * Description: Source file for the leds driver
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/
#include "gpio.h"
#include "led.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*Description:
 * Initializes all Leds (red, green, blue) pins direction.
 * Turn off all the Leds*/
void LEDS_init(void){
	GPIO_setupPinDirection(RED_LED_PORT_ID,RED_LED_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,TURN_OFF);

	GPIO_setupPinDirection(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,TURN_OFF);

	GPIO_setupPinDirection(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,TURN_OFF);
}

/*Description:
 * Turns on the specified LED*/
void LED_on(LED_ID id){
	if((0 <= id.pin && id.pin <= 7) | (0 <= id.port && id.port <=3)){
		GPIO_writePin(id.port,id.pin,TURN_ON);
	}
}

void LED_off(LED_ID id){
	if((0 <= id.pin && id.pin <= 7) | (0 <= id.port && id.port <=3)){
		GPIO_writePin(id.port,id.pin,TURN_OFF);
	}
}




