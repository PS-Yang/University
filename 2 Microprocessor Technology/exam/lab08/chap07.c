// --------------------------------------------------------------------
//
//   Title     :  chap07-1.c
//             :
//   Library   :
//             :
//   Developers:  MICROTIME MDS group
//             :
//   Purpose   :  DEMO LCD Program for Creator Board
//             :
//   Limitation:
//             :
//   Note      :
//             :
// --------------------------------------------------------------------
//   modification history :
// --------------------------------------------------------------------
//   Version| mod. date: |
//   V1.0   | 10/31/2003 | First release
// --------------------------------------------------------------------
//
// Note:
//
//       MICROTIME COMPUTER INC.
//
//


/*************************************************************************
Include files
*************************************************************************/
#include <stdio.h>
#include "driver.h"

void shift_down(unsigned short line);
unsigned short cpld_ctrl ;

unsigned short io_reg2;		
unsigned short row, col, new_row, new_col; 		
unsigned short cpld_ctrl;
const UC Select_Scan[] = {
	0xe,0xd,0xb,0x7
};

void shift_left(unsigned short line, unsigned short vertical);
const char pattern[4][3] ={"000", "010","010", "011"}; 
		
unsigned short row, col, new_row, new_col; 		
				      
const UC LED_tb2[] = {
		0xc0, 0xf9, 0xa4, 0xb0, 0x99,
		0x92, 0x82, 0xf8, 0x80, 0x90,
		0xa0, 0x83, 0xc6, 0xa1, 0x84,
		0x8e, 0x7f, 0xff
		};
/********************************************************************
不精準的延遲副程式 : 
********************************************************************/
/*void Delay(unsigned short ms)
{
	unsigned short i, j;
	
	for (i=0; i < ms ; i++)
	    for (j=0; j < 1000; j++) {}
}	
*/

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
/********************************************************************
系統初始化
********************************************************************/
void Initial_Creator(void)
{
        //Initial CPLD_CTRL
        cpld_ctrl = 0x3C;
        CPLD_CTRL = cpld_ctrl;
        Delay(500);
        cpld_ctrl |= 0x01;    		//Release IO reset
        CPLD_CTRL = cpld_ctrl;

        Delay(500);
		
        Initial_TIMER0();
        Initial_KEYPAD();
        Initial_LCD();
   //     LCD_EnableCursor(FALSE);
}

//對LCD設定資料
 void WriteLCD (unsigned short reg_no, unsigned short value)
{
	LCD_CMD = 0xff;			//MSB
	OptimizationDelay();		//for Optimization	
	LCD_CMD = reg_no;			//LSB
		
	LCD_DATA = (value >> 8) ;	//MSB
	OptimizationDelay();		//for Optimization	
	LCD_DATA = value;		//LSB
} 


void draw_line(unsigned short addr, unsigned short data)
{
     WriteLCD(0x11, addr);
     WriteLCD(0x12, data);
}

/********************************************************************
主程式 
********************************************************************/

extern int sec, min;
int main(void)
{
    int a,b,key_value;
	int n=8;
	
    Initial_Creator();
	
    EnableInterrupt(BIT_GMASK);	// Global interrupt mask Enable
   
    sec = 0;	//default value
   // min = 0;	//default value
    while (1)
    {
		
		
		     draw_line(n*128+sec, 0xc003);
			 draw_line(n*128+16+sec, 0x300c);
			 draw_line(n*128+32+sec, 0x0c30);
			 draw_line(n*128+48+sec, 0x03c0);
			 draw_line(n*128+64+sec, 0x03c0);
			 draw_line(n*128+80+sec, 0x0c30);
			 draw_line(n*128+96+sec, 0x300c);
			 draw_line(n*128+112+sec, 0xc003);
			 
			 draw_line(n*128+sec-1, 0x0000);
			 draw_line(n*128+16+sec-1, 0x0000);
			 draw_line(n*128+32+sec-1, 0x0000);
			 draw_line(n*128+48+sec-1, 0x0000);
			 draw_line(n*128+64+sec-1, 0x0000);
			 draw_line(n*128+80+sec-1, 0x0000);
			 draw_line(n*128+96+sec-1, 0x0000);
			 draw_line(n*128+112+sec-1, 0x0000);
		 	
	
	
		while(key_value=Keypad()!=-1)
		{
		  for(a=0 ; a<= 127 ;a++) // 清圖
	    		for(b=0;b<=15;b++)
	    		{
		 			draw_line(16*a+b, 0x0000);
		 		}
		
		
		  	if(n==0)  // 最上邊
		  	{
		   		if((key_value=Keypad())==5)
				{
		   			n++;
				}
				Delay(50);
		  	}
		  	else if(n==15) // 到最下邊
		  	{
		   		if((key_value=Keypad())==4)
				{
		   			n--;
		   		}
				Delay(50);
		  	}
		  	else
		  	{
		   		if((key_value=Keypad())==5)
				{
					n++;
		   		}
				else if((key_value=Keypad())==4)
		   		{
					n--;
		   		}
				Delay(50);
		  	}
		  
		
		}
		
		
		
    }

    DisableInterrupt(BIT_GMASK);
    return 0;
}

