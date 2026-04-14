class RGE_Map {
public:
    char gap_0[0x14];
    int width;
    int height;
    int count_map_tiles(int unused);
};

int RGE_Map::count_map_tiles(int unused) {
    return this->width * this->height;
}
