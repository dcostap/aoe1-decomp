// VA: 0043AA90 xlatClut4 (50B, Dib.cpp)
// Translate a buffer of packed 4-bit color indices through a CLUT.
// For each byte, splits into high/low nibbles, looks up each in the
// lookup table, and recombines: result = (lut[val>>4] << 4) | lut[val&0xF]

void __cdecl xlatClut4(unsigned char* buffer, unsigned int count, unsigned char* lut) {
    if (count == 0) return;
    do {
        unsigned char val = *buffer;
        unsigned char hi = val >> 4;
        unsigned char lo = val & 0xF;
        *buffer = (unsigned char)((lut[hi] << 4) | lut[lo]);
        buffer++;
    } while (--count != 0);
}
