#pragma once
#include "common.h"

class RGE_Color_Table {
public:
    // Virtuals (best-effort)
    virtual ~RGE_Color_Table(); // vt[0] (0x0)

    // Constructors (reimplementation; source of truth: `src/game/src/color.cpp.asm` / `.decomp`).
    RGE_Color_Table();
    RGE_Color_Table(int fd);
    RGE_Color_Table(struct TDrawArea* area, long amount_percent, struct tagPALETTEENTRY* base_color_or_null, struct tagPALETTEENTRY* palette_or_null);

    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];
};
static_assert(sizeof(RGE_Color_Table) == 0x128, "Size mismatch");
