class RGE_Map {
public:
    char gap_00[0x08];
    int map_width;
    int map_height;

    unsigned char check_map_coords(short x, short y);
};

unsigned char RGE_Map::check_map_coords(short x, short y) {
    if (((x >= 0) && ((int)x < this->map_width)) && ((y >= 0) && ((int)y < this->map_height))) {
        return 1;
    }
    return 0;
}
