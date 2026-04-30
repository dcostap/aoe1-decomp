// VA: 00449710 compareFilenameStrings
// file_stf.cpp lines 20-22
// 59 bytes
// BLOCKER: VC5 optimizes 2-byte-at-a-time loop into 1-byte-at-a-time.
// The original processes 2 bytes per iteration (add eax,2; add esi,2)
// with eax/esi as pointers and cl as saved second byte. Our VC5
// generates inc ecx; inc edx (byte-at-a-time) regardless of source shape.
//
// Attempt log:
// - while(1) with explicit 2-byte loop: VC5 optimizes to byte-at-a-time
// - do-while with a[-1] check: same optimization
// - separate inc a; inc b twice instead of a+=2: same
// - int locals for byte values: same
// - goto-style break with unified diff return: same
// - unsigned char* with explicit single-byte loads: same
// - while(*a==*b) with inner if breaks: same
// - literal Ghidra decomp with bVar2 boolean tracking: same
// FLAGS: none
// NOTE: Might be VC5 CRT strcmp-style pattern, or a different VC5 version.
// The 2-byte optimization is not reproducible with our build setup.

int compareFilenameStrings(const unsigned char* a, const unsigned char* b) {
    unsigned char c;
    while (1) {
        c = *a;
        if (c != *b) break;
        if (c == 0) return 0;
        c = a[1];
        if (c != b[1]) break;
        a += 2;
        b += 2;
        if (c == 0) return 0;
    }
    if (*a < *b) return -1;
    return 1;
}
