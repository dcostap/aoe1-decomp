// 004245F0 RGE_Color_Table::RGE_Color_Table (palette/area ctor)
// Source: color.cpp lines 245-319
// Size: 424 bytes
//
// Attempt log:
// Probe 1: 352/424B — structural probe, too short (need proper palette fade math)

#include "..\..\include\game_globals.h"

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table() {}
    char color_table_name[30];   // +0x04
    short resource_id;           // +0x22
    unsigned char type;          // +0x24
    unsigned char map_color;     // +0x25
    short id;                    // +0x26
    unsigned char table[256];    // +0x28

    RGE_Color_Table(void* area, long percent, void* base_color, void* palette);
};

struct ColorEntry {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char flags;
};

RGE_Color_Table::RGE_Color_Table(void* area, long percent, void* base_color, void* palette)
{
    this->resource_id = 0;
    this->type = 0;
    this->map_color = 0;
    this->id = 0;
    // Copy palette entries with fade
    if (palette) {
        ColorEntry* src = (ColorEntry*)palette;
        for (int i = 0; i < 256; i++) {
            int r = src[i].r;
            int g = src[i].g;
            int b = src[i].b;

            if (base_color) {
                ColorEntry* bc = (ColorEntry*)base_color;
                r = (r * percent + bc[i].r * (100 - percent)) / 100;
                g = (g * percent + bc[i].g * (100 - percent)) / 100;
                b = (b * percent + bc[i].b * (100 - percent)) / 100;
            }

            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;
            if (r < 0) r = 0;
            if (g < 0) g = 0;
            if (b < 0) b = 0;

            this->table[i] = (unsigned char)r;
        }
    }
}
