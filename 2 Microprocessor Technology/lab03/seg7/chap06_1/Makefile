

chap06_PATH=/usr/var/led
INCLUDE_PATH1=$(chap06_PATH)/common
INCLUDE_PATH2=$(chap06_PATH)/gnu
VPATH = $(chap06_PATH)/common:$(chap06_PATH)/lib:$(chap06_PATH)/gnu

PREFIX=/usr/local
CC=$(PREFIX)/bin/arm-elf-gcc
LD=$(PREFIX)/bin/arm-elf-ld
CFLAGS= -nostartfiles -g -I$(INCLUDE_PATH1) -I$(INCLUDE_PATH2) -I. -O0
AFLAGS=-mapcs-32 -msoft-float -mno-fpu $(CFLAGS)
LFLAGS= -Wl,-elf2flt,-M,-Map=$@.map
OBJS=  chap06_1.o sbrk.o driver.o lcd.o

all : $(OBJS) head_ram.o head_rom.o
	$(CC)  -Tchap06_1.ld -Wl,-M,-Map=chap06_1_ram.map -o "chap06_1_ram.axf" $(OBJS) head_ram.o 
	arm-elf-objcopy -O binary -S chap06_1_ram.axf chap06_1_ram.bin
	$(CC)  -Tchap06_1.ld -Wl,-M,-Map=chap06_1_rom.map -o "chap06_1_rom.axf" $(OBJS) head_rom.o 
	arm-elf-objcopy -O binary -S chap06_1_rom.axf chap06_1_rom.bin

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

head_ram.o : head.s
	$(CC) $(AFLAGS) head.s -c -o head_ram.o
head_rom.o : head.s
	$(CC) $(AFLAGS) -Wa,--defsym=LOADER=0 head.s -c -o head_rom.o 

.PHONY : clean
clean:
	rm *.bin *.axf *.o 	

