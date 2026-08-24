// VA: 00458600 RGE_Map::load_terrain_obj_types
// map.cpp:1916-1942
//
// BINARY NOTE: PDB symbols identify short locals named num, density, flag,
// obj_id, and id. The header scan writes num at entry offset -4.
//
// The loader keeps the original parser and publication order. It preserves
// narrow fscanf destinations, the loaded and count guards, and unconditional
// fclose cleanup. Partial conversions keep the executable's fault order.
//
// Exact-finish result: adding the period map.cpp <windows.h> context restored
// the target's VC5 scheduling basin. A fresh checker reports MATCH and 0.0000%.
// It also proves the 341-byte boundary, owner symbol, no EH frame, and five
// ordered direct calls: fopen, fscanf, fscanf, fscanf, and fclose.
//
// Walkback: removing only <windows.h> restored the 340-byte, 121-byte-diff
// placement basin. Restoring that one header restored the exact result.
// The header is supported by exact map.cpp donor 004568C0, which also requires
// this period SDK context. No alias, raw overlay, fake volatility, or assembly
// is required.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MAP_CONTEXT_H
struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    void* shape;
    void* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char map_lt_cliff_color;
    unsigned char map_rt_cliff_color;
    unsigned char passable_terrain;
    unsigned char impassable_terrain;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
    char gap_196[2];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char* a, char* b, char* c, char* d);
    virtual unsigned char do_terrain_brush(long x, long y, long radius,
                                           unsigned char terrain);
    virtual unsigned char do_terrain_brush_stroke(long x0, long y0, long x1,
                                                  long y1, long radius,
                                                  unsigned char terrain);
    virtual unsigned char do_elevation_brush(long x, long y, long radius,
                                              unsigned char elevation);
    virtual unsigned char do_elevation_brush_stroke(long x0, long y0, long x1,
                                                    long y1, long radius,
                                                    unsigned char elevation);
    virtual unsigned char do_cliff_brush(long x, long y, unsigned char a,
                                         unsigned char b);
    virtual unsigned char do_cliff_brush_stroke(long x0, long y0, long x1,
                                                long y1, unsigned char a,
                                                unsigned char b);
    char gap_04[0x88];
    RGE_Tile_Set terrain_types[32];
    char gap_338C[0x5A00];
    void* map_row_offset;

    void load_terrain_obj_types(char* filename);
};

#endif

void RGE_Map::load_terrain_obj_types(char* filename)
{
    FILE* file = fopen(filename, "r");

    if (file != 0) {
        short num;
        short density;
        short flag;
        short obj_id;
        short id;

        fscanf(file, "%hd", &num);
        while (fscanf(file, "%hd %hd %hd %hd",
                      &id, &obj_id, &density, &flag) != EOF) {
            if (this->terrain_types[id].loaded != 0) {
                if (this->terrain_types[id].num_obj_type < 30) {
                    num = this->terrain_types[id].num_obj_type;
                    this->terrain_types[id].obj_types[num] = obj_id;
                    this->terrain_types[id].obj_density[num] = density;
                    this->terrain_types[id].obj_placement_flag[num] = flag;
                    ++this->terrain_types[id].num_obj_type;
                }
            }
        }
    }

    fclose(file);
}
