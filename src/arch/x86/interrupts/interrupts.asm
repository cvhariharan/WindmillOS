extern isr_handler
extern irq_handler

global enable_interrupts

%macro isr_no_error_code 1
  global isr%1
  isr%1:
    cli                         
    push byte 0             ; hardcoded error code                
    push byte %1                
    
    pusha

    mov ax, ds
    push eax

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call isr_handler

    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    popa
    add esp, 8      ; Clears error code and isr number
    sti
    iret
%endmacro

%macro isr_error_code 1
  global isr%1
  isr%1:
    cli         
    push byte %1

    pusha

    mov ax, ds
    push eax

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call isr_handler

    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    popa
    add esp, 8
    sti
    iret
%endmacro

%macro IRQ 2
  global irq%1
  irq%1:
    cli
    push byte 0
    push byte %2
    
    pusha
    mov ax, ds
    push eax

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call irq_handler
    
    pop ebx
    mov ds, bx
    mov es, bx
    mov fs, bx
    mov gs, bx

    popa
    add esp, 8
    iret
%endmacro

enable_interrupts:
  sti
  ret



isr_no_error_code 0
isr_no_error_code 1
isr_no_error_code 2
isr_no_error_code 3
isr_no_error_code 4
isr_no_error_code 5
isr_no_error_code 6
isr_no_error_code 7
isr_error_code   8
isr_no_error_code 9
isr_error_code   10
isr_error_code   11
isr_error_code   12
isr_error_code   13
isr_error_code   14
isr_no_error_code 15
isr_no_error_code 16
isr_no_error_code 17
isr_no_error_code 18
isr_no_error_code 19
isr_no_error_code 20
isr_no_error_code 21
isr_no_error_code 22
isr_no_error_code 23
isr_no_error_code 24
isr_no_error_code 25
isr_no_error_code 26
isr_no_error_code 27
isr_no_error_code 28
isr_no_error_code 29
isr_no_error_code 30
isr_no_error_code 31

IRQ 0, 32
IRQ 1, 33
IRQ 2, 34
IRQ 3, 35
IRQ 4, 36
IRQ 5, 37
IRQ 6, 38
IRQ 7, 39
IRQ 8, 40
IRQ 9, 41
IRQ 10, 42
IRQ 11, 43
IRQ 12, 44
IRQ 13, 45
IRQ 14, 46
IRQ 15, 47

