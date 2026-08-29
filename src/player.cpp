// This file owns the complete Player source body order.
#include "../include/player.h"
#include "../include/world.h"
#include "../include/mst_play.h"
#include "../include/obj_list.h"
#include "../include/visible.h"
#include "../include/dpl_obj.h"
#include "../include/victory.h"
#include "../include/vis_unit.h"
#include "../include/map.h"
#include "../include/effects.h"
#include "../include/Command.h"
#include "../include/com_hand.h"
#include "../include/Mouseptr.h"
#include "../include/aipbook.h"
#include "../include/unit_ai_module.h"
#include "../include/m_s_obj.h"
#include "../include/m_mi_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/m_co_obj.h"
#include "../include/m_dg_obj.h"
#include "../include/sprite.h"
#include "../include/sound.h"
#include "../include/color.h"
#include "../include/basegame.h"
#include "../include/game_globals.h"
#include "../include/mystring.h"
#include <stdlib.h>
#include <string.h>
#include <memory.h>

extern int pathingCapValue;
extern TCommunications_Handler* comm;
void rge_read(int file, void* buffer, int size);
void rge_write(int file, void* buffer, int size);

struct Selection_Locals {
    int list_count;
    RGE_Static_Object** list;
};

void RGE_Player::logStatus(FILE* p0, int p1) {}

RGE_Player::RGE_Player(int file, RGE_Game_World* world_arg,
                       unsigned char player_id)
    : computerPlayerValue(0), pathingAttemptCapValue(5),
      pathingDelayCapValue(10), tile_list(400), diam_tile_list(400) {
    int* pathing = &this->pathingAttemptCapValue;
    int pathing_cap = pathingCapValue;

    this->id = player_id;
    this->pathingAttemptCapValue = pathing_cap;
    this->world = world_arg;
    this->reset_selected();

    this->doppleganger_creator =
        new RGE_Doppleganger_Creator(this, 100);

    this->relations = (unsigned char*)calloc(
        1, (int)this->world->player_num);
    rge_read(file, this->relations, (int)this->world->player_num);
    rge_read(file, this->unitDiplomacy, 0x24);

    if (save_game_version >= DAT_00570e90) {
        rge_read(file, &this->allied_LOS_Enable, 4);
    } else {
        this->allied_LOS_Enable = 0;
    }

    rge_read(file, &this->allied_victory, 1);

    short name_length;
    rge_read(file, &name_length, 2);
    if (name_length > 0) {
        this->name = (char*)calloc((int)name_length, 1);
        rge_read(file, this->name, (int)name_length);
    } else {
        this->name = 0;
    }

    rge_read(file, &this->attribute_num, 2);
    if (this->attribute_num > 0) {
        this->attributes = (float*)calloc((int)this->attribute_num, 4);
        rge_read(file, this->attributes, (int)this->attribute_num << 2);
    } else {
        this->attributes = 0;
    }

    rge_read(file, &this->view_x, 4);
    rge_read(file, &this->view_y, 4);
    rge_read(file, &this->map_x, 2);
    rge_read(file, &this->map_y, 2);
    rge_read(file, &this->culture, 1);
    rge_read(file, &this->master_player_id, 1);
    rge_read(file, &this->game_status, 1);
    rge_read(file, &this->resigned, 1);

    unsigned char table;
    rge_read(file, &table, 1);
    this->set_color_table(table);

    rge_read(file, pathing, 4);
    rge_read(file, &this->pathingDelayCapValue, 4);

    this->checksum_created_this_update = 0;
    this->checksum = 0;
}

RGE_Player::RGE_Player(RGE_Game_World* world, RGE_Master_Player* master,
                       unsigned char player_id, char* player_name,
                       unsigned char master_id, unsigned char is_computer)
    : computerPlayerValue(0), pathingAttemptCapValue(5),
      pathingDelayCapValue(10), tile_list(400), diam_tile_list(400)
{
    this->pathingAttemptCapValue = pathingCapValue;
    this->master_player_id = master_id;
    this->type = 0;
    this->world = world;
    this->id = (short)player_id;
    this->reset_selected();

    this->name = 0;
    if (player_name != 0) {
        getstring(&this->name, player_name);
    }

    this->relations = (unsigned char*)calloc(1, (int)this->world->player_num);
    for (int i = 0; i < 9; ++i) {
        this->unitDiplomacy[i] = -1;
    }

    short relation_index = 0;
    if (this->world->player_num > 0) {
        do {
            this->relations[relation_index] = 1;
            if (relation_index == this->id) {
                this->unitDiplomacy[relation_index] = 1;
            } else if (relation_index == 0) {
                this->unitDiplomacy[0] = 0;
            } else {
                this->unitDiplomacy[relation_index] = 3;
            }
            ++relation_index;
        } while (relation_index < this->world->player_num);
    }

    this->mutualExploredMask = 0;
    this->mutualVisibleMask = 0;
    this->nonMutualVisibleMask = 0;
    this->allied_LOS_Enable = 0;
    this->allied_victory = 0;

    this->master_object_num = master->master_object_num;
    if (this->master_object_num > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc(
            (int)this->master_object_num, 4);
        short master_index = 0;
        if (this->master_object_num > 0) {
            do {
                if (master->master_objects[master_index] != 0) {
                    this->master_objects[master_index] =
                        master->master_objects[master_index]->make_new_master();
                }
                ++master_index;
            } while (master_index < this->master_object_num);
        }
    }

    if (is_computer != 0) {
        this->objects = new RGE_Object_List;
        this->sleeping_objects = new RGE_Object_List;
        this->doppleganger_objects = new RGE_Object_List;
        this->new_victory();
        this->visible = new RGE_Visible_Map(world->map, this);
    } else {
        this->objects = 0;
        this->sleeping_objects = 0;
        this->doppleganger_objects = 0;
        this->victory_conditions = 0;
        this->visible = 0;
    }

    this->doppleganger_creator = new RGE_Doppleganger_Creator(this, 100);

    this->attribute_num = master->attribute_num;
    if (this->attribute_num > 0) {
        this->attributes = (float*)calloc((int)this->attribute_num, 4);
        memcpy(this->attributes, master->attributes,
               (int)this->attribute_num * 4);
    } else {
        this->attributes = 0;
    }

    this->culture = master->culture;
    this->set_view_loc(
        (float)(this->world->map->map_width / 2),
        (float)(this->world->map->map_height / 2));
    this->set_map_loc(
        (short)(this->world->map->map_width / 2),
        (short)(this->world->map->map_height / 2));

    this->game_status = 0;
    this->resigned = 0;
    this->color_table = 0;
    this->tribe_effect = master->tribe_effect;
    if (is_computer != 0 && this->tribe_effect >= 0) {
        this->world->effects->do_effect((short)this->tribe_effect, this);
    }

    this->checksum = 0;
    this->checksum_created_this_update = 0;
}

RGE_Player::~RGE_Player() {
    RGE_Object_List* object_list;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible_map;
    RGE_Doppleganger_Creator* doppleganger_creator;
    Visible_Resource_Manager* resource_manager;

    object_list = this->objects;
    if (object_list != 0) {
        delete object_list;
    }
    object_list = this->sleeping_objects;
    if (object_list != 0) {
        delete object_list;
    }
    object_list = this->doppleganger_objects;
    if (object_list != 0) {
        delete object_list;
    }
    victory_conditions = this->victory_conditions;
    if (victory_conditions != 0) {
        delete victory_conditions;
    }

    free(this->relations);
    this->relations = 0;

    if (this->master_object_num > 0) {
        for (short i = 0; i < this->master_object_num; ++i) {
            if (this->master_objects[i] != 0) {
                delete this->master_objects[i];
            }
        }
        free(this->master_objects);
        this->master_objects = 0;
        this->master_object_num = 0;
    }

    visible_map = this->visible;
    if (visible_map != 0) {
        delete visible_map;
    }
    doppleganger_creator = this->doppleganger_creator;
    if (doppleganger_creator != 0) {
        delete doppleganger_creator;
    }
    resource_manager = this->VR_List;
    if (resource_manager != 0) {
        delete resource_manager;
    }
    if (this->name != 0) {
        free(this->name);
        this->name = 0;
    }
    if (this->attribute_num > 0) {
        free(this->attributes);
        this->attribute_num = 0;
    }
}

void RGE_Player::set_game_status(unsigned char status) {
    RGE_Player* p = this;
    if (status == p->game_status) return;
    if (p->resigned && status != 2) return;
    p->game_status = status;
    if (status == 2 && !p->resigned) {
    rge_base_game->notification(6, p->id, 0, 0, 0);
    }
}

void RGE_Player::do_resign(int value) {
    unsigned char resigned = this->resigned;
    this->resigned = 1;
    this->set_game_status(2);
    if (!resigned) {
        rge_base_game->notification(5, this->id, value, 0, 0);
    }
}

unsigned char RGE_Player::get_resigned() {
    return this->resigned;
}

char* RGE_Player::aiStatus(int) {
    return 0;
}

int RGE_Player::computerPlayer() const {
    return this->computerPlayerValue;
}

int RGE_Player::isEnemy(int player) {
    if ((((player != this->id) && (player > 0)) && (player < this->world->player_num)) && (this->relations[player] == 3)) {
        return 1;
    }
    return 0;
}

int RGE_Player::isAlly(int player) {
    if (player == this->id) {
        return 1;
    }
    if ((((0 < player) && (player < this->world->player_num)) && (this->relations[player] == 0))) {
        return 1;
    }
    return 0;
}

int RGE_Player::isNeutral(int player) {
    if ((((player != this->id) && (player > 0)) && (player < this->world->player_num)) && (this->relations[player] == 1)) {
        return 1;
    }
    return 0;
}

int RGE_Player::isAllNeutral(void) {
    RGE_Player* p = this;
    for (int i = 1; i < p->world->player_num; i++) {
        if (i != p->id) {
            if (p->isNeutral(i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void RGE_Player::setDiplomaticStance(int, int) {
}

void RGE_Player::loadAIInformation(char*, char*, char*, int, int) {
}

void RGE_Player::sendUnitAIOrder(int p1, int p2, int p3, int p4, int p5, float p6, float p7, float p8, float p9, int p10, int p11, int p12)
{
    this->world->commands->command_ai_order(p1, p1, p2, p3, p4, p5, p6, p7,
                                             p8, p9, p10, p11, p12);
}

void RGE_Player::processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) {
    RGE_Static_Object* obj;
    UnitAIModule* ai;

    obj = this->world->object(param_2);
    if (obj == 0) {
        return;
    }

    ai = obj->unitAI();
    if (ai == 0) {
        return;
    }

    ai = obj->unitAI();
    ai->order(param_1, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12);
}

void RGE_Player::sendGameOrder(RGE_Static_Object* src, RGE_Static_Object* dst, float x, float y) {
    RGE_Static_Object* order_src;

    order_src = src;
    this->world->commands->command_order(&order_src, 1, dst, x, y);
}

void RGE_Player::sendAddWaypointCommand(int a, XYZBYTEPoint* b, int c) {
    int pid = (int)this->id;
    this->world->commands->command_add_waypoint(pid, a, b, c);
}

void RGE_Player::processAddWaypointCommand(int object_id, XYZBYTEPoint* waypoints, int count) {
    RGE_Static_Object* object;

    object = this->world->object(object_id);
    if ((object != 0) && (count > 0)) {
        int n;
        n = count;
        do {
            object->addUserDefinedWaypoint(waypoints, 1);
            waypoints = waypoints + 1;
            n = n - 1;
        } while (n != 0);
    }
}

void RGE_Player::sendPlayCommand(int param_1, int param_2, int param_3)
{
    int selectedUnits[25];
    int selectedCount;
    int* selectedUnit;
    RGE_Static_Object** source;

    this->command_destroy_group(param_1);
    if (this->world->playbook->play(param_3) == 0) {
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d7, -1, -1,
                              -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
        return;
    }

    selectedCount = 0;
    selectedUnit = selectedUnits;
    source = this->sel_list;
    for (int n = 25; n != 0; ++source, --n) {
        RGE_Static_Object* object = *source;
        if (object != 0) {
            ++selectedCount;
            *selectedUnit = object->id;
            ++selectedUnit;
        }
    }

    if (selectedCount != 0) {
        this->command_create_group(param_1, selectedUnits, selectedCount, 2.0f);
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d6, param_2, param_3,
                              -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
    }
}

void RGE_Player::sendPlayCommand(int param_1, int* param_2, int param_3,
                                 int param_4, int param_5)
{
    this->command_destroy_group(param_1);
    AIPlay* play = this->world->playbook->play(param_5);
    if (play == 0) {
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d7, -1, -1,
                              -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
        return;
    }
    if (param_3 != 0) {
        this->command_create_group(param_1, param_2, param_3, 2.0f);
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d6, param_4,
                              param_5, -1.0f, -1.0f, -1.0f, -1.0f, 1, 0,
                              100);
    }
}

int RGE_Player::pathingAttemptCap() {
    return this->pathingAttemptCapValue;
}

void RGE_Player::setPathingAttemptCap(int v) {
    this->pathingAttemptCapValue = v;
}

int RGE_Player::pathingDelayCap() {
    return this->pathingDelayCapValue;
}

void RGE_Player::setPathingDelayCap(int v) {
    this->pathingDelayCapValue = v;
}

int RGE_Player::currentUpdatePathingAttempts() {
    return this->currentUpdatePathingAttemptsValue;
}

int RGE_Player::availablePathingAttempts(int value) {
    if (pathingDelayCapValue != -1 && value > pathingDelayCapValue) {
        return 1;
    }
    if (pathingAttemptCapValue == -1) {
        return 1;
    }
    return currentUpdatePathingAttemptsValue < pathingAttemptCapValue;
}

void RGE_Player::incrementPathingAttempts() {
    this->currentUpdatePathingAttemptsValue++;
}

void __cdecl RGE_Player::sendChatMessage(int player, int mode, char* message, ...)
{
    char textOut[1025];

    vsprintf(textOut, message, (char*)(&message + 1));

    int i;

    if (strlen(textOut) != 0) {
        for (i = 1; i <= rge_base_game->numberPlayers(); ++i) {
            int playerID = rge_base_game->playerID(i);
            if (playerID == player) {
                this->world->commands->com_hand->SendChatMsg(
                    this->id, i, textOut);
            }
        }

        if (mode == 1 && player != this->id) {
            for (i = 1; i <= rge_base_game->numberPlayers(); ++i) {
                int playerID = rge_base_game->playerID(i);
                if (playerID == this->id) {
                    this->world->commands->com_hand->SendChatMsg(
                        this->id, i, textOut);
                }
            }
        }
    }
}

RGE_Static_Object* RGE_Player::make_scenario_obj(float x, float y, float z, short typeID, unsigned char objType, float param6) {
    RGE_Static_Object* obj = 0;
    RGE_Master_Static_Object* master = this->master_objects[typeID];
    if (master != 0) {
        obj = (RGE_Static_Object*)master->make_new_obj(this, x, y, z);
        if (objType >= 7) {
            obj->destroy_obj();
        } else if (objType > 2) {
            obj->die_die_die();
        } else {
            obj->new_angle(param6);
        }
    }
    return obj;
}

void RGE_Player::scenario_save(int) {
}

void RGE_Player::scenario_load(int file, long* pos, float version)
{
    short name_length;
    unsigned char player_count;
    short count;
    int human_team;
    int saved_human_team;

    if (version <= 1.05) {
        int file_handle = file;
        rge_read(file, &name_length, 2);
        if (name_length > 0) {
            char* name_buffer;
            name_buffer = (char*)calloc((int)name_length, 1);
            rge_read(file_handle, name_buffer, (int)name_length);
            if (this->name == 0) {
                this->name = name_buffer;
            } else {
                free(name_buffer);
            }
        }

        rge_read(file_handle, &this->view_x, 4);
        rge_read(file_handle, &this->view_y, 4);
        rge_read(file_handle, &this->map_x, 2);
        rge_read(file_handle, &this->map_y, 2);

        human_team = 0;
        saved_human_team = 0;
        if (rge_base_game->prog_mode != 7) {
            for (int player = 1; player < 9; player++) {
                if (rge_base_game->playerID(player) == this->id &&
                    (comm->GetPlayerHumanity(player) == 2 ||
                     comm->GetPlayerHumanity(player) == 4)) {
                    if (rge_base_game->playerTeam(player - 1) > 1) {
                        human_team = 1;
                        saved_human_team = 1;
                    }
                    break;
                }
            }
        }

        if (version > 1.0) {
            rge_read(file_handle, &player_count, 1);
            if (human_team == 0) {
                this->allied_victory = player_count;
            }
        }

        short i = 0;
        this->allied_LOS_Enable = 0;
        if (this->attribute_num > 0) {
            rge_read(file, this->attributes, 0x74);
        }

        rge_read(file_handle, &count, 2);
        if (count > 0) {
            do {
                unsigned char relation_value;
                rge_read(file_handle, &relation_value, 1);
                if (human_team == 0) {
                    long* player_id = &pos[i];
                    if (*player_id < this->world->player_num && *player_id >= 0) {
                        this->relations[*player_id] = relation_value;
                        if (*player_id == 0) {
                            this->unitDiplomacy[0] = 0;
                        } else if (i == this->id) {
                            this->unitDiplomacy[*player_id] = 1;
                        } else if (relation_value == 0) {
                            this->unitDiplomacy[*player_id] = 2;
                        } else if (relation_value == 1) {
                            this->unitDiplomacy[*player_id] = 3;
                        } else {
                            this->unitDiplomacy[*player_id] = 4;
                        }
                    }
                }
                ++i;
                human_team = saved_human_team;
            } while (i < count);
        }

        if (version > 1.08) {
            rge_read(file_handle, this->unitDiplomacy, 0x24);
        }

        if (this->victory_conditions != 0) {
            delete this->victory_conditions;
        }

        this->load_victory(file_handle, pos, 0);
    }
}

void RGE_Player::scenario_postsave(int file)
{
    short count = strlen(this->name) + 1;

    rge_write(file, &count, 2);
    rge_write(file, this->name, count);
    rge_write(file, &this->view_x, 4);
    rge_write(file, &this->view_y, 4);
    rge_write(file, &this->map_x, 2);
    rge_write(file, &this->map_y, 2);
    rge_write(file, &this->allied_victory, 1);
    rge_write(file, &this->world->player_num, 2);
    rge_write(file, this->relations, this->world->player_num);
    rge_write(file, this->unitDiplomacy, 0x24);
    this->victory_conditions->save(file);
}

void RGE_Player::scenario_postload(int file, long* data, float version)
{
    int file_handle = file;
    short has_team;
    short count;
    unsigned char player_count;
    int has_human_team;
    unsigned char temp_byte;

    rge_read(file_handle, &has_team, 2);
    if (has_team > 0) {
        char* name = (char*)calloc((int)has_team, 1);
        rge_read(file_handle, name, (int)has_team);
        if (this->name == 0) {
            this->name = name;
        }
        else {
            free(name);
        }
    }

    rge_read(file_handle, &this->view_x, 4);
    rge_read(file_handle, &this->view_y, 4);
    rge_read(file_handle, &this->map_x, 2);
    rge_read(file_handle, &this->map_y, 2);

    has_human_team = 0;
    if (rge_base_game->prog_mode != 7) {
        for (int player = 1; player < 9; ++player) {
            if (rge_base_game->playerID(player) == this->id &&
                (comm->GetPlayerHumanity(player) == 2 ||
                 comm->GetPlayerHumanity(player) == 4)) {
                if (rge_base_game->playerTeam(player - 1) > 1) {
                    has_human_team = 1;
                }
                break;
            }
        }
    }

    if (version > 1.0) {
        rge_read(file_handle, &player_count, 1);
        if (has_human_team == 0) {
            this->allied_victory = player_count;
        }
    }

    this->allied_LOS_Enable = 0;
    if (version <= 1.06 && this->attribute_num > 0) {
        rge_read(file_handle, this->attributes, 0x74);
    }

    rge_read(file_handle, &count, 2);
    short i = 0;
    if (count > 0) {
        do {
            rge_read(file_handle, &temp_byte, 1);
            if (has_human_team == 0) {
                short player_id;
                if (data != 0) {
                    player_id = (short)data[i];
                }
                else {
                    player_id = i;
                }
                if (player_id < this->world->player_num && player_id >= 0) {
                    this->relations[player_id] = temp_byte;
                    if (player_id == 0) {
                        this->unitDiplomacy[0] = 0;
                    }
                    else if (player_id == this->id) {
                        this->unitDiplomacy[player_id] = 1;
                    }
                    else if (temp_byte == 0) {
                        this->unitDiplomacy[player_id] = 2;
                    }
                    else if (temp_byte == 1) {
                        this->unitDiplomacy[player_id] = 3;
                    }
                    else {
                        this->unitDiplomacy[player_id] = 4;
                    }
                }
            }
            ++i;
        } while (i < count);
    }

    if (version >= 1.08) {
        rge_read(file_handle, this->unitDiplomacy, 0x24);
    }

    RGE_Victory_Conditions* victory = this->victory_conditions;
    if (victory != 0) {
        delete victory;
    }

    if (version >= 1.09) {
        this->load_victory(file_handle, data, 1);
    }
    else {
        this->load_victory(file_handle, data, 0);
    }
}

void RGE_Player::load(int file)
{
    rge_read(file, &this->master_object_num, 2);

    if (this->master_object_num > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc(
            (int)this->master_object_num, 4);
        rge_read(file, this->master_objects,
                 (int)this->master_object_num * 4);

        for (short i = 0; i < this->master_object_num; ++i) {
            if (this->master_objects[i] != 0) {
                unsigned char type;
                rge_read(file, &type, 1);
                this->load_master_object(file, i, type,
                                         this->world->sprites,
                                         this->world->sounds);
            }
        }
    } else {
        this->master_objects = 0;
    }

    this->visible = new RGE_Visible_Map(file, this->world);
    this->VR_List = new Visible_Resource_Manager(file, this);
    this->objects = new RGE_Object_List;
    this->objects->load_list(file, this->world);
    this->sleeping_objects = new RGE_Object_List;
    this->doppleganger_objects = new RGE_Object_List;
    this->sleeping_objects->load_list(file, this->world);

    if (!(save_game_version < DAT_00570ec0)) {
        this->doppleganger_objects->load_list(file, this->world);
    }
}

void RGE_Player::load_master_object(int file, short index, unsigned char type,
                                     RGE_Sprite** sprites, RGE_Sound** sounds)
{
    RGE_Master_Static_Object* object;

    switch (type) {
    case 10:
        object = new RGE_Master_Static_Object(file, sprites, sounds, 1);
        break;
    case 20:
        object = new RGE_Master_Animated_Object(file, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 30:
        object = new RGE_Master_Moving_Object(file, sprites, sounds, 1);
        break;
    case 60:
        object = new RGE_Master_Missile_Object(file, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 40:
        object = new RGE_Master_Action_Object(file, sprites, sounds, 1);
        break;
    case 50:
        object = new RGE_Master_Combat_Object(file, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 25:
        object = new RGE_Master_Doppleganger_Object(file, sprites, sounds, 1);
        break;
    default:
        return;
    }

    this->master_objects[index] = object;
}

void RGE_Player::load_info(int infile) {
    this->load_victory(infile, 0, 1);
    this->objects->rehook_list();
    this->sleeping_objects->rehook_list();
    this->doppleganger_objects->rehook_list();
}

long RGE_Player::get_checksum(void) {
    if (this->checksum_created_this_update == 0) {
        this->create_checksum();
    }
    return this->checksum;
}

unsigned char RGE_Player::get_checksums(long& cksum1, long& cksum2,
                                        long& cksum3) {
    if (!this->checksum_created_this_update) {
        this->create_checksum();
    }
    cksum1 = this->checksum;
    cksum2 = this->position_checksum;
    cksum3 = this->action_checksum;
    return 1;
}

long RGE_Player::create_checksum(void) {
    int attribute_checksum = 0;
    int object_checksum = 0;
    int object_count = 0;
    float position_checksum = 0.0f;
    long result = (long)this->id;
    this->checksum_created_this_update = 1;
    this->action_checksum = 0;

    result += this->sleeping_objects->number_of_objects;
    result += this->doppleganger_objects->number_of_objects;
    long attribute_count;
    long attribute_num_value = (long)this->attribute_num;

    if (attribute_num_value > 0) {
        attribute_count = attribute_num_value;
        float* attribute = this->attributes;
        do {
            attribute_checksum += (int)*attribute;
            ++attribute;
            --attribute_count;
        } while (attribute_count != 0);
    }

    for (RGE_Object_Node* list = this->objects->list;
         list != 0;
         list = list->next) {
        RGE_Static_Object* object = list->node;
        unsigned char state = object->object_state;
        object_checksum += (int)state;
        object_checksum += (int)object->attribute_amount_held;
        object_checksum += (int)object->master_obj->id;
        object_checksum += object->get_waypoint_checksum();
        ++object_count;
        position_checksum = list->node->world_x + position_checksum;
        position_checksum += list->node->world_y;
        position_checksum += list->node->world_z;
        this->action_checksum += list->node->get_action_checksum();
    }

    result = (result * 0x100 + object_count) * 0x100 + object_checksum;
    result = result * 0x100 + attribute_checksum;
    this->checksum = result;
    this->position_checksum = (long)position_checksum;
    return result;
}

void RGE_Player::new_attribute_num(short attrib, float value) {
    if (attrib < 0) {
        return;
    }
    if (attrib >= this->attribute_num) {
        return;
    }
    this->attributes[(int)attrib] = value;
}

void RGE_Player::add_attribute_num(short attrib, float value, unsigned char unused) {
    if (attrib < 0) return;
    if (attrib >= this->attribute_num) return;
    this->attributes[(int)attrib] = value + this->attributes[(int)attrib];
}

void RGE_Player::make_available(short param_1, unsigned char param_2) {
    RGE_Master_Static_Object* master_object;

    master_object = this->master_objects[param_1];
    if (master_object != 0) {
        master_object->make_available(param_2);
    }
}

void RGE_Player::update() {
    // Line 1231: prolog handled by compiler (push esi; mov esi, ecx)
    // Line 1235: load global MouseSystem and test
    if (MouseSystem) {
        MouseSystem->Poll(); // line 1236
    }

    // Line 1242: zero pathing attempts counter, then update object list
    this->currentUpdatePathingAttemptsValue = 0;
    this->objects->update();

    // Line 1243: update selected units/objects
    this->update_selected();

    // Line 1244-1245: update victory conditions and check result
    if (this->victory_conditions->update() == 1) {
        // vt[1]: call set_game_status(2)
        this->set_game_status(2);
    }

    // Line 1251: clear per-update checksum flag before VR_List processing
    this->checksum_created_this_update = 0;

    // Line 1251-1252: if VR_List exists, process new tiles
    if (this->VR_List) {
        // Pass address of tile_list (offset 0x58 from this)
        this->VR_List->Process_New_Tiles(&this->tile_list);
    }

    // Epilog: compiler will emit pop esi; ret
}

void RGE_Player::update_dopplegangers(void) {
    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }
    this->doppleganger_objects->update();
    this->doppleganger_creator->perform_doppleganger_checks();
}

void RGE_Player::save(int file)
{
    int name_length;
    unsigned char table;

    color_log(0x32, 0x32, 3);
    rge_write(file, &this->type, 1);
    rge_write(file, this->relations, (int)this->world->player_num);
    rge_write(file, this->unitDiplomacy, 0x24);
    rge_write(file, &this->allied_LOS_Enable, 4);
    rge_write(file, &this->allied_victory, 1);

    name_length = strlen(this->name) + 1;
    rge_write(file, &name_length, 2);
    if ((short)name_length > 0) {
        rge_write(file, this->name, (short)name_length);
    }

    rge_write(file, &this->attribute_num, 2);
    short attribute_count = this->attribute_num;
    if (attribute_count > 0) {
        rge_write(file, this->attributes, (int)attribute_count << 2);
    }

    rge_write(file, &this->view_x, 4);
    rge_write(file, &this->view_y, 4);
    rge_write(file, &this->map_x, 2);
    rge_write(file, &this->map_y, 2);
    rge_write(file, &this->culture, 1);
    rge_write(file, &this->master_player_id, 1);
    rge_write(file, &this->game_status, 1);
    rge_write(file, &this->resigned, 1);

    if (this->color_table != 0) {
        table = (unsigned char)this->color_table->id;
    } else {
        table = 0;
    }
    rge_write(file, &table, 1);
    rge_write(file, &this->pathingAttemptCapValue, 4);
    rge_write(file, &this->pathingDelayCapValue, 4);
    color_log(0x32, 0x5F, 3);
}

void RGE_Player::save2(int file) {
    int save_file;
    short* master_object_count;

    color_log('L', 'L', 4);
    save_file = file;
    master_object_count = &this->master_object_num;
    rge_write(save_file, master_object_count, 2);

    if (0 < *master_object_count) {
        int i = 0;
        while (i < *master_object_count) {
            file = (int)this->master_objects[i];
            if (file != 0) {
                file = 1;
            }
            rge_write(save_file, &file, 4);
            ++i;
        }

        short j = 0;
        while (j < *master_object_count) {
            RGE_Master_Static_Object* object = this->master_objects[j];
            if (object != 0) {
                object->save(save_file);
            }
            ++j;
        }
    }

    color_log('L', '$', 4);
    this->visible->save(save_file);
    this->VR_List->save(save_file);
    color_log('L', 0x16, 4);
    this->objects->save(save_file);
    color_log('L', '2', 4);
    this->sleeping_objects->save(save_file);
    color_log('L', '2', 4);
    this->doppleganger_objects->save(save_file);
    color_log('L', '_', 4);
}

void RGE_Player::save_info(int param) {
    this->victory_conditions->save(param);
}

void RGE_Player::set_map_loc(short a, short b) {
    this->map_x = a;
    this->map_y = b;
}

void RGE_Player::set_view_loc(float x, float y)
{
    this->view_x = x;
    this->view_y = y;

    if (x < 0.0f)
        this->view_x = 0.0f;
    else if (x > (float)(this->world->map->map_width - 1))
        this->view_x = (float)(this->world->map->map_width - 1);

    if (y < 0.0f)
        this->view_y = 0.0f;
    else if (y > (float)(this->world->map->map_height - 1))
        this->view_y = (float)(this->world->map->map_height - 1);
}

void RGE_Player::random_start() {
}

void RGE_Player::destroy_objects() {
    RGE_Object_Node* node;

    node = this->objects->list;
    while (node != 0) {
        node->node->destroy_obj();
        node = node->next;
    }
}

void RGE_Player::set_color_table(unsigned char param) {
    this->color_table = this->world->color_tables[param];
}

void RGE_Player::victory_if_game_on(void) {
    if (this->game_status == 0) {
        this->set_game_status(1);
    }
}

void RGE_Player::loss_if_game_on(void) {
    if (this->game_status == 0) {
        this->set_game_status(2);
    }
}

void RGE_Player::win_game_now() {
    this->victory_if_game_on();
    for (int i = 1; i < this->world->player_num; i++) {
        if (i != this->id) {
            if (this->allied_victory) {
                if (!this->relation(i)) {
                    if (!this->world->players[i]->relation((long)this->id) && this->world->players[i]->allied_victory) {
                        this->world->players[i]->victory_if_game_on();
                        continue;
                    }
                }
            }
            this->world->players[i]->loss_if_game_on();
        }
    }
}

unsigned char RGE_Player::check_victory_conditions(void) {
    if (this->game_status != 2) {
        return this->victory_conditions->victory_achieved();
    }
    return 1;
}

unsigned char RGE_Player::check_ally_group(long& count)
{
    long old = count;
    unsigned char ok = 1;

    if (this->game_status != 2) {
        count = 0;
        RGE_Game_World* world = this->world;
        int i = 1;
        if (world->player_num > 1) {
            do {
                if (this->relations[i] == 0) {
                    if (world->players[i]->relation(this->id) != 0)
                        goto failed;
                    if (this->world->players[i]->allied_victory == 0)
                        goto failed;
                }
                count++;
                i++;
                world = this->world;
            } while (i < world->player_num);
        }
    }

    goto done;

failed:
    ok = 0;

done:
    if (old >= 0 && count != old)
        ok = 0;

    return ok;
}

unsigned char RGE_Player::check_victory(void)
{
    long ally = -1;

    if (this->game_status != 2 && this->victory_conditions->victory_achieved()) {
        unsigned char found = 0;
        if (this->allied_victory) {
            for (int i = 1; i < this->world->player_num; i++) {
                if ((i == this->id || this->relations[i] == 0) &&
                    this->world->players[i]->check_ally_group(ally) == 0) {
                    found = 1;
                    break;
                }
            }
        }
        if (this->allied_victory) {
            if (found) return this->game_status;
            for (int i = 1; i < this->world->player_num; i++) {
                if (this->relations[i] == 0 &&
                    this->world->players[i]->check_victory_conditions() == 0) {
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            this->set_game_status(1);
            this->world->game_end_condition = 2;
        }
    }
    return this->game_status;
}

void RGE_Player::modify_tobj(short object_num, short object_group,
                             float amount, unsigned char amount_type)
{
    if (object_num >= 0) {
        short i = object_num;
        if (master_objects[i] != 0) {
            if (objects != 0) {
                RGE_Object_Node* node = objects->list;
                while (node != 0) {
                    if (node->node->master_obj == master_objects[i]) {
                        node->node->modify(amount, amount_type);
                    }
                    node = node->next;
                }
            }
            master_objects[i]->modify(amount, amount_type);
        }
    } else if (object_group >= 0) {
        short i = 0;
        if (master_object_num > 0) {
            do {
                if (master_objects[i] != 0 &&
                    master_objects[i]->object_group == object_group) {
                    if (objects != 0) {
                        RGE_Object_Node* node = objects->list;
                        while (node != 0) {
                            if (node->node->master_obj == master_objects[i]) {
                                node->node->modify(amount, amount_type);
                            }
                            node = node->next;
                        }
                    }
                    master_objects[i]->modify(amount, amount_type);
                }
                ++i;
            } while (i < master_object_num);
        }
    }
}

void RGE_Player::modify_tobj_delta(short object_num, short object_group,
                                   float amount, unsigned char amount_type)
{
    if (object_num >= 0) {
        short i = object_num;
        if (master_objects[i] != 0) {
            if (objects != 0) {
                RGE_Object_Node* node = objects->list;
                while (node != 0) {
                    if (node->node->master_obj == master_objects[i]) {
                        node->node->modify_delta(amount, amount_type);
                    }
                    node = node->next;
                }
            }
            master_objects[i]->modify_delta(amount, amount_type);
        }
    } else if (object_group >= 0) {
        short i = 0;
        if (master_object_num > 0) {
            do {
                if (master_objects[i] != 0 &&
                    master_objects[i]->object_group == object_group) {
                    if (objects != 0) {
                        RGE_Object_Node* node = objects->list;
                        while (node != 0) {
                            if (node->node->master_obj == master_objects[i]) {
                                node->node->modify_delta(amount, amount_type);
                            }
                            node = node->next;
                        }
                    }
                    master_objects[i]->modify_delta(amount, amount_type);
                }
                ++i;
            } while (i < master_object_num);
        }
    }
}

void RGE_Player::modify_tobj_percent(short object_num, short object_group,
                                     float amount, unsigned char amount_type)
{
    if (object_num >= 0) {
        short i = object_num;
        if (master_objects[i] != 0) {
            if (objects != 0) {
                RGE_Object_Node* node = objects->list;
                while (node != 0) {
                    if (node->node->master_obj == master_objects[i]) {
                        node->node->modify_percent(amount, amount_type);
                    }
                    node = node->next;
                }
            }
            master_objects[i]->modify_percent(amount, amount_type);
        }
    } else if (object_group >= 0) {
        short i = 0;
        if (master_object_num > 0) {
            do {
                if (master_objects[i] != 0 &&
                    master_objects[i]->object_group == object_group) {
                    if (objects != 0) {
                        RGE_Object_Node* node = objects->list;
                        while (node != 0) {
                            if (node->node->master_obj == master_objects[i]) {
                                node->node->modify_percent(amount, amount_type);
                            }
                            node = node->next;
                        }
                    }
                    master_objects[i]->modify_percent(amount, amount_type);
                }
                ++i;
            } while (i < master_object_num);
        }
    }
}

void RGE_Player::copy_obj(short srcIndex, short destIndex) {
    if (this->master_objects[srcIndex] == 0) return;
    if (this->master_objects[destIndex] == 0) return;
    if (this->objects != 0) {
        RGE_Object_Node* node = this->objects->list;
        while (node != 0) {
            RGE_Static_Object* obj = node->node;
            if (obj->master_obj == this->master_objects[srcIndex]) {
                obj->copy_obj(this->master_objects[destIndex]);
            }
            node = node->next;
        }
    }
    this->master_objects[srcIndex]->copy_obj(this->master_objects[destIndex]);
}

void RGE_Player::set_allied_victory(unsigned char v) {
    this->allied_victory = v;
}

unsigned char RGE_Player::get_allied_victory() {
    return this->allied_victory;
}

unsigned char RGE_Player::relation(long param) {
    return relations[param];
}

void RGE_Player::set_relation(long playerId, unsigned char relation) {
    this->relations[playerId] = relation;

    if (playerId == 0) {
        this->unitDiplomacy[0] = 0;
    } else if (playerId == this->id) {
        this->unitDiplomacy[playerId] = 1;
    } else if (relation == 0) {
        this->unitDiplomacy[playerId] = 2;
    } else if (relation == 1) {
        this->unitDiplomacy[playerId] = 3;
    } else {
        this->unitDiplomacy[playerId] = 4;
    }

    RGE_Object_Node* node = this->objects->list;
    while (node != 0) {
        node->node->notify_of_relation(playerId, relation);
        node = node->next;
    }
}

RGE_Static_Object* RGE_Player::make_new_object(long id, float x, float y, float z, int unused) {
    if ((id >= 0) && (this->master_objects[id] != 0)) {
        return this->master_objects[id]->make_new_obj(this, x, y, z);
    }
    return 0;
}

void RGE_Player::reset_selected() {
    this->selected_start_col = -1;
    this->selected_start_row = -1;
    this->selected_end_col = -1;
    this->selected_end_row = -1;
    this->replacement_terrain = -1;
    this->replacement_overlay = -1;
    this->replacement_overlay_shape = -1;
    this->sel_count = 0;
    this->selected_obj = 0;
    memset(this->sel_list, 0, 0x64);
    memset(this->groups_used, 0, 0x7F);
}

int RGE_Player::select_object(RGE_Static_Object* object) {
    RGE_Player* player = this;
    RGE_Static_Object* selected = object;
    RGE_Object_Node* node;
    unsigned char group;

    if (player->select_one_object(selected, 1) == 0) {
        return 0;
    }

    group = selected->selected_group;
    if (group > 0x0A) {
        node = player->objects->list;
        while (node != 0) {
            if (node->node != selected && node->node->selected_group == group) {
                if (player->select_one_object(node->node, 0) == 0) {
                    break;
                }
            }
            node = node->next;
        }
    }

    player->selected_obj = selected;
    return 1;
}

int RGE_Player::select_one_object(RGE_Static_Object* obj, int play_sound)
{
    short count = this->sel_count;
    if (count < 25) {
        short slot = -1;
        if (this->sel_list[count] == 0) {
            slot = count;
        } else {
            short i = 0;
            if (count > 0) {
                for (; i < count; ++i) {
                    if (this->sel_list[i] == 0) {
                        slot = i;
                        break;
                    }
                }
            }
        }
        if (slot != -1) {
            this->sel_list[slot] = obj;
            ++this->sel_count;
            this->selected_obj = obj;
            obj->selected = 1;
            if (play_sound != 0) {
                RGE_Sound* sound = obj->master_obj->selected_sound;
                if (sound != 0) {
                    RGE_Player* owner = obj->owner;
                    if (owner == this || owner->id == 0)
                        sound->play(1);
                }
            }
            return 1;
        }
    }
    return 0;
}

void RGE_Player::unselect_object() {
    short i;
    short removed_count;
    RGE_Static_Object* obj;

    if (this->sel_count > 0) {
        i = 0;
        this->selected_obj = 0;
        removed_count = 0;
        for (; i < 25; ++i) {
            if (removed_count >= this->sel_count) {
                break;
            }
            obj = this->sel_list[i];
            if (obj != 0) {
                obj->selected = 0;
                ++removed_count;
                this->sel_list[i] = 0;
            }
        }
        this->sel_count = 0;
    }
}

void RGE_Player::unselect_one_object(RGE_Static_Object* object) {
    short slot;
    short count;
    RGE_Static_Object* current;

    if (this->sel_count <= 0) {
        return;
    }

    slot = 0;
    count = 0;
    while (slot < 25) {
        if (count >= this->sel_count) {
            return;
        }
        current = this->sel_list[slot];
        if (current != 0) {
            if (current == object) {
                this->unselect_one_object(slot);
                return;
            }
            count = count + 1;
        }
        slot = slot + 1;
    }
}

void RGE_Player::unselect_one_object(short index)
{
    int i = index;
    RGE_Static_Object* obj = sel_list[i];
    if (obj != 0) {
        obj->selected = 0;
        int count = sel_count;
        int last = count - 1;
        if (i >= last) {
            sel_list[i] = 0;
        } else {
            sel_list[i] = sel_list[count - 1];
            sel_list[sel_count - 1] = 0;
        }
        RGE_Static_Object* cur = selected_obj;
        --sel_count;
        short new_count = sel_count;
        if (cur == obj) {
            selected_obj = 0;
            if (new_count > 0) {
                for (short j = 0; j < 25; ++j) {
                    if (sel_list[j] != 0) {
                        selected_obj = sel_list[j];
                        return;
                    }
                }
            }
        }
    }
}

int RGE_Player::group_objects(int group)
{
    unsigned char selected_group;
    if (!sel_count) {
        return 0;
    }

    if (group == -1) {
        short i = 0x0B;
        for (; i < 0x7F; ++i) {
            if (groups_used[i]) {
                continue;
            }
            selected_group = (unsigned char)i;
            groups_used[i] = 1;
            break;
        }

        if (i == 0x7F) {
            for (int clear_i = 1; clear_i < 0x7F; ++clear_i) {
                groups_used[clear_i] = 0;
            }

            RGE_Object_Node* node = objects->list;
            while (node) {
                selected_group = node->node->selected_group;
                if (selected_group && !groups_used[selected_group]) {
                    groups_used[selected_group] = 1;
                }
                node = node->next;
            }

            i = 1;
            for (; i < 0x7F; ++i) {
                if (groups_used[i]) {
                    continue;
                }
                selected_group = (unsigned char)i;
                groups_used[i] = 1;
                break;
            }

            if (i == 0x7F) {
                return 0;
            }
        }
    } else {
        selected_group = (unsigned char)group;
        RGE_Object_Node* node = objects->list;
        while (node) {
            if (node->node->selected_group == (unsigned char)group) {
                node->node->selected_group = 0;
            }
            node = node->next;
        }
    }

    short i = 0;
    short count = 0;
    while (i < 0x19) {
        if (count >= sel_count) {
            break;
        }
        RGE_Static_Object* object = sel_list[i];
        if (object && object->owner == this) {
            ++count;
            object->selected_group = selected_group;
        }
        ++i;
    }

    return 1;
}

int RGE_Player::select_group(int group) {
    int first = 1;
    RGE_Object_Node* node = this->objects->list;
    while (node != 0) {
        RGE_Static_Object* obj = node->node;
        if (obj->selected_group == (unsigned char)group) {
            if (first) {
                if (this->select_one_object(obj, 1) == 0) break;
                first = 0;
            } else {
                if (this->select_one_object(obj, 0) == 0) break;
            }
        }
        node = node->next;
    }
    return first == 0;
}

int RGE_Player::own_selected()
{
    short sVar1;
    short sVar2;

    sVar1 = 0;
    sVar2 = 0;
    while (sVar1 < 0x19) {
        if (sVar2 >= this->sel_count)
            return 0;
        if (this->sel_list[sVar1] != 0) {
            sVar2 = sVar2 + 1;
            if (this->sel_list[sVar1]->owner == this)
                return 1;
        }
        sVar1 = sVar1 + 1;
    }

    return 0;
}

int RGE_Player::is_category_selected(short category)
{
    short sVar1;
    short sVar2;

    sVar1 = 0;
    sVar2 = 0;
    while (sVar1 < 0x19) {
        if (sVar2 >= this->sel_count)
            return 0;
        if (this->sel_list[sVar1] != 0) {
            sVar2 = sVar2 + 1;
            if (this->sel_list[sVar1]->master_obj->id == category)
                return 1;
        }
        sVar1 = sVar1 + 1;
    }

    return 0;
}

int RGE_Player::is_group_selected(short group)
{
    short sVar1;
    short sVar2;

    sVar1 = 0;
    sVar2 = 0;
    while (sVar1 < 0x19) {
        if (sVar2 >= this->sel_count)
            return 0;
        if (this->sel_list[sVar1] != 0) {
            sVar2 = sVar2 + 1;
            if (this->sel_list[sVar1]->master_obj->object_group == group)
                return 1;
        }
        sVar1 = sVar1 + 1;
    }

    return 0;
}

unsigned char RGE_Player::unit_level_selected() {
    unsigned char u = 0;
    short i = 0, j = 0;
    for (; i < 25; i++) {
        if (j >= sel_count) return u;
        RGE_Static_Object* p = sel_list[i];
        if (p != 0) {
            if (j != 0 && p->master_obj->unit_level != u) return 0;
            j++;
            u = p->master_obj->unit_level;
        }
    }
    return u;
}

unsigned char RGE_Player::get_select_level() {
    unsigned char select_level = 0xFF;
    short count = this->sel_count;
    short i = 0;
    short matches = 0;

    for (; i < 25; i++) {
        if (matches >= count) break;
        RGE_Static_Object* entry = this->sel_list[i];
        if (entry != 0) {
            unsigned char level = entry->master_obj->select_level;
            if (level < select_level) {
                select_level = level;
            }
            matches++;
        }
    }

    if (select_level == 0xFF)
        return 0;
    return select_level;
}

unsigned char RGE_Player::get_selected_objects_to_command(
    RGE_Static_Object*** out_list, short* out_count,
    short min_select_level, short object_group, short object_id,
    short unit_level)
{
    RGE_Player* player = this;
    long j;
    RGE_Static_Object** selected;
    short count = 0;
    RGE_Static_Object* object;
    RGE_Master_Static_Object* master;
    Selection_Locals locals;

    j = 0;
    *out_list = 0;
    *out_count = 0;
    if (player->sel_count == 0) {
        return 0;
    }

    locals.list = (RGE_Static_Object**)calloc(4, (unsigned int)player->sel_count);
    if (min_select_level == -1) {
        min_select_level = 4;
    }

    locals.list_count = 0;
    selected = player->sel_list;
    while (j < 0x19) {
        if (locals.list_count >= player->sel_count) {
            break;
        }

        object = *selected;
        if (object != 0) {
            if (object->object_state == 2 && object->owner == player) {
                master = object->master_obj;
                if (master->select_level >= min_select_level || player->id == 0) {
                    if (object_group == -1 ||
                        master->object_group == (unsigned char)object_group) {
                        if (object_id == -1 ||
                            master->id == (unsigned char)object_id) {
                            if (unit_level == -1 ||
                                master->unit_level == (unsigned char)unit_level) {
                                if (master->master_type >= 0x28 &&
                                    master->master_type != 0x5A) {
                                    locals.list[count] = object;
                                    ++count;
                                }
                            }
                        }
                    }
                }
            }
            ++locals.list_count;
        }
        ++j;
        ++selected;
    }

    if (count == 0) {
        free(locals.list);
        return 0;
    }

    *out_list = locals.list;
    *out_count = count;
    return 1;
}

void RGE_Player::update_selected() {
    RGE_Player* p = this;
    for (short index = 0, selected = 0; index < 25; index++) {
        if (selected >= p->sel_count) return;
        RGE_Static_Object* obj = p->sel_list[index];
        if (obj != 0) {
            if (obj->object_state < 7 && obj->inside_obj == 0)
                selected++;
            else
                p->unselect_one_object(index);
        }
    }
}

void RGE_Player::select_area(short start_col, short start_row, short end_col, short end_row) {
    this->selected_start_col = start_col;
    this->selected_start_row = start_row;
    this->selected_end_col = end_col;
    this->selected_end_row = end_row;
}

void RGE_Player::unselect_area(void) {
    this->selected_start_col = -1;
    this->selected_start_row = -1;
    this->selected_end_col = -1;
    this->selected_end_row = -1;
}

void RGE_Player::ungroup_objects(void) {
    int i = 0;
    int count = 0;
    RGE_Static_Object** object = this->sel_list;

    // The executable advances the index before the tile pointer.
    for (; i < 0x19; ++i, ++object) {
        if (count >= this->sel_count) {
            break;
        }
        if (*object != 0) {
            ++count;
            (*object)->selected_group = 0;
        }
    }
}

void RGE_Player::analyize_selected_objects() {
}

int RGE_Player::get_mouse_pointer_action_vars(int param1, int& param2, int& param3) {
    param2 = 0;
    param3 = 0;
    return 0;
}

unsigned char RGE_Player::command_make_move(RGE_Static_Object* target, float x, float y) {
    RGE_Static_Object** list;
    short count;
    if (get_selected_objects_to_command(&list, &count, -1, -1, -1, -1)) {
        list[0]->play_move_sound();
        this->world->commands->command_order(list, count, target, x, y);
        free(list);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_make_work(RGE_Static_Object* target, float x, float y) {
    RGE_Static_Object** list;
    short count;
    int i;

    if (this->get_selected_objects_to_command(&list, &count, -1, -1, -1, -1)) {
        RGE_Master_Static_Object* master = list[0]->get_command_master(target, x, y, 0);
        if (master != 0) {
            master->play_command_sound();
        }
        this->world->commands->command_work(list, count, target, x, y);
        if (target != 0) {
            i = 0;
            if (count > 0) {
                do {
                    this->sendUnitAIOrder((int)this->id, list[i]->id, 0x2bd,
                        target->id, (int)target->owner->id,
                        target->world_x, target->world_y, 1.0f,
                        target->master_obj->los * 0.5f, 0, 0, 100);
                    ++i;
                } while (i < count);
            }
        }
        free(list);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_make_do(RGE_Static_Object* target, float x, float y) {
    RGE_Static_Object** list;
    short count;
    if (get_selected_objects_to_command(&list, &count, -1, -1, -1, -1)) {
        RGE_Master_Static_Object* master = list[0]->get_command_master(target, x, y, 0);
        if (master != 0) {
            master->play_command_sound();
        }
        this->world->commands->command_order(list, count, target, x, y);
        free(list);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_stop(void) {
    RGE_Static_Object** list;
    short count;

    if (this->get_selected_objects_to_command(&list, &count, 3, -1, -1, -1)) {
        (*list)->play_move_sound();
        this->world->commands->command_order(list, count, 0, 0.0f, 0.0f);
        free(list);
        return 1;
    }

    return 0;
}

unsigned char RGE_Player::command_place_object(short object_id, float x, float y, float z) {
    if (object_id != -1 && this->master_objects[object_id] != 0) {
        this->world->commands->command_create(object_id, this->id, x, y, z);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_add_attribute(int param_1, float param_2) {
    if ((param_1 != -1) && (param_2 != 0.0f)) {
        this->world->commands->command_add_attribute((int)this->id, param_1, param_2);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_give_attribute(int param1, int param2, float param3) {
    if (param2 == -1) return 0;
    if (param3 == DAT_00570ec4) return 0;
    if (param3 <= this->attributes[param2]) {
        this->world->commands->command_give_attribute(this->id, param1, param2, param3);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_formation(int formation) {
    RGE_Static_Object** list;

    if (formation >= 0 && formation <= 5) {
        int iVar1 = formation;
        short count;
        if (this->get_selected_objects_to_command(&list, &count, -1, -1, -1, -1)) {
            (*list)->play_move_sound();
            this->world->commands->command_formation(list, count, iVar1);
            free(list);
            return 1;
        }
    }

    return 0;
}

unsigned char RGE_Player::command_stand_ground() {
    RGE_Static_Object** list;
    short count;

    if (get_selected_objects_to_command(&list, &count, -1, -1, -1, -1)) {
        list[0]->play_move_sound();
        this->world->commands->command_group_ai_order(this->id, this->id, list, count, 0x2d5, -1, -1, -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 100);
        free(list);
        return 1;
    }

    return 0;
}

unsigned char RGE_Player::command_create_group(int a, int* b, int c, float d) {
    int pid = (int)this->id;
    this->world->commands->command_create_group(pid, a, b, c, d);
    return 1;
}

unsigned char RGE_Player::command_add_to_group(int a, int b, float c) {
    int pid = (int)this->id;
    this->world->commands->command_add_to_group(pid, a, b, c);
    return 1;
}

unsigned char RGE_Player::command_remove_from_group(int a, int b) {
    int pid = (int)this->id;
    this->world->commands->command_remove_from_group(pid, a, b);
    return 1;
}

unsigned char RGE_Player::command_destroy_group(int group_id) {
    this->world->commands->command_destroy_group((int)this->id, group_id);
    return 1;
}

unsigned char RGE_Player::command_resign(int a, int b) {
    if (!this->game_status) {
        this->world->commands->command_resign((int)this->id, a, b);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_add_waypoint(float x, float y, float z) {
    RGE_Static_Object** list;
    short list_num;

    if (this->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
        list[0]->play_move_sound();
        this->world->commands->command_group_waypoint(list, list_num, (int)x, (int)y);
        free(list);
        return 1;
    }
    return 0;
}

RGE_Object_Node* RGE_Player::addObject(RGE_Static_Object* object, int is_sleeping, int use_doppleganger) {
    RGE_Object_Node* node;

    if (is_sleeping != 0) {
        node = this->sleeping_objects->add_node(object);
    } else if (use_doppleganger != 0) {
        node = this->doppleganger_objects->add_node(object);
    } else {
        node = this->objects->add_node(object);
    }

    this->world->addObject(object);
    return node;
}

void RGE_Player::removeObject(RGE_Static_Object* object, int param_2, int param_3, RGE_Object_Node* node) {
    if (param_2 != 0) {
        this->sleeping_objects->remove_node(object, node);
    } else if (param_3 != 0) {
        this->doppleganger_objects->remove_node(object, node);
    } else {
        this->objects->remove_node(object, node);
    }

    this->world->removeObject(object->id);
}

void __cdecl RGE_Player::logMessage(char*, ...) {
}

void RGE_Player::notify(int, int, int, long, long, long) {
}

void RGE_Player::set_map_visible() {
    this->visible->set_all(1);
}

void RGE_Player::remake_visible_map() {
    if (this->visible != 0) {
        delete this->visible;
    }
    this->visible = new RGE_Visible_Map(this->world->map, this);
}

void RGE_Player::load_victory(int param_1, long* param_2, unsigned char param_3) {
    RGE_Victory_Conditions* victory;

    victory = new RGE_Victory_Conditions(this, param_1, param_2, param_3);
    if (victory == 0) {
        victory = 0;
    }
    this->victory_conditions = victory;
}

void RGE_Player::new_victory() {
    RGE_Victory_Conditions* victory = new RGE_Victory_Conditions(this);
    this->victory_conditions = victory;
}

void RGE_Tile_List::add_node(int col, int row) {
    if (this->num_active >= this->list_size) {
        RGE_Tile_List_Node* new_list;
        new_list = (RGE_Tile_List_Node*)calloc(this->list_size * 2, sizeof(RGE_Tile_List_Node));
        memcpy(new_list, this->list, this->list_size * sizeof(RGE_Tile_List_Node));
        free(this->list);
        this->list = new_list;
        this->list_size = this->list_size * 2;
    }

    this->list[this->num_active].col = col;
    this->list[this->num_active].row = row;
    this->num_active++;
    this->new_count++;
}

void RGE_Tile_List::del_list(void) {
    this->num_active = 0;
    this->new_count = 0;

    if (this->collapse_list != 0) {
        free(this->list);
        this->list_size = 8;
        this->list = (RGE_Tile_List_Node*)calloc(8, 8);
        this->collapse_list = 0;
    }
}

RGE_Tile_List::RGE_Tile_List(int max_tiles) {
    this->list = (RGE_Tile_List_Node*)calloc(max_tiles, 8);
    this->list_size = max_tiles;
    this->num_active = 0;
    this->new_count = 0;
    this->collapse_list = 0;
}

RGE_Tile_List::~RGE_Tile_List() {
    if (this->list) {
        free(this->list);
    }
}

void RGE_Tile_List::get_list_info(RGE_Tile_List_Node*& out1, int& out2) {
    out1 = this->list;
    out2 = this->num_active;
}

int RGE_Tile_List::get_new_count() {
    int c = this->new_count;
    this->new_count = 0;
    return c;
}
