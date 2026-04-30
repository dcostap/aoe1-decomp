// VA: 00484B50 count_map_tiles (54B)
// rmm_elev.cpp

class RGE_RMM_Elevation_Generator {
public:
    char gap_00[0x10];
    char** tiles;    // +0x10
    int width;       // +0x14
    int height;      // +0x18

    long count_map_tiles(unsigned char tile_type);
};

long RGE_RMM_Elevation_Generator::count_map_tiles(unsigned char tile_type) {
    char* ptr = *this->tiles;
    char* end = ptr + (this->width * this->height) * 24;
    long count = 0;

    while (ptr < end) {
        if ((ptr[5] & 0x1F) == tile_type) {
            count++;
        }
        ptr += 24;
    }
    return count;
}
