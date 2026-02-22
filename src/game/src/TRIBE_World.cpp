#include <time.h>
#include "../include/TRIBE_World.h"
#include "../include/TribeAIPlayBook.h"
#include "../include/custom_debug.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_Tech.h"
#include "../include/TRIBE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/TRIBE_Command.h"
#include "../include/TRIBE_Command_Game.h"
#include "../include/TRIBE_Effects.h"
#include "../include/T_Scenario.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_Gaia.h"
#include "../include/TRIBE_Master_Player.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/RGE_Player_Info.h"
#include "../include/RGE_Map_Gen_Info.h"
#include "../include/RGE_Object_Info.h"
#include "../include/RGE_Object_Info_Line.h"
#include "../include/RGE_Effects.h"
#include "../include/debug_helpers.h"
#include "../include/RGE_RMM_Object_Generator.h"
#include "../include/RGE_Scenario.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TSound_Driver.h"
#include "../include/globals.h"
#include <new>
#include <stdlib.h>

static int tribe_count_object_type(TRIBE_World* world, short object_id_a, short object_id_b) {
    if (world == nullptr || world->players == nullptr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < world->player_num; ++i) {
        RGE_Player* player = world->players[i];
        if (player == nullptr || player->objects == nullptr) {
            continue;
        }

        for (RGE_Object_Node* node = player->objects->list; node != nullptr; node = node->next) {
            if (node->node == nullptr || node->node->master_obj == nullptr) {
                continue;
            }

            short id = node->node->master_obj->id;
            if (id == object_id_a || (object_id_b >= 0 && id == object_id_b)) {
                count = count + 1;
            }
        }
    }

    return count;
}

static void tribe_world_apply_effect(TRIBE_World* world, short effect_id) {
    if (world == nullptr || world->effects == nullptr || world->players == nullptr) {
        return;
    }

    for (int i = 1; i < world->player_num; ++i) {
        RGE_Player* player = world->players[i];
        if (player != nullptr) {
            world->effects->do_effect(effect_id, player);
        }
    }
}

static void tribe_world_add_victory_points_simple(TRIBE_World* world, int player_index, int amount) {
    if (world == nullptr || world->players == nullptr) {
        return;
    }
    if (player_index <= 0 || player_index >= world->player_num) {
        return;
    }
    RGE_Player* player = world->players[player_index];
    if (player == nullptr || player->victory_conditions == nullptr) {
        return;
    }
    player->victory_conditions->add_victory_points('\0', amount, '\x01');
}

static void tribe_world_remove_tile_node(RGE_Tile* tile, RGE_Static_Object* obj) {
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

static void tribe_world_delete_object_now(RGE_Static_Object* obj) {
    if (obj == nullptr) {
        return;
    }

    RGE_Player* owner = obj->owner;
    RGE_Tile* tile = obj->tile;

    if (owner != nullptr) {
        owner->removeObject(obj, (int)obj->sleep_flag, (int)obj->dopple_flag, obj->player_object_node);
    }

    tribe_world_remove_tile_node(tile, obj);
    obj->player_object_node = nullptr;
    obj->tile = nullptr;
    delete obj;
}

static RGE_Static_Object* tribe_find_by_master_id_simple(RGE_Object_List* list, long master_id, uchar require_state, uchar required_state) {
    if (list == nullptr) {
        return nullptr;
    }

    for (RGE_Object_Node* node = list->list; node != nullptr; node = node->next) {
        RGE_Static_Object* obj = node->node;
        if (obj != nullptr && obj->master_obj != nullptr && obj->master_obj->id == (short)master_id &&
            (require_state == 0 || obj->object_state == required_state)) {
            return obj;
        }
    }

    return nullptr;
}

// Fully verified. Source of truth: tworld.cpp.decomp @ 0x0052DF60
TRIBE_World::TRIBE_World() : RGE_Game_World() {
    this->controllingComputerPlayer = 0xFF;
    this->tech = nullptr;
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->sent_zone_score = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;

    AIPlayBook* created_playbook = nullptr;
    TribeAIPlayBook* tribe_playbook = new (std::nothrow) TribeAIPlayBook();
    if (tribe_playbook == nullptr) {
        created_playbook = nullptr;
    } else {
        created_playbook = static_cast<AIPlayBook*>(tribe_playbook);
    }

    this->playbook = created_playbook;
    if (created_playbook != nullptr) {
        created_playbook->loadPlays((char*)"data\\aoe.ply");
    }
}

// Stub implementations for TRIBE_World virtual methods
// These mostly just call base class or return defaults

uchar TRIBE_World::data_load_world(FILE* param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E350
    // Calls base class data_load_world, then reads tech file name and creates TRIBE_Tech.
    RGE_Game_World::data_load_world(param_1);

    // Original: fscanf(param_1, " %s", tech_file);
    // Then creates TRIBE_Tech from text file.
    char tech_file[24];
    if (param_1) {
        fscanf(param_1, " %s", tech_file);
    } else {
        tech_file[0] = '\0';
    }

    if (this->tech) {
        delete this->tech;
    }
    this->tech = new TRIBE_Tech(tech_file);

    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;

    return 1;
}
uchar TRIBE_World::data_load_terrain_tables(char* param_1) { return RGE_Game_World::data_load_terrain_tables(param_1); }
uchar TRIBE_World::data_load_players(char* param_1) { return RGE_Game_World::data_load_players(param_1); }
uchar TRIBE_World::data_load_objects(char* param_1) { return RGE_Game_World::data_load_objects(param_1); }
uchar TRIBE_World::data_load_sounds(char* param_1) { return RGE_Game_World::data_load_sounds(param_1); }
uchar TRIBE_World::data_load_color_tables(char* param_1) { return RGE_Game_World::data_load_color_tables(param_1); }
uchar TRIBE_World::data_load_sprites(char* param_1) { return RGE_Game_World::data_load_sprites(param_1); }
void TRIBE_World::data_load_players_type(short param_1, short param_2, FILE* param_3) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E220
    // If param_2 == 1, create a TRIBE_Master_Player from file; otherwise delegate to base.
    if (param_2 != 1) {
        RGE_Game_World::data_load_players_type(param_1, param_2, param_3);
        return;
    }
    TRIBE_Master_Player* mp = new TRIBE_Master_Player(param_3);
    this->master_players[param_1] = (RGE_Master_Player*)mp;
}
void TRIBE_World::data_load_effects(char* param_1) { RGE_Game_World::data_load_effects(param_1); }
void TRIBE_World::data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E2B0
    // Creates a TRIBE_Map from terrain data files, then loads terrain object types.
    this->map = new TRIBE_Map(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
    if (this->map) {
        this->map->load_terrain_obj_types(param_9);
    }
}
void TRIBE_World::data_load_random_map(char* param_1, char* param_2, char* param_3, char* param_4) { RGE_Game_World::data_load_random_map(param_1, param_2, param_3, param_4); }
uchar TRIBE_World::init_player_type(int param_1, short param_2, uchar param_3) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E400
    // If param_3 == 1, create a TRIBE_Master_Player; otherwise delegate to base.
    if (param_3 != 1) {
        return RGE_Game_World::init_player_type(param_1, param_2, param_3);
    }
    TRIBE_Master_Player* mp = new TRIBE_Master_Player(param_1);
    this->master_players[param_2] = (RGE_Master_Player*)mp;
    // Call finish_init on the newly created master player
    mp->finish_init(param_1, this->sprites, this->sounds);
    return 1;
}
uchar TRIBE_World::init_player(int param_1) { return RGE_Game_World::init_player(param_1); }
void TRIBE_World::load_player(int param_1, uchar param_2, short param_3) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E830
    if (param_2 == 1 || param_2 == 3) {
        // Human or scenario player -> TRIBE_Player
        TRIBE_Player* p = new TRIBE_Player(param_1, this, (uchar)param_3);
        this->players[param_3] = (RGE_Player*)p;
        p->load(param_1);
    } else if (param_2 == 2) {
        // Gaia player
        TRIBE_Gaia* g = new TRIBE_Gaia(param_1, this, (uchar)param_3);
        this->players[param_3] = (RGE_Player*)g;
        g->load(param_1);
    } else {
        RGE_Game_World::load_player(param_1, param_2, param_3);
    }
}
void TRIBE_World::color_table_init(int param_1) { RGE_Game_World::color_table_init(param_1); }
void TRIBE_World::terrain_tables_init(int param_1) { RGE_Game_World::terrain_tables_init(param_1); }
void TRIBE_World::init_sounds(int param_1, TSound_Driver* param_2) { RGE_Game_World::init_sounds(param_1, param_2); }
void TRIBE_World::init_sprites(int param_1) { RGE_Game_World::init_sprites(param_1); }
void TRIBE_World::map_init(int param_1, TSound_Driver* param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E500.
    this->map = new TRIBE_Map(param_1, this->sounds, (char)1);
}
void TRIBE_World::effects_init(int param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E650
    this->effects = new TRIBE_Effects(param_1);
}
void TRIBE_World::master_player_init(int param_1) {
    RGE_Game_World::master_player_init(param_1);
}
void TRIBE_World::command_init(int param_1, TCommunications_Handler* param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E530
    this->commands = new TRIBE_Command(this, param_2);
}
void TRIBE_World::world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E6B0
    // Calls base world_init, then creates TRIBE_Tech with (param_1, this).
    RGE_Game_World::world_init(param_1, param_2, param_3);

    if (this->tech) {
        delete this->tech;
    }
    this->tech = new TRIBE_Tech(param_1, this);

    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;
}
void TRIBE_World::setup_gaia() {
    // Source of truth: tworld.cpp.decomp @ 0x0052E920
    // Creates a TRIBE_Gaia player (player 0) using master_players[0].
    RGE_Master_Player* mp = (this->master_players && this->master_player_num > 0) ? this->master_players[0] : nullptr;
    TRIBE_Gaia* gaia = new TRIBE_Gaia(this, mp, '\0', "GAIA", '\0');
    this->players[0] = (RGE_Player*)gaia;
}
void TRIBE_World::setup_players(RGE_Player_Info* param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E990
    // Creates TRIBE_Player objects for each player slot (1..player_num-1).
    // Decomp note: param_1->type[iVar4 + 8] is actually param_1->tribe[iVar4 - 1]
    // due to struct memory aliasing (type is at +0x249, tribe is at +0x252 = type + 9).
    for (int i = 1; i < this->player_num; i++) {
        uchar player_type = param_1->type[i - 1];
        uchar civ = param_1->tribe[i - 1]; // civilization/master_player index
        RGE_Master_Player* master = (this->master_players && civ < this->master_player_num) ? this->master_players[civ] : nullptr;
        char* player_name = param_1->name[i - 1];

        TRIBE_Player* player = nullptr;
        if (player_type == 0) {
            // Human player
            player = new TRIBE_Player(this, master, (uchar)i, player_name, civ, '\0', '\x01', nullptr, nullptr, nullptr);
        } else if (player_type == 4) {
            // Computer player
            if (useComputerPlayers == 0) {
                player = new TRIBE_Player(this, master, (uchar)i, player_name, civ, '\0', '\x01', nullptr, nullptr, nullptr);
            } else {
                player = new TRIBE_Player(this, master, (uchar)i, player_name, civ, '\x01', '\x01', nullptr, nullptr, nullptr);
            }
        }
        this->players[i] = (RGE_Player*)player;
    }
}

void TRIBE_World::check_destructables(short param_1, short param_2, float param_3, float param_4, uchar param_5) {
    // Source of truth: tworld.cpp.decomp @ 0x0052EAC0
    if (this->players == nullptr || this->map == nullptr || this->map->map_row_offset == nullptr) {
        return;
    }

    if (param_1 < 0 || param_1 >= this->player_num) {
        return;
    }

    RGE_Player* player = this->players[param_1];
    if (player == nullptr || player->master_objects == nullptr || param_2 < 0 || param_2 >= player->master_object_num) {
        return;
    }

    RGE_Master_Static_Object* target_master = player->master_objects[param_2];
    if (target_master == nullptr) {
        return;
    }

    float rx = target_master->radius_x;
    float ry = target_master->radius_y;
    if (!(rx > 0.0f || ry > 0.0f)) {
        return;
    }

    short min_x = (short)((long)(param_3 - rx));
    short min_y = (short)((long)(param_4 - ry));
    short max_x = (short)((long)(param_3 + rx));
    short max_y = (short)((long)(param_4 + ry));

    if (min_x < 0) {
        min_x = 0;
    }
    if (max_x >= this->map->map_width) {
        max_x = (short)(this->map->map_width - 1);
    }
    if (min_y < 0) {
        min_y = 0;
    }
    if (max_y >= this->map->map_height) {
        max_y = (short)(this->map->map_height - 1);
    }

    for (short y = min_y; y <= max_y; ++y) {
        for (short x = min_x; x <= max_x; ++x) {
            RGE_Object_Node* node = this->map->map_row_offset[y][x].objects.list;
            while (node != nullptr) {
                RGE_Object_Node* next = node->next;
                RGE_Static_Object* obj = node->node;
                if (obj != nullptr && obj->master_obj != nullptr) {
                    RGE_Master_Static_Object* obj_master = obj->master_obj;
                    unsigned char destructable_flag = *((unsigned char*)obj_master + 0x4B);
                    if (obj_master->id != param_2 && destructable_flag != 0) {
                        float dx = obj->world_x - param_3;
                        float dy = obj->world_y - param_4;
                        if (dx < 0.0f) {
                            dx = -dx;
                        }
                        if (dy < 0.0f) {
                            dy = -dy;
                        }

                        if (dx < (obj_master->radius_x + rx) && dy < (obj_master->radius_y + ry)) {
                            if (param_5 == 0) {
                                obj->destroy_obj();
                            } else {
                                tribe_world_delete_object_now(obj);
                            }
                        }
                    }
                }
                node = next;
            }
        }
    }
}

// Fully verified. Source of truth: tworld.cpp.decomp @ 0x00530AC0
void TRIBE_World::send_cheat(short param_1) {
    // Decomp: TRIBE_Command::command_cheat((TRIBE_Command *)this->commands,this->curr_player,param_1);
    // Inline the command_cheat body to avoid adding a new TRIBE_Command surface area.
    if (this->commands == nullptr) {
        return;
    }

    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 6;
    cmd->var1 = this->curr_player;
    cmd->var2 = param_1;

    this->commands->submit(cmd, sizeof(TRIBE_Command_Game));
}

// Fully verified. Source of truth: tworld.cpp.decomp @ 0x00530AE0
void TRIBE_World::cheat(short param_1, short param_2) {
    if (rge_base_game == nullptr) {
        return;
    }

    // RGE_Base_Game::allowCheatCodes(rge_base_game)
    if (rge_base_game->rge_game_options.allowCheatCodesValue == 0) {
        return;
    }

    // ASM uses an unsigned range check (JA) after MOVSX, so negative values are treated as out of range.
    uint cheat_id = (uint)(ushort)param_2;
    if (cheat_id > 0xE7) {
        return;
    }

    TRIBE_Command* cmd = (TRIBE_Command*)this->commands;

    switch ((int)cheat_id) {
    case 0: {
        if (0 < param_1 && this->players != nullptr) {
            RGE_Player* plr = this->players[param_1];
            if (plr != nullptr && plr->objects != nullptr) {
                RGE_Static_Object* obj = tribe_find_by_master_id_simple(plr->objects, 0x6d, 1, 2);
                if (obj != nullptr && cmd != nullptr) {
                    cmd->command_make(obj, 0x112);
                    return;
                }
            }
        }
        break;
    }
    case 1: {
        if (0 < param_1 && this->players != nullptr) {
            RGE_Player* plr = this->players[param_1];
            if (plr != nullptr && plr->objects != nullptr) {
                RGE_Static_Object* obj = tribe_find_by_master_id_simple(plr->objects, 0x6d, 1, 2);
                if (obj != nullptr && cmd != nullptr) {
                    cmd->command_make(obj, 0xf8);
                    return;
                }
            }
        }
        break;
    }
    case 2:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x7f, this->players[param_1]);
            return;
        }
        break;
    case 3:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x80, this->players[param_1]);
            return;
        }
        break;
    case 4:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x81, this->players[param_1]);
            return;
        }
        break;
    case 5:
        if (this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x82, this->players[0]);
            return;
        }
        break;
    case 6:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x83, this->players[param_1]);
            return;
        }
        break;
    case 7:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x84, this->players[param_1]);
            return;
        }
        break;
    case 8:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x85, this->players[param_1]);
            return;
        }
        break;
    case 9:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x86, this->players[param_1]);
            return;
        }
        break;
    case 10:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x87, this->players[param_1]);
            return;
        }
        break;
    case 0xb:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x88, this->players[param_1]);
            return;
        }
        break;
    case 0xc:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x89, this->players[param_1]);
            return;
        }
        break;
    case 0xd:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0x8a, this->players[param_1]);
            return;
        }
        break;
    case 0xe: {
        if (0 < param_1 && this->players != nullptr) {
            RGE_Player* plr = this->players[param_1];
            if (plr != nullptr && plr->objects != nullptr) {
                RGE_Static_Object* obj = tribe_find_by_master_id_simple(plr->objects, 0x6d, 1, 2);
                if (obj != nullptr && cmd != nullptr) {
                    cmd->command_make(obj, 0x182);
                    return;
                }
            }
        }
        break;
    }
    case 0xf:
        if (0 < param_1 && this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0xd7, this->players[param_1]);
            return;
        }
        break;
    case 0x10: {
        if (0 < param_1 && this->players != nullptr) {
            RGE_Player* plr = this->players[param_1];
            if (plr != nullptr && plr->objects != nullptr) {
                RGE_Static_Object* obj = tribe_find_by_master_id_simple(plr->objects, 0x6d, 1, 2);
                if (obj != nullptr && cmd != nullptr) {
                    cmd->command_make(obj, 0x18d);
                    return;
                }
            }
        }
        break;
    }
    case 0x11:
        if (0 < param_1 && this->players != nullptr) {
            RGE_Player* plr = this->players[param_1];
            if (plr != nullptr && plr->objects != nullptr) {
                (void)tribe_find_by_master_id_simple(plr->objects, 0x6d, 1, 2);
                return;
            }
        }
        break;
    case 0x12:
        if (this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0xd8, this->players[0]);
            return;
        }
        break;
    case 0x13:
        if (this->effects != nullptr && this->players != nullptr) {
            this->effects->do_effect(0xd9, this->players[0]);
            return;
        }
        break;
    case 0x64: {
        int iVar2 = 1;
        die_die_die = 1;
        if (1 < (short)this->player_num && this->players != nullptr) {
            int iVar6 = (int)param_1;
            do {
                if ((iVar2 != iVar6) ||
                    (this->players[iVar6] != nullptr && this->players[iVar6]->isAlly(iVar2) == 0) ||
                    (this->players[iVar2] != nullptr && this->players[iVar2]->isAlly(iVar6) == 0)) {
                    RGE_Player* plr = this->players[iVar2];
                    if (plr != nullptr && plr->objects != nullptr) {
                        for (RGE_Object_Node* node = plr->objects->list; node != nullptr; node = node->next) {
                            RGE_Static_Object* obj = node->node;
                            if (obj != nullptr && obj->object_state < 3 && obj->master_obj != nullptr && obj->master_obj->object_group != 1) {
                                obj->die_die_die();
                            }
                        }
                    }
                }
                iVar2 = iVar2 + 1;
            } while (iVar2 < (short)this->player_num);
            return;
        }
        break;
    }
    case 0x65: {
        if (this->players != nullptr) {
            RGE_Player* plr = this->players[param_1];
            if (plr != nullptr && plr->objects != nullptr) {
                for (RGE_Object_Node* node = plr->objects->list; node != nullptr; node = node->next) {
                    RGE_Static_Object* obj = node->node;
                    if (obj != nullptr && obj->object_state < 3 && obj->master_obj != nullptr && obj->master_obj->object_group != 1) {
                        obj->die_die_die();
                    }
                }
                return;
            }
        }
        break;
    }
    case 0x66:
        if (this->players != nullptr) {
            this->players[param_1]->win_game_now();
            this->game_end_condition = 0x68;
            return;
        }
        break;
    case 0x67:
        if (this->players != nullptr) {
            this->players[param_1]->loss_if_game_on();
            return;
        }
        break;
    case 200:
    case 0xc9:
    case 0xca:
    case 0xcb:
    case 0xcc:
    case 0xcd:
    case 0xce:
    case 0xcf:
    case 0xd0:
    case 0xd1: {
        int iVar6 = (int)param_1;
        int iVar2 = (int)cheat_id + -200;
        if (this->players != nullptr &&
            (((iVar2 != iVar6) ||
              (this->players[iVar6] != nullptr && this->players[iVar6]->isAlly(iVar2) == 0)) ||
             (this->players[iVar2] != nullptr && this->players[iVar2]->isAlly(iVar6) == 0))) {
            RGE_Player* plr = this->players[iVar2];
            if (plr != nullptr && plr->objects != nullptr) {
                for (RGE_Object_Node* node = plr->objects->list; node != nullptr; node = node->next) {
                    RGE_Static_Object* obj = node->node;
                    if (obj != nullptr && obj->object_state < 3 && obj->master_obj != nullptr && obj->master_obj->object_group != 1) {
                        obj->die_die_die();
                    }
                }
                return;
            }
        }
        break;
    }
    case 0xdc: {
        if (this->players != nullptr) {
            RGE_Player* plr = this->players[param_1];
            if (plr != nullptr && plr->objects != nullptr) {
                RGE_Static_Object* obj = tribe_find_by_master_id_simple(plr->objects, 0x6d, 1, 2);
                if (obj != nullptr) {
                    cmd->command_make(obj, 0x174);
                    return;
                }
            }
        }
        break;
    }
    case 0xe6: {
        rge_base_game->set_map_visible(1);
        TPanel* panel = rge_base_game->get_view_panel();
        if (panel != nullptr) {
            panel->set_redraw((TPanel::RedrawMode)2);
        }
        panel = rge_base_game->get_map_panel();
        if (panel != nullptr) {
            panel->set_redraw((TPanel::RedrawMode)2);
        }
        return;
    }
    case 0xe7: {
        rge_base_game->set_map_fog(0);
        TPanel* panel = rge_base_game->get_view_panel();
        if (panel != nullptr) {
            panel->set_redraw((TPanel::RedrawMode)2);
        }
        return;
    }
    default:
        break;
    }
}

uchar TRIBE_World::new_random_game(RGE_Player_Info* param_1) {
    // Source of truth:
    // - tworld.cpp.decomp / tworld.cpp.asm contain no dedicated TRIBE_World::new_random_game body.
    // - world.cpp.decomp / world.cpp.asm provide RGE_Game_World::new_random_game @ 0x00542D10.
    // Treat TRIBE path as inherited base behavior until a TRIBE-specific body is recovered.
    return RGE_Game_World::new_random_game(param_1);
}
void TRIBE_World::save(int param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E790
    RGE_Game_World::save(param_1);
    rge_write(param_1, &this->victory_type, 4);
    rge_write(param_1, &this->artifact_count, 4);
    rge_write(param_1, &this->ruin_count, 4);
    rge_write(param_1, &this->countdown_victory, 1);
    rge_write(param_1, &this->countdown_clock, 4);
    rge_write(param_1, &this->score_displayed, 1);
    rge_write(param_1, &this->controllingComputerPlayer, 1);
}
void TRIBE_World::scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5) {
    // Source of truth: tworld.cpp.decomp @ 0x0052ECF0
    // param_1 = player index, param_2 = civilization/master_player index
    // param_3 = player type (0=human, 4=computer), param_4 unused, param_5 = name
    TRIBE_Player* player = nullptr;
    if (param_3 == 0 || (param_3 != 4 && param_3 != 0)) {
        // Human player or unknown type -> create as human
        player = new TRIBE_Player(this, this->master_players[param_2], (uchar)param_1, param_5, param_2, '\0', '\x01', nullptr, nullptr, nullptr);
    } else if (param_3 == 4) {
        // Computer player
        player = new TRIBE_Player(this, this->master_players[param_2], (uchar)param_1, param_5, param_2, '\x01', '\x01', nullptr, nullptr, nullptr);
    }
    this->players[param_1] = (RGE_Player*)player;
}
void TRIBE_World::scenario_make_map(int param_1) { RGE_Game_World::scenario_make_map(param_1); }
uchar TRIBE_World::load_scenario(RGE_Player_Info* param_1) { return RGE_Game_World::load_scenario(param_1); }
uchar TRIBE_World::load_scenario(char* param_1, RGE_Player_Info* param_2) { return RGE_Game_World::load_scenario(param_1, param_2); }
void TRIBE_World::load_scenario1(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario1(param_1, param_2); }
void TRIBE_World::load_scenario2(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario2(param_1, param_2); }
void TRIBE_World::load_scenario3(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario3(param_1, param_2); }
void TRIBE_World::load_scenario4(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario4(param_1, param_2); }
void TRIBE_World::load_scenario5(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario5(param_1, param_2); }
void TRIBE_World::load_scenario6(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario6(param_1, param_2); }
void TRIBE_World::load_scenario7(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario7(param_1, param_2); }
void TRIBE_World::load_scenario8(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario8(param_1, param_2); }
void TRIBE_World::logStatus(FILE* param_1, int param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E0B0
    // Writes game status info to AI log file.
    if (param_1 == nullptr || param_2 != 1) return;

    fprintf(param_1, "---------------------------------\n");

    time_t clock;
    time(&clock);
    struct tm* t = localtime(&clock);
    fprintf(param_1, "AI Log file for Game Started: %s", asctime(t));
    fprintf(param_1, "Number Players            %d\n", this->player_num - 1);

    // If scenario has a name, log it; otherwise log map/victory info
    if (this->scenario) {
        // TODO(accuracy): check scenario->scenario_name and log it
    }

    // Log map size, map type, victory condition from game settings
    // These use get_string through string table lookups in the original.
    // Simplified: just log the numeric values.
    if (rge_base_game) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        fprintf(param_1, "Map Size                  %d\n", game->mapSize());
        fprintf(param_1, "Map Type                  %d\n", game->mapType());
        fprintf(param_1, "Victory Condition         %d\n", game->victoryType());
    }
}
TRIBE_World::~TRIBE_World() {
    if (this->tech) {
        delete this->tech;
        this->tech = nullptr;
    }
}
void TRIBE_World::setup_player_colors() { RGE_Game_World::setup_player_colors(); }
void TRIBE_World::setup_player_colors(RGE_Player_Info* param_1) { RGE_Game_World::setup_player_colors(param_1); }
uchar TRIBE_World::data_load(char* param_1, char* param_2) { return RGE_Game_World::data_load(param_1, param_2); }
uchar TRIBE_World::init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) { return RGE_Game_World::init(param_1, param_2, param_3); }
void TRIBE_World::turn_sound_off() { RGE_Game_World::turn_sound_off(); }
void TRIBE_World::del_game_info() { RGE_Game_World::del_game_info(); }
uchar TRIBE_World::update() { return RGE_Game_World::update(); }
uchar TRIBE_World::get_game_state() { return RGE_Game_World::get_game_state(); }
uchar TRIBE_World::check_game_state() { return RGE_Game_World::check_game_state(); }
uchar TRIBE_World::load_world(int param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052EDF0
    uchar result = RGE_Game_World::load_world(param_1);
    if (result == 0) return 0;

    // Version-gated reads of TRIBE-specific save fields
    if (save_game_version < 5.6f) {
        this->victory_type = 0;
    } else {
        rge_read(param_1, &this->victory_type, 4);
    }

    if (save_game_version < 5.3f) {
        this->artifact_count = 0;
        this->ruin_count = 0;
    } else {
        rge_read(param_1, &this->artifact_count, 4);
        rge_read(param_1, &this->ruin_count, 4);
    }

    if (save_game_version < 5.4f) {
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;
    } else {
        rge_read(param_1, &this->countdown_victory, 1);
        rge_read(param_1, &this->countdown_clock, 4);
    }

    if (save_game_version < 6.6f) {
        this->score_displayed = 0;
    } else {
        rge_read(param_1, &this->score_displayed, 1);
    }

    if (save_game_version >= 6.97f) {
        rge_read(param_1, &this->controllingComputerPlayer, 1);
    } else {
        this->controllingComputerPlayer = 0x02;
    }

    return 1;
}
uchar TRIBE_World::load_game(char* param_1) { return RGE_Game_World::load_game(param_1); }
uchar TRIBE_World::new_game(RGE_Player_Info* param_1, int param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x0052EF30
    CUSTOM_DEBUG_LOG("TRIBE_World::new_game enter");
    this->score_displayed = 0;
    this->controllingComputerPlayer = 0xFF;

    uchar result = RGE_Game_World::new_game(param_1, param_2);
    CUSTOM_DEBUG_LOG_FMT("TRIBE_World::new_game after base result=%d", (int)result);

    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
    T_Scenario* tScenario = (T_Scenario*)this->scenario;
    CUSTOM_DEBUG_LOG("TRIBE_World::new_game checkpoint before reset timers");

    // Reset countdown timers for all players.
    for (int i = 0; i < this->player_num; i++) {
        rge_base_game->reset_countdown_timer(i);
    }
    CUSTOM_DEBUG_LOG("TRIBE_World::new_game checkpoint after reset timers");

    if (result != 0) {
        this->victory_type = 4;
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;

        int isCampaign = rge_base_game->campaignGame();
        int isRandom = rge_base_game->randomGame();

        if ((isCampaign == 0 && isRandom != 0) ||
            (game != nullptr && game->victoryType() != 0)) {
            int victoryAmount = (game != nullptr) ? game->victoryAmount() : 0;
            int vt = (game != nullptr) ? game->victoryType() : 0;
            CUSTOM_DEBUG_LOG_FMT(
                "TRIBE_World::new_game victory setup: vt=%d victoryAmount=%d",
                vt,
                victoryAmount);
            if (tScenario != nullptr) {
                tScenario->Set_victory_all_flag(0);
                tScenario->Set_Multi_Conquest(0);
                tScenario->Set_Multi_Ruins(0);
                tScenario->Set_Multi_Artifacts(0);
                tScenario->Set_Multi_Discoveries(0);
                tScenario->Set_Multi_Exploration(0);
                tScenario->Set_Multi_Gold(0);
            }

            switch (vt) {
            case 0: // VictoryDefault
            case 1: // VictoryStandard
                this->victory_type = 0;
                if (tScenario != nullptr) {
                    tScenario->Set_Multi_Conquest(1);
                }
                break;
            case 2: // VictoryConquest
                this->victory_type = 1;
                if (tScenario != nullptr) {
                    tScenario->Set_Multi_Conquest(1);
                }
                break;
            case 3: // VictoryExplore
                if (tScenario != nullptr) {
                    tScenario->Set_Multi_Exploration(victoryAmount);
                }
                break;
            case 4: // VictoryRuins
                if (tScenario != nullptr) {
                    tScenario->Set_Multi_Ruins(victoryAmount);
                }
                break;
            case 5: // VictoryArtifacts
                if (tScenario != nullptr) {
                    tScenario->Set_Multi_Artifacts(victoryAmount);
                }
                break;
            case 6: // VictoryDiscoveries
                if (tScenario != nullptr) {
                    tScenario->Set_Multi_Discoveries(victoryAmount);
                }
                break;
            case 9: // VictoryGold
                if (tScenario != nullptr) {
                    tScenario->Set_Multi_Gold(victoryAmount);
                }
                break;
            case 7: // VictoryTime
                this->victory_type = 2;
                if (tScenario != nullptr) {
                    tScenario->Set_Multi_Conquest(1);
                }
                this->countdown_victory = 1;
                this->countdown_clock = (float)victoryAmount;
                break;
            case 8: // VictoryScore
                this->victory_type = 3;
                if (tScenario != nullptr) {
                    tScenario->Set_Multi_Conquest(1);
                }
                break;
            default:
                break;
            }

            if (tScenario != nullptr) {
                CUSTOM_DEBUG_LOG("TRIBE_World::new_game Save_victory_conditions_into_players");
                tScenario->Save_victory_conditions_into_players(0);
                CUSTOM_DEBUG_LOG("TRIBE_World::new_game after Save_victory_conditions_into_players");
            }
            CUSTOM_DEBUG_LOG("TRIBE_World::new_game checkpoint after-save step1");

            if (vt == 8 && this->player_num > 1) {
                CUSTOM_DEBUG_LOG("TRIBE_World::new_game applying score victory points");
                for (int i = 1; i < this->player_num; ++i) {
                    tribe_world_add_victory_points_simple(this, i, victoryAmount);
                }
                CUSTOM_DEBUG_LOG("TRIBE_World::new_game score victory points applied");
            }
        } else {
            if ((rge_base_game->campaignGame() != 0 || rge_base_game->scenarioGame() != 0) && tScenario != nullptr) {
                int mpVictory = tScenario->GetMPVictory();
                if (mpVictory == 0) {
                    this->victory_type = 0;
                } else if (mpVictory == 1) {
                    this->victory_type = 1;
                } else if (mpVictory == 2) {
                    this->victory_type = 3;
                    int victoryScore = tScenario->GetVictoryScore();
                    for (int i = 1; i < this->player_num; ++i) {
                        tribe_world_add_victory_points_simple(this, i, victoryScore);
                    }
                } else if (mpVictory == 3) {
                    this->victory_type = 2;
                    this->countdown_victory = 1;
                    this->countdown_clock = (float)tScenario->GetVictoryTime();
                }
            }
        }

        RGE_RMM_Object_Generator* objGen = nullptr;
        CUSTOM_DEBUG_LOG("TRIBE_World::new_game creating RGE_RMM_Object_Generator");
        if (this->map != nullptr) {
            objGen = new RGE_RMM_Object_Generator(this->map, (RGE_Random_Map_Module*)nullptr, this, (RGE_Object_Info*)nullptr, 0);
        }
        CUSTOM_DEBUG_LOG_FMT("TRIBE_World::new_game object generator ptr=%p", objGen);

        if (objGen != nullptr && tScenario != nullptr) {
            CUSTOM_DEBUG_LOG("TRIBE_World::new_game object generator setup begin");
            int debug_skip_obj_gen = 0;
            if (rge_base_game != nullptr) {
                debug_skip_obj_gen = rge_base_game->check_prog_argument((char*)"DEBUGSKIPOBJGEN");
            }
            int targetArtifacts = tScenario->Get_Multi_Artifacts();
            if (targetArtifacts > 0) {
                int existingArtifacts = tribe_count_object_type(this, 0x9f, -1);
                if (targetArtifacts > existingArtifacts) {
                    objGen->add_quick_obj(0x9f, targetArtifacts - existingArtifacts, 0);
                }
            }

            int targetDiscoveries = tScenario->Get_Multi_Discoveries();
            if (targetDiscoveries > 0) {
                int existingDiscoveries = tribe_count_object_type(this, 10, -1);
                if (targetDiscoveries > existingDiscoveries) {
                    objGen->add_quick_obj(10, targetDiscoveries - existingDiscoveries, 0);
                }
            }

            int targetRuins = tScenario->Get_Multi_Ruins();
            if (targetRuins > 0) {
                int existingRuins = tribe_count_object_type(this, 0x9e, 0xa3);
                if (targetRuins > existingRuins) {
                    objGen->add_quick_obj(0x9e, targetRuins - existingRuins, 0);
                }
            }

            if (rge_base_game->campaignGame() == 0 && rge_base_game->randomGame() != 0) {
                if (this->victory_type == 3 ||
                    (debug_rand("C:\\msdev\\work\\age1_x1\\tworld.cpp", 0x38d) % 100) < 0x32) {
                    objGen->add_quick_obj(0x9f, 5, this->map->map_width / 5);
                    this->artifact_count = 5;
                }
                if ((debug_rand("C:\\msdev\\work\\age1_x1\\tworld.cpp", 0x394) % 100) < 0x32) {
                    objGen->add_quick_obj(0x9e, 5, this->map->map_width / 5);
                    this->ruin_count = 5;
                }
            } else {
                this->artifact_count = tribe_count_object_type(this, 0x9f, -1);
                this->ruin_count = tribe_count_object_type(this, 0x9e, 0xa3);
            }

            if (debug_skip_obj_gen != 0) {
                // TODO: STUB: Temporary debug gate to isolate map-start crash near object generation.
                CUSTOM_DEBUG_LOG("TRIBE_World::new_game object generator generate SKIPPED (DEBUGSKIPOBJGEN)");
            } else {
                CUSTOM_DEBUG_LOG("TRIBE_World::new_game object generator generate begin");
                objGen->generate();
                CUSTOM_DEBUG_LOG("TRIBE_World::new_game object generator generate done");
            }
            delete objGen;
            objGen = nullptr;
            CUSTOM_DEBUG_LOG("TRIBE_World::new_game object generator deleted");
        }
    }

    if (game != nullptr) {
        CUSTOM_DEBUG_LOG("TRIBE_World::new_game entering post-new-game game-option passes");
        if (game->allowTrading() == 0) {
            tribe_world_apply_effect(this, (short)-8);
        }

        if (game->longCombat() == 1) {
            tribe_world_apply_effect(this, (short)-8);
        }

        if (game->fullTechTree() == 0 && tScenario != nullptr && tScenario->GetScenarioOption(2) == 0) {
            if (this->effects != nullptr && this->players != nullptr) {
                for (int i = 1; i < this->player_num; ++i) {
                    RGE_Player* player = this->players[i];
                    if (player == nullptr) {
                        continue;
                    }
                    short effect_id = *(short*)((char*)player + 0x10C);
                    this->effects->do_effect(effect_id, player);
                }
            }
        } else {
            tribe_world_apply_effect(this, (short)-8);
        }

        int resource_level = game->resourceLevel();
        if (resource_level == 1) {
            for (int i = 1; i < this->player_num; ++i) {
                RGE_Player* player = this->players[i];
                if (player != nullptr && player->attributes != nullptr && player->attribute_num >= 4) {
                    player->attributes[0] = 200.0f;
                    player->attributes[1] = 200.0f;
                    player->attributes[3] = 0.0f;
                    player->attributes[2] = 100.0f;
                }
            }
        } else if (resource_level == 2) {
            for (int i = 1; i < this->player_num; ++i) {
                RGE_Player* player = this->players[i];
                if (player != nullptr && player->attributes != nullptr && player->attribute_num >= 4) {
                    player->attributes[0] = 500.0f;
                    player->attributes[1] = 500.0f;
                    player->attributes[3] = 0.0f;
                    player->attributes[2] = 250.0f;
                }
            }
        } else if (resource_level == 3) {
            for (int i = 1; i < this->player_num; ++i) {
                RGE_Player* player = this->players[i];
                if (player != nullptr && player->attributes != nullptr && player->attribute_num >= 4) {
                    player->attributes[0] = 1000.0f;
                    player->attributes[1] = 1000.0f;
                    player->attributes[3] = 0.0f;
                    player->attributes[2] = 750.0f;
                }
            }
        }

        if (game->deathMatch() != 0) {
            for (int i = 1; i < this->player_num; ++i) {
                RGE_Player* player = this->players[i];
                if (player != nullptr && player->attributes != nullptr && player->attribute_num >= 4) {
                    player->attributes[0] = 20000.0f;
                    player->attributes[1] = 20000.0f;
                    player->attributes[3] = 10000.0f;
                    player->attributes[2] = 5000.0f;
                }
            }
        }

        int start_age = game->startingAge();
        CUSTOM_DEBUG_LOG_FMT("TRIBE_World::new_game start_age=%d", start_age);
        if (start_age == 3) {
            for (int i = 1; i < this->player_num; ++i) {
                TRIBE_Player* player = (TRIBE_Player*)this->players[i];
                if (player != nullptr) {
                    player->rev_tech(0x19);
                }
            }
        } else if (start_age == 4) {
            for (int i = 1; i < this->player_num; ++i) {
                TRIBE_Player* player = (TRIBE_Player*)this->players[i];
                if (player != nullptr) {
                    player->rev_tech(0x17);
                }
            }
        } else if (start_age == 5) {
            for (int i = 1; i < this->player_num; ++i) {
                TRIBE_Player* player = (TRIBE_Player*)this->players[i];
                if (player != nullptr) {
                    player->rev_tech(0x18);
                }
            }
        }

        if (rge_base_game->check_prog_argument("NOFOODCAP") != 0) {
            for (int i = 1; i < this->player_num; ++i) {
                RGE_Player* player = this->players[i];
                if (player != nullptr) {
                    player->new_attribute_num(0x20, 50.0f);
                    player->new_attribute_num(0x21, 0.0f);
                    player->new_attribute_num(0x1E, 500.0f);
                    player->new_attribute_num(0x1F, 5000.0f);
                }
            }
        } else if (rge_base_game->check_prog_argument("SYSTEM2") != 0) {
            for (int i = 1; i < this->player_num; ++i) {
                RGE_Player* player = this->players[i];
                if (player != nullptr) {
                    player->new_attribute_num(0x20, 50.0f);
                    player->new_attribute_num(0x21, 0.0f);
                }
            }
        } else {
            for (int i = 1; i < this->player_num; ++i) {
                TRIBE_Player* player = (TRIBE_Player*)this->players[i];
                if (player != nullptr) {
                    player->new_attribute_num(0x20, (float)game->popLimit());
                    player->new_attribute_num(0x21, 0.0f);
                    player->new_attribute_num(0x1E, 500.0f);
                    player->new_attribute_num(0x2D, 1.0f);
                    if (player->victory_conditions != nullptr) {
                        player->victory_conditions->add_points_attribute_amount('\0', '\0', 0x14, 2, 1);
                        player->victory_conditions->add_points_attribute_amount('\0', '\x01', 0x2B, 1, 1);
                        player->victory_conditions->add_points_attribute_amount('\0', '\x02', 0x2C, 1, 1);
                        player->victory_conditions->add_points_high_attribute_once('\0', '\x03', 0x28, 1, 0x19);
                        player->victory_conditions->add_points_attribute_amount('\x01', '\x04', 0x31, 100, 1);
                        player->victory_conditions->add_points_attribute_amount('\x01', '\x09', 0x35, 0x3C, 1);
                        player->victory_conditions->add_points_high_attribute_amount('\x01', '\x05', 0x25, 1, 1);
                        player->victory_conditions->add_points_high_attribute_once('\x01', '\x06', 0x25, 1, 0x19);
                        player->victory_conditions->add_points_attribute_amount('\x01', '\x07', 0x16, 3, 1);
                        if (rge_base_game->fullVisibility() == 0) {
                            player->victory_conditions->add_points_highest_attribute('\x01', '\x08', 0x16, 1, 0x19);
                        }
                        player->victory_conditions->add_points_attribute_amount('\x02', '\x0A', 0x29, 1, 2);
                        player->victory_conditions->add_points_highest_attribute('\x02', '\x0B', 0x29, 1, 0x19);
                        player->victory_conditions->add_points_attribute_amount('\x02', '\x0C', 0x0E, 1, 10);
                        player->victory_conditions->add_points_attribute_amount('\x02', '\x0D', 7, 1, 10);
                        player->victory_conditions->add_points_attribute_amount('\x02', '\x0E', 0x34, 1, 3);
                        player->victory_conditions->add_points_attribute_amount('\x02', '\x10', 0x37, 1, 0x32);
                        player->victory_conditions->add_points_attribute_amount('\x02', '\x0F', 0x36, 1, 0x32);
                        player->victory_conditions->add_points_attribute_amount('\x03', '\x11', 0x15, 1, 2);
                        player->victory_conditions->add_points_highest_attribute('\x03', '\x12', 0x15, 1, 0x32);
                        player->victory_conditions->add_points_attribute_first('\x03', '\x13', 6, 3, 0x19);
                        player->victory_conditions->add_points_attribute_first('\x03', '\x14', 6, 4, 0x19);
                        player->victory_conditions->add_points_attribute_amount('\x04', '\x16', 0x2D, 1, 100);
                        player->victory_conditions->add_points_attribute_amount('\x04', '\x17', 0x2A, 1, 100);
                    }
                    player->add_population_entry();
                }
            }
        }
    }

    CUSTOM_DEBUG_LOG_FMT("TRIBE_World::new_game exit result=%d", (int)result);
    return result;
}
uchar TRIBE_World::new_scenario(RGE_Player_Info* param_1, int param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x00530370
    uchar result = RGE_Game_World::new_scenario(param_1, param_2);
    // Set starting resources for non-gaia players
    // Attribute indices: 0=food, 1=wood, 2=gold, 3=stone
    // Hex: 0x43480000=200.0f, 0x42c80000=100.0f
    for (int i = 1; i < this->player_num; i++) {
        if (this->players[i] && this->players[i]->attributes && this->players[i]->attribute_num >= 4) {
            this->players[i]->attributes[0] = 200.0f; // food
            this->players[i]->attributes[1] = 200.0f; // wood
            this->players[i]->attributes[2] = 100.0f; // gold
            this->players[i]->attributes[3] = 0.0f;   // stone
        }
    }
    return result;
}
uchar TRIBE_World::save_game(char* param_1) { return RGE_Game_World::save_game(param_1); }
void TRIBE_World::base_save(char* param_1) { RGE_Game_World::base_save(param_1); }
void TRIBE_World::base_save(int param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E770
    RGE_Game_World::base_save(param_1);
    if (this->tech) {
        this->tech->save(param_1);
    }
}
uchar TRIBE_World::save_scenario(char* param_1) { return RGE_Game_World::save_scenario(param_1); }
RGE_Scenario* TRIBE_World::get_scenario_info(char* param_1) { return RGE_Game_World::get_scenario_info(param_1); }
void TRIBE_World::pause(uchar param_1) { RGE_Game_World::pause(param_1); }
void TRIBE_World::scenario_init(RGE_Game_World* param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E5F0
    this->scenario = new T_Scenario(param_1);
}
void TRIBE_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E590
    this->scenario = new T_Scenario(param_1, param_2);
}
int TRIBE_World::addObject(RGE_Static_Object* param_1) { return RGE_Game_World::addObject(param_1); }
int TRIBE_World::removeObject(int param_1) { return RGE_Game_World::removeObject(param_1); }
