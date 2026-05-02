// VA: 0043AB50 memmove (42B)
// PDB source: Dib.cpp lines 1770-1776

extern "C" void memmove(unsigned char* dst, unsigned char* src, int n) {
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
}
