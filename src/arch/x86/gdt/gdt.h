#include "../lib/types.h"

#ifndef _GDT_
#define _GDT_
#define GDT_ENTRIES 5
#endif

struct _gdt_entry {
   u16int_t limit_low;  
   u16int_t base_low;   
   u8int_t  base_middle;
   u8int_t  access;     
   u8int_t  granularity;
   u8int_t  base_high;  
} __attribute__((packed));

typedef struct _gdt_entry gdt_entry_t;

struct _gdt_ptr {
    u16int_t limit;
    u32int_t base;
}__attribute__((packed));

typedef struct _gdt_ptr gdt_ptr_t;

void init_gdt();

extern void gdt_flush(u32int_t);