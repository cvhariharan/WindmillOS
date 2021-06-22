#include "vga.h"

char *vga_buffer = 0;
int global_x = 0, global_y = 0;

void vga_k_init() {
    if(vga_buffer == 0) {
        vga_buffer = (char *) 0xb8000;
    }
}

int vga_raw_write(word_t *arr) {
    int i = 0;
    while(arr[i] != '\0') {
        vga_buffer[i] = arr[i] | 0x00ff;
        vga_buffer[i+1] = arr[i] >> 8;
        i += 2;
    }
}

void vga_k_print(const char *str) {
    vga_k_print_color(str, VGA_CYAN);
}

void vga_decimal_print(int num) {
    char str[2] = {'0' + num, '\0'};
    vga_k_print(str);
}

void vga_k_print_color(const char *str, byte_t color) {
    if(vga_buffer == 0) {
        vga_k_init();
    }

    int c = 0, i = global_x, j = global_y;
    while(str[c] != '\0') {

        switch(str[c]) {
            case '\n':
                j += 1;
                i = 0;
                break;

            default:
                vga_set_char(str[c], i, j, color);
                i += 1;
        }

        c += 1;
        
        if(i >= VGA_COLUMNS) {
            i = 0;
            j += 1;
        }
        
        if(j >= VGA_ROWS) {
            vga_scroll_up();
            j -= 1;
        }

        global_x = i;
        global_y = j;
    }
}


void vga_putchar(const char c) {
    const char s[2] = {c, '\0'};
    vga_k_print_color(s, VGA_GREEN);
}

void vga_k_clear_screen() {
    if(vga_buffer == 0) {
        vga_k_init();
    }
    for(int i = 0; i < VGA_COLUMNS * VGA_ROWS * 2; i = i+2) {
        vga_buffer[i] = ' ';
        vga_buffer[i+1] = 0x00;
    }
}

byte_t vga_get_char(byte_t x, byte_t y) {
    int index = (y * VGA_COLUMNS + x) * 2;                         
    return vga_buffer[index];
}

void vga_set_char(byte_t ch, byte_t x, byte_t y, byte_t color) {
    if(vga_buffer == 0) {
        vga_k_init();
    }
    int index = (y * VGA_COLUMNS + x) * 2;                                 // 2 bytes for each character
    vga_buffer[index] = ch;
    vga_buffer[index+1] = color;
}

void vga_scroll_up() {
    for(int i = 0; i < VGA_COLUMNS; i++) {
        for(int j = 0; j < VGA_ROWS - 1; j++) {
            vga_set_char(vga_get_char(i, j+1), i, j, VGA_CYAN);
        }
    }

    // Clear the remaining characters in the last row
    int i = 0;
    while(i < VGA_COLUMNS) {
        vga_set_char(' ', i, VGA_ROWS - 1, VGA_BLACK);
        i++;
    }
}