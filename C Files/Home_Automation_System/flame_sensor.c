/******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.c
 *
 * Description: Source file for the flame sensor driver
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/
#include "std_types.h"
#include "gpio.h"
#include "flame_sensor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*Description:
 * Initializes the flame sensor pin direction.*/
void FlameSensor_init(void){
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID,PIN_INPUT);
}

/*Description:
 * Reads the value from the flame sensor and returns it.*/
uint8 FlameSensor_getValue(void){
	return GPIO_readPin(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID);
}
