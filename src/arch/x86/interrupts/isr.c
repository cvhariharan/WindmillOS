#include <interrupts/isr.h>
#include <drivers/vga.h>
#include <userinput/keyboard.h>
#include <pic.h>
#include <lib/io.h>
#include <stdio.h>

void isr_handler(registers_t regs) {
    vga_k_print("Received interrupt: ");
    vga_decimal_print(regs.int_no);
    switch(regs.int_no) {
        case 13:
            isr_13();
            break;
    }
}

void irq_handler(registers_t regs) {
    switch(regs.int_no) {
        case 33:
            _keyboard_interrupt();
            break;
        case 44:
            _mouse_interrupt();
            break;
    }
    pic_ack(regs.int_no);
} 

void isr_13() {
    vga_k_print("General Protection Fault\n");
    for(;;) {asm("hlt");}
}

void _keyboard_interrupt() {
    int scancode = inb(0x60);
    char a = get_key_from_scancode(scancode);
    vga_putchar_color(a, VGA_WHITE);
}

void _mouse_interrupt() {
    while(!(inb(0x64) & 1));
    u8int_t is_mouse = inb(0x64) & 0x20;
    if(is_mouse) {
        vga_putchar_color('m', VGA_WHITE);
    }
}