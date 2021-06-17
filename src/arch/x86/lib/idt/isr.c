#include "isr.h"
#include "../../drivers/vga.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs)
{
    vga_k_print("Received interrupt: ");
    vga_decimal_print(regs.int_no);
    vga_k_print("\n");
} 