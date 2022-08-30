 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: app.c
 *
 * Description: Application source folder
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/

#include "KEYPAD.h"
#include "sev_seg.h"




int main(void)
{

	SEV_SEG_init(0);
	while(1)
	{

		SEV_SEG_init(KeyPad_getPressedKey());
	}
}
