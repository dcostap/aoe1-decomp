#include "../include/RGE_Doppleganger_Object.h"
#include "../include/RGE_Active_Sprite_List.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Doppleganger_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Tile.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"

#include <stdint.h>

static void rge_doppleganger_reset_fields(RGE_Doppleganger_Object* self) {
    self->doppled_object = nullptr;
    self->draw_color = nullptr;
    self->doppled_master_obj = nullptr;
    self->doppled_player = 0;
    self->MapAddress = nullptr;
    self->LastMapValue = 0;
    self->CantSeeBits = 0;
    self->map_draw_level = '\0';
    self->map_color = '\0';
    self->doppledObjectID = -1;
}

// Default constructor
RGE_Doppleganger_Object::RGE_Doppleganger_Object()
    : RGE_Animated_Object()
{
    rge_doppleganger_reset_fields(this);
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x004418A0
RGE_Doppleganger_Object::RGE_Doppleganger_Object(
    RGE_Master_Doppleganger_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6, RGE_Static_Object* param_7)
    : RGE_Animated_Object() {
    rge_doppleganger_reset_fields(this);

    if (param_6 != 0) {
        this->setup(param_1, param_2, param_3, param_4, param_5);
    }

    this->doppled_object = param_7;
    if (param_7 == nullptr) {
        this->doppledObjectID = -1;
        this->doppled_master_obj = nullptr;
        this->doppled_player = 0;
        RGE_Static_Object::destroy_obj();
    } else {
        this->doppled_master_obj = param_7->master_obj;
        this->doppled_player = (int)param_7->owner->id;
        this->doppledObjectID = param_7->id;
        this->sprite = param_7->sprite;
        RGE_Active_Sprite_Node* copied = param_7->sprite_list->copy_sprite_list();
        this->sprite_list->use_sprite_list(copied);
        this->facet = param_7->facet;
        this->draw_color = param_7->owner->color_table;
        this->map_draw_level = param_7->master_obj->map_draw_level;
        if (this->map_draw_level == 3) {
            this->map_color = param_7->master_obj->map_color;
        } else {
            this->map_color = param_7->owner->color_table->map_color;
        }
        if (param_7->object_state > 6) {
            this->doppled_object = nullptr;
            this->doppledObjectID = -1;
        }
    }
    this->validate();
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00441A70
RGE_Doppleganger_Object::RGE_Doppleganger_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Animated_Object(param_1, param_2, 0)
{
    int fd = param_1;

    rge_doppleganger_reset_fields(this);

    if (param_3 != 0) {
        this->setup(fd, param_2);
    }

    // Read doppleganger-specific fields after setup
    int temp_int = 0;

    rge_read(fd, &temp_int, 4);
    this->doppled_object = (RGE_Static_Object*)temp_int; // stored as int, rehook resolves to pointer

    this->doppledObjectID = -1;

    rge_read(fd, &this->map_draw_level, 1);
    rge_read(fd, &this->map_color, 4);

    rge_read(fd, &temp_int, 4);
    this->doppled_master_obj = (RGE_Master_Static_Object*)temp_int; // stored as int, rehook resolves

    rge_read(fd, &this->doppled_player, 4);

    if (save_game_version >= 7.06f) {
        rge_read(fd, &this->CantSeeBits, 4);
    }
}

// Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00463000, obj_list.cpp.asm @ 0x00463055
void RGE_Doppleganger_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4) {
    RGE_Animated_Object::draw(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00463100, obj_list.cpp.asm @ 0x00463139
void RGE_Doppleganger_Object::shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4) {
    RGE_Animated_Object::shadow_draw(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00463180, obj_list.cpp.asm @ 0x004631BA
void RGE_Doppleganger_Object::normal_draw(TDrawArea* param_1, short param_2, short param_3) {
    RGE_Animated_Object::normal_draw(param_1, param_2, param_3);
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00441BB0
void RGE_Doppleganger_Object::recycle_in_to_game(
    RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, RGE_Static_Object* param_6) {
    CUSTOM_DEBUG_BEGIN
    static int s_dopple_recycle_dbg_calls = 0;
    int dbg_call_index = s_dopple_recycle_dbg_calls;
    if (dbg_call_index < 32) {
        CUSTOM_DEBUG_LOG_FMT(
            "DOPPLE recycle(6) enter this=%p master=%p player=%p x=%.3f y=%.3f z=%.3f src=%p",
            this,
            param_1,
            param_2,
            param_3,
            param_4,
            param_5,
            param_6);
    }
    s_dopple_recycle_dbg_calls = dbg_call_index + 1;
    CUSTOM_DEBUG_END

    rge_doppleganger_reset_fields(this);

    RGE_Animated_Object::recycle_in_to_game(param_1, param_2, param_3, param_4, param_5);
    this->type = 0x19;

    CUSTOM_DEBUG_BEGIN
    if (dbg_call_index < 32) {
        CUSTOM_DEBUG_LOG_FMT(
            "DOPPLE recycle after base this.owner=%p this.world=%p this.sprite_list=%p",
            this->owner,
            (this->owner != nullptr) ? this->owner->world : nullptr,
            this->sprite_list);
    }
    CUSTOM_DEBUG_END

    this->doppled_object = param_6;
    if (param_6 == nullptr) {
        this->doppledObjectID = -1;
        this->doppled_master_obj = nullptr;
        this->doppled_player = 0;
        this->destroy_obj();
    } else {
        CUSTOM_DEBUG_BEGIN
        if (dbg_call_index < 32) {
            CUSTOM_DEBUG_LOG_FMT(
                "DOPPLE recycle src owner=%p master=%p sprite=%p sprite_list=%p id=%ld state=%u",
                param_6->owner,
                param_6->master_obj,
                param_6->sprite,
                param_6->sprite_list,
                param_6->id,
                (unsigned)param_6->object_state);
        }
        CUSTOM_DEBUG_END

        this->doppled_master_obj = param_6->master_obj;
        this->doppled_player = (int)param_6->owner->id;
        this->doppledObjectID = param_6->id;
        this->sprite = param_6->sprite;
        RGE_Active_Sprite_Node* copied = param_6->sprite_list->copy_sprite_list();
        this->sprite_list->use_sprite_list(copied);
        this->facet = param_6->facet;
        this->draw_color = param_6->owner->color_table;
        this->map_draw_level = param_6->master_obj->map_draw_level;
        if (this->map_draw_level == 3) {
            this->map_color = param_6->master_obj->map_color;
        } else {
            this->map_color = param_6->owner->color_table->map_color;
        }
        this->MapAddress = unified_map_offsets[(int)this->world_y] + (int)this->world_x;
        this->LastMapValue = 0;
        this->CantSeeBits = 0;
        if (param_6->object_state > 6) {
            this->doppled_object = nullptr;
            this->doppledObjectID = -1;
            CUSTOM_DEBUG_BEGIN
            if (dbg_call_index < 32) {
                CUSTOM_DEBUG_LOG("DOPPLE recycle src state>6; calling validate() and returning");
            }
            CUSTOM_DEBUG_END
            this->validate();
            return;
        }
    }

    CUSTOM_DEBUG_BEGIN
    if (dbg_call_index < 32) {
        CUSTOM_DEBUG_LOG("DOPPLE recycle calling validate()");
    }
    CUSTOM_DEBUG_END
    this->validate();
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00441D30
int RGE_Doppleganger_Object::setup(
    RGE_Master_Doppleganger_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    RGE_Animated_Object::setup((RGE_Master_Animated_Object*)param_1, param_2, param_3, param_4, param_5);
    this->type = 0x19;
    this->MapAddress = unified_map_offsets[(int)this->world_y] + (int)this->world_x;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    return 1;
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00441DA0, dpl_obj.cpp.asm @ 0x00441DA0
int RGE_Doppleganger_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Animated_Object::setup(param_1, param_2);
    this->type = 0x19;

    // Compute MapAddress from unified_map_offsets using world coordinates
    int y = (int)this->world_y;
    int x = (int)this->world_x;
    this->MapAddress = unified_map_offsets[y] + x;

    this->LastMapValue = 0;
    this->CantSeeBits = 0;

    return 1;
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00441E00
void RGE_Doppleganger_Object::rehook() {
    RGE_Static_Object::rehook();

    RGE_Player* draw_owner = nullptr;
    intptr_t dopple_obj_value = (intptr_t)this->doppled_object;
    if (dopple_obj_value < 0) {
        this->doppled_object = nullptr;
        this->doppledObjectID = -1;
        int owner_id = -1 - (int)dopple_obj_value;
        draw_owner = this->owner->world->players[owner_id];
    } else {
        RGE_Static_Object* resolved = this->get_object_pointer((long)dopple_obj_value);
        this->doppled_object = resolved;
        if (resolved != nullptr) {
            this->doppledObjectID = resolved->id;
            draw_owner = resolved->owner;
        }
    }

    if (draw_owner != nullptr) {
        this->draw_color = draw_owner->color_table;
    }

    intptr_t master_value = (intptr_t)this->doppled_master_obj;
    if (master_value >= 0) {
        RGE_Player* owner_player = this->owner->world->players[this->doppled_player];
        if (owner_player != nullptr && master_value < owner_player->master_object_num) {
            this->doppled_master_obj = owner_player->master_objects[(int)master_value];
            return;
        }
    }

    this->doppled_master_obj = nullptr;
    this->destroy_obj();
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00441EB0
uchar RGE_Doppleganger_Object::update() {
    uchar ret = RGE_Animated_Object::update();

    if (this->doppled_object != nullptr) {
        if (this->doppled_object->object_state >= 7) {
            this->doppled_object = nullptr;
            this->doppledObjectID = -1;
        }
    } else {
        this->doppledObjectID = -1;
    }

    unsigned long map_value = *this->MapAddress;
    if (map_value != this->LastMapValue) {
        if ((this->owner->mutualVisibleMask & map_value) != 0 && this->object_state < 3) {
            this->destroy_obj();
        }

        unsigned long lose_visible_bits = this->owner->nonMutualVisibleMask & map_value;
        if (lose_visible_bits != 0) {
            unsigned long* remove_bits = this->owner->RemoveVisibleBits;
            while (lose_visible_bits != 0) {
                if ((lose_visible_bits & 1) != 0) {
                    this->CantSeeBits = this->CantSeeBits | *remove_bits;
                }
                remove_bits = remove_bits + 1;
                lose_visible_bits = lose_visible_bits >> 1;
            }
        }
        this->LastMapValue = map_value;
    }

    return ret;
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00441F80
void RGE_Doppleganger_Object::save(int param_1) {
    int fd = param_1;
    RGE_Animated_Object::save(param_1);

    int temp = 0;
    if (this->doppled_object == nullptr) {
        temp = -1 - this->doppled_player;
    } else {
        temp = this->doppled_object->id;
    }
    rge_write(fd, &temp, 4);
    rge_write(fd, &this->map_draw_level, 1);
    rge_write(fd, &this->map_color, 4);

    if (this->doppled_master_obj == nullptr) {
        temp = -1;
    } else {
        temp = (int)this->doppled_master_obj->id;
    }
    rge_write(fd, &temp, 4);
    rge_write(fd, &this->doppled_player, 4);

    if (save_game_version >= 7.06f) {
        rge_write(fd, &this->CantSeeBits, 4);
    }
}

// Fully verified. Source of truth: dpl_obj.cpp.decomp @ 0x00442050
void RGE_Doppleganger_Object::validate() {
    RGE_Map* map = this->owner->world->map;
    if (map == nullptr || map->map_row_offset == nullptr) {
        return;
    }

    int tile_x = (int)this->world_x;
    int tile_y = (int)this->world_y;

    RGE_Tile* row = map->map_row_offset[tile_y];
    if (row == nullptr) {
        return;
    }

    RGE_Object_Node* node = row[tile_x].objects.list;
    while (node != nullptr) {
        RGE_Static_Object* obj = node->node;
        if (obj != nullptr &&
            obj->type == 0x19 &&
            obj->id != this->id &&
            ((RGE_Doppleganger_Object*)obj)->doppledObjectID == this->doppledObjectID &&
            obj->object_state == 2) {
            short this_owner = this->owner->id;
            short other_owner = obj->owner->id;
            if (other_owner == this_owner) {
                obj->destroy_obj();
            } else {
                ((RGE_Doppleganger_Object*)obj)->CantSeeBits |= (1UL << (this_owner & 0x1F));
                this->CantSeeBits |= (1UL << (other_owner & 0x1F));
            }
        }
        node = node->next;
    }
}
