#include <drivers/vga.h>
#include <lib/types.h>
#include <gdt/gdt.h>
#include <interrupts/idt.h>
#include <pic.h>
#include <userinput/mouse.h>
#include <stdio.h>

k_start() {

    init_gdt();
    init_idt();
    pic_init();
    mouse_init();

    vga_k_init();
    vga_k_clear_screen();

    enable_interrupts();
    
    
    for(int i = 0; i < 15; i++) {
        printf("%s", "*");
    }
    printf("\n");

    printf("%s\n", "* Windmill OS *");

    for(int i = 0; i < 15; i++) {
        printf("%s", "*");
    }
    printf("\n");
    
    for(;;) {asm("hlt");}
}