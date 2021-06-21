#include "pic.h"
#include "lib/io.h"

void pic_init() {
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    
    outb(0x21, 0xfd);
    outb(0xA1, 0xff);
}

void pic_ack(unsigned int interrupt) {
    if(interrupt < PIC1_START_INTERRUPT || interrupt > PIC2_END_INTERRUPT) {
        return;
    }
    if(interrupt < PIC2_START_INTERRUPT) {
        outb(PIC1, PIC_ACK);
    } else {
        outb(PIC2, PIC_ACK);
    }
}

void pic_mask(u8int_t mask1, u8int_t mask2)
{
    outb(PIC1_PORT_B, mask1);
    outb(PIC2_PORT_B, mask2);
}