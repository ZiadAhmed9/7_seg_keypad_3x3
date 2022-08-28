 /******************************************************************************
 *
 * Module: sev_seg
 *
 * File Name: sev_seg.h
 *
 * Description: 
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/

#ifndef SEV_SEG_H_
#define SEV_SEG_H_
#include "DIO.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
	Function Name        : SEV_SEG_init
	Function Returns     : void
	Function Arguments   : initial value
	Function Description : start the 7 segment display and initialize it with its initial value
*/

void SEV_SEG_init(uint8 value);



#endif /* SEV_SEG_H_ */
