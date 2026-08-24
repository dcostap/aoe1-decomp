// RGE_Map::scenario_save (00455F10, map.cpp:526-546)
// Attempt log:
// 1 baseline: canonical RGE_Map dimensions and nested short row/column loops;
//   cached tile local produced a 208-byte body with the right calls/frame.
// 2 layout: repeated direct map_row_offset[y][x] accesses restored the separate
//   row-pointer and 24-byte offset computations; exact 218-byte match.

extern "C" void __cdecl rge_write(int file, void* data, int size);

#ifndef MAP_CONTEXT_H
struct RGE_Tile {
    char gap_00[5];
    unsigned char terrain_info;
    char gap_06[18];
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;

    void scenario_save(int file);
};

#endif

void RGE_Map::scenario_save(int file)
{
    RGE_Map* map = this;
    rge_write(file, &map->map_width, 4);

    int* height = &map->map_height;
    rge_write(file, height, 4);

    int height_count = *height;
    short y = 0;
    unsigned char overlay_info;
    unsigned char height_info;
    unsigned char local_bytes[2];

    if (height_count > 0) {
        do {
            short x = 0;
            if (height_count > 0) {
                do {
                    overlay_info = map->map_row_offset[y][x].terrain_info & 0x1f;
                    height_info = map->map_row_offset[y][x].terrain_info >> 5;
                    local_bytes[0] = height_info;
                    local_bytes[1] = 0;
                    rge_write(file, &overlay_info, 1);
                    rge_write(file, local_bytes, 1);
                    rge_write(file, local_bytes + 1, 1);
                    ++x;
                } while (x < *height);
            }
            height_count = *height;
            ++y;
        } while (y < height_count);
    }
}
