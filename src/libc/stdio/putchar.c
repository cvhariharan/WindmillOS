#include <stdio.h>

#if defined(__is_libk)
#include <drivers/vga.h>
#endif

int putchar(int ic) {
#if defined(__is_libk)
	char c = (char) ic;
	vga_putchar(c);
#else
	// TODO: Implement stdio and the write system call.
#endif
	return ic;
}
