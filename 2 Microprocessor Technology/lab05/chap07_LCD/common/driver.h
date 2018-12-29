#ifndef _4510LIB_H
#define _4510LIB_H

#ifndef __4510ADDR_H__
#include        "4510addr.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************
Global Variables
*************************************************************************/
extern UI  cpld_ctrl;
extern UI  io_reg0;

extern UI tick_ms;
extern UC tick_sec, tick_min, tick_hour;

extern UC seven_seg_buf[];

extern UI scan_led;

extern UI scan_key_buf[];
extern UC scan_key, scan_idx, scan_key_in_idx, scan_key_out_idx, key_assigned;
extern UI last_scan_key;


/*************************************************************************
System
*************************************************************************/
#define min(x1,x2) (((x1)<(x2))? (x1):(x2))
#define max(x1,x2) (((x1)>(x2))? (x1):(x2))

UC	 	GetIntNumRange (UC MinNum, UC MaxNum);


/*************************************************************************
LCD Routines
*************************************************************************/
void 	Initial_LCD (void);
void 	DrawImage(UI *pImageBuffer);
void 	LCD_PutRAMData (UI address, UI data);
UI 	LCD_GetRAMData (UI address);

void LCD_ClearScreen (void);
void LCD_ClearOneLine (int y);
void LCD_printf (char *fmt,...);
void LCD_putchar (char c);
void LCD_scroll (void);
void LCD_displ (int x, int y, int ch);
void LCD_CursorMode (unsigned char Mode);
void LCD_EnableCursor (int bCursorOn);
void LCD_Cursor(int x, int y);

/*************************************************************************
CCM Routines
*************************************************************************/
#define CCM_OK		1
#define CCM_IMG_ERR	-1
#define CCM_SYN_ERR	-2
#define CCM_READ_ERR	-3
/*
Input Parameter : 
Return value:
	1 	= Command successfully.
 	-1	= Image Size Mode Error.
 	-2 	= Initla Image Sensor error.
 	-3 	= Read image pixel error	
*/
int 	CaptureImage_CCM (int ImgWidth, int ImgHeight, UC highRef, UC byFilterNoise, UC SyncCCM, UC *pRawBuffer, UC *pBmpBuffer, UC *pnoiseBuffer);
UC  	ProcessCCM(void);

/*************************************************************************
UART Routines
*************************************************************************/
void 	Initial_UART (void);
void 	UART_put_char(UC dev_no, UC so_data);
UC   	UART_get_char(UC dev_no, UC *ch);


/*************************************************************************
CODEC Routines
*************************************************************************/
void 	Initial_CODEC(void);
void 	CODEC_malloc(UL size);
void 	CODEC_mfree(void);
void 	CODEC_Start(void);
void 	CODEC_Stop(void);
void 	CODEC_Record_Start(void);
void 	CODEC_Record_Stop(void);
void 	CODEC_Play_Start(void);
void 	CODEC_Play_Stop(void);


/*************************************************************************
IIC Routines
*************************************************************************/
#define WAIT_I2C 	Delay(1);

void 	IICSetup(void);
void 	IICWriteRTC(U8 Addr, U8 Data);
U8 		IICReadRTC(U8 Addr);
void 	IICWriteAIC(U8 Addr, U8 Data);
U8 	 	IICReadAIC(U8 Addr);


/*************************************************************************
RTC Routines
*************************************************************************/
void 	RTC_set_time(UC sec, UC mins, UC hour, UC day, UC week, UC month, UC year);
void 	RTC_get_time(UC *sec, UC *mins, UC *hour, UC *day, UC *week, UC *month, UC *year);


/*************************************************************************
TIMER0 (SYSTEM TICK) Routines
*************************************************************************/
void 	Initial_TIMER0(void);
void 	OptimizationDelay(void);
void    Delay(UI ms);
void	Creator_print_time(void);

/*************************************************************************
DIPSW Routines
*************************************************************************/
UC 		DIPSW_get_sw(void);

/*************************************************************************
HUHU LED Routines
*************************************************************************/
void 	HUHU_put_led(UC led);


/*************************************************************************
KEYPAD Routines
*************************************************************************/
#define KEY_S 	0xE		// KEY_STAR
#define KEY_P 	0xF		// KEY_POUND

void 	Initial_KEYPAD(void);
UC 		KEYPAD_get_key(UC *ch);
UC 		KEYPAD_chk_key(UC *ch);


/*************************************************************************
7 SEG LED Routines
*************************************************************************/
void 	Initial_7SEG(void);
void 	_7SEG_put_led(UC digit, UC data);


/*************************************************************************
CF Card Routines
*************************************************************************/
void 	AtaGetID(void);
UI 	AtaReadWord(void);
void 	AtaBusyStatusCheck(void);
void 	AtaReadyStatusCheck(void);
UI	AtaDrqStatusCheck(void);


/*************************************************************************
EEPROM Routines
*************************************************************************/
void 	EE_WRITE(U8 addr, U8 data);
U8 	EE_READ(U8 addr);


/*************************************************************************
USB Routines
*************************************************************************/
void 	CMD_USB(void);



#ifdef __cplusplus
}
#endif

#endif // _4510LIB_H
