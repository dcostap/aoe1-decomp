// 004245F0 RGE_Color_Table::RGE_Color_Table (palette/area ctor)
// Source: color.cpp lines 245-319
// Size: 424 bytes
//
// Attempt log:
// Probe 1: 352/424B — structural probe, too short (need proper palette fade math)
// Baseline: typed palette reconstruction with the GetPalette and
// RGE_translate_palette calls, two 256-entry local palettes, and nearest-color
// search. The constructor owns the inline 0x100-byte table at +0x28.
// Explicit four-channel copy reached 405/424B and 368 differing bytes.
// A pointer alias copy and a byte-cursor copy moved code farther or changed
// saved-register allocation, so both were restored.
// Initializing the inner scan index before RGB extraction and using <= 0xFF
// matched the original loop guard and improved block coverage.
// A register-qualified palette parameter produced duplicate code and was
// removed from the living source. Remaining drift is prologue register order,
// copy-loop topology, and local store scheduling.
// Retry r2: Reordered base-color byte stores to red, blue, green, flags; this
// improved shape but worsened positional diff and was restored.
// Added the binary-listed unused temp_color local; VC5 emitted identical code.
// Reconstructed the Ghidra pointer-cursor palette copy; it reached exact size
// but worsened block coverage and was restored. Final validation is the clean
// indexed channel-copy source above. Calls, frame, and CFG counts are exact;
// the remaining structural gap starts in parameter-home/prologue scheduling.
// Follow-up TU pass: spelling the nearest scan bound as i <= 0xff improved the
// strict diff from 368 to 355 bytes and aligned the inner branch shape.
// Typed source/destination cursors, reused loop counters, and declaration-order
// changes were duplicate or worse. The indexed copy remains the source model.

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
    virtual ~RGE_Color_Table() {}
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
    tagPALETTEENTRY palette[256];
    tagPALETTEENTRY temp_palette[256];
    tagPALETTEENTRY color;
    long index;

    if (palette_source == 0) {
        area->GetPalette(palette + 1);
    } else {
        for (int i = 0; i < 256; i++) {
            palette[i + 1].peRed = palette_source[i].peRed;
            palette[i + 1].peGreen = palette_source[i].peGreen;
            palette[i + 1].peBlue = palette_source[i].peBlue;
            palette[i + 1].peFlags = palette_source[i].peFlags;
        }
    }

    if (base_color == 0) {
        color.peRed = 0;
        color.peGreen = 0;
        color.peBlue = 0;
        color.peFlags = 0;
    } else {
        color = *base_color;
    }

    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;
    memset(this->table, 0, 256);

    RGE_translate_palette(palette + 1, temp_palette + 1, color, amount, -1, -1);

    index = 0;
    do {
        int best_color = 0;
        int i = 0;
        int best_distance = 20000;
        int red = temp_palette[index + 1].peRed;
        int green = temp_palette[index + 1].peGreen;
        int blue = temp_palette[index + 1].peBlue;

        for (; i <= 0xff; i++) {
            int red_difference = red - palette[i + 1].peRed;
            int green_difference = green - palette[i + 1].peGreen;
            int blue_difference = blue - palette[i + 1].peBlue;
            int distance = red_difference * red_difference
                         + green_difference * green_difference
                         + blue_difference * blue_difference;
            if (distance < best_distance) {
                best_distance = distance;
                best_color = i;
            }
        }

        this->table[index] = (unsigned char)best_color;
        index++;
    } while (index <= 0xff);
}
