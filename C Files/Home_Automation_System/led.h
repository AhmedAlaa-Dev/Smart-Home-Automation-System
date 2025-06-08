/******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.h
 *
 * Description: Header file for the leds in project
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/
#ifndef LED_H_
#define LED_H_
#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define POSITIVE_LOGIC

#ifdef POSITIVE_LOGIC
#define TURN_ON LOGIC_HIGH
#define TURN_OFF LOGIC_LOW
#elif
#define TURN_ON LOGIC_LOW
#define TURN_OFF LOGIC_HIGH
#endif

#define LEDS_PORT_ID (PORTB_ID)

#define RED_LED_PORT_ID (PORTB_ID)
#define RED_LED_PIN_ID (PIN5_ID)

#define GREEN_LED_PORT_ID (PORTB_ID)
#define GREEN_LED_PIN_ID (PIN6_ID)

#define BLUE_LED_PORT_ID (PORTB_ID)
#define BLUE_LED_PIN_ID (PIN7_ID)

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef struct
{
	uint8 port;
	uint8 pin;
}LED_ID;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*Description:
 * Initializes all Leds (red, green, blue) pins direction.
 * Turn off all the Leds*/
void LEDS_init(void);

/*Description:
 * Turns on the specified LED*/
void LED_on(LED_ID id);
/*Description:
 * Turns off the specified LED*/
void LED_off(LED_ID id);


#endif
