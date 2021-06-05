#ifndef VGA
#define VGA
#define VGA_COLUMNS 80
#define VGA_ROWS 25

// vga_k_init should be explicitly called before calling any vga funcions
// this sets up the vga framebuffer
void vga_k_init();
// vga_k_print should only be used by the kernel for printing debugging messages
// the default font color is cyan on black
void vga_k_print(const char *);
// vga_k_clear clears the vga display buffers by setting ' ' in all locations
void vga_k_clear_screen();

#endif