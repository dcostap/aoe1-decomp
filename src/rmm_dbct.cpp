
#include "../include/world.h"
#include "../include/map.h"
#include "../include/rmm_land.h"
#include "../include/rmm_terrain_info.h"
#include "../include/rmm_terrain_generator.h"
#include "../include/rmm_obj.h"
#include "../include/rmm_elev.h"
#include "../include/rmm_base.h"
#include "../include/rmm_dbct.h"
#include "../include/game_globals.h"
#include "../include/player.h"
#include "../include/debuglog.h"
#include "../include/rge_fio.h"
#include <math.h>
#include <new.h>
#include <stdlib.h>

extern int __cdecl debug_rand(char* file, int line);

static char s_rmm_dbct_path[] =
    "C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp";
static char s_calc_land_start[] =
    "********Random Map calc land start, rand: %d";
static char s_calc_land_end_point1[] =
    "********Random Map calc land end (point1) ";
static char s_calc_land_end_point2[] =
    "********Random Map calc land end (point2) ";
static char s_calc_land_end_point3[] =
    "********Random Map calc land end (point3) ";
static char s_calc_land_xy[] =
    "********Random Map calc land xy player %d (%d, %d)";
static char s_calc_land_end[] =
    "********Random Map calc land end, rand:";

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(
    char* land_file, char* terrain_file, char* object_file,
    char* map_file)
    : RGE_Random_Map_Module(0, 0, 0)
{
    RGE_Land_Data* land_data;
    RGE_Terrain_Data* terrain_data;
    RGE_Object_Data* object_data;
    int map_index;
    int entry_index;
    long terrain_count;
    long object_count;
    long object_type_count;
    long terrain_type;
    long placement_type;
    long land_percent;
    long player_land;
    long group_flag;
    long scale_flag;
    unsigned char scale[4];
    long index1 = 0;
    FILE* infile;

    this->world = 0;
    this->map_type = -1;
    this->number_of_players = 0;

    infile = fopen(map_file, "r");
    if (infile != 0) {
        fscanf(infile, " %d", &this->map_info.map_num);
        if (this->map_info.map_num > 0) {
            this->map_info.maps = (RGE_Map_Data_Entry*)calloc(
                this->map_info.map_num, sizeof(RGE_Map_Data_Entry));
            if (this->map_info.map_num > 0) {
                index1 = 0;
                do {
                    fscanf(infile, "%d", &this->map_info.maps[index1].map_id);
                    ++index1;
                } while (index1 < this->map_info.map_num);
                fclose(infile);
                goto map_database_loaded;
            }
        }
        else {
            this->map_info.maps = 0;
        }
        fclose(infile);
    }
    else {
        this->map_info.maps = 0;
        this->map_info.map_num = 0;
    }

map_database_loaded:
    if (this->map_info.map_num > 0) {
        infile = fopen(land_file, "r");
        if (infile != 0) {
            fscanf(infile, "%d", &terrain_count);
            index1 = 0;
            if (index1 < terrain_count) {
                do {
                    fscanf(infile, "%d", &map_index);
                    land_data = &this->map_info.maps[map_index].land_info;
                    fscanf(infile, "%d %d %d %d %d %d %d %d %d",
                           &land_data->land_num,
                           &land_data->map_edge_buffer[0],
                           &land_data->map_edge_buffer[1],
                           &land_data->map_edge_buffer[2],
                           &land_data->map_edge_buffer[3],
                           &land_data->map_edge_fade,
                           &land_data->land_placement_edge,
                           &land_data->base_terrain,
                           &land_data->grown_land_percent);
                    if (land_data->land_num > 0) {
                        land_data->land = (RGE_Land_Data_Entry*)calloc(
                            land_data->land_num,
                            sizeof(RGE_Land_Data_Entry));
                        entry_index = 0;
                        if (entry_index < land_data->land_num) {
                            do {
                                RGE_Land_Data_Entry& land =
                                    land_data->land[entry_index];
                                fscanf(infile,
                                       "%d %d %d %d %d %d %d %d %d %d %d %d",
                                       &land.land_id,
                                       &terrain_type,
                                       &land.land_avoidance_tiles,
                                       &land.base_square_radius,
                                       &placement_type,
                                       &land_percent,
                                       &land.x,
                                       &land.y,
                                       &player_land,
                                       &group_flag,
                                       &land.radius,
                                       &land.fade);
                                land.terrain_type = (uchar)terrain_type;
                                land.zone = (uchar)placement_type;
                                land.placement_type = (uchar)land_percent;
                                land.amount_of_land_used_percent =
                                    (uchar)player_land;
                                land.by_player_flag = (uchar)group_flag;
                                land.clumpiness_factor = 8;
                                ++entry_index;
                            } while (entry_index < land_data->land_num);
                        }
                    }
                    else {
                        land_data->land = 0;
                    }
                    ++index1;
                } while (index1 < terrain_count);
            }
            fclose(infile);
        }

        infile = fopen(terrain_file, "r");
        if (infile != 0) {
            fscanf(infile, "%d", &object_count);
            index1 = 0;
            if (index1 < object_count) {
                do {
                    fscanf(infile, "%d", &map_index);
                    terrain_data = &this->map_info.maps[map_index].terrain_info;
                    fscanf(infile, "%d", &terrain_data->terrain_num);
                    if (terrain_data->terrain_num <= 0) {
                        terrain_data->terrain = 0;
                    }
                    else {
                        terrain_data->terrain = (RGE_Terrain_Data_Entry*)calloc(
                            terrain_data->terrain_num,
                            sizeof(RGE_Terrain_Data_Entry));
                        for (entry_index = 0;
                             entry_index < terrain_data->terrain_num;
                             ++entry_index) {
                            RGE_Terrain_Data_Entry* terrain =
                                &terrain_data->terrain[entry_index];
                            fscanf(infile, "%d %d %d %d %d",
                                   &terrain->terrain_percent,
                                   &terrain->terrain_type,
                                   &terrain->clumps,
                                   &terrain->spacing,
                                   &terrain->base_terrain_type);
                            terrain->clumpiness_factor = 0x14;
                        }
                    }
                    ++index1;
                } while (index1 < object_count);
            }
            fclose(infile);
        }

        infile = fopen(object_file, "r");
        if (infile != 0) {
            fscanf(infile, "%d", &object_type_count);
            index1 = 0;
            if (index1 < object_type_count) {
                do {
                    fscanf(infile, "%d", &map_index);
                    object_data = &this->map_info.maps[map_index].object_info;
                    fscanf(infile, "%d", &object_data->object_num);
                    if (object_data->object_num <= 0) {
                        object_data->objects = 0;
                    }
                    else {
                        object_data->objects = (RGE_Object_Data_Entry*)calloc(
                            object_data->object_num,
                            sizeof(RGE_Object_Data_Entry));
                        entry_index = 0;
                        if (entry_index < object_data->object_num) {
                            do {
                                fscanf(infile,
                                       "%d %d %d %d %d %d %d %d %d %d %d %d",
                                       &object_data->objects[entry_index].obj_id,
                                       &object_data->objects[entry_index].terrain,
                                       &scale_flag,
                                       scale,
                                       &object_data->objects[entry_index].object_number_per_group,
                                       &object_data->objects[entry_index].object_number_varience,
                                       &object_data->objects[entry_index].number_of_groups,
                                       &object_data->objects[entry_index].group_area,
                                       &object_data->objects[entry_index].player_id,
                                       &object_data->objects[entry_index].land_id,
                                       &object_data->objects[entry_index].land_inner_radius,
                                       &object_data->objects[entry_index].land_outer_radius);
                                object_data->objects[entry_index].group_flag =
                                    (uchar)scale_flag;
                                object_data->objects[entry_index].scale_flag =
                                    scale[0];
                                ++entry_index;
                            } while (entry_index < object_data->object_num);
                        }
                    }
                    ++index1;
                } while (index1 < object_type_count);
            }
            fclose(infile);
        }
    }
    else {
        this->map_info.map_num = 0;
        this->map_info.maps = 0;
    }
}

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(int file)
    : RGE_Random_Map_Module(0, 0, 0)
{
    this->world = 0;
    this->map_type = -1;
    this->number_of_players = 0;

    rge_read(file, &this->map_info, sizeof(RGE_Map_Data));
    if (this->map_info.map_num > 0) {
        this->map_info.maps = (RGE_Map_Data_Entry*)calloc(
            this->map_info.map_num, sizeof(RGE_Map_Data_Entry));
        rge_read(file, this->map_info.maps,
                 this->map_info.map_num * sizeof(RGE_Map_Data_Entry));

        for (int map_index = 0;
             map_index < this->map_info.map_num;
             ++map_index) {
            RGE_Land_Data* land_data =
                &this->map_info.maps[map_index].land_info;
            RGE_Terrain_Data* terrain_data =
                &this->map_info.maps[map_index].terrain_info;
            RGE_Object_Data* object_data =
                &this->map_info.maps[map_index].object_info;
            RGE_Elevation_Data* elevation_data =
                &this->map_info.maps[map_index].elevation_info;

            rge_read(file, land_data, sizeof(RGE_Land_Data));
            if (land_data->land_num > 0) {
                land_data->land = (RGE_Land_Data_Entry*)calloc(
                    land_data->land_num, sizeof(RGE_Land_Data_Entry));
                rge_read(file, land_data->land,
                         land_data->land_num * sizeof(RGE_Land_Data_Entry));
            }

            rge_read(file, terrain_data, sizeof(RGE_Terrain_Data));
            if (terrain_data->terrain_num > 0) {
                terrain_data->terrain = (RGE_Terrain_Data_Entry*)calloc(
                    terrain_data->terrain_num,
                    sizeof(RGE_Terrain_Data_Entry));
                rge_read(file, terrain_data->terrain,
                         terrain_data->terrain_num *
                         sizeof(RGE_Terrain_Data_Entry));
            }

            rge_read(file, object_data, sizeof(RGE_Object_Data));
            if (object_data->object_num > 0) {
                object_data->objects = (RGE_Object_Data_Entry*)calloc(
                    object_data->object_num, sizeof(RGE_Object_Data_Entry));
                rge_read(file, object_data->objects,
                         object_data->object_num *
                         sizeof(RGE_Object_Data_Entry));
            }

            rge_read(file, elevation_data, sizeof(RGE_Elevation_Data));
            if (elevation_data->elevation_num > 0) {
                elevation_data->elevation = (RGE_Elevation_Data_Entry*)calloc(
                    elevation_data->elevation_num,
                    sizeof(RGE_Elevation_Data_Entry));
                rge_read(file, elevation_data->elevation,
                         elevation_data->elevation_num *
                         sizeof(RGE_Elevation_Data_Entry));
            }
        }
    }
}

RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller()
{
    if (this->map_info.map_num > 0) {
        if (this->map_info.maps != 0) {
            for (int index = 0; index < this->map_info.map_num; ++index) {
                if (this->map_info.maps[index].land_info.land_num > 0)
                    free(this->map_info.maps[index].land_info.land);
                if (this->map_info.maps[index].terrain_info.terrain_num > 0)
                    free(this->map_info.maps[index].terrain_info.terrain);
                if (this->map_info.maps[index].object_info.object_num > 0)
                    free(this->map_info.maps[index].object_info.objects);
                if (this->map_info.maps[index].elevation_info.elevation_num > 0)
                    free(this->map_info.maps[index].elevation_info.elevation);
            }
            free(this->map_info.maps);
            this->map_info.map_num = 0;
        }
    }
}

uchar RGE_RMM_Database_Controller::save(int file)
{
    rge_write(file, &this->map_info, sizeof(RGE_Map_Data));

    if (this->map_info.map_num > 0) {
        rge_write(file, this->map_info.maps,
                  this->map_info.map_num * sizeof(RGE_Map_Data_Entry));

        int map_index = 0;
        for (int written = 0; written < this->map_info.map_num;
             ++written, ++map_index) {
            RGE_Land_Data* land_data =
                &this->map_info.maps[map_index].land_info;
            RGE_Terrain_Data* terrain_data =
                &this->map_info.maps[map_index].terrain_info;
            RGE_Object_Data* object_data =
                &this->map_info.maps[map_index].object_info;
            RGE_Elevation_Data* elevation_data =
                &this->map_info.maps[map_index].elevation_info;

            rge_write(file, land_data, sizeof(RGE_Land_Data));
            if (land_data->land_num > 0)
                rge_write(file, land_data->land,
                          land_data->land_num * sizeof(RGE_Land_Data_Entry));

            rge_write(file, terrain_data, sizeof(RGE_Terrain_Data));
            if (terrain_data->terrain_num > 0)
                rge_write(file, terrain_data->terrain,
                          terrain_data->terrain_num *
                          sizeof(RGE_Terrain_Data_Entry));

            rge_write(file, object_data, sizeof(RGE_Object_Data));
            if (object_data->object_num > 0)
                rge_write(file, object_data->objects,
                          object_data->object_num *
                          sizeof(RGE_Object_Data_Entry));

            rge_write(file, elevation_data, sizeof(RGE_Elevation_Data));
            if (elevation_data->elevation_num > 0)
                rge_write(file, elevation_data->elevation,
                          elevation_data->elevation_num *
                          sizeof(RGE_Elevation_Data_Entry));
        }
    }
    return 1;
}

uchar RGE_RMM_Database_Controller::generate()
{
    new RGE_RMM_Terrain_Generator(this->map, this, &this->terrain_info);
    new RGE_RMM_Land_Generator(this->map, this, &this->land_info);
    new RGE_RMM_Object_Generator(this->map, this, this->world,
                                 &this->object_info, 1);
    new RGE_RMM_Elevation_Generator(this->map, this, &this->elevation_info);

    return RGE_Random_Map_Module::generate();
}

uchar RGE_RMM_Database_Controller::init(RGE_Map* map,
                                        RGE_Game_World* world,
                                        uchar map_type,
                                        long players,
                                        uchar group_players)
{
    this->world = world;
    this->map_type = map_type;
    this->number_of_players = players;
    this->update_map_info(map);
    this->create_shared_resources();
    this->add_land_module(group_players);
    this->add_terrain_module();
    this->add_object_module();
    this->add_elevation_module();
    return 1;
}

uchar RGE_RMM_Database_Controller::de_init()
{
    this->world = 0;
    this->map_type = -1;
    this->number_of_players = 0;
    while (this->list != 0) {
        RGE_Random_Map_Module* module = this->list->module;
        if (module != 0) {
            module->~RGE_Random_Map_Module();
            operator delete(module);
        }
    }
    this->destroy_shared_resources();
    this->update_map_info(0);
    return 0;
}

void RGE_RMM_Database_Controller::calc_land_start(
    long start, long radius, long count, RGE_Land_Data_Entry* land)
{
    float radius2;
    float bound_square;
    long min_x;
    long min_y;
    long max_x;
    long max_y;
    long index;
    long end;
    long x;
    long y;
    long index2;
    long* land_ptr;
    const long* prior;
    long dx;
    long dy;
    uchar not_done;

    int random = debug_rand(s_rmm_dbct_path, 451);
    L->Log(s_calc_land_start, random);

    radius2 = (float)(this->map_width - radius * 2) /
        sqrt((float)count);

    if (count > 3 && count < 7)
        radius2 *= 0.9F;
    else if (count >= 7)
        radius2 *= 0.8F;

    bound_square = radius2 * radius2;
    min_x = (long)(this->map_width / 2 - radius2 * 0.9);
    min_y = (long)(this->map_height / 2 - radius2 * 0.9);
    max_x = (long)(this->map_width / 2 + radius2 * 0.9);
    max_y = (long)(this->map_height / 2 + radius2 * 0.9);

    if (min_x <= radius)
        min_x = radius + 1;
    if (min_y <= radius)
        min_y = radius + 1;
    if (max_x >= this->map_width - radius - 1)
        max_x = this->map_width - radius - 2;
    if (max_y >= this->map_height - radius - 1)
        max_y = this->map_height - radius - 2;

    switch (land->placement_type) {
    case 0:
        L->Log(s_calc_land_end_point1);
        end = start + count;
        if (start < end) {
            land_ptr = &this->land_info.land[start].y;
            do {
                land_ptr[-1] = debug_rand(s_rmm_dbct_path, 0x1e5) *
                    (this->map_width - radius * 2) / 0x7fff + radius;
                *land_ptr = debug_rand(s_rmm_dbct_path, 0x1e6) *
                    (this->map_height - radius * 2) / 0x7fff + radius;
                land_ptr += 13;
                --count;
            } while (count != 0);
        }
        break;

    case 1:
        L->Log(s_calc_land_end_point2);
        end = start + count;
        if (start < end) {
            land_ptr = &this->land_info.land[start].y;
            do {
                land_ptr[-1] = land->x;
                *land_ptr = land->y;
                land_ptr += 13;
                --count;
            } while (count != 0);
        }
        break;

    case 2:
        L->Log(s_calc_land_end_point3);
        index = start;
        end = start + count;
        if (index < end) {
            land_ptr = &this->land_info.land[index].y;
            do {
                do {
                    not_done = 0;
                    x = debug_rand(s_rmm_dbct_path, 0x1fc) *
                        (this->map_width - radius * 2) / 0x7fff + radius;
                    y = debug_rand(s_rmm_dbct_path, 0x1fd) *
                        (this->map_height - radius * 2) / 0x7fff + radius;

                    if (x > min_x && x < max_x &&
                        y > min_y && y < max_y) {
                        not_done = 1;
                    }
                    else {
                        index2 = start;
                        prior = land_ptr;
                        if (start < index) {
                            do {
                                dx = x - prior[-1];
                                if (dx < 0)
                                    dx = -dx;
                                dy = y - *prior;
                                if (dy < 0)
                                    dy = -dy;
                                if ((float)(dx * dx + dy * dy) <=
                                    bound_square) {
                                    if (index2 == index - 1) {
                                        long* fallback =
                                            &this->land_info.land[index - 1].y;
                                        *fallback = y;
                                        fallback[-1] = x;
                                        L->Log(s_calc_land_xy,
                                               index2, x, y);
                                    }
                                    not_done = 1;
                                    break;
                                }
                                prior += 13;
                                ++index2;
                            } while (index2 < index);
                        }
                    }
                } while (not_done != 0);

                land_ptr[-1] = x;
                *land_ptr = y;
                L->Log(s_calc_land_xy, index, x, y);
                ++index;
                land_ptr += 13;
            } while (index < end);
        }
        break;
    }

    L->Log(s_calc_land_end);
}

void RGE_RMM_Database_Controller::add_land_module(uchar group_players)
{
    long group_index;
    long map_land_index;
    long land_index;
    long group_count;
    long land_area;
    long placement_edge;
    long team;
    long candidate;
    long other_team;
    long start_land;
    long team_size[8];
    long player_teams[9];
    long land_teams[9];
    long distances[8][8];
    long map_width = this->map_width;
    long map_height = this->map_height;
    long* distance_row;
    RGE_Land_Info_Line* distance_land;

    RGE_Land_Data* land_data =
        &this->map_info.maps[this->map_type].land_info;
    land_area = land_data->grown_land_percent * map_width *
        map_height / 100;
    placement_edge = land_data->land_placement_edge;

    this->land_info.land_num = 0;
    for (map_land_index = 0; map_land_index < land_data->land_num;
         ++map_land_index) {
        if (land_data->land[map_land_index].by_player_flag != 0)
            this->land_info.land_num += this->number_of_players;
        else
            ++this->land_info.land_num;
    }

    this->land_info.base_terrain = (uchar)land_data->base_terrain;
    this->land_info.wall_1_avoidance_line = land_data->map_edge_buffer[0];
    this->land_info.wall_2_avoidance_line = land_data->map_edge_buffer[1];
    this->land_info.wall_3_avoidance_line = this->map_width -
        land_data->map_edge_buffer[2];
    this->land_info.wall_4_avoidance_line = this->map_height -
        land_data->map_edge_buffer[3];
    this->land_info.wall_fade = (uchar)land_data->map_edge_fade;

    land_index = 0;
    for (map_land_index = 0; map_land_index < land_data->land_num;
         ++map_land_index) {
        if (land_data->land[map_land_index].by_player_flag != 0) {
            this->calc_land_start(land_index, placement_edge,
                                  this->number_of_players,
                                  &land_data->land[map_land_index]);
            for (group_index = 0; group_index < this->number_of_players;
                 ++group_index) {
                RGE_Land_Info_Line& land = this->land_info.land[land_index];
                land.terrain_type =
                    land_data->land[map_land_index].terrain_type;
                land.area =
                    land_data->land[map_land_index].land_avoidance_tiles;
                land.base_size =
                    land_data->land[map_land_index].base_square_radius;
                if (land_data->land[map_land_index].by_player_flag == 1)
                    land.zone = land_data->land[map_land_index].zone;
                else
                    land.zone = (uchar)group_index;
                land.land_size =
                    land_data->land[map_land_index].amount_of_land_used_percent *
                    land_area / (this->number_of_players * 100);
                land.clumpiness_factor =
                    land_data->land[map_land_index].clumpiness_factor;
                land.wall_1_avoidance_line =
                    this->land_info.wall_1_avoidance_line;
                land.wall_2_avoidance_line =
                    this->land_info.wall_2_avoidance_line;
                land.wall_3_avoidance_line =
                    this->land_info.wall_3_avoidance_line;
                land.wall_4_avoidance_line =
                    this->land_info.wall_4_avoidance_line;
                land.wall_fade = this->land_info.wall_fade;
                ++land_index;
            }
        }
        else {
            RGE_Land_Info_Line& land = this->land_info.land[land_index];
            land.terrain_type =
                land_data->land[map_land_index].terrain_type;
            land.area =
                land_data->land[map_land_index].land_avoidance_tiles;
            land.base_size =
                land_data->land[map_land_index].base_square_radius;
            land.zone = land_data->land[map_land_index].zone;
            this->calc_land_start(
                land_index, placement_edge, 1,
                &land_data->land[map_land_index]);
            land.land_size =
                land_data->land[map_land_index].amount_of_land_used_percent *
                land_area / 100;
            land.clumpiness_factor =
                land_data->land[map_land_index].clumpiness_factor;
            land.wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
            land.wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
            land.wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
            land.wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
            land.wall_fade = this->land_info.wall_fade;
            ++land_index;
        }
    }

    if (group_players == 0)
        return;

    distance_row = distances[0] + 1;
    distance_land = this->land_info.land;
    group_count = this->land_info.land_num;
    for (land_index = 0; land_index < group_count; ++land_index) {
        RGE_Land_Info_Line* scan_land = this->land_info.land;
        long* size = team_size;
        long remaining = group_count;
        if (remaining > 0) {
            do {
                ++size;
                long delta_x = distance_land->x - scan_land->x;
                long delta_y = distance_land->y - scan_land->y;
                *size = delta_x * delta_x + delta_y * delta_y;
                --remaining;
                ++scan_land;
            } while (remaining != 0);
        }
        for (candidate = 0; candidate < group_count; ++candidate)
            distance_row[candidate] = candidate;
        do {
            uchar ordered = 1;
            for (candidate = 1; candidate < group_count; ++candidate) {
                if (team_size[candidate] > team_size[candidate + 1]) {
                    long distance = team_size[candidate];
                    long member = distance_row[candidate - 1];
                    team_size[candidate] = team_size[candidate + 1];
                    team_size[candidate + 1] = distance;
                    distance_row[candidate - 1] =
                        distance_row[candidate];
                    distance_row[candidate] = member;
                    ordered = 0;
                }
            }
            if (ordered)
                break;
        } while (1);
        ++distance_land;
        distance_row += 8;
    }

    for (land_index = 0; land_index < group_count; ++land_index)
        player_teams[land_index + 1] = -1;

    team = 0;
    for (land_index = 0; land_index < group_count; ++land_index) {
        if (player_teams[land_index + 1] == -1) {
            player_teams[land_index + 1] = team;
            team_size[land_index + 1] = 1;
            for (candidate = 0; candidate < group_count; ++candidate) {
                if (this->world->players[land_index + 1]->relation(
                        candidate + 1) == 0) {
                    player_teams[candidate + 1] = team;
                    ++team_size[land_index + 1];
                }
            }
            ++team;
        }
    }

    for (land_index = 0; land_index < group_count; ++land_index)
        land_teams[land_index + 1] = -1;

    for (group_index = 0; group_index < team; ++group_index) {
        long group_land = 0;
        while (group_land < group_count && land_teams[group_land + 1] != -1)
            ++group_land;

        long members = team_size[group_land + 1];
        long placed = 0;
        while (placed < members) {
            for (candidate = 0; candidate < members; ++candidate) {
                long next_land = distances[group_land][candidate + 1];
                if (land_teams[next_land + 1] == -1) {
                    land_teams[next_land + 1] = group_index;
                    break;
                }
            }

            if (candidate == members) {
                if (members < group_count)
                    ++members;
                start_land = distances[group_land][group_count];
                for (candidate = group_count - 1; candidate >= 0; --candidate) {
                    long next_land = distances[group_land][candidate + 1];
                    if (land_teams[next_land + 1] == -1) {
                        start_land = next_land;
                        break;
                    }
                }
                other_team = -1;
                land_index = start_land;
                for (candidate = 0; candidate < group_count; ++candidate) {
                    long next_land = distances[start_land][candidate + 1];
                    if (land_teams[next_land + 1] != group_index &&
                        land_teams[next_land + 1] >= 0) {
                        other_team = land_teams[next_land + 1];
                        land_index = next_land;
                        for (long nearest = 0;
                             nearest < members; ++nearest) {
                            long member = distances[group_land][nearest + 1];
                            if (land_teams[member + 1] == other_team) {
                                land_index = member;
                                break;
                            }
                        }
                        break;
                    }
                }
                land_teams[start_land + 1] = other_team;
                land_teams[land_index + 1] = -1;
                for (candidate = group_count - 1; candidate >= 0; --candidate) {
                    long next_land = distances[other_team][candidate + 1];
                    if (land_teams[next_land + 1] == other_team) {
                        for (long nearest = 0; nearest < group_count; ++nearest) {
                            long member = distances[start_land][nearest + 1];
                            if (land_teams[member + 1] == -1 &&
                                member != land_index) {
                                land_teams[next_land + 1] = -1;
                                land_teams[member + 1] = other_team;
                                break;
                            }
                        }
                    }
                }
            }
            ++placed;
        }
    }

    for (land_index = 0; land_index < group_count; ++land_index)
        team_size[land_index + 1] = -1;

    for (group_index = 0; group_index < group_count; ++group_index) {
        for (land_index = 0; land_index < group_count; ++land_index) {
            if (team_size[land_index + 1] == -1 &&
                player_teams[land_index + 1] == land_teams[group_index + 1]) {
                team_size[land_index + 1] = group_index;
                break;
            }
        }
    }

    for (land_index = 0; land_index < group_count; ++land_index) {
        player_teams[land_index + 1] =
            this->land_info.land[team_size[land_index + 1]].x;
        land_teams[land_index + 1] =
            this->land_info.land[team_size[land_index + 1]].y;
    }
    for (land_index = 0; land_index < group_count; ++land_index) {
        this->land_info.land[land_index].x = player_teams[land_index + 1];
        this->land_info.land[land_index].y = land_teams[land_index + 1];
    }
}

void RGE_RMM_Database_Controller::add_terrain_module()
{
    RGE_Map_Data_Entry* map =
        this->map_info.maps + this->map_type;
    long land_area = this->map_width * this->map_height *
        map->land_info.grown_land_percent / 100;

    this->terrain_info.terrain_num = map->terrain_info.terrain_num;
    for (long terrain_index = 0;
         terrain_index < map->terrain_info.terrain_num; ++terrain_index) {
        RGE_Terrain_Data_Entry& map_terrain =
            map->terrain_info.terrain[terrain_index];
        RGE_Terrain_Info_Line& terrain =
            this->terrain_info.terrain[terrain_index];

        terrain.terrain_size =
            (long)(map_terrain.terrain_percent * land_area * 0.01F);
        terrain.terrain_type = map_terrain.terrain_type;
        terrain.clumps = map_terrain.clumps;
        terrain.base_terrain_type = map_terrain.base_terrain_type;
        terrain.terrain_generated = 0;
        terrain.spacing = map_terrain.spacing;
        terrain.clumpiness_factor = map_terrain.clumpiness_factor;
        terrain.avoid_hot_spots = 1;
    }

    long hot_spot_index = 0;
    for (long land_index = 0;
         land_index < map->land_info.land_num; ++land_index) {
        RGE_Land_Data_Entry& map_land = map->land_info.land[land_index];
        if (map_land.radius < 0)
            continue;

        if (map_land.by_player_flag == 0) {
            RGE_Terrain_Hot_Spots& hot_spot =
                this->terrain_info.hot_spots[hot_spot_index];
            hot_spot.x = this->land_info.land[hot_spot_index].x;
            hot_spot.y = this->land_info.land[hot_spot_index].y;
            hot_spot.radius = map_land.radius;
            hot_spot.fade = map_land.fade;
            ++hot_spot_index;
        }
        else {
            long player_index = 0;
            while (player_index < this->number_of_players) {
                RGE_Terrain_Hot_Spots& hot_spot =
                    this->terrain_info.hot_spots[hot_spot_index];
                hot_spot.x = this->land_info.land[hot_spot_index].x;
                hot_spot.y = this->land_info.land[hot_spot_index].y;
                hot_spot.radius = map_land.radius;
                hot_spot.fade = map_land.fade;
                ++hot_spot_index;
                ++player_index;
            }
        }
    }
    this->terrain_info.hot_spot_num = hot_spot_index;
}

void RGE_RMM_Database_Controller::add_object_module()
{
    int object_index = 0;
    RGE_Map_Data_Entry* map = this->map_info.maps + this->map_type;
    this->object_info.object_num = map->object_info.object_num;

    if (map->object_info.object_num > 0) {
        int source_index = 0;
        do {
            this->object_info.objects[object_index].obj_id =
                map->object_info.objects[source_index].obj_id;
            this->object_info.objects[object_index].terrain =
                map->object_info.objects[source_index].terrain;
            this->object_info.objects[object_index].group_flag =
                map->object_info.objects[source_index].group_flag;
            this->object_info.objects[object_index].scale_flag =
                map->object_info.objects[source_index].scale_flag;
            this->object_info.objects[object_index].object_number_per_group =
                map->object_info.objects[source_index].object_number_per_group;
            this->object_info.objects[object_index].object_number_varience =
                map->object_info.objects[source_index].object_number_varience;
            this->object_info.objects[object_index].number_of_groups =
                map->object_info.objects[source_index].number_of_groups;
            this->object_info.objects[object_index].player_id =
                map->object_info.objects[source_index].player_id;
            this->object_info.objects[object_index].land_id =
                map->object_info.objects[source_index].land_id;
            this->object_info.objects[object_index].land_inner_radius =
                map->object_info.objects[source_index].land_inner_radius;
            this->object_info.objects[object_index].land_outer_radius =
                map->object_info.objects[source_index].land_outer_radius;
            this->object_info.objects[object_index].group_area =
                map->object_info.objects[source_index].group_area;
            this->object_info.objects[object_index].object_exclusion_zone = 1;
            ++object_index;
            ++source_index;
        } while (object_index < map->object_info.object_num);
    }

    this->object_info.land_num = this->land_info.land_num;
    int player = 0;
    if (map->land_info.land[0].by_player_flag != 0) {
        player = 1;
    }
    int land_index = 0;
    if (this->land_info.land_num > 0) {
        RGE_Land_Info_Line* source = this->land_info.land;
        int map_land_index = 0;
        do {
        this->object_info.lands[land_index].x = source->x;
        this->object_info.lands[land_index].y = source->y;
        this->object_info.lands[land_index].id =
            map->land_info.land[map_land_index].land_id;
        this->object_info.lands[land_index].player_id = player;

        if (player > 0 && ++player > this->number_of_players)
            player = 0;
        if (player == 0) {
            ++map_land_index;
            if (map->land_info.land[map_land_index].by_player_flag != 0)
                player = 1;
        }
        ++land_index;
        ++source;
        } while (land_index < this->land_info.land_num);
    }
}

void RGE_RMM_Database_Controller::add_elevation_module()
{
    RGE_Land_Data* land_data =
        &this->map_info.maps[this->map_type].land_info;
    long land_area = this->map_width * land_data->grown_land_percent *
        this->map_height / 100;

    this->elevation_info.elevation_num = 4;

    this->elevation_info.elevation[0].elevation = 1;
    this->elevation_info.elevation[0].clumps = 10;
    this->elevation_info.elevation[0].base_terrain_type = 0;
    this->elevation_info.elevation[0].base_elevation = 0;
    this->elevation_info.elevation[0].spacing = 2;
    this->elevation_info.elevation[0].elevation_size = land_area * 10 / 100;

    this->elevation_info.elevation[1].elevation = 2;
    this->elevation_info.elevation[1].elevation_size = land_area * 8 / 100;
    this->elevation_info.elevation[1].clumps = 8;
    this->elevation_info.elevation[1].base_terrain_type = 0;
    this->elevation_info.elevation[1].base_elevation = 1;
    this->elevation_info.elevation[1].spacing = 1;

    this->elevation_info.elevation[2].elevation = 3;
    this->elevation_info.elevation[2].clumps = 6;
    this->elevation_info.elevation[2].base_terrain_type = 0;
    this->elevation_info.elevation[2].base_elevation = 2;
    this->elevation_info.elevation[2].spacing = 1;
    this->elevation_info.elevation[2].elevation_size = land_area * 6 / 100;

    this->elevation_info.elevation[3].elevation_size = land_area * 4 / 100;
    this->elevation_info.elevation[3].elevation = 4;
    this->elevation_info.elevation[3].clumps = 4;
    this->elevation_info.elevation[3].base_terrain_type = 0;
    this->elevation_info.elevation[3].base_elevation = 3;
    this->elevation_info.elevation[3].spacing = 1;

    long hot_spot_index = 0;
    for (long land_index = 0;
         land_index < land_data->land_num; ++land_index) {
        if (land_data->land[land_index].radius < 0)
            continue;

        if (land_data->land[land_index].by_player_flag != 0) {
            for (long player_index = 0;
                 player_index < this->number_of_players; ++player_index) {
                this->elevation_info.hot_spots[hot_spot_index].x =
                    this->land_info.land[hot_spot_index].x;
                this->elevation_info.hot_spots[hot_spot_index].y =
                    this->land_info.land[hot_spot_index].y;
                this->elevation_info.hot_spots[hot_spot_index].radius =
                    land_data->land[land_index].radius;
                this->elevation_info.hot_spots[hot_spot_index].fade =
                    land_data->land[land_index].fade;
                ++hot_spot_index;
            }
        }
        else {
            this->elevation_info.hot_spots[hot_spot_index].x =
                this->land_info.land[hot_spot_index].x;
            this->elevation_info.hot_spots[hot_spot_index].y =
                this->land_info.land[hot_spot_index].y;
            this->elevation_info.hot_spots[hot_spot_index].radius =
                land_data->land[land_index].radius;
            this->elevation_info.hot_spots[hot_spot_index].fade =
                land_data->land[land_index].fade;
            ++hot_spot_index;
        }
    }
    this->elevation_info.hot_spot_num = hot_spot_index;
}
