// Stub constructors/destructors for types used by TRIBE_World init overrides.
#include "../include/TRIBE_Map.h"
#include "../include/TRIBE_World.h"
#include "../include/TRIBE_RMM_Database_Controller.h"
#include "../include/custom_debug.h"
#include "../include/TRIBE_Command.h"
#include "../include/RGE_Obj_Info.h"
#include "../include/RGE_Command_Create.h"
#include "../include/RGE_Command_Add_Attribute.h"
#include "../include/RGE_Command_Give_Attribute.h"
#include "../include/TRIBE_Command_Give_Attribute.h"
#include "../include/TRIBE_Command_Trade_Attribute.h"
#include "../include/TRIBE_Effects.h"
#include "../include/T_Scenario.h"
#include "../include/RGE_Scenario_Header.h"
#include "../include/TRIBE_Scenario_Header.h"
#include "../include/RGE_Effect.h"
#include "../include/RGE_Effect_Command.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TRIBE_Player.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/TRIBE_Victory_Conditions.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Timeline.h"
#include "../include/TPicture.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void tribe_init_cliff_master_table(TRIBE_Map* map) {
    for (int i = 0; i < 0x100; ++i) {
        map->cliff_master_table[i].id = -1;
        map->cliff_master_table[i].facet = 0;
        map->cliff_master_table[i].id2 = -1;
        map->cliff_master_table[i].facet2 = -1;
        map->cliff_master_table[i].info.info[0] = 0;
        map->cliff_master_table[i].info.info[1] = 0;
        map->cliff_master_table[i].info.info[2] = 0;
        map->cliff_master_table[i].info.info[3] = 0;
        map->cliff_master_table[i].offset_x = 0.0f;
        map->cliff_master_table[i].offset_y = 0.0f;
    }

    map->setup_cliff_type(1, 0, 0, 0, 0x108, 0x10, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(0, 1, 0, 0, 0x108, 0x12, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(0, 0, 1, 0, 0x108, 0x11, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(0, 0, 0, 1, 0x108, 0x13, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(-1, 0, 0, 0, 0x10A, 0x14, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(0, -1, 0, 0, 0x109, 0x16, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(0, 0, -1, 0, 0x10A, 0x15, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(0, 0, 0, -1, 0x109, 0x17, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(-1, 1, 0, 0, 0x10E, 0x00, -1, -1, 1.5f, 2.0f);
    map->setup_cliff_type(0, -1, -1, 0, 0x110, 0x09, -1, -1, 1.0f, 2.0f);
    map->setup_cliff_type(0, 0, 1, -1, 0x10C, 0x06, -1, -1, 1.0f, 1.5f);
    map->setup_cliff_type(1, 0, 0, 1, 0x108, 0x03, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(1, -1, 0, 0, 0x10B, 0x0C, -1, -1, 2.0f, 1.5f);
    map->setup_cliff_type(0, 1, 1, 0, 0x108, 0x0F, -1, -1, 1.5f, 1.5f);
    map->setup_cliff_type(0, 0, -1, 1, 0x10D, 0x0E, -1, -1, 1.5f, 1.0f);
    map->setup_cliff_type(-1, 0, 0, -1, 0x10F, 0x0D, -1, -1, 2.0f, 1.0f);
    map->setup_cliff_type(1, 0, 1, 0, 0x108, 0x04, 0x108, 0x05, 1.5f, 1.5f);
    map->setup_cliff_type(0, 1, 0, 1, 0x108, 0x01, 0x108, 0x02, 1.5f, 1.5f);
    map->setup_cliff_type(-1, 0, -1, 0, 0x10A, 0x0B, 0x10A, 0x0A, 1.5f, 1.5f);
    map->setup_cliff_type(0, -1, 0, -1, 0x109, 0x08, 0x109, 0x07, 1.5f, 1.5f);
}

static int tribe_is_cliff_master_id(short master_id) {
    return (master_id >= 0x108 && master_id <= 0x111) ? 1 : 0;
}

static void tribe_remove_tile_node(RGE_Tile* tile, RGE_Static_Object* obj) {
    if (tile == nullptr || obj == nullptr) {
        return;
    }

    RGE_Object_Node* node = tile->objects.list;
    while (node != nullptr && node->node != obj) {
        node = node->next;
    }

    if (node == nullptr) {
        return;
    }

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        tile->objects.list = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }

    if (tile->objects.number_of_objects > 0) {
        tile->objects.number_of_objects = (short)(tile->objects.number_of_objects - 1);
    }

    free(node);
}

static void tribe_delete_object_now(RGE_Static_Object* obj) {
    if (obj == nullptr) {
        return;
    }

    RGE_Player* owner = obj->owner;
    RGE_Tile* tile = obj->tile;

    if (owner != nullptr) {
        owner->removeObject(obj, (int)obj->sleep_flag, (int)obj->dopple_flag, obj->player_object_node);
    }

    tribe_remove_tile_node(tile, obj);
    obj->player_object_node = nullptr;
    obj->tile = nullptr;
    delete obj;
}

static void tribe_mark_cliff_dirty(TRIBE_Map* map, RGE_Static_Object* obj) {
    if (map == nullptr || obj == nullptr || map->game_world == nullptr || map->game_world->players == nullptr) {
        return;
    }

    short curr_player = map->game_world->curr_player;
    if (curr_player < 0 || curr_player >= map->game_world->player_num) {
        return;
    }

    RGE_Player* player = map->game_world->players[curr_player];
    if (player == nullptr) {
        return;
    }

    long base_x = (long)obj->world_x;
    long base_y = (long)obj->world_y;

    for (long dx = -1; dx < 2; ++dx) {
        for (long dy = -1; dy < 2; ++dy) {
            player->tile_list.add_node((int)(base_x + dx), (int)(base_y + dy));
        }
    }
}

// --- TRIBE_Map ---
TRIBE_Map::TRIBE_Map(int param_1, RGE_Sound** param_2, char param_3)
    : RGE_Map(param_1, param_2, 0) { // Decomp passes 0 (false) for load_map
    CUSTOM_DEBUG_LOG_FMT("TRIBE_Map::TRIBE_Map(binary) param_1=%d param_3=%d", param_1, (int)param_3);

    if (param_3) {
        this->data_load_random_map(param_1);
    }

    this->Game = nullptr;
    this->rge_player = nullptr;
    this->rge_game_world = nullptr;
    this->rge_map_gen_information = nullptr;
    this->zones = nullptr;
    this->old_cliff_x = -1;
    this->old_cliff_y = -1;
    this->safe_cliff_x = -1;
    this->safe_cliff_y = -1;
    this->old_cliff_direction = -1;
    tribe_init_cliff_master_table(this);
}

TRIBE_Map::TRIBE_Map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8)
    : RGE_Map(param_1, param_3, param_4, param_5, param_6, param_7, param_8) {
    // Source of truth: tmap.cpp.decomp
    // Base call order is (param_1, param_3, param_4, ...), not (..., param_2, param_3, ...).
    this->Game = nullptr;
    this->rge_player = nullptr;
    this->rge_game_world = nullptr;
    this->rge_map_gen_information = nullptr;
    this->zones = nullptr;
    this->old_cliff_x = -1;
    this->old_cliff_y = -1;
    this->safe_cliff_x = -1;
    this->safe_cliff_y = -1;
    this->old_cliff_direction = -1;
    tribe_init_cliff_master_table(this);
}

TRIBE_Map::~TRIBE_Map() {}
void TRIBE_Map::data_load_random_map(int p1) {
    // Source of truth: tmap.cpp.decomp @ 0x0050F800.
    this->random_map = (RGE_RMM_Database_Controller*)new TRIBE_RMM_Database_Controller(p1);
}

void TRIBE_Map::load_random_map(char* p1, char* p2, char* p3, char* p4) {
    // Source of truth: tmap.cpp.decomp @ 0x0050F860.
    // Constructor argument order is (param_2, param_3, param_4, param_1).
    this->random_map = (RGE_RMM_Database_Controller*)new TRIBE_RMM_Database_Controller(p2, p3, p4, p1);
}

void TRIBE_Map::check_tile_for_forest_change(short p1, short p2, RGE_Game_World* p3) {
    // Source of truth: tmap.cpp.decomp @ 0x0050F8D0
    if (this->map_row_offset == nullptr || p1 < 0 || p2 < 0 || p1 >= this->map_width || p2 >= this->map_height) {
        return;
    }

    short x0 = (short)(p1 - 1);
    short x1 = (short)(p1 + 1);
    short y0 = (short)(p2 - 1);
    short y1 = (short)(p2 + 1);

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = (short)(this->map_width - 1);
    if (y1 >= this->map_height) y1 = (short)(this->map_height - 1);

    bool has_tree_obj = false;
    bool needs_forest_transition = false;

    uchar terrain = (uchar)(this->map_row_offset[p2][p1].terrain_type & 0x1f);
    if (terrain == 10) {
        for (short y = y0; y <= y1; ++y) {
            for (short x = x0; x <= x1; ++x) {
                uchar t = (uchar)(this->map_row_offset[y][x].terrain_type & 0x1f);
                if (t != 10 && t != 0x12) {
                    needs_forest_transition = true;
                }
            }
        }
        if (needs_forest_transition) {
            this->change_terrain(p1, p2, 0x12, p3);
        }
    } else if (terrain == 0x12) {
        for (RGE_Object_Node* node = this->map_row_offset[p2][p1].objects.list; node != nullptr; node = node->next) {
            if (node->node == nullptr || node->node->master_obj == nullptr) {
                continue;
            }
            if (node->node->master_obj->object_group == 0x0f && node->node->object_state < 8) {
                has_tree_obj = true;
            }
        }

        if (!has_tree_obj) {
            this->change_terrain(p1, p2, 0, p3);
            for (short y = y0; y <= y1; ++y) {
                for (short x = x0; x <= x1; ++x) {
                    if (x != p1 || y != p2) {
                        this->check_tile_for_forest_change(x, y, p3);
                    }
                }
            }
        }
    }
}

void TRIBE_Map::change_terrain(short p1, short p2, uchar p3, RGE_Game_World* p4) {
    // Source of truth: tmap.cpp.decomp @ 0x0050FA90
    if (this->map_row_offset == nullptr || p1 < 0 || p2 < 0 || p1 >= this->map_width || p2 >= this->map_height) {
        return;
    }

    RGE_Tile* center = &this->map_row_offset[p2][p1];
    center->terrain_type = p3;

    RGE_Player* current_player = nullptr;
    if (p4 != nullptr) {
        short curr = p4->curr_player;
        if (curr >= 1 && curr < p4->player_num && p4->players != nullptr) {
            current_player = p4->players[curr];
        }
    }

    if (current_player != nullptr && p4 != nullptr && p4->game_state != '\x03') {
        current_player->diam_tile_list.add_node((int)p1, (int)p2);
    }

    short x0 = (p1 == 0) ? 0 : (short)(p1 - 1);
    short y0 = (p2 == 0) ? 0 : (short)(p2 - 1);
    short x1 = p1;
    short y1 = p2;
    if (p1 != this->map_width - 1) {
        x1 = (short)(p1 + 1);
    }
    if (p2 != this->map_height - 1) {
        y1 = (short)(p2 + 1);
    }

    for (short y = y0; y <= y1; ++y) {
        for (short x = x0; x <= x1; ++x) {
            RGE_Tile* tile = &this->map_row_offset[y][x];
            uchar old_border_type = tile->border_type;
            uchar old_border_shape = tile->border_shape;
            RGE_Map::get_border_type(x, y);

            if (current_player != nullptr && p4 != nullptr && p4->game_state != '\x03') {
                if (tile->border_type != old_border_type || tile->border_shape != old_border_shape) {
                    current_player->diam_tile_list.add_node((int)x, (int)y);
                }
            }
        }
    }
}

void TRIBE_Map::setup_cliff_type(long p1, long p2, long p3, long p4, long p5, long p6, long p7, long p8, float p9, float p10) {
    int index = (int)(p3 + (p2 + p1 * 4) * 4);
    TRIBE_Master_Cliff_Info* info = &this->cliff_master_table[index * 4 + p4 + 0x55];
    info->id = p5;
    info->facet = p6;
    info->id2 = p7;
    info->facet2 = p8;
    info->offset_x = p9;
    info->offset_y = p10;
    info->info.info[0] = p1;
    info->info.info[1] = p2;
    info->info.info[2] = p3;
    info->info.info[3] = p4;
}

uchar TRIBE_Map::water(uchar p1) {
    if (p1 == 1) {
        return p1;
    }
    if (p1 == 0x16) {
        return 1;
    }
    return (uchar)(p1 == 4);
}

void TRIBE_Map::clean_borders(long p1, long p2, long p3, long p4, uchar p5) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;

    if (p1 < 0) p1 = 0;
    if (p2 < 0) p2 = 0;
    if (p3 >= this->map_width) p3 = max_x;
    if (p4 >= this->map_height) p4 = max_y;
    if (p1 > p3 || p2 > p4) {
        return;
    }

    for (long y = p2; y <= p4; ++y) {
        for (long x = p1; x <= p3; ++x) {
            uchar tt = (uchar)(this->map_row_offset[y][x].terrain_type & 0x1f);

            int near_water = 0;
            if (y > 0) {
                if (this->water((uchar)(this->map_row_offset[y - 1][x].terrain_type & 0x1f)) != 0) {
                    near_water = 1;
                }
            }
            if (near_water == 0 && y < max_y) {
                if (this->water((uchar)(this->map_row_offset[y + 1][x].terrain_type & 0x1f)) != 0) {
                    near_water = 1;
                }
            }
            if (near_water == 0 && x > 0) {
                if (this->water((uchar)(this->map_row_offset[y][x - 1].terrain_type & 0x1f)) != 0) {
                    near_water = 1;
                } else if (y > 0 && this->water((uchar)(this->map_row_offset[y - 1][x - 1].terrain_type & 0x1f)) != 0) {
                    near_water = 1;
                } else if (y < max_y && this->water((uchar)(this->map_row_offset[y + 1][x - 1].terrain_type & 0x1f)) != 0) {
                    near_water = 1;
                }
            }
            if (near_water == 0 && x < max_x) {
                if (this->water((uchar)(this->map_row_offset[y][x + 1].terrain_type & 0x1f)) != 0) {
                    near_water = 1;
                } else if (y > 0 && this->water((uchar)(this->map_row_offset[y - 1][x + 1].terrain_type & 0x1f)) != 0) {
                    near_water = 1;
                } else if (y < max_y && this->water((uchar)(this->map_row_offset[y + 1][x + 1].terrain_type & 0x1f)) != 0) {
                    near_water = 1;
                }
            }

            if (tt == 2) {
                if (near_water == 0) {
                    RGE_Map::set_terrain(this->game_world, (short)x, (short)y, p5, 0, 0);
                }
            } else {
                if (this->water(tt) == 0 && near_water != 0) {
                    RGE_Map::set_terrain(this->game_world, (short)x, (short)y, 2, 0, 0);
                }
            }
        }
    }
}

uchar TRIBE_Map::do_terrain_brush(long p1, long p2, long p3, uchar p4) {
    long x0 = p1 - p3;
    long x1 = p1 + p3;
    long y0 = p2 - p3;
    long y1 = p2 + p3;

    if (x0 < 0) x0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y0 < 0) y0 = 0;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    if (this->water(p4) == 0) {
        for (long y = y0; y <= y1; ++y) {
            for (long x = x0; x <= x1; ++x) {
                RGE_Map::set_terrain(this->game_world, (short)x, (short)y, p4, 0, 0);
            }
        }
        return 1;
    }

    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            if (this->do_terrain_brush_check(x, y) != 0) {
                RGE_Map::set_terrain(this->game_world, (short)x, (short)y, p4, 0, 0);
            }
        }
    }

    return 1;
}

uchar TRIBE_Map::do_terrain_brush_stroke(long p1, long p2, long p3, long p4, long p5, uchar p6) {
    RGE_Map::do_terrain_brush_stroke(p1, p2, p3, p4, p5, p6);

    long x0 = p1;
    long x1 = p3;
    if (p1 < p3) {
        x0 = p1 - p5;
        x1 = p3 + p5;
    } else {
        x0 = p3 - p5;
        x1 = p1 + p5;
    }

    long y0 = p2;
    long y1 = p4;
    if (p2 < p4) {
        y0 = p2 - p5;
        y1 = p4 + p5;
    } else {
        y0 = p4 - p5;
        y1 = p2 + p5;
    }

    this->tribe_clean_terrain(x0 - 2, y0 - 2, x1 + 2, y1 + 2, 1, p6);
    return 1;
}

uchar TRIBE_Map::do_elevation_brush(long p1, long p2, long p3, uchar p4) {
    return RGE_Map::do_elevation_brush(p1, p2, p3, p4);
}

uchar TRIBE_Map::do_elevation_brush_stroke(long p1, long p2, long p3, long p4, long p5, uchar p6) {
    RGE_Map::do_elevation_brush_stroke(p1, p2, p3, p4, p5, p6);

    unsigned int v6 = (unsigned int)p6;
    long x0 = 0;
    long x1 = 0;
    if (p1 < p3) {
        x0 = p1 - (p5 + (long)v6);
        x1 = p3 + p5 + (long)v6;
    } else {
        x0 = (p3 - p5) - (long)v6;
        x1 = p1 + p5 + (long)v6;
    }

    long y0 = 0;
    long y1 = 0;
    if (p2 < p4) {
        y0 = p2 - (p5 + (long)v6);
        y1 = p4 + p5 + (long)v6;
    } else {
        y0 = (p4 - p5) - (long)v6;
        y1 = p2 + p5 + (long)v6;
    }

    this->tribe_clean_elevation(x0 - 2, y0 - 2, x1 + 2, y1 + 2);
    this->tribe_clean_terrain(x0 - 2, y0 - 2, x1 + 2, y1 + 2, 1, 0);
    return 1;
}

RGE_Static_Object* TRIBE_Map::find_cliff(long p1, long p2) {
    // Source of truth: tmap.cpp.decomp @ 0x0050FF20
    if (this->map_row_offset == nullptr) {
        return nullptr;
    }

    long tile_x = p1 * 3 + 1;
    long tile_y = p2 * 3 + 1;
    if (tile_x + 1 >= this->map_width || tile_y + 1 >= this->map_height || tile_x < 0 || tile_y < 0) {
        return nullptr;
    }

    for (long y = tile_y; y <= tile_y + 1; ++y) {
        for (long x = tile_x; x <= tile_x + 1; ++x) {
            RGE_Object_Node* node = this->map_row_offset[y][x].objects.list;
            while (node != nullptr) {
                RGE_Static_Object* obj = node->node;
                if (obj != nullptr && obj->master_obj != nullptr) {
                    if (tribe_is_cliff_master_id(obj->master_obj->id) != 0) {
                        return obj;
                    }
                }
                node = node->next;
            }
        }
    }

    return nullptr;
}

TRIBE_Cliff_Info TRIBE_Map::get_cliff_info(RGE_Static_Object* p1) {
    // Source of truth: tmap.cpp.decomp @ 0x00510020
    TRIBE_Cliff_Info ret;
    ret.info[0] = 0;
    ret.info[1] = 0;
    ret.info[2] = 0;
    ret.info[3] = 0;

    if (p1 == nullptr || p1->master_obj == nullptr) {
        return ret;
    }

    long master_id = (long)p1->master_obj->id;
    long facet = (long)p1->facet;
    for (int i = 0; i < 0x100; ++i) {
        const TRIBE_Master_Cliff_Info* info = &this->cliff_master_table[i];
        if ((info->id == master_id && info->facet == facet) ||
            (info->id2 == master_id && info->facet2 == facet)) {
            ret = info->info;
            return ret;
        }
    }

    return ret;
}

uchar TRIBE_Map::check_cliff_valid(TRIBE_Cliff_Info p1) {
    // Source of truth: tmap.cpp.decomp @ 0x005100D0
    long index = p1.info[3] + (p1.info[2] + (p1.info[1] + p1.info[0] * 4) * 4) * 4 + 0x55;
    return (uchar)(this->cliff_master_table[index].id >= 0);
}

RGE_Static_Object* TRIBE_Map::make_new_cliff(long p1, long p2, TRIBE_Cliff_Info p3) {
    // Source of truth: tmap.cpp.decomp @ 0x00510110
    long table_index = p3.info[2] + (p3.info[1] + p3.info[0] * 4) * 4;
    TRIBE_Master_Cliff_Info* table = &this->cliff_master_table[table_index * 4 + p3.info[3] + 0x55];

    float world_x = (float)(p1 * 3) + table->offset_x;
    float world_y = (float)(p2 * 3) + table->offset_y;

    long object_id = table->id;
    long facet = table->facet;
    if (table->id2 >= 0) {
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\tmap.cpp", 0x221);
        if ((r * 2) > 0x7fff) {
            object_id = table->id2;
            facet = table->facet2;
        }
    }

    if (object_id < 0 || this->game_world == nullptr || this->game_world->players == nullptr ||
        this->game_world->player_num <= 0 || this->game_world->players[0] == nullptr) {
        return nullptr;
    }

    RGE_Static_Object* new_cliff = this->game_world->players[0]->make_new_object(object_id, world_x, world_y, 0.0f, 0);

    if (new_cliff != nullptr) {
        long world_x_i = (long)world_x;
        long world_y_i = (long)world_y;
        if (this->game_world->curr_player >= 0 && this->game_world->curr_player < this->game_world->player_num &&
            this->game_world->players[this->game_world->curr_player] != nullptr) {
            RGE_Player* cur_player = this->game_world->players[this->game_world->curr_player];
            for (long dx = -1; dx < 2; ++dx) {
                for (long dy = -1; dy < 2; ++dy) {
                    cur_player->tile_list.add_node((int)(world_x_i + dx), (int)(world_y_i + dy));
                }
            }
        }
        new_cliff->facet = (uchar)facet;
    }

    TRIBE_World* world = (TRIBE_World*)this->game_world;
    if (world != nullptr) {
        world->check_destructables(0, (short)object_id, world_x, world_y, 1);
    }

    return new_cliff;
}

void TRIBE_Map::remove_cliff_edge(long p1, long p2, long p3) {
    // Source of truth: tmap.cpp.decomp @ 0x005102A0
    switch (p3) {
    case 0:
        p1 = p1 + 1;
        if (p1 >= this->map_width) {
            return;
        }
        break;
    case 1:
        p2 = p2 + 1;
        if (p2 >= this->map_height) {
            return;
        }
        break;
    case 2:
        if (p1 <= 0) {
            return;
        }
        p1 = p1 - 1;
        break;
    case 3:
        if (p2 <= 0) {
            return;
        }
        p2 = p2 - 1;
        break;
    default:
        break;
    }

    RGE_Static_Object* cliff = this->find_cliff(p1, p2);
    TRIBE_Cliff_Info cliff_info = this->get_cliff_info(cliff);
    if (cliff != nullptr) {
        tribe_mark_cliff_dirty(this, cliff);
        tribe_delete_object_now(cliff);

        long reverse = this->reverse_cliff_direction(p3);
        cliff_info.info[reverse] = 0;
        this->make_new_cliff(p1, p2, cliff_info);
    }
}

long TRIBE_Map::reverse_cliff_direction(long p1) {
    // Source of truth: tmap.cpp.decomp @ 0x00510410
    long out = p1 + 2;
    if (out > 3) {
        out = p1 - 2;
    }
    return out;
}

long TRIBE_Map::add_cliff_edge(long p1, long p2, long p3, long p4, long p5) {
    // Source of truth: tmap.cpp.decomp @ 0x00510430
    RGE_Static_Object* cliff = this->find_cliff(p1, p2);
    TRIBE_Cliff_Info cliff_info = this->get_cliff_info(cliff);

    long existing_direction = cliff_info.info[p3];
    long possible_direction1 = 0;
    long possible_facing2 = -1;
    long local_18 = -1;
    long possible_direction2 = 0;

    if (existing_direction != 0) {
        if (p4 == 0) {
            return existing_direction;
        }
        if (p4 == existing_direction) {
            return p4;
        }
    }

    if (cliff != nullptr) {
        tribe_mark_cliff_dirty(this, cliff);
        tribe_delete_object_now(cliff);
    }

    if (p5 == p3) {
        p5 = -1;
    }

    if (p5 < 0) {
        int edge_count = 0;
        for (int i = 0; i < 4; ++i) {
            if (i != p3 && cliff_info.info[i] != 0) {
                edge_count = edge_count + 1;
            }
        }

        if (edge_count == 2) {
            for (int i = 0; i < 4; ++i) {
                long direction = cliff_info.info[i];
                if (direction != 0 && i != p3) {
                    if (possible_facing2 < 0) {
                        possible_facing2 = i;
                        possible_direction1 = direction;
                    } else {
                        local_18 = i;
                        possible_direction2 = direction;
                    }
                    cliff_info.info[i] = 0;
                }
            }
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            if (i != p5) {
                this->remove_cliff_edge(p1, p2, i);
                cliff_info.info[i] = 0;
            }
        }
    }

    if (p4 == 0) {
        p4 = 1;
        bool valid = false;
        cliff_info.info[p3] = 1;

        if (possible_facing2 >= 0) {
            cliff_info.info[possible_facing2] = possible_direction1;
            if (this->check_cliff_valid(cliff_info) == 0) {
                cliff_info.info[possible_facing2] = 0;
            } else {
                valid = true;
                possible_direction1 = 0;
            }
        }

        if (!valid) {
            valid = false;
            if (local_18 >= 0) {
                cliff_info.info[local_18] = possible_direction2;
                if (this->check_cliff_valid(cliff_info) == 0) {
                    cliff_info.info[local_18] = 0;
                } else {
                    valid = true;
                    possible_direction2 = 0;
                }
            }

            if (!valid && this->check_cliff_valid(cliff_info) == 0) {
                cliff_info.info[p3] = -1;
                p4 = -1;
                valid = false;

                if (possible_facing2 >= 0) {
                    cliff_info.info[possible_facing2] = possible_direction1;
                    if (this->check_cliff_valid(cliff_info) == 0) {
                        cliff_info.info[possible_facing2] = 0;
                    } else {
                        valid = true;
                        possible_direction1 = 0;
                    }
                }

                if (!valid) {
                    valid = false;
                    if (local_18 >= 0) {
                        cliff_info.info[local_18] = possible_direction2;
                        if (this->check_cliff_valid(cliff_info) == 0) {
                            cliff_info.info[local_18] = 0;
                        } else {
                            valid = true;
                            possible_direction2 = 0;
                        }
                    }

                    if (!valid && this->check_cliff_valid(cliff_info) == 0) {
                        for (int i = 0; i < 4; ++i) {
                            if (i != p3 && cliff_info.info[i] != 0) {
                                this->remove_cliff_edge(p1, p2, i);
                                cliff_info.info[i] = 0;
                            }
                        }
                    }
                }
            }
        }

        if (possible_direction1 != 0) {
            this->remove_cliff_edge(p1, p2, possible_facing2);
        }
        if (possible_direction2 != 0) {
            this->remove_cliff_edge(p1, p2, local_18);
        }
    } else {
        cliff_info.info[p3] = p4;

        if (possible_facing2 >= 0) {
            cliff_info.info[possible_facing2] = possible_direction1;
            if (this->check_cliff_valid(cliff_info) == 0) {
                cliff_info.info[possible_facing2] = 0;
                this->remove_cliff_edge(p1, p2, possible_facing2);
            }
        }

        if (local_18 >= 0) {
            cliff_info.info[local_18] = possible_direction2;
            if (this->check_cliff_valid(cliff_info) == 0) {
                cliff_info.info[local_18] = 0;
                this->remove_cliff_edge(p1, p2, local_18);
            }
        }

        if (this->check_cliff_valid(cliff_info) == 0) {
            for (int i = 0; i < 4; ++i) {
                if (i != p3 && cliff_info.info[i] != 0) {
                    this->remove_cliff_edge(p1, p2, i);
                    cliff_info.info[i] = 0;
                }
            }
        }
    }

    this->make_new_cliff(p1, p2, cliff_info);
    return p4;
}

uchar TRIBE_Map::do_cliff_brush(long p1, long p2, uchar p3, uchar p4) {
    // Source of truth: tmap.cpp.decomp @ 0x00510A50
    long cliff_x = p1 / 3;
    long cliff_y = p2 / 3;

    if (RGE_Map::do_cliff_brush(p1, p2, p3, p4) != 0) {
        return 1;
    }

    this->safe_cliff_x = cliff_x;
    this->safe_cliff_y = cliff_y;

    if ((this->old_cliff_x == cliff_x && this->old_cliff_y == cliff_y) ||
        (cliff_x * 3 + 2 >= this->map_width) || (cliff_y * 3 + 2 >= this->map_height) ||
        cliff_x < 0 || cliff_y < 0) {
        return 0;
    }

    long use_x = cliff_x;
    long use_y = cliff_y;
    if (this->old_cliff_x != -1 && this->old_cliff_y != -1) {
        long delta_x = p1 - this->old_cliff_x * 3;
        long delta_y = p2 - this->old_cliff_y * 3;
        if (delta_x >= 0 && delta_x < 3) {
            if (delta_y >= 0 && delta_y < 3) {
                return 0;
            }
            use_x = this->old_cliff_x;
        } else {
            use_y = this->old_cliff_y;
        }
    }

    if (this->old_cliff_x == use_x && this->old_cliff_y == use_y) {
        return 1;
    }

    if (p4 != 0) {
        this->delete_cliff(use_x, use_y);
        return 1;
    }

    if (this->old_cliff_x == -1) {
        this->old_cliff_direction = -1;
        this->old_cliff_x = use_x;
        this->old_cliff_y = use_y;
        return 1;
    }

    long direction = 0;
    if (this->old_cliff_x < use_x) {
        direction = 0;
    } else if (use_x < this->old_cliff_x) {
        direction = 2;
    } else {
        direction = (use_y > this->old_cliff_y) ? 1 : 3;
    }

    long new_dir = this->add_cliff_edge(this->old_cliff_x, this->old_cliff_y, direction, 0, this->old_cliff_direction);
    long reverse = this->reverse_cliff_direction(direction);

    this->old_cliff_direction = reverse;
    this->old_cliff_x = use_x;
    this->old_cliff_y = use_y;
    this->add_cliff_edge(use_x, use_y, reverse, new_dir, -1);

    return 1;
}

uchar TRIBE_Map::do_cliff_brush_stroke(long p1, long p2, long p3, long p4, uchar p5, uchar p6) {
    if ((this->safe_cliff_x != p1 / 3) || (this->safe_cliff_y != p2 / 3)) {
        this->old_cliff_x = -1;
        this->old_cliff_y = -1;
        this->safe_cliff_x = -1;
        this->safe_cliff_y = -1;
        this->old_cliff_direction = -1;
    }

    RGE_Map::do_cliff_brush_stroke(p1, p2, p3, p4, p5, p6);
    return 1;
}

void TRIBE_Map::map_generate(RGE_Player* p1, RGE_Game_World* p2, RGE_Player_Info* p3, uchar* p4) {
    this->rge_game_world = p2;
    this->rge_player = p1;
    this->zones = p4;
    this->map_generate(p3);
}

void TRIBE_Map::map_generate(RGE_Player_Info* p1) {
    (void)p1;
    // Source of truth: tmap.cpp.decomp @ 0x0050F7F0 (intentional no-op).
}

void TRIBE_Map::save(int p1) {
    RGE_Map::save(p1);
}

void TRIBE_Map::delete_cliff(long p1, long p2) {
    // Source of truth: tmap.cpp.decomp @ 0x00510960
    RGE_Static_Object* cliff = this->find_cliff(p1, p2);
    TRIBE_Cliff_Info cliff_info = this->get_cliff_info(cliff);
    if (cliff == nullptr) {
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (cliff_info.info[i] != 0) {
            this->remove_cliff_edge(p1, p2, i);
        }
    }

    tribe_mark_cliff_dirty(this, cliff);
    tribe_delete_object_now(cliff);
}

uchar TRIBE_Map::do_terrain_brush_check(long p1, long p2) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }
    if (p1 < 0 || p2 < 0 || p1 >= this->map_width || p2 >= this->map_height) {
        return 0;
    }

    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;

    if ((p1 > 0) && (this->map_row_offset[p2][p1 - 1].tile_type != 0)) {
        return 0;
    }
    if ((p1 < max_x) && (this->map_row_offset[p2][p1 + 1].tile_type != 0)) {
        return 0;
    }

    if (p2 > 0) {
        if (this->map_row_offset[p2 - 1][p1].tile_type != 0) {
            return 0;
        }
        if ((p1 > 0) && (this->map_row_offset[p2 - 1][p1 - 1].tile_type != 0)) {
            return 0;
        }
        if ((p1 < max_x) && (this->map_row_offset[p2 - 1][p1 + 1].tile_type != 0)) {
            return 0;
        }
    }

    if (p2 < max_y) {
        if (this->map_row_offset[p2 + 1][p1].tile_type != 0) {
            return 0;
        }
        if ((p1 > 0) && (this->map_row_offset[p2 + 1][p1 - 1].tile_type != 0)) {
            return 0;
        }
        if ((p1 < max_x) && (this->map_row_offset[p2 + 1][p1 + 1].tile_type != 0)) {
            return 0;
        }
    }

    return 1;
}

void TRIBE_Map::tribe_clean_elevation(long p1, long p2, long p3, long p4) {
    if (p1 < 0) {
        p1 = 0;
    }
    if (p2 < 0) {
        p2 = 0;
    }
    if (p3 >= this->map_width) {
        p3 = this->map_width - 1;
    }
    if (p4 >= this->map_height) {
        p4 = this->map_height - 1;
    }

    for (long y = p2; y <= p4; ++y) {
        for (long x = p1; x <= p3; ++x) {
            uchar tt = (uchar)(this->map_row_offset[y][x].terrain_type & 0x1f);
            if ((this->water(tt) != 0) && (this->do_terrain_brush_check(x, y) == 0)) {
                RGE_Map::set_terrain(this->game_world, (short)x, (short)y, 0, 0, 0);
            }
        }
    }
}

void TRIBE_Map::tribe_clean_terrain(long p1, long p2, long p3, long p4, uchar p5, uchar p6) {
    (void)p5;
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    if (p1 < 0) p1 = 0;
    if (p2 < 0) p2 = 0;
    if (p3 >= this->map_width) p3 = this->map_width - 1;
    if (p4 >= this->map_height) p4 = this->map_height - 1;

    do {
        bool change_flag = false;

        if (p1 > 0) p1 = p1 - 1;
        if (p2 > 0) p2 = p2 - 1;
        if (p3 < this->map_width - 1) p3 = p3 + 1;
        if (p4 < this->map_height - 1) p4 = p4 + 1;

        for (long pass = 0; pass < 2; ++pass) {
            for (long y = p2; y <= p4; ++y) {
                for (long x = p1; x <= p3; ++x) {
                    uchar center_tt = (uchar)(this->map_row_offset[y][x].terrain_type & 0x1f);
                    if (this->water(center_tt) != 0) {
                        continue;
                    }

                    bool n = false;
                    bool s = false;
                    bool e = false;
                    bool w = false;
                    bool nw = false;
                    bool ne = false;
                    bool sw = false;
                    bool se = false;

                    if (y > 0 && this->water((uchar)(this->map_row_offset[y - 1][x].terrain_type & 0x1f)) != 0) n = true;
                    if (y < this->map_height - 1 && this->water((uchar)(this->map_row_offset[y + 1][x].terrain_type & 0x1f)) != 0) s = true;
                    if (x > 0 && this->water((uchar)(this->map_row_offset[y][x - 1].terrain_type & 0x1f)) != 0) w = true;
                    if (x < this->map_width - 1 && this->water((uchar)(this->map_row_offset[y][x + 1].terrain_type & 0x1f)) != 0) e = true;
                    if (y > 0 && x > 0 && this->water((uchar)(this->map_row_offset[y - 1][x - 1].terrain_type & 0x1f)) != 0) nw = true;
                    if (y > 0 && x < this->map_width - 1 && this->water((uchar)(this->map_row_offset[y - 1][x + 1].terrain_type & 0x1f)) != 0) ne = true;
                    if (y < this->map_height - 1 && x > 0 && this->water((uchar)(this->map_row_offset[y + 1][x - 1].terrain_type & 0x1f)) != 0) sw = true;
                    if (y < this->map_height - 1 && x < this->map_width - 1 && this->water((uchar)(this->map_row_offset[y + 1][x + 1].terrain_type & 0x1f)) != 0) se = true;

                    bool should_fix = false;
                    if (pass == 0) {
                        if ((n && s) || (e && w)) {
                            should_fix = true;
                        }
                    } else {
                        if (nw) {
                            if ((ne && !n) || (e && !ne) || (sw && !w) || (s && !sw)) {
                                should_fix = true;
                            } else if ((se && !s) && !e) {
                                should_fix = true;
                            }
                        }
                        if (ne && !should_fix) {
                            if ((nw && !n) || (w && !nw) || (se && !e) || (s && !se) || (sw && !w && !s)) {
                                should_fix = true;
                            }
                        }
                        if (se && !should_fix) {
                            if ((ne && !e) || (n && !ne) || (sw && !s) || (w && !sw) || (nw && !w && !n)) {
                                should_fix = true;
                            }
                        }
                        if (sw && !should_fix) {
                            if ((nw && !w) || (n && !nw) || (se && !s) || (e && !se) || (ne && !e && !n)) {
                                should_fix = true;
                            }
                        }
                    }

                    if (!should_fix) {
                        continue;
                    }

                    if (this->water(p6) == 0) {
                        if (nw) RGE_Map::set_terrain(this->game_world, (short)(x - 1), (short)(y - 1), p6, 0, 0);
                        if (n)  RGE_Map::set_terrain(this->game_world, (short)(x), (short)(y - 1), p6, 0, 0);
                        if (ne) RGE_Map::set_terrain(this->game_world, (short)(x + 1), (short)(y - 1), p6, 0, 0);
                        if (e)  RGE_Map::set_terrain(this->game_world, (short)(x + 1), (short)(y), p6, 0, 0);
                        if (se) RGE_Map::set_terrain(this->game_world, (short)(x + 1), (short)(y + 1), p6, 0, 0);
                        if (s)  RGE_Map::set_terrain(this->game_world, (short)(x), (short)(y + 1), p6, 0, 0);
                        if (sw) RGE_Map::set_terrain(this->game_world, (short)(x - 1), (short)(y + 1), p6, 0, 0);
                        if (w)  RGE_Map::set_terrain(this->game_world, (short)(x - 1), (short)(y), p6, 0, 0);
                    } else {
                        if (this->do_terrain_brush_check(x, y) == 0) {
                            continue;
                        }
                        RGE_Map::set_terrain(this->game_world, (short)x, (short)y, p6, 0, 0);
                    }

                    change_flag = true;
                }
            }
        }

        if (!change_flag) {
            this->clean_borders(p1, p2, p3, p4, p6);
            RGE_Map::set_terrain((RGE_Player*)nullptr, (RGE_Game_World*)nullptr, (short)p1, (short)p2, (short)p3, (short)p4, 0, 0, 0);
            return;
        }
    } while (true);
}

// --- RGE_Command (base class) ---
static uchar rge_duplicate_check_command_order(const RGE_Command* command_owner, const uchar* command_data) {
    // Source of truth: command.cpp.decomp @ 0x00435110
    const uchar* last_order = command_owner->last_order;
    const uint unit_count = (uint)command_data[8];

    if (unit_count != (uint)last_order[8]) {
        return 0;
    }

    const long current_x = (long)(*(const float*)(command_data + 0x0C));
    const long last_x = (long)(*(const float*)(last_order + 0x0C));
    if (current_x != last_x) {
        return 0;
    }

    const long current_y = (long)(*(const float*)(command_data + 0x10));
    const long last_y = (long)(*(const float*)(last_order + 0x10));
    if (current_y != last_y) {
        return 0;
    }

    if (*(const long*)(last_order + 4) != *(const long*)(command_data + 4)) {
        return 0;
    }

    const long* current_units = (const long*)(command_data + 0x14);
    const long* last_units = (const long*)(last_order + 0x14);
    for (uint i = 0; i < unit_count; ++i) {
        if (current_units[i] != last_units[i]) {
            return 0;
        }
    }

    return 1;
}

static uchar rge_duplicate_check_command_stop(const RGE_Command* command_owner, const uchar* command_data) {
    // Source of truth: command.cpp.decomp @ 0x004351B0
    const uchar* last_order = command_owner->last_order;
    const uint unit_count = (uint)command_data[1];

    if (unit_count != (uint)last_order[1]) {
        return 0;
    }

    const long* current_units = (const long*)(command_data + 2);
    const long* last_units = (const long*)(last_order + 2);
    for (uint i = 0; i < unit_count; ++i) {
        if (current_units[i] != last_units[i]) {
            return 0;
        }
    }

    return 1;
}

static uchar rge_close_check_for_duplicate_orders(const RGE_Command* command_owner, const uchar* command_data) {
    // Source of truth: command.cpp.decomp @ 0x00435210
    switch (command_data[0]) {
    case 0:
    case 2:
    case 3:
        return rge_duplicate_check_command_order(command_owner, command_data);
    case 1:
        return rge_duplicate_check_command_stop(command_owner, command_data);
    default:
        return 0;
    }
}

static uchar rge_check_for_duplicate_orders(const RGE_Command* command_owner, const uchar* command_data, long command_size) {
    // Source of truth: command.cpp.decomp @ 0x00435260
    if ((command_owner->last_order != nullptr) &&
        (command_owner->last_order_size == command_size) &&
        (command_owner->last_order[0] == command_data[0])) {
        const ulong now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Command.cpp", 0x497);
        if ((long)(now - (ulong)command_owner->last_order_time) < 500) {
            return rge_close_check_for_duplicate_orders(command_owner, command_data);
        }
    }

    return 0;
}

RGE_Command::RGE_Command(RGE_Game_World* param_1, TCommunications_Handler* param_2) {
    // Source of truth: Command.cpp.decomp @ 0x00433D40
    this->world = param_1;
    this->com_hand = param_2;
    this->last_order = nullptr;
    this->last_order_size = 0;
}

void RGE_Command::reset_communications(TCommunications_Handler* param_1) {
    // Source of truth: Command.cpp.decomp @ 0x00433DB0
    this->com_hand = param_1;
}

RGE_Static_Object* RGE_Command::get_obj(RGE_Obj_Info p1) {
    // Source of truth: command.cpp.decomp @ 0x00433DC0
    if (this->world == nullptr) {
        return nullptr;
    }
    return this->world->object((int)p1.id);
}

void RGE_Command::do_commands() {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00433DE0
    if (this->com_hand == nullptr) {
        return;
    }

    void* command_data = this->com_hand->get_command();
    while (command_data != nullptr) {
        this->do_command(command_data);
        ::operator delete(command_data);
        command_data = this->com_hand->get_command();
    }
}

void RGE_Command::submit(void* p1, long p2) {
    // Source of truth: command.cpp.decomp @ 0x004352C0
    uchar duplicate_order = rge_check_for_duplicate_orders(this, (uchar*)p1, p2);
    if (duplicate_order == 0) {
        this->com_hand->new_command(p1, (int)p2);
    }

    if (this->last_order != nullptr) {
        free(this->last_order);
        this->last_order = nullptr;
    }
    this->last_order = (unsigned char*)p1;
    this->last_order_size = p2;
    this->last_order_time = (long)debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Command.cpp", 0x4AC);
}

RGE_Command::~RGE_Command() {
    // Source of truth: Command.cpp.decomp @ 0x00433D90
    this->world = nullptr;
    this->com_hand = nullptr;
    if (this->last_order) {
        free(this->last_order);
        this->last_order = nullptr;
    }
}
void RGE_Command::do_command_create(RGE_Command_Create* p1) {
    // Source of truth: command.cpp.decomp @ 0x004348B0
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }
    RGE_Player* player = this->world->players[p1->player_id];
    if (player == nullptr) {
        return;
    }
    player->make_new_object((long)p1->obj_catagory, p1->location_x, p1->location_y, p1->location_z, 0);
}
void RGE_Command::do_command_add_attribute(RGE_Command_Add_Attribute* p1) {
    // Source of truth: command.cpp.decomp @ 0x004348F0
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }
    RGE_Player* player = this->world->players[p1->player_id];
    if (player == nullptr) {
        return;
    }
    player->add_attribute_num((short)p1->attr_id, p1->attr_amount, 0);
}
void RGE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* p1) {
    // Source of truth: command.cpp.decomp @ 0x00434920
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    RGE_Player* from_player = this->world->players[p1->player_id];
    if (from_player == nullptr || from_player->attributes == nullptr) {
        return;
    }

    int attr_id = (int)p1->attr_id;
    if (attr_id < 0 || attr_id >= from_player->attribute_num) {
        return;
    }

    float amount = p1->attr_amount;
    if (from_player->attributes[attr_id] < amount) {
        return;
    }

    from_player->add_attribute_num((short)p1->attr_id, -amount, 0);

    RGE_Player* to_player = this->world->players[p1->to_player_id];
    if (to_player == nullptr) {
        return;
    }
    to_player->add_attribute_num((short)p1->attr_id, amount, 0);

    if (rge_base_game != nullptr) {
        rge_base_game->notification(7, p1->player_id, p1->to_player_id, p1->attr_id, (long)amount);
    }
    to_player->notify(p1->player_id, p1->to_player_id, 0x20A, p1->attr_id, (long)amount, 0);
}
void RGE_Command::do_command(void* p1) {
    // Source of truth: command.cpp.decomp @ 0x00433E20 (partial)
    if (p1 == nullptr) {
        return;
    }

    uchar cmd = *(uchar*)p1;
    if (cmd == 4) {
        this->do_command_create((RGE_Command_Create*)p1);
        return;
    }
    if (cmd == 5) {
        this->do_command_add_attribute((RGE_Command_Add_Attribute*)p1);
        return;
    }
    if (cmd == 7) {
        this->do_command_give_attribute((RGE_Command_Give_Attribute*)p1);
    }
}
void RGE_Command::command_create(short p1, short p2, float p3, float p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x004359C0
    RGE_Command_Create* cmd = (RGE_Command_Create*)calloc(1, sizeof(RGE_Command_Create));
    if (cmd == nullptr) {
        return;
    }
    cmd->command = 4;
    cmd->obj_catagory = p1;
    cmd->player_id = (uchar)p2;
    cmd->location_x = p3;
    cmd->location_y = p4;
    cmd->location_z = p5;

    this->submit(cmd, sizeof(RGE_Command_Create));
}
void RGE_Command::command_add_attribute(int p1, int p2, float p3) {
    // Source of truth: command.cpp.decomp @ 0x00435A30
    RGE_Command_Add_Attribute* cmd = (RGE_Command_Add_Attribute*)calloc(1, sizeof(RGE_Command_Add_Attribute));
    if (cmd == nullptr) {
        return;
    }
    cmd->command = 5;
    cmd->player_id = (uchar)p1;
    cmd->attr_id = (uchar)p2;
    cmd->attr_amount = p3;

    this->submit(cmd, sizeof(RGE_Command_Add_Attribute));
}
void RGE_Command::command_give_attribute(int p1, int p2, int p3, float p4) {
    // Source of truth: command.cpp.decomp @ 0x00435A80
    RGE_Command_Give_Attribute* cmd = (RGE_Command_Give_Attribute*)calloc(1, sizeof(RGE_Command_Give_Attribute));
    if (cmd == nullptr) {
        return;
    }
    cmd->command = 7;
    cmd->player_id = (uchar)p1;
    cmd->to_player_id = (uchar)p2;
    cmd->attr_id = (uchar)p3;
    cmd->attr_amount = p4;

    this->submit(cmd, sizeof(RGE_Command_Give_Attribute));
}

static int rge_scenario_active_player_count(const RGE_Scenario* scenario) {
    if (scenario == nullptr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < 16; ++i) {
        if (scenario->PlActive[i] != 0) {
            count = count + 1;
        }
    }
    return count;
}

static int tribe_scenario_any_sp_victory(const T_Scenario* scenario) {
    if (scenario == nullptr) {
        return 0;
    }

    for (int player = 0; player < 16; ++player) {
        if (scenario->PlActive[player] == 0) {
            continue;
        }
        for (int slot = 0; slot < 12; ++slot) {
            if (scenario->sp_victory[player][slot].VictoryType != 0) {
                return 1;
            }
        }
    }
    return 0;
}

RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario* scenario) {
    // Source of truth: scenario.cpp.decomp @ 0x0048AB10
    this->error_code = 0;
    this->version = 2;
    this->checksum = (unsigned long)time(nullptr);
    this->description = nullptr;

    if (scenario != nullptr && scenario->description != nullptr) {
        size_t desc_size = strlen(scenario->description) + 1;
        this->description = (char*)malloc(desc_size);
        if (this->description != nullptr) {
            memcpy(this->description, scenario->description, desc_size);
        } else {
            this->error_code = 1;
        }
    }
}

RGE_Scenario_Header::RGE_Scenario_Header(int p1) {
    // Source of truth: scenario.cpp.decomp @ 0x0048ABB0
    this->error_code = 0;
    this->version = 0;
    this->checksum = 0;
    this->description = nullptr;

    long header_size = 0;
    rge_read(p1, &header_size, 4);
    rge_read(p1, &this->version, 4);
    if (this->version > 1) {
        rge_read(p1, &this->checksum, 4);
    }

    int desc_size = 0;
    rge_read(p1, &desc_size, 4);
    if (desc_size > 0) {
        this->description = (char*)malloc((size_t)desc_size);
        if (this->description == nullptr) {
            this->error_code = 1;
            return;
        }
        rge_read(p1, this->description, desc_size);
    }
}

RGE_Scenario_Header::~RGE_Scenario_Header() {
    // Source of truth: scenario.cpp.decomp @ 0x0048AC70
    if (this->description != nullptr) {
        free(this->description);
        this->description = nullptr;
    }
}

long RGE_Scenario_Header::get_size() {
    // Source of truth: scenario.cpp.decomp @ 0x0048ACA0
    if (this->description == nullptr) {
        return 0xC;
    }
    return (long)(strlen(this->description) + 0xD);
}

void RGE_Scenario_Header::save(int p1) {
    // Source of truth: scenario.cpp.decomp @ 0x0048ACC0
    long header_size = this->get_size();
    rge_write(p1, &header_size, 4);
    rge_write(p1, &this->version, 4);

    if (this->version > 1) {
        rge_write(p1, &this->checksum, 4);
    }

    int desc_size = 0;
    if (this->description != nullptr) {
        desc_size = (int)strlen(this->description) + 1;
    }
    rge_write(p1, &desc_size, 4);
    if (desc_size > 0) {
        rge_write(p1, this->description, desc_size);
    }
}

TRIBE_Scenario_Header::TRIBE_Scenario_Header(T_Scenario* scenario)
    : RGE_Scenario_Header((RGE_Scenario*)scenario) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052A990
    this->any_sp_victory = tribe_scenario_any_sp_victory(scenario);
    this->active_player_count = rge_scenario_active_player_count((RGE_Scenario*)scenario);
}

TRIBE_Scenario_Header::TRIBE_Scenario_Header(int p1)
    : RGE_Scenario_Header(p1) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052A9F0
    this->any_sp_victory = 0;
    this->active_player_count = 0;
    if (this->error_code == 0) {
        rge_read(p1, &this->any_sp_victory, 4);
        rge_read(p1, &this->active_player_count, 4);
    }
}

long TRIBE_Scenario_Header::get_size() {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052AA70
    return RGE_Scenario_Header::get_size() + 8;
}

void TRIBE_Scenario_Header::save(int p1) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052AA80
    RGE_Scenario_Header::save(p1);
    rge_write(p1, &this->any_sp_victory, 4);
    rge_write(p1, &this->active_player_count, 4);
}

static unsigned short rge_scenario_string_len16(const char* text, int include_null) {
    if (text == nullptr) {
        return 0;
    }

    size_t len = strlen(text);
    if (include_null != 0) {
        len = len + 1;
    }

    return (unsigned short)len;
}

static void rge_scenario_write_string16(int fd, const char* text, int include_null) {
    unsigned short length = rge_scenario_string_len16(text, include_null);
    rge_write(fd, &length, 2);
    if (((short)length > 0) && text != nullptr) {
        rge_write(fd, (void*)text, (int)length);
    }
}

static void rge_scenario_write_string16_unchecked(int fd, const char* text) {
    unsigned short length = (unsigned short)strlen(text);
    rge_write(fd, &length, 2);
    if ((short)length > 0) {
        rge_write(fd, (void*)text, (int)length);
    }
}

static void rge_scenario_refresh_ai_blob(const char* ai_dir, const char* file_base, const char* ext,
                                         unsigned char** out_data, int* out_size) {
    if (out_data == nullptr || out_size == nullptr) {
        return;
    }

    char path[300];
    sprintf(path, "%s%s%s", ai_dir, file_base, ext);
    int fd = _open(path, _O_BINARY | _O_RDONLY);
    if (fd == -1) {
        return;
    }

    long file_size = _lseek(fd, 0, SEEK_END);

    *out_size = (int)file_size;
    if (*out_data != nullptr) {
        free(*out_data);
    }
    *out_data = (unsigned char*)calloc((size_t)(*out_size), 1);

    _lseek(fd, 0, SEEK_SET);
    (void)_read(fd, *out_data, (unsigned int)(*out_size));
    _close(fd);
}

// --- RGE_Scenario (base class stubs) ---
RGE_Scenario::~RGE_Scenario() {
    // Source of truth: scenario.cpp.decomp @ 0x0048B5A0
    if (this->time_line != nullptr) {
        delete this->time_line;
        this->time_line = nullptr;
    }

    if (this->description != nullptr) {
        free(this->description);
        this->description = nullptr;
    }
    if (this->hints != nullptr) {
        free(this->hints);
        this->hints = nullptr;
    }
    if (this->win_message != nullptr) {
        free(this->win_message);
        this->win_message = nullptr;
    }
    if (this->loss_message != nullptr) {
        free(this->loss_message);
        this->loss_message = nullptr;
    }
    if (this->historicle_notes != nullptr) {
        free(this->historicle_notes);
        this->historicle_notes = nullptr;
    }

    operator delete(this->scenario_name);
    this->scenario_name = nullptr;

    if (this->mission_picture != nullptr) {
        delete this->mission_picture;
        this->mission_picture = nullptr;
    }

    for (int i = 0; i < 16; ++i) {
        operator delete(this->BuildList[i]);
        this->BuildList[i] = nullptr;
        operator delete(this->CityPlan[i]);
        this->CityPlan[i] = nullptr;
        operator delete(this->AiRules[i]);
        this->AiRules[i] = nullptr;

        if (this->BuildListFile[i] != nullptr) {
            free(this->BuildListFile[i]);
            this->BuildListFile[i] = nullptr;
        }
        if (this->CityPlanFile[i] != nullptr) {
            free(this->CityPlanFile[i]);
            this->CityPlanFile[i] = nullptr;
        }
        if (this->AiRulesFile[i] != nullptr) {
            free(this->AiRulesFile[i]);
            this->AiRulesFile[i] = nullptr;
        }
    }
}
RGE_Static_Object* RGE_Scenario::get_object_pointer(int p1) {
    // Source of truth: scenario.cpp.decomp @ 0x0048B580
    (void)p1;
    return nullptr;
}
void RGE_Scenario::rehook() {
    // Source of truth: scenario.cpp.decomp @ 0x0048B590
    return;
}
float RGE_Scenario::Get_Version() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048C0D0
    return 1.15f;
}
void RGE_Scenario::update() {
    // Fully verified. Source of truth: scenario.cpp.decomp @ 0x0048C3D0
    if (this->time_line != nullptr) {
        this->time_line->update();
    }
}
void RGE_Scenario::save(int p1) {
    // Source of truth: scenario.cpp.decomp @ 0x0048C3E0
    this->Version = this->Get_Version();
    rge_write(p1, &this->Version, 4);

    for (int i = 0; i < 16; ++i) {
        rge_write(p1, this->player_name[i], 0x100);
    }

    for (int i = 0; i < 16; ++i) {
        rge_write(p1, &this->PlActive[i], 4);
        rge_write(p1, &this->PlType[i], 4);
        rge_write(p1, &this->PlCivilization[i], 4);
        rge_write(p1, &this->PlayerPosture[i], 4);
    }

    rge_write(p1, &this->victory_conquest, 1);
    if (this->time_line != nullptr) {
        this->time_line->save(p1);
    }

    rge_scenario_write_string16(p1, this->scenario_name, 0);
    rge_scenario_write_string16(p1, this->description, 1);
    rge_scenario_write_string16(p1, this->hints, 1);
    rge_scenario_write_string16(p1, this->win_message, 1);
    rge_scenario_write_string16(p1, this->loss_message, 1);
    rge_scenario_write_string16(p1, this->historicle_notes, 1);

    rge_scenario_write_string16_unchecked(p1, this->Cine_PreGame);
    rge_scenario_write_string16_unchecked(p1, this->Cine_Victory);
    rge_scenario_write_string16_unchecked(p1, this->Cine_Loss);
    rge_scenario_write_string16_unchecked(p1, this->Mission_Bmp);

    char mission_file[260];
    sprintf(mission_file, "%s.bmp", this->Mission_Bmp);
    TPicture* loaded_picture = new TPicture(mission_file, -1, 0, nullptr, 0);
    if (this->mission_picture != nullptr) {
        if (loaded_picture->Dib == nullptr) {
            delete loaded_picture;
        } else {
            delete this->mission_picture;
            this->mission_picture = loaded_picture;
        }
    } else {
        this->mission_picture = loaded_picture;
    }

    this->mission_picture->Save(p1);

    for (int i = 0; i < 16; ++i) {
        rge_scenario_write_string16_unchecked(p1, this->BuildList[i]);
    }
    for (int i = 0; i < 16; ++i) {
        rge_scenario_write_string16_unchecked(p1, this->CityPlan[i]);
    }
    if (this->Version >= 1.08f) {
        for (int i = 0; i < 16; ++i) {
            rge_scenario_write_string16_unchecked(p1, this->AiRules[i]);
        }
    }

    for (int i = 0; i < 16; ++i) {
        if (this->BuildList[i] != nullptr) {
            rge_scenario_refresh_ai_blob(rge_base_game->prog_info->ai_dir, this->BuildList[i], ".ai",
                                         &this->BuildListFile[i], &this->BuildListFileSize[i]);
        }
        if (this->CityPlan[i] != nullptr) {
            rge_scenario_refresh_ai_blob(rge_base_game->prog_info->ai_dir, this->CityPlan[i], ".cty",
                                         &this->CityPlanFile[i], &this->CityPlanFileSize[i]);
        }
        if (this->AiRules[i] != nullptr) {
            rge_scenario_refresh_ai_blob(rge_base_game->prog_info->ai_dir, this->AiRules[i], ".per",
                                         &this->AiRulesFile[i], &this->AiRulesFileSize[i]);
        }

        rge_write(p1, &this->BuildListFileSize[i], 4);
        rge_write(p1, &this->CityPlanFileSize[i], 4);
        if (this->Version >= 1.08f) {
            rge_write(p1, &this->AiRulesFileSize[i], 4);
        }

        if (this->BuildListFile[i] != nullptr) {
            rge_write(p1, this->BuildListFile[i], this->BuildListFileSize[i]);
        }
        if (this->CityPlanFile[i] != nullptr) {
            rge_write(p1, this->CityPlanFile[i], this->CityPlanFileSize[i]);
        }
        if (this->AiRulesFile[i] != nullptr) {
            rge_write(p1, this->AiRulesFile[i], this->AiRulesFileSize[i]);
        }
    }

    int checksum = -99;
    rge_write(p1, &checksum, 4);
}

// --- TRIBE_Command ---
TRIBE_Command::TRIBE_Command(RGE_Game_World* world, TCommunications_Handler* comm)
    : RGE_Command(world, comm) {
}

TRIBE_Command::~TRIBE_Command() {}
void TRIBE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* p1) {
    // Source of truth: tcommand.cpp.decomp indicates TRIBE-specific handler lives in vt[4] (+0x10).
    // Keep base command-id-7 behavior intact on vt[0].
    RGE_Command::do_command_give_attribute(p1);
}
void TRIBE_Command::do_command(void* p1) {
    // Source of truth: tcommand.cpp.decomp @ 0x00509770 (partial)
    (void)debug_rand("C:\\msdev\\work\\age1_x1\\tcommand.cpp", 0x3F);
    if (p1 == nullptr) {
        return;
    }

    if (*(uchar*)p1 == 0x6C) {
        this->do_command_give_attribute((TRIBE_Command_Give_Attribute*)p1);
        return;
    }
    if (*(uchar*)p1 == 0x6D) {
        this->do_command_trade_attribute((TRIBE_Command_Trade_Attribute*)p1);
        return;
    }

    RGE_Command::do_command(p1);
}
void TRIBE_Command::do_command_give_attribute(TRIBE_Command_Give_Attribute* p1) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050A510
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    float transfer_amount = 0.0f;
    if (p1->attr_amount >= 0.0f) {
        transfer_amount = p1->attr_amount;
    }

    float cost = 0.0f;
    if (transfer_amount > 0.0f) {
        cost = p1->attr_cost * transfer_amount;
    }

    RGE_Player* from_player = this->world->players[p1->player_id];
    RGE_Player* to_player = this->world->players[p1->to_player_id];
    if (from_player == nullptr || to_player == nullptr || from_player->attributes == nullptr) {
        return;
    }

    int attr_id = (int)p1->attr_id;
    if (attr_id < 0 || attr_id >= from_player->attribute_num) {
        return;
    }

    float* from_attr = &from_player->attributes[attr_id];
    if (*from_attr < transfer_amount + cost) {
        cost = *from_attr * p1->attr_cost;
        transfer_amount = *from_attr - cost;
    }

    to_player->add_attribute_num((short)p1->attr_id, transfer_amount, 0);
    from_player->add_attribute_num((short)p1->attr_id, -(transfer_amount + cost), 0);
    from_player->add_attribute_num(0x35, transfer_amount, 0);
    to_player->add_attribute_num(0x35, -transfer_amount, 0);

    if (rge_base_game != nullptr) {
        rge_base_game->notification(7, p1->player_id, p1->to_player_id, p1->attr_id, (long)transfer_amount);
    }
    to_player->notify(p1->player_id, p1->to_player_id, 0x20A, p1->attr_id, (long)transfer_amount, 0);
}
void TRIBE_Command::command_give_attribute(int p1, int p2, int p3, float p4, float p5) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B130
    TRIBE_Command_Give_Attribute* cmd = (TRIBE_Command_Give_Attribute*)calloc(1, sizeof(TRIBE_Command_Give_Attribute));
    if (cmd == nullptr) {
        return;
    }
    cmd->command = 0x6C;
    cmd->player_id = (uchar)p1;
    cmd->to_player_id = (uchar)p2;
    cmd->attr_id = (uchar)p3;
    cmd->attr_amount = p4;
    cmd->attr_cost = p5;

    this->submit(cmd, sizeof(TRIBE_Command_Give_Attribute));
}
void TRIBE_Command::do_command_trade_attribute(TRIBE_Command_Trade_Attribute* p1) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050A6A0
    if (this->world == nullptr || p1 == nullptr) {
        return;
    }

    RGE_Obj_Info* object_ids = (RGE_Obj_Info*)(p1 + 1);
    int count = (int)p1->unit_num;
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = this->get_obj(object_ids[i]);
        if (obj != nullptr) {
            obj->attribute_type_held = (short)p1->attribute;
        }
    }
}
void TRIBE_Command::command_trade_attribute(RGE_Static_Object** p1, short p2, long p3) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B190 (temporary-safe local execution path)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = (int)sizeof(TRIBE_Command_Trade_Attribute) + count * 4;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    TRIBE_Command_Trade_Attribute* cmd = (TRIBE_Command_Trade_Attribute*)buffer;
    cmd->command = 0x6D;
    cmd->unit_num = (uchar)p2;
    cmd->attribute = p3;

    int* object_ids = (int*)(buffer + sizeof(TRIBE_Command_Trade_Attribute));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        object_ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    this->submit(buffer, size);
}
void TRIBE_Command::command_trade_attribute(int p1, int p2, long p3) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B230 (temporary-safe local execution path)
    (void)p2;

    const int size = (int)sizeof(TRIBE_Command_Trade_Attribute) + 4;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }
    TRIBE_Command_Trade_Attribute* cmd = (TRIBE_Command_Trade_Attribute*)buffer;
    cmd->command = 0x6D;
    cmd->unit_num = 1;
    cmd->attribute = p3;
    *(int*)(buffer + sizeof(TRIBE_Command_Trade_Attribute)) = p1;

    this->submit(buffer, size);
}

// --- TRIBE_Effects (from teffects.cpp.decomp) ---
TRIBE_Effects::TRIBE_Effects(int param_1)
    : RGE_Effects(param_1) {
    // Source of truth: teffects.cpp.decomp @ 0x0050D460
    // Just delegates to base class constructor
}

TRIBE_Effects::~TRIBE_Effects() {
    // Source of truth: bucket_050D.cpp.decomp @ 0x0050D4A0
    // Base class destructor handles cleanup
}

void TRIBE_Effects::save(int p1) {
    // Delegates to base class
    RGE_Effects::save(p1);
}

void TRIBE_Effects::do_effect(short p1, RGE_Player* p2) {
    // Source of truth: teffects.cpp.decomp @ 0x0050D4D0
    if ((int)p1 >= this->effect_num) return;
    RGE_Effect* eff = &this->effects[p1];
    if (eff == nullptr) return;
    // TRIBE-specific: process tech-enable/disable effect commands before base do_effect.
    for (short i = 0; i < eff->effect_list_num; i++) {
        RGE_Effect_Command* cmd = &eff->effect_list[i];
        if (cmd != nullptr && cmd->command == 'f' && p2 != nullptr) {
            ((TRIBE_Player*)p2)->tech_abling((long)cmd->change_amount, 0);
        }
    }
    RGE_Effects::do_effect(p1, p2);
}

void TRIBE_Effects::do_tech_effect(short p1, RGE_Player* p2) {
    // Source of truth: teffects.cpp.decomp @ 0x0050D550
    if ((int)p1 < 0 || (int)p1 >= this->effect_num) {
        return;
    }
    RGE_Effect* eff = &this->effects[p1];
    if (eff == nullptr) {
        return;
    }
    for (short i = 0; i < eff->effect_list_num; i++) {
        RGE_Effect_Command* cmd = &eff->effect_list[i];
        if (cmd != nullptr && cmd->command == 'f' && p2 != nullptr) {
            ((TRIBE_Player*)p2)->tech_abling((long)cmd->change_amount, 0);
        }
    }
}

static int t_scenario_get_player_food(T_Scenario* scenario, int idx) {
    if (scenario == nullptr || idx < 0 || idx >= 16) {
        return 0;
    }
    return scenario->player_info[idx].Food;
}

static int t_scenario_get_player_stone(T_Scenario* scenario, int idx) {
    if (scenario == nullptr || idx < 0 || idx >= 16) {
        return 0;
    }
    return scenario->player_info[idx].Stone;
}

static int t_scenario_get_player_gold(T_Scenario* scenario, int idx) {
    if (scenario == nullptr || idx < 0 || idx >= 16) {
        return 0;
    }
    return scenario->player_info[idx].Gold;
}

static int t_scenario_get_player_wood(T_Scenario* scenario, int idx) {
    if (scenario == nullptr || idx < 0 || idx >= 16) {
        return 0;
    }
    return scenario->player_info[idx].Wood;
}

static void t_scenario_clear_disabled_technologies(T_Scenario* scenario) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052B100
    if (scenario == nullptr) {
        return;
    }
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 20; ++j) {
            scenario->DisabledTechnology[i][j] = 1;
        }
    }
}

static void t_scenario_save_attributes_into_players(T_Scenario* scenario) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052BA90
    if (scenario == nullptr || scenario->world == nullptr || scenario->world->players == nullptr) {
        return;
    }

    int player_slot = 1;
    if (scenario->world->player_num <= 1) {
        return;
    }

    int allied_idx = 0;
    int opp_row = 0;
    do {
        int scen_player = player_slot - 1;
        RGE_Player* player = scenario->world->players[player_slot];
        if (player != nullptr) {
            player->new_attribute_num(0, (float)t_scenario_get_player_food(scenario, scen_player));
            player->new_attribute_num(2, (float)t_scenario_get_player_stone(scenario, scen_player));
            player->new_attribute_num(3, (float)t_scenario_get_player_gold(scenario, scen_player));
            player->new_attribute_num(1, (float)t_scenario_get_player_wood(scenario, scen_player));

            int rel_player = 1;
            if (scenario->world->player_num > 1) {
                do {
                    if (rel_player != player_slot) {
                        player->set_relation(rel_player, (uchar)scenario->Opponent[opp_row].Attitude[rel_player - 1]);
                    }
                    rel_player = rel_player + 1;
                } while (rel_player < scenario->world->player_num);
            }

            player->set_allied_victory((uchar)scenario->AlliedVictory[allied_idx]);
        }

        player_slot = player_slot + 1;
        opp_row = opp_row + 1;
        allied_idx = allied_idx + 1;
    } while (player_slot < scenario->world->player_num);
}

// --- T_Scenario ---
T_Scenario::T_Scenario(int param_1, RGE_Game_World* param_2) {
    (void)param_1;
    // Preserve vtable pointer and clear all data fields (base + derived).
    memset((char*)this + sizeof(void*), 0, sizeof(T_Scenario) - sizeof(void*));
    this->world = param_2;
    this->victory_conquest = 1;
    this->InitializeVictoryValues();

    for (int i = 0; i < 16; ++i) {
        this->player_info[i].Gold = 0;
        this->player_info[i].Wood = 200;
        this->player_info[i].Food = 200;
        this->player_info[i].Stone = 150;
    }

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            this->Opponent[i].Attitude[j] = 3;
        }
    }

    this->mp_victory_type = 0;
    this->victory_score = 900;
    this->victory_time = 9000;
    this->victory_all_flag = 0;
    this->which_player = 0;
    this->ScenarioOptions[0] = 0;
    this->ScenarioOptions[1] = 0;
    this->ScenarioOptions[2] = 0;
    t_scenario_clear_disabled_technologies(this);
}

T_Scenario::T_Scenario(RGE_Game_World* param_1) {
    // Preserve vtable pointer and clear all data fields (base + derived).
    memset((char*)this + sizeof(void*), 0, sizeof(T_Scenario) - sizeof(void*));
    this->world = param_1;
    this->victory_conquest = 1;
    this->InitializeVictoryValues();

    for (int i = 0; i < 16; ++i) {
        this->player_info[i].Gold = 0;
        this->player_info[i].Wood = 200;
        this->player_info[i].Food = 200;
        this->player_info[i].Stone = 150;
    }

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            this->Opponent[i].Attitude[j] = 3;
        }
    }

    this->mp_victory_type = 0;
    this->victory_score = 900;
    this->victory_time = 9000;
    this->victory_all_flag = 0;
    this->which_player = 0;
    this->ScenarioOptions[0] = 0;
    this->ScenarioOptions[1] = 0;
    this->ScenarioOptions[2] = 0;
    t_scenario_clear_disabled_technologies(this);
}

T_Scenario::~T_Scenario() {}
RGE_Static_Object* T_Scenario::get_object_pointer(int p1) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052C080
    if (this->world == nullptr || p1 <= 0) {
        return nullptr;
    }
    return this->world->object(p1 - 1);
}
void T_Scenario::rehook() {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052C070
    return;
}
void T_Scenario::save(int p1) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052AF20
    int checksum = -99;

    this->WriteDisabledTechnologiesToMainSystem();
    RGE_Scenario::save(p1);

    Player_Start_Info* player = this->player_info;
    for (int i = 0; i < 16; ++i) {
        rge_write(p1, player, 0x10);
        player = player + 1;
    }

    rge_write(p1, &checksum, 4);
    rge_write(p1, &this->victory, 0x18);
    rge_write(p1, &this->victory_all_flag, 4);
    rge_write(p1, &this->mp_victory_type, 4);
    rge_write(p1, &this->victory_score, 4);
    rge_write(p1, &this->victory_time, 4);
    rge_write(p1, this->Opponent, 0x400);

    SP_Victory_Info (*sp_victory_row)[12] = this->sp_victory;
    for (int i = 0; i < 16; ++i) {
        rge_write(p1, sp_victory_row, 0x2d0);
        sp_victory_row = sp_victory_row + 1;
    }

    rge_write(p1, &checksum, 4);
    rge_write(p1, this->AlliedVictory, 0x40);
    rge_write(p1, this->DisabledTechnology, 0x500);
    rge_write(p1, this->ScenarioOptions, 0xC);
    rge_write(p1, this->PlayerAge, 0x40);
    rge_write(p1, &checksum, 4);
}

void T_Scenario::WriteDisabledTechnologiesToMainSystem() {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052C0B0
    if (this->world == nullptr) {
        return;
    }
    if (this->world->player_num <= 1) {
        return;
    }

    int* disabled_row = this->DisabledTechnology[0] + 1;
    int player_slot = 1;
    do {
        TRIBE_Player* player = (TRIBE_Player*)this->world->players[player_slot];
        if (player != nullptr) {
            if (this->ScenarioOptions[0] != 0 && this->world->effects != nullptr) {
                this->world->effects->do_effect(100, player);
            }

            player->tech_abling(0x58, (uchar)disabled_row[-1]);
            player->tech_abling(0x59, (uchar)disabled_row[0]);
            player->tech_abling(0x5A, (uchar)disabled_row[1]);
            player->tech_abling(0x5B, (uchar)disabled_row[2]);
            player->tech_abling(0x5E, (uchar)disabled_row[3]);
            player->tech_abling(0x5F, (uchar)disabled_row[4]);
            player->tech_abling(0x61, (uchar)disabled_row[5]);
            player->tech_abling(0x62, (uchar)disabled_row[6]);
            player->tech_abling(0x5D, (uchar)disabled_row[7]);
            player->tech_abling(0x60, (uchar)disabled_row[8]);
            player->tech_abling(0x5C, (uchar)disabled_row[9]);
            player->tech_abling(0x65, (uchar)disabled_row[10]);
            player->tech_abling(0x66, (uchar)disabled_row[11]);
            player->tech_abling(0x67, (uchar)disabled_row[12]);
            player->tech_abling(0x73, (uchar)disabled_row[13]);
            player->tech_abling(0x74, (uchar)disabled_row[14]);
        }

        player_slot = player_slot + 1;
        disabled_row = disabled_row + 20;
    } while (player_slot < this->world->player_num);
}

void T_Scenario::InitializeVictoryValues() {
    this->victory.MP_Conquest = 1;
    this->victory.MP_Ruins = 0;
    this->victory.MP_Artifacts = 0;
    this->victory.MP_Discoveries = 0;
    this->victory.MP_Exploration = 0;
    this->victory.MP_Gold = 0;
    memset(this->sp_victory, 0, sizeof(this->sp_victory));
}

void T_Scenario::Set_victory_all_flag(int param_1) {
    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_1 > 1) {
        param_1 = 1;
    }
    this->victory_all_flag = param_1;
}

int T_Scenario::Get_victory_all_flag() {
    return this->victory_all_flag;
}

void T_Scenario::SetMPVictory(int param_1) {
    this->mp_victory_type = param_1;
    if (param_1 != 4) {
        this->victory_conquest = 1;
    }
}

int T_Scenario::GetMPVictory() {
    return this->mp_victory_type;
}

void T_Scenario::SetVictoryScore(int param_1) {
    this->victory_score = param_1;
}

int T_Scenario::GetVictoryScore() {
    return this->victory_score;
}

void T_Scenario::SetVictoryTime(int param_1) {
    this->victory_time = param_1;
}

int T_Scenario::GetVictoryTime() {
    return this->victory_time;
}

void T_Scenario::Set_Multi_Conquest(int param_1) {
    if (param_1 != 0) {
        this->victory.MP_Conquest = 1;
        this->victory_conquest = 1;
        return;
    }
    this->victory.MP_Conquest = 0;
    this->victory_conquest = 0;
}

void T_Scenario::Set_Multi_Ruins(int param_1) {
    this->victory.MP_Ruins = param_1;
}

void T_Scenario::Set_Multi_Artifacts(int param_1) {
    this->victory.MP_Artifacts = param_1;
}

void T_Scenario::Set_Multi_Discoveries(int param_1) {
    this->victory.MP_Discoveries = param_1;
}

void T_Scenario::Set_Multi_Exploration(int param_1) {
    this->victory.MP_Exploration = param_1;
}

void T_Scenario::Set_Multi_Gold(int param_1) {
    this->victory.MP_Gold = param_1;
}

void T_Scenario::SetScenarioOption(int param_1, int param_2) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052B670
    this->ScenarioOptions[param_1] = param_2;
}

int T_Scenario::Get_Multi_Ruins() {
    return this->victory.MP_Ruins;
}

int T_Scenario::Get_Multi_Artifacts() {
    return this->victory.MP_Artifacts;
}

int T_Scenario::Get_Multi_Discoveries() {
    return this->victory.MP_Discoveries;
}

int T_Scenario::Get_Multi_Exploration() {
    return this->victory.MP_Exploration;
}

int T_Scenario::Get_Multi_Gold() {
    return this->victory.MP_Gold;
}

int T_Scenario::GetScenarioOption(int param_1) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052BA60
    return this->ScenarioOptions[param_1];
}

void T_Scenario::Save_victory_conditions_into_players(int param_1) {
    // Source of truth: tscenaro.cpp.decomp @ 0x0052BBC0
    if (param_1 != 0) {
        t_scenario_save_attributes_into_players(this);
    }

    if (this->world == nullptr || this->world->players == nullptr) {
        CUSTOM_DEBUG_LOG("T_Scenario::Save_victory_conditions_into_players skipped (world/players null)");
        return;
    }

    int player_num = this->world->player_num;
    for (int i = 1; i < player_num; ++i) {
        RGE_Player* player = this->world->players[i];
        if (player == nullptr) {
            CUSTOM_DEBUG_LOG_FMT("T_Scenario::Save_victory_conditions_into_players skip reset player=%d (null player)", i);
            continue;
        }
        if (player->victory_conditions == nullptr) {
            player->new_victory();
        }
        if (player->victory_conditions == nullptr) {
            CUSTOM_DEBUG_LOG_FMT("T_Scenario::Save_victory_conditions_into_players skip reset player=%d (no victory list)", i);
            continue;
        }
        player->victory_conditions->destroy_all();
    }

    if (this->mp_victory_type == 4) {
        if (this->victory_all_flag != 0) {
            for (int i = 1; i < player_num; ++i) {
                RGE_Player* player = this->world->players[i];
                if (player != nullptr && player->victory_conditions == nullptr) {
                    player->new_victory();
                }
                RGE_Victory_Conditions* vc = (player != nullptr) ? player->victory_conditions : nullptr;
                if (vc == nullptr) {
                    continue;
                }

                if (this->victory.MP_Exploration != 0) {
                    vc->add_explore('\b', this->victory.MP_Exploration, '\x01');
                }
                if (this->victory.MP_Ruins != 0) {
                    vc->add_attributes('\b', 0x0e, this->victory.MP_Ruins, '\x01');
                }
                if (this->victory.MP_Artifacts != 0) {
                    vc->add_attributes('\b', 7, this->victory.MP_Artifacts, '\x01');
                }
                if (this->victory.MP_Discoveries != 0) {
                    vc->add_attributes('\b', 0x0d, this->victory.MP_Discoveries, '\0');
                }
                if (this->victory.MP_Gold != 0) {
                    vc->add_attributes('\b', 3, this->victory.MP_Gold, '\x01');
                }
            }
        }

        if (this->victory_all_flag == 0) {
            for (int i = 1; i < player_num; ++i) {
                RGE_Player* player = this->world->players[i];
                if (player != nullptr && player->victory_conditions == nullptr) {
                    player->new_victory();
                }
                RGE_Victory_Conditions* vc = (player != nullptr) ? player->victory_conditions : nullptr;
                if (vc == nullptr) {
                    continue;
                }

                if (this->victory.MP_Exploration != 0) {
                    vc->add_explore('\b', this->victory.MP_Exploration, '\x01');
                }
                if (this->victory.MP_Ruins != 0) {
                    vc->add_attributes('\t', 0x0e, this->victory.MP_Ruins, '\x01');
                }
                if (this->victory.MP_Artifacts != 0) {
                    vc->add_attributes('\n', 7, this->victory.MP_Artifacts, '\x01');
                }
                if (this->victory.MP_Discoveries != 0) {
                    vc->add_attributes('\v', 0x0d, this->victory.MP_Discoveries, '\0');
                }
                if (this->victory.MP_Gold != 0) {
                    vc->add_attributes('\f', 3, this->victory.MP_Gold, '\x01');
                }
            }
        }
    }

    int player_index = 0;
    if (player_num > 1) {
        do {
            RGE_Player* player = this->world->players[player_index + 1];
            if (player != nullptr && player->victory_conditions == nullptr) {
                player->new_victory();
            }
            RGE_Victory_Conditions* vc = (player != nullptr) ? player->victory_conditions : nullptr;
            if (vc == nullptr) {
                player_index = player_index + 1;
                continue;
            }

            for (int cond = 0; cond < 12; ++cond) {
                SP_Victory_Info* info = &this->sp_victory[player_index][cond];
                int victory_type = info->VictoryType;
                if (victory_type == 0) {
                    continue;
                }

                if (victory_type == 4) {
                    int attrib_type = info->AttribType;
                    if (attrib_type == 6) {
                        vc->add_explore('\x01', info->Amount, '\x01');
                    } else if (attrib_type == 4) {
                        vc->add_attributes('\x01', 0x0b, info->Amount, '\0');
                    } else if (attrib_type == 3) {
                        vc->add_attributes('\x01', 0, info->Amount, '\0');
                    } else if (attrib_type == 2) {
                        vc->add_attributes('\x01', 2, info->Amount, '\0');
                    } else if (attrib_type == 1) {
                        vc->add_attributes('\x01', 1, info->Amount, '\0');
                    } else if (attrib_type == 0) {
                        vc->add_attributes('\x01', 3, info->Amount, '\0');
                    } else if (attrib_type == 5) {
                        vc->add_attributes('\x01', 6, info->Amount, '\0');
                    }
                } else if (victory_type == 6) {
                    vc->add_attributes('\x01', info->AttribType, info->Amount, '\0');
                } else if (victory_type == 5) {
                    RGE_Static_Object* obj = this->get_object_pointer(info->obj_ID);
                    vc->add_capture('\x01', obj, '\x01');
                } else if (victory_type == 3) {
                    RGE_Static_Object* dest_obj = this->get_object_pointer(info->dest_obj_ID);
                    if (dest_obj != nullptr) {
                        RGE_Static_Object* obj = this->get_object_pointer(info->obj_ID);
                        vc->add_bring('\x01', obj, dest_obj);
                    } else {
                        RGE_Static_Object* obj = this->get_object_pointer(info->obj_ID);
                        vc->add_bring('\x01', obj, info->x1, info->y1, info->x2, info->y2);
                    }
                } else if (victory_type == 2) {
                    if (info->x2 <= 0.0f) {
                        vc->add_create('\x01', info->ObjType, info->Amount, '\0');
                    } else {
                        vc->add_create('\x01', info->ObjType, info->Amount, info->x1, info->y1, info->x2, info->y2, '\0');
                    }
                } else if (victory_type == 7) {
                    ((TRIBE_Victory_Conditions*)vc)->add_tech('\x01', info->AttribType);
                } else if (victory_type == 1) {
                    if (info->ObjType != 0 && info->AllFlag != 0) {
                        vc->add_destroy('\x01', info->ObjType, (RGE_Player*)nullptr);
                    } else {
                        int target_player_id = info->PlayerID;
                        if (target_player_id == 0) {
                            RGE_Static_Object* obj = this->get_object_pointer(info->obj_ID);
                            if (obj != nullptr) {
                                vc->add_destroy('\x01', obj);
                            }
                        } else {
                            RGE_Player* target_player = this->world->players[target_player_id];
                            if (info->ObjType == 0) {
                                vc->add_destroy('\x01', target_player);
                            } else {
                                vc->add_destroy('\x01', info->ObjType, info->Amount, target_player);
                            }
                        }
                    }
                }
            }

            player_index = player_index + 1;
        } while (player_index < player_num - 1);
    }
}

// --- RGE_Tile_List ---
#include "../include/RGE_Tile_List.h"
#include "../include/RGE_Tile_List_Node.h"

RGE_Tile_List::RGE_Tile_List(int param_1) {
    // Source of truth: player.cpp.decomp @ 0x00471E40
    this->list = (RGE_Tile_List_Node*)calloc(param_1, sizeof(RGE_Tile_List_Node));
    this->list_size = param_1;
    this->num_active = 0;
    this->new_count = 0;
    this->collapse_list = 0;
}

void RGE_Tile_List::add_node(int param_1, int param_2) {
    // Source of truth: player.cpp.decomp @ 0x00471D70
    if (this->num_active >= this->list_size) {
        int new_size = this->list_size * 2;
        RGE_Tile_List_Node* new_list = (RGE_Tile_List_Node*)calloc(new_size, sizeof(RGE_Tile_List_Node));
        memcpy(new_list, this->list, this->list_size * sizeof(RGE_Tile_List_Node));
        free(this->list);
        this->list = new_list;
        this->list_size = new_size;
    }
    this->list[this->num_active].col = param_1;
    this->list[this->num_active].row = param_2;
    this->num_active++;
    this->new_count++;
}

void RGE_Tile_List::del_list() {
    // Source of truth: player.cpp.decomp @ 0x00471DF0
    this->num_active = 0;
    this->new_count = 0;
    if (this->collapse_list != 0) {
        free(this->list);
        this->list_size = 8;
        this->list = (RGE_Tile_List_Node*)calloc(8, sizeof(RGE_Tile_List_Node));
        this->collapse_list = 0;
    }
}

void RGE_Tile_List::get_list_info(RGE_Tile_List_Node** param_1, int* param_2) {
    // Source of truth: player.cpp.decomp @ 0x00471E90
    if (param_1 != nullptr) {
        *param_1 = this->list;
    }
    if (param_2 != nullptr) {
        *param_2 = this->num_active;
    }
}

int RGE_Tile_List::get_new_count() {
    // Source of truth: player.cpp.decomp @ 0x00471EB0
    int count = this->new_count;
    this->new_count = 0;
    return count;
}
