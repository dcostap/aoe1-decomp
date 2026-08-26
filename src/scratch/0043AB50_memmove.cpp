// VA: 0043AB50 memmove (42B)
// PDB source: Dib.cpp lines 1770-1776
// BINARY NOTE: Dib.cpp has already included the CRT memmove declaration when
// this owner is grouped. The canonical return and const source surface avoids
// a C-linkage conflict; the helper's return value is unused by its caller.
// TU captain, 2026-08-26, owner sa-c6a4d383-r1:
// - The original source form with a separate count local and no parameter
//   reload reduced the mismatch from 39 bytes to two LEA SIB bytes.
// - Pointer arithmetic, endpoint indexing, declaration order, and byte-pointer
//   parameter probes were codegen duplicates.
// - Returning the decremented working pointer changed the public return value.
//   It was rejected despite its smaller two-byte mismatch.
extern "C" void* memmove(void* dst_arg, const void* src_arg,
    unsigned int n) {
    unsigned char* dst = (unsigned char*)dst_arg;
    unsigned char* src = (unsigned char*)src_arg;
    int count;

    dst = dst + n - 1;
    count = n;
    src = src + n - 1;
    n = n - 1;
    if (count != 0) {
        count = n + 1;
        do {
            *dst = *src;
            dst = dst - 1;
            src = src - 1;
            count = count - 1;
        } while (count != 0);
    }
    return dst_arg;
}
