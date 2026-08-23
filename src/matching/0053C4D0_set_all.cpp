// VA: 0053C4D0 RGE_Visible_Map::set_all (254B)
// PDB source: visible.cpp lines 389-436
// Exact under the shared visible.cpp default-flag context.

#include "../../include/visible_context.h"

void RGE_Visible_Map::set_all(unsigned char value) {
    log_map_call(this->world->world_time, (int)this->player->id, 5, 0,
                 (unsigned int)value, 0, 0, 0, 0);

    int y = 0;
    if (0 < this->heightValue) {
        do {
            int x = 0;
            if (0 < this->widthValue) {
                do {
                    this->map_offsets[y][x] = value;
                    x = x + 1;
                } while (x < this->widthValue);
            }
            y = y + 1;
        } while (y < this->heightValue);
    }

    if ((value == 0xff) || (value == 0)) {
        unsigned long mask = this->PlayerVisibleMaskInvertValue;
        if (value == 0xff) {
            mask = mask & this->PlayerExploredMaskInvertValue;
        }

        y = 0;
        if (0 < this->heightValue) {
            unsigned long** offsets = unified_map_offsets;
            do {
                int x = 0;
                if (0 < this->widthValue) {
                    do {
                        (*offsets)[x] = (*offsets)[x] & mask;
                        x = x + 1;
                    } while (x < this->widthValue);
                }
                y = y + 1;
                offsets = offsets + 1;
            } while (y < this->heightValue);
        }
    } else {
        unsigned long mask = this->PlayerExploredMaskValue;
        mask = mask | this->PlayerVisibleMaskValue;
        y = 0;
        if (0 < this->heightValue) {
            unsigned long** offsets = unified_map_offsets;
            do {
                int x = 0;
                if (0 < this->widthValue) {
                    do {
                        (*offsets)[x] = (*offsets)[x] | mask;
                        x = x + 1;
                    } while (x < this->widthValue);
                }
                y = y + 1;
                offsets = offsets + 1;
            } while (y < this->heightValue);
        }
    }

    if (value == 0xff) {
        this->numberTilesExploredValue = 0;
    } else {
        this->numberTilesExploredValue = this->numberTotalTilesValue;
    }
}
