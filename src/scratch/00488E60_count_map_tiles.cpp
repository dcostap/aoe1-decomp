// RGE_RMM_Terrain_Generator::count_map_tiles
// VA: 00488E60
// rmm_terr.cpp:231-241
// 54 bytes, 19 diff bytes (35.19%)
// Body (35 bytes) is exact match. Prolog register scheduling differs:
// Original: eax=width*total, ecx=total*3 (overwrites this), esi=end
// Rebuilt: esi=height*total→end, ecx=total*3, eax=tileInfo (discarded)
// TU-context register allocation issue. 7+ source forms tried.
// Cleanest version kept below.

#include "../../include/game_globals.h"

class RGE_RMM_Terrain_Generator {
public:
    char gap_00[0x10];
    void* tileInfo;    // +0x10 — pointer to struct with tile array at offset 0
    int width;         // +0x14
    int height;        // +0x18

    long count_map_tiles(unsigned char tileType);
};

long RGE_RMM_Terrain_Generator::count_map_tiles(unsigned char tileType) {
    long count = 0;
    unsigned char* tile = *(unsigned char**)this->tileInfo;
    unsigned char* end = tile + this->width * this->height * 0x18;

    while (tile < end) {
        if ((tile[5] & 0x1F) == tileType) {
            count++;
        }
        tile += 0x18;
    }
    return count;
}
