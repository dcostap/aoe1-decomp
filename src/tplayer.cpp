#include "../include/tplayer.h"
#include "../include/program_mode.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/tworld.h"
#include "../include/tech.h"
#include "../include/t_histry.h"
#include "../include/taimdmd.h"
#include "../include/tvictory.h"
#include "../include/tcommand.h"
#include "../include/tobj_lst.h"
#include "../include/stat_obj.h"
#include "../include/dpl_obj.h"
#include "../include/m_s_obj.h"
#include "../include/m_mi_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/m_co_obj.h"
#include "../include/t_b_obj.h"
#include "../include/tm_b_obj.h"
#include "../include/tm_tre_o.h"
#include "../include/teffects.h"
#include "../include/tscenaro.h"
#include "../include/map.h"
#include "../include/obj_list.h"
#include "../include/visible.h"
#include "../include/vis_unit.h"
#include "../include/basegame.h"
#include "../include/tribegam.h"
#include "../include/com_hand.h"
#include "../include/Mouseptr.h"
#include "../include/effects.h"
#include "../include/color.h"
#include "../include/asp_list.h"
#include "../include/chat.h"
#include "../include/sound.h"
#include "../include/tactical_group.h"
#include "../include/rge_fio.h"
#include "../include/rge_base_game_global.h"
#include "../include/game_globals.h"
#include "../include/resource_ids.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Build-list slots for TRIBE_Player::intelligentBuildListAndRulesSelection. Each name is the
// file loaded for that slot, from string STRING_ID_AI_BUILD_LIST_FIRST + slot.
#define BUILD_LIST_ARCHERS_BRONZE              0
#define BUILD_LIST_ARCHERS_IRON                1
#define BUILD_LIST_ARCHERS_WALLS               2
#define BUILD_LIST_PHALANX_BRONZE              3
#define BUILD_LIST_PHALANX_IRON                4
#define BUILD_LIST_PHALANX_WALLS               5
#define BUILD_LIST_CAVALRY_BRONZE              6
#define BUILD_LIST_CAVALRY_IRON                7
#define BUILD_LIST_CAVALRY_WALLS               8
#define BUILD_LIST_INFANTRY_STONE              9
#define BUILD_LIST_INFANTRY_TOOL               10
#define BUILD_LIST_INFANTRY_BRONZE             11
#define BUILD_LIST_INFANTRY_WALLS              12
#define BUILD_LIST_TRIREME_BRONZE              13
#define BUILD_LIST_TRIREME_IRON                14
#define BUILD_LIST_TRIREME_WALLS               15
#define BUILD_LIST_CAV_ARCHER_IRON             16
#define BUILD_LIST_WAR_ELEPHANT_IRON           17
#define BUILD_LIST_ELEPHANT_ARCHER_IRON        18
#define BUILD_LIST_PRIEST_BRONZE               19
#define BUILD_LIST_PRIEST_IRON                 20
#define BUILD_LIST_PRIEST_WALLS                21
#define BUILD_LIST_DEATH_MATCH_ASSYRIA         22
#define BUILD_LIST_DEATH_MATCH_BABYLON         23
#define BUILD_LIST_DEATH_MATCH_CHOSON          24
#define BUILD_LIST_DEATH_MATCH_EGYPT           25
#define BUILD_LIST_DEATH_MATCH_GREEK           26
#define BUILD_LIST_DEATH_MATCH_HITTITE         27
#define BUILD_LIST_DEATH_MATCH_MINOA           28
#define BUILD_LIST_DEATH_MATCH_PERSIA          29
#define BUILD_LIST_DEATH_MATCH_PHOENICIA       30
#define BUILD_LIST_DEATH_MATCH_SHANG           31
#define BUILD_LIST_DEATH_MATCH_SUMERIA         32
#define BUILD_LIST_DEATH_MATCH_YAMATO          33
#define BUILD_LIST_IMMORTAL_ASSYRIA            34
#define BUILD_LIST_IMMORTAL_EGYPT              35
#define BUILD_LIST_IMMORTAL_GREEK              36
#define BUILD_LIST_IMMORTAL_MINOA              37
#define BUILD_LIST_IMMORTAL_SUMERIA            38
#define BUILD_LIST_IMMORTAL_YAMATO             39
#define BUILD_LIST_ASSYRIA_BALLISTA            40
#define BUILD_LIST_ASSYRIA_BOWMEN              41
#define BUILD_LIST_BABYLON_SWORDSMEN           42
#define BUILD_LIST_BABYLON_SCOUTS              43
#define BUILD_LIST_CHOSON_SWORDSMEN            44
#define BUILD_LIST_CHOSON_AXEMEN               45
#define BUILD_LIST_EGYPT_WAR_ELEPHANTS         46
#define BUILD_LIST_EGYPT_CHARIOTS              47
#define BUILD_LIST_GREEK_PHALANX               48
#define BUILD_LIST_HITTITE_HORSE_ARCHERS       49
#define BUILD_LIST_HITTITE_BOWMEN              50
#define BUILD_LIST_MINOA_COMPOSITE_BOWMEN      51
#define BUILD_LIST_PERSIA_ELEPHANT_ARCHERS     52
#define BUILD_LIST_PHOENICIA_ELEPHANTS         53
#define BUILD_LIST_SHANG_HEAVY_CAVALRY         54
#define BUILD_LIST_SHANG_CAVALRY               55
#define BUILD_LIST_SHANG_CLUBMEN               56
#define BUILD_LIST_SUMERIA_CATAPULTS           57
#define BUILD_LIST_SUMERIA_SCOUTS              58
#define BUILD_LIST_YAMATO_HEAVY_CAVALRY        59
#define BUILD_LIST_DEATH_MATCH_ASSYRIA_WATER   60
#define BUILD_LIST_DEATH_MATCH_BABYLON_WATER   61
#define BUILD_LIST_DEATH_MATCH_CHOSON_WATER    62
#define BUILD_LIST_DEATH_MATCH_EGYPT_WATER     63
#define BUILD_LIST_DEATH_MATCH_GREEK_WATER     64
#define BUILD_LIST_DEATH_MATCH_HITTITE_WATER   65
#define BUILD_LIST_DEATH_MATCH_MINOA_WATER     66
#define BUILD_LIST_DEATH_MATCH_PERSIA_WATER    67
#define BUILD_LIST_DEATH_MATCH_PHOENICIA_WATER 68
#define BUILD_LIST_DEATH_MATCH_SHANG_WATER     69
#define BUILD_LIST_DEATH_MATCH_SUMERIA_WATER   70
#define BUILD_LIST_DEATH_MATCH_YAMATO_WATER    71
#define BUILD_LIST_ASSYRIA_ARCHER_BRONZE       72
#define BUILD_LIST_ASSYRIA_ARCHER_IRON         73
#define BUILD_LIST_ASSYRIA_INFANTRY_BRONZE     74
#define BUILD_LIST_ASSYRIA_BRONZE_WATER        75
#define BUILD_LIST_ASSYRIA_IRON_WATER          76
#define BUILD_LIST_BABYLON_WATER               77
#define BUILD_LIST_CHOSON_BRONZE_WATER         78
#define BUILD_LIST_CHOSON_IRON_WATER           79
#define BUILD_LIST_EGYPT_CHARIOT_ARCHER        80
#define BUILD_LIST_EGYPT_ARCHERS_BRONZE        81
#define BUILD_LIST_EGYPT_ARCHERS_IRON          82
#define BUILD_LIST_EGYPT_WATER                 83
#define BUILD_LIST_GREEK_SIEGE                 84
#define BUILD_LIST_GREEK_BRONZE_WATER          85
#define BUILD_LIST_GREEK_IRON_WATER            86
#define BUILD_LIST_HITTITE_WATER               87
#define BUILD_LIST_MINOA_BRONZE_WATER          88
#define BUILD_LIST_MINOA_IRON_WATER            89
#define BUILD_LIST_PERSIA_BRONZE_WATER         90
#define BUILD_LIST_PERSIA_IRON_WATER           91
#define BUILD_LIST_PHOENICIA_WATER             92
#define BUILD_LIST_SHANG_WATER                 93
#define BUILD_LIST_SUMERIA_BRONZE_WATER        94
#define BUILD_LIST_SUMERIA_IRON_WATER          95
#define BUILD_LIST_YAMATO_BRONZE_WATER         96
#define BUILD_LIST_YAMATO_IRON_WATER           97
#define BUILD_LIST_CARTHAGE_PHALANX            98
#define BUILD_LIST_CARTHAGE_WAR_ELEPHANT       99
#define BUILD_LIST_CARTHAGE_BRONZE_WATER       100
#define BUILD_LIST_CARTHAGE_IRON_WATER         101
#define BUILD_LIST_MACEDON_ELEPHANT            102
#define BUILD_LIST_MACEDON_PHALANX             103
#define BUILD_LIST_MACEDON_CAVALRY             104
#define BUILD_LIST_MACEDON_BRONZE_WATER        105
#define BUILD_LIST_MACEDON_IRON_WATER          106
#define BUILD_LIST_PALMYRA_COMPOSITE_BOW       107
#define BUILD_LIST_PALMYRA_HORSE_ARCHER        108
#define BUILD_LIST_PALMYRA_ELEPHANT            109
#define BUILD_LIST_PALMYRA_BRONZE_WATER        110
#define BUILD_LIST_PALMYRA_IRON_WATER          111
#define BUILD_LIST_ROME_LEGION                 112
#define BUILD_LIST_ROME_AXEMEN                 113
#define BUILD_LIST_ROME_SIEGE                  114
#define BUILD_LIST_ROME_BRONZE_WATER           115
#define BUILD_LIST_ROME_IRON_WATER             116
#define BUILD_LIST_DEATH_MATCH_CARTHAGE        117
#define BUILD_LIST_DEATH_MATCH_MACEDON         118
#define BUILD_LIST_DEATH_MATCH_PALMYRA         119
#define BUILD_LIST_DEATH_MATCH_ROME            120
#define BUILD_LIST_DEATH_MATCH_CARTHAGE_WATER  121
#define BUILD_LIST_DEATH_MATCH_MACEDON_WATER   122
#define BUILD_LIST_DEATH_MATCH_PALMYRA_WATER   123
#define BUILD_LIST_DEATH_MATCH_ROME_WATER      124

// TPlayer owns the object-group selection property table at 0058ABA0.
unsigned long tribe_group_properties[0x28] = { 7, 0, 4, 0, 0x67, 0, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0x10, 0x96, 0,
                                               0, 0, 1, 7, 7,    7, 7, 0, 7, 0, 0, 0, 0, 0, 0, 7, 7, 0,    0,    7 };
int tribe_group_properties_num = 0x28;

static char tplayerSourceName[] = "C:\\msdev\\work\\age1_x1\\tplayer.cpp";
// AI setup log messages and names, as referenced by the original executable.
static char tplayerRandomName[] = "RandomGameSpecialized";

TRIBE_Player::TRIBE_Player(int infile, TRIBE_World* gworld, unsigned char this_id) :
    RGE_Player(infile, gworld, this_id), playerAI(0) {
    rge_read(infile, &this->type, 1);
    rge_read(infile, &this->update_count, 4);
    rge_read(infile, &this->updateCountNeedHelp, 4);
    rge_read(infile, &this->fog_update, 4);
    rge_read(infile, &this->update_time, 4);

    this->tech_tree = new TRIBE_Player_Tech(infile, gworld->tech, this, 0);

    if (save_game_version > 5.0f) {
        rge_read(infile, &this->update_history_count, 4);
        this->history = new TRIBE_History_Info(infile);
    } else {
        this->update_history_count = 0;
        this->history = new TRIBE_History_Info(-1);
    }

    if (save_game_version >= 5.3f) {
        rge_read(infile, &this->ruin_held_time, 4);
        rge_read(infile, &this->artifact_held_time, 4);
    } else {
        this->ruin_held_time = -1.0f;
        this->artifact_held_time = -1.0f;
    }

    if (this->type == 3) {
        int create_ai = 1;
        if (save_game_version >= 7.03f) {
            rge_read(infile, &create_ai, 4);
        }
        if (comm->IsHost() == 1 && create_ai == 1) {
            this->playerAI = new TribeMainDecisionAIModule(this->id, this->name, this, infile);
        }
        this->computerPlayerValue = 1;
    }
}

TRIBE_Player::TRIBE_Player(
    TRIBE_World* gworld, RGE_Master_Player* prototype, unsigned char this_id, char* new_name, unsigned char m_player_id,
    unsigned char computerPlayer, unsigned char flag, char* buildListName, char* cityPlanName, char* ruleSetName
) : RGE_Player(gworld, prototype, this_id, new_name, m_player_id, 0), playerAI(0) {
    this->VR_List = new Visible_Resource_Manager(this, 5);

    if (computerPlayer == 0) {
        this->type = 1;
    } else {
        this->type = 3;
        this->computerPlayerValue = 1;
        if (comm->IsHost() == 1) {
            this->playerAI =
                new TribeMainDecisionAIModule(0, this->id, this->name, this, buildListName, cityPlanName, ruleSetName);
        }
    }

    if (flag != 0) {
        TRIBE_Object_List* list;

        list = new TRIBE_Object_List;
        this->objects = list;
        list = new TRIBE_Object_List;
        this->sleeping_objects = list;
        list = new TRIBE_Object_List;
        this->doppleganger_objects = list;
        this->new_victory();
        this->visible = new RGE_Visible_Map(gworld->map, this);
    }

    int i = 1;
    if (this->world->player_num > 1) {
        do {
            if (i != this->id) {
                this->set_relation(i, RGE_RELATION_ENEMY);
            }
            ++i;
        } while (i < this->world->player_num);
    }

    this->update_count = 0;
    this->update_history_count = 0;
    this->updateCountNeedHelp = 0;
    this->fog_update = (debug_rand(tplayerSourceName, 320) * 3) / 0x7fff + 3;
    this->update_time = 0.0f;
    this->history = new TRIBE_History_Info(-1);
    this->tech_tree = new TRIBE_Player_Tech(gworld->tech, this, 1);
    this->ruin_held_time = -1.0f;
    this->artifact_held_time = -1.0f;
}

TRIBE_Player::~TRIBE_Player() {
    if (tech_tree != 0) {
        delete tech_tree;
        tech_tree = 0;
    }

    if (playerAI != 0) {
        delete playerAI;
        playerAI = 0;
    }

    if (history != 0) {
        delete history;
        history = 0;
    }
}

//! @bug The saved state byte only selects an action. It is never stored in object_state.
//! The new object keeps its constructor default state. destroy_obj() (states 7-8) sets its own
//! state, but die_die_die() (states 3-6) only sets hp to 0.
//! A building saved as dying also skips build(), so it dies with the construction sprite.
RGE_Static_Object* TRIBE_Player::make_scenario_obj(
    float world_x, float world_y, float world_z, short master_id, unsigned char state, float new_angle
) {
    RGE_Static_Object* obj = 0;
    RGE_Master_Static_Object* type = this->master_objects[master_id];
    if (type) {
        obj = type->make_new_obj(this, world_x, world_y, world_z);
        if (state >= RGE_OBJECT_STATE_PENDING_REMOVAL) {
            obj->destroy_obj();
        } else if (state > RGE_OBJECT_STATE_ACTIVE) {
            obj->die_die_die();
        } else {
            RGE_Master_Static_Object* master = obj->master_obj;
            unsigned char group = master->master_type;
            if (group > RGE_MASTER_TYPE_MOVING && group < TRIBE_MASTER_TYPE_TREE) {
                obj->new_angle(new_angle);
            } else {
                obj->facet = static_cast<unsigned char>(static_cast<int>(new_angle));
            }
        }
        if (this->master_objects[master_id]->master_type == TRIBE_MASTER_TYPE_BUILDING
            && state == RGE_OBJECT_STATE_ACTIVE) {
            static_cast<TRIBE_Building_Object*>(obj)->build(10000.0f);
        }
    }
    return obj;
}

void TRIBE_Player::save(int outfile) {
    int save_file;
    color_log(0x16, 0x16, 2);
    save_file = outfile;
    RGE_Player::save(save_file);
    color_log(0x16, 0x24, 2);
    rge_write(save_file, &this->type, 1);
    rge_write(save_file, &this->update_count, 4);
    rge_write(save_file, &this->updateCountNeedHelp, 4);
    rge_write(save_file, &this->fog_update, 4);
    rge_write(save_file, &this->update_time, 4);
    this->tech_tree->save(save_file);
    rge_write(save_file, &this->update_history_count, 4);
    this->history->save(save_file);
    rge_write(save_file, &this->ruin_held_time, 4);
    rge_write(save_file, &this->artifact_held_time, 4);
    color_log(0x16, 0x4C, 2);
    if (this->computerPlayerValue == 1) {
        if (this->playerAI != 0 && comm->IsHost() == 1) {
            outfile = 1;
            rge_write(save_file, &outfile, 4);
            this->playerAI->save(save_file);
            color_log(0x16, 0x5F, 2);
            return;
        }
        outfile = 0;
        rge_write(save_file, &outfile, 4);
    }
    color_log(0x16, 0x5F, 2);
}

void TRIBE_Player::update() {
    this->update_time += this->world->world_time_delta_seconds;
    while (this->update_time > 1.0f) {
        this->update_time -= 1.0f;
        ++this->update_history_count;
        if (this->update_history_count >= 15) {
            this->update_history_count -= 15;
            if (this->attributes[PLAYER_ATTRIBUTE_POPULATION] < 0.0f)
                this->history->add_history_entry(0, 0);
            else
                this->history->add_history_entry(
                    0, static_cast<unsigned char>(static_cast<long>(this->attributes[PLAYER_ATTRIBUTE_POPULATION]))
                );
        }
        if (rge_base_game->fullVisibility())
            this->attributes[PLAYER_ATTRIBUTE_PERCENT_EXPLORED] = 100.0f;
        else
            this->attributes[PLAYER_ATTRIBUTE_PERCENT_EXPLORED] = this->visible->percentExplored() * 100.0f;
        this->attributes[PLAYER_ATTRIBUTE_KILLS_MINUS_LOSSES] =
            this->attributes[PLAYER_ATTRIBUTE_KILLS]
            - (this->attributes[PLAYER_ATTRIBUTE_TOTAL_UNITS_OWNED] - this->attributes[PLAYER_ATTRIBUTE_POPULATION]);
        if (this->attributes[PLAYER_ATTRIBUTE_KILLS_MINUS_LOSSES] < 0.0)
            this->attributes[PLAYER_ATTRIBUTE_KILLS_MINUS_LOSSES] = 0.0f;
        this->attributes[PLAYER_ATTRIBUTE_TRADE_GOODS] += this->attributes[PLAYER_ATTRIBUTE_TRADE_PRODUCTION];
        if (this->attributes[PLAYER_ATTRIBUTE_TRADE_GOODS] > 100.0)
            this->attributes[PLAYER_ATTRIBUTE_TRADE_GOODS] = 100.0f;
        if (this->update_count > 0)
            --this->update_count;
        if (this->updateCountNeedHelp > 0)
            --this->updateCountNeedHelp;
        if (this->id > 0) {
            RGE_Object_Node* node = this->objects->list;
            while (node != 0) {
                RGE_Static_Object* object = node->node;
                int group = object->master_obj->object_group;
                if (group != 0xb && group != OBJECT_GROUP_FLAG && group != OBJECT_GROUP_WALL
                    && group != OBJECT_GROUP_ARTIFACT && group != OBJECT_GROUP_FISHING_BOAT
                    && group != OBJECT_GROUP_TRANSPORT_BOAT && group != OBJECT_GROUP_TRADE_BOAT
                    && group != OBJECT_GROUP_DOPPLEGANGER && object->object_state == RGE_OBJECT_STATE_ACTIVE)
                    break;
                node = node->next;
            }
            if (node == 0) {
                this->set_game_status(2);
                this->attributes[45] = 0.0f;
            }
        }
    }
    RGE_Player::update();
    this->attributes[RGE_RESOURCE_FOOD] -= this->world->world_time_delta_seconds
                                           * this->attributes[PLAYER_ATTRIBUTE_FOOD_MAINTENANCE]
                                           * this->attributes[PLAYER_ATTRIBUTE_POPULATION] * 0.016666667f;
    if (this->attributes[RGE_RESOURCE_FOOD] < 0.0)
        this->attributes[RGE_RESOURCE_FOOD] = 0.0f;
    int seed = debug_rand(tplayerSourceName, 607);
    int old = debug_random_on;
    global_save_debug_random_on1 = old;
    debug_random_on = 0;
    if (this->playerAI && comm->ComputerPlayerGameStart() == 1) {
        if (this->world->currentUpdateComputerPlayer == -1)
            this->world->selectNextComputerPlayer(3);
        this->playerAI->update(0);
    }
    debug_random_on = old;
    debug_srand(tplayerSourceName, 631, seed);
    if (MouseSystem != 0)
        MouseSystem->Poll();
}

void TRIBE_Player::update_dopplegangers() {
    RGE_Player::update_dopplegangers();
}

void TRIBE_Player::scenario_save(int outfile) {
    RGE_Player::scenario_save(outfile);
    rge_write(outfile, &this->attributes[RGE_RESOURCE_FOOD], 4);
    rge_write(outfile, &this->attributes[RGE_RESOURCE_WOOD], 4);
    rge_write(outfile, &this->attributes[RGE_RESOURCE_GOLD], 4);
    rge_write(outfile, &this->attributes[RGE_RESOURCE_STONE], 4);
}

void TRIBE_Player::scenario_load(int infile, long* player_id_hash, float version) {
    TRIBE_Player_Tech* tech;
    int i;
    RGE_Master_Static_Object* obj;

    RGE_Player::scenario_load(infile, player_id_hash, version);

    tech = this->tech_tree;
    if (tech != 0) {
        delete tech;
    }

    i = 0;
    if (this->master_object_num > 0) {
        do {
            obj = this->master_objects[i];
            if (obj != 0) {
                obj->make_available(0);
            }
            i++;
        } while (i < this->master_object_num);
    }

    if (version > 1.06) {
        rge_read(infile, &this->attributes[RGE_RESOURCE_FOOD], 4);
        rge_read(infile, &this->attributes[RGE_RESOURCE_WOOD], 4);
        rge_read(infile, &this->attributes[RGE_RESOURCE_GOLD], 4);
        rge_read(infile, &this->attributes[RGE_RESOURCE_STONE], 4);
    }

    this->attributes[30] = 0.0f;
    this->attributes[PLAYER_ATTRIBUTE_TECHNOLOGY_COUNT] = 0.0f;

    if (version <= 1.03) {
        this->tech_tree = new TRIBE_Player_Tech(infile, static_cast<TRIBE_World*>(this->world)->tech, this, 1);
        return;
    }

    tech = new TRIBE_Player_Tech(static_cast<TRIBE_World*>(this->world)->tech, this, 0);
    this->tech_tree = tech;

    if (this->tribe_effect >= 0 && !static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree()
        && !static_cast<T_Scenario*>(static_cast<TRIBE_World*>(this->world)->scenario)->GetScenarioOption(2)) {
        static_cast<TRIBE_Effects*>(static_cast<TRIBE_World*>(this->world)->effects)
            ->do_tech_effect(static_cast<short>(this->tribe_effect), this);
    } else {
        static_cast<TRIBE_Effects*>(static_cast<TRIBE_World*>(this->world)->effects)->do_tech_effect(0xD2, this);
    }

    if (rge_base_game->game_mode != 7) {
        static_cast<T_Scenario*>(static_cast<TRIBE_World*>(this->world)->scenario)->set_player_tech(this);
    }
    this->tech_tree->check_for_new_tech();
}

void TRIBE_Player::load(int infile) {
    rge_read(infile, &this->master_object_num, 2);
    short count = this->master_object_num;
    if (count > 0) {
        // RGE_Player releases this shared table with free().
        this->master_objects = static_cast<RGE_Master_Static_Object**>(calloc(count, sizeof(*this->master_objects)));
        rge_read(infile, this->master_objects, this->master_object_num * 4);
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
    this->objects = new TRIBE_Object_List;
    this->objects->load_list(infile, this->world);
    this->sleeping_objects = new TRIBE_Object_List;
    this->sleeping_objects->load_list(infile, this->world);
    this->doppleganger_objects = new RGE_Object_List;

    if (save_game_version >= 7.09f) {
        this->doppleganger_objects->load_list(infile, this->world);
    }
}

void TRIBE_Player::load_master_object(
    int infile, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds
) {
    RGE_Master_Static_Object* obj;

    switch (type) {
        case 'F':
            obj = new TRIBE_Master_Combat_Object(infile, sprites, sounds, 1);
            break;
        case 'P':
            obj = new TRIBE_Master_Building_Object(infile, sprites, sounds, 1);
            master_objects[index] = obj;
            return;
        case 'Z':
            obj = new TRIBE_Master_Tree_Object(infile, sprites, sounds, 1);
            break;
        default:
            RGE_Player::load_master_object(infile, index, type, sprites, sounds);
            return;
    }
    master_objects[index] = obj;
}

void TRIBE_Player::tech_cost(
    short tech_id, short& inv_1, short& inv_amt_1, short& inv_2, short& inv_amt_2, short& inv_3, short& inv_amt_3
) {
    TRIBE_Player_Tech* tech = this->tech_tree;
    tech->tech_cost(tech_id, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3);
}

void TRIBE_Player::obj_cost(
    short obj_id, char** name, short& inv_1, short& inv_amt_1, short& inv_2, short& inv_amt_2, short& inv_3,
    short& inv_amt_3, float modifier
) {
    short avail;
    short* amount_output;
    short total = 0;
    inv_1 = -1;
    inv_amt_1 = total;
    inv_2 = -1;
    inv_amt_2 = total;
    inv_3 = -1;
    inv_amt_3 = total;

    unsigned char can = this->check_obj_cost(obj_id, 0, 1.0f, 0);
    RGE_Master_Static_Object* master = this->master_objects[obj_id];
    if (master == 0 || master->master_type < TRIBE_MASTER_TYPE_COMBAT)
        return;
    if (name != 0)
        *name = master->name;

    TRIBE_Master_Combat_Object* combat = static_cast<TRIBE_Master_Combat_Object*>(master);
    if (combat->build_inventory[0].flag != 0) {
        inv_1 = combat->build_inventory[0].type;
        if (inv_1 >= 0) {
            inv_amt_1 = static_cast<short>(combat->build_inventory[0].amount * modifier);
            if (static_cast<float>(inv_amt_1) > this->attributes[inv_1] && can != 0) {
                avail = static_cast<short>(this->attributes[inv_1]);
                total = static_cast<short>(inv_amt_1 - avail);
                inv_amt_1 = avail;
            }
        }
    }
    if (combat->build_inventory[1].flag != 0) {
        inv_2 = combat->build_inventory[1].type;
        if (inv_2 >= 0) {
            inv_amt_2 = static_cast<short>(combat->build_inventory[1].amount * modifier);
            if (static_cast<float>(inv_amt_2) > this->attributes[inv_2] && can != 0) {
                avail = static_cast<short>(this->attributes[inv_2]);
                total += static_cast<short>(inv_amt_2 - avail);
                inv_amt_2 = avail;
            }
        }
    }
    if (combat->build_inventory[2].flag != 0) {
        inv_3 = combat->build_inventory[2].type;
        if (inv_3 >= 0) {
            inv_amt_3 = static_cast<short>(combat->build_inventory[2].amount * modifier);
            if (static_cast<float>(inv_amt_3) > this->attributes[inv_3] && can != 0) {
                avail = static_cast<short>(this->attributes[inv_3]);
                total += static_cast<short>(inv_amt_3 - avail);
                inv_amt_3 = avail;
            }
        }
    }

    if (total > 0) {
        if (inv_1 == 3 || inv_1 == -1) {
            inv_1 = 3;
            amount_output = &inv_amt_1;
        } else {
            if (inv_2 != 3 && inv_2 != -1) {
                if (inv_3 == 3 || inv_3 == -1) {
                    inv_3 = 3;
                    inv_amt_3 = total;
                }
                goto done_total;
            }
            inv_2 = 3;
            amount_output = &inv_amt_2;
        }
        *amount_output += total;
    }

done_total:
    if (inv_amt_1 <= 0)
        inv_1 = -1;
    if (inv_amt_2 <= 0)
        inv_2 = -1;
    if (inv_amt_3 <= 0)
        inv_3 = -1;
}

RGE_Static_Object* TRIBE_Player::find_obj(short obj_id, RGE_Static_Object* after_obj) {
    if (after_obj != 0) {
        int found = 0;
        RGE_Object_Node* node = this->objects->list;
        while (node != 0) {
            RGE_Static_Object* object = node->node;
            if (object != 0) {
                if (found) {
                    if (object->master_obj->id == obj_id && object->object_state <= RGE_OBJECT_STATE_ACTIVE)
                        return node->node;
                } else if (object == after_obj) {
                    found = 1;
                }
            }
            node = node->next;
        }
    }

    RGE_Object_Node* node = this->objects->list;
    if (node == 0)
        return 0;
    while (node != 0) {
        RGE_Static_Object* object = node->node;
        if (object != 0 && object->master_obj->id == obj_id && object->object_state == RGE_OBJECT_STATE_ACTIVE)
            return node->node;
        node = node->next;
    }
    return 0;
}

RGE_Static_Object* TRIBE_Player::make_new_object(long obj_id, float x, float y, float z, int build_all_the_way) {
    RGE_Static_Object* object = RGE_Player::make_new_object(obj_id, x, y, z, build_all_the_way);
    if (object != 0) {
        if (build_all_the_way != 0) {
            static_cast<TRIBE_World*>(this->world)->check_destructables(this->id, static_cast<short>(obj_id), x, y, 0);
            if (object->master_obj->master_type == TRIBE_MASTER_TYPE_BUILDING)
                static_cast<TRIBE_Building_Object*>(object)->build(10000.0f);
        }
        if (rge_base_game->prog_mode == ProgModeScenarioEditor
            && (object->master_obj->object_group == OBJECT_GROUP_FISH || object->master_obj->object_group == 0x21))
            object->sprite_list->set_frame(object->sprite, 5);
    }
    return object;
}

void TRIBE_Player::interface_tech_avail(Item_Avail** list, short* list_num, short obj_cat) {
    short count = 0;
    short inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3;
    Tech_Tree* base_tech = static_cast<TRIBE_World*>(this->world)->tech->tech_tree;

    for (short i = 0; i < this->tech_tree->tech_player_tree_num; i++) {
        if (this->tech_tree->tech_player_tree[i].state == 1 && base_tech[i].build_obj_id == obj_cat) {
            count++;
        }
    }

    if (*list != 0) {
        free(*list);
        *list = 0;
    }

    *list_num = count;
    if (count == 0) {
        return;
    }

    // The dialog owns this C-allocated block and releases it with free().
    *list = static_cast<Item_Avail*>(calloc(count, sizeof(Item_Avail)));

    short list_n = 0;
    short out_index = 0;
    if (this->tech_tree->tech_player_tree_num <= 0) {
        return;
    }

    do {
        int idx = list_n;
        if (this->tech_tree->tech_player_tree[idx].state == 1) {
            Tech_Tree* entry = &base_tech[idx];
            if (entry->build_obj_id == obj_cat) {
                int avail_index = out_index;
                Item_Avail* item = *list;
                item[avail_index].id = list_n;
                (*list)[avail_index].pict = entry->icon;
                (*list)[avail_index].name = entry->name;

                this->tech_tree->tech_cost(list_n, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3);

                (*list)[avail_index].inventory_item_1 = inv_1;
                (*list)[avail_index].inventory_cost_1 = inv_amt_1;
                (*list)[avail_index].inventory_item_2 = inv_2;
                (*list)[avail_index].inventory_cost_2 = inv_amt_2;
                (*list)[avail_index].inventory_item_3 = inv_3;
                (*list)[avail_index].inventory_cost_3 = inv_amt_3;
                (*list)[avail_index].help_string_id = this->tech_tree->get_help_message(list_n);
                (*list)[avail_index].help_page_id = this->tech_tree->get_help_page(list_n);

                out_index++;
            }
        }
        list_n++;
    } while (list_n < this->tech_tree->tech_player_tree_num);
}

void TRIBE_Player::interface_item_avail(Item_Avail** list, short* list_num, short obj_cat) {
    short tribe_flag = 0;
    short count = 0;
    short inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3;

    if (this->master_object_num > 0) {
        RGE_Master_Static_Object** pp = this->master_objects;
        int n = this->master_object_num;
        do {
            RGE_Master_Static_Object* m = *pp;
            if (m != 0 && m->master_type >= TRIBE_MASTER_TYPE_COMBAT && m->available != 0
                && static_cast<TRIBE_Master_Combat_Object*>(m)->id_of_building_obj == obj_cat)
                count++;
            pp++;
            n--;
        } while (n != 0);
    }

    if (obj_cat == MASTER_OBJECT_BUILDER && this->attributes[0x30] == 0.0f
        && this->master_objects[MASTER_OBJECT_TOWN_CENTER1]->available == 0) {
        tribe_flag = 1;
        RGE_Object_Node* node = this->objects->list;
        while (node != 0) {
            if (node->node->master_obj->id == MASTER_OBJECT_TOWN_CENTER1)
                tribe_flag = 0;
            node = node->next;
        }
    }
    if (tribe_flag != 0)
        count++;

    Item_Avail** item_list = list;
    if (*item_list != 0) {
        free(*item_list);
        *item_list = 0;
    }
    *list_num = count;
    if (count == 0)
        return;
    // The dialog owns this C-allocated block and releases it with free().
    *item_list = static_cast<Item_Avail*>(calloc(count, sizeof(Item_Avail)));

    short index = 0;
    short list_n = 0;
    while (index < this->master_object_num) {
        if (this->master_objects[index] != 0 && this->master_objects[index]->master_type >= TRIBE_MASTER_TYPE_COMBAT
            && this->master_objects[index]->available != 0
            && static_cast<TRIBE_Master_Combat_Object*>(this->master_objects[index])->id_of_building_obj == obj_cat) {
            (*item_list)[list_n].id = index;
            (*item_list)[list_n].pict = this->master_objects[index]->button_pict;
            (*item_list)[list_n].name = this->master_objects[index]->name;
            this->obj_cost(static_cast<short>(index), 0, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3, 1.0f);
            (*item_list)[list_n].inventory_item_1 = inv_1;
            (*item_list)[list_n].inventory_cost_1 = inv_amt_1;
            (*item_list)[list_n].inventory_item_2 = inv_2;
            (*item_list)[list_n].inventory_cost_2 = inv_amt_2;
            (*item_list)[list_n].inventory_item_3 = inv_3;
            (*item_list)[list_n].inventory_cost_3 = inv_amt_3;
            (*item_list)[list_n].help_string_id = this->master_objects[index]->get_help_message();
            (*item_list)[list_n].help_page_id = this->master_objects[index]->get_help_page();
            ++list_n;
        }
        index++;
    }

    if (tribe_flag != 0) {
        (*item_list)[list_n].id = MASTER_OBJECT_TOWN_CENTER1;
        (*item_list)[list_n].pict = this->master_objects[MASTER_OBJECT_TOWN_CENTER1]->button_pict;
        (*item_list)[list_n].name = this->master_objects[MASTER_OBJECT_TOWN_CENTER1]->name;
        this->obj_cost(0x6d, 0, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3, 1.0f);
        (*item_list)[list_n].inventory_item_1 = inv_1;
        (*item_list)[list_n].inventory_cost_1 = inv_amt_1;
        (*item_list)[list_n].inventory_item_2 = inv_2;
        (*item_list)[list_n].inventory_cost_2 = inv_amt_2;
        (*item_list)[list_n].inventory_item_3 = inv_3;
        (*item_list)[list_n].inventory_cost_3 = inv_amt_3;
        (*item_list)[list_n].help_string_id = this->master_objects[MASTER_OBJECT_TOWN_CENTER1]->get_help_message();
        (*item_list)[list_n].help_page_id = this->master_objects[MASTER_OBJECT_TOWN_CENTER1]->get_help_page();
    }
}

void TRIBE_Player::interface_trade_avail(Trade_Avail** list, short* list_num) {
    int i = 1;
    int dock_count = 0;
    RGE_Static_Object* dock_list[96];

    if (i < this->world->player_num) {
        do {
            if (i != this->id) {
                RGE_Object_Node* node = this->world->players[i]->objects->list;
                if (node != 0) {
                    RGE_Static_Object** output = dock_list + dock_count;
                    do {
                        //! Trade targets only docks (master id 0x2D); RockNROR allows other trade-partner units.
                        if (node->node->master_obj->id == MASTER_OBJECT_DOCK_1) {
                            if (this->visible->get_visible(
                                    static_cast<short>(node->node->world_x), static_cast<short>(node->node->world_y)
                                )) {
                                ++dock_count;
                                *output = node->node;
                                ++output;
                            }
                        }
                        node = node->next;
                    } while (node != 0);
                }
            }
            ++i;
        } while (i < this->world->player_num);
    }

    if (*list != 0) {
        free(*list);
        *list = 0;
    }

    *list_num = static_cast<short>(dock_count);
    if (dock_count != 0) {
        // The dialog owns this C-allocated block and releases it with free().
        *list = static_cast<Trade_Avail*>(calloc(dock_count, sizeof(Trade_Avail)));
        if (dock_count > 0) {
            RGE_Static_Object** input = dock_list;
            Trade_Avail* output = *list;
            int count = dock_count;
            do {
                ++output;
                RGE_Static_Object* dock = *input;
                ++input;
                --count;
                output[-1].player = dock->owner;
                output[-1].dock = dock;
                output[-1].inventory = dock->attribute_amount_held;
            } while (count != 0);
        }
    }
}

unsigned char TRIBE_Player::command_make_building(short obj_id, float x, float y) {
    short list_num;
    RGE_Static_Object** list;
    short unused_list_num;

    RGE_Master_Static_Object* info = this->master_objects[obj_id];
    if (info != 0 && (info->available != 0 || obj_id == MASTER_OBJECT_TOWN_CENTER1)) {
        if (get_selected_objects_to_command(&list, &list_num, 4, 4, -1, -1)) {
            this->master_objects[MASTER_OBJECT_BUILDER]->play_command_sound();
            static_cast<TRIBE_Command*>(this->world->commands)->command_build(list, list_num, obj_id, x, y);
            free(list);
            return 1;
        }
    }

    return 0;
}

unsigned char TRIBE_Player::command_make_wall(short obj_id, long x1, long y1, long x2, long y2) {
    short list_num;
    RGE_Static_Object** list;

    RGE_Master_Static_Object* info = this->master_objects[obj_id];
    if (info != 0 && info->available != 0) {
        if (get_selected_objects_to_command(&list, &list_num, 4, 4, -1, -1)) {
            this->master_objects[MASTER_OBJECT_BUILDER]->play_command_sound();
            static_cast<TRIBE_Command*>(this->world->commands)
                ->command_build_wall(list, list_num, obj_id, x1, y1, x2, y2);
            free(list);
            return 1;
        }
    }
    return 0;
}

unsigned char TRIBE_Player::command_building_make_tech(short tech_id) {
    RGE_Static_Object* object = this->selected_obj;
    if (object && object->master_obj->master_type == TRIBE_MASTER_TYPE_BUILDING) {
        TRIBE_Command* command = static_cast<TRIBE_Command*>(this->world->commands);
        command->command_research(object, tech_id);
        return 1;
    }
    return 0;
}

unsigned char TRIBE_Player::command_building_cancel() {
    RGE_Static_Object* selected_obj;

    selected_obj = this->selected_obj;
    if (selected_obj != 0) {
        if (selected_obj->owner == this) {
            if (selected_obj->master_obj->master_type == TRIBE_MASTER_TYPE_BUILDING
                || selected_obj->master_obj->master_type == TRIBE_MASTER_TYPE_COMBAT) {
                if (selected_obj->master_obj->object_group != OBJECT_GROUP_ARTIFACT) {
                    static_cast<TRIBE_Command*>(this->world->commands)->command_cancel_build(selected_obj);
                    return 1;
                }
            }
        }
    }

    return 0;
}

unsigned char TRIBE_Player::command_delete_object(RGE_Static_Object* obj) {
    unsigned char type;

    if ((obj != 0) && (obj->owner == this)) {
        type = obj->master_obj->master_type;
        if ((type == TRIBE_MASTER_TYPE_BUILDING) || (type == TRIBE_MASTER_TYPE_COMBAT)) {
            static_cast<TRIBE_Command*>(this->world->commands)->command_cancel_build(obj);
            return 1;
        }
    }
    return 0;
}

unsigned char TRIBE_Player::command_trade_attribute(long attribute) {
    RGE_Static_Object** list;
    short list_num[2];

    if (this->get_selected_objects_to_command(&list, list_num, 4, -1, -1, 5)) {
        (*list)->play_command_sound();
        static_cast<TRIBE_Command*>(this->world->commands)->command_trade_attribute(list, list_num[0], attribute);
        free(list);
        return 1;
    }

    return 0;
}

unsigned char TRIBE_Player::command_trade_attribute(int unitID, long attribute) {
    short player_id = this->id;
    TRIBE_Command* command = static_cast<TRIBE_Command*>(this->world->commands);
    command->command_trade_attribute(unitID, player_id, attribute);
    return 1;
}

unsigned char TRIBE_Player::command_attack_ground(float x, float y) {
    RGE_Static_Object** list;
    short list_num[2];

    if (this->get_selected_objects_to_command(&list, list_num, 4, -1, -1, 4)) {
        (*list)->play_command_sound();
        static_cast<TRIBE_Command*>(this->world->commands)->command_attack_ground(list, list_num[0], x, y);
        free(list);
        return 1;
    }

    return 0;
}

unsigned char TRIBE_Player::command_give_attribute(int to_player_id, int attr_id, float attr_amount, float attr_cost) {
    if (attr_id == -1 || attr_amount == 0.0f) {
        return 0;
    }
    static_cast<TRIBE_Command*>(this->world->commands)
        ->command_give_attribute(this->id, to_player_id, attr_id, attr_amount, attr_cost);
    return 1;
}

unsigned char TRIBE_Player::command_building_make_obj(short obj_id) {
    RGE_Static_Object* object = this->selected_obj;
    if (object && object->master_obj->master_type == TRIBE_MASTER_TYPE_BUILDING) {
        TRIBE_Command* command = static_cast<TRIBE_Command*>(this->world->commands);
        command->command_make(object, obj_id);
        return 1;
    }
    return 0;
}

unsigned char TRIBE_Player::command_make_repair(RGE_Static_Object* obj) {
    short list_num;
    RGE_Static_Object** list;
    if (!(((obj->owner == this || this->isAlly(obj->owner->id))
           && obj->master_obj->master_type == TRIBE_MASTER_TYPE_BUILDING
           && static_cast<float>(obj->master_obj->hp) > obj->hp && obj->object_state < RGE_OBJECT_STATE_DYING)
          || ((obj->owner == this || (this->isAlly(obj->owner->id) && obj->owner->isAlly(this->id)))
              && (obj->master_obj->object_group == OBJECT_GROUP_TRADE_BOAT
                  || obj->master_obj->object_group == OBJECT_GROUP_TRANSPORT_BOAT
                  || obj->master_obj->object_group == OBJECT_GROUP_FISHING_BOAT
                  || obj->master_obj->object_group == OBJECT_GROUP_WAR_BOAT)
              && static_cast<float>(obj->master_obj->hp) > obj->hp && obj->object_state < RGE_OBJECT_STATE_DYING)))
        return 0;
    if (!this->get_selected_objects_to_command(&list, &list_num, 4, 4, -1, -1))
        return 0;
    RGE_Master_Static_Object* repair_master = list[0]->get_command_master(obj, 0.0f, 0.0f, 0.0f);
    if (repair_master != 0)
        repair_master->play_command_sound();
    static_cast<TRIBE_Command*>(this->world->commands)->command_repair(list, list_num, obj);
    free(list);
    return 1;
}

unsigned char TRIBE_Player::command_make_unload(float x, float y) {
    RGE_Static_Object** list;
    short unused_list_num;
    short list_num[2];

    if (get_selected_objects_to_command(&list, list_num, 4, -1, -1, 7)) {
        list[0]->play_command_sound();
        static_cast<TRIBE_Command*>(this->world->commands)->command_unload(list, list_num[0], x, y);
        free(list);
        return 1;
    }
    return 0;
}

unsigned char TRIBE_Player::check_obj_cost(short obj_id, short* attribute_needed, float modifier, int ignore_pop) {
    float gold_replace = this->attributes[RGE_RESOURCE_GOLD];
    if (attribute_needed != 0)
        *attribute_needed = static_cast<short>(-1);
    bool gold_replace_allowed;
    if (this->attributes[PLAYER_ATTRIBUTE_GOLD_REPLACEMENT] < 1.0) {
        gold_replace = 0.0f;
        gold_replace_allowed = false;
    } else {
        gold_replace_allowed = true;
    }
    RGE_Master_Static_Object* object = this->master_objects[obj_id];
    TRIBE_Master_Combat_Object* combat = static_cast<TRIBE_Master_Combat_Object*>(object);
    if (object == 0 || object->master_type < TRIBE_MASTER_TYPE_COMBAT) {
        if (attribute_needed != 0)
            *attribute_needed = static_cast<short>(-1);
        return 0;
    }
    for (int i = 0; i < 3; ++i) {
        int type = combat->build_inventory[i].type;
        if (type < 0)
            continue;
        float inventory_cost = combat->build_inventory[i].amount * modifier;
        if (type == PLAYER_ATTRIBUTE_POPULATION_HEADROOM && ignore_pop == 0
            && this->attributes[PLAYER_ATTRIBUTE_POPULATION] >= this->attributes[PLAYER_ATTRIBUTE_POPULATION_LIMIT]) {
            if (attribute_needed != 0)
                *attribute_needed = PLAYER_ATTRIBUTE_POPULATION_LIMIT;
            return 0;
        }
        if (gold_replace_allowed && type == RGE_RESOURCE_GOLD) {
            gold_replace -= inventory_cost;
            if (gold_replace < 0.0f) {
                if (attribute_needed != 0)
                    *attribute_needed = RGE_RESOURCE_GOLD;
                return 0;
            }
        }
        if (this->attributes[type] < inventory_cost
            && (type != PLAYER_ATTRIBUTE_POPULATION_HEADROOM || ignore_pop == 0)) {
            if (combat->build_inventory[i].flag == 0 || gold_replace + this->attributes[type] < inventory_cost) {
                if (attribute_needed != 0)
                    *attribute_needed = static_cast<short>(type);
                return 0;
            }
            gold_replace -= inventory_cost - this->attributes[type];
        }
    }
    return 1;
}

unsigned char TRIBE_Player::pay_obj_cost(short obj_id, float modifier, int ignore_pop) {
    if (check_obj_cost(obj_id, 0, modifier, ignore_pop)) {
        RGE_Master_Static_Object* object = this->master_objects[obj_id];
        TRIBE_Master_Combat_Object* combat = static_cast<TRIBE_Master_Combat_Object*>(object);
        for (int i = 0; i < 3; ++i) {
            int type = combat->build_inventory[i].type;
            if (type >= 0 && combat->build_inventory[i].flag != 0 && (ignore_pop == 0 || type != 4)) {
                float amount = combat->build_inventory[i].amount * modifier;
                if (amount > this->attributes[type]) {
                    this->attributes[RGE_RESOURCE_GOLD] -= amount - this->attributes[type];
                    this->attributes[type] = 0.0f;
                } else {
                    this->attributes[type] -= amount;
                }
            }
        }
        return 1;
    }
    return 0;
}

void TRIBE_Player::reimburse_obj_cost(short obj_id) {
    RGE_Master_Static_Object* object = this->master_objects[obj_id];
    TRIBE_Master_Combat_Object* combat = static_cast<TRIBE_Master_Combat_Object*>(object);
    if (object->master_type < TRIBE_MASTER_TYPE_COMBAT)
        return;
    Attribute_Cost* cost = combat->build_inventory;
    int i;
    short type;
    unsigned char flag;
    for (i = 0; i < 3; ++i) {
        if ((type = cost->type) >= 0 && (flag = cost->flag) != 0)
            this->attributes[type] += cost->amount;
        ++cost;
    }
}

unsigned char TRIBE_Player::check_tech_cost(short tech_id, short* attribute_needed) {
    return this->tech_tree->check_tech_cost(tech_id, attribute_needed);
}

unsigned char TRIBE_Player::pay_tech_cost(short tech_id) {
    return this->tech_tree->start_research(tech_id, 1, 0);
}

void TRIBE_Player::tech_abling(long tech_id, unsigned char able_flag) {
    if (able_flag != 0)
        this->tech_tree->enable(static_cast<short>(tech_id));
    else
        this->tech_tree->disable(static_cast<short>(tech_id));
}

void TRIBE_Player::rev_tech(long age) {
    switch (age) {
        case PLAYER_ATTRIBUTE_TOOL_AGE_TECH:
            this->tech_tree->do_tech(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_TOOL_AGE_TECH]));
            return;

        case PLAYER_ATTRIBUTE_BRONZE_AGE_TECH:
            this->tech_tree->disable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_BRONZE_AGE_TECH]));
            this->tech_tree->rev_tech(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_TOOL_AGE_TECH]));
            this->tech_tree->enable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_BRONZE_AGE_TECH]));
            this->tech_tree->do_tech(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_BRONZE_AGE_TECH]));
            return;

        case PLAYER_ATTRIBUTE_IRON_AGE_TECH:
            this->tech_tree->disable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_BRONZE_AGE_TECH]));
            this->tech_tree->disable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_IRON_AGE_TECH]));
            this->tech_tree->rev_tech(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_TOOL_AGE_TECH]));
            this->tech_tree->enable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_BRONZE_AGE_TECH]));
            this->tech_tree->rev_tech(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_BRONZE_AGE_TECH]));
            this->tech_tree->enable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_IRON_AGE_TECH]));
            this->tech_tree->do_tech(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_IRON_AGE_TECH]));
            return;

        case 1:
            this->tech_tree->disable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_BRONZE_AGE_TECH]));
            this->tech_tree->disable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_IRON_AGE_TECH]));
            this->tech_tree->rev_tech(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_TOOL_AGE_TECH]));
            this->tech_tree->enable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_BRONZE_AGE_TECH]));
            this->tech_tree->rev_tech(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_BRONZE_AGE_TECH]));
            this->tech_tree->enable(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_IRON_AGE_TECH]));
            this->tech_tree->rev_tech(static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_IRON_AGE_TECH]));
            return;

        default:
            return;
    }
}

void TRIBE_Player::add_population_entry() {
    if (this->attributes[PLAYER_ATTRIBUTE_POPULATION] < 0.0f) {
        this->history->add_history_entry(0, 0);
        return;
    }

    this->history->add_history_entry(0, static_cast<int>(this->attributes[PLAYER_ATTRIBUTE_POPULATION]));
}

void TRIBE_Player::random_start() {
    uchar found_ally = 0;

    if (this->objects->list == 0) {
        float w1;
        float h;
        w1 = ((debug_rand(tplayerSourceName, 1585) * (this->world->map->map_height - 0x1e)) / 0x7fff + 0xf) + 0.5f;
        h = ((debug_rand(tplayerSourceName, 1586) * (this->world->map->map_width - 0x1e)) / 0x7fff + 0xf) + 0.5f;
        int tries = 1;
        while (tries < 5000) {
            if (this->master_objects[MASTER_OBJECT_TOWN_CENTER1]->check_placement(
                    this, h + 0.5f, w1 + 0.5f, 0, 0, 1, 1, 1, 1, 1
                )
                == 0)
                break;
            w1 = ((debug_rand(tplayerSourceName, 1585) * (this->world->map->map_height - 0x1e)) / 0x7fff + 0xf) + 0.5f;
            h = ((debug_rand(tplayerSourceName, 1586) * (this->world->map->map_width - 0x1e)) / 0x7fff + 0xf) + 0.5f;
            ++tries;
        }

        if (tries < 5000) {
            TRIBE_Building_Object* town_center_object = static_cast<TRIBE_Building_Object*>(
                this->master_objects[MASTER_OBJECT_TOWN_CENTER1]->make_new_obj(this, h, w1, 0)
            );
            this->set_map_loc(static_cast<short>(h), static_cast<short>(w1));
            this->set_view_loc(h, w1);
            town_center_object->build(10000.0f);

            int count = 3;
            int w2;
            int h2;
            float w;
            float h1;
            do {
                uchar bad = 1;
                do {
                    w2 = (debug_rand(tplayerSourceName, 1606) * 6) / 0x7fff - 3;
                    h2 = (debug_rand(tplayerSourceName, 1607) * 6) / 0x7fff - 3;
                    w = w2 - debug_rand(tplayerSourceName, 1608) * -3.051851e-05f + w1;
                    h1 = h2 - debug_rand(tplayerSourceName, 1609) * -3.051851e-05f + h;

                    if (w >= 0.0f && w < static_cast<float>(this->world->map->map_height) && h1 >= 0.0f
                        && h1 < static_cast<float>(this->world->map->map_width)
                        && this->master_objects[MASTER_OBJECT_MAN]->check_placement(this, h1, w, 0, 0, 1, 1, 1, 1, 1)
                               == 0) {
                        this->master_objects[MASTER_OBJECT_MAN]->make_new_obj(this, h1, w, 0);
                        bad = 0;
                    }
                } while (bad);
                --count;
            } while (count != 0);
        }
    } else {
        RGE_Static_Object* town_center_object = this->objects->find_by_master_id(0x6d, 0.0f, 0.0f, 0, 0, 0);
        if (town_center_object == 0) {
            town_center_object = this->objects->list->node;
        }
        this->set_map_loc(
            static_cast<short>(town_center_object->world_x), static_cast<short>(town_center_object->world_y)
        );
        this->set_view_loc(town_center_object->world_x, town_center_object->world_y);
    }

    if (rge_base_game->multiplayerGame() || rge_base_game->randomGame()) {
        for (int i = 1; i < this->world->player_num; ++i) {
            if (this->isAlly(i) && i != this->id) {
                RGE_Static_Object* town_center_object = this->objects->find_by_master_id(0x6d, 0.0f, 0.0f, 0, 0, 0);
                if (town_center_object == 0) {
                    town_center_object = this->objects->list->node;
                }
                if (town_center_object != 0) {
                    town_center_object->explore_terrain(this->world->players[i], 0, -1);
                    town_center_object->unexplore_terrain(this->world->players[i], 0, -1);
                }
                this->world->players[i]->make_new_object(MASTER_OBJECT_FLARE, this->view_x, this->view_y, 0, 0);
                found_ally = 1;
            }
        }
    }

    if (this->world->curr_player == this->id && found_ally) {
        for (int i = 1; i < this->world->player_num; ++i) {
            if (i != this->id) {
                for (int j = 1; j < 9; ++j) {
                    if (rge_base_game->playerID(j) == i) {
                        chat->setInChatGroup(j, this->isAlly(i));
                    }
                }
            }
        }
    }
}

void TRIBE_Player::objectCost(int id, int unused1, ResourceItem* ri, int unused2) {
    short object = static_cast<short>(id);
    short inv_amt_3;
    short inv_amt_1;
    short inv_1;
    short inv_2;
    short amt2;
    short inv_3;
    short inv_amt_2;

    this->obj_cost(object, 0, inv_2, inv_amt_1, inv_3, inv_amt_2, inv_1, inv_amt_3, 1.0f);
    ri->incrementValue(inv_2, inv_amt_1);
    ri->incrementValue(inv_3, inv_amt_2);
    ri->incrementValue(inv_1, inv_amt_3);
}

int TRIBE_Player::objectCostByType(int id) {
    short inv_3;
    short inv_amt_1;
    short inv_2;
    short inv_1;
    short inv_amt_2;
    short inv_amt_3;

    obj_cost(static_cast<short>(id), 0, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3, 1.0f);
    return inv_amt_1 + inv_amt_2 + inv_amt_3;
}

void TRIBE_Player::researchCost(int id, int unused1, ResourceItem* ri, int unused2) {
    short technology = static_cast<short>(id);
    short unused_amount;
    short inv_amt_1;
    short inv_2;
    short inv_amt_3;
    short inv_3;
    short inv_1;
    short inv_amt_2;

    this->tech_tree->tech_cost(technology, inv_2, inv_amt_1, inv_3, inv_amt_3, inv_1, inv_amt_2);
    ri->incrementValue(inv_2, inv_amt_1);
    ri->incrementValue(inv_3, inv_amt_3);
    ri->incrementValue(inv_1, inv_amt_2);
}

int TRIBE_Player::objectAvailable(int id) {
    RGE_Master_Static_Object** objects = this->master_objects;
    RGE_Master_Static_Object* object = objects[id];
    if ((object != 0 && object->available) || id == MASTER_OBJECT_TOWN_CENTER1)
        return 1;
    return 0;
}

int TRIBE_Player::researchAvailable(int id) {
    return this->tech_tree->tech_player_tree[id].state == 1;
}

int TRIBE_Player::researchEverAvailable(int id) {
    short state;

    TRIBE_Player_Tech* tech = this->tech_tree;
    state = tech->get_tech_state(static_cast<short>(id));
    if (state != 3 && state != -1)
        return 1;
    return 0;
}

unsigned char TRIBE_Player::researchState(int id) {
    TRIBE_Player_Tech* tech = this->tech_tree;
    return static_cast<unsigned char>(tech->get_tech_state(static_cast<short>(id)));
}

void TRIBE_Player::changeToHumanPlayer() {
}

void TRIBE_Player::changeToComputerPlayer() {
}

char* TRIBE_Player::aiStatus(int sNum) {
    if (this->playerAI == 0) {
        if (this->world->currentUpdateComputerPlayer != -1) {
            RGE_Player* otherPlayer = this->world->players[this->world->currentUpdateComputerPlayer];
            if (otherPlayer != 0) {
                TribeMainDecisionAIModule* ai = static_cast<TRIBE_Player*>(otherPlayer)->playerAI;
                int last = ai->tacticalAI.lastUpdateAreaTimeValue;
                int avg = ai->tacticalAI.averageUpdateAreaTimeValue;
                sprintf(
                    this->aiStatusInformationValue, "ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s.",
                    static_cast<TRIBE_World*>(this->world)->controllingComputerPlayer,
                    this->world->currentUpdateComputerPlayer, avg, last, ai->tacticalAI.updateAreaName()
                );
                return this->aiStatusInformationValue;
            }
        }
        return "Invalid currentUpdateComputerPlayer...";
    }
    if (sNum == 1) {
        sprintf(
            this->aiStatusInformationValue, "Build List:%s, City Plan:%s, BuildAI(C=%s, N=%s, L=%s, %d/%d).",
            this->playerAI->buildAI.buildListName(), this->playerAI->constructionAI.constructionPlanName(),
            this->playerAI->buildAI.currentBuildItemRequested(), this->playerAI->buildAI.nextBuildItemRequested(),
            this->playerAI->buildAI.lastBuildItemRequested(), this->playerAI->buildAI.numberItemsIntoBuildList(),
            this->playerAI->buildAI.buildListLength()
        );
        return this->aiStatusInformationValue;
    }
    if (sNum == 2) {
        sprintf(
            this->aiStatusInformationValue2,
            "NeedRes: %s=%d, %s=%d, %s=%d, %s=%d, ResDiff: %s=%d, %s=%d, %s=%d, %s=%d.",
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)),
            this->playerAI->tacticalAI.neededResourceAmount(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)),
            this->playerAI->tacticalAI.neededResourceAmount(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)),
            this->playerAI->tacticalAI.neededResourceAmount(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)),
            this->playerAI->tacticalAI.neededResourceAmount(3),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)),
            this->playerAI->tacticalAI.resourceDifference(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)),
            this->playerAI->tacticalAI.resourceDifference(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)),
            this->playerAI->tacticalAI.resourceDifference(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)),
            this->playerAI->tacticalAI.resourceDifference(3)
        );
        return this->aiStatusInformationValue2;
    }
    if (sNum == 3) {
        sprintf(
            this->aiStatusInformationValue3,
            "Gat(Act/Des): %s=(%d/%d), %s=(%d/%d), %s=(%d/%d), %s=(%d/%d).  #Civs=%d, #Sol=%d, #Boats=%d.",
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)),
            this->playerAI->tacticalAI.actualGathererCount(0), this->playerAI->tacticalAI.desiredGathererCount(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)),
            this->playerAI->tacticalAI.actualGathererCount(1), this->playerAI->tacticalAI.desiredGathererCount(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)),
            this->playerAI->tacticalAI.actualGathererCount(2), this->playerAI->tacticalAI.desiredGathererCount(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)),
            this->playerAI->tacticalAI.actualGathererCount(3), this->playerAI->tacticalAI.desiredGathererCount(3),
            this->playerAI->tacticalAI.numberCivilians(), this->playerAI->tacticalAI.numberSoldiers(),
            this->playerAI->tacticalAI.numberBoats()
        );
        return this->aiStatusInformationValue3;
    }
    if (sNum == 4) {
        // Wood and Gold show the swapped build-plan numbers; see TribeTacticalAIModule's gatherer distribution.
        sprintf(
            this->aiStatusInformationValue4, "Pers (Spec/BL): Food=(%d/%d), Wood=(%d/%d), Gold=(%d/%d), Stone=(%d/%d).",
            this->playerAI->tacticalAI.strategicNumber(SNFoodGathererPercentage),
            this->playerAI->tacticalAI.strategicNumber(SNBuildPlanFoodGathererPercentage),
            this->playerAI->tacticalAI.strategicNumber(SNWoodGathererPercentage),
            this->playerAI->tacticalAI.strategicNumber(SNBuildPlanGoldGathererPercentage),
            this->playerAI->tacticalAI.strategicNumber(SNGoldGathererPercentage),
            this->playerAI->tacticalAI.strategicNumber(SNBuildPlanWoodGathererPercentage),
            this->playerAI->tacticalAI.strategicNumber(SNStoneGathererPercentage),
            this->playerAI->tacticalAI.strategicNumber(SNBuildPlanStoneGathererPercentage)
        );
        return this->aiStatusInformationValue4;
    }
    if (sNum == 5) {
        sprintf(
            this->aiStatusInformationValue5,
            "Dip: P1(%d/%d/%d), P2(%d/%d/%d), P3(%d/%d/%d), P4(%d/%d/%d), P5(%d/%d/%d), P6(%d/%d/%d), P7(%d/%d/%d), P8(%d/%d/%d).",
            this->playerAI->diplomacyAI.stance(1, 0), this->playerAI->diplomacyAI.stance(1, 1),
            this->playerAI->diplomacyAI.stance(1, 2), this->playerAI->diplomacyAI.stance(2, 0),
            this->playerAI->diplomacyAI.stance(2, 1), this->playerAI->diplomacyAI.stance(2, 2),
            this->playerAI->diplomacyAI.stance(3, 0), this->playerAI->diplomacyAI.stance(3, 1),
            this->playerAI->diplomacyAI.stance(3, 2), this->playerAI->diplomacyAI.stance(4, 0),
            this->playerAI->diplomacyAI.stance(4, 1), this->playerAI->diplomacyAI.stance(4, 2),
            this->playerAI->diplomacyAI.stance(5, 0), this->playerAI->diplomacyAI.stance(5, 1),
            this->playerAI->diplomacyAI.stance(5, 2), this->playerAI->diplomacyAI.stance(6, 0),
            this->playerAI->diplomacyAI.stance(6, 1), this->playerAI->diplomacyAI.stance(6, 2),
            this->playerAI->diplomacyAI.stance(7, 0), this->playerAI->diplomacyAI.stance(7, 1),
            this->playerAI->diplomacyAI.stance(7, 2), this->playerAI->diplomacyAI.stance(8, 0),
            this->playerAI->diplomacyAI.stance(8, 1), this->playerAI->diplomacyAI.stance(8, 2)
        );
        return this->aiStatusInformationValue5;
    }
    if (sNum == 6) {
        TribeMainDecisionAIModule* ai =
            static_cast<TRIBE_Player*>(this->world->players[this->world->currentUpdateComputerPlayer])->playerAI;
        int last = ai->tacticalAI.lastUpdateAreaTimeValue;
        int avg = ai->tacticalAI.averageUpdateAreaTimeValue;
        int attackEnabled = this->playerAI->tacticalAI.attackEnabledValue;
        sprintf(
            this->aiStatusInformationValue6,
            "Per: %s, AttEnab=%d, AttDly=%d Min, ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s.",
            this->playerAI->strategyAI.ruleSetName(), attackEnabled,
            this->playerAI->tacticalAI.strategicNumber(SNInitialAttackDelay) / 60,
            static_cast<TRIBE_World*>(this->world)->controllingComputerPlayer, this->world->currentUpdateComputerPlayer,
            avg, last, ai->tacticalAI.updateAreaName()
        );
        return this->aiStatusInformationValue6;
    }
    return "Invalid status line number.";
}

void TRIBE_Player::kickAI(int m) {
    TribeMainDecisionAIModule* ai = this->playerAI;
    if (ai)
        ai->kick(m);
}

int TRIBE_Player::strategicNumber(int sN) {
    TribeMainDecisionAIModule* ai = this->playerAI;
    if (ai) {
        return ai->tacticalAI.strategicNumber(sN);
    }
    return -1;
}

void __cdecl TRIBE_Player::logMessage(char* textIn, ...) {
    char textOut[1024];

    if (this->playerAI != 0) {
        va_list args;
        va_start(args, textIn);
        vsprintf(textOut, textIn, args);
        va_end(args);
        this->playerAI->logCommonHistory(textOut);
    }
}

int TRIBE_Player::sendAICommand(int caller, int mType, int p1, int p2, int p3) {
    TribeMainDecisionAIModule* ai = this->playerAI;
    if (!ai)
        return 0;
    return ai->processAICommand(caller, mType, p1, p2, p3);
}

RGE_Object_Node* TRIBE_Player::addObject(RGE_Static_Object* obj, int sleepFlag, int dopple_flag) {
    RGE_Object_Node* node = RGE_Player::addObject(obj, sleepFlag, dopple_flag);
    if (obj->master_obj->object_group == 0x0B) {
        return node;
    }
    if (this->playerAI == 0) {
        return node;
    }
    if (obj->id < 0) {
        return node;
    }
    this->playerAI->addObject(obj);
    int flag = 1;
    if (this->world->game_state == 2) {
        flag = 0;
    }
    this->playerAI->buildAI.addItem(obj, flag);
    return node;
}

void TRIBE_Player::removeObject(RGE_Static_Object* obj, int sleepFlag, int dopple_flag, RGE_Object_Node* node) {
    RGE_Player::removeObject(obj, sleepFlag, dopple_flag, node);

    if (this->playerAI) {
        short grp = obj->master_obj->object_group;
        if (grp != 0x0B && obj->id >= 0) {
            this->playerAI->removeObject(obj->id);
        }
    }
}

void TRIBE_Player::buildObject(int bi, int oi, float x, float y, int ui) {
    int* objectId = static_cast<int*>(calloc(1, 4));
    *objectId = bi;
    static_cast<TRIBE_Command*>(this->world->commands)->command_build(this->id, objectId, 1, oi, x, y, ui);
    free(objectId);
}

void TRIBE_Player::cancelBuild(
    int reason, int blockerID, int blockerType, float x, float y, int uniqueID, int builderID
) {
    if (this->playerAI != 0) {
        this->playerAI->buildAI.cancelBuildItem(reason, blockerID, blockerType, x, y, uniqueID, builderID);
    }
}

void TRIBE_Player::registerBuild(RGE_Static_Object* obj, int uniqueID) {
    TribeMainDecisionAIModule* ai = this->playerAI;
    if (!ai)
        return;
    ai->buildAI.addBuiltItem(obj, uniqueID);
}

void TRIBE_Player::trainUnit(int uType, int bID, int uniqueID) {
    short player_id = this->id;
    TRIBE_Command* command = static_cast<TRIBE_Command*>(this->world->commands);
    command->command_make(player_id, bID, uType, uniqueID);
}

void TRIBE_Player::cancelTrain(int reason, int uType, int location, int uniqueID) {
    TribeMainDecisionAIModule* ai = this->playerAI;
    if (!ai) {
        return;
    }
    ai->buildAI.cancelTrainUnit(reason, uType, location, uniqueID);
}

void TRIBE_Player::registerTrain(int uType, int location, int uniqueID, int gameID) {
    TribeMainDecisionAIModule* ai = this->playerAI;
    if (!ai) {
        return;
    }
    ai->buildAI.addTrainedUnit(uType, location, uniqueID, gameID);
}

void TRIBE_Player::research(int rType, int bID, int uniqueID) {
    short player_id = this->id;
    TRIBE_Command* command = static_cast<TRIBE_Command*>(this->world->commands);
    command->command_research(player_id, bID, rType, uniqueID);
}

void TRIBE_Player::cancelResearch(int reason, int rType, int location, int uniqueID) {
    TribeMainDecisionAIModule* ai = this->playerAI;
    if (!ai) {
        return;
    }
    ai->buildAI.cancelResearch(reason, rType, location, uniqueID);
}

void TRIBE_Player::registerResearch(int rType, int location, int uniqueID) {
    TribeMainDecisionAIModule* ai = this->playerAI;
    if (!ai)
        return;
    ai->buildAI.addResearch(rType, location, uniqueID);
}

void TRIBE_Player::taskTrader(int tID, int oID, int ownerID, float x, float y) {
    int* task = static_cast<int*>(calloc(1, 4));
    *task = tID;
    static_cast<TRIBE_Command*>(this->world->commands)->command_work(this->id, task, 1, oID, ownerID, x, y);
    free(task);
}

void TRIBE_Player::taskResourceGatherer(int gID, int oID, int ownerID, float x, float y) {
    int* task = static_cast<int*>(calloc(1, 4));
    *task = gID;
    static_cast<TRIBE_Command*>(this->world->commands)->command_work(this->id, task, 1, oID, ownerID, x, y);
    free(task);
}

void TRIBE_Player::setDiplomaticStance(int playerNum, int rType) {
    static_cast<TRIBE_Command*>(this->world->commands)
        ->command_relation(this->id, static_cast<short>(playerNum), static_cast<short>(rType));
}

void TRIBE_Player::loadAIInformation(char* bL, char* cP, char* rS, int mood, int mapType) {
    char noneString[256];
    char randomString[256];
    char ruleSetName[256];
    char buildListName[256];

    int saveRand;
    int save_debug_random_on;
    saveRand = debug_rand(tplayerSourceName, 2147);
    save_debug_random_on = debug_random_on;
    global_save_debug_random_on2 = save_debug_random_on;
    debug_random_on = 0;

    if (this->playerAI) {
        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapType()) {
            case TRIBE_Game::AllWater:
                this->playerAI->logCommonHistory("We have an all water map.");
                break;
            case TRIBE_Game::MostlyWater:
                this->playerAI->logCommonHistory("We have a mostly water map.");
                break;
            case TRIBE_Game::WaterAndLand:
                this->playerAI->logCommonHistory("We have a land and water map.");
                break;
            case TRIBE_Game::MostlyLand:
                this->playerAI->logCommonHistory("We have a mostly land map.");
                break;
            case TRIBE_Game::AllLand:
                this->playerAI->logCommonHistory("We have an all land map.");
                break;
            default:
                this->playerAI->logCommonHistory("We don't have a specific map type (i.e. this is a scenario).");
                break;
        }
        rge_base_game->get_string(STRING_ID_FILE_NONE, noneString, 256);
        rge_base_game->get_string(STRING_ID_AI_FILE_RANDOM, randomString, 256);

        strcpy(buildListName, s_empty_string);
        strcpy(ruleSetName, s_empty_string);

        if (bL) {
            if (strcmp(bL, randomString) == 0) {
                do {
                    this->intelligentBuildListAndRulesSelection(
                        buildListName, ruleSetName, static_cast<TRIBE_Game*>(rge_base_game)->mapType(),
                        static_cast<TRIBE_Game*>(rge_base_game)->victoryType(),
                        static_cast<TRIBE_Game*>(rge_base_game)->mapSize()
                    );
                    this->playerAI->logCommonHistory("Loading random game selected build list=%s.", buildListName);
                } while (this->playerAI->buildAI.loadBuildList(buildListName, this) == 0);
            } else {
                this->playerAI->logCommonHistory("Loading build list=%s.", bL);
                this->playerAI->buildAI.loadBuildList(bL, this);
            }
        } else {
            do {
                this->intelligentBuildListAndRulesSelection(
                    buildListName, ruleSetName, static_cast<TRIBE_Game*>(rge_base_game)->mapType(),
                    static_cast<TRIBE_Game*>(rge_base_game)->victoryType(),
                    static_cast<TRIBE_Game*>(rge_base_game)->mapSize()
                );
                this->playerAI->logCommonHistory("Loading default build list=%s.", buildListName);
            } while (this->playerAI->buildAI.loadBuildList(buildListName, this) == 0);
        }

        if (cP != 0) {
            if (strcmp(cP, randomString) == 0) {
                this->playerAI->logCommonHistory("Loading no city plan (influence placement will be used).");
            } else {
                this->playerAI->logCommonHistory("Loading city plan=%s.", cP);
                this->playerAI->constructionAI.loadConstructionPlan(
                    cP, this->world->map->map_width, this->world->map->map_height, 0, 0, 0
                );
                goto constructionLoaded;
            }
        } else {
            this->playerAI->logCommonHistory("Loading no city plan (influence placement will be used).");
        }
        this->playerAI->constructionAI.loadConstructionPlan(
            "NONE", this->world->map->map_width, this->world->map->map_height, 0, 0, 0
        );

    constructionLoaded:

        if (rS && strcmp(rS, randomString) != 0) {
            this->playerAI->logCommonHistory("Loading rule set=%s.", rS);
            this->playerAI->strategyAI.loadRules(rS);
        } else if (strcmp(ruleSetName, tplayerRandomName) != 0) {
            this->playerAI->logCommonHistory("Loading random game selected rule set=%s.", ruleSetName);
            this->playerAI->strategyAI.loadRules(ruleSetName);
        } else {
            this->playerAI->logCommonHistory("Rule set has been initialized with code-controlled options.");
        }

        int r = rge_base_game->difficulty();
        this->playerAI->logCommonHistory("Setting difficulty level to %d.", r);
        this->playerAI->strategyAI.setDifficultyLevel(r);
        this->playerAI->updateBuildAIWithObjects();

        for (int i = 1; i < this->world->player_num; ++i) {
            if (i == this->id) {
                this->playerAI->diplomacyAI.setStance(i, 0, 0);
                this->playerAI->diplomacyAI.setStance(i, 2, 100);
            } else if (this->isEnemy(i)) {
                this->playerAI->diplomacyAI.setStance(i, 0, 0x4A);
                this->playerAI->diplomacyAI.setStance(i, 2, 0x18);
            } else if (this->isAlly(i)) {
                this->playerAI->diplomacyAI.setStance(i, 0, 0x18);
                this->playerAI->diplomacyAI.setStance(i, 2, 0x4A);
            }
        }

        for (int j = 1; j < this->world->player_num; ++j) {
            if (!this->isEnemy(j) && !this->isAlly(j))
                this->playerAI->diplomacyAI.setChangeable(j, 1);
            else
                this->playerAI->diplomacyAI.setChangeable(j, 0);
        }

        this->playerAI->emotionalAI.setOverallState(mood);
        char* learn = this->world->scenario->scenario_name;
        if (learn && strlen(learn) != 0)
            this->playerAI->informationAI.loadLearnInfo(learn);
    }

    debug_random_on = save_debug_random_on;
    debug_srand(tplayerSourceName, 2301, saveRand);
}

extern int global_save_debug_random_on3;
extern int global_save_debug_random_on4;

void TRIBE_Player::notify(int caller, int recipient, int mType, long p1, long p2, long p3) {
    RGE_Static_Object* attackingObject;
    switch (mType) {
        case 0x201:
            if (this->update_count == 0) {
                this->update_count = 20;
                attackingObject = this->world->object(p1);
                if (attackingObject != 0) {
                    int seed = debug_rand(tplayerSourceName, 2336);
                    int saved = debug_random_on;
                    debug_random_on = 0;
                    global_save_debug_random_on3 = saved;
                    if (this->world->curr_player == this->id) {
                        //! @bug The alert sound index comes from attribute 26 with no validation or default.
                        //! The gaia master row leaves attribute 26 at 0, so player 0 plays sounds[0].
                        //! Normal players play the attack sound. This runs when player 0 is current.
                        RGE_Sound* sound =
                            this->world
                                ->sounds[static_cast<short>(this->attributes[PLAYER_ATTRIBUTE_ATTACK_WARNING_SOUND])];
                        if (sound != 0)
                            sound->play(1);
                        static_cast<TRIBE_Game*>(rge_base_game)
                            ->add_notification_loc(
                                static_cast<long>(attackingObject->world_x), static_cast<long>(attackingObject->world_y)
                            );
                    }
                    debug_random_on = saved;
                    debug_srand(tplayerSourceName, 2353, seed);
                }
            }
            break;
        //! @bug The transport-failure message types are swapped. A transport that still holds units after
        //! unloading (0x206) shows "You cannot trade with an enemy", and a failed trade (0x20C) shows "Not
        //! enough room to unload all." The original dispatch (005159D0) sends these same types.
        case 0x20C:
            if (p1 == UNIT_AI_ACTION_TRADE)
                static_cast<TRIBE_Game*>(rge_base_game)
                    ->notification(GAME_NOTIFY_NOT_ENOUGH_UNLOAD_SPACE, this->id, 0, 0, 0);
            break;
        case 0x207:
            static_cast<TRIBE_Game*>(rge_base_game)
                ->notification(GAME_NOTIFY_NOT_CLOSE_ENOUGH_TO_LAND, this->id, 0, 0, 0);
            break;
        case 0x206:
            static_cast<TRIBE_Game*>(rge_base_game)
                ->notification(GAME_NOTIFY_CANNOT_TRADE_WITH_ENEMY, this->id, 0, 0, 0);
            break;
    }
    int seed = debug_rand(tplayerSourceName, 2377);
    int saved = debug_random_on;
    global_save_debug_random_on4 = saved;
    debug_random_on = 0;
    if (this->playerAI != 0)
        this->notifyAI(caller, recipient, mType, p1, p2, p3);
    debug_random_on = saved;
    debug_srand(tplayerSourceName, 2390, seed);
}

void TRIBE_Player::notifyAI(int callerID, int recipientID, int mType, long p1, long p2, long p3) {
    RGE_Static_Object* obj = this->world->object(callerID);
    if (mType != 0x20a && mType != 0x72 && mType != 0x74) {
        if (obj == 0)
            return;
        if (obj->unitAI() == 0)
            return;
    }

    switch (mType) {
        case UNIT_AI_NOTIFY_ACTION_FAILED:
            if (p1 != UNIT_AI_ACTION_EXPLORE)
                return;
            {
                TacticalAIGroup* group = this->playerAI->tacticalAI.groupUnitIsIn(callerID);
                if (group == 0)
                    return;
                if (group->type() != TACTICAL_GROUP_TYPE_FISHING)
                    return;
                this->playerAI->tacticalAI.removeGroup(group->id());
                return;
            }
        case UNIT_AI_NOTIFY_REQUEST_TASK: {
            float unY;
            float unX;
            switch (p1) {
                case UNIT_AI_ACTION_EXPLORE:
                case UNIT_AI_ACTION_EXPLORE_AND_DESTROY:
                    if (this->playerAI->informationAI.fullyExploredZone(callerID) != 0
                        && this->playerAI->informationAI.closestUnexploredTile(
                               callerID, obj->world_x, obj->world_y, &unY, &unX
                           ) == 1) {
                        this->playerAI->tacticalAI.taskExplorer(callerID, unY, unX);
                        return;
                    }
                    this->playerAI->tacticalAI.detask(callerID);
                    return;
            }
            break;
        }
        case 0x209:
            obj = this->world->object(p1);
            if (obj != 0) {
                this->playerAI->diplomacyAI.changeStance(obj->owner->id, 0, 10);
                return;
            }
            break;
        case 0x20a:
            this->playerAI->tributeNotify(callerID, p1, p2);
            return;
        case 0x72:
        case 0x74:
        case 0x201:
            this->playerAI->tacticalAI.notify(callerID, recipientID, mType, p1, p2, p3);
            return;
        case 0x20d:
            this->playerAI->informationAI.addImportantObject(p1);
            break;
    }
}

int TRIBE_Player::intelligentCivSelection(int mapType, int gameType, int mapSize) {
    return 0;
}

void TRIBE_Player::intelligentBuildListAndRulesSelection(char* b, char* r, int mapType, int gameType, int mapSize) {
    int i;
    int difficultyLevel;
    int buildLists[125];
    int mostBuiltUnit2;
    char tempString[256];

    if (this->playerAI == 0) {
        return;
    }

    difficultyLevel = rge_base_game->difficulty();
    memset(buildLists, 0, sizeof(buildLists));

    switch (this->master_player_id) {
        case CIVILIZATION_EGYPTIAN:
            this->setupEgyptian(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_GREEK:
            this->setupGreek(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_BABYLONIAN:
            this->setupBabylonian(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_ASSYRIAN:
            this->setupAssyrian(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_MINOAN:
            this->setupMinoan(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_HITTITE:
            this->setupHittite(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_PHOENICIAN:
            this->setupPhoenician(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_SUMERIAN:
            this->setupSumerian(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_PERSIAN:
            this->setupPersian(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_SHANG:
            this->setupShang(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_YAMATO:
            this->setupYamato(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_CHOSON:
            this->setupChoson(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_ROMAN:
            this->setupRoman(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_CARTHAGINIAN:
            this->setupCarthaginian(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_PALMYRAN:
            this->setupPalmyran(buildLists, mapType, gameType, mapSize);
            break;
        case CIVILIZATION_MACEDONIAN:
            this->setupMacedonian(buildLists, mapType, gameType, mapSize);
            break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 0) {
        int civ = this->master_player_id - 1;
        if (civ == (CIVILIZATION_ASSYRIAN - 1) || civ == (CIVILIZATION_EGYPTIAN - 1) || civ == (CIVILIZATION_GREEK - 1)
            || civ == (CIVILIZATION_MINOAN - 1) || civ == (CIVILIZATION_PERSIAN - 1)
            || civ == (CIVILIZATION_PHOENICIAN - 1) || civ == (CIVILIZATION_SUMERIAN - 1)
            || civ == (CIVILIZATION_YAMATO - 1)) {
            int aggressiveSelections = tplayer_globals::aggressiveBuildListCount;
            int selectedBuildLists = tplayer_globals::selectedBuildListCount;
            if (mapType == TRIBE_Game::AllWater) {
                if (selectedBuildLists > 0) {
                    if (aggressiveSelections == 0) {
                        buildLists[BUILD_LIST_TRIREME_BRONZE] += 300;
                        buildLists[BUILD_LIST_TRIREME_IRON] += 300;
                    } else {
                        buildLists[BUILD_LIST_TRIREME_BRONZE] += 100;
                        buildLists[BUILD_LIST_TRIREME_IRON] += 100;
                    }
                } else {
                    buildLists[BUILD_LIST_TRIREME_BRONZE] = 0;
                    buildLists[BUILD_LIST_TRIREME_IRON] = 0;
                }
            }
            if (mapType == TRIBE_Game::MostlyWater) {
                if (selectedBuildLists > 0) {
                    if (aggressiveSelections == 0) {
                        buildLists[BUILD_LIST_TRIREME_BRONZE] += 250;
                        buildLists[BUILD_LIST_TRIREME_IRON] += 250;
                    } else {
                        buildLists[BUILD_LIST_TRIREME_BRONZE] += 75;
                        buildLists[BUILD_LIST_TRIREME_IRON] += 75;
                    }
                } else {
                    buildLists[BUILD_LIST_TRIREME_BRONZE] = 0;
                    buildLists[BUILD_LIST_TRIREME_IRON] = 0;
                }
            }
            if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas) {
                if (selectedBuildLists > 0) {
                    if (aggressiveSelections == 0) {
                        buildLists[BUILD_LIST_TRIREME_BRONZE] += 200;
                        buildLists[BUILD_LIST_TRIREME_IRON] += 200;
                    } else {
                        buildLists[BUILD_LIST_TRIREME_BRONZE] += 50;
                        buildLists[BUILD_LIST_TRIREME_IRON] += 50;
                    }
                } else {
                    buildLists[BUILD_LIST_TRIREME_BRONZE] = 0;
                    buildLists[BUILD_LIST_TRIREME_IRON] = 0;
                }
            }
        }
    }

    this->playerAI->strategyAI.setRule(0xC9, 1);

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 0) {
        int mostBuiltUnit1;

        mostBuiltUnit1 = -1;
        mostBuiltUnit2 = -1;
        this->playerAI->informationAI.loadUnitHistory();
        this->playerAI->informationAI.unitsThatAreMostBuilt(mostBuiltUnit1, mostBuiltUnit2);
        switch (mostBuiltUnit1) {
            case 0:
                buildLists[BUILD_LIST_CAVALRY_BRONZE] += 25;
                buildLists[BUILD_LIST_CAVALRY_IRON] += 25;
                break;
            case 1:
                buildLists[BUILD_LIST_CAVALRY_BRONZE] += 30;
                buildLists[BUILD_LIST_CAVALRY_IRON] += 30;
                break;
            case 2:
                buildLists[BUILD_LIST_WAR_ELEPHANT_IRON] += 20;
                buildLists[BUILD_LIST_ELEPHANT_ARCHER_IRON] += 20;
                buildLists[BUILD_LIST_PHALANX_BRONZE] += 40;
                buildLists[BUILD_LIST_PHALANX_IRON] += 40;
                break;
            case 3:
                buildLists[BUILD_LIST_ARCHERS_BRONZE] += 40;
                buildLists[BUILD_LIST_ARCHERS_IRON] += 20;
                buildLists[BUILD_LIST_PRIEST_BRONZE] += 20;
                buildLists[BUILD_LIST_PRIEST_IRON] += 20;
                buildLists[BUILD_LIST_WAR_ELEPHANT_IRON] -= 60;
                buildLists[BUILD_LIST_ELEPHANT_ARCHER_IRON] -= 60;
                break;
            case 4:
                buildLists[BUILD_LIST_CAVALRY_BRONZE] += 15;
                buildLists[BUILD_LIST_CAVALRY_IRON] += 15;
                buildLists[BUILD_LIST_PRIEST_BRONZE] += 20;
                buildLists[BUILD_LIST_PRIEST_IRON] += 20;
                break;
            case 5:
                buildLists[BUILD_LIST_CAVALRY_BRONZE] += 15;
                buildLists[BUILD_LIST_CAVALRY_IRON] += 15;
                buildLists[BUILD_LIST_ARCHERS_BRONZE] += 10;
                buildLists[BUILD_LIST_ARCHERS_IRON] += 10;
                break;
            case 6:
                buildLists[BUILD_LIST_CAVALRY_BRONZE] += 15;
                buildLists[BUILD_LIST_CAVALRY_IRON] += 15;
                break;
            case 7:
            case 10:
                buildLists[BUILD_LIST_PRIEST_BRONZE] -= 60;
                buildLists[BUILD_LIST_PRIEST_IRON] -= 60;
                break;
            case 8:
                buildLists[BUILD_LIST_PRIEST_BRONZE] += 40;
                buildLists[BUILD_LIST_PRIEST_IRON] += 40;
                if (tplayer_globals::selectedBuildListCount > 0) {
                    buildLists[BUILD_LIST_TRIREME_BRONZE] += 50;
                    buildLists[BUILD_LIST_TRIREME_IRON] += 50;
                }
                break;
            case 9:
                buildLists[BUILD_LIST_PRIEST_BRONZE] += 100;
                buildLists[BUILD_LIST_PRIEST_IRON] += 100;
                break;
        }
    }

    for (i = 0; i < 7; ++i) {
        switch (i) {
            case 0:
                if (buildLists[BUILD_LIST_PRIEST_BRONZE] > 0) {
                    buildLists[BUILD_LIST_PRIEST_BRONZE] /= 3;
                }
                if (buildLists[BUILD_LIST_PRIEST_IRON] > 0) {
                    buildLists[BUILD_LIST_PRIEST_IRON] /= 3;
                }
                if (buildLists[BUILD_LIST_PRIEST_WALLS] > 0) {
                    buildLists[BUILD_LIST_PRIEST_WALLS] /= 3;
                }
                break;
            case 1:
                if (buildLists[BUILD_LIST_CAVALRY_BRONZE] > 0) {
                    buildLists[BUILD_LIST_CAVALRY_BRONZE] /= 3;
                }
                if (buildLists[BUILD_LIST_CAVALRY_IRON] > 0) {
                    buildLists[BUILD_LIST_CAVALRY_IRON] /= 3;
                }
                if (buildLists[BUILD_LIST_CAVALRY_WALLS] > 0) {
                    buildLists[BUILD_LIST_CAVALRY_WALLS] /= 3;
                }
                if (buildLists[BUILD_LIST_YAMATO_HEAVY_CAVALRY] > 0) {
                    buildLists[BUILD_LIST_YAMATO_HEAVY_CAVALRY] /= 3;
                }
                if (buildLists[BUILD_LIST_SUMERIA_SCOUTS] > 0) {
                    buildLists[BUILD_LIST_SUMERIA_SCOUTS] /= 3;
                }
                if (buildLists[BUILD_LIST_SHANG_HEAVY_CAVALRY] > 0) {
                    buildLists[BUILD_LIST_SHANG_HEAVY_CAVALRY] /= 3;
                }
                if (buildLists[BUILD_LIST_SHANG_CAVALRY] > 0) {
                    buildLists[BUILD_LIST_SHANG_CAVALRY] /= 3;
                }
                if (buildLists[BUILD_LIST_MACEDON_CAVALRY] > 0) {
                    buildLists[BUILD_LIST_MACEDON_CAVALRY] /= 3;
                }
                break;
            case 2:
                if (buildLists[BUILD_LIST_CAV_ARCHER_IRON] > 0) {
                    buildLists[BUILD_LIST_CAV_ARCHER_IRON] /= 3;
                }
                if (buildLists[BUILD_LIST_HITTITE_HORSE_ARCHERS] > 0) {
                    buildLists[BUILD_LIST_HITTITE_HORSE_ARCHERS] /= 3;
                }
                if (buildLists[BUILD_LIST_PALMYRA_HORSE_ARCHER] > 0) {
                    buildLists[BUILD_LIST_PALMYRA_HORSE_ARCHER] /= 3;
                }
                break;
            case 3:
                if (buildLists[BUILD_LIST_EGYPT_WAR_ELEPHANTS] > 0) {
                    buildLists[BUILD_LIST_EGYPT_WAR_ELEPHANTS] /= 3;
                }
                if (buildLists[BUILD_LIST_PHOENICIA_ELEPHANTS] > 0) {
                    buildLists[BUILD_LIST_PHOENICIA_ELEPHANTS] /= 3;
                }
                if (buildLists[BUILD_LIST_WAR_ELEPHANT_IRON] > 0) {
                    buildLists[BUILD_LIST_WAR_ELEPHANT_IRON] /= 3;
                }
                if (buildLists[BUILD_LIST_ELEPHANT_ARCHER_IRON] > 0) {
                    buildLists[BUILD_LIST_ELEPHANT_ARCHER_IRON] /= 3;
                }
                if (buildLists[BUILD_LIST_CARTHAGE_WAR_ELEPHANT] > 0) {
                    buildLists[BUILD_LIST_CARTHAGE_WAR_ELEPHANT] /= 3;
                }
                if (buildLists[BUILD_LIST_MACEDON_ELEPHANT] > 0) {
                    buildLists[BUILD_LIST_MACEDON_ELEPHANT] /= 3;
                }
                if (buildLists[BUILD_LIST_PALMYRA_ELEPHANT] > 0) {
                    buildLists[BUILD_LIST_PALMYRA_ELEPHANT] /= 3;
                }
                if (buildLists[BUILD_LIST_ELEPHANT_ARCHER_IRON] > 0) {
                    buildLists[BUILD_LIST_ELEPHANT_ARCHER_IRON] /= 3;
                }
                break;
            case 4:
                if (buildLists[BUILD_LIST_PHALANX_BRONZE] > 0) {
                    buildLists[BUILD_LIST_PHALANX_BRONZE] /= 3;
                }
                if (buildLists[BUILD_LIST_PHALANX_IRON] > 0) {
                    buildLists[BUILD_LIST_PHALANX_IRON] /= 3;
                }
                if (buildLists[BUILD_LIST_PHALANX_WALLS] > 0) {
                    buildLists[BUILD_LIST_PHALANX_WALLS] /= 3;
                }
                if (buildLists[BUILD_LIST_INFANTRY_STONE] > 0) {
                    buildLists[BUILD_LIST_INFANTRY_STONE] /= 3;
                }
                if (buildLists[BUILD_LIST_INFANTRY_TOOL] > 0) {
                    buildLists[BUILD_LIST_INFANTRY_TOOL] /= 3;
                }
                if (buildLists[BUILD_LIST_INFANTRY_BRONZE] > 0) {
                    buildLists[BUILD_LIST_INFANTRY_BRONZE] /= 3;
                }
                if (buildLists[BUILD_LIST_INFANTRY_WALLS] > 0) {
                    buildLists[BUILD_LIST_INFANTRY_WALLS] /= 3;
                }
                if (buildLists[BUILD_LIST_BABYLON_SWORDSMEN] > 0) {
                    buildLists[BUILD_LIST_BABYLON_SWORDSMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_CHOSON_SWORDSMEN] > 0) {
                    buildLists[BUILD_LIST_CHOSON_SWORDSMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_CHOSON_AXEMEN] > 0) {
                    buildLists[BUILD_LIST_CHOSON_AXEMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_EGYPT_CHARIOTS] > 0) {
                    buildLists[BUILD_LIST_EGYPT_CHARIOTS] /= 3;
                }
                if (buildLists[BUILD_LIST_GREEK_PHALANX] > 0) {
                    buildLists[BUILD_LIST_GREEK_PHALANX] /= 3;
                }
                if (buildLists[BUILD_LIST_SHANG_CLUBMEN] > 0) {
                    buildLists[BUILD_LIST_SHANG_CLUBMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_ASSYRIA_INFANTRY_BRONZE] > 0) {
                    buildLists[BUILD_LIST_ASSYRIA_INFANTRY_BRONZE] /= 3;
                }
                if (buildLists[BUILD_LIST_CARTHAGE_PHALANX] > 0) {
                    buildLists[BUILD_LIST_CARTHAGE_PHALANX] /= 3;
                }
                if (buildLists[BUILD_LIST_MACEDON_PHALANX] > 0) {
                    buildLists[BUILD_LIST_MACEDON_PHALANX] /= 3;
                }
                if (buildLists[BUILD_LIST_ROME_LEGION] > 0) {
                    buildLists[BUILD_LIST_ROME_LEGION] /= 3;
                }
                if (buildLists[BUILD_LIST_ROME_AXEMEN] > 0) {
                    buildLists[BUILD_LIST_ROME_AXEMEN] /= 3;
                }
                break;
            case 5:
                if (buildLists[BUILD_LIST_ASSYRIA_BOWMEN] > 0) {
                    buildLists[BUILD_LIST_ASSYRIA_BOWMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_ARCHERS_BRONZE] > 0) {
                    buildLists[BUILD_LIST_ARCHERS_BRONZE] /= 3;
                }
                if (buildLists[BUILD_LIST_ARCHERS_IRON] > 0) {
                    buildLists[BUILD_LIST_ARCHERS_IRON] /= 3;
                }
                if (buildLists[BUILD_LIST_ARCHERS_WALLS] > 0) {
                    buildLists[BUILD_LIST_ARCHERS_WALLS] /= 3;
                }
                if (buildLists[BUILD_LIST_ASSYRIA_BOWMEN] > 0) {
                    buildLists[BUILD_LIST_ASSYRIA_BOWMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_HITTITE_BOWMEN] > 0) {
                    buildLists[BUILD_LIST_HITTITE_BOWMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_MINOA_COMPOSITE_BOWMEN] > 0) {
                    buildLists[BUILD_LIST_MINOA_COMPOSITE_BOWMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_ASSYRIA_ARCHER_BRONZE] > 0) {
                    buildLists[BUILD_LIST_ASSYRIA_ARCHER_BRONZE] /= 3;
                }
                if (buildLists[BUILD_LIST_ASSYRIA_ARCHER_IRON] > 0) {
                    buildLists[BUILD_LIST_ASSYRIA_ARCHER_IRON] /= 3;
                }
                if (buildLists[BUILD_LIST_HITTITE_BOWMEN] > 0) {
                    buildLists[BUILD_LIST_HITTITE_BOWMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_MINOA_COMPOSITE_BOWMEN] > 0) {
                    buildLists[BUILD_LIST_MINOA_COMPOSITE_BOWMEN] /= 3;
                }
                if (buildLists[BUILD_LIST_EGYPT_CHARIOT_ARCHER] > 0) {
                    buildLists[BUILD_LIST_EGYPT_CHARIOT_ARCHER] /= 3;
                }
                if (buildLists[BUILD_LIST_EGYPT_ARCHERS_BRONZE] > 0) {
                    buildLists[BUILD_LIST_EGYPT_ARCHERS_BRONZE] /= 3;
                }
                if (buildLists[BUILD_LIST_EGYPT_ARCHERS_IRON] > 0) {
                    buildLists[BUILD_LIST_EGYPT_ARCHERS_IRON] /= 3;
                }
                if (buildLists[BUILD_LIST_PALMYRA_COMPOSITE_BOW] > 0) {
                    buildLists[BUILD_LIST_PALMYRA_COMPOSITE_BOW] /= 3;
                }
                break;
            case 6:
                if (buildLists[BUILD_LIST_ASSYRIA_BALLISTA] > 0) {
                    buildLists[BUILD_LIST_ASSYRIA_BALLISTA] /= 3;
                }
                if (buildLists[BUILD_LIST_SUMERIA_CATAPULTS] > 0) {
                    buildLists[BUILD_LIST_SUMERIA_CATAPULTS] /= 3;
                }
                if (buildLists[BUILD_LIST_ROME_SIEGE] > 0) {
                    buildLists[BUILD_LIST_ROME_SIEGE] /= 3;
                }
                if (buildLists[BUILD_LIST_GREEK_SIEGE] > 0) {
                    buildLists[BUILD_LIST_GREEK_SIEGE] /= 3;
                }
                break;
        }
    }

    int total = 0;
    int* cursor = buildLists;
    int count = 125;
    do {
        if (*cursor < 0) {
            *cursor = 0;
        }
        ++cursor;
        --count;
    } while (count != 0);
    total = 0;
    cursor = buildLists;
    count = 125;
    do {
        total += *cursor;
        ++cursor;
        --count;
    } while (count != 0);

    int randomValue = debug_rand(tplayerSourceName, 3137);
    int remainder = randomValue % total;
    int selectedBuildList = 0;
    int cumulative = 0;
    int selectionIndex = 0;
    for (; selectionIndex < 125; ++selectionIndex) {
        cumulative += buildLists[selectionIndex];
        if (cumulative > remainder) {
            selectedBuildList = selectionIndex;
            break;
        }
    }

    rge_base_game->get_string(selectedBuildList + STRING_ID_AI_BUILD_LIST_FIRST, b, 256);

    switch (selectedBuildList) {
        case BUILD_LIST_TRIREME_BRONZE:
            this->playerAI->strategyAI.setRule(SNMinimumBoatAttackGroupSize, 4);
            this->playerAI->strategyAI.setRule(SNMaximumBoatAttackGroupSize, 10);
            ++tplayer_globals::buildListCategoryCount7;
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_TRIREME_IRON:
            this->playerAI->strategyAI.setRule(SNMinimumBoatAttackGroupSize, 4);
            this->playerAI->strategyAI.setRule(SNMaximumBoatAttackGroupSize, 10);
            ++tplayer_globals::buildListCategoryCount7;
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_TRIREME_WALLS:
            this->playerAI->strategyAI.setRule(SNMinimumBoatAttackGroupSize, 4);
            this->playerAI->strategyAI.setRule(SNMaximumBoatAttackGroupSize, 10);
            ++tplayer_globals::buildListCategoryCount7;
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_PRIEST_BRONZE:
            ++computerPlayerSetup[0];
            break;
        case BUILD_LIST_PRIEST_IRON:
            ++computerPlayerSetup[0];
            break;
        case BUILD_LIST_PRIEST_WALLS:
            ++computerPlayerSetup[0];
            break;
        case BUILD_LIST_DEATH_MATCH_ASSYRIA:
            break;
        case BUILD_LIST_DEATH_MATCH_BABYLON:
            break;
        case BUILD_LIST_DEATH_MATCH_CHOSON:
            break;
        case BUILD_LIST_DEATH_MATCH_EGYPT:
            break;
        case BUILD_LIST_DEATH_MATCH_GREEK:
            break;
        case BUILD_LIST_DEATH_MATCH_HITTITE:
            break;
        case BUILD_LIST_DEATH_MATCH_MINOA:
            break;
        case BUILD_LIST_DEATH_MATCH_PERSIA:
            break;
        case BUILD_LIST_DEATH_MATCH_PHOENICIA:
            break;
        case BUILD_LIST_DEATH_MATCH_SHANG:
            break;
        case BUILD_LIST_DEATH_MATCH_SUMERIA:
            break;
        case BUILD_LIST_DEATH_MATCH_YAMATO:
            break;
        case BUILD_LIST_IMMORTAL_ASSYRIA:
            break;
        case BUILD_LIST_IMMORTAL_EGYPT:
            break;
        case BUILD_LIST_IMMORTAL_GREEK:
            break;
        case BUILD_LIST_IMMORTAL_MINOA:
            break;
        case BUILD_LIST_IMMORTAL_SUMERIA:
            break;
        case BUILD_LIST_IMMORTAL_YAMATO:
            break;
        case BUILD_LIST_DEATH_MATCH_CARTHAGE:
            break;
        case BUILD_LIST_DEATH_MATCH_MACEDON:
            break;
        case BUILD_LIST_DEATH_MATCH_PALMYRA:
            break;
        case BUILD_LIST_DEATH_MATCH_ROME:
            break;
        case BUILD_LIST_DEATH_MATCH_ASSYRIA_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_BABYLON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_CHOSON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_EGYPT_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_GREEK_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_HITTITE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_MINOA_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_PERSIA_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_PHOENICIA_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_SHANG_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_SUMERIA_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_YAMATO_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_ASSYRIA_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_ASSYRIA_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_BABYLON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_CHOSON_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_CHOSON_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_EGYPT_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_GREEK_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_GREEK_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_HITTITE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_MINOA_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_MINOA_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_PERSIA_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_PERSIA_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_PHOENICIA_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_SHANG_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_SUMERIA_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_SUMERIA_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_YAMATO_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_YAMATO_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_CARTHAGE_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_CARTHAGE_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_MACEDON_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_MACEDON_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_PALMYRA_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_PALMYRA_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_ROME_BRONZE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_ROME_IRON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_CARTHAGE_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_MACEDON_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_PALMYRA_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_DEATH_MATCH_ROME_WATER:
            ++tplayer_globals::aggressiveBuildListCount;
            goto selectedCountersDone;
        case BUILD_LIST_ASSYRIA_ARCHER_BRONZE:
            ++tplayer_globals::selectedBuildListCount;
            ++tplayer_globals::buildListCategoryCount5;
            goto selectedCountersDone;
        case BUILD_LIST_ASSYRIA_ARCHER_IRON:
            ++tplayer_globals::selectedBuildListCount;
            ++tplayer_globals::buildListCategoryCount5;
            goto selectedCountersDone;
        case BUILD_LIST_ASSYRIA_INFANTRY_BRONZE:
            ++tplayer_globals::selectedBuildListCount;
            ++tplayer_globals::buildListCategoryCount4;
            goto selectedCountersDone;
        case BUILD_LIST_CAVALRY_BRONZE:
            ++tplayer_globals::buildListCategoryCount1;
            break;
        case BUILD_LIST_CAVALRY_IRON:
            ++tplayer_globals::buildListCategoryCount1;
            break;
        case BUILD_LIST_CAVALRY_WALLS:
            ++tplayer_globals::buildListCategoryCount1;
            break;
        case BUILD_LIST_BABYLON_SCOUTS:
            ++tplayer_globals::buildListCategoryCount1;
            break;
        case BUILD_LIST_SHANG_HEAVY_CAVALRY:
            ++tplayer_globals::buildListCategoryCount1;
            break;
        case BUILD_LIST_SHANG_CAVALRY:
            ++tplayer_globals::buildListCategoryCount1;
            break;
        case BUILD_LIST_SUMERIA_SCOUTS:
            ++tplayer_globals::buildListCategoryCount1;
            break;
        case BUILD_LIST_YAMATO_HEAVY_CAVALRY:
            ++tplayer_globals::buildListCategoryCount1;
            break;
        case BUILD_LIST_MACEDON_CAVALRY:
            ++tplayer_globals::buildListCategoryCount1;
            break;
        case BUILD_LIST_ARCHERS_BRONZE:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_ARCHERS_IRON:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_ARCHERS_WALLS:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_ASSYRIA_BOWMEN:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_HITTITE_BOWMEN:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_MINOA_COMPOSITE_BOWMEN:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_EGYPT_CHARIOT_ARCHER:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_EGYPT_ARCHERS_BRONZE:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_EGYPT_ARCHERS_IRON:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_PALMYRA_COMPOSITE_BOW:
            ++tplayer_globals::buildListCategoryCount5;
            break;
        case BUILD_LIST_CAV_ARCHER_IRON:
            ++tplayer_globals::buildListCategoryCount2;
            break;
        case BUILD_LIST_HITTITE_HORSE_ARCHERS:
            ++tplayer_globals::buildListCategoryCount2;
            break;
        case BUILD_LIST_PALMYRA_HORSE_ARCHER:
            ++tplayer_globals::buildListCategoryCount2;
            break;
        case BUILD_LIST_WAR_ELEPHANT_IRON:
            ++tplayer_globals::buildListCategoryCount3;
            break;
        case BUILD_LIST_ELEPHANT_ARCHER_IRON:
            ++tplayer_globals::buildListCategoryCount3;
            break;
        case BUILD_LIST_EGYPT_WAR_ELEPHANTS:
            ++tplayer_globals::buildListCategoryCount3;
            break;
        case BUILD_LIST_PERSIA_ELEPHANT_ARCHERS:
            ++tplayer_globals::buildListCategoryCount3;
            break;
        case BUILD_LIST_PHOENICIA_ELEPHANTS:
            ++tplayer_globals::buildListCategoryCount3;
            break;
        case BUILD_LIST_CARTHAGE_WAR_ELEPHANT:
            ++tplayer_globals::buildListCategoryCount3;
            break;
        case BUILD_LIST_MACEDON_ELEPHANT:
            ++tplayer_globals::buildListCategoryCount3;
            break;
        case BUILD_LIST_PALMYRA_ELEPHANT:
            ++tplayer_globals::buildListCategoryCount3;
            break;
        case BUILD_LIST_ASSYRIA_BALLISTA:
            ++tplayer_globals::buildListCategoryCount6;
            break;
        case BUILD_LIST_SUMERIA_CATAPULTS:
            ++tplayer_globals::buildListCategoryCount6;
            break;
        case BUILD_LIST_GREEK_SIEGE:
            ++tplayer_globals::buildListCategoryCount6;
            break;
        case BUILD_LIST_ROME_SIEGE:
            ++tplayer_globals::buildListCategoryCount6;
            break;
        case BUILD_LIST_PHALANX_BRONZE:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_PHALANX_IRON:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_PHALANX_WALLS:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_INFANTRY_STONE:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_INFANTRY_TOOL:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_INFANTRY_BRONZE:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_INFANTRY_WALLS:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_BABYLON_SWORDSMEN:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_CHOSON_SWORDSMEN:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_CHOSON_AXEMEN:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_EGYPT_CHARIOTS:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_GREEK_PHALANX:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_SHANG_CLUBMEN:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_CARTHAGE_PHALANX:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_MACEDON_PHALANX:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_ROME_LEGION:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        case BUILD_LIST_ROME_AXEMEN:
            ++tplayer_globals::buildListCategoryCount4;
            break;
        default:
            ++tplayer_globals::buildListCategoryCount4;
            break;
    }
    ++tplayer_globals::selectedBuildListCount;

selectedCountersDone:
    // Keep the arithmetic lookup; expansion civilization names use different resource IDs.
    rge_base_game->get_string(
        static_cast<int>(this->master_player_id) + (STRING_ID_CIVILIZATION_EGYPTIAN - 1), tempString, 256
    );
    this->playerAI->logCommonHistory(
        "I am the %s civ (culture #%d):", tempString, static_cast<int>(this->master_player_id) - 1
    );
    this->playerAI->logCommonHistory("Selected a best build list of '%s'.", b);
    strcpy(r, tplayerRandomName);
    this->playerAI->logCommonHistory("Setting AI Personality:");

    int workingMapType = mapType;
    switch (gameType) {
        case TRIBE_Game::VictoryDefault:
        case TRIBE_Game::VictoryConquest:
            this->playerAI->strategyAI.setRule(SNRuinsDefendPriority, 5);
            this->playerAI->strategyAI.setRule(SNArtifactDefendPriority, 5);
            break;
        case TRIBE_VICTORY_TYPE_EXPLORATION:
        case TRIBE_VICTORY_TYPE_RUINS:
        case TRIBE_VICTORY_TYPE_ARTIFACTS:
        case TRIBE_VICTORY_TYPE_DISCOVERIES:
            workingMapType = this->playerAI->strategyAI.rule(SNPercentCivilianBuilders);
            if (workingMapType > 0) {
                this->playerAI->strategyAI.setRule(SNPercentCivilianExplorers, 0x32);
                this->playerAI->strategyAI.setRule(SNPercentCivilianBuilders, 0x19);
                this->playerAI->strategyAI.setRule(SNPercentCivilianGatherers, 0x19);
            } else {
                this->playerAI->strategyAI.setRule(SNPercentCivilianExplorers, 0x32);
                this->playerAI->strategyAI.setRule(SNPercentCivilianGatherers, 0x32);
            }
            if (mapType > TRIBE_Game::MostlyWater) {
                this->playerAI->strategyAI.setRule(SNCapCivilianExplorers, 5);
            }
            this->playerAI->strategyAI.setRule(SNNumberExploreGroups, 2);
            this->playerAI->strategyAI.setRule(SNNumberBoatExploreGroups, 2);
            workingMapType = mapType;
            if (gameType != TRIBE_VICTORY_TYPE_EXPLORATION) {
                this->playerAI->strategyAI.setRule(SNNumberDefendGroups, mapSize + 1);
                this->playerAI->strategyAI.setRule(SNNumberAttackGroups, 1);
                if (gameType == TRIBE_VICTORY_TYPE_RUINS) {
                    this->playerAI->strategyAI.setRule(SNRuinsDefendPriority, 1);
                } else {
                    this->playerAI->strategyAI.setRule(SNRuinsDefendPriority, 5);
                }
                if (gameType == TRIBE_VICTORY_TYPE_ARTIFACTS) {
                    this->playerAI->strategyAI.setRule(SNArtifactDefendPriority, 1);
                } else {
                    this->playerAI->strategyAI.setRule(SNArtifactDefendPriority, 5);
                }
            }
            break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        this->playerAI->strategyAI.setRule(SNCapCivilianBuilders, 10);
    }

    int attackTime = (debug_rand(tplayerSourceName, 3642) % 12 + 0x1C) * 60;
    switch (selectedBuildList) {
        case BUILD_LIST_ARCHERS_BRONZE:
        case BUILD_LIST_PHALANX_BRONZE:
        case BUILD_LIST_INFANTRY_BRONZE:
        case BUILD_LIST_INFANTRY_WALLS:
        case BUILD_LIST_TRIREME_BRONZE:
        case BUILD_LIST_PRIEST_BRONZE:
        case BUILD_LIST_EGYPT_CHARIOTS:
        case BUILD_LIST_GREEK_PHALANX:
        case BUILD_LIST_MINOA_COMPOSITE_BOWMEN:
        case BUILD_LIST_SHANG_CAVALRY:
        case BUILD_LIST_SUMERIA_CATAPULTS:
        case BUILD_LIST_ASSYRIA_ARCHER_BRONZE:
        case BUILD_LIST_ASSYRIA_INFANTRY_BRONZE:
        case BUILD_LIST_ASSYRIA_BRONZE_WATER:
        case BUILD_LIST_CHOSON_BRONZE_WATER:
        case BUILD_LIST_EGYPT_ARCHERS_BRONZE:
        case BUILD_LIST_GREEK_BRONZE_WATER:
        case BUILD_LIST_MINOA_BRONZE_WATER:
        case BUILD_LIST_PERSIA_BRONZE_WATER:
        case BUILD_LIST_SUMERIA_BRONZE_WATER:
        case BUILD_LIST_YAMATO_BRONZE_WATER:
        case BUILD_LIST_CARTHAGE_BRONZE_WATER:
        case BUILD_LIST_MACEDON_BRONZE_WATER:
        case BUILD_LIST_PALMYRA_BRONZE_WATER:
        case BUILD_LIST_ROME_BRONZE_WATER:
            ++tplayer_globals::fastAttackListCount;
            attackTime = (debug_rand(tplayerSourceName, 3672) % 6 + 0x14) * 60;
            break;
        case BUILD_LIST_INFANTRY_TOOL:
        case BUILD_LIST_ASSYRIA_BOWMEN:
        case BUILD_LIST_BABYLON_SCOUTS:
        case BUILD_LIST_CHOSON_SWORDSMEN:
        case BUILD_LIST_CHOSON_AXEMEN:
        case BUILD_LIST_HITTITE_BOWMEN:
        case BUILD_LIST_SUMERIA_SCOUTS:
        case BUILD_LIST_ROME_AXEMEN:
            ++tplayer_globals::attackTimingCategoryCount;
            attackTime = (debug_rand(tplayerSourceName, 3684) % 4 + 0x0B) * 60;
            break;
        case BUILD_LIST_INFANTRY_STONE:
        case BUILD_LIST_SHANG_CLUBMEN:
            attackTime = (debug_rand(tplayerSourceName, 3689) % 2 + 5) * 60;
            ++tplayer_globals::attackTimingCategoryCount;
            break;
        default:
            ++tplayer_globals::defaultAttackListCount;
            break;
    }

    int difficultyCopy = difficultyLevel;
    if (difficultyLevel == RGE_DIFFICULTY_HARDEST && debug_rand(tplayerSourceName, 3699) % 3 == 0) {
        attackTime -= 300;
    }
    this->playerAI->strategyAI.setRule(SNInitialAttackDelay, attackTime);
    this->playerAI->strategyAI.setRule(SNMinimumAttackGroupSize, 2);
    this->playerAI->strategyAI.setRule(SNMaximumAttackGroupSize, 10);
    this->playerAI->strategyAI.setRule(SNScaleMinimumAttackGroupSize, 1);
    this->playerAI->strategyAI.setRule(SNScalingFrequency, 4);

    if (debug_rand(tplayerSourceName, 3712) % 3 == 0) {
        this->playerAI->strategyAI.setRule(0xBC, 0);
    } else {
        this->playerAI->strategyAI.setRule(0xBC, 1);
    }
    this->playerAI->strategyAI.setRule(0xC3, debug_rand(tplayerSourceName, 3718) % 0x28 + 10);
    this->playerAI->strategyAI.setRule(0xBD, debug_rand(tplayerSourceName, 3722) % 0x46 + 0x1E);
    this->playerAI->strategyAI.setRule(
        SNPercentageExploreExterminators, (debug_rand(tplayerSourceName, 3726) % 5 + 5) * difficultyLevel
    );
    this->playerAI->strategyAI.setRule(0xC7, (debug_rand(tplayerSourceName, 3730) % 10 + 10) * difficultyLevel);
    this->playerAI->strategyAI.setRule(0xA1, 4);

    randomValue = mapSize;
    if (workingMapType == TRIBE_Game::AllWater) {
        randomValue -= 2;
    } else if (workingMapType == TRIBE_Game::MostlyWater) {
        randomValue -= 1;
    }

    switch (randomValue) {
        case -2:
        case -1:
            this->playerAI->strategyAI.setRule(SNMinimumTownSize, debug_rand(tplayerSourceName, 3746) % 2 + 0x0E);
            this->playerAI->strategyAI.setRule(
                0x4A, this->playerAI->strategyAI.rule(SNMinimumTownSize) + debug_rand(tplayerSourceName, 3748) % 4 + 1
            );
            break;
        case 0:
            this->playerAI->strategyAI.setRule(SNMinimumTownSize, debug_rand(tplayerSourceName, 3751) % 2 + 0x0F);
            this->playerAI->strategyAI.setRule(
                0x4A, this->playerAI->strategyAI.rule(SNMinimumTownSize) + debug_rand(tplayerSourceName, 3753) % 4 + 1
            );
            break;
        case 1:
            this->playerAI->strategyAI.setRule(SNMinimumTownSize, debug_rand(tplayerSourceName, 3756) % 3 + 0x10);
            this->playerAI->strategyAI.setRule(
                0x4A, this->playerAI->strategyAI.rule(SNMinimumTownSize) + debug_rand(tplayerSourceName, 3758) % 5 + 1
            );
            break;
        case 2:
            this->playerAI->strategyAI.setRule(SNMinimumTownSize, debug_rand(tplayerSourceName, 3761) % 2 + 0x11);
            this->playerAI->strategyAI.setRule(
                0x4A, this->playerAI->strategyAI.rule(SNMinimumTownSize) + debug_rand(tplayerSourceName, 3763) % 6 + 1
            );
            break;
        case 3:
            this->playerAI->strategyAI.setRule(SNMinimumTownSize, debug_rand(tplayerSourceName, 3766) % 2 + 0x12);
            this->playerAI->strategyAI.setRule(
                0x4A, this->playerAI->strategyAI.rule(SNMinimumTownSize) + debug_rand(tplayerSourceName, 3768) % 7 + 1
            );
            break;
        case 4:
            this->playerAI->strategyAI.setRule(SNMinimumTownSize, debug_rand(tplayerSourceName, 3771) % 4 + 0x12);
            this->playerAI->strategyAI.setRule(
                0x4A, this->playerAI->strategyAI.rule(SNMinimumTownSize) + debug_rand(tplayerSourceName, 3773) % 8 + 1
            );
            break;
        default:
            this->playerAI->strategyAI.setRule(SNMinimumTownSize, debug_rand(tplayerSourceName, 3777) % 2 + 0x12);
            this->playerAI->strategyAI.setRule(
                0x4A, this->playerAI->strategyAI.rule(SNMinimumTownSize) + debug_rand(tplayerSourceName, 3779) % 9 + 1
            );
            break;
    }
    this->playerAI->strategyAI.setRule(0xD0, 1);
    this->playerAI->strategyAI.setRule(0xD1, 1);
    this->playerAI->strategyAI.setRule(0xD2, 1);
    this->playerAI->strategyAI.setRule(0xDF, 1);

    if (workingMapType == TRIBE_Game::AllWater) {
        this->playerAI->strategyAI.setRule(0xD4, 3);
        this->playerAI->strategyAI.setRule(0xD5, 6);
        this->playerAI->strategyAI.setRule(0xD6, 2);
        this->playerAI->strategyAI.setRule(0xE0, 6);
    } else if (workingMapType == TRIBE_Game::MostlyWater) {
        this->playerAI->strategyAI.setRule(0xD4, 2);
        this->playerAI->strategyAI.setRule(0xD5, 5);
        this->playerAI->strategyAI.setRule(0xD6, 2);
        this->playerAI->strategyAI.setRule(0xE0, 4);
    } else if (workingMapType == TRIBE_Game::WaterAndLand || workingMapType == TRIBE_Game::Lake
               || workingMapType == TRIBE_Game::Continental || workingMapType == TRIBE_Game::Isthmas) {
        this->playerAI->strategyAI.setRule(0xD4, 1);
        this->playerAI->strategyAI.setRule(0xD5, 4);
        this->playerAI->strategyAI.setRule(0xD6, 1);
        this->playerAI->strategyAI.setRule(0xE0, 3);
    } else if (workingMapType == TRIBE_Game::MostlyLand || workingMapType == TRIBE_Game::AllLand
               || workingMapType == TRIBE_Game::Hilly) {
        this->playerAI->strategyAI.setRule(0xD4, 0);
        this->playerAI->strategyAI.setRule(0xD5, 0);
        this->playerAI->strategyAI.setRule(0xD6, 0);
        this->playerAI->strategyAI.setRule(0xE0, 0);
    }

    if (allowAIToCheat != 0) {
        int cheatFood = 0;
        int cheatGold = 0;
        int cheatWood = 0;
        int cheatStone = 0;
        if (difficultyCopy == RGE_DIFFICULTY_HARDEST) {
            cheatFood = 2000;
            cheatWood = 2000;
            cheatStone = 2000;
            cheatGold = 2000;
        }
        this->playerAI->strategyAI.setRule(0x8A, cheatFood);
        this->playerAI->strategyAI.setRule(0x8B, cheatWood);
        this->playerAI->strategyAI.setRule(0x8C, cheatStone);
        this->playerAI->strategyAI.setRule(0x8D, cheatGold);
        difficultyLevel = difficultyCopy;
    }

    this->playerAI->strategyAI.setRule(0xA8, 0);
    this->playerAI->strategyAI.setRule(0xA2, 0);
    if (difficultyLevel < RGE_DIFFICULTY_EASY) {
        this->playerAI->strategyAI.setRule(0xC2, 1);
        this->playerAI->strategyAI.setRule(SNAttackCoordination, 2);
    } else {
        this->playerAI->strategyAI.setRule(0xC2, 0);
        this->playerAI->strategyAI.setRule(SNAttackCoordination, 1);
    }

    if (difficultyLevel == RGE_DIFFICULTY_HARDEST) {
        this->playerAI->strategyAI.setRule(0xBA, 0xB4);
        this->playerAI->strategyAI.setRule(0xBA, 200);
    } else if (difficultyLevel == RGE_DIFFICULTY_HARD) {
        this->playerAI->strategyAI.setRule(0xBA, 0xB4);
        this->playerAI->strategyAI.setRule(0xBA, 0x96);
    } else if (difficultyLevel == RGE_DIFFICULTY_MODERATE) {
        this->playerAI->strategyAI.setRule(0xBA, 0xB4);
        this->playerAI->strategyAI.setRule(0xBA, 100);
    } else if (difficultyLevel == RGE_DIFFICULTY_EASY) {
        this->playerAI->strategyAI.setRule(0xBA, 0xB4);
        this->playerAI->strategyAI.setRule(0xBA, 0x32);
    }

    if (debug_rand(tplayerSourceName, 3920) % 6 < 5) {
        this->playerAI->strategyAI.setRule(0xB5, 1);
    } else {
        this->playerAI->strategyAI.setRule(0xB5, 0);
    }
    if (debug_rand(tplayerSourceName, 3926) % 3 < 1) {
        this->playerAI->strategyAI.setRule(0xB6, 1);
    } else {
        this->playerAI->strategyAI.setRule(0xB6, 0);
    }
}

void TRIBE_Player::setupEgyptian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Egyptians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_EGYPT_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_EGYPT] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_EGYPT_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_EGYPT] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_EGYPT_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_EGYPT] = 100;
        }
    } else if (rge_base_game->difficulty() < RGE_DIFFICULTY_HARD) {
        b[BUILD_LIST_IMMORTAL_EGYPT] = 100;
    } else {
        b[BUILD_LIST_PHALANX_BRONZE] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_WAR_ELEPHANT_IRON] = 0x28;
        b[BUILD_LIST_ELEPHANT_ARCHER_IRON] = 0x28;
        b[BUILD_LIST_EGYPT_WAR_ELEPHANTS] = 100;
        b[BUILD_LIST_PRIEST_BRONZE] = 0x32;
        b[BUILD_LIST_PRIEST_IRON] = 0x32;
        b[BUILD_LIST_EGYPT_CHARIOTS] = 100;
        b[BUILD_LIST_EGYPT_CHARIOT_ARCHER] = 100;
        b[BUILD_LIST_EGYPT_ARCHERS_BRONZE] = 0x1E;
        b[BUILD_LIST_EGYPT_ARCHERS_IRON] = 0x14;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_EGYPT_WATER] = 200;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_EGYPT_WATER] = 100;
        }
    }
}

void TRIBE_Player::setupGreek(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Greeks.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_GREEK_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_GREEK] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_GREEK_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_GREEK] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_GREEK_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_GREEK] = 100;
        }
    } else if (rge_base_game->difficulty() < RGE_DIFFICULTY_HARD) {
        b[BUILD_LIST_IMMORTAL_GREEK] = 100;
    } else {
        b[BUILD_LIST_CAVALRY_BRONZE] = 0x1E;
        b[BUILD_LIST_INFANTRY_BRONZE] = 0x1E;
        b[BUILD_LIST_PRIEST_IRON] = 0x1E;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_PHALANX_BRONZE] = 0x46;
        b[BUILD_LIST_PHALANX_IRON] = 0x32;
        b[BUILD_LIST_CAVALRY_IRON] = 0x14;
        b[BUILD_LIST_PRIEST_BRONZE] = 0x32;
        b[BUILD_LIST_GREEK_PHALANX] = 100;
        b[BUILD_LIST_GREEK_SIEGE] = 100;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_GREEK_BRONZE_WATER] = 200;
            b[BUILD_LIST_GREEK_IRON_WATER] = 200;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_GREEK_BRONZE_WATER] = 100;
            b[BUILD_LIST_GREEK_IRON_WATER] = 100;
        }
    }
}

void TRIBE_Player::setupBabylonian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Babylonians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_BABYLON_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_BABYLON] = 60;
            b[BUILD_LIST_DEATH_MATCH_BABYLON_WATER] = 40;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_BABYLON] = 80;
            b[BUILD_LIST_DEATH_MATCH_BABYLON_WATER] = 20;
        } else {
            b[BUILD_LIST_DEATH_MATCH_BABYLON] = 100;
        }
    } else {
        b[BUILD_LIST_ARCHERS_IRON] = 10;
        b[BUILD_LIST_CAVALRY_BRONZE] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_BRONZE] = 10;
        b[BUILD_LIST_ARCHERS_BRONZE] = 20;
        b[BUILD_LIST_PRIEST_BRONZE] = 40;
        b[BUILD_LIST_PRIEST_IRON] = 40;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 30;
        b[BUILD_LIST_BABYLON_SWORDSMEN] = 100;
        b[BUILD_LIST_BABYLON_SCOUTS] = 100;
        b[BUILD_LIST_PHALANX_BRONZE] = 20;
        b[BUILD_LIST_INFANTRY_TOOL] = 20;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater)
            b[BUILD_LIST_BABYLON_WATER] = 60;
        else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                 || mapType == TRIBE_Game::Continental)
            b[BUILD_LIST_BABYLON_WATER] = 30;
    }
}

void TRIBE_Player::setupAssyrian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Assyrians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_ASSYRIA_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_ASSYRIA] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_ASSYRIA_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_ASSYRIA] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_ASSYRIA_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_ASSYRIA] = 100;
        }
    } else if (rge_base_game->difficulty() < RGE_DIFFICULTY_HARD) {
        b[BUILD_LIST_IMMORTAL_ASSYRIA] = 100;
    } else {
        b[BUILD_LIST_PHALANX_BRONZE] = 10;
        b[BUILD_LIST_CAVALRY_IRON] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_PRIEST_IRON] = 10;
        b[BUILD_LIST_ASSYRIA_ARCHER_BRONZE] = 0x50;
        b[BUILD_LIST_ASSYRIA_ARCHER_IRON] = 0x50;
        b[BUILD_LIST_ASSYRIA_INFANTRY_BRONZE] = 0x50;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 0x28;
        b[BUILD_LIST_INFANTRY_BRONZE] = 0x28;
        b[BUILD_LIST_CAVALRY_BRONZE] = 0x14;
        b[BUILD_LIST_PRIEST_BRONZE] = 0x14;
        b[BUILD_LIST_ASSYRIA_BALLISTA] = 100;
        b[BUILD_LIST_ASSYRIA_BOWMEN] = 100;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_ASSYRIA_BRONZE_WATER] = 100;
            b[BUILD_LIST_ASSYRIA_IRON_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_ASSYRIA_BRONZE_WATER] = 0x32;
            b[BUILD_LIST_ASSYRIA_IRON_WATER] = 0x32;
        }
    }
}

void TRIBE_Player::setupMinoan(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Minoans.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_MINOA_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_MINOA] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_MINOA_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_MINOA] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_MINOA_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_MINOA] = 100;
        }
    } else if (rge_base_game->difficulty() < RGE_DIFFICULTY_HARD) {
        b[BUILD_LIST_IMMORTAL_MINOA] = 100;
    } else {
        b[BUILD_LIST_PHALANX_IRON] = 10;
        b[BUILD_LIST_CAVALRY_BRONZE] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_INFANTRY_BRONZE] = 10;
        b[BUILD_LIST_ARCHERS_BRONZE] = 0x3C;
        b[BUILD_LIST_ARCHERS_IRON] = 0x50;
        b[BUILD_LIST_PHALANX_BRONZE] = 0x14;
        b[BUILD_LIST_MINOA_COMPOSITE_BOWMEN] = 100;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_MINOA_BRONZE_WATER] = 200;
            b[BUILD_LIST_MINOA_IRON_WATER] = 200;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_MINOA_BRONZE_WATER] = 100;
            b[BUILD_LIST_MINOA_IRON_WATER] = 100;
        }
    }
}

void TRIBE_Player::setupHittite(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Hittites.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_HITTITE_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_HITTITE] = 60;
            b[BUILD_LIST_DEATH_MATCH_HITTITE_WATER] = 40;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_HITTITE] = 80;
            b[BUILD_LIST_DEATH_MATCH_HITTITE_WATER] = 20;
        } else {
            b[BUILD_LIST_DEATH_MATCH_HITTITE] = 100;
        }
    } else {
        b[BUILD_LIST_PHALANX_IRON] = 0x28;
        b[BUILD_LIST_ELEPHANT_ARCHER_IRON] = 0x28;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 80;
        b[BUILD_LIST_HITTITE_HORSE_ARCHERS] = 100;
        b[BUILD_LIST_HITTITE_BOWMEN] = 100;
        b[BUILD_LIST_PHALANX_BRONZE] = 30;

        b[BUILD_LIST_CAVALRY_BRONZE] = 0x14;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_INFANTRY_BRONZE] = 10;
        b[BUILD_LIST_WAR_ELEPHANT_IRON] = 0x14;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_HITTITE_WATER] = 0xA0;
            b[BUILD_LIST_ARCHERS_BRONZE] = 0x14;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_HITTITE_WATER] = 0x50;
            b[BUILD_LIST_ARCHERS_BRONZE] = 10;
        }
    }
}

void TRIBE_Player::setupPhoenician(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Phoenicians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_PHOENICIA_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_PHOENICIA] = 60;
            b[BUILD_LIST_DEATH_MATCH_PHOENICIA_WATER] = 40;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_PHOENICIA] = 80;
            b[BUILD_LIST_DEATH_MATCH_PHOENICIA_WATER] = 20;
        } else {
            b[BUILD_LIST_DEATH_MATCH_PHOENICIA] = 100;
        }
    } else {
        b[BUILD_LIST_PHALANX_BRONZE] = 10;
        b[BUILD_LIST_PHALANX_IRON] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_INFANTRY_BRONZE] = 10;
        b[BUILD_LIST_WAR_ELEPHANT_IRON] = 70;
        b[BUILD_LIST_ELEPHANT_ARCHER_IRON] = 70;
        b[BUILD_LIST_ARCHERS_BRONZE] = 20;
        b[BUILD_LIST_CAVALRY_BRONZE] = 20;
        b[BUILD_LIST_PRIEST_BRONZE] = 20;
        b[BUILD_LIST_ARCHERS_IRON] = 40;
        b[BUILD_LIST_PRIEST_IRON] = 30;
        b[BUILD_LIST_PHOENICIA_ELEPHANTS] = 100;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_PHOENICIA_WATER] = 200;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_PHOENICIA_WATER] = 100;
        }
    }
}

void TRIBE_Player::setupSumerian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Sumerians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_SUMERIA_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_SUMERIA] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_SUMERIA_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_SUMERIA] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_SUMERIA_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_SUMERIA] = 100;
        }
    } else if (rge_base_game->difficulty() < RGE_DIFFICULTY_HARD) {
        b[BUILD_LIST_IMMORTAL_SUMERIA] = 100;
    } else {
        b[BUILD_LIST_CAV_ARCHER_IRON] = 0x1E;
        b[BUILD_LIST_PHALANX_BRONZE] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_INFANTRY_BRONZE] = 10;
        b[BUILD_LIST_PHALANX_IRON] = 0x14;
        b[BUILD_LIST_WAR_ELEPHANT_IRON] = 0x14;
        b[BUILD_LIST_SUMERIA_CATAPULTS] = 100;
        b[BUILD_LIST_SUMERIA_SCOUTS] = 100;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_SUMERIA_BRONZE_WATER] = 200;
            b[BUILD_LIST_SUMERIA_IRON_WATER] = 200;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_SUMERIA_BRONZE_WATER] = 100;
            b[BUILD_LIST_SUMERIA_IRON_WATER] = 100;
        }
    }
}

void TRIBE_Player::setupPersian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Persians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_PERSIA_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_PERSIA] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_PERSIA_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_PERSIA] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_PERSIA_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_PERSIA] = 0x64;
        }
    } else {
        b[BUILD_LIST_CAVALRY_BRONZE] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_WAR_ELEPHANT_IRON] = 0x3C;
        b[BUILD_LIST_ELEPHANT_ARCHER_IRON] = 0x3C;
        b[BUILD_LIST_ARCHERS_IRON] = 0x28;
        b[BUILD_LIST_INFANTRY_BRONZE] = 0x28;
        b[BUILD_LIST_PRIEST_IRON] = 0x28;
        b[BUILD_LIST_ARCHERS_BRONZE] = 0x14;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 0x14;
        b[BUILD_LIST_CAVALRY_IRON] = 0x32;
        b[BUILD_LIST_PRIEST_BRONZE] = 0x14;
        b[BUILD_LIST_PERSIA_ELEPHANT_ARCHERS] = 0x64;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_PERSIA_BRONZE_WATER] = 0xC8;
            b[BUILD_LIST_PERSIA_IRON_WATER] = 0xC8;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_PERSIA_BRONZE_WATER] = 0x64;
            b[BUILD_LIST_PERSIA_IRON_WATER] = 0x64;
        }
    }
}

void TRIBE_Player::setupShang(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Shang.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_SHANG_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_SHANG] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_SHANG_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_SHANG] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_SHANG_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_SHANG] = 100;
        }
    } else {
        b[BUILD_LIST_ARCHERS_BRONZE] = 10;
        b[BUILD_LIST_PHALANX_BRONZE] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_CAVALRY_BRONZE] = 50;
        b[BUILD_LIST_CAVALRY_IRON] = 50;
        b[BUILD_LIST_SHANG_CLUBMEN] = 50;

        b[BUILD_LIST_INFANTRY_BRONZE] = 30;
        b[BUILD_LIST_PRIEST_IRON] = 30;
        b[BUILD_LIST_ARCHERS_IRON] = 0x14;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 0x14;
        b[BUILD_LIST_PRIEST_BRONZE] = 0x14;
        b[BUILD_LIST_SHANG_HEAVY_CAVALRY] = 100;
        b[BUILD_LIST_SHANG_CAVALRY] = 100;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_SHANG_WATER] = 0xA0;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_SHANG_WATER] = 0x50;
        }
    }
}

void TRIBE_Player::setupYamato(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Yamato.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_YAMATO_WATER] = 100;
            return;
        }
        if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_YAMATO] = 60;
            b[BUILD_LIST_DEATH_MATCH_YAMATO_WATER] = 40;
            return;
        }
        if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_YAMATO] = 80;
            b[BUILD_LIST_DEATH_MATCH_YAMATO_WATER] = 20;
            return;
        }
        b[BUILD_LIST_DEATH_MATCH_YAMATO] = 100;
        return;
    } else if (rge_base_game->difficulty() < RGE_DIFFICULTY_HARD) {
        b[BUILD_LIST_IMMORTAL_YAMATO] = 100;
    } else {
        b[BUILD_LIST_PHALANX_BRONZE] = 10;
        b[BUILD_LIST_PHALANX_IRON] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_CAVALRY_BRONZE] = 50;
        b[BUILD_LIST_CAVALRY_IRON] = 50;
        b[BUILD_LIST_ARCHERS_BRONZE] = 20;
        b[BUILD_LIST_ARCHERS_IRON] = 20;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 40;
        b[BUILD_LIST_INFANTRY_BRONZE] = 20;
        b[BUILD_LIST_YAMATO_HEAVY_CAVALRY] = 100;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_YAMATO_BRONZE_WATER] = 200;
            b[BUILD_LIST_YAMATO_IRON_WATER] = 200;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_YAMATO_BRONZE_WATER] = 100;
            b[BUILD_LIST_YAMATO_IRON_WATER] = 100;
        }
    }
}

void TRIBE_Player::setupChoson(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Choson.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_CHOSON_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_CHOSON] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_CHOSON_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_CHOSON] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_CHOSON_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_CHOSON] = 100;
        }
    } else {
        b[BUILD_LIST_ARCHERS_IRON] = 10;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 10;
        b[BUILD_LIST_PHALANX_BRONZE] = 10;
        b[BUILD_LIST_CAVALRY_IRON] = 0x1E;
        b[BUILD_LIST_INFANTRY_STONE] = 0x1E;
        b[BUILD_LIST_INFANTRY_TOOL] = 0x1E;
        b[BUILD_LIST_ARCHERS_BRONZE] = 0x14;
        b[BUILD_LIST_CAVALRY_BRONZE] = 0x14;
        b[BUILD_LIST_INFANTRY_BRONZE] = 0x46;
        b[BUILD_LIST_PRIEST_BRONZE] = 0x32;
        b[BUILD_LIST_PRIEST_IRON] = 0x5A;
        b[BUILD_LIST_CHOSON_SWORDSMEN] = 100;
        b[BUILD_LIST_CHOSON_AXEMEN] = 100;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_CHOSON_BRONZE_WATER] = 200;
            b[BUILD_LIST_CHOSON_IRON_WATER] = 200;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_CHOSON_BRONZE_WATER] = 100;
            b[BUILD_LIST_CHOSON_IRON_WATER] = 100;
        }
    }
}

void TRIBE_Player::setupRoman(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Roman.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_ROME_WATER] = 0x64;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_ROME] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_ROME_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_ROME] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_ROME_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_ROME] = 0x64;
        }
    } else {
        b[BUILD_LIST_ARCHERS_BRONZE] = 0x0A;
        b[BUILD_LIST_CAVALRY_BRONZE] = 0x0A;
        b[BUILD_LIST_INFANTRY_STONE] = 0x0A;
        b[BUILD_LIST_INFANTRY_TOOL] = 0x0A;
        b[BUILD_LIST_PRIEST_BRONZE] = 0x0A;
        b[BUILD_LIST_PRIEST_IRON] = 0x0A;
        b[BUILD_LIST_PHALANX_BRONZE] = 0x14;
        b[BUILD_LIST_PHALANX_IRON] = 0x14;
        b[BUILD_LIST_INFANTRY_BRONZE] = 0x50;
        b[BUILD_LIST_ROME_LEGION] = 0x64;
        b[BUILD_LIST_ROME_AXEMEN] = 0x3C;
        b[BUILD_LIST_ROME_SIEGE] = 0x50;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_ROME_BRONZE_WATER] = 0xC8;
            b[BUILD_LIST_ROME_IRON_WATER] = 0xC8;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_ROME_BRONZE_WATER] = 0x64;
            b[BUILD_LIST_ROME_IRON_WATER] = 0x64;
        }
    }
}

void TRIBE_Player::setupCarthaginian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Carthaginian.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_CARTHAGE_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_CARTHAGE] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_CARTHAGE_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_CARTHAGE] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_CARTHAGE_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_CARTHAGE] = 100;
        }
    } else {
        b[BUILD_LIST_ARCHERS_BRONZE] = 10;
        b[BUILD_LIST_ARCHERS_IRON] = 10;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 10;
        b[BUILD_LIST_CAVALRY_IRON] = 10;
        b[BUILD_LIST_INFANTRY_STONE] = 10;
        b[BUILD_LIST_INFANTRY_TOOL] = 10;
        b[BUILD_LIST_INFANTRY_BRONZE] = 10;
        b[BUILD_LIST_WAR_ELEPHANT_IRON] = 0x3C;
        b[BUILD_LIST_ELEPHANT_ARCHER_IRON] = 0x3C;
        b[BUILD_LIST_PHALANX_BRONZE] = 0x46;
        b[BUILD_LIST_CARTHAGE_PHALANX] = 0x50;
        b[BUILD_LIST_CARTHAGE_WAR_ELEPHANT] = 0x50;
        b[BUILD_LIST_PHALANX_IRON] = 0x32;
        b[BUILD_LIST_CAVALRY_BRONZE] = 0x1E;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_CARTHAGE_BRONZE_WATER] = 200;
            b[BUILD_LIST_CARTHAGE_IRON_WATER] = 200;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_CARTHAGE_BRONZE_WATER] = 100;
            b[BUILD_LIST_CARTHAGE_IRON_WATER] = 100;
        }
    }
}

void TRIBE_Player::setupPalmyran(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Palmyran.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_PALMYRA_WATER] = 0x64;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_PALMYRA] = 0x3C;
            b[BUILD_LIST_DEATH_MATCH_PALMYRA_WATER] = 0x28;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_PALMYRA] = 0x50;
            b[BUILD_LIST_DEATH_MATCH_PALMYRA_WATER] = 0x14;
        } else {
            b[BUILD_LIST_DEATH_MATCH_PALMYRA] = 0x64;
        }
    } else {
        b[BUILD_LIST_PHALANX_BRONZE] = 0x28;
        b[BUILD_LIST_CAVALRY_BRONZE] = 0x28;
        b[BUILD_LIST_ARCHERS_BRONZE] = 0x1E;
        b[BUILD_LIST_CAVALRY_IRON] = 0x0A;
        b[BUILD_LIST_INFANTRY_STONE] = 0x0A;
        b[BUILD_LIST_INFANTRY_TOOL] = 0x0A;
        b[BUILD_LIST_INFANTRY_BRONZE] = 0x0A;
        b[BUILD_LIST_ARCHERS_IRON] = 0x1E;
        b[BUILD_LIST_PALMYRA_COMPOSITE_BOW] = 0x50;
        b[BUILD_LIST_PALMYRA_HORSE_ARCHER] = 0x50;
        b[BUILD_LIST_PALMYRA_ELEPHANT] = 0x50;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 0x3C;
        b[BUILD_LIST_PHALANX_IRON] = 0x14;
        b[BUILD_LIST_WAR_ELEPHANT_IRON] = 0x3C;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_PALMYRA_BRONZE_WATER] = 0xC8;
            b[BUILD_LIST_PALMYRA_IRON_WATER] = 0xC8;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_PALMYRA_BRONZE_WATER] = 0x64;
            b[BUILD_LIST_PALMYRA_IRON_WATER] = 0x64;
        }
    }
}

void TRIBE_Player::setupMacedonian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Macedonian.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_DEATH_MATCH_MACEDON_WATER] = 100;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake) {
            b[BUILD_LIST_DEATH_MATCH_MACEDON] = 60;
            b[BUILD_LIST_DEATH_MATCH_MACEDON_WATER] = 40;
        } else if (mapType == TRIBE_Game::Continental || mapType == TRIBE_Game::Isthmas) {
            b[BUILD_LIST_DEATH_MATCH_MACEDON] = 80;
            b[BUILD_LIST_DEATH_MATCH_MACEDON_WATER] = 20;
        } else {
            b[BUILD_LIST_DEATH_MATCH_MACEDON] = 100;
        }
    } else {
        b[BUILD_LIST_PHALANX_BRONZE] = 0x28;
        b[BUILD_LIST_PHALANX_IRON] = 0x28;
        b[BUILD_LIST_ARCHERS_BRONZE] = 0x0A;
        b[BUILD_LIST_CAVALRY_BRONZE] = 0x1E;
        b[BUILD_LIST_CAVALRY_IRON] = 0x1E;
        b[BUILD_LIST_WAR_ELEPHANT_IRON] = 0x1E;
        b[BUILD_LIST_MACEDON_CAVALRY] = 0x50;
        b[BUILD_LIST_MACEDON_ELEPHANT] = 0x50;
        b[BUILD_LIST_MACEDON_PHALANX] = 0x50;
        b[BUILD_LIST_ARCHERS_IRON] = 0x0A;
        b[BUILD_LIST_CAV_ARCHER_IRON] = 0x14;

        if (mapType == TRIBE_Game::AllWater || mapType == TRIBE_Game::MostlyWater) {
            b[BUILD_LIST_MACEDON_BRONZE_WATER] = 0xC8;
            b[BUILD_LIST_MACEDON_IRON_WATER] = 0xC8;
        } else if (mapType == TRIBE_Game::WaterAndLand || mapType == TRIBE_Game::Lake || mapType == TRIBE_Game::Isthmas
                   || mapType == TRIBE_Game::Continental) {
            b[BUILD_LIST_MACEDON_BRONZE_WATER] = 100;
            b[BUILD_LIST_MACEDON_IRON_WATER] = 100;
        }
    }
}

void TRIBE_Player::logStatus(FILE* out, int firstTime) {
    char tempString[256];
    if (out == 0)
        return;

    fprintf(out, "Player %d:\n", static_cast<int>(this->id));
    if (firstTime == 1) {
        // Keep the arithmetic lookup; expansion civilization names use different resource IDs.
        rge_base_game->get_string(
            static_cast<int>(this->master_player_id) + (STRING_ID_CIVILIZATION_EGYPTIAN - 1), tempString, 256
        );
        if (this->playerAI == 0) {
            fprintf(out, "  Human Player, %s.\n", tempString);
        } else {
            fprintf(out, "  Computer Player, %s.\n", tempString);
            fprintf(out, "  Build List:      %s.\n", this->playerAI->buildAI.buildListName());
            fprintf(out, "  City Plan:       %s.\n", this->playerAI->constructionAI.constructionPlanName());
            fprintf(out, "  VC File:         %s.\n", this->playerAI->strategyAI.ruleSetName());
        }
    }

    fprintf(out, "  Points:\n");
    fprintf(out, "    Combat         %d.\n", this->victory_conditions->get_victory_points_group(0));
    fprintf(out, "    Economy        %d.\n", this->victory_conditions->get_victory_points_group(1));
    fprintf(out, "    Religion       %d.\n", this->victory_conditions->get_victory_points_group(2));
    fprintf(out, "    Science        %d.\n", this->victory_conditions->get_victory_points_group(3));
    fprintf(out, "    Survival       %d.\n", this->victory_conditions->get_victory_points_id(0x16));
    fprintf(out, "    Wonder         %d.\n", this->victory_conditions->get_victory_points_id(0x17));
    fprintf(out, "      Total:       %d.\n", this->victory_conditions->get_victory_points());
    fprintf(out, "  Population:      %d.\n", static_cast<int>(this->attributes[PLAYER_ATTRIBUTE_POPULATION]));
    fprintf(out, "  Kills:           %d.\n", this->victory_conditions->get_attribute_id(0));
    fprintf(out, "  Kill Ratio:      %d.\n", this->victory_conditions->get_attribute_id(2));
    fprintf(out, "  Razings:         %d.\n", this->victory_conditions->get_attribute_id(1));
    fprintf(out, "  Food:            %d.\n", static_cast<int>(this->attributes[RGE_RESOURCE_FOOD]));
    fprintf(out, "  Gold:            %d.\n", static_cast<int>(this->attributes[RGE_RESOURCE_GOLD]));
    fprintf(out, "  Stone:           %d.\n", static_cast<int>(this->attributes[RGE_RESOURCE_STONE]));
    fprintf(out, "  Wood:            %d.\n", static_cast<int>(this->attributes[RGE_RESOURCE_WOOD]));
    fprintf(out, "  Technology:      %d.\n", this->victory_conditions->get_attribute_id(0x11));
    fprintf(out, "  Exploration:     %d.\n", this->victory_conditions->get_attribute_id(7));

    if (this->playerAI != 0) {
        fprintf(
            out, "Build AI: last=%s, last2=%s, Progress=%d/%d.\n", this->playerAI->buildAI.currentBuildItemRequested(),
            this->playerAI->buildAI.lastBuildItemRequested(), this->playerAI->buildAI.numberItemsIntoBuildList(),
            this->playerAI->buildAI.buildListLength()
        );
        fprintf(
            out, "Civilians: Total=%d, Exp(%d/%d), Gat(%d/%d), Res(%d,%d,%d,%d).\n",
            this->playerAI->tacticalAI.numberCivilians(), this->playerAI->tacticalAI.numberCivilianExplorers(),
            this->playerAI->tacticalAI.desiredNumberCivilianExplorers(), this->playerAI->tacticalAI.numberGatherers(),
            this->playerAI->tacticalAI.desiredNumberGatherers(), this->playerAI->tacticalAI.neededResource(0),
            this->playerAI->tacticalAI.neededResource(1), this->playerAI->tacticalAI.neededResource(2),
            this->playerAI->tacticalAI.neededResource(3)
        );
        fprintf(out, "Number Soldiers=%d.\n", this->playerAI->tacticalAI.numberSoldiers());
    }
}

void TRIBE_Player::trackUnitGather(int unitID, int attributeID, int amount) {
    if (!this->playerAI)
        return;

    this->playerAI->tacticalAI.trackUnitGather(unitID, attributeID, amount);
}

void TRIBE_Player::get_achievement(unsigned char achievement, char* info) {
    switch (achievement) {
        case 0:
            strcpy(info, name);
            break;
        case 1:
            sprintf(
                info, "%4.f", attributes[PLAYER_ATTRIBUTE_TOTAL_UNITS_OWNED] - attributes[PLAYER_ATTRIBUTE_POPULATION]
            );
            break;
        case 2:
            sprintf(info, "%4.f", attributes[PLAYER_ATTRIBUTE_KILLS]);
            break;
        case 3:
            sprintf(info, "%4.f", attributes[PLAYER_ATTRIBUTE_POPULATION]);
            break;
        case 4:
            sprintf(info, "%5.f", attributes[RGE_RESOURCE_GOLD]);
            break;
        case 5: {
            float pct = this->visible->percentExplored() * 100.0f;
            sprintf(info, "%3.f%%", pct);
            break;
        }
        case 6:
            sprintf(info, "%4.f", attributes[PLAYER_ATTRIBUTE_TOTAL_UNITS_OWNED]);
            break;
        case 7:
            sprintf(
                info, "%4.f/%4.f/%4.f", attributes[PLAYER_ATTRIBUTE_ARTIFACTS],
                attributes[PLAYER_ATTRIBUTE_DISCOVERIES], attributes[PLAYER_ATTRIBUTE_RUINS]
            );
            break;
        case 8:
            sprintf(info, "%4.f", attributes[PLAYER_ATTRIBUTE_TECHNOLOGY_COUNT]);
            break;
    }
}

void TRIBE_Player::load_victory(int infile, long* player_id_hash, unsigned char version_control) {
    TRIBE_Victory_Conditions* v = new TRIBE_Victory_Conditions(this, infile, player_id_hash, version_control);
    this->victory_conditions = v;
}

void TRIBE_Player::new_victory() {
    TRIBE_Victory_Conditions* v = new TRIBE_Victory_Conditions(this);
    this->victory_conditions = v;
}

void TRIBE_Player::add_attribute_num(short attribute, float amount, unsigned char earned) {
    if ((attribute == RGE_RESOURCE_GOLD) && (earned != 0)) {
        this->attributes[PLAYER_ATTRIBUTE_GOLD_EARNED] = amount + this->attributes[PLAYER_ATTRIBUTE_GOLD_EARNED];
    }
    if (attribute == PLAYER_ATTRIBUTE_ALLIED_LOS) {
        this->allied_LOS_Enable = 1;
        this->world->update_mutual_allies();
    }
    RGE_Player::add_attribute_num(attribute, amount, earned);
}

void TRIBE_Player::analyize_selected_objects() {
    int i = 0;
    tplayer_globals::selectedObjectCount = 0;
    this->sel_object_properties = 0;

    if (this->sel_count == 0) {
        return;
    }

    int j = 0;
    RGE_Static_Object** p = this->sel_list;
    for (; i < 25; ++i, ++p) {
        if (j >= this->sel_count) {
            return;
        }
        if (*p != 0) {
            if ((*p)->owner->id == this->id) {
                int group = (*p)->master_obj->object_group;
                if (group >= 0 && group < tribe_group_properties_num) {
                    if (group == OBJECT_GROUP_PRIEST) {
                        this->sel_object_properties |= 0x16;
                        ++tplayer_globals::selectedObjectCount;
                        tplayer_globals::selectedObjectId = (*p)->id;
                        if ((*p)->attribute_amount_held >= 100.0f) {
                            this->sel_object_properties |= 0x80;
                        }
                    } else {
                        this->sel_object_properties |= tribe_group_properties[group];
                    }
                }

                int object_id = (*p)->master_obj->id;
                if (object_id == 0x4F || object_id == 0xC7 || object_id == 0x45 || object_id == 0x116) {
                    this->sel_object_properties |= 1;
                }
            }
            ++j;
        }
    }
}

int TRIBE_Player::get_mouse_pointer_action_vars(int Obj_id, int& newFacet, int& text_id) {
    int ObjectType;
    int ObjPlayer;
    RGE_Static_Object* thisObj;
    int MaxHp;
    int MstrObjId;
    RGE_Master_Static_Object* master;
    MouseClickInfo* entry;
    int use_selection;
    MouseClickInfo* RtClickTable;
    int table_count;
    int action_code;
    int action_var;
    int current;

    thisObj = this->world->object(Obj_id);
    entry = 0;
    newFacet = 0;
    text_id = 0;
    current = 0;
    if (thisObj != 0) {
        if (thisObj->type == 0x19) {
            RGE_Doppleganger_Object* dopple = static_cast<RGE_Doppleganger_Object*>(thisObj);
            master = dopple->doppled_master_obj;
            ObjectType = dopple->doppled_player;
            ObjPlayer = master->object_group;
            MstrObjId = master->id;
            MaxHp = master->hp;
        } else {
            master = thisObj->master_obj;
            ObjPlayer = master->object_group;
            ObjectType = thisObj->owner->id;
            MstrObjId = master->id;
            MaxHp = master->hp;
        }

        if (ObjectType < 0 || ObjectType >= this->world->player_num) {
            return 0;
        }

        this->analyize_selected_objects();
        if (MstrObjId == MASTER_OBJECT_ARTIFACT_RUINS1 || MstrObjId == MASTER_OBJECT_ARTIFACT_RUINS2) {
            current = 50;
        }

    retry_table:
        if (this->sel_count == 0 || this->sel_object_properties == 0) {
            TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
            use_selection = 0;
            RtClickTable = game->MouseLeftClickTable;
            table_count = game->MouseLeftClickTableSize;
        } else {
            TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
            use_selection = 1;
            RtClickTable = game->MouseRightClickTable;
            table_count = game->MouseRightClickTableSize;
        }

        if (ObjPlayer >= 0 && ObjPlayer < table_count) {
            MouseClickInfo* probe = RtClickTable + ObjPlayer;
            if (probe->object_group == ObjPlayer) {
                entry = probe;
            }
        }
        if (entry == 0) {
            int i = 0;
            while (i < table_count) {
                MouseClickInfo* scan = RtClickTable + i;
                if (scan->object_group == ObjPlayer) {
                    entry = RtClickTable + i;
                    break;
                }
                ++i;
            }
        }
        if (entry == 0) {
            return 0;
        }

        switch (this->unitDiplomacy[ObjectType]) {
            case 0:
                action_code = entry->gaia_action;
                action_var = entry->gaia_text_id;
                break;
            case 1:
                action_code = entry->self_action;
                action_var = entry->self_text_id;
                break;
            case 2:
                action_code = entry->ally_action;
                action_var = entry->ally_text_id;
                break;
            case 3:
                action_code = entry->neutral_action;
                action_var = entry->neutral_text_id;
                break;
            case 4:
                action_code = entry->enemy_action;
                action_var = entry->enemy_text_id;
                break;
            default:
                action_code = -1;
                action_var = -1;
                break;
        }
        if (action_code == -1) {
            return 0;
        }

    redo_mouseFunc:
        do {
            switch (action_code) {
                case 0:
                    newFacet = 0;
                    text_id = current + action_var;
                    goto finish;
                case 1:
                case 8:
                    if ((this->sel_object_properties & 1) != 0 && thisObj->object_state <= RGE_OBJECT_STATE_ACTIVE) {
                        newFacet = 4;
                        text_id = current + action_var;
                        goto finish;
                    }
                    if (action_code != 8) {
                        goto finish;
                    }
                    current = 50;
                    action_code = 7;
                    continue;
                case 2:
                    if ((this->sel_object_properties & 2) == 0) {
                        goto finish;
                    }
                    newFacet = 5;
                    text_id = current + action_var;
                    goto finish;
                case 3:
                    if ((this->sel_object_properties & 4) == 0) {
                        goto finish;
                    }
                    newFacet = 5;
                    text_id = current + action_var;
                    goto finish;
                case 4:
                    if ((this->sel_object_properties & 0x10) == 0) {
                        goto finish;
                    }
                    if (tplayer_globals::selectedObjectCount == 1 && Obj_id == tplayer_globals::selectedObjectId) {
                        goto finish;
                    }
                    {
                        int hp = static_cast<int>(thisObj->hp);
                        if (hp <= 0 || hp >= MaxHp) {
                            goto finish;
                        }
                    }
                    newFacet = 5;
                    text_id = current + action_var;
                    goto finish;
                case 5:
                    if ((this->sel_object_properties & 0x20) == 0) {
                        goto finish;
                    }
                    if (thisObj->object_state == RGE_OBJECT_STATE_UNBUILT) {
                        current = 50;
                    }
                    //! @bug The full-hp gate drops an intact farm here and falls back to the retry.
                    //! The retry re-reads the left-click table, so it shows "Click to select" and facet 0.
                    //! A villager selection gets no work hint or cursor, even though right-click works.
                    {
                        int hp = static_cast<int>(thisObj->hp);
                        if (hp <= 0 || hp >= MaxHp) {
                            goto finish;
                        }
                    }
                    newFacet = 3;
                    text_id = current + action_var;
                    goto finish;
                case 6:
                case 9:
                    if ((this->sel_object_properties & 0x40) != 0) {
                        newFacet = 3;
                        text_id = current + action_var;
                        goto finish;
                    }
                    if (action_code != 9) {
                        goto finish;
                    }
                    current = 50;
                    action_code = 1;
                    continue;
                case 7:
                    if ((this->sel_object_properties & 0x80) == 0) {
                        goto finish;
                    }
                    if (ObjPlayer == OBJECT_GROUP_PRIEST
                        && this->attributes[PLAYER_ATTRIBUTE_PRIEST_CONVERSION] == g_player_selection_zero_attribute) {
                        goto finish;
                    }
                    if (ObjPlayer == OBJECT_GROUP_BUILDING
                        && this->attributes[PLAYER_ATTRIBUTE_BUILDING_CONVERSION]
                               == g_player_selection_zero_attribute) {
                        goto finish;
                    }
                    if (ObjPlayer == 3
                        && (MstrObjId == MASTER_OBJECT_TOWN_CENTER1 || MstrObjId == MASTER_OBJECT_WONDER)) {
                        goto finish;
                    }
                    newFacet = 5;
                    text_id = current + action_var;
                    goto finish;
                default:
                    newFacet = 0;
                    text_id = 0;
                    goto finish;
            }
        } while (1);

    finish:
        if (use_selection == 1 && newFacet == 0 && text_id == 0) {
            this->sel_object_properties = 0;
            entry = 0;
            goto retry_table;
        }
        return 1;
    }
    return 0;
}

TRIBE_Gaia::TRIBE_Gaia(int infile, TRIBE_World* gworld, unsigned char this_id) : TRIBE_Player(infile, gworld, this_id) {
    this->type = 2;
    rge_read(infile, &update_time, 4);
    rge_read(infile, &update_nature, 4);
    rge_read(infile, &animal_max, 4);
    rge_read(infile, &last_count, 4);
}

TRIBE_Gaia::TRIBE_Gaia(
    TRIBE_World* gworld, RGE_Master_Player* prototype, unsigned char this_id, char* new_name, unsigned char m_player_id
) : TRIBE_Player(gworld, prototype, this_id, new_name, m_player_id, 0, 1, 0, 0, 0) {
    this->type = 2;
    this->update_time = 0.0f;
    this->update_nature = 0x1D;
    this->animal_max = 0;
    this->last_count = 0;
}

void TRIBE_Gaia::save(int outfile) {
    TRIBE_Player::save(outfile);

    rge_write(outfile, &this->update_time, 4);
    rge_write(outfile, &this->update_nature, 4);
    rge_write(outfile, &this->animal_max, 4);
    rge_write(outfile, &this->last_count, 4);
}

void TRIBE_Gaia::update() {
    this->update_time = this->update_time + this->world->world_time_delta_seconds;
    if (this->update_time > 1.0f) {
        do {
            this->update_time = this->update_time - 1.0f;
            if (++this->update_nature == 0x1E) {
                this->update_nature = 0;
            }
        } while (this->update_time > 1.0f);
    }
    RGE_Player::update();
}

void TRIBE_Gaia::load_master_object(
    int infile, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds
) {
    TRIBE_Player::load_master_object(infile, index, type, sprites, sounds);
}

void TRIBE_Gaia::random_start() {
}

void TRIBE_Player::scenario_postload(int infile, long* player_id_hash, float version) {
    RGE_Player::scenario_postload(infile, player_id_hash, version);
    if (0.0 < this->attributes[PLAYER_ATTRIBUTE_ALLIED_LOS]) {
        this->allied_LOS_Enable = 1;
        this->world->update_mutual_allies();
    }
}
