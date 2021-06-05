#ifndef VGA
#define VGA
#define VGA_COLUMNS 80
#define VGA_ROWS 25

void vga_k_init();
void vga_k_print(const char *);
void vga_k_clear_screen();

#endif