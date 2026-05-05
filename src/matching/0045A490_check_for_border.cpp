// 0045A490 RGE_Map::check_for_border (map.cpp:3018-3030, 102B)

class RGE_Tile_Set {
public:
    short borders[32];              // 64 bytes
    unsigned char gap[0x198 - 64];  // pad to 408 = 0x198 total
};

class RGE_Border_Set {
public:
    unsigned char loaded;
    unsigned char gap[0x59F];
};

class RGE_Map {
public:
    void* vtable_ptr;
    void* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    char tilesizes[0x72];
    unsigned char pad_0[2];
    char gap_before_terrain[0xBE];
    RGE_Tile_Set terrain_types[31];
    unsigned char gap_after_terrain[0xDA];
    RGE_Border_Set border_types[16];

    void check_for_border(unsigned char param_1, unsigned char* param_2);
};

void RGE_Map::check_for_border(unsigned char param_1, unsigned char* param_2)
{
    if (*param_2 == param_1) {
        return;
    }
    short border = this->terrain_types[param_1].borders[*param_2];
    if (border == -1 || border < 0 || border >= 0x10 || this->border_types[border].loaded == 0) {
        *param_2 = param_1;
    }
}
