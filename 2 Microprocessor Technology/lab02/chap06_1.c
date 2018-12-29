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
int i;
unsigned short io_reg1;
unsigned short io_reg2;
unsigned short io_reg3;
unsigned short io_reg4;
unsigned short io_reg5;
unsigned short io_reg6;
unsigned short io_reg7;
unsigned short io_reg8;
unsigned short io_reg9;
/*************************************************************************
System Initialize
*************************************************************************/
void Initial_Creator(void)
{
        Initial_TIMER0();
        Initial_KEYPAD();
}

const UC LED_tb2[] = {
		0xc0, 0xf9, 0xa4, 0xb0, 0x99,
		0x92, 0x82, 0xf8, 0x80, 0x90,
		0xa0, 0x83, 0xc6, 0xa1, 0x84,
		0x8e, 0x7f, 0xff };

/*************************************************************************
MAIN Program 
*************************************************************************/
int main(void) {
	Initial_Creator();         
	while (1) 
	{
		for(i=1;i<=5;i++)	
		{
			if(i==1 || i==5)
			{
				io_reg1 = IO_REG1;
				io_reg1 = (io_reg1 << 8 );
				io_reg2 = io_reg1 & 0xf000;
				io_reg3 = io_reg1 & 0x0f00;
				io_reg4 = io_reg2 >> 1 ;
				io_reg5 = io_reg3 << 1 ;
				io_reg6 = io_reg4 ^ io_reg5 ;
				io_reg6 = io_reg6 & 0x1800;
				io_reg7 = io_reg4 | io_reg5;
				io_reg7 = io_reg7 & 0x6600;
				io_reg8 = io_reg1 & 0x8100;
				io_reg9 = io_reg6 + io_reg7 + io_reg8;
				IO_REG2 = io_reg9;
				Delay(400);
			}
			if(i==2 || i==4)
			{
				io_reg1 = IO_REG1;
				io_reg1 = (io_reg1 << 8 );
				io_reg2 = io_reg1 & 0xf000;
				io_reg3 = io_reg1 & 0x0f00;
				io_reg4 = io_reg2 >> 2 ;
				io_reg5 = io_reg3 << 2 ;
				io_reg6 = io_reg4 ^ io_reg5 ;
				io_reg6 = io_reg6 & 0x3c00;
				io_reg8 = io_reg1 & 0xc300;
				io_reg9 = io_reg6 + io_reg8;
				IO_REG2 = io_reg9;
				Delay(400);
			}
			if(i==3)
			{
				io_reg1 = IO_REG1;
				io_reg1 = (io_reg1 << 8 );
				io_reg2 = io_reg1 & 0xf000;
				io_reg3 = io_reg1 & 0x0f00;
				io_reg4 = io_reg2 >> 3 ;
				io_reg5 = io_reg3 << 3 ;
				io_reg6 = io_reg4 ^ io_reg5 ;
				io_reg6 = io_reg6 & 0x1800;
				io_reg7 = io_reg4 | io_reg5;
				io_reg7 = io_reg7 & 0x6600;
				io_reg8 = io_reg1 & 0x8100;
				io_reg9 = io_reg6 + io_reg7 + io_reg8;
				IO_REG2 = io_reg9;
				Delay(400);
			}
		}	
	}        
	DisableInterrupt(BIT_GMASK);
}