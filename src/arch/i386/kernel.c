#define VGA_COLUMNS 80
#define VGA_ROWS 25

void clear_screen(char *);

k_start() {
    const char *str = "Windmill OS";
    char *vga_buffer = (char *) 0xb8000;

    clear_screen(vga_buffer);
    
    int i = 0, j = 0;
    while(str[j] != '\0') {
        vga_buffer[i] = str[j];

        // x86 is little endian so the colors come afterwards. Eg 0x0248 -> 48 02
        vga_buffer[i+1] = 0x02; // Green color font
        i += 2;
        j++;
    }
}

void clear_screen(char *vga_buffer) {
    for(int i = 0; i < VGA_COLUMNS * VGA_ROWS * 2; i = i+2) {
        vga_buffer[i] = ' ';
        vga_buffer[i+1] = 0x07;
    }
}