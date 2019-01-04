TARGET:=main
DEPS:=user
MCU:=32MZ2048EFG100
MDBSCRIPT:=mdbscript.txt

CC=xc32-gcc 
BIN2H=xc32-bin2hex
MDB=mdb -l OFF
CFLAGS=-O2 -mprocessor=$(MCU) -std=gnu11 
SIZE:=xc32-size

.PHONY: all hex size mdbflash clean

all: clean | hex size flash

clean:					## tidy things up	
	@echo Tidy up...
	-rm -f $(MDBSCRIPT) $(TARGET:=.o) $(TARGET:=.hex) $(TARGET:=.elf) $(addsuffix .o, $(DEPS)) $(addsuffix .i, $(DEPS)) $(addsuffix .s, $(DEPS))

size: 
	@echo -en "\e[38;5;82m"
	@echo -e "** Size of the resulting sections:"
	$(SIZE) $(TARGET:=.elf)
	@echo -en "\e[39m"

hex: $(TARGET:=.hex)			## create .hex file

$(TARGET:=.elf): $(TARGET:=.c) $(addsuffix .o, $(DEPS))
	@echo Building \'$(TARGET)\' elf
	$(CC) $(CFLAGS) $(addsuffix .o, $(DEPS)) $(TARGET:=.c) -o $@
	#$(SIZE) $(TARGET:=.elf)

.ONESHELL:
flash: $(TARGET:=.hex)
	@cat <<- EOF > $(MDBSCRIPT)
	device PIC$(MCU)
	set programoptions.eraseb4program true
	set poweroptions.powerenable false
	hwtool PICkit3 -p
	program $(TARGET:=.hex)
	reset MCLR
	quit
	EOF
	$(MDB) $(MDBSCRIPT)

%.hex: %.elf	
	$(BIN2H) $< 
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@