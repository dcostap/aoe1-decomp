#ifndef MAP_CONTEXT_H
struct Tile {
    char gap[5];
    unsigned char terrain_type : 5;
    unsigned char height : 3;
    char rest[18];
};
class RGE_Map {
public:
    char gap_00[0x8C];
    char terrain_types[0x20 * 0x198];
    char gap_after[0x8D8C - (0x8C + 0x20 * 0x198)];
    Tile** map_row_offset;
    unsigned char get_terrain(short x, short y);
};
#endif
unsigned char RGE_Map::get_terrain(short x, short y) {
    unsigned char id = this->map_row_offset[y][x].terrain_type;
    if (id <= 0x20) {
        unsigned int idx = id;
        char* t = (char*)this + idx * 0x198;
        if (*(unsigned char*)(t + 0x8C) != 0 || *(short*)(t + 0x144) >= 0) {
            return id;
        }
    }
    return 0;
}
