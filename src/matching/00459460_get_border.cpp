// first pass: read the tile border type from the row-offset grid, mask it to 4 bits, and return 0 when the border table says that type is not loaded
// tried direct row/table access, then explicit tile_x/tile_y locals; the remaining mismatch stayed at the opening load order (asm wants y->x with push ebx/push esi)
// tried the typed tile + border-entry surface so VC5 can synthesize the x*24 row access and the 0x5A0-sized border table scale directly

#ifndef MAP_CONTEXT_H
struct RGE_Map_Tile {
    char gap_00[6];
    unsigned char border;
    char gap_07[17];
};

struct RGE_Map_Border_Type {
    unsigned char loaded;
    char gap_01[0x59F];
};

class RGE_Map {
public:
    char gap_00[0x338C];
    RGE_Map_Border_Type border_types[16];
    RGE_Map_Tile** map_row_offset;

    unsigned char get_border(short x, short y);
};

#endif

unsigned char RGE_Map::get_border(short x, short y) {
    unsigned char border = this->map_row_offset[y][x].border & 0x0F;
    if (border > 0x10 || this->border_types[border].loaded == 0) {
        border = 0;
    }
    return border;
}
