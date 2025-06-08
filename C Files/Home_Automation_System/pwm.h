#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PWM_PORT_ID PORTB_ID
#define PWM_PIN_ID PIN3_ID
#define MAX_8BIT_VALUE 255

/*******************************************************************************
 *                              Functions Prototypes                           *
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
void PWM_Timer0_Start(uint8 duty_cycle);
#endif /* PWM_H_ */
