 // creator-s3c4510-codec. c --  s3c4510 processor with a TLV320AIC12 codec.
#include    <4510addr.h>
#include    <lcd.h>
#include    "GenFont8_8.h"
#include    <stdarg.h>
#include    <string.h>
#include    <stdio.h>
#include    <stdlib.h>

enum LCDCommand{
	LCD_START_OSC=0,		// Start oscillation	
	LCD_DEVICE_CODE=0,		// Device code read	
	LCD_DRV_OUT=1,			// Driver output control
	LCD_WAVEFORM=2,			// LCD-driving-waveform control
	LCD_PWR_CONTROL=3,		// Power control
	LCD_CONTRAST=4,			// Contrast control
	LCD_ENTRY_MODE=5,		// Entry mode
	LCD_ROTATION=6,			// Rotation
	LCD_DISPLAY=7,			// Display control		
	LCD_CURSOR=8,			// Cursor control
	LCD_DB_HEIGHT=9,		// Double-height display position
	LCD_VET_SCROLL=0xa,		// Vertical scroll
	LCD_HOR_CURSOR_POS=0xb,		// Horizontal cursor position
	LCD_VER_CURSOR_POS=0xc,		// Vertical cursor position
	LCD_RAM_MASK=0x10,		// RAM write data mask
	LCD_RAM_ADDR=0x11,		// RAM address set
	LCD_RAM_DATA=0x12,		// RAM Data
	LCD_RAM_WR=0x12,		// RAM data write
	LCD_RAM_RD=0x12			// RAM data read
};

static unsigned char       Xpos, Ypos, ScrWidth, ScrHeight,YScrollOffset;
static unsigned char       byFontHeight, byFontWidth;
static unsigned char       byCursorOn, byCursorMode;

static unsigned short io_reg0 ;

//對LCD讀取資料
 unsigned short ReadLCD (unsigned short addr)
{
	unsigned short data;

	LCD_CMD = 0xff;			//MSB
	OptimizationDelay();		//for Optimization	
	LCD_CMD = addr;			//LSB
	data = LCD_DATA << 8;		//MSB
	data |= LCD_DATA;		//LSB

	// 若是讀取LCD的顯示區域CGRAM資料時, 
	// 第一次資料是不合法, 第二次才是正確資料
	if (addr == LCD_RAM_DATA) {
	    LCD_CMD = 0xff;		//MSB
    	    OptimizationDelay();	//for Optimization	    
	    LCD_CMD = addr;		//LSB
	    data = LCD_DATA << 8;	//MSB
	    data |= LCD_DATA;		//LSB
	}
	return (data);
}



//對LCD設定資料
 void WriteLCD (unsigned short addr, unsigned short data)
{
	LCD_CMD = 0xff;			//MSB
	OptimizationDelay();		//for Optimization	
	LCD_CMD = addr;			//LSB
		
	LCD_DATA = (data >> 8) ;	//MSB
	OptimizationDelay();		//for Optimization	
	LCD_DATA = data;		//LSB
}



//清除LCD畫面, 並重新設定垂直捲動
 void LCD_ClearViewArea (void)
{
	int	i;
	
	SET_ADDRESS_LCD(0);		//設定開始寫入的LCD RAM的起始位址
	for (i=0; i < 0x800; i++)	//清除LCD畫面
	    SET_RAM_DATA_LCD(0);
	    
	WriteLCD(LCD_VET_SCROLL, 0);	//重新設定垂直捲動	
}



/* ------------------ printf  ----------------------------------------- */
void LCD_printf (char *fmt,...)
{
        va_list     ap;
        char        string[512], *p=string;

        va_start(ap, fmt);
        vsprintf(string, fmt, ap);
        va_end(ap);
        while (*p)
            LCD_putchar(*p++);
}

/* ------------------ set cursor -------------------------------------- */
void LCD_Cursor(int x, int y)
{
        unsigned short  HS, HE, VS;

        HS = x * byFontWidth;
        HE = HS + (byFontWidth - 1);
        WriteLCD(LCD_HOR_CURSOR_POS, (HE << 8) + HS);

        VS = (y + 1) * byFontHeight - 2;
        //VE = VS + (byFontHeight - 1);
        WriteLCD(LCD_VER_CURSOR_POS, ((VS+1)<<8) + VS);
        
        Xpos = x; Ypos = y;
}


//將資料寫入LCD的顯示區域內
void LCD_PutRAMData (unsigned short address, unsigned short data)
{
	SET_ADDRESS_LCD(address);	//設定LCD顯示區域RAM的位址
	SET_RAM_DATA_LCD(data);		//將所指定的資料寫入所指定LCD顯示區域RAM
}



//清除整個LCD營幕成空白, 並且游標重新歸位為原點
void LCD_ClearScreen (void)
{
        LCD_ClearViewArea();
        Xpos = Ypos = YScrollOffset = 0;
        WriteLCD(LCD_VET_SCROLL, 0);
    	LCD_SetCursor(Xpos, Ypos);		
}



//將LCD某行變成空白行
 void LCD_ClearOneLine (int y)
{
        int             x;

        for (x=0; x < ScrWidth; x++)	
            LCD_displ(x, y, ' ');	//在X,Y寫入空白字元
        Xpos = 0;
}



//LCD往上垂直捲動一行
 void LCD_scroll (void)
{
        if (YScrollOffset == 0)
            YScrollOffset = ScrHeight - 1;
        else
            YScrollOffset--;

        WriteLCD(LCD_VET_SCROLL, byFontHeight * (Ypos - YScrollOffset + 1));
        LCD_ClearOneLine(Ypos);		//最下面一行清除為空白行
}



//將單一個字元寫入LCD
 void LCD_displ (int x, int y, int ch)
{
        unsigned short  addr, data ;
        int             i, YRelation;

	//可顯示自元範圍從0x20~0x7E
	//其餘用空白取代
        data = (ch >= 0x20 && ch <= 0x7E) ? ch : ' ';
        
        //計算字元所在位置
        YRelation = y - YScrollOffset;
        addr = x + (YRelation * 0x80);

	//取出字元的圖型資料後寫入LCD
	for (i=0; i < byFontWidth; i++){
            LCD_PutRAMData(addr, charset[data][i]);
            addr += 0x10;
        }
}



//將單一個字元寫入顯示裝置
 void LCD_putchar (char c)
{
        switch (c){
        case '\n' :			//換行字元 
            if (Ypos == (ScrHeight-1))	//如果到達最後一行將往上捲動一行
                LCD_scroll();
            else
                Ypos++;
            Xpos = 0;
            break ;
        case '\t' :			//TAB字元用空白字元替換
            do LCD_putchar(' ');
            while (Xpos%TABS);
            break ;
        default :			//當超過每行最大寬度時自動換行
            if ((Xpos+1) >= ScrWidth){
                LCD_putchar('\n');
            }
            LCD_displ(Xpos++, Ypos, c);	//將字元寫入LCD
            break ;
        }
        if (byCursorOn)			
            LCD_SetCursor(Xpos, Ypos);	//移動游標到所顯式的字元後面
}



//設定游標模式
 void LCD_CursorMode (unsigned char Mode)
{
        byCursorMode = Mode & 0x3;
}



//啟動/關閉游標
void LCD_EnableCursor (int bCursorOn)
{
        unsigned short  data;

        byCursorOn = bCursorOn;
        if (byCursorOn)
            data = byCursorMode | 0x04;
        else
            data = 0;
        WriteLCD(LCD_CURSOR, data);
}



//讀取游標位置
 void LCD_GetCursor(int *x, int *y)
{
	*x = Xpos ; *y = Ypos;		
}



//設定游標位置
 void LCD_SetCursor(int x, int y)
{
        unsigned short  HS, HE, VS;

        HS = x * byFontWidth;
        HE = HS + (byFontWidth - 1);
        WriteLCD(LCD_HOR_CURSOR_POS, (HE << 8) + HS);

        VS = (y + 1) * byFontHeight - 2;
        WriteLCD(LCD_VER_CURSOR_POS, ((VS+1)<<8) + VS);
        
        Xpos = x; Ypos = y;
}


 void 
LCD_DrawFullImage (unsigned short *pImageBuffer)
{
	int	i;
	
	SET_ADDRESS_LCD(0);
	
	for (i=0; i < 0x800; i++){
	    SET_RAM_DATA_LCD(pImageBuffer[i]);
	}
}



// 初始化LCD的命令集
 void InitialLCD (void)
{
	int 	i;
	
	//LCD初始命令同步
	for (i=0; i < 4; i++){
            LCD_CMD = 0;			//同步命令
            OptimizationDelay();
        }
		
	WriteLCD(LCD_START_OSC, 1);		//重新啟動LCD 
	Delay(15);				//延遲等待LCD進入穩定工作狀態
	
	//128 * 128 ; Inervt COM & SEG
	//CMS=1, SGS=1, CN=0, NL3-0=1111:128*128 dots, 
	WriteLCD(LCD_DRV_OUT, 0x030f);		
	
	//B/C=0, EOR=0, NW4-0=0000
	WriteLCD(LCD_WAVEFORM, 0);		
	
	//BS2-0=000:1/11 bias driver, BT1-0=10:Six-times boost
	//DC1-0=11:4-divided clock, AP1-0=11:Large, 
	//SLP=0, Sleep mode off, STB=0:Standby mode off)
	WriteLCD(LCD_PWR_CONTROL, 0x23c);	
	
	//CT5-0=011000:
	WriteLCD(LCD_CONTRAST, 0x18);		
	
	//I/D=1:Increment by 1, AM1-0=00:Horizontal move, LG1=00:Replace mode)
	WriteLCD(LCD_ENTRY_MODE, 0x10);		
	
	//RT2-0=000:No shift)
	WriteLCD(LCD_ROTATION, 0);		
	
	//C=1:Cursor display started, CM1-0=00:White-blink cursor) 
	WriteLCD(LCD_CURSOR, 4);		
	
	//DE6-0=0000000:, DS6-0=0000000:
	WriteLCD(LCD_DB_HEIGHT, 0);		
	
	//SL6-0=0000000:First raster-row displayed at the top
	WriteLCD(LCD_VET_SCROLL, 0);		
	
	//HE6-0=HS6-0=VE6-0=VS6-0=0000000
	WriteLCD(LCD_HOR_CURSOR_POS, 0);		
	
	//VM15-0=0000H:No mask
	WriteLCD(LCD_RAM_MASK, 0);		
	
	//AD10-0=000H
	WriteLCD(LCD_RAM_ADDR, 0);		
	
	//PS1-0=00:Partial scroll off, DHE=0:Double-height display off,
	//GS=0, REV=0, D=1:Dispkay on
	WriteLCD(LCD_DISPLAY, 1);		
	
	LCD_ClearScreen();			//清除畫面成空白	
}



// 規畫LCD操作模式
// 總共多少行, 每行多少字
// 設定游標型態
void Initial_LCD (void)
{
        byFontHeight = 8;			//文字字型高度為8
        byFontWidth = 8;			//文字字型寬度為8
        ScrWidth = 128 / byFontWidth;		//LCD每行共多少文字
        ScrHeight = 128 / byFontHeight;		//LCD總共有多少行
        
        InitialLCD();				//LCD工作模式設定
        
        LCD_CursorMode(BLACK_BLINK_CURSOR);	//黑色閃爍的游標
        LCD_EnableCursor(UM);			//啟動游標
        
}
