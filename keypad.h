 /******************************************************************************
 *
 * Module: keypad
 *
 * File Name: keypad.h
 *
 * Description:
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define N_col 3
#define N_row 4
#define KEYPAD_PORT_OUT PORTD
#define KEYPAD_PORT_IN  PIND
#define KEYPAD_PORT_DIR DDRD



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*function that returns the ASCII value of the pressed button on the keypad */

uint8 KeyPad_getPressedKey(void);

#endif /* KEYPAD_H_ */
