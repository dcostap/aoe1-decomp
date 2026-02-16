#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_Gaia.h"
#include "../include/TRIBE_Master_Player.h"
#include "../include/TRIBE_Master_Tree_Object.h"
#include "../include/TRIBE_Master_Combat_Object.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Player_Tech.h"
#include "../include/TRIBE_History_Info.h"
#include "../include/TRIBE_Victory_Conditions.h"
#include "../include/TRIBE_Command.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

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
    // Note: base class called with is_active='\0' — TRIBE_Player creates its own object lists.
    this->playerAI = nullptr;

    // Set player type for computer players
    if (is_computer != 0) {
        this->type = 3; // computer player type in TRIBE layer
        this->computerPlayerValue = 1;
        // TODO(accuracy): create TribeMainDecisionAIModule if comm->IsHost()
    } else {
        this->type = 1; // human player type in TRIBE layer
    }

    // Set relations to enemy for all other players
    if (world) {
        for (int i = 1; i < world->player_num; i++) {
            if (i != this->id) {
                if (this->relations && i < world->player_num) {
                    this->relations[i] = 3; // enemy
                }
            }
        }
    }

    this->update_count = 0;
    this->update_history_count = 0;
    this->updateCountNeedHelp = 0;
    this->update_time = 0.0f;
    // fog_update: random offset 3-6 per decomp: (debug_rand() * 3) / 0x7fff + 3
    this->fog_update = (rand() * 3) / 0x7fff + 3;

    memset(this->aiStatusInformationValue, 0, sizeof(this->aiStatusInformationValue));
    memset(this->aiStatusInformationValue2, 0, sizeof(this->aiStatusInformationValue2));
    memset(this->aiStatusInformationValue3, 0, sizeof(this->aiStatusInformationValue3));
    memset(this->aiStatusInformationValue4, 0, sizeof(this->aiStatusInformationValue4));
    memset(this->aiStatusInformationValue5, 0, sizeof(this->aiStatusInformationValue5));
    memset(this->aiStatusInformationValue6, 0, sizeof(this->aiStatusInformationValue6));

    // TODO(accuracy): create TRIBE_History_Info(-1) for history
    this->history = nullptr;

    // TODO(accuracy): create TRIBE_Player_Tech from world->tech for tech_tree
    this->tech_tree = nullptr;

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

    // Read saved TRIBE_Player fields
    rge_read(param_1, &this->type, 1);
    rge_read(param_1, &this->update_count, 4);
    rge_read(param_1, &this->updateCountNeedHelp, 4);
    rge_read(param_1, &this->fog_update, 4);
    rge_read(param_1, &this->update_time, 4);

    // TODO(accuracy): create TRIBE_Player_Tech from save file + world->tech
    this->tech_tree = nullptr;

    if (save_game_version <= 5.0f) {
        this->update_history_count = 0;
    } else {
        rge_read(param_1, &this->update_history_count, 4);
    }

    // TODO(accuracy): create TRIBE_History_Info from save file or default(-1)
    this->history = nullptr;

    if (save_game_version < 5.3f) {
        this->ruin_held_time = -1.0f;
        this->artifact_held_time = -1.0f;
    } else {
        rge_read(param_1, &this->ruin_held_time, 4);
        rge_read(param_1, &this->artifact_held_time, 4);
    }

    // Computer player AI loading
    if (this->type == 3) {
        int has_ai = 1;
        if (save_game_version >= 7.03f) {
            rge_read(param_1, &has_ai, 4);
        }
        // TODO(accuracy): create TribeMainDecisionAIModule from save if IsHost && has_ai
        this->computerPlayerValue = 1;
    }
}

// TRIBE_Player destructor - Source of truth: tplayer.cpp.decomp @ 0x005120F0
TRIBE_Player::~TRIBE_Player() {
    if (this->tech_tree) {
        // TODO(accuracy): call TRIBE_Player_Tech::~TRIBE_Player_Tech
        delete this->tech_tree;
        this->tech_tree = nullptr;
    }
    if (this->playerAI) {
        // TODO(accuracy): call TribeMainDecisionAIModule destructor via vtable
        // delete this->playerAI;
        this->playerAI = nullptr;
    }
    if (this->history) {
        // TODO(accuracy): call TRIBE_History_Info::~TRIBE_History_Info
        delete this->history;
        this->history = nullptr;
    }
    // Base ~RGE_Player() called automatically
}

// --- TRIBE_Gaia constructors ---
TRIBE_Gaia::TRIBE_Gaia(RGE_Game_World* world, RGE_Master_Player* master, uchar player_id, char* name, uchar type)
    : TRIBE_Player(world, master, player_id, name, 0, '\0', '\0', nullptr, nullptr, nullptr) {
    this->update_time = 0.0f;
    this->update_nature = 0;
    this->last_count = 0;
    this->animal_max = 0;
}

TRIBE_Gaia::TRIBE_Gaia(int param_1, RGE_Game_World* world, uchar player_id)
    : TRIBE_Player(param_1, world, player_id) {
    this->update_time = 0.0f;
    this->update_nature = 0;
    this->last_count = 0;
    this->animal_max = 0;
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
void TRIBE_Player::update() {
    // Source of truth: tplayer.cpp.decomp @ 0x005123B0
    // Accumulate update_time based on world_time_delta_seconds
    if (this->world) {
        this->update_time += this->world->world_time_delta_seconds;
    }

    // Process update ticks while update_time > 1.0
    while (this->update_time > 1.0f) {
        this->update_history_count++;
        this->update_time -= 1.0f;

        // Decrement update counters
        if (this->update_count > 0) {
            this->update_count--;
        }
        if (this->updateCountNeedHelp > 0) {
            this->updateCountNeedHelp--;
        }

        // TODO(accuracy): history entry every 15 ticks
        // TODO(accuracy): update explored percentage
        // TODO(accuracy): check for player defeat (no units left)
    }

    // Call base class update (resets pathing attempts, etc.)
    RGE_Player::update();

    // TODO(accuracy): AI module update
    // TODO(accuracy): fog_update attribute decay
}
void TRIBE_Player::update_dopplegangers() { RGE_Player::update_dopplegangers(); }
void TRIBE_Player::save(int param_1) {
    // Source of truth: tplayer.cpp.decomp @ 0x00512250
    RGE_Player::save(param_1);
    rge_write(param_1, &this->type, 1);
    rge_write(param_1, &this->update_count, 4);
    rge_write(param_1, &this->updateCountNeedHelp, 4);
    rge_write(param_1, &this->fog_update, 4);
    rge_write(param_1, &this->update_time, 4);
    if (this->tech_tree) {
        // TODO(accuracy): TRIBE_Player_Tech::save(this->tech_tree, param_1);
    }
    rge_write(param_1, &this->update_history_count, 4);
    if (this->history) {
        // TODO(accuracy): TRIBE_History_Info::save(this->history, param_1);
    }
    rge_write(param_1, &this->ruin_held_time, 4);
    rge_write(param_1, &this->artifact_held_time, 4);
    // Computer player AI save
    if (this->type == 1) {
        int has_ai = 0;
        if (this->playerAI != nullptr) {
            // TODO(accuracy): check IsHost and save AI data
        }
        rge_write(param_1, &has_ai, 4);
    }
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
void TRIBE_Player::buildObject(int param_1, int param_2, float param_3, float param_4, int param_5) {}
void TRIBE_Player::cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7) {}
void TRIBE_Player::registerBuild(RGE_Static_Object* param_1, int param_2) {}
void TRIBE_Player::trainUnit(int param_1, int param_2, int param_3) {}
void TRIBE_Player::cancelTrain(int param_1, int param_2, int param_3, int param_4) {}
void TRIBE_Player::registerTrain(int param_1, int param_2, int param_3, int param_4) {}
void TRIBE_Player::research(int param_1, int param_2, int param_3) {}
void TRIBE_Player::cancelResearch(int param_1, int param_2, int param_3, int param_4) {}
void TRIBE_Player::registerResearch(int param_1, int param_2, int param_3) {}
void TRIBE_Player::taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5) {}
void TRIBE_Player::taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5) {}
void TRIBE_Player::notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {}
