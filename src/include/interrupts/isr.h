#include "../lib/types.h"

typedef struct registers
{
   u32int_t ds;
   u32int_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
   u32int_t int_no, err_code;
   u32int_t eip, cs, eflags, useresp, ss;
} registers_t; 