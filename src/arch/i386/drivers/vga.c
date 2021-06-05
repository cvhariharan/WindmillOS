#include "vga.h"

char *vga_buffer = 0;

void vga_k_init() {
    if(vga_buffer == 0) {
        vga_buffer = (char *) 0xb8000;
    }
}

void vga_k_print(const char *str) {
    if(vga_buffer == 0) {
        vga_k_init();
    }

    int i = 0, j = 0;
    while(str[j] != '\0') {
        vga_buffer[i] = str[j];

        // x86 is little endian so the colors come afterwards. Eg 0x0248 -> 48 02
        vga_buffer[i+1] = 0x02; // Green color font
        i += 2;
        j++;
    }
}
void vga_k_clear_screen() {
    if(vga_buffer == 0) {
        vga_k_init();
    }
    for(int i = 0; i < VGA_COLUMNS * VGA_ROWS * 2; i = i+2) {
        vga_buffer[i] = ' ';
        vga_buffer[i+1] = 0x07;
    }
}