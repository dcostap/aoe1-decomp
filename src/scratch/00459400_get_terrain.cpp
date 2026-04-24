// attempt 1: 2D int array indexing with >> 24 & 0x1F; wrong map_row_offset type (int** vs int*)
// attempt 2: (unsigned char*) cast on row ptr; extra push edi at +20, terrain_types access differs
// attempt 3: same as 2; VC5 always pushes edi for cast expr, loads [ecx+8C] into ecx

struct TerrainType {
    unsigned char loaded;
    char gap_01[0x137];
    short terrain_to_draw;
};

class RGE_Map {
public:
    char gap_00[0x8C];
    TerrainType* terrain_types;
    char gap_90[0x8D00 - 4];
    int* map_row_offset;

    unsigned char get_terrain(short x, short y);
};

unsigned char RGE_Map::get_terrain(short x, short y) {
    unsigned char id = ((unsigned char*)map_row_offset[y])[x * 24 + 5] & 0x1F;
    if (id > 0x20) {
        return 0;
    }
    if (terrain_types[id].loaded != 0) {
        return id;
    }
    if (terrain_types[id].terrain_to_draw >= 0) {
        return id;
    }
    return 0;
}
