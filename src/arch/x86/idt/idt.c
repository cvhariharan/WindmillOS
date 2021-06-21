#include "idt.h"

idt_entry_t idt_entries[IDT_ENTRIES];
idt_ptr_t idt_ptr;

void init_idt() {
    idt_ptr.limit = sizeof(idt_entry_t) * 256 - 1;
    idt_ptr.base  = (u32int_t)&idt_entries;

    idt_set_gate(0, (u32int_t)isr0, 0x08, 0x8e);
    idt_set_gate(1, (u32int_t)isr1, 0x08, 0x8e);
    idt_set_gate(2, (u32int_t)isr2, 0x08, 0x8e);
    idt_set_gate(3, (u32int_t)isr3, 0x08, 0x8e);
    idt_set_gate(4, (u32int_t)isr4, 0x08, 0x8e);
    idt_set_gate(5, (u32int_t)isr5, 0x08, 0x8e);
    idt_set_gate(6, (u32int_t)isr6, 0x08, 0x8e);
    idt_set_gate(7, (u32int_t)isr7, 0x08, 0x8e);
    idt_set_gate(8, (u32int_t)isr8, 0x08, 0x8e);
    idt_set_gate(9, (u32int_t)isr9, 0x08, 0x8e);
    idt_set_gate(10, (u32int_t)isr10, 0x08, 0x8e);
    idt_set_gate(11, (u32int_t)isr11, 0x08, 0x8e);
    idt_set_gate(12, (u32int_t)isr12, 0x08, 0x8e);
    idt_set_gate(13, (u32int_t)isr13, 0x08, 0x8e);
    idt_set_gate(14, (u32int_t)isr14, 0x08, 0x8e);
    idt_set_gate(15, (u32int_t)isr15, 0x08, 0x8e);
    idt_set_gate(16, (u32int_t)isr16, 0x08, 0x8e);
    idt_set_gate(17, (u32int_t)isr17, 0x08, 0x8e);
    idt_set_gate(18, (u32int_t)isr18, 0x08, 0x8e);
    idt_set_gate(19, (u32int_t)isr19, 0x08, 0x8e);
    idt_set_gate(20, (u32int_t)isr20, 0x08, 0x8e);
    idt_set_gate(21, (u32int_t)isr21, 0x08, 0x8e);
    idt_set_gate(22, (u32int_t)isr22, 0x08, 0x8e);
    idt_set_gate(23, (u32int_t)isr23, 0x08, 0x8e);
    idt_set_gate(24, (u32int_t)isr24, 0x08, 0x8e);
    idt_set_gate(25, (u32int_t)isr25, 0x08, 0x8e);
    idt_set_gate(26, (u32int_t)isr26, 0x08, 0x8e);
    idt_set_gate(27, (u32int_t)isr27, 0x08, 0x8e);
    idt_set_gate(28, (u32int_t)isr28, 0x08, 0x8e);
    idt_set_gate(29, (u32int_t)isr29, 0x08, 0x8e);
    idt_set_gate(30, (u32int_t)isr30, 0x08, 0x8e);
    idt_set_gate(31, (u32int_t)isr31, 0x08, 0x8e);
    idt_set_gate(32, (u32int_t)irq0, 0x08, 0x8e);
    idt_set_gate(33, (u32int_t)irq1, 0x08, 0x8e);
    idt_set_gate(34, (u32int_t)irq2, 0x08, 0x8e);
    idt_set_gate(35, (u32int_t)irq3, 0x08, 0x8e);
    idt_set_gate(36, (u32int_t)irq4, 0x08, 0x8e);
    idt_set_gate(37, (u32int_t)irq5, 0x08, 0x8e);
    idt_set_gate(38, (u32int_t)irq6, 0x08, 0x8e);
    idt_set_gate(39, (u32int_t)irq7, 0x08, 0x8e);
    idt_set_gate(40, (u32int_t)irq8, 0x08, 0x8e);
    idt_set_gate(41, (u32int_t)irq9, 0x08, 0x8e);
    idt_set_gate(42, (u32int_t)irq10, 0x08, 0x8e);
    idt_set_gate(43, (u32int_t)irq11, 0x08, 0x8e);
    idt_set_gate(44, (u32int_t)irq12, 0x08, 0x8e);
    idt_set_gate(45, (u32int_t)irq13, 0x08, 0x8e);
    idt_set_gate(46, (u32int_t)irq14, 0x08, 0x8e);
    idt_set_gate(47, (u32int_t)irq15, 0x08, 0x8e);

    idt_flush((u32int_t)&idt_ptr);
}

void idt_set_gate(u8int_t index, u32int_t base, u16int_t sel, u8int_t flags) {
    idt_entries[index].base_lo = base & 0xFFFF;
    idt_entries[index].base_hi = (base >> 16) & 0xFFFF;

    idt_entries[index].sel     = sel;
    idt_entries[index].always0 = 0;
    idt_entries[index].flags   = flags;
}