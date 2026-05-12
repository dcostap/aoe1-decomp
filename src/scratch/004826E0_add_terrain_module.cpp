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

struct RGE_Terrain_Record {
    int terrain_size;        // +0x00
    int base_terrain_type;   // +0x04
    int terrain_type;        // +0x08
    int clumps;              // +0x0C
    int spacing;             // +0x10
    int terrain_generated;   // +0x14
    char pad_18[8];          // stride 0x20
};

struct RGE_Terrain_HotSpot {
    int x;
    int y;
    int radius1;
    int radius2;
};

struct RGE_Terrain_Info {
    RGE_Terrain_Record terrain[2]; // +0x00,+0x20
    char gap_40[0xC60 - 0x40];
    int terrain_num;              // +0xC60
    RGE_Terrain_HotSpot hot_spots[1]; // +0xC64
    char gap_after_hotspots[0x1294 - 0xC74];
    int hot_spot_num;             // +0x1294
};

struct RGE_Land_Info {
    char gap_00[0x08];
    int first_x;                  // +0x08
    int first_y;                  // +0x0C
    char gap_10[0x141C - 0x10];
    int land_num;                 // +0x141C
};

class RGE_RMM_Terrain_Generator {
public:
    char gap[0x12CC];
    RGE_RMM_Terrain_Generator(void* map, void* module, RGE_Terrain_Info* info);
};

class RGE_RMM_Controller {
public:
    char gap_00[0x0C];
    void* map;          // +0x0C
    char gap_10[4];
    int height;         // +0x14
    int width;          // +0x18

    void add_terrain_module(RGE_Terrain_Info& terrain_info, RGE_Land_Info& land_info, long type);
};

void RGE_RMM_Controller::add_terrain_module(RGE_Terrain_Info& terrain_info, RGE_Land_Info& land_info, long type)
{
    int area;
    int i;

    terrain_info.terrain_num = 2;

    switch (type) {
    case 3:
    case 4:
        area = this->width;
        area *= this->height;
        terrain_info.terrain[0].terrain_type = 10;
        terrain_info.terrain[0].clumps = 30;
        terrain_info.terrain[0].terrain_generated = 0;
        terrain_info.terrain[0].base_terrain_type = 0;
        terrain_info.terrain[0].terrain_size = area * 20 / 100;
        terrain_info.terrain[0].spacing = 2;

        area = this->width;
        area *= this->height;
        terrain_info.terrain[1].terrain_type = 6;
        terrain_info.terrain[1].clumps = 17;
        terrain_info.terrain[1].terrain_size = area * 30 / 100;
        goto terrain_switch_done;

    case 0:
    case 1:
    case 2:
        area = this->width;
        area *= this->height;
        terrain_info.terrain[0].terrain_type = 10;
        terrain_info.terrain[0].clumps = 20;
        terrain_info.terrain[0].terrain_generated = 0;
        terrain_info.terrain[0].base_terrain_type = 0;
        terrain_info.terrain[0].terrain_size = area * 20 / 100;
        terrain_info.terrain[0].spacing = 2;

        area = this->width;
        area *= this->height;
        terrain_info.terrain[1].terrain_type = 6;
        terrain_info.terrain[1].clumps = 7;
        terrain_info.terrain[1].terrain_size = area * 30 / 100;
        goto terrain_switch_done;
    }
    goto terrain_switch_default;

terrain_switch_done:
    terrain_info.terrain[1].terrain_generated = 0;
    terrain_info.terrain[1].base_terrain_type = 0;
    terrain_info.terrain[1].spacing = 0;

terrain_switch_default:
    terrain_info.hot_spot_num = land_info.land_num;
    for (i = 0; i < terrain_info.hot_spot_num; i++) {
        int* land = (int*)((char*)&land_info + 0x0C + i * 0x34);
        terrain_info.hot_spots[i].x = land[-1];
        terrain_info.hot_spots[i].y = land[0];
        terrain_info.hot_spots[i].radius1 = 12;
        terrain_info.hot_spots[i].radius2 = 20;
    }

    new RGE_RMM_Terrain_Generator(this->map, this, &terrain_info);
}
