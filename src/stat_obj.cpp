#include "../include/act_obj.h"
#include "../include/program_mode.h"
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

static char STR_STAT_OBJ[] = "C:\\msdev\\work\\age1_x1\\stat_obj.cpp";

extern int startLoggingAI;
extern int logDebugID;
extern FILE* debugOut;

RGE_Static_Object::RGE_Static_Object(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner, float x, float y, float z,
                                     int do_setup)
    : sprite(0), old_sprite(0), unitAIValue(0), groupCommanderValue(-1), zoneMapIndex(-1), groupRangeValue(5.0f),
      inObstructionMapValue(0), lastInObstructionMapValue(0), underAttackValue(0) {
    this->player_object_node = 0;
    if (do_setup != 0) {
        this->setup(tobj, obj_owner, x, y, z);
    }
}

RGE_Static_Object::RGE_Static_Object(int infile, RGE_Game_World* gworld, int do_setup)
    : sprite(0), old_sprite(0), unitAIValue(0), groupCommanderValue(-1), zoneMapIndex(-1), groupRangeValue(5.0f),
      inObstructionMapValue(0), lastInObstructionMapValue(0), underAttackValue(0) {
    this->player_object_node = 0;
    if (do_setup != 0) {
        this->setup(infile, gworld);
    }
}

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

        this->owner->removeObject(this, this->sleep_flag, this->dopple_flag, this->player_object_node);

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
            node->node->exit_obj();
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

void RGE_Static_Object::recycle_in_to_game(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner, float x, float y,
                                           float z) {
    this->old_sprite = 0;
    this->unitAIValue = 0;
    this->underAttackValue = 0;
    this->sprite = 0;
    this->groupCommanderValue = -1;
    this->groupRangeValue = 5.0f;
    this->owner = obj_owner;
    this->master_obj = tobj;
    this->tile = 0;
    this->inside_obj = 0;

    this->hp = (float)(int)tobj->hp;
    this->sleep_flag = (this->hp > 0.0f);
    this->dopple_flag = (tobj->master_type == 0x19);

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

    int seed = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 387);
    int old_debug = debug_random_on;
    debug_random_on = 0;

    RGE_Sound* sound = this->master_obj->created_sound;
    if (sound != 0 && this->owner->id == this->owner->world->curr_player) {
        sound->play(1);
    }

    debug_random_on = old_debug;
    debug_srand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 397, seed);
}

void RGE_Static_Object::recycle_out_of_game() {
    if (this->master_obj->recyclable != 0 &&
        this->owner->world->recycle_object_out_of_game(this->master_obj->master_type, this) != 0) {
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
            this->owner->removeObject(this, this->sleep_flag, this->dopple_flag, this->player_object_node);
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

// setup is a protected virtual member in the shipped symbol.

int RGE_Static_Object::setup(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner, float x, float y, float z) {
    int old_debug;
    int seed;
    this->type = 10;
    this->owner = obj_owner;
    this->master_obj = tobj;
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

    seed = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 554);
    old_debug = debug_random_on;
    debug_random_on = 0;
    if (this->master_obj->created_sound != 0 && this->owner->id == this->owner->world->curr_player) {
        this->master_obj->created_sound->play(1);
    }
    debug_random_on = old_debug;
    debug_srand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 565, seed);
    return 1;
}

// this loader entry is a protected virtual setup member.

int RGE_Static_Object::setup(int infile, RGE_Game_World* gworld) {
    long long_val;
    int byte_val;
    int numberUnits;
    int tempInt;
    short short_val;

    this->type = 10;
    rge_read(infile, &long_val, 1);
    this->owner = gworld->players[long_val & 0xff];

    rge_read(infile, &short_val, 2);
    this->master_obj = this->owner->master_objects[short_val];

    rge_read(infile, &short_val, 2);
    if (short_val >= 0) {
        this->sprite = gworld->sprites[short_val];
    } else {
        this->sprite = 0;
    }

    this->old_sprite = 0;
    rge_read(infile, &tempInt, 4);
    if (tempInt == -1) {
        this->inside_obj = 0;
    } else {
        this->inside_obj = (RGE_Static_Object*)tempInt;
    }

    rge_read(infile, &this->hp, 4);
    rge_read(infile, &this->object_state, 1);
    rge_read(infile, &this->sleep_flag, 1);
    if (save_game_version >= 7.09f) {
        rge_read(infile, &this->dopple_flag, 1);
    }
    rge_read(infile, &this->goto_sleep_flag, 1);
    rge_read(infile, &this->id, 4);
    rge_read(infile, &this->facet, 1);
    rge_read(infile, &this->world_x, 4);
    rge_read(infile, &this->world_y, 4);
    rge_read(infile, &this->world_z, 4);
    rge_read(infile, &this->screen_x_offset, 2);
    rge_read(infile, &this->screen_y_offset, 2);
    rge_read(infile, &this->shadow_x_offset, 2);
    rge_read(infile, &this->shadow_y_offset, 2);
    rge_read(infile, &this->selected_group, 1);
    rge_read(infile, &this->attribute_type_held, 2);
    rge_read(infile, &this->attribute_amount_held, 4);
    rge_read(infile, &this->worker_num, 1);
    rge_read(infile, &this->curr_damage_percent, 1);
    rge_read(infile, &this->underAttackValue, 1);
    this->tile = 0;
    rge_read(infile, &this->groupCommanderValue, 4);
    rge_read(infile, &this->groupRangeValue, 4);

    if (save_game_version == 6.991f) {
        rge_read(infile, &numberUnits, 4);
        rge_read(infile, &numberUnits, 4);
        rge_read(infile, &numberUnits, 4);
        {
            int temp_int;
            int temp_dword;
            rge_read(infile, &temp_int, 4);
            rge_read(infile, &temp_dword, 4);
            rge_read(infile, &temp_dword, 4);
        }
    }

    rge_read(infile, &byte_val, 4);
    numberUnits = 0;
    if (0 < byte_val) {
        do {
            int tempInt;
            rge_read(infile, &tempInt, 4);
            // The duplicate scan checks count before capacity.
            this->groupMembers.add(tempInt);
            numberUnits = numberUnits + 1;
        } while (numberUnits < byte_val);
    }

    rge_read(infile, &byte_val, 4);
    numberUnits = 0;
    if (0 < byte_val) {
        do {
            int tempInt;
            rge_read(infile, &tempInt, 4);
            this->pathingGroupMembers.add(tempInt);
            numberUnits = numberUnits + 1;
        } while (numberUnits < byte_val);
    }

    this->sprite_list = this->create_sprite_list();
    this->sprite_list->load(infile, gworld->sprites);
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

void RGE_Static_Object::change_unique_id() {
    this->owner->removeObject(this, this->sleep_flag, this->dopple_flag, this->player_object_node);

    if (this->master_obj->recyclable != 0) {
        this->id = this->owner->world->get_next_reusable_object_id();
    } else {
        this->id = this->owner->world->get_next_object_id();
    }
    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);
}

RGE_Object_List* RGE_Static_Object::create_object_list(void) {
    return new RGE_Object_List;
}

RGE_Active_Sprite_List* RGE_Static_Object::create_sprite_list(void) {
    return new RGE_Active_Sprite_List(this);
}

void RGE_Static_Object::get_starting_attribute() {
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

void RGE_Static_Object::give_attribute_to_owner(void) {
    for (int i = 0; i < 3; ++i) {
        RGE_Master_Static_Object* master = this->master_obj;
        unsigned char status = master->attribute_flag[i];
        if (status >= 1 && status <= 2) {
            short attr_id = master->attribute_type_held[i];
            if (attr_id >= 0) {
                this->owner->add_attribute_num(attr_id, master->attribute_amount_held[i], 0);
            }
        }
    }
}

void RGE_Static_Object::take_attribute_from_owner(void) {
    for (int i = 0; i < 3; ++i) {
        RGE_Master_Static_Object* master = this->master_obj;
        if (master->attribute_flag[i] == 2) {
            short attr = master->attribute_type_held[i];
            if (attr >= 0) {
                this->owner->add_attribute_num(attr, -master->attribute_amount_held[i], 0);
            }
        }
    }
}

void RGE_Static_Object::draw(TDrawArea* render_area, short x, short y, RGE_Color_Table* draw_color) {
    SDI_Object_ID = this->id;

    if (this->type == 0x19) {
        RGE_Doppleganger_Object* dopple = static_cast<RGE_Doppleganger_Object*>(this);

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
        if (this->selected != 0 || rge_base_game->outline_type == 3 ||
            ((this->master_obj->draw_flag & 1) == 1 && rge_base_game->prog_mode == ProgModeScenarioEditor)) {
            this->capture_frame(render_area, x, y);
        }

        SDI_Draw_Line = (int)y + (int)this->shadow_y_offset;
        this->sprite_list->draw(this->facet, this->screen_x_offset + x, this->screen_y_offset + y,
                                this->shadow_x_offset + x, y + this->shadow_y_offset, draw_color, render_area);
    }

    SDI_Object_ID = -1;
}

void RGE_Static_Object::shadow_draw(TDrawArea* render_area, short x, short y, unsigned char flag) {
    if (this->tile != 0 && this->object_state < 7) {
        this->sprite_list->shadow_draw(this->facet, this->shadow_x_offset + x, this->shadow_y_offset + y,
                                       this->owner->color_table, render_area, flag);
    }
}

void RGE_Static_Object::normal_draw(TDrawArea* render_area, short x, short y) {
    if (this->tile == 0) {
        return;
    }
    if ((unsigned char)this->object_state >= 7) {
        return;
    }

    unsigned char is_selected;
    if (this->selected != 0 || rge_base_game->outline_type == 3) {
        is_selected = 1;
    } else {
        is_selected = 0;
    }

    if (is_selected) {
        this->draw_back_frame(render_area, x, y);
    }

    this->sprite_list->normal_draw(this->facet, (short)((int)(short)this->screen_x_offset + (int)x),
                                   (short)((int)(short)this->screen_y_offset + (int)y), this->owner->color_table,
                                   render_area);

    if (is_selected) {
        this->draw_front_frame(render_area, x, y);
    }
}

void RGE_Static_Object::draw_front_frame(TDrawArea* render_area, short x, short y) {
    int game_mode = rge_base_game->game_mode;
    if (game_mode == 1) {
        this->draw_frame_3d_cube_front(render_area, x, y);
        return;
    }
    unsigned int outline_type = rge_base_game->outline_type;
    if (outline_type > 3)
        return;
    switch (outline_type) {
    case 0:
        this->draw_frame(render_area, x, y);
        return;
    case 1:
        this->draw_frame_3d_cube_front(render_area, x, y);
        return;
    case 2:
    case 3:
        this->draw_frame_3d_square_front(render_area, x, y);
        return;
    }
}

void RGE_Static_Object::draw_back_frame(TDrawArea* render_area, short x, short y) {
    if (rge_base_game->game_mode == 1) {
        this->draw_frame_3d_cube_back(render_area, x, y);
        return;
    }

    switch (rge_base_game->outline_type) {
    case 0:
        return;
    case 1:
        this->draw_frame_3d_cube_back(render_area, x, y);
        return;
    case 2:
    case 3:
        this->draw_frame_3d_square_back(render_area, x, y);
        return;
    default:
        return;
    }
}

void RGE_Static_Object::capture_frame(TDrawArea* render_area, short x, short y) {
    if (SDI_Capture_Info) {
        if (rge_base_game->game_mode == 1) {
            this->capture_frame_3d_cube(render_area, x, y);
            return;
        }

        switch (rge_base_game->outline_type) {
        case 0:
            this->capture_square_frame(render_area, x, y);
            return;
        case 1:
            this->capture_frame_3d_cube(render_area, x, y);
            return;
        case 2:
        case 3:
            this->capture_frame_3d_square(render_area, x, y);
            return;
        }
    }
}

void RGE_Static_Object::capture_square_frame(TDrawArea* render_area, short x, short y) {
    short min_y;
    short min_x;
    int y0;
    short max_y;
    short max_x;

    if (this->sprite != 0 && this->sprite_list != 0) {
        this->sprite_list->get_facetindex(this->sprite, this->facet);

        if (this->get_frame(min_x, min_y, max_x, max_y) != 0) {
            int x1;
            int y1;
            x1 = x + min_x - 1 + this->screen_x_offset;
            y1 = y + min_y - 1 + this->screen_y_offset;
            y0 = y + max_y + 1 + this->screen_y_offset;
            SDI_List->AddGDINode(4, y0, x1, y1, x + max_x + this->screen_x_offset + 1, y0, 0, 0, 0, 0, 10, 0xff,
                                 SDI_Object_ID);

            if (this->object_state <= 2) {
                int health = (int)this->hp;
                if (health < 1) {
                    health = 0;
                }

                int max_health = (int)this->master_obj->hp;
                if (max_health > 0) {
                    y1 -= 6;
                    int y2 = y1 + 5;
                    int x2 = x1 + 26;
                    health = (health * 25) / max_health + x1;
                    if (health >= x2) {
                        health = x2 - 1;
                    }

                    SDI_List->AddGDINode(2, y0, x1, y1, x2, y2, health, 0, health + 1, 0, 20, 0xff, SDI_Object_ID);
                }
            }
        }
    }
}

void RGE_Static_Object::capture_frame_3d_cube(TDrawArea* render_area, short x, short y) {}

void RGE_Static_Object::capture_frame_3d_square(TDrawArea* render_area, short x, short y) {
    RGE_Master_Static_Object* master = this->master_obj;
    RGE_Map* map = this->owner->world->map;
    float radius_x;
    float radius_y;
    float radius_z;
    if (rge_base_game->outline_type == 3) {
        radius_x = master->radius_x;
        radius_y = master->radius_y;
        radius_z = master->radius_z;
    } else {
        radius_x = master->outline_radius_x;
        radius_y = master->outline_radius_y;
        radius_z = master->outline_radius_z;
    }

    unsigned char draw_color;
    if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0) {
        draw_color = 0;
    } else if ((this->selected & 1) == 0) {
        if (rge_base_game->outline_type == 3) {
            draw_color = 0x74;
        } else if ((master->draw_flag & 1) == 1 && rge_base_game->prog_mode == ProgModeScenarioEditor) {
            draw_color = master->draw_color;
        } else {
            draw_color = 0xff;
        }
    } else {
        draw_color = 0xff;
    }

    if ((this->selected & 2) != 0) {
        draw_color = 0x4a;
    }
    if ((this->selected & 4) != 0) {
        draw_color = 0x97;
    }

    x += this->screen_x_offset;
    y += this->screen_y_offset;

    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
    short x4;
    short y4;
    map->get_point(x1, y1, radius_x, -radius_y, 0.0f, x, y);
    map->get_point(x2, y2, radius_x, radius_y, 0.0f, x, y);
    map->get_point(x3, y3, -radius_x, radius_y, 0.0f, x, y);
    map->get_point(x4, y4, -radius_x, -radius_y, 0.0f, x, y);

    SDI_List->AddGDINode(1, y, x1, y1, x2, y2, x3, y3, x4, y4, 10, draw_color, SDI_Object_ID);

    if (this->selected != 0 && this->selected_group > 0 && this->selected_group < 10 &&
        this->owner->id == this->owner->world->curr_player) {
        TShape* group_num_shape = rge_base_game->get_shape(0);
        if (group_num_shape != 0) {
            Shape_Info* shape_info = (Shape_Info*)group_num_shape->FShape + this->selected_group;
            SDI_List->AddDrawNode(group_num_shape->FShape, shape_info, y, x4 - 6, y4 - 8, 0, 0, 0, 0x1e, SDI_Object_ID);
        }
    }

    if ((this->selected & 1) == 1 && (this->master_obj->draw_flag & 2) == 0) {
        int cur_hp = (int)this->hp;
        if (cur_hp > 0) {
            short bar_x;
            short bar_y;
            map->get_point(bar_x, bar_y, radius_x, -radius_y, radius_z, x, y);

            if (cur_hp < 1) {
                cur_hp = 0;
            }
            int tot_hp = this->master_obj->hp;
            if (tot_hp > 0) {
                short left = bar_x - 12;
                short top = bar_y - 2;
                short right = left + 23;
                short bottom = bar_y - 1;
                short filled_right;
                short empty_left;
                int has_filled;
                int has_empty;

                x2 = right;
                y2 = bottom;

                if (cur_hp == tot_hp) {
                    filled_right = right;
                    has_filled = 1;
                    empty_left = -1;
                    has_empty = 0;
                } else if (cur_hp == 0) {
                    filled_right = -1;
                    has_filled = 0;
                    empty_left = left;
                    has_empty = 1;
                } else {
                    filled_right = left + (cur_hp * 24) / tot_hp;
                    if (filled_right >= right) {
                        filled_right = right - 1;
                    }
                    has_filled = 1;
                    empty_left = filled_right + 1;
                    has_empty = 1;
                }

                SDI_List->AddGDINode(2, y, left, top, right, bottom, filled_right, has_filled, empty_left, has_empty,
                                     0x1e, draw_color, SDI_Object_ID);
            }
        }
    }

    if (rge_base_game->display_selected_ids != 0) {
        TShape* number_shape = rge_base_game->get_shape(0);
        int object_id = this->id;
        int value = object_id;
        if (value < 0) {
            value = -value;
        }

        int digits[5];
        digits[0] = value / 10000;
        value %= 10000;
        digits[1] = value / 1000;
        value %= 1000;
        digits[2] = value / 100;
        value %= 100;
        digits[3] = value / 10;
        digits[4] = value % 10;

        int first_digit = 0;
        if (object_id < 10000) {
            first_digit = 1;
        }
        if (object_id < 1000) {
            first_digit = 2;
        }
        if (object_id < 100) {
            first_digit = 3;
        }
        if (object_id < 10) {
            first_digit = 4;
        }

        if (object_id < 0) {
            x2 += 7;
            SDI_List->AddGDINode(4, y, x2 + 1, y2 + 3, x2 + 5, y2 + 3, 0, 0, 0, 0, 0x1e, 0x97, SDI_Object_ID);
        }

        for (int i = first_digit; i < 5; ++i) {
            x2 += 7;
            if (digits[i] == 0) {
                SDI_List->AddGDINode(4, y, x2 + 1, y2, x2 + 5, y2 + 5, 0, 0, 0, 0, 0x1e, 0xff, SDI_Object_ID);
            } else {
                Shape_Info* shape_info = (Shape_Info*)number_shape->FShape + digits[i];
                SDI_List->AddDrawNode(number_shape->FShape, shape_info, y, x2, y2, 0, 0, 0, 0x1e, SDI_Object_ID);
            }
        }
    }
}

static char stat_obj_square_back_tag[] = "stat_obj::draw_frame_3d_square_back";

void RGE_Static_Object::draw_frame_3d_square_back(TDrawArea* render_area, short x, short y) {
    RGE_Map* map;
    float negative_rx1;
    TPanel* view;
    short y2;
    short x2;
    short x1;
    short y1;
    float ry1;
    float rx1;

    map = this->owner->world->map;
    ry1 = this->master_obj->outline_radius_x;
    rx1 = this->master_obj->outline_radius_y;
    view = rge_base_game->get_view_panel();
    if (view != 0) {
        render_area->Unlock(stat_obj_square_back_tag);
        if (render_area->GetDc(stat_obj_square_back_tag) != 0) {
            SelectClipRgn(render_area->DrawDc, view->clip_rgn);
            if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(render_area->DrawDc, GetStockObject(BLACK_PEN));
            } else {
                SelectObject(render_area->DrawDc, GetStockObject(WHITE_PEN));
            }

            x += this->screen_x_offset;
            y += this->screen_y_offset;

            negative_rx1 = -rx1;
            map->get_point(x2, y2, ry1, negative_rx1, 0.0f, x, y);
            map->get_point(x1, y1, ry1, rx1, 0.0f, x, y);
            MoveToEx(render_area->DrawDc, x2, y2, 0);
            LineTo(render_area->DrawDc, x1, y1);
            map->get_point(x2, y2, ry1, negative_rx1, 0.0f, x, y);
            map->get_point(x1, y1, -ry1, negative_rx1, 0.0f, x, y);
            MoveToEx(render_area->DrawDc, x2, y2, 0);
            LineTo(render_area->DrawDc, x1, y1);
            SelectClipRgn(render_area->DrawDc, 0);
            render_area->ReleaseDc(stat_obj_square_back_tag);
        }
        render_area->Lock(stat_obj_square_back_tag, 1);
    }
}

static char tag[] = "stat_obj::draw_frame_3d_square_front";

void RGE_Static_Object::draw_frame_3d_square_front(TDrawArea* render_area, short x, short y) {
    short y1;
    short x1;
    short y2;
    short x2;
    float rz2;
    float ry1;
    float rx1;
    TPanel* view_panel;

    RGE_Map* map = this->owner->world->map;
    ry1 = this->master_obj->outline_radius_x;
    rz2 = this->master_obj->outline_radius_y;
    rx1 = this->master_obj->radius_z;
    view_panel = rge_base_game->get_view_panel();
    if (view_panel != 0) {
        render_area->Unlock(tag);
        x += this->screen_x_offset;
        y += this->screen_y_offset;
        if (render_area->GetDc(tag) != 0) {
            SelectClipRgn(render_area->DrawDc, view_panel->clip_rgn);
            if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(render_area->DrawDc, GetStockObject(BLACK_PEN));
            } else {
                SelectObject(render_area->DrawDc, GetStockObject(WHITE_PEN));
            }

            map->get_point(x1, y1, -ry1, -rz2, 0.0f, x, y);
            map->get_point(x2, y2, -ry1, rz2, 0.0f, x, y);
            MoveToEx(render_area->DrawDc, x1, y1, 0);
            LineTo(render_area->DrawDc, x2, y2);

            map->get_point(x1, y1, ry1, rz2, 0.0f, x, y);
            map->get_point(x2, y2, -ry1, rz2, 0.0f, x, y);
            MoveToEx(render_area->DrawDc, x1, y1, 0);
            LineTo(render_area->DrawDc, x2, y2);
            SelectClipRgn(render_area->DrawDc, 0);
            render_area->ReleaseDc(tag);
        }

        render_area->Lock(tag, 1);
        int value = (int)this->hp;
        if (value > 0) {
            map->get_point(x1, y1, ry1, -rz2, rx1, x, y);
            if (value < 1)
                value = 0;
            int denom = this->master_obj->hp;
            if (denom > 0) {
                int bar_bottom = (-1) + y1;
                int bar_left = (-12) + x1;
                render_area->FillRect(bar_left, bar_bottom - 1, bar_left + 24, bar_bottom, 0x97);
                bar_bottom = y1;
                bar_bottom--;
                bar_left = y1;
                bar_left--;
                bar_left--;
                render_area->FillRect(x1 - 12, bar_left, (value * 24) / denom + x1 - 12, bar_bottom, 0x4a);
            }
        }
    }
}

void RGE_Static_Object::draw_frame_3d_cube_back(TDrawArea* render_area, short x, short y) {
    short y2, x2, y1, x1;
    float negative_ry;
    RGE_Master_Static_Object* m = this->master_obj;
    float ry1, rz2, rz3, rz4, rx2, ry2, rx1;
    ry1 = m->outline_radius_x * 0.25f;
    rz2 = m->outline_radius_y * 0.25f;
    rz3 = m->outline_radius_z * 0.25f;
    rz4 = m->outline_radius_z * 0.75f;
    rx2 = m->outline_radius_x;
    RGE_Map* map = this->owner->world->map;
    ry2 = m->outline_radius_y;
    rx1 = m->outline_radius_z;
    TPanel* view = rge_base_game->get_view_panel();

    if (view != 0) {
        render_area->Unlock(0);
        void* dc = render_area->GetDc(0);
        if (dc != 0) {
            SelectClipRgn(render_area->DrawDc, view->clip_rgn);
            if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0)
                SelectObject(render_area->DrawDc, GetStockObject(BLACK_PEN));
            else
                SelectObject(render_area->DrawDc, GetStockObject(WHITE_PEN));

            x += this->screen_x_offset;
            y += this->screen_y_offset;
            negative_ry = -ry2;

            map->get_point(x2, y2, rx2, negative_ry, 0.0f, x, y);
            map->get_point(x1, y1, rx2, negative_ry, rz3, x, y);
            MoveToEx(render_area->DrawDc, x2, y2, 0);
            LineTo(render_area->DrawDc, x1, y1);
            map->get_point(x2, y2, rx2, negative_ry, rz4, x, y);
            map->get_point(x1, y1, rx2, negative_ry, rx1, x, y);
            MoveToEx(render_area->DrawDc, x2, y2, 0);
            LineTo(render_area->DrawDc, x1, y1);
            map->get_point(x2, y2, rx2, negative_ry, 0.0f, x, y);
            map->get_point(x1, y1, ry1, negative_ry, 0.0f, x, y);
            MoveToEx(render_area->DrawDc, x2, y2, 0);
            LineTo(render_area->DrawDc, x1, y1);
            map->get_point(x2, y2, -rx2, negative_ry, 0.0f, x, y);
            map->get_point(x1, y1, -ry1, negative_ry, 0.0f, x, y);
            MoveToEx(render_area->DrawDc, x2, y2, 0);
            LineTo(render_area->DrawDc, x1, y1);
            map->get_point(x2, y2, rx2, negative_ry, 0.0f, x, y);
            map->get_point(x1, y1, rx2, -rz2, 0.0f, x, y);
            MoveToEx(render_area->DrawDc, x2, y2, 0);
            LineTo(render_area->DrawDc, x1, y1);
            map->get_point(x2, y2, rx2, ry2, 0.0f, x, y);
            map->get_point(x1, y1, rx2, rz2, 0.0f, x, y);
            MoveToEx(render_area->DrawDc, x2, y2, 0);
            LineTo(render_area->DrawDc, x1, y1);

            SelectClipRgn(render_area->DrawDc, 0);
            render_area->ReleaseDc(0);
        }
        render_area->Lock(0, 1);
    }
}

void RGE_Static_Object::draw_frame_3d_cube_front(TDrawArea* render_area, short x, short y) {
    short y2, x2, y1, x1;
    float negative_rz2;
    float negative_ry2, negative_ry1;
    RGE_Master_Static_Object* master = this->master_obj;
    float ry1 = master->outline_radius_x * 0.25f;
    float rx2 = master->outline_radius_y * 0.25f;
    float rz3 = master->outline_radius_z * 0.25f;
    float rz4 = master->outline_radius_z * 0.75f;
    float ry2 = master->outline_radius_x;
    float rz2 = master->outline_radius_y;
    float rx1 = master->outline_radius_z;
    RGE_Map* map = this->owner->world->map;
    TPanel* view = rge_base_game->get_view_panel();

    // A null view returns before the draw-area lock sequence.
    if (view == 0)
        return;

    render_area->Unlock(0);
    if (render_area->GetDc(0) != 0) {
        SelectClipRgn(render_area->DrawDc, view->clip_rgn);
        if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0) {
            SelectObject(render_area->DrawDc, GetStockObject(BLACK_PEN));
        } else {
            SelectObject(render_area->DrawDc, GetStockObject(WHITE_PEN));
        }

        // Update x before y and keep both incoming short homes.
        x += this->screen_x_offset;
        y += this->screen_y_offset - 0x10;
        negative_rz2 = -rz2;

        map->get_point(x2, y2, ry2, negative_rz2, rx1, x, y);
        map->get_point(x1, y1, ry1, negative_rz2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        negative_ry2 = -ry2;
        map->get_point(x2, y2, negative_ry2, negative_rz2, rx1, x, y);
        // Delay this negation until the first projection ends.
        negative_ry1 = -ry1;
        map->get_point(x1, y1, negative_ry1, negative_rz2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, ry2, rz2, rx1, x, y);
        map->get_point(x1, y1, ry1, rz2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, rz2, rx1, x, y);
        map->get_point(x1, y1, negative_ry1, rz2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, ry2, rz2, rx1, x, y);
        map->get_point(x1, y1, ry2, rx2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, ry2, negative_rz2, rx1, x, y);
        map->get_point(x1, y1, ry2, -rx2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, rz2, rx1, x, y);
        map->get_point(x1, y1, negative_ry2, rx2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, negative_rz2, rx1, x, y);
        map->get_point(x1, y1, negative_ry2, -rx2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, negative_rz2, 0.0f, x, y);
        map->get_point(x1, y1, negative_ry2, -rx2, 0.0f, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, rz2, 0.0f, x, y);
        map->get_point(x1, y1, negative_ry2, rx2, 0.0f, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, ry2, rz2, 0.0f, x, y);
        map->get_point(x1, y1, ry1, rz2, 0.0f, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, rz2, 0.0f, x, y);
        map->get_point(x1, y1, negative_ry1, rz2, 0.0f, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, rz2, 0.0f, x, y);
        map->get_point(x1, y1, negative_ry2, rz2, rz3, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, rz2, rz4, x, y);
        map->get_point(x1, y1, negative_ry2, rz2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, negative_rz2, 0.0f, x, y);
        map->get_point(x1, y1, negative_ry2, negative_rz2, rz3, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, negative_ry2, negative_rz2, rz4, x, y);
        map->get_point(x1, y1, negative_ry2, negative_rz2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, ry2, rz2, 0.0f, x, y);
        map->get_point(x1, y1, ry2, rz2, rz3, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        map->get_point(x2, y2, ry2, rz2, rz4, x, y);
        map->get_point(x1, y1, ry2, rz2, rx1, x, y);
        MoveToEx(render_area->DrawDc, x2, y2, 0);
        LineTo(render_area->DrawDc, x1, y1);

        SelectClipRgn(render_area->DrawDc, 0);
        render_area->ReleaseDc(0);
    }
    render_area->Lock(0, 1);
}

// Keep the sprite and sprite-list guards, facet dispatch, frame

void RGE_Static_Object::draw_frame(TDrawArea* render_area, short x, short y) {
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

            render_area->DrawRect(x1, y1, x2, y2, 0xff);

            if (this->object_state <= 2) {
                int cur_hp = (int)this->hp;
                if (cur_hp < 1) {
                    cur_hp = 0;
                }

                int tot_hp = (int)this->master_obj->hp;
                if (tot_hp > 0) {
                    y1 -= 6;
                    x2 = x1 + 26;
                    y2 = y1 + 5;
                    render_area->DrawRect(x1, y1, x2, y2, 0xff);

                    render_area->FillRect(++x1, ++y1, x2 -= 2, y2 -= 2, 0x55);
                    render_area->FillRect(x1, y1, (cur_hp * 25) / tot_hp + x1 - 1, y1 + 3, 0x25);
                }
            }
        }
    }
}

typedef unsigned char uchar;

uchar RGE_Static_Object::update() {
    uchar ret = 0;
    if (this->goto_sleep_flag != 0) {
        RGE_Player* own = this->owner;
        this->goto_sleep_flag = 0;
        own->removeObject(this, 0, this->dopple_flag, this->player_object_node);
        this->player_object_node = this->owner->addObject(this, 1, this->dopple_flag);
        return 0;
    }
    if (this->groupMembers.number() > 0) {
        for (int i = 0; i < this->groupMembers.number(); i++) {
            int id = this->groupMembers[i];
            RGE_Static_Object* obj = this->owner->world->object(id);
            if (obj == 0 || obj->object_state > 2) {
                this->groupMembers.remove(id);
                i--;
            }
        }
    }
    if (this->inside_obj == 0) {
        switch (this->object_state) {
        case 2:
            this->check_damage_sprites();
        case 0:
            if (this->hp < 1.0f) {
                this->set_object_state(3);
                this->new_sprite(this->master_obj->death_sprite);
                int r = debug_rand(STR_STAT_OBJ, 1796);
                int old = debug_random_on;
                debug_random_on = 0;
                if (this->master_obj->death_sound != 0 && this->owner->id == this->owner->world->curr_player)
                    this->master_obj->death_sound->play(1);
                debug_random_on = old;
                debug_srand(STR_STAT_OBJ, 1806, r);
            }
            break;
        case 3:
        case 5:
            if (this->attribute_type_held == -1 || this->attribute_amount_held <= 0.0f) {
                if (this->master_obj->undead_flag != 0) {
                    this->set_object_state(6);
                    this->new_sprite(this->master_obj->undead_sprite);
                    break;
                }
                this->set_object_state(7);
                this->spawn_death_obj();
                break;
            }
            if (this->master_obj->attribute_rot > 0.0f) {
                this->attribute_amount_held =
                    this->attribute_amount_held -
                    this->owner->world->world_time_delta_seconds * this->master_obj->attribute_rot;
                if (this->attribute_amount_held < 0.0f) {
                    this->attribute_amount_held = 0.0f;
                }
            }
            break;
        case 7:
            this->set_object_state(8);
            break;
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

static char s_stat_obj_cpp[] = "C:\\msdev\\work\\age1_x1\\stat_obj.cpp";

void RGE_Static_Object::check_damage_sprites() {
    long new_damage_loc = -1;
    long curr_damage_loc = -1;

    RGE_Master_Static_Object* master = this->master_obj;
    if (master->hp <= 0 || master->damage_sprite_num == 0) {
        return;
    }

    long health_percent = (long)(this->hp * g_damage_health_percent_scale / master->hp);
    unsigned char new_damage_percent = (unsigned char)(100 - health_percent);
    if (new_damage_percent == this->curr_damage_percent) {
        return;
    }

    if (new_damage_percent < 100) {
        for (long i = 0; i < (long)master->damage_sprite_num; ++i) {
            RGE_Damage_Sprite_Info* damage_sprite = &master->damage_sprites[i];
            if (damage_sprite->damage_percent < new_damage_percent) {
                curr_damage_loc = i;
            }
            if (damage_sprite->damage_percent < this->curr_damage_percent) {
                new_damage_loc = i;
            }
        }
    }

    if (curr_damage_loc == new_damage_loc) {
        this->curr_damage_percent = new_damage_percent;
        return;
    }

    if (curr_damage_loc >= 0) {
        RGE_Damage_Sprite_Info* damage_sprite = &this->master_obj->damage_sprites[curr_damage_loc];
        RGE_Sprite* sprite = 0;
        short x = 0;
        short y = 0;

        switch (damage_sprite->flag) {
        case 0:
            sprite = damage_sprite->sprite;
            break;
        case 1: {
            RGE_Master_Static_Object* random_master = this->master_obj;
            int random_value = debug_rand(s_stat_obj_cpp, 1908);
            float rand_x = (float)random_value * random_master->radius_x;
            rand_x = rand_x * g_damage_sprite_random_scale - random_master->radius_x;
            short x_part = (short)this->world_x;
            rand_x += this->world_x - (float)x_part;

            random_master = this->master_obj;
            random_value = debug_rand(s_stat_obj_cpp, 1909);
            float rand_y = (float)random_value * random_master->radius_y;
            rand_y = rand_y * g_damage_sprite_random_scale - random_master->radius_y;
            short y_part = (short)this->world_y;
            rand_y += this->world_y - (float)y_part;

            this->owner->world->map->get_point(x, y, rand_x, rand_y, this->world_z, 0, 0);
            sprite = damage_sprite->sprite;
            break;
        }
        case 2:
            this->new_sprite(damage_sprite->sprite);
            goto damage_sprite_done;
        default:
            goto damage_sprite_done;
        }

        this->sprite_list->add_sprite(sprite, 0x5A, x, y);
    }

damage_sprite_done:
    if (new_damage_loc >= 0) {
        RGE_Damage_Sprite_Info* damage_sprite = &this->master_obj->damage_sprites[new_damage_loc];
        if (damage_sprite->flag < 2) {
            this->sprite_list->remove_sprite(damage_sprite->sprite);
        } else if (damage_sprite->flag == 2 &&
                   (curr_damage_loc < 0 || this->master_obj->damage_sprites[curr_damage_loc].flag != 2)) {
            this->new_sprite(this->master_obj->sprite);
            this->curr_damage_percent = new_damage_percent;
            return;
        }
    }

    this->curr_damage_percent = new_damage_percent;
}

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

RGE_Static_Object* RGE_Static_Object::get_object_pointer(long obj_id) {
    RGE_Static_Object* object;
    unsigned char player_id;

    object = 0;
    if (obj_id >= 0) {
        object = this->owner->objects->find_by_id(obj_id);
        if (object == 0) {
            object = this->owner->sleeping_objects->find_by_id(obj_id);
            if (object == 0) {
                object = this->owner->doppleganger_objects->find_by_id(obj_id);
                if (object == 0) {
                    player_id = 0;
                    while (player_id < this->owner->world->player_num) {
                        if (player_id != this->owner->id) {
                            object = this->owner->world->players[player_id]->objects->find_by_id(obj_id);
                            if (object != 0) {
                                break;
                            }
                            object = this->owner->world->players[player_id]->sleeping_objects->find_by_id(obj_id);
                            if (object != 0) {
                                break;
                            }
                            object = this->owner->world->players[player_id]->doppleganger_objects->find_by_id(obj_id);
                            if (object != 0) {
                                break;
                            }
                        }
                        player_id++;
                    }
                }
            }
        }
    }

    return object;
}

RGE_Sprite* RGE_Static_Object::get_sprite_pointer(short sprite_id) {
    RGE_Game_World* world;

    if (sprite_id >= 0) {
        world = this->owner->world;
        if (sprite_id < world->sprite_num) {
            return world->sprites[sprite_id];
        }
    }
    return 0;
}

void RGE_Static_Object::save(int outfile) {
    short short_val;
    int long_val;
    int tempInt = outfile;
    int i;

    rge_write(tempInt, &this->type, 1);
    rge_write(tempInt, &this->owner->id, 1);
    rge_write(tempInt, &this->master_obj->id, 2);

    if (this->sprite == 0)
        short_val = -1;
    else
        short_val = this->sprite->id;
    rge_write(tempInt, &short_val, 2);

    if (this->inside_obj == 0)
        long_val = -1;
    else
        long_val = this->inside_obj->id;
    rge_write(tempInt, &long_val, 4);

    rge_write(tempInt, &this->hp, 4);
    rge_write(tempInt, &this->object_state, 1);
    rge_write(tempInt, &this->sleep_flag, 1);
    rge_write(tempInt, &this->dopple_flag, 1);
    rge_write(tempInt, &this->goto_sleep_flag, 1);
    rge_write(tempInt, &this->id, 4);
    rge_write(tempInt, &this->facet, 1);
    rge_write(tempInt, &this->world_x, 4);
    rge_write(tempInt, &this->world_y, 4);
    rge_write(tempInt, &this->world_z, 4);
    rge_write(tempInt, &this->screen_x_offset, 2);
    rge_write(tempInt, &this->screen_y_offset, 2);
    rge_write(tempInt, &this->shadow_x_offset, 2);
    rge_write(tempInt, &this->shadow_y_offset, 2);
    rge_write(tempInt, &this->selected_group, 1);
    rge_write(tempInt, &this->attribute_type_held, 2);
    rge_write(tempInt, &this->attribute_amount_held, 4);
    rge_write(tempInt, &this->worker_num, 1);
    rge_write(tempInt, &this->curr_damage_percent, 1);
    rge_write(tempInt, &this->underAttackValue, 1);
    rge_write(tempInt, &this->groupCommanderValue, 4);
    rge_write(tempInt, &this->groupRangeValue, 4);

    outfile = this->groupMembers.number();
    rge_write(tempInt, &outfile, 4);
    i = 0;
    if (this->groupMembers.number() > 0)
        do {
            outfile = this->groupMembers[i];
            rge_write(tempInt, &outfile, 4);
            ++i;
        } while (i < this->groupMembers.number());

    outfile = this->pathingGroupMembers.number();
    rge_write(tempInt, &outfile, 4);
    int k = 0;
    if (this->pathingGroupMembers.number() > 0)
        do {
            outfile = this->pathingGroupMembers[k];
            rge_write(tempInt, &outfile, 4);
            ++k;
        } while (k < this->pathingGroupMembers.number());

    this->sprite_list->save(tempInt);
}

// teleport uses the canonical named terrain methods.
float RGE_Static_Object::teleport(float x, float y, float z) {
    float rz = 0.0f;
    RGE_Map* map = this->owner->world->map;
    if (this->inside_obj != 0) {
        return 0.0f;
    }

    if (this->master_obj->radius_z > 0.0) {
        this->removeFromObstructionMap(2);
    }

    if (x < 0.0f) {
        x = 0.0f;
    }
    if (x >= (float)map->map_width) {
        x = (float)map->map_width - 0.001f;
    }
    if (y < 0.0f) {
        y = 0.0f;
    }
    if (y >= (float)map->map_height) {
        y = (float)map->map_height - 0.001f;
    }

    int tx = (int)x;
    int ty = (int)y;
    float rx = x - (float)tx;
    float ry = y - (float)ty;

    if (tx >= map->map_width) {
        tx = map->map_width - 1;
    } else if (tx < 0) {
        tx = 0;
    }
    if (ty >= map->map_height) {
        ty = map->map_height - 1;
    } else if (ty < 0) {
        ty = 0;
    }

    RGE_Tile* new_tile = map->map_row_offset[ty] + tx;
    if (new_tile != this->tile && this->inside_obj == 0) {
        if (this->tile != 0) {
            this->tile->objects.remove_node(this, 0);
        }
        new_tile->objects.add_node(this);
        if (this->tile != 0) {
            this->unexplore_terrain(this->owner, 0, -1);
        }

        this->world_z = z;
        this->world_x = x;
        this->world_y = y;
        this->tile = new_tile;
        if (this->object_state == 2) {
            this->explore_terrain(this->owner, 0, -1);
        }
    } else {
        this->world_x = x;
        this->world_y = y;
        this->world_z = z;
    }

    if (this->master_obj->radius_z > 0.0) {
        this->addToObstructionMap(2);
    }

    float zd = 0.0f;
    switch (new_tile->tile_type) {
    case 0:
        rz = 0.0f;
        break;
    case 1:
        rz = rx + ry < 1.0f ? ry : 1.0f - rx;
        break;
    case 2:
        rz = rx + ry < 1.0f ? rx : 1.0f - ry;
        zd = 1.0f;
        break;
    case 3:
        rz = rx <= ry ? 1.0f - ry : 1.0f - rx;
        break;
    case 4:
        rz = rx <= ry ? rx : ry;
        break;
    case 5:
        rz = 1.0f - rx;
        break;
    case 6:
        rz = 1.0f - ry;
        zd = 1.0f;
        break;
    case 7:
        rz = ry;
        break;
    case 8:
        rz = rx;
        zd = 1.0f;
        break;
    case 9:
        rz = rx - ry;
        if (rz < 0.0f) {
            rz = -rz;
        } else {
            rz = 0.0f;
        }
        break;
    case 10:
        rz = rx - ry;
        if (rz <= 0.0f) {
            rz = 0.0f;
        }
        zd = 1.0f;
        break;
    case 11:
        rz = rx + ry;
        if (rz < 1.0f) {
            rz = 1.0f - rz;
        } else {
            rz = 0.0f;
        }
        break;
    case 12:
        rz = rx + ry;
        if (rz > 1.0f) {
            rz -= 1.0f;
        } else {
            rz = 0.0f;
        }
        break;
    case 13:
        rz = rx + ry < 1.0f ? 1.0f - rx : ry;
        break;
    case 14:
        rz = rx + ry < 1.0f ? 1.0f - ry : rx;
        zd = 1.0f;
        break;
    case 15:
        rz = rx <= ry ? ry : rx;
        zd = 1.0f;
        break;
    case 16:
        rz = rx <= ry ? 1.0f - rx : 1.0f - ry;
        zd = 1.0f;
        break;
    default:
        break;
    }

    RGE_Master_Static_Object* master = this->master_obj;
    rz += this->tile->height;
    switch (master->movement_type) {
    case 0:
        this->world_z = rz;
        break;
    case 1:
        if (rz > this->world_z) {
            this->world_z = rz;
        }
        break;
    }

    this->screen_x_offset = (short)((ry + rx) * map->tile_half_width);
    float screen_y = zd + ry + 1.0f - rx;
    this->screen_y_offset = (short)((screen_y - this->world_z) * map->tile_half_height);

    switch (master->movement_type) {
    case 0:
        this->shadow_x_offset = this->screen_x_offset;
        this->shadow_y_offset = this->screen_y_offset;
        break;
    case 1:
        this->shadow_x_offset = (short)((ry + rx) * map->tile_half_width);
        this->shadow_y_offset = (short)((screen_y - rz) * map->tile_half_height);
        break;
    }

    return rz;
}

void RGE_Static_Object::new_sprite(RGE_Sprite* nsprite) {
    if (nsprite == 0) {
        nsprite = this->master_obj->sprite;
    }
    if (this->sprite != nsprite &&
        (this->sprite != this->master_obj->death_sprite || this->master_obj->death_sprite == 0)) {
        this->old_sprite = this->sprite;
        this->sprite_list->remove_sprite(this->sprite);
        this->sprite = nsprite;
        this->sprite_list->add_sprite(nsprite, 0x3C, 0, 0);
        this->facet = 0;
    }
}

void RGE_Static_Object::add_overlay_sprite(RGE_Sprite* nsprite, unsigned char order) {
    sprite_list->add_sprite(nsprite, order, 0, 0);
}

// this virtual member takes an RGE_Sprite pointer.
void RGE_Static_Object::remove_overlay_sprite(RGE_Sprite* nsprite) {
    this->sprite_list->remove_sprite(nsprite);
}

void RGE_Static_Object::change_ownership(RGE_Player* new_owner) {
    if (new_owner->master_objects[this->master_obj->id] == 0) {
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

    this->owner->removeObject(this, this->sleep_flag, this->dopple_flag, this->player_object_node);
    RGE_Object_Node* new_node = new_owner->addObject(this, this->sleep_flag, this->dopple_flag);

    RGE_Master_Static_Object* old_master = this->master_obj;
    this->player_object_node = new_node;
    RGE_Master_Static_Object* new_master = new_owner->master_objects[old_master->id];
    RGE_Sprite* new_sprite;
    if (this->sprite == old_master->sprite) {
        new_sprite = new_master->sprite;
    } else if (this->sprite == old_master->death_sprite) {
        new_sprite = new_master->death_sprite;
    } else if (this->sprite == old_master->undead_sprite) {
        new_sprite = new_master->undead_sprite;
    } else {
        new_sprite = new_master->sprite;
    }

    if (new_sprite != 0) {
        this->new_sprite(new_sprite);
    }

    this->owner = new_owner;
    this->master_obj = new_master;
    this->hp = (float)(int)new_master->hp * hp_num;

    if (this->object_state == 2) {
        this->explore_terrain(new_owner, 0, -1);
    }

    this->give_attribute_to_owner();
    this->notify(this->id, this->id, 0x20B, (int)new_owner->id, 0, 0);
}

void RGE_Static_Object::modify(float amount, unsigned char flag) {
    switch (flag) {
    case 0: {
        int max_hp = this->master_obj->hp;
        this->hp = (float)(short)(long)(amount * this->hp / max_hp);
    } break;
    case 1:
        if (this->tile != 0 && this->object_state == 2) {
            this->unexplore_terrain(this->owner, 0, -1);
            this->explore_terrain(this->owner, 0, (int)amount);
            return;
        }
        break;
    }
}

void RGE_Static_Object::modify_delta(float amount, unsigned char flag) {
    unsigned int op = flag & 0xff;
    switch (op) {
    case 1:
        if (this->tile != 0 && this->object_state == 2) {
            RGE_Player* owner = this->owner;
            this->unexplore_terrain(owner, 0, -1);
            RGE_Master_Static_Object* master = this->master_obj;
            this->explore_terrain(this->owner, 0, (int)(master->los + amount));
        }
        return;
    case 0: {
        this->hp = (float)(int)(short)((amount + this->master_obj->hp) * this->hp / this->master_obj->hp);
        break;
    }
    default:
        return;
    }
}

void RGE_Static_Object::modify_percent(float amount, unsigned char flag) {
    switch (flag) {
    case 0: {
        int tmp = (int)(amount * hp);
        hp = (float)(short)tmp;
        break;
    }
    case 1:
        if (tile != 0 && object_state == 2) {
            this->unexplore_terrain(this->owner, 0, -1);

            int val = (int)(master_obj->los * amount);
            this->explore_terrain(this->owner, 0, val);
        }
        break;
    }
}

void RGE_Static_Object::transform(RGE_Master_Static_Object* obj) {
    float hp_num = (float)(signed short)(master_obj->hp);
    hp_num = hp / hp_num;

    if (tile != 0) {
        unexplore_terrain(owner, 0, -1);
    }

    removeFromObstructionMap(2);

    master_obj = obj;

    if (tile != 0) {
        register const int no_range = -1;
        explore_terrain(owner, 0, no_range);
    }

    addToObstructionMap(2);

    new_sprite(obj->sprite);

    hp = (float)obj->hp;
    hp = hp * hp_num;
    object_state = 0;

    set_object_state(2);
}

void RGE_Static_Object::copy_obj(RGE_Master_Static_Object* source) {
    RGE_Sprite* new_sprite = 0;

    if (this->tile != 0 && this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
        this->explore_terrain(this->owner, 0, (int)source->los);
    }

    float hp_num = this->hp / (float)(int)this->master_obj->hp;
    this->hp = (float)(int)this->master_obj->hp;
    if (this->object_state == 2) {
        this->check_damage_sprites();
    }

    RGE_Master_Static_Object* old_master = this->master_obj;
    RGE_Sprite* old_sprite = this->sprite;
    if (old_sprite == old_master->sprite) {
        new_sprite = source->sprite;
    } else if (old_sprite == old_master->death_sprite) {
        new_sprite = source->death_sprite;
    } else if (old_sprite == old_master->undead_sprite) {
        new_sprite = source->undead_sprite;
    }

    int new_hp = source->hp;
    this->master_obj = source;
    this->hp = (float)(int)new_hp * hp_num;
    if (this->object_state == 2) {
        this->check_damage_sprites();
    }

    this->master_obj = old_master;
    if (new_sprite != 0) {
        this->new_sprite(new_sprite);
    }
}

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

void RGE_Static_Object::die_die_die(void) {
    if ((this->selected & 1) != 0) {
        this->owner->unselect_one_object(this);
    }
    this->set_sleep_flag(0);
    this->hp = 0;
}

typedef unsigned long ulong;

void RGE_Static_Object::remove_visible_resource() {
    ulong ExploredVal;
    ulong explored;
    RGE_Player* player;
    if (this->id >= 0 && this->owner != 0 && this->master_obj != 0 &&
        (this->master_obj->create_doppleganger_on_death != 0 || this->master_obj->track_as_resource != 0)) {
        ExploredVal = unified_map_offsets[(int)this->world_y][(int)this->world_x];
        explored = ExploredVal >> 16;
        ExploredVal &= 0xFFFF;
        if (explored > 0) {
            int player_index = 0;
            do {
                if ((explored & 1) == 1) {
                    if (this->master_obj->track_as_resource != 0) {
                        player = this->owner->world->players[player_index];
                        player->VR_List->Remove_Resource(this->id, this->master_obj->resource_group);
                    }
                    if (this->master_obj->create_doppleganger_on_death == 1 && (ExploredVal & 1) == 0 && player_index > 0) {
                        player = this->owner->world->players[player_index];
                        static_cast<RGE_Master_Doppleganger_Object*>(player->master_objects[243])
                            ->make_new_obj(player, this->world_x, this->world_y, this->world_z, this);
                    }
                }
                player_index++;
                ExploredVal >>= 1;
                explored >>= 1;
            } while (explored != 0);
        }
        if (this->master_obj->create_doppleganger_on_death == 2) {
            this->owner->doppleganger_creator->remove_doppleganger_check(this);
        }
    }
}

typedef unsigned long ulong;

void RGE_Static_Object::create_doppleganger_when_dying() {
    if (this->id >= 0 && this->owner != 0 && this->master_obj != 0 && this->master_obj->create_doppleganger_on_death == 2) {
        ulong ExploredVal = unified_map_offsets[(int)this->world_y][(int)this->world_x];
        ulong explored = ExploredVal >> 16;
        ExploredVal &= 0xFFFF;
        if (explored > 0) {
            int i = 0;
            do {
                if ((explored & 1) == 1 && (ExploredVal & 1) == 0 && i > 0) {
                    RGE_Player* player = this->owner->world->players[i];
                    static_cast<RGE_Master_Doppleganger_Object*>(player->master_objects[243])
                        ->make_new_obj(player, this->world_x, this->world_y, this->world_z, this);
                }
                i++;
                ExploredVal >>= 1;
                explored >>= 1;
            } while (explored != 0);
        }
        this->owner->doppleganger_creator->add_doppleganger_check(
            this, &unified_map_offsets[(int)this->world_y][(int)this->world_x]);
    }
}

void RGE_Static_Object::set_object_state(unsigned char new_object_state) {
    if (this->object_state != new_object_state) {
        if (new_object_state >= 3 && this->object_state < 3) {
            this->take_attribute_from_owner();
            if (this->master_obj->create_doppleganger_on_death == 2) {
                this->create_doppleganger_when_dying();
            }
        }

        if (this->object_state <= 3 && new_object_state >= 7) {
            this->remove_visible_resource();
        }

        if (new_object_state >= 3 && this->object_state == 2 && this->tile != 0) {
            this->unexplore_terrain(this->owner, 0, -1);
            if (this->master_obj->los > 0.0) {
                this->explore_terrain(this->owner, 1, -1);
            }
        }

        if (this->object_state < 7 && new_object_state == 7 && this->tile != 0 && this->master_obj->los > 0.0) {
            this->unexplore_terrain(this->owner, 1, -1);
        }

        this->object_state = new_object_state;

        if (new_object_state == 3 && this->groupCommanderValue == this->id && this->unitAIValue != 0 &&
            this->groupMembers.number() > 1) {
            int i = 0;
            int newCommander = -1;
            if (this->groupMembers.number() > 0) {
                do {
                    if (this->groupMembers[i] != this->id) {
                        RGE_Static_Object* member = this->owner->world->object(this->groupMembers[i]);
                        if (member != 0 && member->object_state <= 2 && member->unitAI() != 0) {
                            if (newCommander == -1) {
                                newCommander = this->groupMembers[i];
                            }
                            member->groupCommanderValue = newCommander;
                            if (this->groupMembers[i] == newCommander) {
                                member->unitAI()->setPlayStatus(this->unitAIValue->playStatus);
                            }
                        }
                    }
                    ++i;
                } while (i < this->groupMembers.number());
            }
        }

        if (this->sleep_flag != 0 && this->object_state != 2 && this->object_state != 6) {
            this->set_sleep_flag(0);
        }
    }
}

// The final X overlap accepts less, equal, and unordered comparisons.

RGE_Static_Object* RGE_Static_Object::check_object_bounds() {
    float rx;
    float ry;
    short x1;
    short y1;
    short x2;
    short y2;

    rx = this->master_obj->radius_x;
    ry = this->master_obj->radius_y;
    if (rx > 0.0f || ry > 0.0f) {
        x1 = (short)(int)(this->world_x - 3.0f);
        y1 = (short)(int)(this->world_y - 3.0f);
        x2 = (short)(int)(this->world_x + 3.0f);
        y2 = (short)(int)(this->world_y + 3.0f);
        RGE_Map* map = this->owner->world->map;
        if (x1 < 0)
            x1 = 0;
        if (x2 >= map->map_width)
            x2 = (short)map->map_width - 1;
        if (y1 < 0)
            y1 = 0;
        if (y2 >= map->map_height)
            y2 = (short)map->map_height - 1;
        for (short y_index = y1; y_index <= y2; ++y_index) {
            RGE_Tile* tile = map->map_row_offset[y_index] + x1;
            for (short x = x1; x <= x2; ++x) {
                RGE_Object_Node* n = tile->objects.list;
                if (n != 0) {
                    do {
                        RGE_Static_Object* obj = n->node;
                        RGE_Master_Static_Object* master = obj->master_obj;
                        float ry2 = master->radius_y;
                        float rx2 = master->radius_x;
                        if (rx2 > 0.0f && ry2 > 0.0f) {
                            float dy = obj->world_y - this->world_y;
                            float dx = obj->world_x - this->world_x;
                            if (dy < 0.0f)
                                dy = -dy;
                            if (dx < 0.0f)
                                dx = -dx;
                            if (dy <= ry2 + ry) {
                                float x_limit = rx2 + rx;
                                if (!(dx > x_limit)) {
                                    return obj;
                                }
                            }
                        }
                        n = n->next;
                    } while (n != 0);
                }
                ++tile;
            }
        }
    }
    return 0;
}

float RGE_Static_Object::get_terrain_speed(unsigned char terrain) {
    return owner->world->terrains[master_obj->terrain][terrain];
}

unsigned char RGE_Static_Object::is_moving() {
    return 0;
}

// this method is an exceptional nonvirtual member. Its original
unsigned char RGE_Static_Object::is_dying(void) {
    if (object_state >= 3 && object_state != 6) {
        return 1;
    }
    return 0;
}

// the four outputs are references, not pointer parameters.

int RGE_Static_Object::get_frame(short& min_x, short& min_y, short& max_x, short& max_y) {
    if (this->sprite != 0 && this->sprite_list != 0) {
        return this->sprite_list->get_frame(min_x, min_y, max_x, max_y, this->sprite, (unsigned char)this->facet);
    }
    return 0;
}

unsigned char RGE_Static_Object::more_room() {
    if (this->objects->number_of_objects < (short)(unsigned short)this->master_obj->obj_max)
        return 1;
    return 0;
}

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

void RGE_Static_Object::exit_obj(void) {
    if (inside_obj != 0) {
        inside_obj->objects->remove_node(this, 0);
        inside_obj = 0;
    }
}

// LOSTBL is a struct in the original decorated return type.
LOSTBL* RGE_Static_Object::get_los_table(void) {
    if (this->owner == 0) {
        return 0;
    }
    return this->owner->visible->get_los_table((int)this->master_obj->los, 0);
}

extern "C" long __cdecl _ftol(void);

int RGE_Static_Object::explore_terrain(RGE_Player* whos, unsigned char explore_type, int Override_LOS) {
    if (whos != 0) {
        if (Override_LOS == -1) {
            Override_LOS = (int)this->master_obj->los;
        }
        if (Override_LOS > 0) {
            RGE_Visible_Map* visible = whos->visible;
            long current = (whos->id == whos->world->curr_player);
            if (explore_type == 0) {
                return visible->explore_terrain((long)this->world_x, (long)this->world_y, Override_LOS, 0, current,
                                                this->id);
            } else {
                if (this->master_obj->radius_x > 0.0 && this->master_obj->radius_y > 0.0) {
                    return visible->explore_terrain_sq((long)(this->world_x - this->master_obj->radius_x),
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


void RGE_Static_Object::unexplore_terrain(RGE_Player* whos, unsigned char explore_type, int Override_LOS) {
    if (whos != 0) {
        if (Override_LOS == -1) {
            Override_LOS = (int)this->master_obj->los;
        }
        if (Override_LOS > 0) {
            RGE_Visible_Map* visible = whos->visible;
            long current = (whos->id == whos->world->curr_player);
            if (explore_type == 0) {
                visible->unexplore_terrain((long)this->world_x, (long)this->world_y, Override_LOS, 0, current, this->id);
            } else {
                if (this->master_obj->radius_x > 0.0 && this->master_obj->radius_y > 0.0) {
                    visible->unexplore_terrain_sq((long)(this->world_x - this->master_obj->radius_x),
                                                  (long)(this->world_y - this->master_obj->radius_y),
                                                  (long)(this->world_x + this->master_obj->radius_x - 0.01f),
                                                  (long)(this->world_y + this->master_obj->radius_y - 0.01f), current,
                                                  this->id);
                }
            }
        }
    }
}

void RGE_Static_Object::damage(int weapon_num, RGE_Armor_Weapon_Info* damage, float attack_modifier,
                               RGE_Player* attacking_player, RGE_Static_Object* attackingObject) {
    float damage_amount;

    damage_amount = this->calculateDamage(weapon_num, damage, attack_modifier, attacking_player, attackingObject);
    this->hp = this->hp - damage_amount;
    if (this->hp < 1.0) {
        this->hp = 0.0f;
        this->set_sleep_flag(0);
    }
}

float RGE_Static_Object::calculateDamage(int weapon_num, RGE_Armor_Weapon_Info* damage, float attack_modifier,
                                         RGE_Player* attacking_player, RGE_Static_Object* attackingObject) {
    float damage_amount = 0.0f;

    if (weapon_num > 0) {
        short* value = &damage->value;
        do {
            damage_amount = (float)(int)(*value) * attack_modifier + damage_amount;
            value = value + 2;
            weapon_num = weapon_num - 1;
        } while (weapon_num != 0);
    }
    return damage_amount;
}

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

void RGE_Static_Object::set_attribute(short attr_type, float attr_amount) {
    attribute_type_held = attr_type;
    attribute_amount_held = attr_amount;
}

void RGE_Static_Object::set_attribute_amount(float attr_amount, unsigned char delta, unsigned char check_max) {
    if (delta != 0) {
        this->attribute_amount_held = attr_amount + this->attribute_amount_held;
    } else {
        this->attribute_amount_held = attr_amount;
    }

    if (check_max != 0) {
        if ((float)(int)this->master_obj->attribute_max_amount < this->attribute_amount_held) {
            this->attribute_amount_held = (float)(int)this->master_obj->attribute_max_amount;
        }
    }
}

unsigned char RGE_Static_Object::heal(float healing) {
    float new_hp = healing + this->hp;
    this->hp = new_hp;
    if (healing < 0.0f) {
        if (new_hp < 1.0f)
            this->hp = 1.0f;
    }
    int maxHp = this->master_obj->hp;
    if (maxHp <= this->hp) {
        this->hp = (float)maxHp;
        return 1;
    }
    return 0;
}

void RGE_Static_Object::notify_of_relation(long player_id, unsigned char relation) {}

void RGE_Static_Object::set_being_worked_on(RGE_Action_Object* work_obj, short action_type, unsigned char attack_flag) {
    if (worker_num < 0xFA) {
        worker_num = worker_num + 1;
    }
    set_sleep_flag(0);
}

void RGE_Static_Object::release_being_worked_on(RGE_Static_Object* caller) {
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

int RGE_Static_Object::inRange(RGE_Static_Object* obj, float range) {
    float dX = obj->world_x - this->world_x;
    float dY = obj->world_y - this->world_y;

    if (dX < 0.0f) {
        dX = -dX;
    }
    if (dY < 0.0f) {
        dY = -dY;
    }

    float other_radius_x = obj->master_obj->radius_x;
    float this_radius_x = this->master_obj->radius_x;
    float this_radius_y = this->master_obj->radius_y;
    float other_radius_y = obj->master_obj->radius_y;
    float x = dX - this_radius_x - other_radius_x;
    float y = dY - this_radius_y - other_radius_y;

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

float RGE_Static_Object::distance_to_object(RGE_Static_Object* obj) {
    float dX = obj->world_x - this->world_x;
    float dY = obj->world_y - this->world_y;

    if (dX < 0.0f)
        dX = -dX;
    if (dY < 0.0f)
        dY = -dY;

    float other_radius_x = obj->master_obj->radius_x;
    float this_radius_x = this->master_obj->radius_x;
    float this_radius_y = this->master_obj->radius_y;
    float other_radius_y = obj->master_obj->radius_y;
    float x = dX - this_radius_x - other_radius_x;
    float y = dY - this_radius_y - other_radius_y;

    if (x < 0.0f)
        x = 0.0f;
    if (y < 0.0f)
        y = 0.0f;

    return (float)sqrt(x * x + y * y);
}

float RGE_Static_Object::distance_to_position(float x, float y, float z) {
    float dX = world_x - x;
    float dY = world_y - y;

    if (dX < 0.0f)
        dX = -dX;
    if (dY < 0.0f)
        dY = -dY;

    float radius_x = master_obj->radius_x;
    float radius_y = master_obj->radius_y;
    dX = dX - radius_x;
    dY = dY - radius_y;

    if (dX < 0.0f)
        dX = 0.0f;
    if (dY < 0.0f)
        dY = 0.0f;

    return sqrt(dX * dX + dY * dY);
}

unsigned char RGE_Static_Object::hit_test(short draw_x, short draw_y, short mouse_x, short mouse_y,
                                          short check_radius) {
    if (this->sprite != 0 && this->sprite_list != 0) {
        short frame = this->sprite_list->frame(this->sprite);
        short scr_x = mouse_x - this->screen_x_offset - draw_x;
        short scr_y = mouse_y - this->screen_y_offset - draw_y;

        if (this->sprite->hit_test(scr_x, scr_y, this->facet, frame) != 0) {
            return 1;
        }

        if (check_radius != 0) {
            for (short i = -check_radius; i < check_radius; ++i) {
                for (short inner = -check_radius; inner < check_radius; ++inner) {
                    if (this->sprite->hit_test(scr_x + i, scr_y + inner, this->facet, frame) != 0) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }

    return 0;
}

unsigned char RGE_Static_Object::box_hit_test(short draw_x, short draw_y, short start_x, short start_y, short end_x,
                                              short end_y) {
    if (this->sprite == 0)
        return 0;
    if (this->sprite_list == 0)
        return 0;

    this->sprite_list->get_facetindex(this->sprite, this->facet);

    short min_x;
    short min_y;
    short max_y;
    short max_x;
    if (this->get_frame(min_x, min_y, max_x, max_y) == 0)
        return 0;

    min_x = min_x + draw_x + this->screen_x_offset;
    min_y = min_y + draw_y + this->screen_y_offset;
    max_x = max_x + draw_x + this->screen_x_offset;
    max_y = max_y + draw_y + this->screen_y_offset;

    if (min_x >= start_x && min_x <= end_x && min_y >= start_y && min_y <= end_y)
        return 1;
    if (max_x >= start_x && max_x <= end_x && max_y >= start_y && max_y <= end_y)
        return 1;
    if (start_x >= min_x && start_x <= max_x && start_y >= min_y && start_y <= max_y)
        return 1;
    if (end_x >= min_x && end_x <= max_x && end_y >= min_y && end_y <= max_y)
        return 1;
    if (start_x < min_x && end_x > max_x && ((start_y > min_y && start_y < max_y) || (end_y > min_y && end_y < max_y)))
        return 1;
    if (start_y < min_y && end_y > max_y && ((start_x > min_x && start_x < max_x) || (end_x > min_x && end_x < max_x)))
        return 1;

    return 0;
}

void RGE_Static_Object::set_location(float x, float y, float z) {
    world_x = x;
    world_y = y;
    world_z = z;
}

void RGE_Static_Object::new_angle(float new_angle) {}

unsigned char RGE_Static_Object::drop_held_objects(int dropZone) {
    float drop_x[10];
    float drop_y[10];
    float radius_x[10];
    float radius_y[10];
    float x;
    float y;
    unsigned char count;
    int drop_points = 1;

    drop_x[0] = this->world_x;
    drop_y[0] = this->world_y;
    radius_x[0] = this->master_obj->radius_x * 2.0f;
    radius_y[0] = this->master_obj->radius_y * 2.0f;
    count = 0;

    RGE_Object_Node* temp = this->objects->list;
    while (temp != 0) {
        RGE_Object_Node* next = temp->next;

        while (drop_points > 0) {
            if (this->find_drop_location(dropZone, x, y, temp->node->master_obj, temp->node, drop_x[0], drop_y[0],
                                         radius_x[0], radius_y[0]) != 0) {
                RGE_Static_Object* object = temp->node;
                object->set_location(this->world_x, this->world_y, this->world_z);
                object->exit_obj();
                object->teleport(x, y, this->world_z);
                ++count;

                if (drop_points < 9) {
                    drop_x[drop_points] = x;
                    drop_y[drop_points] = y;
                    radius_x[drop_points] = object->master_obj->radius_x * 2.0f;
                    radius_y[drop_points] = object->master_obj->radius_y * 2.0f;
                    ++drop_points;
                }
                break;
            }

            --drop_points;
            if (drop_points > 0) {
                drop_x[drop_points - 1] = drop_x[drop_points];
                drop_y[drop_points - 1] = drop_y[drop_points];
                radius_x[drop_points - 1] = radius_x[drop_points];
                radius_y[drop_points - 1] = radius_y[drop_points];
            }
        }

        temp = next;
    }

    return count;
}

// the x and y outputs are float references in the shipped symbol.
unsigned char RGE_Static_Object::find_drop_location(int dropZone, float& x, float& y, RGE_Master_Static_Object* m_obj,
                                                    RGE_Static_Object* obj, float drop_x, float drop_y, float radius_x,
                                                    float radius_y) {
    radius_x = radius_x + m_obj->radius_x;
    radius_y = radius_y + m_obj->radius_y;
    float radius_2x = radius_x + radius_x;
    float radius_2y = radius_y + radius_y;
    short index = 1;

    while (index < 2) {
        short count = 0;
        do {
            switch ((debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 3898) * 4) / 0x7fff) {
            case 0: {
                x = radius_x + drop_x;
                int value = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 3902);
                y = drop_y + ((float)value * radius_2y * (1.0f / 32767.0f) - radius_y);
                break;
            }
            case 1: {
                x = drop_x - radius_x;
                int value = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 3906);
                y = drop_y + ((float)value * radius_2y * (1.0f / 32767.0f) - radius_y);
                break;
            }
            case 2: {
                y = radius_y + drop_y;
                int value = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 3910);
                x = drop_x + ((float)value * radius_2x * (1.0f / 32767.0f) - radius_x);
                break;
            }
            case 3: {
                y = drop_y - radius_y;
                int value = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 3914);
                x = drop_x + ((float)value * radius_2x * (1.0f / 32767.0f) - radius_x);
                break;
            }
            }

            if (x >= 0.0f && y >= 0.0f) {
                RGE_Map* map = this->owner->world->map;
                if (x < (float)map->map_width && y < (float)map->map_height) {
                    if (dropZone != -1 && dropZone != (int)this->lookupZone((int)x, (int)y)) {
                        goto retry_attempt;
                    }
                    // success returns from inside the retry loop.
                    if (m_obj->check_placement(this->owner, x, y, 0, 1, 1, 1, 0, 1, 1) == 0 &&
                        obj->passableTile(x, y, 0) == 1) {
                        return 1;
                    }
                }
            }
        retry_attempt:
            ++count;
        } while (count < 50);

        radius_x = radius_x + (m_obj->radius_x + m_obj->radius_x);
        radius_y = radius_y + (m_obj->radius_y + m_obj->radius_y);
        radius_2x = radius_2x + (m_obj->radius_x * 4.0f);
        radius_2y = radius_2y + (m_obj->radius_y * 4.0f);
        ++index;
    }

    return 0;
}

RGE_Check_List::RGE_Check_List() {
    this->list = 0;
}

RGE_Check_List::~RGE_Check_List() {
    RGE_Check_Node* next;

    while (this->list != 0) {
        next = this->list->next;
        free(this->list);
        this->list = next;
    }
}

void RGE_Check_List::add_node(RGE_Static_Object* obj, float dx, float dy, unsigned char flag1) {
    RGE_Check_Node* node = static_cast<RGE_Check_Node*>(calloc(1, sizeof(RGE_Check_Node)));
    node->next = this->list;
    node->node = obj;
    node->dx = dx;
    node->dy = dy;
    node->flag = flag1;
    this->list = node;
}

RGE_Check_List* RGE_Static_Object::make_object_bounds_list(float delta) {
    RGE_Master_Static_Object* master = this->master_obj;
    float rx = master->radius_x;
    float ry = master->radius_y;

    if (!(rx > 0.0f) || !(ry > 0.0f) || !(master->radius_z > 0.0f)) {
        return 0;
    }

    short min_x = (short)(this->world_x - g_object_bounds_min_adjustment);
    short min_y = (short)(this->world_y - g_object_bounds_min_adjustment);
    short max_x = (short)(this->world_x - g_object_bounds_max_adjustment);
    short max_y = (short)(this->world_y - g_object_bounds_max_adjustment);
    RGE_Map* map = this->owner->world->map;

    RGE_Check_List* check_list = new RGE_Check_List;

    if (min_x < 0) {
        min_x = 0;
    }
    if (max_x >= map->map_width) {
        max_x = (short)map->map_width;
        --max_x;
    }
    if (min_y < 0) {
        min_y = 0;
    }
    if (max_y >= map->map_height) {
        max_y = (short)map->map_height;
        --max_y;
    }

    if (min_y <= max_y) {
        int y_count = (int)max_y - (int)min_y + 1;
        int y = (int)min_y;
        do {
            RGE_Tile* tile = map->map_row_offset[y] + min_x;
            if (min_x <= max_x) {
                int x_count = (int)max_x - (int)min_x + 1;
                do {
                    RGE_Object_Node* object_node = tile->objects.list;
                    while (object_node != 0) {
                        RGE_Static_Object* object = object_node->node;
                        if (object != this) {
                            RGE_Master_Static_Object* object_master = object->master_obj;
                            float ry2 = object_master->radius_y;
                            float rx2 = object_master->radius_x;

                            if (ry2 > 0.0f && rx2 > 0.0f) {
                                float dz = object->world_z - this->world_z;
                                if (!(dz >= -object_master->radius_z) || dz > this->master_obj->radius_z) {
                                    object_node = object_node->next;
                                    continue;
                                }

                                float raw_x = object->world_x - this->world_x;
                                float raw_y = object->world_y - this->world_y;
                                unsigned char flag = 0;
                                if (!(raw_x >= 0.0f)) {
                                    raw_x = -raw_x;
                                    flag = 1;
                                }
                                if (!(raw_y >= 0.0f)) {
                                    raw_y = -raw_y;
                                    flag = (unsigned char)(flag + 2);
                                }

                                float dx = raw_x - (rx2 + rx);
                                float dy = raw_y - (ry2 + ry);
                                if (!(dx >= delta) && !(dy >= delta) && (dy >= 0.0f || dx >= 0.0f)) {
                                    check_list->add_node(object, dx, dy, flag);
                                }
                            }
                        }
                        object_node = object_node->next;
                    }
                    tile = tile + 1;
                    --x_count;
                } while (x_count != 0);
            }
            ++y;
            --y_count;
        } while (y_count != 0);
    }

    if (check_list->list == 0) {
        delete check_list;
        check_list = 0;
    }
    return check_list;
}

// The owned body is [004C6AA0, 004C6B41); later bytes are padding.
// Keep the narrow sprite facet-count read at sprite + 0x60.

extern "C" double __cdecl atan2(double, double);

int RGE_Static_Object::boundToFacet(float tX, float tY, int numberBindingFacets) {
    int best = -1;
    float smallestFacetDifference = 0.0f;
    float angle = (float)atan2(this->world_y - tY, this->world_x - tX);
    if (angle < 0.0f) {
        angle = angle + 6.2831855f;
    }
    float cur = 0.0f;
    if (numberBindingFacets == -1) {
        numberBindingFacets = this->sprite->facet_num;
    }
    float anglePerFacet = 6.2831855f / (float)numberBindingFacets;
    for (int i = 0; i < numberBindingFacets; i++) {
        float diff = angle - cur;
        if (diff < 0.0f) {
            diff = -diff;
        }
        if (best == -1 || diff < smallestFacetDifference) {
            smallestFacetDifference = diff;
            best = i;
        }
        cur = cur + anglePerFacet;
    }
    return best;
}

// The owned body is [004C6B50, 004C6B5F); the next byte is padding.
// Keep the narrow sprite facet-count read at sprite + 0x60.
int RGE_Static_Object::numberFacets() {
    if (this->sprite)
        return (int)this->sprite->facet_num;
    return 0;
}

// The owned body is [004C6B60, 004C6B67); 004C6B67 begins padding.
// The body is one narrow byte read at this + 0x86 followed by ret.
unsigned char RGE_Static_Object::underAttack() const {
    return this->underAttackValue;
}

// The owned body is [004C6B70, 004C6B7D); 004C6B7D begins padding.
// Keep the virtual, non-const setter ABI and the narrow +0x86 store.
void RGE_Static_Object::setUnderAttack(unsigned char v) {
    this->underAttackValue = v;
}

// The body is [004C6B80, 004C6C8A); 004C6C90 starts the next symbol.
int RGE_Static_Object::addToObstructionMap(int obMapCode) {
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
            if (obMapCode != 1) {
                pathSystem.incrementObstruction(x, y);
            }
            if (obMapCode != 0) {
                aiPathSystem.incrementObstruction(x, y);
            }
        }
    }

    this->lastInObstructionMapValue = this->inObstructionMapValue;
    this->inObstructionMapValue = 1;
    return 1;
}

// The owned body is [004C6C90, 004C6D9A); 004C6DA0 starts changeInfluenceMap.

int RGE_Static_Object::removeFromObstructionMap(int obMapCode) {
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
            if (obMapCode != 1) {
                pathSystem.decrementObstruction(x, y);
            }
            if (obMapCode != 0) {
                aiPathSystem.decrementObstruction(x, y);
            }
        }
    }

    this->lastInObstructionMapValue = this->inObstructionMapValue;
    this->inObstructionMapValue = 0;
    return 1;
}

extern "C" double __cdecl floor(double);
extern "C" double __cdecl ceil(double);

void RGE_Static_Object::changeInfluenceMap(InfluenceMap* iMap, int increment, int usePercentCoverage, int useLOS) {
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

    if (useLOS == 0) {
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

    if (useLOS == 0) {
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

    for (int x = minX; x < maxX; x++) {
        for (int y = minY; y < maxY; y++) {
            if (usePercentCoverage) {
                float left = (float)y;
                if (objectMinX > (float)y) left = objectMinX;
                float right = (float)(y + 1);
                if (objectMaxX < right)
                    right = objectMaxX;
                float top = (float)x;
                if (objectMinY > (float)x) top = objectMinY;
                float bottom = (float)(x + 1);
                if (objectMaxY < bottom)
                    bottom = objectMaxY;
                int value = (int)((right - left) * (bottom - top) * 255.0f);
                if (increment == 1) {
                    iMap->incrementValue(y, x, value);
                } else {
                    iMap->decrementValue(y, x, value);
                }
            } else {
                if (increment == 1) {
                    iMap->incrementValue(y, x, 255);
                } else {
                    iMap->decrementValue(y, x, 255);
                }
            }
        }
    }
}

RGE_Check_List* RGE_Static_Object::objectCollisionList(float delta) {
    RGE_Master_Static_Object* master = this->master_obj;
    float master_radius_y = master->radius_y;
    if (!(master->radius_x > 0.0f) || !(master_radius_y > 0.0f) || !(master->radius_z > 0.0)) {
        return 0;
    }

    RGE_Map* map = this->owner->world->map;
    int minXTile = (int)this->world_x - 3;
    int maxXTile = (int)this->world_x + 3;
    int minYTile = (int)this->world_y - 3;
    int maxYTile = (int)this->world_y + 3;

    if (minXTile < 0) {
        minXTile = 0;
    }
    if (maxXTile >= map->map_width) {
        maxXTile = map->map_width - 1;
    }
    if (minYTile < 0) {
        minYTile = 0;
    }
    if (maxYTile >= map->map_height) {
        maxYTile = map->map_height - 1;
    }

    RGE_Check_List* result = 0;
    for (int yIndex = minYTile; yIndex <= maxYTile; ++yIndex) {
        RGE_Tile* tile = map->map_row_offset[yIndex] + minXTile;
        for (int x = minXTile; x <= maxXTile; ++x, ++tile) {
            for (RGE_Object_Node* node = tile->objects.list; node != 0; node = node->next) {
                RGE_Static_Object* object = node->node;
                if (object == this) {
                    continue;
                }

                RGE_Master_Static_Object* object_master = object->master_obj;
                if (!(object_master->radius_z > 0.0)) {
                    continue;
                }

                float tempRX = object_master->radius_x;
                float tempRY = object_master->radius_y;
                if (!(tempRX > 0.0f) || !(tempRY > 0.0f)) {
                    continue;
                }

                float dz = object->world_z - this->world_z;
                if ((dz > 0.0f && dz > this->master_obj->radius_z) || (dz < 0.0f && dz < -object_master->radius_z)) {
                    continue;
                }

                if (this->world_x < object->world_x) {
                    float gap = (object->world_x - tempRX) - (this->world_x + this->master_obj->radius_x);
                    if (gap > delta) {
                        continue;
                    }
                } else {
                    float overlap = (object->world_x + tempRX) - (this->world_x - this->master_obj->radius_x);
                    if (overlap < -delta) {
                        continue;
                    }
                }

                if (this->world_y < object->world_y) {
                    float gap = (object->world_y - tempRY) - (this->world_y + this->master_obj->radius_y);
                    if (gap > delta) {
                        continue;
                    }
                } else {
                    float overlap = (object->world_y + tempRY) - (this->world_y - this->master_obj->radius_y);
                    if (overlap < -delta) {
                        continue;
                    }
                }

                if (result == 0) {
                    result = new RGE_Check_List;
                }
                result->add_node(object, 0.0f, 0.0f, 0);
            }
        }
    }

    return result;
}

// logDebug is a public virtual cdecl member.

void __cdecl RGE_Static_Object::logDebug(char* textIn, ...) {
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
        va_start(args, textIn);
        vsprintf(textOut, textIn, args);
        va_end(args);

        if (strlen(textOut) != 0) {
            fprintf(debugOut, "UNIT #%5d: %s\n", this->id, textOut);
        } else {
            fprintf(debugOut, "UNIT #%5d\n", this->id);
        }
    }
}

UnitAIModule* RGE_Static_Object::unitAI() {
    return this->unitAIValue;
}

unsigned char RGE_Static_Object::lookupZone(XYPoint p) {
    if (p.x < 0 || p.y < 0) {
        return 0;
    }

    RGE_Zone_Map* zoneMap;

    if (zoneMapIndex == -1) {
        RGE_Game_World* world = owner->world;
        zoneMap = world->map->map_zones->get_zone_map(world->terrains[master_obj->terrain], world->terrain_size,
                                                      zoneMapIndex);
    } else {
        RGE_Game_World* world = owner->world;
        zoneMap = world->map->map_zones->get_zone_map(zoneMapIndex);
    }

    if (zoneMap == 0) {
        return 0;
    }

    return zoneMap->get_zone_info(p.x, p.y);
}

unsigned char RGE_Static_Object::lookupZone(int x, int y) {
    RGE_Game_World* world;
    RGE_Zone_Map* zone_map;

    if (x < 0 || y < 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map(world->terrains[this->master_obj->terrain], world->terrain_size,
                                                       this->zoneMapIndex);
    } else {
        zone_map = this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }

    if (zone_map == 0) {
        return 0;
    }

    return zone_map->get_zone_info(x, y);
}

unsigned char RGE_Static_Object::currentZone() {
    RGE_Zone_Map* zoneMap;

    if (zoneMapIndex == -1) {
        RGE_Game_World* world = owner->world;
        zoneMap = world->map->map_zones->get_zone_map(world->terrains[master_obj->terrain], world->terrain_size,
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

// the point input is a reference to struct XYPoint.

int RGE_Static_Object::withinRangeOfZoneAtPoint(unsigned char zone, float range, XYPoint& point) {
    RGE_Zone_Map* zone_map;

    if (this->zoneMapIndex == -1) {
        RGE_Game_World* world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map(world->terrains[this->master_obj->terrain], world->terrain_size,
                                                       this->zoneMapIndex);
    } else {
        zone_map = this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }

    if (zone_map != 0) {
        return zone_map->withinRange(zone, point, range);
    }
    return 0;
}

int RGE_Static_Object::withinRangeOfZone(unsigned char zone, float range) {
    int ix = (int)this->world_x;
    int iy = (int)this->world_y;
    RGE_Zone_Map* zone_map;

    if (this->zoneMapIndex == -1) {
        RGE_Game_World* world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map(world->terrains[this->master_obj->terrain], world->terrain_size,
                                                       this->zoneMapIndex);
    } else {
        RGE_Game_World* world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }

    if (zone_map != 0) {
        XYPoint point;
        point.x = ix;
        point.y = iy;
        return zone_map->withinRange(zone, point, range);
    }
    return 0;
}

// the output point is a reference to struct XYPoint.

int RGE_Static_Object::findClosestPointInTerrainType(XYPoint p, XYPoint& rVal, int type1, int type2, int range) {
    RGE_Zone_Map* zone_map;
    if (this->zoneMapIndex == -1) {
        RGE_Game_World* world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map(world->terrains[this->master_obj->terrain], world->terrain_size,
                                                       this->zoneMapIndex);
    } else {
        zone_map = this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }
    if (zone_map != 0) {
        return zone_map->findClosestPointInTerrainType(p, rVal, type1, type2, range);
    }
    return 0;
}

int RGE_Static_Object::isGroupCommander(void) {
    return id == groupCommanderValue;
}

int RGE_Static_Object::inGroup() {
    return this->groupMembers.number() > 0;
}

int RGE_Static_Object::unitIsInGroup(int uID) {
    return this->groupMembers.contains(uID);
}

int RGE_Static_Object::createGroup(int* units, int count, int commander, float range) {
    if (units == 0 || count == 0) {
        return 0;
    }

    groupMembers.zeroNumber();

    if (count > 0) {
        int* current = units;
        int remaining = count;
        do {
            int id = *current;
            if (id >= 0) {
                groupMembers.add(id);
            }

            current = current + 1;
            remaining = remaining - 1;
        } while (remaining != 0);
    }

    groupCommanderValue = commander;
    groupRangeValue = range;
    return 1;
}

int RGE_Static_Object::commanderCreateGroup(int* units, int count, int commander, float range) {
    if (units == 0 || count == 0) {
        return 0;
    }

    if (count > 0) {
        int* p = units;
        int r = count;
        do {
            int id = *p;
            RGE_Static_Object* obj = owner->world->object(id);
            if (obj != 0) {
                obj->createGroup(units, count, commander, range);
            }
            p++;
            r--;
        } while (r != 0);
    }

    return 1;
}

int RGE_Static_Object::addToGroup(int unit, float range) {
    if (this->groupMembers.number() >= 25) {
        return 0;
    }

    this->groupMembers.add(unit);
    return 1;
}

int RGE_Static_Object::commanderAddToGroup(int unit, float range) {
    RGE_Static_Object* unitObj = this->owner->world->object(unit);
    int temp[25];
    ManagedArray<int>& group = this->groupMembers;
    if (unitObj == 0) {
        return 0;
    }

    if (group.number() >= 25) {
        return 0;
    }

    int i = 0;
    if (group.number() > 0) {
        do {
            int member = group[i];
            temp[i] = member;
            if (member != this->id) {
                RGE_Static_Object* object = this->owner->world->object(group[i]);
                if (object != 0) {
                    object->addToGroup(unit, range);
                }
            }
            ++i;
        } while (i < group.number());
    }

    temp[i] = unit;
    this->addToGroup(unit, range);
    unitObj->createGroup(temp, i + 1, this->id, range);
    return 1;
}

int RGE_Static_Object::removeFromGroup(int unit) {
    int result = groupMembers.remove(unit);
    if (groupMembers.number() <= 0) {
        groupCommanderValue = -1;
    }
    return result;
}

int RGE_Static_Object::commanderRemoveFromGroup(int uID) {
    if (uID == this->id && this->id == this->groupCommanderValue) {
        return this->commanderDestroyGroup();
    }

    int i = 0;
    if (this->groupMembers.number() > 0) {
        do {
            RGE_Static_Object* object = this->owner->world->object(this->groupMembers[i]);
            if (object != 0 && object->id != this->id) {
                object->groupMembers.remove(uID);
            }

            ++i;
        } while (i < this->groupMembers.number());
    }

    this->removeFromGroup(uID);
    return 1;
}

int RGE_Static_Object::destroyGroup() {
    groupMembers.zeroNumber();
    groupCommanderValue = -1;
    return 1;
}

int RGE_Static_Object::commanderDestroyGroup() {
    int i = 0;
    if (this->groupMembers.number() > 0) {
        do {
            RGE_Static_Object* object = this->owner->world->object(this->groupMembers[i]);
            if (object != 0 && object->id != this->id) {
                object->destroyGroup();
            }
            ++i;
        } while (i < this->groupMembers.number());
    }
    this->destroyGroup();
    return 1;
}

void RGE_Static_Object::addToPathingGroup(int uID) {
    this->pathingGroupMembers.add(uID);
}

void RGE_Static_Object::removeAllFromPathingGroup(void) {
    if (owner->computerPlayer() == 1) {
        pathingGroupMembers.zeroNumber();
    }
}

void RGE_Static_Object::remove_shadows(void) {
    int x0 = (int)this->world_x;
    int y0 = (int)this->world_y;
    this->owner->world->map->request_redraw(x0 - 2, y0 - 2, x0 + 1, y0 + 1, 0);
}

void RGE_Static_Object::set_sleep_flag(unsigned char flag_in) {
    if (sleep_flag == flag_in)
        return;

    if (flag_in == 0) {
        if (goto_sleep_flag != 0) {
            sleep_flag = 0;
            goto_sleep_flag = 0;
            return;
        }

        RGE_Object_Node* oldField = player_object_node;
        owner->removeObject(this, (int)(unsigned char)sleep_flag, (int)dopple_flag, oldField);

        sleep_flag = 0;
        player_object_node = owner->addObject(this, 0, (int)dopple_flag);
        return;
    }

    goto_sleep_flag = 1;
    sleep_flag = flag_in;
}

// the shipped getter returns long and is virtual.
long RGE_Static_Object::get_action_checksum() {
    return 0;
}

// the shipped getter returns long and is virtual.
long RGE_Static_Object::get_waypoint_checksum() {
    return 0;
}
