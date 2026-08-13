// VA: 004826E0 RGE_RMM_Controller::add_terrain_module
// rmm_cntr.cpp lines 247-298
// Attempt log:
// 1: natural source from packet/decompiler with /GX: comparable but terrain record stride wrong and switch case order reversed.
// 2: fix terrain record stride to 0x20, put cases 3/4 first: switch body closer but global terrain_info gaps wrong.
// 3: fix terrain_info hot-spot/num offsets and land_info land array offsets; loop/new path now structurally close.
// 4: move terrain[1] zero/default fields after switch: improved edit diff, but VC5 tail-merged second-size computation.
// 5: swap local width/height field names and vary second-size expression: no change; expression reverted.
// tried flags /O2 no-/Oy, /Ox, /Ob0 same; /O1 too short.
// left in scratch: EH/new path, hot-spot copy loop, and data offsets are modeled; remaining broad drift is switch case tail-merge/load-order and later register scheduling, not accepted_drift-safe.
// 6: fresh baseline rebuilt the prior source with current inputs: exact size/frame/calls, but the terrain
//    multiply order, record field declaration order, switch body order, and loop constants differed.
// 7: canonical RGE terrain/land layouts and controller base offsets; natural switch and generator ownership.
// 8: canonical field assignment order fixed both first-record stores and improved the diff to 262 bytes.
// 9: raw dimension and no-op expression variants did not improve emitted code and were removed.
// 10: block-scoped area locals were a codegen duplicate; restored one natural local.
// 11: replaced the explicit shared-tail goto with natural switch breaks, matching the packet's line-268 break; emitted code was unchanged.
// left in scratch: exact size/frame/call parity and canonical field ownership; switch tail merge and
//    loop constant hoisting remain broad VC5 codegen differences.

#include <new.h>

class RGE_Map;

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate();

    void* parent;
    void* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;          // +0x14
    long map_height;         // +0x18
    float schedule;
    void* search_map;
    void* search_map_rows;
    void* stack_array;
    void* stack_offsets;
};

class RGE_Terrain_Info_Line {
public:
    long terrain_size;
    long terrain_generated;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
    long avoid_hot_spots;
};

class RGE_Terrain_Hot_Spots {
public:
    long x;
    long y;
    long radius;
    long fade;
};

class RGE_Terrain_Info {
public:
    RGE_Terrain_Info_Line terrain[99];
    long terrain_num;
    RGE_Terrain_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

class RGE_Land_Info_Line {
public:
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    unsigned char zone;
    unsigned char pad_19[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_31[3];
};

class RGE_Land_Info {
public:
    RGE_Land_Info_Line land[99];
    long land_num;
    unsigned char base_terrain;
    unsigned char pad_1421[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_1435[3];
};

class RGE_RMM_Terrain_Generator {
public:
    char gap[0x12CC];
    RGE_RMM_Terrain_Generator(void* map, void* module, RGE_Terrain_Info* info);
};

class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:
    void add_terrain_module(RGE_Terrain_Info& terrain_info,
                            RGE_Land_Info& land_info, long type);
};

void RGE_RMM_Controller::add_terrain_module(RGE_Terrain_Info& terrain_info,
                                              RGE_Land_Info& land_info,
                                              long type)
{
    int area;

    terrain_info.terrain_num = 2;

    switch (type) {
    case 3:
    case 4:
        area = this->map_height * this->map_width;
        terrain_info.terrain[0].terrain_type = 10;
        terrain_info.terrain[0].clumps = 30;
        terrain_info.terrain[0].base_terrain_type = 0;
        terrain_info.terrain[0].terrain_generated = 0;
        terrain_info.terrain[0].terrain_size = area * 20 / 100;
        terrain_info.terrain[0].spacing = 2;

        area = this->map_height * this->map_width;
        terrain_info.terrain[1].terrain_type = 6;
        terrain_info.terrain[1].clumps = 17;
        terrain_info.terrain[1].terrain_size = area * 30 / 100;
        break;

    case 0:
    case 1:
    case 2:
        area = this->map_height * this->map_width;
        terrain_info.terrain[0].terrain_type = 10;
        terrain_info.terrain[0].clumps = 20;
        terrain_info.terrain[0].base_terrain_type = 0;
        terrain_info.terrain[0].terrain_generated = 0;
        terrain_info.terrain[0].terrain_size = area * 20 / 100;
        terrain_info.terrain[0].spacing = 2;

        area = this->map_height * this->map_width;
        terrain_info.terrain[1].terrain_type = 6;
        terrain_info.terrain[1].clumps = 7;
        terrain_info.terrain[1].terrain_size = area * 30 / 100;
        break;
    }

    terrain_info.terrain[1].base_terrain_type = 0;
    terrain_info.terrain[1].terrain_generated = 0;
    terrain_info.terrain[1].spacing = 0;

    terrain_info.hot_spot_num = land_info.land_num;
    int i = 0;
    if (terrain_info.hot_spot_num > 0) {
        RGE_Land_Info_Line* land = land_info.land;
        long* hot_spot = &terrain_info.hot_spots[0].y;
        do {
            hot_spot[-1] = land->x;
            ++i;
            hot_spot[0] = land->y;
            hot_spot[1] = 12;
            hot_spot[2] = 20;
            ++land;
            hot_spot += 4;
        } while (i < terrain_info.hot_spot_num);
    }

    new RGE_RMM_Terrain_Generator(this->map, this, &terrain_info);
}
