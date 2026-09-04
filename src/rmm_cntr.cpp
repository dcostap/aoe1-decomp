
#include "../include/rmm_cntr.h"
#include "../include/rmm_land.h"
#include "../include/rmm_obj.h"
#include "../include/rmm_terrain_generator.h"
#include <math.h>
#include <new.h>

extern "C" int __cdecl debug_rand(char* file, int line);
static char s_rmm_cntr_path[] = "C:\\msdev\\work\\age1_x1\\rmm_cntr.cpp";

RGE_RMM_Controller::RGE_RMM_Controller(RGE_Map* map, RGE_Game_World* world,
    uchar map_type, long number_of_players)
    : RGE_Random_Map_Module(map, 0, 1)
{
    int type = map_type;
    RGE_Terrain_Info terrain_info;
    RGE_Land_Info land_info;
    this->add_land_module(land_info, type, number_of_players);
    this->add_terrain_module(terrain_info, land_info, type);
    this->add_object_module(world, land_info);
}

uchar RGE_RMM_Controller::generate()
{
    return RGE_Random_Map_Module::generate();
}

void RGE_RMM_Controller::add_land_module(RGE_Land_Info& info, long type,
    long land_num)
{
    long radius;
    long index;
    uchar not_done;
    long index2;
    // The land loop uses area as its anchor and advances 13 long values.
    long* land = &info.land[0].area;
    info.land_num = land_num;
    switch (type) {
    default:
        info.base_terrain = 0;
        info.wall_1_avoidance_line = 0; info.wall_2_avoidance_line = 0;
        radius = 0;
        info.wall_3_avoidance_line = 0; info.wall_4_avoidance_line = 0;
        info.wall_fade = 0; break;
    case 3:
        info.base_terrain = 1;
        radius = 90;
        info.wall_1_avoidance_line = 0; info.wall_2_avoidance_line = 0;
        info.wall_3_avoidance_line = 0; info.wall_4_avoidance_line = 0;
        info.wall_fade = 0; break;
    case 2:
        info.base_terrain = 1;
        info.wall_1_avoidance_line = 4; info.wall_2_avoidance_line = 4;
        radius = 70;
        info.wall_3_avoidance_line = this->map_width - 5;
        info.wall_4_avoidance_line = this->map_height - 5;
        info.wall_fade = 34; break;
    case 1:
        info.base_terrain = 1;
        info.wall_1_avoidance_line = 6; info.wall_2_avoidance_line = 6;
        radius = 50;
        info.wall_3_avoidance_line = this->map_width - 7;
        info.wall_4_avoidance_line = this->map_height - 7;
        info.wall_fade = 20; break;
    case 0:
        info.base_terrain = 1;
        info.wall_1_avoidance_line = 8; info.wall_2_avoidance_line = 8;
        radius = 30;
        info.wall_3_avoidance_line = this->map_width - 9;
        info.wall_4_avoidance_line = this->map_height - 9;
        info.wall_fade = 20; break;
    }
    long land_tile_num = radius * this->map_width * this->map_height / 100;
    float radius2 = (float)(this->map_width - 16) / sqrt((float)land_num) * 0.8;
    float bound_square = radius2 * radius2;
    long min_x = (long)(this->map_width / 2 - radius2 * 0.9);
    long min_y = (long)(this->map_height / 2 - radius2 * 0.9);
    long max_x = (long)(this->map_width / 2 + radius2 * 0.9);
    long max_y = (long)(this->map_height / 2 + radius2 * 0.9);
    if (min_x <= 8) min_x = 9;
    if (min_y <= 8) min_y = 9;
    if (max_x >= this->map_width - 9) max_x = this->map_width - 10;
    if (max_y >= this->map_height - 9) max_y = this->map_height - 10;
    index = 0;
    if (0 < land_num) {
        do {
            switch (type) {
            case 2:
            case 3:
            case 4:
                land[-4] = 0; *land = 3; land[-1] = 5;
                *(uchar*)(land + 1) = 0; break;
            case 1:
                land[-4] = 0; *land = 4;
                goto set_land_defaults;
            case 0:
                land[-4] = 0; *land = 7;
set_land_defaults:
                land[-1] = 5; *(uchar*)(land + 1) = (uchar)index; break;
            }
            long x;
            long y;
            do {
                not_done = 0;
                x = debug_rand(s_rmm_cntr_path, 0xd1) * (this->map_width - 16) / 0x7fff + 8;
                y = debug_rand(s_rmm_cntr_path, 0xd2) * (this->map_height - 16) / 0x7fff + 8;
                if (x > min_x && x < max_x && y > min_y && y < max_y) not_done = 1;
                else {
                    index2 = 0;
                    for (; index2 < index; ++index2) {
                        RGE_Land_Info_Line& prior = info.land[index2];
                        long dx = x - prior.x;
                        long dy = y - prior.y;
                        if (dx < 0) dx = -dx;
                        if (dy < 0) dy = -dy;
                        if ((float)(dx * dx + dy * dy) <= bound_square) {
                            if (!not_done && index2 == index - 1) { prior.y = y; prior.x = x; }
                            not_done = 1;
                        }
                    }
                }
            } while (not_done);
            land[-3] = x; land[-2] = y;
            ((RGE_Land_Info_Line*)(land - 5))->land_size = land_tile_num / info.land_num;
            ++index;
            land += 13;
        } while (index < info.land_num);
    }
    new RGE_RMM_Land_Generator(this->map, this, &info);
}

void RGE_RMM_Controller::add_terrain_module(RGE_Terrain_Info& info,
    RGE_Land_Info& lands, long type)
{
    long area;
    long i;
    info.terrain_num = 2;
    switch (type) {
    case 3: case 4:
        area = this->map_height * this->map_width;
        info.terrain[0].terrain_type = 10; info.terrain[0].clumps = 30;
        info.terrain[0].base_terrain_type = 0; info.terrain[0].terrain_generated = 0;
        info.terrain[0].terrain_size = area * 20 / 100; info.terrain[0].spacing = 2;
        area = this->map_height * this->map_width;
        info.terrain[1].terrain_type = 6; info.terrain[1].clumps = 17;
        info.terrain[1].terrain_size = area * 30 / 100; break;
    case 0: case 1: case 2:
        area = this->map_height * this->map_width;
        info.terrain[0].terrain_type = 10; info.terrain[0].clumps = 20;
        info.terrain[0].base_terrain_type = 0; info.terrain[0].terrain_generated = 0;
        info.terrain[0].terrain_size = area * 20 / 100; info.terrain[0].spacing = 2;
        area = this->map_height * this->map_width;
        info.terrain[1].terrain_type = 6; info.terrain[1].clumps = 7;
        info.terrain[1].terrain_size = area * 30 / 100; break;
    default: goto after_defaults;
    }
    info.terrain[1].base_terrain_type = 0;
    info.terrain[1].terrain_generated = 0;
    info.terrain[1].spacing = 0;
after_defaults:
    info.hot_spot_num = lands.land_num;
    for (i = 0; i < info.hot_spot_num; ++i) {
        info.hot_spots[i].x = lands.land[i].x;
        info.hot_spots[i].y = lands.land[i].y;
        info.hot_spots[i].radius = 12;
        info.hot_spots[i].fade = 20;
    }
    new RGE_RMM_Terrain_Generator(this->map, this, &info);
}

long RGE_RMM_Controller::count_map_tiles(uchar ignored)
{
    return this->map_width * this->map_height;
}

void RGE_RMM_Controller::add_object_module(RGE_Game_World* world,
    RGE_Land_Info& lands)
{
    RGE_Object_Info info;
    long i;
    int count;
    info.object_num = 6;
    info.objects[1].land_outer_radius = 4;
    info.objects[2].object_number_per_group = 6;
    info.objects[3].object_number_per_group = 6;
    info.objects[3].group_area = 4;
    info.objects[4].object_number_per_group = 6;
    RGE_Object_Info_Line& deer = info.objects[0];
    deer.obj_id = 0x6d; deer.terrain = 0; deer.group_flag = 0; deer.scale_flag = 0;
    deer.object_number_per_group = 1; deer.object_number_varience = 0;
    deer.number_of_groups = 1; deer.player_id = -1; deer.land_id = 0;
    deer.land_inner_radius = 0; deer.land_outer_radius = 0;
    RGE_Object_Info_Line& berry = info.objects[1];
    berry.obj_id = 0x53; berry.terrain = 0; berry.group_flag = 0; berry.scale_flag = 0;
    berry.object_number_per_group = 1; berry.object_number_varience = 0;
    berry.number_of_groups = 3; berry.player_id = -1; berry.land_id = 0;
    berry.land_inner_radius = 2;
    RGE_Object_Info_Line& gold = info.objects[2];
    gold.obj_id = 0x41; gold.terrain = 0; gold.group_flag = 1; gold.scale_flag = 1;
    gold.object_number_varience = 3; gold.number_of_groups = 10; gold.group_area = 3;
    gold.player_id = 0; gold.land_id = -1; gold.land_inner_radius = -1;
    gold.land_outer_radius = -1;
    RGE_Object_Info_Line& stone = info.objects[3];
    stone.obj_id = 0x66; stone.terrain = -1; stone.group_flag = 2; stone.scale_flag = 0;
    stone.object_number_varience = 2; stone.number_of_groups = 1;
    stone.player_id = 0; stone.land_id = 0; stone.land_outer_radius = 15; stone.land_inner_radius = 9;
    RGE_Object_Info_Line& tree = info.objects[4];
    tree.obj_id = 0x42; tree.terrain = -1; tree.group_flag = 2; tree.scale_flag = 0;
    tree.object_number_varience = 2; tree.number_of_groups = 1; tree.group_area = 4;
    tree.player_id = 0; tree.land_id = 0; tree.land_inner_radius = 9; tree.land_outer_radius = 15;
    RGE_Object_Info_Line& predator = info.objects[5];
    predator.obj_id = 0x3b; predator.terrain = -1; predator.group_flag = 1; predator.scale_flag = 0;
    predator.object_number_per_group = 5; predator.object_number_varience = 2;
    predator.number_of_groups = 1; predator.group_area = 3; predator.player_id = 0;
    predator.land_id = 0; predator.land_outer_radius = 15; predator.land_inner_radius = 9;
    count = lands.land_num;
    info.land_num = count;
    for (i = 0; i < count; ++i) {
        info.lands[i].x = lands.land[i].x;
        info.lands[i].y = lands.land[i].y;
        info.lands[i].id = 0;
        info.lands[i].player_id = i + 1;
    }
    new RGE_RMM_Object_Generator(this->map, this, world, &info, 1);
}
