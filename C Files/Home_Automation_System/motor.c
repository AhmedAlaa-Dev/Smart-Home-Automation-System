/******************************************************************************
 * Module: MOTOR
 *
 * File Name: motor.c
 *
 * Description: Source file for the motor driver
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/
#include "gpio.h"
#include "motor.h"
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*Description:
 * Initializes the DC motor by setting the direction for the motor pins and stopping the
motor at the beginning.*/
void DCMotor_Init(void){
	GPIO_setupPinDirection(IN1_PORT_ID,IN1_PIN_ID,PIN_OUTPUT);

	GPIO_setupPinDirection(IN2_PORT_ID,IN2_PIN_ID,PIN_OUTPUT);

	GPIO_writePin(IN1_PORT_ID,IN1_PIN_ID,MOTOR_OFF);
	GPIO_writePin(IN2_PORT_ID,IN2_PIN_ID,MOTOR_OFF);
}
/*Description:
 * Controls the motor's state (Clockwise/Anti-Clockwise/Stop) and adjusts the speed based
on the input duty cycle.*/
void DCMotor_Rotate(DcMotor_State state,uint8 speed){
	switch(state){
		case CW:
			GPIO_writePin(IN1_PORT_ID,IN1_PIN_ID,MOTOR_ON);
			GPIO_writePin(IN2_PORT_ID,IN2_PIN_ID,MOTOR_OFF);
			break;
		case A_CW:
			GPIO_writePin(IN1_PORT_ID,IN1_PIN_ID,MOTOR_OFF);
			GPIO_writePin(IN2_PORT_ID,IN2_PIN_ID,MOTOR_ON);
			break;
		case Stop:
		default:
			GPIO_writePin(IN1_PORT_ID,IN1_PIN_ID,MOTOR_OFF);
			GPIO_writePin(IN2_PORT_ID,IN2_PIN_ID,MOTOR_OFF);
	}

	PWM_Timer0_Start(speed);
}

