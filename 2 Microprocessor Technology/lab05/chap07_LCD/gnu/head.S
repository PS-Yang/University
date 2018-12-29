/*
 *  head.S
 *
 *  Copyright (C) 2003 Microtime Computer Inc.
 *
 *  32-bit startup code for s3c5410b Creator EV board
 */

#include "config.h"
#include "memcfg_h.s"

	.global stext
	.global main
	.global __gccmain

.section ".stext"

	.equ	USER_MODE, 	0x10
        .equ 	FIQ_MODE ,   	0x11
        .equ 	IRQ_MODE ,   	0x12
        .equ 	SVC_MODE ,   	0x13
      	.equ 	ABORT_MODE ,   	0x17
      	.equ 	UNDEF_MODE ,   	0x1b
       	.equ	MODE_MASK  ,  	0x1f
        .equ 	NOINT ,		0xc0
	.equ 	ROM0_SIZE		, 0x200000
	.equ 	SDRAM0_BASE_FOR_LOADER	, 0x1000000
		
	.macro HANDLER HandleLabel
        SUB	  sp,sp,#4
        STMFD	  sp!,{r0}
        LDR       r0,=\HandleLabel
        LDR       r0,[r0]         
        STR       r0,[sp,#4]      
        LDMFD     sp!,{r0,pc}     
        .endm


stext:

	LDR     PC, Addr_Reset
	LDR     PC, Addr_Undefined
	LDR     PC, Addr_Swi
	LDR     PC, Addr_Prefetch
	LDR     PC, Addr_Dabort
	b	.                            
	LDR     PC, Addr_IRQ
	LDR     PC, Addr_FIQ



Addr_Reset:     .long     ResetHandler
Addr_Undefined: .long     HandlerUndef
Addr_Swi:	.long     HandlerSWI
Addr_Prefetch: 	.long     HandlerPabort
Addr_Dabort:    .long     HandlerDabort
                .long     0 
Addr_IRQ:      	.long     HandlerIRQ
Addr_FIQ:      	.long     HandlerFIQ


HandlerFIQ:    HANDLER pISR_FIQ
HandlerIRQ:    HANDLER pISR_IRQ
HandlerUndef:  HANDLER pISR_Undef
HandlerSWI:    HANDLER pISR_SWI
HandlerDabort: HANDLER pISR_Dabort
HandlerPabort: HANDLER pISR_Pabort             



IsrIRQ:
        SUBS	LR,LR,#4
        STMFD   sp!,{r0-r12,LR}

        LDR     r9,=INTOSET_IRQ
        LDR     r9,[r9]
        LDR     r8,=pISR_EXT0
        MOV	LR,pc		@setup LR
        LDR     pc,[r8,r9]	@b irq_routine
        
        LDMFD   sp!,{r0-r12,pc}^

IsrSWI:
        MOVS	PC,LR



ResetHandler:


        LDR     r0,=INTMSK
        LDR     r1,=0x003FFFFF  @all interrupt disable
        STR     r1,[r0]

        @
        @Set memory control registers
        @
        LDR     r0,=SMRDATA
        LDR     r1,=SYSCFG                      @SYSCON Address
        LDR     r3, [r0], #4
        STR     r3, [r1], #0

        LDR     r1,=CLKCON                      @CLKCON Address
        LDR     r3, [r0], #4
        STR     r3, [r1], #0

        LDR     R0,=SMRDATA1
        LDMIA   R0,{R1-R3}
        LDR     R0,=EXTACON0
        STMIA   R0,{R1-R3}

.ifdef LOADER

        LDR     R0,=LOADER_MAP		@setup ROMCON0..5,DRAMCON0..3,REFEXTCON
        LDMIA   R0,{R1-R11}
        LDR     R0,=ROMCON0
        STMIA   R0,{R1-R11}

	LDR	R0,=0
	LDR	R1,=ROM0_SIZE
	LDR	R2,=SDRAM0_BASE_FOR_LOADER
Relocate:
	LDR	R3,[R0],#4
	STR	R3,[R2],#4
	SUBS	R1,R1,#4
	BNE	Relocate
.endif

        LDR     R0,=SMRDATA2
        LDMIA   R0,{R1-R11}
        LDR     R0,=ROMCON0
        STMIA   R0,{R1-R11}

   


cstartup:

	
/*
 * SysInitVars: Initialise the DATA and BSS sections.
 *
 * The DATA section is initialised by copying data from the end of the
 * ROM image (given by _etext) to the start of the RAM image
 * (given by _sdata), stopping when we reach _edata.
 * All data from _sbss to _ebss is then cleared to 0
 */

/*
 * Load up the linker defined values for the static data copy
 */
	ldr	r0, =_etext
	ldr	r1, =_sdata
	ldr	r3, =_sbss

/*
 * But first check whether we are trying to copy to the same address.
 * If so, this means that the image was linked as an application image
 * with the DATA section immediately following the CODE section.
 * Therefore there is nothing to copy since the data is already in place
 */
	cmp	r0, r1
	beq	1f

/*
 * Stop on Carry Set (ie R1 becomes >= R3).
 */
0:	cmp	r1, r0
	ldrcc	r2, [r0], #4
	strcc	r2, [r3], #4
	bcc	0b

/*
 * Clear remainder of data to _end to 0
 */
1:	ldr	r1, =_ebss
	mov	r2, #0
2:	cmp	r3, r1
	strcc	r2, [r3], #4
	bcc	2b

        @ Setup IRQ handler
        LDR     r0,=pISR_IRQ       @This routine is needed
        LDR     r1,=IsrIRQ 
        STR     r1,[r0]

        @ Setup SWI handler
        LDR     r0,=pISR_SWI       @This routine is needed
        LDR     r1,=IsrSWI 
        STR     r1,[r0]


/*
 * Define stack for supervisor modes
 */
        MRS     r0,cpsr
        BIC     r0,r0,#MODE_MASK
        ORR     r1,r0,#IRQ_MODE|NOINT
        MSR     cpsr,r1            @IRQMode
        LDR     sp,=_IRQ_STACK

        ORR     r1,r0,#FIQ_MODE|NOINT
        MSR     cpsr,r1            @FIQMode
        LDR     sp,=_FIQ_STACK


	mrs	r0, cpsr
	bic	r0, r0, #PSR_MODE_MASK
	orr	r0, r0, #PSR_SVC_MODE
	bic	r0,r0,#0xc0		@enable IRQ and FIQ
	msr	cpsr, r0
	ldr	sp, =_USR_STACK

/*
 * Embedded System should never return, if return then run again
 */
3: 
	bl	main
	b	3b



SMRDATA:
        .long ((SYS_SDM<<31)+(SYS_PD_ID<<26)+(SYS_SFR_SADDR<<16)+(SYS_SRAM_SADDR<<6)+(SYS_CM<<4)+(SYS_WE<<2)+(SYS_CE<<1)+(SYS_SE))
        .long ((CLK_TAC<<18)+(CLK_R5MUX<<17)+(CLK_R5WAIT<<16)+(CLK_DIVIDING))
SMRDATA1:
        .long ((IO1_TACC<<25)+(IO1_TCOH<<22)+(IO1_TACS<<19)+(IO1_TCOS<<16)+(IO0_TACC<<9)+(IO0_TCOH<<6)+(IO0_TACS<<3)+(IO0_TCOS))
        .long ((IO3_TACC<<25)+(IO3_TCOH<<22)+(IO3_TACS<<19)+(IO3_TCOS<<16)+(IO1_TACC<<9)+(IO1_TCOH<<6)+(IO1_TACS<<3)+(IO1_TCOS))
        .long ((IO3_BWSCON<<26)+(IO2_BWSCON<<24)+(IO1_BWSCON<<22)+(IO0_BWSCON<<20)+(DR3_BWSCON<<18)+(DR2_BWSCON<<16)+(DR1_BWSCON<<14)+(DR0_BWSCON<<12)+(R5_BWSCON<<10)+(R4_BWSCON<<8)+(R3_BWSCON<<6)+(R2_BWSCON<<4)+(R1_BWSCON<<2)+(R0_BWSCON))
SMRDATA2:
        .long ((R0_NSADDR<<20)+(R0_SADDR<<10)+(R0_TACC<<4)+(R0_TPA<<2)+R0_PMC)
        .long ((R1_NSADDR<<20)+(R1_SADDR<<10)+(R1_TACC<<4)+(R1_TPA<<2)+R1_PMC)
        .long ((R2_NSADDR<<20)+(R2_SADDR<<10)+(R2_TACC<<4)+(R2_TPA<<2)+R2_PMC)
        .long ((R3_NSADDR<<20)+(R3_SADDR<<10)+(R3_TACC<<4)+(R3_TPA<<2)+R3_PMC)
        .long ((R4_NSADDR<<20)+(R4_SADDR<<10)+(R4_TACC<<4)+(R4_TPA<<2)+R4_PMC)
        .long ((R5_NSADDR<<20)+(R5_SADDR<<10)+(R5_TACC<<4)+(R5_TPA<<2)+R5_PMC)
        .long ((DR0_NSADDR<<20)+(DR0_SADDR<<10)+(DR0_TRP<<8)+(DR0_TRC<<7)+(DR0_TCP<<3)+(DR0_TCS<<1)+DR0_EDO)
        .long ((DR1_NSADDR<<20)+(DR1_SADDR<<10)+(DR1_TRP<<8)+(DR1_TRC<<7)+(DR0_TCP<<3)+(DR1_TCS<<1)+DR1_EDO)
        .long ((DR2_NSADDR<<20)+(DR2_SADDR<<10)+(DR2_TRP<<8)+(DR2_TRC<<7)+(DR0_TCP<<3)+(DR2_TCS<<1)+DR2_EDO)
        .long ((DR3_NSADDR<<20)+(DR3_SADDR<<10)+(DR3_TRP<<8)+(DR3_TRC<<7)+(DR0_TCP<<3)+(DR3_TCS<<1)+DR3_EDO)
        .long ((REF_CNT<<21)+(REF_TCSR<<20)+(REF_TCHR<<17)+(REF_REN<<16)+(REF_VSF<<15)+REF_SADDR)

.ifdef LOADER
LOADER_MAP:
        .long ((0x1F<<20)+(0<<10)+(R0_TACC<<4)+(R0_TPA<<2)+R0_PMC)
        .long ((R1_NSADDR<<20)+(R1_SADDR<<10)+(R1_TACC<<4)+(R1_TPA<<2)+R1_PMC)
        .long ((R2_NSADDR<<20)+(R2_SADDR<<10)+(R2_TACC<<4)+(R2_TPA<<2)+R2_PMC)
        .long ((R3_NSADDR<<20)+(R3_SADDR<<10)+(R3_TACC<<4)+(R3_TPA<<2)+R3_PMC)
        .long ((R4_NSADDR<<20)+(R4_SADDR<<10)+(R4_TACC<<4)+(R4_TPA<<2)+R4_PMC)
        .long ((R5_NSADDR<<20)+(R5_SADDR<<10)+(R5_TACC<<4)+(R5_TPA<<2)+R5_PMC)
        .long ((0x2ff<<20)+(0x100<<10)+(DR0_TRP<<8)+(DR0_TRC<<7)+(DR0_TCP<<3)+(DR0_TCS<<1)+DR0_EDO)
        .long ((DR1_NSADDR<<20)+(DR1_SADDR<<10)+(DR1_TRP<<8)+(DR1_TRC<<7)+(DR0_TCP<<3)+(DR1_TCS<<1)+DR1_EDO)
        .long ((DR2_NSADDR<<20)+(DR2_SADDR<<10)+(DR2_TRP<<8)+(DR2_TRC<<7)+(DR0_TCP<<3)+(DR2_TCS<<1)+DR2_EDO)
        .long ((DR3_NSADDR<<20)+(DR3_SADDR<<10)+(DR3_TRP<<8)+(DR3_TRC<<7)+(DR0_TCP<<3)+(DR3_TCS<<1)+DR3_EDO)
        .long ((REF_CNT<<21)+(REF_TCSR<<20)+(REF_TCHR<<17)+(REF_REN<<16)+(REF_VSF<<15)+REF_SADDR)
.endif


.section ".bss"

		.global  pISR_Reset, pISR_Undef, pISR_SWI, pISR_Pabort, pISR_Dabort
		.global  pISR_Reserved, pISR_IRQ, pISR_FIQ
		.global  pISR_EXT0, pISR_TIMER0, pISR_EXT2, pISR_U0TINT, pISR_U0RERR, pISR_U1TINT, pISR_U1RERR

pISR_Undef: 	.long   0
pISR_SWI:   	.long   0
pISR_Pabort:    .long   0
pISR_Dabort:    .long   0
pISR_Reserved:  .long   0
pISR_IRQ:   	.long   0
pISR_FIQ:   	.long   0
pISR_EXT0:  	.long   0
pISR_EXT1:  	.long   0
pISR_EXT2:  	.long   0
pISR_EXT3: 	.long   0
pISR_U0TINT:	.long   0
pISR_U0RERR:	.long   0
pISR_U1TINT:	.long   0
pISR_U1RERR:   	.long   0
pISR_GDMA0:   	.long   0
pISR_GDMA1:	.long   0
pISR_TIMER0: 	.long   0
pISR_TIMER1: 	.long   0
pISR_HDLCTXA: 	.long   0
pISR_HDLCRXA: 	.long   0
pISR_HDLCTXB: 	.long   0
pISR_HDLCRXB:	.long   0
pISR_ECBDMATx:	.long   0
pISR_ECBDMARx:	.long   0
pISR_ECMACTx:	.long   0
pISR_ECMACRx:	.long   0
pISR_i2cbus:	.long   0
