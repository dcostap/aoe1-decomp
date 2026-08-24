#ifndef MAP_CONTEXT_H
struct TileSizeEntry {
    short width;
    short height;
    short y_delta;
};

class RGE_Map {
public:
    char gap_00[0x18];
    TileSizeEntry tilesizes[256];

    void set_tile_size(unsigned char index, short width, short height, short y_delta);
};

#endif

void RGE_Map::set_tile_size(unsigned char index, short width, short height, short y_delta) {
    this->tilesizes[index].width = width;
    this->tilesizes[index].height = height;
    this->tilesizes[index].y_delta = y_delta;
}
