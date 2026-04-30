// 004374C0 RGE_Diamond_Map::clear_image (diam_map.cpp:519-569)
// Minimal implementation matching original structure

#include <string.h>

struct TDA {
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    unsigned char* pixels;
    int gap_0C[4];
    int pitch;
    int width;
    int bpp;
    int height;
};

struct ImLine {
    short tile_row;
    short start_x;
    short line_len;
};

struct DMap {
    char pad0[0x0C];
    long pnl_x;
    long pnl_y;
    char pad1[0x14 - 0x14];
    long clip_l;
    long clip_t;
    long clip_r;
    long clip_b;
    char pad2[0xBB];
    unsigned char bg;
    char pad3[0x34];
    ImLine* lines;
    char pad4[8];
    short map_w;
    short map_h;
    short start_y;
    short map_iw;
    short map_ih;
    char pad5[0x2C];
    TDA* sa;
};

void DMap::clear_image()
{
    TDA* area = this->sa;
    unsigned char* lock_ret = area->Lock("diam_map::clear_image", 1);
    if (!lock_ret) return;

    short sy = this->start_y;
    int pitch;
    short line_w;

    if (area->bpp == 1) {
        pitch = sy * area->width + (int)area->pixels;
        line_w = (short)area->width;
    } else {
        pitch = (area->height - sy - 1) * area->width + (int)area->pixels;
        line_w = (short)(-(short)area->width);
    }

    short cy = (short)(this->pnl_y + sy);
    short ey = cy + this->map_ih;
    ImLine* p = this->lines;
    short rc = ey - cy;

    do {
        int y = cy;
        if (y >= this->clip_t && y <= this->clip_b) {
            short sx = p->start_x;
            short ex = sx + (short)this->pnl_x + p->line_len - 1;

            if ((int)sx < this->clip_l)
                sx = (short)this->clip_l;
            if ((int)ex > this->clip_r)
                ex = (short)this->clip_r;

            if ((int)sx >= this->clip_l && (int)ex <= this->clip_r) {
                int w = (int)ex - (int)sx + 1;
                memset((void*)(pitch + (int)sx), this->bg, w);
            }
        }
        p++;
        pitch += line_w;
        cy++;
        rc--;
    } while (rc);

    area->Unlock("diam_map::clear_image");
}
