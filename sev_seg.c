 /******************************************************************************
 *
 * Module: sev_seg
 *
 * File Name: sev_seg.c
 *
 * Description: 
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#include "sev_seg.h"
#include "DIO.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void SEV_SEG_init(uint8 value)
{
	DIO_set_port_Dir('A',out);
	DIO_setPINDir('C',6,out);
	DIO_write_PIN('C',6,0);
	DIO_write_port('A',value);

}

