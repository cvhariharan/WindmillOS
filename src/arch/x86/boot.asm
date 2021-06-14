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