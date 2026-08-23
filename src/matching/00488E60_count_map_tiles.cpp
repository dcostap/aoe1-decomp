#include "../../include/rmm_terr_context.h"

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
