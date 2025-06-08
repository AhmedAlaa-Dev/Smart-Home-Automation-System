/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: buzzer.h
 *
 * Description: Header file for the Buzzer
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PORT_ID (PORTD_ID)
#define BUZZER_PIN_ID (PIN3_ID)

#define BUZZER_ON LOGIC_HIGH
#define BUZZER_OFF LOGIC_LOW


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*Description:
 * Initializes the buzzer pin direction and turn off the buzzer*/
void Buzzer_init(void);

/*Description:
 * Activates the buzzer*/
void Buzzer_on(void);

/*Description:
 * Deactivates the buzzer*/
void Buzzer_off(void);

#endif /* BUZZER_H_ */
