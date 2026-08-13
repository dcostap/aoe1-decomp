// 00482270 RGE_RMM_Controller::add_land_module
// Baseline: period-plausible typed reconstruction from rmm_cntr.cpp's
// RGE_Land_Info / RGE_Land_Info_Line ownership and the original CFG.
// The old scratch attempt had the parameter order, return type, and land-line
// layout wrong; it was a pointer-returning scaffold rather than this void
// helper that fills an RGE_Land_Info reference.
// Attempt log:
// - Corrected the ABI to void add_land_module(RGE_Land_Info&, long, long),
//   restored the 0x34 RGE_Land_Info_Line layout, and modeled the natural
//   switch/random-placement/new expression. Baseline: 1090 bytes, 8 calls,
//   exact CFG/size, but 0x34 frame versus the oracle's 0x30.
// - An area-field cursor matched two additional addressing bytes (941-byte
//   diagnostic diff) but spilled the cursor and remained a raw decompiler
//   anchor; restored the cleaner typed line pointer for the living source.
// - Volatile dimension rereads, controller/info pointer aliases, header
//   context, and cursor-carry variants were nonproductive or diagnostic;
//   cursor-carry worsened the strict diff. No inline asm or status promotion.
// - Fresh natural ownership probe: used the period RGE_Random_Map_Module
//   parent/list and buffer types, plus the polymorphic land-generator surface
//   from exact same-module donors. The direct new/constructor path and typed
//   outer loop remained unchanged; emitted code was identical (943-byte diff,
//   0x34 frame). This is negative evidence against constructor/list context
//   as the first structural blocker.
// GIVEUP: remaining broad VC5 register/lifetime and 4-byte local-frame drift;
// calls, CFG, field ownership, math constants, random scaling, and generator
// constructor relocation are aligned.

#include <math.h>
#include <new.h>

typedef unsigned char uchar;

class RGE_Map;
class RGE_Tile;
class Map_Stack;
class RGE_Random_Map_Module_List;

class RGE_Random_Map_Module {
public:
    virtual uchar generate();

    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    uchar* search_map;
    uchar** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;
};

class RGE_Land_Info_Line {
public:
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    uchar zone;
    uchar pad_19[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar pad_end[3];
};

class RGE_Land_Info {
public:
    RGE_Land_Info_Line land[99];
    long land_num;
    uchar base_terrain;
    uchar pad_1421[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar pad_end[3];
};

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    RGE_Land_Info info;
    virtual uchar generate();

    RGE_RMM_Land_Generator(RGE_Map* map, RGE_Random_Map_Module* parent,
                           RGE_Land_Info* info);
};

class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:
    void add_land_module(RGE_Land_Info& land_info, long type, long land_num);
};

extern "C" int __cdecl debug_rand(char* file, int line);
extern char rmm_cntr_cpp_path[];

void RGE_RMM_Controller::add_land_module(RGE_Land_Info& land_info,
                                          long type, long land_num)
{
    long radius;

    land_info.land_num = land_num;

    switch (type) {
    default:
        radius = 0;
        land_info.base_terrain = 0;
        land_info.wall_1_avoidance_line = 0;
        land_info.wall_2_avoidance_line = 0;
        land_info.wall_3_avoidance_line = 0;
        land_info.wall_4_avoidance_line = 0;
        land_info.wall_fade = 0;
        break;
    case 3:
        radius = 90;
        land_info.base_terrain = 1;
        land_info.wall_1_avoidance_line = 0;
        land_info.wall_2_avoidance_line = 0;
        land_info.wall_3_avoidance_line = 0;
        land_info.wall_4_avoidance_line = 0;
        land_info.wall_fade = 0;
        break;
    case 2:
        radius = 70;
        land_info.base_terrain = 1;
        land_info.wall_1_avoidance_line = 4;
        land_info.wall_2_avoidance_line = 4;
        land_info.wall_3_avoidance_line = this->map_width - 5;
        land_info.wall_4_avoidance_line = this->map_height - 5;
        land_info.wall_fade = 0x22;
        break;
    case 1:
        radius = 50;
        land_info.base_terrain = 1;
        land_info.wall_1_avoidance_line = 6;
        land_info.wall_2_avoidance_line = 6;
        land_info.wall_3_avoidance_line = this->map_width - 7;
        land_info.wall_4_avoidance_line = this->map_height - 7;
        land_info.wall_fade = 0x14;
        break;
    case 0:
        radius = 30;
        land_info.base_terrain = 1;
        land_info.wall_1_avoidance_line = 8;
        land_info.wall_2_avoidance_line = 8;
        land_info.wall_3_avoidance_line = this->map_width - 9;
        land_info.wall_4_avoidance_line = this->map_height - 9;
        land_info.wall_fade = 0x14;
        break;
    }

    long land_tile_num = radius * this->map_width * this->map_height / 100;
    float land_radius = ((float)(this->map_width - 16) /
                         sqrt((float)land_num)) * 0.8;
    float bound_square = land_radius * land_radius;
    long mid_x2 = (long)(this->map_width / 2 - land_radius * 0.9);
    long index2 = (long)(this->map_height / 2 - land_radius * 0.9);
    long mid_y1 = (long)(this->map_width / 2 + land_radius * 0.9);
    long mid_y2 = (long)(this->map_height / 2 + land_radius * 0.9);

    if (mid_x2 < 9) {
        mid_x2 = 9;
    }
    if (index2 < 9) {
        index2 = 9;
    }
    if (mid_y1 >= this->map_width - 9) {
        mid_y1 = this->map_width - 10;
    }
    if (mid_y2 >= this->map_height - 9) {
        mid_y2 = this->map_height - 10;
    }

    long index = 0;
    if (0 < land_num) {
        RGE_Land_Info_Line* land = land_info.land;
        do {
            switch (type) {
            case 0:
                land->land_size = 0;
                land->terrain_type = 7;
                goto set_land_defaults;
            case 1:
                land->land_size = 0;
                land->terrain_type = 4;
            set_land_defaults:
                land->base_size = 5;
                land->zone = (uchar)index;
                break;
            case 2:
            case 3:
            case 4:
                land->land_size = 0;
                land->terrain_type = 3;
                land->base_size = 5;
                land->zone = 0;
                break;
            default:
                break;
            }

            uchar found = 0;
            long x;
            long y;
            do {
                found = 0;
                x = debug_rand(rmm_cntr_cpp_path, 0xD1) *
                    (this->map_width - 16) / 0x7fff + 8;
                y = debug_rand(rmm_cntr_cpp_path, 0xD2) *
                    (this->map_height - 16) / 0x7fff + 8;

                if ((mid_x2 < x) && (x < mid_y1) &&
                    (index2 < y) && (y < mid_y2)) {
                    found = 1;
                }
                else {
                    long inner = 0;
                    if (0 < index) {
                        RGE_Land_Info_Line* previous = land_info.land;
                        do {
                            long dx = x - previous->x;
                            if (dx < 0) {
                                dx = -dx;
                            }
                            long dy = y - previous->y;
                            if (dy < 0) {
                                dy = -dy;
                            }
                            if ((float)(dx * dx + dy * dy) <= bound_square) {
                                if ((!found) && (inner == index - 1)) {
                                    previous->y = y;
                                    previous->x = x;
                                }
                                found = 1;
                            }
                            ++inner;
                            ++previous;
                        } while (inner < index);
                    }
                }
            } while (found);

            land->x = x;
            land->y = y;
            land->land_size = land_tile_num / land_num;
            ++index;
            ++land;
        } while (index < land_num);
    }

    new RGE_RMM_Land_Generator(this->map, this, &land_info);
}
