// 00484A40 RGE_RMM_Elevation_Generator::generate_modifiers
// PDB: rmm_elev.cpp lines 159-193
// Baseline reconstruction: clear the shared search map, then accumulate the
// positive falloff contribution of each elevation hot spot for every tile.
// Attempt log:
// - Natural nested loops matched size/frame/calls but VC5 loaded map_width
//   first for the commutative clear-size expression.
// - A height-first accumulator restored the original clear-size load order.
// - The binary-proven hot-spot cursor is anchored at the y field; declaring
//   that cursor before the scoped count places the count-home store after the
//   LEA, producing the exact VC5 block.

#include <math.h>
#include <string.h>

#include "..\..\include\rmm_elev_context.h"

void RGE_RMM_Elevation_Generator::generate_modifiers()
{
    long modifier;

    long map_size = this->map_height;
    map_size *= this->map_width;
    memset(this->search_map, 0, map_size);

    long y = 0;
    if (y < this->map_height) {
        do {
            long x = 0;
            if (x < this->map_width) {
                do {
                    modifier = 0;
                    if (this->info.hot_spot_num > 0) {
                        long* hot_spot = &this->info.hot_spots[0].y;
                        long hot_spot_num = this->info.hot_spot_num;
                        do {
                            long dx = x - hot_spot[-1];
                            long dy = y - hot_spot[0];

                            if (dx < 0)
                                dx = -dx;
                            if (dy < 0)
                                dy = -dy;

                            long distance = (long)sqrt((double)(dx * dx + dy * dy));
                            long contribution = hot_spot[1] - distance;
                            if (contribution > 0)
                                modifier += hot_spot[2] * contribution;

                            hot_spot += 4;
                            --hot_spot_num;
                        } while (hot_spot_num != 0);
                    }

                    if (modifier > 100)
                        this->search_map_rows[y][x] = 101;
                    else
                        this->search_map_rows[y][x] = (unsigned char)modifier;
                    ++x;
                } while (x < this->map_width);
            }
            ++y;
        } while (y < this->map_height);
    }
}
