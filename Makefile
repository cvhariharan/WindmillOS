CC = "./cross-compiler/cross/bin/i386-elf-gcc"
CFLAGS = -m32 -ffreestanding -g -c -I src/include
default: run

.PHONY: default build run clean kernel.o libk.a

build/boot.o: src/arch/x86/boot.asm
	nasm -f elf32 -g src/arch/x86/boot.asm -o build/boot.o

build/kernel.o: src/arch/x86/kernel.c src/arch/x86/drivers/vga.c src/arch/x86/gdt/gdt.c src/arch/x86/interrupts/idt.c src/arch/x86/pic.c
	$(CC) $(CFLAGS) src/arch/x86/kernel.c -o build/kernel.o -nostdlib
	$(CC) $(CFLAGS) src/arch/x86/drivers/vga.c -o build/vga.o -nostdlib
	$(CC) $(CFLAGS) src/arch/x86/gdt/gdt.c -o build/gdt.o
	nasm -f elf32 -g src/arch/x86/gdt/gdt.asm -o build/gdt_asm.o
	$(CC) $(CFLAGS) src/arch/x86/interrupts/idt.c -o build/idt.o
	$(CC) $(CFLAGS) src/arch/x86/interrupts/isr.c -o build/isr.o
	$(CC) $(CFLAGS) src/arch/x86/pic.c -o build/pic.o
	nasm -f elf32 -g src/arch/x86/interrupts/idt.asm -o build/idt_asm.o
	nasm -f elf32 -g src/arch/x86/interrupts/interrupts.asm -o build/interrupt.o
	$(CC) $(CFLAGS) src/arch/x86/userinput/keyboard.c -o build/keyboard.o

build/kernel.bin: build/boot.o build/kernel.o linker.ld libk.a
	ld -m elf_i386 --nmagic --output=build/kernel.bin --script=linker.ld build/boot.o build/kernel.o build/vga.o build/gdt.o build/gdt_asm.o \
	build/idt.o build/idt_asm.o build/isr.o build/interrupt.o build/keyboard.o \
	build/pic.o build/libk.a

windmill.iso: build/kernel.bin isofiles/boot/grub/grub.cfg
	mkdir -p isofiles/boot/grub
	cp build/kernel.bin isofiles/boot/
	grub2-mkrescue -o windmill.iso isofiles

libk.a: build-libc.sh src/libc
	chmod +x ./build-libc.sh
	./build-libc.sh


build: windmill.iso

setup:
	mkdir -p build

run: cross-compiler setup windmill.iso
	qemu-system-i386 -cdrom windmill.iso

debug: setup windmill.iso
	qemu-system-i386 -gdb tcp::26000 -S -cdrom windmill.iso

cross-compiler/cross/bin/i386-elf-gcc:
	chmod +x ./build-compiler.sh
	./build-compiler.sh

cross-compiler: cross-compiler/cross/bin/i386-elf-gcc

# set-compiler:
# 	export PREFIX="$PWD/cross-compiler/bin"
# 	export PATH="$PREFIX/bin:$PATH"

clean:
	rm -rf build/* windmill.iso
	rm -rf cross-compiler/build-gcc cross-compiler/build-binutils