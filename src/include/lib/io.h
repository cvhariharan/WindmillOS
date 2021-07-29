#ifndef _IO_H
#define _IO_H

#include "types.h"

static inline void outb(u16int_t port, u8int_t val) {
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline u8int_t inb(u16int_t port) {
    u8int_t ret;
    asm volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

#endif