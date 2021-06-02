global _start
extern k_start

section .text
bits 32
_start:
    push ebp
    mov ebp, esp
    call k_start
    mov esp, ebp
    pop ebp
    hlt