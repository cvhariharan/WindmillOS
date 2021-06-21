#include "../lib/types.h"

typedef struct registers
{
   u32int_t ds;                  // Data segment selector
   u32int_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   u32int_t int_no, err_code;    // Interrupt number and error code (if applicable)
   u32int_t eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t; 