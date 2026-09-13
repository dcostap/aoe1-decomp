
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

TRIBE_Map::TRIBE_Map(int p1, RGE_Sound** p2, unsigned char load)
    : RGE_Map(p1, p2, 0)
{
    if (load != 0) {
        this->data_load_random_map(p1);
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

TRIBE_Map::TRIBE_Map(char* param1, char* param2, char* param3, char* param4,
                     short param5, short param6, short param7,
                     RGE_Sound** param8)
    : RGE_Map(param1, param3, param4, param5, param6, param7, param8)
{
}

TRIBE_Map::~TRIBE_Map()
{
}

void TRIBE_Map::save(int p)
{
    RGE_Map::save(p);
}

void TRIBE_Map::map_generate(RGE_Player* player, RGE_Game_World* world,
                             RGE_Player_Info* info, unsigned char* zones_in)
{
    // The shipped wrapper stores world at +0x8DD4 and player at
    // +0x8DD8 before it delegates to the one-argument overload.
    this->rge_player = player;
    this->rge_game_world = world;
    this->zones = zones_in;
    this->map_generate(info);
}

void TRIBE_Map::map_generate(RGE_Player_Info* info)
{
}

void TRIBE_Map::data_load_random_map(int param_1)
{
    this->random_map = new TRIBE_RMM_Database_Controller(param_1);
}

void TRIBE_Map::load_random_map(char* param_1, char* param_2, char* param_3,
                                char* param_4)
{
    TRIBE_RMM_Database_Controller* ctrl =
        new TRIBE_RMM_Database_Controller(param_2, param_3, param_4, param_1);
    this->random_map = ctrl;
}

void TRIBE_Map::check_tile_for_forest_change(short x, short y,
                                              RGE_Game_World* world)
{
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

void TRIBE_Map::change_terrain(short x, short y, unsigned char terrain,
                               RGE_Game_World* world)
{
    RGE_Tile* tile = this->map_row_offset[y] + x;
    tile->terrain_type = terrain;

    short current_player = world->curr_player;
    RGE_Player* player;
    if (current_player > 0 && current_player < world->player_num)
        player = world->players[current_player];
    else
        player = 0;

    if (player != 0 && world->game_state != 3)
        player->diam_tile_list.add_node(x, y);

    short start_x;
    short start_y;
    short end_x = x;
    short end_y = y;

    if (x == 0)
        start_x = 0;
    else
        start_x = x - 1;

    if (y == 0)
        start_y = 0;
    else
        start_y = y - 1;

    if (x != this->map_width - 1)
        ++end_x;
    if (y != this->map_height - 1)
        ++end_y;

    for (short row = start_y; row <= end_y; ++row) {
        for (short col = start_x; col <= end_x; ++col) {
            tile = this->map_row_offset[row] + col;
            unsigned char old_border = tile->border_type;
            unsigned char old_shape = tile->border_shape;
            this->get_border_type(col, row);

            if (player != 0 &&
                (tile->border_type != old_border ||
                 tile->border_shape != old_shape) &&
                world->game_state != 3) {
                player->diam_tile_list.add_node(col, row);
            }
        }
    }
}

unsigned char TRIBE_Map::do_terrain_brush(long x, long y, long r,
                                          unsigned char type)
{
    long rad = r;
    long start_x = x - rad;
    long end_x = x + rad;
    long start_y = y - rad;
    long end_y = y + rad;

    if (start_x < 0)
        start_x = 0;
    if (end_x >= map_width)
        end_x = map_width - 1;
    if (start_y < 0)
        start_y = 0;
    if (end_y >= map_height)
        end_y = map_height - 1;

    if (water(type)) {
        for (long cy = start_y; cy <= end_y; cy++) {
            for (long cx = start_x; cx <= end_x; cx++) {
                if (do_terrain_brush_check(cx, cy)) {
                    set_terrain(this->game_world, (short)cx, (short)cy,
                                type, 0, 0);
                }
            }
        }
        return 1;
    }

    for (long cy = start_y; cy <= end_y; cy++) {
        for (long cx = start_x; cx <= end_x; cx++) {
            set_terrain(this->game_world, (short)cx, (short)cy, type, 0, 0);
        }
    }
    return 1;
}

unsigned char TRIBE_Map::do_terrain_brush_stroke(long p1, long p2, long p3,
                                                 long p4, long p5,
                                                 unsigned char p6)
{
    RGE_Map::do_terrain_brush_stroke(p1, p2, p3, p4, p5, p6);

    if (p1 < p3) {
        p1 -= p5;
        p3 += p5;
    } else {
        int tmp = p1;
        p1 = p3 - p5;
        p3 = tmp + p5;
    }

    if (p2 < p4) {
        p2 -= p5;
        p4 += p5;
    } else {
        int tmp = p2;
        p2 = p4 - p5;
        p4 = tmp + p5;
    }

    tribe_clean_terrain(p1 - 2, p2 - 2, p3 + 2, p4 + 2, 1, p6);
    return 1;
}

unsigned char TRIBE_Map::do_elevation_brush_stroke(long x1, long y1, long x2,
                                                   long y2, long r,
                                                   unsigned char c)
{
    RGE_Map::do_elevation_brush_stroke(x1, y1, x2, y2, r, c);

    if (x1 < x2) {
        x1 -= r + c;
        x2 += r + c;
    } else {
        long ox1 = x1;
        x1 = x2 - r - c;
        x2 = ox1 + r + c;
    }

    if (y1 < y2) {
        y1 -= r + c;
        y2 += r + c;
    } else {
        long oy1 = y1;
        y1 = y2 - r - c;
        y2 = oy1 + r + c;
    }

    x1 -= 2;
    y1 -= 2;
    x2 += 2;
    y2 += 2;
    tribe_clean_elevation(x1, y1, x2, y2);
    tribe_clean_terrain(x1, y1, x2, y2, 1, 0);
    return 1;
}

void TRIBE_Map::setup_cliff_type(long param_1, long param_2, long param_3,
                                 long param_4, long param_5, long param_6,
                                 long param_7, long param_8, float param_9,
                                 float param_10)
{
    int iVar1;
    int idx;

    iVar1 = param_3 + (param_2 + param_1 * 4) * 4;
    idx = iVar1 * 4 + param_4 + 0x55;

    this->cliff_master_table[idx].id = param_5;
    this->cliff_master_table[idx].facet = param_6;
    this->cliff_master_table[idx].id2 = param_7;
    this->cliff_master_table[idx].facet2 = param_8;
    this->cliff_master_table[idx].offset_x = param_9;
    this->cliff_master_table[idx].offset_y = param_10;
    this->cliff_master_table[idx].info.info[0] = param_1;
    this->cliff_master_table[idx].info.info[1] = param_2;
    this->cliff_master_table[idx].info.info[2] = param_3;
    this->cliff_master_table[idx].info.info[3] = param_4;
}

RGE_Static_Object* TRIBE_Map::find_cliff(long param_1, long param_2)
{
    long x1 = param_1 * 3 + 1;
    long y1 = param_2 * 3 + 1;

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

TRIBE_Cliff_Info TRIBE_Map::get_cliff_info(RGE_Static_Object* obj)
{
    TRIBE_Cliff_Info ret = {0, 0, 0, 0};

    if (obj == 0)
        return ret;

    int facet = (int)obj->facet;
    int masterObjId = (int)obj->master_obj->id;
    for (int i = 0; i < 0x100; ++i) {
        if ((cliff_master_table[i].id == masterObjId &&
             cliff_master_table[i].facet == facet) ||
            (cliff_master_table[i].id2 == masterObjId &&
             cliff_master_table[i].facet2 == facet)) {
            return cliff_master_table[i].info;
        }
    }

    return ret;
}

unsigned char TRIBE_Map::check_cliff_valid(TRIBE_Cliff_Info param_1)
{
    int temp = param_1.info[0] * 4 + param_1.info[1];
    temp = param_1.info[2] + temp * 4;
    temp = param_1.info[3] + temp * 4;
    return this->cliff_master_table[temp + 0x55].id >= 0;
}

RGE_Static_Object* TRIBE_Map::make_new_cliff(long x, long y,
                                              TRIBE_Cliff_Info info)
{
    long info0 = info.info[0];
    long info1 = info.info[1];
    int table_index = info0 * 16 + info1 * 4 + info.info[2];
    int cliff_index = table_index * 4 + info.info[3] + 0x55;
    long facet;
    float x_pos = (float)(x * 3) +
        this->cliff_master_table[cliff_index].offset_x;
    float y_pos = (float)(y * 3) +
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
            id, x_pos, y_pos, 0.0f, 0);

        for (long tile_offset = -1; tile_offset < 2; ++tile_offset) {
            for (long j = -1; j < 2; ++j) {
                this->game_world->players[this->game_world->curr_player]
                    ->diam_tile_list.add_node(
                    (int)(tile_offset + (long)(x_pos)),
                    (int)(j + (long)(y_pos)));
            }
        }

        if (new_cliff != 0)
            new_cliff->facet = (unsigned char)facet;

        static_cast<TRIBE_World*>(this->game_world)->check_destructables(
            0, (short)id, x_pos, y_pos, 1);
    } else {
        new_cliff = 0;
    }

    return new_cliff;
}

void TRIBE_Map::remove_cliff_edge(long x, long y, long dir)
{
    TRIBE_Cliff_Info cliff_info;

    switch (dir) {
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

        cliff_info.info[this->reverse_cliff_direction(dir)] = 0;
        this->make_new_cliff(x, y, cliff_info);
    }
}

long TRIBE_Map::reverse_cliff_direction(long dir)
{
    long result = dir + 2;
    if (result >= 4)
        result -= 4;
    return result;
}

long TRIBE_Map::add_cliff_edge(long x, long y, long direction, long facing,
                               long old_direction)
{
    RGE_Static_Object* cliff = this->find_cliff(x, y);
    TRIBE_Cliff_Info cliff_info = this->get_cliff_info(cliff);
    long possible_direction1 = 0;
    long possible_facing1 = -1;
    long possible_facing2 = -1;
    long possible_direction2 = 0;
    long result;
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

    if (old_direction == direction)
        old_direction = -1;

    if (old_direction >= 0) {
        for (long i = 0; i < 4; ++i) {
            if (i != old_direction) {
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
        result = facing;
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
        result = cliff_info.info[direction] = 1;
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
                result = cliff_info.info[direction] = -1;
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
    return result;
}

void TRIBE_Map::delete_cliff(long param_1, long param_2)
{
    RGE_Static_Object* cliff = find_cliff(param_1, param_2);

    TRIBE_Cliff_Info info = get_cliff_info(cliff);

    if (cliff != 0) {
        info = get_cliff_info(cliff);

        for (int i = 0; i < 4; i++) {
            if (info.info[i] != 0)
                remove_cliff_edge(param_1, param_2, i);
        }

        param_2 = -1;
        do {
            int inner = -1;
            do {
                RGE_Game_World* world = this->game_world;
                world->players[world->curr_player]->diam_tile_list.add_node(
                    param_2 + (long)cliff->world_x,
                    inner + (long)cliff->world_y);
                inner++;
            } while (inner < 2);
            param_2++;
        } while (param_2 < 2);

        delete cliff;
    }
}

unsigned char TRIBE_Map::do_cliff_brush(long x, long y, unsigned char a,
                                        unsigned char b)
{
    int cliff_x = x / 3;
    int cliff_y = y / 3;

    if (RGE_Map::do_cliff_brush(x, y, a, b))
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
        int delta_x = x - old_x * 3;
        int delta_y = y - this->old_cliff_y * 3;

        if (delta_x >= 3 || delta_x <= -1) {
            cliff_y = this->old_cliff_y;
        } else if (delta_y < 3 && delta_y > -1) {
            return 0;
        } else {
            cliff_x = old_x;
        }
    }

    if (cliff_x == old_x && cliff_y == this->old_cliff_y)
        return 1;

    if (b != 0) {
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

    long edge = this->add_cliff_edge(old_x, this->old_cliff_y,
                                     direction, 0,
                                     this->old_cliff_direction);
    direction = this->reverse_cliff_direction(direction);
    this->old_cliff_direction = direction;
    this->old_cliff_x = cliff_x;
    this->old_cliff_y = cliff_y;
    this->add_cliff_edge(cliff_x, cliff_y, direction, edge, -1);
    return 1;
}

unsigned char TRIBE_Map::do_cliff_brush_stroke(long a, long b, long c, long d,
                                               unsigned char e,
                                               unsigned char f)
{
    if (this->safe_cliff_x != a / 3 || this->safe_cliff_y != b / 3) {
        this->old_cliff_x = -1;
        this->old_cliff_y = -1;
        this->safe_cliff_x = -1;
        this->safe_cliff_y = -1;
        this->old_cliff_direction = -1;
    }
    RGE_Map::do_cliff_brush_stroke(a, b, c, d, e, f);
    return 1;
}

unsigned char TRIBE_Map::water(unsigned char value)
{
    if (value == 1)
        return value;
    if (value == 0x16)
        return 1;
    if (value == 4)
        return 1;
    return 0;
}

void TRIBE_Map::clean_borders(long x1, long y1, long x2, long y2,
                              unsigned char terrain)
{
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
                                         (short)y1, terrain, 0, 0);
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

unsigned char TRIBE_Map::do_terrain_brush_check(long x, long y)
{
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

void TRIBE_Map::tribe_clean_elevation(long x_start, long y_start,
                                      long x_end, long y_end)
{
    if (x_start < 0)
        x_start = 0;
    if (y_start < 0)
        y_start = 0;
    if (x_end >= map_width)
        x_end = map_width - 1;
    if (y_end >= map_height)
        y_end = map_height - 1;

    for (; y_start <= y_end; ++y_start) {
        for (long x = x_start; x <= x_end; ++x) {
            if (water(map_row_offset[y_start][x].terrain_type)) {
                if (!do_terrain_brush_check(x, y_start)) {
                    RGE_Map::set_terrain(game_world, (short)x,
                                         (short)y_start, 0, 0, 0);
                }
            }
        }
    }
}

void TRIBE_Map::tribe_clean_terrain(long x1, long y1, long x2, long y2,
                                     unsigned char unused,
                                     unsigned char terrain)
{
    short map_width = (short)this->map_width;
    short offset_nw = (short)(-1 - map_width);
    short offset_n = (short)-map_width;
    short offset_ne = (short)(1 - map_width);
    short offset_se = (short)(map_width + 1);
    short offset_sw = (short)(map_width - 1);

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

        int pass = 0;
        do {
            for (int row = (int)y1; row <= y2; ++row) {
                RGE_Tile* tile = this->map_row_offset[row] + x1;
                for (int col = (int)x1; col <= x2; ++tile, ++col) {
                    if (this->water(tile->terrain_type & 0x1f))
                        continue;

                    short north_west = 0;
                    short north = 0;
                    short north_east = 0;
                    short east = 0;
                    short south_east = 0;
                    short south = 0;
                    short south_west = 0;
                    short west = 0;

                    if (row > 0 &&
                        this->water(tile[offset_n].terrain_type & 0x1f))
                        north = 1;
                    if (row < this->map_height - 1 &&
                        this->water(tile[map_width].terrain_type & 0x1f))
                        south = 1;
                    if (col > 0 &&
                        this->water(tile[-1].terrain_type & 0x1f))
                        west = 1;
                    if (col < this->map_width - 1 &&
                        this->water(tile[1].terrain_type & 0x1f))
                        east = 1;

                    if (row > 0) {
                        if (col > 0 &&
                            this->water(tile[offset_nw].terrain_type & 0x1f))
                            north_west = 1;
                        if (col < this->map_width - 1 &&
                            this->water(tile[offset_ne].terrain_type & 0x1f))
                            north_east = 1;
                    }
                    if (row < this->map_height - 1) {
                        if (col > 0 &&
                            this->water(tile[offset_sw].terrain_type & 0x1f))
                            south_west = 1;
                        if (col < this->map_width - 1 &&
                            this->water(tile[offset_se].terrain_type & 0x1f))
                            south_east = 1;
                    }

                    unsigned char fix = 0;
                    if (pass == 0) {
                        if ((north && south) || (east && west))
                            fix = 1;
                    } else {
                        if (north_west) {
                            if ((north_east && !north) ||
                                (east && !north_east) ||
                                (south_west && !west) ||
                                (south && !south_west))
                                fix = 1;
                            else if (south_east && !south && !east)
                                fix = 1;
                        }
                        if (north_east && !fix) {
                            if ((north_west && !north) ||
                                (west && !north_west) ||
                                (south_east && !east) ||
                                (south && !south_east))
                                fix = 1;
                            else if (south_west && !west && !south)
                                fix = 1;
                        }
                        if (south_east && !fix) {
                            if ((north_east && !east) ||
                                (north && !north_east) ||
                                (south_west && !south) ||
                                (west && !south_west))
                                fix = 1;
                            else if (north_west && !west && !north)
                                fix = 1;
                        }
                        if (south_west && !fix) {
                            if ((north_west && !west) ||
                                (north && !north_west) ||
                                (south_east && !south) ||
                                (east && !south_east))
                                fix = 1;
                            else if (north_east && !east && !north)
                                fix = 1;
                        }
                    }

                    if (!fix)
                        continue;

                    if (!this->water(terrain)) {
                        short srow = (short)row;
                        short scol = (short)col;
                        if (north_west)
                            RGE_Map::set_terrain(this->game_world, scol - 1,
                                                 srow - 1, terrain, 0, 0);
                        if (north)
                            RGE_Map::set_terrain(this->game_world, scol,
                                                 srow - 1, terrain, 0, 0);
                        if (north_east)
                            RGE_Map::set_terrain(this->game_world, scol + 1,
                                                 srow - 1, terrain, 0, 0);
                        if (east)
                            RGE_Map::set_terrain(this->game_world, scol + 1,
                                                 srow, terrain, 0, 0);
                        if (south_east)
                            RGE_Map::set_terrain(this->game_world, scol + 1,
                                                 srow + 1, terrain, 0, 0);
                        if (south)
                            RGE_Map::set_terrain(this->game_world, scol,
                                                 srow + 1, terrain, 0, 0);
                        if (south_west)
                            RGE_Map::set_terrain(this->game_world, scol - 1,
                                                 srow + 1, terrain, 0, 0);
                        if (west)
                            RGE_Map::set_terrain(this->game_world, scol - 1,
                                                 srow, terrain, 0, 0);
                    } else {
                        if (!this->do_terrain_brush_check(col, row))
                            continue;
                        RGE_Map::set_terrain(this->game_world, (short)col,
                                             (short)row, terrain, 0, 0);
                    }
                    change_flag = 1;
                }
            }
            ++pass;
        } while (pass < 2);
    } while (change_flag != 0);

    this->clean_borders(x1, y1, x2, y2, terrain);
    RGE_Map::set_terrain((RGE_Player*)0, (RGE_Game_World*)0,
                         (short)x1, (short)y1, (short)x2, (short)y2,
                         0, 0, 0);
}
