//=============================================================================
// File Name : 4510addr.h
// Function  : S3C4510 Define Address Register
// Program   :
// Date      : February 24, 2003
// Version   : 0.0
// History
//   0.0 : Programming start (February 24,2003) -> SOP
//=============================================================================

#ifndef __4510ADDR_H__
#define __4510ADDR_H__

#ifndef __DEF_H__
#include "def.h"
#endif

#ifndef _OPTION_H
#include "option.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif


/*============================================================================================
;System Manager control
;============================================================================================*/
#define SYSCON          (*(volatile unsigned *)0x03FF0000) //System configuration register              ;0x07FFFF91
#define CLKCON          (*(volatile unsigned *)0x03FF3000) //Clock control register                     ;0x00000000
#define EXTACON0        (*(volatile unsigned *)0x03FF3008) //External I/O timing register 1             ;0x00000000
#define EXTACON1        (*(volatile unsigned *)0x03FF300C) //External I/O timing register 2             ;0x00000000
#define EXTDBWTH        (*(volatile unsigned *)0x03FF3010) //Data bus width of each bank                ;0x00000000
#define ROMCON0         (*(volatile unsigned *)0x03FF3014) //ROM/SRAM/Flash bank 0 control register     ;0x20000060
#define ROMCON1         (*(volatile unsigned *)0x03FF3018) //ROM/SRAM/Flash bank 1 control register     ;0x00000060
#define ROMCON2         (*(volatile unsigned *)0x03FF301C) //ROM/SRAM/Flash bank 2 control register     ;0x00000060
#define ROMCON3         (*(volatile unsigned *)0x03FF3020) //ROM/SRAM/Flash bank 3 control register     ;0x00000060
#define ROMCON4         (*(volatile unsigned *)0x03FF3024) //ROM/SRAM/Flash bank 4 control register     ;0x00000060
#define ROMCON5         (*(volatile unsigned *)0x03FF3028) //ROM/SRAM/Flash bank 5 control register     ;0x00000060
#define DRAMCON0        (*(volatile unsigned *)0x03FF302C) //DRAM bank 0 control register               ;0x00000000
#define DRAMCON1        (*(volatile unsigned *)0x03FF3030) //DRAM bank 0 control register               ;0x00000000
#define DRAMCON2        (*(volatile unsigned *)0x03FF3034) //DRAM bank 0 control register               ;0x00000000
#define DRAMCON3        (*(volatile unsigned *)0x03FF3038) //DRAM bank 0 control register               ;0x00000000
#define REFEXTCON       (*(volatile unsigned *)0x03FF303C) //Refresh and external I/O control register ;0x83FD0000


/*============================================================================================
;Ethernet(BDMA) registers
;============================================================================================*/
#define BDMATXCON       (*(volatile unsigned *)0x03FF9000)     // 0x00000000    ; Buffered DMA receive control register
#define BDMARXCON       (*(volatile unsigned *)0x03FF9004)     // 0x00000000    ; Buffered DMA transmit control register
#define BDMATXPTR       (*(volatile unsigned *)0x03FF9008)     // 0xFFFFFFFF    ; Transmit trame descriptor start address
#define BDMARXPTR       (*(volatile unsigned *)0x03FF900C)     // 0xFFFFFFFF    ; Receive frame descriptor start address
#define BDMARXLSZ       (*(volatile unsigned *)0x03FF9010)     // Undefined     ; Receive frame maximum size
#define BDMASTAT        (*(volatile unsigned *)0x03FF9014)     // 0x00000000    ; Buffered DMA status


/*============================================================================================
;Ethernet(MAC) registers
;============================================================================================*/
#define MACON           (*(volatile unsigned *)0x03FFA000)     // 0x00000000    ; Ethernet MAC control register
#define CAMCON          (*(volatile unsigned *)0x03FFA004)     // 0x00000000    ; CAM control register
#define MACTXCON        (*(volatile unsigned *)0x03FFA008)     // 0x00000000    ; MAC transmit control register
#define MACTXSTAT       (*(volatile unsigned *)0x03FFA00C)     // 0x00000000    ; MAC transmit status register
#define MACRXCON        (*(volatile unsigned *)0x03FFA010)     // 0x00000000    ; MAC receive control register
#define MACRXSTAT       (*(volatile unsigned *)0x03FFA014)     // 0x00000000    ; MAC receive status register
#define STADATA         (*(volatile unsigned *)0x03FFA018)     // 0x00000000    ; Station management data
#define STACON          (*(volatile unsigned *)0x03FFA01C)     // 0x00006000    ; Station management control and address
#define CAMEN           (*(volatile unsigned *)0x03FFA028)     // 0x00000000    ; CAM enable register
#define EMISSCNT        (*(volatile unsigned *)0x03FFA03C)     // 0x00000000    ; Missed error count
#define EPZCNT          (*(volatile unsigned *)0x03FFA040)     // 0x00000000    ; Pause count
#define ERMPZCNT        (*(volatile unsigned *)0x03FFA044)     // 0x00000000    ; Read; Remote pause count
#define ETXSTAT         (*(volatile unsigned *)0x03FF9040)     // 0x00000000    ; Read; Transmit control frame status


/*============================================================================================
;HDLC  Channel A Registers
;============================================================================================*/
#define HMODEA          (*(volatile unsigned *)0x03FF7000)     // 0x00000000    ; HDLC mode register
#define MCONA           (*(volatile unsigned *)0x03FF7004)     // 0x00000000    ; HDLC control register
#define HSTATA          (*(volatile unsigned *)0x03FF7008)     // 0x00000000    ; HDLC status register
#define HINTENA         (*(volatile unsigned *)0x03FF700C)     // 0x00000000    ; HDLC interrupt enable register
#define HTXFIFOCA       (*(volatile unsigned *)0x03FF7010)     // 0x00000000    ; TxFIFO frame continue register
#define HTXFIFOTA       (*(volatile unsigned *)0x03FF7014)     // 0x00000000    ; TxFIFO frame terminate register r
#define HRXFIFOA        (*(volatile unsigned *)0x03FF7018)     // 0x00000000    ; THDLC RxFIFO entry register
#define HBRGTCA         (*(volatile unsigned *)0x03FF701C)     // 0x00000000    ; HDLC Baud rate generate time constantr
#define HPRMBA          (*(volatile unsigned *)0x03FF7020)     // 0x00000000    ; HDLC Preamble Constant 0x00000000
#define HSADR0A         (*(volatile unsigned *)0x03FF7024)     // 0x00000000    ; HDLC station address 0
#define HSADR1A         (*(volatile unsigned *)0x03FF7028)     // 0x00000000    ; HDLC station address 1 0x00000000
#define HSADR2A         (*(volatile unsigned *)0x03FF702C)     // 0x00000000    ; HDLC station address 2
#define HSADR3A         (*(volatile unsigned *)0x03FF7030)     // 0x00000000    ; HDLC station address 3
#define HMASKA          (*(volatile unsigned *)0x03FF7034)     // 0x00000000    ; HDLC mask register
#define HDMATXPTRA      (*(volatile unsigned *)0x03FF7038)     // 0xFFFFFFFF    ; DMA Tx buffer descriptor pointer
#define HDMARXPTRA      (*(volatile unsigned *)0x03FF703C)     // 0xFFFFFFFF    ; DMA Rx buffer descriptor pointer
#define HMFLRA          (*(volatile unsigned *)0x03FF7040)     // 0xXXXX0000    ; Maximum frame length register
#define HRBSRA          (*(volatile unsigned *)0x03FF7044)     // 0xXXXX0000    ; DMA receive buffer size register


/*============================================================================================
;HDLC  Channel B Registers
;============================================================================================*/
#define HMODEB          (*(volatile unsigned *)0x03FF8000)     // 0x00000000    ; HDLC mode register
#define MCONB           (*(volatile unsigned *)0x03FF8004)     // 0x00000000    ; HDLC control register
#define HSTATB          (*(volatile unsigned *)0x03FF8008)     // 0x000104000   ; HDLC status register
#define HINTENB         (*(volatile unsigned *)0x03FF800C)     // 0x00000000    ; HDLC interrupt enable register
#define HTXFIFOCB       (*(volatile unsigned *)0x03FF8010)     // 0x00000000    ; TxFIFO frame continue register

#define HRXFIFOB        (*(volatile unsigned *)0x03FF8018)     // 0x00000000    ; HDLC RxFIFO entry register
#define HBRGTCB         (*(volatile unsigned *)0x03FF801C)     // 0x00000000    ; HDLC Baud rate generate time constant
#define HPRMBB          (*(volatile unsigned *)0x03FF8020)     // 0x00000000    ; HDLC Preamble Constant
#define HSAR0B          (*(volatile unsigned *)0x03FF8024)     // 0x00000000    ; HDLC station address 0
#define HSAR1B          (*(volatile unsigned *)0x03FF8028)     // 0x00000000    ; HDLC station address 1
#define HSAR2B          (*(volatile unsigned *)0x03FF802C)     // 0x00000000    ; HDLC station address 2
#define HSAR3B          (*(volatile unsigned *)0x03FF8030)     // 0x00000000    ; HDLC station address 3
#define HMASKB          (*(volatile unsigned *)0x03FF8034)     // 0x00000000    ; HDLC mask register
#define HDMATXPTRB      (*(volatile unsigned *)0x03FF8038)     // 0xFFFFFFFF    ; DMA Tx buffer descriptor pointer
#define HDMARXPTRB      (*(volatile unsigned *)0x03FF803C)     // 0xFFFFFFFF    ; DMA Rx buffer descriptor pointer
#define HMFLRB          (*(volatile unsigned *)0x03FF8040)     // 0x00000000    ; Maximum frame length register
#define HRBSRB          (*(volatile unsigned *)0x03FF8044)     // 0x00000000    ; DMA receive buffer size register


/*============================================================================================
;I/O PORT CONTROL
;============================================================================================*/
#define IOPMOD          (*(volatile unsigned *)0x03FF5000) //I/O port mode register                     ; 0x00000000 All Input
#define IOPCON		(*(volatile unsigned *)0x03FF5004) //I/O port control registerr         ; 0x00000000
#define IOPDATA         (*(volatile unsigned *)0x03FF5008) //I/O port data register                     ; Undefined


/*============================================================================================
;S3C4510B interrupt sources
;============================================================================================*/
#define INTMOD          (*(volatile unsigned *)0x03FF4000)      //Interrupt mode register               ; 0x00000000
#define INTPND          (*(volatile unsigned *)0x03FF4004)      //Interrupt pending register            ; 0x00000000
#define INTMSK          (*(volatile unsigned *)0x03FF4008)      //Interrupt mask register               ; 0x003FFFFF
#define INTPRI0         (*(volatile unsigned *)0x03FF400C)      //Interrupt priority register 0         ; 0x03020100
#define INTPRI1         (*(volatile unsigned *)0x03FF4010)      //Interrupt priority register 1         ; 0x07060504
#define INTPRI2         (*(volatile unsigned *)0x03FF4014)      //Interrupt priority register 2         ; 0x0B0A0908
#define INTPRI3         (*(volatile unsigned *)0x03FF4018)      //Interrupt priority register 3         ; 0x0F0E0D0C
#define INTPRI4         (*(volatile unsigned *)0x03FF401C)      //nterrupt priority register 4          ; 0x13121110
#define INTPRI5         (*(volatile unsigned *)0x03FF4020)      //Interrupt priority register 5         ; 0x00000014
#define INTOFFSET       (*(volatile unsigned *)0x03FF4024)      //Interrupt offset register             ; 0x00000054
#define INTOSET_FIQ     (*(volatile unsigned *)0x03FF4030)      //FIQ Interrupt offset register         ; 0x00000054
#define INTOSET_IRQ     (*(volatile unsigned *)0x03FF4034)      //IRQ Interrupt offset register         ; 0x00000054


/*============================================================================================
;I2C Bus control registers
;============================================================================================*/
#define IICCON          (*(volatile unsigned *)0x03FFF000)     // 0x00000000    ; I2C bus control status register 0x00000054
#define IICBUF          (*(volatile unsigned *)0x03FFF004)     // Undefined     ; I2C bus shift buffer register
#define IICPS           (*(volatile unsigned *)0x03FFF008)     // 0x00000000    ; I2C bus prescaler register
#define IICCOUNT        (*(volatile unsigned *)0x03FFF00C)     // 0x00000000    ; I2C bus prescaler counter register

/*============================================================================================
;GDMA control registers
;============================================================================================*/
#define GDMACON0         (*(volatile unsigned *)0x03FFB000)     // 0x00000000; GDMA controller channel 0 control register
#define GDMACON1         (*(volatile unsigned *)0x03FFC000)     // 0x00000000; GDMA controller channel 1 control register
#define GDMASRC0         (*(volatile unsigned *)0x03FFB004)     // Undefined;  GDMA channel 0 source address register
#define GDMASRC1         (*(volatile unsigned *)0x03FFC004)     // Undefined;  GDMA channel 1 source address register
#define GDMADST0         (*(volatile unsigned *)0x03FFB008)     // Undefined;  GDMA channel 0 destination address register
#define GDMADST1         (*(volatile unsigned *)0x03FFC008)     // Undefined;  GDMA channel 1 destination address register
#define GDMACNT0         (*(volatile unsigned *)0x03FFB00C)     // Undefined;  GDMA channel 0 transfer count register
#define GDMACNT1         (*(volatile unsigned *)0x03FFC00C)     // Undefined;  GDMA channel 1 transfer count register
#define	GDMA0_RUN_ENABLE (*(volatile unsigned *)0x03FFB020)     	
#define	GDMA1_RUN_ENABLE (*(volatile unsigned *)0x03FFC020)	

/*============================================================================================
;UART control registers
;============================================================================================*/
#define ULCON0          (*(volatile unsigned *)0x03FFD000)      //0x00          ; UART channel 0 line control register
#define UCON0           (*(volatile unsigned *)0x03FFD004)      //0x00          ; UART channel 0 control register
#define USTAT0          (*(volatile unsigned *)0x03FFD008)      //0xC0          ; UART channel 0 status register
#define UTXBUF0         (*(volatile unsigned *)0x03FFD00c)      //Undefined     ; UART channel 0 transmit holding register
#define URXBUF0         (*(volatile unsigned *)0x03FFD010)      //Undefined     ; UART channel 0 receive buffer register
#define UBRDIV0         (*(volatile unsigned *)0x03FFD014)      //0x00          ; Baud rate divisor register 0

#define ULCON1          (*(volatile unsigned *)0x03FFe000)      //0x00          ; UART channel 1 line control register
#define UCON1           (*(volatile unsigned *)0x03FFe004)      //0x00          ; UART channel 1 control register
#define USTAT1          (*(volatile unsigned *)0x03FFe008)      //0xC0          ; UART channel 1 status register
#define UTXBUF1         (*(volatile unsigned *)0x03FFe00c)      //Undefined     ; UART channel 1 transmit holding register
#define URXBUF1         (*(volatile unsigned *)0x03FFe010)      //Undefined     ; UART channel 1 receive buffer register
#define UBRDIV1         (*(volatile unsigned *)0x03FFe014)      //0x00          ; Baud rate divisor register 1

#define WrUTXH0(c)      UTXBUF0 = (unsigned char)(c)
#define RdURXH0()       URXBUF0

/*============================================================================================
;Timers control registers
;============================================================================================*/
#define TMOD            (*(volatile unsigned *)0x03FF6000)     // 0x00000000    ; Timer mode register
#define TDATA0          (*(volatile unsigned *)0x03FF6004)     // 0x00000000    ; Timer 0 data register
#define TCNT0           (*(volatile unsigned *)0x03FF600C)     // 0xFFFFFFFF    ; Timer 0 count register
#define TDATA1          (*(volatile unsigned *)0x03FF6008)     // 0x00000000    ; Timer 1 data register
#define TCNT1           (*(volatile unsigned *)0x03FF6010)     // 0xFFFFFFFF    ; Timer 1 count register


// ISR
extern unsigned pISR_RESET ;
extern unsigned pISR_UNDEF;
extern unsigned pISR_SWI;
extern unsigned pISR_PABORT;
extern unsigned pISR_DABORT;
extern unsigned pISR_RESERVED;
extern unsigned pISR_IRQ;
extern unsigned pISR_FIQ;

extern unsigned pISR_EXT0;
extern unsigned pISR_EXT1;
extern unsigned pISR_EXT2;
extern unsigned pISR_EXT3;
extern unsigned pISR_U0TINT;
extern unsigned pISR_U0RERR;
extern unsigned pISR_U1TINT;
extern unsigned pISR_U1RERR;
extern unsigned pISR_GDMA0;
extern unsigned pISR_GDMA1;
extern unsigned pISR_TIMER0;
extern unsigned pISR_TIMER1;
extern unsigned pISR_HDLCTXA;
extern unsigned pISR_HDLCRXA;
extern unsigned pISR_HDLCTXB;
extern unsigned pISR_HDLCRXB;
extern unsigned pISR_ECBDMATx;
extern unsigned pISR_ECBDMARx;
extern unsigned pISR_ECMACTx;
extern unsigned pISR_ECMACRx;
extern unsigned pISR_i2cbus;


// PENDING BIT
#define EXT0            0  /* external interrupt 0             */
#define EXT1            1  /* external interrupt 1             */
#define EXT2            2  /* external interrupt 2             */
#define EXT3            3  /* external interrupt 3             */
#define U0TINT          4  /* uart0 transmit interrupt         */
#define U0RERR          5  /* uart0 receive & error interrupt  */
#define U1TINT          6  /* uart1 transmit interrupt         */
#define U1RERR          7  /* uart1 receive & error interrupt  */
#define GDMA0           8  /* GDMA channel 0 interrupt         */
#define GDMA1           9  /* GDMA channel 1 interrupt         */
#define TIMER0          10  /* timer 0 interrupt                */
#define TIMER1          11  /* timer 1 interrupt                */
#define HDLCTXA         12  /* HDLC channel A TX interrupt      */
#define HDLCRXA         13  /* HDLC channel A Rx interrupt      */
#define HDLCTXB         14  /* HDLC channel B TX interrupt      */
#define HDLCRXB         15  /* HDLC channel B Rx interrupt      */
#define ECBDMATx        16  /* Eternet controller BDMA Tx intrrupt*/
#define ECBDMARx        17  /* Eternet controller BDMA Rx intrrupt*/
#define ECMACTx         18  /* Eternet controller BDMA Tx intrrupt*/
#define ECMACRx         19  /* Eternet controller BDMA Rx intrrupt*/
#define i2cbus          20  /* i2 C-bus interrupt                 */

#define BIT_EXT0        (0x1)
#define BIT_EXT1        (0x1<<1)
#define BIT_EXT2        (0x1<<2)
#define BIT_EXT3        (0x1<<3)
#define BIT_U0TINT      (0x1<<4)
#define BIT_U0RERR      (0x1<<5)
#define BIT_U1TINT      (0x1<<6)
#define BIT_U1RERR      (0x1<<7)
#define BIT_GDMA0       (0x1<<8)
#define BIT_GDMA1       (0x1<<9)
#define BIT_TIMER0      (0x1<<10)
#define BIT_TIMER1      (0x1<<11)
#define BIT_HDLCTXA     (0x1<<12)
#define BIT_HDLCRXA     (0x1<<13)
#define BIT_HDLCTXB     (0x1<<14)
#define BIT_HDLCRXB     (0x1<<15)
#define BIT_ECBDMATx    (0x1<<16)
#define BIT_ECBDMARx    (0x1<<17)
#define BIT_ECMACTx     (0x1<<18)
#define BIT_ECMACRx     (0x1<<19)
#define BIT_i2cbus      (0x1<<20)
#define BIT_GMASK       (0x1<<21)
#define BIT_ALLMSK      (0xffffffff)


#define ClearPending(bit) {INTPND = (bit);}

#define EnableInterrupt(x)       INTMSK &= (~x);
#define DisableInterrupt(x)      INTMSK |= (x);



/*============================================================================================
;Peripheral control registers
;============================================================================================*/
#define ECS0_BASE 		0x03F00000

#define CF_TASK_BASE 	(ECS0_BASE+0x0000)	/* CF_nCS0 */
#define CF_STATUS_BASE	(ECS0_BASE+0x0200)	/* CF_nCS1 : not used */

#define ATA_BYTDATREG   (*(unsigned short *)(CF_TASK_BASE+0x0000)) /* DATA read/write */
#define ATA_ERRFEAREG   (*(unsigned short *)(CF_TASK_BASE+0x0002)) /* read error/write feature */
#define ATA_SECTCOUNT   (*(unsigned short *)(CF_TASK_BASE+0x0004)) /* sector count */
#define ATA_SECTORNO    (*(unsigned short *)(CF_TASK_BASE+0x0006)) /* sector number */
#define ATA_CYLINDLOW   (*(unsigned short *)(CF_TASK_BASE+0x0008)) /* cylinder low */
#define ATA_CYLINDHI    (*(unsigned short *)(CF_TASK_BASE+0x000A)) /* cylinder high */
#define ATA_SCARDHEAD   (*(unsigned short *)(CF_TASK_BASE+0x000C)) /* select card/head */
#define ATA_STATCOMMD   (*(unsigned short *)(CF_TASK_BASE+0x000E)) /* read status/write command */

#define USB_DATA 		(*(unsigned short *)(ECS0_BASE+0x0400))
#define USB_CMD 		(*(unsigned short *)(ECS0_BASE+0x0402))
#define CCM_DATA 		(*(unsigned short *)(ECS0_BASE+0x0600))
#define LCD_CMD 		(*(unsigned short *)(ECS0_BASE+0x0800))
#define LCD_DATA 		(*(unsigned short *)(ECS0_BASE+0x0802))
#define CODEC_DATA 		(*(unsigned short *)(ECS0_BASE+0x0A00))
#define IO_REG0			(*(unsigned short *)(ECS0_BASE+0x0C00))
#define IO_REG1 		(*(unsigned short *)(ECS0_BASE+0x0C02))	
#define IO_REG2 		(*(unsigned short *)(ECS0_BASE+0x0C04))	
#define CPLD_CTRL 		(*(unsigned short *)(ECS0_BASE+0x0E00))	/* Write */
						//00	: IO_nRST
						//01	: AIC_ON
						//02	: EXPTM1
						//03	: EXPTM2
						//04	: FPGA_nPGM
						//05	: FPGA_CCLK
						//06	: IRQ3_SEL
						//07	: DMA_SEL
#define CPLD_STATUS		(*(unsigned short *)(ECS0_BASE+0x0E00))	/* Read */
						//00 	: EE_DO
						//01 	: USB_nEOT
						//02 	: USB_ON
						//03 	: NA
						//04 	: CCD_nRDY
						//05-15 : 0


#ifdef __cplusplus
}
#endif
#define inl(addr)        (addr)
#define outl(data, addr) ((addr) = (data))

#endif
