#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_Gaia.h"
#include "../include/TRIBE_Master_Player.h"
#include "../include/TRIBE_Master_Tree_Object.h"
#include "../include/TRIBE_Master_Combat_Object.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_World.h"
#include "../include/TRIBE_Object_List.h"
#include "../include/TRIBE_Player_Tech.h"
#include "../include/TRIBE_History_Info.h"
#include "../include/TRIBE_Victory_Conditions.h"
#include "../include/TRIBE_Command.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Visible_Map.h"
#include "../include/RGE_Game_World.h"
#include "../include/Visible_Resource_Manager.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TMousePointer.h"
#include "../include/RGE_Base_Game.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include "../include/TribeMainDecisionAIModule.h"

#include <new>
#include <stdlib.h>

class TribeBuildAIModule {
public:
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int addBuiltItem(RGE_Static_Object* param_1, int param_2);
    int cancelBuildItem(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7);
    int addTrainedUnit(int param_1, int param_2, int param_3, int param_4);
    int cancelTrainUnit(int param_1, int param_2, int param_3, int param_4);
    int addResearch(int param_1, int param_2, int param_3);
    int cancelResearch(int param_1, int param_2, int param_3, int param_4);
};

static short tribe_player_attr_as_short(TRIBE_Player* player, int index) {
    if (player == nullptr || player->attributes == nullptr) {
        return 0;
    }
    if (index < 0 || index >= player->attribute_num) {
        return 0;
    }
    return (short)((long)player->attributes[index]);
}

// --- TRIBE_Player constructors ---
TRIBE_Player::TRIBE_Player(RGE_Game_World* world, RGE_Master_Player* master, uchar player_id, char* name, uchar civ, uchar is_computer, uchar is_active, char* ai1, char* ai2, char* ai3)
    : RGE_Player(world, master, player_id, name, civ, '\0', '\0', ai1, ai2, ai3) {
    // Source of truth: tplayer.cpp.decomp @ 0x00511E20
    this->playerAI = nullptr;
    this->VR_List = new (std::nothrow) Visible_Resource_Manager((RGE_Player*)this, 5);

    if (is_computer != 0) {
        this->type = 3;
        this->computerPlayerValue = 1;
        if (((TCommunications_Handler*)comm)->IsHost() == 1) {
            this->playerAI = new (std::nothrow) TribeMainDecisionAIModule(nullptr, (int)this->id, this->name, this, ai1, ai2, ai3);
        }
    } else {
        this->type = 1;
    }

    if (is_active != 0) {
        this->objects = new (std::nothrow) TRIBE_Object_List();
        this->sleeping_objects = new (std::nothrow) TRIBE_Object_List();
        this->doppleganger_objects = new (std::nothrow) TRIBE_Object_List();
        this->new_victory();
        if (world != nullptr && world->map != nullptr) {
            this->visible = new (std::nothrow) RGE_Visible_Map(world->map, (RGE_Player*)this);
        }
    }

    if (world != nullptr && world->player_num > 1) {
        for (int i = 1; i < world->player_num; ++i) {
            if (i != this->id) {
                this->set_relation(i, 3);
            }
        }
    }

    this->update_count = 0;
    this->update_history_count = 0;
    this->updateCountNeedHelp = 0;
    int random_value = debug_rand("C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x140);
    this->update_time = 0.0f;
    this->fog_update = (random_value * 3) / 0x7fff + 3;

    memset(this->aiStatusInformationValue, 0, sizeof(this->aiStatusInformationValue));
    memset(this->aiStatusInformationValue2, 0, sizeof(this->aiStatusInformationValue2));
    memset(this->aiStatusInformationValue3, 0, sizeof(this->aiStatusInformationValue3));
    memset(this->aiStatusInformationValue4, 0, sizeof(this->aiStatusInformationValue4));
    memset(this->aiStatusInformationValue5, 0, sizeof(this->aiStatusInformationValue5));
    memset(this->aiStatusInformationValue6, 0, sizeof(this->aiStatusInformationValue6));

    this->history = new (std::nothrow) TRIBE_History_Info(-1);
    this->tech_tree = new (std::nothrow) TRIBE_Player_Tech(((TRIBE_World*)world)->tech, (RGE_Player*)this, 1);

    this->ruin_held_time = -1.0f;
    this->artifact_held_time = -1.0f;
}

TRIBE_Player::TRIBE_Player(int param_1, RGE_Game_World* world, uchar player_id)
    : RGE_Player(param_1, world, player_id) {
    // Source of truth: tplayer.cpp.decomp @ 0x00511BD0
    this->playerAI = nullptr;
    memset(this->aiStatusInformationValue, 0, sizeof(this->aiStatusInformationValue));
    memset(this->aiStatusInformationValue2, 0, sizeof(this->aiStatusInformationValue2));
    memset(this->aiStatusInformationValue3, 0, sizeof(this->aiStatusInformationValue3));
    memset(this->aiStatusInformationValue4, 0, sizeof(this->aiStatusInformationValue4));
    memset(this->aiStatusInformationValue5, 0, sizeof(this->aiStatusInformationValue5));
    memset(this->aiStatusInformationValue6, 0, sizeof(this->aiStatusInformationValue6));

    rge_read(param_1, &this->type, 1);
    rge_read(param_1, &this->update_count, 4);
    rge_read(param_1, &this->updateCountNeedHelp, 4);
    rge_read(param_1, &this->fog_update, 4);
    rge_read(param_1, &this->update_time, 4);
    this->tech_tree = new (std::nothrow) TRIBE_Player_Tech(param_1, ((TRIBE_World*)world)->tech, (RGE_Player*)this, 0);

    if (save_game_version <= 5.0f) {
        this->update_history_count = 0;
        this->history = new (std::nothrow) TRIBE_History_Info(-1);
    } else {
        rge_read(param_1, &this->update_history_count, 4);
        this->history = new (std::nothrow) TRIBE_History_Info(param_1);
    }

    if (save_game_version < 5.3f) {
        this->ruin_held_time = -1.0f;
        this->artifact_held_time = -1.0f;
    } else {
        rge_read(param_1, &this->ruin_held_time, 4);
        rge_read(param_1, &this->artifact_held_time, 4);
    }

    if (this->type == 3) {
        int has_ai = 1;
        if (save_game_version >= 7.03f) {
            rge_read(param_1, &has_ai, 4);
        }
        if (((TCommunications_Handler*)comm)->IsHost() == 1 && has_ai == 1) {
            this->playerAI = new (std::nothrow) TribeMainDecisionAIModule((int)this->id, this->name, this, param_1);
        }
        this->computerPlayerValue = 1;
    }
}

TRIBE_Player::~TRIBE_Player() {
    // Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005120F0
    if (this->tech_tree) {
        delete this->tech_tree;
        this->tech_tree = nullptr;
    }
    if (this->playerAI) {
        delete this->playerAI;
        this->playerAI = nullptr;
    }
    if (this->history) {
        delete this->history;
        this->history = nullptr;
    }
}

// --- TRIBE_Gaia constructors ---
TRIBE_Gaia::TRIBE_Gaia(RGE_Game_World* world, RGE_Master_Player* master, uchar player_id, char* name, uchar type)
    // Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00519BD0
    : TRIBE_Player(world, master, player_id, name, type, '\0', '\x01', nullptr, nullptr, nullptr) {
    *((unsigned char*)this + 0x48) = 2;
    this->update_time = 0.0f;
    this->update_nature = 0x1d;
    this->animal_max = 0;
    this->last_count = 0;
}

TRIBE_Gaia::TRIBE_Gaia(int param_1, RGE_Game_World* world, uchar player_id)
    // Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00519AF0
    : TRIBE_Player(param_1, world, player_id) {
    *((unsigned char*)this + 0x48) = 2;
    rge_read(param_1, &this->update_time, 4);
    rge_read(param_1, &this->update_nature, 4);
    rge_read(param_1, &this->animal_max, 4);
    rge_read(param_1, &this->last_count, 4);
}

TRIBE_Gaia::~TRIBE_Gaia() {}
void TRIBE_Gaia::update() { TRIBE_Player::update(); }

// --- TRIBE_Master_Player constructors ---
TRIBE_Master_Player::TRIBE_Master_Player(int param_1)
    : RGE_Master_Player(param_1) {}

TRIBE_Master_Player::TRIBE_Master_Player(FILE* param_1)
    : RGE_Master_Player(param_1) {}

TRIBE_Master_Player::~TRIBE_Master_Player() {}
void TRIBE_Master_Player::finish_init(int p1, RGE_Sprite** p2, RGE_Sound** p3) { RGE_Master_Player::finish_init(p1, p2, p3); }
void TRIBE_Master_Player::load_master_object(int p1, uchar p2, RGE_Sprite** p3, RGE_Sound** p4, short p5) {
    RGE_Master_Static_Object* loaded = nullptr;

    if (p2 == 'F') {
        loaded = new TRIBE_Master_Combat_Object(p1, p3, p4, 1);
    } else if (p2 == 'P') {
        loaded = new TRIBE_Master_Building_Object(p1, p3, p4, 1);
    } else if (p2 == 'Z') {
        loaded = new TRIBE_Master_Tree_Object(p1, p3, p4, 1);
    } else {
        RGE_Master_Player::load_master_object(p1, p2, p3, p4, p5);
        return;
    }

    if (this->master_objects != nullptr && p5 >= 0 && p5 < this->master_object_num) {
        this->master_objects[p5] = loaded;
    }
}
void TRIBE_Master_Player::create_master_object_space(short p1) { RGE_Master_Player::create_master_object_space(p1); }
void TRIBE_Master_Player::load_object(FILE* p1, uchar p2, RGE_Sprite** p3, RGE_Sound** p4, short p5) {
    RGE_Master_Static_Object* loaded = nullptr;

    if (p2 == 'F') {
        loaded = new TRIBE_Master_Combat_Object(p1, p3, p4, p5, 1);
    } else if (p2 == 'P') {
        loaded = new TRIBE_Master_Building_Object(p1, p3, p4, p5, 1);
    } else if (p2 == 'Z') {
        loaded = new TRIBE_Master_Tree_Object(p1, p3, p4, p5, 1);
    } else {
        RGE_Master_Player::load_object(p1, p2, p3, p4, p5);
        return;
    }

    if (this->master_objects != nullptr && p5 >= 0 && p5 < this->master_object_num) {
        this->master_objects[p5] = loaded;
    }
}
void TRIBE_Master_Player::save(int p1) { RGE_Master_Player::save(p1); }
void TRIBE_Player::set_game_status(uchar param_1) { RGE_Player::set_game_status(param_1); }
void TRIBE_Player::do_resign(int param_1) { RGE_Player::do_resign(param_1); }
void TRIBE_Player::changeToHumanPlayer() { RGE_Player::changeToHumanPlayer(); }
void TRIBE_Player::changeToComputerPlayer() { RGE_Player::changeToComputerPlayer(); }
char* TRIBE_Player::aiStatus(int param_1) { return RGE_Player::aiStatus(param_1); }
int TRIBE_Player::isEnemy(int param_1) { return RGE_Player::isEnemy(param_1); }
int TRIBE_Player::isAlly(int param_1) { return RGE_Player::isAlly(param_1); }
int TRIBE_Player::isNeutral(int param_1) { return RGE_Player::isNeutral(param_1); }
int TRIBE_Player::isAllNeutral() { return RGE_Player::isAllNeutral(); }
void TRIBE_Player::setDiplomaticStance(int param_1, int param_2) { RGE_Player::setDiplomaticStance(param_1, param_2); }
void TRIBE_Player::loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5) { RGE_Player::loadAIInformation(param_1, param_2, param_3, param_4, param_5); }
void TRIBE_Player::sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) { RGE_Player::sendUnitAIOrder(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
void TRIBE_Player::processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) { RGE_Player::processAIOrder(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
void TRIBE_Player::kickAI(int param_1) { RGE_Player::kickAI(param_1); }
int TRIBE_Player::strategicNumber(int param_1) { return RGE_Player::strategicNumber(param_1); }
void TRIBE_Player::sendGameOrder(RGE_Static_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4) { RGE_Player::sendGameOrder(param_1, param_2, param_3, param_4); }
void TRIBE_Player::sendAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) { RGE_Player::sendAddWaypointCommand(param_1, param_2, param_3); }
void TRIBE_Player::processAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3) { RGE_Player::processAddWaypointCommand(param_1, param_2, param_3); }
void TRIBE_Player::sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5) { RGE_Player::sendPlayCommand(param_1, param_2, param_3, param_4, param_5); }
void TRIBE_Player::sendPlayCommand(int param_1, int param_2, int param_3) { RGE_Player::sendPlayCommand(param_1, param_2, param_3); }
int TRIBE_Player::sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5) { return RGE_Player::sendAICommand(param_1, param_2, param_3, param_4, param_5); }
int TRIBE_Player::objectCostByType(int param_1) { return RGE_Player::objectCostByType(param_1); }
void TRIBE_Player::trackUnitGather(int param_1, int param_2, int param_3) { RGE_Player::trackUnitGather(param_1, param_2, param_3); }
RGE_Static_Object* TRIBE_Player::make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6) { return RGE_Player::make_scenario_obj(param_1, param_2, param_3, param_4, param_5, param_6); }
void TRIBE_Player::scenario_save(int param_1) {
    // Source of truth: tplayer.cpp.decomp @ 0x00512630
    RGE_Player::scenario_save(param_1);
    // Write starting resources (food, wood, stone, gold) - attributes[0..3]
    if (this->attributes && this->attribute_num >= 4) {
        rge_write(param_1, &this->attributes[0], 4); // food
        rge_write(param_1, &this->attributes[1], 4); // wood
        rge_write(param_1, &this->attributes[3], 4); // stone (offset 0xc = index 3)
        rge_write(param_1, &this->attributes[2], 4); // gold  (offset 0x8 = index 2)
    }
}
void TRIBE_Player::scenario_load(int param_1, long* param_2, float param_3) { RGE_Player::scenario_load(param_1, param_2, param_3); }
void TRIBE_Player::scenario_postsave(int param_1) { RGE_Player::scenario_postsave(param_1); }
void TRIBE_Player::scenario_postload(int param_1, long* param_2, float param_3) { RGE_Player::scenario_postload(param_1, param_2, param_3); }
void TRIBE_Player::load(int param_1) { RGE_Player::load(param_1); }
void TRIBE_Player::add_attribute_num(short param_1, float param_2, uchar param_3) { RGE_Player::add_attribute_num(param_1, param_2, param_3); }
void TRIBE_Player::tech_abling(long param_1, uchar param_2) {
    // Source of truth: tplayer.cpp.decomp @ 0x00513DA0
    // Temporary-safe: tech_tree construction is still partial in current decomp state.
    if (this->tech_tree == nullptr) {
        return;
    }
    if (param_2 != 0) {
        this->tech_tree->enable((short)param_1);
        return;
    }
    this->tech_tree->disable((short)param_1);
}
void TRIBE_Player::rev_tech(long param_1) {
    // Source of truth: tplayer.cpp.asm @ 0x00513DD0
    if (this->tech_tree == nullptr) {
        return;
    }

    short attr_00 = tribe_player_attr_as_short(this, 0);
    short attr_17 = tribe_player_attr_as_short(this, 0x17);
    short attr_18 = tribe_player_attr_as_short(this, 0x18);
    short attr_19 = tribe_player_attr_as_short(this, 0x19);

    switch (param_1) {
    case 0x17:
        this->tech_tree->disable(attr_17);
        this->tech_tree->rev_tech(attr_00);
        this->tech_tree->enable(attr_17);
        this->tech_tree->do_tech(attr_17);
        return;
    case 0x18:
        this->tech_tree->disable(attr_00);
        this->tech_tree->disable(attr_18);
        this->tech_tree->rev_tech(attr_19);
        this->tech_tree->enable(attr_00);
        this->tech_tree->rev_tech(attr_17);
        this->tech_tree->enable(attr_18);
        this->tech_tree->do_tech(attr_00);
        return;
    case 0x19:
        this->tech_tree->do_tech(attr_19);
        return;
    case 1:
        this->tech_tree->disable(attr_17);
        this->tech_tree->disable(attr_18);
        this->tech_tree->rev_tech(attr_00);
        this->tech_tree->enable(attr_17);
        this->tech_tree->rev_tech(attr_17);
        this->tech_tree->enable(attr_00);
        this->tech_tree->rev_tech(attr_18);
        return;
    default:
        return;
    }
}
void TRIBE_Player::add_population_entry() {
    // Source of truth: tplayer.cpp.asm @ 0x00513FD0
    if (this->history == nullptr || this->attributes == nullptr || this->attribute_num <= 0x0B) {
        return;
    }

    float population = this->attributes[0x0B];
    if (population < 0.0f) {
        this->history->add_history_entry(0, 0);
    } else {
        this->history->add_history_entry(0, (uchar)((long)population));
    }
}
uchar TRIBE_Player::check_obj_cost(short param_1, short* param_2, float param_3, int param_4) {
    // Source of truth: tplayer.cpp.decomp @ 0x00513AF0
    float reserve_resource = this->attributes[3];
    if (param_2 != nullptr) {
        *param_2 = -1;
    }

    bool can_use_reserve = 1.0f <= this->attributes[0x1D];
    if (!can_use_reserve) {
        reserve_resource = 0.0f;
    }

    TRIBE_Master_Combat_Object* master = (TRIBE_Master_Combat_Object*)this->master_objects[param_1];
    if (master == nullptr || master->master_type < 'F') {
        if (param_2 != nullptr) {
            *param_2 = -1;
        }
        return 0;
    }

    for (int i = 0; i < 3; ++i) {
        int attr_type = (int)master->build_inventory[i].type;
        if (attr_type >= 0) {
            float needed = (float)(int)master->build_inventory[i].amount * param_3;

            if (((attr_type == 4) && (param_4 == 0)) && (this->attributes[0x20] <= this->attributes[0x0B])) {
                if (param_2 == nullptr) {
                    return 0;
                }
                *param_2 = 0x20;
                return 0;
            }

            if (can_use_reserve && attr_type == 3) {
                reserve_resource = reserve_resource - needed;
                if (reserve_resource < 0.0f) {
                    if (param_2 == nullptr) {
                        return 0;
                    }
                    *param_2 = 3;
                    return 0;
                }
            }

            if ((this->attributes[attr_type] < needed) && ((attr_type != 4) || (param_4 == 0))) {
                if ((master->build_inventory[i].flag == 0) || (reserve_resource + this->attributes[attr_type] < needed)) {
                    if (param_2 == nullptr) {
                        return 0;
                    }
                    *param_2 = master->build_inventory[i].type;
                    return 0;
                }
                reserve_resource = reserve_resource - (needed - this->attributes[attr_type]);
            }
        }
    }

    return 1;
}
uchar TRIBE_Player::pay_obj_cost(short param_1, float param_2, int param_3) {
    // Source of truth: tplayer.cpp.decomp @ 0x00513C50
    if (this->check_obj_cost(param_1, nullptr, param_2, param_3) != 0) {
        TRIBE_Master_Combat_Object* master = (TRIBE_Master_Combat_Object*)this->master_objects[param_1];
        Attribute_Cost* cost = &master->build_inventory[0];

        for (int i = 0; i < 3; ++i) {
            int attr_type = (int)cost[i].type;
            if (((attr_type >= 0) && (cost[i].flag != 0)) && ((param_3 == 0) || (attr_type != 4))) {
                float needed = (float)(int)cost[i].amount * param_2;
                if (needed <= this->attributes[attr_type]) {
                    this->attributes[attr_type] = this->attributes[attr_type] - needed;
                }
                else {
                    this->attributes[3] = this->attributes[3] - (needed - this->attributes[attr_type]);
                    this->attributes[attr_type] = 0.0f;
                }
            }
        }
        return 1;
    }

    return 0;
}
void TRIBE_Player::reimburse_obj_cost(short param_1) {
    // Source of truth: tplayer.cpp.decomp @ 0x00513D00
    TRIBE_Master_Combat_Object* master = (TRIBE_Master_Combat_Object*)this->master_objects[param_1];
    if (master->master_type >= 'F') {
        Attribute_Cost* cost = &master->build_inventory[0];
        for (int i = 0; i < 3; ++i) {
            if ((cost[i].type >= 0) && (cost[i].flag != 0)) {
                float* attr = &this->attributes[cost[i].type];
                *attr = (float)(int)cost[i].amount + *attr;
            }
        }
    }
}
void TRIBE_Player::update() {
    // Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005123B0
    this->update_time = this->world->world_time_delta_seconds + this->update_time;
    while (this->update_time > 1.0f) {
        int previous_history_count = this->update_history_count;
        int next_history_count = previous_history_count + 1;
        this->update_history_count = next_history_count;
        this->update_time = this->update_time - 1.0f;

        if (next_history_count > 0xE) {
            this->update_history_count = previous_history_count - 0xE;
            uchar population_value = 0;
            if (0.0f <= this->attributes[0x0B]) {
                population_value = (uchar)((long)this->attributes[0x0B]);
            }
            this->history->add_history_entry(0, population_value);
        }

        if (rge_base_game->fullVisibility() == 0) {
            this->attributes[0x16] = this->visible->percentExplored() * 100.0f;
        } else {
            this->attributes[0x16] = 100.0f;
        }

        this->attributes[0x2C] = this->attributes[0x14] - (this->attributes[0x13] - this->attributes[0x0B]);
        if (this->attributes[0x2C] < 0.0f) {
            this->attributes[0x2C] = 0.0f;
        }

        this->attributes[9] = this->attributes[10] + this->attributes[9];
        if (100.0f < this->attributes[9]) {
            this->attributes[9] = 100.0f;
        }

        if (this->update_count > 0) {
            this->update_count = this->update_count - 1;
        }
        if (this->updateCountNeedHelp > 0) {
            this->updateCountNeedHelp = this->updateCountNeedHelp - 1;
        }

        if (0 < this->id) {
            RGE_Object_Node* node = nullptr;
            if (this->objects != nullptr) {
                node = this->objects->list;
            }
            while (node != nullptr) {
                short object_group = node->node->master_obj->object_group;
                if ((object_group != 0x0B) && (object_group != 0x1E) && (object_group != 0x1B) && (object_group != 1) &&
                    (object_group != 0x15) && (object_group != 0x14) && (object_group != 2) && (object_group != 0x25) &&
                    (node->node->object_state == 2)) {
                    break;
                }
                node = node->next;
            }

            if (node == nullptr) {
                this->set_game_status(2);
                this->attributes[0x2D] = 0.0f;
            }
        }
    }

    RGE_Player::update();

    this->attributes[0] = this->attributes[0] - this->world->world_time_delta_seconds * this->attributes[0x21] * this->attributes[0x0B] * 0.016666668f;
    if (this->attributes[0] < 0.0f) {
        this->attributes[0] = 0.0f;
    }

    uint saved_seed = (uint)debug_rand("C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x25F);
    int saved_debug_random_on = debug_random_on;
    debug_random_on = 0;

    if (this->playerAI != nullptr && ((TCommunications_Handler*)comm)->MultiplayerGameStart() == 1) {
        if (this->world->currentUpdateComputerPlayer == -1) {
            this->world->selectNextComputerPlayer(3);
        }
        void** vtable = *(void***)this->playerAI;
        ((int(__thiscall*)(TribeMainDecisionAIModule*, int))vtable[12])(this->playerAI, 0);
    }

    debug_random_on = saved_debug_random_on;
    debug_srand("C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x277, saved_seed);
    if (MouseSystem != nullptr) {
        MouseSystem->Poll();
    }
}
void TRIBE_Player::update_dopplegangers() { RGE_Player::update_dopplegangers(); }
void TRIBE_Player::save(int param_1) {
    // Source of truth: tplayer.cpp.decomp @ 0x00512250
    color_log(0x16, 0x16, 2);
    int handle = param_1;
    RGE_Player::save(param_1);
    color_log(0x16, 0x24, 2);
    rge_write(param_1, &this->type, 1);
    rge_write(param_1, &this->update_count, 4);
    rge_write(param_1, &this->updateCountNeedHelp, 4);
    rge_write(param_1, &this->fog_update, 4);
    rge_write(param_1, &this->update_time, 4);
    this->tech_tree->save(param_1);
    rge_write(param_1, &this->update_history_count, 4);
    this->history->save(param_1);
    rge_write(param_1, &this->ruin_held_time, 4);
    rge_write(param_1, &this->artifact_held_time, 4);
    color_log(0x16, 0x4C, 2);

    if (this->computerPlayerValue == 1) {
        if (this->playerAI != nullptr && ((TCommunications_Handler*)comm)->IsHost() == 1) {
            int has_ai = 1;
            rge_write(handle, &has_ai, 4);
            void** vtable = *(void***)this->playerAI;
            ((int(__thiscall*)(TribeMainDecisionAIModule*, int))vtable[15])(this->playerAI, handle);
            color_log(0x16, 0x5F, 2);
            return;
        }
        int has_ai = 0;
        rge_write(param_1, &has_ai, 4);
    }
    color_log(0x16, 0x5F, 2);
}
void TRIBE_Player::save2(int param_1) { RGE_Player::save2(param_1); }
void TRIBE_Player::save_info(int param_1) { RGE_Player::save_info(param_1); }
void TRIBE_Player::random_start() { RGE_Player::random_start(); }
RGE_Static_Object* TRIBE_Player::make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5) { return RGE_Player::make_new_object(param_1, param_2, param_3, param_4, param_5); }
void TRIBE_Player::analyize_selected_objects() { RGE_Player::analyize_selected_objects(); }
int TRIBE_Player::get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3) { return RGE_Player::get_mouse_pointer_action_vars(param_1, param_2, param_3); }
uchar TRIBE_Player::command_make_move(RGE_Static_Object* param_1, float param_2, float param_3) { return RGE_Player::command_make_move(param_1, param_2, param_3); }
uchar TRIBE_Player::command_make_work(RGE_Static_Object* param_1, float param_2, float param_3) { return RGE_Player::command_make_work(param_1, param_2, param_3); }
uchar TRIBE_Player::command_make_do(RGE_Static_Object* param_1, float param_2, float param_3) { return RGE_Player::command_make_do(param_1, param_2, param_3); }
uchar TRIBE_Player::command_stop() { return RGE_Player::command_stop(); }
uchar TRIBE_Player::command_place_object(short param_1, float param_2, float param_3, float param_4) { return RGE_Player::command_place_object(param_1, param_2, param_3, param_4); }
uchar TRIBE_Player::command_add_attribute(int param_1, float param_2) { return RGE_Player::command_add_attribute(param_1, param_2); }
uchar TRIBE_Player::command_give_attribute(int param_1, int param_2, float param_3) { return RGE_Player::command_give_attribute(param_1, param_2, param_3); }
uchar TRIBE_Player::command_formation(int param_1) { return RGE_Player::command_formation(param_1); }
uchar TRIBE_Player::command_stand_ground() { return RGE_Player::command_stand_ground(); }
uchar TRIBE_Player::command_create_group(int param_1, int* param_2, int param_3, float param_4) { return RGE_Player::command_create_group(param_1, param_2, param_3, param_4); }
uchar TRIBE_Player::command_add_to_group(int param_1, int param_2, float param_3) { return RGE_Player::command_add_to_group(param_1, param_2, param_3); }
uchar TRIBE_Player::command_remove_from_group(int param_1, int param_2) { return RGE_Player::command_remove_from_group(param_1, param_2); }
uchar TRIBE_Player::command_destroy_group(int param_1) { return RGE_Player::command_destroy_group(param_1); }
uchar TRIBE_Player::command_resign(int param_1, int param_2) { return RGE_Player::command_resign(param_1, param_2); }
uchar TRIBE_Player::command_add_waypoint(float param_1, float param_2, float param_3) { return RGE_Player::command_add_waypoint(param_1, param_2, param_3); }
RGE_Object_Node* TRIBE_Player::addObject(RGE_Static_Object* param_1, int param_2, int param_3) { return RGE_Player::addObject(param_1, param_2, param_3); }
void TRIBE_Player::removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4) { RGE_Player::removeObject(param_1, param_2, param_3, param_4); }
void TRIBE_Player::logMessage(char* param_1) { RGE_Player::logMessage(param_1); }
void TRIBE_Player::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) { RGE_Player::notify(param_1, param_2, param_3, param_4, param_5, param_6); }
void TRIBE_Player::logStatus(FILE* param_1, int param_2) { RGE_Player::logStatus(param_1, param_2); }
void TRIBE_Player::load_victory(int param_1, long* param_2, uchar param_3) {
    this->victory_conditions = new TRIBE_Victory_Conditions((RGE_Player*)this, param_1, param_2, param_3);
}
void TRIBE_Player::new_victory() {
    this->victory_conditions = new TRIBE_Victory_Conditions((RGE_Player*)this);
}
uchar TRIBE_Player::command_give_attribute(int param_1, int param_2, float param_3, float param_4) {
    // Source of truth: tplayer.cpp.decomp @ 0x005138D0
    if (param_2 == -1 || param_3 == 0.0f) {
        return 0;
    }
    if (this->world == nullptr || this->world->commands == nullptr) {
        return 0;
    }

    ((TRIBE_Command*)this->world->commands)->command_give_attribute((int)this->id, param_1, param_2, param_3, param_4);
    return 1;
}
// Offset: 0x00515130
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00515130
void TRIBE_Player::buildObject(int param_1, int param_2, float param_3, float param_4, int param_5) {
    int* allocated_ids = (int*)calloc(1, 4);
    *allocated_ids = param_1;
    ((TRIBE_Command*)this->world->commands)->command_build((int)this->id, allocated_ids, 1, param_2, param_3, param_4, param_5);
    free(allocated_ids);
}

// Offset: 0x00515180
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00515180
void TRIBE_Player::cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7) {
    if (this->playerAI != nullptr) {
        ((TribeBuildAIModule*)this->playerAI->buildAI)->cancelBuildItem(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
    }
}

// Offset: 0x005151C0
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005151C0
void TRIBE_Player::registerBuild(RGE_Static_Object* param_1, int param_2) {
    if (this->playerAI != nullptr) {
        ((TribeBuildAIModule*)this->playerAI->buildAI)->addBuiltItem(param_1, param_2);
    }
}

// Offset: 0x005151F0
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005151F0
void TRIBE_Player::trainUnit(int param_1, int param_2, int param_3) {
    ((TRIBE_Command*)this->world->commands)->command_make((int)this->id, param_2, param_1, param_3);
}

// Offset: 0x00515220
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00515220
void TRIBE_Player::cancelTrain(int param_1, int param_2, int param_3, int param_4) {
    if (this->playerAI != nullptr) {
        ((TribeBuildAIModule*)this->playerAI->buildAI)->cancelTrainUnit(param_1, param_2, param_3, param_4);
    }
}

// Offset: 0x00515250
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00515250
void TRIBE_Player::registerTrain(int param_1, int param_2, int param_3, int param_4) {
    if (this->playerAI != nullptr) {
        ((TribeBuildAIModule*)this->playerAI->buildAI)->addTrainedUnit(param_1, param_2, param_3, param_4);
    }
}

// Offset: 0x00515280
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00515280
void TRIBE_Player::research(int param_1, int param_2, int param_3) {
    ((TRIBE_Command*)this->world->commands)->command_research((int)this->id, param_2, param_1, param_3);
}

// Offset: 0x005152B0
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005152B0
void TRIBE_Player::cancelResearch(int param_1, int param_2, int param_3, int param_4) {
    if (this->playerAI != nullptr) {
        ((TribeBuildAIModule*)this->playerAI->buildAI)->cancelResearch(param_1, param_2, param_3, param_4);
    }
}

// Offset: 0x005152E0
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005152E0
void TRIBE_Player::registerResearch(int param_1, int param_2, int param_3) {
    if (this->playerAI != nullptr) {
        ((TribeBuildAIModule*)this->playerAI->buildAI)->addResearch(param_1, param_2, param_3);
    }
}

// Offset: 0x00515310
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00515310
void TRIBE_Player::taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5) {
    int* allocated_ids = (int*)calloc(1, 4);
    *allocated_ids = param_1;
    ((RGE_Command*)this->world->commands)->command_work((int)this->id, allocated_ids, 1, param_2, param_3, param_4, param_5);
    free(allocated_ids);
}

// Offset: 0x00515360
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00515360
void TRIBE_Player::taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5) {
    int* allocated_ids = (int*)calloc(1, 4);
    *allocated_ids = param_1;
    ((RGE_Command*)this->world->commands)->command_work((int)this->id, allocated_ids, 1, param_2, param_3, param_4, param_5);
    free(allocated_ids);
}
void TRIBE_Player::notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {}

// Offset: 0x00513690
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513690
uchar TRIBE_Player::command_make_wall(short param_1, long param_2, long param_3, long param_4, long param_5) {
    int iVar1;
    short sVar2;
    uchar uVar3;
    RGE_Static_Object** list;
    short list_num;

    sVar2 = param_1;
    iVar1 = (int)this->master_objects[(int)param_1];
    if ((iVar1 != 0) && (*(char*)(iVar1 + 0x52) != '\0')) {
        list = nullptr;
        list_num = 0;
        uVar3 = ((RGE_Player*)this)->get_selected_objects_to_command(&list, &list_num, 4, 4, (short)-1, (short)-1);
        if (uVar3 != '\0') {
            // Parity: virtual call at *(this->master_objects + 0x1d8)->vtable + 0x2c (tplayer.cpp.asm @ 0x005136ca).
            if (this->master_objects != nullptr) {
                void* obj = *(void**)((char*)this->master_objects + 0x1d8);
                if (obj != nullptr) {
                    using VCall = void(__thiscall*)(void*);
                    VCall fn = (VCall)(*(void***)(obj))[0x2c / 4];
                    fn(obj);
                }
            }

            ((TRIBE_Command*)this->world->commands)->command_build_wall(list, list_num, sVar2, param_2, param_3, param_4, param_5);
            free(list);
            return '\x01';
        }
    }
    return '\0';
}

// Offset: 0x00513600
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513600
uchar TRIBE_Player::command_make_building(short master_obj_id, float x, float y) {
    int iVar1;
    short sVar2;
    uchar uVar3;
    RGE_Static_Object** list;
    short list_num;

    sVar2 = master_obj_id;
    iVar1 = (int)this->master_objects[(int)master_obj_id];
    if ((iVar1 != 0) && ((*(char*)(iVar1 + 0x52) != '\0' || (master_obj_id == 0x6d)))) {
        list = nullptr;
        list_num = 0;
        uVar3 = ((RGE_Player*)this)->get_selected_objects_to_command(&list, &list_num, 4, 4, (short)-1, (short)-1);
        if (uVar3 != '\0') {
            // Parity: virtual call at *(this->master_objects + 0x1d8)->vtable + 0x2c (tplayer.cpp.asm @ 0x00513649).
            void* obj = *(void**)((char*)this->master_objects + 0x1d8);
            using VCall = void(__thiscall*)(void*);
            VCall fn = (VCall)(*(void***)(obj))[0x2c / 4];
            fn(obj);

            ((TRIBE_Command*)this->world->commands)->command_build(list, list_num, sVar2, x, y);
            free(list);
            return '\x01';
        }
    }
    return '\0';
}

// Offset: 0x00513860
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513860
uchar TRIBE_Player::command_attack_ground(float x, float y) {
    uchar uVar1;
    RGE_Static_Object** list;
    short list_num;

    list = nullptr;
    list_num = 0;
    uVar1 = ((RGE_Player*)this)->get_selected_objects_to_command(&list, &list_num, 4, (short)-1, (short)-1, 4);
    if (uVar1 != '\0') {
        list[0]->play_command_sound();
        ((TRIBE_Command*)this->world->commands)->command_attack_ground(list, list_num, x, y);
        free(list);
        return '\x01';
    }
    return '\0';
}

// Offset: 0x00513950
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513950
uchar TRIBE_Player::command_make_repair(RGE_Static_Object* target) {
    RGE_Static_Object* pRVar1;
    uchar uVar2;
    int iVar3;
    RGE_Static_Object** list;
    short sVar5;
    short list_num;
    RGE_Master_Static_Object* pRVar6;

    pRVar1 = target;
    if (((((TRIBE_Player*)target->owner != this) && ((iVar3 = this->isAlly((int)target->owner->id), iVar3 == 0))) ||
         (pRVar1->master_obj->master_type != 'P')) ||
        (((float)(int)pRVar1->master_obj->hp <= pRVar1->hp || (2 < pRVar1->object_state)))) {
        if ((TRIBE_Player*)pRVar1->owner != this) {
            iVar3 = this->isAlly((int)pRVar1->owner->id);
            if (iVar3 == 0) {
                return '\0';
            }
            iVar3 = pRVar1->owner->isAlly((int)this->id);
            if (iVar3 == 0) {
                return '\0';
            }
        }
        sVar5 = pRVar1->master_obj->object_group;
        if (((sVar5 != 2) && (sVar5 != 0x14)) && ((sVar5 != 0x15 && (sVar5 != 0x16)))) {
            return '\0';
        }
        if ((float)(int)pRVar1->master_obj->hp <= pRVar1->hp) {
            return '\0';
        }
        if (2 < pRVar1->object_state) {
            return '\0';
        }
    }

    list = nullptr;
    list_num = 0;
    uVar2 = ((RGE_Player*)this)->get_selected_objects_to_command(&list, &list_num, 4, 4, (short)-1, (short)-1);
    if (uVar2 == '\0') {
        return '\0';
    }
    pRVar6 = list[0]->get_command_master(pRVar1, 0.0f, 0.0f, 0.0f);
    if (pRVar6 != nullptr) {
        pRVar6->play_command_sound();
    }
    ((TRIBE_Command*)this->world->commands)->command_repair(list, list_num, pRVar1);
    free(list);
    return '\x01';
}

// Offset: 0x00513A80
// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513A80
uchar TRIBE_Player::command_make_unload(float x, float y) {
    uchar uVar1;
    RGE_Static_Object** list;
    short list_num;

    list = nullptr;
    list_num = 0;
    uVar1 = ((RGE_Player*)this)->get_selected_objects_to_command(&list, &list_num, 4, (short)-1, (short)-1, 7);
    if (uVar1 != '\0') {
        list[0]->play_command_sound();
        ((TRIBE_Command*)this->world->commands)->command_unload(list, list_num, x, y);
        free(list);
        return '\x01';
    }
    return '\0';
}
