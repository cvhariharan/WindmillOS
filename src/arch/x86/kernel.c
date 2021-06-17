#include "drivers/vga.h"
#include "lib/types.h"
#include "lib/gdt/gdt.h"
#include "lib/idt/idt.h"

k_start() {

    init_gdt();
    init_idt();

    vga_k_init();
    vga_k_clear_screen();

    asm volatile ("int $0x3");
    asm volatile ("int $0x4");

    
    vga_k_print_color("Windmill OS\n", VGA_GREEN);
    vga_k_print("0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n");
}