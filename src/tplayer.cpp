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
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

extern float DAT_00576818, DAT_0057681c, DAT_00576820;
extern float DAT_00576824, DAT_00576828, DAT_0057682c, DAT_00576840;
extern float DAT_00576868, DAT_0057686c;
extern double DAT_00576830, DAT_00576838;
extern unsigned int DAT_0086bc88, DAT_0086bc8c;
extern unsigned int DAT_00886c1c, DAT_00886c20, DAT_00886c24, DAT_00886c28;
extern unsigned int DAT_00886c2c, DAT_00886c30, DAT_00886c34, DAT_00886c38;
extern unsigned int DAT_00886c3c, DAT_00886c40, DAT_00886c44, DAT_00886c48;
extern unsigned int computerPlayerSetup[13];
extern int allowAIToCheat;
extern int debug_random_on, global_save_debug_random_on1, global_save_debug_random_on2;
extern int global_save_debug_random_on3, global_save_debug_random_on4;
extern char s_592A40[];
extern float save_game_version;
extern TCommunications_Handler* comm;
extern TChat* chat;
extern "C" int __cdecl debug_rand(char*, int);
extern "C" void __cdecl debug_srand(char*, int, int);


struct BuildListPacket { int weights[125]; int mostBuiltUnit; };

static void dividePositive(int& value) { if (value > 0) value /= 3; }

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
    : RGE_Player(fd, (RGE_Game_World*)world, mode), playerAI(0)
{
    rge_read(fd, &this->type, 1);
    rge_read(fd, &this->update_count, 4);
    rge_read(fd, &this->updateCountNeedHelp, 4);
    rge_read(fd, &this->fog_update, 4);
    rge_read(fd, &this->update_time, 4);

    this->tech_tree = new TRIBE_Player_Tech(fd, world->tech, (RGE_Player*)this, 0);

    if (save_game_version > DAT_00576818) {
        rge_read(fd, &this->update_history_count, 4);
        this->history = new TRIBE_History_Info(fd);
    } else {
        this->update_history_count = 0;
        this->history = new TRIBE_History_Info(-1);
    }

    if (save_game_version >= DAT_0057681c) {
        rge_read(fd, &this->ruin_held_time, 4);
        rge_read(fd, &this->artifact_held_time, 4);
    } else {
        this->ruin_held_time = -1.0f;
        this->artifact_held_time = -1.0f;
    }

    if (this->type == 3) {
        int create_ai = 1;
        if (save_game_version >= DAT_00576820) {
            rge_read(fd, &create_ai, 4);
        }
        if (comm->IsHost() == 1 && create_ai == 1) {
            this->playerAI = new TribeMainDecisionAIModule((int)this->id, this->name, this, fd);
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
    this->VR_List = new Visible_Resource_Manager((RGE_Player*)this, 5);

    if (make_ai == 0) {
        this->type = 1;
    } else {
        this->type = 3;
        this->computerPlayerValue = 1;
        if (comm->IsHost() == 1) {
            this->playerAI = new TribeMainDecisionAIModule(
                (void*)0, this->id, this->name, this, ai1, ai2, ai3);
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
        this->visible = new RGE_Visible_Map(world->map, (RGE_Player*)this);
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
    this->fog_update = (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x140) * 3) / 0x7fff + 3;
    this->update_time = 0.0f;
    this->history = new TRIBE_History_Info(-1);
    this->tech_tree = new TRIBE_Player_Tech(world->tech, (RGE_Player*)this, 1);
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
            unsigned char group = (unsigned char)obj->master_obj->object_group;
            if (group > 0x1E && group < 0x5A) {
                obj->new_angle(amount);
            }
            else {
                obj->facet = (unsigned char)(int)amount;
            }
        }
        if (this->master_objects[type_id]->object_group == 0x50 && mode == 2) {
            ((TRIBE_Building_Object*)obj)->build(10000.0f);
        }
    }
    return obj;
}




void TRIBE_Player::save(int file)
{
    int save_file = file;
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
    if (this->type == 1) {
        int present = this->playerAI != 0 && comm->IsHost() == 1;
        rge_write(save_file, &present, 4);
        if (present) this->playerAI->save(save_file);
    }
    color_log(0x16, 0x5F, 2);
}




void TRIBE_Player::update()
{
    float* attributes = this->attributes;
    this->update_time += this->world->world_time_delta_seconds;
    while (this->update_time > DAT_00576824) {
        this->update_time -= DAT_00576824;
        ++this->update_history_count;
        if (this->update_history_count >= 15) {
            this->update_history_count -= 15;
            unsigned char population = attributes[11] < DAT_00576828
                ? 0 : (unsigned char)(long)attributes[11];
            this->history->add_history_entry(0, population);
        }
        if (rge_base_game->fullVisibility()) attributes[22] = 100.0f;
        else attributes[22] = this->visible->percentExplored() * DAT_0057682c;
        attributes[44] = attributes[20] - (attributes[19] - attributes[11]);
        if (attributes[44] < DAT_00576830) attributes[44] = 0.0f;
        attributes[9] += attributes[10];
        if (attributes[9] > DAT_00576838) attributes[9] = 100.0f;
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
    attributes[0] -= this->world->world_time_delta_seconds * attributes[33] * attributes[11] * DAT_00576840;
    if (attributes[0] < DAT_00576830) attributes[0] = 0.0f;
    int seed = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x25f);
    int old = debug_random_on;
    global_save_debug_random_on1 = old;
    debug_random_on = 0;
    if (this->playerAI && comm->ComputerPlayerGameStart() == 1) {
        if (this->world->currentUpdateComputerPlayer == -1) this->world->selectNextComputerPlayer(3);
        this->playerAI->update(0);
    }
    debug_random_on = old;
    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x277, seed);
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
        tech->~TRIBE_Player_Tech();
        delete tech;
    }

    i = 0;
    if (this->master_object_num > 0) {
        do {
            obj = (RGE_Master_Static_Object*)this->master_objects[i];
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
        this->tech_tree = new TRIBE_Player_Tech(file, ((TRIBE_World*)this->world)->tech, this, 1);
        return;
    }

    tech = new TRIBE_Player_Tech(((TRIBE_World*)this->world)->tech, this, 0);
    this->tech_tree = tech;

    if (this->culture >= 0 && !static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree() && !static_cast<T_Scenario*>(((TRIBE_World*)this->world)->scenario)->GetScenarioOption(2)) {
        static_cast<TRIBE_Effects*>(((TRIBE_World*)this->world)->effects)->do_tech_effect((short)this->culture, this);
    }
    else {
        static_cast<TRIBE_Effects*>(((TRIBE_World*)this->world)->effects)->do_tech_effect(0xD2, this);
    }

    if (rge_base_game->game_mode != 7) {
        static_cast<T_Scenario*>(((TRIBE_World*)this->world)->scenario)->set_player_tech(this);
    }
    this->tech_tree->check_for_new_tech();
}


extern float DAT_00576858;


void TRIBE_Player::load(int file)
{
    rge_read(file, &this->master_object_num, 2);
    short count = this->master_object_num;
    if (count > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc(count, 4);
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

    if (save_game_version >= DAT_00576858) {
        this->doppleganger_objects->load_list(file, this->world);
    }
}




void TRIBE_Player::load_master_object(int param_1, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Static_Object* obj;

    switch (type) {
    case 'F':
        obj = new RGE_Master_Combat_Object(param_1, sprites, sounds, 1);
        break;
    case 'P':
        obj = new TRIBE_Master_Building_Object(param_1, sprites, sounds, 1);
        master_objects[index] = obj;
        return;
    case 'Z':
        obj = new TRIBE_Master_Tree_Object(param_1, sprites, sounds, 1);
        break;
    default:
        RGE_Player::load_master_object(param_1, index, type, sprites, sounds);
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
    short* types[3] = { &t1, &t2, &t3 };
    short* amounts[3] = { &a1, &a2, &a3 };
    RGE_Master_Static_Object* master = this->master_objects[(unsigned short)obj];
    t1 = t2 = t3 = -1;
    a1 = a2 = a3 = 0;
    if (nameOut != 0) *nameOut = master == 0 ? 0 : master->name;
    if (master == 0 || master->master_type < 0x46) return;
    for (int i = 0; i < 3; ++i) {
        *types[i] = master->attribute_type_held[i];
        if (*types[i] >= 0)
            *amounts[i] = (short)(master->attribute_amount_held[i] * factor);
    }
}


RGE_Static_Object* TRIBE_Player::find_obj(short id, RGE_Static_Object* after)
{
    RGE_Object_Node* node = this->objects->list;
    bool found = after == 0;
    while (node != 0) {
        RGE_Static_Object* object = node->node;
        if (object != 0) {
            if (found && object->master_obj->id == id && object->object_state <= 2)
                return object;
            if (object == after) found = true;
        }
        node = node->next;
    }
    return 0;
}


RGE_Static_Object* TRIBE_Player::make_new_object(long id, float x, float y, float z, int unused)
{
    RGE_Static_Object* object = RGE_Player::make_new_object(id, x, y, z, unused);
    if (object == 0) return 0;
    if (unused != 0) {
        static_cast<TRIBE_World*>(this->world)->check_destructables(
            (short)id, (short)id, x, y, 0);
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
    Tech_Tree* master = ((TRIBE_World*)this->world)->tech->tech_tree;

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

    *out_items = (Item_Avail*)calloc((int)count, 0x28);

    short n = 0;
    short out_index = 0;
    if (this->tech_tree->tech_player_tree_num <= 0) {
        return;
    }

    do {
        int idx = (int)n;
        if (this->tech_tree->tech_player_tree[idx].state == 1) {
            Tech_Tree* entry = &master[idx];
            if (entry->build_obj_id == button_location) {
                int avail_index = (int)out_index;
                Item_Avail* item = *out_items;
                item[avail_index].id = n;
                (*out_items)[avail_index].pict = entry->icon;
                (*out_items)[avail_index].name = entry->name;

                this->tech_tree->tech_cost(n, &inv1, &amt1, &inv2, &amt2, &inv3, &amt3);

                (*out_items)[avail_index].inventory_item_1 = inv1;
                (*out_items)[avail_index].inventory_cost_1 = (float)(int)amt1;
                (*out_items)[avail_index].inventory_item_2 = inv2;
                (*out_items)[avail_index].inventory_cost_2 = (float)(int)amt2;
                (*out_items)[avail_index].inventory_item_3 = inv3;
                (*out_items)[avail_index].inventory_cost_3 = (float)(int)amt3;
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

    if (group == 0x76 && this->attributes[0x30] == DAT_00576828 && this->master_objects[0x6d]->available == 0) {
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
    *item_list = (Item_Avail*)calloc((int)count, 0x28);

    short idx = 0;
    short out_i = 0;
    while (idx < this->master_object_num) {
            if (this->master_objects[idx] != 0 && this->master_objects[idx]->master_type >= 0x46 &&
                this->master_objects[idx]->available != 0 && this->master_objects[idx]->object_group == group) {
                (*item_list)[out_i].id = idx;
                (*item_list)[out_i].pict = this->master_objects[idx]->button_pict;
                (*item_list)[out_i].name = this->master_objects[idx]->name;
                this->obj_cost((short)idx, 0, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3, 1.0f);
                (*item_list)[out_i].inventory_item_1 = inv_1;
                (*item_list)[out_i].inventory_cost_1 = (float)(int)inv_amt_1;
                (*item_list)[out_i].inventory_item_2 = inv_2;
                (*item_list)[out_i].inventory_cost_2 = (float)(int)inv_amt_2;
                (*item_list)[out_i].inventory_item_3 = inv_3;
                (*item_list)[out_i].inventory_cost_3 = (float)(int)inv_amt_3;
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
        (*item_list)[out_i].inventory_cost_1 = (float)(int)inv_amt_1;
        (*item_list)[out_i].inventory_item_2 = inv_2;
        (*item_list)[out_i].inventory_cost_2 = (float)(int)inv_amt_2;
        (*item_list)[out_i].inventory_item_3 = inv_3;
        (*item_list)[out_i].inventory_cost_3 = (float)(int)inv_amt_3;
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
                                    (short)node->node->world_x,
                                    (short)node->node->world_y)) {
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

    *out_count = (short)dock_count;
    if (dock_count != 0) {
        *out_trade = (Trade_Avail*)calloc(dock_count, 0x0C);
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
    short local_4;
    RGE_Static_Object** list;
    short list_num;

    RGE_Master_Static_Object* info = this->master_objects[(unsigned short)type];
    if (info != 0 && (info->available != 0 || type == 0x6d)) {
        if (get_selected_objects_to_command(&list, (short*)&local_4, 4, 4, -1, -1)) {
            ((RGE_Master_Static_Object*)this->master_objects[0x76])->play_command_sound();
            static_cast<TRIBE_Command*>(this->world->commands)->command_build(list, local_4, type, x, y);
            free(list);
            return 1;
        }
    }

    return 0;
}



unsigned char TRIBE_Player::command_make_wall(short type, long p2, long p3,
                                               long p4, long p5)
{
    short local_4;
    RGE_Static_Object** list;

    RGE_Master_Static_Object* info = this->master_objects[(unsigned short)type];
    if (info != 0 && info->available != 0) {
        if (get_selected_objects_to_command(&list, &local_4, 4, 4,
                                            -1, -1)) {
            this->master_objects[0x76]->play_command_sound();
            static_cast<TRIBE_Command*>(this->world->commands)->command_build_wall(list, local_4, type,
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


unsigned char TRIBE_Player::command_building_cancel(void) {
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


void __cdecl free(void*);


unsigned char TRIBE_Player::command_trade_attribute(long param) {
    RGE_Static_Object** list;
    short local_4[2];

    if (this->get_selected_objects_to_command(&list, local_4, 4, -1, -1, 5)) {
        (*list)->play_command_sound();
        static_cast<TRIBE_Command*>(this->world->commands)->command_trade_attribute(list, local_4[0], param);
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


void __cdecl free(void*);


unsigned char TRIBE_Player::command_attack_ground(float x, float y) {
    RGE_Static_Object** list;
    short local_4[2];

    if (this->get_selected_objects_to_command(&list, local_4, 4, -1, -1, 4)) {
        (*list)->play_command_sound();
        static_cast<TRIBE_Command*>(this->world->commands)->command_attack_ground(list, local_4[0], x, y);
        free(list);
        return 1;
    }

    return 0;
}


unsigned char TRIBE_Player::command_give_attribute(int param_1, int param_2, float param_3, float param_4) {
    if (param_2 == -1 || param_3 == DAT_00576828) {
        return 0;
    }
    static_cast<TRIBE_Command*>(this->world->commands)->command_give_attribute(this->id, param_1, param_2, param_3, param_4);
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
    if ((float)obj->master_obj->hp > obj->hp || obj->object_state > 2)
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

unsigned char TRIBE_Player::command_make_unload(float param_1, float param_2) {
    RGE_Static_Object** list;
    short list_num;
    short local_4[2];

    if (get_selected_objects_to_command(&list, local_4, 4, -1, -1, 7)) {
        list[0]->play_command_sound();
        static_cast<TRIBE_Command*>(this->world->commands)->command_unload(list, local_4[0], param_1, param_2);
        free(list);
        return 1;
    }
    return 0;
}


unsigned char TRIBE_Player::check_obj_cost(short obj_id, short* out, float factor,
                                             int skip_farm)
{
    RGE_Master_Static_Object* object = this->master_objects[(unsigned short)obj_id];
    if (out != 0) *out = -1;
    if (object == 0 || object->master_type < 0x46) return 0;
    float population = this->attributes[3];
    bool population_available = this->attributes[29] >= 1.0f;
    if (!population_available) population = 0.0f;
    for (int i = 0; i < 3; ++i) {
        int type = object->attribute_type_held[i];
        if (type < 0) continue;
        float amount = object->attribute_amount_held[i] * factor;
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
            if (object->attribute_flag[i] == 0 ||
                population + this->attributes[type] < amount) {
                if (out != 0) *out = (short)type;
                return 0;
            }
            population -= amount - this->attributes[type];
        }
    }
    return 1;
}


unsigned char TRIBE_Player::pay_obj_cost(short obj_id, float factor, int skip_farm)
{
    RGE_Master_Static_Object* object = this->master_objects[(unsigned short)obj_id];
    if (!check_obj_cost(obj_id, 0, factor, skip_farm) || object == 0) return 0;
    for (int i = 0; i < 3; ++i) {
        int type = object->attribute_type_held[i];
        if (type >= 0 && object->attribute_flag[i] != 0 &&
            (skip_farm == 0 || type != 4)) {
            float amount = object->attribute_amount_held[i] * factor;
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


void TRIBE_Player::reimburse_obj_cost(short obj_idx)
{
    RGE_Master_Static_Object* object = this->master_objects[(unsigned short)obj_idx];
    if (object == 0 || object->master_type < 0x46) return;
    for (int i = 0; i < 3; ++i) {
        int type = object->attribute_type_held[i];
        if (type >= 0 && object->attribute_flag[i] != 0)
            this->attributes[type] += object->attribute_amount_held[i];
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
    if (enable != 0) this->tech_tree->enable((short)tech_id);
    else this->tech_tree->disable((short)tech_id);
}


void TRIBE_Player::rev_tech(long param_1)
{
    switch (param_1) {
    case 0x19:
        this->tech_tree->do_tech((short)(long)this->attributes[25]);
        return;

    case 0x17:
        this->tech_tree->disable((short)(long)this->attributes[23]);
        this->tech_tree->rev_tech((short)(long)this->attributes[25]);
        this->tech_tree->enable((short)(long)this->attributes[23]);
        this->tech_tree->do_tech((short)(long)this->attributes[23]);
        return;

    case 0x18:
        this->tech_tree->disable((short)(long)this->attributes[23]);
        this->tech_tree->disable((short)(long)this->attributes[24]);
        this->tech_tree->rev_tech((short)(long)this->attributes[25]);
        this->tech_tree->enable((short)(long)this->attributes[23]);
        this->tech_tree->rev_tech((short)(long)this->attributes[23]);
        this->tech_tree->enable((short)(long)this->attributes[24]);
        this->tech_tree->do_tech((short)(long)this->attributes[24]);
        return;

    case 1:
        this->tech_tree->disable((short)(long)this->attributes[23]);
        this->tech_tree->disable((short)(long)this->attributes[24]);
        this->tech_tree->rev_tech((short)(long)this->attributes[25]);
        this->tech_tree->enable((short)(long)this->attributes[23]);
        this->tech_tree->rev_tech((short)(long)this->attributes[23]);
        this->tech_tree->enable((short)(long)this->attributes[24]);
        this->tech_tree->rev_tech((short)(long)this->attributes[24]);
        return;

    default:
        return;
    }
}


void TRIBE_Player::add_population_entry(void) {
    if (this->attributes[11] < 0.0f) {
        this->history->add_history_entry(0, 0);
        return;
    }

    this->history->add_history_entry(0, (int)this->attributes[11]);
}





void TRIBE_Player::random_start()
{
    uchar found_ally = 0;

    if (this->objects->list == 0) {
        float w1;
        float h;
        w1 = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x631) *
                      (this->world->map->map_height - 0x1e)) / 0x7fff + 0xf)
              - DAT_00576868;
        h = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x632) *
                     (this->world->map->map_width - 0x1e)) / 0x7fff + 0xf)
             - DAT_00576868;
        int tries = 1;
        while (tries < 5000) {
            if (this->master_objects[0x6d]->check_placement(
                    this, h - DAT_00576868, w1 - DAT_00576868,
                    0, 0, 1, 1, 1, 1, 1) == 0)
                break;
            w1 = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x631) *
                          (this->world->map->map_height - 0x1e)) / 0x7fff + 0xf)
                         - DAT_00576868;
            h = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x632) *
                         (this->world->map->map_width - 0x1e)) / 0x7fff + 0xf)
                - DAT_00576868;
            ++tries;
        }

        if (tries < 5000) {
            TRIBE_Building_Object* town_center_object =
                (TRIBE_Building_Object*)this->master_objects[0x6d]->make_new_obj(
                    this, h, w1, 0);
            this->set_map_loc((short)h, (short)w1);
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
                    x_delta = (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x646) * 6) /
                              0x7fff - 3;
                    y_delta = (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x647) * 6) /
                              0x7fff - 3;
                    x = (float)x_delta -
                        (float)debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x648) * DAT_0057686c + w1;
                    y = (float)y_delta -
                        (float)debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x649) * DAT_0057686c + h;

                    if (x >= DAT_00576828 && x < (float)this->world->map->map_height &&
                        y >= DAT_00576828 && y < (float)this->world->map->map_width &&
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
        this->set_map_loc((short)town_center_object->world_x,
                          (short)town_center_object->world_y);
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


void TRIBE_Player::objectCost(int object_id, int param_2, ResourceItem* item, int param_4) {
    short inv1;
    short amt1;
    short inv2;
    short amt2;
    short inv3;
    short amt3;

    this->obj_cost((short)object_id, 0, inv2, (short&)object_id, inv3, amt3, amt1, inv1, 1.0f);
    item->incrementValue(inv2, (short)object_id);
    item->incrementValue(inv3, amt3);
    item->incrementValue(amt1, inv1);
}


int TRIBE_Player::objectCostByType(int input)
{
    short param_1;
    short inv_3;
    short inv_2;
    short inv_1;
    short local_4;
    short local_2;

    obj_cost((short)input, (char**)0, local_2, param_1, local_4, inv_2, inv_1, inv_3, 1.0f);
    return (int)param_1 + (int)inv_3 + (int)inv_2;
}


void TRIBE_Player::researchCost(int tech_id, int unused, ResourceItem* resources, int unused2) {
    short inv_amt_2;
    short inv_2;
    short inv_amt_3;
    short inv_3;
    short inv_1;
    short inv_amt_1;

    this->tech_tree->tech_cost((short)tech_id, &inv_2, (short*)&tech_id, &inv_3, &inv_amt_3, &inv_1, &inv_amt_1);
    resources->incrementValue(inv_2, (short)tech_id);
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
    state = tech->get_tech_state((short)tech_id);
    if (state != 3 && state != -1)
        return 1;
    return 0;
}


unsigned char TRIBE_Player::researchState(int tech_id) {
    TRIBE_Player_Tech* tech =
        this->tech_tree;
    return (unsigned char)tech->get_tech_state((short)tech_id);
}


void TRIBE_Player::changeToHumanPlayer() {}


void TRIBE_Player::changeToComputerPlayer() {}



char* TRIBE_Player::aiStatus(int param_1)
{
    if (this->playerAI == 0) {
        if (this->world->currentUpdateComputerPlayer != -1) {
            RGE_Player* otherPlayer = this->world->players[this->world->currentUpdateComputerPlayer];
            if (otherPlayer != 0) {
                TribeMainDecisionAIModule* ai = ((TRIBE_Player*)otherPlayer)->playerAI;
                int last = ai->tacticalAI.lastUpdateAreaTimeValue;
                int avg = ai->tacticalAI.averageUpdateAreaTimeValue;
                sprintf(this->aiStatusInformationValue,
                    "ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s.",
                    ((TRIBE_World*)this->world)->controllingComputerPlayer,
                    this->world->currentUpdateComputerPlayer,
                    avg,
                    last,
                    ai->tacticalAI.updateAreaName());
                return this->aiStatusInformationValue;
            }
        }
        return "Invalid currentUpdateComputerPlayer...";
    }
    if (param_1 == 1) {
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
    if (param_1 == 2) {
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
    if (param_1 == 3) {
        sprintf(this->aiStatusInformationValue3,
            "Gat(Act/Des): %s=(%d/%d), %s=(%d/%d), %s=(%d/%d), %s=(%d/%d).  #Civs=%d, #Sol=%d, #Boats=%d.",
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)), this->playerAI->tacticalAI.actualGathererCount(0), this->playerAI->tacticalAI.desiredGathererCount(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)), this->playerAI->tacticalAI.actualGathererCount(1), this->playerAI->tacticalAI.desiredGathererCount(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)), this->playerAI->tacticalAI.actualGathererCount(2), this->playerAI->tacticalAI.desiredGathererCount(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)), this->playerAI->tacticalAI.actualGathererCount(3), this->playerAI->tacticalAI.desiredGathererCount(3),
            this->playerAI->tacticalAI.numberCivilians(), this->playerAI->tacticalAI.numberSoldiers(), this->playerAI->tacticalAI.numberBoats());
        return this->aiStatusInformationValue3;
    }
    if (param_1 == 4) {
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
    if (param_1 == 5) {
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
    if (param_1 == 6) {
        TribeMainDecisionAIModule* ai =
            ((TRIBE_Player*)this->world->players[this->world->currentUpdateComputerPlayer])->playerAI;
        int last = ai->tacticalAI.lastUpdateAreaTimeValue;
        int avg = ai->tacticalAI.averageUpdateAreaTimeValue;
        int attackEnabled = this->playerAI->tacticalAI.attackEnabledValue;
        sprintf(this->aiStatusInformationValue6,
            "Per: %s, AttEnab=%d, AttDly=%d Min, ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s.",
            this->playerAI->strategyAI.ruleSetName(),
            attackEnabled,
            this->playerAI->tacticalAI.strategicNumber(0x68) / 60,
            ((TRIBE_World*)this->world)->controllingComputerPlayer,
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
        vsprintf(textOut, format, (char*)((&format) + 1));
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


void TRIBE_Player::removeObject(RGE_Static_Object* obj, int param_2, int param_3, RGE_Object_Node* param_4) {
    RGE_Player::removeObject(obj, param_2, param_3, param_4);

    if (this->playerAI) {
        short grp = obj->master_obj->object_group;
        if (grp != 0x0B && obj->id >= 0) {
            this->playerAI->removeObject(obj->id);
        }
    }
}




void TRIBE_Player::buildObject(int param_1, int param_2, float param_3, float param_4, int param_5)
{
    int* objectId = (int*)calloc(1, 4);
    *objectId = param_1;
    static_cast<TRIBE_Command*>(this->world->commands)->command_build(this->id, objectId, 1, param_2, param_3, param_4, param_5);
    free(objectId);
}


void TRIBE_Player::cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7) {
    if (this->playerAI != 0) {
        this->playerAI->buildAI.cancelBuildItem(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
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



void TRIBE_Player::taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5) {
    int* task = (int*)calloc(1, 4);
    *task = param_1;
    static_cast<TRIBE_Command*>(this->world->commands)->command_work(this->id, task, 1, param_2, param_3, param_4, param_5);
    free(task);
}



void TRIBE_Player::taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5) {
    int* piVar1 = (int*)calloc(1, 4);
    *piVar1 = param_1;
    static_cast<TRIBE_Command*>(this->world->commands)->command_work((int)this->id, piVar1, 1, param_2, param_3, param_4, param_5);
    free(piVar1);
}


void TRIBE_Player::setDiplomaticStance(int target_id, int stance) {
    static_cast<TRIBE_Command*>(this->world->commands)->command_relation(this->id, (short)target_id, (short)stance);
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

        if (ruleFile) {
            if (strcmp(ruleFile, randomString) == 0) {
                this->playerAI->logCommonHistory(tplayerDefaultMessage);
            } else {
                this->playerAI->logCommonHistory(tplayerFileMessage, ruleFile);
                this->playerAI->constructionAI.loadConstructionPlan(ruleFile,
                    this->world->map->map_width, this->world->map->map_height, 0, 0, 0);
                goto constructionLoaded;
            }
        } else {
            this->playerAI->logCommonHistory(tplayerDefaultMessage);
        }
        this->playerAI->constructionAI.loadConstructionPlan(tplayerDefaultPlan,
            this->world->map->map_width, this->world->map->map_height, 0, 0, 0);

    constructionLoaded:

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



void TRIBE_Player::notify(int param_1, int param_2, int param_3,
                          long param_4, long param_5, long param_6)
{
    RGE_Static_Object* object;
    switch (param_3) {
    case 0x201:
        if (this->update_count == 0) {
            this->update_count = 20;
            object = this->world->object(param_4);
            if (object != 0) {
                int seed = debug_rand((char*)"C:/msdev/work/age1_x1/tplayer.cpp", 0x920);
                int saved = debug_random_on;
                debug_random_on = 0;
                global_save_debug_random_on3 = saved;
                if (this->world->curr_player == this->id) {
                    RGE_Sound* sound = this->world->sounds[(short)this->attributes[26]];
                    if (sound != 0) sound->play(1);
                    static_cast<TRIBE_Game*>(rge_base_game)->add_notification_loc(
                        (long)object->world_x, (long)object->world_y);
                }
                debug_random_on = saved;
                debug_srand((char*)"C:/msdev/work/age1_x1/tplayer.cpp", 0x931, seed);
            }
        }
        break;
    case 0x20C:
        if (param_4 == 0x267)
            static_cast<TRIBE_Game*>(rge_base_game)->notification(3, this->id, 0, 0, 0);
        break;
    case 0x207:
        static_cast<TRIBE_Game*>(rge_base_game)->notification(1, this->id, 0, 0, 0);
        break;
    case 0x206:
        static_cast<TRIBE_Game*>(rge_base_game)->notification(2, this->id, 0, 0, 0);
        break;
    }
    int seed = debug_rand((char*)"C:/msdev/work/age1_x1/tplayer.cpp", 0x949);
    int saved = debug_random_on;
    global_save_debug_random_on4 = saved;
    debug_random_on = 0;
    if (this->playerAI != 0)
        this->notifyAI(param_1, param_2, param_3, param_4, param_5, param_6);
    debug_random_on = saved;
    debug_srand((char*)"C:/msdev/work/age1_x1/tplayer.cpp", 0x956, seed);
}




void TRIBE_Player::notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6)
{
    RGE_Static_Object* obj = this->world->object(param_1);
    float target_x;
    float target_y;
    if (param_3 != 0x20a && param_3 != 0x72 && param_3 != 0x74) {
        if (obj == 0) return;
        if (obj->unitAI() == 0) return;
    }

    switch (param_3) {
    case 0x1f9:
        if (param_4 != 0x25d) return;
        {
            TacticalAIGroup* group = this->playerAI->tacticalAI.groupUnitIsIn(param_1);
            if (group == 0) return;
            if (group->type() != 0x6b) return;
            this->playerAI->tacticalAI.removeGroup(group->id());
            return;
        }
    case 0x202:
        switch (param_4) {
        case 0x25d:
        case 0x26f:
            if (this->playerAI->informationAI.fullyExploredZone(param_1) != 0 &&
                this->playerAI->informationAI.closestUnexploredTile(param_1, obj->world_x, obj->world_y, &target_x, &target_y) == 1) {
                this->playerAI->tacticalAI.taskExplorer(param_1, target_x, target_y);
                return;
            }
            this->playerAI->tacticalAI.detask(param_1);
            return;
        }
        break;
    case 0x209:
        obj = this->world->object(param_4);
        if (obj != 0) {
            this->playerAI->diplomacyAI.changeStance(obj->owner->id, 0, 10);
            return;
        }
        break;
    case 0x20a:
        ((TribeMainDecisionAIModule*)this->playerAI)->tributeNotify(param_1, param_4, param_5);
        return;
    case 0x72:
    case 0x74:
    case 0x201:
        this->playerAI->tacticalAI.notify(param_1, param_2, param_3, param_4, param_5, param_6);
        return;
    case 0x20d:
        this->playerAI->informationAI.addImportantObject(param_4);
        break;
    }
}


int TRIBE_Player::intelligentCivSelection(int p0, int p1, int p2) { return 0; }




void TRIBE_Player::intelligentBuildListAndRulesSelection(char* buildListName, char* ruleSetName,
                                                         int mapType, int victoryType, int mapSize)
{
    int difficultyLevel;
    int gameDifficulty;
    BuildListPacket packet;
    char tempString[256];

    if (this->playerAI == 0) {
        return;
    }

    gameDifficulty = rge_base_game->difficulty();
    memset(packet.weights, 0, sizeof(packet.weights));

    switch (this->culture) {
    case 1:  this->setupEgyptian(packet.weights, mapType, victoryType, mapSize); break;
    case 2:  this->setupGreek(packet.weights, mapType, victoryType, mapSize); break;
    case 3:  this->setupBabylonian(packet.weights, mapType, victoryType, mapSize); break;
    case 4:  this->setupAssyrian(packet.weights, mapType, victoryType, mapSize); break;
    case 5:  this->setupMinoan(packet.weights, mapType, victoryType, mapSize); break;
    case 6:  this->setupHittite(packet.weights, mapType, victoryType, mapSize); break;
    case 7:  this->setupPhoenician(packet.weights, mapType, victoryType, mapSize); break;
    case 8:  this->setupSumerian(packet.weights, mapType, victoryType, mapSize); break;
    case 9:  this->setupPersian(packet.weights, mapType, victoryType, mapSize); break;
    case 10: this->setupShang(packet.weights, mapType, victoryType, mapSize); break;
    case 11: this->setupYamato(packet.weights, mapType, victoryType, mapSize); break;
    case 12: this->setupChoson(packet.weights, mapType, victoryType, mapSize); break;
    case 13: this->setupRoman(packet.weights, mapType, victoryType, mapSize); break;
    case 14: this->setupCarthaginian(packet.weights, mapType, victoryType, mapSize); break;
    case 15: this->setupPalmyran(packet.weights, mapType, victoryType, mapSize); break;
    case 16: this->setupMacedonian(packet.weights, mapType, victoryType, mapSize); break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 0) {
        int civ = this->culture - 1;
        if (civ == 3 || civ == 0 || civ == 1 || civ == 4 || civ == 8 ||
            civ == 6 || civ == 7 || civ == 10) {
            int c48 = DAT_00886c48;
            int c44 = DAT_00886c44;
            if (mapType == 0) {
                if (c44 > 0) {
                    if (c48 == 0) {
                        packet.weights[(0x0E) - 1] += 300;
                        packet.weights[(0x0F) - 1] += 300;
                    } else {
                        packet.weights[(0x0E) - 1] += 100;
                        packet.weights[(0x0F) - 1] += 100;
                    }
                } else {
                    packet.weights[(0x0E) - 1] = 0;
                    packet.weights[(0x0F) - 1] = 0;
                }
            }
            if (mapType == 1) {
                if (c44 > 0) {
                    if (c48 == 0) {
                        packet.weights[(0x0E) - 1] += 250;
                        packet.weights[(0x0F) - 1] += 250;
                    } else {
                        packet.weights[(0x0E) - 1] += 75;
                        packet.weights[(0x0F) - 1] += 75;
                    }
                } else {
                    packet.weights[(0x0E) - 1] = 0;
                    packet.weights[(0x0F) - 1] = 0;
                }
            }
            if (mapType == 2 || mapType == 6 || mapType == 8) {
                if (c44 > 0) {
                    if (c48 == 0) {
                        packet.weights[(0x0E) - 1] += 200;
                        packet.weights[(0x0F) - 1] += 200;
                    } else {
                        packet.weights[(0x0E) - 1] += 50;
                        packet.weights[(0x0F) - 1] += 50;
                    }
                } else {
                    packet.weights[(0x0E) - 1] = 0;
                    packet.weights[(0x0F) - 1] = 0;
                }
            }
        }
    }

    this->playerAI->strategyAI.setRule(0xC9, 1);

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 0) {
        difficultyLevel = -1;
        packet.mostBuiltUnit = -1;
        this->playerAI->informationAI.loadUnitHistory();
        this->playerAI->informationAI.unitsThatAreMostBuilt(&difficultyLevel, &packet.mostBuiltUnit);
        switch (difficultyLevel) {
        case 0:
            packet.weights[(7) - 1] += 25;
            packet.weights[(8) - 1] += 25;
            break;
        case 1:
            packet.weights[(7) - 1] += 30;
            packet.weights[(8) - 1] += 30;
            break;
        case 2:
            packet.weights[(0x12) - 1] += 20;
            packet.weights[(0x13) - 1] += 20;
            packet.weights[(4) - 1] += 40;
            packet.weights[(5) - 1] += 40;
            break;
        case 3:
            packet.weights[(1) - 1] += 40;
            packet.weights[(2) - 1] += 20;
            packet.weights[(0x14) - 1] += 20;
            packet.weights[(0x15) - 1] += 20;
            packet.weights[(0x12) - 1] -= 60;
            packet.weights[(0x13) - 1] -= 60;
            break;
        case 4:
            packet.weights[(7) - 1] += 15;
            packet.weights[(8) - 1] += 15;
            packet.weights[(0x14) - 1] += 20;
            packet.weights[(0x15) - 1] += 20;
            break;
        case 5:
            packet.weights[(7) - 1] += 15;
            packet.weights[(8) - 1] += 15;
            packet.weights[(1) - 1] += 10;
            packet.weights[(2) - 1] += 10;
            break;
        case 6:
            packet.weights[(7) - 1] += 15;
            packet.weights[(8) - 1] += 15;
            break;
        case 7:
        case 10:
            packet.weights[(0x14) - 1] -= 60;
            packet.weights[(0x15) - 1] -= 60;
            break;
        case 8:
            packet.weights[(0x14) - 1] += 40;
            packet.weights[(0x15) - 1] += 40;
            if (DAT_00886c44 > 0) {
                packet.weights[(0x0E) - 1] += 50;
                packet.weights[(0x0F) - 1] += 50;
            }
            break;
        case 9:
            packet.weights[(0x14) - 1] += 100;
            packet.weights[(0x15) - 1] += 100;
            break;
        }
    }

    difficultyLevel = 0;
    do {
        switch (difficultyLevel) {
        case 0:
            if (0 < (packet.weights[(0x14) - 1])) (packet.weights[(0x14) - 1]) = (packet.weights[(0x14) - 1]) / 3;
            if (0 < (packet.weights[(0x15) - 1])) (packet.weights[(0x15) - 1]) = (packet.weights[(0x15) - 1]) / 3;
            if (0 < (packet.weights[(0x16) - 1])) (packet.weights[(0x16) - 1]) = (packet.weights[(0x16) - 1]) / 3;
            break;
        case 1:
            if (0 < (packet.weights[(7) - 1])) (packet.weights[(7) - 1]) = (packet.weights[(7) - 1]) / 3;
            if (0 < (packet.weights[(8) - 1])) (packet.weights[(8) - 1]) = (packet.weights[(8) - 1]) / 3;
            if (0 < (packet.weights[(9) - 1])) (packet.weights[(9) - 1]) = (packet.weights[(9) - 1]) / 3;
            if (0 < (packet.weights[(0x3C) - 1])) (packet.weights[(0x3C) - 1]) = (packet.weights[(0x3C) - 1]) / 3;
            if (0 < (packet.weights[(0x3B) - 1])) (packet.weights[(0x3B) - 1]) = (packet.weights[(0x3B) - 1]) / 3;
            if (0 < (packet.weights[(0x37) - 1])) (packet.weights[(0x37) - 1]) = (packet.weights[(0x37) - 1]) / 3;
            if (0 < (packet.weights[(0x38) - 1])) (packet.weights[(0x38) - 1]) = (packet.weights[(0x38) - 1]) / 3;
            if (0 < (packet.weights[(0x69) - 1])) (packet.weights[(0x69) - 1]) = (packet.weights[(0x69) - 1]) / 3;
            break;
        case 2:
            if (0 < (packet.weights[(0x11) - 1])) (packet.weights[(0x11) - 1]) = (packet.weights[(0x11) - 1]) / 3;
            if (0 < (packet.weights[(0x32) - 1])) (packet.weights[(0x32) - 1]) = (packet.weights[(0x32) - 1]) / 3;
            if (0 < (packet.weights[(0x6D) - 1])) (packet.weights[(0x6D) - 1]) = (packet.weights[(0x6D) - 1]) / 3;
            break;
        case 3:
            if (0 < (packet.weights[(0x2F) - 1])) (packet.weights[(0x2F) - 1]) = (packet.weights[(0x2F) - 1]) / 3;
            if (0 < (packet.weights[(0x36) - 1])) (packet.weights[(0x36) - 1]) = (packet.weights[(0x36) - 1]) / 3;
            if (0 < (packet.weights[(0x12) - 1])) (packet.weights[(0x12) - 1]) = (packet.weights[(0x12) - 1]) / 3;
            if (0 < (packet.weights[(0x13) - 1])) (packet.weights[(0x13) - 1]) = (packet.weights[(0x13) - 1]) / 3;
            if (0 < (packet.weights[(100) - 1])) (packet.weights[(100) - 1]) = (packet.weights[(100) - 1]) / 3;
            if (0 < (packet.weights[(0x67) - 1])) (packet.weights[(0x67) - 1]) = (packet.weights[(0x67) - 1]) / 3;
            if (0 < (packet.weights[(0x6E) - 1])) (packet.weights[(0x6E) - 1]) = (packet.weights[(0x6E) - 1]) / 3;
            if (0 < (packet.weights[(0x13) - 1])) (packet.weights[(0x13) - 1]) = (packet.weights[(0x13) - 1]) / 3;
            break;
        case 4:
            if (0 < (packet.weights[(4) - 1])) (packet.weights[(4) - 1]) = (packet.weights[(4) - 1]) / 3;
            if (0 < (packet.weights[(5) - 1])) (packet.weights[(5) - 1]) = (packet.weights[(5) - 1]) / 3;
            if (0 < (packet.weights[(6) - 1])) (packet.weights[(6) - 1]) = (packet.weights[(6) - 1]) / 3;
            if (0 < (packet.weights[(10) - 1])) (packet.weights[(10) - 1]) = (packet.weights[(10) - 1]) / 3;
            if (0 < (packet.weights[(0x0B) - 1])) (packet.weights[(0x0B) - 1]) = (packet.weights[(0x0B) - 1]) / 3;
            if (0 < (packet.weights[(0x0C) - 1])) (packet.weights[(0x0C) - 1]) = (packet.weights[(0x0C) - 1]) / 3;
            if (0 < (packet.weights[(0x0D) - 1])) (packet.weights[(0x0D) - 1]) = (packet.weights[(0x0D) - 1]) / 3;
            if (0 < (packet.weights[(0x2B) - 1])) (packet.weights[(0x2B) - 1]) = (packet.weights[(0x2B) - 1]) / 3;
            if (0 < (packet.weights[(0x2D) - 1])) (packet.weights[(0x2D) - 1]) = (packet.weights[(0x2D) - 1]) / 3;
            if (0 < (packet.weights[(0x2E) - 1])) (packet.weights[(0x2E) - 1]) = (packet.weights[(0x2E) - 1]) / 3;
            if (0 < (packet.weights[(0x30) - 1])) (packet.weights[(0x30) - 1]) = (packet.weights[(0x30) - 1]) / 3;
            if (0 < (packet.weights[(0x31) - 1])) (packet.weights[(0x31) - 1]) = (packet.weights[(0x31) - 1]) / 3;
            if (0 < (packet.weights[(0x39) - 1])) (packet.weights[(0x39) - 1]) = (packet.weights[(0x39) - 1]) / 3;
            if (0 < (packet.weights[(0x4B) - 1])) (packet.weights[(0x4B) - 1]) = (packet.weights[(0x4B) - 1]) / 3;
            if (0 < (packet.weights[(99) - 1])) (packet.weights[(99) - 1]) = (packet.weights[(99) - 1]) / 3;
            if (0 < (packet.weights[(0x68) - 1])) (packet.weights[(0x68) - 1]) = (packet.weights[(0x68) - 1]) / 3;
            if (0 < (packet.weights[(0x71) - 1])) (packet.weights[(0x71) - 1]) = (packet.weights[(0x71) - 1]) / 3;
            if (0 < (packet.weights[(0x72) - 1])) (packet.weights[(0x72) - 1]) = (packet.weights[(0x72) - 1]) / 3;
            break;
        case 5:
            if (0 < (packet.weights[(0x2A) - 1])) (packet.weights[(0x2A) - 1]) = (packet.weights[(0x2A) - 1]) / 3;
            if (0 < (packet.weights[(1) - 1])) (packet.weights[(1) - 1]) = (packet.weights[(1) - 1]) / 3;
            if (0 < (packet.weights[(2) - 1])) (packet.weights[(2) - 1]) = (packet.weights[(2) - 1]) / 3;
            if (0 < (packet.weights[(3) - 1])) (packet.weights[(3) - 1]) = (packet.weights[(3) - 1]) / 3;
            if (0 < (packet.weights[(0x2A) - 1])) (packet.weights[(0x2A) - 1]) = (packet.weights[(0x2A) - 1]) / 3;
            if (0 < (packet.weights[(0x33) - 1])) (packet.weights[(0x33) - 1]) = (packet.weights[(0x33) - 1]) / 3;
            if (0 < (packet.weights[(0x34) - 1])) (packet.weights[(0x34) - 1]) = (packet.weights[(0x34) - 1]) / 3;
            if (0 < (packet.weights[(0x49) - 1])) (packet.weights[(0x49) - 1]) = (packet.weights[(0x49) - 1]) / 3;
            if (0 < (packet.weights[(0x4A) - 1])) (packet.weights[(0x4A) - 1]) = (packet.weights[(0x4A) - 1]) / 3;
            if (0 < (packet.weights[(0x33) - 1])) (packet.weights[(0x33) - 1]) = (packet.weights[(0x33) - 1]) / 3;
            if (0 < (packet.weights[(0x34) - 1])) (packet.weights[(0x34) - 1]) = (packet.weights[(0x34) - 1]) / 3;
            if (0 < (packet.weights[(0x51) - 1])) (packet.weights[(0x51) - 1]) = (packet.weights[(0x51) - 1]) / 3;
            if (0 < (packet.weights[(0x52) - 1])) (packet.weights[(0x52) - 1]) = (packet.weights[(0x52) - 1]) / 3;
            if (0 < (packet.weights[(0x53) - 1])) (packet.weights[(0x53) - 1]) = (packet.weights[(0x53) - 1]) / 3;
            if (0 < (packet.weights[(0x6C) - 1])) (packet.weights[(0x6C) - 1]) = (packet.weights[(0x6C) - 1]) / 3;
            break;
        case 6:
            if (0 < (packet.weights[(0x29) - 1])) (packet.weights[(0x29) - 1]) = (packet.weights[(0x29) - 1]) / 3;
            if (0 < (packet.weights[(0x3A) - 1])) (packet.weights[(0x3A) - 1]) = (packet.weights[(0x3A) - 1]) / 3;
            if (0 < (packet.weights[(0x73) - 1])) (packet.weights[(0x73) - 1]) = (packet.weights[(0x73) - 1]) / 3;
            if (0 < (packet.weights[(0x55) - 1])) (packet.weights[(0x55) - 1]) = (packet.weights[(0x55) - 1]) / 3;
            break;
        }
        ++difficultyLevel;
    } while (difficultyLevel < 7);

    int total = 0;
    int* cursor = packet.weights;
    int count = 125;
    do {
        if (*cursor < 0) {
            *cursor = 0;
        }
        ++cursor;
        --count;
    } while (count != 0);
    total = 0;
    cursor = packet.weights;
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
        cumulative += packet.weights[selectionIndex];
        if (cumulative > remainder) {
            selectedBuildList = selectionIndex;
            break;
        }
    }

    rge_base_game->get_string(selectedBuildList + 0x26930, buildListName, 0x100);

    switch (selectedBuildList) {
    case 0x0D: this->playerAI->strategyAI.setRule(0x3B, 4); this->playerAI->strategyAI.setRule(0x3C, 10); ++DAT_00886c34; ++DAT_00886c48; goto selectedCountersDone;
    case 0x0E: this->playerAI->strategyAI.setRule(0x3B, 4); this->playerAI->strategyAI.setRule(0x3C, 10); ++DAT_00886c34; ++DAT_00886c48; goto selectedCountersDone;
    case 0x0F: this->playerAI->strategyAI.setRule(0x3B, 4); this->playerAI->strategyAI.setRule(0x3C, 10); ++DAT_00886c34; ++DAT_00886c48; goto selectedCountersDone;
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
    case 0x3C: ++DAT_00886c48; goto selectedCountersDone;
    case 0x3D: ++DAT_00886c48; goto selectedCountersDone;
    case 0x3E: ++DAT_00886c48; goto selectedCountersDone;
    case 0x3F: ++DAT_00886c48; goto selectedCountersDone;
    case 0x40: ++DAT_00886c48; goto selectedCountersDone;
    case 0x41: ++DAT_00886c48; goto selectedCountersDone;
    case 0x42: ++DAT_00886c48; goto selectedCountersDone;
    case 0x43: ++DAT_00886c48; goto selectedCountersDone;
    case 0x44: ++DAT_00886c48; goto selectedCountersDone;
    case 0x45: ++DAT_00886c48; goto selectedCountersDone;
    case 0x46: ++DAT_00886c48; goto selectedCountersDone;
    case 0x47: ++DAT_00886c48; goto selectedCountersDone;
    case 0x4B: ++DAT_00886c48; goto selectedCountersDone;
    case 0x4C: ++DAT_00886c48; goto selectedCountersDone;
    case 0x4D: ++DAT_00886c48; goto selectedCountersDone;
    case 0x4E: ++DAT_00886c48; goto selectedCountersDone;
    case 0x4F: ++DAT_00886c48; goto selectedCountersDone;
    case 0x53: ++DAT_00886c48; goto selectedCountersDone;
    case 0x55: ++DAT_00886c48; goto selectedCountersDone;
    case 0x56: ++DAT_00886c48; goto selectedCountersDone;
    case 0x57: ++DAT_00886c48; goto selectedCountersDone;
    case 0x58: ++DAT_00886c48; goto selectedCountersDone;
    case 0x59: ++DAT_00886c48; goto selectedCountersDone;
    case 0x5A: ++DAT_00886c48; goto selectedCountersDone;
    case 0x5B: ++DAT_00886c48; goto selectedCountersDone;
    case 0x5C: ++DAT_00886c48; goto selectedCountersDone;
    case 0x5D: ++DAT_00886c48; goto selectedCountersDone;
    case 0x5E: ++DAT_00886c48; goto selectedCountersDone;
    case 0x5F: ++DAT_00886c48; goto selectedCountersDone;
    case 0x60: ++DAT_00886c48; goto selectedCountersDone;
    case 0x61: ++DAT_00886c48; goto selectedCountersDone;
    case 100: ++DAT_00886c48; goto selectedCountersDone;
    case 0x65: ++DAT_00886c48; goto selectedCountersDone;
    case 0x69: ++DAT_00886c48; goto selectedCountersDone;
    case 0x6A: ++DAT_00886c48; goto selectedCountersDone;
    case 0x6E: ++DAT_00886c48; goto selectedCountersDone;
    case 0x6F: ++DAT_00886c48; goto selectedCountersDone;
    case 0x73: ++DAT_00886c48; goto selectedCountersDone;
    case 0x74: ++DAT_00886c48; goto selectedCountersDone;
    case 0x79: ++DAT_00886c48; goto selectedCountersDone;
    case 0x7A: ++DAT_00886c48; goto selectedCountersDone;
    case 0x7B: ++DAT_00886c48; goto selectedCountersDone;
    case 0x7C: ++DAT_00886c48; goto selectedCountersDone;
    case 0x48: ++DAT_00886c44; ++DAT_00886c2c; goto selectedCountersDone;
    case 0x49: ++DAT_00886c44; ++DAT_00886c2c; goto selectedCountersDone;
    case 0x4A: ++DAT_00886c44; ++DAT_00886c28; goto selectedCountersDone;
    case 6: ++DAT_00886c1c; break;
    case 7: ++DAT_00886c1c; break;
    case 8: ++DAT_00886c1c; break;
    case 0x2B: ++DAT_00886c1c; break;
    case 0x36: ++DAT_00886c1c; break;
    case 0x37: ++DAT_00886c1c; break;
    case 0x3A: ++DAT_00886c1c; break;
    case 0x3B: ++DAT_00886c1c; break;
    case 0x68: ++DAT_00886c1c; break;
    case 0: ++DAT_00886c2c; break;
    case 1: ++DAT_00886c2c; break;
    case 2: ++DAT_00886c2c; break;
    case 0x29: ++DAT_00886c2c; break;
    case 0x32: ++DAT_00886c2c; break;
    case 0x33: ++DAT_00886c2c; break;
    case 0x50: ++DAT_00886c2c; break;
    case 0x51: ++DAT_00886c2c; break;
    case 0x52: ++DAT_00886c2c; break;
    case 0x6B: ++DAT_00886c2c; break;
    case 0x10: ++DAT_00886c20; break;
    case 0x31: ++DAT_00886c20; break;
    case 0x6C: ++DAT_00886c20; break;
    case 0x11: ++DAT_00886c24; break;
    case 0x12: ++DAT_00886c24; break;
    case 0x2E: ++DAT_00886c24; break;
    case 0x34: ++DAT_00886c24; break;
    case 0x35: ++DAT_00886c24; break;
    case 99: ++DAT_00886c24; break;
    case 0x66: ++DAT_00886c24; break;
    case 0x6D: ++DAT_00886c24; break;
    case 0x28: ++DAT_00886c30; break;
    case 0x39: ++DAT_00886c30; break;
    case 0x54: ++DAT_00886c30; break;
    case 0x72: ++DAT_00886c30; break;
    case 3: ++DAT_00886c28; break;
    case 4: ++DAT_00886c28; break;
    case 5: ++DAT_00886c28; break;
    case 9: ++DAT_00886c28; break;
    case 10: ++DAT_00886c28; break;
    case 0x0B: ++DAT_00886c28; break;
    case 0x0C: ++DAT_00886c28; break;
    case 0x2A: ++DAT_00886c28; break;
    case 0x2C: ++DAT_00886c28; break;
    case 0x2D: ++DAT_00886c28; break;
    case 0x2F: ++DAT_00886c28; break;
    case 0x30: ++DAT_00886c28; break;
    case 0x38: ++DAT_00886c28; break;
    case 0x62: ++DAT_00886c28; break;
    case 0x67: ++DAT_00886c28; break;
    case 0x70: ++DAT_00886c28; break;
    case 0x71: ++DAT_00886c28; break;
    default:
        ++DAT_00886c28;
        break;
    }
    ++DAT_00886c44;

selectedCountersDone:
    rge_base_game->get_string((int)this->culture + 0x27F6, tempString, 0x100);
    this->playerAI->logCommonHistory(tplayerEmptyName, tempString, (int)this->culture - 1);
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
        ++DAT_00886c3c;
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
        ++DAT_00886c38;
        attackTime = (debug_rand(tplayerSourceName, 0xE64) % 4 + 0x0B) * 60;
        break;
    case 9:
    case 0x38:
        attackTime = (debug_rand(tplayerSourceName, 0xE69) % 2 + 5) * 60;
        ++DAT_00886c38;
        break;
    default:
        ++DAT_00886c40;
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



void TRIBE_Player::setupGreek(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Greeks.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x40] = 100;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x1A] = 60;
            param_1[0x40] = 40;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x1A] = 80;
            param_1[0x40] = 20;
        } else {
            param_1[0x1A] = 100;
        }
    } else {
        int* p1 = param_1;
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

        int p2 = param_2;

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



void TRIBE_Player::setupAssyrian(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Assyrians.");
    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x3c] = 100;
            return;
        }
        if (param_2 == 2 || param_2 == 6) {
            param_1[0x16] = 60;
            param_1[0x3c] = 40;
            return;
        }
        if (param_2 == 5 || param_2 == 8) {
            param_1[0x16] = 80;
            param_1[0x3c] = 20;
            return;
        }
        param_1[0x16] = 100;
        return;
    }

    if (rge_base_game->difficulty() < 1) {
        param_1[0x22] = 100;
        return;
    }

    param_1[3] = 10;
    param_1[7] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0x14] = 10;
    param_1[0x48] = 0x50;
    param_1[0x49] = 0x50;
    param_1[0x4a] = 0x50;
    param_1[0x10] = 0x28;
    param_1[0xb] = 0x28;
    param_1[6] = 0x14;
    param_1[0x13] = 0x14;
    param_1[0x28] = 100;
    param_1[0x29] = 100;
    if (param_2 == 0 || param_2 == 1) {
        param_1[0x4b] = 100;
        param_1[0x4c] = 100;
    } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
        param_1[0x4b] = 50;
        param_1[0x4c] = 50;
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



void TRIBE_Player::setupHittite(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Hittites.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x41] = 100;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x1B] = 60;
            param_1[0x41] = 40;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x1B] = 80;
            param_1[0x41] = 20;
        } else {
            param_1[0x1B] = 100;
        }
    } else {
        param_1[4] = 0x28;
        param_1[0x12] = 0x28;
        param_1[0x10] = 80;
        param_1[0x31] = 100;
        param_1[0x32] = 100;
        param_1[3] = 30;

        param_1[6] = 0x14;
        param_1[9] = 10;
        param_1[10] = 10;
        param_1[11] = 10;
        param_1[0x11] = 0x14;

        if (param_2 == 0 || param_2 == 1) {
            param_1[0x57] = 0xA0;
            param_1[0] = 0x14;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x57] = 0x50;
            param_1[0] = 10;
        }
    }
}



void TRIBE_Player::setupPhoenician(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Phoenicians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x44] = 100;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x1E] = 60;
            param_1[0x44] = 40;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x1E] = 80;
            param_1[0x44] = 20;
        } else {
            param_1[0x1E] = 100;
        }
    } else {
        param_1[3] = 10;
        param_1[4] = 10;
        param_1[9] = 10;
        param_1[10] = 10;
        param_1[11] = 10;
        param_1[0x11] = 70;
        param_1[0x12] = 70;
        param_1[0] = 20;
        param_1[6] = 20;
        param_1[0x13] = 20;
        param_1[1] = 40;
        param_1[0x14] = 30;
        param_1[0x35] = 100;

        if (param_2 == 0 || param_2 == 1) {
            param_1[0x5C] = 200;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x5C] = 100;
        }
    }
}



void TRIBE_Player::setupSumerian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Sumerians.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() == 1) {
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



void TRIBE_Player::setupYamato(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Yamato.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x47] = 100;
            return;
        }
        if (param_2 == 2 || param_2 == 6) {
            param_1[0x21] = 60;
            param_1[0x47] = 40;
            return;
        }
        if (param_2 == 5 || param_2 == 8) {
            param_1[0x21] = 80;
            param_1[0x47] = 20;
            return;
        }
        param_1[0x21] = 100;
        return;
    } else if (rge_base_game->difficulty() < 1) {
        param_1[0x27] = 100;
    } else {
        param_1[3] = 10;
        param_1[4] = 10;
        param_1[9] = 10;
        param_1[10] = 10;
        param_1[6] = 50;
        param_1[7] = 50;
        param_1[0] = 20;
        param_1[1] = 20;
        param_1[0x10] = 40;
        param_1[0x0B] = 20;
        param_1[0x3B] = 100;

        if (param_2 == 0 || param_2 == 1) {
            param_1[0x60] = 200;
            param_1[0x61] = 200;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x60] = 100;
            param_1[0x61] = 100;
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



void TRIBE_Player::setupRoman(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Roman.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x7C] = 0x64;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x78] = 0x3C;
            param_1[0x7C] = 0x28;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x78] = 0x50;
            param_1[0x7C] = 0x14;
        } else {
            param_1[0x78] = 0x64;
        }
    } else {
        param_1[0] = 0x0A;
        param_1[6] = 0x0A;
        param_1[9] = 0x0A;
        param_1[10] = 0x0A;
        param_1[0x13] = 0x0A;
        param_1[0x14] = 0x0A;
        param_1[3] = 0x14;
        param_1[4] = 0x14;
        param_1[0x0B] = 0x50;
        param_1[0x70] = 0x64;
        param_1[0x71] = 0x3C;
        param_1[0x72] = 0x50;

        if (param_2 == 0 || param_2 == 1) {
            param_1[0x73] = 0xC8;
            param_1[0x74] = 0xC8;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x73] = 0x64;
            param_1[0x74] = 0x64;
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



void TRIBE_Player::setupPalmyran(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Palmyran.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x7B] = 0x64;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x77] = 0x3C;
            param_1[0x7B] = 0x28;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x77] = 0x50;
            param_1[0x7B] = 0x14;
        } else {
            param_1[0x77] = 0x64;
        }
    } else {
        param_1[3] = 0x28;
        param_1[6] = 0x28;
        param_1[0] = 0x1E;
        param_1[7] = 0x0A;
        param_1[9] = 0x0A;
        param_1[10] = 0x0A;
        param_1[11] = 0x0A;
        param_1[1] = 0x1E;
        param_1[0x6B] = 0x50;
        param_1[0x6C] = 0x50;
        param_1[0x6D] = 0x50;
        param_1[0x10] = 0x3C;
        param_1[4] = 0x14;
        param_1[0x11] = 0x3C;

        if (param_2 == 0 || param_2 == 1) {
            param_1[0x6E] = 0xC8;
            param_1[0x6F] = 0xC8;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x6E] = 0x64;
            param_1[0x6F] = 0x64;
        }
    }
}



void TRIBE_Player::setupMacedonian(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Macedonian.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x7A] = 100;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x76] = 60;
            param_1[0x7A] = 40;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x76] = 80;
            param_1[0x7A] = 20;
        } else {
            param_1[0x76] = 100;
        }
    } else {
        param_1[3] = 0x28;
        param_1[4] = 0x28;
        param_1[0] = 0x0A;
        param_1[6] = 0x1E;
        param_1[7] = 0x1E;
        param_1[0x11] = 0x1E;
        param_1[0x68] = 0x50;
        param_1[0x66] = 0x50;
        param_1[0x67] = 0x50;
        param_1[1] = 0x0A;
        param_1[0x10] = 0x14;

        if (param_2 == 0 || param_2 == 1) {
            param_1[0x69] = 0xC8;
            param_1[0x6A] = 0xC8;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x69] = 100;
            param_1[0x6A] = 100;
        }
    }
}



void TRIBE_Player::logStatus(FILE* f, int verbose)
{
    char tempString[256];
    if (f == 0)
        return;

    fprintf(f, "Player %d:\n", (int)this->id);
    if (verbose == 1) {
        rge_base_game->get_string((int)this->id + 0x27f6, tempString, 0x100);
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
    fprintf(f, "  Population:      %d.\n", (int)this->attributes[3]);
    fprintf(f, "  Kills:           %d.\n", this->victory_conditions->get_attribute_id(0));
    fprintf(f, "  Kill Ratio:      %d.\n", this->victory_conditions->get_attribute_id(2));
    fprintf(f, "  Razings:         %d.\n", this->victory_conditions->get_attribute_id(1));
    fprintf(f, "  Food:            %d.\n", (int)this->attributes[0]);
    fprintf(f, "  Gold:            %d.\n", (int)this->attributes[1]);
    fprintf(f, "  Stone:           %d.\n", (int)this->attributes[2]);
    fprintf(f, "  Wood:            %d.\n", (int)this->attributes[4]);
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
        sprintf(buffer, "%4.f", (double)(attributes[19] - attributes[11]));
        break;
    case 2:
        sprintf(buffer, "%4.f", (double)attributes[20]);
        break;
    case 3:
        sprintf(buffer, "%4.f", (double)attributes[11]);
        break;
    case 4:
        sprintf(buffer, "%5.f", (double)attributes[3]);
        break;
    case 5: {
        float pct = this->visible->percentExplored() * 100.0f;
        sprintf(buffer, "%3.f%%", (double)pct);
        break;
    }
    case 6:
        sprintf(buffer, "%4.f", (double)attributes[19]);
        break;
    case 7:
        sprintf(buffer, "%4.f/%4.f/%4.f",
            (double)attributes[7],
            (double)attributes[13],
            (double)attributes[14]);
        break;
    case 8:
        sprintf(buffer, "%4.f", (double)attributes[21]);
        break;
    }
}

void TRIBE_Player::load_victory(int param_1, long* param_2, unsigned char param_3) {
    TRIBE_Victory_Conditions* v = new TRIBE_Victory_Conditions(this, param_1, param_2, param_3);
    if (v == 0) {
        v = 0;
    }
    this->victory_conditions = v;
}


void TRIBE_Player::new_victory(void) {
    TRIBE_Victory_Conditions* v = new TRIBE_Victory_Conditions(this);
    this->victory_conditions = v;
}


void TRIBE_Player::add_attribute_num(short param_1, float param_2, unsigned char param_3) {
    if ((param_1 == 3) && (param_3 != 0)) {
        float addend = param_2;
        float dest = this->attributes[49];
        this->attributes[49] = addend + dest;
    }
    if (param_1 == 0x32) {
        this->allied_LOS_Enable = 1;
        this->world->update_mutual_allies();
    }
    RGE_Player::add_attribute_num(param_1, param_2, param_3);
}


extern unsigned long tribe_group_properties[];
extern int tribe_group_properties_num;

void TRIBE_Player::analyize_selected_objects()
{
    int i = 0;
    DAT_0086bc8c = 0;
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
                        ++DAT_0086bc8c;
                        DAT_0086bc88 = (*p)->id;
                        if ((*p)->attribute_amount_held >= DAT_0057682c) {
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
    return 0;
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
                        unsigned char param_3, char* param_4, unsigned char param_5)
    : TRIBE_Player(world, player, param_3, param_4, param_5, 0, 1, 0, 0, 0)
{
    this->type = 2;
    this->update_time = 0.0f;
    this->update_nature = 0x1D;
    this->animal_max = 0;
    this->last_count = 0;
}


void TRIBE_Gaia::save(int param_1) {
    TRIBE_Player::save(param_1);

    rge_write(param_1, &this->update_time, 4);
    rge_write(param_1, &this->update_nature, 4);
    rge_write(param_1, &this->animal_max, 4);
    rge_write(param_1, &this->last_count, 4);
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


void TRIBE_Player::scenario_postload(int param_1, long* param_2, float param_3) {
    RGE_Player::scenario_postload(param_1, param_2, param_3);
    if (0.0 < this->attributes[0]) {
        this->mutualExploredMask = 1;
        this->world->update_mutual_allies();
    }
}
