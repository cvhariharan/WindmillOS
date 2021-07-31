#include <userinput/mouse.h>
#include <lib/io.h>

int mouse_init() {
    outb(0x64, 0xD4); // address the mouse
    outb(0x60, 0xF3); // write mouse command to set sample rate

    while(!(inb(0x64) & 1)) { asm("pause"); } // wait till mouse responds back
    u8int_t ack = inb(0x60); // read the acknowledge signal
    outb(0x64, 0xD4); // address the mouse
    outb(0x60, 100); // write the sample rate parameter
    
    while(!(inb(0x64) & 1)) { asm("pause"); }
    ack = inb(0x60);
}