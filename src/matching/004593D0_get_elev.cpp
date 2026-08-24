#ifndef MAP_CONTEXT_H
struct MapTile {
    char gap_00[0x05];
    unsigned char elev_and_terrain;
    char gap_06[0x12];
};

class RGE_Map {
public:
    char gap_00[0x8D8C];
    MapTile** map_row_offset;

    unsigned char get_elev(short x, short y);
};

#endif

unsigned char RGE_Map::get_elev(short x, short y) {
    unsigned char elev;

    elev = (unsigned char)(this->map_row_offset[y][x].elev_and_terrain >> 5);
    if (elev > 8) {
        elev = 0;
    }
    return elev;
}
