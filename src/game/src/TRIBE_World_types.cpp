// Implementations for types used by TRIBE_World init overrides.
#include "../include/TRIBE_Map.h"
#include "../include/TRIBE_World.h"
#include "../include/TRIBE_RMM_Database_Controller.h"
#include "../include/custom_debug.h"
#include "../include/TRIBE_Command.h"
#include "../include/RGE_Obj_Info.h"
#include "../include/RGE_Command_Create.h"
#include "../include/RGE_Command_Add_Attribute.h"
#include "../include/RGE_Command_Give_Attribute.h"
#include "../include/RGE_Command_Stop.h"
#include "../include/RGE_Command_Pause.h"
#include "../include/RGE_Command_Order.h"
#include "../include/RGE_Command_Formation.h"
#include "../include/RGE_Command_Create_Group.h"
#include "../include/RGE_Command_Destroy_Group.h"
#include "../include/RGE_Command_Add_To_Group.h"
#include "../include/RGE_Command_Remove_From_Group.h"
#include "../include/RGE_Command_Add_Waypoint.h"
#include "../include/RGE_Command_Group_Waypoint.h"
#include "../include/RGE_Command_AI_Order.h"
#include "../include/RGE_Command_Group_AI_Order.h"
#include "../include/RGE_Command_Resign.h"
#include "../include/TRIBE_Command_Give_Attribute.h"
#include "../include/TRIBE_Command_Trade_Attribute.h"
#include "../include/TRIBE_Command_Repair.h"
#include "../include/TRIBE_Command_Queue.h"
#include "../include/TRIBE_Command_Unload.h"
#include "../include/TRIBE_Command_Make.h"
#include "../include/TRIBE_Command_Research.h"
#include "../include/TRIBE_Action_Make_Obj.h"
#include "../include/TRIBE_Action_Make_Tech.h"
#include "../include/TRIBE_Command_Build.h"
#include "../include/TRIBE_Command_Game.h"
#include "../include/TRIBE_Command_Explore.h"
#include "../include/TRIBE_Command_Build_Wall.h"
#include "../include/TRIBE_Command_Cancel_Build.h"
#include "../include/TRIBE_Command_Attack_Ground.h"
#include "../include/TRIBE_Building_Object.h"
#include "../include/Production_Queue_Record.h"
#include "../include/TRIBE_Master_Building_Object.h"
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
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Task_List.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Timeline.h"
#include "../include/TPicture.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

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

static void rge_command_set_waiting_to_move(RGE_Static_Object* obj, int waiting_value) {
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* SetWaitingToMoveFn)(RGE_Static_Object*, int);
    void** vtable = *(void***)obj;
    SetWaitingToMoveFn fn = (SetWaitingToMoveFn)vtable[0x12C / 4];
    fn(obj, waiting_value);
}

static void rge_command_issue_work(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* WorkFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    WorkFn fn = (WorkFn)vtable[0xA0 / 4];
    fn(obj, target_value, x, y, z);
}

static void rge_command_issue_move_to(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* MoveToFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    MoveToFn fn = (MoveToFn)vtable[0x9C / 4];
    fn(obj, target_value, x, y, z);
}

static void rge_command_issue_order(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* OrderFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    OrderFn fn = (OrderFn)vtable[0x98 / 4];
    fn(obj, target_value, x, y, z);
}

static void rge_command_set_move_ai_state(UnitAIModule* unit_ai, int target_id, int target_type, float target_x, float target_y) {
    if (unit_ai == nullptr) {
        return;
    }

    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x28) = 0x2C6;
    *(int*)(ai + 0x30) = 0x262;
    *(int*)(ai + 0x34) = target_id;
    *(int*)(ai + 0x38) = target_type;
    *(float*)(ai + 0x3C) = target_x;
    *(float*)(ai + 0x40) = target_y;
    *(float*)(ai + 0x44) = 0.0f;
    *(float*)(ai + 0x48) = 0.0f;
}

struct tribe_unit_ai_notify_event {
    long caller;
    long recipient;
    long mType;
    long p1;
    long p2;
    long p3;
};

static void tribe_unit_ai_set_current_order(UnitAIModule* unit_ai, int order_value) {
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x50) = *(int*)(ai + 0x28);
    *(int*)(ai + 0x28) = order_value;
}

static void tribe_unit_ai_set_current_action(UnitAIModule* unit_ai, int action_value) {
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x54) = *(int*)(ai + 0x30);
    *(int*)(ai + 0x30) = action_value;
}

static void tribe_unit_ai_set_current_target(UnitAIModule* unit_ai, int target_id, int target_type, float target_x, float target_y, float target_z) {
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x58) = *(int*)(ai + 0x34);
    *(int*)(ai + 0x5C) = *(int*)(ai + 0x38);
    *(int*)(ai + 0x34) = target_id;
    *(int*)(ai + 0x38) = target_type;
    *(float*)(ai + 0x3C) = target_x;
    *(float*)(ai + 0x40) = target_y;
    *(float*)(ai + 0x44) = target_z;
}

static void tribe_unit_ai_remove_current_target(UnitAIModule* unit_ai) {
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    int current_target_type = *(int*)(ai + 0x38);
    *(int*)(ai + 0x58) = *(int*)(ai + 0x34);
    *(int*)(ai + 0x34) = -1;
    *(int*)(ai + 0x38) = -1;
    *(int*)(ai + 0x5C) = current_target_type;
    *(float*)(ai + 0x3C) = -1.0f;
    *(float*)(ai + 0x40) = -1.0f;
    *(float*)(ai + 0x44) = -1.0f;
}

static void tribe_unit_ai_purge_notify_queue(UnitAIModule* unit_ai, ulong update_time) {
    if (unit_ai == nullptr) {
        return;
    }

    unsigned char* ai = (unsigned char*)unit_ai;
    int notify_count = *(int*)(ai + 0x1C);
    if (0 < notify_count) {
        tribe_unit_ai_notify_event* notify_queue = (tribe_unit_ai_notify_event*)(*(void**)(ai + 0x24));
        for (int i = 0; i < notify_count; ++i) {
            int queued_action = (int)notify_queue[i].p1;
            int current_action = *(int*)(ai + 0x30);
            int current_order = *(int*)(ai + 0x28);

            if ((notify_queue[i].mType == 0x1FA) &&
                (((queued_action != 0x262) || (current_action == 0x262)) || (current_action == 0x268)) &&
                ((current_order == -1) && (current_action == queued_action))) {
                tribe_unit_ai_remove_current_target(unit_ai);
                typedef int(__thiscall* StopObjectFn)(UnitAIModule*, int);
                void** vtable = *(void***)unit_ai;
                StopObjectFn stop_object = (StopObjectFn)vtable[0x58 / 4];
                stop_object(unit_ai, 1);
                break;
            }
        }
    }

    *(int*)(ai + 0x1C) = 0;
    *(ulong*)(ai + 0xF4) = update_time;
}

static void tribe_unit_ai_set_tasked_by_player(UnitAIModule* unit_ai) {
    tribe_unit_ai_purge_notify_queue(unit_ai, 0);
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
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00433DC0
    if (p1.id == -1) {
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
void RGE_Command::do_command_order(RGE_Command_Order* p1) {
    // Source of truth: command.cpp.decomp @ 0x00433F20
    int unit_num = (int)p1->unit_num;
    float unit_num_float = (float)unit_num;
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);
    RGE_Static_Object* target = this->get_obj(p1->target);

    if (unit_num > 1) {
        float min_x = 10000.0f;
        float max_x = 0.0f;
        float min_y = 10000.0f;
        float max_y = 0.0f;
        float total_x = 0.0f;
        float total_y = 0.0f;

        for (int i = 0; i < unit_num; ++i) {
            RGE_Static_Object* obj = this->get_obj(units[i]);
            if (obj != nullptr) {
                if (min_x <= obj->world_x) {
                    if (max_x < obj->world_x) {
                        max_x = obj->world_x;
                    }
                } else {
                    min_x = obj->world_x;
                }

                if (min_y <= obj->world_y) {
                    if (max_y < obj->world_y) {
                        max_y = obj->world_y;
                    }
                } else {
                    min_y = obj->world_y;
                }

                total_x = total_x + obj->world_x;
                total_y = total_y + obj->world_y;
            }
        }

        if (((max_x - min_x) <= 8.0f) && ((max_y - min_y) <= 8.0f)) {
            if (unit_num_float == 0.0f) {
                return;
            }

            float center_x = total_x / unit_num_float;
            float center_y = total_y / unit_num_float;

            for (int index = 0; index < unit_num; ++index) {
                RGE_Static_Object* obj = this->get_obj(units[index]);
                if (obj != nullptr) {
                    obj->removeAllFromPathingGroup();
                    rge_command_set_waiting_to_move(obj, 1);

                    for (int group_index = 0; group_index < unit_num; ++group_index) {
                        if (group_index != index) {
                            obj->addToPathingGroup((int)units[group_index].id);
                        }
                    }

                    float adjusted_x = (obj->world_x - center_x) + p1->location_x;
                    float adjusted_y = (obj->world_y - center_y) + p1->location_y;

                    if (adjusted_x >= 0.0f) {
                        float map_width = (float)obj->owner->world->map->map_width;
                        if (map_width <= adjusted_x) {
                            adjusted_x = map_width - 1.0f;
                        }
                    } else {
                        adjusted_x = 1.0f;
                    }

                    if (adjusted_y >= 0.0f) {
                        float map_height = (float)obj->owner->world->map->map_height;
                        if (map_height <= adjusted_y) {
                            adjusted_y = map_height - 1.0f;
                        }
                    } else {
                        adjusted_y = 1.0f;
                    }

                    long order_target = 0;
                    if ((target != nullptr) && ((target->master_obj->radius_x > 0.0f) || (target->master_obj->radius_y > 0.0f))) {
                        order_target = (long)target;
                    }

                    rge_command_issue_order(obj, order_target, adjusted_x, adjusted_y, 0.0f);
                }
            }
            return;
        }
    }

    for (int index = 0; index < unit_num; ++index) {
        RGE_Static_Object* obj = this->get_obj(units[index]);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            rge_command_set_waiting_to_move(obj, 1);

            for (int group_index = 0; group_index < unit_num; ++group_index) {
                if (group_index != index) {
                    obj->addToPathingGroup((int)units[group_index].id);
                }
            }

            rge_command_issue_order(obj, (long)target, p1->location_x, p1->location_y, 0.0f);
        }
    }
}
void RGE_Command::do_command_work(RGE_Command_Order* p1) {
    // Source of truth: command.cpp.decomp @ 0x00434320
    int unit_num = (int)p1->unit_num;
    RGE_Static_Object* target = this->get_obj(p1->target);
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);

    for (int index = 0; index < unit_num; ++index) {
        RGE_Static_Object* obj = this->get_obj(units[index]);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            rge_command_set_waiting_to_move(obj, 1);

            for (int i = 0; i < unit_num; ++i) {
                if (i != index) {
                    obj->addToPathingGroup((int)units[i].id);
                }
            }

            rge_command_issue_work(obj, (long)target, p1->location_x, p1->location_y, 0.0f);
        }
    }
}
void RGE_Command::do_command_move(RGE_Command_Order* p1) {
    // Source of truth: command.cpp.decomp @ 0x00434400
    int unit_num = (int)p1->unit_num;
    float unit_num_float = (float)unit_num;
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);
    RGE_Static_Object* target = this->get_obj(p1->target);

    if (unit_num > 1) {
        float min_x = 10000.0f;
        float max_x = 0.0f;
        float min_y = 10000.0f;
        float max_y = 0.0f;
        float total_x = 0.0f;
        float total_y = 0.0f;

        for (int i = 0; i < unit_num; ++i) {
            RGE_Static_Object* obj = this->get_obj(units[i]);
            if (obj != nullptr) {
                if (min_x <= obj->world_x) {
                    if (max_x < obj->world_x) {
                        max_x = obj->world_x;
                    }
                } else {
                    min_x = obj->world_x;
                }

                if (min_y <= obj->world_y) {
                    if (max_y < obj->world_y) {
                        max_y = obj->world_y;
                    }
                } else {
                    min_y = obj->world_y;
                }

                total_x = total_x + obj->world_x;
                total_y = total_y + obj->world_y;
            }
        }

        if (((max_x - min_x) <= 8.0f) && ((max_y - min_y) <= 8.0f)) {
            if (unit_num_float == 0.0f) {
                return;
            }

            float center_x = total_x / unit_num_float;
            float center_y = total_y / unit_num_float;

            for (int index = 0; index < unit_num; ++index) {
                RGE_Static_Object* obj = this->get_obj(units[index]);
                if (obj != nullptr) {
                    obj->removeAllFromPathingGroup();
                    rge_command_set_waiting_to_move(obj, 1);

                    for (int group_index = 0; group_index < unit_num; ++group_index) {
                        if (group_index != index) {
                            obj->addToPathingGroup((int)units[group_index].id);
                        }
                    }

                    float adjusted_x = (obj->world_x - center_x) + p1->location_x;
                    float adjusted_y = (obj->world_y - center_y) + p1->location_y;

                    if (adjusted_x >= 0.0f) {
                        float map_width = (float)obj->owner->world->map->map_width;
                        if (map_width <= adjusted_x) {
                            adjusted_x = map_width - 1.0f;
                        }
                    } else {
                        adjusted_x = 1.0f;
                    }

                    if (adjusted_y >= 0.0f) {
                        float map_height = (float)obj->owner->world->map->map_height;
                        if (map_height <= adjusted_y) {
                            adjusted_y = map_height - 1.0f;
                        }
                    } else {
                        adjusted_y = 1.0f;
                    }

                    long move_target = (long)target;
                    if ((target == nullptr) || ((target->master_obj->radius_x <= 0.0f) && (target->master_obj->radius_y <= 0.0f))) {
                        move_target = 0;
                    }
                    rge_command_issue_move_to(obj, move_target, adjusted_x, adjusted_y, 0.0f);

                    UnitAIModule* unit_ai = obj->unitAIValue;
                    if (unit_ai != nullptr) {
                        int target_id = -1;
                        int target_type = -1;
                        if ((target != nullptr) && ((target->master_obj->radius_x > 0.0f) || (target->master_obj->radius_y > 0.0f))) {
                            target_id = (int)target->id;
                            target_type = (int)target->master_obj->object_group;
                        }
                        rge_command_set_move_ai_state(unit_ai, target_id, target_type, adjusted_x, adjusted_y);
                    }
                }
            }
            return;
        }
    }

    for (int index = 0; index < unit_num; ++index) {
        RGE_Static_Object* obj = this->get_obj(units[index]);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            rge_command_set_waiting_to_move(obj, 1);

            for (int group_index = 0; group_index < unit_num; ++group_index) {
                if (group_index != index) {
                    obj->addToPathingGroup((int)units[group_index].id);
                }
            }

            rge_command_issue_move_to(obj, (long)target, p1->location_x, p1->location_y, 0.0f);

            UnitAIModule* unit_ai = obj->unitAIValue;
            if (unit_ai != nullptr) {
                int target_id = -1;
                int target_type = -1;
                if ((target != nullptr) && ((target->master_obj->radius_x > 0.0f) || (target->master_obj->radius_y > 0.0f))) {
                    target_id = (int)target->id;
                    target_type = (int)target->master_obj->object_group;
                }
                rge_command_set_move_ai_state(unit_ai, target_id, target_type, p1->location_x, p1->location_y);
            }
        }
    }
}
void RGE_Command::do_command_formation(RGE_Command_Formation* p1) {
    // Source of truth: command.cpp.decomp @ 0x00434A00
    int unit_num = p1->unitNum;
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);

    if (unit_num <= 1) {
        return;
    }

    int i = 0;
    RGE_Static_Object* reference_unit = nullptr;
    float closest_distance = 0.0f;
    while (i < unit_num) {
        RGE_Static_Object* obj = this->get_obj(units[i]);
        if (obj != nullptr) {
            float distance = sqrtf(obj->world_x * obj->world_x + obj->world_y * obj->world_y);
            if ((i == 0) || (distance < closest_distance)) {
                reference_unit = obj;
                closest_distance = distance;
            }
        }
        i = i + 1;
    }

    float adjusted_y_location = 1.0f;
    float temp_x = 1.0f;
    int flip_pair = 0;

    switch (p1->formationID) {
    case 1:
    case 4:
    case 5:
        adjusted_y_location = 1.5f;
        temp_x = 1.5f;
        break;
    case 2:
    case 3:
        adjusted_y_location = 2.0f;
        temp_x = 2.0f;
        break;
    default:
        adjusted_y_location = 1.0f;
        temp_x = 1.0f;
        break;
    }

    for (int index = 0; index < unit_num; ++index) {
        RGE_Static_Object* obj = this->get_obj(units[index]);
        if (obj == nullptr) {
            continue;
        }

        obj->removeAllFromPathingGroup();
        rge_command_set_waiting_to_move(obj, 1);

        for (int group_index = 0; group_index < unit_num; ++group_index) {
            if (group_index != index) {
                obj->addToPathingGroup((int)units[group_index].id);
            }
        }

        if ((reference_unit != nullptr) && (obj != reference_unit)) {
            float temp_y = reference_unit->world_x;
            float adjusted_x_location = reference_unit->world_y;

            switch (p1->formationID) {
            case 0:
                temp_y = temp_y + adjusted_y_location;
                adjusted_y_location = adjusted_y_location + 1.0f;
                adjusted_x_location = adjusted_x_location + temp_x;
                temp_x = temp_x + 1.0f;
                break;
            case 1:
                temp_y = temp_y + adjusted_y_location;
                adjusted_y_location = adjusted_y_location + 1.5f;
                adjusted_x_location = adjusted_x_location - temp_x;
                temp_x = temp_x + 1.5f;
                break;
            case 2:
                temp_y = temp_y + adjusted_y_location;
                adjusted_y_location = adjusted_y_location + 2.0f;
                break;
            case 3:
                adjusted_x_location = adjusted_x_location + temp_x;
                temp_x = temp_x + 2.0f;
                break;
            case 4:
                temp_y = temp_y + adjusted_y_location;
                if (flip_pair != 0) {
                    adjusted_x_location = adjusted_x_location + temp_x;
                    temp_x = temp_x + 1.5f;
                    adjusted_y_location = adjusted_y_location + 1.5f;
                    flip_pair = 0;
                } else {
                    adjusted_x_location = adjusted_x_location - temp_x;
                    flip_pair = 1;
                }
                break;
            case 5:
                temp_y = temp_y - adjusted_y_location;
                if (flip_pair != 0) {
                    adjusted_x_location = adjusted_x_location + temp_x;
                    temp_x = temp_x + 1.5f;
                    adjusted_y_location = adjusted_y_location + 1.5f;
                    flip_pair = 0;
                } else {
                    adjusted_x_location = adjusted_x_location - temp_x;
                    flip_pair = 1;
                }
                break;
            }

            rge_command_issue_move_to(obj, 0, temp_y, adjusted_x_location, 1.0f);
        }
    }
}
void RGE_Command::do_command_create_group(RGE_Command_Create_Group* p1) {
    // Source of truth: command.cpp.decomp @ 0x00435020
    RGE_Static_Object* commander = this->world->object(p1->groupCommander);
    if ((commander != nullptr) && (commander->owner->id == (ushort)p1->player_id)) {
        commander->commanderCreateGroup(p1->unitsToGroup, (int)p1->numberUnitsToGroup, p1->groupCommander, p1->groupRange);
    }
}
void RGE_Command::do_command_add_to_group(RGE_Command_Add_To_Group* p1) {
    // Source of truth: command.cpp.decomp @ 0x00435060
    RGE_Static_Object* commander = this->world->object(p1->groupCommander);
    if ((commander != nullptr) && (commander->owner->id == (ushort)p1->player_id)) {
        commander->commanderAddToGroup(p1->newUnit, p1->groupRange);
    }
}
void RGE_Command::do_command_remove_from_group(RGE_Command_Remove_From_Group* p1) {
    // Source of truth: command.cpp.decomp @ 0x004350A0
    RGE_Static_Object* commander = this->world->object(p1->groupCommander);
    if ((commander != nullptr) && (commander->owner->id == (ushort)p1->player_id)) {
        commander->commanderRemoveFromGroup(p1->unit);
    }
}
void RGE_Command::do_command_destroy_group(RGE_Command_Destroy_Group* p1) {
    // Source of truth: command.cpp.decomp @ 0x004350E0
    RGE_Static_Object* commander = this->world->object(p1->groupCommander);
    if ((commander != nullptr) && (commander->owner->id == (ushort)p1->player_id)) {
        commander->commanderDestroyGroup();
    }
}
void RGE_Command::do_command_stop(RGE_Command_Stop* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434290
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);
    for (uint i = (uint)p1->unit_num; i != 0; --i) {
        RGE_Static_Object* obj = this->get_obj(*units);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            obj->stop();
        }
        units = units + 1;
    }
}
void RGE_Command::do_command_pause(RGE_Command_Pause* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x004342E0
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);
    for (uint i = (uint)p1->unit_num; i != 0; --i) {
        RGE_Static_Object* obj = this->get_obj(*units);
        if (obj != nullptr) {
            obj->pause();
        }
        units = units + 1;
    }
}
void RGE_Command::do_command_add_waypoint(RGE_Command_Add_Waypoint* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434F70
    RGE_Static_Object* obj = this->world->object(p1->recipient);
    if (obj != nullptr) {
        this->world->players[p1->player_id]->processAddWaypointCommand(p1->recipient, p1->waypoint, p1->numberWaypoints);
    }
}
void RGE_Command::do_command_group_waypoint(RGE_Command_Group_Waypoint* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434FB0
    RGE_Command_Group_Waypoint* p2 = p1;
    RGE_Obj_Info* recipients = (RGE_Obj_Info*)(p1 + 1);

    for (uint i = (uint)p1->unit_num; i != 0; --i) {
        RGE_Static_Object* obj = this->get_obj(*recipients);
        if (obj != nullptr) {
            XYZBYTEPoint waypoint;
            waypoint.x = p2->x;
            waypoint.y = p2->y;
            waypoint.z = 0;
            obj->owner->processAddWaypointCommand(obj->id, &waypoint, 1);
        }
        recipients = recipients + 1;
    }
}
void RGE_Command::do_command_ai_order(RGE_Command_AI_Order* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434D40
    RGE_Static_Object* obj = this->world->object(p1->recipient);
    if (obj != nullptr) {
        obj->removeAllFromPathingGroup();
        this->world->players[p1->player_id]->processAIOrder(
            p1->issuer,
            p1->recipient,
            (int)p1->orderType,
            p1->target,
            p1->targetOwner,
            p1->targetX,
            p1->targetY,
            p1->targetZ,
            p1->range,
            p1->immediate,
            p1->inFront,
            p1->orderPriority);
    }
}
void RGE_Command::do_command_group_ai_order(RGE_Command_Group_AI_Order* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434DC0
    RGE_Command_Group_AI_Order* p2 = p1;
    RGE_Obj_Info* recipients = (RGE_Obj_Info*)(p1 + 1);

    for (uint i = (uint)p1->recipient_count; i != 0; --i) {
        RGE_Static_Object* obj = this->get_obj(*recipients);
        if (obj != nullptr) {
            float target_x = p2->targetX;
            if (target_x == -1.0f) {
                target_x = obj->world_x;
            }

            float target_y = p2->targetY;
            if (target_y == -1.0f) {
                target_y = obj->world_y;
            }

            float target_z = p2->targetZ;
            if (target_z == -1.0f) {
                target_z = obj->world_z;
            }

            obj->removeAllFromPathingGroup();
            this->world->players[p2->player_id]->processAIOrder(
                p2->issuer,
                obj->id,
                (int)p2->orderType,
                p2->target,
                p2->targetOwner,
                target_x,
                target_y,
                target_z,
                p2->range,
                p2->immediate,
                p2->inFront,
                p2->orderPriority);
        }
        recipients = recipients + 1;
    }
}
void RGE_Command::do_command_resign(RGE_Command_Resign* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434EB0
    int multiplayer = rge_base_game->multiplayerGame();
    if (multiplayer == 0) {
        this->world->players[p1->player_id]->do_resign((int)p1->dropped);
        return;
    }

    int matching_total = 0;
    int matching_resigned = 0;
    int i = 1;
    rge_base_game->resigned[p1->comm_player_id] = 1;
    do {
        uint mapped_id = (uint)rge_base_game->playerID(i);
        if ((mapped_id == p1->player_id) && ((matching_total = matching_total + 1), rge_base_game->resigned[i] != 0)) {
            matching_resigned = matching_resigned + 1;
        }
        i = i + 1;
    } while (i < 9);

    if (matching_total == matching_resigned) {
        this->world->players[p1->player_id]->do_resign((int)p1->dropped);
    }
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
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00433E20
    uchar cmd = *(uchar*)p1;
    if (cmd == 0) {
        this->do_command_order((RGE_Command_Order*)p1);
        return;
    }
    if (cmd == 1) {
        this->do_command_stop((RGE_Command_Stop*)p1);
        return;
    }
    if (cmd == 2) {
        this->do_command_work((RGE_Command_Order*)p1);
        return;
    }
    if (cmd == 3) {
        this->do_command_move((RGE_Command_Order*)p1);
        return;
    }
    if (cmd == 4) {
        this->do_command_create((RGE_Command_Create*)p1);
        return;
    }
    if (cmd == 5) {
        this->do_command_add_attribute((RGE_Command_Add_Attribute*)p1);
        return;
    }
    if (cmd == 6) {
        this->do_command_formation((RGE_Command_Formation*)p1);
        return;
    }
    if (cmd == 7) {
        this->do_command_give_attribute((RGE_Command_Give_Attribute*)p1);
        return;
    }
    if (cmd == 8) {
        this->do_command_create_group((RGE_Command_Create_Group*)p1);
        return;
    }
    if (cmd == 9) {
        this->do_command_destroy_group((RGE_Command_Destroy_Group*)p1);
        return;
    }
    if (cmd == 0xE) {
        this->do_command_add_to_group((RGE_Command_Add_To_Group*)p1);
        return;
    }
    if (cmd == 0xF) {
        this->do_command_remove_from_group((RGE_Command_Remove_From_Group*)p1);
        return;
    }
    if (cmd == 0xC) {
        this->do_command_add_waypoint((RGE_Command_Add_Waypoint*)p1);
        return;
    }
    if (cmd == 0x10) {
        this->do_command_group_waypoint((RGE_Command_Group_Waypoint*)p1);
        return;
    }
    if (cmd == 0xA) {
        this->do_command_ai_order((RGE_Command_AI_Order*)p1);
        return;
    }
    if (cmd == 0x11) {
        this->do_command_group_ai_order((RGE_Command_Group_AI_Order*)p1);
        return;
    }
    if (cmd == 0xB) {
        this->do_command_resign((RGE_Command_Resign*)p1);
        return;
    }
}
void RGE_Command::command_order(RGE_Static_Object** p1, short p2, RGE_Static_Object* p3, float p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x00435320
    int count = (int)p2;
    int size = count * 4 + 0x14;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    if (p3 == nullptr) {
        cmd->target.id = -1;
    }
    else {
        cmd->target.id = p3->id;
    }
    cmd->command = 0;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p4;
    cmd->location_y = p5;

    this->submit(cmd, size);
}
void RGE_Command::command_stop(RGE_Static_Object** p1, short p2) {
    // Source of truth: command.cpp.decomp @ 0x00435420
    int count = (int)p2;
    int size = count * 4 + 2;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 2);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Stop* cmd = (RGE_Command_Stop*)raw;
    cmd->command = 1;
    cmd->unit_num = (uchar)p2;

    this->submit(cmd, size);
}
void RGE_Command::command_stop(int p1, int* p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x004354F0
    (void)p1;
    if ((p2 == nullptr) || (p3 <= 0)) {
        return;
    }

    int size = p3 * 4 + 2;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 2);
    if (p3 > 0) {
        int idx = 0;
        do {
            ids[idx] = p2[idx];
            idx = idx + 1;
        } while (idx < p3);
    }

    RGE_Command_Stop* cmd = (RGE_Command_Stop*)raw;
    cmd->command = 1;
    cmd->unit_num = (uchar)p3;

    this->submit(cmd, size);
}
void RGE_Command::command_pause(int p1, int* p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x004355A0
    (void)p1;
    if ((p2 == nullptr) || (p3 <= 0)) {
        return;
    }

    int size = p3 * 4 + 2;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 2);
    if (p3 > 0) {
        int idx = 0;
        do {
            ids[idx] = p2[idx];
            idx = idx + 1;
        } while (idx < p3);
    }

    RGE_Command_Pause* cmd = (RGE_Command_Pause*)raw;
    cmd->command = 0xD;
    cmd->unit_num = (uchar)p3;

    this->submit(cmd, size);
}
void RGE_Command::command_work(RGE_Static_Object** p1, short p2, RGE_Static_Object* p3, float p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x00435620
    int count = (int)p2;
    int size = count * 4 + 0x14;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    if (p3 == nullptr) {
        cmd->target.id = -1;
    }
    else {
        cmd->target.id = p3->id;
    }
    cmd->command = 2;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p4;
    cmd->location_y = p5;

    this->submit(cmd, size);
}
void RGE_Command::command_work(int p1, int* p2, int p3, int p4, int p5, float p6, float p7) {
    // Source of truth: command.cpp.decomp @ 0x00435720
    (void)p1;
    (void)p5;
    if ((p2 == nullptr) || (p3 <= 0)) {
        return;
    }

    int size = p3 * 4 + 0x14;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (p3 > 0) {
        int idx = 0;
        do {
            ids[idx] = p2[idx];
            idx = idx + 1;
        } while (idx < p3);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    cmd->location_x = p6;
    cmd->command = 2;
    cmd->unit_num = (uchar)p3;
    cmd->target.id = p4;
    cmd->location_y = p7;

    this->submit(cmd, size);
}
void RGE_Command::command_move(RGE_Static_Object** p1, short p2, RGE_Static_Object* p3, float p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x00435810
    int count = (int)p2;
    int size = count * 4 + 0x14;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    if (p3 == nullptr) {
        cmd->target.id = -1;
    }
    else {
        cmd->target.id = p3->id;
    }
    cmd->command = 3;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p4;
    cmd->location_y = p5;

    this->submit(cmd, size);
}
void RGE_Command::command_move(int p1, int* p2, int p3, int p4, int p5, float p6, float p7) {
    // Source of truth: command.cpp.decomp @ 0x00435900
    (void)p1;
    (void)p5;
    if ((p2 == nullptr) || (p3 <= 0)) {
        return;
    }

    int size = p3 * 4 + 0x14;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (p3 > 0) {
        int idx = 0;
        do {
            ids[idx] = p2[idx];
            idx = idx + 1;
        } while (idx < p3);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    cmd->command = 3;
    cmd->unit_num = (uchar)p3;
    cmd->target.id = p4;
    cmd->location_x = p6;
    cmd->location_y = p7;

    this->submit(cmd, size);
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
void RGE_Command::command_formation(RGE_Static_Object** p1, int p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x00435AE0
    int size = p2 * 4 + 0xC;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0xC);
    if (p2 > 0) {
        for (int i = 0; i < p2; ++i) {
            RGE_Static_Object* obj = p1[i];
            if (obj == nullptr) {
                ids[i] = -1;
            }
            else {
                ids[i] = (int)obj->id;
            }
        }
    }

    RGE_Command_Formation* cmd = (RGE_Command_Formation*)raw;
    cmd->command = 6;
    cmd->unitNum = p2 & 0xFF;
    cmd->formationID = p3;

    this->submit(cmd, size);
}
void RGE_Command::command_create_group(int p1, int p2, int* p3, int p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x00435BB0
    RGE_Command_Create_Group* cmd = (RGE_Command_Create_Group*)calloc(1, sizeof(RGE_Command_Create_Group));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 8;
    cmd->player_id = (uchar)p1;
    cmd->groupCommander = p2;
    if (p4 > 0) {
        int* dst = cmd->unitsToGroup;
        int* src = p3;
        int count = p4;
        do {
            *dst = *src;
            dst = dst + 1;
            src = src + 1;
            count = count - 1;
        } while (count != 0);
    }
    cmd->numberUnitsToGroup = (uchar)p4;
    cmd->groupRange = p5;

    this->submit(cmd, sizeof(RGE_Command_Create_Group));
}
void RGE_Command::command_add_to_group(int p1, int p2, int p3, float p4) {
    // Source of truth: command.cpp.decomp @ 0x00435C50
    RGE_Command_Add_To_Group* cmd = (RGE_Command_Add_To_Group*)calloc(1, sizeof(RGE_Command_Add_To_Group));
    if (cmd == nullptr) {
        return;
    }

    cmd->groupCommander = p2;
    cmd->command = 0xE;
    cmd->player_id = (uchar)p1;
    cmd->newUnit = p3;
    cmd->groupRange = p4;

    this->submit(cmd, sizeof(RGE_Command_Add_To_Group));
}
void RGE_Command::command_remove_from_group(int p1, int p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x00435CD0
    RGE_Command_Remove_From_Group* cmd = (RGE_Command_Remove_From_Group*)calloc(1, sizeof(RGE_Command_Remove_From_Group));
    if (cmd == nullptr) {
        return;
    }

    cmd->groupCommander = p2;
    cmd->command = 0xF;
    cmd->player_id = (uchar)p1;
    cmd->unit = p3;

    this->submit(cmd, sizeof(RGE_Command_Remove_From_Group));
}
void RGE_Command::command_destroy_group(int p1, int p2) {
    // Source of truth: command.cpp.decomp @ 0x00435D40
    RGE_Command_Destroy_Group* cmd = (RGE_Command_Destroy_Group*)calloc(1, sizeof(RGE_Command_Destroy_Group));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 9;
    cmd->player_id = (uchar)p1;
    cmd->groupCommander = p2;

    this->submit(cmd, sizeof(RGE_Command_Destroy_Group));
}
void RGE_Command::command_ai_order(int p1, int p2, int p3, int p4, int p5, int p6, float p7, float p8, float p9, float p10, uchar p11, uchar p12, uchar p13) {
    // Source of truth: command.cpp.decomp @ 0x00435D90
    RGE_Command_AI_Order* cmd = (RGE_Command_AI_Order*)calloc(1, sizeof(RGE_Command_AI_Order));
    if (cmd == nullptr) {
        return;
    }

    cmd->player_id = (uchar)p1;
    cmd->issuer = (uchar)p2;
    cmd->orderType = (short)p4;
    cmd->orderPriority = p13;
    cmd->targetOwner = (uchar)p6;
    cmd->targetX = p7;
    cmd->targetY = p8;
    cmd->targetZ = p9;
    cmd->command = 0xA;
    cmd->recipient = p3;
    cmd->target = p5;
    cmd->range = p10;
    cmd->immediate = p11;
    cmd->inFront = p12;

    this->submit(cmd, sizeof(RGE_Command_AI_Order));
}
void RGE_Command::command_group_ai_order(int p1, int p2, RGE_Static_Object** p3, short p4, int p5, int p6, int p7, float p8, float p9, float p10, float p11, uchar p12, uchar p13, uchar p14) {
    // Source of truth: command.cpp.decomp @ 0x00435EA0
    if ((p3 == nullptr) || (p4 <= 0)) {
        return;
    }

    int count = (int)p4;
    int size = count * 4 + 0x24;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* recipients = (int*)(raw + 0x24);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p3[idx];
            if (obj == nullptr) {
                recipients[idx] = -1;
            }
            else {
                recipients[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Group_AI_Order* cmd = (RGE_Command_Group_AI_Order*)raw;
    cmd->issuer = (uchar)p2;
    cmd->orderPriority = p14;
    cmd->targetOwner = (uchar)p7;
    cmd->recipient_count = (uchar)p4;
    cmd->targetX = p8;
    cmd->targetY = p9;
    cmd->target = p6;
    cmd->targetZ = p10;
    cmd->range = p11;
    cmd->command = 0x11;
    cmd->player_id = (uchar)p1;
    cmd->orderType = p5;
    cmd->immediate = p12;
    cmd->inFront = p13;

    this->submit(cmd, size);
}
void RGE_Command::command_resign(int p1, int p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x00435FE0
    RGE_Command_Resign* cmd = (RGE_Command_Resign*)calloc(1, sizeof(RGE_Command_Resign));
    if (cmd == nullptr) {
        return;
    }

    cmd->comm_player_id = (uchar)p2;
    cmd->command = 0xB;
    cmd->player_id = (uchar)p1;
    cmd->dropped = (uchar)p3;

    this->submit(cmd, sizeof(RGE_Command_Resign));
}
void RGE_Command::command_add_waypoint(int p1, int p2, XYZBYTEPoint* p3, int p4) {
    // Source of truth: command.cpp.decomp @ 0x00436030
    RGE_Command_Add_Waypoint* cmd = (RGE_Command_Add_Waypoint*)calloc(1, sizeof(RGE_Command_Add_Waypoint));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0xC;
    cmd->player_id = (uchar)p1;
    cmd->recipient = p2;
    cmd->numberWaypoints = (uchar)p4;
    if (p4 > 0) {
        XYZBYTEPoint* dst = cmd->waypoint;
        XYZBYTEPoint* src = p3;
        int count = p4;
        do {
            dst->x = src->x;
            dst->y = src->y;
            dst->z = src->z;
            dst = dst + 1;
            src = src + 1;
            count = count - 1;
        } while (count != 0);
    }

    this->submit(cmd, sizeof(RGE_Command_Add_Waypoint));
}
void RGE_Command::command_add_waypoint(int p1, int p2, uchar p3, uchar p4, uchar p5) {
    // Source of truth: command.cpp.decomp @ 0x004360D0
    RGE_Command_Add_Waypoint* cmd = (RGE_Command_Add_Waypoint*)calloc(1, sizeof(RGE_Command_Add_Waypoint));
    if (cmd == nullptr) {
        return;
    }

    cmd->waypoint[0].x = p3;
    cmd->command = 0xC;
    cmd->player_id = (uchar)p1;
    cmd->recipient = p2;
    cmd->numberWaypoints = 1;
    cmd->waypoint[0].y = p4;
    cmd->waypoint[0].z = p5;

    this->submit(cmd, sizeof(RGE_Command_Add_Waypoint));
}
void RGE_Command::command_group_waypoint(RGE_Static_Object** p1, short p2, uchar p3, uchar p4) {
    // Source of truth: command.cpp.decomp @ 0x00436150
    int count = (int)p2;
    int size = count * 4 + 4;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 4);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Group_Waypoint* cmd = (RGE_Command_Group_Waypoint*)raw;
    cmd->command = 0x10;
    cmd->unit_num = (uchar)p2;
    cmd->x = p3;
    cmd->y = p4;

    this->submit(cmd, size);
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

// --- TRIBE_Command ---

TRIBE_Command::TRIBE_Command(RGE_Game_World* world, TCommunications_Handler* comm)
    : RGE_Command(world, comm) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509720
}

TRIBE_Command::~TRIBE_Command() {}
void TRIBE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* p1) {
    // Source of truth: tcommand.cpp.decomp indicates TRIBE-specific handler lives in vt[4] (+0x10).
    // Keep base command-id-7 behavior intact on vt[0].
    RGE_Command::do_command_give_attribute(p1);
}
void TRIBE_Command::do_command(void* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509770
    (void)debug_rand("C:\\msdev\\work\\age1_x1\\tcommand.cpp", 0x3F);

    uchar cmd = *(uchar*)p1;
    switch (cmd) {
    case 4:
        this->do_command_tribe_create((RGE_Command_Create*)p1);
        return;
    case 100:
        this->do_command_make((TRIBE_Command_Make*)p1);
        return;
    case 0x65:
        this->do_command_research((TRIBE_Command_Research*)p1);
        return;
    case 0x66:
        this->do_command_build((TRIBE_Command_Build*)p1);
        return;
    case 0x67:
        this->do_command_game((TRIBE_Command_Game*)p1);
        return;
    case 0x68:
        this->do_command_explore((TRIBE_Command_Explore*)p1);
        return;
    case 0x69:
        this->do_command_build_wall((TRIBE_Command_Build_Wall*)p1);
        return;
    case 0x6A:
        this->do_command_cancel_build((TRIBE_Command_Cancel_Build*)p1);
        return;
    case 0x6B:
        this->do_command_attack_ground((TRIBE_Command_Attack_Ground*)p1);
        return;
    case 0x6C:
        // TRIBE-specific give-attribute handler lives in vt[4] (+0x10).
        // Use an explicit vtable dispatch to match the original ASM `CALL [vtable + 0x10]`.
        {
            typedef void(__thiscall* GiveAttrFn)(TRIBE_Command*, TRIBE_Command_Give_Attribute*);
            void** vtable = *(void***)this;
            GiveAttrFn fn = (GiveAttrFn)vtable[0x10 / 4];
            fn(this, (TRIBE_Command_Give_Attribute*)p1);
        }
        return;
    case 0x6D:
        this->do_command_trade_attribute((TRIBE_Command_Trade_Attribute*)p1);
        return;
    case 0x6E:
        this->do_command_repair((TRIBE_Command_Repair*)p1);
        return;
    case 0x6F:
        this->do_command_unload((TRIBE_Command_Unload*)p1);
        return;
    case 0x77:
        this->do_command_queue((TRIBE_Command_Queue*)p1);
        return;
    default:
        RGE_Command::do_command(p1);
        return;
    }
}
void TRIBE_Command::do_command_tribe_create(RGE_Command_Create* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509910
    int player_index = (uint)p1->player_id;
    int object_index = (int)p1->obj_catagory;

    RGE_Player* player = this->world->players[player_index];
    RGE_Master_Static_Object* master = player->master_objects[object_index];
    if (master->unit_level == 1) {
        p1->location_z = 4.0f;
    }

    RGE_Static_Object* obj = master->make_new_obj(player, p1->location_x, p1->location_y, p1->location_z);
    if (obj->master_obj->master_type == 'P') {
        ((TRIBE_Building_Object*)obj)->build(10000.0f);
    }
}
void TRIBE_Command::do_command_make(TRIBE_Command_Make* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509980
    if ((this->world == nullptr) || (this->world->players == nullptr) || (p1 == nullptr)) {
        return;
    }

    TRIBE_Building_Object* building = (TRIBE_Building_Object*)this->world->object(p1->unit_id);
    TRIBE_Player* player = (TRIBE_Player*)this->world->players[p1->unit_player_id];

    short work_type = 0;
    if (building == nullptr) {
        work_type = 0x67;
    } else if ((building->production_queue_actions != nullptr) && (building->production_queue_actions->get_action() != nullptr)) {
        work_type = building->production_queue_actions->get_action()->type();
    }

    if ((building != nullptr) && (work_type != 0x67) && (work_type != 0x66)) {
        TRIBE_Action_Make_Obj* action = new TRIBE_Action_Make_Obj((RGE_Action_Object*)building, p1->obj_id, p1->unique_id, 0);
        if (action != nullptr) {
            typedef void(__thiscall* AddActionFn)(TRIBE_Building_Object*, RGE_Action*);
            void** vtable = *(void***)building;
            AddActionFn add_action = (AddActionFn)vtable[0x208 / 4];
            add_action(building, action);
        }

        UnitAIModule* unit_ai = building->unitAIValue;
        if (unit_ai != nullptr) {
            tribe_unit_ai_set_current_action(unit_ai, 0x26C);
            tribe_unit_ai_set_current_target(unit_ai, p1->unique_id, -1, -1.0f, -1.0f, -1.0f);
        }
    } else if (player != nullptr) {
        player->cancelTrain(0, (int)p1->obj_id, p1->unit_id, p1->unique_id);
    }
}
void TRIBE_Command::do_command_research(TRIBE_Command_Research* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509AF0
    if ((this->world == nullptr) || (this->world->players == nullptr) || (p1 == nullptr)) {
        return;
    }

    TRIBE_Building_Object* building = (TRIBE_Building_Object*)this->world->object(p1->unit_id);
    TRIBE_Player* player = (TRIBE_Player*)this->world->players[p1->unit_player_id];

    short work_type = 0;
    if (building == nullptr) {
        work_type = 0x67;
    } else if ((building->production_queue_actions != nullptr) && (building->production_queue_actions->get_action() != nullptr)) {
        work_type = building->production_queue_actions->get_action()->type();
    }

    if ((building != nullptr) && (work_type != 0x67) && (work_type != 0x66)) {
        TRIBE_Action_Make_Tech* action = new TRIBE_Action_Make_Tech((RGE_Action_Object*)building, p1->tech_id, p1->unique_id);
        if (action != nullptr) {
            typedef void(__thiscall* AddActionFn)(TRIBE_Building_Object*, RGE_Action*);
            void** vtable = *(void***)building;
            AddActionFn add_action = (AddActionFn)vtable[0x208 / 4];
            add_action(building, action);
        }

        UnitAIModule* unit_ai = building->unitAIValue;
        if (unit_ai != nullptr) {
            tribe_unit_ai_set_current_action(unit_ai, 0x26C);
            tribe_unit_ai_set_current_target(unit_ai, p1->unique_id, -1, -1.0f, -1.0f, -1.0f);
        }
    } else if (player != nullptr) {
        player->cancelResearch((int)p1->tech_id, p1->unit_id, -1, p1->unique_id);
    }
}
void TRIBE_Command::do_command_build(TRIBE_Command_Build* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509C60
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    TRIBE_Player* player = (TRIBE_Player*)this->world->players[p1->unit_player_id];
    if (player == nullptr || p1->obj_id == -1) {
        return;
    }

    TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)player->master_objects[p1->obj_id];
    if (master == nullptr) {
        return;
    }

    int blocking_object = 0;
    uchar placement_result = master->check_placement(player, p1->location_x, p1->location_y, &blocking_object, 1, 1, 1, 1, 1, 1);

    int unit_num = (int)p1->unit_num;
    int* unit_ids = (int*)(p1 + 1);

    if (placement_result != 0) {
        if (unit_num > 0) {
            RGE_Static_Object* first = this->get_obj(RGE_Obj_Info{ unit_ids[0] });
            if (first != nullptr) {
                player->cancelBuild((int)placement_result, 1, (int)p1->obj_id, p1->location_x, p1->location_y, p1->unique_id, (int)first->id);
            }
        }
        return;
    }

    if (player->pay_obj_cost(p1->obj_id, 1.0f, 0) == 0) {
        if (unit_num > 0) {
            RGE_Static_Object* first = this->get_obj(RGE_Obj_Info{ unit_ids[0] });
            if (first != nullptr) {
                player->cancelBuild(0, 1, (int)p1->obj_id, p1->location_x, p1->location_y, p1->unique_id, (int)first->id);
            }
        }
        return;
    }

    RGE_Static_Object* built_obj = master->make_new_obj(player, p1->location_x, p1->location_y, 0.0f, p1->unique_id);
    if (built_obj == nullptr) {
        return;
    }

    for (int i = 0; i < unit_num; ++i) {
        RGE_Static_Object* unit = this->get_obj(RGE_Obj_Info{ unit_ids[i] });
        if (unit != nullptr) {
            unit->removeAllFromPathingGroup();
            rge_command_issue_order(unit, (long)built_obj, p1->location_x, p1->location_y, 0.0f);
        }
    }
}
void TRIBE_Command::place_line_of_walls(TRIBE_Player* p1, TRIBE_Master_Building_Object* p2, int p3, int p4, int p5, int p6, int p7, RGE_Static_Object** p8) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A010
    if (p1 == nullptr || p2 == nullptr) {
        return;
    }

    int x_step = 0;
    if (p4 != p6) {
        x_step = (p6 <= p4) ? -1 : 1;
    }

    int y_step = 0;
    if (p5 != p7) {
        y_step = (p7 <= p5) ? -1 : 1;
    }

    int x = p4;
    int y = p5;
    while (true) {
        int blocking = 0;
        char blocked = (char)p2->check_placement(p1, (float)x + 0.5f, (float)y + 0.5f, &blocking, 1, (uchar)p2->id, 0, 1, 1, 1);
        if (blocked == 0) {
            if (p1->pay_obj_cost(p2->id, 1.0f, 0) == 0) {
                return;
            }

            RGE_Static_Object* wall = p2->make_new_obj(p1, (float)x + 0.5f, (float)y + 0.5f, 0.0f, p3);
            if (wall != nullptr && p8 != nullptr && *p8 == nullptr) {
                *p8 = wall;
            }
        }

        if (x == p6 && y == p7) {
            break;
        }

        x += x_step;
        y += y_step;
    }
}
void TRIBE_Command::do_command_build_wall(TRIBE_Command_Build_Wall* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509E10
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    TRIBE_Player* player = (TRIBE_Player*)this->world->players[p1->unit_player_id];
    if (player == nullptr || p1->obj_id == -1) {
        return;
    }

    TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)player->master_objects[p1->obj_id];
    if (master == nullptr) {
        return;
    }

    RGE_Static_Object* first_built = nullptr;

    int x1 = (int)p1->x1;
    int y1 = (int)p1->y1;
    int x2 = (int)p1->x2;
    int y2 = (int)p1->y2;

    int abs_dy = y2 - y1;
    if (abs_dy < 0) abs_dy = -abs_dy;
    int abs_dx = x2 - x1;
    if (abs_dx < 0) abs_dx = -abs_dx;

    if (abs_dy == abs_dx) {
        this->place_line_of_walls(player, master, p1->unique_id, x1, y1, x2, y2, &first_built);
    }
    else if (abs_dy < abs_dx) {
        this->place_line_of_walls(player, master, p1->unique_id, x1, y1, x2, y1, &first_built);

        if (y1 < y2) {
            this->place_line_of_walls(player, master, p1->unique_id, x2, y1 + 1, x2, y2, &first_built);
        }
        else if (y2 < y1) {
            this->place_line_of_walls(player, master, p1->unique_id, x2, y1 - 1, x2, y2, &first_built);
        }
    }
    else {
        this->place_line_of_walls(player, master, p1->unique_id, x1, y1, x1, y2, &first_built);

        if (x1 < x2) {
            this->place_line_of_walls(player, master, p1->unique_id, x1 + 1, y2, x2, y2, &first_built);
        }
        else if (x2 < x1) {
            this->place_line_of_walls(player, master, p1->unique_id, x1 - 1, y2, x2, y2, &first_built);
        }
    }

    if (first_built == nullptr) {
        return;
    }

    int* unit_ids = (int*)(p1 + 1);
    int unit_num = (int)p1->unit_num;
    for (int i = 0; i < unit_num; ++i) {
        RGE_Static_Object* unit = this->get_obj(RGE_Obj_Info{ unit_ids[i] });
        if (unit != nullptr) {
            unit->removeAllFromPathingGroup();
            rge_command_issue_order(unit, (long)first_built, first_built->world_x, first_built->world_y, 0.0f);
        }
    }
}
void TRIBE_Command::do_command_explore(TRIBE_Command_Explore* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A140 (ASM-audited for __ftol usage)
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    if (this->world->players[p1->unit_player_id] == nullptr) {
        return;
    }

    int unit_num = (int)p1->numUnits;
    if (unit_num <= 0) {
        return;
    }

    int* unit_ids = (int*)(p1 + 1);
    for (int i = 0; i < unit_num; ++i) {
        RGE_Static_Object* unit = this->get_obj(RGE_Obj_Info{ unit_ids[i] });
        if (unit != nullptr) {
            unit->removeAllFromPathingGroup();
            unit->explore((int)p1->targetXPosition, (int)p1->targetYPosition, 1);
        }
    }
}
void TRIBE_Command::do_command_game(TRIBE_Command_Game* p1) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050A1D0
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    switch (p1->game_command) {
    case 0: {
        RGE_Player* plr = this->world->players[p1->var1];
        if (plr != nullptr) {
            plr->set_relation((int)p1->var2, (uchar)(int)p1->var3);
        }
        if (rge_base_game != nullptr) {
            rge_base_game->notification(8, (int)p1->var1, (int)p1->var2, (int)p1->var4, 0);
        }
        this->world->update_mutual_allies();
        break;
    }
    case 1:
        // No dedicated setter exists yet; original calls RGE_Game_World::set_game_speed.
        this->world->game_speed = p1->var3;
        break;
    case 4:
        if (rge_base_game != nullptr) {
            rge_base_game->quick_build = (int)p1->var1;
        }
        break;
    case 5: {
        RGE_Player* plr = this->world->players[p1->var1];
        if (plr != nullptr) {
            plr->set_allied_victory((uchar)p1->var2);
        }
        break;
    }
    case 6:
        ((TRIBE_World*)this->world)->cheat(p1->var1, (short)(uchar)p1->var2);
        break;
    default:
        break;
    }
}
void TRIBE_Command::do_command_cancel_build(TRIBE_Command_Cancel_Build* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A490
    if (this->world == nullptr || p1 == nullptr) {
        return;
    }

    RGE_Static_Object* obj = this->world->object(p1->unit_id);
    if (obj != nullptr) {
        typedef void(__thiscall* CancelFn)(RGE_Static_Object*);
        void** vtable = *(void***)obj;
        CancelFn cancel = (CancelFn)vtable[0x240 / 4];
        cancel(obj);
    }
}
void TRIBE_Command::do_command_attack_ground(TRIBE_Command_Attack_Ground* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A4C0
    if (p1 == nullptr) {
        return;
    }

    int unit_num = (int)p1->unit_num;
    int* unit_ids = (int*)(p1 + 1);
    for (int i = 0; i < unit_num; ++i) {
        RGE_Static_Object* unit = this->get_obj(RGE_Obj_Info{ unit_ids[i] });
        if (unit != nullptr) {
            unit->attack(p1->location_x, p1->location_y, 0.0f, 1);
        }
    }
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
void TRIBE_Command::command_make(RGE_Static_Object* p1, short p2) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050A7F0 (debug-log side effect intentionally omitted)
    if (p1 == nullptr) {
        return;
    }

    TRIBE_Command_Make* cmd = (TRIBE_Command_Make*)calloc(1, sizeof(TRIBE_Command_Make));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 100;
    cmd->unit_id = (int)p1->id;
    cmd->unit_player_id = (uchar)p1->owner->id;
    cmd->obj_id = p2;
    cmd->unique_id = -1;

    this->submit(cmd, sizeof(TRIBE_Command_Make));
}
void TRIBE_Command::command_make(int p1, int p2, int p3, int p4) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050A860 (debug-log side effect intentionally omitted)
    if (p2 < 0) {
        return;
    }

    TRIBE_Command_Make* cmd = (TRIBE_Command_Make*)calloc(1, sizeof(TRIBE_Command_Make));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 100;
    cmd->unit_id = p2;
    cmd->unit_player_id = (uchar)p1;
    cmd->obj_id = (short)p3;
    cmd->unique_id = p4;

    this->submit(cmd, sizeof(TRIBE_Command_Make));
}
void TRIBE_Command::command_research(RGE_Static_Object* p1, short p2) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050A8D0 (debug-log side effect intentionally omitted)
    if (p1 == nullptr) {
        return;
    }

    TRIBE_Command_Research* cmd = (TRIBE_Command_Research*)calloc(1, sizeof(TRIBE_Command_Research));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x65;
    cmd->unit_id = (int)p1->id;
    cmd->unit_player_id = (uchar)p1->owner->id;
    cmd->tech_id = p2;
    cmd->unique_id = -1;

    this->submit(cmd, sizeof(TRIBE_Command_Research));
}
void TRIBE_Command::command_research(int p1, int p2, int p3, int p4) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050A940 (debug-log side effect intentionally omitted)
    if (p2 < 0) {
        return;
    }

    TRIBE_Command_Research* cmd = (TRIBE_Command_Research*)calloc(1, sizeof(TRIBE_Command_Research));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x65;
    cmd->unit_id = p2;
    cmd->unit_player_id = (uchar)p1;
    cmd->tech_id = (short)p3;
    cmd->unique_id = p4;

    this->submit(cmd, sizeof(TRIBE_Command_Research));
}
void TRIBE_Command::command_build(RGE_Static_Object** p1, short p2, short p3, float p4, float p5) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050A9B0 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = count * 4 + (int)sizeof(TRIBE_Command_Build);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Build));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Build* cmd = (TRIBE_Command_Build*)buffer;
    cmd->command = 0x66;
    cmd->unit_num = (uchar)p2;
    cmd->unit_player_id = (*p1 != nullptr) ? (uchar)(*p1)->owner->id : (uchar)0xFF;
    cmd->location_x = p4;
    cmd->location_y = p5;
    cmd->obj_id = p3;
    cmd->unique_id = -1;

    this->submit(buffer, size);
}
void TRIBE_Command::command_build(int p1, int* p2, int p3, int p4, float p5, float p6, int p7) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AA90 (debug-log side effect intentionally omitted)
    if (p2 == nullptr || p3 <= 0) {
        return;
    }

    int size = p3 * 4 + (int)sizeof(TRIBE_Command_Build);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Build));
    for (int i = 0; i < p3; ++i) {
        ids[i] = p2[i];
    }

    TRIBE_Command_Build* cmd = (TRIBE_Command_Build*)buffer;
    cmd->command = 0x66;
    cmd->unit_num = (uchar)p3;
    cmd->unit_player_id = (uchar)p1;
    cmd->location_x = p5;
    cmd->location_y = p6;
    cmd->obj_id = (short)p4;
    cmd->unique_id = p7;

    this->submit(buffer, size);
}
void TRIBE_Command::command_build_wall(RGE_Static_Object** p1, short p2, short p3, long p4, long p5, long p6, long p7) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AB30 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = count * 4 + (int)sizeof(TRIBE_Command_Build_Wall);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Build_Wall));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Build_Wall* cmd = (TRIBE_Command_Build_Wall*)buffer;
    cmd->command = 0x69;
    cmd->unit_num = (uchar)p2;
    cmd->unit_player_id = (*p1 != nullptr) ? (uchar)(*p1)->owner->id : (uchar)0xFF;
    cmd->obj_id = p3;

    if (p4 < 0) p4 = 0;
    if (p4 > 0xFF) p4 = 0xFF;
    if (p5 < 0) p5 = 0;
    if (p5 > 0xFF) p5 = 0xFF;
    if (p6 < 0) p6 = 0;
    if (p6 > 0xFF) p6 = 0xFF;
    if (p7 < 0) p7 = 0;
    if (p7 > 0xFF) p7 = 0xFF;

    cmd->x1 = (uchar)p4;
    cmd->y1 = (uchar)p5;
    cmd->x2 = (uchar)p6;
    cmd->y2 = (uchar)p7;
    cmd->unique_id = -1;

    this->submit(buffer, size);
}
void TRIBE_Command::command_explore(int p1, int* p2, int p3, float p4, float p5) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AC70 (debug-log side effect intentionally omitted)
    if (p2 == nullptr || p3 <= 0) {
        return;
    }

    int size = p3 * 4 + (int)sizeof(TRIBE_Command_Explore);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Explore));
    for (int i = 0; i < p3; ++i) {
        ids[i] = p2[i];
    }

    TRIBE_Command_Explore* cmd = (TRIBE_Command_Explore*)buffer;
    cmd->command = 0x68;
    cmd->numUnits = (uchar)p3;
    cmd->unit_player_id = (uchar)p1;
    cmd->targetXPosition = p4;
    cmd->targetYPosition = p5;

    this->submit(buffer, size);
}
void TRIBE_Command::command_game_speed(float p1) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050ADF0 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 1;
    cmd->var3 = p1;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}
void TRIBE_Command::command_save_game() {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AE40
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 8;
    this->submit(cmd, sizeof(TRIBE_Command_Game));
}
void TRIBE_Command::command_cancel_build(RGE_Static_Object* p1) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050AFD0 (debug-log side effect intentionally omitted)
    if (p1 == nullptr) {
        return;
    }

    TRIBE_Command_Cancel_Build* cmd = (TRIBE_Command_Cancel_Build*)calloc(1, sizeof(TRIBE_Command_Cancel_Build));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x6A;
    cmd->unit_id = (int)p1->id;

    this->submit(cmd, sizeof(TRIBE_Command_Cancel_Build));
}
void TRIBE_Command::command_attack_ground(RGE_Static_Object** p1, short p2, float p3, float p4) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B020 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = count * 4 + (int)sizeof(TRIBE_Command_Attack_Ground);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Attack_Ground));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Attack_Ground* cmd = (TRIBE_Command_Attack_Ground*)buffer;
    cmd->command = 0x6B;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p3;
    cmd->location_y = p4;

    this->submit(buffer, size);
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
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A6A0
    RGE_Obj_Info* object_ids = (RGE_Obj_Info*)(p1 + 1);
    uint count = (uint)p1->unit_num;
    for (uint i = 0; i < count; ++i) {
        RGE_Static_Object* obj = this->get_obj(object_ids[i]);
        if (obj != nullptr) {
            obj->attribute_type_held = (short)p1->attribute;
        }
    }
}
void TRIBE_Command::do_command_repair(TRIBE_Command_Repair* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A6E0
    RGE_Static_Object* target = this->get_obj(p1->target);
    RGE_Obj_Info* object_ids = (RGE_Obj_Info*)(p1 + 1);
    uint count = (uint)p1->unit_num;

    for (uint i = 0; i < count; ++i) {
        RGE_Static_Object* obj = this->get_obj(object_ids[i]);
        if (obj != nullptr) {
            ((TRIBE_Combat_Object*)obj)->do_repair(target);
        }
    }
}
void TRIBE_Command::do_command_unload(TRIBE_Command_Unload* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A730
    RGE_Obj_Info* object_ids = (RGE_Obj_Info*)(p1 + 1);
    uint count = (uint)p1->unit_num;

    for (uint i = 0; i < count; ++i) {
        RGE_Static_Object* obj = this->get_obj(object_ids[i]);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            int owner_id = (int)obj->owner->id;
            obj->owner->processAIOrder(owner_id, obj->id, 0x2D1, obj->id, owner_id, p1->location_x, p1->location_y, 0.0f, 1.0f, 1, 0, 100);
        }
    }
}
void TRIBE_Command::do_command_queue(TRIBE_Command_Queue* p1) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050A7B0
    TRIBE_Building_Object* building = (TRIBE_Building_Object*)this->world->object(p1->bldg_id);
    if (building != nullptr) {
        short train_count = p1->train_count;
        if (0 < train_count) {
            building->add_to_production_queue(p1->train_id, train_count);
            return;
        }
        building->remove_from_production_queue(p1->train_id, (short)-train_count);
    }
}
void TRIBE_Command::command_trade_attribute(RGE_Static_Object** p1, short p2, long p3) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B190 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = (int)sizeof(TRIBE_Command_Trade_Attribute) + count * 4;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* object_ids = (int*)(buffer + sizeof(TRIBE_Command_Trade_Attribute));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        object_ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Trade_Attribute* cmd = (TRIBE_Command_Trade_Attribute*)buffer;
    cmd->command = 0x6D;
    cmd->unit_num = (uchar)p2;
    cmd->attribute = p3;

    this->submit(buffer, size);
}
void TRIBE_Command::command_trade_attribute(int p1, int p2, long p3) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B230 (debug-log side effect intentionally omitted)
    (void)p2;

    const int size = 0xC;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    *(int*)(buffer + sizeof(TRIBE_Command_Trade_Attribute)) = p1;

    TRIBE_Command_Trade_Attribute* cmd = (TRIBE_Command_Trade_Attribute*)buffer;
    cmd->command = 0x6D;
    cmd->unit_num = 1;
    cmd->attribute = p3;

    this->submit(buffer, size);
}
void TRIBE_Command::command_repair(RGE_Static_Object** p1, short p2, RGE_Static_Object* p3) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B290 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = (int)sizeof(TRIBE_Command_Repair) + count * 4;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* object_ids = (int*)(buffer + sizeof(TRIBE_Command_Repair));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        object_ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Repair* cmd = (TRIBE_Command_Repair*)buffer;
    cmd->command = 0x6E;
    cmd->unit_num = (uchar)p2;
    cmd->target.id = p3->id;

    this->submit(buffer, size);
}
void TRIBE_Command::command_unload(RGE_Static_Object** p1, short p2, float p3, float p4) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B330 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = (int)sizeof(TRIBE_Command_Unload) + count * 4;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* object_ids = (int*)(buffer + sizeof(TRIBE_Command_Unload));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        object_ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Unload* cmd = (TRIBE_Command_Unload*)buffer;
    cmd->command = 0x6F;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p3;
    cmd->location_y = p4;

    this->submit(buffer, size);
}
void TRIBE_Command::command_queue(RGE_Static_Object* p1, short p2, short p3) {
    // Source of truth: tcommand.cpp.decomp @ 0x0050B3E0 (debug-log side effect intentionally omitted)
    TRIBE_Command_Queue* cmd = (TRIBE_Command_Queue*)calloc(1, sizeof(TRIBE_Command_Queue));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x77;
    cmd->bldg_id = p1->id;
    cmd->train_id = p2;
    cmd->train_count = p3;

    this->submit(cmd, sizeof(TRIBE_Command_Queue));
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
    if ((int)p1 < 0 || (int)p1 >= this->effect_num || this->effects == nullptr) return;
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
