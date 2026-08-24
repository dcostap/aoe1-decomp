// attempt 2: derive COLORREFs from palette entries and install system color slots 5 and 8

#ifndef AOE1_PANEL_EZ_CONTEXT_H
struct PALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(void* palette, unsigned int start, unsigned int count, PALETTEENTRY* entries);
extern "C" __declspec(dllimport) int __stdcall SetSysColors(int count, const int* elements, const unsigned long* colors);
#endif

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    char gap_000[0xEF];
    unsigned char color_index;
    char gap_0F0[0x20C - 0xF0];
    void* palette;
    char gap_210[0x328 - 0x210];
    unsigned long text_color1;

    void set_system_colors();
};
#endif

void TEasy_Panel::set_system_colors() {
    unsigned long color;
    int element;
    PALETTEENTRY pe;
    PALETTEENTRY entry;

    GetPaletteEntries(this->palette, this->color_index, 1, &entry);
    color = ((unsigned long)entry.peBlue << 16) | ((unsigned long)entry.peGreen << 8) | entry.peRed;
    element = 5;
    SetSysColors(1, &element, &color);

    GetPaletteEntries(this->palette, this->text_color1, 1, &entry);
    color = ((unsigned long)entry.peBlue << 16) | ((unsigned long)entry.peGreen << 8) | entry.peRed;
    element = 8;
    SetSysColors(1, &element, &color);
}
