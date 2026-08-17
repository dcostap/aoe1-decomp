// VA: 00458600 RGE_Map::load_terrain_obj_types
// map.cpp:1916-1942
//
// Binary facts: map.cpp PDB symbols prove short locals named num, density,
// flag, obj_id, and id. The header scan writes num at entry offset -4.
//
// The loop keeps only loaded terrain sets with fewer than 30 entries. It then
// stores the object id, density, and placement flag, and increments the field.
//
// Current reconstruction: the typed terrain ownership and guard order now
// produce the original 341-byte size and 100 instructions. All five calls,
// frame, and call targets align. The checker reports 121 differing bytes.
//
// The remaining mismatch is one placement-byte address lowering. The target
// adds this plus num before the terrain stride. VC5 emits the equivalent tile
// base plus num form from the natural typed member expression.
//
// Tested and rejected: direct pointer syntax, reversed subscripts, implicit
// this, declaration order, cast changes, and a typed terrain-set gap. These
// forms either duplicate the 121-byte result or lack binary support.
// Revisit probes added typed pointer-add, pointer-local, record-reference,
// signed-char, index-cast, and array-pointer forms. A 17-case variant lab
// produced one codegen group. Every case stayed at 341 bytes and 121 bytes
// differed under the authoritative checker.
//
// Canonical full RGE_Map layout, virtual slots, and typed pointer members also
// emitted the same group. A cached typed record across the loop shrank the
// function to 264 bytes and was rejected. No policy-valid exact source was
// found. The typed direct-member source remains the clean reconstruction.
// Keep the typed direct-member source authoritative until new source evidence
// explains this final expression schedule.

#include <stdio.h>
#include <stdlib.h>

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
