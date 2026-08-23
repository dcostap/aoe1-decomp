// VA: 004889F0 RGE_RMM_Terrain_Generator::check_borders
// Source: rmm_terr.cpp lines 76-116
// Attempt log:
// 1: initial structured reconstruction from packet/decompiler; row typed int* caused x offset scale-by-4.
// 2: model rows as byte rows.

#include "../../include/rmm_terr_context.h"

void RGE_RMM_Terrain_Generator::check_borders()
{
    int y = 0;
    int max_y = this->height - 1;
    int max_x = this->width - 1;

    if (this->height > 0) {
        do {
            int xoff = 0;
            int x = 0;
            if (this->width > 0) {
                do {
                    uchar t = (uchar)(this->rows[y][xoff + 5] & 0x1f);
                    if (!this->water(t)) {
                        uchar border = 0;
                        if (y > 0 && this->water((uchar)(this->rows[y - 1][xoff + 5] & 0x1f))) {
                            border = 1;
                        } else if (y < max_y && this->water((uchar)(this->rows[y + 1][xoff + 5] & 0x1f))) {
                            border = 1;
                        }

                        if (xoff > 0) {
                            if (this->water((uchar)(this->rows[y][xoff - 0x13] & 0x1f)) ||
                                (y > 0 && this->water((uchar)(this->rows[y - 1][xoff - 0x13] & 0x1f))) ||
                                (y < max_y && this->water((uchar)(this->rows[y + 1][xoff - 0x13] & 0x1f)))) {
                                border = 1;
                            }
                        }

                        if (x < max_x) {
                            if (this->water((uchar)(this->rows[y][xoff + 0x1d] & 0x1f)) ||
                                (y > 0 && this->water((uchar)(this->rows[y - 1][xoff + 0x1d] & 0x1f))) ||
                                (y < max_y && this->water((uchar)(this->rows[y + 1][xoff + 0x1d] & 0x1f)))) {
                                border = 1;
                            }
                        }

                        if (border == 1) {
                            uchar* cell = (uchar*)&this->rows[y][xoff + 5];
                            *cell = (uchar)((*cell & 0xe2) | 2);
                        }
                    }
                    ++x;
                    xoff += 0x18;
                } while (x < this->width);
            }
            ++y;
        } while (y < this->height);
    }
}
