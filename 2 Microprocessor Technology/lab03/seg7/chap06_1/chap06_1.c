/*************************************************************************
Include files
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "driver.h"

/*************************************************************************
Variables
*************************************************************************/
/*************************************************************************
System Initialize
*************************************************************************/
void Initial_Creator(void)
{
        Initial_TIMER0();
        Initial_KEYPAD();
}
int j;
const UC LED_tb2[] = {
		0xc0, 0xf9, 0xa4, 0xb0, 0x99,
		0x92, 0x82, 0xf8, 0x80, 0x90,
		0xa0, 0x83, 0xc6, 0xa1, 0x84,
		0x8e, 0x7f, 0xff
		};
unsigned short i;
unsigned short io_reg1;
/*************************************************************************
MAIN Program 
*************************************************************************/
int main(void) {
	Initial_Creator();         
	i = 0;
	j = 0;
	while (1) {
	    io_reg1 = IO_REG1;
		io_reg1 = io_reg1 | 0xff7f;
		if(io_reg1 == 0xff7f) //8¶}
		{
		
		
		io_reg1 = IO_REG1;
		io_reg1 = io_reg1|0xff80;
		io_reg1 = io_reg1^0xffff ;
		io_reg1 =io_reg1+1;
		
		 IO_REG0 = 0xfe00 + 0xbf; // 0xfe00 : COM0 -
		 Delay(1);
		 IO_REG0 = 0xf700 + LED_tb2[io_reg1%10]; // 0xf700 : COM3
		 Delay(1);
		 IO_REG0 = 0xfb00 + LED_tb2[((io_reg1/10)%10)]; // 0xfb00 : COM2
		 Delay(1);
		 IO_REG0 = 0xfd00 + LED_tb2[(io_reg1/100)]; // 0xfd00 : COM1
		 Delay(1);
		}
		else
		{
		 io_reg1 = IO_REG1;
		 io_reg1 = io_reg1|0xff80;
		 io_reg1 = io_reg1^0xffff;
		 
		 IO_REG0 = 0xf700 + LED_tb2[(io_reg1%10)]; // 0xf700 : COM3
		 Delay(1);
		 IO_REG0 = 0xfb00 + LED_tb2[((io_reg1/10)%10)]; // 0xfb00 : COM2
		 Delay(1);
		 IO_REG0 = 0xfd00 + LED_tb2[(io_reg1/100)]; // 0xfd00 : COM1
		 Delay(1);
		}
		
		
	}        
	DisableInterrupt(BIT_GMASK);
}