default: run

.PHONY: default build run clean kernel.o

start.o: src/arch/i386/start.asm
	nasm -f elf32 src/arch/i386/start.asm -o build/start.o

boot.o: src/arch/i386/boot.asm
	nasm -f elf32 src/arch/i386/boot.asm -o build/boot.o

kernel.o: src/arch/i386/kernel.c src/arch/i386/drivers/vga.c
	gcc -m32 -c src/arch/i386/kernel.c -o build/kernel.o -nostdlib
	gcc -m32 -c src/arch/i386/drivers/vga.c -o build/vga.o -nostdlib

kernel.bin: start.o boot.o kernel.o linker.ld
	ld -m elf_i386 --nmagic --output=build/kernel.bin --script=linker.ld build/boot.o build/start.o build/kernel.o build/vga.o

windmill.iso: kernel.bin isofiles/boot/grub/grub.cfg
	mkdir -p isofiles/boot/grub
	cp build/kernel.bin isofiles/boot/
	grub-mkrescue -o windmill.iso isofiles

build: windmill.iso

setup:
	mkdir -p build

run: setup windmill.iso
	qemu-system-i386 -cdrom windmill.iso

debug: setup windmill.iso
	qemu-system-i386 -gdb tcp::26000 -S -cdrom windmill.iso

clean:
	rm -rf build/* windmill.iso
