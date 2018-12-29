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
void shift_left(unsigned short line, unsigned short vertical);
const char pattern[4][3] ={"000", "010","010", "011"}; 
		
unsigned short row, col, new_row, new_col; 		
				      
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


int main(void)
{
         
        unsigned short  addr;
        unsigned short  i,j,l,r;

	    Initial_Creator();
        Initial_LCD();
		
		
       while(1)
       {   									
          	 draw_line(0, 0xF000);			// 此為PPT第五頁code
			 draw_line(32, 0x0F00);			// addr 16 為一個row
			 draw_line(64, 0x00F0);			//.隔一行顯示在LCD上.比較看得清楚
			 draw_line(96, 0x000F);
			 draw_line(128, 0xC33C);
			 draw_line(160, 0x3333);
      }
        return(0);
}

