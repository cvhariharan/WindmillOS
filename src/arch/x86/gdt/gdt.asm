[GLOBAL gdt_flush]

gdt_flush:
    mov eax, [esp+4]  ; first value on the top of the stack would be the return value. So the next is the arg
    lgdt [eax] 
    mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
    mov ds, ax        ; Load all data segment selectors
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:longjmp_gdt   ; 0x08 is the offset to our code segment: Far jump!

longjmp_gdt:
   ret