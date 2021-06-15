default: run

.PHONY: default build run clean kernel.o

start.o: src/arch/x86/start.asm
	nasm -f elf32 -g src/arch/x86/start.asm -o build/start.o

boot.o: src/arch/x86/boot.asm
	nasm -f elf32 -g src/arch/x86/boot.asm -o build/boot.o

kernel.o: src/arch/x86/kernel.c src/arch/x86/drivers/vga.c src/arch/x86/lib/gdt/gdt.c src/arch/x86/lib/idt/idt.c
	gcc -m32 -c src/arch/x86/kernel.c -o build/kernel.o -nostdlib
	gcc -m32 -c src/arch/x86/drivers/vga.c -o build/vga.o -nostdlib
	gcc -m32 -c src/arch/x86/lib/gdt/gdt.c -o build/gdt.o
	nasm -f elf32 -g src/arch/x86/lib/gdt/gdt.asm -o build/gdt_asm.o
	gcc -m32 -c src/arch/x86/lib/idt/idt.c -o build/idt.o
	gcc -m32 -c src/arch/x86/lib/idt/isr.c -o build/isr.o
	nasm -f elf32 -g src/arch/x86/lib/idt/idt.asm -o build/idt_asm.o
	nasm -f elf32 -g src/arch/x86/lib/idt/interrupt.asm -o build/interrupt.o

kernel.bin: start.o boot.o kernel.o linker.ld
	ld -m elf_i386 --nmagic --output=build/kernel.bin --script=linker.ld build/boot.o build/start.o build/kernel.o build/vga.o build/gdt.o build/gdt_asm.o \
	build/idt.o build/idt_asm.o build/isr.o build/interrupt.o

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
