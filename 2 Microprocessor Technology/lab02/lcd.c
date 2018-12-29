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

//��LCDŪ�����
 unsigned short ReadLCD (unsigned short addr)
{
	unsigned short data;

	LCD_CMD = 0xff;			//MSB
	OptimizationDelay();		//for Optimization	
	LCD_CMD = addr;			//LSB
	data = LCD_DATA << 8;		//MSB
	data |= LCD_DATA;		//LSB

	// �Y�OŪ��LCD����ܰϰ�CGRAM��Ʈ�, 
	// �Ĥ@����ƬO���X�k, �ĤG���~�O���T���
	if (addr == LCD_RAM_DATA) {
	    LCD_CMD = 0xff;		//MSB
    	    OptimizationDelay();	//for Optimization	    
	    LCD_CMD = addr;		//LSB
	    data = LCD_DATA << 8;	//MSB
	    data |= LCD_DATA;		//LSB
	}
	return (data);
}



//��LCD�]�w���
 void WriteLCD (unsigned short addr, unsigned short data)
{
	LCD_CMD = 0xff;			//MSB
	OptimizationDelay();		//for Optimization	
	LCD_CMD = addr;			//LSB
		
	LCD_DATA = (data >> 8) ;	//MSB
	OptimizationDelay();		//for Optimization	
	LCD_DATA = data;		//LSB
}



//�M��LCD�e��, �í��s�]�w��������
 void LCD_ClearViewArea (void)
{
	int	i;
	
	SET_ADDRESS_LCD(0);		//�]�w�}�l�g�J��LCD RAM���_�l��}
	for (i=0; i < 0x800; i++)	//�M��LCD�e��
	    SET_RAM_DATA_LCD(0);
	    
	WriteLCD(LCD_VET_SCROLL, 0);	//���s�]�w��������	
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


//�N��Ƽg�JLCD����ܰϰ줺
void LCD_PutRAMData (unsigned short address, unsigned short data)
{
	SET_ADDRESS_LCD(address);	//�]�wLCD��ܰϰ�RAM����}
	SET_RAM_DATA_LCD(data);		//�N�ҫ��w����Ƽg�J�ҫ��wLCD��ܰϰ�RAM
}



//�M�����LCD������ť�, �åB��Э��s�k�쬰���I
void LCD_ClearScreen (void)
{
        LCD_ClearViewArea();
        Xpos = Ypos = YScrollOffset = 0;
        WriteLCD(LCD_VET_SCROLL, 0);
    	LCD_SetCursor(Xpos, Ypos);		
}



//�NLCD�Y���ܦ��ťզ�
 void LCD_ClearOneLine (int y)
{
        int             x;

        for (x=0; x < ScrWidth; x++)	
            LCD_displ(x, y, ' ');	//�bX,Y�g�J�ťզr��
        Xpos = 0;
}



//LCD���W�������ʤ@��
 void LCD_scroll (void)
{
        if (YScrollOffset == 0)
            YScrollOffset = ScrHeight - 1;
        else
            YScrollOffset--;

        WriteLCD(LCD_VET_SCROLL, byFontHeight * (Ypos - YScrollOffset + 1));
        LCD_ClearOneLine(Ypos);		//�̤U���@��M�����ťզ�
}



//�N��@�Ӧr���g�JLCD
 void LCD_displ (int x, int y, int ch)
{
        unsigned short  addr, data ;
        int             i, YRelation;

	//�i��ܦۤ��d��q0x20~0x7E
	//��l�Ϊťը��N
        data = (ch >= 0x20 && ch <= 0x7E) ? ch : ' ';
        
        //�p��r���Ҧb��m
        YRelation = y - YScrollOffset;
        addr = x + (YRelation * 0x80);

	//���X�r�����ϫ���ƫ�g�JLCD
	for (i=0; i < byFontWidth; i++){
            LCD_PutRAMData(addr, charset[data][i]);
            addr += 0x10;
        }
}



//�N��@�Ӧr���g�J��ܸ˸m
 void LCD_putchar (char c)
{
        switch (c){
        case '\n' :			//����r�� 
            if (Ypos == (ScrHeight-1))	//�p�G��F�̫�@��N���W���ʤ@��
                LCD_scroll();
            else
                Ypos++;
            Xpos = 0;
            break ;
        case '\t' :			//TAB�r���Ϊťզr������
            do LCD_putchar(' ');
            while (Xpos%TABS);
            break ;
        default :			//��W�L�C��̤j�e�׮ɦ۰ʴ���
            if ((Xpos+1) >= ScrWidth){
                LCD_putchar('\n');
            }
            LCD_displ(Xpos++, Ypos, c);	//�N�r���g�JLCD
            break ;
        }
        if (byCursorOn)			
            LCD_SetCursor(Xpos, Ypos);	//���ʴ�Ш���㦡���r���᭱
}



//�]�w��мҦ�
 void LCD_CursorMode (unsigned char Mode)
{
        byCursorMode = Mode & 0x3;
}



//�Ұ�/�������
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



//Ū����Ц�m
 void LCD_GetCursor(int *x, int *y)
{
	*x = Xpos ; *y = Ypos;		
}



//�]�w��Ц�m
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



// ��l��LCD���R�O��
 void InitialLCD (void)
{
	int 	i;
	
	//LCD��l�R�O�P�B
	for (i=0; i < 4; i++){
            LCD_CMD = 0;			//�P�B�R�O
            OptimizationDelay();
        }
		
	WriteLCD(LCD_START_OSC, 1);		//���s�Ұ�LCD 
	Delay(15);				//���𵥫�LCD�i�Jí�w�u�@���A
	
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
	
	LCD_ClearScreen();			//�M���e�����ť�	
}



// �W�eLCD�ާ@�Ҧ�
// �`�@�h�֦�, �C��h�֦r
// �]�w��Ы��A
void Initial_LCD (void)
{
        byFontHeight = 8;			//��r�r�����׬�8
        byFontWidth = 8;			//��r�r���e�׬�8
        ScrWidth = 128 / byFontWidth;		//LCD�C��@�h�֤�r
        ScrHeight = 128 / byFontHeight;		//LCD�`�@���h�֦�
        
        InitialLCD();				//LCD�u�@�Ҧ��]�w
        
        LCD_CursorMode(BLACK_BLINK_CURSOR);	//�¦�{�{�����
        LCD_EnableCursor(UM);			//�Ұʴ��
        
}
