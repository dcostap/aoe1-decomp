// PSEUDO-FUNCTION: padding-only exception.
// ORIGINAL ASM: nop ; nop ; nop ; nop ; nop
__declspec(naked) void padding_pseudo_function(void) {
    __asm _emit 0x90
    __asm _emit 0x90
    __asm _emit 0x90
    __asm _emit 0x90
    __asm _emit 0x90
}
