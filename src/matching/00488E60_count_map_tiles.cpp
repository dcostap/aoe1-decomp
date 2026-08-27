#include "../../include/rmm_terr_context.h"

// BINARY NOTE: rmm_terr.cpp lines 231-241 scan +0x10 rows with +0x18 tiles.
// BLOCKER: the complete context reverses the +0x14/+0x18 product loads.
// Natural source variants did not change those two bytes.
long RGE_RMM_Terrain_Generator::count_map_tiles(unsigned char tileType) {
    unsigned char* tile = *(unsigned char**)this->tileInfo;
    unsigned char* end = tile + this->width * this->height * 0x18;
    long count = 0;

    while (tile < end) {
        if (((unsigned char)tile[5] & 0x1F) == tileType) {
            count++;
        }
        tile += 0x18;
    }
    return count;
}
