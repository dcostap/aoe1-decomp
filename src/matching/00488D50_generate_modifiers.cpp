// 00488D50 RGE_RMM_Terrain_Generator::generate_modifiers
// PDB: rmm_terr.cpp lines 179-213
// Attempt log:
// - baseline: canonical terrain search-map ownership and natural nested
//   hot-spot falloff loops, matching the sibling elevation generator's source
//   family.
// - anchoring the hot-spot cursor at the proven y field reduced the baseline
//   27-byte drift to 21 bytes while preserving the typed 16-byte record owner.
// - the exact source shape uses a direct hot-spot guard, declares the y-anchored
//   cursor before the scoped count, and keeps modifier function-scoped; this
//   reproduces the original initialization block and output register coloring.
// - The grouped rmm_terr.cpp context needs a named map size. Load map_width,
//   then compound-multiply map_height. This keeps the anchor exact.

#include <math.h>
#include <string.h>

#include "../../include/rmm_terr_context.h"

void RGE_RMM_Terrain_Generator::generate_modifiers()
{
    long modifier;

    long map_size = this->map_width;
    map_size *= this->map_height;
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
