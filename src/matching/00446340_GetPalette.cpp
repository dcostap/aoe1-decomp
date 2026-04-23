struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawArea {
public:
    void* DrawSystem;

    void GetPalette(tagPALETTEENTRY* palette);
};

void TDrawArea::GetPalette(tagPALETTEENTRY* palette) {
    int* out = (int*)palette;
    int offset = 0x78 - (int)out;
    int count = 0x100;

    do {
        *out = *(int*)((int)this->DrawSystem + offset + (int)out);
        out++;
    } while (--count);
}
