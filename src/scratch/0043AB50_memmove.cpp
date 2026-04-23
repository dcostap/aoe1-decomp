void* memmove(void* dest, const void* src, unsigned int count) {
    unsigned char* d = (unsigned char*)dest + count - 1;
    const unsigned char* s = (const unsigned char*)src + count - 1;
    if (count != 0) {
        do {
            *d = *s;
            --d;
            --s;
            --count;
        } while (count != 0);
    }
    return dest;
}
