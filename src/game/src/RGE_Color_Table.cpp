#include "../include/RGE_Color_Table.h"
#include "../include/TDrawArea.h"

#include <string.h>

// NOTE: This file is a best-effort reimplementation based on immutable references:
// - `src/game/src/color.cpp.asm`
// - `src/game/src/color.cpp.decomp`
//
// Only the constructor used by `TEasy_Panel::set_shadow_amount` and the destructor are implemented.

static void RGE_translate_palette(tagPALETTEENTRY* in_pal, tagPALETTEENTRY* out_pal, tagPALETTEENTRY target, long amount_percent, int skip1, int skip2) {
    // Source of truth: `color.cpp.decomp` (function `RGE_translate_palette`).
    //
    // Translates each entry toward `target` by `amount_percent`, except indices `skip1` and `skip2`.
    // The original uses integer math and a brightness term derived from the RGB components.
    for (int index1 = 0; index1 < 256; ++index1) {
        if (index1 == skip1 || index1 == skip2) {
            out_pal[index1] = in_pal[index1];
            continue;
        }

        const int red = (int)in_pal[index1].peRed;
        const int green = (int)in_pal[index1].peGreen;
        const int blue = (int)in_pal[index1].peBlue;

        // Bubble-sort three intensities to compute min/mid/max.
        int intense[3];
        intense[0] = red;
        intense[1] = green;
        intense[2] = blue;
        for (int pass = 0; pass < 2; ++pass) {
            for (int i = 0; i < 2; ++i) {
                if (intense[i] < intense[i + 1]) {
                    int t = intense[i];
                    intense[i] = intense[i + 1];
                    intense[i + 1] = t;
                }
            }
        }

        // After sorting descending: intense[0] = max, intense[1] = mid, intense[2] = min.
        const int maxv = intense[0];
        const int midv = intense[1];
        const int minv = intense[2];

        int iVar7 = (midv + maxv) * (0xFF - minv);
        // The original includes sign-fixups for arithmetic shifts; plain integer math matches C semantics.
        iVar7 = (iVar7 >> 9) + minv;
        if (iVar7 < 0) iVar7 = 0;
        if (iVar7 > 255) iVar7 = 255;

        // Move each component toward (target_component * intensity / 255).
        int target_r = ((int)target.peRed * iVar7) / 255;
        int target_g = ((int)target.peGreen * iVar7) / 255;
        int target_b = ((int)target.peBlue * iVar7) / 255;

        int delta_r = (target_r - red) * (int)amount_percent;
        int delta_g = (target_g - green) * (int)amount_percent;
        int delta_b = (target_b - blue) * (int)amount_percent;

        int out_r = red + (delta_r / 100);
        int out_g = green + (delta_g / 100);
        int out_b = blue + (delta_b / 100);

        if (out_r < 0) out_r = 0; else if (out_r > 255) out_r = 255;
        if (out_g < 0) out_g = 0; else if (out_g > 255) out_g = 255;
        if (out_b < 0) out_b = 0; else if (out_b > 255) out_b = 255;

        out_pal[index1].peRed = (BYTE)out_r;
        out_pal[index1].peGreen = (BYTE)out_g;
        out_pal[index1].peBlue = (BYTE)out_b;
        out_pal[index1].peFlags = in_pal[index1].peFlags;
    }
}

RGE_Color_Table::RGE_Color_Table() {
    memset(this, 0, sizeof(*this));
}

RGE_Color_Table::RGE_Color_Table(TDrawArea* area, long amount_percent, tagPALETTEENTRY* base_color_or_null, tagPALETTEENTRY* palette_or_null) {
    // Source of truth: `color.cpp.decomp` ctor at 0x004245F0.
    memset(this, 0, sizeof(*this));

    // Store the percent in `id` so `TDrawArea::DrawShadowBox` can shade 16/32bpp surfaces.
    // NOTE: Non-original, but contained to the runtime-generated "shadow" tables.
    if (amount_percent < 0) amount_percent = 0;
    if (amount_percent > 100) amount_percent = 100;
    this->id = (short)amount_percent;

    tagPALETTEENTRY palette[256];
    tagPALETTEENTRY temp_palette[256];
    memset(palette, 0, sizeof(palette));
    memset(temp_palette, 0, sizeof(temp_palette));

    if (palette_or_null) {
        memcpy(palette, palette_or_null, sizeof(palette));
    } else if (area) {
        area->GetPalette(palette);
    }

    tagPALETTEENTRY base;
    if (base_color_or_null) base = *base_color_or_null;
    else { base.peRed = 0; base.peGreen = 0; base.peBlue = 0; base.peFlags = 0; }

    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;
    memset(this->table, 0, sizeof(this->table));

    RGE_translate_palette(palette, temp_palette, base, amount_percent, -1, -1);

    for (int index1 = 0; index1 < 256; ++index1) {
        int best_idx = 0;
        int best_dist = 20000;
        for (int i = 0; i < 256; ++i) {
            const int dr = (int)temp_palette[index1].peRed - (int)palette[i].peRed;
            const int dg = (int)temp_palette[index1].peGreen - (int)palette[i].peGreen;
            const int db = (int)temp_palette[index1].peBlue - (int)palette[i].peBlue;
            const int dist = dr * dr + dg * dg + db * db;
            if (dist < best_dist) {
                best_dist = dist;
                best_idx = i;
            }
        }
        this->table[index1] = (unsigned char)best_idx;
    }
}

RGE_Color_Table::~RGE_Color_Table() {
    // The original destructor is trivial.
}

