#include "../include/tplayer.h"
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
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// TPlayer owns the object-group selection property table at 0058ABA0.
unsigned long tribe_group_properties[0x28] = {
    7, 0, 4, 0, 0x67, 0, 7, 0,
    0, 0, 0, 0, 7, 7, 0, 0,
    0, 0, 0x10, 0x96, 0, 0, 1, 7,
    7, 7, 7, 0, 7, 0, 0, 0,
    0, 7, 0, 0, 0, 0, 0, 7
};
int tribe_group_properties_num = 0x28;

static char tplayerSourceName[] = "C:/msdev/work/age1_x1/tplayer.cpp";
static char tplayerEmptyName[] = "";
static char tplayerRandomName[] = "Random";
static char tplayerDefaultPlan[] = "default";
static char tplayerMapMessages[6][32] = {
    "Map: unknown", "Map: open", "Map: water", "Map: highland",
    "Map: forest", "Map: random"
};
static char tplayerBuildMessage[] = "Build list: %s";
static char tplayerFileMessage[] = "File: %s";
static char tplayerDefaultMessage[] = "Default";
static char tplayerRulesMessage[] = "Rules: %s";
static char tplayerDifficultyMessage[] = "Difficulty: %d";



TRIBE_Player::TRIBE_Player(int fd, TRIBE_World* world, unsigned char mode)
    : RGE_Player(fd, world, mode), playerAI(0)
{
    rge_read(fd, &this->type, 1);
    rge_read(fd, &this->update_count, 4);
    rge_read(fd, &this->updateCountNeedHelp, 4);
    rge_read(fd, &this->fog_update, 4);
    rge_read(fd, &this->update_time, 4);

    this->tech_tree = new TRIBE_Player_Tech(fd, world->tech, this, 0);

    if (save_game_version > 5.0f) {
        rge_read(fd, &this->update_history_count, 4);
        this->history = new TRIBE_History_Info(fd);
    } else {
        this->update_history_count = 0;
        this->history = new TRIBE_History_Info(-1);
    }

    if (save_game_version >= 5.30000019f) {
        rge_read(fd, &this->ruin_held_time, 4);
        rge_read(fd, &this->artifact_held_time, 4);
    } else {
        this->ruin_held_time = -1.0f;
        this->artifact_held_time = -1.0f;
    }

    if (this->type == 3) {
        int create_ai = 1;
        if (save_game_version >= 7.03000021f) {
            rge_read(fd, &create_ai, 4);
        }
        if (comm->IsHost() == 1 && create_ai == 1) {
            this->playerAI = new TribeMainDecisionAIModule(this->id, this->name, this, fd);
        }
        this->computerPlayerValue = 1;
    }
}







TRIBE_Player::TRIBE_Player(TRIBE_World* world, RGE_Master_Player* master,
                           unsigned char player_id, char* name_arg,
                           unsigned char civ, unsigned char make_ai,
                           unsigned char make_lists, char* ai1, char* ai2,
                           char* ai3)
    : RGE_Player(world, master, player_id, name_arg, civ, 0), playerAI(0)
{
    this->VR_List = new Visible_Resource_Manager(this, 5);

    if (make_ai == 0) {
        this->type = 1;
    } else {
        this->type = 3;
        this->computerPlayerValue = 1;
        if (comm->IsHost() == 1) {
            this->playerAI = new TribeMainDecisionAIModule(
                0, this->id, this->name, this, ai1, ai2, ai3);
        }
    }

    if (make_lists != 0) {
        TRIBE_Object_List* list;

        list = new TRIBE_Object_List;
        this->objects = list;
        list = new TRIBE_Object_List;
        this->sleeping_objects = list;
        list = new TRIBE_Object_List;
        this->doppleganger_objects = list;
        this->new_victory();
        this->visible = new RGE_Visible_Map(world->map, this);
    }

    int i = 1;
    if (this->world->player_num > 1) {
        do {
            if (i != this->id) {
                this->set_relation(i, 3);
            }
            ++i;
        } while (i < this->world->player_num);
    }

    this->update_count = 0;
    this->update_history_count = 0;
    this->updateCountNeedHelp = 0;
    this->fog_update = (debug_rand(tplayerSourceName, 0x140) * 3) / 0x7fff + 3;
    this->update_time = 0.0f;
    this->history = new TRIBE_History_Info(-1);
    this->tech_tree = new TRIBE_Player_Tech(world->tech, this, 1);
    this->ruin_held_time = -1.0f;
    this->artifact_held_time = -1.0f;
}



TRIBE_Player::~TRIBE_Player()
{
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



RGE_Static_Object* TRIBE_Player::make_scenario_obj(float x, float y, float z, short type_id, unsigned char mode, float amount)
{
    RGE_Static_Object* obj = 0;
    RGE_Master_Static_Object* type = this->master_objects[type_id];
    if (type) {
        obj = type->make_new_obj(this, x, y, z);
        if (mode >= 7) {
            obj->destroy_obj();
        }
        else if (mode > 2) {
            obj->die_die_die();
        }
        else {
            unsigned char master_type = obj->master_obj->master_type;
            if (master_type > 0x1E && master_type < 0x5A) {
                obj->new_angle(amount);
            }
            else {
                obj->facet = static_cast<unsigned char>(static_cast<int>(amount));
            }
        }
        if (this->master_objects[type_id]->master_type == 0x50 && mode == 2) {
            static_cast<TRIBE_Building_Object*>(obj)->build(10000.0f);
        }
    }
    return obj;
}




void TRIBE_Player::save(int file)
{
    int save_file = file;
    int present;
    color_log(0x16, 0x16, 2);
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
    if (this->type == 1 && this->playerAI != 0 && comm->IsHost() == 1) {
        present = 1;
        rge_write(save_file, &present, 4);
        this->playerAI->save(save_file);
    } else {
        present = 0;
        rge_write(save_file, &present, 4);
    }
    color_log(0x16, 0x5F, 2);
}




void TRIBE_Player::update()
{
    float* attributes = this->attributes;
    this->update_time += this->world->world_time_delta_seconds;
    while (this->update_time > 1.0f) {
        this->update_time -= 1.0f;
        ++this->update_history_count;
        if (this->update_history_count >= 15) {
            this->update_history_count -= 15;
            unsigned char population = attributes[11] < 0.0f
                ? 0 : static_cast<unsigned char>(static_cast<long>(attributes[11]));
            this->history->add_history_entry(0, population);
        }
        if (rge_base_game->fullVisibility()) attributes[22] = 100.0f;
        else attributes[22] = this->visible->percentExplored() * 100.0f;
        attributes[44] = attributes[20] - (attributes[19] - attributes[11]);
        if (attributes[44] < 0.0) attributes[44] = 0.0f;
        attributes[9] += attributes[10];
        if (attributes[9] > 100.0) attributes[9] = 100.0f;
        if (this->update_count > 0) --this->update_count;
        if (this->updateCountNeedHelp > 0) --this->updateCountNeedHelp;
        if (this->id > 0) {
            RGE_Object_Node* node = this->objects->list;
            while (node != 0) {
                RGE_Static_Object* object = node->node;
                short group = object->master_obj->object_group;
                if (group != 0xb && group != 0x1e && group != 0x1b &&
                    group != 1 && group != 0x15 && group != 0x14 &&
                    group != 2 && group != 0x25 && object->object_state == 2)
                    break;
                node = node->next;
            }
            if (node == 0) {
                this->set_game_status(2);
                attributes[45] = 0.0f;
            }
        }
    }
    RGE_Player::update();
    attributes[0] -= this->world->world_time_delta_seconds * attributes[33] * attributes[11] * 0.0166666675f;
    if (attributes[0] < 0.0) attributes[0] = 0.0f;
    int seed = debug_rand(tplayerSourceName, 0x25f);
    int old = debug_random_on;
    global_save_debug_random_on1 = old;
    debug_random_on = 0;
    if (this->playerAI && comm->ComputerPlayerGameStart() == 1) {
        if (this->world->currentUpdateComputerPlayer == -1) this->world->selectNextComputerPlayer(3);
        this->playerAI->update(0);
    }
    debug_random_on = old;
    debug_srand(tplayerSourceName, 0x277, seed);
    if (MouseSystem != 0) MouseSystem->Poll();
}


void TRIBE_Player::update_dopplegangers() { RGE_Player::update_dopplegangers(); }

void TRIBE_Player::scenario_save(int file) {
    RGE_Player::scenario_save(file);
    rge_write(file, &this->attributes[0], 4);
    rge_write(file, &this->attributes[1], 4);
    rge_write(file, &this->attributes[3], 4);
    rge_write(file, &this->attributes[2], 4);
}


void TRIBE_Player::scenario_load(int file, long* pos, float version)
{
    TRIBE_Player_Tech* tech;
    int i;
    RGE_Master_Static_Object* obj;

    RGE_Player::scenario_load(file, pos, version);

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
        rge_read(file, &this->attributes[0], 4);
        rge_read(file, &this->attributes[1], 4);
        rge_read(file, &this->attributes[3], 4);
        rge_read(file, &this->attributes[2], 4);
    }

    this->attributes[30] = 0.0f;
    this->attributes[21] = 0.0f;

    if (version <= 1.03) {
        this->tech_tree = new TRIBE_Player_Tech(file, static_cast<TRIBE_World*>(this->world)->tech, this, 1);
        return;
    }

    tech = new TRIBE_Player_Tech(static_cast<TRIBE_World*>(this->world)->tech, this, 0);
    this->tech_tree = tech;

    if (this->culture >= 0 && !static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree() && !static_cast<T_Scenario*>(static_cast<TRIBE_World*>(this->world)->scenario)->GetScenarioOption(2)) {
        static_cast<TRIBE_Effects*>(static_cast<TRIBE_World*>(this->world)->effects)->do_tech_effect(static_cast<short>(this->culture), this);
    }
    else {
        static_cast<TRIBE_Effects*>(static_cast<TRIBE_World*>(this->world)->effects)->do_tech_effect(0xD2, this);
    }

    if (rge_base_game->game_mode != 7) {
        static_cast<T_Scenario*>(static_cast<TRIBE_World*>(this->world)->scenario)->set_player_tech(this);
    }
    this->tech_tree->check_for_new_tech();
}


void TRIBE_Player::load(int file)
{
    rge_read(file, &this->master_object_num, 2);
    short count = this->master_object_num;
    if (count > 0) {
        // RGE_Player releases this shared table with free().
        this->master_objects = static_cast<RGE_Master_Static_Object**>(
            calloc(count, sizeof(*this->master_objects)));
        rge_read(file, this->master_objects, this->master_object_num * 4);
        for (short i = 0; i < this->master_object_num; ++i) {
            if (this->master_objects[i] != 0) {
                unsigned char type;
                rge_read(file, &type, 1);
                this->load_master_object(file, i, type, this->world->sprites, this->world->sounds);
            }
        }
    } else {
        this->master_objects = 0;
    }

    this->visible = new RGE_Visible_Map(file, this->world);
    this->VR_List = new Visible_Resource_Manager(file, this);
    this->objects = new TRIBE_Object_List;
    this->objects->load_list(file, this->world);
    this->sleeping_objects = new TRIBE_Object_List;
    this->sleeping_objects->load_list(file, this->world);
    this->doppleganger_objects = new RGE_Object_List;

    if (save_game_version >= 7.09000015f) {
        this->doppleganger_objects->load_list(file, this->world);
    }
}




void TRIBE_Player::load_master_object(int first, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Static_Object* obj;

    switch (type) {
    case 'F':
        obj = new TRIBE_Master_Combat_Object(first, sprites, sounds, 1);
        break;
    case 'P':
        obj = new TRIBE_Master_Building_Object(first, sprites, sounds, 1);
        master_objects[index] = obj;
        return;
    case 'Z':
        obj = new TRIBE_Master_Tree_Object(first, sprites, sounds, 1);
        break;
    default:
        RGE_Player::load_master_object(first, index, type, sprites, sounds);
        return;
    }
    master_objects[index] = obj;
}


void TRIBE_Player::tech_cost(short tech_id, short& value_1, short& value_2,
                             short& value_3, short& value_4, short& value_5,
                             short& value_6) {
    TRIBE_Player_Tech* tech =
        this->tech_tree;
    tech->tech_cost(tech_id, &value_1, &value_2, &value_3,
                    &value_4, &value_5, &value_6);
}



void TRIBE_Player::obj_cost(short obj, char** nameOut, short& t1, short& a1,
                             short& t2, short& a2, short& t3, short& a3,
                             float factor)
{
    short* amount_output;
    short available;
    short total = 0;
    t1 = -1;
    a1 = 0;
    t2 = -1;
    a2 = 0;
    t3 = -1;
    a3 = 0;

    unsigned char canUseAvailableResources =
        this->check_obj_cost(obj, 0, 1.0f, 0);
    RGE_Master_Static_Object* master =
        this->master_objects[obj];
    if (master == 0 || master->master_type < 0x46) return;
    if (nameOut != 0) *nameOut = master->name;

    TRIBE_Master_Combat_Object* combat =
        static_cast<TRIBE_Master_Combat_Object*>(master);
    if (combat->build_inventory[0].flag != 0) {
        t1 = combat->build_inventory[0].type;
        if (t1 >= 0) {
            a1 = static_cast<short>(combat->build_inventory[0].amount * factor);
            if (static_cast<float>(a1) > this->attributes[t1] &&
                canUseAvailableResources != 0) {
                available = static_cast<short>(this->attributes[t1]);
                total = static_cast<short>(total + a1 - available);
                a1 = available;
            }
        }
    }
    if (combat->build_inventory[1].flag != 0) {
        t2 = combat->build_inventory[1].type;
        if (t2 >= 0) {
            a2 = static_cast<short>(combat->build_inventory[1].amount * factor);
            if (static_cast<float>(a2) > this->attributes[t2] &&
                canUseAvailableResources != 0) {
                available = static_cast<short>(this->attributes[t2]);
                total = static_cast<short>(total + a2 - available);
                a2 = available;
            }
        }
    }
    if (combat->build_inventory[2].flag != 0) {
        t3 = combat->build_inventory[2].type;
        if (t3 >= 0) {
            a3 = static_cast<short>(combat->build_inventory[2].amount * factor);
            if (static_cast<float>(a3) > this->attributes[t3] &&
                canUseAvailableResources != 0) {
                available = static_cast<short>(this->attributes[t3]);
                total = static_cast<short>(total + a3 - available);
                a3 = available;
            }
        }
    }

    if (total > 0) {
        if (t1 == 3 || t1 == -1) {
            t1 = 3;
            amount_output = &a1;
        } else if (t2 == 3 || t2 == -1) {
            t2 = 3;
            amount_output = &a2;
        } else if (t3 != 3 && t3 != -1) {
            amount_output = 0;
        } else {
            t3 = 3;
            a3 = total;
            amount_output = 0;
        }
        if (amount_output != 0) *amount_output = static_cast<short>(*amount_output + total);
    }

    if (a1 <= 0) t1 = -1;
    if (a2 <= 0) t2 = -1;
    if (a3 <= 0) t3 = -1;
}


RGE_Static_Object* TRIBE_Player::find_obj(short id, RGE_Static_Object* after)
{
    if (after != 0) {
        int found = 0;
        RGE_Object_Node* node = this->objects->list;
        while (node != 0) {
            RGE_Static_Object* object = node->node;
            if (object != 0) {
                if (found) {
                    if (object->master_obj->id == id && object->object_state <= 2)
                        return object;
                } else if (object == after) {
                    found = 1;
                }
            }
            node = node->next;
        }
    }

    RGE_Object_Node* node = this->objects->list;
    if (node == 0) return 0;
    for (;;) {
        RGE_Static_Object* object = node->node;
        if (object != 0 && object->master_obj->id == id && object->object_state == 2)
            return object;
        node = node->next;
        if (node == 0) return 0;
    }
}


RGE_Static_Object* TRIBE_Player::make_new_object(long id, float x, float y, float z, int unused)
{
    RGE_Static_Object* object = RGE_Player::make_new_object(id, x, y, z, unused);
    if (object == 0) return 0;
    if (unused != 0) {
        static_cast<TRIBE_World*>(this->world)->check_destructables(
            static_cast<short>(id), static_cast<short>(id), x, y, 0);
        if (object->master_obj->master_type == 'P')
            static_cast<TRIBE_Building_Object*>(object)->build(10000.0f);
    }
    if (rge_base_game->prog_mode == 7 &&
        (object->master_obj->object_group == 5 ||
         object->master_obj->object_group == 0x21))
        object->sprite_list->set_frame(object->sprite, 5);
    return object;
}


void TRIBE_Player::interface_tech_avail(Item_Avail** out_items, short* out_count, short button_location)
{
    short count = 0;
    short inv1, amt1, inv2, amt2, inv3, amt3;
    Tech_Tree* master = static_cast<TRIBE_World*>(this->world)->tech->tech_tree;

    for (short i = 0; i < this->tech_tree->tech_player_tree_num; i++) {
        if (this->tech_tree->tech_player_tree[i].state == 1 &&
            master[i].build_obj_id == button_location) {
            count++;
        }
    }

    if (*out_items != 0) {
        free(*out_items);
        *out_items = 0;
    }

    *out_count = count;
    if (count == 0) {
        return;
    }

    // The dialog owns this C-allocated block and releases it with free().
    *out_items = static_cast<Item_Avail*>(calloc(count, sizeof(Item_Avail)));

    short n = 0;
    short out_index = 0;
    if (this->tech_tree->tech_player_tree_num <= 0) {
        return;
    }

    do {
        int idx = n;
        if (this->tech_tree->tech_player_tree[idx].state == 1) {
            Tech_Tree* entry = &master[idx];
            if (entry->build_obj_id == button_location) {
                int avail_index = out_index;
                Item_Avail* item = *out_items;
                item[avail_index].id = n;
                (*out_items)[avail_index].pict = entry->icon;
                (*out_items)[avail_index].name = entry->name;

                this->tech_tree->tech_cost(n, &inv1, &amt1, &inv2, &amt2, &inv3, &amt3);

                (*out_items)[avail_index].inventory_item_1 = inv1;
                (*out_items)[avail_index].inventory_cost_1 = amt1;
                (*out_items)[avail_index].inventory_item_2 = inv2;
                (*out_items)[avail_index].inventory_cost_2 = amt2;
                (*out_items)[avail_index].inventory_item_3 = inv3;
                (*out_items)[avail_index].inventory_cost_3 = amt3;
                (*out_items)[avail_index].help_string_id = this->tech_tree->get_help_message(n);
                (*out_items)[avail_index].help_page_id = this->tech_tree->get_help_page(n);

                out_index++;
            }
        }
        n++;
    } while (n < this->tech_tree->tech_player_tree_num);
}




void TRIBE_Player::interface_item_avail(Item_Avail** out, short* count_out, short group)
{
    short add_extra = 0;
    short count = 0;
    short inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3;

    if (this->master_object_num > 0) {
        RGE_Master_Static_Object** pp = this->master_objects;
        int n = this->master_object_num;
        do {
            RGE_Master_Static_Object* m = *pp;
            if (m != 0 && m->master_type >= 0x46 && m->available != 0 && m->object_group == group) count++;
            pp++;
            n--;
        } while (n != 0);
    }

    if (group == 0x76 && this->attributes[0x30] == 0.0f && this->master_objects[0x6d]->available == 0) {
        add_extra = 1;
        RGE_Object_Node* node = this->objects->list;
        while (node != 0) {
            if (node->node->master_obj->id == 0x6d) add_extra = 0;
            node = node->next;
        }
    }
    if (add_extra != 0) count++;

    Item_Avail** item_list = out;
    if (*item_list != 0) { free(*item_list); *item_list = 0; }
    *count_out = count;
    if (count == 0) return;
    // The dialog owns this C-allocated block and releases it with free().
    *item_list = static_cast<Item_Avail*>(calloc(count, sizeof(Item_Avail)));

    short idx = 0;
    short out_i = 0;
    while (idx < this->master_object_num) {
            if (this->master_objects[idx] != 0 && this->master_objects[idx]->master_type >= 0x46 &&
                this->master_objects[idx]->available != 0 && this->master_objects[idx]->object_group == group) {
                (*item_list)[out_i].id = idx;
                (*item_list)[out_i].pict = this->master_objects[idx]->button_pict;
                (*item_list)[out_i].name = this->master_objects[idx]->name;
                this->obj_cost(static_cast<short>(idx), 0, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3, 1.0f);
                (*item_list)[out_i].inventory_item_1 = inv_1;
                (*item_list)[out_i].inventory_cost_1 = inv_amt_1;
                (*item_list)[out_i].inventory_item_2 = inv_2;
                (*item_list)[out_i].inventory_cost_2 = inv_amt_2;
                (*item_list)[out_i].inventory_item_3 = inv_3;
                (*item_list)[out_i].inventory_cost_3 = inv_amt_3;
                (*item_list)[out_i].help_string_id = this->master_objects[idx]->get_help_message();
                (*item_list)[out_i].help_page_id = this->master_objects[idx]->get_help_page();
                ++out_i;
            }
            idx++;
    }

    if (add_extra != 0) {
        (*item_list)[out_i].id = 0x6d;
        (*item_list)[out_i].pict = this->master_objects[0x6d]->button_pict;
        (*item_list)[out_i].name = this->master_objects[0x6d]->name;
        this->obj_cost(0x6d, 0, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3, 1.0f);
        (*item_list)[out_i].inventory_item_1 = inv_1;
        (*item_list)[out_i].inventory_cost_1 = inv_amt_1;
        (*item_list)[out_i].inventory_item_2 = inv_2;
        (*item_list)[out_i].inventory_cost_2 = inv_amt_2;
        (*item_list)[out_i].inventory_item_3 = inv_3;
        (*item_list)[out_i].inventory_cost_3 = inv_amt_3;
        (*item_list)[out_i].help_string_id = this->master_objects[0x6d]->get_help_message();
        (*item_list)[out_i].help_page_id = this->master_objects[0x6d]->get_help_page();
    }
}


void TRIBE_Player::interface_trade_avail(Trade_Avail** out_trade,
                                          short* out_count)
{
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
                        if (node->node->master_obj->id == 0x2D) {
                            if (this->visible->get_visible(
                                    static_cast<short>(node->node->world_x),
                                    static_cast<short>(node->node->world_y))) {
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

    if (*out_trade != 0) {
        free(*out_trade);
        *out_trade = 0;
    }

    *out_count = static_cast<short>(dock_count);
    if (dock_count != 0) {
        // The dialog owns this C-allocated block and releases it with free().
        *out_trade = static_cast<Trade_Avail*>(calloc(dock_count, sizeof(Trade_Avail)));
        if (dock_count > 0) {
            RGE_Static_Object** input = dock_list;
            Trade_Avail* output = *out_trade;
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



unsigned char TRIBE_Player::command_make_building(short type, float x, float y) {
    short selectedCount;
    RGE_Static_Object** list;
    short list_num;

    RGE_Master_Static_Object* info = this->master_objects[type];
    if (info != 0 && (info->available != 0 || type == 0x6d)) {
        if (get_selected_objects_to_command(&list, &selectedCount, 4, 4, -1, -1)) {
            this->master_objects[0x76]->play_command_sound();
            static_cast<TRIBE_Command*>(this->world->commands)->command_build(list, selectedCount, type, x, y);
            free(list);
            return 1;
        }
    }

    return 0;
}



unsigned char TRIBE_Player::command_make_wall(short type, long p2, long p3,
                                               long p4, long p5)
{
    short selectedCount;
    RGE_Static_Object** list;

    RGE_Master_Static_Object* info = this->master_objects[type];
    if (info != 0 && info->available != 0) {
        if (get_selected_objects_to_command(&list, &selectedCount, 4, 4,
                                            -1, -1)) {
            this->master_objects[0x76]->play_command_sound();
            static_cast<TRIBE_Command*>(this->world->commands)->command_build_wall(list, selectedCount, type,
                                                       p2, p3, p4, p5);
            free(list);
            return 1;
        }
    }
    return 0;
}


unsigned char TRIBE_Player::command_building_make_tech(short arg) {
    RGE_Static_Object* object = this->selected_obj;
    if (object && object->master_obj->master_type == 'P') {
        TRIBE_Command* command =
            static_cast<TRIBE_Command*>(this->world->commands);
        command->command_research(object, arg);
        return 1;
    }
    return 0;
}


unsigned char TRIBE_Player::command_building_cancel() {
    RGE_Static_Object* selected_obj;

    selected_obj = this->selected_obj;
    if (selected_obj != 0) {
        if (selected_obj->owner == this) {
            if (selected_obj->master_obj->master_type == 'P' || selected_obj->master_obj->master_type == 'F') {
                if (selected_obj->master_obj->object_group != 1) {
                    static_cast<TRIBE_Command*>(this->world->commands)->command_cancel_build(selected_obj);
                    return 1;
                }
            }
        }
    }

    return 0;
}


unsigned char TRIBE_Player::command_delete_object(RGE_Static_Object* object) {
    unsigned char type;

    if ((object != 0) && (object->owner == this)) {
        type = object->master_obj->master_type;
        if ((type == 'P') || (type == 'F')) {
            static_cast<TRIBE_Command*>(this->world->commands)->command_cancel_build(object);
            return 1;
        }
    }
    return 0;
}


unsigned char TRIBE_Player::command_trade_attribute(long param) {
    RGE_Static_Object** list;
    short selectedCount[2];

    if (this->get_selected_objects_to_command(&list, selectedCount, 4, -1, -1, 5)) {
        (*list)->play_command_sound();
        static_cast<TRIBE_Command*>(this->world->commands)->command_trade_attribute(list, selectedCount[0], param);
        free(list);
        return 1;
    }

    return 0;
}


unsigned char TRIBE_Player::command_trade_attribute(int a, long b) {
    short player_id = this->id;
    TRIBE_Command* command =
        static_cast<TRIBE_Command*>(this->world->commands);
    command->command_trade_attribute(a, player_id, b);
    return 1;
}


unsigned char TRIBE_Player::command_attack_ground(float x, float y) {
    RGE_Static_Object** list;
    short selectedCount[2];

    if (this->get_selected_objects_to_command(&list, selectedCount, 4, -1, -1, 4)) {
        (*list)->play_command_sound();
        static_cast<TRIBE_Command*>(this->world->commands)->command_attack_ground(list, selectedCount[0], x, y);
        free(list);
        return 1;
    }

    return 0;
}


unsigned char TRIBE_Player::command_give_attribute(int first, int second, float third, float fourth) {
    if (second == -1 || third == 0.0f) {
        return 0;
    }
    static_cast<TRIBE_Command*>(this->world->commands)->command_give_attribute(this->id, first, second, third, fourth);
    return 1;
}


unsigned char TRIBE_Player::command_building_make_obj(short arg) {
    RGE_Static_Object* object = this->selected_obj;
    if (object && object->master_obj->master_type == 'P') {
        TRIBE_Command* command =
            static_cast<TRIBE_Command*>(this->world->commands);
        command->command_make(object, arg);
        return 1;
    }
    return 0;
}




unsigned char TRIBE_Player::command_make_repair(RGE_Static_Object* obj)
{
    short list_num;
    RGE_Static_Object** selected;
    if (obj == 0) return 0;
    if (obj->owner != this &&
        this->isAlly(obj->owner == 0 ? -1 : obj->owner->id) == 0)
        return 0;
    if (obj->master_obj->master_type != 'P' &&
        (obj->master_obj->object_group != 2 &&
         obj->master_obj->object_group != 0x14 &&
         obj->master_obj->object_group != 0x15 &&
         obj->master_obj->object_group != 0x16))
        return 0;
    if (static_cast<float>(obj->master_obj->hp) > obj->hp || obj->object_state > 2)
        return 0;
    if (!this->get_selected_objects_to_command(&selected, &list_num, 4, 4, -1, -1))
        return 0;
    RGE_Master_Static_Object* repair_master =
        selected[0]->get_command_master(obj, 0.0f, 0.0f, 0.0f);
    if (repair_master != 0) repair_master->play_command_sound();
    static_cast<TRIBE_Command*>(this->world->commands)->command_repair(
        selected, list_num, obj);
    free(selected);
    return 1;
}

unsigned char TRIBE_Player::command_make_unload(float first, float second) {
    RGE_Static_Object** list;
    short list_num;
    short selectedCount[2];

    if (get_selected_objects_to_command(&list, selectedCount, 4, -1, -1, 7)) {
        list[0]->play_command_sound();
        static_cast<TRIBE_Command*>(this->world->commands)->command_unload(list, selectedCount[0], first, second);
        free(list);
        return 1;
    }
    return 0;
}


unsigned char TRIBE_Player::check_obj_cost(short obj_id, short* out, float factor,
                                             int skip_farm)
{
    float population = this->attributes[3];
    if (out != 0) *out = -1;
    RGE_Master_Static_Object* object = this->master_objects[obj_id];
    TRIBE_Master_Combat_Object* combat = static_cast<TRIBE_Master_Combat_Object*>(object);
    if (object->master_type < 0x46) return 0;
    unsigned char population_available =
        this->attributes[29] >= 1.0f;
    if (!population_available) population = 0.0f;
    for (int i = 0; i < 3; ++i) {
        int type = combat->build_inventory[i].type;
        if (type < 0) continue;
        float amount = combat->build_inventory[i].amount * factor;
        if (type == 4 && skip_farm == 0 &&
            this->attributes[11] >= this->attributes[32]) {
            if (out != 0) *out = 0x20;
            return 0;
        }
        if (population_available && type == 3) {
            population -= amount;
            if (population < 0.0f) {
                if (out != 0) *out = 3;
                return 0;
            }
        }
        if (this->attributes[type] < amount &&
            (type != 4 || skip_farm == 0)) {
            if (combat->build_inventory[i].flag == 0 ||
                population + this->attributes[type] < amount) {
                if (out != 0) *out = static_cast<short>(type);
                return 0;
            }
            population -= amount - this->attributes[type];
        }
    }
    return 1;
}


unsigned char TRIBE_Player::pay_obj_cost(short obj_id, float factor, int skip_farm)
{
    if (check_obj_cost(obj_id, 0, factor, skip_farm)) {
        RGE_Master_Static_Object* object = this->master_objects[obj_id];
        TRIBE_Master_Combat_Object* combat = static_cast<TRIBE_Master_Combat_Object*>(object);
        for (int i = 0; i < 3; ++i) {
            int type = combat->build_inventory[i].type;
            if (type >= 0 && combat->build_inventory[i].flag != 0 &&
                (skip_farm == 0 || type != 4)) {
                float amount = combat->build_inventory[i].amount * factor;
                if (amount > this->attributes[type]) {
                    this->attributes[3] -= amount - this->attributes[type];
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


void TRIBE_Player::reimburse_obj_cost(short obj_idx)
{
    RGE_Master_Static_Object* object = this->master_objects[obj_idx];
    TRIBE_Master_Combat_Object* combat = static_cast<TRIBE_Master_Combat_Object*>(object);
    if (object->master_type < 0x46) return;
    for (int i = 0; i < 3; ++i) {
        Attribute_Cost* cost = &combat->build_inventory[i];
        int type = cost->type;
        unsigned char flag = cost->flag;
        if (type >= 0 && flag != 0)
            this->attributes[type] += cost->amount;
    }
}


unsigned char TRIBE_Player::check_tech_cost(short tech_id, short* cost)
{
    return this->tech_tree->check_tech_cost(tech_id, cost);
}


unsigned char TRIBE_Player::pay_tech_cost(short tech_id)
{
    return this->tech_tree->start_research(tech_id, 1, 0);
}


void TRIBE_Player::tech_abling(long tech_id, unsigned char enable)
{
    if (enable != 0) this->tech_tree->enable(static_cast<short>(tech_id));
    else this->tech_tree->disable(static_cast<short>(tech_id));
}


void TRIBE_Player::rev_tech(long first)
{
    switch (first) {
    case 0x19:
        this->tech_tree->do_tech(static_cast<short>(this->attributes[25]));
        return;

    case 0x17:
        this->tech_tree->disable(static_cast<short>(this->attributes[23]));
        this->tech_tree->rev_tech(static_cast<short>(this->attributes[25]));
        this->tech_tree->enable(static_cast<short>(this->attributes[23]));
        this->tech_tree->do_tech(static_cast<short>(this->attributes[23]));
        return;

    case 0x18:
        this->tech_tree->disable(static_cast<short>(this->attributes[23]));
        this->tech_tree->disable(static_cast<short>(this->attributes[24]));
        this->tech_tree->rev_tech(static_cast<short>(this->attributes[25]));
        this->tech_tree->enable(static_cast<short>(this->attributes[23]));
        this->tech_tree->rev_tech(static_cast<short>(this->attributes[23]));
        this->tech_tree->enable(static_cast<short>(this->attributes[24]));
        this->tech_tree->do_tech(static_cast<short>(this->attributes[24]));
        return;

    case 1:
        this->tech_tree->disable(static_cast<short>(this->attributes[23]));
        this->tech_tree->disable(static_cast<short>(this->attributes[24]));
        this->tech_tree->rev_tech(static_cast<short>(this->attributes[25]));
        this->tech_tree->enable(static_cast<short>(this->attributes[23]));
        this->tech_tree->rev_tech(static_cast<short>(this->attributes[23]));
        this->tech_tree->enable(static_cast<short>(this->attributes[24]));
        this->tech_tree->rev_tech(static_cast<short>(this->attributes[24]));
        return;

    default:
        return;
    }
}


void TRIBE_Player::add_population_entry() {
    if (this->attributes[11] < 0.0f) {
        this->history->add_history_entry(0, 0);
        return;
    }

    this->history->add_history_entry(0, static_cast<int>(this->attributes[11]));
}





void TRIBE_Player::random_start()
{
    uchar found_ally = 0;

    if (this->objects->list == 0) {
        float w1;
        float h;
        w1 = ((debug_rand(tplayerSourceName, 0x631) *
               (this->world->map->map_height - 0x1e)) / 0x7fff + 0xf)
              - -0.5f;
        h = ((debug_rand(tplayerSourceName, 0x632) *
              (this->world->map->map_width - 0x1e)) / 0x7fff + 0xf)
             - -0.5f;
        int tries = 1;
        while (tries < 5000) {
            if (this->master_objects[0x6d]->check_placement(
                    this, h - -0.5f, w1 - -0.5f,
                    0, 0, 1, 1, 1, 1, 1) == 0)
                break;
            w1 = ((debug_rand(tplayerSourceName, 0x631) *
                   (this->world->map->map_height - 0x1e)) / 0x7fff + 0xf)
                         - -0.5f;
            h = ((debug_rand(tplayerSourceName, 0x632) *
                  (this->world->map->map_width - 0x1e)) / 0x7fff + 0xf)
                - -0.5f;
            ++tries;
        }

        if (tries < 5000) {
            TRIBE_Building_Object* town_center_object =
                static_cast<TRIBE_Building_Object*>(this->master_objects[0x6d]->make_new_obj(
                    this, h, w1, 0));
            this->set_map_loc(static_cast<short>(h), static_cast<short>(w1));
            this->set_view_loc(h, w1);
            town_center_object->build(10000.0f);

            int count = 3;
            int x_delta;
            int y_delta;
            float x;
            float y;
            do {
                uchar bad = 1;
                do {
                    x_delta = (debug_rand(tplayerSourceName, 0x646) * 6) /
                              0x7fff - 3;
                    y_delta = (debug_rand(tplayerSourceName, 0x647) * 6) /
                              0x7fff - 3;
                    x = x_delta -
                        debug_rand(tplayerSourceName, 0x648) * -3.05185094e-05f + w1;
                    y = y_delta -
                        debug_rand(tplayerSourceName, 0x649) * -3.05185094e-05f + h;

                    if (x >= 0.0f && x < static_cast<float>(this->world->map->map_height) &&
                        y >= 0.0f && y < static_cast<float>(this->world->map->map_width) &&
                        this->master_objects[0x53]->check_placement(
                            this, y, x, 0, 0, 1, 1, 1, 1, 1) == 0) {
                        this->master_objects[0x53]->make_new_obj(this, y, x, 0);
                        bad = 0;
                    }
                } while (bad);
                --count;
            } while (count != 0);
        }
    } else {
        RGE_Static_Object* town_center_object =
            this->objects->find_by_master_id(0x6d, 0.0f, 0.0f, 0, 0, 0);
        if (town_center_object == 0) {
            town_center_object = this->objects->list->node;
        }
        this->set_map_loc(static_cast<short>(town_center_object->world_x),
                          static_cast<short>(town_center_object->world_y));
        this->set_view_loc(town_center_object->world_x,
                           town_center_object->world_y);
    }

    if (rge_base_game->multiplayerGame() || rge_base_game->randomGame()) {
        for (int i = 1; i < this->world->player_num; ++i) {
            if (this->isAlly(i) && i != this->id) {
                RGE_Static_Object* town_center_object =
                    this->objects->find_by_master_id(0x6d, 0.0f, 0.0f, 0, 0, 0);
                if (town_center_object == 0) {
                    town_center_object = this->objects->list->node;
                }
                if (town_center_object != 0) {
                    town_center_object->explore_terrain(this->world->players[i], 0, -1);
                    town_center_object->unexplore_terrain(this->world->players[i], 0, -1);
                }
                this->world->players[i]->make_new_object(
                    0x70, this->view_x, this->view_y, 0, 0);
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


void TRIBE_Player::objectCost(int object_id, int second, ResourceItem* item, int fourth) {
    short object = static_cast<short>(object_id);
    short inv1;
    short amount1;
    short amt1;
    short inv2;
    short amt2;
    short inv3;
    short amt3;

    this->obj_cost(object, 0, inv2, amount1, inv3, amt3, amt1, inv1, 1.0f);
    item->incrementValue(inv2, amount1);
    item->incrementValue(inv3, amt3);
    item->incrementValue(amt1, inv1);
}


int TRIBE_Player::objectCostByType(int input)
{
    short first;
    short inv_3;
    short inv_2;
    short inv_1;
    short selectedCount;
    short firstType;

    obj_cost(static_cast<short>(input), 0, firstType, first, selectedCount, inv_2, inv_1, inv_3, 1.0f);
    return first + inv_3 + inv_2;
}


void TRIBE_Player::researchCost(int tech_id, int unused, ResourceItem* resources, int unused2) {
    short technology = static_cast<short>(tech_id);
    short inv_amt_2;
    short amount_2;
    short inv_2;
    short inv_amt_3;
    short inv_3;
    short inv_1;
    short inv_amt_1;

    this->tech_tree->tech_cost(technology, &inv_2, &amount_2, &inv_3, &inv_amt_3, &inv_1, &inv_amt_1);
    resources->incrementValue(inv_2, amount_2);
    resources->incrementValue(inv_3, inv_amt_3);
    resources->incrementValue(inv_1, inv_amt_1);
}


int TRIBE_Player::objectAvailable(int obj_id) {
    RGE_Master_Static_Object** objects =
        this->master_objects;
    RGE_Master_Static_Object* object = objects[obj_id];
    if ((object != 0 && object->available) || obj_id == 0x6D)
        return 1;
    return 0;
}


int TRIBE_Player::researchAvailable(int index) {
    return this->tech_tree->tech_player_tree[index].state == 1;
}


int TRIBE_Player::researchEverAvailable(int tech_id) {
    short state;

    TRIBE_Player_Tech* tech =
        this->tech_tree;
    state = tech->get_tech_state(static_cast<short>(tech_id));
    if (state != 3 && state != -1)
        return 1;
    return 0;
}


unsigned char TRIBE_Player::researchState(int tech_id) {
    TRIBE_Player_Tech* tech =
        this->tech_tree;
    return static_cast<unsigned char>(tech->get_tech_state(static_cast<short>(tech_id)));
}


void TRIBE_Player::changeToHumanPlayer() {}


void TRIBE_Player::changeToComputerPlayer() {}



char* TRIBE_Player::aiStatus(int first)
{
    if (this->playerAI == 0) {
        if (this->world->currentUpdateComputerPlayer != -1) {
            RGE_Player* otherPlayer = this->world->players[this->world->currentUpdateComputerPlayer];
            if (otherPlayer != 0) {
                TribeMainDecisionAIModule* ai = static_cast<TRIBE_Player*>(otherPlayer)->playerAI;
                int last = ai->tacticalAI.lastUpdateAreaTimeValue;
                int avg = ai->tacticalAI.averageUpdateAreaTimeValue;
                sprintf(this->aiStatusInformationValue,
                    "ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s.",
                    static_cast<TRIBE_World*>(this->world)->controllingComputerPlayer,
                    this->world->currentUpdateComputerPlayer,
                    avg,
                    last,
                    ai->tacticalAI.updateAreaName());
                return this->aiStatusInformationValue;
            }
        }
        return "Invalid currentUpdateComputerPlayer...";
    }
    if (first == 1) {
        sprintf(this->aiStatusInformationValue,
            "Build List:%s, City Plan:%s, BuildAI(C=%s, N=%s, L=%s, %d/%d).",
            this->playerAI->buildAI.buildListName(),
            this->playerAI->constructionAI.constructionPlanName(),
            this->playerAI->buildAI.currentBuildItemRequested(),
            this->playerAI->buildAI.nextBuildItemRequested(),
            this->playerAI->buildAI.lastBuildItemRequested(),
            this->playerAI->buildAI.numberItemsIntoBuildList(),
            this->playerAI->buildAI.buildListLength());
        return this->aiStatusInformationValue;
    }
    if (first == 2) {
        sprintf(this->aiStatusInformationValue2,
            "NeedRes: %s=%d, %s=%d, %s=%d, %s=%d, ResDiff: %s=%d, %s=%d, %s=%d, %s=%d.",
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)), this->playerAI->tacticalAI.neededResourceAmount(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)), this->playerAI->tacticalAI.neededResourceAmount(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)), this->playerAI->tacticalAI.neededResourceAmount(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)), this->playerAI->tacticalAI.neededResourceAmount(3),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)), this->playerAI->tacticalAI.resourceDifference(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)), this->playerAI->tacticalAI.resourceDifference(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)), this->playerAI->tacticalAI.resourceDifference(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)), this->playerAI->tacticalAI.resourceDifference(3));
        return this->aiStatusInformationValue2;
    }
    if (first == 3) {
        sprintf(this->aiStatusInformationValue3,
            "Gat(Act/Des): %s=(%d/%d), %s=(%d/%d), %s=(%d/%d), %s=(%d/%d).  #Civs=%d, #Sol=%d, #Boats=%d.",
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)), this->playerAI->tacticalAI.actualGathererCount(0), this->playerAI->tacticalAI.desiredGathererCount(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)), this->playerAI->tacticalAI.actualGathererCount(1), this->playerAI->tacticalAI.desiredGathererCount(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)), this->playerAI->tacticalAI.actualGathererCount(2), this->playerAI->tacticalAI.desiredGathererCount(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)), this->playerAI->tacticalAI.actualGathererCount(3), this->playerAI->tacticalAI.desiredGathererCount(3),
            this->playerAI->tacticalAI.numberCivilians(), this->playerAI->tacticalAI.numberSoldiers(), this->playerAI->tacticalAI.numberBoats());
        return this->aiStatusInformationValue3;
    }
    if (first == 4) {
        sprintf(this->aiStatusInformationValue4,
            "Pers (Spec/BL): Food=(%d/%d), Wood=(%d/%d), Gold=(%d/%d), Stone=(%d/%d).",
            this->playerAI->tacticalAI.strategicNumber(0x75),
            this->playerAI->tacticalAI.strategicNumber(0x9C),
            this->playerAI->tacticalAI.strategicNumber(0x78),
            this->playerAI->tacticalAI.strategicNumber(0x9D),
            this->playerAI->tacticalAI.strategicNumber(0x76),
            this->playerAI->tacticalAI.strategicNumber(0x9F),
            this->playerAI->tacticalAI.strategicNumber(0x77),
            this->playerAI->tacticalAI.strategicNumber(0x9E));
        return this->aiStatusInformationValue4;
    }
    if (first == 5) {
        sprintf(this->aiStatusInformationValue5,
            "Dip: P1(%d/%d/%d), P2(%d/%d/%d), P3(%d/%d/%d), P4(%d/%d/%d), P5(%d/%d/%d), P6(%d/%d/%d), P7(%d/%d/%d), P8(%d/%d/%d).",
            this->playerAI->diplomacyAI.stance(1, 0), this->playerAI->diplomacyAI.stance(1, 1), this->playerAI->diplomacyAI.stance(1, 2),
            this->playerAI->diplomacyAI.stance(2, 0), this->playerAI->diplomacyAI.stance(2, 1), this->playerAI->diplomacyAI.stance(2, 2),
            this->playerAI->diplomacyAI.stance(3, 0), this->playerAI->diplomacyAI.stance(3, 1), this->playerAI->diplomacyAI.stance(3, 2),
            this->playerAI->diplomacyAI.stance(4, 0), this->playerAI->diplomacyAI.stance(4, 1), this->playerAI->diplomacyAI.stance(4, 2),
            this->playerAI->diplomacyAI.stance(5, 0), this->playerAI->diplomacyAI.stance(5, 1), this->playerAI->diplomacyAI.stance(5, 2),
            this->playerAI->diplomacyAI.stance(6, 0), this->playerAI->diplomacyAI.stance(6, 1), this->playerAI->diplomacyAI.stance(6, 2),
            this->playerAI->diplomacyAI.stance(7, 0), this->playerAI->diplomacyAI.stance(7, 1), this->playerAI->diplomacyAI.stance(7, 2),
            this->playerAI->diplomacyAI.stance(8, 0), this->playerAI->diplomacyAI.stance(8, 1), this->playerAI->diplomacyAI.stance(8, 2));
        return this->aiStatusInformationValue5;
    }
    if (first == 6) {
        TribeMainDecisionAIModule* ai =
            static_cast<TRIBE_Player*>(this->world->players[
                this->world->currentUpdateComputerPlayer])->playerAI;
        int last = ai->tacticalAI.lastUpdateAreaTimeValue;
        int avg = ai->tacticalAI.averageUpdateAreaTimeValue;
        int attackEnabled = this->playerAI->tacticalAI.attackEnabledValue;
        sprintf(this->aiStatusInformationValue6,
            "Per: %s, AttEnab=%d, AttDly=%d Min, ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s.",
            this->playerAI->strategyAI.ruleSetName(),
            attackEnabled,
            this->playerAI->tacticalAI.strategicNumber(0x68) / 60,
            static_cast<TRIBE_World*>(this->world)->controllingComputerPlayer,
            this->world->currentUpdateComputerPlayer,
            avg,
            last,
            ai->tacticalAI.updateAreaName());
        return this->aiStatusInformationValue6;
    }
    return "Invalid status line number.";
}


void TRIBE_Player::kickAI(int param) {
    TribeMainDecisionAIModule* ai =
        this->playerAI;
    if (ai)
        ai->kick(param);
}


int TRIBE_Player::strategicNumber(int index) {
    TribeMainDecisionAIModule* ai =
        this->playerAI;
    if (ai) {
        return ai->tacticalAI.strategicNumber(index);
    }
    return -1;
}



void __cdecl TRIBE_Player::logMessage(char* format, ...) {
    char textOut[1024];

    if (this->playerAI != 0) {
        va_list args;
        va_start(args, format);
        vsprintf(textOut, format, args);
        va_end(args);
        this->playerAI->logCommonHistory(textOut);
    }
}


int TRIBE_Player::sendAICommand(int a, int b, int c, int d, int e) {
    TribeMainDecisionAIModule* ai =
        this->playerAI;
    if (!ai) return 0;
    return ai->processAICommand(a, b, c, d, e);
}


RGE_Object_Node* TRIBE_Player::addObject(RGE_Static_Object* obj, int param2, int param3)
{
    RGE_Object_Node* node = RGE_Player::addObject(obj, param2, param3);
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
    if (obj->object_state == 2) {
        flag = 0;
    }
    this->playerAI->buildAI.addItem(obj, flag);
    return node;
}


void TRIBE_Player::removeObject(RGE_Static_Object* obj, int second, int third, RGE_Object_Node* fourth) {
    RGE_Player::removeObject(obj, second, third, fourth);

    if (this->playerAI) {
        short grp = obj->master_obj->object_group;
        if (grp != 0x0B && obj->id >= 0) {
            this->playerAI->removeObject(obj->id);
        }
    }
}




void TRIBE_Player::buildObject(int first, int second, float third, float fourth, int fifth)
{
    int* objectId = static_cast<int*>(calloc(1, 4));
    *objectId = first;
    static_cast<TRIBE_Command*>(this->world->commands)->command_build(this->id, objectId, 1, second, third, fourth, fifth);
    free(objectId);
}


void TRIBE_Player::cancelBuild(int first, int second, int third, float fourth, float fifth, int sixth, int seventh) {
    if (this->playerAI != 0) {
        this->playerAI->buildAI.cancelBuildItem(first, second, third, fourth, fifth, sixth, seventh);
    }
}


void TRIBE_Player::registerBuild(RGE_Static_Object* object, int value) {
    TribeMainDecisionAIModule* ai =
        this->playerAI;
    if (!ai) return;
    ai->buildAI.addBuiltItem(object, value);
}


void TRIBE_Player::trainUnit(int a, int b, int c) {
    short player_id = this->id;
    TRIBE_Command* command =
        static_cast<TRIBE_Command*>(this->world->commands);
    command->command_make(player_id, b, a, c);
}


void TRIBE_Player::cancelTrain(int a, int b, int c, int d) {
    TribeMainDecisionAIModule* ai =
        this->playerAI;
    if (!ai) {
        return;
    }
    ai->buildAI.cancelTrainUnit(a, b, c, d);
}


void TRIBE_Player::registerTrain(int a, int b, int c, int d) {
    TribeMainDecisionAIModule* ai =
        this->playerAI;
    if (!ai) {
        return;
    }
    ai->buildAI.addTrainedUnit(a, b, c, d);
}


void TRIBE_Player::research(int a, int b, int c) {
    short player_id = this->id;
    TRIBE_Command* command =
        static_cast<TRIBE_Command*>(this->world->commands);
    command->command_research(player_id, b, a, c);
}


void TRIBE_Player::cancelResearch(int a, int b, int c, int d) {
    TribeMainDecisionAIModule* ai =
        this->playerAI;
    if (!ai) {
        return;
    }
    ai->buildAI.cancelResearch(a, b, c, d);
}


void TRIBE_Player::registerResearch(int a, int b, int c) {
    TribeMainDecisionAIModule* ai =
        this->playerAI;
    if (!ai) return;
    ai->buildAI.addResearch(a, b, c);
}



void TRIBE_Player::taskTrader(int first, int second, int third, float fourth, float fifth) {
    int* task = static_cast<int*>(calloc(1, 4));
    *task = first;
    static_cast<TRIBE_Command*>(this->world->commands)->command_work(this->id, task, 1, second, third, fourth, fifth);
    free(task);
}



void TRIBE_Player::taskResourceGatherer(int first, int second, int third, float fourth, float fifth) {
    int* task = static_cast<int*>(calloc(1, 4));
    *task = first;
    static_cast<TRIBE_Command*>(this->world->commands)->command_work(this->id, task, 1, second, third, fourth, fifth);
    free(task);
}


void TRIBE_Player::setDiplomaticStance(int target_id, int stance) {
    static_cast<TRIBE_Command*>(this->world->commands)->command_relation(this->id, static_cast<short>(target_id), static_cast<short>(stance));
}


void TRIBE_Player::loadAIInformation(char* aiFile, char* ruleFile, char* personalityFile, int buildId, int unused)
{
    char noneString[256];
    char randomString[256];
    char ruleSetName[256];
    char buildListName[256];

    int saveRand;
    int save_debug_random_on;
    saveRand = debug_rand(tplayerSourceName, 0x863);
    save_debug_random_on = debug_random_on;
    global_save_debug_random_on2 = save_debug_random_on;
    debug_random_on = 0;

    if (this->playerAI) {
        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapType()) {
        case 0: this->playerAI->logCommonHistory(tplayerMapMessages[0]); break;
        case 1: this->playerAI->logCommonHistory(tplayerMapMessages[1]); break;
        case 2: this->playerAI->logCommonHistory(tplayerMapMessages[2]); break;
        case 3: this->playerAI->logCommonHistory(tplayerMapMessages[3]); break;
        case 4: this->playerAI->logCommonHistory(tplayerMapMessages[4]); break;
        default: this->playerAI->logCommonHistory(tplayerMapMessages[5]); break;
        }
        rge_base_game->get_string(0x2775, noneString, 0x100);
        rge_base_game->get_string(0x277B, randomString, 0x100);

        strcpy(buildListName, s_592A40);
        strcpy(ruleSetName, s_592A40);

        if (aiFile) {
            if (strcmp(aiFile, randomString) == 0) {
                do {
                    this->intelligentBuildListAndRulesSelection(buildListName, ruleSetName,
                        static_cast<TRIBE_Game*>(rge_base_game)->mapType(), static_cast<TRIBE_Game*>(rge_base_game)->victoryType(), static_cast<TRIBE_Game*>(rge_base_game)->mapSize());
                    this->playerAI->logCommonHistory(tplayerBuildMessage, buildListName);
                } while (this->playerAI->buildAI.loadBuildList(buildListName, this) == 0);
            } else {
                this->playerAI->logCommonHistory(tplayerFileMessage, aiFile);
                this->playerAI->buildAI.loadBuildList(aiFile, this);
            }
        } else {
            do {
                this->intelligentBuildListAndRulesSelection(buildListName, ruleSetName,
                    static_cast<TRIBE_Game*>(rge_base_game)->mapType(), static_cast<TRIBE_Game*>(rge_base_game)->victoryType(), static_cast<TRIBE_Game*>(rge_base_game)->mapSize());
                this->playerAI->logCommonHistory(tplayerBuildMessage, buildListName);
            } while (this->playerAI->buildAI.loadBuildList(buildListName, this) == 0);
        }

        if (ruleFile != 0 && strcmp(ruleFile, randomString) != 0) {
            this->playerAI->logCommonHistory(tplayerFileMessage, ruleFile);
            this->playerAI->constructionAI.loadConstructionPlan(
                ruleFile, this->world->map->map_width,
                this->world->map->map_height, 0, 0, 0);
        } else {
            this->playerAI->logCommonHistory(tplayerDefaultMessage);
            this->playerAI->constructionAI.loadConstructionPlan(
                tplayerDefaultPlan, this->world->map->map_width,
                this->world->map->map_height, 0, 0, 0);
        }

        if (personalityFile && strcmp(personalityFile, randomString) != 0) {
            this->playerAI->logCommonHistory(tplayerFileMessage, personalityFile);
            this->playerAI->strategyAI.loadRules(personalityFile);
        } else if (strcmp(ruleSetName, tplayerRandomName) != 0) {
            this->playerAI->logCommonHistory(tplayerRulesMessage, ruleSetName);
            this->playerAI->strategyAI.loadRules(ruleSetName);
        } else {
            this->playerAI->logCommonHistory(tplayerDefaultMessage);
        }

        int r = rge_base_game->difficulty();
        this->playerAI->logCommonHistory(tplayerDifficultyMessage, r);
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

        this->playerAI->emotionalAI.setOverallState(buildId);
        char* learn = static_cast<T_Scenario*>(this->world->scenario)->hints;
        if (learn && strlen(learn) != 0) this->playerAI->informationAI.loadLearnInfo(learn);
    }

    debug_random_on = save_debug_random_on;
    debug_srand(tplayerSourceName, 0x8FD, saveRand);
}



void TRIBE_Player::notify(int first, int second, int third,
                          long fourth, long fifth, long sixth)
{
    RGE_Static_Object* object;
    switch (third) {
    case 0x201:
        if (this->update_count == 0) {
            this->update_count = 20;
            object = this->world->object(fourth);
            if (object != 0) {
                int seed = debug_rand(tplayerSourceName, 0x920);
                int saved = debug_random_on;
                debug_random_on = 0;
                if (this->world->curr_player == this->id) {
                    RGE_Sound* sound = this->world->sounds[static_cast<short>(this->attributes[26])];
                    if (sound != 0) sound->play(1);
                    static_cast<TRIBE_Game*>(rge_base_game)->add_notification_loc(
                        static_cast<long>(object->world_x), static_cast<long>(object->world_y));
                }
                debug_random_on = saved;
                debug_srand(tplayerSourceName, 0x931, seed);
            }
        }
        break;
    case 0x20C:
        if (fourth == 0x267)
            static_cast<TRIBE_Game*>(rge_base_game)->notification(3, this->id, 0, 0, 0);
        break;
    case 0x207:
        static_cast<TRIBE_Game*>(rge_base_game)->notification(1, this->id, 0, 0, 0);
        break;
    case 0x206:
        static_cast<TRIBE_Game*>(rge_base_game)->notification(2, this->id, 0, 0, 0);
        break;
    }
    int seed = debug_rand(tplayerSourceName, 0x949);
    int saved = debug_random_on;
    debug_random_on = 0;
    if (this->playerAI != 0)
        this->notifyAI(first, second, third, fourth, fifth, sixth);
    debug_random_on = saved;
    debug_srand(tplayerSourceName, 0x956, seed);
}




void TRIBE_Player::notifyAI(int first, int second, int third, long fourth, long fifth, long sixth)
{
    RGE_Static_Object* obj = this->world->object(first);
    float target_x;
    float target_y;
    if (third != 0x20a && third != 0x72 && third != 0x74) {
        if (obj == 0) return;
        if (obj->unitAI() == 0) return;
    }

    switch (third) {
    case 0x1f9:
        if (fourth != 0x25d) return;
        {
            TacticalAIGroup* group = this->playerAI->tacticalAI.groupUnitIsIn(first);
            if (group == 0) return;
            if (group->type() != 0x6b) return;
            this->playerAI->tacticalAI.removeGroup(group->id());
            return;
        }
    case 0x202:
        switch (fourth) {
        case 0x25d:
        case 0x26f:
            if (this->playerAI->informationAI.fullyExploredZone(first) != 0 &&
                this->playerAI->informationAI.closestUnexploredTile(first, obj->world_x, obj->world_y, &target_x, &target_y) == 1) {
                this->playerAI->tacticalAI.taskExplorer(first, target_x, target_y);
                return;
            }
            this->playerAI->tacticalAI.detask(first);
            return;
        }
        break;
    case 0x209:
        obj = this->world->object(fourth);
        if (obj != 0) {
            this->playerAI->diplomacyAI.changeStance(obj->owner->id, 0, 10);
            return;
        }
        break;
    case 0x20a:
        this->playerAI->tributeNotify(first, fourth, fifth);
        return;
    case 0x72:
    case 0x74:
    case 0x201:
        this->playerAI->tacticalAI.notify(first, second, third, fourth, fifth, sixth);
        return;
    case 0x20d:
        this->playerAI->informationAI.addImportantObject(fourth);
        break;
    }
}


int TRIBE_Player::intelligentCivSelection(int p0, int p1, int p2) { return 0; }




void TRIBE_Player::intelligentBuildListAndRulesSelection(char* buildListName, char* ruleSetName,
                                                         int mapType, int victoryType, int mapSize)
{
    int difficultyLevel;
    int gameDifficulty;
    int weights[125];
    int mostBuiltUnit;
    char tempString[256];

    if (this->playerAI == 0) {
        return;
    }

    gameDifficulty = rge_base_game->difficulty();
    memset(weights, 0, sizeof(weights));

    switch (this->culture) {
    case 1:  this->setupEgyptian(weights, mapType, victoryType, mapSize); break;
    case 2:  this->setupGreek(weights, mapType, victoryType, mapSize); break;
    case 3:  this->setupBabylonian(weights, mapType, victoryType, mapSize); break;
    case 4:  this->setupAssyrian(weights, mapType, victoryType, mapSize); break;
    case 5:  this->setupMinoan(weights, mapType, victoryType, mapSize); break;
    case 6:  this->setupHittite(weights, mapType, victoryType, mapSize); break;
    case 7:  this->setupPhoenician(weights, mapType, victoryType, mapSize); break;
    case 8:  this->setupSumerian(weights, mapType, victoryType, mapSize); break;
    case 9:  this->setupPersian(weights, mapType, victoryType, mapSize); break;
    case 10: this->setupShang(weights, mapType, victoryType, mapSize); break;
    case 11: this->setupYamato(weights, mapType, victoryType, mapSize); break;
    case 12: this->setupChoson(weights, mapType, victoryType, mapSize); break;
    case 13: this->setupRoman(weights, mapType, victoryType, mapSize); break;
    case 14: this->setupCarthaginian(weights, mapType, victoryType, mapSize); break;
    case 15: this->setupPalmyran(weights, mapType, victoryType, mapSize); break;
    case 16: this->setupMacedonian(weights, mapType, victoryType, mapSize); break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 0) {
        int civ = this->culture - 1;
        if (civ == 3 || civ == 0 || civ == 1 || civ == 4 || civ == 8 ||
            civ == 6 || civ == 7 || civ == 10) {
            int aggressiveSelections = tplayer_globals::aggressiveBuildListCount;
            int selectedBuildLists = tplayer_globals::selectedBuildListCount;
            if (mapType == 0) {
                if (selectedBuildLists > 0) {
                    if (aggressiveSelections == 0) {
                        weights[(0x0E) - 1] += 300;
                        weights[(0x0F) - 1] += 300;
                    } else {
                        weights[(0x0E) - 1] += 100;
                        weights[(0x0F) - 1] += 100;
                    }
                } else {
                    weights[(0x0E) - 1] = 0;
                    weights[(0x0F) - 1] = 0;
                }
            }
            if (mapType == 1) {
                if (selectedBuildLists > 0) {
                    if (aggressiveSelections == 0) {
                        weights[(0x0E) - 1] += 250;
                        weights[(0x0F) - 1] += 250;
                    } else {
                        weights[(0x0E) - 1] += 75;
                        weights[(0x0F) - 1] += 75;
                    }
                } else {
                    weights[(0x0E) - 1] = 0;
                    weights[(0x0F) - 1] = 0;
                }
            }
            if (mapType == 2 || mapType == 6 || mapType == 8) {
                if (selectedBuildLists > 0) {
                    if (aggressiveSelections == 0) {
                        weights[(0x0E) - 1] += 200;
                        weights[(0x0F) - 1] += 200;
                    } else {
                        weights[(0x0E) - 1] += 50;
                        weights[(0x0F) - 1] += 50;
                    }
                } else {
                    weights[(0x0E) - 1] = 0;
                    weights[(0x0F) - 1] = 0;
                }
            }
        }
    }

    this->playerAI->strategyAI.setRule(0xC9, 1);

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 0) {
        difficultyLevel = -1;
        mostBuiltUnit = -1;
        this->playerAI->informationAI.loadUnitHistory();
        this->playerAI->informationAI.unitsThatAreMostBuilt(difficultyLevel, mostBuiltUnit);
        switch (difficultyLevel) {
        case 0:
            weights[(7) - 1] += 25;
            weights[(8) - 1] += 25;
            break;
        case 1:
            weights[(7) - 1] += 30;
            weights[(8) - 1] += 30;
            break;
        case 2:
            weights[(0x12) - 1] += 20;
            weights[(0x13) - 1] += 20;
            weights[(4) - 1] += 40;
            weights[(5) - 1] += 40;
            break;
        case 3:
            weights[(1) - 1] += 40;
            weights[(2) - 1] += 20;
            weights[(0x14) - 1] += 20;
            weights[(0x15) - 1] += 20;
            weights[(0x12) - 1] -= 60;
            weights[(0x13) - 1] -= 60;
            break;
        case 4:
            weights[(7) - 1] += 15;
            weights[(8) - 1] += 15;
            weights[(0x14) - 1] += 20;
            weights[(0x15) - 1] += 20;
            break;
        case 5:
            weights[(7) - 1] += 15;
            weights[(8) - 1] += 15;
            weights[(1) - 1] += 10;
            weights[(2) - 1] += 10;
            break;
        case 6:
            weights[(7) - 1] += 15;
            weights[(8) - 1] += 15;
            break;
        case 7:
        case 10:
            weights[(0x14) - 1] -= 60;
            weights[(0x15) - 1] -= 60;
            break;
        case 8:
            weights[(0x14) - 1] += 40;
            weights[(0x15) - 1] += 40;
            if (tplayer_globals::selectedBuildListCount > 0) {
                weights[(0x0E) - 1] += 50;
                weights[(0x0F) - 1] += 50;
            }
            break;
        case 9:
            weights[(0x14) - 1] += 100;
            weights[(0x15) - 1] += 100;
            break;
        }
    }

    difficultyLevel = 0;
    do {
        switch (difficultyLevel) {
        case 0:
            if (0 < (weights[(0x14) - 1])) (weights[(0x14) - 1]) = (weights[(0x14) - 1]) / 3;
            if (0 < (weights[(0x15) - 1])) (weights[(0x15) - 1]) = (weights[(0x15) - 1]) / 3;
            if (0 < (weights[(0x16) - 1])) (weights[(0x16) - 1]) = (weights[(0x16) - 1]) / 3;
            break;
        case 1:
            if (0 < (weights[(7) - 1])) (weights[(7) - 1]) = (weights[(7) - 1]) / 3;
            if (0 < (weights[(8) - 1])) (weights[(8) - 1]) = (weights[(8) - 1]) / 3;
            if (0 < (weights[(9) - 1])) (weights[(9) - 1]) = (weights[(9) - 1]) / 3;
            if (0 < (weights[(0x3C) - 1])) (weights[(0x3C) - 1]) = (weights[(0x3C) - 1]) / 3;
            if (0 < (weights[(0x3B) - 1])) (weights[(0x3B) - 1]) = (weights[(0x3B) - 1]) / 3;
            if (0 < (weights[(0x37) - 1])) (weights[(0x37) - 1]) = (weights[(0x37) - 1]) / 3;
            if (0 < (weights[(0x38) - 1])) (weights[(0x38) - 1]) = (weights[(0x38) - 1]) / 3;
            if (0 < (weights[(0x69) - 1])) (weights[(0x69) - 1]) = (weights[(0x69) - 1]) / 3;
            break;
        case 2:
            if (0 < (weights[(0x11) - 1])) (weights[(0x11) - 1]) = (weights[(0x11) - 1]) / 3;
            if (0 < (weights[(0x32) - 1])) (weights[(0x32) - 1]) = (weights[(0x32) - 1]) / 3;
            if (0 < (weights[(0x6D) - 1])) (weights[(0x6D) - 1]) = (weights[(0x6D) - 1]) / 3;
            break;
        case 3:
            if (0 < (weights[(0x2F) - 1])) (weights[(0x2F) - 1]) = (weights[(0x2F) - 1]) / 3;
            if (0 < (weights[(0x36) - 1])) (weights[(0x36) - 1]) = (weights[(0x36) - 1]) / 3;
            if (0 < (weights[(0x12) - 1])) (weights[(0x12) - 1]) = (weights[(0x12) - 1]) / 3;
            if (0 < (weights[(0x13) - 1])) (weights[(0x13) - 1]) = (weights[(0x13) - 1]) / 3;
            if (0 < (weights[(100) - 1])) (weights[(100) - 1]) = (weights[(100) - 1]) / 3;
            if (0 < (weights[(0x67) - 1])) (weights[(0x67) - 1]) = (weights[(0x67) - 1]) / 3;
            if (0 < (weights[(0x6E) - 1])) (weights[(0x6E) - 1]) = (weights[(0x6E) - 1]) / 3;
            if (0 < (weights[(0x13) - 1])) (weights[(0x13) - 1]) = (weights[(0x13) - 1]) / 3;
            break;
        case 4:
            if (0 < (weights[(4) - 1])) (weights[(4) - 1]) = (weights[(4) - 1]) / 3;
            if (0 < (weights[(5) - 1])) (weights[(5) - 1]) = (weights[(5) - 1]) / 3;
            if (0 < (weights[(6) - 1])) (weights[(6) - 1]) = (weights[(6) - 1]) / 3;
            if (0 < (weights[(10) - 1])) (weights[(10) - 1]) = (weights[(10) - 1]) / 3;
            if (0 < (weights[(0x0B) - 1])) (weights[(0x0B) - 1]) = (weights[(0x0B) - 1]) / 3;
            if (0 < (weights[(0x0C) - 1])) (weights[(0x0C) - 1]) = (weights[(0x0C) - 1]) / 3;
            if (0 < (weights[(0x0D) - 1])) (weights[(0x0D) - 1]) = (weights[(0x0D) - 1]) / 3;
            if (0 < (weights[(0x2B) - 1])) (weights[(0x2B) - 1]) = (weights[(0x2B) - 1]) / 3;
            if (0 < (weights[(0x2D) - 1])) (weights[(0x2D) - 1]) = (weights[(0x2D) - 1]) / 3;
            if (0 < (weights[(0x2E) - 1])) (weights[(0x2E) - 1]) = (weights[(0x2E) - 1]) / 3;
            if (0 < (weights[(0x30) - 1])) (weights[(0x30) - 1]) = (weights[(0x30) - 1]) / 3;
            if (0 < (weights[(0x31) - 1])) (weights[(0x31) - 1]) = (weights[(0x31) - 1]) / 3;
            if (0 < (weights[(0x39) - 1])) (weights[(0x39) - 1]) = (weights[(0x39) - 1]) / 3;
            if (0 < (weights[(0x4B) - 1])) (weights[(0x4B) - 1]) = (weights[(0x4B) - 1]) / 3;
            if (0 < (weights[(99) - 1])) (weights[(99) - 1]) = (weights[(99) - 1]) / 3;
            if (0 < (weights[(0x68) - 1])) (weights[(0x68) - 1]) = (weights[(0x68) - 1]) / 3;
            if (0 < (weights[(0x71) - 1])) (weights[(0x71) - 1]) = (weights[(0x71) - 1]) / 3;
            if (0 < (weights[(0x72) - 1])) (weights[(0x72) - 1]) = (weights[(0x72) - 1]) / 3;
            break;
        case 5:
            if (0 < (weights[(0x2A) - 1])) (weights[(0x2A) - 1]) = (weights[(0x2A) - 1]) / 3;
            if (0 < (weights[(1) - 1])) (weights[(1) - 1]) = (weights[(1) - 1]) / 3;
            if (0 < (weights[(2) - 1])) (weights[(2) - 1]) = (weights[(2) - 1]) / 3;
            if (0 < (weights[(3) - 1])) (weights[(3) - 1]) = (weights[(3) - 1]) / 3;
            if (0 < (weights[(0x2A) - 1])) (weights[(0x2A) - 1]) = (weights[(0x2A) - 1]) / 3;
            if (0 < (weights[(0x33) - 1])) (weights[(0x33) - 1]) = (weights[(0x33) - 1]) / 3;
            if (0 < (weights[(0x34) - 1])) (weights[(0x34) - 1]) = (weights[(0x34) - 1]) / 3;
            if (0 < (weights[(0x49) - 1])) (weights[(0x49) - 1]) = (weights[(0x49) - 1]) / 3;
            if (0 < (weights[(0x4A) - 1])) (weights[(0x4A) - 1]) = (weights[(0x4A) - 1]) / 3;
            if (0 < (weights[(0x33) - 1])) (weights[(0x33) - 1]) = (weights[(0x33) - 1]) / 3;
            if (0 < (weights[(0x34) - 1])) (weights[(0x34) - 1]) = (weights[(0x34) - 1]) / 3;
            if (0 < (weights[(0x51) - 1])) (weights[(0x51) - 1]) = (weights[(0x51) - 1]) / 3;
            if (0 < (weights[(0x52) - 1])) (weights[(0x52) - 1]) = (weights[(0x52) - 1]) / 3;
            if (0 < (weights[(0x53) - 1])) (weights[(0x53) - 1]) = (weights[(0x53) - 1]) / 3;
            if (0 < (weights[(0x6C) - 1])) (weights[(0x6C) - 1]) = (weights[(0x6C) - 1]) / 3;
            break;
        case 6:
            if (0 < (weights[(0x29) - 1])) (weights[(0x29) - 1]) = (weights[(0x29) - 1]) / 3;
            if (0 < (weights[(0x3A) - 1])) (weights[(0x3A) - 1]) = (weights[(0x3A) - 1]) / 3;
            if (0 < (weights[(0x73) - 1])) (weights[(0x73) - 1]) = (weights[(0x73) - 1]) / 3;
            if (0 < (weights[(0x55) - 1])) (weights[(0x55) - 1]) = (weights[(0x55) - 1]) / 3;
            break;
        }
        ++difficultyLevel;
    } while (difficultyLevel < 7);

    int total = 0;
    int* cursor = weights;
    int count = 125;
    do {
        if (*cursor < 0) {
            *cursor = 0;
        }
        ++cursor;
        --count;
    } while (count != 0);
    total = 0;
    cursor = weights;
    count = 125;
    do {
        total += *cursor;
        ++cursor;
        --count;
    } while (count != 0);

    int randomValue = debug_rand(tplayerSourceName, 0xC41);
    int remainder = randomValue % total;
    int selectedBuildList = 0;
    int cumulative = 0;
    int selectionIndex = 0;
    for (; selectionIndex < 125; ++selectionIndex) {
        cumulative += weights[selectionIndex];
        if (cumulative > remainder) {
            selectedBuildList = selectionIndex;
            break;
        }
    }

    rge_base_game->get_string(selectedBuildList + 0x26930, buildListName, 0x100);

    switch (selectedBuildList) {
    case 0x0D: this->playerAI->strategyAI.setRule(0x3B, 4); this->playerAI->strategyAI.setRule(0x3C, 10); ++tplayer_globals::buildListCategoryCount7; ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x0E: this->playerAI->strategyAI.setRule(0x3B, 4); this->playerAI->strategyAI.setRule(0x3C, 10); ++tplayer_globals::buildListCategoryCount7; ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x0F: this->playerAI->strategyAI.setRule(0x3B, 4); this->playerAI->strategyAI.setRule(0x3C, 10); ++tplayer_globals::buildListCategoryCount7; ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x13: ++computerPlayerSetup[0]; break;
    case 0x14: ++computerPlayerSetup[0]; break;
    case 0x15: ++computerPlayerSetup[0]; break;
    case 0x16: break;
    case 0x17: break;
    case 0x18: break;
    case 0x19: break;
    case 0x1A: break;
    case 0x1B: break;
    case 0x1C: break;
    case 0x1D: break;
    case 0x1E: break;
    case 0x1F: break;
    case 0x20: break;
    case 0x21: break;
    case 0x22: break;
    case 0x23: break;
    case 0x24: break;
    case 0x25: break;
    case 0x26: break;
    case 0x27: break;
    case 0x75: break;
    case 0x76: break;
    case 0x77: break;
    case 0x78: break;
    case 0x3C: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x3D: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x3E: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x3F: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x40: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x41: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x42: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x43: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x44: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x45: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x46: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x47: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x4B: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x4C: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x4D: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x4E: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x4F: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x53: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x55: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x56: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x57: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x58: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x59: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x5A: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x5B: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x5C: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x5D: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x5E: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x5F: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x60: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x61: ++tplayer_globals::aggressiveBuildListCount; break;
    case 100: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x65: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x69: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x6A: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x6E: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x6F: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x73: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x74: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x79: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x7A: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x7B: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x7C: ++tplayer_globals::aggressiveBuildListCount; break;
    case 0x48: ++tplayer_globals::selectedBuildListCount; ++tplayer_globals::buildListCategoryCount5; break;
    case 0x49: ++tplayer_globals::selectedBuildListCount; ++tplayer_globals::buildListCategoryCount5; break;
    case 0x4A: ++tplayer_globals::selectedBuildListCount; ++tplayer_globals::buildListCategoryCount4; break;
    case 6: ++tplayer_globals::buildListCategoryCount1; break;
    case 7: ++tplayer_globals::buildListCategoryCount1; break;
    case 8: ++tplayer_globals::buildListCategoryCount1; break;
    case 0x2B: ++tplayer_globals::buildListCategoryCount1; break;
    case 0x36: ++tplayer_globals::buildListCategoryCount1; break;
    case 0x37: ++tplayer_globals::buildListCategoryCount1; break;
    case 0x3A: ++tplayer_globals::buildListCategoryCount1; break;
    case 0x3B: ++tplayer_globals::buildListCategoryCount1; break;
    case 0x68: ++tplayer_globals::buildListCategoryCount1; break;
    case 0: ++tplayer_globals::buildListCategoryCount5; break;
    case 1: ++tplayer_globals::buildListCategoryCount5; break;
    case 2: ++tplayer_globals::buildListCategoryCount5; break;
    case 0x29: ++tplayer_globals::buildListCategoryCount5; break;
    case 0x32: ++tplayer_globals::buildListCategoryCount5; break;
    case 0x33: ++tplayer_globals::buildListCategoryCount5; break;
    case 0x50: ++tplayer_globals::buildListCategoryCount5; break;
    case 0x51: ++tplayer_globals::buildListCategoryCount5; break;
    case 0x52: ++tplayer_globals::buildListCategoryCount5; break;
    case 0x6B: ++tplayer_globals::buildListCategoryCount5; break;
    case 0x10: ++tplayer_globals::buildListCategoryCount2; break;
    case 0x31: ++tplayer_globals::buildListCategoryCount2; break;
    case 0x6C: ++tplayer_globals::buildListCategoryCount2; break;
    case 0x11: ++tplayer_globals::buildListCategoryCount3; break;
    case 0x12: ++tplayer_globals::buildListCategoryCount3; break;
    case 0x2E: ++tplayer_globals::buildListCategoryCount3; break;
    case 0x34: ++tplayer_globals::buildListCategoryCount3; break;
    case 0x35: ++tplayer_globals::buildListCategoryCount3; break;
    case 99: ++tplayer_globals::buildListCategoryCount3; break;
    case 0x66: ++tplayer_globals::buildListCategoryCount3; break;
    case 0x6D: ++tplayer_globals::buildListCategoryCount3; break;
    case 0x28: ++tplayer_globals::buildListCategoryCount6; break;
    case 0x39: ++tplayer_globals::buildListCategoryCount6; break;
    case 0x54: ++tplayer_globals::buildListCategoryCount6; break;
    case 0x72: ++tplayer_globals::buildListCategoryCount6; break;
    case 3: ++tplayer_globals::buildListCategoryCount4; break;
    case 4: ++tplayer_globals::buildListCategoryCount4; break;
    case 5: ++tplayer_globals::buildListCategoryCount4; break;
    case 9: ++tplayer_globals::buildListCategoryCount4; break;
    case 10: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x0B: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x0C: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x2A: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x2C: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x2D: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x2F: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x30: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x38: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x62: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x67: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x70: ++tplayer_globals::buildListCategoryCount4; break;
    case 0x71: ++tplayer_globals::buildListCategoryCount4; break;
    default:
        ++tplayer_globals::buildListCategoryCount4;
        break;
    }
    ++tplayer_globals::selectedBuildListCount;

    rge_base_game->get_string(static_cast<int>(this->culture) + 0x27F6, tempString, 0x100);
    this->playerAI->logCommonHistory(tplayerEmptyName, tempString, static_cast<int>(this->culture) - 1);
    this->playerAI->logCommonHistory(tplayerBuildMessage, buildListName);
    strcpy(ruleSetName, tplayerRandomName);
    this->playerAI->logCommonHistory(tplayerRulesMessage);

    int workingMapType = mapType;
    switch (victoryType) {
    case 0:
    case 1:
        this->playerAI->strategyAI.setRule(0x36, 5);
        this->playerAI->strategyAI.setRule(0x37, 5);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        workingMapType = this->playerAI->strategyAI.rule(1);
        if (workingMapType > 0) {
            this->playerAI->strategyAI.setRule(0, 0x32);
            this->playerAI->strategyAI.setRule(1, 0x19);
            this->playerAI->strategyAI.setRule(2, 0x19);
        } else {
            this->playerAI->strategyAI.setRule(0, 0x32);
            this->playerAI->strategyAI.setRule(2, 0x32);
        }
        if (mapType > 1) {
            this->playerAI->strategyAI.setRule(3, 5);
        }
        this->playerAI->strategyAI.setRule(0x2A, 2);
        this->playerAI->strategyAI.setRule(0x3D, 2);
        workingMapType = mapType;
        if (victoryType != 2) {
            this->playerAI->strategyAI.setRule(0x26, mapSize + 1);
            this->playerAI->strategyAI.setRule(0x24, 1);
            if (victoryType == 3) {
                this->playerAI->strategyAI.setRule(0x36, 1);
            } else {
                this->playerAI->strategyAI.setRule(0x36, 5);
            }
            if (victoryType == 4) {
                this->playerAI->strategyAI.setRule(0x37, 1);
            } else {
                this->playerAI->strategyAI.setRule(0x37, 5);
            }
        }
        break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        this->playerAI->strategyAI.setRule(4, 10);
    }

    int attackTime = (debug_rand(tplayerSourceName, 0xE3A) % 12 + 0x1C) * 60;
    switch (selectedBuildList) {
    case 0:
    case 3:
    case 0x0B:
    case 0x0C:
    case 0x0D:
    case 0x13:
    case 0x2F:
    case 0x30:
    case 0x33:
    case 0x37:
    case 0x39:
    case 0x48:
    case 0x4A:
    case 0x4B:
    case 0x4E:
    case 0x51:
    case 0x55:
    case 0x58:
    case 0x5A:
    case 0x5E:
    case 0x60:
    case 100:
    case 0x69:
    case 0x6E:
    case 0x73:
        ++tplayer_globals::fastAttackListCount;
        attackTime = (debug_rand(tplayerSourceName, 0xE58) % 6 + 0x14) * 60;
        break;
    case 10:
    case 0x29:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x32:
    case 0x3A:
    case 0x71:
        ++tplayer_globals::attackTimingCategoryCount;
        attackTime = (debug_rand(tplayerSourceName, 0xE64) % 4 + 0x0B) * 60;
        break;
    case 9:
    case 0x38:
        attackTime = (debug_rand(tplayerSourceName, 0xE69) % 2 + 5) * 60;
        ++tplayer_globals::attackTimingCategoryCount;
        break;
    default:
        ++tplayer_globals::defaultAttackListCount;
        break;
    }

    int difficultyCopy = gameDifficulty;
    if (gameDifficulty == 0 && debug_rand(tplayerSourceName, 0xE73) % 3 == 0) {
        attackTime -= 300;
    }
    this->playerAI->strategyAI.setRule(0x68, attackTime);
    this->playerAI->strategyAI.setRule(0x10, 2);
    this->playerAI->strategyAI.setRule(0x1A, 10);
    this->playerAI->strategyAI.setRule(0x5D, 1);
    this->playerAI->strategyAI.setRule(99, 4);

    if (debug_rand(tplayerSourceName, 0xE80) % 3 == 0) {
        this->playerAI->strategyAI.setRule(0xBC, 0);
    } else {
        this->playerAI->strategyAI.setRule(0xBC, 1);
    }
    this->playerAI->strategyAI.setRule(0xC3, debug_rand(tplayerSourceName, 0xE86) % 0x28 + 10);
    this->playerAI->strategyAI.setRule(0xBD, debug_rand(tplayerSourceName, 0xE8A) % 0x46 + 0x1E);
    this->playerAI->strategyAI.setRule(0xC6, (debug_rand(tplayerSourceName, 0xE8E) % 5 + 5) * gameDifficulty);
    this->playerAI->strategyAI.setRule(0xC7, (debug_rand(tplayerSourceName, 0xE92) % 10 + 10) * gameDifficulty);
    this->playerAI->strategyAI.setRule(0xA1, 4);

    randomValue = mapSize;
    if (workingMapType == 0) {
        randomValue -= 2;
    } else if (workingMapType == 1) {
        randomValue -= 1;
    }

    switch (randomValue) {
    case -2:
    case -1:
        this->playerAI->strategyAI.setRule(0x49, debug_rand(tplayerSourceName, 0xEA2) % 2 + 0x0E);
        this->playerAI->strategyAI.setRule(0x4A, this->playerAI->strategyAI.rule(0x49) + debug_rand(tplayerSourceName, 0xEA4) % 4 + 1);
        break;
    case 0:
        this->playerAI->strategyAI.setRule(0x49, debug_rand(tplayerSourceName, 0xEA7) % 2 + 0x0F);
        this->playerAI->strategyAI.setRule(0x4A, this->playerAI->strategyAI.rule(0x49) + debug_rand(tplayerSourceName, 0xEA9) % 4 + 1);
        break;
    case 1:
        this->playerAI->strategyAI.setRule(0x49, debug_rand(tplayerSourceName, 0xEAC) % 3 + 0x10);
        this->playerAI->strategyAI.setRule(0x4A, this->playerAI->strategyAI.rule(0x49) + debug_rand(tplayerSourceName, 0xEAE) % 5 + 1);
        break;
    case 2:
        this->playerAI->strategyAI.setRule(0x49, debug_rand(tplayerSourceName, 0xEB1) % 2 + 0x11);
        this->playerAI->strategyAI.setRule(0x4A, this->playerAI->strategyAI.rule(0x49) + debug_rand(tplayerSourceName, 0xEB3) % 6 + 1);
        break;
    case 3:
        this->playerAI->strategyAI.setRule(0x49, debug_rand(tplayerSourceName, 0xEB6) % 2 + 0x12);
        this->playerAI->strategyAI.setRule(0x4A, this->playerAI->strategyAI.rule(0x49) + debug_rand(tplayerSourceName, 0xEB8) % 7 + 1);
        break;
    case 4:
        this->playerAI->strategyAI.setRule(0x49, debug_rand(tplayerSourceName, 0xEBB) % 4 + 0x12);
        this->playerAI->strategyAI.setRule(0x4A, this->playerAI->strategyAI.rule(0x49) + debug_rand(tplayerSourceName, 0xEBD) % 8 + 1);
        break;
    default:
        this->playerAI->strategyAI.setRule(0x49, debug_rand(tplayerSourceName, 0xEC1) % 2 + 0x12);
        this->playerAI->strategyAI.setRule(0x4A, this->playerAI->strategyAI.rule(0x49) + debug_rand(tplayerSourceName, 0xEC3) % 9 + 1);
        break;
    }
    this->playerAI->strategyAI.setRule(0xD0, 1);
    this->playerAI->strategyAI.setRule(0xD1, 1);
    this->playerAI->strategyAI.setRule(0xD2, 1);
    this->playerAI->strategyAI.setRule(0xDF, 1);

    if (workingMapType == 0) {
        this->playerAI->strategyAI.setRule(0xD4, 3);
        this->playerAI->strategyAI.setRule(0xD5, 6);
        this->playerAI->strategyAI.setRule(0xD6, 2);
        this->playerAI->strategyAI.setRule(0xE0, 6);
    } else if (workingMapType == 1) {
        this->playerAI->strategyAI.setRule(0xD4, 2);
        this->playerAI->strategyAI.setRule(0xD5, 5);
        this->playerAI->strategyAI.setRule(0xD6, 2);
        this->playerAI->strategyAI.setRule(0xE0, 4);
    } else if (workingMapType == 2 || workingMapType == 6 || workingMapType == 5 || workingMapType == 8) {
        this->playerAI->strategyAI.setRule(0xD4, 1);
        this->playerAI->strategyAI.setRule(0xD5, 4);
        this->playerAI->strategyAI.setRule(0xD6, 1);
        this->playerAI->strategyAI.setRule(0xE0, 3);
    } else if (workingMapType == 3 || workingMapType == 4 || workingMapType == 7) {
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
        if (difficultyCopy == 0) {
            cheatFood = 2000;
            cheatWood = 2000;
            cheatStone = 2000;
            cheatGold = 2000;
        }
        this->playerAI->strategyAI.setRule(0x8A, cheatFood);
        this->playerAI->strategyAI.setRule(0x8B, cheatWood);
        this->playerAI->strategyAI.setRule(0x8C, cheatStone);
        this->playerAI->strategyAI.setRule(0x8D, cheatGold);
        gameDifficulty = difficultyCopy;
    }

    this->playerAI->strategyAI.setRule(0xA8, 0);
    this->playerAI->strategyAI.setRule(0xA2, 0);
    if (gameDifficulty < 3) {
        this->playerAI->strategyAI.setRule(0xC2, 1);
        this->playerAI->strategyAI.setRule(0x2F, 2);
    } else {
        this->playerAI->strategyAI.setRule(0xC2, 0);
        this->playerAI->strategyAI.setRule(0x2F, 1);
    }

    if (gameDifficulty == 0) {
        this->playerAI->strategyAI.setRule(0xBA, 0xB4);
        this->playerAI->strategyAI.setRule(0xBA, 200);
    } else if (gameDifficulty == 1) {
        this->playerAI->strategyAI.setRule(0xBA, 0xB4);
        this->playerAI->strategyAI.setRule(0xBA, 0x96);
    } else if (gameDifficulty == 2) {
        this->playerAI->strategyAI.setRule(0xBA, 0xB4);
        this->playerAI->strategyAI.setRule(0xBA, 100);
    } else if (gameDifficulty == 3) {
        this->playerAI->strategyAI.setRule(0xBA, 0xB4);
        this->playerAI->strategyAI.setRule(0xBA, 0x32);
    }

    if (debug_rand(tplayerSourceName, 0xF50) % 6 < 5) {
        this->playerAI->strategyAI.setRule(0xB5, 1);
    } else {
        this->playerAI->strategyAI.setRule(0xB5, 0);
    }
    if (debug_rand(tplayerSourceName, 0xF56) % 3 < 1) {
        this->playerAI->strategyAI.setRule(0xB6, 1);
    } else {
        this->playerAI->strategyAI.setRule(0xB6, 0);
    }
}



void TRIBE_Player::setupEgyptian(int* p, int type, int unused1, int unused2)
{
    this->playerAI->logCommonHistory("Setting up as Egyptians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x3F] = 100;
        } else if (type == 2 || type == 6) {
            p[0x19] = 0x3C;
            p[0x3F] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x19] = 0x50;
            p[0x3F] = 0x14;
        } else {
            p[0x19] = 100;
        }
    } else if (rge_base_game->difficulty() < 1) {
        p[0x23] = 100;
    } else {
        p[3] = 10;
        p[9] = 10;
        p[10] = 10;
        p[0x11] = 0x28;
        p[0x12] = 0x28;
        p[0x2E] = 100;
        p[0x13] = 0x32;
        p[0x14] = 0x32;
        p[0x2F] = 100;
        p[0x50] = 100;
        p[0x51] = 0x1E;
        p[0x52] = 0x14;

        if (type == 0 || type == 1) {
            p[0x53] = 200;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[0x53] = 100;
        }
    }
}



void TRIBE_Player::setupGreek(int* first, int second, int third, int fourth)
{
    this->playerAI->logCommonHistory("Setting up as Greeks.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (second == 0 || second == 1) {
            first[0x40] = 100;
        } else if (second == 2 || second == 6) {
            first[0x1A] = 60;
            first[0x40] = 40;
        } else if (second == 5 || second == 8) {
            first[0x1A] = 80;
            first[0x40] = 20;
        } else {
            first[0x1A] = 100;
        }
    } else {
        int* p1 = first;
        int diff = rge_base_game->difficulty();
        if (diff < 1) {
            p1[0x24] = 100;
            return;
        }

        p1[6] = 30;
        p1[0xB] = 30;
        p1[0x14] = 30;
        p1[9] = 10;
        p1[10] = 10;
        p1[3] = 70;

        int p2 = second;

        p1[4] = 50;
        p1[7] = 20;
        p1[0x13] = 50;
        p1[0x30] = 100;
        p1[0x54] = 100;

        if (p2 == 0 || p2 == 1) {
            p1[0x55] = 200;
            p1[0x56] = 200;
        } else if (p2 == 2 || p2 == 6 || p2 == 8 || p2 == 5) {
            p1[0x55] = 100;
            p1[0x56] = 100;
        }
    }
}



void TRIBE_Player::setupBabylonian(int* p, int type, int unused1, int unused2)
{
    this->playerAI->logCommonHistory("Setting up as Babylonians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[61] = 100;
        } else if (type == 2 || type == 6) {
            p[23] = 60;
            p[61] = 40;
        } else if (type == 5 || type == 8) {
            p[23] = 80;
            p[61] = 20;
        } else {
            p[23] = 100;
        }
    } else {
        p[1] = 10;
        p[6] = 10;
        p[9] = 10;
        p[11] = 10;
        p[0] = 20;
        p[19] = 40;
        p[20] = 40;
        p[16] = 30;
        p[42] = 100;
        p[43] = 100;
        p[3] = 20;
        p[10] = 20;

        if (type == 0 || type == 1)
            p[77] = 60;
        else if (type == 2 || type == 6 || type == 8 || type == 5)
            p[77] = 30;
    }
}



void TRIBE_Player::setupAssyrian(int* first, int second, int third, int fourth)
{
    this->playerAI->logCommonHistory("Setting up as Assyrians.");
    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (second == 0 || second == 1) {
            first[0x3c] = 100;
            return;
        }
        if (second == 2 || second == 6) {
            first[0x16] = 60;
            first[0x3c] = 40;
            return;
        }
        if (second == 5 || second == 8) {
            first[0x16] = 80;
            first[0x3c] = 20;
            return;
        }
        first[0x16] = 100;
        return;
    }

    if (rge_base_game->difficulty() < 1) {
        first[0x22] = 100;
        return;
    }

    first[3] = 10;
    first[7] = 10;
    first[9] = 10;
    first[10] = 10;
    first[0x14] = 10;
    first[0x48] = 0x50;
    first[0x49] = 0x50;
    first[0x4a] = 0x50;
    first[0x10] = 0x28;
    first[0xb] = 0x28;
    first[6] = 0x14;
    first[0x13] = 0x14;
    first[0x28] = 100;
    first[0x29] = 100;
    if (second == 0 || second == 1) {
        first[0x4b] = 100;
        first[0x4c] = 100;
    } else if (second == 2 || second == 6 || second == 8 || second == 5) {
        first[0x4b] = 50;
        first[0x4c] = 50;
    }
}



void TRIBE_Player::setupMinoan(int* p, int type, int unused1, int unused2) {
    this->playerAI->logCommonHistory("Setting up as Minoans.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x42] = 100;
        } else if (type == 2 || type == 6) {
            p[0x1C] = 0x3C;
            p[0x42] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x1C] = 0x50;
            p[0x42] = 0x14;
        } else {
            p[0x1C] = 100;
        }
    } else if (rge_base_game->difficulty() < 1) {
        p[0x25] = 100;
    } else {
        p[4] = 10;
        p[6] = 10;
        p[9] = 10;
        p[10] = 10;
        p[0xB] = 10;
        p[0] = 0x3C;
        p[1] = 0x50;
        p[3] = 0x14;
        p[0x33] = 100;

        if (type == 0 || type == 1) {
            p[0x58] = 200;
            p[0x59] = 200;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[0x58] = 100;
            p[0x59] = 100;
        }
    }
}



void TRIBE_Player::setupHittite(int* first, int second, int third, int fourth)
{
    this->playerAI->logCommonHistory("Setting up as Hittites.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (second == 0 || second == 1) {
            first[0x41] = 100;
        } else if (second == 2 || second == 6) {
            first[0x1B] = 60;
            first[0x41] = 40;
        } else if (second == 5 || second == 8) {
            first[0x1B] = 80;
            first[0x41] = 20;
        } else {
            first[0x1B] = 100;
        }
    } else {
        first[4] = 0x28;
        first[0x12] = 0x28;
        first[0x10] = 80;
        first[0x31] = 100;
        first[0x32] = 100;
        first[3] = 30;

        first[6] = 0x14;
        first[9] = 10;
        first[10] = 10;
        first[11] = 10;
        first[0x11] = 0x14;

        if (second == 0 || second == 1) {
            first[0x57] = 0xA0;
            first[0] = 0x14;
        } else if (second == 2 || second == 6 || second == 8 || second == 5) {
            first[0x57] = 0x50;
            first[0] = 10;
        }
    }
}



void TRIBE_Player::setupPhoenician(int* first, int second, int third, int fourth)
{
    this->playerAI->logCommonHistory("Setting up as Phoenicians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (second == 0 || second == 1) {
            first[0x44] = 100;
        } else if (second == 2 || second == 6) {
            first[0x1E] = 60;
            first[0x44] = 40;
        } else if (second == 5 || second == 8) {
            first[0x1E] = 80;
            first[0x44] = 20;
        } else {
            first[0x1E] = 100;
        }
    } else {
        first[3] = 10;
        first[4] = 10;
        first[9] = 10;
        first[10] = 10;
        first[11] = 10;
        first[0x11] = 70;
        first[0x12] = 70;
        first[0] = 20;
        first[6] = 20;
        first[0x13] = 20;
        first[1] = 40;
        first[0x14] = 30;
        first[0x35] = 100;

        if (second == 0 || second == 1) {
            first[0x5C] = 200;
        } else if (second == 2 || second == 6 || second == 8 || second == 5) {
            first[0x5C] = 100;
        }
    }
}



void TRIBE_Player::setupSumerian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Sumerians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == 0 || mapType == 1) {
            b[0x46] = 100;
        } else if (mapType == 2 || mapType == 6) {
            b[0x20] = 0x3C;
            b[0x46] = 0x28;
        } else if (mapType == 5 || mapType == 8) {
            b[0x20] = 0x50;
            b[0x46] = 0x14;
        } else {
            b[0x20] = 100;
        }
    } else if (rge_base_game->difficulty() < 1) {
        b[0x26] = 100;
    } else {
        b[0x10] = 0x1E;
        b[3] = 10;
        b[9] = 10;
        b[10] = 10;
        b[11] = 10;
        b[4] = 0x14;
        b[0x11] = 0x14;
        b[0x39] = 100;
        b[0x3A] = 100;

        if (mapType == 0 || mapType == 1) {
            b[0x5E] = 200;
            b[0x5F] = 200;
        } else if (mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5) {
            b[0x5E] = 100;
            b[0x5F] = 100;
        }
    }
}



void TRIBE_Player::setupPersian(int* p, int type, int unused1, int unused2)
{
    this->playerAI->logCommonHistory("Setting up as Persians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x43] = 100;
        } else if (type == 2 || type == 6) {
            p[0x1D] = 0x3C;
            p[0x43] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x1D] = 0x50;
            p[0x43] = 0x14;
        } else {
            p[0x1D] = 0x64;
        }
    } else {
        p[6] = 10;
        p[9] = 10;
        p[10] = 10;
        p[0x11] = 0x3C;
        p[0x12] = 0x3C;
        p[1] = 0x28;
        p[0xB] = 0x28;
        p[0x14] = 0x28;
        p[0] = 0x14;
        p[0x10] = 0x14;
        p[7] = 0x32;
        p[0x13] = 0x14;
        p[0x34] = 0x64;

        if (type == 0 || type == 1) {
            p[0x5A] = 0xC8;
            p[0x5B] = 0xC8;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[0x5A] = 0x64;
            p[0x5B] = 0x64;
        }
    }
}


void TRIBE_Player::setupShang(int* b, int mapType, int gameType, int mapSize)
{
    this->playerAI->logCommonHistory("Setting up as Shang.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (mapType == 0 || mapType == 1) {
            b[0x45] = 100;
        } else if (mapType == 2 || mapType == 6) {
            b[0x1F] = 0x3C;
            b[0x45] = 0x28;
        } else if (mapType == 5 || mapType == 8) {
            b[0x1F] = 0x50;
            b[0x45] = 0x14;
        } else {
            b[0x1F] = 100;
        }
    } else {
        b[0] = 10;
        b[3] = 10;
        b[9] = 10;
        b[10] = 10;
        b[6] = 50;
        b[7] = 50;
        b[0x38] = 50;

        b[11] = 30;
        b[0x14] = 30;
        b[1] = 0x14;
        b[0x10] = 0x14;
        b[0x13] = 0x14;
        b[0x36] = 100;
        b[0x37] = 100;

        if (mapType == 0 || mapType == 1) {
            b[0x5D] = 0xA0;
        } else if (mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5) {
            b[0x5D] = 0x50;
        }
    }
}



void TRIBE_Player::setupYamato(int* first, int second, int third, int fourth)
{
    this->playerAI->logCommonHistory("Setting up as Yamato.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (second == 0 || second == 1) {
            first[0x47] = 100;
            return;
        }
        if (second == 2 || second == 6) {
            first[0x21] = 60;
            first[0x47] = 40;
            return;
        }
        if (second == 5 || second == 8) {
            first[0x21] = 80;
            first[0x47] = 20;
            return;
        }
        first[0x21] = 100;
        return;
    } else if (rge_base_game->difficulty() < 1) {
        first[0x27] = 100;
    } else {
        first[3] = 10;
        first[4] = 10;
        first[9] = 10;
        first[10] = 10;
        first[6] = 50;
        first[7] = 50;
        first[0] = 20;
        first[1] = 20;
        first[0x10] = 40;
        first[0x0B] = 20;
        first[0x3B] = 100;

        if (second == 0 || second == 1) {
            first[0x60] = 200;
            first[0x61] = 200;
        } else if (second == 2 || second == 6 || second == 8 || second == 5) {
            first[0x60] = 100;
            first[0x61] = 100;
        }
    }
}



void TRIBE_Player::setupChoson(int* p, int type, int unused1, int unused2) {
    this->playerAI->logCommonHistory("Setting up as Choson.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x3E] = 100;
        } else if (type == 2 || type == 6) {
            p[0x18] = 0x3C;
            p[0x3E] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x18] = 0x50;
            p[0x3E] = 0x14;
        } else {
            p[0x18] = 100;
        }
    } else {
        p[1] = 10;
        p[0x10] = 10;
        p[3] = 10;
        p[7] = 0x1E;
        p[9] = 0x1E;
        p[10] = 0x1E;
        p[0] = 0x14;
        p[6] = 0x14;
        p[0xB] = 0x46;
        p[0x13] = 0x32;
        p[0x14] = 0x5A;
        p[0x2C] = 100;
        p[0x2D] = 100;

        if (type == 0 || type == 1) {
            p[0x4E] = 200;
            p[0x4F] = 200;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[0x4E] = 100;
            p[0x4F] = 100;
        }
    }
}



void TRIBE_Player::setupRoman(int* first, int second, int third, int fourth)
{
    this->playerAI->logCommonHistory("Setting up as Roman.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (second == 0 || second == 1) {
            first[0x7C] = 0x64;
        } else if (second == 2 || second == 6) {
            first[0x78] = 0x3C;
            first[0x7C] = 0x28;
        } else if (second == 5 || second == 8) {
            first[0x78] = 0x50;
            first[0x7C] = 0x14;
        } else {
            first[0x78] = 0x64;
        }
    } else {
        first[0] = 0x0A;
        first[6] = 0x0A;
        first[9] = 0x0A;
        first[10] = 0x0A;
        first[0x13] = 0x0A;
        first[0x14] = 0x0A;
        first[3] = 0x14;
        first[4] = 0x14;
        first[0x0B] = 0x50;
        first[0x70] = 0x64;
        first[0x71] = 0x3C;
        first[0x72] = 0x50;

        if (second == 0 || second == 1) {
            first[0x73] = 0xC8;
            first[0x74] = 0xC8;
        } else if (second == 2 || second == 6 || second == 8 || second == 5) {
            first[0x73] = 0x64;
            first[0x74] = 0x64;
        }
    }
}



void TRIBE_Player::setupCarthaginian(int* p, int type, int unused1, int unused2) {
    this->playerAI->logCommonHistory("Setting up as Carthaginian.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x79] = 100;
        } else if (type == 2 || type == 6) {
            p[0x75] = 0x3C;
            p[0x79] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x75] = 0x50;
            p[0x79] = 0x14;
        } else {
            p[0x75] = 100;
        }
    } else {
        p[0] = 10;
        p[1] = 10;
        p[0x10] = 10;
        p[7] = 10;
        p[9] = 10;
        p[10] = 10;
        p[11] = 10;
        p[0x11] = 0x3C;
        p[0x12] = 0x3C;
        p[3] = 0x46;
        p[0x62] = 0x50;
        p[99] = 0x50;
        p[4] = 0x32;
        p[6] = 0x1E;

        if (type == 0 || type == 1) {
            p[100] = 200;
            p[101] = 200;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[100] = 100;
            p[101] = 100;
        }
    }
}



void TRIBE_Player::setupPalmyran(int* first, int second, int third, int fourth)
{
    this->playerAI->logCommonHistory("Setting up as Palmyran.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (second == 0 || second == 1) {
            first[0x7B] = 0x64;
        } else if (second == 2 || second == 6) {
            first[0x77] = 0x3C;
            first[0x7B] = 0x28;
        } else if (second == 5 || second == 8) {
            first[0x77] = 0x50;
            first[0x7B] = 0x14;
        } else {
            first[0x77] = 0x64;
        }
    } else {
        first[3] = 0x28;
        first[6] = 0x28;
        first[0] = 0x1E;
        first[7] = 0x0A;
        first[9] = 0x0A;
        first[10] = 0x0A;
        first[11] = 0x0A;
        first[1] = 0x1E;
        first[0x6B] = 0x50;
        first[0x6C] = 0x50;
        first[0x6D] = 0x50;
        first[0x10] = 0x3C;
        first[4] = 0x14;
        first[0x11] = 0x3C;

        if (second == 0 || second == 1) {
            first[0x6E] = 0xC8;
            first[0x6F] = 0xC8;
        } else if (second == 2 || second == 6 || second == 8 || second == 5) {
            first[0x6E] = 0x64;
            first[0x6F] = 0x64;
        }
    }
}



void TRIBE_Player::setupMacedonian(int* first, int second, int third, int fourth)
{
    this->playerAI->logCommonHistory("Setting up as Macedonian.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (second == 0 || second == 1) {
            first[0x7A] = 100;
        } else if (second == 2 || second == 6) {
            first[0x76] = 60;
            first[0x7A] = 40;
        } else if (second == 5 || second == 8) {
            first[0x76] = 80;
            first[0x7A] = 20;
        } else {
            first[0x76] = 100;
        }
    } else {
        first[3] = 0x28;
        first[4] = 0x28;
        first[0] = 0x0A;
        first[6] = 0x1E;
        first[7] = 0x1E;
        first[0x11] = 0x1E;
        first[0x68] = 0x50;
        first[0x66] = 0x50;
        first[0x67] = 0x50;
        first[1] = 0x0A;
        first[0x10] = 0x14;

        if (second == 0 || second == 1) {
            first[0x69] = 0xC8;
            first[0x6A] = 0xC8;
        } else if (second == 2 || second == 6 || second == 8 || second == 5) {
            first[0x69] = 100;
            first[0x6A] = 100;
        }
    }
}



void TRIBE_Player::logStatus(FILE* f, int verbose)
{
    char tempString[256];
    if (f == 0)
        return;

    fprintf(f, "Player %d:\n", static_cast<int>(this->id));
    if (verbose == 1) {
        rge_base_game->get_string(static_cast<int>(this->master_player_id) + 0x27f6, tempString, 0x100);
        if (this->playerAI == 0) {
            fprintf(f, "  Human Player, %s.\n", tempString);
        } else {
            fprintf(f, "  Computer Player, %s.\n", tempString);
            fprintf(f, "  Build List:      %s.\n", this->playerAI->buildAI.buildListName());
            fprintf(f, "  City Plan:       %s.\n", this->playerAI->constructionAI.constructionPlanName());
            fprintf(f, "  VC File:         %s.\n", this->playerAI->strategyAI.ruleSetName());
        }
    }

    fprintf(f, "  Points:\n");
    fprintf(f, "    Combat         %d.\n", this->victory_conditions->get_victory_points_group(0));
    fprintf(f, "    Economy        %d.\n", this->victory_conditions->get_victory_points_group(1));
    fprintf(f, "    Religion       %d.\n", this->victory_conditions->get_victory_points_group(2));
    fprintf(f, "    Science        %d.\n", this->victory_conditions->get_victory_points_group(3));
    fprintf(f, "    Survival       %d.\n", this->victory_conditions->get_victory_points_id(0x16));
    fprintf(f, "    Wonder         %d.\n", this->victory_conditions->get_victory_points_id(0x17));
    fprintf(f, "      Total:       %d.\n", this->victory_conditions->get_victory_points());
    fprintf(f, "  Population:      %d.\n", static_cast<int>(this->attributes[11]));
    fprintf(f, "  Kills:           %d.\n", this->victory_conditions->get_attribute_id(0));
    fprintf(f, "  Kill Ratio:      %d.\n", this->victory_conditions->get_attribute_id(2));
    fprintf(f, "  Razings:         %d.\n", this->victory_conditions->get_attribute_id(1));
    fprintf(f, "  Food:            %d.\n", static_cast<int>(this->attributes[0]));
    fprintf(f, "  Gold:            %d.\n", static_cast<int>(this->attributes[3]));
    fprintf(f, "  Stone:           %d.\n", static_cast<int>(this->attributes[2]));
    fprintf(f, "  Wood:            %d.\n", static_cast<int>(this->attributes[1]));
    fprintf(f, "  Technology:      %d.\n", this->victory_conditions->get_attribute_id(0x11));
    fprintf(f, "  Exploration:     %d.\n", this->victory_conditions->get_attribute_id(7));

    if (this->playerAI != 0) {
        fprintf(f, "Build AI: last=%s, last2=%s, Progress=%d/%d.\n",
                this->playerAI->buildAI.currentBuildItemRequested(),
                this->playerAI->buildAI.lastBuildItemRequested(),
                this->playerAI->buildAI.numberItemsIntoBuildList(),
                this->playerAI->buildAI.buildListLength());
        fprintf(f, "Civilians: Total=%d, Exp(%d/%d), Gat(%d/%d), Res(%d,%d,%d,%d).\n",
                this->playerAI->tacticalAI.numberCivilians(),
                this->playerAI->tacticalAI.numberCivilianExplorers(),
                this->playerAI->tacticalAI.desiredNumberCivilianExplorers(),
                this->playerAI->tacticalAI.numberGatherers(),
                this->playerAI->tacticalAI.desiredNumberGatherers(),
                this->playerAI->tacticalAI.neededResource(0),
                this->playerAI->tacticalAI.neededResource(1),
                this->playerAI->tacticalAI.neededResource(2),
                this->playerAI->tacticalAI.neededResource(3));
        fprintf(f, "Number Soldiers=%d.\n", this->playerAI->tacticalAI.numberSoldiers());
    }
}


void TRIBE_Player::trackUnitGather(int a, int b, int c)
{
    if (!this->playerAI)
        return;

    this->playerAI->tacticalAI.trackUnitGather(a, b, c);
}


void TRIBE_Player::get_achievement(unsigned char type, char* buffer)
{
    switch (type) {
    case 0:
        strcpy(buffer, name);
        break;
    case 1:
        sprintf(buffer, "%4.f", attributes[19] - attributes[11]);
        break;
    case 2:
        sprintf(buffer, "%4.f", attributes[20]);
        break;
    case 3:
        sprintf(buffer, "%4.f", attributes[11]);
        break;
    case 4:
        sprintf(buffer, "%5.f", attributes[3]);
        break;
    case 5: {
        float pct = this->visible->percentExplored() * 100.0f;
        sprintf(buffer, "%3.f%%", pct);
        break;
    }
    case 6:
        sprintf(buffer, "%4.f", attributes[19]);
        break;
    case 7:
        sprintf(buffer, "%4.f/%4.f/%4.f",
            attributes[7], attributes[13], attributes[14]);
        break;
    case 8:
        sprintf(buffer, "%4.f", attributes[21]);
        break;
    }
}

void TRIBE_Player::load_victory(int first, long* second, unsigned char third) {
    TRIBE_Victory_Conditions* v = new TRIBE_Victory_Conditions(this, first, second, third);
    if (v == 0) {
        v = 0;
    }
    this->victory_conditions = v;
}


void TRIBE_Player::new_victory() {
    TRIBE_Victory_Conditions* v = new TRIBE_Victory_Conditions(this);
    this->victory_conditions = v;
}


void TRIBE_Player::add_attribute_num(short first, float second, unsigned char third) {
    if ((first == 3) && (third != 0)) {
        float addend = second;
        float dest = this->attributes[49];
        this->attributes[49] = addend + dest;
    }
    if (first == 0x32) {
        this->allied_LOS_Enable = 1;
        this->world->update_mutual_allies();
    }
    RGE_Player::add_attribute_num(first, second, third);
}


void TRIBE_Player::analyize_selected_objects()
{
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
                    if (group == 0x12) {
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
                if (object_id == 0x4F || object_id == 0xC7 ||
                    object_id == 0x45 || object_id == 0x116) {
                    this->sel_object_properties |= 1;
                }
            }
            ++j;
        }
    }
}




int TRIBE_Player::get_mouse_pointer_action_vars(int id, int& action, int& var)
{
    action = 0;
    var = 0;
    RGE_Static_Object* object = this->world->object(id);
    if (object == 0) return 0;
    this->analyize_selected_objects();

    TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
    MouseClickInfo* table = game->MouseRightClickTable;
    int table_count = game->MouseRightClickTableSize;
    if (this->sel_object_properties != 0) {
        table = game->MouseLeftClickTable;
        table_count = game->MouseLeftClickTableSize;
    }
    int group = object->master_obj->object_group;
    if (table == 0 || group < 0 || group >= table_count) return 0;

    MouseClickInfo* info = &table[group];
    if (object->owner == this) {
        action = info->self_action;
        var = info->self_text_id;
    } else if (object->owner == 0 || object->owner->id == 0) {
        action = info->gaia_action;
        var = info->gaia_text_id;
    } else if (this->isAlly(object->owner->id) != 0) {
        action = info->ally_action;
        var = info->ally_text_id;
    } else if (this->isNeutral(object->owner->id) != 0) {
        action = info->neutral_action;
        var = info->neutral_text_id;
    } else {
        action = info->enemy_action;
        var = info->enemy_text_id;
    }
    return action >= 0;
}


TRIBE_Gaia::TRIBE_Gaia(int file, TRIBE_World* world, unsigned char player_id)
    : TRIBE_Player(file, world, player_id)
{
    this->type = 2;
    rge_read(file, &update_time, 4);
    rge_read(file, &update_nature, 4);
    rge_read(file, &animal_max, 4);
    rge_read(file, &last_count, 4);
}


TRIBE_Gaia::TRIBE_Gaia(TRIBE_World* world, RGE_Master_Player* player,
                        unsigned char third, char* fourth, unsigned char fifth)
    : TRIBE_Player(world, player, third, fourth, fifth, 0, 1, 0, 0, 0)
{
    this->type = 2;
    this->update_time = 0.0f;
    this->update_nature = 0x1D;
    this->animal_max = 0;
    this->last_count = 0;
}


void TRIBE_Gaia::save(int first) {
    TRIBE_Player::save(first);

    rge_write(first, &this->update_time, 4);
    rge_write(first, &this->update_nature, 4);
    rge_write(first, &this->animal_max, 4);
    rge_write(first, &this->last_count, 4);
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


void TRIBE_Gaia::load_master_object(int a, short b, unsigned char c,
                                    RGE_Sprite** d, RGE_Sound** e) {
    TRIBE_Player::load_master_object(a, b, c, d, e);
}


void TRIBE_Gaia::random_start() {}


void TRIBE_Player::scenario_postload(int first, long* second, float third) {
    RGE_Player::scenario_postload(first, second, third);
    if (0.0 < this->attributes[50]) {
        this->allied_LOS_Enable = 1;
        this->world->update_mutual_allies();
    }
}
