#include <lib/types.h>

#ifndef VGA
#define VGA
#define VGA_COLUMNS 80
#define VGA_ROWS 25

#define VGA_BLACK 0x00
#define VGA_BLUE 0x01
#define VGA_GREEN 0x02
#define VGA_CYAN 0x03
#define VGA_RED 0x04
#define VGA_MAGENTA 0x05
#define VGA_BROWN 0x06
#define VGA_LGRAY 0x07
#define VGA_DGRAY 0x08
#define VGA_LBLUE 0x09
#define VGA_LGREEN 0x0a
#define VGA_LCYAN 0x0b
#define VGA_LRED 0x0c
#define VGA_LMAGENTA 0x0d
#define VGA_YELLOW 0x0e
#define VGA_WHITE 0x0f

// vga_k_init should be explicitly called before calling any vga funcions
// this sets up the vga framebuffer
void vga_k_init();
// vga_k_print should only be used by the kernel for printing debugging messages
// the default font color is cyan on black
void vga_k_print(const char *);
// vga_k_print_color can be used to print with a specific font color
// used internally by vga_k_print
void vga_k_print_color(const char *, byte_t);
// vga_k_clear clears the vga display buffers by setting ' ' in all locations
void vga_k_clear_screen();

void vga_decimal_print(int);

byte_t vga_get_char(byte_t, byte_t);

void vga_set_char(byte_t, byte_t, byte_t, byte_t);

int vga_raw_write(word_t *);

void vga_putchar(const char);

void vga_putchar_color(const char, byte_t);

#endif