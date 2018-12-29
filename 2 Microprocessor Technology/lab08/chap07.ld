OUTPUT_ARCH(arm)
ENTRY(stext)

SECTIONS
{
	.text 0x00000000 : {		/* Real text segment		*/
		_text = .;		/* Text and read-only data	*/
		*(.stext)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_etext = .;		/* End of text section		*/
	}

	.data : {
		_sdata = .;
		*(.data)
		. = ALIGN(4);
		_edata = .;
	}

	.bss : {
		_sbss = .;		/* BSS				*/
		*(.bss)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
	}
	
	_end = .;
	
	.stack 0x1000000 : {
		_USR_STACK = .;	/* STACK			*/
		_IRQ_STACK = . - 0x1000;
		_FIQ_STACK = . - 0x1000;
		__stack_limit = . - 0x1000;
	}
}
