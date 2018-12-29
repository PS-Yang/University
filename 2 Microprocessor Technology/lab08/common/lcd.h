#ifndef _LCD_H_ 
#define _LCD_H_ 

// 游標各種操作模式
#define WHITE_BLINK_CURSOR		0	// 白色閃爍游標
#define BLACK_BLINK_CURSOR		1	// 黑色閃爍游標
#define REVERSE_CURSOR			2	// 黑白交換的游標
#define REVERSE_BLINK_CURSOR		3	// 黑白閃爍交換的游標


#define TABS				4	// 多少空白字代表TAB

// 讀寫LCD RAM的Macro 
#define SET_ADDRESS_LCD(x)		WriteLCD(LCD_RAM_ADDR, x);
#define SET_RAM_DATA_LCD(x)		WriteLCD(LCD_RAM_DATA, x);

void LCD_printf (char *fmt,...);
void LCD_Cursor(int x, int y);
unsigned short ReadLCD (unsigned short addr);
void WriteLCD (unsigned short addr, unsigned short data);
void LCD_ClearViewArea (void);
void LCD_PutRAMData (unsigned short address, unsigned short data);
void LCD_ClearScreen (void);
void LCD_ClearOneLine (int y);
void LCD_scroll (void);
void LCD_displ (int x, int y, int ch);
void LCD_putchar (char c);
void LCD_CursorMode (unsigned char Mode);
void LCD_EnableCursor (int bCursorOn);
void LCD_SetCursor(int x, int y);
void InitialLCD (void);
void Initial_LCD (void);

static void OptimizationDelay(void) {}	// for Optimization
static void ScanTimer(void);


#endif /*_LCD_H_ */

