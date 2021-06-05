#include "drivers/vga.h"

void clear_screen(char *);

k_start() {
    const char *str = "Windmill OS";

    vga_k_init();
    vga_k_clear_screen();
    vga_k_print("Testing 123... Booting Windmill OS");
}