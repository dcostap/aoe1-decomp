#ifndef MAP_CONTEXT_H
class RGE_Tile;

class RGE_Map {
public:
    void* vtable_ptr; // +0x0
    RGE_Tile* map; // +0x4
    long map_width; // +0x8
    long map_height; // +0xC
    long world_width; // +0x10
    long world_height; // +0x14
    char tilesizes[0x72];
    char gap_0[0x2];
    char terrain_types[0x3300];
    char border_types[0x5A00];
    RGE_Tile** map_row_offset; // +0x8D8C

    void clear_map_view_info();
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
};

#endif

void RGE_Map::clear_map_view_info() {
    unsigned char* puVar1;
    int iVar2;
    int iVar3;
    RGE_Tile* tile_row;

    iVar3 = 0;
    if (0 < this->map_height) {
        do {
            iVar2 = 0;
            tile_row = this->map_row_offset[iVar3];
            if (0 < this->map_width) {
                puVar1 = &tile_row->last_drawn_shape;
                do {
                    puVar1[-1] = 0;
                    *puVar1 = 0xff;
                    puVar1[1] = 0;
                    puVar1[2] = 0;
                    puVar1[3] = 0xff;
                    puVar1 = puVar1 + 0x18;
                    iVar2 = iVar2 + 1;
                } while (iVar2 < this->map_width);
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 < this->map_height);
    }
}
