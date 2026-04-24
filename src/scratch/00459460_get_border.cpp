// first pass: read the tile border type from the row-offset grid, mask it to 4 bits, and return 0 when the border table says that type is not loaded
// tried direct row/table access, then explicit tile_x/tile_y locals; the remaining mismatch stayed at the opening load order (asm wants y->x with push ebx/push esi)

class RGE_Map {
public:
    char gap_00[0x338C];
    unsigned char border_types[0x5A00];
    unsigned char** map_row_offset;

    unsigned char get_border(short x, short y);
};

unsigned char RGE_Map::get_border(short x, short y) {
    short tile_y = y;
    short tile_x = x;
    unsigned char border = this->map_row_offset[(unsigned short)tile_y][tile_x * 24 + 6] & 0x0F;
    if (border > 0x10 || this->border_types[(unsigned char)border] == 0) {
        return 0;
    }
    return border;
}
