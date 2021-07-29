#include "../lib/types.h"

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

void idt_flush(u32int_t);
void enable_interrupts();
void isr0();
void isr1();
void isr2();
void isr3();
void isr4();
void isr5();
void isr6();
void isr7();
void isr8();
void isr9();
void isr10();
void isr11();
void isr12();
void isr13();
void isr14();
void isr15();
void isr16();
void isr17();
void isr18();
void isr19();
void isr20();
void isr21();
void isr22();
void isr23();
void isr24();
void isr25();
void isr26();
void isr27();
void isr28();
void isr29();
void isr30();
void isr31();
void irq0();
void irq1();
void irq2();
void irq3();
void irq4();
void irq5();
void irq6();
void irq7();
void irq8();
void irq9();
void irq10();
void irq11();
void irq12();
void irq13();
void irq14();
void irq15();