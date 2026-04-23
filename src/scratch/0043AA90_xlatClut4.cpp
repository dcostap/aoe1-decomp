void __cdecl xlatClut4(unsigned char* data, int count, unsigned char* table) {
    if (count != 0) {
        do {
            *data = table[*data & 0x0F] | (table[*data >> 4] << 4);
            data = data + 1;
            count = count - 1;
        } while (count != 0);
    }
}
