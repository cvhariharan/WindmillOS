#include "../types.h"

#ifndef _IDT_
#define _IDT_
#define IDT_ENTRIES 256
#endif

struct _idt_entry {
   u16int_t base_lo;
   u16int_t sel;    
   u8int_t  always0;
   u8int_t  flags;  
   u16int_t base_hi;
} __attribute__((packed));

typedef struct _idt_entry idt_entry_t;

struct _idt_ptr
{
   u16int_t limit;
   u32int_t base;
} __attribute__((packed));

typedef struct _idt_ptr idt_ptr_t;

void init_idt();

extern void idt_flush(u32int_t);

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();