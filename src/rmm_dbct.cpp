
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

extern "C" int __cdecl debug_rand(char* file, int line);

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
    char* terrain_file, char* object_file, char* terrain_type_file,
    char* map_file)
    : RGE_Random_Map_Module(0, 0, 0)
{
    int index = 0;
    FILE* infile;
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
                for (index = 0; index < this->map_info.map_num; ++index) {
                    fscanf(infile, "%d", &this->map_info.maps[index].map_id);
                }
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
        infile = fopen(terrain_file, "r");
        if (infile != 0) {
            fscanf(infile, "%d", &terrain_count);
            if (terrain_count > 0) {
                for (index = 0; index < terrain_count; ++index) {
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
                        for (entry_index = 0;
                             entry_index < land_data->land_num;
                             ++entry_index) {
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
                        }
                    }
                    else {
                        land_data->land = 0;
                    }
                }
            }
            fclose(infile);
        }

        infile = fopen(object_file, "r");
        if (infile != 0) {
            fscanf(infile, "%d", &object_count);
            if (object_count > 0) {
                for (index = 0; index < object_count; ++index) {
                    fscanf(infile, "%d", &map_index);
                    terrain_data = &this->map_info.maps[map_index].terrain_info;
                    fscanf(infile, "%d", &terrain_data->terrain_num);
                    if (terrain_data->terrain_num > 0) {
                        terrain_data->terrain = (RGE_Terrain_Data_Entry*)calloc(
                            terrain_data->terrain_num,
                            sizeof(RGE_Terrain_Data_Entry));
                        for (entry_index = 0;
                             entry_index < terrain_data->terrain_num;
                             ++entry_index) {
                            RGE_Terrain_Data_Entry& terrain =
                                terrain_data->terrain[entry_index];
                            fscanf(infile, "%d %d %d %d %d",
                                   &terrain.terrain_percent,
                                   &terrain.terrain_type,
                                   &terrain.clumps,
                                   &terrain.spacing,
                                   &terrain.base_terrain_type);
                            terrain.clumpiness_factor = 0x14;
                        }
                    }
                    else {
                        terrain_data->terrain = 0;
                    }
                }
            }
            fclose(infile);
        }

        infile = fopen(terrain_type_file, "r");
        if (infile != 0) {
            fscanf(infile, "%d", &object_type_count);
            if (object_type_count > 0) {
                for (index = 0; index < object_type_count; ++index) {
                    fscanf(infile, "%d", &map_index);
                    object_data = &this->map_info.maps[map_index].object_info;
                    fscanf(infile, "%d", &object_data->object_num);
                    if (object_data->object_num > 0) {
                        object_data->objects = (RGE_Object_Data_Entry*)calloc(
                            object_data->object_num,
                            sizeof(RGE_Object_Data_Entry));
                        for (entry_index = 0;
                             entry_index < object_data->object_num;
                             ++entry_index) {
                            RGE_Object_Data_Entry& object =
                                object_data->objects[entry_index];
                            fscanf(infile,
                                   "%d %d %d %d %d %d %d %d %d %d %d %d",
                                   &object.obj_id,
                                   &object.terrain,
                                   &scale_flag,
                                   scale,
                                   &object.object_number_per_group,
                                   &object.object_number_varience,
                                   &object.number_of_groups,
                                   &object.group_area,
                                   &object.player_id,
                                   &object.land_id,
                                   &object.land_inner_radius,
                                   &object.land_outer_radius);
                            object.group_flag = (uchar)scale_flag;
                            object.scale_flag = scale[0];
                        }
                    }
                    else {
                        object_data->objects = 0;
                    }
                }
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
    long index;
    long previous;
    long x;
    long y;
    bool retry;
    float bound;
    long minimum_x;
    long minimum_y;
    long maximum_x;
    long maximum_y;

    L->Log(s_calc_land_start, debug_rand(s_rmm_dbct_path, 0x1C3));
    long diameter = radius + radius;
    bound = (float)(this->map_width - diameter) / sqrt((float)count);
    if (count > 3 && count < 7)
        bound *= 0.9F;
    else if (count >= 7)
        bound *= 0.8F;

    float bound_square = bound * bound;
    minimum_x = (int)(this->map_width / 2 - bound * 0.9);
    minimum_y = (int)(this->map_height / 2 - bound * 0.9);
    maximum_x = (int)(this->map_width / 2 - bound * -0.9);
    maximum_y = (int)(this->map_height / 2 - bound * -0.9);
    if (minimum_x <= radius)
        minimum_x = radius + 1;
    if (minimum_y <= radius)
        minimum_y = radius + 1;
    if (maximum_x >= this->map_width - radius - 1)
        maximum_x = this->map_width - radius - 2;
    if (maximum_y >= this->map_height - radius - 1)
        maximum_y = this->map_height - radius - 2;

    switch (land->placement_type) {
    case 0:
        L->Log(s_calc_land_end_point1);
        for (index = start; index < start + count; ++index) {
            this->land_info.land[index].x =
                debug_rand(s_rmm_dbct_path, 0x1E5) *
                (this->map_width - diameter) / 0x7FFF + radius;
            this->land_info.land[index].y =
                debug_rand(s_rmm_dbct_path, 0x1E6) *
                (this->map_height - diameter) / 0x7FFF + radius;
        }
        break;
    case 1:
        L->Log(s_calc_land_end_point2);
        for (index = start; index < start + count; ++index) {
            this->land_info.land[index].x = land->x;
            this->land_info.land[index].y = land->y;
        }
        break;
    case 2:
        L->Log(s_calc_land_end_point3);
        for (index = start; index < start + count; ++index) {
            retry = false;
            do {
                x = debug_rand(s_rmm_dbct_path, 0x1FC) *
                    (this->map_width - diameter) / 0x7FFF + radius;
                y = debug_rand(s_rmm_dbct_path, 0x1FD) *
                    (this->map_height - diameter) / 0x7FFF + radius;
                if (x > minimum_x && x < maximum_x &&
                    y > minimum_y && y < maximum_y)
                    goto retry_position;
                for (previous = start; previous < index; ++previous) {
                    int delta_x = x - this->land_info.land[previous].x;
                    int delta_y = y - this->land_info.land[previous].y;
                    if (delta_x < 0)
                        delta_x = -delta_x;
                    if (delta_y < 0)
                        delta_y = -delta_y;
                    if ((float)(delta_x * delta_x + delta_y * delta_y) <=
                        bound_square) {
                        if (previous == index - 1) {
                            this->land_info.land[index].x = x;
                            this->land_info.land[index].y = y;
                            L->Log(s_calc_land_xy, index, x, y);
                        }
                        goto retry_position;
                    }
                }
                goto retry_done;
retry_position:
                retry = true;
retry_done:
                ;
            } while (retry);
            this->land_info.land[index].x = x;
            this->land_info.land[index].y = y;
            L->Log(s_calc_land_xy, index, x, y);
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
    long team_size[9];
    long player_teams[9];
    long land_teams[9];
    long distances[8][8];

    RGE_Land_Data* land_data =
        &this->map_info.maps[this->map_type].land_info;
    land_area = land_data->grown_land_percent * this->map_width *
        this->map_height / 100;
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
        RGE_Land_Data_Entry& map_land = land_data->land[map_land_index];
        if (map_land.by_player_flag != 0) {
            this->calc_land_start(land_index, placement_edge,
                                  this->number_of_players, &map_land);
            for (group_index = 0; group_index < this->number_of_players;
                 ++group_index) {
                RGE_Land_Info_Line& land = this->land_info.land[land_index];
                land.terrain_type = map_land.terrain_type;
                land.area = map_land.land_avoidance_tiles;
                land.base_size = map_land.base_square_radius;
                if (map_land.by_player_flag == 1)
                    land.zone = map_land.zone;
                else
                    land.zone = (uchar)group_index;
                land.land_size = map_land.amount_of_land_used_percent *
                    land_area / (this->number_of_players * 100);
                land.clumpiness_factor = map_land.clumpiness_factor;
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
            land.terrain_type = map_land.terrain_type;
            land.area = map_land.land_avoidance_tiles;
            land.base_size = map_land.base_square_radius;
            land.zone = map_land.zone;
            this->calc_land_start(land_index, placement_edge, 1, &map_land);
            land.land_size = map_land.amount_of_land_used_percent * land_area /
                100;
            land.clumpiness_factor = map_land.clumpiness_factor;
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

    group_count = this->land_info.land_num;
    for (land_index = 0; land_index < group_count; ++land_index) {
        for (candidate = 0; candidate < group_count; ++candidate) {
            long delta_x = this->land_info.land[land_index].x -
                this->land_info.land[candidate].x;
            long delta_y = this->land_info.land[land_index].y -
                this->land_info.land[candidate].y;
            team_size[candidate + 1] =
                delta_x * delta_x + delta_y * delta_y;
            distances[land_index][candidate + 1] = candidate;
        }
        do {
            uchar ordered = 1;
            for (candidate = 1; candidate < group_count; ++candidate) {
                if (team_size[candidate] > team_size[candidate + 1]) {
                    long distance = team_size[candidate];
                    long member = distances[land_index][candidate];
                    team_size[candidate] = team_size[candidate + 1];
                    team_size[candidate + 1] = distance;
                    distances[land_index][candidate] =
                        distances[land_index][candidate + 1];
                    distances[land_index][candidate + 1] = member;
                    ordered = 0;
                }
            }
            if (ordered)
                break;
        } while (1);
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
                long first = distances[group_land][group_count];
                for (candidate = group_count - 1; candidate >= 0; --candidate) {
                    long next_land = distances[group_land][candidate + 1];
                    if (land_teams[next_land + 1] == -1) {
                        first = next_land;
                        break;
                    }
                }
                other_team = -1;
                land_index = first;
                for (candidate = 0; candidate < group_count; ++candidate) {
                    long next_land = distances[first][candidate + 1];
                    if (land_teams[next_land + 1] != group_index &&
                        land_teams[next_land + 1] >= 0) {
                        other_team = land_teams[next_land + 1];
                        land_index = next_land;
                        for (long nearest = 0; nearest < members; ++nearest) {
                            long member = distances[group_land][nearest + 1];
                            if (land_teams[member + 1] == other_team) {
                                land_index = member;
                                break;
                            }
                        }
                        break;
                    }
                }
                land_teams[first + 1] = other_team;
                land_teams[land_index + 1] = -1;
                for (candidate = group_count - 1; candidate >= 0; --candidate) {
                    long next_land = distances[other_team][candidate + 1];
                    if (land_teams[next_land + 1] == other_team) {
                        for (long nearest = 0; nearest < group_count; ++nearest) {
                            long member = distances[first][nearest + 1];
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
    RGE_Map_Data_Entry& map_entry = this->map_info.maps[this->map_type];
    long terrain_index = 0;
    long land_area = this->map_width * this->map_height *
        map_entry.land_info.grown_land_percent / 100;

    this->terrain_info.terrain_num = map_entry.terrain_info.terrain_num;
    while (terrain_index < map_entry.terrain_info.terrain_num) {
        RGE_Terrain_Info_Line& terrain = this->terrain_info.terrain[terrain_index];
        RGE_Terrain_Data_Entry& map_terrain =
            map_entry.terrain_info.terrain[terrain_index];
        terrain.terrain_size = (long)((float)(map_terrain.terrain_percent *
            land_area) * DAT_00571ec0);
        terrain.terrain_type = map_terrain.terrain_type;
        terrain.clumps = map_terrain.clumps;
        terrain.base_terrain_type = map_terrain.base_terrain_type;
        terrain.terrain_generated = 0;
        terrain.spacing = map_terrain.spacing;
        terrain.clumpiness_factor = map_terrain.clumpiness_factor;
        terrain.avoid_hot_spots = 1;
        ++terrain_index;
    }

    int hot_spot_index = 0;
    for (long map_land_index = 0;
         map_land_index < map_entry.land_info.land_num;
         ++map_land_index) {
        RGE_Land_Data_Entry& map_land = map_entry.land_info.land[map_land_index];
        if (map_land.radius >= 0) {
            if (map_land.by_player_flag != 0) {
                for (int player_index = 0;
                     player_index < this->number_of_players;
                     ++player_index) {
                    RGE_Terrain_Hot_Spots& hot_spot =
                        this->terrain_info.hot_spots[hot_spot_index];
                    hot_spot.x = this->land_info.land[hot_spot_index].x;
                    hot_spot.y = this->land_info.land[hot_spot_index].y;
                    hot_spot.radius = map_land.radius;
                    hot_spot.fade = map_land.fade;
                    ++hot_spot_index;
                }
            }
            else {
                RGE_Terrain_Hot_Spots& hot_spot =
                    this->terrain_info.hot_spots[hot_spot_index];
                hot_spot.x = this->land_info.land[hot_spot_index].x;
                hot_spot.y = this->land_info.land[hot_spot_index].y;
                hot_spot.radius = map_land.radius;
                hot_spot.fade = map_land.fade;
                ++hot_spot_index;
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
        RGE_Land_Point_Info_Line* destination = this->object_info.lands;
        int map_land_index = 0;
        do {
        destination->x = source->x;
        destination->y = source->y;
        destination->id = map->land_info.land[map_land_index].land_id;
        destination->player_id = player;

        if (player > 0 && ++player > this->number_of_players)
            player = 0;
        if (player == 0) {
            ++map_land_index;
            if (map->land_info.land[map_land_index].by_player_flag != 0)
                player = 1;
        }
        ++land_index;
        ++source;
        ++destination;
        } while (land_index < this->land_info.land_num);
    }
}

void RGE_RMM_Database_Controller::add_elevation_module()
{
    RGE_Land_Data& map_land =
        this->map_info.maps[this->map_type].land_info;
    int land_area = map_land.grown_land_percent * this->map_width *
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

    this->elevation_info.elevation[2].elevation_size = land_area * 6 / 100;
    this->elevation_info.elevation[2].elevation = 3;
    this->elevation_info.elevation[2].clumps = 6;
    this->elevation_info.elevation[2].base_terrain_type = 0;
    this->elevation_info.elevation[2].base_elevation = 2;
    this->elevation_info.elevation[2].spacing = 1;

    this->elevation_info.elevation[3].elevation_size = land_area * 4 / 100;
    this->elevation_info.elevation[3].elevation = 4;
    this->elevation_info.elevation[3].clumps = 4;
    this->elevation_info.elevation[3].base_terrain_type = 0;
    this->elevation_info.elevation[3].base_elevation = 3;
    this->elevation_info.elevation[3].spacing = 1;

    int hot_spot_index = 0;
    for (int land_index = 0; land_index < map_land.land_num; ++land_index) {
        if (map_land.land[land_index].radius >= 0) {
            if (map_land.land[land_index].by_player_flag != 0) {
                for (int player_index = 0;
                     player_index < this->number_of_players;
                     ++player_index) {
                    RGE_Elevation_Hot_Spots& hot_spot =
                        this->elevation_info.hot_spots[hot_spot_index];
                    hot_spot.x = this->land_info.land[hot_spot_index].x;
                    hot_spot.y = this->land_info.land[hot_spot_index].y;
                    hot_spot.radius = map_land.land[land_index].radius;
                    hot_spot.fade = map_land.land[land_index].fade;
                    ++hot_spot_index;
                }
            }
            else {
                RGE_Elevation_Hot_Spots& hot_spot =
                    this->elevation_info.hot_spots[hot_spot_index];
                hot_spot.x = this->land_info.land[hot_spot_index].x;
                hot_spot.y = this->land_info.land[hot_spot_index].y;
                hot_spot.radius = map_land.land[land_index].radius;
                hot_spot.fade = map_land.land[land_index].fade;
                ++hot_spot_index;
            }
        }
    }
    this->elevation_info.hot_spot_num = hot_spot_index;
}
