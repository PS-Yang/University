

chap07_PATH=.
INCLUDE_PATH1=$(chap07_PATH)/common
INCLUDE_PATH2=$(chap07_PATH)/gnu
VPATH = $(chap07_PATH)/common:$(chap07_PATH)/lib:$(chap07_PATH)/gnu

PREFIX=/usr/local
CC=$(PREFIX)/bin/arm-elf-gcc
LD=$(PREFIX)/bin/arm-elf-ld
CFLAGS= -nostartfiles -g -I$(INCLUDE_PATH1) -I$(INCLUDE_PATH2) -I. -O0
AFLAGS=-mapcs-32 -msoft-float -mno-fpu $(CFLAGS)
LFLAGS= -Wl,-elf2flt,-M,-Map=$@.map
OBJS=  chap07.o sbrk.o driver.o lcd.o

all : $(OBJS) head_ram.o head_rom.o
	$(CC)  -Tchap07.ld -Wl,-M,-Map=chap07_ram.map -o "chap07_ram.axf" $(OBJS) head_ram.o 
	arm-elf-objcopy -O binary -S chap07_ram.axf chap07_ram.bin
	$(CC)  -Tchap07.ld -Wl,-M,-Map=chap07_rom.map -o "chap07_rom.axf" $(OBJS) head_rom.o 

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

head_ram.o : head.s
	$(CC) $(AFLAGS) head.s -c -o head_ram.o
head_rom.o : head.s
	$(CC) $(AFLAGS) -Wa,--defsym=LOADER=0 head.s -c -o head_rom.o 

.PHONY : clean
clean:
	rm *.bin *.axf *.o 	

