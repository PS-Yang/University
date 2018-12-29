/*************************************************************************
Include files
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "driver.h"

unsigned short io_reg2;		
unsigned short row, col, new_row, new_col; 		
unsigned short cpld_ctrl;
const UC Select_Scan[] = {
	0xe,0xd,0xb,0x7
};
/*********************************
              Initial
**********************************/
void Initial_Creator(void){
	//Initial CPLD_CTRL
	cpld_ctrl = 0x3C;
	CPLD_CTRL = cpld_ctrl;
  Delay(500);
  cpld_ctrl |= 0x01; //Release IO reset
  CPLD_CTRL = cpld_ctrl;
  Delay(500);
  Initial_LCD();
}
void Initial_Creator_Keypad(void){
  Initial_TIMER0();
  Initial_KEYPAD();
}
/*********************************
             Keypad
**********************************/
int Keypad() {
	int x,y;
	int count;
	
	
	for(x = 0 ; x< 4 ; x++ ) 
	{  // Scan Row
		io_reg2 = 0xff00 + Select_Scan[x];
		IO_REG2 = io_reg2;
		Delay(1);	// 防彈跳		
		for(y=0 ; y<4;y++) 
		{	// Scan Column
			if(((IO_REG1 >> 8) & 0x0f) == Select_Scan[y]) 
			{ // 判斷使用者按了那一行
				count = 4*x+y;
			  	return count;
			}
		}
	}
	return -1;  // 沒按任何一鍵
}
/*********************************
                LCD
**********************************/
void WriteLCD (unsigned short reg_no, unsigned short value) {
	LCD_CMD = 0xff;		//MSB
	OptimizationDelay();	//for Optimization	
	LCD_CMD = reg_no;	//LSB
		
	LCD_DATA = (value >> 8);	//MSB
	OptimizationDelay();		//for Optimization	
	LCD_DATA = value;		//LSB
}

void draw_line(unsigned short addr, unsigned short data)
{
     WriteLCD(0x11, addr);
     WriteLCD(0x12, data);
}
/*********************************
               Main 
**********************************/
int main(void) {  
	unsigned short  led = 0xfeff;
	int num=1, key_value;

	Initial_Creator();
	Initial_Creator_Keypad();
	Initial_LCD();
	IO_REG0=0xfefe;
	while(1) 
	{
		
		while((key_value= Keypad())!=-1) 
		{
			if(num==1)
			{
				if(key_value==7)
				{
					IO_REG0=0xfdfe;
					Delay(100);
					num=2;
					break;
				}
				else if(key_value==5)
				{
					IO_REG0=0xfedf;
					Delay(100);
					num=12;
					break;
				}
			}
			else if(num==2)
			{
				if(key_value==6)
				{
					IO_REG0=0xfefe;
					Delay(100);
					num=1;
					break;
				}
				else if(key_value==7)
				{
					IO_REG0=0xfbfe;
					Delay(100);
					num=3;
					break;
				}
			}
			else if(num==3)
			{
				if(key_value==7)
				{
					IO_REG0=0xf7fe;
					Delay(100);
					num=4;
					break;
				}
				else if(key_value==6)
				{
					IO_REG0=0xfdfe;
					Delay(100);
					num=2;
					break;
				}
			}
			else if(num==4)
			{
				if(key_value==6)
				{
					IO_REG0=0xfbfe;
					Delay(100);
					num=3;
					break;
				}
				else if(key_value==5)
				{
					IO_REG0=0xf7fd;
					Delay(100);
					num=5;
					break;
				}
			}
			else if(num==5)
			{
				if(key_value==6)
				{
					IO_REG0=0xf7fe;
					Delay(100);
					num=4;
					break;
				}
				else if(key_value==5)
				{
					IO_REG0=0xf7fb;
					Delay(100);
					num=6;
					break;
				}
			}
			else if(num==6)
			{
				if(key_value==4)
				{
					IO_REG0=0xf7fd;
					Delay(100);
					num=5;
					break;
				}
				else if(key_value==6)
				{
					IO_REG0=0xf7f7;
					Delay(100);
					num=7;
					break;
				}
			}
			else if(num==7)
			{
				if(key_value==4)
				{
					IO_REG0=0xf7fb;
					Delay(100);
					num=6;
					break;
				}
				else if(key_value==6)
				{
					IO_REG0=0xfbf7;
					Delay(100);
					num=8;
					break;
				}
			}
			else if(num==8)
			{
				if(key_value==7)
				{
					IO_REG0=0xf7f7;
					Delay(100);
					num=7;
					break;
				}
				else if(key_value==6)
				{
					IO_REG0=0xfdf7;
					Delay(100);
					num=9;
				    break;
				}
			}
			else if(num==9)
			{
				if(key_value==7)
				{
					IO_REG0=0xfbf7;
					Delay(100);
					num=8;
					break;
				}
				else if(key_value==6)
				{
					IO_REG0=0xfef7;
					Delay(100);
					num=10;
					break;
				}
			}
			else if(num==10)
			{
				if(key_value==7)
				{
					IO_REG0=0xfdf7;
					Delay(100);
					num=9;
					break;
				}
				else if(key_value==4)
				{
					IO_REG0=0xfeef;
					Delay(100);
					num=11;
					break;
				}
			}
			else if(num==11)
			{
				if(key_value==7)
				{
					IO_REG0=0xfef7;
					Delay(100);
					num=10;
					break;
				}
				else if(key_value==4)
				{
					IO_REG0=0xfedf;
					Delay(100);
					num=12;
					break;
				}
			}
			else if(num==12)
			{
				if(key_value==7)
				{
					IO_REG0=0xfefe;
					Delay(100);
					num=1;
					break;
				}
				else if(key_value==5)
				{
					IO_REG0=0xfeef;
					Delay(100);
					num=11;
					break;
				}
			}
			
			
			
			
			
		
			Delay(250);
		}
	}
	return(0);
}

