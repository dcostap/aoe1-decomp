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
