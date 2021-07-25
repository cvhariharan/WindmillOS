# Windmill OS
A very basic operating system.


### Build Instructions
Prerequisites
- gcc
- ld
- qemu
- grub-mkrescue

Clone the repo and run `make` to build the cross-compiler and the kernel and to start the OS in qemu. Use `grub-mkrescue` if `grub2-mkrescue` doesn't work on debian based systems.  
The first build will take some time because it will download binutils and gcc to build the i386 cross-compiler. Subsequent builds would be faster.