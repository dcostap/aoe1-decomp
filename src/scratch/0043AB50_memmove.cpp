// VA: 0043AB50 memmove (42B)
// Dib.cpp - custom reverse copy memmove, extern C

extern "C" void memmove(void* dst, const void* src, int size) {
    int count = size;
    char* d = (char*)dst + count - 1;
    const char* s = (const char*)src + count - 1;
    if (count != 0) {
        do {
            *d-- = *s--;
        } while (--count != 0);
    }
}
