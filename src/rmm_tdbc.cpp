
#include "../include/rmm_tdbc.h"
#include "../include/rmm_clif.h"
#include "../include/rmm_shal.h"
#include "../include/map.h"
#include "../include/tribegam.h"
#include "../include/rge_base_game_global.h"
#include "../include/game_globals.h"
#include "../include/debuglog.h"
#include <new.h>

static char s_rmm_tdbc_path[] = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp";
static char s_land_log[] = "Random Map land initilization, rand: %d";
static char s_terrain_log[] = "Random Map terrain initilization, rand: %d";
static char s_object_log[] = "Random Map object initilization, rand: %d";
static char s_shallows_log[] = "Random Map shallows initilization, rand: %d";

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(char* land_file, char* terrain_file, char* object_file, char* map_file)
    : RGE_RMM_Database_Controller(land_file, terrain_file, object_file,
                                  map_file) {
}

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(int infile)
    : RGE_RMM_Database_Controller(infile) {
}

uchar TRIBE_RMM_Database_Controller::init(RGE_Map* in_map, RGE_Game_World* in_world, uchar type, long player_num, uchar fixed_position) {
    RGE_Cliffs_Info cliff_info;

    fixed_position =
        (uchar)(((TRIBE_Game*)rge_base_game)->randomizePositions() == 0);
    this->RGE_RMM_Database_Controller::init(
        in_map, in_world, type, player_num, fixed_position);

    if (debug_rand(s_rmm_tdbc_path, 64) > 0x1fff) {
        long base_cliff_size;
        long base_cliff_length;
        long width = this->map_width;
        if (width <= 72) {
            base_cliff_size = 3;
            base_cliff_length = 10;
        } else if (width <= 96) {
            base_cliff_size = 4;
            base_cliff_length = 12;
        } else if (width <= 120) {
            base_cliff_size = 6;
            base_cliff_length = 14;
        } else if (width <= 144) {
            base_cliff_size = 8;
            base_cliff_length = 16;
        } else if (width <= 200) {
            base_cliff_size = 18;
            base_cliff_length = 20;
        } else if (width <= 250) {
            base_cliff_size = 28;
            base_cliff_length = 20;
        }

        switch (this->map_type) {
        case 0: base_cliff_size = 0; base_cliff_length = 0; break;
        case 1: base_cliff_size -= 5; base_cliff_length -= 6; break;
        case 2: base_cliff_size -= 3; base_cliff_length -= 2; break;
        case 5:
        case 6:
        case 8: base_cliff_length -= 4; break;
        }
        if (base_cliff_length < 3)
            base_cliff_length = 3;

        cliff_info.number_of_cliffs = base_cliff_size;
        cliff_info.number_of_cliffs_variance = 2;
        cliff_info.cliff_terrain_spacing = 2;
        cliff_info.cliff_to_cliff_spacing = 2;
        if (base_cliff_length - 3 <= 0)
            cliff_info.cliff_size_variance = 0;
        else
            cliff_info.cliff_size_variance = (base_cliff_length - 3) / 2;
        cliff_info.average_cliff_size =
            base_cliff_length - cliff_info.cliff_size_variance;

        long count = this->terrain_info.hot_spot_num;
        cliff_info.hot_spot_num = count;
        if (count > 0) {
            for (long index = 0; index < count; ++index) {
                cliff_info.hot_spots[index].x =
                    this->terrain_info.hot_spots[index].x;
                cliff_info.hot_spots[index].y =
                    this->terrain_info.hot_spots[index].y;
                cliff_info.hot_spots[index].radius =
                    this->terrain_info.hot_spots[index].radius;
            }
        }

        if (cliff_info.average_cliff_size > 0 &&
            cliff_info.number_of_cliffs > 0) {
            new RGE_RMM_Cliffs_Generator(this->map, this, cliff_info);
        }
    }
    return 1;
}

uchar TRIBE_RMM_Database_Controller::de_init() {
    this->RGE_RMM_Database_Controller::de_init();
    return 1;
}

void TRIBE_RMM_Database_Controller::add_land_module(uchar fixed_positions) {
    long original_edge =
        this->map_info.maps[this->map_type].land_info.land_placement_edge;
    if ((this->map_type == 5 || this->map_type == 8) &&
        this->map_width < 100) {
        int edge = this->map_width >= 80 ? 0 : -1;
        edge &= -5;
        this->map_info.maps[this->map_type].land_info.land_placement_edge =
            edge + 25;
    }

    this->RGE_RMM_Database_Controller::add_land_module(fixed_positions);
    this->map_info.maps[this->map_type].land_info.land_placement_edge =
        original_edge;

    int minus_one = -1;
    if (this->map_type < 5) {
        if (debug_rand(s_rmm_tdbc_path, 185) < 0x3fff) {
            this->land_info.wall_1_avoidance_line = minus_one;
            for (int i = 0; i < this->land_info.land_num; ++i)
                this->land_info.land[i].wall_1_avoidance_line = minus_one;
        }
        if (debug_rand(s_rmm_tdbc_path, 192) < 0x3fff) {
            this->land_info.wall_2_avoidance_line = minus_one;
            for (int i = 0; i < this->land_info.land_num; ++i)
                this->land_info.land[i].wall_2_avoidance_line = minus_one;
        }
        if (debug_rand(s_rmm_tdbc_path, 199) < 0x3fff) {
            this->land_info.wall_3_avoidance_line = this->map_width;
            for (int i = 0; i < this->land_info.land_num; ++i)
                this->land_info.land[i].wall_3_avoidance_line = this->map_width;
        }
        if (debug_rand(s_rmm_tdbc_path, 206) < 0x3fff) {
            this->land_info.wall_4_avoidance_line = this->map_height;
            for (int i = 0; i < this->land_info.land_num; ++i)
                this->land_info.land[i].wall_4_avoidance_line = this->map_height;
        }
    }

    if (this->map_type == 8) {
        if (debug_rand(s_rmm_tdbc_path, 216) < 0x3fff) {
            this->land_info.wall_1_avoidance_line = minus_one;
            this->land_info.wall_3_avoidance_line = this->map_width;
            for (int i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].wall_1_avoidance_line = minus_one;
                this->land_info.land[i].wall_3_avoidance_line = this->map_width;
            }
        } else {
            this->land_info.wall_2_avoidance_line = minus_one;
            this->land_info.wall_4_avoidance_line = this->map_height;
            for (int i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].wall_2_avoidance_line = minus_one;
                this->land_info.land[i].wall_4_avoidance_line = this->map_height;
            }
        }
    }

    if ((this->map_type >= 2 && this->map_type <= 6) || this->map_type == 8) {
        if (debug_rand(s_rmm_tdbc_path, 241) < 0x3fff) {
            if (debug_rand(s_rmm_tdbc_path, 247) < 0x3fff) {
                for (int i = 0; i < this->land_info.land_num; i += 2)
                    this->land_info.land[i].zone = 0;
            } else {
                for (int i = 0; i < this->land_info.land_num; i += 2)
                    this->land_info.land[i].zone = (uchar)i;
            }
            if (debug_rand(s_rmm_tdbc_path, 255) < 0x3fff) {
                for (int i = 1; i < this->land_info.land_num; i += 2)
                    this->land_info.land[i].zone = 1;
            } else {
                for (int i = 1; i < this->land_info.land_num; i += 2)
                    this->land_info.land[i].zone = (uchar)i;
            }
            this->add_shallows_module();
        } else if (this->map_type == 4) {
            for (int i = 0; i < this->land_info.land_num; ++i)
                this->land_info.land[i].zone = 0;
            this->land_info.base_terrain = 0;
        } else if (this->map_type >= 5) {
            for (int i = 0; i < this->land_info.land_num; ++i)
                this->land_info.land[i].zone = 0;
        }
    }

    if (this->map_type == 5 || this->map_type == 8) {
        int edge = 20;
        if (this->map_width < 100) {
            edge = this->map_width >= 80 ? 0 : -1;
            edge = (edge & -5) + 15;
            if (this->land_info.wall_1_avoidance_line > 0)
                this->land_info.wall_1_avoidance_line = edge;
            if (this->land_info.wall_2_avoidance_line > 0)
                this->land_info.wall_2_avoidance_line = edge;
            if (this->land_info.wall_3_avoidance_line < this->map_width)
                this->land_info.wall_3_avoidance_line = this->map_width - edge;
            if (this->land_info.wall_4_avoidance_line < this->map_height)
                this->land_info.wall_4_avoidance_line = this->map_height - edge;
            for (int i = 0; i < this->land_info.land_num; ++i) {
                RGE_Land_Info_Line& land = this->land_info.land[i];
                if (land.wall_1_avoidance_line > 0) land.wall_1_avoidance_line = edge;
                if (land.wall_2_avoidance_line > 0) land.wall_2_avoidance_line = edge;
                if (land.wall_3_avoidance_line < this->map_width) land.wall_3_avoidance_line = this->map_width - edge;
                if (land.wall_4_avoidance_line < this->map_height) land.wall_4_avoidance_line = this->map_height - edge;
            }
        }
        int diameter = edge + edge;
        int area = (this->map_width - diameter) * (this->map_height - diameter);
        int each = (long)((double)area * DAT_00571f20);
        for (int i = 0; i < this->land_info.land_num; ++i)
            this->land_info.land[i].land_size = each / this->land_info.land_num;
    }

    L->Log(s_land_log, debug_rand(s_rmm_tdbc_path, 311));
}

void TRIBE_RMM_Database_Controller::add_terrain_module() {
    long land_tile_num =
        this->map_info.maps[this->map_type].land_info.grown_land_percent *
        this->map_width * this->map_height / 100;

    this->RGE_RMM_Database_Controller::add_terrain_module();

    float tile_ratio = (float)land_tile_num * DAT_00571f28;
    for (int i = 0; i < this->terrain_info.terrain_num; ++i) {
        if (this->terrain_info.terrain[i].terrain_type != 6) {
            if (tile_ratio > DAT_00571f30)
                this->terrain_info.terrain[i].clumps = (long)
                    ((float)this->terrain_info.terrain[i].clumps * tile_ratio);
        }
    }

    if (debug_rand(s_rmm_tdbc_path, 340) < 0x1fff) {
        for (int i = 0; i < this->terrain_info.terrain_num; ++i) {
            if (this->terrain_info.terrain[i].terrain_type == 13) {
                this->terrain_info.terrain[i].terrain_size *= 3;
                this->terrain_info.terrain[i].clumps *= 3;
                this->terrain_info.terrain[i].avoid_hot_spots = 2;
            } else if (this->terrain_info.terrain[i].terrain_type == 20) {
                this->terrain_info.terrain[i].terrain_size /= 2;
                this->terrain_info.terrain[i].clumps /= 2;
            } else if (this->terrain_info.terrain[i].terrain_type == 19) {
                this->terrain_info.terrain[i].terrain_size /= 2;
                this->terrain_info.terrain[i].clumps /= 2;
            } else if (this->terrain_info.terrain[i].terrain_type == 10) {
                this->terrain_info.terrain[i].terrain_size /= 2;
                this->terrain_info.terrain[i].clumps /= 2;
                this->terrain_info.terrain[i].avoid_hot_spots = 2;
            } else if (this->terrain_info.terrain[i].terrain_type == 6) {
                this->terrain_info.terrain[i].terrain_size *= 2;
                this->terrain_info.terrain[i].avoid_hot_spots = 0;
            }
        }
    } else {
        for (int i = 0; i < this->terrain_info.terrain_num; ++i) {
            if (this->terrain_info.terrain[i].terrain_type == 6)
                this->terrain_info.terrain[i].avoid_hot_spots = 0;
            else {
                if (this->terrain_info.terrain[i].terrain_type == 10 ||
                    this->terrain_info.terrain[i].terrain_type == 13)
                    this->terrain_info.terrain[i].avoid_hot_spots = 2;
            }
        }
    }

    L->Log(s_terrain_log, debug_rand(s_rmm_tdbc_path, 384));
}

void TRIBE_RMM_Database_Controller::add_object_module() {
    int index;

    this->RGE_RMM_Database_Controller::add_object_module();
    debug_rand(s_rmm_tdbc_path, 408);

    if (((TRIBE_Game*)rge_base_game)->startingAge() ==
        TRIBE_Game::NomadAge) {
        for (index = 0; index < this->object_info.object_num; ++index) {
            if (this->object_info.objects[index].obj_id == 0x53)
                this->object_info.objects[index].number_of_groups = 1;
        }
        for (index = 0; index < this->object_info.object_num; ++index) {
            if (this->object_info.objects[index].obj_id == 0x6d)
                this->object_info.objects[index].number_of_groups = 0;
        }
    }

    if (this->map_type == 6) {
        for (index = this->land_info.land_num; index > 0; --index)
            this->land_info.land[index] = this->land_info.land[index - 1];

        int width = this->map_width;
        int edge = width / 6;
        int height = this->map_height;
        this->land_info.land[0].zone = (uchar)this->land_info.land_num;
        this->land_info.land[0].terrain_type = 1;
        this->land_info.land[0].area = 7;
        this->land_info.land[0].base_size = 2;
        this->land_info.land[0].land_size = (long)((double)
            ((height - edge * 2) * (width - edge * 2)) * DAT_00571f38);
        this->land_info.land[0].clumpiness_factor = 10;
        this->land_info.land[0].x = this->map->map_width / 2;
        this->land_info.land[0].y = this->map->map_height / 2;
        this->land_info.land[0].wall_1_avoidance_line = edge;
        this->land_info.land[0].wall_2_avoidance_line = edge;
        this->land_info.land[0].wall_3_avoidance_line = width - edge;
        this->land_info.land[0].wall_4_avoidance_line = height - edge;
        this->land_info.land[0].wall_fade = 10;
        ++this->land_info.land_num;
    }

    if (this->map_type < 2) {
        long count = debug_rand(s_rmm_tdbc_path, 451) * 4 / 0x7fff + 1;
        if (count + this->number_of_players > 10)
            count = 10 - this->number_of_players;

        long adjustment =
            (this->map_width + this->map_height) * count /
            this->land_info.land_num;
        for (index = 0; index < this->land_info.land_num; ++index)
            this->land_info.land[index].land_size -= adjustment;

        for (index = 0; index < count; ++index) {
            this->land_info.land[index + this->land_info.land_num].terrain_type =
                0;
            this->land_info.land[index + this->land_info.land_num].area = 7;
            this->land_info.land[index + this->land_info.land_num].base_size = 3;
            this->land_info.land[index + this->land_info.land_num].zone =
                (uchar)(index + this->land_info.land_num);
            this->land_info.land[index + this->land_info.land_num].land_size =
                (long)((double)(this->map_width + this->map_height) *
                    DAT_00571f40);
            this->land_info.land[index + this->land_info.land_num].
                clumpiness_factor = 10;
            this->land_info.land[index + this->land_info.land_num].
                wall_1_avoidance_line =
                this->land_info.wall_1_avoidance_line;
            this->land_info.land[index + this->land_info.land_num].
                wall_2_avoidance_line =
                this->land_info.wall_2_avoidance_line;
            this->land_info.land[index + this->land_info.land_num].
                wall_3_avoidance_line =
                this->land_info.wall_3_avoidance_line;
            this->land_info.land[index + this->land_info.land_num].
                wall_4_avoidance_line =
                this->land_info.wall_4_avoidance_line;
            this->land_info.land[index + this->land_info.land_num].wall_fade =
                this->land_info.wall_fade;

            long index1 = 0;
            long x;
            long y;
            uchar done;
            do {
                ++index1;
                done = 1;
                x = debug_rand(s_rmm_tdbc_path, 478) *
                    (this->map_width - 16) / 0x7fff + 8;
                y = debug_rand(s_rmm_tdbc_path, 479) *
                    (this->map_height - 16) / 0x7fff + 8;

                for (int prior = 0;
                     prior < this->land_info.land_num && done != 0;
                     ++prior) {
                    long dx = x - this->land_info.land[prior].x;
                    long dy = y - this->land_info.land[prior].y;
                    if (dx * dx + dy * dy < 400)
                        done = 0;
                }
            } while (done == 0 && index1 < 1000);

            if (index1 >= 1000)
                count = index;

            this->land_info.land[index + this->land_info.land_num].x = x;
            this->land_info.land[index + this->land_info.land_num].y = y;

            this->object_info.objects[this->object_info.object_num].terrain = -1;
            this->object_info.objects[this->object_info.object_num].group_flag = 2;
            this->object_info.objects[this->object_info.object_num].scale_flag = 0;
            this->object_info.objects[this->object_info.object_num].
                object_number_per_group = 8;
            this->object_info.objects[this->object_info.object_num].
                object_number_varience = 0;
            this->object_info.objects[this->object_info.object_num].
                number_of_groups = 1;
            this->object_info.objects[this->object_info.object_num].group_area = 4;
            this->object_info.objects[this->object_info.object_num].player_id = 0;
            this->object_info.objects[this->object_info.object_num].land_id =
                index + this->land_info.land_num;
            this->object_info.objects[this->object_info.object_num].
                land_inner_radius = 0;
            this->object_info.objects[this->object_info.object_num].
                land_outer_radius = 26;
            this->object_info.objects[this->object_info.object_num].
                object_exclusion_zone = 0;
            if (debug_rand(s_rmm_tdbc_path, 509) < 0x3fff)
                this->object_info.objects[this->object_info.object_num].obj_id =
                    0x66;
            else
                this->object_info.objects[this->object_info.object_num].obj_id =
                    0x42;
            ++this->object_info.object_num;

            this->object_info.lands[this->object_info.land_num].y = y;
            this->object_info.lands[this->object_info.land_num].x = x;
            this->object_info.lands[this->object_info.land_num].id =
                index + this->land_info.land_num;
            this->object_info.lands[this->object_info.land_num].player_id = 0;
            ++this->object_info.land_num;
        }
        this->land_info.land_num += count;
    }

    for (index = 0; index < this->object_info.object_num; ++index) {
        RGE_Object_Info_Line& object = this->object_info.objects[index];
        if (object.land_id >= 0) {
            switch (object.obj_id) {
            case 0x3b:
            case 0x41:
            case 0x42:
            case 0x66:
                object.object_exclusion_zone = 12;
                break;
            }
        } else if (object.land_id == -2) {
            switch (object.obj_id) {
            case 0x41:
                object.object_exclusion_zone = this->map->map_width / 8;
                break;
            case 0x3b:
            case 0x42:
                object.object_exclusion_zone = this->map->map_width / 6;
                break;
            case 0x66:
                object.object_exclusion_zone = this->map->map_width / 6;
                break;
            }
        }
    }

    L->Log(s_object_log, debug_rand(s_rmm_tdbc_path, 566));
}

void TRIBE_RMM_Database_Controller::add_elevation_module() {
    this->RGE_RMM_Database_Controller::add_elevation_module();
    int random = debug_rand(s_rmm_tdbc_path, 579);
    float scale = (DAT_00571f4c - (float)random * DAT_00571f48) * DAT_00571f50;
    if (this->map_type == 7) scale *= DAT_00571f54;
    for (int i = 0; i < this->elevation_info.elevation_num; ++i)
        this->elevation_info.elevation[i].elevation_size =
            (long)((float)this->elevation_info.elevation[i].elevation_size * scale);
    L->Log(s_terrain_log, debug_rand(s_rmm_tdbc_path, 587));
}

void TRIBE_RMM_Database_Controller::add_shallows_module() {
    RGE_Shallows_Info shallows_info;
    shallows_info.shallows_num = this->land_info.land_num;
    for (int i = 0; i < shallows_info.shallows_num; ++i) {
        shallows_info.shallows[i].x = this->land_info.land[i].x;
        shallows_info.shallows[i].y = this->land_info.land[i].y;
    }
    new RGE_RMM_Shallows_Generator(this->map, this, &shallows_info);
    L->Log(s_shallows_log, debug_rand(s_rmm_tdbc_path, 607));
}

uchar TRIBE_RMM_Database_Controller::generate() {
    uchar ret_num = this->RGE_RMM_Database_Controller::generate();
    for (int row = 0; row < this->map_height; ++row) {
        for (int column = 0; column < this->map_width; ++column) {
            if (this->map_row_offset[row][column].terrain_type == 0x10)
                this->map_row_offset[row][column].terrain_type = 0;
        }
    }
    return ret_num;
}
