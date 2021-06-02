k_start() {
    int *vga_buffer = (int *) 0xb8000;

    *(vga_buffer) = 0x0248;
    *(vga_buffer + 1) = 0x0249;
    *(vga_buffer + 2) = 0x0221;
}