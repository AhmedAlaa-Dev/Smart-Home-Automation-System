/******************************************************************************
 * Module: Buzzer
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the Buzzer
 *
 * Author: Ahmed Alaa
 *******************************************************************************/

#include "gpio.h"
#include "buzzer.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*Description:
 * Initializes the buzzer pin direction and turn off the buzzer*/
void Buzzer_init(void){
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,BUZZER_OFF);
}

/*Description:
 * Activates the buzzer*/
void Buzzer_on(void){
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,BUZZER_ON);
}

/*Description:
 * Deactivates the buzzer*/
void Buzzer_off(void){
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,BUZZER_OFF);
}
