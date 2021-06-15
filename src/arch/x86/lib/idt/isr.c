#include "isr.h"
#include "../../drivers/vga.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs)
{
    vga_k_init();
    vga_k_clear_screen();
    vga_k_print("Received interrupt\n");
} 