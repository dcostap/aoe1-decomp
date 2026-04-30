// VA: 0043AA90 xlatClut4 (50B)
// Dib.cpp - color lookup table translation with explicit ordering

void xlatClut4(unsigned char* buf, unsigned int count, unsigned char* table) {
    if (count == 0) return;
    do {
        unsigned char val = *buf;
        unsigned char high = table[val >> 4];
        unsigned char low = table[val & 0x0F];
        *buf = (unsigned char)((high << 4) | low);
        buf++;
    } while (--count != 0);
}
