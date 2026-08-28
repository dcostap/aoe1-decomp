// PDB source module: C:\\msdev\\work\\age1_x1\\stat_obj.cpp.
// Definitions follow the original source order.
#include "../include/act_obj.h"
#include "../include/asp_list.h"
#include "../include/basegame.h"
#include "../include/color.h"
#include "../include/dpl_obj.h"
#include "../include/drawarea.h"
#include "../include/infmap.h"
#include "../include/m_co_obj.h"
#include "../include/m_s_obj.h"
#include "../include/map.h"
#include "../include/obj_list.h"
#include "../include/pathsys.h"
#include "../include/panel.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"
#include "../include/Shape.h"
#include "../include/sound.h"
#include "../include/sprite.h"
#include "../include/stat_obj.h"
#include "../include/unit_ai_module.h"
#include "../include/victory.h"
#include "../include/visible.h"
#include "../include/vis_unit.h"
#include "../include/view.h"
#include "../include/world.h"
#include "../include/zone_map.h"
#include "../include/game_globals.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

extern int startLoggingAI;
extern int logDebugID;
extern FILE* debugOut;
extern char STR_STAT_OBJ[];

extern "C" {
int __cdecl debug_rand(char*, int);
void __cdecl debug_srand(char*, int, int);
}

// 004C1100 RGE_Static_Object::RGE_Static_Object




RGE_Static_Object::RGE_Static_Object(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z, int do_setup)
    : sprite(0), old_sprite(0)
{
    this->unitAIValue = 0;
    this->groupCommanderValue = -1;
    this->zoneMapIndex = -1;
    this->groupRangeValue = 5.0f;
    this->inObstructionMapValue = 0;
    this->lastInObstructionMapValue = 0;
    this->underAttackValue = 0;
    this->player_object_node = 0;
    if (do_setup != 0) {
        this->setup(master, player, x, y, z);
    }
}


// 004C11E0 RGE_Static_Object::RGE_Static_Object




RGE_Static_Object::RGE_Static_Object(int id, RGE_Game_World* world, int do_setup)
    : sprite(0), old_sprite(0)
{
    this->unitAIValue = 0;
    this->groupCommanderValue = -1;
    this->zoneMapIndex = -1;
    this->groupRangeValue = 5.0f;
    this->inObstructionMapValue = 0;
    this->lastInObstructionMapValue = 0;
    this->underAttackValue = 0;
    this->player_object_node = 0;
    if (do_setup != 0) {
        this->setup(id, world);
    }
}



// 004C1290 RGE_Static_Object::~RGE_Static_Object


RGE_Static_Object::~RGE_Static_Object() {
    this->remove_visible_resource();

    if (this->owner != 0) {
        if (this->object_state < 3) {
            this->take_attribute_from_owner();
        }
        if (this->object_state < 7) {
            this->owner->victory_conditions->update_for_object(this);
        }
    }

    if (this->sprite_list != 0) {
        delete this->sprite_list;
        this->sprite_list = 0;
    }

    if (this->owner != 0) {
        if (this->selected & 1) {
            this->owner->unselect_one_object(this);
        }

        this->owner->removeObject(this, this->sleep_flag, this->dopple_flag,
                                  this->player_object_node);

        this->owner = 0;
    }

    if (this->tile != 0) {
        this->tile->objects.remove_node(this, 0);
        this->tile = 0;
    }

    if (this->master_obj != 0) {
        if (this->master_obj->radius_z > 0.0) {
            this->removeFromObstructionMap(2);
        }
    }

    if (this->inside_obj != 0) {
        this->inside_obj->objects->remove_node(this, 0);
        this->inside_obj = 0;
    }

    if (this->objects != 0) {
        RGE_Object_Node* node = this->objects->list;
        while (node != 0) {
            RGE_Object_Node* next = node->next;
            node->node->release_from_holder();
            node = next;
        }

        RGE_Object_List* list = this->objects;
        if (list != 0) {
            delete list;
        }
    }

    if (this->unitAIValue != 0) {
        delete this->unitAIValue;
        this->unitAIValue = 0;
    }
}


// 004C1420 RGE_Static_Object::recycle_in_to_game



void RGE_Static_Object::recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z)
{
    this->old_sprite = 0;
    this->unitAIValue = 0;
    this->underAttackValue = 0;
    this->sprite = 0;
    this->groupCommanderValue = -1;
    this->groupRangeValue = 5.0f;
    this->owner = player;
    this->master_obj = master;
    this->tile = 0;
    this->inside_obj = 0;

    this->hp = (float)(int)master->hp;
    this->sleep_flag = (this->hp > 0.0f);
    this->dopple_flag = (master->master_type == 0x19);

    this->facet = 0;
    this->world_x = -999.0f;
    this->world_y = -999.0f;
    this->world_z = 0.0f;
    this->screen_x_offset = 0;
    this->screen_y_offset = 0;
    this->shadow_x_offset = 0;
    this->shadow_y_offset = 0;
    this->selected = 0;
    this->selected_group = 0;
    this->worker_num = 0;
    this->object_state = 2;
    this->curr_damage_percent = 0;
    this->goto_sleep_flag = 0;
    this->player_object_node = 0;

    this->get_starting_attribute();
    this->give_attribute_to_owner();

    this->new_sprite(this->master_obj->sprite);
    this->world_x = x;
    this->world_y = y;
    this->world_z = z;
    this->old_sprite = 0;
    this->teleport(x, y, z);

    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);

    int seed = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x183);
    int old_debug = debug_random_on;
    debug_random_on = 0;

    RGE_Sound* sound = this->master_obj->created_sound;
    if (sound != 0 && this->owner->id == this->owner->world->curr_player) {
        sound->play(1);
    }

    debug_random_on = old_debug;
    debug_srand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x18D, seed);
}


// 004C1590 RGE_Static_Object::recycle_out_of_game


void RGE_Static_Object::recycle_out_of_game() {
    if (this->master_obj->recyclable != 0 &&
        this->owner->world->recycle_object_out_of_game(
            this->master_obj->master_type, this) != 0) {
        if (this->object_state < 3) {
            this->take_attribute_from_owner();
        }
        if (this->object_state < 7) {
            this->owner->victory_conditions->update_for_object(this);
        }
        if (this->sprite_list != 0) {
            this->sprite_list->delete_list();
        }
        if (this->owner != 0) {
            if ((this->selected & 1) != 0) {
                this->owner->unselect_one_object(this);
            }
            this->owner->removeObject(this, this->sleep_flag,
                                      this->dopple_flag,
                                      this->player_object_node);
            this->owner = 0;
        }
        if (this->tile != 0) {
            this->tile->objects.remove_node(this, 0);
            this->tile = 0;
        }
        if (this->inside_obj != 0) {
            this->inside_obj->objects->remove_node(this, 0);
            this->inside_obj = 0;
        }
        if (this->objects != 0) {
            RGE_Object_Node* node = this->objects->list;
            while (node != 0) {
                RGE_Object_Node* next = node->next;
                node->node->exit_obj();
                node = next;
            }
        }
        if (this->unitAIValue != 0) {
            delete this->unitAIValue;
            this->unitAIValue = 0;
        }
        if (this->master_obj != 0 && 0.0 < this->master_obj->radius_z) {
            this->removeFromObstructionMap(2);
        }
        this->master_obj = 0;
    } else {
        delete this;
    }
}


// 004C16B0 RGE_Static_Object::setup
// BINARY NOTE: setup is a protected virtual member in the shipped symbol.
// BINARY NOTE: setup is a protected virtual member in the shipped symbol.



int RGE_Static_Object::setup(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z)
{
    int old_debug;
    int seed;
    this->type = 10;
    this->owner = player;
    this->master_obj = master;
    this->tile = 0;
    this->inside_obj = 0;
    this->objects = this->create_object_list();

    this->hp = (float)(int)this->master_obj->hp;
    this->sleep_flag = (this->hp > 0.0f);
    this->dopple_flag = (this->master_obj->master_type == 0x19);

    this->facet = 0;
    this->world_x = -999.0f;
    this->world_y = -999.0f;
    this->world_z = 0.0f;
    this->screen_x_offset = 0;
    this->screen_y_offset = 0;
    this->shadow_x_offset = 0;
    this->shadow_y_offset = 0;
    this->selected = 0;
    this->selected_group = 0;
    this->worker_num = 0;
    this->object_state = 2;
    this->curr_damage_percent = 0;
    this->goto_sleep_flag = 0;
    this->get_starting_attribute();
    this->give_attribute_to_owner();

    if (this->master_obj->recyclable != 0) {
        this->id = this->owner->world->get_next_reusable_object_id();
    } else {
        this->id = this->owner->world->get_next_object_id();
    }
    this->sprite_list = this->create_sprite_list();
    this->new_sprite(this->master_obj->sprite);

    this->world_x = x;
    this->world_y = y;
    this->world_z = z;
    this->old_sprite = 0;
    this->teleport(x, y, z);

    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);

    seed = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x22A);
    old_debug = debug_random_on;
    debug_random_on = 0;
    if (this->master_obj->created_sound != 0 && this->owner->id == this->owner->world->curr_player) {
        this->master_obj->created_sound->play(1);
    }
    debug_random_on = old_debug;
    debug_srand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x235, seed);
    return 1;
}


// 004C1840 RGE_Static_Object::setup
// BINARY NOTE: this loader entry is a protected virtual setup member.


int RGE_Static_Object::setup(int file, RGE_Game_World* world) {
    int save_file = file;
    int long_val;
    int byte_val;
    int numberUnits;
    int tempInt;
    int tempInt_fffffff8;
    int local_4;
    short index;

    this->type = 10;
    rge_read(save_file, &long_val, 1);
    this->owner = world->players[long_val & 0xff];

    // BINARY NOTE: The shipped loader reuses the incoming file home for this index.
    rge_read(save_file, &index, 2);
    this->master_obj = this->owner->master_objects[index];

    rge_read(save_file, &index, 2);
    if (index >= 0) {
        this->sprite = world->sprites[index];
    } else {
        this->sprite = 0;
    }

    this->old_sprite = 0;
    rge_read(save_file, &tempInt, 4);
    if (tempInt == -1) {
        this->inside_obj = 0;
    } else {
        this->inside_obj = world->object(tempInt);
    }

    rge_read(save_file, &this->hp, 4);
    rge_read(save_file, &this->object_state, 1);
    rge_read(save_file, &this->sleep_flag, 1);
    if (save_game_version >= 7.09f) {
        rge_read(save_file, &this->dopple_flag, 1);
    }
    rge_read(save_file, &this->goto_sleep_flag, 1);
    rge_read(save_file, &this->id, 4);
    rge_read(save_file, &this->facet, 1);
    rge_read(save_file, &this->world_x, 4);
    rge_read(save_file, &this->world_y, 4);
    rge_read(save_file, &this->world_z, 4);
    rge_read(save_file, &this->screen_x_offset, 2);
    rge_read(save_file, &this->screen_y_offset, 2);
    rge_read(save_file, &this->shadow_x_offset, 2);
    rge_read(save_file, &this->shadow_y_offset, 2);
    rge_read(save_file, &this->selected_group, 1);
    rge_read(save_file, &this->attribute_type_held, 2);
    rge_read(save_file, &this->attribute_amount_held, 4);
    rge_read(save_file, &this->worker_num, 1);
    rge_read(save_file, &this->curr_damage_percent, 1);
    rge_read(save_file, &this->underAttackValue, 1);
    this->tile = 0;
    rge_read(save_file, &this->groupCommanderValue, 4);
    rge_read(save_file, &this->groupRangeValue, 4);

    if (save_game_version == 6.991f) {
        rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &local_4, 4);
        rge_read(save_file, &tempInt_fffffff8, 4);
        rge_read(save_file, &tempInt_fffffff8, 4);
    }

    rge_read(save_file, &byte_val, 4);
    numberUnits = 0;
    if (0 < byte_val) {
        do {
            rge_read(save_file, &tempInt_fffffff8, 4);
            // BINARY NOTE: The duplicate scan checks count before capacity.
            int number = this->groupMembers.numberValue;
            int index = 0;
            local_4 = tempInt_fffffff8;
            for (; index < number && index < this->groupMembers.maximumSizeValue;
                 index = index + 1) {
                if (this->groupMembers.value[index] == tempInt_fffffff8) {
                    goto group_member_found;
                }
            }
            if (number > this->groupMembers.maximumSizeValue - 1) {
                int newNumber = number + 1;
                int* values = new int[newNumber];
                if (values != 0) {
                    index = 0;
                    for (; index < this->groupMembers.maximumSizeValue && index < newNumber;
                         index = index + 1) {
                        values[index] = this->groupMembers.value[index];
                    }
                    delete[] this->groupMembers.value;
                    this->groupMembers.value = values;
                    this->groupMembers.maximumSizeValue = newNumber;
                }
            }
            this->groupMembers.value[this->groupMembers.numberValue] = local_4;
            this->groupMembers.numberValue = this->groupMembers.numberValue + 1;
        group_member_found:
            numberUnits = numberUnits + 1;
        } while (numberUnits < byte_val);
    }

    rge_read(save_file, &byte_val, 4);
    numberUnits = 0;
    if (0 < byte_val) {
        do {
            rge_read(save_file, &local_4, 4);
            int number = this->pathingGroupMembers.numberValue;
            int index = 0;
            tempInt_fffffff8 = local_4;
            for (; index < number && index < this->pathingGroupMembers.maximumSizeValue;
                 index = index + 1) {
                if (this->pathingGroupMembers.value[index] == local_4) {
                    goto pathing_member_found;
                }
            }
            if (number > this->pathingGroupMembers.maximumSizeValue - 1) {
                int newNumber = number + 1;
                int* values = new int[newNumber];
                if (values != 0) {
                    index = 0;
                    for (; index < this->pathingGroupMembers.maximumSizeValue && index < newNumber;
                         index = index + 1) {
                        values[index] = this->pathingGroupMembers.value[index];
                    }
                    delete[] this->pathingGroupMembers.value;
                    this->pathingGroupMembers.value = values;
                    this->pathingGroupMembers.maximumSizeValue = newNumber;
                }
            }
            this->pathingGroupMembers.value[this->pathingGroupMembers.numberValue] = tempInt_fffffff8;
            this->pathingGroupMembers.numberValue = this->pathingGroupMembers.numberValue + 1;
        pathing_member_found:
            numberUnits = numberUnits + 1;
        } while (numberUnits < byte_val);
    }

    this->sprite_list = this->create_sprite_list();
    this->sprite_list->load(save_file, world->sprites);
    this->owner->world->addObject(this);

    if (this->sleep_flag != 0) {
        this->owner->sleeping_objects->add_node(this);
    } else if (this->dopple_flag != 0) {
        this->owner->doppleganger_objects->add_node(this);
    } else {
        this->owner->objects->add_node(this);
    }

    this->objects = this->create_object_list();
    this->selected = 0;
    return 1;
}


// 004C1CF0 RGE_Static_Object::change_unique_id

void RGE_Static_Object::change_unique_id() {
    this->owner->removeObject(this, this->sleep_flag, this->dopple_flag, this->player_object_node);

    if (this->master_obj->recyclable != 0) {
        this->id = this->owner->world->get_next_reusable_object_id();
    } else {
        this->id = this->owner->world->get_next_object_id();
    }
    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);
}


// 004C1D60 RGE_Static_Object::create_object_list

RGE_Object_List* RGE_Static_Object::create_object_list(void) {
    return new RGE_Object_List;
}


// 004C1DC0 RGE_Static_Object::create_sprite_list

RGE_Active_Sprite_List* RGE_Static_Object::create_sprite_list(void) {
    return new RGE_Active_Sprite_List(this);
}


// 004C1E20 RGE_Static_Object::get_starting_attribute
void RGE_Static_Object::get_starting_attribute()
{
    RGE_Master_Static_Object* master;
    unsigned char* attr_flag;
    short* attr_type;
    float* attr_amount;
    int count;

    master = this->master_obj;
    this->attribute_type_held = -1;
    this->attribute_amount_held = 0;
    attr_flag = master->attribute_flag;
    attr_amount = master->attribute_amount_held;
    attr_type = master->attribute_type_held;
    count = 3;
    do {
        if (*attr_flag == 0 && *attr_type != -1) {
            this->attribute_type_held = *attr_type;
            this->attribute_amount_held = *attr_amount;
        }
        attr_type++;
        attr_amount++;
        attr_flag++;
        count--;
    } while (count != 0);
}


// 004C1E70 RGE_Static_Object::give_attribute_to_owner


void RGE_Static_Object::give_attribute_to_owner(void) {
    for (int i = 0; i < 3; ++i) {
        RGE_Master_Static_Object* master = this->master_obj;
        unsigned char status = master->attribute_flag[i];
        if (status >= 1 && status <= 2) {
            short attr_id = master->attribute_type_held[i];
            if (attr_id >= 0) {
                float value = master->attribute_amount_held[i];
                this->owner->add_attribute_num(attr_id, value, 0);
            }
        }
    }
}


// 004C1ED0 RGE_Static_Object::take_attribute_from_owner


void RGE_Static_Object::take_attribute_from_owner(void) {
    for (int i = 0; i < 3; ++i) {
        RGE_Master_Static_Object* master = this->master_obj;
        if (master->attribute_flag[i] == 2) {
            short attr = master->attribute_type_held[i];
            if (attr >= 0) {
                this->owner->add_attribute_num(
                    attr, -master->attribute_amount_held[i], 0);
            }
        }
    }
}


// 004C1F30 RGE_Static_Object::draw



void RGE_Static_Object::draw(TDrawArea* area, short x, short y,
                             RGE_Color_Table* color_table)
{
    SDI_Object_ID = this->id;

    if (this->type == 0x19) {
        RGE_Doppleganger_Object* dopple =
            static_cast<RGE_Doppleganger_Object*>(this);

        if ((dopple->CantSeeBits & (1 << this->owner->world->curr_player)) != 0) {
            SDI_Object_ID = -1;
            return;
        }

        if (dopple->doppled_object != 0) {
            SDI_Object_ID = dopple->doppled_object->id;
        } else {
            SDI_Object_ID = -1;
        }
    }

    if (this->tile != 0 && this->object_state < 7) {
        if (this->selected != 0 ||
            rge_base_game->outline_type == 3 ||
            ((this->master_obj->draw_flag & 1) == 1 &&
             rge_base_game->prog_mode == 7)) {
            this->capture_frame(area, x, y);
        }

        SDI_Draw_Line = (int)y + (int)this->shadow_y_offset;
        this->sprite_list->draw(
            this->facet,
            this->screen_x_offset + x,
            this->screen_y_offset + y,
            this->shadow_x_offset + x,
            y + this->shadow_y_offset,
            color_table,
            area);
    }

    SDI_Object_ID = -1;
}


// 004C2030 RGE_Static_Object::shadow_draw
void RGE_Static_Object::shadow_draw(TDrawArea* param_1, short param_2, short param_3, unsigned char param_4) {
    if (this->tile != 0 && this->object_state < 7) {
        this->sprite_list->shadow_draw(this->facet, this->shadow_x_offset + param_2, this->shadow_y_offset + param_3, this->owner->color_table, param_1, param_4);
    }
}


// 004C2080 RGE_Static_Object::normal_draw


void RGE_Static_Object::normal_draw(TDrawArea* param_1, short param_2, short param_3)
{
    if (this->tile == 0) {
        return;
    }
    if ((unsigned char)this->object_state >= 7) {
        return;
    }

    unsigned char isSelected;
    if (this->selected != 0 || rge_base_game->outline_type == 3) {
        isSelected = 1;
    } else {
        isSelected = 0;
    }

    if (isSelected) {
        this->draw_back_frame(param_1, param_2, param_3);
    }

    this->sprite_list->normal_draw(
        this->facet,
        (short)((int)(short)this->screen_x_offset + (int)param_2),
        (short)((int)(short)this->screen_y_offset + (int)param_3),
        this->owner->color_table,
        param_1
    );

    if (isSelected) {
        this->draw_front_frame(param_1, param_2, param_3);
    }
}


// 004C2110 RGE_Static_Object::draw_front_frame


void RGE_Static_Object::draw_front_frame(TDrawArea* param_1, short param_2, short param_3) {
    int gm = rge_base_game->game_mode;
    if (gm == 1) { this->draw_frame_3d_cube_front(param_1, param_2, param_3); return; }
    unsigned int ot = rge_base_game->outline_type;
    if (ot > 3) return;
    switch (ot) {
    case 0: this->draw_frame(param_1, param_2, param_3); return;
    case 2: case 3: this->draw_frame_3d_square_front(param_1,param_2,param_3); return;
    case 1: this->draw_frame_3d_cube_front(param_1,param_2,param_3); return;
    }
}


// 004C21A0 RGE_Static_Object::draw_back_frame



void RGE_Static_Object::draw_back_frame(TDrawArea* area, short x, short y) {
    if (rge_base_game->game_mode == 1) {
        this->draw_frame_3d_cube_back(area, x, y);
        return;
    }

    switch (rge_base_game->outline_type) {
    case 0:
        return;
    case 1:
        this->draw_frame_3d_cube_back(area, x, y);
        return;
    case 2:
    case 3:
        this->draw_frame_3d_square_back(area, x, y);
        return;
    default:
        return;
    }
}


// 004C2220 RGE_Static_Object::capture_frame


void RGE_Static_Object::capture_frame(TDrawArea* area, short x, short y) {
    if (SDI_Capture_Info) {
        if (rge_base_game->game_mode == 1) {
            this->capture_frame_3d_cube(area, x, y);
            return;
        }

        switch (rge_base_game->outline_type) {
        case 0:
            this->capture_square_frame(area, x, y);
            return;
        case 1:
            this->capture_frame_3d_cube(area, x, y);
            return;
        case 2:
        case 3:
            this->capture_frame_3d_square(area, x, y);
            return;
        }
    }
}


// 004C22C0 RGE_Static_Object::capture_square_frame
// - ORIGINAL BUG: the original first AddGDINode setup reuses screen_y_offset




void RGE_Static_Object::capture_square_frame(TDrawArea* render_area,
                                             short x, short y)
{
    short min_y;
    short min_x;
    int y0;
    short max_y;
    short max_x;

    if (this->sprite != 0 && this->sprite_list != 0) {
        this->sprite_list->get_facetindex(this->sprite, this->facet);

        if (this->get_frame(min_x, min_y, max_x, max_y) != 0) {
            int x1 = x + min_x - 1 + this->screen_x_offset;
            int y1 = y + min_y - 1 + this->screen_y_offset;
            y0 = y + max_y + 1 + this->screen_y_offset;
            int y_line = y0 + this->screen_y_offset + 1;
            int x2 = max_x + this->screen_y_offset +
                     this->screen_x_offset + 1;

            SDI_List->AddGDINode(4, y_line, x1, y1, x2, y_line,
                                 0, 0, 0, 0, 10, 0xff, SDI_Object_ID);

            if (this->object_state <= 2) {
                int health = (int)this->hp;
                if (health < 1) {
                    health = 0;
                }

                int max_health = (int)this->master_obj->hp;
                if (max_health > 0) {
                    int health_right = (health * 25) / max_health + x1;
                    if (health_right >= x1 + 26) {
                        health_right = x1 + 25;
                    }

                    SDI_List->AddGDINode(2, y_line, x1, y1 - 6, x1 + 26,
                                         y1 - 1, health_right, 0,
                                         health_right + 1, 0, 20, 0xff,
                                         SDI_Object_ID);
                }
            }
        }
    }
}


// 004C23F0 RGE_Static_Object::capture_frame_3d_cube

void RGE_Static_Object::capture_frame_3d_cube(TDrawArea* p0, short p1, short p2) {}


// 004C2400 RGE_Static_Object::capture_frame_3d_square



void RGE_Static_Object::capture_frame_3d_square(
    TDrawArea*, short param_3, short param_4)
{
    RGE_Master_Static_Object* pRVar1;
    RGE_Map* this_00;
    TShape* pTVar2;
    int iVar3;
    int iVar4;
    int* piVar5;
    unsigned int uVar6;
    int iVar7;
    short sVar8;
    int sVar9;
    unsigned char draw_color;
    unsigned char y2;
    float x3_radius;
    float ry1;
    float radius_y;
    int tot_hp;
    float radius_z;
    float neg_x3;
    short x0;
    short y0;
    short corner1_x;
    short corner1_y;
    short corner2_x;
    short corner2_y;
    short corner3_x;
    short corner3_y;
    short corner4_x;
    short corner4_y;
    short health_x;
    short health_y;
    int idv[6];
    RGE_Base_Game* base;
    unsigned char outline_type;
    int digit_x;

    base = rge_base_game;
    outline_type = base->outline_type;
    this_00 = this->owner->world->map;
    pRVar1 = this->master_obj;
    if (outline_type == 3) {
        x3_radius = pRVar1->radius_x;
        radius_y = pRVar1->radius_y;
        radius_z = pRVar1->radius_z;
    } else {
        x3_radius = pRVar1->outline_radius_x;
        radius_y = pRVar1->outline_radius_y;
        radius_z = pRVar1->outline_radius_z;
    }
    if (startLoggingAI == 1 && this->groupCommanderValue == this->id &&
        this->id >= 0) {
        y2 = 0;
    } else if ((this->selected & 1) == 0) {
        if (outline_type == 3) {
            y2 = 0x74;
        } else if ((pRVar1->draw_flag & 1) == 1 &&
                   base->prog_mode == 7) {
            y2 = pRVar1->draw_color;
        } else {
            y2 = 0xFF;
        }
    } else {
        y2 = 0xFF;
    }
    if ((this->selected & 2) != 0) {
        y2 = 0x4A;
    }
    if ((this->selected & 4) != 0) {
        y2 = 0x97;
    }

    sVar9 = param_4 + this->screen_y_offset;
    sVar8 = param_3 + this->screen_x_offset;
    digit_x = param_3;
    ry1 = -radius_y;
    this_00->get_point(corner1_x, corner1_y,
                       x3_radius, ry1, 0.0f, sVar8, sVar9);
    this_00->get_point(corner2_x, corner2_y, x3_radius, radius_y,
                       0.0f, sVar8, sVar9);
    neg_x3 = -x3_radius;
    this_00->get_point(corner3_x, corner3_y, neg_x3, radius_y,
                       0.0f, sVar8, sVar9);
    this_00->get_point(corner4_x, corner4_y, neg_x3, ry1,
                       0.0f, sVar8, sVar9);

    tot_hp = y2;
    iVar4 = (int)sVar9;
    SDI_List->AddGDINode(
        1, iVar4, corner1_x, corner1_y,
        corner2_x, corner2_y, corner3_x, corner3_y, corner4_x,
        corner4_y, 10, y2, SDI_Object_ID);

    if (this->selected != 0 && this->selected_group != 0 &&
        this->selected_group < 10 &&
        this->owner->id == this->owner->world->curr_player &&
        (pTVar2 = rge_base_game->get_shape(0)) != 0) {
        SDI_List->AddDrawNode(
            pTVar2->FShape,
            pTVar2->shape_info + this->selected_group,
            iVar4, corner4_x - 6, corner4_y - 8,
            0, 0, 0, 0x1E, SDI_Object_ID);
    }

    int health = (int)this->hp;
    if ((this->selected & 1) == 1 && (pRVar1->draw_flag & 2) == 0 &&
        health > 0) {
        this_00->get_point(health_x, health_y, x3_radius, ry1, radius_z,
                           sVar8, sVar9);
        int max_hp = pRVar1->hp;
        if (max_hp > 0) {
            int health_left = health_x - 12;
            int health_top = health_y - 2;
            int health_right = health_x + 11;
            int health_bottom = health_y - 1;
            int health_fill_end;
            int health_fill_style;
            int health_fill_start;
            int health_draw;

            digit_x = health_right;
            if (health == max_hp) {
                health_fill_end = health_right;
                health_fill_style = 1;
                health_fill_start = -1;
                health_draw = 0;
            } else {
                if (health == 0) {
                    health_fill_end = -1;
                    health_fill_style = 0;
                    health_fill_start = health_left;
                } else {
                    health_fill_style = 1;
                    health_fill_end = health_top + (health * 24) / max_hp;
                    if (health_right <= health_fill_end) {
                        health_fill_end = health_x + 10;
                    }
                    health_fill_start = health_fill_end + 1;
                }
                health_draw = 1;
            }
            SDI_List->AddGDINode(
                2, iVar4, health_left, health_top, health_right,
                health_bottom, health_fill_end, health_fill_style,
                health_fill_start, health_draw, 0x1E, tot_hp, SDI_Object_ID);
        }
    }

    if (rge_base_game->display_selected_ids != 0) {
        pTVar2 = rge_base_game->get_shape(0);
        iVar7 = this->id;
        iVar3 = iVar7;
        if (iVar7 < 0) {
            iVar3 = -iVar7;
        }
        idv[1] = iVar3 / 10000;
        idv[2] = (iVar3 % 10000) / 1000;
        iVar3 = (iVar3 % 10000) % 1000;
        idv[3] = iVar3 / 100;
        iVar3 = iVar3 % 100;
        idv[4] = iVar3 / 10;
        idv[5] = iVar3 % 10;
        uVar6 = (unsigned int)(iVar7 < 10000);
        if (iVar7 < 1000) {
            uVar6 = 2;
        }
        if (iVar7 < 100) {
            uVar6 = 3;
        }
        if (iVar7 < 10) {
            uVar6 = 4;
        }
        if (iVar7 < 0) {
            digit_x += 7;
            SDI_List->AddGDINode(
                4, iVar4, digit_x + 1, health_y + 2,
                digit_x + 5, health_y + 2,
                0, 0, 0, 0, 0x1E, 0x97, SDI_Object_ID);
        }
        if (uVar6 < 5) {
            piVar5 = idv + uVar6 + 1;
            iVar7 = 5 - uVar6;
            do {
                digit_x += 7;
                sVar8 = (short)digit_x;
                if (*piVar5 != 0) {
                    SDI_List->AddDrawNode(
                        pTVar2->FShape,
                        pTVar2->shape_info + *piVar5,
                        iVar4, (int)sVar8, health_y - 1,
                        0, 0, 0, 0x1E, SDI_Object_ID);
                } else {
                    SDI_List->AddGDINode(
                        4, iVar4, sVar8 + 1, health_y - 1,
                        sVar8 + 5, health_y + 4,
                        0, 0, 0, 0, 0x1E, 0xFF, SDI_Object_ID);
                }
                ++piVar5;
                --iVar7;
            } while (iVar7 != 0);
        }
    }
}


// 004C2970 RGE_Static_Object::draw_frame_3d_square_back


static char stat_obj_square_back_tag[] =
    "stat_obj::draw_frame_3d_square_back";

void RGE_Static_Object::draw_frame_3d_square_back(TDrawArea* area, short x, short y)
{
    RGE_Map* map;
    float fVar1;
    TPanel* view;
    short y2;
    short x2;
    short point_x;
    short point_y;
    float ry1;
    float local_4;

    map = this->owner->world->map;
    ry1 = this->master_obj->outline_radius_x;
    local_4 = this->master_obj->outline_radius_y;
    view = rge_base_game->get_view_panel();
    if (view != 0) {
        area->Unlock(stat_obj_square_back_tag);
        if (area->GetDc(stat_obj_square_back_tag) != 0) {
            SelectClipRgn(area->DrawDc, view->clip_rgn);
            if (startLoggingAI == 1 &&
                this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(area->DrawDc, GetStockObject(7));
            } else {
                SelectObject(area->DrawDc, GetStockObject(6));
            }

            x += this->screen_x_offset;
            y += this->screen_y_offset;

            fVar1 = -local_4;
            map->get_point(x2, y2, ry1, fVar1, 0.0f, x, y);
            map->get_point(point_x, point_y, ry1, local_4, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, point_x, point_y);
            map->get_point(x2, y2, ry1, fVar1, 0.0f, x, y);
            map->get_point(point_x, point_y, -ry1, fVar1, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, point_x, point_y);
            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc(stat_obj_square_back_tag);
        }
        area->Lock(stat_obj_square_back_tag, 1);
    }
}


// 004C2B50 RGE_Static_Object::draw_frame_3d_square_front


static char tag[] = "stat_obj::draw_frame_3d_square_front";

void RGE_Static_Object::draw_frame_3d_square_front(
    TDrawArea* area, short x, short y)
{
    short y1;
    short x1;
    short y2;
    short x2;
    float outline_y;
    float outline_x;
    float radius_z;
    TPanel* panel;

    RGE_Map* map = this->owner->world->map;
    outline_x = this->master_obj->outline_radius_x;
    outline_y = this->master_obj->outline_radius_y;
    radius_z = this->master_obj->radius_z;
    panel = rge_base_game->get_view_panel();
    if (panel != 0) {
        area->Unlock(tag);
        x += this->screen_x_offset;
        y += this->screen_y_offset;
        if (area->GetDc(tag) != 0) {
            SelectClipRgn(area->DrawDc, panel->clip_rgn);
            if (startLoggingAI == 1 &&
                this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(area->DrawDc, GetStockObject(7));
            } else {
                SelectObject(area->DrawDc, GetStockObject(6));
            }

            map->get_point(x1, y1, -outline_x, -outline_y, 0.0f,
                          x, y);
            map->get_point(x2, y2, -outline_x, outline_y, 0.0f,
                          x, y);
            MoveToEx(area->DrawDc, x1, y1, 0);
            LineTo(area->DrawDc, x2, y2);

            map->get_point(x1, y1, outline_x, outline_y, 0.0f,
                          x, y);
            map->get_point(x2, y2, -outline_x, outline_y, 0.0f,
                          x, y);
            MoveToEx(area->DrawDc, x1, y1, 0);
            LineTo(area->DrawDc, x2, y2);
            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc(tag);
        }

        area->Lock(tag, 1);
        int value = (int)this->hp;
        if (value > 0) {
            map->get_point(x1, y1, outline_x, -outline_y, radius_z,
                          x, y);
            if (value < 1)
                value = 0;
            int denom = this->master_obj->hp;
            if (denom > 0) {
                int bar_bottom = (-1) + y1;
                int bar_left = (-12) + x1;
                area->FillRect(bar_left, bar_bottom - 1,
                               bar_left + 24, bar_bottom, 0x97);
                int fill_height = (value * 24) / denom;
                int fill_right = fill_height + x1 - 12;
                area->FillRect(x1 - 12, y1 - 2, fill_right,
                               y1 - 1, 0x4a);
            }
        }
    }
}


// 004C2DF0 RGE_Static_Object::draw_frame_3d_cube_back
// BINARY NOTE: The reviewed extern rge_base_game declaration is required here;


void RGE_Static_Object::draw_frame_3d_cube_back(TDrawArea* area, short sx, short sy)
{
    short y2, x2, y1, x1;
    float negRy;
    RGE_Master_Static_Object* m = this->master_obj;
    float ry1, rz2, rz3, rz4, rx2, ry2, rzFull;
    ry1 = m->outline_radius_x * 0.25f;
    rz2 = m->outline_radius_y * 0.25f;
    rz3 = m->outline_radius_z * 0.25f;
    rz4 = m->outline_radius_z * 0.75f;
    rx2 = m->outline_radius_x;
    RGE_Map* map = this->owner->world->map;
    ry2 = m->outline_radius_y;
    rzFull = m->outline_radius_z;
    TPanel* view = rge_base_game->get_view_panel();

    if (view != 0) {
        area->Unlock(0);
        void* dc = area->GetDc(0);
        if (dc != 0) {
        SelectClipRgn(area->DrawDc, view->clip_rgn);
        if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0)
            SelectObject(area->DrawDc, GetStockObject(7));
        else
            SelectObject(area->DrawDc, GetStockObject(6));

        sx += this->screen_x_offset;
        sy += this->screen_y_offset;
        negRy = -ry2;

        map->get_point(x2, y2, rx2, negRy, 0.0f, sx, sy);
        map->get_point(x1, y1, rx2, negRy, rz3, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(x2, y2, rx2, negRy, rz4, sx, sy);
        map->get_point(x1, y1, rx2, negRy, rzFull, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(x2, y2, rx2, negRy, 0.0f, sx, sy);
        map->get_point(x1, y1, ry1, negRy, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(x2, y2, -rx2, negRy, 0.0f, sx, sy);
        map->get_point(x1, y1, -ry1, negRy, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(x2, y2, rx2, negRy, 0.0f, sx, sy);
        map->get_point(x1, y1, rx2, -rz2, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(x2, y2, rx2, ry2, 0.0f, sx, sy);
        map->get_point(x1, y1, rx2, rz2, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);

        SelectClipRgn(area->DrawDc, 0);
        area->ReleaseDc(0);
        }
        area->Lock(0, 1);
    }
}


// 004C31E0 RGE_Static_Object::draw_frame_3d_cube_front


void RGE_Static_Object::draw_frame_3d_cube_front(TDrawArea* area, short x, short y)
{
    short y2, x2, y1, x1;
    float neg_ry;
    float neg_ry2, neg_local_10;
    RGE_Master_Static_Object* master = this->master_obj;
    float local_10 = master->outline_radius_x * 0.25f;
    float rx2 = master->outline_radius_y * 0.25f;
    float rz3 = master->outline_radius_z * 0.25f;
    float local_4 = master->outline_radius_z * 0.75f;
    float ry2 = master->outline_radius_x;
    float rz4 = master->outline_radius_y;
    float rx1 = master->outline_radius_z;
    RGE_Map* map = this->owner->world->map;
    TPanel* view = rge_base_game->get_view_panel();

    // BINARY NOTE: A null view returns before the draw-area lock sequence.
    if (view == 0)
        return;

    area->Unlock(0);
        if (area->GetDc(0) != 0) {
            SelectClipRgn(area->DrawDc, view->clip_rgn);
            if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(area->DrawDc, GetStockObject(7));
            } else {
                SelectObject(area->DrawDc, GetStockObject(6));
            }

            // BINARY NOTE: Update x before y and keep both incoming short homes.
            x += this->screen_x_offset;
            y += this->screen_y_offset - 0x10;
            neg_ry = -rz4;

            map->get_point(x2, y2, ry2, neg_ry, rx1, x, y);
            map->get_point(x1, y1, local_10, neg_ry, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            neg_ry2 = -ry2;
            map->get_point(x2, y2, neg_ry2, neg_ry, rx1, x, y);
            // BINARY NOTE: Delay this negation until the first projection ends.
            neg_local_10 = -local_10;
            map->get_point(x1, y1, neg_local_10, neg_ry, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, ry2, rz4, rx1, x, y);
            map->get_point(x1, y1, local_10, rz4, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, rz4, rx1, x, y);
            map->get_point(x1, y1, neg_local_10, rz4, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, ry2, rz4, rx1, x, y);
            map->get_point(x1, y1, ry2, rx2, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, ry2, neg_ry, rx1, x, y);
            map->get_point(x1, y1, ry2, -rx2, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, rz4, rx1, x, y);
            map->get_point(x1, y1, neg_ry2, rx2, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, neg_ry, rx1, x, y);
            map->get_point(x1, y1, neg_ry2, -rx2, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, neg_ry, 0.0f, x, y);
            map->get_point(x1, y1, neg_ry2, -rx2, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, rz4, 0.0f, x, y);
            map->get_point(x1, y1, neg_ry2, rx2, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, ry2, rz4, 0.0f, x, y);
            map->get_point(x1, y1, local_10, rz4, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, rz4, 0.0f, x, y);
            map->get_point(x1, y1, neg_local_10, rz4, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, rz4, 0.0f, x, y);
            map->get_point(x1, y1, neg_ry2, rz4, rz3, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, rz4, local_4, x, y);
            map->get_point(x1, y1, neg_ry2, rz4, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, neg_ry, 0.0f, x, y);
            map->get_point(x1, y1, neg_ry2, neg_ry, rz3, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, neg_ry2, neg_ry, local_4, x, y);
            map->get_point(x1, y1, neg_ry2, neg_ry, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, ry2, rz4, 0.0f, x, y);
            map->get_point(x1, y1, ry2, rz4, rz3, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(x2, y2, ry2, rz4, local_4, x, y);
            map->get_point(x1, y1, ry2, rz4, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc(0);
        }
    area->Lock(0, 1);
}


// 004C3B30 RGE_Static_Object::draw_frame
// BINARY NOTE: Keep the sprite and sprite-list guards, facet dispatch, frame



void RGE_Static_Object::draw_frame(TDrawArea* area, short x, short y)
{
    short min_x;
    short min_y;
    short max_y;
    short max_x;
    int x1;
    int y1;
    int x2;
    int y2;

    if (this->sprite != 0 && this->sprite_list != 0) {
        this->sprite_list->get_facetindex(this->sprite, this->facet);

        if (this->get_frame(min_x, min_y, max_x, max_y) != 0) {
            x1 = x + min_x + this->screen_x_offset - 1;
            y1 = y + min_y + this->screen_y_offset - 1;
            x2 = x + max_x + this->screen_x_offset + 1;
            y2 = y + max_y + this->screen_y_offset + 1;

            area->DrawRect(x1, y1, x2, y2, 0xff);

            if (this->object_state <= 2) {
                int health = (int)this->hp;
                if (health < 1) {
                    health = 0;
                }

                int max_health = (int)this->master_obj->hp;
                if (max_health > 0) {
                    y1 -= 6;
                    x2 = x1 + 26;
                    y2 = y1 + 5;
                    area->DrawRect(x1, y1, x2, y2, 0xff);

                    area->FillRect(++x1, ++y1, x2 -= 2, y2 -= 2, 0x55);
                    area->FillRect(x1, y1,
                                   (health * 25) / max_health + x1 - 1,
                                   y1 + 3, 0x25);
                }
            }
        }
    }
}


// 004C3C70 RGE_Static_Object::update

typedef unsigned char uchar;



uchar RGE_Static_Object::update()
{
    uchar ret = 0;
    if (this->goto_sleep_flag != 0) {
        RGE_Player* own = this->owner;
        this->goto_sleep_flag = 0;
        own->removeObject(this, 0, this->dopple_flag, this->player_object_node);
        this->player_object_node = this->owner->addObject(this, 1, this->dopple_flag);
        return 0;
    }
    if (this->groupMembers.numberValue > 0) {
        int i = 0;
        if (i < this->groupMembers.numberValue) {
            while (i < this->groupMembers.numberValue) {
                int id = this->groupMembers[i];
                RGE_Static_Object* obj = this->owner->world->object(id);
                if (obj == 0 || obj->object_state > 2) {
                    int n = this->groupMembers.maximumSizeValue; int k = 0;
                    while (k < n && this->groupMembers.value[k] != id) { k++; }
                    if (k < n) {
                        if (k < n - 1) { do { int* p = this->groupMembers.value; k++; p[k-1] = p[k]; } while (k < this->groupMembers.maximumSizeValue - 1); }
                        int gn = this->groupMembers.numberValue - 1; this->groupMembers.numberValue = gn; if (gn < 0) this->groupMembers.numberValue = 0;
                    }
                    i--;
                }
                i++;
            }
        }
    }
    if (this->inside_obj == 0) {
        switch (this->object_state) {
    case 2: this->check_damage_sprites();
    case 0:
        if (this->hp < 1.0f) {
            this->set_object_state(3); this->new_sprite(this->master_obj->death_sprite);
            int r = debug_rand(STR_STAT_OBJ, 0x704); int old = debug_random_on; debug_random_on = 0;
            if (this->master_obj->death_sound != 0 && this->owner->id == this->owner->world->curr_player) this->master_obj->death_sound->play(1);
            debug_random_on = old; debug_srand(STR_STAT_OBJ, 0x70e, r);
        } break;
    case 3: case 5:
        if (this->attribute_type_held == -1 || this->attribute_amount_held <= 0.0f) {
            if (this->master_obj->undead_flag != 0) { this->set_object_state(6); this->new_sprite(this->master_obj->undead_sprite); break; }
            this->set_object_state(7); this->spawn_death_obj(); break;
        }
        if (this->groupRangeValue > 0.0f) {
            this->attribute_amount_held = this->attribute_amount_held -
                this->owner->world->world_time_delta_seconds *
                this->groupRangeValue;
            if (this->attribute_amount_held < 0.0f) {
                this->attribute_amount_held = 0.0f;
            }
        }
        break;
    case 7: this->set_object_state(8); break;
    case 8:
        if (this->master_obj->recyclable != 0)
            ret = 2;
        else
            ret = 1;
        break;
        }
    } else {
        if (this->inside_obj->object_state > 2)
            this->set_object_state(this->inside_obj->object_state);
    }
    return ret;
}


// 004C3F90 RGE_Static_Object::check_damage_sprites

static char s_stat_obj_cpp[] = "C:\\msdev\\work\\age1_x1\\stat_obj.cpp";



void RGE_Static_Object::check_damage_sprites()
{
    RGE_Master_Static_Object* master = this->master_obj;
    long old_damage_loc = -1;
    long new_damage_loc = -1;
    unsigned char new_percent;

    if (master->hp <= 0) return;
    if (master->damage_sprite_num == 0) return;

    new_percent = (unsigned char)(100 - (int)(this->hp * 100.0f / master->hp));
    if (new_percent == this->curr_damage_percent) return;

    if (new_percent < 100 && master->damage_sprite_num > 0) {
        for (int i = 0, n = master->damage_sprite_num; i < n; i++) {
            if (master->damage_sprites[i].damage_percent < new_percent) new_damage_loc = i;
            if (master->damage_sprites[i].damage_percent < this->curr_damage_percent) old_damage_loc = i;
        }
    }

    if (new_damage_loc != old_damage_loc) {
        if (new_damage_loc > -1) {
            RGE_Damage_Sprite_Info* info = &this->master_obj->damage_sprites[new_damage_loc];
            unsigned char flag = info->flag;
            RGE_Sprite* sprite;
            long add_x;
            long add_y;
            switch (flag) {
            case 0:
                sprite = info->sprite;
                add_x = 0;
                add_y = 0;
                goto add_damage_sprite;
            case 1: {
                    RGE_Master_Static_Object* m = this->master_obj;
                    float rand_x = (float)debug_rand(s_stat_obj_cpp, 0x774);
                    float fx = (this->world_x - (short)this->world_x) +
                               (rand_x * m->radius_x * 0.000030517578f - m->radius_x);
                    rand_x = (float)debug_rand(s_stat_obj_cpp, 0x775);
                    float fy = (this->world_y - (short)this->world_y) +
                               (rand_x * m->radius_y * 0.000030517578f - m->radius_y);
                    short sx, sy;
                    this->owner->world->map->get_point(sx, sy, fx, fy, this->world_z, 0, 0);
                    sprite = info->sprite;
                    add_x = sx;
                    add_y = sy;
                    goto add_damage_sprite;
                }
            case 2:
                this->new_sprite(info->sprite);
                goto damage_sprite_done;
            default:
                goto damage_sprite_done;
            }

        add_damage_sprite:
            this->sprite_list->add_sprite(sprite, 0x5A, add_x, add_y);
        damage_sprite_done:;
        }

        if (old_damage_loc > -1) {
            RGE_Damage_Sprite_Info* oldInfo = &this->master_obj->damage_sprites[old_damage_loc];
            if (oldInfo->flag == 2) {
                if (new_damage_loc < 0 || this->master_obj->damage_sprites[new_damage_loc].flag != 2) {
                    this->new_sprite(this->master_obj->sprite);
                }
            } else if (oldInfo->flag < 2) {
                this->sprite_list->remove_sprite(oldInfo->sprite);
            }
        }
    }
    this->curr_damage_percent = new_percent;
}


// 004C41D0 RGE_Static_Object::spawn_death_obj


RGE_Static_Object* RGE_Static_Object::spawn_death_obj(void) {
    short id = this->master_obj->death_spawn_obj_id;
    if (id >= 0) {
        RGE_Master_Static_Object* master = this->owner->master_objects[id];
        if (master != 0) {
            return master->make_new_obj(this->owner, this->world_x, this->world_y, this->world_z);
        }
    }
    return 0;
}


// 004C4210 RGE_Static_Object::rehook

void RGE_Static_Object::rehook(void) {
    RGE_Static_Object* obj;

    this->teleport((float)this->world_x, (float)this->world_y, (float)this->world_z);
    obj = this->inside_obj;
    if (obj != 0) {
        this->inside_obj = 0;
        obj = this->get_object_pointer((long)obj);
        if (obj != 0) {
            this->enter_obj(obj);
        }
    }
}


// 004C4250 RGE_Static_Object::get_object_pointer




RGE_Static_Object* RGE_Static_Object::get_object_pointer(long id)
{
    RGE_Static_Object* object = 0;

    if (id >= 0) {
        object = this->owner->objects->find_by_id(id);
        if (object == 0) {
            object = this->owner->sleeping_objects->find_by_id(id);
            if (object == 0) {
                object = this->owner->doppleganger_objects->find_by_id(id);
                if (object == 0) {
                    long object_id = id;
                    RGE_Player* player = this->owner;
                    unsigned char player_index = 0;
                    RGE_Game_World* world = player->world;
                    if (world->player_num > 0) {
                        short compare_index = 0;
                        do {
                            if (compare_index != player->id) {
                                object = world->players[player_index]->objects->find_by_id(object_id);
                                if (object != 0) {
                                    return object;
                                }
                                object = this->owner->world->players[player_index]->sleeping_objects->find_by_id(object_id);
                                if (object != 0) {
                                    return object;
                                }
                                object = this->owner->world->players[player_index]->doppleganger_objects->find_by_id(object_id);
                                if (object != 0) {
                                    return object;
                                }
                            }
                            player = this->owner;
                            ++player_index;
                            compare_index = player_index;
                            world = player->world;
                        } while (compare_index < world->player_num);
                    }
                }
            }
        }
    }

    return object;
}


// 004C4330 RGE_Static_Object::get_sprite_pointer



RGE_Sprite* RGE_Static_Object::get_sprite_pointer(short index) {
    RGE_Game_World* world;

    if (index >= 0) {
        world = this->owner->world;
        if (index < world->sprite_num) {
            return world->sprites[index];
        }
    }
    return 0;
}


// 004C4360 RGE_Static_Object::save


void RGE_Static_Object::save(int file)
{
    short sprite_id;
    int inside_id;
    int saved_file = file;
    int i;

    rge_write(saved_file, &this->type, 1);
    rge_write(saved_file, &this->owner->id, 1);
    rge_write(saved_file, &this->master_obj->id, 2);

    if (this->sprite == 0)
        sprite_id = -1;
    else
        sprite_id = this->sprite->id;
    rge_write(saved_file, &sprite_id, 2);

    if (this->inside_obj == 0)
        inside_id = -1;
    else
        inside_id = this->inside_obj->id;
    rge_write(saved_file, &inside_id, 4);

    rge_write(saved_file, &this->hp, 4);
    rge_write(saved_file, &this->object_state, 1);
    rge_write(saved_file, &this->sleep_flag, 1);
    rge_write(saved_file, &this->dopple_flag, 1);
    rge_write(saved_file, &this->goto_sleep_flag, 1);
    rge_write(saved_file, &this->id, 4);
    rge_write(saved_file, &this->facet, 1);
    rge_write(saved_file, &this->world_x, 4);
    rge_write(saved_file, &this->world_y, 4);
    rge_write(saved_file, &this->world_z, 4);
    rge_write(saved_file, &this->screen_x_offset, 2);
    rge_write(saved_file, &this->screen_y_offset, 2);
    rge_write(saved_file, &this->shadow_x_offset, 2);
    rge_write(saved_file, &this->shadow_y_offset, 2);
    rge_write(saved_file, &this->selected_group, 1);
    rge_write(saved_file, &this->attribute_type_held, 2);
    rge_write(saved_file, &this->attribute_amount_held, 4);
    rge_write(saved_file, &this->worker_num, 1);
    rge_write(saved_file, &this->curr_damage_percent, 1);
    rge_write(saved_file, &this->underAttackValue, 1);
    rge_write(saved_file, &this->groupCommanderValue, 4);
    rge_write(saved_file, &this->groupRangeValue, 4);

    file = this->groupMembers.numberValue;
    rge_write(saved_file, &file, 4);
    i = 0;
    if (this->groupMembers.numberValue > 0) do {
        file = this->groupMembers[i];
        rge_write(saved_file, &file, 4);
        ++i;
    } while (i < this->groupMembers.numberValue);

    file = this->pathingGroupMembers.numberValue;
    rge_write(saved_file, &file, 4);
    int k = 0;
    if (this->pathingGroupMembers.numberValue > 0) do {
        file = this->pathingGroupMembers[k];
        rge_write(saved_file, &file, 4);
        ++k;
    } while (k < this->pathingGroupMembers.numberValue);

    this->sprite_list->save(saved_file);
}


// 004C4680 RGE_Static_Object::teleport
// BINARY NOTE: teleport uses the canonical named terrain methods.


float RGE_Static_Object::teleport(float param_1, float param_2, float param_3) {
    float result;
    RGE_Map* map;
    float rx;
    float rz;
    int tx;
    int ty;
    RGE_Tile* new_tile;
    result = 0.0f;
    map = this->owner->world->map;
    if (this->inside_obj != 0) {
        return 0.0f;
    }

    if (0.0 < this->master_obj->radius_z) {
        this->removeFromObstructionMap(2);
    }

    if (param_1 < 0.0f) {
        param_1 = 0.0f;
    }
    // BINARY NOTE: The upper-bound loads come directly from map width and height.
    if (param_1 >= (float)map->map_width) {
        param_1 = (float)map->map_width - 0.001f;
    }
    if (param_2 < 0.0f) {
        param_2 = 0.0f;
    }
    if (param_2 >= (float)map->map_height) {
        param_2 = (float)map->map_height - 0.001f;
    }

    tx = (int)param_1;
    ty = (int)param_2;
    rx = param_1 - (float)tx;
    rz = param_2 - (float)ty;
    if (tx < map->map_width) {
        if (tx < 0) {
            tx = 0;
        }
    } else {
        tx = map->map_width - 1;
    }
    if (ty < map->map_height) {
        if (ty < 0) {
            ty = 0;
        }
    } else {
        ty = map->map_height - 1;
    }

    new_tile = map->map_row_offset[ty] + tx;
    if (new_tile == this->tile || this->inside_obj != 0) {
        this->world_x = param_1;
        this->world_y = param_2;
        this->world_z = param_3;
    } else {
        if (this->tile != 0) {
            this->tile->objects.remove_node(this, 0);
        }
        new_tile->objects.add_node(this);
        if (this->tile != 0) {
            this->unexplore_terrain(this->owner, 0, -1);
        }
        this->world_z = param_3;
        this->world_x = param_1;
        this->world_y = param_2;
        this->tile = new_tile;
        if (this->object_state == 2) {
            this->explore_terrain(this->owner, 0, -1);
        }
    }

    if (0.0 < this->master_obj->radius_z) {
        this->addToObstructionMap(2);
    }

    switch (new_tile->tile_type) {
    case 1:
        if (rx + rz < 1.0f) {
            result = rz;
        } else {
            result = 1.0f - rx;
        }
        break;
    case 2:
        if (rx + rz < 1.0f) {
            result = rx;
        } else {
            result = 1.0f - rz;
        }
        break;
    case 3:
        if (rx <= rz) {
            result = 1.0f - rz;
        } else {
            result = 1.0f - rx;
        }
        break;
    case 4:
        if (rx <= rz) {
            result = rx;
        } else {
            result = rz;
        }
        break;
    case 5:
        result = 1.0f - rx;
        break;
    case 6:
        result = 1.0f - rz;
        break;
    case 7:
        result = rz;
        break;
    case 8:
        result = rx;
        break;
    case 9:
        if (rx - rz < 0.0f) {
            result = -(rx - rz);
        } else {
            result = 0.0f;
        }
        break;
    case 10:
        result = rx - rz;
        if (result <= 0.0f) {
            result = 0.0f;
        }
        break;
    case 11:
        if (rx + rz < 1.0f) {
            result = 1.0f - (rx + rz);
        } else {
            result = 0.0f;
        }
        break;
    case 12:
        if (1.0f < rx + rz) {
            result = (rx + rz) - 1.0f;
        } else {
            result = 0.0f;
        }
        break;
    case 0:
        result = 0.0f;
        break;
    case 13:
        if (1.0f <= rx + rz) {
            result = rz;
        } else {
            result = 1.0f - rx;
        }
        break;
    case 14:
        if (1.0f <= rx + rz) {
            result = rx;
        } else {
            result = 1.0f - rz;
        }
        break;
    case 15:
        if (rx <= rz) {
            result = rz;
        } else {
            result = rx;
        }
        break;
    case 16:
        if (rx <= rz) {
            result = 1.0f - rx;
        } else {
            result = 1.0f - rz;
        }
        break;
    default:
        break;
    }

    RGE_Master_Static_Object* master = this->master_obj;
    unsigned char movement = master->movement_type;
    result += (float)new_tile->height;
    if (movement == 0 || (movement == 1 && this->world_z < result)) {
        this->world_z = result;
    }

    this->screen_x_offset =
        (short)((rx + rz) * map->tile_half_width);
    this->screen_y_offset =
        (short)((result + rx - rz - this->world_z) * map->tile_half_height);

    if (movement == 0) {
        this->shadow_x_offset = this->screen_x_offset;
        this->shadow_y_offset = this->screen_y_offset;
    } else if (movement == 1) {
        this->shadow_x_offset =
            (short)((rx + rz) * map->tile_half_width);
        this->shadow_y_offset =
            (short)((result - rz) * map->tile_half_height);
    }
    return result;
}


// 004C4BD0 RGE_Static_Object::new_sprite

void RGE_Static_Object::new_sprite(RGE_Sprite* sprite) {
    if (sprite == 0) {
        sprite = this->master_obj->sprite;
    }
    if (this->sprite != sprite && (this->sprite != this->master_obj->death_sprite || this->master_obj->death_sprite == 0)) {
        this->old_sprite = this->sprite;
        this->sprite_list->remove_sprite(this->sprite);
        this->sprite = sprite;
        this->sprite_list->add_sprite(sprite, 0x3C, 0, 0);
        this->facet = 0;
    }
}


// 004C4C20 RGE_Static_Object::add_overlay_sprite


void RGE_Static_Object::add_overlay_sprite(RGE_Sprite* sprite, unsigned char mode) {
    sprite_list->add_sprite(sprite, mode, 0, 0);
}


// 004C4C40 RGE_Static_Object::remove_overlay_sprite

// BINARY NOTE: this virtual member takes an RGE_Sprite pointer.
void RGE_Static_Object::remove_overlay_sprite(RGE_Sprite* param) {
    this->sprite_list->remove_sprite(param);
}


// 004C4C50 RGE_Static_Object::change_ownership


void RGE_Static_Object::change_ownership(RGE_Player* player)
{
    if (player->master_objects[this->master_obj->id] == 0) {
        return;
    }

    if ((this->selected & 1) != 0) {
        this->owner->unselect_one_object(this);
    }

    float hp_num = this->hp / (float)(int)this->master_obj->hp;
    this->take_attribute_from_owner();

    if (this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
    }

    this->owner->removeObject(this, this->sleep_flag, this->dopple_flag,
                              this->player_object_node);
    RGE_Object_Node* new_node =
        player->addObject(this, this->sleep_flag, this->dopple_flag);

    RGE_Master_Static_Object* old_master = this->master_obj;
    this->player_object_node = new_node;
    RGE_Master_Static_Object* new_master =
        player->master_objects[old_master->id];
    RGE_Sprite* new_sprite = this->sprite;
    if (new_sprite != old_master->sprite) {
        if (new_sprite == old_master->death_sprite) {
            new_sprite = new_master->death_sprite;
        } else if (new_sprite == old_master->undead_sprite) {
            new_sprite = new_master->undead_sprite;
        } else {
            new_sprite = new_master->sprite;
        }
    } else {
        new_sprite = new_master->sprite;
    }

    if (new_sprite != 0) {
        this->new_sprite(new_sprite);
    }

    this->owner = player;
    this->master_obj = new_master;
    this->hp = (float)(int)new_master->hp * hp_num;

    if (this->object_state == 2) {
        this->explore_terrain(player, 0, -1);
    }

    this->give_attribute_to_owner();
    this->notify(this->id, this->id, 0x20B, (int)player->id, 0, 0);
}


// 004C4D80 RGE_Static_Object::modify

void RGE_Static_Object::modify(float value, unsigned char type) {
    switch (type) {
    case 0:
        {
            int maxHp = this->master_obj->hp;
            this->hp = (float)(short)(long)(value * this->hp / maxHp);
        }
        break;
    case 1:
        if (this->tile != 0 && this->object_state == 2) {
            this->setDamage(this->owner, 0, -1);
            this->setHealth(this->owner, 0, (long)value);
            return;
        }
        break;
    }
}


// 004C4E00 RGE_Static_Object::modify_delta


void RGE_Static_Object::modify_delta(float delta, unsigned char type)
{
    unsigned int op = type & 0xff;
    switch (op) {
    case 1:
        if (this->tile != 0 && this->object_state == 2) {
            RGE_Player* owner = this->owner;
            this->unexplore_terrain(owner, 0, -1);
            RGE_Master_Static_Object* master = this->master_obj;
            this->explore_terrain(this->owner, 0, (int)(master->los + delta));
        }
        return;
    case 0: {
        RGE_Master_Static_Object* master = this->master_obj;
        float max_hp = (float)master->hp;
        this->hp = (float)(int)(short)((delta + max_hp) * this->hp / max_hp);
        break;
    }
    default:
        return;
    }
}


// 004C4E90 RGE_Static_Object::modify_percent




void RGE_Static_Object::modify_percent(float percent, unsigned char mode) {
    switch (mode) {
    case 0: {
        int tmp = (int)(percent * hp);
        hp = (float)(short)tmp;
        break;
    }
    case 1:
        if (tile != 0 && object_state == 2) {
            this->unexplore_terrain(this->owner, 0, -1);

            int val = (int)(master_obj->los * percent);
            this->explore_terrain(this->owner, 0, val);
        }
        break;
    }
}


// 004C4F10 RGE_Static_Object::transform


void RGE_Static_Object::transform(RGE_Master_Static_Object* param_1) {
    float ratio = (float)(signed short)(master_obj->hp);
    ratio = hp / ratio;

    if (tile != 0) {
        unexplore_terrain(owner, 0, -1);
    }

    removeFromObstructionMap(2);

    master_obj = param_1;

    if (tile != 0) {
        explore_terrain(owner, 0, (int)param_1->los);
    }

    addToObstructionMap(2);

    new_sprite(param_1->sprite);

    hp = (float)param_1->hp;
    hp = hp * ratio;
    object_state = 0;

    update(2);
}


// 004C4FB0 RGE_Static_Object::copy_obj


void RGE_Static_Object::copy_obj(RGE_Master_Static_Object* master)
{
    RGE_Sprite* new_sprite = 0;

    if (this->tile != 0 && this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
        this->explore_terrain(this->owner, 0, (int)master->los);
    }

    float hp_num = this->hp / (float)(int)this->master_obj->hp;
    this->hp = (float)(int)this->master_obj->hp;
    if (this->object_state == 2) {
        this->check_damage_sprites();
    }

    RGE_Master_Static_Object* old_master = this->master_obj;
    RGE_Sprite* old_sprite = this->sprite;
    if (old_sprite == old_master->sprite) {
        new_sprite = master->sprite;
    } else if (old_sprite == old_master->death_sprite) {
        new_sprite = master->death_sprite;
    } else if (old_sprite == old_master->undead_sprite) {
        new_sprite = master->undead_sprite;
    }

    int new_hp = master->hp;
    this->master_obj = master;
    this->hp = (float)(int)new_hp * hp_num;
    if (this->object_state == 2) {
        this->check_damage_sprites();
    }

    this->master_obj = old_master;
    if (new_sprite != 0) {
        this->new_sprite(new_sprite);
    }
}


// 004C5080 RGE_Static_Object::destroy_obj


void RGE_Static_Object::destroy_obj(void) {
    if (this->object_state < 7) {
        if (this->inside_obj != 0) {
            this->exit_obj();
        }
        if ((this->selected & 1) != 0) {
            this->owner->unselect_one_object(this);
        }
        this->set_sleep_flag(0);
        this->set_object_state(7);
    }
}


// 004C50C0 RGE_Static_Object::die_die_die

void RGE_Static_Object::die_die_die(void) {
    if ((this->selected & 1) != 0) {
        this->owner->unselect_one_object(this);
    }
    this->set_sleep_flag(0);
    this->hp = 0;
}


// 004C50F0 RGE_Static_Object::remove_visible_resource

typedef unsigned long ulong;



void RGE_Static_Object::remove_visible_resource() {
    ulong mask;
    ulong explored;
    RGE_Player* player;
    if (this->id >= 0 && this->owner != 0 && this->master_obj != 0 &&
        (this->master_obj->create_doppleganger_on_death != 0 ||
         this->master_obj->track_as_resource != 0)) {
        mask = unified_map_offsets[(int)this->world_y][(int)this->world_x];
        explored = mask >> 16;
        mask &= 0xFFFF;
        if (explored > 0) {
            int player_index = 0;
            do {
                if ((explored & 1) == 1) {
                    if (this->master_obj->track_as_resource != 0) {
                        player = this->owner->world->players[player_index];
                        player->VR_List->Remove_Resource(
                            this->id, this->master_obj->resource_group);
                    }
                    if (this->master_obj->create_doppleganger_on_death == 1 &&
                        (mask & 1) == 0 && player_index > 0) {
                        player = this->owner->world->players[player_index];
                        static_cast<RGE_Master_Doppleganger_Object*>(player->master_objects[243])->make_new_obj(
                            player, this->world_x, this->world_y, this->world_z, this);
                    }
                }
                player_index++;
                mask >>= 1;
                explored >>= 1;
            } while (explored != 0);
        }
        if (this->master_obj->create_doppleganger_on_death == 2) {
            this->owner->doppleganger_creator->remove_doppleganger_check(this);
        }
    }
}


// 004C5210 RGE_Static_Object::create_doppleganger_when_dying

typedef unsigned long ulong;



void RGE_Static_Object::create_doppleganger_when_dying() {
    if (this->id >= 0 && this->owner != 0 && this->master_obj != 0 &&
        this->master_obj->create_doppleganger_on_death == 2) {
        ulong mask = unified_map_offsets[(int)this->world_y][(int)this->world_x];
        ulong explored = mask >> 16;
        mask &= 0xFFFF;
        if (explored > 0) {
            int i = 0;
            do {
                if ((explored & 1) == 1 && (mask & 1) == 0 && i > 0) {
                    RGE_Player* player = this->owner->world->players[i >> 2];
                    static_cast<RGE_Master_Doppleganger_Object*>(player->master_objects[243])->make_new_obj(
                        player, this->world_x, this->world_y, this->world_z, this);
                }
                i += 4;
                mask >>= 1;
                explored >>= 1;
            } while (explored != 0);
        }
        this->owner->doppleganger_creator->add_doppleganger_check(
            this, &unified_map_offsets[(int)this->world_y][(int)this->world_x]);
    }
}


// 004C52F0 RGE_Static_Object::set_object_state

void RGE_Static_Object::set_object_state(unsigned char state)
{
    if (this->object_state != state) {
        if (state >= 3 && this->object_state < 3) {
            this->take_attribute_from_owner();
            if (this->master_obj->create_doppleganger_on_death == 2) {
                this->create_doppleganger_when_dying();
            }
        }

        if (this->object_state <= 3 && state >= 7) {
            this->remove_visible_resource();
        }

        if (state >= 3 && this->object_state == 2 && this->tile != 0) {
            this->unexplore_terrain(this->owner, 0, -1);
            if (this->master_obj->los > 0.0) {
                this->explore_terrain(this->owner, 1, -1);
            }
        }

        if (this->object_state < 7 && state == 7 && this->tile != 0 &&
            this->master_obj->los > 0.0) {
            this->unexplore_terrain(this->owner, 1, -1);
        }

        this->object_state = state;

        if (state == 3 &&
            this->groupCommanderValue == this->id &&
            this->unitAIValue != 0 &&
            this->groupMembers.numberValue > 1) {
            int i = 0;
            int newCommander = -1;
            if (this->groupMembers.numberValue > 0) {
                do {
                    if (this->groupMembers[i] != this->id) {
                        RGE_Static_Object* object =
                            this->owner->world->object(this->groupMembers[i]);
                        if (object != 0 && object->object_state <= 2 &&
                            object->unitAI() != 0) {
                            if (newCommander == -1) {
                                newCommander = this->groupMembers[i];
                            }
                            object->groupCommanderValue = newCommander;
                            if (this->groupMembers[i] == newCommander) {
                                object->unitAI()->playStatus =
                                    this->unitAIValue->playStatus;
                            }
                        }
                    }
                    ++i;
                } while (i < this->groupMembers.numberValue);
            }
        }

        if (this->sleep_flag != 0 && this->object_state != 2 &&
            this->object_state != 6) {
            this->set_sleep_flag(0);
        }
    }
}


// 004C5610 RGE_Static_Object::check_object_bounds
// BINARY NOTE: The executable's final X overlap accepts less, equal, and


RGE_Static_Object* RGE_Static_Object::check_object_bounds()
{
    float radius_x;
    float radius_y;
    short x1;
    short y1;
    short x2;
    short y2;
    short y_index;

    radius_x = this->master_obj->radius_x;
    radius_y = this->master_obj->radius_y;
    if (!(radius_x <= 0.0f && radius_y <= 0.0f)) {
        x1 = (short)(int)(this->world_x - 3.0f);
        y1 = (short)(int)(this->world_y - 3.0f);
        x2 = (short)(int)(this->world_x + 3.0f);
        y2 = (short)(int)(this->world_y + 3.0f);
        RGE_Map* map = this->owner->world->map;
        if (x1 < 0) x1 = 0;
        if (x2 >= map->map_width) x2 = (short)map->map_width - 1;
        if (y1 < 0) y1 = 0;
        if (y2 >= map->map_height) y2 = (short)map->map_height - 1;
        y_index = y1;
        if (y1 > y2) return 0;
        do {
            short x = x1;
            if (x1 <= x2) {
                do {
                    RGE_Object_Node* n =
                        map->map_row_offset[y_index][x].objects.list;
                    if (n != 0) {
                        do {
                            RGE_Static_Object* obj = n->node;
                            RGE_Master_Static_Object* master = obj->master_obj;
                            float object_radius_y = master->radius_y;
                            float object_radius_x = master->radius_x;
                            if (object_radius_x > 0.0f && object_radius_y > 0.0f) {
                                float dy = obj->world_y - this->world_y;
                                float dx = obj->world_x - this->world_x;
                                if (dy < 0.0f) dy = -dy;
                                if (dx < 0.0f) dx = -dx;
                                if (dy <= object_radius_y + radius_y) {
                                    float x_limit = object_radius_x + radius_x;
                                    if (!(dx > x_limit)) {
                                        return obj;
                                    }
                                }
                            }
                            n = n->next;
                        } while (n != 0);
                    }
                    x++;
                } while (x <= x2);
            }
            y_index++;
        } while (y_index <= y2);
    }
    return 0;
}


// 004C5820 RGE_Static_Object::get_terrain_speed

float RGE_Static_Object::get_terrain_speed(unsigned char terrain_type) {
    return owner->world->terrains[master_obj->terrain][terrain_type];
}


// 004C5850 RGE_Static_Object::is_moving

unsigned char RGE_Static_Object::is_moving() { return 0; }


// 004C5860 RGE_Static_Object::is_dying

// BINARY NOTE: this method is an exceptional nonvirtual member. Its original
unsigned char RGE_Static_Object::is_dying(void) {
    if (object_state >= 3 && object_state != 6) {
        return 1;
    }
    return 0;
}


// 004C5880 RGE_Static_Object::get_frame
// BINARY NOTE: the four outputs are references, not pointer parameters.


int RGE_Static_Object::get_frame(short& param_1, short& param_2, short& param_3, short& param_4) {
    if (this->sprite != 0 && this->sprite_list != 0) {
        return this->sprite_list->get_frame(param_1, param_2, param_3,
                                            param_4, this->sprite,
                                            (unsigned char)this->facet);
    }
    return 0;
}


// 004C58C0 RGE_Static_Object::more_room


unsigned char RGE_Static_Object::more_room() {
    return objects->number_of_objects < (short)(unsigned short)master_obj->obj_max;
}


// 004C58E0 RGE_Static_Object::enter_obj




void RGE_Static_Object::enter_obj(RGE_Static_Object* target) {
    if (!target->more_room()) {
        return;
    }

    if (inside_obj != 0) {
        inside_obj->exit_obj();
    }

    if (tile != 0) {
        this->unexplore_terrain(owner, 0, -1);

        tile->objects.remove_node(this, 0);
        tile = 0;
    }

    removeFromObstructionMap(2);
    target->objects->add_node(this);
    inside_obj = target;
    world_x = target->world_x;
    world_y = target->world_y;
}


// 004C5960 RGE_Static_Object::exit_obj

void RGE_Static_Object::exit_obj(void) {
    if (inside_obj != 0) {
        inside_obj->objects->remove_node(this, 0);
        inside_obj = 0;
    }
}


// 004C5980 RGE_Static_Object::get_los_table

// BINARY NOTE: LOSTBL is a struct in the original decorated return type.
LOSTBL* RGE_Static_Object::get_los_table(void) {
    if (this->owner == 0) {
        return 0;
    }
    return this->owner->visible->get_los_table((int)this->master_obj->los, 0);
}


// 004C59B0 RGE_Static_Object::explore_terrain

extern "C" long __cdecl _ftol(void);


int RGE_Static_Object::explore_terrain(RGE_Player* player, unsigned char mode, int range)
{
    if (player != 0) {
        if (range == -1) {
            range = (int)this->master_obj->los;
        }
        if (range > 0) {
            RGE_Visible_Map* visible = player->visible;
            long current = (player->id == player->world->curr_player);
            if (mode == 0) {
                return visible->explore_terrain(
                    (long)this->world_x, (long)this->world_y, range, 0, current, this->id);
            } else {
                if (this->master_obj->radius_x > 0.0 && this->master_obj->radius_y > 0.0) {
                    return visible->explore_terrain_sq(
                        (long)(this->world_x - this->master_obj->radius_x),
                        (long)(this->world_y - this->master_obj->radius_y),
                        (long)(this->world_x + this->master_obj->radius_x - 0.01f),
                        (long)(this->world_y + this->master_obj->radius_y - 0.01f),
                        current, this->id);
                }
            }
        }
    }
    return 0;
}


// 004C5AA0 RGE_Static_Object::unexplore_terrain

extern "C" long __cdecl _ftol(void);


void RGE_Static_Object::unexplore_terrain(RGE_Player* player, unsigned char mode, int range)
{
    if (player != 0) {
        if (range == -1) {
            range = (int)this->master_obj->los;
        }
        if (range > 0) {
            RGE_Visible_Map* visible = player->visible;
            long current = (player->id == player->world->curr_player);
            if (mode == 0) {
                visible->unexplore_terrain(
                    (long)this->world_x, (long)this->world_y, range, 0, current, this->id);
            } else {
                if (this->master_obj->radius_x > 0.0 && this->master_obj->radius_y > 0.0) {
                    visible->unexplore_terrain_sq(
                        (long)(this->world_x - this->master_obj->radius_x),
                        (long)(this->world_y - this->master_obj->radius_y),
                        (long)(this->world_x + this->master_obj->radius_x - 0.01f),
                        (long)(this->world_y + this->master_obj->radius_y - 0.01f),
                        current, this->id);
                }
            }
        }
    }
}


// 004C5B90 RGE_Static_Object::damage
void RGE_Static_Object::damage(int count, RGE_Armor_Weapon_Info* info, float scale, RGE_Player* player, RGE_Static_Object* object) {
    float damage_amount;

    damage_amount = this->calculateDamage(count, info, scale, player, object);
    this->hp = this->hp - damage_amount;
    if (this->hp < 1.0) {
        this->hp = 0.0f;
        this->set_sleep_flag(0);
    }
}


// 004C5BE0 RGE_Static_Object::calculateDamage

float RGE_Static_Object::calculateDamage(int count, RGE_Armor_Weapon_Info* info, float scale, RGE_Player*, RGE_Static_Object*) {
    float damage = 0.0f;

    if (count > 0) {
        short* value = &info->value;
        do {
            damage = (float)(int)(*value) * scale + damage;
            value = value + 2;
            count = count - 1;
        } while (count != 0);
    }
    return damage;
}


// 004C5C10 RGE_Static_Object::rotate

void RGE_Static_Object::rotate(long amount) {
    int facet_num = (int)this->sprite->facet_num;
    int facet = amount + (unsigned int)this->facet;

    while (facet < 0) {
        facet += facet_num;
    }
    while (facet >= facet_num) {
        facet -= facet_num;
    }
    this->facet = (unsigned char)facet;
}


// 004C5C40 RGE_Static_Object::set_attribute

void RGE_Static_Object::set_attribute(short param1, float param2) {
    attribute_type_held = param1;
    attribute_amount_held = param2;
}


// 004C5C60 RGE_Static_Object::set_attribute_amount
void RGE_Static_Object::set_attribute_amount(float amount, unsigned char add, unsigned char clamp)
{
    if (add != 0) {
        this->attribute_amount_held = amount + this->attribute_amount_held;
    }
    else {
        this->attribute_amount_held = amount;
    }

    if (clamp != 0) {
        if ((float)(int)this->master_obj->attribute_max_amount < this->attribute_amount_held) {
            this->attribute_amount_held = (float)(int)this->master_obj->attribute_max_amount;
        }
    }
}


// 004C5CB0 RGE_Static_Object::heal

unsigned char RGE_Static_Object::heal(float amount) {
    float fVar1 = amount + this->hp;
    this->hp = fVar1;
    if (amount < 0.0f) {
        if (fVar1 < 1.0f) this->hp = 1.0f;
    }
    int maxHp = this->master_obj->hp;
    if (maxHp <= this->hp) {
        this->hp = (float)maxHp;
        return 1;
    }
    return 0;
}


// 004C5D10 RGE_Static_Object::notify_of_relation

void RGE_Static_Object::notify_of_relation(long p0, unsigned char p1) {}


// 004C5D20 RGE_Static_Object::set_being_worked_on

void RGE_Static_Object::set_being_worked_on(RGE_Action_Object* action, short mode, unsigned char flag) {
    if (worker_num < 0xFA) {
        worker_num = worker_num + 1;
    }
    set_sleep_flag(0);
}


// 004C5D40 RGE_Static_Object::release_being_worked_on
void RGE_Static_Object::release_being_worked_on(RGE_Static_Object* unused) {
    if (this->worker_num > 0) {
        this->worker_num--;
    }
    if (this->worker_num == 0) {
        unsigned char state = this->object_state;
        if (state == 2) {
            if (!(this->hp < 0.0f)) {
                goto sleep_it;
            }
        }
        if (state != 6) {
            return;
        }
    sleep_it:
        set_sleep_flag(1);
    }
}


// 004C5D80 RGE_Static_Object::inRange
//   - BINARY NOTE: The complete Y expression stays in the pending x87 status window. This









int RGE_Static_Object::inRange(RGE_Static_Object* other, float range)
{
    float dx = other->world_x - this->world_x;
    float dy = other->world_y - this->world_y;

    if (dx < 0.0f) {
        dx = -dx;
    }
    if (dy < 0.0f) {
        dy = -dy;
    }

    float other_radius_x = other->master_obj->radius_x;
    float this_radius_x = this->master_obj->radius_x;
    float this_radius_y = this->master_obj->radius_y;
    float other_radius_y = other->master_obj->radius_y;
    float x = dx - this_radius_x - other_radius_x;
    float y = dy - this_radius_y - other_radius_y;

    if (x < 0.0f) {
        x = 0.0f;
    }
    if (y < 0.0f) {
        y = 0.0f;
    }

    if (x * x + y * y < range * range) {
        return 1;
    }
    return 0;
}


// 004C5E50 RGE_Static_Object::distance_to_object













float RGE_Static_Object::distance_to_object(RGE_Static_Object* other) {
    float dx = other->world_x - this->world_x;
    float dy = other->world_y - this->world_y;

    if (dx < 0.0f) dx = -dx;
    if (dy < 0.0f) dy = -dy;

    float other_radius_x = other->master_obj->radius_x;
    float this_radius_x = this->master_obj->radius_x;
    float this_radius_y = this->master_obj->radius_y;
    float other_radius_y = other->master_obj->radius_y;
    float x = dx - this_radius_x - other_radius_x;
    float y = dy - this_radius_y - other_radius_y;

    if (x < 0.0f) x = 0.0f;
    if (y < 0.0f) y = 0.0f;

    return (float)sqrt(x * x + y * y);
}


// 004C5F00 RGE_Static_Object::distance_to_position



float RGE_Static_Object::distance_to_position(float x, float y, float z)
{
    float dx = world_x - x;
    float dy = world_y - y;

    if (dx < 0.0f)
        dx = -dx;
    if (dy < 0.0f)
        dy = -dy;

    float dx2 = dx - master_obj->radius_x;
    float dy2 = dy - master_obj->radius_y;

    if (dx2 < 0.0f)
        dx2 = 0.0f;
    if (dy2 < 0.0f)
        dy2 = 0.0f;

    return sqrt(dx2 * dx2 + dy2 * dy2);
}


// 004C5FA0 RGE_Static_Object::hit_test


unsigned char RGE_Static_Object::hit_test(
    short x, short y, short x2, short y2, short range)
{
    if (this->sprite != 0 && this->sprite_list != 0) {
        short frame = this->sprite_list->frame(this->sprite);
        short hit_x = x2 - this->screen_x_offset - x;
        short hit_y = y2 - this->screen_y_offset - y;

        if (this->sprite->hit_test(hit_x, hit_y, this->facet, frame) != 0) {
            return 1;
        }

        if (range != 0) {
            for (short outer = -range; outer < range; ++outer) {
                for (short inner = -range; inner < range; ++inner) {
                    if (this->sprite->hit_test(
                            hit_x + outer, hit_y + inner,
                            this->facet, frame) != 0) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }

    return 0;
}


// 004C60A0 RGE_Static_Object::box_hit_test



unsigned char RGE_Static_Object::box_hit_test(short param_1, short param_2, short param_3, short param_4, short param_5, short param_6) {
    if (this->sprite == 0) return 0;
    if (this->sprite_list == 0) return 0;

    this->sprite_list->get_facetindex(this->sprite, this->facet);

    short min_x;
    short min_y;
    short max_y;
    short max_x;
    if (this->get_frame(min_x, min_y, max_x, max_y) == 0) return 0;

    min_x = min_x + param_1 + this->screen_x_offset;
    min_y = min_y + param_2 + this->screen_y_offset;
    max_x = max_x + param_1 + this->screen_x_offset;
    max_y = max_y + param_2 + this->screen_y_offset;

    if (min_x >= param_3 && min_x <= param_5 && min_y >= param_4 && min_y <= param_6) return 1;
    if (max_x >= param_3 && max_x <= param_5 && max_y >= param_4 && max_y <= param_6) return 1;
    if (param_3 >= min_x && param_3 <= max_x && param_4 >= min_y && param_4 <= max_y) return 1;
    if (param_5 >= min_x && param_5 <= max_x && param_6 >= min_y && param_6 <= max_y) return 1;
    if (param_3 < min_x && param_5 > max_x &&
        ((param_4 > min_y && param_4 < max_y) ||
         (param_6 > min_y && param_6 < max_y))) return 1;
    if (param_4 < min_y && param_6 > max_y &&
        ((param_3 > min_x && param_3 < max_x) ||
         (param_5 > min_x && param_5 < max_x))) return 1;

    return 0;
}


// 004C6240 RGE_Static_Object::set_location

void RGE_Static_Object::set_location(float x, float y, float z) {
    world_x = x;
    world_y = y;
    world_z = z;
}


// 004C6260 RGE_Static_Object::new_angle

void RGE_Static_Object::new_angle(float p0) {}


// 004C6270 RGE_Static_Object::drop_held_objects


unsigned char RGE_Static_Object::drop_held_objects(int mode)
{
    int i = 1;
    unsigned char count = 0;
    RGE_Object_Node* temp;
    float x;
    float y;
    float drop_y[10];
    float radius_x[10];
    float drop_x[10];
    float radius_y[10];
    drop_x[1] = this->world_x;
    drop_y[1] = this->world_y;
    radius_x[1] = this->master_obj->radius_x + this->master_obj->radius_x;
    radius_y[1] = this->master_obj->radius_y + this->master_obj->radius_y;
    temp = this->objects->list;

    while (temp != 0) {
        RGE_Object_Node* next;
        next = temp->next;
        while (i > 0) {
                    if (
                        this->find_drop_location(mode, x, y,
                                                  temp->node->master_obj,
                                                  temp->node, drop_x[1],
                                                  drop_y[1], radius_x[1],
                                                  radius_y[1])
                    ) {
                        RGE_Static_Object* held = temp->node;
                        held->set_location(this->world_x, this->world_y, this->world_z);
                        held->exit_obj();
                        held->teleport(x, y, this->world_z);
                        ++count;
                        if (i < 9) {
                            RGE_Master_Static_Object* master = held->master_obj;
                            int index = i++;
                            drop_x[index + 1] = x;
                            drop_y[index + 1] = y;
                            radius_x[index + 1] = master->radius_x + master->radius_x;
                            radius_y[index + 1] = master->radius_y + master->radius_y;
                        }
                        break;
                    }
                    --i;
                    if (i <= 0) break;
                    drop_x[i] = drop_x[i + 1];
                    drop_y[i] = drop_y[i + 1];
                    radius_y[i] = radius_y[i + 1];
                    radius_x[i] = radius_x[i + 1];
        }
        temp = next;
    }
    return count;
}


// 004C6400 RGE_Static_Object::find_drop_location
// BINARY NOTE: the x and y outputs are float references in the shipped symbol.

unsigned char RGE_Static_Object::find_drop_location(
    int terrain, float& x, float& y, RGE_Master_Static_Object* master,
    RGE_Static_Object* object, float drop_x, float drop_y,
    float radius_x, float radius_y)
{
    radius_x = radius_x + master->radius_x;
    radius_y = radius_y + master->radius_y;
    float radius_2x = radius_x + radius_x;
    float radius_2y = radius_y + radius_y;
    short outer = 1;

    while (outer < 2) {
        short attempt = 0;
        do {
            switch ((debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0xf3a) * 4) / 0x7fff) {
            case 0: {
                x = radius_x + drop_x;
                int value = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0xf3e);
                y = (float)value * radius_2y * (1.0f / 32767.0f) - radius_y + drop_y;
                break;
            }
            case 1: {
                x = drop_x - radius_x;
                int value = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0xf42);
                y = drop_y +
                     ((float)value * radius_2y * (1.0f / 32767.0f) - radius_y);
                break;
            }
            case 2: {
                y = radius_y + drop_y;
                int value = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0xf46);
                x = (float)value * radius_2x * (1.0f / 32767.0f) - radius_x + drop_x;
                break;
            }
            case 3: {
                y = drop_y - radius_y;
                int value = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0xf4a);
                x = (float)value * radius_2x * (1.0f / 32767.0f) - radius_x + drop_x;
                break;
            }
            }

            if (x >= 0.0f && y >= 0.0f) {
                RGE_Map* map = this->owner->world->map;
                if (x < (float)map->map_width &&
                    y < (float)map->map_height) {
                    if (terrain != -1 &&
                        terrain != (int)this->lookupZone((int)x, (int)y)) {
                        goto retry_attempt;
                    }
                    // BINARY NOTE: success returns from inside the retry loop.
                    if (master->check_placement(this->owner, x, y,
                        0, 1, 1, 1, 0, 1, 1) == 0 &&
                        object->passableTile(x, y, 0) == 1) {
                        return 1;
                    }
                }
            }
retry_attempt:
            ++attempt;
        } while (attempt < 50);

        radius_x = radius_x + (master->radius_x + master->radius_x);
        radius_y = radius_y + (master->radius_y + master->radius_y);
        radius_2x = radius_2x + (master->radius_x * 4.0f);
        radius_2y = radius_2y + (master->radius_y * 4.0f);
        ++outer;
    }

    return 0;
}


// 004C66C0 RGE_Check_List::RGE_Check_List

RGE_Check_List::RGE_Check_List() {
    this->list = 0;
}


// 004C66D0 RGE_Check_List::~RGE_Check_List

RGE_Check_List::~RGE_Check_List() {
    RGE_Check_Node* next;

    while (this->list != 0) {
        next = this->list->next;
        free(this->list);
        this->list = next;
    }
}


// 004C6700 RGE_Check_List::add_node

void RGE_Check_List::add_node(RGE_Static_Object* object, float dx, float dy, unsigned char flag) {
    RGE_Check_Node* node = static_cast<RGE_Check_Node*>(calloc(1, sizeof(RGE_Check_Node)));
    node->next = this->list;
    node->node = object;
    node->dx = dx;
    node->dy = dy;
    node->flag = flag;
    this->list = node;
}


// 004C6740 RGE_Static_Object::make_object_bounds_list


RGE_Check_List* RGE_Static_Object::make_object_bounds_list(float max_dist) {
    float radius_x;
    float radius_y;
    short x2;
    short y1;
    short x1;
    short y2;
    RGE_Map* map;
    RGE_Check_List* check_list;
    RGE_Check_List* result;

    radius_x = this->master_obj->radius_x;
    radius_y = this->master_obj->radius_y;
    if (radius_x <= 0.0f || radius_y <= 0.0f ||
        this->master_obj->radius_z <= 0.0f) {
        return 0;
    }

    x1 = (short)(this->world_x - 3.0f);
    y1 = (short)(this->world_y - 3.0f);
    x2 = (short)(this->world_x + 3.0f);
    y2 = (short)(this->world_y + 3.0f);

    map = this->owner->world->map;
    check_list = new RGE_Check_List;
    result = check_list;

    if (x1 < 0) {
        x1 = 0;
    }
    if (x2 >= map->map_width) {
        x2 = (short)(map->map_width - 1);
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (y2 >= map->map_height) {
        y2 = (short)(map->map_height - 1);
    }

    if (y1 <= y2) {
        int row = (int)y1;
        int row_count = (int)y2 - (int)y1 + 1;
        do {
            RGE_Tile* tile = map->map_row_offset[row] + (int)x1;
            if (x1 <= x2) {
                int col_count = (int)x2 - (int)x1 + 1;
                do {
                    RGE_Object_Node* object_node = tile->objects.list;
                    while (object_node != 0) {
                        RGE_Static_Object* object = object_node->node;
                        if (object != this) {
                            RGE_Master_Static_Object* object_master =
                                object->master_obj;
                            float object_radius_y = object_master->radius_y;
                            float object_radius_x = object_master->radius_x;
                            if (object_radius_y > 0.0f &&
                                object_radius_x > 0.0f) {
                                float z = object->world_z - this->world_z;
                                if (z >= -object_master->radius_z &&
                                    z <= this->master_obj->radius_z) {
                                    float dx = object->world_x - this->world_x;
                                    float dy = object->world_y - this->world_y;
                                    unsigned char flag;

                                    if (dx < 0.0f) {
                                        dx = -dx;
                                        flag = 1;
                                    } else {
                                        flag = 0;
                                    }
                                    if (dy < 0.0f) {
                                        flag = (unsigned char)(flag + 2);
                                        dy = -dy;
                                    }

                                    dx -= object_radius_x + radius_x;
                                    dy -= object_radius_y + radius_y;
                                    if (dx < max_dist && dy < max_dist &&
                                        (0.0f <= dy ||
                                         0.0f <= dx)) {
                                        check_list->add_node(object, dx, dy,
                                                             flag);
                                    }
                                }
                            }
                        }
                        object_node = object_node->next;
                    }
                    ++tile;
                    --col_count;
                } while (col_count != 0);
            }
            ++row;
            --row_count;
        } while (row_count != 0);
    }

    if (check_list->list == 0) {
        if (check_list != 0) {
            delete check_list;
        }
        result = 0;
    }
    return result;
}


// 004C6AA0 RGE_Static_Object::boundToFacet
// BINARY NOTE: PDB owner is RGE_Static_Object::boundToFacet.
// BINARY NOTE: The owned body is [004C6AA0, 004C6B41); later bytes are padding.
// BINARY NOTE: Keep the narrow sprite facet-count read at sprite + 0x60.

extern "C" double __cdecl atan2(double, double);


int RGE_Static_Object::boundToFacet(float x, float y, int facet_num)
{
    int best = -1;
    float best_diff = 0.0f;
    float angle = (float)atan2(this->world_y - y, this->world_x - x);
    if (angle < 0.0f) {
        angle = angle - -6.2831855f;
    }
    float cur = 0.0f;
    if (facet_num == -1) {
        facet_num = this->sprite->facet_num;
    }
    float step = 6.2831855f / (float)facet_num;
    for (int i = 0; i < facet_num; i++) {
        float diff = angle - cur;
        if (diff < 0.0f) {
            diff = -diff;
        }
        if (best == -1 || diff < best_diff) {
            best_diff = diff;
            best = i;
        }
        cur = cur + step;
    }
    return best;
}


// 004C6B50 RGE_Static_Object::numberFacets
// BINARY NOTE: PDB owner is RGE_Static_Object::numberFacets.
// BINARY NOTE: The owned body is [004C6B50, 004C6B5F); the next byte is padding.
// BINARY NOTE: Keep the narrow sprite facet-count read at sprite + 0x60.


int RGE_Static_Object::numberFacets() {
    if (this->sprite)
        return (int)this->sprite->facet_num;
    return 0;
}


// 004C6B60 RGE_Static_Object::underAttack
// BINARY NOTE: PDB owner is RGE_Static_Object::underAttack() const.
// BINARY NOTE: The owned body is [004C6B60, 004C6B67); 004C6B67 begins padding.
// BINARY NOTE: The body is one narrow byte read at this + 0x86 followed by ret.


unsigned char RGE_Static_Object::underAttack() const { return this->underAttackValue; }


// 004C6B70 RGE_Static_Object::setUnderAttack
// BINARY NOTE: PDB owner is RGE_Static_Object::setUnderAttack(unsigned char).
// BINARY NOTE: The owned body is [004C6B70, 004C6B7D); 004C6B7D begins padding.
// BINARY NOTE: Keep the virtual, non-const setter ABI and the narrow +0x86 store.


void RGE_Static_Object::setUnderAttack(unsigned char v) { this->underAttackValue = v; }


// 004C6B80 RGE_Static_Object::addToObstructionMap
// BINARY NOTE: PDB-qualified owner is RGE_Static_Object::addToObstructionMap(int).
// BINARY NOTE: The body is [004C6B80, 004C6C8A); 004C6C90 starts the next symbol.

int RGE_Static_Object::addToObstructionMap(int mode)
{
    if (this->master_obj->radius_z <= 0.0f) {
        return 0;
    }
    if (this->inObstructionMapValue == 1) {
        return 0;
    }

    int obMapMinX = (int)((this->world_x - this->master_obj->radius_x) * 4.0f);
    if (obMapMinX < 0) {
        obMapMinX = 0;
    }
    int obMapMinY = (int)((this->world_y - this->master_obj->radius_y) * 4.0f);
    if (obMapMinY < 0) {
        obMapMinY = 0;
    }
    int obMapMaxX = (int)((this->master_obj->radius_x + this->world_x) * 4.0f);
    int obMapMaxY = (int)((this->master_obj->radius_y + this->world_y) * 4.0f);

    for (int x = obMapMinX; x < obMapMaxX; x++) {
        for (int y = obMapMinY; y < obMapMaxY; y++) {
            if (mode != 1) {
                pathSystem.incrementObstruction(x, y);
            }
            if (mode != 0) {
                aiPathSystem.incrementObstruction(x, y);
            }
        }
    }

    this->lastInObstructionMapValue = this->inObstructionMapValue;
    this->inObstructionMapValue = 1;
    return 1;
}


// 004C6C90 RGE_Static_Object::removeFromObstructionMap
// BINARY NOTE: PDB-qualified owner is RGE_Static_Object::removeFromObstructionMap(int).
// BINARY NOTE: The owned body is [004C6C90, 004C6D9A); 004C6DA0 starts changeInfluenceMap.

int RGE_Static_Object::removeFromObstructionMap(int mode)
{
    if (this->master_obj->radius_z <= 0.0f) {
        return 0;
    }
    if (!this->inObstructionMapValue) {
        return 0;
    }

    int obMapMinX = (int)((this->world_x - this->master_obj->radius_x) * 4.0f);
    if (obMapMinX < 0) {
        obMapMinX = 0;
    }
    int obMapMinY = (int)((this->world_y - this->master_obj->radius_y) * 4.0f);
    if (obMapMinY < 0) {
        obMapMinY = 0;
    }
    int obMapMaxX = (int)((this->master_obj->radius_x + this->world_x) * 4.0f);
    int obMapMaxY = (int)((this->master_obj->radius_y + this->world_y) * 4.0f);

    for (int x = obMapMinX; x < obMapMaxX; x++) {
        for (int y = obMapMinY; y < obMapMaxY; y++) {
            if (mode != 1) {
                pathSystem.decrementObstruction(x, y);
            }
            if (mode != 0) {
                aiPathSystem.decrementObstruction(x, y);
            }
        }
    }

    this->lastInObstructionMapValue = this->inObstructionMapValue;
    this->inObstructionMapValue = 0;
    return 1;
}


// 004C6DA0 RGE_Static_Object::changeInfluenceMap

extern "C" double __cdecl floor(double);
extern "C" double __cdecl ceil(double);


void RGE_Static_Object::changeInfluenceMap(InfluenceMap* map, int mode, int gradient, int useRadius)
{
    int minYTile;
    int minXTile;
    int maxYTile;
    int maxXTile;
    float objectMaxY;
    float objectMinY;
    float objectMaxX;
    float objectMinX;

    int minY;
    int maxY;
    int minX;
    int maxX;

    if (useRadius == 0) {
        minY = (int)floor(this->world_x - this->master_obj->radius_x);
        maxY = (int)ceil(this->master_obj->radius_x + this->world_x);
        minX = (int)floor(this->world_y - this->master_obj->radius_y);
        maxX = (int)ceil(this->master_obj->radius_y + this->world_y);
    } else {
        minY = (int)floor(this->world_x - this->master_obj->radius_x - this->master_obj->los);
        maxY = (int)ceil(this->master_obj->radius_x + this->master_obj->los + this->world_x);
        minX = (int)floor(this->world_y - this->master_obj->radius_y - this->master_obj->los);
        maxX = (int)ceil(this->master_obj->radius_y + this->master_obj->los + this->world_y);
    }

    if (useRadius == 0) {
        objectMinX = this->world_x - this->master_obj->radius_x;
        objectMaxX = this->master_obj->radius_x + this->world_x;
        objectMinY = this->world_y - this->master_obj->radius_y;
        objectMaxY = this->master_obj->radius_y + this->world_y;
    } else {
        objectMinX = this->world_x - this->master_obj->radius_x - this->master_obj->los;
        objectMaxX = this->master_obj->radius_x + this->master_obj->los + this->world_x;
        objectMinY = this->world_y - this->master_obj->radius_y - this->master_obj->los;
        objectMaxY = this->master_obj->radius_y + this->master_obj->los + this->world_y;
    }

    for (int xTile = minX; xTile < maxX; xTile++) {
        for (int yTile = minY; yTile < maxY; yTile++) {
            if (gradient) {
                float left = (float)yTile;
                if (objectMinX > (float)yTile) left = objectMinX;
                float right = (float)(yTile + 1);
                if (objectMaxX < right) right = objectMaxX;
                float top = (float)xTile;
                if (objectMinY > (float)xTile) top = objectMinY;
                float bottom = (float)(xTile + 1);
                if (objectMaxY < bottom) bottom = objectMaxY;
                int value = (int)((right - left) * (bottom - top) * 255.0f);
                if (mode == 1) {
                    map->incrementValue(yTile, xTile, value);
                } else {
                    map->decrementValue(yTile, xTile, value);
                }
            } else {
                if (mode == 1) {
                    map->incrementValue(yTile, xTile, 255);
                } else {
                    map->decrementValue(yTile, xTile, 255);
                }
            }
        }
    }
}


// 004C7030 RGE_Static_Object::objectCollisionList


RGE_Check_List* RGE_Static_Object::objectCollisionList(float extra)
{
    if (this->master_obj->radius_x <= 0.0f ||
        this->master_obj->radius_y <= 0.0f ||
        this->master_obj->radius_z <= 0.0f) {
        return 0;
    }
    RGE_Check_List* result = new RGE_Check_List;
    result->add_node(this, 0.0f, 0.0f, 0);
    (void)extra;
    return result;
}


// 004C7340 RGE_Static_Object::logDebug
// BINARY NOTE: logDebug is a public virtual cdecl member.


void __cdecl RGE_Static_Object::logDebug(const char* format, ...)
{
    char textOut[1024];

    if (logDebugID == -1 || logDebugID == this->id) {
        if (debugOut == 0) {
            debugOut = fopen("c:\\aoeunit.txt", "w");
            if (debugOut == 0) {
                return;
            }
            fprintf(debugOut, "WORLD TIME: %ld\n", this->owner->world->world_time);
        }

        va_list args;
        va_start(args, format);
        vsprintf(textOut, format, args);
        va_end(args);

        if (strlen(textOut) != 0) {
            fprintf(debugOut, "UNIT #%5d: %s\n", this->id, textOut);
        } else {
            fprintf(debugOut, "UNIT #%5d\n", this->id);
        }
    }
}


// 004C7420 RGE_Static_Object::unitAI

UnitAIModule* RGE_Static_Object::unitAI() { return this->unitAIValue; }


// 004C7430 RGE_Static_Object::lookupZone



unsigned char RGE_Static_Object::lookupZone(XYPoint pt) {
    if (pt.x < 0 || pt.y < 0) {
        return 0;
    }

    RGE_Zone_Map* zoneMap;

    if (zoneMapIndex == -1) {
        RGE_Game_World* world = owner->world;
        zoneMap = world->map->map_zones->get_zone_map(
            world->terrains[master_obj->terrain],
            world->terrain_size,
            zoneMapIndex);
    } else {
        RGE_Game_World* world = owner->world;
        zoneMap = world->map->map_zones->get_zone_map(zoneMapIndex);
    }

    if (zoneMap == 0) {
        return 0;
    }

    return zoneMap->get_zone_info(pt.x, pt.y);
}


// 004C74B0 RGE_Static_Object::lookupZone


unsigned char RGE_Static_Object::lookupZone(int x, int y) {
    RGE_Game_World* world;
    RGE_Zone_Map* zone_map;

    if (x < 0 || y < 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map(
            world->terrains[this->master_obj->terrain],
            world->terrain_size,
            this->zoneMapIndex);
    } else {
        zone_map = this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }

    if (zone_map == 0) {
        return 0;
    }

    return zone_map->get_zone_info(x, y);
}


// 004C7530 RGE_Static_Object::currentZone



unsigned char RGE_Static_Object::currentZone() {
    RGE_Zone_Map* zoneMap;

    if (zoneMapIndex == -1) {
        RGE_Game_World* world = owner->world;
        zoneMap = world->map->map_zones->get_zone_map(
            world->terrains[master_obj->terrain],
            world->terrain_size,
            zoneMapIndex);
    } else {
        RGE_Game_World* world = owner->world;
        zoneMap = world->map->map_zones->get_zone_map(zoneMapIndex);
    }

    if (zoneMap != 0) {
        return zoneMap->get_zone_info((int)world_x, (int)world_y);
    }

    return 0;
}


// 004C75B0 RGE_Static_Object::withinRangeOfZoneAtPoint
// BINARY NOTE: the point input is a reference to struct XYPoint.


int RGE_Static_Object::withinRangeOfZoneAtPoint(unsigned char param_1, float param_2, XYPoint& param_3) {
    RGE_Zone_Map* zone_map;

    if (this->zoneMapIndex == -1) {
        RGE_Game_World* world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map(
            world->terrains[this->master_obj->terrain], world->terrain_size,
            this->zoneMapIndex);
    } else {
        zone_map = this->owner->world->map->map_zones->get_zone_map(
            this->zoneMapIndex);
    }

    if (zone_map != 0) {
        return zone_map->withinRange(param_1, param_3, param_2);
    }
    return 0;
}


// 004C7630 RGE_Static_Object::withinRangeOfZone


int RGE_Static_Object::withinRangeOfZone(unsigned char type, float range)
{
    int ix = (int)this->world_x;
    int iy = (int)this->world_y;
    RGE_Zone_Map* zone;

    if (this->zoneMapIndex == -1) {
        RGE_Game_World* world = this->owner->world;
        zone = world->map->map_zones->get_zone_map(
            world->terrains[this->master_obj->terrain], world->terrain_size,
            this->zoneMapIndex);
    } else {
        RGE_Game_World* world = this->owner->world;
        zone = world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }

    if (zone != 0) {
        XYPoint point;
        point.x = ix;
        point.y = iy;
        return zone->withinRange(type, point, range);
    }
    return 0;
}


// 004C76C0 RGE_Static_Object::findClosestPointInTerrainType
// BINARY NOTE: the output point is a reference to struct XYPoint.


int RGE_Static_Object::findClosestPointInTerrainType(XYPoint point, XYPoint& out, int a, int b, int c) {
    RGE_Zone_Map* zone_map;
    if (this->zoneMapIndex == -1) {
        RGE_Game_World* world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map(
            world->terrains[this->master_obj->terrain], world->terrain_size,
            this->zoneMapIndex);
    } else {
        zone_map = this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }
    if (zone_map != 0) {
        return zone_map->findClosestPointInTerrainType(point, out, a, b, c);
    }
    return 0;
}


// 004C7740 RGE_Static_Object::isGroupCommander

int RGE_Static_Object::isGroupCommander(void) {
    return id == groupCommanderValue;
}


// 004C7760 RGE_Static_Object::inGroup


int RGE_Static_Object::inGroup() { return this->groupMembers.numberValue > 0; }


// 004C7770 RGE_Static_Object::unitIsInGroup

int RGE_Static_Object::unitIsInGroup(int value) {
    int count = this->groupMembers.numberValue;
    int index = 0;

    if (count > 0) {
        for (; index < count; index++) {
            if (index >= this->groupMembers.maximumSizeValue) {
                goto not_found_shared;
            }
            if (this->groupMembers.value[index] == value) {
                return 1;
            }
        }
    }
    return 0;

not_found_shared:
    return 0;
}


// 004C77B0 RGE_Static_Object::createGroup


int RGE_Static_Object::createGroup(int* list, int count, int commander, float range)
{
    if (list == 0 || count == 0) {
        return 0;
    }

    groupMembers.numberValue = 0;

    if (count > 0) {
        int* current = list;
        int remaining = count;
        do {
            int id = *current;
            if (id >= 0) {
                int number = groupMembers.numberValue;
                int i = 0;
                while (i < number) {
                    if (i >= groupMembers.maximumSizeValue) {
                        break;
                    }
                    if (groupMembers.value[i] == id) {
                        goto next;
                    }
                    i++;
                }

                if (number > groupMembers.maximumSizeValue - 1) {
                    int newMaximum = number + 1;
                    int* newValue = new int[newMaximum];
                    if (newValue != 0) {
                        i = 0;
                        for (; i < groupMembers.maximumSizeValue && i < newMaximum; i++) {
                            newValue[i] = groupMembers.value[i];
                        }
                        delete[] groupMembers.value;
                        groupMembers.value = newValue;
                        groupMembers.maximumSizeValue = newMaximum;
                    }
                }

                groupMembers.value[groupMembers.numberValue] = id;
                groupMembers.numberValue = groupMembers.numberValue + 1;
            }

        next:
            current = current + 1;
            remaining = remaining - 1;
        } while (remaining != 0);
    }

    groupCommanderValue = commander;
    groupRangeValue = range;
    return 1;
}


// 004C78B0 RGE_Static_Object::commanderCreateGroup



int RGE_Static_Object::commanderCreateGroup(int* list, int count, int param3, float param4) {
    if (list == 0 || count == 0) {
        return 0;
    }

    if (count > 0) {
        int* p = list;
        int r = count;
        do {
            int id = *p;
            RGE_Static_Object* obj = owner->world->object(id);
            if (obj != 0) {
                obj->createGroup(list, count, param3, param4);
            }
            p++;
            r--;
        } while (r != 0);
    }

    return 1;
}


// 004C7920 RGE_Static_Object::addToGroup

int RGE_Static_Object::addToGroup(int groupIndex, float unused)
{
    if (this->groupMembers.numberValue >= 25) {
        return 0;
    }

    {
        int count = this->groupMembers.numberValue;
        int i = 0;
        while (i < count) {
            if (i >= this->groupMembers.maximumSizeValue) {
                break;
            }
            if (this->groupMembers.value[i] == groupIndex) {
                goto done;
            }
            i++;
        }

        if (count > this->groupMembers.maximumSizeValue - 1) {
            int newMax = count + 1;
            int* newArray = new int[newMax];
            if (newArray != 0) {
                for (i = 0; i < this->groupMembers.maximumSizeValue && i < newMax; i++) {
                    newArray[i] = this->groupMembers.value[i];
                }
                delete[] this->groupMembers.value;
                this->groupMembers.value = newArray;
                this->groupMembers.maximumSizeValue = newMax;
            }
        }

        this->groupMembers.value[this->groupMembers.numberValue] = groupIndex;
        this->groupMembers.numberValue++;
    }

done:
    return 1;
}


// 004C79D0 RGE_Static_Object::commanderAddToGroup


int RGE_Static_Object::commanderAddToGroup(int id, float range)
{
    RGE_Static_Object* unitObject = this->owner->world->object(id);
    int temp[25];
    ManagedArray<int>& group = this->groupMembers;
    if (unitObject == 0) {
        return 0;
    }

    if (group.numberValue >= 25) {
        return 0;
    }

    int i = 0;
    if (group.numberValue > 0) {
        do {
            int member = group[i];
            temp[i] = member;
            if (member != this->id) {
                RGE_Static_Object* object =
                    this->owner->world->object(group[i]);
                if (object != 0) {
                    object->addToGroup(id, range);
                }
            }
            ++i;
        } while (i < group.numberValue);
    }

    temp[i] = id;
    this->addToGroup(id, range);
    unitObject->createGroup(temp, i + 1, this->id, range);
    return 1;
}


// 004C7B60 RGE_Static_Object::removeFromGroup



int RGE_Static_Object::removeFromGroup(int param_1) {
    int count = groupMembers.maximumSizeValue;
    int index = 0;
    int result;

    if (count > 0) {
        int* ptr = groupMembers.value;
        while (1) {
            if (*ptr == param_1) break;
            ++index;
            ++ptr;
            if (index < count) continue;
            break;
        }
    }
    if (index >= count) {
        result = 0;
        goto final;
    }

    if (index < groupMembers.maximumSizeValue - 1) {
        while (index < groupMembers.maximumSizeValue - 1) {
            groupMembers.value[index] = groupMembers.value[index + 1];
            ++index;
        }
    }

    --groupMembers.numberValue;
    if (groupMembers.numberValue < 0) {
        groupMembers.numberValue = 0;
    }
    result = 1;

final:
    if (groupMembers.numberValue <= 0) {
        groupCommanderValue = -1;
    }
    return result;
}


// 004C7BD0 RGE_Static_Object::commanderRemoveFromGroup


int RGE_Static_Object::commanderRemoveFromGroup(int id)
{
    if (id == this->id && this->id == this->groupCommanderValue) {
        return this->commanderDestroyGroup();
    }

    int i = 0;
    if (this->groupMembers.numberValue > 0) {
        do {
            if (i > this->groupMembers.maximumSizeValue - 1) {
                int newMax = i + 1;
                int* newValue = new int[newMax];
                if (newValue != 0) {
                    int j = 0;
                    if (this->groupMembers.maximumSizeValue > 0) {
                        do {
                            if (j < newMax) {
                                ++j;
                                newValue[j - 1] = this->groupMembers.value[j - 1];
                            } else {
                                break;
                            }
                        } while (j < this->groupMembers.maximumSizeValue);
                    }
                    delete[] this->groupMembers.value;
                    this->groupMembers.value = newValue;
                    this->groupMembers.maximumSizeValue = newMax;
                }
            }

            RGE_Static_Object* object = this->owner->world->object(this->groupMembers.value[i]);
            if (object != 0 && object->id != this->id) {
                int max = object->groupMembers.maximumSizeValue;
                int j = 0;
                if (max > 0) {
                    int* p = object->groupMembers.value;
                    while (1) {
                        if (*p == id) {
                            break;
                        }
                        ++j;
                        ++p;
                        if (j < max) {
                            continue;
                        }
                        break;
                    }
                }

                if (j < max) {
                    if (j < max - 1) {
                        do {
                            object->groupMembers.value[j] = object->groupMembers.value[j + 1];
                            ++j;
                        } while (j < object->groupMembers.maximumSizeValue - 1);
                    }

                    int newCount = object->groupMembers.numberValue - 1;
                    object->groupMembers.numberValue = newCount;
                    if (newCount < 0) {
                        object->groupMembers.numberValue = 0;
                    }
                }
            }

            ++i;
        } while (i < this->groupMembers.numberValue);
    }

    this->removeFromGroup(id);
    return 1;
}


// 004C7CE0 RGE_Static_Object::destroyGroup

int RGE_Static_Object::destroyGroup() {
    groupMembers.numberValue = 0;
    groupCommanderValue = -1;
    return 1;
}


// 004C7D00 RGE_Static_Object::commanderDestroyGroup
int RGE_Static_Object::commanderDestroyGroup(){ this->destroyGroup(); return 1; }


// 004C7DB0 RGE_Static_Object::addToPathingGroup


void RGE_Static_Object::addToPathingGroup(int groupIndex)
{
    int i = 0;
    int count = this->pathingGroupMembers.numberValue;
    if (count > 0) {
        int max = this->pathingGroupMembers.maximumSizeValue;
        while (1) {
            if (i >= max)
                break;
            if (this->pathingGroupMembers.value[i] == groupIndex)
                return;
            i++;
            if (i < count)
                continue;
            break;
        }
    }

    if (count > this->pathingGroupMembers.maximumSizeValue - 1) {
        int newMax = count + 1;
        int* newMembers = new int[newMax];
        if (newMembers != 0) {
            int max = this->pathingGroupMembers.maximumSizeValue;
            int j = 0;
            if (max > 0) {
                for (; j < max; j++) {
                    if (j >= newMax)
                        break;
                    newMembers[j] = this->pathingGroupMembers.value[j];
                    max = this->pathingGroupMembers.maximumSizeValue;
                }
            }
            delete[] this->pathingGroupMembers.value;
            this->pathingGroupMembers.value = newMembers;
            this->pathingGroupMembers.maximumSizeValue = newMax;
        }
    }

    this->pathingGroupMembers.value[this->pathingGroupMembers.numberValue] = groupIndex;
    this->pathingGroupMembers.numberValue++;
}


// 004C7E50 RGE_Static_Object::removeAllFromPathingGroup


void RGE_Static_Object::removeAllFromPathingGroup(void) {
    if (owner->computerPlayer() == 1) {
        pathingGroupMembers.numberValue = 0;
    }
}


// 004C7E70 RGE_Static_Object::remove_shadows

void RGE_Static_Object::remove_shadows(void) {
    int x0 = (int)this->world_x;
    int y0 = (int)this->world_y;
    this->owner->world->map->request_redraw(x0 - 2, y0 - 2, x0 + 1, y0 + 1, 0);
}


// 004C7EB0 RGE_Static_Object::set_sleep_flag



void RGE_Static_Object::set_sleep_flag(unsigned char newFlag) {
    if (sleep_flag == newFlag) return;

    if (newFlag == 0) {
        if (goto_sleep_flag != 0) {
            sleep_flag = 0;
            goto_sleep_flag = 0;
            return;
        }

        RGE_Object_Node* oldField = player_object_node;
        owner->removeObject(this, (int)(unsigned char)sleep_flag,
                            (int)dopple_flag, oldField);

        sleep_flag = 0;
        player_object_node = owner->addObject(this, 0, (int)dopple_flag);
        return;
    }

    goto_sleep_flag = 1;
    sleep_flag = newFlag;
}


// 004C7F30 RGE_Static_Object::get_action_checksum

// BINARY NOTE: the shipped getter returns long and is virtual.
long RGE_Static_Object::get_action_checksum() { return 0; }


// 004C7F40 RGE_Static_Object::get_waypoint_checksum

// BINARY NOTE: the shipped getter returns long and is virtual.
long RGE_Static_Object::get_waypoint_checksum() { return 0; }
