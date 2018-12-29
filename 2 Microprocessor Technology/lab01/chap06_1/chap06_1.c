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
unsigned short io_reg2;
unsigned short io_reg1;
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
		0x8e, 0x7f, 0xff
		};

/*************************************************************************
MAIN Program 
*************************************************************************/
int main(void)
{


        Initial_Creator();         
	//EnableInterrupt(BIT_GMASK);
	
	while (10)
         {
		 io_reg1 =IO_REG1;
		 io_reg1 =io_reg1 | 0xff7f;
		  if(io_reg1 == 0xff7f) // 8¶}
		  {    
		   io_reg2 = IO_REG1; 
		   io_reg2 = (io_reg2 << 8) | 0xc000; 
		   IO_REG2 = io_reg2;
		  }
         else 
		  { 
		   io_reg1 =IO_REG1;
		   io_reg1 =io_reg1 | 0xffbf;
		   if(io_reg1 == 0xffbf)// 7¶}
		   {
			  if( ( io_reg2 | 0xfeff ) == 0xfeff )
			  {
			   io_reg2 = (io_reg2 >> 1);
		       IO_REG2 = io_reg2; 
			  
			  }
			  else
			  {
			    io_reg2=(io_reg2>>1)|0x8000;
                IO_REG2 = io_reg2;
			  }
		   }
		   else
		   {
		      if( ( io_reg2 | 0x7fff ) == 0x7fff )
			  {
			   io_reg2=(io_reg2<<1);
               IO_REG2 = io_reg2;
			  }
			  else
			  {
			   io_reg2=(io_reg2<<1)|0x0100;
               IO_REG2 = io_reg2; 
			  }
		   }
		  }
		Delay(200);    
		/*IO_REG0 =  0x0e00;  	
      	        Delay(200);*/
         }        
                
        DisableInterrupt(BIT_GMASK);
}
