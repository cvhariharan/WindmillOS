k_start() {
    const char *str = "Hi!";
    char *vga_buffer = (char *) 0xb8000;

    int i = 0, j = 0;
    while(str[j] != '\0') {
        vga_buffer[i] = str[j];

        // x86 is little endian so the colors come afterwards. Eg 0x0248 -> 48 02
        vga_buffer[i+1] = 0x02; // Green color font
        i += 2;
        j++;
    }
}