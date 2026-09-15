
#include "../include/rmm_cntr.h"
#include "../include/rmm_land.h"
#include "../include/rmm_obj.h"
#include "../include/rmm_terrain_generator.h"
#include <math.h>
#include <new.h>

extern int __cdecl debug_rand(char* file, int line);
static char s_rmm_cntr_path[] = "C:\\msdev\\work\\age1_x1\\rmm_cntr.cpp";

RGE_RMM_Controller::RGE_RMM_Controller(RGE_Map* in_map, RGE_Game_World* world,
    uchar type, long player_num)
    : RGE_Random_Map_Module(in_map, 0, 1) {
    int map_type = type;
    RGE_Terrain_Info terrain_info;
    RGE_Land_Info land_info;
    this->add_land_module(land_info, map_type, player_num);
    this->add_terrain_module(terrain_info, land_info, map_type);
    this->add_object_module(world, land_info);
}

uchar RGE_RMM_Controller::generate() {
    return RGE_Random_Map_Module::generate();
}

void RGE_RMM_Controller::add_land_module(RGE_Land_Info& info,
    long type, long player_num) {
    long land_percent;
    long mid_x1;
    long mid_y2;
    long x;
    long y;
    bool not_done;

    info.land_num = player_num;

    switch (type) {
    default:
        info.base_terrain = 0;
        info.wall_1_avoidance_line = 0;
        info.wall_2_avoidance_line = 0;
        info.wall_3_avoidance_line = 0;
        info.wall_4_avoidance_line = 0;
        info.wall_fade = 0;
        land_percent = 0;
        break;
    case 3:
        info.base_terrain = 1;
        info.wall_1_avoidance_line = 0;
        info.wall_2_avoidance_line = 0;
        info.wall_3_avoidance_line = 0;
        info.wall_4_avoidance_line = 0;
        info.wall_fade = 0;
        land_percent = 90;
        break;
    case 2:
        info.base_terrain = 1;
        info.wall_1_avoidance_line = 4;
        info.wall_2_avoidance_line = 4;
        info.wall_3_avoidance_line = this->map_width - 5;
        info.wall_4_avoidance_line = this->map_height - 5;
        info.wall_fade = 34;
        land_percent = 70;
        break;
    case 1:
        info.base_terrain = 1;
        info.wall_1_avoidance_line = 6;
        info.wall_2_avoidance_line = 6;
        info.wall_3_avoidance_line = this->map_width - 7;
        info.wall_4_avoidance_line = this->map_height - 7;
        info.wall_fade = 20;
        land_percent = 50;
        break;
    case 0:
        info.base_terrain = 1;
        info.wall_1_avoidance_line = 8;
        info.wall_2_avoidance_line = 8;
        info.wall_3_avoidance_line = this->map_width - 9;
        info.wall_4_avoidance_line = this->map_height - 9;
        info.wall_fade = 20;
        land_percent = 30;
    }

    long land_tile_num =
        land_percent * this->map_height * this->map_width / 100;
    float bound =
        (float)(this->map_width - 16) / sqrt((float)player_num) * .8;
    float bound_square = bound * bound;
    long mid_x2 = (long)(this->map_width / 2 - bound * .9);
    long index2 = (long)(this->map_height / 2 - bound * .9);
    long mid_y1 = (long)(this->map_width / 2 - bound * -.9);
    long maximum_y = (long)(this->map_height / 2 - bound * -.9);

    if (mid_x2 <= 8)
        mid_x2 = 9;
    if (index2 <= 8)
        index2 = 9;
    if (mid_y1 >= this->map_width - 9)
        mid_y1 = this->map_width - 10;
    if (maximum_y >= this->map_height - 9)
        maximum_y = this->map_height - 10;

    mid_x1 = 0;
    if (0 < player_num) {
        do {
            switch (type) {
            case 2:
            case 3:
            case 4:
                info.land[mid_x1].terrain_type = 0;
                info.land[mid_x1].area = 3;
                info.land[mid_x1].base_size = 5;
                info.land[mid_x1].zone = 0;
                break;
            case 1:
                info.land[mid_x1].terrain_type = 0;
                info.land[mid_x1].area = 4;
                info.land[mid_x1].base_size = 5;
                info.land[mid_x1].zone = (uchar)mid_x1;
                break;
            case 0:
                info.land[mid_x1].terrain_type = 0;
                info.land[mid_x1].area = 7;
                info.land[mid_x1].base_size = 5;
                info.land[mid_x1].zone = (uchar)mid_x1;
            }

            do {
                not_done = false;
                x = debug_rand(s_rmm_cntr_path, 0xD1) *
                    (this->map_width - 16) / 0x7FFF + 8;
                y = debug_rand(s_rmm_cntr_path, 0xD2) *
                    (this->map_height - 16) / 0x7FFF + 8;

                if (x > mid_x2 && x < mid_y1 &&
                    y > index2 && y < maximum_y) {
                    not_done = true;
                } else {
                    mid_y2 = 0;
                    if (0 < mid_x1) {
                        do {
                            long delta_x = x - info.land[mid_y2].x;
                            if (delta_x < 0)
                                delta_x = -delta_x;
                            long delta_y = y - info.land[mid_y2].y;
                            if (delta_y < 0)
                                delta_y = -delta_y;
                            if ((float)(delta_x * delta_x +
                                delta_y * delta_y) <= bound_square) {
                                if (!not_done && mid_y2 == mid_x1 - 1) {
                                    info.land[mid_y2].y = y;
                                    info.land[mid_y2].x = x;
                                }
                                not_done = true;
                            }
                            ++mid_y2;
                        } while (mid_y2 < mid_x1);
                    }
                }
            } while (not_done);

            info.land[mid_x1].x = x;
            info.land[mid_x1].y = y;
            info.land[mid_x1].land_size = land_tile_num / info.land_num;
            ++mid_x1;
        } while (mid_x1 < info.land_num);
    }

    new RGE_RMM_Land_Generator(this->map, this, &info);
}

void RGE_RMM_Controller::add_terrain_module(RGE_Terrain_Info& info,
    RGE_Land_Info& land_info, long type) {
    info.terrain_num = 2;
    switch (type) {
    case 3:
    case 4:
        info.terrain[0].terrain_size =
            this->map_width * this->map_height * 20 / 100;
        info.terrain[0].terrain_type = 10;
        info.terrain[0].clumps = 30;
        info.terrain[0].base_terrain_type = 0;
        info.terrain[0].terrain_generated = 0;
        info.terrain[0].spacing = 2;

        info.terrain[1].terrain_size =
            this->map_width * this->map_height * 30 / 100;
        info.terrain[1].terrain_type = 6;
        info.terrain[1].clumps = 17;
        goto terrain_defaults;
    case 0:
    case 1:
    case 2:
        info.terrain[0].terrain_size =
            this->map_width * this->map_height * 20 / 100;
        info.terrain[0].terrain_type = 10;
        info.terrain[0].clumps = 20;
        info.terrain[0].base_terrain_type = 0;
        info.terrain[0].terrain_generated = 0;
        info.terrain[0].spacing = 2;

        info.terrain[1].terrain_size =
            this->map_width * this->map_height * 30 / 100;
        info.terrain[1].terrain_type = 6;
        info.terrain[1].clumps = 7;
    terrain_defaults:
        info.terrain[1].base_terrain_type = 0;
        info.terrain[1].terrain_generated = 0;
        info.terrain[1].spacing = 0;

    default:
        long i = 0;
        info.hot_spot_num = land_info.land_num;
        if (info.hot_spot_num > 0) {
            do {
                info.hot_spots[i].x = land_info.land[i].x;
                info.hot_spots[i].y = land_info.land[i].y;
                info.hot_spots[i].radius = 12;
                info.hot_spots[i].fade = 20;
                ++i;
            } while (i < info.hot_spot_num);
        }

        new RGE_RMM_Terrain_Generator(this->map, this, &info);
    }
}

long RGE_RMM_Controller::count_map_tiles(uchar terrain) {
    return this->map_width * this->map_height;
}

void RGE_RMM_Controller::add_object_module(RGE_Game_World* world,
    RGE_Land_Info& land_info) {
    RGE_Object_Info object_info;
    object_info.object_num = 6;

    object_info.objects[0].obj_id = 0x6d;
    object_info.objects[0].terrain = 0;
    object_info.objects[0].group_flag = 0;
    object_info.objects[0].scale_flag = 0;
    object_info.objects[0].object_number_per_group = 1;
    object_info.objects[0].object_number_varience = 0;
    object_info.objects[0].number_of_groups = 1;
    object_info.objects[0].player_id = -1;
    object_info.objects[0].land_id = 0;
    object_info.objects[0].land_inner_radius = 0;
    object_info.objects[0].land_outer_radius = 0;

    object_info.objects[1].obj_id = 0x53;
    object_info.objects[1].terrain = 0;
    object_info.objects[1].group_flag = 0;
    object_info.objects[1].scale_flag = 0;
    object_info.objects[1].object_number_per_group = 1;
    object_info.objects[1].object_number_varience = 0;
    object_info.objects[1].number_of_groups = 3;
    object_info.objects[1].player_id = -1;
    object_info.objects[1].land_id = 0;
    object_info.objects[1].land_inner_radius = 2;
    object_info.objects[1].land_outer_radius = 4;

    object_info.objects[2].obj_id = 0x41;
    object_info.objects[2].terrain = 0;
    object_info.objects[2].group_flag = 1;
    object_info.objects[2].scale_flag = 1;
    object_info.objects[2].object_number_per_group = 6;
    object_info.objects[2].object_number_varience = 3;
    object_info.objects[2].number_of_groups = 10;
    object_info.objects[2].group_area = 3;
    object_info.objects[2].player_id = 0;
    object_info.objects[2].land_id = -1;
    object_info.objects[2].land_inner_radius = -1;
    object_info.objects[2].land_outer_radius = -1;

    object_info.objects[3].obj_id = 0x66;
    object_info.objects[3].terrain = -1;
    object_info.objects[3].group_flag = 2;
    object_info.objects[3].scale_flag = 0;
    object_info.objects[3].object_number_per_group = 6;
    object_info.objects[3].object_number_varience = 2;
    object_info.objects[3].number_of_groups = 1;
    object_info.objects[3].group_area = 4;
    object_info.objects[3].player_id = 0;
    object_info.objects[3].land_id = 0;
    object_info.objects[3].land_inner_radius = 9;
    object_info.objects[3].land_outer_radius = 15;

    object_info.objects[4].obj_id = 0x42;
    object_info.objects[4].terrain = -1;
    object_info.objects[4].group_flag = 2;
    object_info.objects[4].scale_flag = 0;
    object_info.objects[4].object_number_per_group = 6;
    object_info.objects[4].object_number_varience = 2;
    object_info.objects[4].number_of_groups = 1;
    object_info.objects[4].group_area = 4;
    object_info.objects[4].player_id = 0;
    object_info.objects[4].land_id = 0;
    object_info.objects[4].land_inner_radius = 9;
    object_info.objects[4].land_outer_radius = 15;

    object_info.objects[5].obj_id = 0x3b;
    object_info.objects[5].terrain = -1;
    object_info.objects[5].group_flag = 1;
    object_info.objects[5].scale_flag = 0;
    object_info.objects[5].object_number_per_group = 5;
    object_info.objects[5].object_number_varience = 2;
    object_info.objects[5].number_of_groups = 1;
    object_info.objects[5].group_area = 3;
    object_info.objects[5].player_id = 0;
    object_info.objects[5].land_id = 0;
    object_info.objects[5].land_inner_radius = 9;
    object_info.objects[5].land_outer_radius = 15;

    long land_num = land_info.land_num;
    object_info.land_num = land_num;
    long i = 0;
    if (0 < land_num) {
        do {
            object_info.lands[i].x = land_info.land[i].x;
            object_info.lands[i].y = land_info.land[i].y;
            object_info.lands[i].id = 0;
            object_info.lands[i].player_id = i + 1;
            ++i;
        } while (i < land_num);
    }

    new RGE_RMM_Object_Generator(this->map, this, world, &object_info, 1);
}
