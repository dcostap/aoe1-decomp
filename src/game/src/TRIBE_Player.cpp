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
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_Tech.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Visible_Map.h"
#include "../include/RGE_Game_World.h"
#include "../include/Item_Avail.h"
#include "../include/Trade_Avail.h"
#include "../include/ResourceItem.h"
#include "../include/Visible_Resource_Manager.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TMousePointer.h"
#include "../include/RGE_Base_Game.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include "../include/AIModule.h"
#include "../include/TribeMainDecisionAIModule.h"
#include "../include/TribeStrategyAIModule.h"
#include "../include/TribeInformationAIModule.h"
#include "../include/RGE_Game_Info.h"

#include <new>
#include <stdlib.h>
#include <string.h>

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

static int player_difficulty(TRIBE_Player* player) {
    (void)player;
    return (int)rge_base_game->rge_game_options.difficultyValue;
}

// TODO: STUB: Missing original tplayer.cpp global AI counters; using local parity placeholders.
int DAT_00886c1c = 0;
int DAT_00886c20 = 0;
int DAT_00886c24 = 0;
int DAT_00886c28 = 0;
int DAT_00886c2c = 0;
int DAT_00886c30 = 0;
int DAT_00886c34 = 0;
int DAT_00886c38 = 0;
int DAT_00886c3c = 0;
int DAT_00886c40 = 0;
int DAT_00886c44 = 0;
int DAT_00886c48 = 0;
// TODO: STUB: Missing original global computerPlayerSetup array; only index 0 is used here.
int computerPlayerSetup[13] = {0};
// TODO: STUB: Missing original allowAIToCheat global wiring from basegame startup.
int allowAIToCheat = 1;

static int signed_mask_mod(int value, int mask) {
    int sign = value >> 0x1f;
    return (((value ^ sign) - sign & mask ^ sign) - sign);
}

static void loadUnitHistoryParity(TribeInformationAIModule* information_ai) {
    char history_file_name[256];

    if ((rge_base_game != nullptr) && (rge_base_game->player_game_info != nullptr)) {
        char* player_name = ((RGE_Game_Info*)rge_base_game->player_game_info)->get_current_player_name();
        sprintf(history_file_name, "learn\\%s.uh", player_name);
    } else {
        strcpy(history_file_name, "learn\\Default.uh");
    }

    int history_file = rge_open(history_file_name, 0x8000);
    if (history_file != -1) {
        rge_read(history_file, information_ai->unitHistory, 0x2c);
        rge_close(history_file);
    }
}

static void unitsThatAreMostBuiltParity(TribeInformationAIModule* information_ai, int* most_built_unit_1, int* most_built_unit_2) {
    int* history = information_ai->unitHistory;
    int highest = -1;
    *most_built_unit_1 = -1;

    for (int i = 0; i < 0xb; ++i) {
        if ((highest == -1) || (highest < history[i])) {
            *most_built_unit_1 = i;
            highest = history[i];
        }
    }

    highest = -1;
    *most_built_unit_2 = -1;
    for (int i = 0; i < 0xb; ++i) {
        if ((i != *most_built_unit_1) && ((highest == -1) || (highest < history[i]))) {
            *most_built_unit_2 = i;
            highest = history[i];
        }
    }
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
    // Fully verified. Source of truth: tplayer.cpp.asm @ 0x00513DA0
    // tech_tree is constructed in TRIBE_Player init/load paths (0x00511BD0, 0x00511E20, 0x00512690).
    if (param_2 != 0) {
        this->tech_tree->enable((short)param_1);
        return;
    }
    this->tech_tree->disable((short)param_1);
}
void TRIBE_Player::rev_tech(long param_1) {
    // Fully verified. Source of truth: tplayer.cpp.asm @ 0x00513DD0
    // Original runtime flow dereferences tech_tree/attributes directly in this tech-tree toggle path.
    switch (param_1) {
    case 0x17:
        this->tech_tree->disable((short)((long)this->attributes[0x17]));
        this->tech_tree->rev_tech((short)((long)this->attributes[0]));
        this->tech_tree->enable((short)((long)this->attributes[0x17]));
        this->tech_tree->do_tech((short)((long)this->attributes[0x17]));
        return;
    case 0x18:
        this->tech_tree->disable((short)((long)this->attributes[0]));
        this->tech_tree->disable((short)((long)this->attributes[0x18]));
        this->tech_tree->rev_tech((short)((long)this->attributes[0x19]));
        this->tech_tree->enable((short)((long)this->attributes[0]));
        this->tech_tree->rev_tech((short)((long)this->attributes[0x17]));
        this->tech_tree->enable((short)((long)this->attributes[0x18]));
        this->tech_tree->do_tech((short)((long)this->attributes[0]));
        return;
    case 0x19:
        this->tech_tree->do_tech((short)((long)this->attributes[0x19]));
        return;
    case 1:
        this->tech_tree->disable((short)((long)this->attributes[0x17]));
        this->tech_tree->disable((short)((long)this->attributes[0x18]));
        this->tech_tree->rev_tech((short)((long)this->attributes[0]));
        this->tech_tree->enable((short)((long)this->attributes[0x17]));
        this->tech_tree->rev_tech((short)((long)this->attributes[0x17]));
        this->tech_tree->enable((short)((long)this->attributes[0]));
        this->tech_tree->rev_tech((short)((long)this->attributes[0x18]));
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

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00512BF0
void TRIBE_Player::tech_cost(short tech_id, short* inv_1, short* amt_1, short* inv_2, short* amt_2, short* inv_3, short* amt_3) {
    this->tech_tree->tech_cost(tech_id, inv_1, amt_1, inv_2, amt_2, inv_3, amt_3);
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00512EC0
RGE_Static_Object* TRIBE_Player::find_obj(short master_obj_id, RGE_Static_Object* start_after) {
    if (start_after != nullptr) {
        int found_start = 0;
        for (RGE_Object_Node* node = this->objects->list; node != nullptr; node = node->next) {
            RGE_Static_Object* obj = node->node;
            if (obj == nullptr) {
                continue;
            }
            if (found_start != 0) {
                if ((obj->master_obj->id == master_obj_id) && (obj->object_state < 3)) {
                    return obj;
                }
            }
            else if (obj == start_after) {
                found_start = 1;
            }
        }
    }

    for (RGE_Object_Node* node = this->objects->list; node != nullptr; node = node->next) {
        RGE_Static_Object* obj = node->node;
        if ((obj != nullptr) && (obj->master_obj->id == master_obj_id) && (obj->object_state == 2)) {
            return obj;
        }
    }
    return nullptr;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513000
void TRIBE_Player::interface_tech_avail(Item_Avail** out_items, short* out_count, short button_location) {
    short available_count = 0;
    int i;

    for (i = 0; i < this->tech_tree->tech_player_tree_num; ++i) {
        if ((this->tech_tree->tech_player_tree[i].state == 1) &&
            (this->tech_tree->base_tech->tech_tree[i].button_location == button_location)) {
            available_count++;
        }
    }

    if (*out_items != nullptr) {
        free(*out_items);
        *out_items = nullptr;
    }

    *out_count = available_count;
    if (available_count == 0) {
        return;
    }

    *out_items = (Item_Avail*)calloc((int)available_count, sizeof(Item_Avail));

    short out_index = 0;
    for (i = 0; i < this->tech_tree->tech_player_tree_num; ++i) {
        if ((this->tech_tree->tech_player_tree[i].state == 1) &&
            (this->tech_tree->base_tech->tech_tree[i].button_location == button_location)) {
            short inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3;
            (*out_items)[out_index].id = (short)i;
            (*out_items)[out_index].pict = this->tech_tree->base_tech->tech_tree[i].icon;
            (*out_items)[out_index].name = this->tech_tree->base_tech->tech_tree[i].name;
            this->tech_cost((short)i, &inv_1, &inv_amt_1, &inv_2, &inv_amt_2, &inv_3, &inv_amt_3);
            (*out_items)[out_index].inventory_item_1 = inv_1;
            (*out_items)[out_index].inventory_cost_1 = (float)(int)inv_amt_1;
            (*out_items)[out_index].inventory_item_2 = inv_2;
            (*out_items)[out_index].inventory_cost_2 = (float)(int)inv_amt_2;
            (*out_items)[out_index].inventory_item_3 = inv_3;
            (*out_items)[out_index].inventory_cost_3 = (float)(int)inv_amt_3;
            (*out_items)[out_index].help_string_id = this->tech_tree->base_tech->get_help_message((short)i);
            (*out_items)[out_index].help_page_id = this->tech_tree->base_tech->get_help_page((short)i);
            out_index++;
        }
    }
}

static void interface_obj_cost(TRIBE_Player* player, short obj_id,
                               short* inv_1, short* amt_1, short* inv_2, short* amt_2, short* inv_3, short* amt_3) {
    TRIBE_Master_Combat_Object* master;
    short shortage = 0;
    uchar can_afford;

    *inv_1 = -1;
    *amt_1 = 0;
    *inv_2 = -1;
    *amt_2 = 0;
    *inv_3 = -1;
    *amt_3 = 0;

    can_afford = player->check_obj_cost(obj_id, nullptr, 1.0f, 0);
    master = (TRIBE_Master_Combat_Object*)player->master_objects[(int)obj_id];
    if ((master == nullptr) || (master->master_type < 'F')) {
        return;
    }

    Attribute_Cost* costs = &master->build_inventory[0];
    short* inv_slots[3] = { inv_1, inv_2, inv_3 };
    short* amt_slots[3] = { amt_1, amt_2, amt_3 };

    for (int i = 0; i < 3; ++i) {
        if ((costs[i].flag != 0) && (costs[i].type >= 0)) {
            short inv = costs[i].type;
            short amt = costs[i].amount;
            *inv_slots[i] = inv;
            *amt_slots[i] = amt;

            if ((player->attributes[(int)inv] < (float)(int)amt) && (can_afford != 0)) {
                short adjusted = (short)player->attributes[(int)inv];
                shortage = (short)(shortage + (amt - adjusted));
                *amt_slots[i] = adjusted;
            }
        }
    }

    if (shortage > 0) {
        if ((*inv_1 == 3) || (*inv_1 == -1)) {
            *inv_1 = 3;
            *amt_1 = (short)(*amt_1 + shortage);
        }
        else if ((*inv_2 == 3) || (*inv_2 == -1)) {
            *inv_2 = 3;
            *amt_2 = (short)(*amt_2 + shortage);
        }
        else if ((*inv_3 == 3) || (*inv_3 == -1)) {
            *inv_3 = 3;
            *amt_3 = (short)(*amt_3 + shortage);
        }
    }

    if (*amt_1 < 1) {
        *inv_1 = -1;
    }
    if (*amt_2 < 1) {
        *inv_2 = -1;
    }
    if (*amt_3 < 1) {
        *inv_3 = -1;
    }
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005131C0
void TRIBE_Player::interface_item_avail(Item_Avail** out_items, short* out_count, short button_location) {
    short available_count = 0;
    short include_town_center = 0;
    short i;
    short out_index;

    for (i = 0; i < this->master_object_num; ++i) {
        RGE_Master_Static_Object* master = this->master_objects[(int)i];
        if ((master != nullptr) && (master->master_type > 0x45) && (master->available != 0) &&
            (*(short*)((char*)master + 0x15c) == button_location)) {
            available_count++;
        }
    }

    if ((button_location == 0x76) && (this->attributes[0x30] == 0.0f) &&
        (this->master_objects[0x6d]->available == 0)) {
        include_town_center = 1;
        for (RGE_Object_Node* node = this->objects->list; node != nullptr; node = node->next) {
            if ((node->node != nullptr) && (node->node->master_obj->id == 0x6d)) {
                include_town_center = 0;
                break;
            }
        }
    }

    if (include_town_center != 0) {
        available_count++;
    }

    if (*out_items != nullptr) {
        free(*out_items);
        *out_items = nullptr;
    }

    *out_count = available_count;
    if (available_count == 0) {
        return;
    }

    *out_items = (Item_Avail*)calloc((int)available_count, sizeof(Item_Avail));

    out_index = 0;
    for (i = 0; i < this->master_object_num; ++i) {
        RGE_Master_Static_Object* master = this->master_objects[(int)i];
        if ((master != nullptr) && (master->master_type > 0x45) && (master->available != 0) &&
            (*(short*)((char*)master + 0x15c) == button_location)) {
            short inv_1, amt_1, inv_2, amt_2, inv_3, amt_3;
            (*out_items)[out_index].id = i;
            (*out_items)[out_index].pict = master->button_pict;
            (*out_items)[out_index].name = master->name;
            interface_obj_cost(this, i, &inv_1, &amt_1, &inv_2, &amt_2, &inv_3, &amt_3);
            (*out_items)[out_index].inventory_item_1 = inv_1;
            (*out_items)[out_index].inventory_cost_1 = (float)(int)amt_1;
            (*out_items)[out_index].inventory_item_2 = inv_2;
            (*out_items)[out_index].inventory_cost_2 = (float)(int)amt_2;
            (*out_items)[out_index].inventory_item_3 = inv_3;
            (*out_items)[out_index].inventory_cost_3 = (float)(int)amt_3;
            (*out_items)[out_index].help_string_id = master->get_help_message();
            (*out_items)[out_index].help_page_id = master->get_help_page();
            out_index++;
        }
    }

    if (include_town_center != 0) {
        RGE_Master_Static_Object* master = this->master_objects[0x6d];
        short inv_1, amt_1, inv_2, amt_2, inv_3, amt_3;
        (*out_items)[out_index].id = 0x6d;
        (*out_items)[out_index].pict = master->button_pict;
        (*out_items)[out_index].name = master->name;
        interface_obj_cost(this, 0x6d, &inv_1, &amt_1, &inv_2, &amt_2, &inv_3, &amt_3);
        (*out_items)[out_index].inventory_item_1 = inv_1;
        (*out_items)[out_index].inventory_cost_1 = (float)(int)amt_1;
        (*out_items)[out_index].inventory_item_2 = inv_2;
        (*out_items)[out_index].inventory_cost_2 = (float)(int)amt_2;
        (*out_items)[out_index].inventory_item_3 = inv_3;
        (*out_items)[out_index].inventory_cost_3 = (float)(int)amt_3;
        (*out_items)[out_index].help_string_id = master->get_help_message();
        (*out_items)[out_index].help_page_id = master->get_help_page();
    }
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005134F0
void TRIBE_Player::interface_trade_avail(Trade_Avail** out_items, short* out_count) {
    RGE_Static_Object* dock_list[96];
    int dock_count = 0;

    for (int player_index = 1; player_index < this->world->player_num; ++player_index) {
        if (player_index == this->id) {
            continue;
        }

        RGE_Player* other_player = this->world->players[player_index];
        for (RGE_Object_Node* node = other_player->objects->list; node != nullptr; node = node->next) {
            if ((node->node != nullptr) && (node->node->master_obj->id == 0x2d)) {
                int col = (int)node->node->world_x;
                int row = (int)node->node->world_y;
                if (this->visible->get_visible(col, row) != 0) {
                    dock_list[dock_count] = node->node;
                    dock_count++;
                }
            }
        }
    }

    if (*out_items != nullptr) {
        free(*out_items);
        *out_items = nullptr;
    }

    *out_count = (short)dock_count;
    if (dock_count == 0) {
        return;
    }

    *out_items = (Trade_Avail*)calloc(dock_count, sizeof(Trade_Avail));
    for (int i = 0; i < dock_count; ++i) {
        (*out_items)[i].dock = dock_list[i];
        (*out_items)[i].player = dock_list[i]->owner;
        (*out_items)[i].inventory = dock_list[i]->attribute_amount_held;
    }
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513720
uchar TRIBE_Player::command_building_make_tech(short tech_id) {
    if ((this->selected_obj != nullptr) && (this->selected_obj->master_obj->master_type == 'P')) {
        ((TRIBE_Command*)this->world->commands)->command_research(this->selected_obj, tech_id);
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513750
uchar TRIBE_Player::command_building_cancel() {
    if ((this->selected_obj != nullptr) && ((TRIBE_Player*)this->selected_obj->owner == this)) {
        uchar master_type = this->selected_obj->master_obj->master_type;
        if (((master_type == 'P') || (master_type == 'F')) && (this->selected_obj->master_obj->object_group != 1)) {
            ((TRIBE_Command*)this->world->commands)->command_cancel_build(this->selected_obj);
            return '\x01';
        }
    }
    return '\0';
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513790
uchar TRIBE_Player::command_delete_object(RGE_Static_Object* target) {
    if ((target != nullptr) && ((TRIBE_Player*)target->owner == this)) {
        uchar master_type = target->master_obj->master_type;
        if ((master_type == 'P') || (master_type == 'F')) {
            ((TRIBE_Command*)this->world->commands)->command_cancel_build(target);
            return '\x01';
        }
    }
    return '\0';
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005137D0
uchar TRIBE_Player::command_trade_attribute(long attribute_type) {
    RGE_Static_Object** list = nullptr;
    short list_num = 0;
    uchar ok = ((RGE_Player*)this)->get_selected_objects_to_command(&list, &list_num, 4, (short)-1, (short)-1, 5);
    if (ok != '\0') {
        list[0]->play_command_sound();
        ((TRIBE_Command*)this->world->commands)->command_trade_attribute(list, list_num, attribute_type);
        free(list);
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513840
uchar TRIBE_Player::command_trade_attribute(int player_id, long attribute_type) {
    ((TRIBE_Command*)this->world->commands)->command_trade_attribute(player_id, (int)this->id, attribute_type);
    return '\x01';
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513920
uchar TRIBE_Player::command_building_make_obj(short object_id) {
    if ((this->selected_obj != nullptr) && (this->selected_obj->master_obj->master_type == 'P')) {
        ((TRIBE_Command*)this->world->commands)->command_make(this->selected_obj, object_id);
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513D60
uchar TRIBE_Player::check_tech_cost(short tech_id, short* missing_attr) {
    return this->tech_tree->check_tech_cost(tech_id, missing_attr);
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00513D80
uchar TRIBE_Player::pay_tech_cost(short tech_id) {
    return this->tech_tree->start_research(tech_id, 1, nullptr);
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005145E0
void TRIBE_Player::researchCost(int tech_id, int unused, ResourceItem* resource_cost, int unused2) {
    short inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3;
    (void)unused;
    (void)unused2;

    this->tech_tree->tech_cost((short)tech_id, &inv_1, &inv_amt_1, &inv_2, &inv_amt_2, &inv_3, &inv_amt_3);
    resource_cost->incrementValue((int)inv_1, (int)inv_amt_1);
    resource_cost->incrementValue((int)inv_2, (int)inv_amt_2);
    resource_cost->incrementValue((int)inv_3, (int)inv_amt_3);
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00514660
int TRIBE_Player::objectAvailable(int object_id) {
    int iVar1 = (int)this->master_objects[object_id];
    if (((iVar1 == 0) || (*(char*)(iVar1 + 0x52) == '\0')) && (object_id != 0x6d)) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00514690
int TRIBE_Player::researchAvailable(int tech_id) {
    return (uint)(this->tech_tree->tech_player_tree[tech_id].state == 1);
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005146B0
int TRIBE_Player::researchEverAvailable(int tech_id) {
    short state = this->tech_tree->get_tech_state((short)tech_id);
    if ((state != 3) && (state != -1)) {
        return 1;
    }
    return 0;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005146E0
uchar TRIBE_Player::researchState(int tech_id) {
    return (uchar)this->tech_tree->get_tech_state((short)tech_id);
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00515DF0
int TRIBE_Player::intelligentCivSelection(int param_1, int param_2, int param_3) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    return 0;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00515E00
void TRIBE_Player::intelligentBuildListAndRulesSelection(char* build_list_name, char* rule_set_name, int map_type, int victory_type, int map_size) {
    if (this->playerAI == nullptr) {
        return;
    }

    TribeStrategyAIModule* strategy_ai = (TribeStrategyAIModule*)this->playerAI->strategyAI;
    TribeInformationAIModule* information_ai = (TribeInformationAIModule*)this->playerAI->informationAI;
    int build_lists[126];
    int most_built_unit_1 = -1;
    int most_built_unit_2 = -1;
    char civ_name[256];
    int iVar3;
    int iVar5;
    int iVar10;
    int iVar11;

    build_lists[0] = player_difficulty(this);
    for (int i = 0; i < 0x7d; ++i) {
        build_lists[i + 1] = 0;
    }

    switch (this->culture) {
    case 1:  this->setupEgyptian(build_lists + 1, map_type, victory_type, map_size); break;
    case 2:  this->setupGreek(build_lists + 1, map_type, victory_type, map_size); break;
    case 3:  this->setupBabylonian(build_lists + 1, map_type, victory_type, map_size); break;
    case 4:  this->setupAssyrian(build_lists + 1, map_type, victory_type, map_size); break;
    case 5:  this->setupMinoan(build_lists + 1, map_type, victory_type, map_size); break;
    case 6:  this->setupHittite(build_lists + 1, map_type, victory_type, map_size); break;
    case 7:  this->setupPhoenician(build_lists + 1, map_type, victory_type, map_size); break;
    case 8:  this->setupSumerian(build_lists + 1, map_type, victory_type, map_size); break;
    case 9:  this->setupPersian(build_lists + 1, map_type, victory_type, map_size); break;
    case 10: this->setupShang(build_lists + 1, map_type, victory_type, map_size); break;
    case 11: this->setupYamato(build_lists + 1, map_type, victory_type, map_size); break;
    case 12: this->setupChoson(build_lists + 1, map_type, victory_type, map_size); break;
    case 13: this->setupRoman(build_lists + 1, map_type, victory_type, map_size); break;
    case 14: this->setupCarthaginian(build_lists + 1, map_type, victory_type, map_size); break;
    case 15: this->setupPalmyran(build_lists + 1, map_type, victory_type, map_size); break;
    case 16: this->setupMacedonian(build_lists + 1, map_type, victory_type, map_size); break;
    }

    if ((((TRIBE_Game*)rge_base_game)->deathMatch() == '\0') &&
        ((this->culture == 4) || (this->culture == 1) || (this->culture == 2) || (this->culture == 5) ||
         (this->culture == 9) || (this->culture == 7) || (this->culture == 8) || (this->culture == 11))) {
        if (map_type == 0) {
            if (DAT_00886c44 < 1) {
                build_lists[0xe] = 0;
                build_lists[0xf] = 0;
            } else if (DAT_00886c48 == 0) {
                build_lists[0xe] = build_lists[0xe] + 300;
                build_lists[0xf] = build_lists[0xf] + 300;
            } else {
                build_lists[0xe] = build_lists[0xe] + 100;
                build_lists[0xf] = build_lists[0xf] + 100;
            }
        }
        if (map_type == 1) {
            if (DAT_00886c44 < 1) {
                build_lists[0xe] = 0;
                build_lists[0xf] = 0;
            } else if (DAT_00886c48 == 0) {
                build_lists[0xe] = build_lists[0xe] + 0xfa;
                build_lists[0xf] = build_lists[0xf] + 0xfa;
            } else {
                build_lists[0xe] = build_lists[0xe] + 0x4b;
                build_lists[0xf] = build_lists[0xf] + 0x4b;
            }
        }
        if ((map_type == 2) || (map_type == 6) || (map_type == 8)) {
            if (DAT_00886c44 < 1) {
                build_lists[0xe] = 0;
                build_lists[0xf] = 0;
            } else if (DAT_00886c48 == 0) {
                build_lists[0xe] = build_lists[0xe] + 200;
                build_lists[0xf] = build_lists[0xf] + 200;
            } else {
                build_lists[0xe] = build_lists[0xe] + 0x32;
                build_lists[0xf] = build_lists[0xf] + 0x32;
            }
        }
    }

    strategy_ai->setRule(0xc9, 1);

    if (((TRIBE_Game*)rge_base_game)->deathMatch() == '\0') {
        loadUnitHistoryParity(information_ai);
        unitsThatAreMostBuiltParity(information_ai, &most_built_unit_1, &most_built_unit_2);

        switch (most_built_unit_1) {
        case 0:
            build_lists[7] = build_lists[7] + 0x19;
            build_lists[8] = build_lists[8] + 0x19;
            break;
        case 1:
            build_lists[7] = build_lists[7] + 0x1e;
            build_lists[8] = build_lists[8] + 0x1e;
            break;
        case 2:
            build_lists[0x13] = build_lists[0x13] + 0x14;
            build_lists[0x12] = build_lists[0x12] + 0x14;
            build_lists[4] = build_lists[4] + 0x28;
            build_lists[5] = build_lists[5] + 0x28;
            break;
        case 3:
            build_lists[1] = build_lists[1] + 0x28;
            build_lists[0x12] = build_lists[0x12] + -0x3c;
            build_lists[0x13] = build_lists[0x13] + -0x3c;
            build_lists[2] = build_lists[2] + 0x14;
            build_lists[0x14] = build_lists[0x14] + 0x14;
            build_lists[0x15] = build_lists[0x15] + 0x14;
            break;
        case 4:
            build_lists[7] = build_lists[7] + 0xf;
            build_lists[8] = build_lists[8] + 0xf;
            build_lists[0x15] = build_lists[0x15] + 0x14;
            build_lists[0x14] = build_lists[0x14] + 0x14;
            break;
        case 5:
            build_lists[7] = build_lists[7] + 0xf;
            build_lists[8] = build_lists[8] + 0xf;
            build_lists[1] = build_lists[1] + 10;
            build_lists[2] = build_lists[2] + 10;
            break;
        case 6:
            build_lists[7] = build_lists[7] + 0xf;
            build_lists[8] = build_lists[8] + 0xf;
            break;
        case 7:
        case 10:
            build_lists[0x15] = build_lists[0x15] - 0x3c;
            build_lists[0x14] = build_lists[0x14] - 0x3c;
            break;
        case 8:
            build_lists[0x14] = build_lists[0x14] + 0x28;
            build_lists[0x15] = build_lists[0x15] + 0x28;
            if (0 < DAT_00886c44) {
                build_lists[0xe] = build_lists[0xe] + 0x32;
                build_lists[0xf] = build_lists[0xf] + 0x32;
            }
            break;
        case 9:
            build_lists[0x15] = build_lists[0x15] + 100;
            build_lists[0x14] = build_lists[0x14] + 100;
            break;
        }
    }

    for (int difficulty_level = 0; difficulty_level < 7; ++difficulty_level) {
        switch (difficulty_level) {
        case 0:
            if (0 < build_lists[0x14]) { build_lists[0x14] = build_lists[0x14] / 3; }
            if (0 < build_lists[0x15]) { build_lists[0x15] = build_lists[0x15] / 3; }
            if (0 < build_lists[0x16]) { build_lists[0x16] = build_lists[0x16] / 3; }
            break;
        case 1:
            if (0 < build_lists[7]) { build_lists[7] = build_lists[7] / 3; }
            if (0 < build_lists[8]) { build_lists[8] = build_lists[8] / 3; }
            if (0 < build_lists[9]) { build_lists[9] = build_lists[9] / 3; }
            if (0 < build_lists[0x3c]) { build_lists[0x3c] = build_lists[0x3c] / 3; }
            if (0 < build_lists[0x3b]) { build_lists[0x3b] = build_lists[0x3b] / 3; }
            if (0 < build_lists[0x37]) { build_lists[0x37] = build_lists[0x37] / 3; }
            if (0 < build_lists[0x38]) { build_lists[0x38] = build_lists[0x38] / 3; }
            if (0 < build_lists[0x69]) { build_lists[0x69] = build_lists[0x69] / 3; }
            break;
        case 2:
            if (0 < build_lists[0x11]) { build_lists[0x11] = build_lists[0x11] / 3; }
            if (0 < build_lists[0x32]) { build_lists[0x32] = build_lists[0x32] / 3; }
            if (0 < build_lists[0x6d]) { build_lists[0x6d] = build_lists[0x6d] / 3; }
            break;
        case 3:
            if (0 < build_lists[0x2f]) { build_lists[0x2f] = build_lists[0x2f] / 3; }
            if (0 < build_lists[0x36]) { build_lists[0x36] = build_lists[0x36] / 3; }
            if (0 < build_lists[0x12]) { build_lists[0x12] = build_lists[0x12] / 3; }
            if (0 < build_lists[0x13]) { build_lists[0x13] = build_lists[0x13] / 3; }
            if (0 < build_lists[100]) { build_lists[100] = build_lists[100] / 3; }
            if (0 < build_lists[0x67]) { build_lists[0x67] = build_lists[0x67] / 3; }
            if (0 < build_lists[0x6e]) { build_lists[0x6e] = build_lists[0x6e] / 3; }
            if (0 < build_lists[0x13]) { build_lists[0x13] = build_lists[0x13] / 3; }
            break;
        case 4:
            if (0 < build_lists[4]) { build_lists[4] = build_lists[4] / 3; }
            if (0 < build_lists[5]) { build_lists[5] = build_lists[5] / 3; }
            if (0 < build_lists[6]) { build_lists[6] = build_lists[6] / 3; }
            if (0 < build_lists[10]) { build_lists[10] = build_lists[10] / 3; }
            if (0 < build_lists[0xb]) { build_lists[0xb] = build_lists[0xb] / 3; }
            if (0 < build_lists[0xc]) { build_lists[0xc] = build_lists[0xc] / 3; }
            if (0 < build_lists[0xd]) { build_lists[0xd] = build_lists[0xd] / 3; }
            if (0 < build_lists[0x2b]) { build_lists[0x2b] = build_lists[0x2b] / 3; }
            if (0 < build_lists[0x2d]) { build_lists[0x2d] = build_lists[0x2d] / 3; }
            if (0 < build_lists[0x2e]) { build_lists[0x2e] = build_lists[0x2e] / 3; }
            if (0 < build_lists[0x30]) { build_lists[0x30] = build_lists[0x30] / 3; }
            if (0 < build_lists[0x31]) { build_lists[0x31] = build_lists[0x31] / 3; }
            if (0 < build_lists[0x39]) { build_lists[0x39] = build_lists[0x39] / 3; }
            if (0 < build_lists[0x4b]) { build_lists[0x4b] = build_lists[0x4b] / 3; }
            if (0 < build_lists[99]) { build_lists[99] = build_lists[99] / 3; }
            if (0 < build_lists[0x68]) { build_lists[0x68] = build_lists[0x68] / 3; }
            if (0 < build_lists[0x71]) { build_lists[0x71] = build_lists[0x71] / 3; }
            if (0 < build_lists[0x72]) { build_lists[0x72] = build_lists[0x72] / 3; }
            break;
        case 5:
            if (0 < build_lists[0x2a]) { build_lists[0x2a] = build_lists[0x2a] / 3; }
            if (0 < build_lists[1]) { build_lists[1] = build_lists[1] / 3; }
            if (0 < build_lists[2]) { build_lists[2] = build_lists[2] / 3; }
            if (0 < build_lists[3]) { build_lists[3] = build_lists[3] / 3; }
            if (0 < build_lists[0x2a]) { build_lists[0x2a] = build_lists[0x2a] / 3; }
            if (0 < build_lists[0x33]) { build_lists[0x33] = build_lists[0x33] / 3; }
            if (0 < build_lists[0x34]) { build_lists[0x34] = build_lists[0x34] / 3; }
            if (0 < build_lists[0x49]) { build_lists[0x49] = build_lists[0x49] / 3; }
            if (0 < build_lists[0x4a]) { build_lists[0x4a] = build_lists[0x4a] / 3; }
            if (0 < build_lists[0x33]) { build_lists[0x33] = build_lists[0x33] / 3; }
            if (0 < build_lists[0x34]) { build_lists[0x34] = build_lists[0x34] / 3; }
            if (0 < build_lists[0x51]) { build_lists[0x51] = build_lists[0x51] / 3; }
            if (0 < build_lists[0x52]) { build_lists[0x52] = build_lists[0x52] / 3; }
            if (0 < build_lists[0x53]) { build_lists[0x53] = build_lists[0x53] / 3; }
            if (0 < build_lists[0x6c]) { build_lists[0x6c] = build_lists[0x6c] / 3; }
            break;
        case 6:
            if (0 < build_lists[0x29]) { build_lists[0x29] = build_lists[0x29] / 3; }
            if (0 < build_lists[0x3a]) { build_lists[0x3a] = build_lists[0x3a] / 3; }
            if (0 < build_lists[0x73]) { build_lists[0x73] = build_lists[0x73] / 3; }
            if (0 < build_lists[0x55]) { build_lists[0x55] = build_lists[0x55] / 3; }
            break;
        }
    }

    for (int i = 1; i <= 0x7d; ++i) {
        if (build_lists[i] < 0) {
            build_lists[i] = 0;
        }
    }

    int total_weight = 0;
    for (int i = 1; i <= 0x7d; ++i) {
        total_weight = total_weight + build_lists[i];
    }

    int random_value = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xc41);
    int cumulative_weight = 0;
    int selected_build_list = 0;
    int index = 0;
    while (index < 0x7d) {
        cumulative_weight = cumulative_weight + build_lists[index + 1];
        int selected_index = index;
        if ((random_value % total_weight) < cumulative_weight) {
            selected_build_list = selected_index;
            break;
        }
        index = index + 1;
        selected_build_list = 0;
    }

    rge_base_game->get_string((long)(selected_build_list + 0x26930), build_list_name, 0x100);

    bool skip_default_increment = false;
    switch (selected_build_list) {
    case 0:
    case 1:
    case 2:
    case 0x29:
    case 0x32:
    case 0x33:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x6b:
        DAT_00886c2c = DAT_00886c2c + 1;
        break;
    case 6:
    case 7:
    case 8:
    case 0x2b:
    case 0x36:
    case 0x37:
    case 0x3a:
    case 0x3b:
    case 0x68:
        DAT_00886c1c = DAT_00886c1c + 1;
        break;
    case 0xd:
    case 0xe:
    case 0xf:
        strategy_ai->setRule(0x3b, 4);
        strategy_ai->setRule(0x3c, 10);
        DAT_00886c34 = DAT_00886c34 + 1;
        DAT_00886c48 = DAT_00886c48 + 1;
        skip_default_increment = true;
        break;
    case 0x10:
    case 0x31:
    case 0x6c:
        DAT_00886c20 = DAT_00886c20 + 1;
        break;
    case 0x11:
    case 0x12:
    case 0x2e:
    case 0x34:
    case 0x35:
    case 99:
    case 0x66:
    case 0x6d:
        DAT_00886c24 = DAT_00886c24 + 1;
        break;
    case 0x13:
    case 0x14:
    case 0x15:
        computerPlayerSetup[0] = computerPlayerSetup[0] + 1;
        break;
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
        break;
    case 0x28:
    case 0x39:
    case 0x54:
    case 0x72:
        DAT_00886c30 = DAT_00886c30 + 1;
        break;
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x53:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x61:
    case 100:
    case 0x65:
    case 0x69:
    case 0x6a:
    case 0x6e:
    case 0x6f:
    case 0x73:
    case 0x74:
    case 0x79:
    case 0x7a:
    case 0x7b:
    case 0x7c:
        DAT_00886c48 = DAT_00886c48 + 1;
        skip_default_increment = true;
        break;
    case 0x48:
    case 0x49:
        DAT_00886c44 = DAT_00886c44 + 1;
        DAT_00886c2c = DAT_00886c2c + 1;
        skip_default_increment = true;
        break;
    case 0x4a:
        DAT_00886c44 = DAT_00886c44 + 1;
        DAT_00886c28 = DAT_00886c28 + 1;
        skip_default_increment = true;
        break;
    default:
        DAT_00886c28 = DAT_00886c28 + 1;
        break;
    }

    if (!skip_default_increment) {
        DAT_00886c44 = DAT_00886c44 + 1;
    }

    rge_base_game->get_string((long)this->culture + 0x27f6, civ_name, 0x100);
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"I am the %s civ (culture #%d):", civ_name, (int)this->culture - 1);
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Selected a best build list of '%s'.", build_list_name);
    strcpy(rule_set_name, "RandomGameSpecialized");
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting AI Personality:");

    iVar10 = most_built_unit_2;
    switch (most_built_unit_1) {
    case 0:
    case 1:
        strategy_ai->setRule(0x36, 5);
        strategy_ai->setRule(0x37, 5);
        iVar10 = most_built_unit_2;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        iVar10 = strategy_ai->rule(1);
        if (iVar10 < 1) {
            strategy_ai->setRule(0, 0x32);
            iVar10 = 0x32;
        } else {
            strategy_ai->setRule(0, 0x32);
            strategy_ai->setRule(1, 0x19);
            iVar10 = 0x19;
        }
        strategy_ai->setRule(2, iVar10);
        if (1 < most_built_unit_2) {
            strategy_ai->setRule(3, 5);
        }
        strategy_ai->setRule(0x2a, 2);
        strategy_ai->setRule(0x3d, 2);
        iVar10 = most_built_unit_2;
        if (most_built_unit_1 != 2) {
            strategy_ai->setRule(0x26, build_lists[0] + 1);
            strategy_ai->setRule(0x24, 1);
            strategy_ai->setRule(0x36, most_built_unit_1 == 3 ? 1 : 5);
            strategy_ai->setRule(0x37, most_built_unit_1 == 4 ? 1 : 5);
        }
        break;
    }

    if (((TRIBE_Game*)rge_base_game)->deathMatch() == '\x01') {
        strategy_ai->setRule(4, 10);
    }

    iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe3a);
    iVar5 = (iVar5 % 0xc + 0x1c) * 0x3c;
    switch (selected_build_list) {
    case 0:
    case 3:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0x13:
    case 0x2f:
    case 0x30:
    case 0x33:
    case 0x37:
    case 0x39:
    case 0x48:
    case 0x4a:
    case 0x4b:
    case 0x4e:
    case 0x51:
    case 0x55:
    case 0x58:
    case 0x5a:
    case 0x5e:
    case 0x60:
    case 100:
    case 0x69:
    case 0x6e:
    case 0x73:
        DAT_00886c3c = DAT_00886c3c + 1;
        iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe58);
        iVar5 = (iVar5 % 6 + 0x14) * 0x3c;
        break;
    case 9:
    case 0x38:
        iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe69);
        iVar5 = (signed_mask_mod(iVar5, 1) + 5) * 0x3c;
        DAT_00886c38 = DAT_00886c38 + 1;
        break;
    case 10:
    case 0x29:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x32:
    case 0x3a:
    case 0x71:
        DAT_00886c38 = DAT_00886c38 + 1;
        iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe64);
        iVar5 = (signed_mask_mod(iVar5, 3) + 0xb) * 0x3c;
        break;
    default:
        DAT_00886c40 = DAT_00886c40 + 1;
        break;
    }

    iVar11 = build_lists[0];
    if ((build_lists[0] == 0) && (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe73) % 3 == 0)) {
        iVar5 = iVar5 - 300;
    }

    strategy_ai->setRule(0x68, iVar5);
    strategy_ai->setRule(0x10, 2);
    strategy_ai->setRule(0x1a, 10);
    strategy_ai->setRule(0x5d, 1);
    strategy_ai->setRule(99, 4);

    iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe80);
    strategy_ai->setRule(0xbc, (int)(iVar5 % 3 != 0));

    iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe86);
    strategy_ai->setRule(0xc3, iVar5 % 0x28 + 10);

    iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe8a);
    strategy_ai->setRule(0xbd, iVar5 % 0x46 + 0x1e);

    iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe8e);
    strategy_ai->setRule(0xc6, (iVar5 % 5 + 5) * build_lists[0]);

    iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xe92);
    strategy_ai->setRule(199, (iVar5 % 10 + 10) * build_lists[0]);
    strategy_ai->setRule(0xa1, 4);

    iVar5 = build_lists[0];
    if (iVar10 == 0) {
        iVar5 = iVar5 - 2;
    } else if (iVar10 == 1) {
        iVar5 = iVar5 - 1;
    }

    switch (iVar5) {
    case 0:
        iVar3 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xea7);
        strategy_ai->setRule(0x49, signed_mask_mod(iVar3, 1) + 0xf);
        iVar3 = strategy_ai->rule(0x49);
        iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xea9);
        iVar3 = iVar3 + 1 + signed_mask_mod(iVar5, 3);
        break;
    case 1: {
        iVar3 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xeac);
        strategy_ai->setRule(0x49, iVar3 % 3 + 0x10);
        iVar3 = strategy_ai->rule(0x49);
        int temp = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xeae);
        iVar3 = iVar3 + 1 + (temp % 5);
        break;
    }
    case 2: {
        iVar3 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xeb1);
        strategy_ai->setRule(0x49, signed_mask_mod(iVar3, 1) + 0x11);
        iVar3 = strategy_ai->rule(0x49);
        int temp = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xeb3);
        iVar3 = iVar3 + 1 + (temp % 6);
        break;
    }
    case 3: {
        iVar3 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xeb6);
        strategy_ai->setRule(0x49, signed_mask_mod(iVar3, 1) + 0x12);
        iVar3 = strategy_ai->rule(0x49);
        int temp = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xeb8);
        iVar3 = iVar3 + 1 + (temp % 7);
        break;
    }
    case 4:
        iVar3 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xebb);
        strategy_ai->setRule(0x49, signed_mask_mod(iVar3, 3) + 0x12);
        iVar3 = strategy_ai->rule(0x49);
        iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xebd);
        iVar3 = iVar3 + 1 + signed_mask_mod(iVar5, 7);
        break;
    case -2:
    case -1:
        iVar3 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xea2);
        strategy_ai->setRule(0x49, signed_mask_mod(iVar3, 1) + 0xe);
        iVar3 = strategy_ai->rule(0x49);
        iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xea4);
        iVar3 = iVar3 + 1 + signed_mask_mod(iVar5, 3);
        break;
    default: {
        iVar3 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xec1);
        strategy_ai->setRule(0x49, signed_mask_mod(iVar3, 1) + 0x12);
        iVar3 = strategy_ai->rule(0x49);
        int temp = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xec3);
        iVar3 = iVar3 + 1 + (temp % 9);
        break;
    }
    }

    strategy_ai->setRule(0x4a, iVar3);
    strategy_ai->setRule(0xd0, 1);
    strategy_ai->setRule(0xd1, 1);
    strategy_ai->setRule(0xd2, 1);
    strategy_ai->setRule(0xdf, 1);

    if (iVar10 == 0) {
        strategy_ai->setRule(0xd4, 3);
        strategy_ai->setRule(0xd5, 6);
        strategy_ai->setRule(0xd6, 2);
        strategy_ai->setRule(0xe0, 6);
    } else if (iVar10 == 1) {
        strategy_ai->setRule(0xd4, 2);
        strategy_ai->setRule(0xd5, 5);
        strategy_ai->setRule(0xd6, 2);
        strategy_ai->setRule(0xe0, 4);
    } else if ((iVar10 == 2) || (iVar10 == 6) || (iVar10 == 5) || (iVar10 == 8)) {
        strategy_ai->setRule(0xd4, 1);
        strategy_ai->setRule(0xd5, 4);
        strategy_ai->setRule(0xd6, 1);
        strategy_ai->setRule(0xe0, 3);
    } else if ((iVar10 == 3) || (iVar10 == 4) || (iVar10 == 7)) {
        strategy_ai->setRule(0xd4, 0);
        strategy_ai->setRule(0xd5, 0);
        strategy_ai->setRule(0xd6, 0);
        strategy_ai->setRule(0xe0, 0);
    }

    if (allowAIToCheat != 0) {
        int wood = 0;
        int food = 0;
        int gold = 0;
        int stone = 0;
        if (iVar11 == 0) {
            wood = 2000;
            food = 2000;
            gold = 2000;
            stone = 2000;
        }
        strategy_ai->setRule(0x8a, wood);
        strategy_ai->setRule(0x8b, food);
        strategy_ai->setRule(0x8c, gold);
        strategy_ai->setRule(0x8d, stone);
    }

    strategy_ai->setRule(0xa8, 0);
    strategy_ai->setRule(0xa2, 0);

    if (iVar11 < 3) {
        strategy_ai->setRule(0xc2, 1);
        iVar10 = 2;
    } else {
        strategy_ai->setRule(0xc2, 0);
        iVar10 = 1;
    }
    strategy_ai->setRule(0x2f, iVar10);

    if (iVar11 == 0) {
        strategy_ai->setRule(0xba, 0xb4);
        iVar11 = 200;
    } else if (iVar11 == 1) {
        strategy_ai->setRule(0xba, 0xb4);
        iVar11 = 0x96;
    } else if (iVar11 == 2) {
        strategy_ai->setRule(0xba, 0xb4);
        iVar11 = 100;
    } else if (iVar11 == 3) {
        strategy_ai->setRule(0xba, 0xb4);
        iVar11 = 0x32;
    }
    if (iVar11 == 200 || iVar11 == 0x96 || iVar11 == 100 || iVar11 == 0x32) {
        strategy_ai->setRule(0xba, iVar11);
    }

    iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xf50);
    strategy_ai->setRule(0xb5, (int)(iVar5 % 6 < 5));

    iVar5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0xf56);
    strategy_ai->setRule(0xb6, (int)(iVar5 % 3 < 1));
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00517B90
void TRIBE_Player::setupEgyptian(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Egyptians.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        if (player_difficulty(this) < 1) {
            build_lists[0x23] = 100;
            return;
        }
        build_lists[3] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0x11] = 0x28;
        build_lists[0x12] = 0x28;
        build_lists[0x2e] = 100;
        build_lists[0x13] = 0x32;
        build_lists[0x14] = 0x32;
        build_lists[0x2f] = 100;
        build_lists[0x50] = 100;
        build_lists[0x51] = 0x1e;
        build_lists[0x52] = 0x14;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x53] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x53] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x3f] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x19] = 0x3c;
        build_lists[0x3f] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x19] = 0x50;
        build_lists[0x3f] = 0x14;
        return;
    }
    build_lists[0x19] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00517CD0
void TRIBE_Player::setupGreek(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Greeks.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        if (player_difficulty(this) < 1) {
            build_lists[0x24] = 100;
            return;
        }
        build_lists[6] = 0x1e;
        build_lists[0xb] = 0x1e;
        build_lists[0x14] = 0x1e;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[3] = 0x46;
        build_lists[4] = 0x32;
        build_lists[7] = 0x14;
        build_lists[0x13] = 0x32;
        build_lists[0x30] = 100;
        build_lists[0x54] = 100;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x55] = 200;
            build_lists[0x56] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x55] = 100;
            build_lists[0x56] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x40] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x1a] = 0x3c;
        build_lists[0x40] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x1a] = 0x50;
        build_lists[0x40] = 0x14;
        return;
    }
    build_lists[0x1a] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00517E10
void TRIBE_Player::setupBabylonian(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Babylonians.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[1] = 10;
        build_lists[6] = 10;
        build_lists[9] = 10;
        build_lists[0xb] = 10;
        build_lists[0] = 0x14;
        build_lists[0x13] = 0x28;
        build_lists[0x14] = 0x28;
        build_lists[0x10] = 0x1e;
        build_lists[0x2a] = 100;
        build_lists[0x2b] = 100;
        build_lists[3] = 0x14;
        build_lists[10] = 0x14;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x4d] = 0x3c;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x4d] = 0x1e;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x3d] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x17] = 0x3c;
        build_lists[0x3d] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x17] = 0x50;
        build_lists[0x3d] = 0x14;
        return;
    }
    build_lists[0x17] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00517F30
void TRIBE_Player::setupAssyrian(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Assyrians.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        if (player_difficulty(this) < 1) {
            build_lists[0x22] = 100;
            return;
        }
        build_lists[3] = 10;
        build_lists[7] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0x14] = 10;
        build_lists[0x48] = 0x50;
        build_lists[0x49] = 0x50;
        build_lists[0x4a] = 0x50;
        build_lists[0x10] = 0x28;
        build_lists[0xb] = 0x28;
        build_lists[6] = 0x14;
        build_lists[0x13] = 0x14;
        build_lists[0x28] = 100;
        build_lists[0x29] = 100;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x4b] = 100;
            build_lists[0x4c] = 100;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x4b] = 0x32;
            build_lists[0x4c] = 0x32;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x3c] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x16] = 0x3c;
        build_lists[0x3c] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x16] = 0x50;
        build_lists[0x3c] = 0x14;
        return;
    }
    build_lists[0x16] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00518090
void TRIBE_Player::setupMinoan(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Minoans.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        if (player_difficulty(this) < 1) {
            build_lists[0x25] = 100;
            return;
        }
        build_lists[4] = 10;
        build_lists[6] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0xb] = 10;
        build_lists[0] = 0x3c;
        build_lists[1] = 0x50;
        build_lists[3] = 0x14;
        build_lists[0x33] = 100;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x58] = 200;
            build_lists[0x59] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x58] = 100;
            build_lists[0x59] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x42] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x1c] = 0x3c;
        build_lists[0x42] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x1c] = 0x50;
        build_lists[0x42] = 0x14;
        return;
    }
    build_lists[0x1c] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005181C0
void TRIBE_Player::setupHittite(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Hittites.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[4] = 0x28;
        build_lists[0x12] = 0x28;
        build_lists[0x10] = 0x50;
        build_lists[0x31] = 100;
        build_lists[0x32] = 100;
        build_lists[3] = 0x1e;
        build_lists[6] = 0x14;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0xb] = 10;
        build_lists[0x11] = 0x14;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x57] = 0xa0;
            build_lists[0] = 0x14;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x57] = 0x50;
            build_lists[0] = 10;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x41] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x1b] = 0x3c;
        build_lists[0x41] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x1b] = 0x50;
        build_lists[0x41] = 0x14;
        return;
    }
    build_lists[0x1b] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005182E0
void TRIBE_Player::setupPhoenician(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Phoenicians.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[3] = 10;
        build_lists[4] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0xb] = 10;
        build_lists[0x11] = 0x46;
        build_lists[0x12] = 0x46;
        build_lists[0] = 0x14;
        build_lists[6] = 0x14;
        build_lists[0x13] = 0x14;
        build_lists[1] = 0x28;
        build_lists[0x14] = 0x1e;
        build_lists[0x35] = 100;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x5c] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x5c] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x44] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x1e] = 0x3c;
        build_lists[0x44] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x1e] = 0x50;
        build_lists[0x44] = 0x14;
        return;
    }
    build_lists[0x1e] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00518400
void TRIBE_Player::setupSumerian(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Sumerians.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        if (player_difficulty(this) < 1) {
            build_lists[0x26] = 100;
            return;
        }
        build_lists[3] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0xb] = 10;
        build_lists[4] = 0x14;
        build_lists[0x11] = 0x14;
        build_lists[0x10] = 0x1e;
        build_lists[0x39] = 100;
        build_lists[0x3a] = 100;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x5e] = 200;
            build_lists[0x5f] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x5e] = 100;
            build_lists[0x5f] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x46] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x20] = 0x3c;
        build_lists[0x46] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x20] = 0x50;
        build_lists[0x46] = 0x14;
        return;
    }
    build_lists[0x20] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00518540
void TRIBE_Player::setupPersian(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Persians.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[6] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0x11] = 0x3c;
        build_lists[0x12] = 0x3c;
        build_lists[1] = 0x28;
        build_lists[0xb] = 0x28;
        build_lists[0x14] = 0x28;
        build_lists[0] = 0x14;
        build_lists[0x10] = 0x14;
        build_lists[7] = 0x32;
        build_lists[0x13] = 0x14;
        build_lists[0x34] = 100;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x5a] = 200;
            build_lists[0x5b] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x5a] = 100;
            build_lists[0x5b] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x43] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x1d] = 0x3c;
        build_lists[0x43] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x1d] = 0x50;
        build_lists[0x43] = 0x14;
        return;
    }
    build_lists[0x1d] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00518670
void TRIBE_Player::setupShang(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Shang.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[0] = 10;
        build_lists[3] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[6] = 0x32;
        build_lists[7] = 0x32;
        build_lists[0x38] = 0x32;
        build_lists[0xb] = 0x1e;
        build_lists[0x14] = 0x1e;
        build_lists[1] = 0x14;
        build_lists[0x10] = 0x14;
        build_lists[0x13] = 0x14;
        build_lists[0x36] = 100;
        build_lists[0x37] = 100;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x5d] = 0xa0;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x5d] = 0x50;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x45] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x1f] = 0x3c;
        build_lists[0x45] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x1f] = 0x50;
        build_lists[0x45] = 0x14;
        return;
    }
    build_lists[0x1f] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005187A0
void TRIBE_Player::setupYamato(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Yamato.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        if (player_difficulty(this) < 1) {
            build_lists[0x27] = 100;
            return;
        }
        build_lists[3] = 10;
        build_lists[4] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[6] = 0x32;
        build_lists[7] = 0x32;
        build_lists[0] = 0x14;
        build_lists[1] = 0x14;
        build_lists[0x10] = 0x28;
        build_lists[0xb] = 0x14;
        build_lists[0x3b] = 100;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x60] = 200;
            build_lists[0x61] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x60] = 100;
            build_lists[0x61] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x47] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x21] = 0x3c;
        build_lists[0x47] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x21] = 0x50;
        build_lists[0x47] = 0x14;
        return;
    }
    build_lists[0x21] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x005188F0
void TRIBE_Player::setupChoson(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Choson.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[1] = 10;
        build_lists[0x10] = 10;
        build_lists[3] = 10;
        build_lists[7] = 0x1e;
        build_lists[9] = 0x1e;
        build_lists[10] = 0x1e;
        build_lists[0] = 0x14;
        build_lists[6] = 0x14;
        build_lists[0xb] = 0x46;
        build_lists[0x13] = 0x32;
        build_lists[0x14] = 0x5a;
        build_lists[0x2c] = 100;
        build_lists[0x2d] = 100;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x4e] = 200;
            build_lists[0x4f] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x4e] = 100;
            build_lists[0x4f] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x3e] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x18] = 0x3c;
        build_lists[0x3e] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x18] = 0x50;
        build_lists[0x3e] = 0x14;
        return;
    }
    build_lists[0x18] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00518A20
void TRIBE_Player::setupRoman(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Roman.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[0] = 10;
        build_lists[6] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0x13] = 10;
        build_lists[0x14] = 10;
        build_lists[3] = 0x14;
        build_lists[4] = 0x14;
        build_lists[0xb] = 0x50;
        build_lists[0x70] = 100;
        build_lists[0x71] = 0x3c;
        build_lists[0x72] = 0x50;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x73] = 200;
            build_lists[0x74] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x73] = 100;
            build_lists[0x74] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x7c] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x78] = 0x3c;
        build_lists[0x7c] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x78] = 0x50;
        build_lists[0x7c] = 0x14;
        return;
    }
    build_lists[0x78] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00518B50
void TRIBE_Player::setupCarthaginian(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Carthaginian.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[0] = 10;
        build_lists[1] = 10;
        build_lists[0x10] = 10;
        build_lists[7] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0xb] = 10;
        build_lists[0x11] = 0x3c;
        build_lists[0x12] = 0x3c;
        build_lists[3] = 0x46;
        build_lists[0x62] = 0x50;
        build_lists[99] = 0x50;
        build_lists[4] = 0x32;
        build_lists[6] = 0x1e;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[100] = 200;
            build_lists[0x65] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[100] = 100;
            build_lists[0x65] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x79] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x75] = 0x3c;
        build_lists[0x79] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x75] = 0x50;
        build_lists[0x79] = 0x14;
        return;
    }
    build_lists[0x75] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00518C90
void TRIBE_Player::setupPalmyran(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Palmyran.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[3] = 0x28;
        build_lists[6] = 0x28;
        build_lists[0] = 0x1e;
        build_lists[7] = 10;
        build_lists[9] = 10;
        build_lists[10] = 10;
        build_lists[0xb] = 10;
        build_lists[1] = 0x1e;
        build_lists[0x6b] = 0x50;
        build_lists[0x6c] = 0x50;
        build_lists[0x6d] = 0x50;
        build_lists[0x10] = 0x3c;
        build_lists[4] = 0x14;
        build_lists[0x11] = 0x3c;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x6e] = 200;
            build_lists[0x6f] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x6e] = 100;
            build_lists[0x6f] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x7b] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x77] = 0x3c;
        build_lists[0x7b] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x77] = 0x50;
        build_lists[0x7b] = 0x14;
        return;
    }
    build_lists[0x77] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00518DD0
void TRIBE_Player::setupMacedonian(int* build_lists, int map_type, int victory_type, int map_size) {
    (void)victory_type;
    (void)map_size;
    ((AIModule*)this->playerAI)->logCommonHistory((char*)"Setting up as Macedonian.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() != '\x01') {
        build_lists[3] = 0x28;
        build_lists[4] = 0x28;
        build_lists[0] = 10;
        build_lists[6] = 0x1e;
        build_lists[7] = 0x1e;
        build_lists[0x11] = 0x1e;
        build_lists[0x68] = 0x50;
        build_lists[0x66] = 0x50;
        build_lists[0x67] = 0x50;
        build_lists[1] = 10;
        build_lists[0x10] = 0x14;
        if ((map_type == 0) || (map_type == 1)) {
            build_lists[0x69] = 200;
            build_lists[0x6a] = 200;
        }
        else if (((map_type == 2) || (map_type == 6)) || ((map_type == 8) || (map_type == 5))) {
            build_lists[0x69] = 100;
            build_lists[0x6a] = 100;
        }
        return;
    }

    if ((map_type == 0) || (map_type == 1)) {
        build_lists[0x7a] = 100;
        return;
    }
    if ((map_type == 2) || (map_type == 6)) {
        build_lists[0x76] = 0x3c;
        build_lists[0x7a] = 0x28;
        return;
    }
    if ((map_type == 5) || (map_type == 8)) {
        build_lists[0x76] = 0x50;
        build_lists[0x7a] = 0x14;
        return;
    }
    build_lists[0x76] = 100;
}

// Fully verified. Source of truth: tplayer.cpp.decomp @ 0x00519320
void TRIBE_Player::get_achievement(uchar achievement_id, char* out_text) {
    float value;

    switch (achievement_id) {
    case '\0':
        strcpy(out_text, this->name);
        return;
    case '\x01':
        value = this->attributes[0x13] - this->attributes[0x0B];
        sprintf(out_text, "%4.f", (double)value);
        return;
    case '\x02':
        sprintf(out_text, "%4.f", (double)this->attributes[0x14]);
        return;
    case '\x03':
        sprintf(out_text, "%4.f", (double)this->attributes[0x0B]);
        return;
    case '\x04':
        sprintf(out_text, "%5.f", (double)this->attributes[3]);
        return;
    case '\x05':
        value = this->visible->percentExplored();
        sprintf(out_text, "%3.f%%", (double)(value * 100.0f));
        return;
    case '\x06':
        sprintf(out_text, "%4.f", (double)this->attributes[0x13]);
        return;
    case '\a':
        sprintf(out_text, "%4.f/%4.f/%4.f", (double)this->attributes[7], (double)this->attributes[0x0D], (double)this->attributes[0x0E]);
        return;
    case '\b':
        sprintf(out_text, "%4.f", (double)this->attributes[0x15]);
        return;
    default:
        return;
    }
}
