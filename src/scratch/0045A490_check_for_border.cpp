// attempt 4: switch to the real RGE_Map surface so the terrain/border accesses compile against the known layout
// blocker watch: the earlier raw-offset forms were functionally right but the prolog/register basin stayed wrong; this latest layout probe pushed the .text size over the local limit, so the function is paused in scratch
#include "..\..\include\game_types.h"

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char gap_01[0xBD];
    short borders[32];
};

class RGE_Border_Set {
public:
    unsigned char loaded;
    unsigned char gap_01[0x59F];
};

class RGE_Map {
public:
    void* vtable_ptr;
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    char tilesizes[0x72];
    unsigned char _pad_0[2];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];

    void check_for_border(unsigned char param_1, unsigned char* param_2);
};

void RGE_Map::check_for_border(unsigned char param_1, unsigned char* param_2) {
    short border;

    if (*param_2 != param_1) {
        border = this->terrain_types[param_1].borders[*param_2];
        if (border != -1 && border >= 0 && border < 0x10 && this->border_types[border].loaded == 0) {
            *param_2 = param_1;
        }
    }
}
