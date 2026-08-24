// attempt 2: natural shadow amount setter with virtual delete of old color table and palette-derived replacement

#ifndef AOE1_PANEL_EZ_CONTEXT_H
struct PALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(void* palette, unsigned int start, unsigned int count, PALETTEENTRY* entries);
#endif

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char data[0x124];
    RGE_Color_Table(void* draw_area, long amount, PALETTEENTRY* colors, PALETTEENTRY* palette_entries);
};

class TEasy_Panel {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void redraw(long mode);
    char gap_004[0x20 - 4];
    void* draw_area;
    char gap_024[0x78 - 0x24];
    void* panel_window;
    char gap_07C[0x20C - 0x7C];
    void* palette;
    char gap_210[0x44C - 0x210];
    RGE_Color_Table* shadow_color_table;
    long shadow_amount;

    void set_shadow_amount(long amount);
};
#endif

void TEasy_Panel::set_shadow_amount(long amount) {
    PALETTEENTRY palette_entries[256];

    if (amount == -1) {
        this->shadow_amount = 0;
    } else {
        this->shadow_amount = amount;
    }

    if (this->shadow_color_table != 0) {
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    if (this->palette != 0 && this->shadow_amount > 0) {
        if (GetPaletteEntries(this->palette, 0, 0x100, palette_entries)) {
            this->shadow_color_table = new RGE_Color_Table(this->draw_area, this->shadow_amount, 0, palette_entries);
        }
    }

    if (this->panel_window != 0) {
        this->redraw(2);
    }
}
