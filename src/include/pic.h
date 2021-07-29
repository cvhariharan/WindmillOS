#include "lib/types.h"
#ifndef _PIC_
#define PIC

#define PIC1		0x20		/* IO base address for master PIC */
#define PIC2		0xA0		/* IO base address for slave PIC */
#define PIC1_START_INTERRUPT 0x20
#define PIC2_START_INTERRUPT 0x28
#define PIC2_END_INTERRUPT   PIC2_START_INTERRUPT + 7
#define PIC_ACK 0x20

#define PIC1_COMMAND	PIC1
#define PIC1_DATA	(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	(PIC2+1)

#define PIC1_PORT_A 0x20
#define PIC1_PORT_B 0x21

#define PIC2_PORT_A 0xA0
#define PIC2_PORT_B 0xA1


#define PIC1_ICW1   0x11
#define PIC2_ICW1   PIC1_ICW2

#define PIC1_ICW2   0x20
#define PIC2_ICW2   0x28

#define PIC1_ICW3   0x04
#define PIC2_ICW3   0x02

#define PIC1_ICW4   0x05
#define PIC2_ICW4   0x01

void pic_ack(unsigned int);
void pic_init();
void pic_mask(u8int_t, u8int_t);

#endif
