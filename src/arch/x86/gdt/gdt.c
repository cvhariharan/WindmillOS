#include "gdt.h"

gdt_entry_t gdt_entries[GDT_ENTRIES];
gdt_ptr_t gdt_ptr;

void init_gdt() {
    gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
    gdt_ptr.base = (u32int_t)&gdt_entries;

    // Flat-memory setup
    gdt_set_entry(0, 0, 0, 0, 0);                // Null segment
    gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    gdt_set_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    gdt_set_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

    gdt_flush((u32int_t)&gdt_ptr);
}

void gdt_set_entry(u8int_t index, u32int_t base, u32int_t limit, u8int_t access, u8int_t granularity) {
    if(index > GDT_ENTRIES) {
        return;
    }

    gdt_entries[index].limit_low = limit & 0xffff;
    gdt_entries[index].granularity = (limit >> 16) & 0x0f;
    gdt_entries[index].granularity |= granularity & 0xF0;
    gdt_entries[index].access = access;

    gdt_entries[index].base_low = base & 0xffff;
    gdt_entries[index].base_middle = (base >> 16) & 0xff;
    gdt_entries[index].base_high = (base >> 24) & 0xff;
}