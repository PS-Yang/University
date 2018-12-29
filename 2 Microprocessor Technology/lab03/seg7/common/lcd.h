#ifndef _LCD_H_ 
#define _LCD_H_ 

// ��ЦU�ؾާ@�Ҧ�
#define WHITE_BLINK_CURSOR		0	// �զ�{�{���
#define BLACK_BLINK_CURSOR		1	// �¦�{�{���
#define REVERSE_CURSOR			2	// �¥ե洫�����
#define REVERSE_BLINK_CURSOR		3	// �¥հ{�{�洫�����


#define TABS				4	// �h�֪ťզr�N��TAB

// Ū�gLCD RAM��Macro 
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

