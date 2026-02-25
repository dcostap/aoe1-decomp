#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Player.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/RGE_Command.h"
#include "../include/RGE_Visible_Map.h"
#include "../include/Visible_Resource_Manager.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Doppleganger_Creator.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TMousePointer.h"
#include "../include/TCommunications_Handler.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"

#include <stdlib.h>
#include <string.h>
#include <cstdint>
#include <new>
#include <stdarg.h>
#include <stdio.h>

static long rge_ftol(float v) {
    // MSVC x86 __ftol equivalent (x87 FISTP using current rounding mode).
    long result;
    __asm {
        fld v
        fistp result
    }
    return result;
}

static RGE_Object_List* rge_player_get_list(RGE_Player* self, int sleeping, int dopple) {
    if (self == nullptr) {
        return nullptr;
    }
    if (sleeping != 0) {
        return self->sleeping_objects;
    }
    if (dopple != 0) {
        return self->doppleganger_objects;
    }
    return self->objects;
}

static void rge_player_set_list(RGE_Player* self, int sleeping, int dopple, RGE_Object_List* list) {
    if (self == nullptr) {
        return;
    }
    if (sleeping != 0) {
        self->sleeping_objects = list;
        return;
    }
    if (dopple != 0) {
        self->doppleganger_objects = list;
        return;
    }
    self->objects = list;
}

static RGE_Object_List* rge_player_ensure_list(RGE_Player* self, int sleeping, int dopple) {
    RGE_Object_List* list = rge_player_get_list(self, sleeping, dopple);
    if (list != nullptr) {
        return list;
    }

    list = new (std::nothrow) RGE_Object_List();
    if (list == nullptr) {
        return nullptr;
    }
    rge_player_set_list(self, sleeping, dopple, list);
    return list;
}

static RGE_Object_Node* rge_player_add_node(RGE_Object_List* list, RGE_Static_Object* obj) {
    if (list == nullptr) {
        return nullptr;
    }

    RGE_Object_Node* node = (RGE_Object_Node*)calloc(1, sizeof(RGE_Object_Node));
    if (node == nullptr) {
        return nullptr;
    }

    node->node = obj;
    node->prev = nullptr;
    node->next = list->list;
    if (list->list != nullptr) {
        list->list->prev = node;
    }
    list->list = node;
    list->number_of_objects = (short)(list->number_of_objects + 1);
    return node;
}

static void rge_player_remove_node(RGE_Object_List* list, RGE_Object_Node* node) {
    if (list == nullptr || node == nullptr) {
        return;
    }
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        list->list = node->next;
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }
    free(node);
    list->number_of_objects = (short)(list->number_of_objects - 1);
}

// --- RGE_Player constructors ---
RGE_Player::RGE_Player() {
    this->computerPlayerValue = 0;
    this->pathingAttemptCapValue = 0;
    this->pathingDelayCapValue = 0;
    this->currentUpdatePathingAttemptsValue = 0;
    this->checksum = 0;
    this->position_checksum = 0;
    this->action_checksum = 0;
    this->checksum_created_this_update = 0;
    this->master_object_num = 0;
    this->master_objects = nullptr;
    this->objects = nullptr;
    this->sleeping_objects = nullptr;
    this->doppleganger_objects = nullptr;
    this->victory_conditions = nullptr;
    this->visible = nullptr;
    this->world = nullptr;
    this->doppleganger_creator = nullptr;
    this->name = nullptr;
    this->type = 0;
    this->id = 0;
    this->attribute_num = 0;
    this->attributes = nullptr;
    this->culture = 0;
    this->game_status = 0;
    this->resigned = 0;
    this->relations = nullptr;
    memset(this->unitDiplomacy, 0, sizeof(this->unitDiplomacy));
    memset(this->mutualAlly, 0, sizeof(this->mutualAlly));
    this->mutualExploredMask = 0;
    this->mutualVisibleMask = 0;
    this->nonMutualVisibleMask = 0;
    memset(this->RemoveVisibleBits, 0, sizeof(this->RemoveVisibleBits));
    this->allied_LOS_Enable = 0;
    this->allied_victory = 0;
    this->master_player_id = 0;
    this->color_table = nullptr;
    this->tribe_effect = 0;
    this->VR_List = nullptr;
    this->view_x = 0.0f;
    this->view_y = 0.0f;
    this->map_x = 0;
    this->map_y = 0;
    this->selected_start_col = 0;
    this->selected_start_row = 0;
    this->selected_end_col = 0;
    this->selected_end_row = 0;
    this->replacement_terrain = -1;
    this->replacement_overlay = -1;
    this->replacement_overlay_shape = 0;
    this->selected_obj = nullptr;
    memset(this->sel_list, 0, sizeof(this->sel_list));
    this->sel_object_properties = 0;
    this->sel_count = 0;
    memset(this->groups_used, 0, sizeof(this->groups_used));
}

RGE_Player::RGE_Player(RGE_Game_World* world, RGE_Master_Player* master, uchar player_id, char* name_str, uchar civ, uchar is_computer, uchar is_active, char* ai1, char* ai2, char* ai3)
    : RGE_Player() {
    // Source of truth: player.cpp.decomp @ 0x0046E770
    this->pathingAttemptCapValue = 5;
    this->pathingDelayCapValue = 10;
    this->master_player_id = civ;
    this->type = 0; // base type always 0; TRIBE_Player sets computerPlayerValue
    this->world = world;
    this->id = (short)player_id;

    // Source of truth: player.cpp.decomp (constructor paths allocate doppleganger_creator early).
    // Required for New Game: TRIBE_Building_Object ctor unconditionally calls doppleganger_creator->add_doppleganger_check.
    if (this->doppleganger_creator == nullptr) {
        this->doppleganger_creator = new (std::nothrow) RGE_Doppleganger_Creator(this, 100);
    }

    if (name_str) {
        this->name = _strdup(name_str);
    }

    // Allocate relations array (one byte per player)
    if (world && world->player_num > 0) {
        this->relations = (unsigned char*)calloc(1, world->player_num);
        // Initialize diplomacy: -1 for all, then set per player
        for (int i = 0; i < 9; i++) {
            this->unitDiplomacy[i] = -1;
        }
        for (short i = 0; i < world->player_num; i++) {
            this->relations[i] = 1; // neutral by default
            if (i == this->id) {
                this->unitDiplomacy[i] = 1; // self = ally
            } else if (i == 0) {
                this->unitDiplomacy[0] = 0; // gaia = gaia
            } else {
                this->unitDiplomacy[i] = 3; // others = enemy
            }
        }
    }

    // Copy master objects from RGE_Master_Player
    if (master) {
        this->master_object_num = master->master_object_num;
        if (this->master_object_num > 0) {
            this->master_objects = (RGE_Master_Static_Object**)calloc(this->master_object_num, sizeof(RGE_Master_Static_Object*));
            for (short i = 0; i < this->master_object_num; ++i) {
                if (master->master_objects != nullptr && master->master_objects[i] != nullptr) {
                    this->master_objects[i] = master->master_objects[i]->make_new_master();
                }
            }
        }
        // Copy attributes from master player
        this->attribute_num = master->attribute_num;
        if (this->attribute_num > 0) {
            this->attributes = (float*)calloc(this->attribute_num, sizeof(float));
            if (master->attributes) {
                memcpy(this->attributes, master->attributes, this->attribute_num * sizeof(float));
            }
        }
        this->culture = master->culture;
        this->tribe_effect = (long)master->tribe_effect;
    }

    // Set initial view to center of map
    if (world && world->map) {
        this->view_x = (float)(world->map->map_width / 2);
        this->view_y = (float)(world->map->map_height / 2);
        this->map_x = (short)(world->map->map_width / 2);
        this->map_y = (short)(world->map->map_height / 2);
    }

    this->game_status = 0;
    this->resigned = 0;
    this->checksum = 0;
    this->checksum_created_this_update = 0;

    if (is_active != 0) {
        // Source of truth: player.cpp.decomp @ 0x0046E770 (active-player allocations)
        if (this->objects == nullptr) {
            this->objects = new (std::nothrow) RGE_Object_List();
        }
        if (this->sleeping_objects == nullptr) {
            this->sleeping_objects = new (std::nothrow) RGE_Object_List();
        }
        if (this->doppleganger_objects == nullptr) {
            this->doppleganger_objects = new (std::nothrow) RGE_Object_List();
        }
        this->new_victory();
        if (this->visible == nullptr && world != nullptr) {
            this->visible = new (std::nothrow) RGE_Visible_Map(world->map, this);
        }
    }
}

RGE_Player::RGE_Player(int param_1, RGE_Game_World* world, uchar player_id)
    : RGE_Player() {
    // Source of truth: player.cpp.decomp @ 0x0046E4B0
    this->pathingAttemptCapValue = 5;
    this->pathingDelayCapValue = 10;
    this->id = (short)player_id;
    this->world = world;

    // Source of truth: player.cpp.decomp @ 0x0046E4B0
    if (this->doppleganger_creator == nullptr) {
        this->doppleganger_creator = new (std::nothrow) RGE_Doppleganger_Creator(this, 100);
    }

    // Allocate and read relations
    this->relations = (unsigned char*)calloc(1, (int)world->player_num);
    rge_read(param_1, this->relations, (int)world->player_num);
    rge_read(param_1, this->unitDiplomacy, 0x24);

    // Version-gated allied LOS
    if (save_game_version < 4.01f) {
        this->allied_LOS_Enable = 0;
    } else {
        rge_read(param_1, &this->allied_LOS_Enable, 4);
    }
    rge_read(param_1, &this->allied_victory, 1);

    // Read name
    short name_len = 0;
    rge_read(param_1, &name_len, 2);
    if (name_len < 1) {
        this->name = nullptr;
    } else {
        this->name = (char*)calloc((int)name_len, 1);
        rge_read(param_1, this->name, (int)name_len);
    }

    // Read attributes
    rge_read(param_1, &this->attribute_num, 2);
    if (this->attribute_num < 1) {
        this->attributes = nullptr;
    } else {
        this->attributes = (float*)calloc((int)this->attribute_num, 4);
        rge_read(param_1, this->attributes, (int)this->attribute_num * 4);
    }

    // Read view/map position
    rge_read(param_1, &this->view_x, 4);
    rge_read(param_1, &this->view_y, 4);
    rge_read(param_1, &this->map_x, 2);
    rge_read(param_1, &this->map_y, 2);

    // Read player info
    rge_read(param_1, &this->culture, 1);
    rge_read(param_1, &this->master_player_id, 1);
    rge_read(param_1, &this->game_status, 1);
    rge_read(param_1, &this->resigned, 1);

    // Read color table ID (ignored for now)
    uchar color_id = 0;
    rge_read(param_1, &color_id, 1);
    this->set_color_table(color_id);

    // Read pathing caps
    rge_read(param_1, &this->pathingAttemptCapValue, 4);
    rge_read(param_1, &this->pathingDelayCapValue, 4);

    this->checksum_created_this_update = 0;
    this->checksum = 0;
}

RGE_Player::~RGE_Player() {
    // Source of truth: player.cpp.decomp @ 0x0046EB00
    if (this->objects != nullptr) {
        delete this->objects;
        this->objects = nullptr;
    }
    if (this->sleeping_objects != nullptr) {
        delete this->sleeping_objects;
        this->sleeping_objects = nullptr;
    }
    if (this->doppleganger_objects != nullptr) {
        delete this->doppleganger_objects;
        this->doppleganger_objects = nullptr;
    }
    if (this->victory_conditions) {
        delete this->victory_conditions;
        this->victory_conditions = nullptr;
    }

    // Free relations
    if (this->relations) {
        free(this->relations);
        this->relations = nullptr;
    }

    // Free master objects array (each entry via virtual destructor)
    if (this->master_object_num > 0) {
        for (short i = 0; i < this->master_object_num; i++) {
            if (this->master_objects[i]) {
                delete this->master_objects[i];
                this->master_objects[i] = nullptr;
            }
        }
        free(this->master_objects);
        this->master_objects = nullptr;
        this->master_object_num = 0;
    }

    if (this->visible != nullptr) {
        delete this->visible;
        this->visible = nullptr;
    }
    if (this->doppleganger_creator != nullptr) {
        delete this->doppleganger_creator;
        this->doppleganger_creator = nullptr;
    }
    if (this->VR_List != nullptr) {
        delete this->VR_List;
        this->VR_List = nullptr;
    }

    // Free name
    if (this->name) {
        free(this->name);
        this->name = nullptr;
    }

    // Free attributes
    if (this->attribute_num > 0) {
        free(this->attributes);
        this->attributes = nullptr;
        this->attribute_num = 0;
    }
}
void RGE_Player::set_game_status(uchar param_1) {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x0046ECE0 (audited vs player.cpp.asm).
    if ((param_1 != this->game_status) && (this->resigned == 0 || param_1 == 2)) {
        uchar was_resigned = this->resigned;
        this->game_status = param_1;
        if (param_1 == 2 && was_resigned == 0) {
            rge_base_game->notification(6, (long)this->id, 0, 0, 0);
        }
    }
}
void RGE_Player::do_resign(int param_1) {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x0046ED50 (audited vs player.cpp.asm).
    uchar old_resigned = this->resigned;
    this->resigned = 1;
    this->set_game_status(2);
    if (old_resigned == 0) {
        rge_base_game->notification(5, (long)this->id, param_1, 0, 0);
    }
}
void RGE_Player::changeToHumanPlayer() {}
void RGE_Player::changeToComputerPlayer() {}
char* RGE_Player::aiStatus(int param_1) { return nullptr; }
int RGE_Player::isEnemy(int param_1) {
    // Source of truth: player.cpp.decomp @ 0x0046EDC0
    if (param_1 != this->id && param_1 > 0 && param_1 < this->world->player_num
        && this->relations && this->relations[param_1] == 3) {
        return 1;
    }
    return 0;
}
int RGE_Player::isAlly(int param_1) {
    // Source of truth: player.cpp.decomp @ 0x0046EE00
    if (param_1 == this->id) return 1;
    if (param_1 > 0 && param_1 < this->world->player_num
        && this->relations && this->relations[param_1] == 0) {
        return 1;
    }
    return 0;
}
int RGE_Player::isNeutral(int param_1) {
    // Source of truth: player.cpp.decomp @ 0x0046EE40
    if (param_1 != this->id && param_1 > 0 && param_1 < this->world->player_num
        && this->relations && this->relations[param_1] == 1) {
        return 1;
    }
    return 0;
}
int RGE_Player::isAllNeutral() {
    // Source of truth: player.cpp.decomp @ 0x0046EE80
    if (!this->world || this->world->player_num < 2) return 1;
    for (int i = 1; i < this->world->player_num; i++) {
        if (i != this->id && !this->isNeutral(i)) {
            return 0;
        }
    }
    return 1;
}
void RGE_Player::setDiplomaticStance(int param_1, int param_2) {}
void RGE_Player::loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5) {}
void RGE_Player::sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) {}
void RGE_Player::processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) {}
void RGE_Player::kickAI(int param_1) {}
int RGE_Player::strategicNumber(int param_1) { return -1; }
void RGE_Player::sendGameOrder(RGE_Static_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4) {}
void RGE_Player::sendAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) {}
void RGE_Player::processAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) {}
void RGE_Player::sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5) {}
void RGE_Player::sendPlayCommand(int param_1, int param_2, int param_3) {}
int RGE_Player::sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5) { return 0; }
int RGE_Player::objectCostByType(int param_1) { return 0; }
void RGE_Player::trackUnitGather(int param_1, int param_2, int param_3) {}
RGE_Static_Object* RGE_Player::make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6) {
    // Source of truth: player.cpp.decomp @ 0x0046F3A0
    if (param_4 < 0 || this->master_objects == nullptr || param_4 >= this->master_object_num ||
        this->master_objects[param_4] == nullptr) {
        return nullptr;
    }

    RGE_Static_Object* obj = this->master_objects[param_4]->make_new_obj(this, param_1, param_2, param_3);
    if (obj == nullptr) {
        return nullptr;
    }

    if (param_5 > 6) {
        obj->destroy_obj();
    } else if (param_5 > 2) {
        obj->die_die_die();
    }
    obj->new_angle(param_6);
    return obj;
}
void RGE_Player::scenario_save(int param_1) {}
void RGE_Player::scenario_load(int param_1, long* param_2, float param_3) {
    // Source of truth: player.cpp.decomp @ 0x0046F420
    if (param_3 > 1.05f) {
        return;
    }

    short name_len = 0;
    rge_read(param_1, &name_len, 2);
    if (name_len > 0) {
        char* temp_name = (char*)calloc((int)name_len, 1);
        if (temp_name != nullptr) {
            rge_read(param_1, temp_name, (int)name_len);
            if (this->name == nullptr) {
                this->name = temp_name;
            } else {
                free(temp_name);
            }
        }
    }

    rge_read(param_1, &this->view_x, 4);
    rge_read(param_1, &this->view_y, 4);
    rge_read(param_1, &this->map_x, 2);
    rge_read(param_1, &this->map_y, 2);

    if (param_3 > 1.0f) {
        uchar allied_victory = 0;
        rge_read(param_1, &allied_victory, 1);
        this->allied_victory = allied_victory;
    }

    this->allied_LOS_Enable = 0;
    if (this->attribute_num > 0) {
        unsigned char attr_buf[0x74];
        rge_read(param_1, attr_buf, 0x74);
        int copy_bytes = this->attribute_num * 4;
        if (copy_bytes > 0x74) {
            copy_bytes = 0x74;
        }
        if (copy_bytes > 0 && this->attributes != nullptr) {
            memcpy(this->attributes, attr_buf, (size_t)copy_bytes);
        }
    }

    short relation_count = 0;
    rge_read(param_1, &relation_count, 2);
    for (short i = 0; i < relation_count; ++i) {
        uchar relation_value = 0;
        rge_read(param_1, &relation_value, 1);
        int rel_idx = (param_2 != nullptr) ? (int)param_2[i] : (int)i;
        if (this->world != nullptr && rel_idx >= 0 && rel_idx < this->world->player_num && this->relations != nullptr) {
            this->relations[rel_idx] = relation_value;
            if (rel_idx == 0) {
                this->unitDiplomacy[0] = 0;
            } else if (rel_idx == this->id) {
                this->unitDiplomacy[rel_idx] = 1;
            } else if (relation_value == 0) {
                this->unitDiplomacy[rel_idx] = 2;
            } else if (relation_value == 1) {
                this->unitDiplomacy[rel_idx] = 3;
            } else {
                this->unitDiplomacy[rel_idx] = 4;
            }
        }
    }

    if (param_3 > 1.08f) {
        rge_read(param_1, this->unitDiplomacy, 0x24);
    }

    if (this->victory_conditions != nullptr) {
        delete this->victory_conditions;
        this->victory_conditions = nullptr;
    }
    this->load_victory(param_1, param_2, 0);
}
void RGE_Player::scenario_postsave(int param_1) {
    // Source of truth: player.cpp.decomp @ 0x0046F6B0
    // Write name length + name
    short name_len = 0;
    if (this->name) {
        name_len = (short)(strlen(this->name) + 1);
    }
    rge_write(param_1, &name_len, 2);
    if (name_len > 0) {
        rge_write(param_1, this->name, (int)name_len);
    }
    // Write view/map position
    rge_write(param_1, &this->view_x, 4);
    rge_write(param_1, &this->view_y, 4);
    rge_write(param_1, &this->map_x, 2);
    rge_write(param_1, &this->map_y, 2);
    // Write allied victory flag
    rge_write(param_1, &this->allied_victory, 1);
    // Write relations
    rge_write(param_1, &this->world->player_num, 2);
    rge_write(param_1, this->relations, (int)this->world->player_num);
    rge_write(param_1, this->unitDiplomacy, 0x24);
    if (this->victory_conditions) {
        this->victory_conditions->save(param_1);
    }
}
void RGE_Player::scenario_postload(int param_1, long* param_2, float param_3) {
    // Source of truth: player.cpp.decomp @ 0x0046F7A0
    short name_len = 0;
    rge_read(param_1, &name_len, 2);
    if (name_len > 0) {
        char* temp_name = (char*)calloc((int)name_len, 1);
        if (temp_name != nullptr) {
            rge_read(param_1, temp_name, (int)name_len);
            if (this->name == nullptr) {
                this->name = temp_name;
            } else {
                free(temp_name);
            }
        }
    }

    rge_read(param_1, &this->view_x, 4);
    rge_read(param_1, &this->view_y, 4);
    rge_read(param_1, &this->map_x, 2);
    rge_read(param_1, &this->map_y, 2);

    if (param_3 > 1.0f) {
        uchar allied_victory = 0;
        rge_read(param_1, &allied_victory, 1);
        this->allied_victory = allied_victory;
    }

    this->allied_LOS_Enable = 0;
    if (param_3 <= 1.06f && this->attribute_num > 0) {
        unsigned char attr_buf[0x74];
        rge_read(param_1, attr_buf, 0x74);
        int copy_bytes = this->attribute_num * 4;
        if (copy_bytes > 0x74) {
            copy_bytes = 0x74;
        }
        if (copy_bytes > 0 && this->attributes != nullptr) {
            memcpy(this->attributes, attr_buf, (size_t)copy_bytes);
        }
    }

    short relation_count = 0;
    rge_read(param_1, &relation_count, 2);
    for (short i = 0; i < relation_count; ++i) {
        uchar relation_value = 0;
        rge_read(param_1, &relation_value, 1);
        int rel_idx = (param_2 != nullptr) ? (int)param_2[i] : (int)i;
        if (this->world != nullptr && rel_idx >= 0 && rel_idx < this->world->player_num && this->relations != nullptr) {
            this->relations[rel_idx] = relation_value;
            if (rel_idx == 0) {
                this->unitDiplomacy[0] = 0;
            } else if (rel_idx == this->id) {
                this->unitDiplomacy[rel_idx] = 1;
            } else if (relation_value == 0) {
                this->unitDiplomacy[rel_idx] = 2;
            } else if (relation_value == 1) {
                this->unitDiplomacy[rel_idx] = 3;
            } else {
                this->unitDiplomacy[rel_idx] = 4;
            }
        }
    }

    if (param_3 >= 1.08f) {
        rge_read(param_1, this->unitDiplomacy, 0x24);
    }

    if (this->victory_conditions != nullptr) {
        delete this->victory_conditions;
        this->victory_conditions = nullptr;
    }
    this->load_victory(param_1, param_2, (param_3 >= 1.09f) ? 1 : 0);
}
void RGE_Player::load(int param_1) {}

long RGE_Player::get_checksum() {
    // Fully verified. Source of truth: player.cpp.asm @ 0x0046FF40
    if (this->checksum_created_this_update == 0) {
        this->create_checksum();
    }
    return this->checksum;
}

uchar RGE_Player::get_checksums(long& checksum, long& position_checksum, long& action_checksum) {
    // Fully verified. Source of truth: player.cpp.asm @ 0x0046FF60
    if (this->checksum_created_this_update == 0) {
        this->create_checksum();
    }
    checksum = this->checksum;
    position_checksum = this->position_checksum;
    action_checksum = this->action_checksum;
    return 1;
}

long RGE_Player::create_checksum() {
    // Fully verified. Source of truth: player.cpp.asm @ 0x0046FF90
    // Note: local variable names mirror the decomp's structure, but this function is ASM-audited.

    const int id_sum = (int)this->id + (int)this->sleeping_objects->number_of_objects + (int)this->doppleganger_objects->number_of_objects;

    this->checksum_created_this_update = 1;
    this->action_checksum = 0;

    uint obj_checksum = 0;
    uint num1 = 0;

    uint temp_position_checksum = 0; // sum of attribute floats converted via __ftol
    float local_10 = 0.0f;           // sum of object xyz positions

    int num2 = (int)this->attribute_num;
    float* attrs = this->attributes;
    if (num2 > 0) {
        do {
            temp_position_checksum += (uint)rge_ftol(*attrs);
            attrs += 1;
            num2 -= 1;
        } while (num2 != 0);
    }

    for (RGE_Object_Node* node = this->objects->list; node != nullptr; node = node->next) {
        RGE_Static_Object* obj = node->node;

        const uint state = (uint)obj->object_state;
        const int held_amount = (int)rge_ftol(obj->attribute_amount_held);
        const int master_id = (int)(short)obj->master_obj->id;
        const int waypoint_checksum = (int)obj->get_waypoint_checksum();

        obj_checksum = obj_checksum + state + (uint)held_amount + (uint)master_id + (uint)waypoint_checksum;
        num1 += 1;

        local_10 = (local_10 + obj->world_x + obj->world_y) + obj->world_z;
        this->action_checksum = (long)((uint)this->action_checksum + (uint)obj->get_action_checksum());
    }

    uint checksum = (uint)id_sum;
    checksum = (checksum << 8) + num1;
    checksum = (checksum << 8) + obj_checksum;
    checksum = (checksum << 8) + (uint)temp_position_checksum;

    this->checksum = (long)checksum;
    this->position_checksum = rge_ftol(local_10);
    return this->checksum;
}

void RGE_Player::new_attribute_num(short param_1, float param_2) {
    // Source of truth: player.cpp.decomp @ 0x004700B0
    if (param_1 >= 0 && param_1 < this->attribute_num) {
        this->attributes[param_1] = param_2;
    }
}
void RGE_Player::add_attribute_num(short param_1, float param_2, uchar param_3) {
    // Source of truth: player.cpp.decomp @ 0x004700D0
    if (param_1 >= 0 && param_1 < this->attribute_num) {
        this->attributes[param_1] = this->attributes[param_1] + param_2;
    }
}
void RGE_Player::update() {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00470120
    CUSTOM_DEBUG_LOG_FMT("RGE_Player::update this=%p id=%d objects=%p dopple=%p", this, (int)this->id, this->objects, this->doppleganger_objects);
    if (MouseSystem != nullptr) {
        MouseSystem->Poll();
    }
    this->currentUpdatePathingAttemptsValue = 0;
    if (this->objects != nullptr) {
        this->objects->update();
    }
    this->update_selected();
    if (this->victory_conditions != nullptr && this->victory_conditions->update() == '\x01') {
        this->set_game_status(2);
    }
    this->checksum_created_this_update = 0;
    if (this->VR_List != nullptr) {
        this->VR_List->Process_New_Tiles(&this->tile_list);
    }
}
void RGE_Player::update_dopplegangers() {
    // Source of truth: player.cpp.decomp @ 0x00470180
    if (MouseSystem != nullptr) {
        MouseSystem->Poll();
    }
    if (this->doppleganger_objects != nullptr) {
        this->doppleganger_objects->update();
    }
    if (this->doppleganger_creator != nullptr) {
        this->doppleganger_creator->perform_doppleganger_checks();
    }
}
void RGE_Player::save(int param_1) {
    // Source of truth: player.cpp.decomp @ 0x004701B0
    rge_write(param_1, &this->type, 1);
    rge_write(param_1, this->relations, (int)this->world->player_num);
    rge_write(param_1, this->unitDiplomacy, 0x24);
    rge_write(param_1, &this->allied_LOS_Enable, 4);
    rge_write(param_1, &this->allied_victory, 1);
    // Write name length + name
    short name_len = 0;
    if (this->name) {
        name_len = (short)(strlen(this->name) + 1);
    }
    rge_write(param_1, &name_len, 2);
    if (name_len > 0) {
        rge_write(param_1, this->name, (int)name_len);
    }
    // Attributes
    rge_write(param_1, &this->attribute_num, 2);
    if (this->attribute_num > 0) {
        rge_write(param_1, this->attributes, (int)this->attribute_num * 4);
    }
    // View/map position
    rge_write(param_1, &this->view_x, 4);
    rge_write(param_1, &this->view_y, 4);
    rge_write(param_1, &this->map_x, 2);
    rge_write(param_1, &this->map_y, 2);
    // Player info
    rge_write(param_1, &this->culture, 1);
    rge_write(param_1, &this->master_player_id, 1);
    rge_write(param_1, &this->game_status, 1);
    rge_write(param_1, &this->resigned, 1);
    // Color table ID
    uchar color_id = 0;
    if (this->color_table) {
        color_id = (uchar)this->color_table->id;
    }
    rge_write(param_1, &color_id, 1);
    // Pathing caps
    rge_write(param_1, &this->pathingAttemptCapValue, 4);
    rge_write(param_1, &this->pathingDelayCapValue, 4);
}
void RGE_Player::save2(int param_1) {}
void RGE_Player::save_info(int param_1) {}
void RGE_Player::random_start() {}
RGE_Static_Object* RGE_Player::make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5) {
    (void)param_5;
    if (param_1 < 0 || this->master_objects == nullptr || param_1 >= this->master_object_num) {
        return nullptr;
    }

    RGE_Master_Static_Object* master = this->master_objects[param_1];
    if (master == nullptr) {
        return nullptr;
    }

    return master->make_new_obj(this, param_2, param_3, param_4);
}
void RGE_Player::analyize_selected_objects() {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00471520
    return;
}
int RGE_Player::get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3) {
    // Source of truth: player.cpp.decomp @ 0x00471530
    *param_2 = 0;
    *param_3 = 0;
    return 0;
}
uchar RGE_Player::command_make_move(RGE_Static_Object* param_1, float param_2, float param_3) {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00471550
    RGE_Static_Object** list = nullptr;
    short list_num = 0;
    uchar can_command = this->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1);
    if (can_command != 0) {
        list[0]->play_move_sound();
        this->world->commands->command_move(list, list_num, param_1, param_2, param_3);
        free(list);
        return 1;
    }
    return 0;
}

uchar RGE_Player::command_make_work(RGE_Static_Object* param_1, float param_2, float param_3) {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x004715D0
    RGE_Static_Object** list = nullptr;
    short list_num = 0;
    uchar can_command = this->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1);
    if (can_command != 0) {
        RGE_Master_Static_Object* command_master = list[0]->get_command_master(param_1, param_2, param_3, 0.0f);
        if (command_master != nullptr) {
            command_master->play_command_sound();
        }

        this->world->commands->command_work(list, list_num, param_1, param_2, param_3);

        if ((param_1 != nullptr) && (list_num > 0)) {
            int i = 0;
            do {
                this->sendUnitAIOrder(
                    (int)this->id,
                    (int)list[i]->id,
                    0x2BD,
                    (int)param_1->id,
                    (int)param_1->owner->id,
                    param_1->world_x,
                    param_1->world_y,
                    1.0f,
                    param_1->master_obj->los * 0.5f,
                    0,
                    0,
                    100);
                i = i + 1;
            } while (i < list_num);
        }

        free(list);
        return 1;
    }
    return 0;
}

uchar RGE_Player::command_make_do(RGE_Static_Object* param_1, float param_2, float param_3) {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x004716D0
    RGE_Static_Object** list = nullptr;
    short list_num = 0;
    uchar can_command = this->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1);
    if (can_command != 0) {
        RGE_Master_Static_Object* command_master = list[0]->get_command_master(param_1, param_2, param_3, 0.0f);
        if (command_master != nullptr) {
            command_master->play_command_sound();
        }

        this->world->commands->command_order(list, list_num, param_1, param_2, param_3);
        free(list);
        return 1;
    }
    return 0;
}
uchar RGE_Player::command_stop() { return 1; }
uchar RGE_Player::command_place_object(short param_1, float param_2, float param_3, float param_4) {
    // Source of truth: player.cpp.decomp @ 0x004717D0
    if (param_1 == -1 || this->master_objects == nullptr) {
        return 0;
    }
    int obj_idx = (int)param_1;
    if (obj_idx < 0 || obj_idx >= this->master_object_num) {
        return 0;
    }
    if (this->master_objects[obj_idx] == nullptr) {
        return 0;
    }
    if (this->world == nullptr || this->world->commands == nullptr) {
        return 0;
    }

    this->world->commands->command_create(param_1, this->id, param_2, param_3, param_4);
    return 1;
}
uchar RGE_Player::command_add_attribute(int param_1, float param_2) {
    // Source of truth: player.cpp.decomp @ 0x00471820
    if (param_1 == -1 || param_2 == 0.0f) {
        return 0;
    }
    if (this->world == nullptr || this->world->commands == nullptr) {
        return 0;
    }

    this->world->commands->command_add_attribute((int)this->id, param_1, param_2);
    return 1;
}
uchar RGE_Player::command_give_attribute(int param_1, int param_2, float param_3) {
    // Source of truth: player.cpp.decomp @ 0x00471860
    if (param_2 == -1 || param_3 == 0.0f) {
        return 0;
    }
    if (this->world == nullptr || this->world->commands == nullptr || this->attributes == nullptr) {
        return 0;
    }
    if (param_2 < 0 || param_2 >= this->attribute_num) {
        return 0;
    }
    if (param_3 > this->attributes[param_2]) {
        return 0;
    }

    this->world->commands->command_give_attribute((int)this->id, param_1, param_2, param_3);
    return 1;
}
uchar RGE_Player::command_formation(int param_1) { return 1; }
uchar RGE_Player::command_stand_ground() { return 1; }
uchar RGE_Player::command_create_group(int param_1, int* param_2, int param_3, float param_4) { return 1; }
uchar RGE_Player::command_add_to_group(int param_1, int param_2, float param_3) { return 1; }
uchar RGE_Player::command_remove_from_group(int param_1, int param_2) { return 1; }
uchar RGE_Player::command_destroy_group(int param_1) { return 1; }
uchar RGE_Player::command_resign(int param_1, int param_2) { return 1; }
uchar RGE_Player::command_add_waypoint(float param_1, float param_2, float param_3) { return 1; }
RGE_Object_Node* RGE_Player::addObject(RGE_Static_Object* param_1, int param_2, int param_3) {
    RGE_Object_List* list = rge_player_ensure_list(this, param_2, param_3);
    if (list == nullptr) {
        return nullptr;
    }

    RGE_Object_Node* node = rge_player_add_node(list, param_1);
    if (node != nullptr && this->world != nullptr) {
        this->world->addObject(param_1);
    }
    return node;
}

void RGE_Player::removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4) {
    RGE_Object_List* list = rge_player_get_list(this, param_2, param_3);
    if (list == nullptr) {
        return;
    }

    RGE_Object_Node* node = param_4;
    if (node == nullptr) {
        node = list->list;
        while (node != nullptr && node->node != param_1) {
            node = node->next;
        }
        if (node == nullptr) {
            return;
        }
    }

    rge_player_remove_node(list, node);
    if (this->world != nullptr && param_1 != nullptr) {
        this->world->removeObject((int)param_1->id);
    }
}
void RGE_Player::logMessage(char* param_1) {}
void RGE_Player::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {}
void RGE_Player::logStatus(FILE* param_1, int param_2) {}
void RGE_Player::load_victory(int param_1, long* param_2, uchar param_3) {
    this->victory_conditions = new RGE_Victory_Conditions(this, param_1, param_2, param_3);
}
void RGE_Player::new_victory() {
    this->victory_conditions = new RGE_Victory_Conditions(this);
}

void RGE_Player::reset_selected() {
    // Source of truth: player.cpp.decomp @ 0x00470CB0
    this->selected_start_col = -1;
    this->selected_start_row = -1;
    this->selected_end_col = -1;
    this->selected_end_row = -1;
    this->replacement_terrain = -1;
    this->replacement_overlay = -1;
    this->replacement_overlay_shape = -1;
    this->sel_count = 0;
    this->selected_obj = nullptr;
    for (int i = 0; i < 25; i++) {
        this->sel_list[i] = nullptr;
    }
    memset(this->groups_used, 0, sizeof(this->groups_used));
}

void RGE_Player::unselect_one_object(RGE_Static_Object* param_1) {
    // Source of truth: player.cpp.decomp @ 0x00470E80
    if (this->sel_count > 0) {
        short sVar1 = 0;
        short sVar2 = 0;
        while (sVar2 < this->sel_count) {
            if (this->sel_list[sVar1] != nullptr) {
                if (this->sel_list[sVar1] == param_1) {
                    unselect_one_object(sVar1);
                    return;
                }
                sVar2++;
            }
            sVar1++;
            if (sVar1 > 0x18) {
                return;
            }
        }
    }
}

void RGE_Player::unselect_one_object(short param_1) {
    // Source of truth: player.cpp.decomp @ 0x00470ED0
    int idx = (int)param_1;
    RGE_Static_Object* obj = this->sel_list[idx];
    if (obj != nullptr) {
        obj->selected = 0;
        if (idx < this->sel_count - 1) {
            this->sel_list[idx] = this->sel_list[this->sel_count - 1];
            this->sel_list[this->sel_count - 1] = nullptr;
        } else {
            this->sel_list[idx] = nullptr;
        }
        this->sel_count--;
        if (this->selected_obj == obj) {
            this->selected_obj = nullptr;
            if (this->sel_count > 0) {
                short s = 0;
                while (this->sel_list[s] == nullptr) {
                    s++;
                    if (s > 0x18) {
                        return;
                    }
                }
                this->selected_obj = this->sel_list[s];
            }
        }
    }
}

void RGE_Player::select_one_object(RGE_Static_Object* param_1) {
    // Source of truth: player.cpp.decomp @ 0x00470D80 (simplified - no sound)
    short sVar1 = this->sel_count;
    if (sVar1 < 0x19) {
        short sVar3 = sVar1;
        if (this->sel_list[sVar1] != nullptr) {
            short sVar2 = 0;
            sVar3 = -1;
            if (sVar1 > 0) {
                do {
                    sVar3 = sVar2;
                    if (this->sel_list[sVar2] == nullptr) break;
                    sVar2++;
                    sVar3 = -1;
                } while (sVar2 < sVar1);
            }
        }
        if (sVar3 != -1) {
            this->sel_list[sVar3] = param_1;
            this->sel_count++;
            this->selected_obj = param_1;
            param_1->selected = 1;
        }
    }
}

int RGE_Player::select_one_object(RGE_Static_Object* param_1, int param_2) {
    // Partially verified. Source of truth: player.cpp.decomp calls select_one_object(obj,0) and checks success.
    (void)param_2;
    short before = this->sel_count;
    this->select_one_object(param_1);
    return (this->sel_count != before);
}

void RGE_Player::select_area(long param_1, long param_2, long param_3, long param_4) {
    // Source of truth: player.cpp.decomp @ 0x00471480
    this->selected_start_col = (short)param_1;
    this->selected_start_row = (short)param_2;
    this->selected_end_col = (short)param_3;
    this->selected_end_row = (short)param_4;
}

void RGE_Player::unselect_area() {
    // Source of truth: player.cpp.decomp @ 0x004714C0
    this->selected_start_col = -1;
    this->selected_start_row = -1;
    this->selected_end_col = -1;
    this->selected_end_row = -1;
}

void RGE_Player::unselect_object() {
    // Source of truth: player.cpp.decomp @ 0x00470E30
    if (this->sel_count > 0) {
        short sVar1 = 0;
        this->selected_obj = nullptr;
        short sVar2 = 0;
        do {
            if (this->sel_count <= sVar2) break;
            if (this->sel_list[sVar1] != nullptr) {
                this->sel_list[sVar1]->selected = 0;
                sVar2++;
                this->sel_list[sVar1] = nullptr;
            }
            sVar1++;
        } while (sVar1 < 0x19);
        this->sel_count = 0;
    }
}

void RGE_Player::update_selected() {
    // Source of truth: player.cpp.decomp @ 0x00471430
    short sVar3 = 0;
    short sVar2 = 0;
    do {
        if (this->sel_count <= sVar2) {
            return;
        }
        RGE_Static_Object* obj = this->sel_list[sVar3];
        if (obj != nullptr) {
            if (obj->object_state < 7 && obj->inside_obj == nullptr) {
                sVar2++;
            } else {
                unselect_one_object(sVar3);
            }
        }
        sVar3++;
    } while (sVar3 < 0x19);
}

int RGE_Player::select_object(RGE_Static_Object* param_1) {
    // Source of truth: player.cpp.decomp @ 0x00470D20 (audited vs player.cpp.asm).
    if (select_one_object(param_1, 1) == 0) {
        return 0;
    }

    uchar selected_group = param_1->selected_group;
    if (selected_group > 10 && this->objects != nullptr) {
        RGE_Object_Node* node = this->objects->list;
        while (node != nullptr) {
            RGE_Static_Object* obj = node->node;
            if (obj != param_1 && obj->selected_group == selected_group) {
                if (select_one_object(obj, 0) == 0) {
                    break;
                }
            }
            node = node->next;
        }
    }

    this->selected_obj = param_1;
    return 1;
}

unsigned char RGE_Player::get_select_level() {
    // Source of truth: player.cpp.decomp @ 0x00471290
    unsigned char best = 0xFF;
    short idx = 0;
    short found = 0;
    do {
        if (this->sel_count <= found) {
            break;
        }
        if (this->sel_list[idx] != nullptr) {
            unsigned char level = this->sel_list[idx]->master_obj->select_level;
            if (level < best) {
                best = level;
            }
            found = (short)(found + 1);
        }
        idx = (short)(idx + 1);
    } while (idx < 0x19);

    return (unsigned char)(((best == 0xFF) - 1U) & best);
}

unsigned char RGE_Player::get_selected_objects_to_command(
    RGE_Static_Object*** list_out,
    short* list_num_out,
    short min_select_level,
    short object_group,
    short object_id,
    short unit_level) {
    // Source of truth: player.cpp.decomp @ 0x004712F0
    int idx = 0;
    *list_out = nullptr;
    short list_num = 0;
    *list_num_out = 0;

    if (this->sel_count == 0) {
        return 0;
    }

    RGE_Static_Object** list = (RGE_Static_Object**)calloc(4, (int)this->sel_count);
    if (list == nullptr) {
        return 0;
    }

    if (min_select_level == -1) {
        min_select_level = 4;
    }

    short processed = 0;
    for (short i = 0; i < 0x19; ++i) {
        if (this->sel_count <= processed) {
            break;
        }

        RGE_Static_Object* obj = this->sel_list[i];
        if (obj != nullptr) {
            processed = (short)(processed + 1);

            if (obj->object_state == 2 && obj->owner == this) {
                RGE_Master_Static_Object* master = obj->master_obj;
                if ((min_select_level <= (short)(unsigned short)master->select_level || this->id == 0) &&
                    (object_group == -1 || master->object_group == (object_group & 0xFF)) &&
                    (object_id == -1 || master->id == (object_id & 0xFF)) &&
                    (unit_level == -1 || master->unit_level == (unsigned char)unit_level) &&
                    (0x27 < master->master_type) && (master->master_type != 0x5A)) {
                    list[idx++] = obj;
                    list_num = (short)(list_num + 1);
                }
            }
        }
    }

    if (list_num == 0) {
        free(list);
        return 0;
    }

    *list_out = list;
    *list_num_out = list_num;
    return 1;
}

// --- Non-virtual methods ---
void RGE_Player::set_relation(long param_1, uchar param_2) {
    // Source of truth: player.cpp.decomp @ 0x00470BE0 (audited vs player.cpp.asm).
    this->relations[param_1] = param_2;
    if (param_1 == 0) {
        this->unitDiplomacy[0] = 0; // gaia
    } else if (param_1 == this->id) {
        this->unitDiplomacy[param_1] = 1; // self = ally
    } else if (param_2 == 0) {
        this->unitDiplomacy[param_1] = 2; // ally
    } else if (param_2 == 1) {
        this->unitDiplomacy[param_1] = 3; // neutral
    } else {
        this->unitDiplomacy[param_1] = 4; // enemy
    }

    if (this->objects != nullptr) {
        for (RGE_Object_Node* node = this->objects->list; node != nullptr; node = node->next) {
            if (node->node != nullptr) {
                node->node->notify_of_relation(param_1, param_2);
            }
        }
    }
}

void RGE_Player::set_view_loc(float x, float y) {
    // Source of truth: player.cpp.decomp @ 0x004704C0
    this->view_x = x;
    this->view_y = y;
    // Clamp to map bounds
    if (this->world && this->world->map) {
        if (x >= 0.0f) {
            float max_x = (float)(this->world->map->map_width - 1);
            if (x > max_x) this->view_x = max_x;
        } else {
            this->view_x = 0.0f;
        }
        if (y >= 0.0f) {
            float max_y = (float)(this->world->map->map_height - 1);
            if (y > max_y) this->view_y = max_y;
        } else {
            this->view_y = 0.0f;
        }
    }
}

void RGE_Player::set_map_loc(short x, short y) {
    this->map_x = x;
    this->map_y = y;
}

void RGE_Player::set_map_visible() {
    // Source of truth: player.cpp.decomp @ 0x00471BF0
    if (this->visible == nullptr) {
        this->remake_visible_map();
    }
    if (this->visible == nullptr || this->visible->visible_map == nullptr) {
        return;
    }

    memset(this->visible->visible_map, 1, (size_t)this->visible->numberTotalTilesValue);
    this->visible->numberTilesExploredValue = this->visible->numberTotalTilesValue;
}

void RGE_Player::remake_visible_map() {
    // Source of truth: player.cpp.decomp @ 0x00471C00
    if (this->visible != nullptr) {
        if (this->visible->map_offsets != nullptr) {
            free(this->visible->map_offsets);
            this->visible->map_offsets = nullptr;
        }
        if (this->visible->visible_map != nullptr) {
            free(this->visible->visible_map);
            this->visible->visible_map = nullptr;
        }
        free(this->visible);
        this->visible = nullptr;
    }

    if (this->world == nullptr || this->world->map == nullptr ||
        this->world->map->map_width <= 0 || this->world->map->map_height <= 0) {
        return;
    }

    RGE_Visible_Map* vis = (RGE_Visible_Map*)calloc(1, sizeof(RGE_Visible_Map));
    if (vis == nullptr) {
        return;
    }

    vis->world = this->world;
    vis->player = this;
    vis->map = this->world->map;
    vis->widthValue = this->world->map->map_width;
    vis->heightValue = this->world->map->map_height;
    vis->numberTilesExploredValue = 0;
    vis->numberTotalTilesValue = vis->widthValue * vis->heightValue;

    if (this->id >= 0 && this->id < 32) {
        vis->PlayerVisibleMaskValue = (1UL << this->id);
        vis->PlayerExploredMaskValue = (1UL << this->id);
    } else {
        vis->PlayerVisibleMaskValue = 0;
        vis->PlayerExploredMaskValue = 0;
    }
    vis->PlayerVisibleMaskInvertValue = ~vis->PlayerVisibleMaskValue;
    vis->PlayerExploredMaskInvertValue = ~vis->PlayerExploredMaskValue;

    vis->visible_map = (uchar*)calloc((size_t)vis->numberTotalTilesValue, 1);
    vis->map_offsets = (uchar**)calloc((size_t)vis->heightValue, sizeof(uchar*));
    if (vis->visible_map == nullptr || vis->map_offsets == nullptr) {
        if (vis->map_offsets != nullptr) {
            free(vis->map_offsets);
        }
        if (vis->visible_map != nullptr) {
            free(vis->visible_map);
        }
        free(vis);
        return;
    }

    for (int row = 0; row < vis->heightValue; ++row) {
        vis->map_offsets[row] = vis->visible_map + row * vis->widthValue;
    }

    this->visible = vis;
}

uchar RGE_Player::get_resigned() { return this->resigned; }
int RGE_Player::computerPlayer() { return this->computerPlayerValue; }

// Fully verified. Source of truth: player.cpp.decomp @ 0x0046F250
int RGE_Player::availablePathingAttempts(int param_1) {
    if ((this->pathingDelayCapValue != -1) && (this->pathingDelayCapValue < param_1)) {
        return 1;
    }
    if (this->pathingAttemptCapValue == -1) {
        return 1;
    }
    return (this->currentUpdatePathingAttemptsValue < this->pathingAttemptCapValue) ? 1 : 0;
}

// Fully verified. Source of truth: player.cpp.decomp @ 0x0046F290
void RGE_Player::incrementPathingAttempts() {
    this->currentUpdatePathingAttemptsValue = this->currentUpdatePathingAttemptsValue + 1;
}

void __cdecl RGE_Player::sendChatMessage(int param_1, int param_2, char* param_3, ...) {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x0046F2A0 (and player.cpp.asm @ 0x0046F2A0)
    char textOut[1025];

    va_list args;
    va_start(args, param_3);
    vsprintf(textOut + 4, param_3, args);
    va_end(args);

    if (textOut[4] == '\0') {
        return;
    }

    TCommunications_Handler* comm_handler = this->world->commands->com_hand;

    uint slot = 1;
    int playerCount = rge_base_game->numberPlayers();
    if (playerCount > 0) {
        do {
            const int player_id = rge_base_game->playerID((int)slot);
            if (player_id == param_1) {
                comm_handler->SendChatMsg((uint)this->id, slot, textOut + 4);
            }
            slot += 1;
            playerCount = rge_base_game->numberPlayers();
        } while ((int)slot <= playerCount);
    }

    if (param_2 == 1 && param_1 != this->id) {
        slot = 1;
        playerCount = rge_base_game->numberPlayers();
        if (playerCount > 0) {
            do {
                const int player_id = rge_base_game->playerID((int)slot);
                if (player_id == this->id) {
                    comm_handler->SendChatMsg((uint)this->id, slot, textOut + 4);
                }
                slot += 1;
                playerCount = rge_base_game->numberPlayers();
            } while ((int)slot <= playerCount);
        }
    }
}

void RGE_Player::set_color_table(uchar param_1) {
    // Source of truth: player.cpp.decomp @ 0x004705A0
    if (this->world && this->world->color_tables) {
        this->color_table = this->world->color_tables[param_1];
    }
}

void RGE_Player::win_game_now() {
    // Source of truth: player.cpp.decomp @ 0x00470600
    this->victory_if_game_on();
    for (int i = 1; i < this->world->player_num; i++) {
        if (i != this->id) {
            if (this->allied_victory != 0) {
                // Check if mutual allies with allied_victory enabled
                if (this->relations[i] == 0 &&
                    this->world->players[i]->relations &&
                    this->world->players[i]->relations[this->id] == 0 &&
                    this->world->players[i]->allied_victory != 0) {
                    this->world->players[i]->victory_if_game_on();
                    continue;
                }
            }
            this->world->players[i]->loss_if_game_on();
        }
    }
}

void RGE_Player::victory_if_game_on() {
    // Source of truth: player.cpp.decomp @ 0x004705C0
    if (this->game_status == 0) {
        this->set_game_status(1); // won
    }
}

void RGE_Player::loss_if_game_on() {
    // Source of truth: player.cpp.decomp @ 0x004705E0
    if (this->game_status == 0) {
        this->set_game_status(2); // lost
    }
}

void RGE_Player::load_info(int param_1) {
    // Source of truth: player.cpp.decomp @ 0x0046FF00
    this->load_victory(param_1, nullptr, '\x01');
    if (this->objects != nullptr) {
        this->objects->rehook_list();
    }
    if (this->sleeping_objects != nullptr) {
        this->sleeping_objects->rehook_list();
    }
    if (this->doppleganger_objects != nullptr) {
        this->doppleganger_objects->rehook_list();
    }
}

uchar RGE_Player::check_victory_conditions() {
    // Source of truth: player.cpp.decomp @ 0x00470690
    if (this->game_status != '\x02') {
        return (this->victory_conditions != nullptr) ? this->victory_conditions->victory_achieved() : '\0';
    }
    return '\x01';
}

uchar RGE_Player::check_ally_group(long* param_1) {
    // Source of truth: player.cpp.decomp @ 0x004706B0
    long old_count = (param_1 != nullptr) ? *param_1 : -1;
    uchar ok = '\x01';

    if (this->game_status != '\x02') {
        if (param_1 != nullptr) {
            *param_1 = 0;
        }

        if (this->world != nullptr && this->world->player_num > 1) {
            for (int i = 1; i < this->world->player_num; ++i) {
                if (this->relations != nullptr && this->relations[i] == '\0') {
                    RGE_Player* other = (this->world->players != nullptr) ? this->world->players[i] : nullptr;
                    if (other != nullptr) {
                        if (other->relation((long)this->id) != '\0' || other->allied_victory == '\0') {
                            ok = '\0';
                            break;
                        }
                    }
                }

                if (param_1 != nullptr) {
                    *param_1 = *param_1 + 1;
                }
            }
        }
    }

    if (old_count >= 0 && param_1 != nullptr && *param_1 != old_count) {
        ok = '\0';
    }

    return ok;
}

uchar RGE_Player::check_victory() {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00470750 (audited vs player.cpp.asm).
    if (this->game_status != '\x02' && this->victory_conditions != nullptr && this->victory_conditions->victory_achieved() != '\0') {
        bool blocked = false;
        if (this->allied_victory != '\0') {
            long count = -1;
            if (this->world != nullptr && this->world->player_num > 1) {
                for (int i = 1; i < this->world->player_num; ++i) {
                    if (i == (int)this->id || (this->relations != nullptr && this->relations[i] == '\0')) {
                        RGE_Player* other = (this->world->players != nullptr) ? this->world->players[i] : nullptr;
                        if (other != nullptr && other->check_ally_group(&count) == '\0') {
                            blocked = true;
                            break;
                        }
                    }
                }
            }

            if (this->allied_victory != '\0' && !blocked) {
                if (this->world != nullptr && this->world->player_num > 1) {
                    for (int i = 1; i < this->world->player_num; ++i) {
                        if (this->relations != nullptr && this->relations[i] == '\0') {
                            RGE_Player* other = (this->world->players != nullptr) ? this->world->players[i] : nullptr;
                            if (other != nullptr && other->check_victory_conditions() == '\0') {
                                blocked = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (!blocked) {
            this->set_game_status('\x01'); // won
            if (this->world != nullptr) {
                this->world->game_end_condition = '\x02';
            }
        }
    }

    return this->game_status;
}

void RGE_Player::set_allied_victory(uchar param_1) {
    // Source of truth: player.cpp.decomp @ 0x00470BB0
    this->allied_victory = param_1;
}

uchar RGE_Player::get_allied_victory() {
    // Source of truth: player.cpp.decomp @ 0x00470BC0
    return this->allied_victory;
}

uchar RGE_Player::relation(long param_1) {
    // Source of truth: player.cpp.decomp @ 0x00470BD0
    return this->relations[param_1];
}
