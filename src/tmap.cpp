
#include "../include/tmap.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/rmm_tdbc.h"
#include "../include/stat_obj.h"
#include "../include/tworld.h"
#include "../include/world_info.h"
#include <stdlib.h>

typedef unsigned char uchar;

extern int __cdecl debug_rand(char*, int);

TRIBE_Map::TRIBE_Map(int p1, RGE_Sound** p2, unsigned char load)
    : RGE_Map(p1, p2, 0),
      old_cliff_x(-1),
      old_cliff_y(-1),
      safe_cliff_x(-1),
      safe_cliff_y(-1),
      old_cliff_direction(-1)
{
    if (load != 0) {
        this->data_load_random_map(p1);
    }

    for (int i = 0; i < 0x100; i++) {
        TRIBE_Master_Cliff_Info& cliff = this->cliff_master_table[i];
        cliff.id = -1;
        cliff.facet = -1;
        cliff.id2 = -1;
        cliff.facet2 = -1;
        cliff.info.info[0] = 0;
        cliff.info.info[1] = 0;
        cliff.info.info[2] = 0;
        cliff.info.info[3] = 0;
        cliff.offset_x = 0.0f;
        cliff.offset_y = 0.0f;
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
    short y0 = y - 1;
    short y1 = y + 1;
    short x0 = x - 1;
    short x1 = x + 1;
    unsigned char changed = 0;
    unsigned char object_found = 0;
    if (x0 < 0)
        x0 = 0;
    if (y0 < 0)
        y0 = 0;
    if (x1 >= this->map_width)
        x1 = (short)this->map_width - 1;
    if (y1 >= this->map_height)
        y1 = (short)this->map_height - 1;

    unsigned char terrain = tile->terrain_type;
    switch (terrain) {
    case 0x0A: {
        RGE_Tile** row_cursor;
        RGE_Tile* row_tile;
        row_tile = this->map_row_offset[y0] + x0;
        row_cursor = this->map_row_offset + y0;
        if (y0 <= y1) {
            int row_count = (int)y1 - (int)y0 + 1;
            do {
                if (x0 <= x1) {
                    RGE_Tile* scan = row_tile;
                    int col_count = (int)x1 - (int)x0 + 1;
                    do {
                        unsigned char nearby = scan->terrain_type;
                        if (nearby != 0x0A && nearby != 0x12)
                            changed = 1;
                        ++scan;
                    } while (--col_count != 0);
                }
                row_tile = row_cursor[1] + x0;
                ++row_cursor;
            } while (--row_count != 0);
        }

        if (changed)
            change_terrain(x, y, 0x12, world);
        break;
    }
    case 0x12: {
        for (RGE_Object_Node* node = tile->objects.list; node != 0;
             node = node->next) {
            RGE_Static_Object* object = node->node;
            if (object->master_obj->id == 0x0F && object->object_state < 8)
                object_found = 1;
        }

        if (!object_found) {
            change_terrain(x, y, 0, world);
            for (short row = y0; row <= y1; ++row) {
                for (short col = x0; col <= x1; ++col) {
                    if (col != x || row != y)
                        this->check_tile_for_forest_change(col, row, world);
                }
            }
        }
        break;
    }
    default:
        break;
    }
}

void TRIBE_Map::change_terrain(short x, short y, unsigned char terrain,
                                RGE_Game_World* world)
{
    RGE_Player* player;
    RGE_Tile* tile;
    unsigned char old_border;
    int col_start;
    short col_end;
    int row_start;
    short row_end;
    short col;

    tile = this->map_row_offset[y] + x;
    old_border = terrain;
    old_border = tile->terrain_type;
    tile->terrain_type = terrain;

    if (world->curr_player <= 0 || world->curr_player >= world->player_num)
        player = 0;
    else
        player = world->players[world->curr_player];

    if (player != 0 && world->game_state != 3)
        player->diam_tile_list.add_node(x, y);

    if (x == 0)
        col_start = 0;
    else
        col_start = x - 1;

    if (y == 0)
        row_start = 0;
    else
        row_start = y - 1;

    col_end = (x == this->map_width - 1) ? x : x + 1;
    row_end = (y == this->map_height - 1) ? y : y + 1;

    y = row_start;
    for (; y <= row_end; ++y) {
        col = col_start;
        for (; col <= col_end; ++col) {
            tile = this->map_row_offset[y] + col;
            old_border = tile->border_type;
            terrain = tile->border_shape;

            this->get_border_type(col, y);

            if (player != 0) {
                if (tile->border_type != old_border ||
                    tile->border_shape != terrain) {
                    if (world->game_state != 3)
                        player->diam_tile_list.add_node(col, y);
                }
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
        do {
            RGE_Static_Object* object = node->node;
            short tid = object->master_obj->id;
            if (tid >= 0x108 && tid <= 0x111)
                return object;
            node = node->next;
        } while (node != 0);
    }

    if (RGE_Object_Node* node = this->map_row_offset[y1 + 1][x1].objects.list) {
        do {
            RGE_Static_Object* object = node->node;
            short tid = object->master_obj->id;
            if (tid >= 0x108 && tid <= 0x111)
                return object;
            node = node->next;
        } while (node != 0);
    }

    if (RGE_Object_Node* node = this->map_row_offset[y1][x1 + 1].objects.list) {
        do {
            RGE_Static_Object* object = node->node;
            short tid = object->master_obj->id;
            if (tid >= 0x108 && tid <= 0x111)
                return object;
            node = node->next;
        } while (node != 0);
    }

    if (RGE_Object_Node* node = this->map_row_offset[y1 + 1][x1 + 1].objects.list) {
        do {
            RGE_Static_Object* object = node->node;
            short tid = object->master_obj->id;
            if (tid >= 0x108 && tid <= 0x111)
                return object;
            node = node->next;
        } while (node != 0);
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
    for (int i = 0; i < 256; ++i) {
        const TRIBE_Master_Cliff_Info& entry = this->cliff_master_table[i];
        if ((entry.id == masterObjId && entry.facet == facet) ||
            (entry.id2 == masterObjId && entry.facet2 == facet)) {
            return entry.info;
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
    int table_index = info.info[0] * 16 + info.info[1] * 4 + info.info[2];
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
                    ->diam_tile_list.add_node(outer + (long)cliff->world_y,
                                               inner + (long)cliff->world_z);
                ++inner;
            } while (inner < 2);
            ++outer;
        } while (outer < 2);

        delete cliff;

        int reverse = this->reverse_cliff_direction(dir);
        cliff_info.info[reverse] = 0;
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

long TRIBE_Map::add_cliff_edge(long x, long y, long facing, long existing,
                               long other_facing)
{
    RGE_Static_Object* cliff = this->find_cliff(x, y);
    TRIBE_Cliff_Info cliff_info = this->get_cliff_info(cliff);

    long possible_facing2;
    long possible_direction1;
    long possible_facing1;
    long possible_direction2;
    possible_direction1 = 0;
    possible_facing2 = -1;
    possible_facing1 = -1;
    possible_direction2 = 0;

    if (cliff_info.info[facing] != 0) {
        if (existing == 0)
            return existing;
        if (existing == cliff_info.info[facing])
            return existing;
    }

    if (cliff != 0) {
        long y_offset = -1;
        do {
            long x_offset = -1;
            do {
                RGE_Game_World* world = this->game_world;
                world->players[world->curr_player]->diam_tile_list.add_node(
                    y_offset + (long)cliff->world_y,
                    x_offset + (long)cliff->world_z);
                ++x_offset;
            } while (x_offset < 2);
            ++y_offset;
        } while (y_offset < 2);

        delete cliff;
    }

    if (other_facing == facing)
        other_facing = -1;

    if (other_facing >= 0) {
        long i = 0;
        do {
            if (i != other_facing) {
                this->remove_cliff_edge(x, y, i);
                cliff_info.info[i] = 0;
            }
            ++i;
        } while (i < 4);
    } else {
        long count = 0;
        long i = 0;
        do {
            if (cliff_info.info[i] != 0 && i != facing)
                ++count;
            ++i;
        } while (i < 4);

        if (count == 2) {
            i = 0;
            do {
                if (cliff_info.info[i] != 0 && i != facing) {
                    if (possible_facing2 < 0) {
                        possible_facing2 = i;
                        possible_direction1 = cliff_info.info[i];
                    } else {
                        possible_facing1 = i;
                        possible_direction2 = cliff_info.info[i];
                    }
                    cliff_info.info[i] = 0;
                }
                ++i;
            } while (i < 4);
        }
    }

    if (existing) {
        cliff_info.info[facing] = existing;

        if (possible_facing2 > -1) {
            cliff_info.info[possible_facing2] = possible_direction1;
            if (!this->check_cliff_valid(cliff_info)) {
                cliff_info.info[possible_facing2] = 0;
                this->remove_cliff_edge(x, y, possible_facing2);
            }
        }

        if (possible_facing1 > -1) {
            cliff_info.info[possible_facing1] = possible_direction2;
            if (!this->check_cliff_valid(cliff_info)) {
                cliff_info.info[possible_facing1] = 0;
                this->remove_cliff_edge(x, y, possible_facing1);
            }
        }

        if (!this->check_cliff_valid(cliff_info)) {
            long i = 0;
            do {
                if (i != facing && cliff_info.info[i] != 0) {
                    this->remove_cliff_edge(x, y, i);
                    cliff_info.info[i] = 0;
                }
                ++i;
            } while (i < 4);
        }
    } else {
        bool found = false;
        existing = 1;
        cliff_info.info[facing] = 1;

        if (possible_facing2 > -1) {
            cliff_info.info[possible_facing2] = possible_direction1;
            if (!this->check_cliff_valid(cliff_info))
                cliff_info.info[possible_facing2] = 0;
            else {
                found = true;
                possible_direction1 = 0;
            }
        }

        if (!found && possible_facing1 > -1) {
            cliff_info.info[possible_facing1] = possible_direction2;
            if (!this->check_cliff_valid(cliff_info))
                cliff_info.info[possible_facing1] = 0;
            else {
                found = true;
                possible_direction2 = 0;
            }
        }

        if (!found && !this->check_cliff_valid(cliff_info)) {
            cliff_info.info[facing] = -1;
            existing = -1;
            found = false;

            if (possible_facing2 > -1) {
                cliff_info.info[possible_facing2] = possible_direction1;
                if (!this->check_cliff_valid(cliff_info))
                    cliff_info.info[possible_facing2] = 0;
                else {
                    found = true;
                    possible_direction1 = 0;
                }
            }

            if (!found && possible_facing1 > -1) {
                cliff_info.info[possible_facing1] = possible_direction2;
                if (!this->check_cliff_valid(cliff_info))
                    cliff_info.info[possible_facing1] = 0;
                else {
                    found = true;
                    possible_direction2 = 0;
                }
            }

            if (!found && !this->check_cliff_valid(cliff_info)) {
                long i = 0;
                do {
                    if (i != facing && cliff_info.info[i] != 0) {
                        this->remove_cliff_edge(x, y, i);
                        cliff_info.info[i] = 0;
                    }
                    ++i;
                } while (i < 4);
            }
        }
    }

    if (possible_direction1 != 0)
        this->remove_cliff_edge(x, y, possible_facing2);
    if (possible_direction2 != 0)
        this->remove_cliff_edge(x, y, possible_facing1);

    this->make_new_cliff(x, y, cliff_info);
    return existing;
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
                    param_2 + (long)cliff->world_y,
                    inner + (long)cliff->world_z);
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
        if (x_start <= x_end) {
            long x = x_start;
            do {
                if (water(map_row_offset[y_start][x].terrain_type)) {
                    if (!do_terrain_brush_check(x, y_start)) {
                        RGE_Map::set_terrain(game_world, (short)x,
                                             (short)y_start, 0, 0, 0);
                    }
                }
                ++x;
            } while (x <= x_end);
        }
    }
}

void TRIBE_Map::tribe_clean_terrain(long x1, long y1, long x2, long y2,
                                    uchar flag, uchar terrain)
{
    uchar change_flag;
    RGE_Tile* tile;
    short up;
    short upper_right;
    short right;
    short lower_right;
    short down;
    short lower_left;
    short left;
    short upper_left;
    short width = (short)this->map_width;
    short up_left_offset = (short)(-1 - width);
    short down_offset = width;
    short up_offset = (short)-width;
    short up_right_offset = (short)(1 - width);
    short down_right_offset = (short)(width + 1);
    short down_left_offset = (short)(width - 1);

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

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

        for (long pass = 0; pass < 2; ++pass) {
            for (long y = y1; y <= y2; ++y) {
                long x = x1;
                tile = this->map_row_offset[y] + x;
                if (x <= x2) {
                    do {
                        if (!this->water(tile->terrain_type)) {
                            up = 0;
                            upper_right = 0;
                            right = 0;
                            lower_right = 0;
                            down = 0;
                            lower_left = 0;
                            left = 0;
                            upper_left = 0;

                            if (y > 0 && this->water((tile[up_offset]).terrain_type))
                                up = 1;
                            if (y < this->map_height - 1 &&
                                this->water((tile[down_offset]).terrain_type))
                                down = 1;
                            if (x > 0 && this->water((tile - 1)->terrain_type))
                                left = 1;
                            if (x < this->map_width - 1 &&
                                this->water((tile + 1)->terrain_type))
                                right = 1;
                            if (y > 0) {
                                if (x > 0 &&
                                    this->water((tile[up_left_offset]).terrain_type))
                                    upper_left = 1;
                                if (x < this->map_width - 1 &&
                                    this->water((tile[up_right_offset]).terrain_type))
                                    upper_right = 1;
                            }
                            if (y < this->map_height - 1) {
                                if (x > 0 &&
                                    this->water((tile[down_left_offset]).terrain_type))
                                    lower_left = 1;
                                if (x < this->map_width - 1 &&
                                    this->water((tile[down_right_offset]).terrain_type))
                                    lower_right = 1;
                            }

                            uchar place = 0;
                            if (pass == 0) {
                                if ((up && down) || (left && right))
                                    place = 1;
                            } else {
                                if (upper_left) {
                                    if ((upper_right && !up) ||
                                        (right && !upper_right) ||
                                        (lower_left && !left) ||
                                        (down && !lower_left))
                                        place = 1;
                                    else if (lower_right && !down && !right)
                                        place = 1;
                                }
                                if (upper_right && !place) {
                                    if ((upper_left && !up) ||
                                        (left && !upper_left) ||
                                        (lower_right && !right) ||
                                        (down && !lower_right) ||
                                        (lower_left && !left && !down))
                                        place = 1;
                                }
                                if (lower_right && !place) {
                                    if ((upper_right && !right) ||
                                        (up && !upper_right) ||
                                        (lower_left && !down) ||
                                        (left && !lower_left) ||
                                        (upper_left && !left && !up))
                                        place = 1;
                                }
                                if (lower_left && !place) {
                                    if ((upper_left && !left) ||
                                        (up && !upper_left) ||
                                        (lower_right && !down) ||
                                        (right && !lower_right) ||
                                        (upper_right && !right && !up))
                                        place = 1;
                                }
                            }

                            if (place) {
                                if (this->water(terrain)) {
                                    if (this->do_terrain_brush_check(x, y))
                                        this->set_terrain(this->game_world,
                                                          (short)x, (short)y,
                                                          terrain, 0, 0);
                                } else {
                                    if (upper_left)
                                        this->set_terrain(this->game_world,
                                            (short)(x - 1), (short)(y - 1),
                                            terrain, 0, 0);
                                    if (up)
                                        this->set_terrain(this->game_world,
                                            (short)x, (short)(y - 1), terrain,
                                            0, 0);
                                    if (upper_right)
                                        this->set_terrain(this->game_world,
                                            (short)(x + 1), (short)(y - 1),
                                            terrain, 0, 0);
                                    if (right)
                                        this->set_terrain(this->game_world,
                                            (short)(x + 1), (short)y, terrain,
                                            0, 0);
                                    if (lower_right)
                                        this->set_terrain(this->game_world,
                                            (short)(x + 1), (short)(y + 1),
                                            terrain, 0, 0);
                                    if (down)
                                        this->set_terrain(this->game_world,
                                            (short)x, (short)(y + 1), terrain,
                                            0, 0);
                                    if (lower_left)
                                        this->set_terrain(this->game_world,
                                            (short)(x - 1), (short)(y + 1),
                                            terrain, 0, 0);
                                    if (left)
                                        this->set_terrain(this->game_world,
                                            (short)(x - 1), (short)y, terrain,
                                            0, 0);
                                }
                                change_flag = 1;
                            }
                        }
                        ++x;
                        ++tile;
                    } while (x <= x2);
                }
            }
        }
    } while (change_flag);

    this->clean_borders(x1, y1, x2, y2, terrain);
    this->set_terrain(0, 0, x1, y1, x2, y2, 0, 0, 0);
}
