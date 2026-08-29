// PSEUDO-FUNCTION: padding-only exception.
__declspec(naked) void padding_pseudo_function(void) {
    __asm _emit 0x90
}
