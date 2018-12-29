@ =====================================================================================
@ SYSCFG Register
@[0] Stall enable (SE)
@	Must be set to zero.
@[1] Cache enable (CE)
@	When set to ¡§1¡¨, cache operations are enabled.
@[2] Write buffer enable (WE)
@	When set to ¡§1¡¨, write buffer operations are@enabled.
@[5:4] Cache mode (CM)
@	This 2-bit value determines how internal memory is
@	to be divided into cache and SRAM.
@	00 = 4-Kbyte SRAM, 4-Kbyte cache
@	01 = 0-Kbyte SRAM, 8-Kbyte cache
@	10 = 8-Kbyte SRAM, 0-Kbyte cache
@	NOTE: When you write 10 to this field, the cache
@	enable bit is cleared automatically.
@[15:6] Internal SRAM base pointer
@	This 10-bit address becomes the upper address
@	of SRAM. A25 through A16, the remaining SRAM
@	addresses, and A15 through A0, are filled with zeros.
@[25:16] Special register bank base pointer
@	The resolution of this value is 64 K. Therefore, to
@	place the start address at 1800000H (24 M), use this
@	formula:
@	Setting value = (1800000H / 64 K) << 16.
@[29:26] Product Identifier (PD_ID)
@	0000 = KS32C5000
@	0001 = KS32C50100
@[31] Sync. DRAM Mode
@	0 = Normal/EDO DRAM interface for 4 DRAM banks
@	1 = Sync. DRAM interface for 4 DRAM banks
@ =====================================================================================
	.equ	CACHE_DISABLE, 0
	.equ	CACHE_ENABLE, 1
	.equ	SYS_SE,0
		.equ	SYS_CE ,CACHE_DISABLE
		.equ	SYS_WE ,0
		.equ	SYS_CM, 1	@ 0-Kbyte SRAM, 8-Kbyte cache
	.equ	SYS_SRAM_SADDR, 0x3FE	@ Internal SRAM Start Address = 0x3FE0000
	.equ	SYS_SFR_SADDR, 0x3FF	@ SFR Start Address = 0x3FF0000
	.equ	SYS_PD_ID, 1	@ KS32C50100
		.equ	SYS_SDM, 1	@ 1 = Sync. DRAM interface for 4 DRAM banks




@ =====================================================================================
@ CLKCON
@
@[15:0] Clock dividing value
@	If all bits are 0, a non-divided clock is used. Only one bit
@	can be set in CLKCON[15:0]. That is, the clock dividing
@	value is defined as 1, 2, 4, 8,16, ....
@	Internal system clock, f MCLK = f ICLK / (CLKCON+1)
@[16] ROM bank 5 wait enable
@	0 = Disable ROM bank 5 wait.
@	1 = Enable ROM bank 5 wait.
@[17] ROM bank 5 address/data bus Mux enable
@	0 = Normal operation
@	1 = Enable bus multiplexing
@[19:18] Mux bus Address Cycle (tAC)
@	00 = 1 MCLK
@	01 = 2 MCLK
@	10 = 3 MCLK
@[31] Test bit
@	This bit should be always 0.
@ =====================================================================================
	.equ	CLK_DIVIDING, 0
	.equ	CLK_R5WAIT, 0	@ Disable
	.equ	CLK_R5MUX, 0	@ Normal operation
		.equ	CLK_TAC, 0	@ 1 MCLK

@ =====================================================================================
@EXTDBWTH
@[1:0] 	Data bus width for ROM/SRAM/FLASH bank 0 (DSR0)
@	DSR0 is read-only data at the B0SIZE [1:0] pins. DSR0 is read-only because
@	ROM/SRAM/FLASH bank 0 is used to boot the ROM while the data bus width
@	for ROM/SRAM/FLASH bank 0 is set using B0SIZE [1:0].
@	00 = Not permitted
@	01 = Byte (8 bits)
@	10 = Half-word (16 bits)
@	11 = Word (32 bits)
@[3:2] Data bus width for ROM/SRAM/FLASH bank 1 (DSR1)
@[5:4] DSR2, [7:6] DSR3, [9:8] DSR4, [11:10] DSR5
@	00 = Disable
@	01 = Byte (8 bits)
@	10 = Half-word (16 bits)
@	11 = Word (32 bits)
@[13:12] Data bus width for DRAM bank 0 (DSD0)
@[15:14] DSD1, [17:16] DSD2, [19:18] DSD3
@	00 = Disable
@	01 = Byte (8 bits)
@	10 = Half-word (16 bits)
@	11 = Word (32 bits)
@[21:20] Data bus width for external I/O bank 0 (DSX0)
@[23:22] DSX1, [25:24] DSX2, [27:26] DSX3
@	00 = Disable
@	01 = Byte (8 bits)
@	10 = Half-word (16 bits)
@	11 = Word (32 bits)
@ =====================================================================================
	.equ	BUS_DISABLE, (00)
		.equ	DW8, (0x1)
		.equ	DW16, (0x2)
		.equ	DW32, (0x3)

	.equ R0_BWSCON, (DW16)
	.equ R1_BWSCON, (BUS_DISABLE)
	.equ R2_BWSCON ,(BUS_DISABLE)
	.equ R3_BWSCON ,(BUS_DISABLE)
	.equ R4_BWSCON, (DW32)
	.equ R5_BWSCON ,(DW32)

	.equ DR0_BWSCON ,(DW32)
	.equ DR1_BWSCON ,(BUS_DISABLE)
	.equ DR2_BWSCON, (BUS_DISABLE)
	.equ DR3_BWSCON, (BUS_DISABLE)

	.equ IO0_BWSCON, (DW16)
	.equ IO1_BWSCON, (DW16)
	.equ IO2_BWSCON ,(DW16)
	.equ IO3_BWSCON ,(DW16)


@ =====================================================================================
@ External I/O access timing register 0/1
@[2:0] Chip selection set-up time on nOE (tCOS0, tCOS2)
@[18:16] tCOS1, tCOS3
@	000 = 0 cycle 100 = 4 cycles
@	001 = 1 cycles 101 = 5 cycles
@	010 = 2 cycle 110 = 6 cycles
@	011 = 3 cycles 111 = 7 cycles
@[5:3] Address set-up time before nECS (tACS0, tACS2)
@[21:19] tACS1, tACS3
@	000 = 0 cycle 100 = 4 cycles
@	001 = 1 cycles 101 = 5 cycles
@	010 = 2 cycle 110 = 6 cycles
@	011 = 3 cycles 111 = 7 cycles
@[8:6] Chip selection hold time on nOE (tCOH0, tCOH2)
@[24:22] tCOH1, tCOH3
@	000 = 0 cycle 100 = 4 cycles
@	001 = 1 cycles 101 = 5 cycles
@	010 = 2 cycle 110 = 6 cycles
@	011 = 3 cycles 111 = 7 cycles
@[11:9] Access cycles (nOE Low time) (tACC0, tACC2)
@[27:25] tACC1, tACC3
@	000 = 0 cycle 100 = 4 cycles
@	001 = 1 cycles 101 = 5 cycles
@	010 = 2 cycle 110 = 6 cycles
@	011 = 3 cycles 111 = 7 cycles
@ =====================================================================================
@
	.equ	IO0_TCOS, 2	@ 7 Cycles
	.equ	IO0_TACS, 2	@ 7 Cycles
	.equ	IO0_TCOH, 2	@ 7 Cycles
	.equ	IO0_TACC ,5	@ 7 Cycles
	.equ	IO1_TCOS ,7	@ 7 Cycles
	.equ	IO1_TACS ,7	@ 7 Cycles
	.equ	IO1_TCOH ,7	@ 7 Cycles
	.equ	IO1_TACC ,7	@ 7 Cycles
	.equ	IO2_TCOS ,7	@ 7 Cycles
	.equ	IO2_TACS, 7	@ 7 Cycles
	.equ	IO2_TCOH, 7	@ 7 Cycles
	.equ	IO2_TACC ,7	@ 7 Cycles
	.equ	IO3_TCOS ,7	@ 7 Cycles
	.equ	IO3_TACS ,7	@ 7 Cycles
	.equ	IO3_TCOH ,7	@ 7 Cycles
	.equ	IO3_TACC ,7	@ 7 Cycles



@ =====================================================================================
@ROMCONn Bit Description
@ Page Mode configuration(PMC)
@[1:0] Page mode configuration (PMC)
@00 = Normal R  01 = 4-word page
@10 = 8-word page 11 = 16-word page

@[3:2] Page address access time (tPA)
@00 = 5 cycles 01 = 2 cycles
@10 = 3 cycles 11 = 4 cycles
@

@[6:4] Programmable access cycle (tACC)
@000 = Disable bank 001 = 2 cycles
@010 = 3 cycles 011 = 4 cycles
@100 = 5 cycles 101 = 6 cycles
@110 = 7 cycles 111 = Reserved

@[19:10] R/SRAM/Flash bank # base pointer
@This value is the start address of the R/SRAM/Flash bank #.
@The start address is calculated as R/SRAM/FLASH bank # base
@pointer << 16

@[29:20] R/SRAM/FLASH bank # next pointer
@This value is the current bank end address << 16 + 1
@
@ =====================================================================================

@ ROMCON0 : 0x20000060 after Reset 
@

		.equ	R0_PMC, 0	@ Normal R
		.equ	R0_TPA ,0	@ 5 cycles
		.equ	R0_TACC ,4	@ 5 cycles
	.equ	R0_SADDR, 0x180	@ Start Address = 0x01800000
	.equ	R0_NSADDR, 0x1A0	@ End   Address = 0x01A00000-1

@ ROMCON1 : 0x00000060 after Reset 
@
		.equ	R1_PMC, 0	@ Normal R
		.equ	R1_TPA, 0	@ 5 cycles
		.equ	R1_TACC, 6	@ 7 cycles
	.equ	R1_SADDR, 0	@ Start Address = 0
	.equ	R1_NSADDR, 0    	@ Next R Address@

@ ROMCON2 : 0x00000060 after Reset 
@
		.equ	R2_PMC, 0	@ Normal R
		.equ	R2_TPA, 0	@ 5 cycles
		.equ	R2_TACC, 6	@ 7 cycles
	.equ	R2_SADDR, 0	@ Start Address = 0
	.equ	R2_NSADDR, 0   	@ Next R Address@

@ ROMCON3 : 0x00000060 after Reset 
@
		.equ	R3_PMC, 0	@ Normal R
		.equ	R3_TPA, 0	@ 5 cycles
		.equ	R3_TACC, 6	@ 7 cycles
	.equ	R3_SADDR, 0	@ Start Address = 0
	.equ	R3_NSADDR, 0    	@ Next R Address@

@ ROMCON4 : 0x00000060 after Reset 
@
		.equ	R4_PMC, 0	@ Normal R
		.equ	R4_TPA, 0	@ 5 cycles
		.equ	R4_TACC, 6	@ 7 cycles
	.equ	R4_SADDR, 0	@ Start Address = 0
	.equ	R4_NSADDR, 0    	@ Next R Address@

@ ROMCON5 : 0x00000060 after Reset 
@
		.equ	R5_PMC, 0	@ Normal R
		.equ	R5_TPA, 0	@ 5 cycles
		.equ	R5_TACC, 6	@ 7 cycles
	.equ	R5_SADDR, 0	@ Start Address = 0
	.equ	R5_NSADDR, 0    	@ Next R Address@

@ =====================================================================================
@DRAM Parameter 
@DRAMCON#
@ =====================================================================================
@[0] EDO mode (EDO) (note)
@	0 = Normal DRAM (Fast page mode DRAM)
@	1 = EDO DRAM
@[2:1] CAS strobe time (tCS)
@	00 = 1 cycle 01 = 2 cycles
@	10 = 3 cycles 11 = 4 cycles
@[3:3] CAS pre-charge time (tCP) (note)
@	0 = 1 cycle 1 = 2 cycles
@[6:4] Reserved
@	These bits default value is 000. But, you must set to 001.
@
@[7] RAS to CAS delay (tRC or tRCD)
@	0 = 1 cycle 1 = 2 cycles
@
@[9:8] RAS pre-charge time (tRP)
@	00 = 1 cycle 01 = 2 cycles
@	10 = 3 cycles 11 = 4 cycles
@
@[19:10] DRAM bank # base pointer
@This value indicates the start address of DRAM bank #. The start address is
@calculated as RAM bank # base pointer << 16
@
@[29:20] DRAM bank # Next pointer
@This value is the current bank end address << 16 + 1
@
@[31:30] Number of column address bits in DRAM bank # (CAN)
@	00 = 8 bits 01 = 9 bits
@	10 = 10 bits 11 = 11 bits
@

@ DRAMCON0 : 0x00000000 after Reset 
@
		.equ	DR0_EDO, 1	@ 
		.equ	DR0_TCS, 0	@
		.equ	DR0_TCP, 0	@ 
		.equ	DR0_TRC, 0	@ 
		.equ	DR0_TRP, 3    	@ 
	.equ	DR0_SADDR ,0	@ Start Address = 0x00000000 
	.equ	DR0_NSADDR, 0x100	@ End   Address = 0x01000000-1

@ DRAMCON1 : 0x00000000 after Reset 
@
		.equ	DR1_EDO, 0	@ 
		.equ	DR1_TCS, 0	@
		.equ	DR1_TCP, 0	@ 
		.equ	DR1_TRC, 0	@ 
		.equ	DR1_TRP, 0   	@ 
	.equ	DR1_SADDR, 0	@
	.equ	DR1_NSADDR, 0	@

@ DRAMCON2 : 0x00000000 after Reset 
@
		.equ	DR2_EDO, 0	@ 
		.equ	DR2_TCS, 0	@
		.equ	DR2_TCP, 0	@ 
		.equ	DR2_TRC,  0	@ 
		.equ	DR2_TRP,0    	@ 
	.equ	DR2_SADDR, 0	@
	.equ	DR2_NSADDR, 0	@

@ DRAMCON3 : 0x00000000 after Reset 
@
		.equ	DR3_EDO ,0	@ 
		.equ	DR3_TCS ,0	@
		.equ	DR3_TCP ,0	@ 
		.equ	DR3_TRC ,0	@ 
		.equ	DR3_TRP, 0   	@ 
	.equ	DR3_SADDR, 0	@
	.equ	DR3_NSADDR, 0	@


@ =====================================================================================
@ REFEXTCON
@======================================================================================
@[9:0] 	External I/O bank 0 base pointer (base address)
@	This value is the start address of external I/O bank 0. Start address is defined as
@	External I/O bank 0 base pointer << 16. The end address of external I/O bank 0 is
@	defined as External I/O bank 0 base pointer >> 16 + 16 K bytes - 1.
@	NOTE: All external I/O banks are located in the continuous address space which
@	begins at the start address of external I/O bank 0. The size of each external I/O
@	bank is fixed at 16 K bytes. The start and end addresses of the other three external
@	I/O banks can be derived from the external I/O bank 0 base pointer value.
@
@[15] 	Validity of special register field (VSF)
@	0 = Not accessible to memory bank
@	1 = Accessible to memory bank
@[16] 	Refresh enable (REN)
@	0 = Disable DRAM refresh
@	1 = Enable DRAM refresh
@[19:17] CAS hold time (tCHR)
@	ROW Cycle Time (tRC) (note1)
@	000 = 1 cycle 001 = 2 cycles
@	010 = 3 cycles 011 = 4 cycles
@	100 = 5 cycles 101 = Not used (6 cycles)
@	110 = Not used 111 = Not used
@[20] CAS setup time (tCSR) (note2)
@	0 = 1 cycle
@	1 = 2 cycles
@[31:21] Refresh count value (duration)
@	The refresh period is calculated as (2 11 - Value + 1) / f MCLK

	.equ	REF_SADDR ,0x3F0
		.equ	REF_VSF ,1	@ Accessible to memory bank	
		.equ	REF_REN ,1	@ Enable DRAM refresh
	.equ	REF_TCHR ,4	@ 5 cycles(CAS hold time)
	.equ	REF_TCSR ,0	@ 1 cycles(CAS setup tim)
		.equ	REF_CNT, 0x4E1	@ Refresh count value
