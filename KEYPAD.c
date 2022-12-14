 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.c
 *
 * Description: 
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#include "KEYPAD.h"
#include "DIO.h"
#include "std_types.h"
#include "Micro_Config.h"
/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/
#if (N_col==3)
static uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number);

#elif (N_col==4)
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number);

#endif
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void KeyPad_init(void)
{
	DIO_setPINDir( KEYPAD_PORT_OUT,4,in);
	DIO_setPINDir( KEYPAD_PORT_OUT,5,in);
	DIO_setPINDir( KEYPAD_PORT_OUT,6,in);
	DIO_setPINDir( KEYPAD_PORT_OUT,7,in);
	DIO_setPINDir( KEYPAD_PORT_IN,2,in);
	DIO_setPINDir( KEYPAD_PORT_IN,3,in);
	DIO_setPINDir( KEYPAD_PORT_IN,4,in);
	DIO_enablePullup_pin(KEYPAD_PORT_IN,2,1);
	DIO_enablePullup_pin(KEYPAD_PORT_IN,3,1);
	DIO_enablePullup_pin(KEYPAD_PORT_IN,4,1);
}

uint8 KeyPad_getPressedKey(void)
{
	uint8 col,row;
	while(1)
	{
		KeyPad_init();
		for(row=0;row<N_col;row++)
		{
			if(row>0)
			{
				DIO_setPINDir( KEYPAD_PORT_OUT,row+3,in);
			}
			DIO_setPINDir( KEYPAD_PORT_OUT,row+4,out);
			DIO_write_PIN(KEYPAD_PORT_OUT,row+4,0);
			for(col=0;col<N_col;col++)
			{
				if(DIO_read_PIN(KEYPAD_PORT_IN,col+2)==0)
				{
					#if (N_col==3)
					return KeyPad_4x3_adjustKeyNumber((row*N_col)+col+1);
					#elif (N_col==4)
					return KeyPad_4x4_adjustKeyNumber((row*N_col)+col+1);
					#endif
				}
			}
		}
	}

}


uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number)
{
	switch(button_number)
	{
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	default:
		return '0';
		break;

	}

}
