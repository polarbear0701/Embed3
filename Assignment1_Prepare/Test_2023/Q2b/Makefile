CFILES = $(wildcard ./src/*.c)
OFILES = $(CFILES:./src/%.c=./obj/%.o)

GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib

all: clean kernel8.img run

rpi = 3
uart = 1

ifeq ($(rpi), 4)
rpi = 4
else 
rpi = 3
endif


ifeq ($(uart), 0)
uart = 0
else
uart = 1
endif

GCCFLAGS += -DUART$(uart) -DRPI$(rpi)





./obj/boot.o: ./src/boot.S
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./src/boot.S -o ./obj/boot.o

./obj/kernel.o: ./src/kernel.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

./obj/uart.o: ./serial/uart$(uart).c
	@echo UART$(uart) compiled!
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

kernel8.img: ./obj/boot.o ./obj/uart.o $(OFILES)
	aarch64-none-elf-ld -nostdlib ./obj/boot.o ./obj/uart.o $(OFILES) -T ./inc/link.ld -o kernel8.elf
	aarch64-none-elf-objcopy -O binary kernel8.elf kernel8.img

clean:
	rm -f *.img *.elf ./obj/*.o

run:
ifeq ($(uart), 1)
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -serial null -serial stdio
else
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -serial stdio
endif