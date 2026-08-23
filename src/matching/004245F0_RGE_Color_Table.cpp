// 004245F0 RGE_Color_Table::RGE_Color_Table (palette/area ctor)
// Source: color.cpp lines 245-319
// Size: 424 bytes
//
// Exact reconstruction notes:
// - The constructor owns the 256-byte table at +0x28.
// - It uses two 256-entry local palettes and a nearest-color scan.
// - PDB data confirms the local array homes and the 0x81C-byte frame.
// - The decompiler's palette[1] labels were an
// array-base artifact. The original physical GetPalette, translate, and scan
// addresses use palette[0] and temp_palette[0]. Removing every +1 recovered
// the original 424-byte body, frame, calls, CFG, and stack overlap.
// Walkback: restoring +1 only at GetPalette caused 1 differing byte;
// restoring it in the copy caused 360 differing bytes and a six-byte body
// growth; restoring it in translate caused 2 differing bytes; restoring it
// in either nearest-color source or candidate index caused 1 differing byte.
// Therefore the zero-based form is the smallest exact source model.
//
// Context audit:
// - PDB data places this public overload in color.cpp after three sibling
// constructors. The out-of-line virtual destructor follows it.
// - The PDB owner ABI is
//   RGE_Color_Table(TDrawArea*, long, tagPALETTEENTRY*, tagPALETTEENTRY*).
// - Both exact Panel_ez.cpp callers read 256 palette entries, allocate the
// 0x128-byte object, call this constructor, and then publish its result.
// Their new-expression EH state owns allocation cleanup if construction fails.
// - This constructor has no EH frame or destructible local object. It writes
// the vptr before its first palette access. Before translation, it clears
// resource_id, type, map_color, and table. It does not write name or id.
// A fault therefore exposes only this binary-proven partial state.

#include <string.h>

struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawArea {
public:
    void GetPalette(tagPALETTEENTRY* entries);
};

void RGE_translate_palette(tagPALETTEENTRY* source, tagPALETTEENTRY* target,
                           tagPALETTEENTRY color, long amount,
                           int first, int last);

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char color_table_name[30];   // +0x04
    short resource_id;           // +0x22
    unsigned char type;          // +0x24
    unsigned char map_color;     // +0x25
    short id;                    // +0x26
    unsigned char table[256];    // +0x28

    RGE_Color_Table(TDrawArea* area, long amount,
                   tagPALETTEENTRY* base_color,
                   tagPALETTEENTRY* palette);
};

RGE_Color_Table::RGE_Color_Table(TDrawArea* area, long amount,
                                 tagPALETTEENTRY* base_color,
                                 tagPALETTEENTRY* palette_source)
{
    long temp_color;
    tagPALETTEENTRY palette[256];
    tagPALETTEENTRY temp_palette[256];
    tagPALETTEENTRY color;
    long index;

    if (palette_source == 0) {
        area->GetPalette(palette);
    } else {
        for (int i = 0; i < 256; i++) {
            palette[i].peRed = palette_source[i].peRed;
            palette[i].peGreen = palette_source[i].peGreen;
            palette[i].peBlue = palette_source[i].peBlue;
            palette[i].peFlags = palette_source[i].peFlags;
        }
    }

    if (base_color == 0) {
        color.peRed = 0;
        color.peBlue = 0;
        color.peGreen = 0;
        color.peFlags = 0;
    } else {
        color.peRed = base_color->peRed;
        color.peBlue = base_color->peBlue;
        color.peGreen = base_color->peGreen;
        color.peFlags = base_color->peFlags;
    }

    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;
    memset(this->table, 0, 256);

    RGE_translate_palette(palette, temp_palette, color, amount, -1, -1);

    index = 0;
    do {
        temp_color = 0;
        int i = 0;
        int best_distance = 20000;
        int red = temp_palette[index].peRed;
        int green = temp_palette[index].peGreen;
        int blue = temp_palette[index].peBlue;

        for (; i <= 0xff; i++) {
            int red_difference = red - palette[i].peRed;
            int green_difference = green - palette[i].peGreen;
            int blue_difference = blue - palette[i].peBlue;
            int distance = red_difference * red_difference
                         + green_difference * green_difference
                         + blue_difference * blue_difference;
            if (distance < best_distance) {
                best_distance = distance;
                temp_color = i;
            }
        }

        this->table[index] = (unsigned char)temp_color;
        index++;
    } while (index <= 0xff);
}
