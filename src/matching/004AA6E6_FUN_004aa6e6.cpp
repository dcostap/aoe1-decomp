// PSEUDO-FUNCTION: padding-only exception.
// ORIGINAL ASM: mov edi,edi
__declspec(naked) void padding_pseudo_function(void) {
    __asm _emit 0x8B
    __asm _emit 0xFF
}
