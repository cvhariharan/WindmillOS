; multiboot headers

section .multiboot_header
header:
    dd 0xe85250d6                ; magic number
    dd 0                         ; protected mode code
    dd end - header

    dd 0x100000000 - (0xe85250d6 + 0 + (end - header))

    dw 0
    dw 0
    dd 8
end:

section .bss
align 16
stack_bottom:
resb 16384 ; 16 KiB
stack_top:

global _start
extern k_start

section .text
bits 32
    _start:
        mov esp, stack_top
        push ebp
        mov ebp, esp
        call k_start
        mov esp, ebp
        pop ebp

        cli
.hang:  hlt
        jmp .hang
