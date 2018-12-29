/*===========================================
; NAME: OPTION.H
; DESC: Configuration options for .S files
; HISTORY:
; 02.26.2003: ver 0.0
;===========================================
*/

#ifndef _OPTION_H
#define _OPTION_H

#include "compiler_option.h"


#define	PCLK			10*1000000*5
#define	RAM_SIZE		0x0001000000

/*
Start address of each stacks
*/
/*
#define CODE_SIZE		0x20000			
#define _ISRVECT_SIZE	0x400
#define _CSTACK_SIZE	0x20000				
#define _IRQ_SIZE		0x400	
#define _FIQ_SIZE		0x400
#define _HEAP_SIZE		0x800000
#define _ISRVECT		CODE_SIZE
#define _HEAP			_ISRVECT + _ISRVECT_SIZE	// 0x020400 ~ 0x820400

#define _CSTACK			RAM_SIZE - 8				// 0xFFFFF8 ~ 0xFDFFF8
#define _IRQ_STACK		_CSTACK - 8 - _CSTACK_SIZE	// 0xFDFFF0 ~ 0xFDFBF0
#define _FIQ_STACK		_IRQ_STACK - 8 -_IRQ_SIZE	// 0xFDFBE8 ~ 0xFDF7E0
*/


#endif // _OPTION_H


