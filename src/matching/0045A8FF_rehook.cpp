// PSEUDO-FUNCTION: padding-only exception.
// ORIGINAL ASM: nop
__declspec(naked) void padding_pseudo_function(void) {
    __asm _emit 0x90
}
