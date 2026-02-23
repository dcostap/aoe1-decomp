#include "../include/RGE_Color_Table.h"
#include "../include/TDrawArea.h"
#include "../include/globals.h"
#include "../include/mystring.h"

#include <string.h>

// TODO(accuracy): This file is a best-effort reimplementation based on immutable references:
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
    memset(this->color_table_name, 0, sizeof(this->color_table_name));
    this->resource_id = 0;
    this->type = 0;
    this->map_color = 0;
    this->id = 0;
    memset(this->table, 0, sizeof(this->table));
}

RGE_Color_Table::RGE_Color_Table(FILE* infile, short param_id) {
    // Fully verified. Source of truth: color.cpp.decomp @ 0x00424440
    this->id = param_id;
    memset(this->table, 0, sizeof(this->table));

    short temp_map_color = 0;
    short temp_type = 0;
    fscanf(infile, " %hd %29s %hd %hd", &this->resource_id, this->color_table_name, &temp_map_color, &temp_type);
    this->map_color = (unsigned char)temp_map_color;
    this->type = (unsigned char)temp_type;

    char* with_ext = nullptr;
    addstring(&with_ext, this->color_table_name, (char*)".col");
    if (with_ext != nullptr) {
        strncpy(this->color_table_name, with_ext, sizeof(this->color_table_name) - 1);
        this->color_table_name[sizeof(this->color_table_name) - 1] = '\0';
        free(with_ext);
    }
}

RGE_Color_Table::RGE_Color_Table(int fd) {
    // Source of truth: color.cpp.decomp line 192
    rge_read(fd, this->color_table_name, 0x1E);
    rge_read(fd, &this->id, 2);
    rge_read(fd, &this->resource_id, 2);
    rge_read(fd, &this->map_color, 1);
    rge_read(fd, &this->type, 1);

    // Read the 256-byte translation table from data\<name>
    char data_path[260];
    sprintf(data_path, "data\\%s", this->color_table_name);
    FILE* f = fopen(data_path, "r");
    if (f) {
        for (int i = 0; i < 256; i++) {
            short val;
            fscanf(f, " %hd", &val);
            this->table[i] = (unsigned char)val;
        }
        fclose(f);
    }
}

RGE_Color_Table::RGE_Color_Table(TDrawArea* area, long amount_percent, tagPALETTEENTRY* base_color_or_null, tagPALETTEENTRY* palette_or_null) {
    // Source of truth: `color.cpp.decomp` ctor at 0x004245F0.
    memset(this->color_table_name, 0, sizeof(this->color_table_name));
    this->resource_id = 0;
    this->type = 0;
    this->map_color = 0;
    this->id = 0;
    memset(this->table, 0, sizeof(this->table));

    // Store the percent in `id` so `TDrawArea::DrawShadowBox` can shade 16/32bpp surfaces.
    // NOTE: Non-original, but contained to the runtime-generated "shadow" tables.
    if (amount_percent < 0) amount_percent = 0;
    if (amount_percent > 100) amount_percent = 100;
    this->id = (short)amount_percent;

    tagPALETTEENTRY palette[257];
    tagPALETTEENTRY temp_palette[257];
    memset(palette, 0, sizeof(palette));
    memset(temp_palette, 0, sizeof(temp_palette));

    if (palette_or_null) {
        memcpy(&palette[1], palette_or_null, 256 * sizeof(tagPALETTEENTRY));
    } else if (area) {
        area->GetPalette(&palette[1]);
    }

    tagPALETTEENTRY base;
    if (base_color_or_null) base = *base_color_or_null;
    else { base.peRed = 0; base.peGreen = 0; base.peBlue = 0; base.peFlags = 0; }

    RGE_translate_palette(&palette[1], &temp_palette[1], base, amount_percent, -1, -1);

    for (int index1 = 0; index1 < 256; ++index1) {
        int best_idx = 0;
        int best_dist = 20000;
        const tagPALETTEENTRY& target = temp_palette[index1 + 1];
        for (int i = 0; i < 256; ++i) {
            const tagPALETTEENTRY& candidate = palette[i + 1];
            const int dr = (int)target.peRed - (int)candidate.peRed;
            const int dg = (int)target.peGreen - (int)candidate.peGreen;
            const int db = (int)target.peBlue - (int)candidate.peBlue;
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

