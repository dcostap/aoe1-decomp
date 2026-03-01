#include "../include/RGE_RMM_Controller.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Land_Info.h"
#include "../include/RGE_Object_Info.h"
#include "../include/RGE_RMM_Land_Generator.h"
#include "../include/RGE_RMM_Object_Generator.h"
#include "../include/RGE_RMM_Terrain_Generator.h"
#include "../include/RGE_Terrain_Info.h"
#include "../include/debug_helpers.h"

#include <math.h>
#include <new>
#include <string.h>

namespace {
static void rmm_cntr_switch_anchor_004826B2() {
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x004826B2
}

static void rmm_cntr_switch_anchor_0048287E() {
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x0048287E
}
} // namespace

RGE_RMM_Controller::RGE_RMM_Controller(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4)
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x004821A0
    : RGE_Random_Map_Module(param_1, nullptr, 1) {
    RGE_Land_Info land_info;
    memset(&land_info, 0, sizeof(land_info));

    RGE_Terrain_Info terrain_info;
    memset(&terrain_info, 0, sizeof(terrain_info));

    this->add_land_module(&land_info, (long)param_3, param_4);
    this->add_terrain_module(&terrain_info, &land_info, (long)param_3);
    this->add_object_module(param_2, &land_info);
}

uchar RGE_RMM_Controller::generate() {
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x00482260
    return RGE_Random_Map_Module::generate();
}

void RGE_RMM_Controller::add_land_module(RGE_Land_Info* param_1, long param_2, long param_3) {
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x00482270
    param_1->land_num = param_3;

    long land_tile_percent = 0;
    switch (param_2) {
        case 0:
            param_1->base_terrain = 1;
            param_1->wall_1_avoidance_line = 8;
            param_1->wall_2_avoidance_line = 8;
            param_1->wall_3_avoidance_line = this->map_width - 9;
            param_1->wall_4_avoidance_line = this->map_height - 9;
            param_1->wall_fade = 0x14;
            land_tile_percent = 0x1e;
            break;
        case 1:
            param_1->base_terrain = 1;
            param_1->wall_1_avoidance_line = 6;
            param_1->wall_2_avoidance_line = 6;
            param_1->wall_3_avoidance_line = this->map_width - 7;
            param_1->wall_4_avoidance_line = this->map_height - 7;
            param_1->wall_fade = 0x14;
            land_tile_percent = 0x32;
            break;
        case 2:
            param_1->base_terrain = 1;
            param_1->wall_1_avoidance_line = 4;
            param_1->wall_2_avoidance_line = 4;
            param_1->wall_3_avoidance_line = this->map_width - 5;
            param_1->wall_4_avoidance_line = this->map_height - 5;
            param_1->wall_fade = 0x22;
            land_tile_percent = 0x46;
            break;
        case 3:
            param_1->base_terrain = 1;
            param_1->wall_1_avoidance_line = 0;
            param_1->wall_2_avoidance_line = 0;
            param_1->wall_3_avoidance_line = 0;
            param_1->wall_4_avoidance_line = 0;
            param_1->wall_fade = 0;
            land_tile_percent = 0x5a;
            break;
        default:
            param_1->base_terrain = 0;
            param_1->wall_1_avoidance_line = 0;
            param_1->wall_2_avoidance_line = 0;
            param_1->wall_3_avoidance_line = 0;
            param_1->wall_4_avoidance_line = 0;
            param_1->wall_fade = 0;
            land_tile_percent = 0;
            break;
    }

    float bound = ((float)(this->map_width - 0x10) / (float)sqrt((double)param_3)) * 0.8f;
    float bound_sq = bound * bound;

    long mid_x2 = (long)((float)(this->map_width / 2) - bound);
    long index2 = (long)((float)(this->map_height / 2) - bound);
    long mid_y1 = (long)((float)(this->map_width / 2) + bound);
    long mid_y2 = (long)((float)(this->map_height / 2) + bound);

    if (mid_x2 < 9) mid_x2 = 9;
    if (index2 < 9) index2 = 9;
    if (mid_y1 >= this->map_width - 9) mid_y1 = this->map_width - 10;
    if (mid_y2 >= this->map_height - 9) mid_y2 = this->map_height - 10;

    for (long index = 0; index < param_1->land_num; ++index) {
        RGE_Land_Info_Line* line = &param_1->land[index];

        switch (param_2) {
            case 0:
                line->terrain_type = 0;
                line->area = 7;
                line->base_size = 5;
                line->zone = (uchar)index;
                break;
            case 1:
                line->terrain_type = 0;
                line->area = 4;
                line->base_size = 5;
                line->zone = (uchar)index;
                break;
            case 2:
            case 3:
            case 4:
                line->terrain_type = 0;
                line->area = 3;
                line->base_size = 5;
                line->zone = 0;
                break;
            default:
                break;
        }

        long x = 0;
        long y = 0;
        bool bad = true;
        while (bad) {
            bad = false;
            x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_cntr.cpp", 0xd1) * (this->map_width - 0x10)) / 0x7fff + 8;
            y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_cntr.cpp", 0xd2) * (this->map_height - 0x10)) / 0x7fff + 8;

            if ((mid_x2 < x && x < mid_y1) && (index2 < y && y < mid_y2)) {
                bad = true;
            } else {
                for (long j = 0; j < index; ++j) {
                    long dx = x - param_1->land[j].x;
                    if (dx < 0) dx = -dx;
                    long dy = y - param_1->land[j].y;
                    if (dy < 0) dy = -dy;
                    if ((float)(dx * dx + dy * dy) <= bound_sq) {
                        if (!bad && (j == index - 1)) {
                            param_1->land[j].x = x;
                            param_1->land[j].y = y;
                        }
                        bad = true;
                    }
                }
            }
        }

        line->x = x;
        line->y = y;
        line->land_size = ((land_tile_percent * this->map_height * this->map_width) / 100) / param_1->land_num;
    }

    (void)new (std::nothrow) RGE_RMM_Land_Generator(this->map, this, param_1);
}

void FUN_004826b2() {
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x004826B2
    // Switch jump-table padding thunk (`mov edi, edi`).
}

void RGE_RMM_Controller::add_terrain_module(RGE_Terrain_Info* param_1, RGE_Land_Info* param_2, long param_3) {
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x004826E0
    if (param_1 == nullptr || param_2 == nullptr) {
        return;
    }

    param_1->terrain_num = 2;
    switch (param_3) {
        case 0:
        case 1:
        case 2:
            param_1->terrain[0].terrain_type = 10;
            param_1->terrain[0].clumps = 0x14;
            param_1->terrain[0].base_terrain_type = 0;
            param_1->terrain[0].terrain_generated = 0;
            param_1->terrain[0].terrain_size = (this->map_height * this->map_width * 0x14) / 100;
            param_1->terrain[0].spacing = 2;

            param_1->terrain[1].terrain_type = 6;
            param_1->terrain[1].clumps = 7;
            param_1->terrain[1].terrain_size = (this->map_height * this->map_width * 0x1e) / 100;
            break;
        case 3:
        case 4:
            param_1->terrain[0].terrain_type = 10;
            param_1->terrain[0].clumps = 0x1e;
            param_1->terrain[0].base_terrain_type = 0;
            param_1->terrain[0].terrain_generated = 0;
            param_1->terrain[0].terrain_size = (this->map_height * this->map_width * 0x14) / 100;
            param_1->terrain[0].spacing = 2;

            param_1->terrain[1].terrain_type = 6;
            param_1->terrain[1].clumps = 0x11;
            param_1->terrain[1].terrain_size = (this->map_height * this->map_width * 0x1e) / 100;
            break;
        default:
            break;
    }

    param_1->terrain[1].base_terrain_type = 0;
    param_1->terrain[1].terrain_generated = 0;
    param_1->terrain[1].spacing = 0;

    param_1->hot_spot_num = param_2->land_num;
    for (long i = 0; i < param_1->hot_spot_num && i < 99; ++i) {
        param_1->hot_spots[i].x = param_2->land[i].x;
        param_1->hot_spots[i].y = param_2->land[i].y;
        param_1->hot_spots[i].radius = 0xc;
        param_1->hot_spots[i].fade = 0x14;
    }

    (void)new (std::nothrow) RGE_RMM_Terrain_Generator(this->map, this, param_1);
}

void FUN_0048287e() {
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x0048287E
    // Switch jump-table padding thunk (`mov edi, edi`).
}

long RGE_RMM_Controller::count_map_tiles(uchar param_1) {
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x004828A0
    (void)param_1;
    return this->map_width * this->map_height;
}

void RGE_RMM_Controller::add_object_module(RGE_Game_World* param_1, RGE_Land_Info* param_2) {
    // Fully verified. Source of truth: rmm_cntr.cpp.decomp @ 0x004828B0
    RGE_Object_Info object_info;

    object_info.object_num = 6;
    object_info.objects[1].object_exclusion_zone = 4;
    object_info.objects[2].object_number_varience = 6;
    object_info.objects[3].object_number_varience = 6;
    object_info.objects[3].player_id = 4;
    object_info.objects[4].object_number_varience = 6;

    object_info.objects[0].terrain = 0x6d;
    *reinterpret_cast<long*>(&object_info.objects[0].group_flag) = 0;
    *reinterpret_cast<uchar*>(&object_info.objects[0].object_number_per_group) = 0;
    *(reinterpret_cast<uchar*>(&object_info.objects[0].object_number_per_group) + 1) = 0;
    object_info.objects[0].object_number_varience = 1;
    object_info.objects[0].number_of_groups = 0;
    object_info.objects[0].group_area = 1;
    object_info.objects[0].land_id = -1;
    object_info.objects[0].land_inner_radius = 0;
    object_info.objects[0].land_outer_radius = 0;
    object_info.objects[0].object_exclusion_zone = 0;

    object_info.objects[1].terrain = 0x53;
    *reinterpret_cast<long*>(&object_info.objects[1].group_flag) = 0;
    *reinterpret_cast<uchar*>(&object_info.objects[1].object_number_per_group) = 0;
    *(reinterpret_cast<uchar*>(&object_info.objects[1].object_number_per_group) + 1) = 0;
    object_info.objects[1].object_number_varience = 1;
    object_info.objects[1].number_of_groups = 0;
    object_info.objects[1].group_area = 3;
    object_info.objects[1].land_id = -1;
    object_info.objects[1].land_inner_radius = 0;
    object_info.objects[1].land_outer_radius = 2;

    object_info.objects[2].terrain = 0x41;
    *reinterpret_cast<long*>(&object_info.objects[2].group_flag) = 0;
    *reinterpret_cast<uchar*>(&object_info.objects[2].object_number_per_group) = 1;
    *(reinterpret_cast<uchar*>(&object_info.objects[2].object_number_per_group) + 1) = 1;
    object_info.objects[2].number_of_groups = 3;
    object_info.objects[2].group_area = 10;
    object_info.objects[2].player_id = 3;
    object_info.objects[2].land_id = 0;
    object_info.objects[2].land_inner_radius = -1;
    object_info.objects[2].land_outer_radius = -1;
    object_info.objects[2].object_exclusion_zone = -1;

    object_info.objects[3].terrain = 0x66;
    *reinterpret_cast<long*>(&object_info.objects[3].group_flag) = -1;
    *reinterpret_cast<uchar*>(&object_info.objects[3].object_number_per_group) = 2;
    *(reinterpret_cast<uchar*>(&object_info.objects[3].object_number_per_group) + 1) = 0;
    object_info.objects[3].number_of_groups = 2;
    object_info.objects[3].group_area = 1;
    object_info.objects[3].player_id = 4;
    object_info.objects[3].land_id = 0;
    object_info.objects[3].land_inner_radius = 0;
    object_info.objects[3].land_outer_radius = 9;
    object_info.objects[3].object_exclusion_zone = 0xf;

    object_info.objects[4].terrain = 0x42;
    *reinterpret_cast<long*>(&object_info.objects[4].group_flag) = -1;
    *reinterpret_cast<uchar*>(&object_info.objects[4].object_number_per_group) = 2;
    *(reinterpret_cast<uchar*>(&object_info.objects[4].object_number_per_group) + 1) = 0;
    object_info.objects[4].number_of_groups = 2;
    object_info.objects[4].group_area = 1;
    object_info.objects[4].player_id = 4;
    object_info.objects[4].land_id = 0;
    object_info.objects[4].land_inner_radius = 0;
    object_info.objects[4].land_outer_radius = 9;
    object_info.objects[4].object_exclusion_zone = 0xf;

    object_info.objects[5].terrain = 0x3b;
    *reinterpret_cast<long*>(&object_info.objects[5].group_flag) = -1;
    object_info.objects[5].player_id = 3;
    *reinterpret_cast<uchar*>(&object_info.objects[5].object_number_per_group) = 1;
    *(reinterpret_cast<uchar*>(&object_info.objects[5].object_number_per_group) + 1) = 0;
    object_info.objects[5].object_number_varience = 5;
    object_info.objects[5].number_of_groups = 2;
    object_info.objects[5].group_area = 1;
    object_info.objects[5].land_id = 0;
    object_info.objects[5].land_inner_radius = 0;
    object_info.objects[5].land_outer_radius = 9;
    object_info.objects[5].object_exclusion_zone = 0xf;

    long land_num = param_2->land_num;
    for (long i = 0; i < land_num; ++i) {
        object_info.lands[i].x = param_2->land[i].x;
        object_info.lands[i].y = param_2->land[i].y;
        object_info.lands[i].id = 0;
        object_info.lands[i].player_id = i + 1;
    }

    (void)new (std::nothrow) RGE_RMM_Object_Generator(
        this->map, this, param_1, reinterpret_cast<RGE_Object_Info*>(&object_info.objects[0].terrain), 1);
}

