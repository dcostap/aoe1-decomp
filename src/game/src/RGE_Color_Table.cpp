#include "../include/RGE_Color_Table.h"
#include "../include/TDrawArea.h"
#include "../include/globals.h"
#include "../include/mystring.h"

#include <string.h>

static void RGE_translate_palette(tagPALETTEENTRY* in_pal, tagPALETTEENTRY* out_pal, tagPALETTEENTRY target, long amount_percent, int skip1, int skip2) {
    // Fully verified. Source of truth: color.cpp.decomp @ 0x00423EE0
    for (int index1 = 0; index1 < 256; ++index1) {
        if (index1 == skip1 || index1 == skip2) {
            out_pal[index1] = in_pal[index1];
            continue;
        }

        const int red = (uint)in_pal[index1].peRed & 0xff;
        const int green = (uint)in_pal[index1].peGreen & 0xff;
        const int blue = (uint)in_pal[index1].peBlue & 0xff;

        // Bubble-sort 3 values descending: intense[0]=max, intense[1]=mid, intense[2]=min.
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

        // `iVar7` is a derived "brightness" term used to keep hues while shifting toward `target`.
        int iVar7 = (int)((uint)(intense[1] + intense[2]) * (uint)(0xff - intense[0]));
        iVar7 = ((iVar7 + ((iVar7 >> 0x1f) & 0x1ff)) >> 9) + intense[0];

        const int target_r = (((uint)target.peRed & 0xff) * iVar7) / 0xff;
        const int target_g = (((uint)target.peGreen & 0xff) * iVar7) / 0xff;
        const int target_b = (((uint)target.peBlue & 0xff) * iVar7) / 0xff;

        const int delta_r = (target_r - red) * (int)amount_percent;
        const int delta_g = (target_g - green) * (int)amount_percent;
        const int delta_b = (target_b - blue) * (int)amount_percent;

        out_pal[index1].peRed = (BYTE)(red + (delta_r / 100));
        out_pal[index1].peGreen = (BYTE)(green + (delta_g / 100));
        out_pal[index1].peBlue = (BYTE)(blue + (delta_b / 100));
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
    fscanf(infile, " %hd %s %hd %hd", &this->resource_id, this->color_table_name, &temp_map_color, &temp_type);
    this->map_color = (unsigned char)temp_map_color;
    this->type = (unsigned char)temp_type;

    char* file_name = nullptr;
    addstring(&file_name, this->color_table_name, (char*)".col");
    if (file_name != nullptr) {
        strcpy(this->color_table_name, file_name);
        free(file_name);
    }
}

RGE_Color_Table::RGE_Color_Table(int fd) {
    // Fully verified. Source of truth: color.cpp.decomp @ 0x00424350
    rge_read(fd, this->color_table_name, 0x1E);
    rge_read(fd, &this->id, 2);
    rge_read(fd, &this->resource_id, 2);
    rge_read(fd, &this->map_color, 1);
    rge_read(fd, &this->type, 1);

    char tempname[300];
    sprintf(tempname + 4, "data\\%s", this->color_table_name);

    FILE* f = fopen(tempname + 4, "r");
    if (f != nullptr) {
        for (int i = 0; i < 0x100; ++i) {
            short temp_color = 0;
            fscanf(f, "%hd", &temp_color);
            this->table[i] = (unsigned char)temp_color;
        }
        fclose(f);
    }
}

RGE_Color_Table::RGE_Color_Table(char* param_1) {
    // Fully verified. Source of truth: color.cpp.decomp @ 0x004244F0
    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;
    memset(this->table, 0, sizeof(this->table));

    strcpy(this->color_table_name, param_1);
    strcat(this->color_table_name, ".col");

    char tempname[300];
    sprintf(tempname + 4, "data\\%s", this->color_table_name);

    FILE* f = fopen(tempname + 4, "r");
    if (f != nullptr) {
        for (int i = 0; i < 0x100; ++i) {
            short temp_color = 0;
            fscanf(f, "%hd", &temp_color);
            this->table[i] = (unsigned char)temp_color;
        }
        fclose(f);
    }
}

RGE_Color_Table::RGE_Color_Table(TDrawArea* area, long amount_percent, tagPALETTEENTRY* base_color_or_null, tagPALETTEENTRY* palette_or_null) {
    // Fully verified. Source of truth: color.cpp.asm @ 0x004245F0
    tagPALETTEENTRY palette[257];
    tagPALETTEENTRY temp_palette[257];

    if (palette_or_null == nullptr) {
        area->GetPalette(palette + 1);
    } else {
        memcpy(palette + 1, palette_or_null, 0x100 * sizeof(tagPALETTEENTRY));
    }

    tagPALETTEENTRY base;
    if (base_color_or_null == nullptr) {
        base.peRed = 0;
        base.peGreen = 0;
        base.peBlue = 0;
        base.peFlags = 0;
    } else {
        base = *base_color_or_null;
    }

    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;
    memset(this->table, 0, sizeof(this->table));

    RGE_translate_palette(palette + 1, temp_palette + 1, base, amount_percent, -1, -1);

    for (int index1 = 0; index1 <= 0xff; ++index1) {
        int best_idx = 0;
        int best_dist = 0x4e20;

        const int temp_r = (uint)temp_palette[index1 + 1].peRed & 0xff;
        const int temp_g = (uint)temp_palette[index1 + 1].peGreen & 0xff;
        const int temp_b = (uint)temp_palette[index1 + 1].peBlue & 0xff;

        for (int i = 0; i <= 0xff; ++i) {
            const int pal_r = (uint)palette[i + 1].peRed & 0xff;
            const int pal_g = (uint)palette[i + 1].peGreen & 0xff;
            const int pal_b = (uint)palette[i + 1].peBlue & 0xff;

            const int dr = temp_r - pal_r;
            const int dg = temp_g - pal_g;
            const int db = temp_b - pal_b;
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
    // Fully verified. Source of truth: color.cpp.decomp @ 0x004247A0
}

void RGE_Color_Table::save(int fd) {
    // Fully verified. Source of truth: color.cpp.decomp @ 0x004247B0
    rge_write(fd, this->color_table_name, 0x1e);
    rge_write(fd, &this->id, 2);
    rge_write(fd, &this->resource_id, 2);
    rge_write(fd, &this->map_color, 1);
    rge_write(fd, &this->type, 1);
}

