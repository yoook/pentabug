PROJECT=pentabug

APPS = buggy chat jumpy mariotheme geiger ducklings blinker

OPTIMIZATION = -Os
MCU = atmega88pa
F_CPU = 8000000
QUARZ = 8MHZ
FUSES = lfuse:w:0xe2:m -U hfuse:w:0xdf:m -U efuse:w:0x01:m

#########################################################################

APP_SRC=$(APPS:%=apps/%.c)
SRC=$(wildcard lib/*.c *.c) $(APP_SRC)
OBJECTS= $(SRC:.c=.o) 
LSTFILES= $(SRC:.c=.lst)
HEADERS=$(wildcard */*/*.h */*.h *.h)

#  Compiler Options
GCFLAGS = -ffreestanding -std=gnu99 -mmcu=$(MCU) $(OPTIMIZATION) -Wl,-gc-sections -nostdlib -I. -Iinclude
# Warnings
GCFLAGS += -Wstrict-prototypes -Wundef -Wall -Wextra -Wunreachable-code  
# Optimizazions
GCFLAGS += -fsingle-precision-constant -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -fno-builtin -ffunction-sections -fno-common -fdata-sections 
# Debug stuff
GCFLAGS += -Wa,-adhlns=$(<:.c=.lst),-gstabs -g

GCFLAGS += -DF_CPU=$(F_CPU) -DQUARZ=$(QUARZ)

LDFLAGS = -mmcu=$(MCU) $(OPTIMIZATION) -gc-sections


#  Paths
GCC = avr-gcc
OBJCOPY = avr-objcopy
REMOVE = rm -f
SIZE = avr-size
AVRDUDE = avrdude

#########################################################################

all: $(PROJECT).hex Makefile 
	@$(SIZE) --mcu=$(MCU) --format=avr $(PROJECT).elf

$(PROJECT).hex: $(PROJECT).elf Makefile
	@echo "  \033[1;34mOBJCOPY\033[0m $(PROJECT).elf -> $(PROJECT).hex"
	@$(OBJCOPY) -O ihex -R .eeprom $(PROJECT).elf $(PROJECT).hex

$(PROJECT).elf: $(OBJECTS) Makefile
	@echo "  \033[1;34mLink   \033[0m (\033[1;33m $(OBJECTS)\033[0m) -> $(PROJECT).elf"
	@$(GCC) $(OBJECTS) $(LDFLAGS)  -o $(PROJECT).elf

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(LSTFILES)
	$(REMOVE) $(PROJECT).hex
	$(REMOVE) $(PROJECT).elf

#########################################################################

%.o: %.c Makefile $(HEADERS)
	@echo "  \033[1;34mCompile\033[0m $<"
	@$(GCC) $(GCFLAGS) -o $@ -c $<


#########################################################################

fuse: 
	$(AVRDUDE) -p m88 -F -c usbtiny  -v -v  -U $(FUSES)

flash: $(PROJECT).hex Makefile
	$(AVRDUDE) -p m88 -F -c usbtiny  -B 1  -U flash:w:$(PROJECT).hex

fljohn: $(PROJECT).hex Makefile
	$(AVRDUDE) -p m88 -F  -P /dev/serial/by-id/usb-FTDI_USB__-__Serial-if00-port0   -c stk500v2 -v -v  -U flash:w:$(PROJECT).hex

flsmart: $(PROJECT).hex Makefile
	$(AVRDUDE) -p m88 -F  -P /dev/ttyUSB0 -c stk500v2 -v -v  -U flash:w:$(PROJECT).hex

flusbasp: $(PROJECT).hex Makefile
	$(AVRDUDE) -p m88 -F -c usbasp -v -v  -U flash:w:$(PROJECT).hex

.PHONY : clean all fuse flash fljohn 

