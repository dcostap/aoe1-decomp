
#include "../include/tmap.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/rmm_tdbc.h"
#include "../include/stat_obj.h"
#include "../include/tworld.h"
#include "../include/world_info.h"
#include <float.h>
#include <stdlib.h>

typedef unsigned char uchar;

extern int __cdecl debug_rand(char*, int);

TRIBE_Map::TRIBE_Map(int infile, RGE_Sound** sound, unsigned char setup)
    : RGE_Map(infile, sound, 0) {
    if (setup != 0) {
        this->data_load_random_map(infile);
    }

    this->old_cliff_x = -1;
    this->old_cliff_y = -1;
    this->safe_cliff_x = -1;
    this->safe_cliff_y = -1;

    for (int i = 0; i < 0x100; i++) {
        TRIBE_Master_Cliff_Info& cliff = this->cliff_master_table[i];
        cliff.offset_x = 0.0f;
        cliff.offset_y = 0.0f;
        cliff.info.info[0] = 0;
        cliff.info.info[1] = 0;
        cliff.info.info[2] = 0;
        cliff.info.info[3] = 0;
        cliff.id = -1;
        cliff.facet = -1;
        cliff.id2 = -1;
        cliff.facet2 = -1;
    }

    setup_cliff_type(1,0,0,0,0x108,0x10,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,1,0,0,0x108,0x12,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,1,0,0x108,0x11,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,0,1,0x108,0x13,-1,-1,1.5f,1.5f);
    setup_cliff_type(-1,0,0,0,0x10a,0x14,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,-1,0,0,0x109,0x16,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,-1,0,0x10a,0x15,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,0,-1,0x109,0x17,-1,-1,1.5f,1.5f);
    setup_cliff_type(-1,1,0,0,0x10e,0,-1,-1,1.5f,2.0f);
    setup_cliff_type(0,-1,-1,0,0x110,9,-1,-1,1.0f,2.0f);
    setup_cliff_type(0,0,1,-1,0x10c,6,-1,-1,1.0f,1.5f);
    setup_cliff_type(1,0,0,1,0x108,3,-1,-1,1.5f,1.5f);
    setup_cliff_type(1,-1,0,0,0x10b,0xc,-1,-1,2.0f,1.5f);
    setup_cliff_type(0,1,1,0,0x108,0xf,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,-1,1,0x10d,0xe,-1,-1,1.5f,1.0f);
    setup_cliff_type(-1,0,0,-1,0x10f,0xd,-1,-1,2.0f,1.0f);
    setup_cliff_type(1,0,1,0,0x108,4,0x108,5,1.5f,1.5f);
    setup_cliff_type(0,1,0,1,0x108,1,0x108,2,1.5f,1.5f);
    setup_cliff_type(-1,0,-1,0,0x10a,0xb,0x10a,10,1.5f,1.5f);
    setup_cliff_type(0,-1,0,-1,0x109,8,0x109,7,1.5f,1.5f);
}

TRIBE_Map::TRIBE_Map(char* border_tbl, char* overlay_tbl, char* terrain_tbl,
                     char* map_tbl, short TileWid, short TileHgt,
                     short ElevHgt, RGE_Sound** sound)
    : RGE_Map(border_tbl, terrain_tbl, map_tbl, TileWid, TileHgt, ElevHgt,
              sound) {
}

TRIBE_Map::~TRIBE_Map() {
}

void TRIBE_Map::save(int outfile) {
    RGE_Map::save(outfile);
}

void TRIBE_Map::map_generate(RGE_Player* owner, RGE_Game_World* gworld,
                             RGE_Player_Info* player_info,
                             unsigned char* zone_terrain) {
    // The shipped wrapper stores player at +0x8DD4 and world at
    // +0x8DD8 before it delegates to the one-argument overload.
    this->rge_player = owner;
    this->rge_game_world = gworld;
    this->zones = zone_terrain;
    this->map_generate(player_info);
}

void TRIBE_Map::map_generate(RGE_Player_Info* player_info) {
}

void TRIBE_Map::data_load_random_map(int infile) {
    this->random_map = new TRIBE_RMM_Database_Controller(infile);
}

void TRIBE_Map::load_random_map(char* rmm_map_file, char* rmm_land_file,
                                char* rmm_terr_file, char* rmm_obj_file) {
    TRIBE_RMM_Database_Controller* ctrl =
        new TRIBE_RMM_Database_Controller(rmm_land_file, rmm_terr_file,
                                          rmm_obj_file, rmm_map_file);
    this->random_map = ctrl;
}

void TRIBE_Map::check_tile_for_forest_change(short x, short y,
                                              RGE_Game_World* world) {
    RGE_Tile* tile = this->map_row_offset[y] + x;
    short x0 = x - 1;
    short y0 = y - 1;
    short x1 = x + 1;
    short y1 = y + 1;
    unsigned char forest_object = 0;
    unsigned char success = 0;

    if (x0 < 0)
        x0 = 0;
    if (y0 < 0)
        y0 = 0;
    if (x1 >= this->map_width)
        x1 = (short)this->map_width - 1;
    if (y1 >= this->map_height)
        y1 = (short)this->map_height - 1;

    if (tile->terrain_type == 10) {
        for (short row = y0; row <= y1; ++row) {
            for (short col = x0; col <= x1; ++col) {
                unsigned char terrain =
                    this->map_row_offset[row][col].terrain_type;
                if (terrain != 10 && terrain != 18)
                    success = 1;
            }
        }

        if (success)
            this->change_terrain(x, y, 18, world);
    } else if (tile->terrain_type == 18) {
        RGE_Object_Node* node = tile->objects.list;
        while (node != 0) {
            if (node->node->master_obj->object_group == 15 &&
                node->node->object_state < 8)
                forest_object = 1;
            node = node->next;
        }

        if (!forest_object) {
            this->change_terrain(x, y, 0, world);

            for (short row = y0; row <= y1; ++row) {
                for (short col = x0; col <= x1; ++col) {
                    if (col != x || row != y)
                        this->check_tile_for_forest_change(col, row, world);
                }
            }
        }
    }
}

void TRIBE_Map::change_terrain(short map_col, short map_row,
                               unsigned char new_terrain,
                               RGE_Game_World* world) {
    RGE_Tile* tile = this->map_row_offset[map_row] + map_col;
    tile->terrain_type = new_terrain;

    short current_player = world->curr_player;
    RGE_Player* player;
    if (current_player > 0 && current_player < world->player_num)
        player = world->players[current_player];
    else
        player = 0;

    if (player != 0 && world->game_state != 3)
        player->diam_tile_list.add_node(map_col, map_row);

    short start_x;
    short start_y;
    short col1 = map_col;
    short row2 = map_row;

    if (map_col == 0)
        start_x = 0;
    else
        start_x = map_col - 1;

    if (map_row == 0)
        start_y = 0;
    else
        start_y = map_row - 1;

    if (map_col != this->map_width - 1)
        ++col1;
    if (map_row != this->map_height - 1)
        ++row2;

    for (short row = start_y; row <= row2; ++row) {
        for (short col2 = start_x; col2 <= col1; ++col2) {
            tile = this->map_row_offset[row] + col2;
            unsigned char old_border = tile->border_type;
            unsigned char save_border_shape = tile->border_shape;
            this->get_border_type(col2, row);

            if (player != 0 &&
                (tile->border_type != old_border ||
                 tile->border_shape != save_border_shape) &&
                world->game_state != 3) {
                player->diam_tile_list.add_node(col2, row);
            }
        }
    }
}

unsigned char TRIBE_Map::do_terrain_brush(long x, long y, long brush_size,
                                          unsigned char terrain_id) {
    long rad = brush_size;
    long x1 = x - rad;
    long end_x = x + rad;
    long start_y = y - rad;
    long y2 = y + rad;

    if (x1 < 0)
        x1 = 0;
    if (end_x >= map_width)
        end_x = map_width - 1;
    if (start_y < 0)
        start_y = 0;
    if (y2 >= map_height)
        y2 = map_height - 1;

    if (water(terrain_id)) {
        for (long cy = start_y; cy <= y2; cy++) {
            for (long cx = x1; cx <= end_x; cx++) {
                if (do_terrain_brush_check(cx, cy)) {
                    set_terrain(this->game_world, (short)cx, (short)cy,
                                terrain_id, 0, 0);
                }
            }
        }
        return 1;
    }

    for (long cy = start_y; cy <= y2; cy++) {
        for (long cx = x1; cx <= end_x; cx++) {
            set_terrain(this->game_world, (short)cx, (short)cy, terrain_id, 0,
                        0);
        }
    }
    return 1;
}

unsigned char TRIBE_Map::do_terrain_brush_stroke(long x1, long y1, long x2,
                                                 long y2, long brush_size,
                                                 unsigned char terrain_id) {
    RGE_Map::do_terrain_brush_stroke(x1, y1, x2, y2, brush_size, terrain_id);

    if (x1 < x2) {
        x1 -= brush_size;
        x2 += brush_size;
    } else {
        int tmp = x1;
        x1 = x2 - brush_size;
        x2 = tmp + brush_size;
    }

    if (y1 < y2) {
        y1 -= brush_size;
        y2 += brush_size;
    } else {
        int tmp = y1;
        y1 = y2 - brush_size;
        y2 = tmp + brush_size;
    }

    tribe_clean_terrain(x1 - 2, y1 - 2, x2 + 2, y2 + 2, 1, terrain_id);
    return 1;
}

unsigned char TRIBE_Map::do_elevation_brush_stroke(long x1, long y1, long x2,
                                                   long y2, long brush_size,
                                                   unsigned char elevation_height) {
    RGE_Map::do_elevation_brush_stroke(x1, y1, x2, y2, brush_size,
                                       elevation_height);

    if (x1 < x2) {
        x1 -= brush_size + elevation_height;
        x2 += brush_size + elevation_height;
    } else {
        long ox1 = x1;
        x1 = x2 - brush_size - elevation_height;
        x2 = ox1 + brush_size + elevation_height;
    }

    if (y1 < y2) {
        y1 -= brush_size + elevation_height;
        y2 += brush_size + elevation_height;
    } else {
        long oy1 = y1;
        y1 = y2 - brush_size - elevation_height;
        y2 = oy1 + brush_size + elevation_height;
    }

    x1 -= 2;
    y1 -= 2;
    x2 += 2;
    y2 += 2;
    tribe_clean_elevation(x1, y1, x2, y2);
    tribe_clean_terrain(x1, y1, x2, y2, 1, 0);
    return 1;
}

void TRIBE_Map::setup_cliff_type(long r, long d, long l, long u, long id,
                                 long facet, long id2, long facet2,
                                 float offset_x, float offset_y) {
    int info_index;
    int cliff_index;

    info_index = l + (d + r * 4) * 4;
    cliff_index = info_index * 4 + u + 0x55;

    this->cliff_master_table[cliff_index].id = id;
    this->cliff_master_table[cliff_index].facet = facet;
    this->cliff_master_table[cliff_index].id2 = id2;
    this->cliff_master_table[cliff_index].facet2 = facet2;
    this->cliff_master_table[cliff_index].offset_x = offset_x;
    this->cliff_master_table[cliff_index].offset_y = offset_y;
    this->cliff_master_table[cliff_index].info.info[0] = r;
    this->cliff_master_table[cliff_index].info.info[1] = d;
    this->cliff_master_table[cliff_index].info.info[2] = l;
    this->cliff_master_table[cliff_index].info.info[3] = u;
}

RGE_Static_Object* TRIBE_Map::find_cliff(long x, long y) {
    long x1 = x * 3 + 1;
    long y1 = y * 3 + 1;

    if (x1 + 1 > this->map_width)
        return 0;
    if (y1 + 1 > this->map_height)
        return 0;

    if (RGE_Object_Node* node = this->map_row_offset[y1][x1].objects.list) {
        while (node) {
            if (node->node->master_obj->id >= 0x108 &&
                node->node->master_obj->id <= 0x111)
                return node->node;
            node = node->next;
        }
    }

    if (RGE_Object_Node* node = this->map_row_offset[y1 + 1][x1].objects.list) {
        while (node) {
            if (node->node->master_obj->id >= 0x108 &&
                node->node->master_obj->id <= 0x111)
                return node->node;
            node = node->next;
        }
    }

    if (RGE_Object_Node* node =
            this->map_row_offset[y1][x1 + 1].objects.list) {
        while (node) {
            if (node->node->master_obj->id >= 0x108 &&
                node->node->master_obj->id <= 0x111)
                return node->node;
            node = node->next;
        }
    }

    if (RGE_Object_Node* node =
            this->map_row_offset[y1 + 1][x1 + 1].objects.list) {
        while (node) {
            if (node->node->master_obj->id >= 0x108 &&
                node->node->master_obj->id <= 0x111)
                return node->node;
            node = node->next;
        }
    }

    return 0;
}

TRIBE_Cliff_Info TRIBE_Map::get_cliff_info(RGE_Static_Object* cliff) {
    TRIBE_Cliff_Info ret = {0, 0, 0, 0};

    if (cliff == 0)
        return ret;

    int facet = (int)cliff->facet;
    int master_obj_id = (int)cliff->master_obj->id;
    for (int i = 0; i < 0x100; ++i) {
        if ((cliff_master_table[i].id == master_obj_id &&
             cliff_master_table[i].facet == facet) ||
            (cliff_master_table[i].id2 == master_obj_id &&
             cliff_master_table[i].facet2 == facet)) {
            return cliff_master_table[i].info;
        }
    }

    return ret;
}

unsigned char TRIBE_Map::check_cliff_valid(TRIBE_Cliff_Info info) {
    int temp = info.info[0] * 4 + info.info[1];
    temp = info.info[2] + temp * 4;
    temp = info.info[3] + temp * 4;
    return this->cliff_master_table[temp + 0x55].id >= 0;
}

RGE_Static_Object* TRIBE_Map::make_new_cliff(long x, long y,
                                              TRIBE_Cliff_Info info) {
    long info0 = info.info[0];
    long info1 = info.info[1];
    int i = info0 * 16 + info1 * 4 + info.info[2];
    int cliff_index = i * 4 + info.info[3] + 0x55;
    long facet;
    float world_x = (float)(x * 3) +
        this->cliff_master_table[cliff_index].offset_x;
    float world_y = (float)(y * 3) +
        this->cliff_master_table[cliff_index].offset_y;
    RGE_Static_Object* new_cliff;
    long id;

    if (this->cliff_master_table[cliff_index].id2 > -1 &&
        debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tmap.cpp", 0x221) * 2 > 0x7fff) {
        id = this->cliff_master_table[cliff_index].id2;
        facet = this->cliff_master_table[cliff_index].facet2;
    } else {
        id = this->cliff_master_table[cliff_index].id;
        facet = this->cliff_master_table[cliff_index].facet;
    }

    if (id >= 0) {
        new_cliff = this->game_world->players[0]->make_new_object(
            id, world_x, world_y, 0.0f, 0);

        for (long tile_offset = -1; tile_offset < 2; ++tile_offset) {
            for (long j = -1; j < 2; ++j) {
                this->game_world->players[this->game_world->curr_player]
                    ->diam_tile_list.add_node(
                    (int)(tile_offset + (long)(world_x)),
                    (int)(j + (long)(world_y)));
            }
        }

        if (new_cliff != 0)
            new_cliff->facet = (unsigned char)facet;

        static_cast<TRIBE_World*>(this->game_world)->check_destructables(
            0, (short)id, world_x, world_y, 1);
    } else {
        new_cliff = 0;
    }

    return new_cliff;
}

void TRIBE_Map::remove_cliff_edge(long x, long y, long direction) {
    TRIBE_Cliff_Info cliff_info;

    switch (direction) {
    case 0:
        ++x;
        if (x >= this->map_width)
            return;
        break;
    case 2:
        if (x <= 0)
            return;
        --x;
        break;
    case 3:
        if (y <= 0)
            return;
        --y;
        break;
    case 1:
        ++y;
        if (y >= this->map_height)
            return;
        break;
    }

    RGE_Static_Object* cliff = this->find_cliff(x, y);
    cliff_info = this->get_cliff_info(cliff);

    if (cliff != 0) {
        long outer = -1;
        do {
            int inner = -1;
            do {
                this->game_world->players[this->game_world->curr_player]
                    ->diam_tile_list.add_node(outer + (long)cliff->world_x,
                                               inner + (long)cliff->world_y);
                ++inner;
            } while (inner < 2);
            ++outer;
        } while (outer < 2);

        delete cliff;

        cliff_info.info[this->reverse_cliff_direction(direction)] = 0;
        this->make_new_cliff(x, y, cliff_info);
    }
}

long TRIBE_Map::reverse_cliff_direction(long direction) {
    long result = direction + 2;
    if (result >= 4)
        result -= 4;
    return result;
}

long TRIBE_Map::add_cliff_edge(long x, long y, long direction, long facing,
                               long save_direction) {
    RGE_Static_Object* cliff = this->find_cliff(x, y);
    TRIBE_Cliff_Info cliff_info = this->get_cliff_info(cliff);
    long possible_direction1 = 0;
    long possible_facing1 = -1;
    long possible_facing2 = -1;
    long possible_direction2 = 0;
    long ret_num;
    int valid;

    if (cliff_info.info[direction] != 0) {
        if (facing == 0)
            return cliff_info.info[direction];
        if (facing == cliff_info.info[direction])
            return facing;
    }

    if (cliff != 0) {
        for (long i = -1; i < 2; ++i) {
            for (long j = -1; j < 2; ++j) {
                this->game_world->players[this->game_world->curr_player]
                    ->diam_tile_list.add_node(i + (long)cliff->world_x,
                                               j + (long)cliff->world_y);
            }
        }
        delete cliff;
    }

    if (save_direction == direction)
        save_direction = -1;

    if (save_direction >= 0) {
        for (long i = 0; i < 4; ++i) {
            if (i != save_direction) {
                this->remove_cliff_edge(x, y, i);
                cliff_info.info[i] = 0;
            }
        }
    } else {
        long count = 0;
        for (long i = 0; i < 4; ++i) {
            if (cliff_info.info[i] != 0 && i != direction)
                ++count;
        }

        if (count == 2) {
            for (long i = 0; i < 4; ++i) {
                if (cliff_info.info[i] != 0 && i != direction) {
                    if (possible_facing1 < 0) {
                        possible_facing1 = i;
                        possible_direction1 = cliff_info.info[i];
                    } else {
                        possible_facing2 = i;
                        possible_direction2 = cliff_info.info[i];
                    }
                    cliff_info.info[i] = 0;
                }
            }
        }
    }

    if (facing != 0) {
        ret_num = facing;
        cliff_info.info[direction] = facing;

        if (possible_facing1 > -1) {
            cliff_info.info[possible_facing1] = possible_direction1;
            if (!this->check_cliff_valid(cliff_info)) {
                cliff_info.info[possible_facing1] = 0;
                this->remove_cliff_edge(x, y, possible_facing1);
            }
        }

        if (possible_facing2 > -1) {
            cliff_info.info[possible_facing2] = possible_direction2;
            if (!this->check_cliff_valid(cliff_info)) {
                cliff_info.info[possible_facing2] = 0;
                this->remove_cliff_edge(x, y, possible_facing2);
            }
        }

        if (!this->check_cliff_valid(cliff_info)) {
            for (long i = 0; i < 4; ++i) {
                if (i != direction && cliff_info.info[i] != 0) {
                    this->remove_cliff_edge(x, y, i);
                    cliff_info.info[i] = 0;
                }
            }
        }
    } else {
        ret_num = cliff_info.info[direction] = 1;
        valid = 0;

        if (possible_facing1 > -1) {
            cliff_info.info[possible_facing1] = possible_direction1;
            if (!this->check_cliff_valid(cliff_info)) {
                cliff_info.info[possible_facing1] = 0;
            } else {
                valid = 1;
                possible_direction1 = 0;
            }
        }

        if (!valid) {
            valid = 0;
            if (possible_facing2 > -1) {
                cliff_info.info[possible_facing2] = possible_direction2;
                if (!this->check_cliff_valid(cliff_info)) {
                    cliff_info.info[possible_facing2] = 0;
                } else {
                    valid = 1;
                    possible_direction2 = 0;
                }
            }

            if (!valid && !this->check_cliff_valid(cliff_info)) {
                ret_num = cliff_info.info[direction] = -1;
                valid = 0;

                if (possible_facing1 > -1) {
                    cliff_info.info[possible_facing1] = possible_direction1;
                    if (!this->check_cliff_valid(cliff_info)) {
                        cliff_info.info[possible_facing1] = 0;
                    } else {
                        valid = 1;
                        possible_direction1 = 0;
                    }
                }

                if (!valid) {
                    valid = 0;
                    if (possible_facing2 > -1) {
                        cliff_info.info[possible_facing2] =
                            possible_direction2;
                        if (!this->check_cliff_valid(cliff_info)) {
                            cliff_info.info[possible_facing2] = 0;
                        } else {
                            valid = 1;
                            possible_direction2 = 0;
                        }
                    }

                    if (!valid && !this->check_cliff_valid(cliff_info)) {
                        for (long i = 0; i < 4; ++i) {
                            if (i != direction && cliff_info.info[i] != 0) {
                                this->remove_cliff_edge(x, y, i);
                                cliff_info.info[i] = 0;
                            }
                        }
                    }
                }
            }
        }

        if (possible_direction1 != 0)
            this->remove_cliff_edge(x, y, possible_facing1);
        if (possible_direction2 != 0)
            this->remove_cliff_edge(x, y, possible_facing2);
    }

    this->make_new_cliff(x, y, cliff_info);
    return ret_num;
}

void TRIBE_Map::delete_cliff(long x, long y) {
    RGE_Static_Object* cliff = find_cliff(x, y);

    TRIBE_Cliff_Info cliff_info = get_cliff_info(cliff);

    if (cliff != 0) {
        cliff_info = get_cliff_info(cliff);

        for (int i = 0; i < 4; i++) {
            if (cliff_info.info[i] != 0)
                remove_cliff_edge(x, y, i);
        }

        y = -1;
        do {
            int inner = -1;
            do {
                RGE_Game_World* world = this->game_world;
                world->players[world->curr_player]->diam_tile_list.add_node(
                    y + (long)cliff->world_x,
                    inner + (long)cliff->world_y);
                inner++;
            } while (inner < 2);
            y++;
        } while (y < 2);

        delete cliff;
    }
}

unsigned char TRIBE_Map::do_cliff_brush(long x, long y, unsigned char cliff_id,
                                        unsigned char delete_cliff_flag) {
    int cliff_x = x / 3;
    int cliff_y = y / 3;

    if (RGE_Map::do_cliff_brush(x, y, cliff_id, delete_cliff_flag))
        return 1;

    int old_x = this->old_cliff_x;
    this->safe_cliff_x = cliff_x;
    this->safe_cliff_y = cliff_y;

    if (old_x == cliff_x && this->old_cliff_y == cliff_y)
        return 0;

    if (cliff_x * 3 + 2 >= this->map_width ||
        cliff_y * 3 + 2 >= this->map_height ||
        cliff_x < 0 || cliff_y < 0)
        return 0;

    if (old_x != -1 && this->old_cliff_y != -1) {
        int dx = x - old_x * 3;
        int delta_y = y - this->old_cliff_y * 3;

        if (dx >= 3 || dx <= -1) {
            cliff_y = this->old_cliff_y;
        } else if (delta_y < 3 && delta_y > -1) {
            return 0;
        } else {
            cliff_x = old_x;
        }
    }

    if (cliff_x == old_x && cliff_y == this->old_cliff_y)
        return 1;

    if (delete_cliff_flag != 0) {
        this->delete_cliff(cliff_x, cliff_y);
        return 1;
    }

    if (old_x == -1) {
        this->old_cliff_direction = -1;
        this->old_cliff_x = cliff_x;
        this->old_cliff_y = cliff_y;
        return 1;
    }

    long direction;
    if (cliff_x > old_x)
        direction = 0;
    else if (old_x > cliff_x)
        direction = 2;
    else {
        direction = 1;
        if (this->old_cliff_y >= cliff_y)
            direction = 3;
    }

    long facing = this->add_cliff_edge(old_x, this->old_cliff_y,
                                       direction, 0,
                                       this->old_cliff_direction);
    direction = this->reverse_cliff_direction(direction);
    this->old_cliff_direction = direction;
    this->old_cliff_x = cliff_x;
    this->old_cliff_y = cliff_y;
    this->add_cliff_edge(cliff_x, cliff_y, direction, facing, -1);
    return 1;
}

unsigned char TRIBE_Map::do_cliff_brush_stroke(long x1, long y1, long x2,
                                               long y2, unsigned char cliff_id,
                                               unsigned char delete_cliff) {
    if (this->safe_cliff_x != x1 / 3 || this->safe_cliff_y != y1 / 3) {
        this->old_cliff_x = -1;
        this->old_cliff_y = -1;
        this->safe_cliff_x = -1;
        this->safe_cliff_y = -1;
        this->old_cliff_direction = -1;
    }
    RGE_Map::do_cliff_brush_stroke(x1, y1, x2, y2, cliff_id, delete_cliff);
    return 1;
}

unsigned char TRIBE_Map::water(unsigned char terrain) {
    if (terrain == 1)
        return terrain;
    if (terrain == 0x16)
        return 1;
    if (terrain == 4)
        return 1;
    return 0;
}

void TRIBE_Map::clean_borders(long x1, long y1, long x2, long y2,
                              unsigned char terrain_id) {
    long max_y = this->map_height - 1;
    long max_x = this->map_width - 1;

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= this->map_width)
        x2 = max_x;
    if (y2 >= this->map_height)
        y2 = max_y;

    for (; y1 <= y2; ++y1) {
        long x = x1;
        if (x <= x2) {
            for (; x <= x2; ++x) {
                if (this->map_row_offset[y1][x].terrain_type == 2) {
                    bool border = false;
                    if ((y1 > 0 && this->water(this->map_row_offset[y1 - 1][x].terrain_type)) ||
                        (y1 < max_y && this->water(this->map_row_offset[y1 + 1][x].terrain_type)))
                        border = true;
                    if (x > 0) {
                        if (this->water(this->map_row_offset[y1][x - 1].terrain_type) ||
                            (y1 > 0 && this->water(this->map_row_offset[y1 - 1][x - 1].terrain_type)) ||
                            (y1 < max_y && this->water(this->map_row_offset[y1 + 1][x - 1].terrain_type)))
                            border = true;
                    }
                    if (x < max_x) {
                        if (this->water(this->map_row_offset[y1][x + 1].terrain_type) ||
                            (y1 > 0 && this->water(this->map_row_offset[y1 - 1][x + 1].terrain_type)) ||
                            (y1 < max_y && this->water(this->map_row_offset[y1 + 1][x + 1].terrain_type)))
                            border = 1;
                    }
                    if (border == 1)
                        continue;
                    RGE_Map::set_terrain(this->game_world, (short)x,
                                         (short)y1, terrain_id, 0, 0);
                } else if (!this->water(this->map_row_offset[y1][x].terrain_type)) {
                    bool border = false;
                    if ((y1 > 0 && this->water(this->map_row_offset[y1 - 1][x].terrain_type)) ||
                        (y1 < max_y && this->water(this->map_row_offset[y1 + 1][x].terrain_type)))
                        border = true;
                    if (x > 0) {
                        if (this->water(this->map_row_offset[y1][x - 1].terrain_type) ||
                            (y1 > 0 && this->water(this->map_row_offset[y1 - 1][x - 1].terrain_type)) ||
                            (y1 < max_y && this->water(this->map_row_offset[y1 + 1][x - 1].terrain_type)))
                            border = true;
                    }
                    if (x < max_x) {
                        if (this->water(this->map_row_offset[y1][x + 1].terrain_type) ||
                            (y1 > 0 && this->water(this->map_row_offset[y1 - 1][x + 1].terrain_type)) ||
                            (y1 < max_y && this->water(this->map_row_offset[y1 + 1][x + 1].terrain_type)))
                            border = 1;
                    }
                    if (border == 1)
                        this->set_terrain(this->game_world, (short)x,
                                          (short)y1, 2, 0, 0);
                }
            }
        }
    }
}

unsigned char TRIBE_Map::do_terrain_brush_check(long x, long y) {
    RGE_Tile* tile = map_row_offset[y] + x;

    if (x > 0 && tile[-1].tile_type != 0)
        return 0;

    if (x < map_width - 1 && tile[+1].tile_type != 0)
        return 0;

    if (y > 0) {
        if ((tile - map_width)->tile_type != 0)
            return 0;
        if (x > 0 && (tile - map_width)[-1].tile_type != 0)
            return 0;
        if (x < map_width - 1 && (tile - map_width)[+1].tile_type != 0)
            return 0;
    }

    if (y < map_height - 1) {
        if ((tile + map_width)->tile_type != 0)
            return 0;
        if (x > 0 && (tile + map_width)[-1].tile_type != 0)
            return 0;
        if (x < map_width - 1 && (tile + map_width)[+1].tile_type != 0)
            return 0;
    }

    return 1;
}

void TRIBE_Map::tribe_clean_elevation(long x1, long y1, long x2, long y2) {
    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= map_width)
        x2 = map_width - 1;
    if (y2 >= map_height)
        y2 = map_height - 1;

    for (; y1 <= y2; ++y1) {
        for (long x = x1; x <= x2; ++x) {
            if (water(map_row_offset[y1][x].terrain_type)) {
                if (!do_terrain_brush_check(x, y1)) {
                    RGE_Map::set_terrain(game_world, (short)x,
                                         (short)y1, 0, 0, 0);
                }
            }
        }
    }
}

void TRIBE_Map::tribe_clean_terrain(long x1, long y1, long x2, long y2,
                                     unsigned char check_terrain,
                                     unsigned char replacement_terrain) {
    short map_width = (short)this->map_width;
    short offset1 = (short)(-1 - map_width);
    short offset2 = (short)-map_width;
    short offset3 = (short)(1 - map_width);
    short offset5 = (short)(map_width + 1);
    short offset7 = (short)(map_width - 1);

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

    unsigned char change_flag;
    do {
        change_flag = 0;
        if (x1 > 0)
            --x1;
        if (y1 > 0)
            --y1;
        if (x2 < this->map_width - 1)
            ++x2;
        if (y2 < this->map_height - 1)
            ++y2;

        int pass_index = 0;
        do {
            for (int row = (int)y1; row <= y2; ++row) {
                RGE_Tile* til = this->map_row_offset[row] + x1;
                for (int col = (int)x1; col <= x2; ++til, ++col) {
                    if (this->water(til->terrain_type & 0x1f))
                        continue;

                    short place2 = 0;
                    short place3 = 0;
                    short place4 = 0;
                    short place5 = 0;
                    short place6 = 0;
                    short place7 = 0;
                    short place8 = 0;
                    short west = 0;

                    if (row > 0 &&
                        this->water(til[offset2].terrain_type & 0x1f))
                        place3 = 1;
                    if (row < this->map_height - 1 &&
                        this->water(til[map_width].terrain_type & 0x1f))
                        place7 = 1;
                    if (col > 0 &&
                        this->water(til[-1].terrain_type & 0x1f))
                        west = 1;
                    if (col < this->map_width - 1 &&
                        this->water(til[1].terrain_type & 0x1f))
                        place5 = 1;

                    if (row > 0) {
                        if (col > 0 &&
                            this->water(til[offset1].terrain_type & 0x1f))
                            place2 = 1;
                        if (col < this->map_width - 1 &&
                            this->water(til[offset3].terrain_type & 0x1f))
                            place4 = 1;
                    }
                    if (row < this->map_height - 1) {
                        if (col > 0 &&
                            this->water(til[offset7].terrain_type & 0x1f))
                            place8 = 1;
                        if (col < this->map_width - 1 &&
                            this->water(til[offset5].terrain_type & 0x1f))
                            place6 = 1;
                    }

                    unsigned char fix = 0;
                    if (pass_index == 0) {
                        if ((place3 && place7) || (place5 && west))
                            fix = 1;
                    } else {
                        if (place2) {
                            if ((place4 && !place3) ||
                                (place5 && !place4) ||
                                (place8 && !west) ||
                                (place7 && !place8))
                                fix = 1;
                            else if (place6 && !place7 && !place5)
                                fix = 1;
                        }
                        if (place4 && !fix) {
                            if ((place2 && !place3) ||
                                (west && !place2) ||
                                (place6 && !place5) ||
                                (place7 && !place6))
                                fix = 1;
                            else if (place8 && !west && !place7)
                                fix = 1;
                        }
                        if (place6 && !fix) {
                            if ((place4 && !place5) ||
                                (place3 && !place4) ||
                                (place8 && !place7) ||
                                (west && !place8))
                                fix = 1;
                            else if (place2 && !west && !place3)
                                fix = 1;
                        }
                        if (place8 && !fix) {
                            if ((place2 && !west) ||
                                (place3 && !place2) ||
                                (place6 && !place7) ||
                                (place5 && !place6))
                                fix = 1;
                            else if (place4 && !place5 && !place3)
                                fix = 1;
                        }
                    }

                    if (!fix)
                        continue;

                    if (!this->water(replacement_terrain)) {
                        short srow = (short)row;
                        short scol = (short)col;
                        if (place2)
                            RGE_Map::set_terrain(this->game_world, scol - 1,
                                                 srow - 1,
                                                 replacement_terrain, 0, 0);
                        if (place3)
                            RGE_Map::set_terrain(this->game_world, scol,
                                                 srow - 1,
                                                 replacement_terrain, 0, 0);
                        if (place4)
                            RGE_Map::set_terrain(this->game_world, scol + 1,
                                                 srow - 1,
                                                 replacement_terrain, 0, 0);
                        if (place5)
                            RGE_Map::set_terrain(this->game_world, scol + 1,
                                                 srow, replacement_terrain, 0,
                                                 0);
                        if (place6)
                            RGE_Map::set_terrain(this->game_world, scol + 1,
                                                 srow + 1,
                                                 replacement_terrain, 0, 0);
                        if (place7)
                            RGE_Map::set_terrain(this->game_world, scol,
                                                 srow + 1,
                                                 replacement_terrain, 0, 0);
                        if (place8)
                            RGE_Map::set_terrain(this->game_world, scol - 1,
                                                 srow + 1,
                                                 replacement_terrain, 0, 0);
                        if (west)
                            RGE_Map::set_terrain(this->game_world, scol - 1,
                                                 srow, replacement_terrain, 0,
                                                 0);
                    } else {
                        if (!this->do_terrain_brush_check(col, row))
                            continue;
                        RGE_Map::set_terrain(this->game_world, (short)col,
                                             (short)row, replacement_terrain, 0,
                                             0);
                    }
                    change_flag = 1;
                }
            }
            ++pass_index;
        } while (pass_index < 2);
    } while (change_flag != 0);

    this->clean_borders(x1, y1, x2, y2, replacement_terrain);
    RGE_Map::set_terrain((RGE_Player*)0, (RGE_Game_World*)0,
                         (short)x1, (short)y1, (short)x2, (short)y2,
                         0, 0, 0);
}
