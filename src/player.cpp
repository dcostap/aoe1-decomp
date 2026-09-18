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

RGE_Player::RGE_Player(int infile, RGE_Game_World* gworld,
                       unsigned char this_id)
    : computerPlayerValue(0), pathingAttemptCapValue(5),
      pathingDelayCapValue(10), tile_list(400), diam_tile_list(400) {
    int* pathing = &this->pathingAttemptCapValue;
    int pathing_cap = pathingCapValue;

    this->id = this_id;
    this->pathingAttemptCapValue = pathing_cap;
    this->world = gworld;
    this->reset_selected();

    this->doppleganger_creator =
        new RGE_Doppleganger_Creator(this, 100);

    this->relations = (unsigned char*)calloc(1, (int)this->world->player_num);
    rge_read(infile, this->relations, (int)this->world->player_num);
    rge_read(infile, this->unitDiplomacy, 36);

    if (save_game_version >= DAT_00570e90) {
        rge_read(infile, &this->allied_LOS_Enable, 4);
    } else {
        this->allied_LOS_Enable = 0;
    }

    rge_read(infile, &this->allied_victory, 1);

    short index;
    rge_read(infile, &index, 2);
    if (index > 0) {
        this->name = (char*)calloc((int)index, 1);
        rge_read(infile, this->name, (int)index);
    } else {
        this->name = 0;
    }

    rge_read(infile, &this->attribute_num, 2);
    if (this->attribute_num > 0) {
        this->attributes = (float*)calloc((int)this->attribute_num, 4);
        rge_read(infile, this->attributes, (int)this->attribute_num << 2);
    } else {
        this->attributes = 0;
    }

    rge_read(infile, &this->view_x, 4);
    rge_read(infile, &this->view_y, 4);
    rge_read(infile, &this->map_x, 2);
    rge_read(infile, &this->map_y, 2);
    rge_read(infile, &this->culture, 1);
    rge_read(infile, &this->master_player_id, 1);
    rge_read(infile, &this->game_status, 1);
    rge_read(infile, &this->resigned, 1);

    unsigned char table;
    rge_read(infile, &table, 1);
    this->set_color_table(table);

    rge_read(infile, pathing, 4);
    rge_read(infile, &this->pathingDelayCapValue, 4);

    this->checksum_created_this_update = 0;
    this->checksum = 0;
}

RGE_Player::RGE_Player(RGE_Game_World* gworld,
                       RGE_Master_Player* prototype,
                       unsigned char this_id, char* new_name,
                       unsigned char m_player_id,
                       unsigned char flag)
    : computerPlayerValue(0), pathingAttemptCapValue(5),
      pathingDelayCapValue(10), tile_list(400), diam_tile_list(400) {
    this->pathingAttemptCapValue = pathingCapValue;
    this->master_player_id = m_player_id;
    this->type = 0;
    this->world = gworld;
    this->id = this_id;
    this->reset_selected();

    this->name = 0;
    if (new_name != 0) {
        getstring(&this->name, new_name);
    }

    this->relations = (unsigned char*)calloc(1, (int)this->world->player_num);
    memset(this->unitDiplomacy, -1, sizeof(this->unitDiplomacy));
    for (short i = 0; i < this->world->player_num; ++i) {
        this->relations[i] = 1;
        if (i == this->id) {
            this->unitDiplomacy[i] = 1;
        } else if (i == 0) {
            this->unitDiplomacy[0] = 0;
        } else {
            this->unitDiplomacy[i] = 3;
        }
    }

    this->mutualExploredMask = 0;
    this->mutualVisibleMask = 0;
    this->nonMutualVisibleMask = 0;
    this->allied_LOS_Enable = 0;
    this->allied_victory = 0;

    this->master_object_num = prototype->master_object_num;
    if (this->master_object_num > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc((int)this->master_object_num, 4);
        for (short i = 0; i < this->master_object_num; ++i) {
            if (prototype->master_objects[i] != 0) {
                this->master_objects[i] =
                    prototype->master_objects[i]->make_new_master();
            }
        }
    }

    if (flag != 0) {
        this->objects = new RGE_Object_List;
        this->sleeping_objects = new RGE_Object_List;
        this->doppleganger_objects = new RGE_Object_List;
        this->new_victory();
        this->visible = new RGE_Visible_Map(gworld->map, this);
    } else {
        this->objects = 0;
        this->sleeping_objects = 0;
        this->doppleganger_objects = 0;
        this->victory_conditions = 0;
        this->visible = 0;
    }

    this->doppleganger_creator =
        new RGE_Doppleganger_Creator(this, 100);

    this->attribute_num = prototype->attribute_num;
    if (this->attribute_num > 0) {
        this->attributes = (float*)calloc((int)this->attribute_num, 4);
        memcpy(this->attributes, prototype->attributes, (int)this->attribute_num * 4);
    } else {
        this->attributes = 0;
    }
    this->culture = prototype->culture;

    this->set_view_loc((float)(this->world->map->map_width / 2), (float)(this->world->map->map_height / 2));
    this->set_map_loc((short)(this->world->map->map_width / 2), (short)(this->world->map->map_height / 2));

    this->game_status = 0;
    this->resigned = 0;
    this->color_table = 0;
    this->tribe_effect = (long)prototype->tribe_effect;
    if (flag != 0 && this->tribe_effect >= 0) {
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

void RGE_Player::set_game_status(unsigned char new_status) {
    RGE_Player* player = this;
    if (new_status == player->game_status) return;
    if (player->resigned && new_status != 2) return;
    player->game_status = new_status;
    if (new_status == 2 && !player->resigned) {
        rge_base_game->notification(6, player->id, 0, 0, 0);
    }
}

void RGE_Player::do_resign(int dropped) {
    unsigned char resigned = this->resigned;
    this->resigned = 1;
    this->set_game_status(2);
    if (!resigned) {
        rge_base_game->notification(5, this->id, dropped, 0, 0);
    }
}

unsigned char RGE_Player::get_resigned() {
    return this->resigned;
}

char* RGE_Player::aiStatus(int sNum) {
    return 0;
}

int RGE_Player::computerPlayer() const {
    return this->computerPlayerValue;
}

int RGE_Player::isEnemy(int playerNum) {
    if ((((playerNum != this->id) && (playerNum > 0)) && (playerNum < this->world->player_num)) && (this->relations[playerNum] == 3)) {
        return 1;
    }
    return 0;
}

int RGE_Player::isAlly(int playerNum) {
    if (playerNum == this->id) {
        return 1;
    }
    if ((((0 < playerNum) && (playerNum < this->world->player_num)) && (this->relations[playerNum] == 0))) {
        return 1;
    }
    return 0;
}

int RGE_Player::isNeutral(int playerNum) {
    if ((((playerNum != this->id) && (playerNum > 0)) && (playerNum < this->world->player_num)) && (this->relations[playerNum] == 1)) {
        return 1;
    }
    return 0;
}

int RGE_Player::isAllNeutral(void) {
    RGE_Player* player = this;
    for (int i = 1; i < player->world->player_num; i++) {
        if (i != player->id) {
            if (player->isNeutral(i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void RGE_Player::setDiplomaticStance(int playerNum, int rType) {
}

void RGE_Player::loadAIInformation(char* bL, char* cP, char* rS,
                                   int mood, int mapType) {
}

void RGE_Player::sendUnitAIOrder(int issuer, int recipient, int orderType,
                                 int target, int targetOwner, float targetX,
                                 float targetY, float targetZ, float range,
                                 int immediate, int inFront, int priority) {
    this->world->commands->command_ai_order(issuer, issuer, recipient, orderType, target, targetOwner,
                                            targetX, targetY, targetZ, range, immediate, inFront, priority);
}

void RGE_Player::processAIOrder(int issuer, int recipient, int orderType,
                                int target, int targetOwner, float targetX,
                                float targetY, float targetZ, float range,
                                int immediate, int inFront, int priority) {
    RGE_Static_Object* obj;
    UnitAIModule* ai;

    obj = this->world->object(recipient);
    if (obj == 0) {
        return;
    }

    ai = obj->unitAI();
    if (ai == 0) {
        return;
    }

    ai = obj->unitAI();
    ai->order(issuer, orderType, target, targetOwner, targetX, targetY, targetZ, range, immediate, inFront, priority);
}

void RGE_Player::sendGameOrder(RGE_Static_Object* unit,
                               RGE_Static_Object* target, float targetX,
                               float targetY) {
    RGE_Static_Object* units;

    units = unit;
    this->world->commands->command_order(&units, 1, target, targetX, targetY);
}

void RGE_Player::sendAddWaypointCommand(int recipient, XYZBYTEPoint* waypoint,
                                         int numWaypoints) {
    int player_id = (int)this->id;
    this->world->commands->command_add_waypoint(player_id, recipient, waypoint, numWaypoints);
}

void RGE_Player::processAddWaypointCommand(int recipient,
                                            XYZBYTEPoint* waypoint,
                                            int numWaypoints) {
    RGE_Static_Object* object;

    object = this->world->object(recipient);
    if ((object != 0) && (numWaypoints > 0)) {
        int remaining = numWaypoints;
        do {
            object->addUserDefinedWaypoint(waypoint, 1);
            waypoint = waypoint + 1;
            remaining = remaining - 1;
        } while (remaining != 0);
    }
}

void RGE_Player::sendPlayCommand(int recipient, int target, int playID) {
    int selectedUnits[25];
    int selectedCount;
    int* selectedUnit;
    RGE_Static_Object** source;

    this->command_destroy_group(recipient);
    if (this->world->playbook->play(playID) == 0) {
        this->sendUnitAIOrder((int)this->id, recipient, 0x2d7, -1, -1, -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
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
        this->command_create_group(recipient, selectedUnits, selectedCount, 2.0f);
        this->sendUnitAIOrder((int)this->id, recipient, 0x2d6, target, playID, -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
    }
}

void RGE_Player::sendPlayCommand(int recipient, int* groupUnits, int groupCount,
                                 int target, int playID) {
    this->command_destroy_group(recipient);
    AIPlay* play = this->world->playbook->play(playID);
    if (play == 0) {
        this->sendUnitAIOrder((int)this->id, recipient, 0x2d7, -1, -1, -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
        return;
    }
    if (groupCount != 0) {
        this->command_create_group(recipient, groupUnits, groupCount, 2.0f);
        this->sendUnitAIOrder((int)this->id, recipient, 0x2d6, target, playID, -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
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

int RGE_Player::availablePathingAttempts(int numWaitDelays) {
    if (pathingDelayCapValue != -1 && numWaitDelays > pathingDelayCapValue) {
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

void __cdecl RGE_Player::sendChatMessage(int playerID, int copySelf,
                                         char* textIn, ...) {
    char textOut[1025];

    // The cdecl varargs begin after textIn on the stack.
    vsprintf(textOut, textIn, (char*)(&textIn + 1));

    int i;

    if (strlen(textOut) != 0) {
        for (i = 1; i <= rge_base_game->numberPlayers(); ++i) {
            int current_player_id = rge_base_game->playerID(i);
            if (current_player_id == playerID) {
                this->world->commands->com_hand->SendChatMsg(this->id, i, textOut);
            }
        }

        if (copySelf == 1 && playerID != this->id) {
            for (i = 1; i <= rge_base_game->numberPlayers(); ++i) {
                int current_player_id = rge_base_game->playerID(i);
                if (current_player_id == this->id) {
                    this->world->commands->com_hand->SendChatMsg(this->id, i, textOut);
                }
            }
        }
    }
}

RGE_Static_Object* RGE_Player::make_scenario_obj(float world_x, float world_y,
                                                  float world_z, short master_id,
                                                  unsigned char state,
                                                  float new_angle) {
    RGE_Static_Object* obj = 0;
    RGE_Master_Static_Object* master = this->master_objects[master_id];
    if (master != 0) {
        obj = (RGE_Static_Object*)master->make_new_obj(this, world_x, world_y, world_z);
        if (state >= 7) {
            obj->destroy_obj();
        } else if (state > 2) {
            obj->die_die_die();
        } else {
            obj->new_angle(new_angle);
        }
    }
    return obj;
}

void RGE_Player::scenario_save(int outfile) {
}

void RGE_Player::scenario_load(int infile, long* player_id_hash, float version) {
    short name_length;
    unsigned char player_count;
    short count;
    int has_team;

    if (version <= 1.05) {
        int file_handle = infile;
        rge_read(infile, &name_length, 2);
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

        has_team = 0;
        if (rge_base_game->prog_mode != 7) {
            for (int player = 1; player < 9; player++) {
                if (rge_base_game->playerID(player) == this->id && (comm->GetPlayerHumanity(player) == 2 ||
                     comm->GetPlayerHumanity(player) == 4)) {
                    if (rge_base_game->playerTeam(player - 1) > 1) {
                        has_team = 1;
                    }
                    break;
                }
            }
        }

        if (version > 1.0) {
            rge_read(file_handle, &player_count, 1);
            if (has_team == 0) {
                this->allied_victory = player_count;
            }
        }

        short i = 0;
        this->allied_LOS_Enable = 0;
        if (this->attribute_num > 0) {
            rge_read(infile, this->attributes, 116);
        }

        rge_read(file_handle, &count, 2);
        if (count > 0) {
            do {
                unsigned char temp_byte;
                rge_read(file_handle, &temp_byte, 1);
                if (has_team == 0) {
                    long* player_id = &player_id_hash[i];
                    if (*player_id < this->world->player_num && *player_id >= 0) {
                        this->relations[*player_id] = temp_byte;
                        if (*player_id == 0) {
                            this->unitDiplomacy[0] = 0;
                        } else if (i == this->id) {
                            // The executable compares the entry index here.
                            this->unitDiplomacy[*player_id] = 1;
                        } else if (temp_byte == 0) {
                            this->unitDiplomacy[*player_id] = 2;
                        } else if (temp_byte == 1) {
                            this->unitDiplomacy[*player_id] = 3;
                        } else {
                            this->unitDiplomacy[*player_id] = 4;
                        }
                    }
                }
                ++i;
            } while (i < count);
        }

        if (version > 1.08) {
            rge_read(file_handle, this->unitDiplomacy, 36);
        }

        if (this->victory_conditions != 0) {
            delete this->victory_conditions;
        }

        this->load_victory(file_handle, player_id_hash, 0);
    }
}

void RGE_Player::scenario_postsave(int outfile) {
    short count = strlen(this->name) + 1;

    rge_write(outfile, &count, 2);
    rge_write(outfile, this->name, count);
    rge_write(outfile, &this->view_x, 4);
    rge_write(outfile, &this->view_y, 4);
    rge_write(outfile, &this->map_x, 2);
    rge_write(outfile, &this->map_y, 2);
    rge_write(outfile, &this->allied_victory, 1);
    rge_write(outfile, &this->world->player_num, 2);
    rge_write(outfile, this->relations, this->world->player_num);
    rge_write(outfile, this->unitDiplomacy, 36);
    this->victory_conditions->save(outfile);
}

void RGE_Player::scenario_postload(int infile, long* player_id_hash,
                                   float version) {
    int file_handle = infile;
    short name_length;
    short count;
    unsigned char player_count;
    int has_team;
    unsigned char temp_byte;

    rge_read(file_handle, &name_length, 2);
    if (name_length > 0) {
        char* name = (char*)calloc((int)name_length, 1);
        rge_read(file_handle, name, (int)name_length);
        if (this->name == 0) {
            this->name = name;
        } else {
            free(name);
        }
    }

    rge_read(file_handle, &this->view_x, 4);
    rge_read(file_handle, &this->view_y, 4);
    rge_read(file_handle, &this->map_x, 2);
    rge_read(file_handle, &this->map_y, 2);

    has_team = 0;
    if (rge_base_game->prog_mode != 7) {
        for (int player = 1; player < 9; ++player) {
            if (rge_base_game->playerID(player) == this->id && (comm->GetPlayerHumanity(player) == 2 ||
                 comm->GetPlayerHumanity(player) == 4)) {
                if (rge_base_game->playerTeam(player - 1) > 1) {
                    has_team = 1;
                }
                break;
            }
        }
    }

    if (version > 1.0) {
        rge_read(file_handle, &player_count, 1);
        if (has_team == 0) {
            this->allied_victory = player_count;
        }
    }

    this->allied_LOS_Enable = 0;
    if (version <= 1.06 && this->attribute_num > 0) {
        rge_read(file_handle, this->attributes, 116);
    }

    rge_read(file_handle, &count, 2);
    short i = 0;
    if (count > 0) {
        do {
            rge_read(file_handle, &temp_byte, 1);
            if (has_team == 0) {
                short player_id;
                if (player_id_hash != 0) {
                    player_id = (short)player_id_hash[i];
                } else {
                    player_id = i;
                }
                if (player_id < this->world->player_num && player_id >= 0) {
                    this->relations[player_id] = temp_byte;
                    if (player_id == 0) {
                        this->unitDiplomacy[0] = 0;
                    } else if (player_id == this->id) {
                        this->unitDiplomacy[player_id] = 1;
                    } else if (temp_byte == 0) {
                        this->unitDiplomacy[player_id] = 2;
                    } else if (temp_byte == 1) {
                        this->unitDiplomacy[player_id] = 3;
                    } else {
                        this->unitDiplomacy[player_id] = 4;
                    }
                }
            }
            ++i;
        } while (i < count);
    }

    if (version >= 1.08) {
        rge_read(file_handle, this->unitDiplomacy, 36);
    }

    RGE_Victory_Conditions* victory = this->victory_conditions;
    if (victory != 0) {
        delete victory;
    }

    if (version >= 1.09) {
        this->load_victory(file_handle, player_id_hash, 1);
    } else {
        this->load_victory(file_handle, player_id_hash, 0);
    }
}

void RGE_Player::load(int infile) {
    rge_read(infile, &this->master_object_num, 2);

    if (this->master_object_num > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc((int)this->master_object_num, 4);
        rge_read(infile, this->master_objects, (int)this->master_object_num * 4);

        for (short i = 0; i < this->master_object_num; ++i) {
            if (this->master_objects[i] != 0) {
                unsigned char obj_type;
                rge_read(infile, &obj_type, 1);
                this->load_master_object(infile, i, obj_type, this->world->sprites, this->world->sounds);
            }
        }
    } else {
        this->master_objects = 0;
    }

    this->visible = new RGE_Visible_Map(infile, this->world);
    this->VR_List = new Visible_Resource_Manager(infile, this);
    this->objects = new RGE_Object_List;
    this->objects->load_list(infile, this->world);
    this->sleeping_objects = new RGE_Object_List;
    this->doppleganger_objects = new RGE_Object_List;
    this->sleeping_objects->load_list(infile, this->world);

    if (!(save_game_version < DAT_00570ec0)) {
        this->doppleganger_objects->load_list(infile, this->world);
    }
}

void RGE_Player::load_master_object(int infile, short index, unsigned char type,
                                     RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Static_Object* object;

    switch (type) {
    case 10:
        object = new RGE_Master_Static_Object(infile, sprites, sounds, 1);
        break;
    case 20:
        object = new RGE_Master_Animated_Object(infile, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 30:
        object = new RGE_Master_Moving_Object(infile, sprites, sounds, 1);
        break;
    case 60:
        object = new RGE_Master_Missile_Object(infile, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 40:
        object = new RGE_Master_Action_Object(infile, sprites, sounds, 1);
        break;
    case 50:
        object = new RGE_Master_Combat_Object(infile, sprites, sounds, 1);
        this->master_objects[index] = object;
        return;
    case 25:
        object = new RGE_Master_Doppleganger_Object(infile, sprites, sounds, 1);
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

unsigned char RGE_Player::get_checksums(long& new_checksum,
                                        long& new_position_checksum,
                                        long& new_action_checksum) {
    if (!this->checksum_created_this_update) {
        this->create_checksum();
    }
    new_checksum = this->checksum;
    new_position_checksum = this->position_checksum;
    new_action_checksum = this->action_checksum;
    return 1;
}

long RGE_Player::create_checksum() {
    long num1 = 0;
    long num2 = 0;
    long num3 = 0;
    long num4;
    float temp_position_checksum = 0.0f;

    this->checksum_created_this_update = 1;
    this->action_checksum = 0;
    num4 = this->id + this->sleeping_objects->number_of_objects +
        this->doppleganger_objects->number_of_objects;

    for (int i = 0; i < this->attribute_num; ++i) {
        num1 += (long)this->attributes[i];
    }

    RGE_Object_Node* list = this->objects->list;
    while (list != 0) {
        num2 += list->node->object_state +
            (long)list->node->attribute_amount_held +
            list->node->master_obj->id;
        num2 += list->node->get_waypoint_checksum();
        ++num3;
        temp_position_checksum += list->node->world_x;
        temp_position_checksum += list->node->world_y;
        temp_position_checksum += list->node->world_z;
        this->action_checksum += list->node->get_action_checksum();
        list = list->next;
    }

    this->checksum = (((num4 * 0x100 + num3) * 0x100 + num2) * 0x100) +
        num1;
    this->position_checksum = (long)temp_position_checksum;
    return this->checksum;
}

void RGE_Player::new_attribute_num(short attribute, float amount) {
    if (attribute < 0) {
        return;
    }
    if (attribute >= this->attribute_num) {
        return;
    }
    this->attributes[(int)attribute] = amount;
}

void RGE_Player::add_attribute_num(short attribute, float amount,
                                   unsigned char earned) {
    if (attribute < 0) return;
    if (attribute >= this->attribute_num) return;
    this->attributes[(int)attribute] = amount + this->attributes[(int)attribute];
}

void RGE_Player::make_available(short obj_category, unsigned char on_off_flag) {
    RGE_Master_Static_Object* master_object;

    master_object = this->master_objects[obj_category];
    if (master_object != 0) {
        master_object->make_available(on_off_flag);
    }
}

void RGE_Player::update() {
    if (MouseSystem) {
        MouseSystem->Poll();
    }

    this->currentUpdatePathingAttemptsValue = 0;
    this->objects->update();

    this->update_selected();

    if (this->victory_conditions->update() == 1) {
        this->set_game_status(2);
    }

    this->checksum_created_this_update = 0;

    if (this->VR_List) {
        this->VR_List->Process_New_Tiles(&this->tile_list);
    }
}

void RGE_Player::update_dopplegangers(void) {
    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }
    this->doppleganger_objects->update();
    this->doppleganger_creator->perform_doppleganger_checks();
}

void RGE_Player::save(int outfile) {
    int name_length;
    unsigned char table;

    color_log(0x32, 0x32, 3);
    rge_write(outfile, &this->type, 1);
    rge_write(outfile, this->relations, (int)this->world->player_num);
    rge_write(outfile, this->unitDiplomacy, 36);
    rge_write(outfile, &this->allied_LOS_Enable, 4);
    rge_write(outfile, &this->allied_victory, 1);

    name_length = strlen(this->name) + 1;
    rge_write(outfile, &name_length, 2);
    if ((short)name_length > 0) {
        rge_write(outfile, this->name, (short)name_length);
    }

    rge_write(outfile, &this->attribute_num, 2);
    short index = this->attribute_num;
    if (index > 0) {
        rge_write(outfile, this->attributes, (int)index << 2);
    }

    rge_write(outfile, &this->view_x, 4);
    rge_write(outfile, &this->view_y, 4);
    rge_write(outfile, &this->map_x, 2);
    rge_write(outfile, &this->map_y, 2);
    rge_write(outfile, &this->culture, 1);
    rge_write(outfile, &this->master_player_id, 1);
    rge_write(outfile, &this->game_status, 1);
    rge_write(outfile, &this->resigned, 1);

    if (this->color_table != 0) {
        table = (unsigned char)this->color_table->id;
    } else {
        table = 0;
    }
    rge_write(outfile, &table, 1);
    rge_write(outfile, &this->pathingAttemptCapValue, 4);
    rge_write(outfile, &this->pathingDelayCapValue, 4);
    color_log(0x32, 0x5F, 3);
}

void RGE_Player::save2(int outfile) {
    int save_file;
    short* master_object_count;

    color_log('L', 'L', 4);
    save_file = outfile;
    master_object_count = &this->master_object_num;
    rge_write(save_file, master_object_count, 2);

    if (0 < *master_object_count) {
        int i = 0;
        while (i < *master_object_count) {
            outfile = (int)this->master_objects[i];
            if (outfile != 0) {
                outfile = 1;
            }
            rge_write(save_file, &outfile, 4);
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

void RGE_Player::save_info(int outfile) {
    this->victory_conditions->save(outfile);
}

void RGE_Player::set_map_loc(short x, short y) {
    this->map_x = x;
    this->map_y = y;
}

void RGE_Player::set_view_loc(float x, float y) {
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

void RGE_Player::set_color_table(unsigned char new_table) {
    this->color_table = this->world->color_tables[new_table];
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

unsigned char RGE_Player::check_ally_group(long& count) {
    long last_count = count;
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
    if (last_count >= 0 && count != last_count)
        ok = 0;

    return ok;
}

unsigned char RGE_Player::check_victory(void) {
    long count = -1;

    if (this->game_status != 2 && this->victory_conditions->victory_achieved()) {
        unsigned char found = 0;
        if (this->allied_victory) {
            for (int i = 1; i < this->world->player_num; i++) {
                if ((i == this->id || this->relations[i] == 0) && this->world->players[i]->check_ally_group(count) == 0) {
                    found = 1;
                    break;
                }
            }
        }
        if (this->allied_victory) {
            if (found) return this->game_status;
            for (int i = 1; i < this->world->player_num; i++) {
                if (this->relations[i] == 0 && this->world->players[i]->check_victory_conditions() == 0) {
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

void RGE_Player::modify_tobj(short obj_id, short group,
                             float amount, unsigned char flag) {
    if (obj_id >= 0) {
        short index = obj_id;
        if (master_objects[index] != 0) {
            if (objects != 0) {
                RGE_Object_Node* node = objects->list;
                while (node != 0) {
                    if (node->node->master_obj == master_objects[index]) {
                        node->node->modify(amount, flag);
                    }
                    node = node->next;
                }
            }
            master_objects[index]->modify(amount, flag);
        }
    } else if (group >= 0) {
        short index = 0;
        if (master_object_num > 0) {
            do {
                if (master_objects[index] != 0 && master_objects[index]->object_group == group) {
                    if (objects != 0) {
                        RGE_Object_Node* node = objects->list;
                        while (node != 0) {
                            if (node->node->master_obj == master_objects[index]) {
                                node->node->modify(amount, flag);
                            }
                            node = node->next;
                        }
                    }
                    master_objects[index]->modify(amount, flag);
                }
                ++index;
            } while (index < master_object_num);
        }
    }
}

void RGE_Player::modify_tobj_delta(short obj_id, short group,
                                   float amount, unsigned char flag) {
    if (obj_id >= 0) {
        short index = obj_id;
        if (master_objects[index] != 0) {
            if (objects != 0) {
                RGE_Object_Node* node = objects->list;
                while (node != 0) {
                    if (node->node->master_obj == master_objects[index]) {
                        node->node->modify_delta(amount, flag);
                    }
                    node = node->next;
                }
            }
            master_objects[index]->modify_delta(amount, flag);
        }
    } else if (group >= 0) {
        short index = 0;
        if (master_object_num > 0) {
            do {
                if (master_objects[index] != 0 && master_objects[index]->object_group == group) {
                    if (objects != 0) {
                        RGE_Object_Node* node = objects->list;
                        while (node != 0) {
                            if (node->node->master_obj == master_objects[index]) {
                                node->node->modify_delta(amount, flag);
                            }
                            node = node->next;
                        }
                    }
                    master_objects[index]->modify_delta(amount, flag);
                }
                ++index;
            } while (index < master_object_num);
        }
    }
}

void RGE_Player::modify_tobj_percent(short obj_id, short group,
                                     float amount, unsigned char flag) {
    if (obj_id >= 0) {
        short index = obj_id;
        if (master_objects[index] != 0) {
            if (objects != 0) {
                RGE_Object_Node* node = objects->list;
                while (node != 0) {
                    if (node->node->master_obj == master_objects[index]) {
                        node->node->modify_percent(amount, flag);
                    }
                    node = node->next;
                }
            }
            master_objects[index]->modify_percent(amount, flag);
        }
    } else if (group >= 0) {
        short index = 0;
        if (master_object_num > 0) {
            do {
                if (master_objects[index] != 0 && master_objects[index]->object_group == group) {
                    if (objects != 0) {
                        RGE_Object_Node* node = objects->list;
                        while (node != 0) {
                            if (node->node->master_obj == master_objects[index]) {
                                node->node->modify_percent(amount, flag);
                            }
                            node = node->next;
                        }
                    }
                    master_objects[index]->modify_percent(amount, flag);
                }
                ++index;
            } while (index < master_object_num);
        }
    }
}

void RGE_Player::copy_obj(short dest, short source) {
    if (this->master_objects[dest] == 0) return;
    if (this->master_objects[source] == 0) return;
    if (this->objects != 0) {
        RGE_Object_Node* node = this->objects->list;
        while (node != 0) {
            RGE_Static_Object* obj = node->node;
            if (obj->master_obj == this->master_objects[dest]) {
                obj->copy_obj(this->master_objects[source]);
            }
            node = node->next;
        }
    }
    this->master_objects[dest]->copy_obj(this->master_objects[source]);
}

void RGE_Player::set_allied_victory(unsigned char flag) {
    this->allied_victory = flag;
}

unsigned char RGE_Player::get_allied_victory() {
    return this->allied_victory;
}

unsigned char RGE_Player::relation(long player_id) {
    return relations[player_id];
}

void RGE_Player::set_relation(long player_id, unsigned char relation) {
    this->relations[player_id] = relation;

    if (player_id == 0) {
        this->unitDiplomacy[0] = 0;
    } else if (player_id == this->id) {
        this->unitDiplomacy[player_id] = 1;
    } else if (relation == 0) {
        this->unitDiplomacy[player_id] = 2;
    } else if (relation == 1) {
        this->unitDiplomacy[player_id] = 3;
    } else {
        this->unitDiplomacy[player_id] = 4;
    }

    RGE_Object_Node* node = this->objects->list;
    while (node != 0) {
        node->node->notify_of_relation(player_id, relation);
        node = node->next;
    }
}

RGE_Static_Object* RGE_Player::make_new_object(long obj_id, float x, float y,
                                               float z, int build_all_the_way) {
    if ((obj_id >= 0) && (this->master_objects[obj_id] != 0)) {
        return this->master_objects[obj_id]->make_new_obj(this, x, y, z);
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
    memset(this->sel_list, 0, 100);
    memset(this->groups_used, 0, 127);
}

int RGE_Player::select_object(RGE_Static_Object* obj) {
    RGE_Player* player = this;
    RGE_Static_Object* selected = obj;
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

int RGE_Player::select_one_object(RGE_Static_Object* obj, int play_sound) {
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

void RGE_Player::unselect_one_object(RGE_Static_Object* obj) {
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
            if (current == obj) {
                this->unselect_one_object(slot);
                return;
            }
            count = count + 1;
        }
        slot = slot + 1;
    }
}

void RGE_Player::unselect_one_object(short index) {
    int object_index = index;
    RGE_Static_Object* obj = sel_list[object_index];
    if (obj != 0) {
        obj->selected = 0;
        int count = sel_count;
        int last = count - 1;
        if (object_index >= last) {
            sel_list[object_index] = 0;
        } else {
            sel_list[object_index] = sel_list[count - 1];
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

int RGE_Player::group_objects(int id) {
    unsigned char group;
    if (!sel_count) {
        return 0;
    }

    if (id == -1) {
        short i = 0x0B;
        for (; i < 0x7F; ++i) {
            if (groups_used[i]) {
                continue;
            }
            group = (unsigned char)i;
            groups_used[i] = 1;
            break;
        }

        if (i == 0x7F) {
            for (int clear_i = 1; clear_i < 0x7F; ++clear_i) {
                groups_used[clear_i] = 0;
            }

            RGE_Object_Node* node = objects->list;
            while (node) {
                group = node->node->selected_group;
                if (group && !groups_used[group]) {
                    groups_used[group] = 1;
                }
                node = node->next;
            }

            i = 1;
            for (; i < 0x7F; ++i) {
                if (groups_used[i]) {
                    continue;
                }
                group = (unsigned char)i;
                groups_used[i] = 1;
                break;
            }

            if (i == 0x7F) {
                return 0;
            }
        }
    } else {
        group = (unsigned char)id;
        RGE_Object_Node* node = objects->list;
        while (node) {
            if (node->node->selected_group == (unsigned char)id) {
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
            object->selected_group = group;
        }
        ++i;
    }

    return 1;
}

int RGE_Player::select_group(int id) {
    int first = 1;
    RGE_Object_Node* node = this->objects->list;
    while (node != 0) {
        RGE_Static_Object* obj = node->node;
        if (obj->selected_group == (unsigned char)id) {
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

int RGE_Player::own_selected() {
    short index;
    short count;

    index = 0;
    count = 0;
    while (index < 0x19) {
        if (count >= this->sel_count)
            return 0;
        if (this->sel_list[index] != 0) {
            count = count + 1;
            if (this->sel_list[index]->owner == this)
                return 1;
        }
        index = index + 1;
    }

    return 0;
}

int RGE_Player::is_category_selected(short object_category) {
    short index;
    short count;

    index = 0;
    count = 0;
    while (index < 0x19) {
        if (count >= this->sel_count)
            return 0;
        if (this->sel_list[index] != 0) {
            count = count + 1;
            if (this->sel_list[index]->master_obj->id == object_category)
                return 1;
        }
        index = index + 1;
    }

    return 0;
}

int RGE_Player::is_group_selected(short object_group) {
    short index;
    short count;

    index = 0;
    count = 0;
    while (index < 0x19) {
        if (count >= this->sel_count)
            return 0;
        if (this->sel_list[index] != 0) {
            count = count + 1;
            if (this->sel_list[index]->master_obj->object_group == object_group)
                return 1;
        }
        index = index + 1;
    }

    return 0;
}

unsigned char RGE_Player::unit_level_selected() {
    unsigned char level = 0;
    short index = 0, count = 0;
    for (; index < 25; index++) {
        if (count >= sel_count) return level;
        RGE_Static_Object* object = sel_list[index];
        if (object != 0) {
            if (count != 0 && object->master_obj->unit_level != level) return 0;
            count++;
            level = object->master_obj->unit_level;
        }
    }
    return level;
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
    RGE_Static_Object*** list_in, short* list_num_in,
    short min_select_level, short object_group, short object_id,
    short unit_level) {
    RGE_Player* player = this;
    long j;
    RGE_Static_Object** list;
    short count = 0;
    RGE_Static_Object* object;
    RGE_Master_Static_Object* master;
    Selection_Locals locals;

    j = 0;
    *list_in = 0;
    *list_num_in = 0;
    if (player->sel_count == 0) {
        return 0;
    }

    locals.list = (RGE_Static_Object**)calloc(4, (unsigned int)player->sel_count);
    if (min_select_level == -1) {
        min_select_level = 4;
    }

    locals.list_count = 0;
    list = player->sel_list;
    while (j < 0x19) {
        if (locals.list_count >= player->sel_count) {
            break;
        }

        object = *list;
        if (object != 0) {
            if (object->object_state == 2 && object->owner == player) {
                master = object->master_obj;
                if (master->select_level >= min_select_level || player->id == 0) {
                    if (object_group == -1 || master->object_group == (unsigned char)object_group) {
                        if (object_id == -1 || master->id == (unsigned char)object_id) {
                            if (unit_level == -1 || master->unit_level == (unsigned char)unit_level) {
                                if (master->master_type >= 0x28 && master->master_type != 0x5A) {
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
        ++list;
    }

    if (count == 0) {
        free(locals.list);
        return 0;
    }

    *list_in = locals.list;
    *list_num_in = count;
    return 1;
}

void RGE_Player::update_selected() {
    RGE_Player* player = this;
    for (short index = 0, selected = 0; index < 25; index++) {
        if (selected >= player->sel_count) return;
        RGE_Static_Object* obj = player->sel_list[index];
        if (obj != 0) {
            if (obj->object_state < 7 && obj->inside_obj == 0)
                selected++;
            else
                player->unselect_one_object(index);
        }
    }
}

void RGE_Player::select_area(short col1, short row1, short col2, short row2) {
    this->selected_start_col = col1;
    this->selected_start_row = row1;
    this->selected_end_col = col2;
    this->selected_end_row = row2;
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

int RGE_Player::get_mouse_pointer_action_vars(int Obj_id, int& newFacet,
                                              int& text_id) {
    newFacet = 0;
    text_id = 0;
    return 0;
}

unsigned char RGE_Player::command_make_move(RGE_Static_Object* obj, float x,
                                            float y) {
    RGE_Static_Object** list;
    short list_num;
    if (get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
        list[0]->play_move_sound();
        this->world->commands->command_move(list, list_num, obj, x, y);
        free(list);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_make_work(RGE_Static_Object* obj, float x,
                                             float y) {
    RGE_Static_Object** list;
    short list_num;
    int i;

    if (this->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
        RGE_Master_Static_Object* master = list[0]->get_command_master(obj, x, y, 0);
        if (master != 0) {
            master->play_command_sound();
        }
        this->world->commands->command_work(list, list_num, obj, x, y);
        if (obj != 0) {
            i = 0;
            if (list_num > 0) {
                do {
                    this->sendUnitAIOrder((int)this->id, list[i]->id, 0x2bd, obj->id, (int)obj->owner->id,
                                          obj->world_x, obj->world_y, 1.0f, obj->master_obj->los * 0.5f, 0, 0, 100);
                    ++i;
                } while (i < list_num);
            }
        }
        free(list);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_make_do(RGE_Static_Object* obj, float x,
                                           float y) {
    RGE_Static_Object** list;
    short list_num;
    if (get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
        RGE_Master_Static_Object* master = list[0]->get_command_master(obj, x, y, 0);
        if (master != 0) {
            master->play_command_sound();
        }
        this->world->commands->command_order(list, list_num, obj, x, y);
        free(list);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_stop(void) {
    RGE_Static_Object** list;
    short list_num;

    if (this->get_selected_objects_to_command(&list, &list_num, 3, -1, -1, -1)) {
        (*list)->play_command_sound();
        this->world->commands->command_stop(list, list_num);
        free(list);
        return 1;
    }

    return 0;
}

unsigned char RGE_Player::command_place_object(short obj_id, float x, float y,
                                               float z) {
    if (obj_id != -1 && this->master_objects[obj_id] != 0) {
        this->world->commands->command_create(obj_id, this->id, x, y, z);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_add_attribute(int attr_id, float attr_amount) {
    if ((attr_id != -1) && (attr_amount != 0.0f)) {
        this->world->commands->command_add_attribute((int)this->id, attr_id, attr_amount);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_give_attribute(int to_player_id, int attr_id,
                                                 float attr_amount) {
    if (attr_id == -1) return 0;
    if (attr_amount == DAT_00570ec4) return 0;
    if (attr_amount <= this->attributes[attr_id]) {
        this->world->commands->command_give_attribute(this->id, to_player_id, attr_id, attr_amount);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_formation(int formationID) {
    RGE_Static_Object** list;

    if (formationID >= 0 && formationID <= 5) {
        int formation_id = formationID;
        short listNum;
        if (this->get_selected_objects_to_command(&list, &listNum, -1, -1, -1, -1)) {
            (*list)->play_command_sound();
            this->world->commands->command_formation(list, listNum, formation_id);
            free(list);
            return 1;
        }
    }

    return 0;
}

unsigned char RGE_Player::command_stand_ground() {
    RGE_Static_Object** list;
    short listNum;

    if (get_selected_objects_to_command(&list, &listNum, -1, -1, -1, -1)) {
        list[0]->play_command_sound();
        this->world->commands->command_group_ai_order(this->id, this->id, list, listNum, 0x2d5, -1, -1, -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 100);
        free(list);
        return 1;
    }

    return 0;
}

unsigned char RGE_Player::command_create_group(int commander, int* groupList,
                                               int groupLength, float range) {
    int player_id = (int)this->id;
    this->world->commands->command_create_group(player_id, commander, groupList, groupLength, range);
    return 1;
}

unsigned char RGE_Player::command_add_to_group(int commander, int unitID,
                                               float range) {
    int player_id = (int)this->id;
    this->world->commands->command_add_to_group(player_id, commander, unitID, range);
    return 1;
}

unsigned char RGE_Player::command_remove_from_group(int commander, int unitID) {
    int player_id = (int)this->id;
    this->world->commands->command_remove_from_group(player_id, commander, unitID);
    return 1;
}

unsigned char RGE_Player::command_destroy_group(int unitID) {
    this->world->commands->command_destroy_group((int)this->id, unitID);
    return 1;
}

unsigned char RGE_Player::command_resign(int comm_player_id, int dropped) {
    if (!this->game_status) {
        this->world->commands->command_resign((int)this->id, comm_player_id, dropped);
        return 1;
    }
    return 0;
}

unsigned char RGE_Player::command_add_waypoint(float x, float y, float z) {
    RGE_Static_Object** list;
    short list_num;

    if (this->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
        list[0]->play_command_sound();
        this->world->commands->command_group_waypoint(list, list_num, (int)x, (int)y);
        free(list);
        return 1;
    }
    return 0;
}

RGE_Object_Node* RGE_Player::addObject(RGE_Static_Object* obj, int sleep_flag,
                                       int dopple_flag) {
    RGE_Object_Node* node;

    if (sleep_flag != 0) {
        node = this->sleeping_objects->add_node(obj);
    } else if (dopple_flag != 0) {
        node = this->doppleganger_objects->add_node(obj);
    } else {
        node = this->objects->add_node(obj);
    }

    this->world->addObject(obj);
    return node;
}

void RGE_Player::removeObject(RGE_Static_Object* obj, int sleep_flag,
                              int dopple_flag, RGE_Object_Node* node) {
    if (sleep_flag != 0) {
        this->sleeping_objects->remove_node(obj, node);
    } else if (dopple_flag != 0) {
        this->doppleganger_objects->remove_node(obj, node);
    } else {
        this->objects->remove_node(obj, node);
    }

    this->world->removeObject(obj->id);
}

void __cdecl RGE_Player::logMessage(char* in, ...) {
}

void RGE_Player::notify(int caller, int recipient, int mType, long p1, long p2,
                        long p3) {
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

void RGE_Player::load_victory(int infile, long* player_id_hash,
                              unsigned char version_control) {
    RGE_Victory_Conditions* victory =
        new RGE_Victory_Conditions(this, infile, player_id_hash, version_control);
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

RGE_Tile_List::RGE_Tile_List(int Initial_Size) {
    this->list = (RGE_Tile_List_Node*)calloc(Initial_Size, 8);
    this->list_size = Initial_Size;
    this->num_active = 0;
    this->new_count = 0;
    this->collapse_list = 0;
}

RGE_Tile_List::~RGE_Tile_List() {
    if (this->list) {
        free(this->list);
    }
}

void RGE_Tile_List::get_list_info(RGE_Tile_List_Node*& theList,
                                  int& list_size) {
    theList = this->list;
    list_size = this->num_active;
}

int RGE_Tile_List::get_new_count() {
    int c = this->new_count;
    this->new_count = 0;
    return c;
}
