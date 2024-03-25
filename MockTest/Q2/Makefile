#--------------------------------------Makefile-------------------------------------
CFILES = $(wildcard ./kernel/*.c)
OFILES = $(CFILES:./kernel/%.c=./build/%.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib
all: clean ./build/uart1.o kernel8.img

./build/uart1.o: ./uart/uart1.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./uart/uart1.c -o ./build/uart1.o

./build/boot.o: ./kernel/boot.S
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./kernel/boot.S -o ./build/boot.o
./build/%.o: ./kernel/%.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@
kernel8.img: ./build/boot.o $(OFILES)
	aarch64-none-elf-ld -nostdlib ./build/boot.o ./build/uart1.o $(OFILES) -T ./kernel/link.ld -o ./build/kernel8.elf
	aarch64-none-elf-objcopy -O binary ./build/kernel8.elf kernel8.img
clean:
	rm -f ./build/kernel8.elf *.o *.img
# Run emulation with QEMU
run:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -serial null -serial stdio
	
