// --------------------------------------------------------------------
//
//   Title     :  DRIVER.C
//             :
//   Library   :
//             :
//   Developers:  MICROTIME MDS group
//             :
//   Purpose   :  Drivers for Creator S3C4510
//             :  TIMER0, 4X4 KEY_PAD, 7_SEG LED
//             :  DIP_SW, HUHU_LED, RTC, EEPROM
//             :
//   Limitation:
//             :
//   Note      :
//             :
// --------------------------------------------------------------------
//   modification history :
// --------------------------------------------------------------------
//   Version| mod. date: |
//   V1.0   | 03/31/2003 | First release
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
#include "driver.h"

/*************************************************************************
Variable define
*************************************************************************/
/*	Global control */
UI cpld_ctrl;
UI io_reg0 ;

/*	Timer0 system tick */
UI tick_ms;
UC tick_sec, tick_min, tick_hour;
UC tick_on;

/*	7_SEG LED */
UC seven_seg_buf[4], seven_seg_idx;
UI tbl_7seg_com[4] = {0x0e00, 0x0d00, 0x0b00, 0x0700};



/*	KEY_PAD */
UI scan_led=0x5500;
UC scan_key, scan_idx, scan_key_in_idx, scan_key_out_idx;
UI scan_key_buf[16], last_scan_key;
UC key_assigned;

/*	I2C */
void    Delay(UI ms);

#define S_WRITE		0x00			//Write IIC data for slave
#define S_READ		0x01			//Read IIC data for slave

#define BF			0x01			//Buffer flag
#define IEN			0x02			//Interrupt enable
#define LRB			0x04			//Last bit received
									//ACK not received
#define ACK			0x08			//Acknowlege enable
									//Generate an ACK signal at 9th SCL
#define NOACK		0x00			//No more received data is required
									//from the slave
#define START		0x10
#define STOP		0x20
#define RESTART		0x30
#define BUSY		0x40
#define IICRESET	0x80			//Reset the IIC-BUS controller

#define WAIT_I2C 	Delay(1);



void Initial_TIMER0(void);



/*************************************************************************
System TICK (TIMER0)

*************************************************************************/
IRQ_ATTR1 void  IRQ_ATTR2 IRQ_TIMER0(void)
{
		UN_CVT cvt;		
		tick_ms++;
		//IOPDATA ^= 0x20000;	//Test
		if((tick_ms & 0xf) == 0) {
			if((scan_key_in_idx+1) == scan_key_out_idx) {	//Key_Pad Overfllow
				//TODO
			}
			else {
				IO_REG2 = scan_led | 0xfe;
				cvt.b[0] = (UC)((IO_REG1 & 0x0f00) >> 8);
				IO_REG2 = scan_led | 0xfd;
				cvt.b[0] |= (UC)((IO_REG1 & 0x0f00) >> 4);
				IO_REG2 = scan_led | 0xfb;
				cvt.b[1] = (UC)((IO_REG1 & 0x0f00) >> 8);
				IO_REG2 = scan_led | 0xf7;
				cvt.b[1] |= (UC)((IO_REG1 & 0x0f00) >> 4);
				if(last_scan_key == cvt.w[0]) {
					if(key_assigned == UM) {
						if(cvt.w[0] != 0xffff) {
							scan_key_buf[scan_key_in_idx++] = cvt.w[0];
							scan_key_in_idx &= 0xf;
						}
						key_assigned = OK;
					}
				}
				else {
					key_assigned = UM;
				}
				last_scan_key = cvt.w[0];
			}
		}
		if((tick_ms % 1000) == 0) {
			//tick_ms = 0;
			tick_on = OK;
			tick_sec++;
			if(tick_sec >= 60) {
				tick_sec = 0;
				tick_min++;
				if(tick_min >= 60) {
					tick_min = 0;
					tick_hour++;
				}
			}
		}	
		ClearPending(BIT_TIMER0);
		//IOPDATA ^= 0x20000;	//Test
}




void Initial_TIMER0(void)
{
		TMOD = 0x00000003;
		TDATA0 = 50000;	//=50000*20ns = 1ms
		
		tick_on = UM;
		tick_ms = 0;
		tick_sec = 0;
		tick_min = 0;
		tick_hour = 0;
		
		pISR_TIMER0 = (unsigned)IRQ_TIMER0;
		ClearPending(BIT_TIMER0);
		EnableInterrupt(BIT_TIMER0);
}


void OptimizationDelay(void)
{
}



void Delay (UI ms)
{
        int i, j;
        UI temp;
        
		if(tick_on == OK) {
			temp = (tick_ms + ms);
			while(temp != tick_ms);
		}
		else {
	        for (i=0; i<ms; i++) {
	            for (j= 0; j < 1000; j++)    {
	            }
	        }
		}

}



/*************************************************************************
4X4 KEY PAD
*************************************************************************/
#define KEY_0 		0xdfff
#define KEY_1 		0xfffe
#define KEY_2 		0xfffd
#define KEY_3 		0xfffb
#define KEY_4 		0xffef
#define KEY_5 		0xffdf
#define KEY_6 		0xffbf
#define KEY_7 		0xfeff
#define KEY_8 		0xfdff
#define KEY_9 		0xfbff
#define KEY_A 		0xfff7
#define KEY_B 		0xff7f
#define KEY_C 		0xf7ff
#define KEY_D 		0x7fff
#define KEY_STAR 	0xefff
#define KEY_POND 	0xbfff


UC Creator_key2num(UI ch);

void Initial_KEYPAD(void)
{
		UC i;
		last_scan_key = 0xffff;
		scan_key_in_idx = 0;
		scan_key_out_idx = 0;
		key_assigned = UM;
		for(i=0; i<16; i++)	scan_key_buf[i] = 0xffff;

}


UC KEYPAD_get_key(UC *ch)
{
		UI temp;

		if(scan_key_out_idx != scan_key_in_idx) {
			temp = scan_key_buf[scan_key_out_idx++];
			scan_key_out_idx &= 0xf;
			*ch = Creator_key2num(temp);
			return(OK);
		}
		return(UM);
}


UC KEYPAD_chk_key(UC *ch)
{
		UI temp;
		if(scan_key_out_idx != scan_key_in_idx) {
			temp = scan_key_buf[scan_key_out_idx];
			*ch = Creator_key2num(temp);
			return(OK);
		}
		return(UM);
}

UI key2num_tbl[16] = {
		KEY_0, KEY_1, KEY_2, KEY_3,
		KEY_4, KEY_5, KEY_6, KEY_7,
		KEY_8, KEY_9, KEY_A, KEY_B,
		KEY_C, KEY_D, KEY_STAR, KEY_POND
		};
	

UC Creator_key2num(UI ch)
{
		UC idx;
		for(idx=0; idx<16; idx++) {
			if(ch == key2num_tbl[idx]) return(idx);
		}
		return(0xff);
}




/*************************************************************************
I2c
*************************************************************************/


void IICSetup(void)
{
	// Reset IIC Controller
	IICCON = IICRESET;

	// Set Prescale Value: fSCL (defined in iic.h) is IIC Serial Clock Frequency.
	IICPS = 63;				//MCLK / (16X(IICPS+1)-3) = 50K
}


void IICWriteRTC(U8 Addr, U8 Data)
{
		U8 SlaveAddr=(0x51<<1);
	
		IICSetup();

		while(IICCON & BUSY);
		IICCON = START|BF;

		while(!(IICCON & BF));
		IICBUF = SlaveAddr|S_WRITE;
		
		WAIT_I2C

		while(!(IICCON & BF));
		IICBUF = Addr;

		WAIT_I2C
		
		while(!(IICCON & BF));
		IICBUF = Data;
	
		WAIT_I2C
	
		IICCON = STOP;
}


U8 IICReadRTC(U8 Addr)
{
		U8 SlaveAddr=(0x51<<1);
		U8 temp;

		IICSetup();

		while(IICCON & BUSY);
		IICCON = START|BF;

		while(!(IICCON & BF));
		IICBUF = SlaveAddr|S_WRITE;

		WAIT_I2C

		while(!(IICCON & BF));
		IICBUF = Addr;

		WAIT_I2C

		while(!(IICCON & BF));
		IICCON = (RESTART|ACK|BF);

		while(!(IICCON & BF));
		IICCON = (START|ACK|BF);

		while(!(IICCON & BF));
		IICBUF = SlaveAddr|S_READ;

		WAIT_I2C

		while(!(IICCON & BF));
		IICCON &= 0xfe;
	
		while(!(IICCON & BF));

		temp = IICBUF;
		IICCON &= 0xf6;
	
		while(!(IICCON & BF));
		IICCON = STOP;
		return(temp);
}


void IICWriteAIC(U8 Addr, U8 Data)
{
		U8 SlaveAddr=0x80;
	
		IICSetup();

		while(IICCON & BUSY);
		IICCON = START|BF;

		while(!(IICCON & BF));
		IICBUF = SlaveAddr|S_WRITE;

		WAIT_I2C

		while(!(IICCON & BF));
		IICBUF = Addr;

		WAIT_I2C

		while(!(IICCON & BF));
		IICBUF = Data;

		WAIT_I2C

		IICCON = STOP;
}


U8 IICReadAIC(U8 Addr)
{
		U8 temp=0;

		if(0) {	//Bug to be fixed
		
		U8 SlaveAddr=0x80;
		
		IICSetup();

		while(IICCON & BUSY);
		IICCON = START|BF;

		while(!(IICCON & BF));
		IICBUF = SlaveAddr|S_WRITE;

		WAIT_I2C

		while(!(IICCON & BF));
		IICBUF = Addr;
		
		WAIT_I2C

		while(!(IICCON & BF));
		IICCON = STOP;

		while(!(IICCON & BUSY));
		IICCON = (START|ACK|BF);

		while(!(IICCON & BF));
		IICBUF = SlaveAddr|S_READ;

		WAIT_I2C

		while(!(IICCON & BF));
		IICCON &= 0xfe;
	
		while(!(IICCON & BF));

		temp = IICBUF;
		IICCON &= 0xf6;
	
		while(!(IICCON & BF));
		IICCON = STOP;
		}
		return(temp);
}


/*************************************************************************
7 SEGMENT LED
*************************************************************************/

const UC LED_tbl[] = {
		0xc0, 0xf9, 0xa4, 0xb0, 0x99,
		0x92, 0x82, 0xf8, 0x80, 0x90,
		0xa0, 0x83, 0xc6, 0xa1, 0x84,
		0x8e, 0x7f, 0xff
		};

void Initial_7SEG(void)
{
		seven_seg_buf[0] = 0x90;
		seven_seg_buf[1] = 0xA3;
		seven_seg_buf[2] = 0xA3;
		seven_seg_buf[3] = 0xA1;
		
}


void _7SEG_put_led(UC digit, UC data)
{
		if(data <= 0x0d) seven_seg_buf[digit] = LED_tbl[data];

}


/*************************************************************************
Real Time Clock
*************************************************************************/
#define RTC_CONTROL1	0x00
#define RTC_CONTROL2	0x01
#define RTC_SECONDS		0x02
#define RTC_MINUTES		0x03
#define RTC_HOURS		0x04
#define RTC_DAYS		0x05
#define RTC_WEEKDAYS	0x06
#define RTC_MONTHS		0x07
#define RTC_YEARS		0x08
#define RTC_M_ALARM		0x09
#define RTC_H_ALARM		0x0A
#define RTC_D_ALARM		0x0B
#define RTC_W_ALARM		0x0C
#define RTC_CLKOUT		0x0D
#define RTC_TIMER_CT	0x0E
#define RTC_TIMER		0x0F

void RTC_set_time(UC sec, UC mins, UC hour, UC day, UC week, UC month, UC year)
{
		IICWriteRTC(RTC_SECONDS, sec);
		IICWriteRTC(RTC_MINUTES, mins);
		IICWriteRTC(RTC_HOURS, hour);
		IICWriteRTC(RTC_DAYS, day);
		IICWriteRTC(RTC_WEEKDAYS, week);
		IICWriteRTC(RTC_MONTHS, month);
		IICWriteRTC(RTC_YEARS, year);
}


void RTC_get_time(UC *sec, UC *mins, UC *hour, UC *day, UC *week, UC *month, UC *year)
{
		*sec = IICReadRTC(RTC_SECONDS) & 0x7f;
		*mins = IICReadRTC(RTC_MINUTES) & 0x7f;
		*hour = IICReadRTC(RTC_HOURS) & 0x3f;
		*day = IICReadRTC(RTC_DAYS) & 0x3f;
		*week = IICReadRTC(RTC_WEEKDAYS) & 0x7;
		*month = IICReadRTC(RTC_MONTHS) & 0x1f;
		*year = IICReadRTC(RTC_YEARS);
}

