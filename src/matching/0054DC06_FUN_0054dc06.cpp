// PSEUDO-FUNCTION: padding-only exception.
// ORIGINAL ASM: mov eax,eax
__declspec(naked) void padding_pseudo_function(void) {
    __asm _emit 0x8B
    __asm _emit 0xC0
}
