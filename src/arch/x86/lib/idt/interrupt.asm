extern isr_handler

%macro isr_no_error_code 1
  global isr%1
  isr%1:
    cli                         
    push byte 0             ; hardcoded error code                
    push byte %1                
    jmp isr_common_stub         
%endmacro

%macro isr_error_code 1
  global isr%1
  isr%1:
    cli         
    push byte %1
    jmp isr_common_stub
%endmacro

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


isr_common_stub:
   pusha                    ; Pushes edi,esi,ebp,esp,ebx,edx,ecx,eax

   mov ax, ds               ; Lower 16-bits of eax = ds.
   push eax                 ; save the data segment descriptor

   mov ax, 0x10  ; load the kernel data segment descriptor
   mov ds, ax
   mov es, ax
   mov fs, ax
   mov gs, ax

   call isr_handler

   pop eax        ; reload the original data segment descriptor
   mov ds, ax
   mov es, ax
   mov fs, ax
   mov gs, ax

   popa                     ; Pops edi,esi,ebp...
   add esp, 8     ; Cleans up the pushed error code and pushed ISR number
   sti
   iret           ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP