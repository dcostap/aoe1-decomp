
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
#include <stdio.h>
#include <stdlib.h>

extern int __cdecl debug_rand(char* file, int line);

static char s_rmm_dbct_path[] = "C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp";
static char s_calc_land_start[] = "********Random Map calc land start, rand: %d";
static char s_calc_land_end_point1[] = "********Random Map calc land end (point1) ";
static char s_calc_land_end_point2[] = "********Random Map calc land end (point2) ";
static char s_calc_land_end_point3[] = "********Random Map calc land end (point3) ";
static char s_calc_land_xy[] = "********Random Map calc land xy player %d (%d, %d)";
static char s_calc_land_end[] = "********Random Map calc land end, rand:";

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(
    char* land_file, char* terrain_file, char* object_file, char* map_file
) : RGE_Random_Map_Module(0, 0, 0) {
    FILE* infile;
    long map_id;
    long land_num;
    long terrain_num;
    long object_num;
    long temp_terrain_type;
    long temp_zone;
    long temp_placement_type;
    long temp_amount_of_land_used_percent;
    long temp_by_player_flag;
    long temp_group_flag;
    long temp_scale_flag;

    this->world = 0;
    this->map_type = -1;
    this->number_of_players = 0;

    infile = fopen(map_file, "r");
    if (infile != 0) {
        fscanf(infile, " %d", &this->map_info.map_num);
        if (this->map_info.map_num > 0) {
            this->map_info.maps = (RGE_Map_Data_Entry*) calloc(this->map_info.map_num, sizeof(RGE_Map_Data_Entry));
            for (long index1 = 0; index1 < this->map_info.map_num; ++index1)
                fscanf(infile, "%d", &this->map_info.maps[index1].map_id);
        } else {
            this->map_info.maps = 0;
        }
        fclose(infile);
    } else {
        this->map_info.map_num = 0;
        this->map_info.maps = 0;
    }

    if (this->map_info.map_num <= 0) {
        this->map_info.map_num = 0;
        this->map_info.maps = 0;
        return;
    }

    infile = fopen(land_file, "r");
    if (infile != 0) {
        fscanf(infile, "%d", &land_num);
        for (long index1 = 0; index1 < land_num; ++index1) {
            fscanf(infile, "%d", &map_id);
            RGE_Land_Data* data = &this->map_info.maps[map_id].land_info;
            fscanf(
                infile, "%d %d %d %d %d %d %d %d %d", &data->land_num, &data->map_edge_buffer[0],
                &data->map_edge_buffer[1], &data->map_edge_buffer[2], &data->map_edge_buffer[3], &data->map_edge_fade,
                &data->land_placement_edge, &data->base_terrain, &data->grown_land_percent
            );

            if (data->land_num > 0) {
                data->land = (RGE_Land_Data_Entry*) calloc(data->land_num, sizeof(RGE_Land_Data_Entry));
                for (long land_index = 0; land_index < data->land_num; ++land_index) {
                    RGE_Land_Data_Entry* land = &data->land[land_index];
                    fscanf(
                        infile, "%d %d %d %d %d %d %d %d %d %d %d %d", &land->land_id, &temp_terrain_type,
                        &land->land_avoidance_tiles, &land->base_square_radius, &temp_zone, &temp_placement_type,
                        &land->x, &land->y, &temp_amount_of_land_used_percent, &temp_by_player_flag, &land->radius,
                        &land->fade
                    );
                    land->terrain_type = (uchar) temp_terrain_type;
                    land->zone = (uchar) temp_zone;
                    land->placement_type = (uchar) temp_placement_type;
                    land->amount_of_land_used_percent = (uchar) temp_amount_of_land_used_percent;
                    land->by_player_flag = (uchar) temp_by_player_flag;
                    land->clumpiness_factor = 8;
                }
            } else {
                data->land = 0;
            }
        }
        fclose(infile);
    }

    infile = fopen(terrain_file, "r");
    if (infile != 0) {
        fscanf(infile, "%d", &terrain_num);
        for (long index1 = 0; index1 < terrain_num; ++index1) {
            fscanf(infile, "%d", &map_id);
            RGE_Terrain_Data* data = &this->map_info.maps[map_id].terrain_info;
            fscanf(infile, "%d", &data->terrain_num);
            if (data->terrain_num > 0) {
                data->terrain = (RGE_Terrain_Data_Entry*) calloc(data->terrain_num, sizeof(RGE_Terrain_Data_Entry));
                for (long terrain_index = 0; terrain_index < data->terrain_num; ++terrain_index) {
                    RGE_Terrain_Data_Entry* terrain = &data->terrain[terrain_index];
                    fscanf(
                        infile, "%d %d %d %d %d", &terrain->terrain_percent, &terrain->terrain_type, &terrain->clumps,
                        &terrain->spacing, &terrain->base_terrain_type
                    );
                    terrain->clumpiness_factor = 20;
                }
            } else {
                data->terrain = 0;
            }
        }
        fclose(infile);
    }

    infile = fopen(object_file, "r");
    if (infile != 0) {
        fscanf(infile, "%d", &object_num);
        for (long index1 = 0; index1 < object_num; ++index1) {
            fscanf(infile, "%d", &map_id);
            RGE_Object_Data* data = &this->map_info.maps[map_id].object_info;
            fscanf(infile, "%d", &data->object_num);
            if (data->object_num > 0) {
                data->objects = (RGE_Object_Data_Entry*) calloc(data->object_num, sizeof(RGE_Object_Data_Entry));
                for (long object_index = 0; object_index < data->object_num; ++object_index) {
                    RGE_Object_Data_Entry* object = &data->objects[object_index];
                    fscanf(
                        infile, "%d %d %d %d %d %d %d %d %d %d %d %d", &object->obj_id, &object->terrain,
                        &temp_group_flag, &temp_scale_flag, &object->object_number_per_group,
                        &object->object_number_varience, &object->number_of_groups, &object->group_area,
                        &object->player_id, &object->land_id, &object->land_inner_radius, &object->land_outer_radius
                    );
                    object->group_flag = (uchar) temp_group_flag;
                    object->scale_flag = (uchar) temp_scale_flag;
                }
            } else {
                data->objects = 0;
            }
        }
        fclose(infile);
    }
}

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(int infile) : RGE_Random_Map_Module(0, 0, 0) {
    this->world = 0;
    this->map_type = -1;
    this->number_of_players = 0;

    rge_read(infile, &this->map_info, sizeof(RGE_Map_Data));
    if (this->map_info.map_num > 0) {
        this->map_info.maps = (RGE_Map_Data_Entry*) calloc(this->map_info.map_num, sizeof(RGE_Map_Data_Entry));
        rge_read(infile, this->map_info.maps, this->map_info.map_num * sizeof(RGE_Map_Data_Entry));

        for (int index = 0; index < this->map_info.map_num; ++index) {
            RGE_Land_Data* land_data = &this->map_info.maps[index].land_info;
            RGE_Terrain_Data* terrain_data = &this->map_info.maps[index].terrain_info;
            RGE_Object_Data* object_data = &this->map_info.maps[index].object_info;
            RGE_Elevation_Data* elevation_info = &this->map_info.maps[index].elevation_info;

            rge_read(infile, land_data, sizeof(RGE_Land_Data));
            if (land_data->land_num > 0) {
                land_data->land = (RGE_Land_Data_Entry*) calloc(land_data->land_num, sizeof(RGE_Land_Data_Entry));
                rge_read(infile, land_data->land, land_data->land_num * sizeof(RGE_Land_Data_Entry));
            }

            rge_read(infile, terrain_data, sizeof(RGE_Terrain_Data));
            if (terrain_data->terrain_num > 0) {
                terrain_data->terrain =
                    (RGE_Terrain_Data_Entry*) calloc(terrain_data->terrain_num, sizeof(RGE_Terrain_Data_Entry));
                rge_read(infile, terrain_data->terrain, terrain_data->terrain_num * sizeof(RGE_Terrain_Data_Entry));
            }

            rge_read(infile, object_data, sizeof(RGE_Object_Data));
            if (object_data->object_num > 0) {
                object_data->objects =
                    (RGE_Object_Data_Entry*) calloc(object_data->object_num, sizeof(RGE_Object_Data_Entry));
                rge_read(infile, object_data->objects, object_data->object_num * sizeof(RGE_Object_Data_Entry));
            }

            rge_read(infile, elevation_info, sizeof(RGE_Elevation_Data));
            if (elevation_info->elevation_num > 0) {
                elevation_info->elevation =
                    (RGE_Elevation_Data_Entry*) calloc(elevation_info->elevation_num, sizeof(RGE_Elevation_Data_Entry));
                rge_read(
                    infile, elevation_info->elevation, elevation_info->elevation_num * sizeof(RGE_Elevation_Data_Entry)
                );
            }
        }
    }
}

RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller() {
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

uchar RGE_RMM_Database_Controller::save(int outfile) {
    rge_write(outfile, &this->map_info, sizeof(RGE_Map_Data));

    if (this->map_info.map_num > 0) {
        rge_write(outfile, this->map_info.maps, this->map_info.map_num * sizeof(RGE_Map_Data_Entry));

        int map_index = 0;
        for (int index = 0; index < this->map_info.map_num; ++index, ++map_index) {
            RGE_Land_Data* land_data = &this->map_info.maps[map_index].land_info;
            RGE_Terrain_Data* terrain_data = &this->map_info.maps[map_index].terrain_info;
            RGE_Object_Data* object_data = &this->map_info.maps[map_index].object_info;
            RGE_Elevation_Data* elevation_info = &this->map_info.maps[map_index].elevation_info;

            rge_write(outfile, land_data, sizeof(RGE_Land_Data));
            if (land_data->land_num > 0)
                rge_write(outfile, land_data->land, land_data->land_num * sizeof(RGE_Land_Data_Entry));

            rge_write(outfile, terrain_data, sizeof(RGE_Terrain_Data));
            if (terrain_data->terrain_num > 0)
                rge_write(outfile, terrain_data->terrain, terrain_data->terrain_num * sizeof(RGE_Terrain_Data_Entry));

            rge_write(outfile, object_data, sizeof(RGE_Object_Data));
            if (object_data->object_num > 0)
                rge_write(outfile, object_data->objects, object_data->object_num * sizeof(RGE_Object_Data_Entry));

            rge_write(outfile, elevation_info, sizeof(RGE_Elevation_Data));
            if (elevation_info->elevation_num > 0)
                rge_write(
                    outfile, elevation_info->elevation, elevation_info->elevation_num * sizeof(RGE_Elevation_Data_Entry)
                );
        }
    }
    return 1;
}

uchar RGE_RMM_Database_Controller::generate() {
    new RGE_RMM_Terrain_Generator(this->map, this, &this->terrain_info);
    new RGE_RMM_Land_Generator(this->map, this, &this->land_info);
    new RGE_RMM_Object_Generator(this->map, this, this->world, &this->object_info, 1);
    new RGE_RMM_Elevation_Generator(this->map, this, &this->elevation_info);

    return RGE_Random_Map_Module::generate();
}

uchar RGE_RMM_Database_Controller::init(
    RGE_Map* in_map, RGE_Game_World* in_world, uchar type, long player_num, uchar fixed_positions
) {
    this->world = in_world;
    this->map_type = type;
    this->number_of_players = player_num;
    this->update_map_info(in_map);
    this->create_shared_resources();
    this->add_land_module(fixed_positions);
    this->add_terrain_module();
    this->add_object_module();
    this->add_elevation_module();
    return 1;
}

uchar RGE_RMM_Database_Controller::de_init() {
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
    long land_index, long edge, long land_num, RGE_Land_Data_Entry* info
) {
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

    radius2 = (float) (this->map_width - edge * 2) / sqrt((float) land_num);

    if (land_num > 3 && land_num < 7)
        radius2 *= 0.9F;
    else if (land_num >= 7)
        radius2 *= 0.8F;

    bound_square = radius2 * radius2;
    min_x = (long) (this->map_width / 2 - radius2 * 0.9);
    min_y = (long) (this->map_height / 2 - radius2 * 0.9);
    max_x = (long) (this->map_width / 2 + radius2 * 0.9);
    max_y = (long) (this->map_height / 2 + radius2 * 0.9);

    if (min_x <= edge)
        min_x = edge + 1;
    if (min_y <= edge)
        min_y = edge + 1;
    if (max_x >= this->map_width - edge - 1)
        max_x = this->map_width - edge - 2;
    if (max_y >= this->map_height - edge - 1)
        max_y = this->map_height - edge - 2;

    switch (info->placement_type) {
        case 0:
            L->Log(s_calc_land_end_point1);
            end = land_index + land_num;
            if (land_index < end) {
                land_ptr = &this->land_info.land[land_index].y;
                do {
                    land_ptr[-1] = debug_rand(s_rmm_dbct_path, 485) * (this->map_width - edge * 2) / 0x7fff + edge;
                    *land_ptr = debug_rand(s_rmm_dbct_path, 486) * (this->map_height - edge * 2) / 0x7fff + edge;
                    land_ptr += 13;
                    --land_num;
                } while (land_num != 0);
            }
            break;

        case 1:
            L->Log(s_calc_land_end_point2);
            end = land_index + land_num;
            if (land_index < end) {
                land_ptr = &this->land_info.land[land_index].y;
                do {
                    land_ptr[-1] = info->x;
                    *land_ptr = info->y;
                    land_ptr += 13;
                    --land_num;
                } while (land_num != 0);
            }
            break;

        case 2:
            L->Log(s_calc_land_end_point3);
            index = land_index;
            end = land_index + land_num;
            if (index < end) {
                land_ptr = &this->land_info.land[index].y;
                do {
                    do {
                        not_done = 0;
                        x = debug_rand(s_rmm_dbct_path, 508) * (this->map_width - edge * 2) / 0x7fff + edge;
                        y = debug_rand(s_rmm_dbct_path, 509) * (this->map_height - edge * 2) / 0x7fff + edge;

                        if (x > min_x && x < max_x && y > min_y && y < max_y) {
                            not_done = 1;
                        } else {
                            index2 = land_index;
                            // Original 00483825 resets the scan to the first land,
                            // not the current output record (004838FE).
                            prior = &this->land_info.land[land_index].y;
                            if (land_index < index) {
                                do {
                                    dx = x - prior[-1];
                                    if (dx < 0)
                                        dx = -dx;
                                    dy = y - *prior;
                                    if (dy < 0)
                                        dy = -dy;
                                    if ((float) (dx * dx + dy * dy) <= bound_square) {
                                        if (index2 == index - 1) {
                                            long* fallback = &this->land_info.land[index - 1].y;
                                            *fallback = y;
                                            fallback[-1] = x;
                                            L->Log(s_calc_land_xy, index2, x, y);
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

void RGE_RMM_Database_Controller::add_land_module(uchar fixed_positions) {
    RGE_Land_Data* map_land = &this->map_info.maps[this->map_type].land_info;
    long land_tile_num = map_land->grown_land_percent * this->map_width * this->map_height / 100;
    long placement_edge = map_land->land_placement_edge;
    long index;
    long index2 = 0;

    this->land_info.land_num = 0;
    for (index = 0; index < map_land->land_num; ++index) {
        if (map_land->land[index].by_player_flag != 0)
            this->land_info.land_num += this->number_of_players;
        else
            ++this->land_info.land_num;
    }

    this->land_info.base_terrain = (uchar) map_land->base_terrain;
    this->land_info.wall_1_avoidance_line = map_land->map_edge_buffer[0];
    this->land_info.wall_2_avoidance_line = map_land->map_edge_buffer[1];
    this->land_info.wall_3_avoidance_line = this->map_width - map_land->map_edge_buffer[2];
    this->land_info.wall_4_avoidance_line = this->map_height - map_land->map_edge_buffer[3];
    this->land_info.wall_fade = (uchar) map_land->map_edge_fade;

    for (index = 0; index < map_land->land_num; ++index) {
        RGE_Land_Data_Entry* source = &map_land->land[index];
        if (source->by_player_flag != 0) {
            this->calc_land_start(index2, placement_edge, this->number_of_players, source);
            for (long player = 0; player < this->number_of_players; ++player) {
                RGE_Land_Info_Line* land = &this->land_info.land[index2];
                land->terrain_type = source->terrain_type;
                land->area = source->land_avoidance_tiles;
                land->base_size = source->base_square_radius;
                if (source->by_player_flag == 1)
                    land->zone = source->zone;
                else
                    land->zone = (uchar) player;
                land->land_size = source->amount_of_land_used_percent * land_tile_num / (this->number_of_players * 100);
                land->clumpiness_factor = source->clumpiness_factor;
                land->wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
                land->wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
                land->wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
                land->wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
                land->wall_fade = this->land_info.wall_fade;
                ++index2;
            }
        } else {
            RGE_Land_Info_Line* land = &this->land_info.land[index2];
            land->terrain_type = source->terrain_type;
            land->area = source->land_avoidance_tiles;
            land->base_size = source->base_square_radius;
            land->zone = source->zone;
            this->calc_land_start(index2, placement_edge, 1, source);
            land->land_size = source->amount_of_land_used_percent * land_tile_num / 100;
            land->clumpiness_factor = source->clumpiness_factor;
            land->wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
            land->wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
            land->wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
            land->wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
            land->wall_fade = this->land_info.wall_fade;
            ++index2;
        }
    }

    if (fixed_positions == 0)
        return;

    long d2[8];
    long distances[8][8];
    long index1;
    long swap;
    long start_land;
    long other_land = land_tile_num;

    for (index1 = 0; index1 < this->land_info.land_num; ++index1) {
        for (index = 0; index < this->land_info.land_num; ++index) {
            long dx = this->land_info.land[index1].x - this->land_info.land[index].x;
            long dy = this->land_info.land[index1].y - this->land_info.land[index].y;
            d2[index] = dx * dx + dy * dy;
        }
        for (index = 0; index < this->land_info.land_num; ++index)
            distances[index1][index] = index;

        do {
            index2 = 1;
            for (index = 1; index < this->land_info.land_num; ++index) {
                if (d2[index - 1] > d2[index]) {
                    swap = d2[index - 1];
                    d2[index - 1] = d2[index];
                    d2[index] = swap;
                    swap = distances[index1][index - 1];
                    distances[index1][index - 1] = distances[index1][index];
                    distances[index1][index] = swap;
                    index2 = 0;
                }
            }
        } while (index2 == 0);
    }

    long player_teams[8];
    long team_size[8];
    long current_team = 0;
    for (index = 0; index < this->land_info.land_num; ++index)
        player_teams[index] = -1;

    for (index = 0; index < this->land_info.land_num; ++index) {
        if (player_teams[index] == -1) {
            player_teams[index] = current_team;
            team_size[current_team] = 1;
            for (index1 = 0; index1 < this->land_info.land_num; ++index1) {
                if (this->world->players[index + 1]->relation(index1 + 1) == RGE_RELATION_ALLY) {
                    player_teams[index1] = current_team;
                    ++team_size[current_team];
                }
            }
            ++current_team;
        }
    }

    long land_claimed[8];
    for (index = 0; index < this->land_info.land_num; ++index)
        land_claimed[index] = -1;

    for (index1 = 0; index1 < current_team; ++index1) {
        for (index = 0; index < this->land_info.land_num && land_claimed[index] != -1; ++index) {
        }

        long edge = 0;
        long land_wanted = team_size[index1];
        while (edge < team_size[index1]) {
            for (index2 = 0; index2 < land_wanted; ++index2) {
                long candidate = distances[index][index2];
                if (land_claimed[candidate] == -1) {
                    land_claimed[candidate] = index1;
                    break;
                }
            }
            if (index2 < land_wanted) {
                ++edge;
                continue;
            }

            if (land_wanted < this->land_info.land_num)
                ++land_wanted;

            for (index2 = this->land_info.land_num - 1; index2 >= 0; --index2) {
                long candidate = distances[index][index2];
                if (land_claimed[candidate] == -1) {
                    start_land = candidate;
                    break;
                }
            }

            long other_team = -1;
            for (long candidate_index = 0; candidate_index < this->land_info.land_num; ++candidate_index) {
                long candidate = distances[start_land][candidate_index];
                if (land_claimed[candidate] != index1 && land_claimed[candidate] > -1) {
                    other_team = land_claimed[candidate];
                    other_land = candidate;
                    for (long wanted_index = 0; wanted_index < land_wanted; ++wanted_index) {
                        candidate = distances[index][wanted_index];
                        if (land_claimed[candidate] == other_team) {
                            other_team = land_claimed[candidate];
                            other_land = candidate;
                            break;
                        }
                    }
                    break;
                }
            }

            land_claimed[start_land] = other_team;
            land_claimed[other_land] = -1;

            for (index2 = this->land_info.land_num - 1; index2 >= 0; --index2) {
                long candidate = distances[other_team][index2];
                if (land_claimed[candidate] == other_team) {
                    for (long wanted_index = 0; wanted_index < this->land_info.land_num; ++wanted_index) {
                        long replacement = distances[start_land][wanted_index];
                        if (land_claimed[replacement] == -1 && replacement != other_land) {
                            land_claimed[candidate] = -1;
                            land_claimed[replacement] = other_team;
                            break;
                        }
                    }
                }
            }
        }
    }

    long player_hash[8];
    for (index = 0; index < this->land_info.land_num; ++index)
        player_hash[index] = -1;
    for (index = 0; index < this->land_info.land_num; ++index) {
        for (index1 = 0; index1 < this->land_info.land_num; ++index1) {
            if (player_hash[index1] == -1 && player_teams[index1] == land_claimed[index]) {
                player_hash[index1] = index;
                break;
            }
        }
    }

    long tx[8];
    long ty[8];
    for (index = 0; index < this->land_info.land_num; ++index) {
        tx[index] = this->land_info.land[player_hash[index]].x;
        ty[index] = this->land_info.land[player_hash[index]].y;
    }
    for (index = 0; index < this->land_info.land_num; ++index) {
        this->land_info.land[index].x = tx[index];
        this->land_info.land[index].y = ty[index];
    }
}

void RGE_RMM_Database_Controller::add_terrain_module() {
    RGE_Map_Data_Entry* map = this->map_info.maps + this->map_type;
    long land_area = this->map_width * this->map_height * map->land_info.grown_land_percent / 100;

    this->terrain_info.terrain_num = map->terrain_info.terrain_num;
    for (long terrain_index = 0; terrain_index < map->terrain_info.terrain_num; ++terrain_index) {
        RGE_Terrain_Data_Entry& map_terrain = map->terrain_info.terrain[terrain_index];
        RGE_Terrain_Info_Line& terrain = this->terrain_info.terrain[terrain_index];

        terrain.terrain_size = (long) (map_terrain.terrain_percent * land_area * 0.01F);
        terrain.terrain_type = map_terrain.terrain_type;
        terrain.clumps = map_terrain.clumps;
        terrain.base_terrain_type = map_terrain.base_terrain_type;
        terrain.terrain_generated = 0;
        terrain.spacing = map_terrain.spacing;
        terrain.clumpiness_factor = map_terrain.clumpiness_factor;
        terrain.avoid_hot_spots = 1;
    }

    long hot_spot_index = 0;
    for (long land_index = 0; land_index < map->land_info.land_num; ++land_index) {
        RGE_Land_Data_Entry& map_land = map->land_info.land[land_index];
        if (map_land.radius < 0)
            continue;

        if (map_land.by_player_flag == 0) {
            RGE_Terrain_Hot_Spots& hot_spot = this->terrain_info.hot_spots[hot_spot_index];
            hot_spot.x = this->land_info.land[hot_spot_index].x;
            hot_spot.y = this->land_info.land[hot_spot_index].y;
            hot_spot.radius = map_land.radius;
            hot_spot.fade = map_land.fade;
            ++hot_spot_index;
        } else {
            long player_index = 0;
            while (player_index < this->number_of_players) {
                RGE_Terrain_Hot_Spots& hot_spot = this->terrain_info.hot_spots[hot_spot_index];
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

void RGE_RMM_Database_Controller::add_object_module() {
    int object_index = 0;
    RGE_Map_Data_Entry* map = this->map_info.maps + this->map_type;
    this->object_info.object_num = map->object_info.object_num;

    if (map->object_info.object_num > 0) {
        int source_index = 0;
        do {
            this->object_info.objects[object_index].obj_id = map->object_info.objects[source_index].obj_id;
            this->object_info.objects[object_index].terrain = map->object_info.objects[source_index].terrain;
            this->object_info.objects[object_index].group_flag = map->object_info.objects[source_index].group_flag;
            this->object_info.objects[object_index].scale_flag = map->object_info.objects[source_index].scale_flag;
            this->object_info.objects[object_index].object_number_per_group =
                map->object_info.objects[source_index].object_number_per_group;
            this->object_info.objects[object_index].object_number_varience =
                map->object_info.objects[source_index].object_number_varience;
            this->object_info.objects[object_index].number_of_groups =
                map->object_info.objects[source_index].number_of_groups;
            this->object_info.objects[object_index].player_id = map->object_info.objects[source_index].player_id;
            this->object_info.objects[object_index].land_id = map->object_info.objects[source_index].land_id;
            this->object_info.objects[object_index].land_inner_radius =
                map->object_info.objects[source_index].land_inner_radius;
            this->object_info.objects[object_index].land_outer_radius =
                map->object_info.objects[source_index].land_outer_radius;
            this->object_info.objects[object_index].group_area = map->object_info.objects[source_index].group_area;
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
    long index1 = 0;
    if (this->land_info.land_num > 0) {
        RGE_Land_Info_Line* source = this->land_info.land;
        int map_land_index = 0;
        do {
            this->object_info.lands[index1].x = source->x;
            this->object_info.lands[index1].y = source->y;
            this->object_info.lands[index1].id = map->land_info.land[map_land_index].land_id;
            this->object_info.lands[index1].player_id = player;

            if (player > 0 && ++player > this->number_of_players)
                player = 0;
            if (player == 0) {
                ++map_land_index;
                if (map->land_info.land[map_land_index].by_player_flag != 0)
                    player = 1;
            }
            ++index1;
            ++source;
        } while (index1 < this->land_info.land_num);
    }
}

void RGE_RMM_Database_Controller::add_elevation_module() {
    RGE_Land_Data* land_data = &this->map_info.maps[this->map_type].land_info;
    long land_area = this->map_width * land_data->grown_land_percent * this->map_height / 100;

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
    for (long land_index = 0; land_index < land_data->land_num; ++land_index) {
        if (land_data->land[land_index].radius < 0)
            continue;

        if (land_data->land[land_index].by_player_flag != 0) {
            for (long index = 0; index < this->number_of_players; ++index) {
                this->elevation_info.hot_spots[hot_spot_index].x = this->land_info.land[hot_spot_index].x;
                this->elevation_info.hot_spots[hot_spot_index].y = this->land_info.land[hot_spot_index].y;
                this->elevation_info.hot_spots[hot_spot_index].radius = land_data->land[land_index].radius;
                this->elevation_info.hot_spots[hot_spot_index].fade = land_data->land[land_index].fade;
                ++hot_spot_index;
            }
        } else {
            this->elevation_info.hot_spots[hot_spot_index].x = this->land_info.land[hot_spot_index].x;
            this->elevation_info.hot_spots[hot_spot_index].y = this->land_info.land[hot_spot_index].y;
            this->elevation_info.hot_spots[hot_spot_index].radius = land_data->land[land_index].radius;
            this->elevation_info.hot_spots[hot_spot_index].fade = land_data->land[land_index].fade;
            ++hot_spot_index;
        }
    }
    this->elevation_info.hot_spot_num = hot_spot_index;
}
