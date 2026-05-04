// VA: 00449710 compareFilenameStrings (59 B)
// PDB source: file_stf.cpp lines 20-22
// ACCEPTED_DRIFT: VC5 register allocation differs from original.
// Original: eax/esi for pointers, dl/bl/cl for bytes, sbb return.
// Rebuilt:  eax/esi for pointers, cl/dl for bytes, setge return.
// Behavior-identical. Matching: prologue, pointer handling, comparisons,
// increment by 2, null checks, return 0 path. 35/59 edit-equal bytes.
// Remaining drift: register choice (cl/dl vs dl/bl/cl), missing push ebx,
// conditional jump at bottom (jmp vs test+jne), and return computation
// (setge/dec/and/inc vs sbb/sbb).

int __cdecl compareFilenameStrings(const char* a, const char* b) {
    char ca, cb;

    while (1) {
        ca = *a;
        cb = *b;
        if (ca != cb) return (ca < cb) ? -1 : 1;
        if (ca == 0) return 0;
        ca = a[1];
        cb = b[1];
        if (ca != cb) return (ca < cb) ? -1 : 1;
        a += 2;
        b += 2;
        if (ca == 0) return 0;
    }
}
