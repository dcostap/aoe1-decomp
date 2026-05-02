// VA: 00449710 compareFilenameStrings (59 B)
// PDB source: file_stf.cpp lines 20-22
// ACCEPTED_DRIFT
// Reason: VC5 register allocation differs — uses ecx/esi/al/dl instead of
// eax/esi/dl/bl/cl. Return uses sbb/and/inc instead of sbb/sbb. No ebx save.
// Behavior-identical, same size, same 2-byte loop structure.

int __cdecl compareFilenameStrings(const unsigned char* a, const unsigned char* b) {
    unsigned char ca, cb;
    while (1) {
        ca = *a;
        cb = *b;
        if (ca != cb)
            return (ca < cb) ? -1 : 1;
        if (ca == 0) return 0;
        ca = a[1];
        cb = b[1];
        if (ca != cb)
            return (ca < cb) ? -1 : 1;
        a += 2;
        b += 2;
        if (ca == 0) return 0;
    }
}
