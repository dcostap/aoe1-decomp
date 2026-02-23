#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Master_Doppleganger_Object.h"
#include "../include/RGE_Doppleganger_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Visible_Map.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Action_Object.h"
#include "../include/TDrawArea.h"
#include "../include/TShape.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Tile.h"
#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/PathingSystem.h"
#include "../include/RGE_Active_Sprite_List.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Damage_Sprite_Info.h"
#include "../include/RGE_Unified_Visible_Map.h"
#include "../include/RGE_Sound.h"
#include "../include/Visible_Resource_Manager.h"
#include "../include/RGE_Doppleganger_Creator.h"
#include "../include/RGE_Base_Game.h"
#include "../include/DClipInfo_List.h"
#include "../include/globals.h"
#include "../include/debug_helpers.h"
#include "../include/custom_debug.h"
#include <cstring>
#include <new>

static void rge_static_set_sleep_flag(RGE_Static_Object* obj, uchar sleep_flag) {
    if (obj == nullptr || obj->owner == nullptr) {
        return;
    }

    if (obj->sleep_flag == sleep_flag) {
        return;
    }

    if (sleep_flag == 0) {
        if (obj->goto_sleep_flag != 0) {
            obj->sleep_flag = 0;
            obj->goto_sleep_flag = 0;
            return;
        }

        obj->owner->removeObject(obj, (int)obj->sleep_flag, (int)obj->dopple_flag, obj->player_object_node);
        obj->sleep_flag = 0;
        obj->player_object_node = obj->owner->addObject(obj, 0, (int)obj->dopple_flag);
        return;
    }

    obj->goto_sleep_flag = 1;
    obj->sleep_flag = sleep_flag;
}

void RGE_Static_Object::set_sleep_flag(uchar sleep_flag) {
    // Fully verified. Source of truth: stat_obj.cpp.asm calls this helper via RGE_Static_Object::set_sleep_flag.
    rge_static_set_sleep_flag(this, sleep_flag);
}

static void rge_static_ensure_group_capacity(ManagedArray<int>& arr, int required_index) {
    if (arr.maximumSizeValue - 1 >= required_index) {
        return;
    }

    int new_capacity = required_index + 1;
    int* new_values = (int*)operator new(new_capacity * (int)sizeof(int));
    if (new_values == nullptr) {
        return;
    }

    int copy_index = 0;
    if (arr.maximumSizeValue > 0) {
        while (copy_index < arr.maximumSizeValue) {
            if (required_index + 1 <= copy_index) {
                break;
            }
            new_values[copy_index] = arr.value[copy_index];
            copy_index = copy_index + 1;
        }
    }

    operator delete(arr.value);
    arr.value = new_values;
    arr.maximumSizeValue = new_capacity;
}

static void rge_static_add_unique_member(ManagedArray<int>& arr, int value) {
    int current_count = arr.numberValue;
    for (int index = 0; index < current_count; ++index) {
        if (arr.maximumSizeValue <= index) {
            break;
        }
        if (arr.value[index] == value) {
            return;
        }
    }

    if (arr.maximumSizeValue - 1 < arr.numberValue) {
        rge_static_ensure_group_capacity(arr, arr.numberValue);
    }

    if (arr.value != nullptr && arr.numberValue < arr.maximumSizeValue) {
        arr.value[arr.numberValue] = value;
        arr.numberValue = arr.numberValue + 1;
    }
}

struct AIPlayStatusRaw {
    unsigned char bytes[0x1C8];
};

static void rge_static_set_unit_ai_play_status(UnitAIModule* target_unit_ai, UnitAIModule* source_unit_ai) {
    // ASM source: stat_obj.cpp.asm @ 0x004C55BF reads UnitAIModule::playStatus at +0x12C.
    if (target_unit_ai == nullptr) {
        return;
    }

    AIPlayStatusRaw** target_slot = (AIPlayStatusRaw**)((unsigned char*)target_unit_ai + 0x12C);
    if (*target_slot == nullptr) {
        AIPlayStatusRaw* new_status = (AIPlayStatusRaw*)operator new(sizeof(AIPlayStatusRaw));
        if (new_status == nullptr) {
            return;
        }
        std::memset(new_status, 0, sizeof(AIPlayStatusRaw));
        *target_slot = new_status;
    }

    if (source_unit_ai == nullptr) {
        return;
    }

    AIPlayStatusRaw* source_status = *(AIPlayStatusRaw**)((unsigned char*)source_unit_ai + 0x12C);
    if (source_status == nullptr) {
        return;
    }

    std::memcpy(*target_slot, source_status, sizeof(AIPlayStatusRaw));
}

static void rge_static_ctor_common_init(RGE_Static_Object* obj) {
    obj->id = 0;
    obj->master_obj = nullptr;
    obj->owner = nullptr;
    obj->sprite = nullptr;
    obj->old_sprite = nullptr;
    obj->sprite_list = nullptr;
    obj->tile = nullptr;
    obj->inside_obj = nullptr;
    obj->objects = nullptr;
    obj->screen_x_offset = 0;
    obj->screen_y_offset = 0;
    obj->shadow_x_offset = 0;
    obj->shadow_y_offset = 0;
    obj->hp = 0.0f;
    obj->curr_damage_percent = 0;
    obj->facet = 0;
    obj->selected = 0;
    obj->selected_group = 0;
    obj->world_x = 0.0f;
    obj->world_y = 0.0f;
    obj->world_z = 0.0f;
    obj->attribute_amount_held = 0.0f;
    obj->object_state = 0;
    obj->sleep_flag = 0;
    obj->dopple_flag = 0;
    obj->goto_sleep_flag = 0;
    obj->attribute_type_held = -1;
    obj->type = 0x0A;
    obj->worker_num = 0;
    obj->player_object_node = nullptr;

    obj->pathingGroupMembers.value = nullptr;
    obj->pathingGroupMembers.numberValue = 0;
    obj->pathingGroupMembers.desiredNumberValue = 0;
    obj->pathingGroupMembers.maximumSizeValue = 0;

    obj->groupMembers.value = nullptr;
    obj->groupMembers.numberValue = 0;
    obj->groupMembers.desiredNumberValue = 0;
    obj->groupMembers.maximumSizeValue = 0;

    obj->groupCommanderValue = -1;
    obj->zoneMapIndex = -1;
    obj->unitAIValue = nullptr;
    obj->groupRangeValue = 5.0f;
    obj->inObstructionMapValue = 0;
    obj->lastInObstructionMapValue = 0;
    obj->underAttackValue = 0;
    obj->player_object_node = nullptr;
}

RGE_Static_Object::RGE_Static_Object() {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C11E0 init path (no setup call)
    rge_static_ctor_common_init(this);
}

RGE_Static_Object::RGE_Static_Object(int param_1, RGE_Game_World* param_2, int param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C11E0
    rge_static_ctor_common_init(this);

    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// TODO: STUB, many RGE_Static_Object virtuals below still need full stat_obj.cpp transliteration.
RGE_Static_Object::~RGE_Static_Object() {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C1290
    this->remove_visible_resource();

    if (this->owner != nullptr) {
        if (this->object_state < 3) {
            this->take_attribute_from_owner();
        }
        if (this->object_state < 7 && this->owner != nullptr) {
            if (this->owner->victory_conditions != nullptr) {
                this->owner->victory_conditions->update_for_object(this);
            } else {
                static int s_static_dtor_vc_guard_logs = 0;
                CUSTOM_DEBUG_BEGIN
                if (s_static_dtor_vc_guard_logs < 64) {
                    CUSTOM_DEBUG_LOG_FMT(
                        "RGE_Static_Object deleting-dtor guard: missing victory_conditions id=%ld owner=%p",
                        this->id,
                        this->owner);
                    s_static_dtor_vc_guard_logs++;
                }
                CUSTOM_DEBUG_END
            }
        }
    }

    if (this->sprite_list != nullptr) {
        void*** sprite_list_vtable = (void***)this->sprite_list;
        void(__thiscall *deleting_dtor)(void*, int) = (void(__thiscall*)(void*, int))(*sprite_list_vtable)[0];
        deleting_dtor(this->sprite_list, 1);
        this->sprite_list = nullptr;
    }

    if (this->owner != nullptr) {
        if ((this->selected & 1) != 0) {
            this->owner->unselect_one_object(this);
        }
        this->owner->removeObject(this, (int)this->sleep_flag, (int)this->dopple_flag, this->player_object_node);
        this->owner = nullptr;
    }

    if (this->tile != nullptr) {
        this->tile->objects.remove_node(this, nullptr);
        this->tile = nullptr;
    }

    if (this->master_obj != nullptr && this->master_obj->radius_z > 0.0f) {
        this->removeFromObstructionMap(2);
    }

    if (this->inside_obj != nullptr) {
        this->inside_obj->objects->remove_node(this, nullptr);
        this->inside_obj = nullptr;
    }

    if (this->objects != nullptr) {
        RGE_Object_Node* node = this->objects->list;
        while (node != nullptr) {
            RGE_Object_Node* next = node->next;
            node->node->exit_obj();
            node = next;
        }

        this->objects->~RGE_Object_List();
        operator delete(this->objects);
    }

    if (this->unitAIValue != nullptr) {
        void*** unit_ai_vtable = (void***)this->unitAIValue;
        void(__thiscall *deleting_dtor)(void*, int) = (void(__thiscall*)(void*, int))(*unit_ai_vtable)[0];
        deleting_dtor(this->unitAIValue, 1);
        this->unitAIValue = nullptr;
    }

    if (this->groupMembers.value != nullptr) {
        operator delete(this->groupMembers.value);
        this->groupMembers.value = nullptr;
    }
    this->groupMembers.numberValue = 0;
    this->groupMembers.desiredNumberValue = 0;
    this->groupMembers.maximumSizeValue = 0;

    if (this->pathingGroupMembers.value != nullptr) {
        operator delete(this->pathingGroupMembers.value);
        this->pathingGroupMembers.value = nullptr;
    }
    this->pathingGroupMembers.numberValue = 0;
    this->pathingGroupMembers.desiredNumberValue = 0;
    this->pathingGroupMembers.maximumSizeValue = 0;
}
void RGE_Static_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C1420
    this->old_sprite = nullptr;
    this->unitAIValue = nullptr;
    this->underAttackValue = 0;
    this->sprite = nullptr;
    this->groupCommanderValue = -1;
    this->groupRangeValue = 5.0f;
    this->owner = param_2;
    this->master_obj = param_1;
    this->tile = nullptr;
    this->inside_obj = nullptr;

    float hp_value = (float)(int)(short)param_1->hp;
    this->hp = hp_value;
    this->sleep_flag = (hp_value > 0.0f) ? 1 : 0;
    this->dopple_flag = (param_1->master_type == 0x19) ? 1 : 0;

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
    this->player_object_node = nullptr;

    this->get_starting_attribute();
    this->give_attribute_to_owner();
    this->new_sprite(this->master_obj->sprite);

    this->world_x = param_3;
    this->world_y = param_4;
    this->world_z = param_5;
    this->old_sprite = nullptr;
    this->teleport(param_3, param_4, param_5);

    this->player_object_node = this->owner->addObject(this, (int)this->sleep_flag, (int)this->dopple_flag);

    unsigned int r_num = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x183);
    int saved_random_on = debug_random_on;
    debug_random_on = 0;

    RGE_Sound* created_sound = this->master_obj->created_sound;
    if (created_sound != nullptr && this->owner->id == this->owner->world->curr_player) {
        created_sound->play(1);
    }

    debug_random_on = saved_random_on;
    debug_srand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x18d, r_num);
}

void RGE_Static_Object::recycle_out_of_game() {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C1590
    if (this->master_obj->recyclable != 0 &&
        this->owner->world->recycle_object_out_of_game(this->master_obj->master_type, this) != 0) {
        if (this->object_state < 3) {
            this->take_attribute_from_owner();
        }
        if (this->object_state < 7) {
            if (this->owner != nullptr && this->owner->victory_conditions != nullptr) {
                this->owner->victory_conditions->update_for_object(this);
            } else {
                static int s_recycle_vc_guard_logs = 0;
                CUSTOM_DEBUG_BEGIN
                if (s_recycle_vc_guard_logs < 32) {
                    CUSTOM_DEBUG_LOG_FMT(
                        "RGE_Static_Object recycle guard: missing victory_conditions id=%ld owner=%p",
                        this->id,
                        this->owner);
                    s_recycle_vc_guard_logs++;
                }
                CUSTOM_DEBUG_END
            }
        }
        if (this->sprite_list != nullptr) {
            this->sprite_list->delete_list();
        }
        if (this->owner != nullptr) {
            if ((this->selected & 1) != 0) {
                this->owner->unselect_one_object(this);
            }
            this->owner->removeObject(this, (int)this->sleep_flag, (int)this->dopple_flag, this->player_object_node);
            this->owner = nullptr;
        }
        if (this->tile != nullptr) {
            this->tile->objects.remove_node(this, nullptr);
            this->tile = nullptr;
        }
        if (this->inside_obj != nullptr) {
            this->inside_obj->objects->remove_node(this, nullptr);
            this->inside_obj = nullptr;
        }
        if (this->objects != nullptr) {
            RGE_Object_Node* node = this->objects->list;
            while (node != nullptr) {
                RGE_Object_Node* next = node->next;
                node->node->exit_obj();
                node = next;
            }
        }
        if (this->unitAIValue != nullptr) {
            void*** unit_ai_vtable = (void***)this->unitAIValue;
            void(__thiscall *deleting_dtor)(void*, int) = (void(__thiscall*)(void*, int))(*unit_ai_vtable)[0];
            deleting_dtor(this->unitAIValue, 1);
            this->unitAIValue = nullptr;
        }
        if (this->master_obj != nullptr && this->master_obj->radius_z > 0.0f) {
            this->removeFromObstructionMap(2);
        }
        this->master_obj = nullptr;
        return;
    }

    if (this != nullptr) {
        void*** self_vtable = (void***)this;
        void(__thiscall *deleting_dtor)(void*, int) = (void(__thiscall*)(void*, int))(*self_vtable)[0];
        deleting_dtor(this, 1);
    }
}
void RGE_Static_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C1F30
    static int s_static_draw_guard_logs = 0;
    SDI_Object_ID = this->id;

    if (this->owner == nullptr || this->sprite_list == nullptr || this->master_obj == nullptr) {
        CUSTOM_DEBUG_BEGIN
        if (s_static_draw_guard_logs < 32) {
            CUSTOM_DEBUG_LOG_FMT(
                "RGE_Static_Object::draw guard: id=%ld owner=%p sprite_list=%p master=%p state=%u tile=%p type=%u",
                this->id,
                this->owner,
                this->sprite_list,
                this->master_obj,
                (unsigned int)this->object_state,
                this->tile,
                (unsigned int)this->type);
            s_static_draw_guard_logs++;
        }
        CUSTOM_DEBUG_END
        SDI_Object_ID = -1;
        return;
    }

    if (this->type == 0x19) {
        // Doppleganger draw: draw visibility gating + real underlying object id for capture/pick.
        RGE_Doppleganger_Object* dop = (RGE_Doppleganger_Object*)this;
        if (this->owner->world == nullptr) {
            SDI_Object_ID = -1;
            return;
        }
        if (((uint)dop->CantSeeBits & (1u << ((uint)this->owner->world->curr_player & 0x1f))) != 0) {
            SDI_Object_ID = -1;
            return;
        }
        if (dop->doppled_object == nullptr) {
            SDI_Object_ID = -1;
        } else {
            SDI_Object_ID = dop->doppled_object->id;
        }
    }

    if ((this->tile != nullptr) && (this->object_state < 7)) {
        if ((this->selected != 0) || (rge_base_game->outline_type == 3) ||
            (((this->master_obj->draw_flag & 1) == 1) && (rge_base_game->prog_mode == 7))) {
            this->capture_frame(param_1, param_2, param_3);
        }
        SDI_Draw_Line = (int)param_3 + (int)this->shadow_y_offset;
        this->sprite_list->draw(this->facet, this->screen_x_offset + param_2, this->screen_y_offset + param_3,
                                this->shadow_x_offset + param_2, param_3 + this->shadow_y_offset, param_4, param_1);
    }

    SDI_Object_ID = -1;
}

void RGE_Static_Object::shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C2030
    static int s_static_shadow_guard_logs = 0;
    if (this->owner == nullptr || this->sprite_list == nullptr) {
        CUSTOM_DEBUG_BEGIN
        if (s_static_shadow_guard_logs < 16) {
            CUSTOM_DEBUG_LOG_FMT(
                "RGE_Static_Object::shadow_draw guard: id=%ld owner=%p sprite_list=%p state=%u",
                this->id,
                this->owner,
                this->sprite_list,
                (unsigned int)this->object_state);
            s_static_shadow_guard_logs++;
        }
        CUSTOM_DEBUG_END
        return;
    }
    if ((this->tile != nullptr) && (this->object_state < 7)) {
        RGE_Color_Table* ct = this->owner->color_table;
        this->sprite_list->shadow_draw(this->facet, this->shadow_x_offset + param_2, this->shadow_y_offset + param_3, ct, param_1, param_4);
    }
}

void RGE_Static_Object::normal_draw(TDrawArea* param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C2080
    static int s_static_normal_guard_logs = 0;
    if (this->owner == nullptr || this->sprite_list == nullptr) {
        CUSTOM_DEBUG_BEGIN
        if (s_static_normal_guard_logs < 16) {
            CUSTOM_DEBUG_LOG_FMT(
                "RGE_Static_Object::normal_draw guard: id=%ld owner=%p sprite_list=%p state=%u",
                this->id,
                this->owner,
                this->sprite_list,
                (unsigned int)this->object_state);
            s_static_normal_guard_logs++;
        }
        CUSTOM_DEBUG_END
        return;
    }
    if ((this->tile != nullptr) && (this->object_state < 7)) {
        bool draw_frame = (this->selected != 0) || (rge_base_game->outline_type == 3);
        if (draw_frame) {
            this->draw_back_frame(param_1, param_2, param_3);
        }
        RGE_Color_Table* ct = this->owner->color_table;
        this->sprite_list->normal_draw(this->facet, this->screen_x_offset + param_2, this->screen_y_offset + param_3, ct, param_1);
        if (draw_frame) {
            this->draw_front_frame(param_1, param_2, param_3);
        }
    }
}

void RGE_Static_Object::draw_front_frame(TDrawArea* param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C2110
    if (rge_base_game->game_mode != 1) {
        switch (rge_base_game->outline_type) {
        case 0:
            this->draw_frame(param_1, param_2, param_3);
            return;
        case 1:
            this->draw_frame_3d_cube_front(param_1, param_2, param_3);
            return;
        case 2:
        case 3:
            this->draw_frame_3d_square_front(param_1, param_2, param_3);
            return;
        }
        return;
    }
    this->draw_frame_3d_cube_front(param_1, param_2, param_3);
}

void RGE_Static_Object::draw_back_frame(TDrawArea* param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C21A0
    if (rge_base_game->game_mode == 1) {
        this->draw_frame_3d_cube_back(param_1, param_2, param_3);
        return;
    }
    switch (rge_base_game->outline_type) {
    case 1:
        this->draw_frame_3d_cube_back(param_1, param_2, param_3);
        return;
    case 2:
    case 3:
        this->draw_frame_3d_square_back(param_1, param_2, param_3);
        return;
    }
}

void RGE_Static_Object::draw_frame(TDrawArea* param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C3B30
    if ((this->sprite != nullptr) && (this->sprite_list != nullptr)) {
        this->sprite_list->get_facetindex(this->sprite, this->facet);
        short min_x = 0;
        short min_y = 0;
        short max_x = 0;
        short max_y = 0;
        if (this->get_frame(&min_x, &min_y, &max_x, &max_y) != 0) {
            int x1 = (int)min_x + (int)param_2 + -1 + (int)this->screen_x_offset;
            int y1 = (int)min_y + (int)param_3 + -1 + (int)this->screen_y_offset;
            int x2 = (int)max_x + (int)param_2 + 1 + (int)this->screen_x_offset;
            int y2 = (int)max_y + (int)param_3 + 1 + (int)this->screen_y_offset;
            param_1->DrawRect(x1, y1, x2, y2, 0xff);

            if (this->object_state < 3) {
                int hp_int = (int)this->hp;
                if (hp_int < 1) {
                    hp_int = 0;
                }
                int tot_hp = (int)this->master_obj->hp;
                if (tot_hp > 0) {
                    param_1->DrawRect(x1, y1 + -6, x1 + 0x1a, y1 + -1, 0xff);
                    int bar_left = x1 + 1;
                    param_1->FillRect(bar_left, y1 + -5, x1 + 0x18, y1 + -3, 0x55);
                    int filled = (hp_int * 0x19) / tot_hp;
                    if (filled > 0) {
                        param_1->FillRect(bar_left, y1 + -5, bar_left + filled + -1, y1 + -2, 0x25);
                    }
                }
            }
        }
    }
}

void RGE_Static_Object::capture_frame(TDrawArea* param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C2220
    if (SDI_Capture_Info != 0) {
        if (rge_base_game->game_mode == 1) {
            this->capture_frame_3d_cube(param_1, param_2, param_3);
            return;
        }
        switch (rge_base_game->outline_type) {
        case 0:
            this->capture_square_frame(param_1, param_2, param_3);
            return;
        case 1:
            this->capture_frame_3d_cube(param_1, param_2, param_3);
            return;
        case 2:
        case 3:
            this->capture_frame_3d_square(param_1, param_2, param_3);
            return;
        }
    }
}

void RGE_Static_Object::capture_square_frame(TDrawArea* /*param_1*/, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C22C0
    if ((this->sprite != nullptr) && (this->sprite_list != nullptr)) {
        this->sprite_list->get_facetindex(this->sprite, this->facet);
        short min_x = 0;
        short min_y = 0;
        short max_x = 0;
        short max_y = 0;
        if (this->get_frame(&min_x, &min_y, &max_x, &max_y) != 0) {
            int x1 = (int)min_x + (int)param_2 + -1 + (int)this->screen_x_offset;
            int y1 = (int)min_y + (int)param_3 + -1 + (int)this->screen_y_offset;
            int x2 = (int)max_x + (int)param_2 + 1 + (int)this->screen_x_offset;
            int y2 = (int)max_y + (int)param_3 + 1 + (int)this->screen_y_offset;
            SDI_List->AddGDINode(4, y2, x1, y1, x2, y2, 0, 0, 0, 0, 10, 0xff, (int)SDI_Object_ID);

            if (this->object_state < 3) {
                int hp_int = (int)this->hp;
                if (hp_int < 1) {
                    hp_int = 0;
                }
                int tot_hp = (int)this->master_obj->hp;
                if (tot_hp > 0) {
                    int filled_right = (hp_int * 0x19) / tot_hp + x1;
                    if (x1 + 0x1a <= filled_right) {
                        filled_right = x1 + 0x19;
                    }
                    SDI_List->AddGDINode(2, y2, x1, y1 + -6, x1 + 0x1a, y1 + -1, filled_right, 0, filled_right + 1, 0, 0x14, 0xff, (int)SDI_Object_ID);
                }
            }
        }
    }
}

void RGE_Static_Object::capture_frame_3d_cube(TDrawArea* /*param_1*/, short /*param_2*/, short /*param_3*/) {
    // Fully verified. Source of truth: stat_obj.cpp.asm @ 0x004C23F0
}

void RGE_Static_Object::capture_frame_3d_square(TDrawArea* /*param_1*/, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C2400
    RGE_Master_Static_Object* master = this->master_obj;
    RGE_Map* map = this->owner->world->map;

    float rx = 0.0f;
    float ry = 0.0f;
    float rz = 0.0f;
    if (rge_base_game->outline_type == 3) {
        rx = master->radius_x;
        ry = master->radius_y;
        rz = master->radius_z;
    } else {
        rx = master->outline_radius_x;
        ry = master->outline_radius_y;
        rz = master->outline_radius_z;
    }

    uchar draw_color = 0xff;
    if (((startLoggingAI == 1) && (this->groupCommanderValue == this->id)) && (this->id >= 0)) {
        draw_color = 0;
    } else if ((this->selected & 1) == 0) {
        if (rge_base_game->outline_type == 3) {
            draw_color = 0x74;
        } else if (((master->draw_flag & 1) == 1) && (rge_base_game->prog_mode == 7)) {
            draw_color = master->draw_color;
        }
    }
    if ((this->selected & 2) != 0) {
        draw_color = 0x4a;
    }
    if ((this->selected & 4) != 0) {
        draw_color = 0x97;
    }

    float neg_ry = -ry;
    short screen_x = (short)(param_2 + this->screen_x_offset);
    short screen_y = (short)(param_3 + this->screen_y_offset);

    short x0 = 0, y0 = 0;
    short x1 = 0, y1 = 0;
    short x2 = 0, y2 = 0;
    short x3 = 0, y3 = 0;
    map->get_point(&x0, &y0, rx, neg_ry, 0.0f, screen_x, screen_y);
    map->get_point(&x1, &y1, rx, ry, 0.0f, screen_x, screen_y);
    map->get_point(&x2, &y2, -rx, ry, 0.0f, screen_x, screen_y);
    map->get_point(&x3, &y3, -rx, neg_ry, 0.0f, screen_x, screen_y);

    int draw_line = (int)screen_y;
    SDI_List->AddGDINode(1, draw_line, (int)x0, (int)y0, (int)x1, (int)y1, (int)x2, (int)y2, (int)x3, (int)y3, 10, (int)draw_color, (int)SDI_Object_ID);

    if ((this->selected != 0) && (this->selected_group != 0) && (this->selected_group < 10) &&
        (this->owner->id == this->owner->world->curr_player)) {
        TShape* group_num_shape = rge_base_game->get_shape(0);
        if (group_num_shape != nullptr) {
            SDI_List->AddDrawNode(group_num_shape->FShape, &group_num_shape->shape_info[this->selected_group], draw_line,
                                  (int)x3 + -6, (int)y3 + -8, 0, nullptr, 0, 0x1e, (int)SDI_Object_ID);
        }
    }

    if (((this->selected & 1) == 1) && ((master->draw_flag & 2) == 0)) {
        int hp_int = (int)this->hp;
        if (hp_int > 0) {
            short hp_x = 0;
            short hp_y = 0;
            map->get_point(&hp_x, &hp_y, rx, neg_ry, rz, screen_x, screen_y);
            if (hp_int < 1) {
                hp_int = 0;
            }
            int tot_hp = (int)master->hp;
            if (tot_hp > 0) {
                int left = (int)hp_x + -0xc;
                int top = (int)hp_y + -2;
                int right = (int)hp_x + 0xb;
                int bottom = (int)hp_y + -1;

                int x_fill = 0;
                int y_fill = 0;
                int x_fill2 = 0;
                int y_fill2 = 0;
                if (hp_int == tot_hp) {
                    y_fill = 1;
                    x_fill = right;
                    x_fill2 = -1;
                    y_fill2 = 0;
                } else if (hp_int == 0) {
                    x_fill = -1;
                    y_fill = 0;
                    x_fill2 = left;
                    y_fill2 = 1;
                } else {
                    y_fill = 1;
                    x_fill = ((hp_int * 0x18) / tot_hp) + left;
                    if (right <= x_fill) {
                        x_fill = (int)hp_x + 10;
                    }
                    x_fill2 = x_fill + 1;
                    y_fill2 = 1;
                }

                SDI_List->AddGDINode(2, draw_line, left, top, right, bottom, x_fill, y_fill, x_fill2, y_fill2, 0x1e, (int)draw_color, (int)SDI_Object_ID);
            }
        }
    }

    if (rge_base_game->display_selected_ids != 0) {
        TShape* digit_shape = rge_base_game->get_shape(0);
        int raw_id = (int)this->id;
        int abs_id = raw_id < 0 ? -raw_id : raw_id;

        int digits[6];
        digits[1] = abs_id / 10000;
        digits[2] = (abs_id % 10000) / 1000;
        int t = (abs_id % 10000) % 1000;
        digits[3] = t / 100;
        t = t % 100;
        digits[4] = t / 10;
        digits[5] = t % 10;

        uint start_index = (uint)(raw_id < 10000);
        if (raw_id < 1000) start_index = 2;
        if (raw_id < 100) start_index = 3;
        if (raw_id < 10) start_index = 4;

        int cur_x = (int)x1;
        int base_y = (int)y1;
        if (raw_id < 0) {
            cur_x += 7;
            SDI_List->AddGDINode(4, draw_line, cur_x + 1, base_y + 3, cur_x + 5, base_y + 3, 0, 0, 0, 0, 0x1e, 0x97, (int)SDI_Object_ID);
        }

        if (start_index < 5) {
            int* p_digit = &digits[(int)start_index + 1];
            int remaining = (int)(5 - start_index);
            while (remaining != 0) {
                cur_x += 7;
                short sx = (short)cur_x;
                if (*p_digit == 0) {
                    SDI_List->AddGDINode(4, draw_line, (int)sx + 1, base_y, (int)sx + 5, base_y + 5, 0, 0, 0, 0, 0x1e, 0xff, (int)SDI_Object_ID);
                } else if (digit_shape != nullptr) {
                    SDI_List->AddDrawNode(digit_shape->FShape, &digit_shape->shape_info[*p_digit], draw_line, (int)sx, base_y, 0, nullptr, 0, 0x1e, (int)SDI_Object_ID);
                }
                ++p_digit;
                remaining = remaining + -1;
            }
        }
    }
}

void RGE_Static_Object::draw_frame_3d_square_back(TDrawArea* param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C2970
    RGE_Map* map = this->owner->world->map;
    float rx = this->master_obj->outline_radius_x;
    float ry = this->master_obj->outline_radius_y;

    TPanel* view_panel = rge_base_game->get_view_panel();
    if (view_panel != nullptr) {
        param_1->Unlock((char*)"stat_obj::draw_frame_3d_square_back");
        if (param_1->GetDc((char*)"stat_obj::draw_frame_3d_square_back") != nullptr) {
            SelectClipRgn((HDC)param_1->DrawDc, (HRGN)view_panel->clip_rgn);

            HGDIOBJ pen = GetStockObject(6);
            if (((startLoggingAI == 1) && (this->groupCommanderValue == this->id)) && (-1 < this->id)) {
                pen = GetStockObject(7);
            }
            SelectObject((HDC)param_1->DrawDc, pen);

            float neg_ry = -ry;
            short screen_x = (short)(param_2 + this->screen_x_offset);
            short screen_y = (short)(param_3 + this->screen_y_offset);
            short x2 = 0, y2 = 0;
            short x1 = 0, y1 = 0;

            map->get_point(&x2, &y2, rx, neg_ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, rx, ry, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, neg_ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx, neg_ry, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            SelectClipRgn((HDC)param_1->DrawDc, nullptr);
            param_1->ReleaseDc((char*)"stat_obj::draw_frame_3d_square_back");
        }
        param_1->Lock((char*)"stat_obj::draw_frame_3d_square_back", 1);
    }
}

void RGE_Static_Object::draw_frame_3d_square_front(TDrawArea* param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C2B50
    RGE_Map* map = this->owner->world->map;
    float rx = this->master_obj->outline_radius_x;
    float ry = this->master_obj->outline_radius_y;
    float rz = this->master_obj->radius_z;

    TPanel* view_panel = rge_base_game->get_view_panel();
    if (view_panel != nullptr) {
        param_1->Unlock((char*)"stat_obj::draw_frame_3d_square_front");

        short screen_x = (short)(param_2 + this->screen_x_offset);
        short screen_y = (short)(param_3 + this->screen_y_offset);

        if (param_1->GetDc((char*)"stat_obj::draw_frame_3d_square_front") != nullptr) {
            SelectClipRgn((HDC)param_1->DrawDc, (HRGN)view_panel->clip_rgn);

            HGDIOBJ pen = GetStockObject(6);
            if (((startLoggingAI == 1) && (this->groupCommanderValue == this->id)) && (-1 < this->id)) {
                pen = GetStockObject(7);
            }
            SelectObject((HDC)param_1->DrawDc, pen);

            float neg_rx = -rx;
            float neg_ry = -ry;
            short x2 = 0, y2 = 0;
            short x1 = 0, y1 = 0;

            map->get_point(&x2, &y2, neg_rx, neg_ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, neg_rx, ry, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, neg_rx, ry, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            SelectClipRgn((HDC)param_1->DrawDc, nullptr);
            param_1->ReleaseDc((char*)"stat_obj::draw_frame_3d_square_front");
        }

        param_1->Lock((char*)"stat_obj::draw_frame_3d_square_front", 1);

        int hp_int = (int)this->hp;
        if (hp_int > 0) {
            short hp_x = 0;
            short hp_y = 0;
            map->get_point(&hp_x, &hp_y, rx, -ry, rz, screen_x, screen_y);
            if (hp_int < 1) {
                hp_int = 0;
            }
            int tot_hp = (int)this->master_obj->hp;
            if (tot_hp > 0) {
                param_1->FillRect((long)hp_x + -0xc, (long)hp_y + -2, (long)hp_x + 0xc, (long)hp_y + -1, 0x97);
                param_1->FillRect((long)hp_x + -0xc, (long)hp_y + -2,
                                  (long)hp_x + -0xc + (hp_int * 0x18) / tot_hp, (long)hp_y + -1, 0x4a);
            }
        }
    }
}

void RGE_Static_Object::draw_frame_3d_cube_back(TDrawArea* param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C2DF0
    RGE_Master_Static_Object* master = this->master_obj;
    RGE_Map* map = this->owner->world->map;

    float rx_small = master->outline_radius_x * 0.25f;
    float ry_small = master->outline_radius_y * 0.25f;
    float rz_small = master->outline_radius_z * 0.25f;
    float rz_large = master->outline_radius_z * 0.75f;
    float rx = master->outline_radius_x;
    float ry = master->outline_radius_y;
    float rz = master->outline_radius_z;

    TPanel* view_panel = rge_base_game->get_view_panel();
    if (view_panel != nullptr) {
        param_1->Unlock(nullptr);
        if (param_1->GetDc(nullptr) != nullptr) {
            SelectClipRgn((HDC)param_1->DrawDc, (HRGN)view_panel->clip_rgn);

            HGDIOBJ pen = GetStockObject(6);
            if (((startLoggingAI == 1) && (this->groupCommanderValue == this->id)) && (-1 < this->id)) {
                pen = GetStockObject(7);
            }
            SelectObject((HDC)param_1->DrawDc, pen);

            float neg_ry = -ry;
            short screen_x = (short)(param_2 + this->screen_x_offset);
            short screen_y = (short)(param_3 + this->screen_y_offset);
            short x2 = 0, y2 = 0;
            short x1 = 0, y1 = 0;

            map->get_point(&x2, &y2, rx, neg_ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, rx, neg_ry, rz_small, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, neg_ry, rz_large, screen_x, screen_y);
            map->get_point(&x1, &y1, rx, neg_ry, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, neg_ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, rx_small, neg_ry, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, neg_ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx_small, neg_ry, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, neg_ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, rx, -ry_small, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, rx, ry_small, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            SelectClipRgn((HDC)param_1->DrawDc, nullptr);
            param_1->ReleaseDc(nullptr);
        }
        param_1->Lock(nullptr, 1);
    }
}

void RGE_Static_Object::draw_frame_3d_cube_front(TDrawArea* param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C31E0
    RGE_Master_Static_Object* master = this->master_obj;
    RGE_Map* map = this->owner->world->map;

    float rx_small = master->outline_radius_x * 0.25f;
    float ry_small = master->outline_radius_y * 0.25f;
    float rz_small = master->outline_radius_z * 0.25f;
    float rz_large = master->outline_radius_z * 0.75f;
    float rx = master->outline_radius_x;
    float ry = master->outline_radius_y;
    float rz = master->outline_radius_z;

    TPanel* view_panel = rge_base_game->get_view_panel();
    if (view_panel != nullptr) {
        param_1->Unlock(nullptr);
        if (param_1->GetDc(nullptr) != nullptr) {
            SelectClipRgn((HDC)param_1->DrawDc, (HRGN)view_panel->clip_rgn);

            HGDIOBJ pen = GetStockObject(6);
            if (((startLoggingAI == 1) && (this->groupCommanderValue == this->id)) && (-1 < this->id)) {
                pen = GetStockObject(7);
            }
            SelectObject((HDC)param_1->DrawDc, pen);

            float neg_ry = -ry;
            short screen_x = (short)(param_2 + this->screen_x_offset);
            short screen_y = (short)(param_3 + this->screen_y_offset + -0x10);
            short x2 = 0, y2 = 0;
            short x1 = 0, y1 = 0;

            map->get_point(&x2, &y2, rx, neg_ry, rz, screen_x, screen_y);
            map->get_point(&x1, &y1, rx_small, neg_ry, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, neg_ry, rz, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx_small, neg_ry, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, ry, rz, screen_x, screen_y);
            map->get_point(&x1, &y1, rx_small, ry, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, ry, rz, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx_small, ry, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, ry, rz, screen_x, screen_y);
            map->get_point(&x1, &y1, rx, ry_small, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, neg_ry, rz, screen_x, screen_y);
            map->get_point(&x1, &y1, rx, -ry_small, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, ry, rz, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx, ry_small, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, neg_ry, rz, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx, -ry_small, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, neg_ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx, -ry_small, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx, ry_small, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, rx_small, ry, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx_small, ry, 0.0f, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx, ry, rz_small, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, ry, rz_large, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx, ry, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, neg_ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx, neg_ry, rz_small, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, -rx, neg_ry, rz_large, screen_x, screen_y);
            map->get_point(&x1, &y1, -rx, neg_ry, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, ry, 0.0f, screen_x, screen_y);
            map->get_point(&x1, &y1, rx, ry, rz_small, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            map->get_point(&x2, &y2, rx, ry, rz_large, screen_x, screen_y);
            map->get_point(&x1, &y1, rx, ry, rz, screen_x, screen_y);
            MoveToEx((HDC)param_1->DrawDc, (int)x2, (int)y2, nullptr);
            LineTo((HDC)param_1->DrawDc, (int)x1, (int)y1);

            SelectClipRgn((HDC)param_1->DrawDc, nullptr);
            param_1->ReleaseDc(nullptr);
        }
        param_1->Lock(nullptr, 1);
    }
}

int RGE_Static_Object::get_frame(short* x1, short* y1, short* x2, short* y2) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5880
    if ((this->sprite != nullptr) && (this->sprite_list != nullptr)) {
        uchar ok = this->sprite_list->get_frame(x1, y1, x2, y2, this->sprite, (long)(uint)this->facet);
        return (int)(uint)ok;
    }
    return 0;
}
uchar RGE_Static_Object::update() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C3C70

    // goto_sleep_flag: transfer object between awake/sleep lists
    if (this->goto_sleep_flag != 0) {
        this->goto_sleep_flag = 0;
        this->owner->removeObject(this, 0, (int)this->dopple_flag, this->player_object_node);
        RGE_Object_Node* node = this->owner->addObject(this, 1, (int)this->dopple_flag);
        this->player_object_node = node;
        return 0;
    }

    // Group member cleanup: remove dead/invalid members
    int numMembers = this->groupMembers.numberValue;
    if (numMembers > 0) {
        int i = 0;
        while (i < this->groupMembers.numberValue) {
            // Grow array if needed
            if (this->groupMembers.maximumSizeValue - 1 < i) {
                int* newArr = (int*)operator new((i + 1) * sizeof(int));
                if (newArr != nullptr) {
                    int j = 0;
                    if (this->groupMembers.maximumSizeValue > 0) {
                        while (j < this->groupMembers.maximumSizeValue) {
                            if (i + 1 <= j)
                                break;
                            newArr[j] = this->groupMembers.value[j];
                            j++;
                        }
                    }
                    operator delete(this->groupMembers.value);
                    this->groupMembers.value = newArr;
                    this->groupMembers.maximumSizeValue = i + 1;
                }
            }

            int memberId = this->groupMembers.value[i];
            RGE_Static_Object* memberObj = this->owner->world->object(memberId);

            if (memberObj == nullptr || memberObj->object_state > 2) {
                // Find the member in the array
                int maxSize = this->groupMembers.maximumSizeValue;
                int idx = 0;
                if (maxSize > 0) {
                    int* arr = this->groupMembers.value;
                    while (idx < maxSize) {
                        if (*arr == memberId)
                            break;
                        idx++;
                        arr++;
                    }
                }
                // Compact the array by shifting elements left
                if (idx < maxSize) {
                    if (idx < maxSize - 1) {
                        int k = idx;
                        do {
                            int* arr = this->groupMembers.value;
                            int kNext = k + 1;
                            arr[k] = arr[kNext];
                            k = kNext;
                        } while (k < this->groupMembers.maximumSizeValue - 1);
                    }
                    int newNum = this->groupMembers.numberValue - 1;
                    this->groupMembers.numberValue = newNum;
                    if (newNum < 0) {
                        this->groupMembers.numberValue = 0;
                    }
                }
                i--;
            }
            i++;
        }
    }

    // Inside-object state propagation
    RGE_Static_Object* insideObj = this->inside_obj;
    if (insideObj != nullptr) {
        if (insideObj->object_state > 2) {
            this->set_object_state(insideObj->object_state);
        }
        return 0;
    }

    // State machine
    switch (this->object_state) {
    case 2:
        this->check_damage_sprites();
        // fall through
    case 0:
        if (this->hp < 1.0f) {
            this->set_object_state(3);
            this->new_sprite(this->master_obj->death_sprite);

            unsigned int r_num = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x704);
            int saved_random_on = debug_random_on;
            debug_random_on = 0;

            RGE_Sound* dsound = this->master_obj->death_sound;
            if (dsound != nullptr && this->owner->id == this->owner->world->curr_player) {
                dsound->play(1);
            }

            debug_random_on = saved_random_on;
            debug_srand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x70e, r_num);
            return 0;
        }
        break;

    case 3:
    case 5:
        CUSTOM_DEBUG_LOG_FMT(
            "RGE_Static_Object::update decay this=%p id=%ld state=%d owner=%p world=%p master=%p attr_type=%d attr_amt=%.3f",
            this,
            this->id,
            (int)this->object_state,
            this->owner,
            (this->owner ? this->owner->world : nullptr),
            this->master_obj,
            (int)this->attribute_type_held,
            this->attribute_amount_held);
        if (this->attribute_type_held == -1 || this->attribute_amount_held <= 0.0f) {
            CUSTOM_DEBUG_LOG("RGE_Static_Object::update decay branch: no held resource path");
            if (this->master_obj->undead_flag != 0) {
                CUSTOM_DEBUG_LOG("RGE_Static_Object::update decay branch: undead transition");
                this->set_object_state(6);
                this->new_sprite(this->master_obj->undead_sprite);
                return 0;
            }
            CUSTOM_DEBUG_LOG("RGE_Static_Object::update decay branch: final death transition");
            this->set_object_state(7);
            CUSTOM_DEBUG_LOG("RGE_Static_Object::update decay branch: state set to 7");
            this->spawn_death_obj();
            CUSTOM_DEBUG_LOG("RGE_Static_Object::update decay branch: spawn_death_obj returned");
            return 0;
        }
        if (this->master_obj->attribute_rot > 0.0f) {
            CUSTOM_DEBUG_LOG_FMT("RGE_Static_Object::update decay branch: attribute rot=%.3f", this->master_obj->attribute_rot);
            float newAmount = this->attribute_amount_held -
                this->owner->world->world_time_delta_seconds * this->master_obj->attribute_rot;
            this->attribute_amount_held = newAmount;
            if (newAmount < 0.0f) {
                this->attribute_amount_held = 0.0f;
                CUSTOM_DEBUG_LOG("RGE_Static_Object::update decay branch: clamped attribute to zero");
                return 0;
            }
        }
        break;

    case 7:
        this->set_object_state(8);
        return 0;

    case 8:
        return (this->master_obj->recyclable != 0) + 1;
    }

    return 0;
}
void RGE_Static_Object::check_damage_sprites() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C3F90
    RGE_Master_Static_Object* master = this->master_obj;
    long current_damage_loc = -1;
    long previous_damage_loc = -1;

    if (master->hp < 1) {
        return;
    }

    uchar damage_sprite_num = master->damage_sprite_num;
    if (damage_sprite_num == 0) {
        return;
    }

    int master_hp = (int)master->hp;
    uchar new_damage_percent = (uchar)(100 - (int)((this->hp * 100.0f) / (float)master_hp));
    if (new_damage_percent == this->curr_damage_percent) {
        return;
    }

    if (new_damage_percent < 100 && damage_sprite_num != 0) {
        RGE_Damage_Sprite_Info* info = master->damage_sprites;
        for (int i = 0; i < (int)damage_sprite_num; ++i) {
            if (info->damage_percent < new_damage_percent) {
                current_damage_loc = i;
            }
            if (info->damage_percent < this->curr_damage_percent) {
                previous_damage_loc = i;
            }
            ++info;
        }
    }

    if (current_damage_loc != previous_damage_loc) {
        if (current_damage_loc > -1) {
            RGE_Damage_Sprite_Info* info = &master->damage_sprites[current_damage_loc];
            uchar flag = info->flag;

            if (flag == 0) {
                this->sprite_list->add_sprite(info->sprite, 0x5A, 0, 0);
            } else if (flag == 1) {
                static const float kRandScale = 6.1037019e-05f;

                int rand_x_int = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x774);
                float rand_x = (float)rand_x_int * master->radius_x * kRandScale - master->radius_x;
                rand_x = rand_x + (this->world_x - (float)(int)this->world_x);

                int rand_y_int = debug_rand("C:\\msdev\\work\\age1_x1\\stat_obj.cpp", 0x775);
                float rand_y = (float)rand_y_int * master->radius_y * kRandScale - master->radius_y;
                rand_y = rand_y + (this->world_y - (float)(int)this->world_y);

                short x = 0;
                short y = 0;
                this->owner->world->map->get_point(&x, &y, rand_x, rand_y, this->world_z, 0, 0);
                this->sprite_list->add_sprite(info->sprite, 0x5A, (long)x, (long)y);
            } else if (flag == 2) {
                this->new_sprite(info->sprite);
            }
        }

        if (previous_damage_loc > -1) {
            RGE_Damage_Sprite_Info* info = &master->damage_sprites[previous_damage_loc];
            uchar flag = info->flag;

            if (flag <= 1) {
                this->sprite_list->remove_sprite(info->sprite);
            } else if (flag == 2) {
                if (!(current_damage_loc >= 0 && master->damage_sprites[current_damage_loc].flag == 2)) {
                    this->new_sprite(master->sprite);
                }
            }
        }
    }

    this->curr_damage_percent = new_damage_percent;
}
void RGE_Static_Object::rehook() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4210
    this->teleport(this->world_x, this->world_y, this->world_z);
    RGE_Static_Object* pObj = this->inside_obj;
    if (pObj != nullptr) {
        this->inside_obj = nullptr;
        pObj = this->get_object_pointer((long)pObj);
        if (pObj != nullptr) {
            this->enter_obj(pObj);
        }
    }
}
void RGE_Static_Object::save(int param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4360
    int fd = param_1;
    rge_write(fd, &this->type, 1);
    rge_write(fd, &this->owner->id, 1);
    rge_write(fd, &this->master_obj->id, 2);

    long long_val;
    if (this->sprite == nullptr) {
        long_val = -1;
    } else {
        long_val = (long)this->sprite->id;
    }
    rge_write(fd, &long_val, 2);

    long inside_id;
    if (this->inside_obj == nullptr) {
        inside_id = -1;
    } else {
        inside_id = this->inside_obj->id;
    }
    rge_write(fd, &inside_id, 4);

    rge_write(fd, &this->hp, 4);
    rge_write(fd, &this->object_state, 1);
    rge_write(fd, &this->sleep_flag, 1);
    rge_write(fd, &this->dopple_flag, 1);
    rge_write(fd, &this->goto_sleep_flag, 1);
    rge_write(fd, &this->id, 4);
    rge_write(fd, &this->facet, 1);
    rge_write(fd, &this->world_x, 4);
    rge_write(fd, &this->world_y, 4);
    rge_write(fd, &this->world_z, 4);
    rge_write(fd, &this->screen_x_offset, 2);
    rge_write(fd, &this->screen_y_offset, 2);
    rge_write(fd, &this->shadow_x_offset, 2);
    rge_write(fd, &this->shadow_y_offset, 2);
    rge_write(fd, &this->selected_group, 1);
    rge_write(fd, &this->attribute_type_held, 2);
    rge_write(fd, &this->attribute_amount_held, 4);
    rge_write(fd, &this->worker_num, 1);
    rge_write(fd, &this->curr_damage_percent, 1);
    rge_write(fd, &this->underAttackValue, 1);
    rge_write(fd, &this->groupCommanderValue, 4);
    rge_write(fd, &this->groupRangeValue, 4);

    // Write groupMembers array
    int count = this->groupMembers.numberValue;
    rge_write(fd, &count, 4);
    for (int i = 0; i < this->groupMembers.numberValue; i++) {
        if (this->groupMembers.maximumSizeValue - 1 < i) {
            int* newArr = (int*)::operator new(i * 4 + 4);
            if (newArr != nullptr) {
                int j = 0;
                if (0 < this->groupMembers.maximumSizeValue) {
                    do {
                        if (i + 1 <= j) break;
                        newArr[j] = this->groupMembers.value[j];
                        j++;
                    } while (j < this->groupMembers.maximumSizeValue);
                }
                ::operator delete(this->groupMembers.value);
                this->groupMembers.value = newArr;
                this->groupMembers.maximumSizeValue = i + 1;
            }
        }
        int val = this->groupMembers.value[i];
        rge_write(fd, &val, 4);
    }

    // Write pathingGroupMembers array
    count = this->pathingGroupMembers.numberValue;
    rge_write(fd, &count, 4);
    for (int i = 0; i < this->pathingGroupMembers.numberValue; i++) {
        if (this->pathingGroupMembers.maximumSizeValue - 1 < i) {
            int* newArr = (int*)::operator new(i * 4 + 4);
            if (newArr != nullptr) {
                int j = 0;
                if (0 < this->pathingGroupMembers.maximumSizeValue) {
                    do {
                        if (i + 1 <= j) break;
                        newArr[j] = this->pathingGroupMembers.value[j];
                        j++;
                    } while (j < this->pathingGroupMembers.maximumSizeValue);
                }
                ::operator delete(this->pathingGroupMembers.value);
                this->pathingGroupMembers.value = newArr;
                this->pathingGroupMembers.maximumSizeValue = i + 1;
            }
        }
        int val = this->pathingGroupMembers.value[i];
        rge_write(fd, &val, 4);
    }

    this->sprite_list->save(fd);
}
float RGE_Static_Object::teleport(float param_1, float param_2, float param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4680
    // ASM-verified at stat_obj.cpp.asm @ 0x004C4680
    RGE_Map* map = this->owner->world->map;

    if (this->inside_obj != nullptr) {
        return 0.0f;
    }

    // Remove from obstruction map if object has nonzero radius_z
    if (this->master_obj->radius_z > 0.0f) {
        this->removeFromObstructionMap(2);
    }

    // Clamp param_1 (X) to valid map range [0, map_width - 0.001]
    if (param_1 < 0.0f) {
        param_1 = 0.0f;
    }
    int mapWidth = map->map_width;
    if (param_1 >= (float)mapWidth) {
        param_1 = (float)mapWidth - 0.001f;
    }

    // Clamp param_2 (Y) to valid map range [0, map_height - 0.001]
    if (param_2 < 0.0f) {
        param_2 = 0.0f;
    }
    int mapHeight = map->map_height;
    if (param_2 >= (float)mapHeight) {
        param_2 = (float)mapHeight - 0.001f;
    }

    // Compute tile indices
    int tx = (int)param_1;
    int ty = (int)param_2;

    // Compute fractional positions within tile
    float fracX = param_1 - (float)tx;
    float fracY = param_2 - (float)ty;

    // Clamp tile indices to valid range
    if (tx >= mapWidth) {
        tx = mapWidth - 1;
    } else if (tx < 0) {
        tx = 0;
    }
    if (ty >= mapHeight) {
        ty = mapHeight - 1;
    } else if (ty < 0) {
        ty = 0;
    }

    // Look up the destination tile
    RGE_Tile* newTile = &map->map_row_offset[ty][tx];
    RGE_Tile* oldTile = this->tile;

    if (newTile == oldTile || this->inside_obj != nullptr) {
        // Same tile (or inside something): just update coordinates
        this->world_x = param_1;
        this->world_y = param_2;
        this->world_z = param_3;
    } else {
        // Different tile: transfer between tile object lists
        if (oldTile != nullptr) {
            oldTile->objects.remove_node(this, nullptr);
        }
        newTile->objects.add_node(this);

        // Unexplore old tile's visibility
        if (this->tile != nullptr) {
            this->unexplore_terrain(this->owner, 0, -1);
        }

        // Update coordinates and tile pointer
        this->world_z = param_3;
        this->world_x = param_1;
        this->world_y = param_2;
        this->tile = newTile;

        // Explore new tile's visibility if object is active
        if (this->object_state == 2) {
            this->explore_terrain(this->owner, 0, -1);
        }
    }

    // Re-add to obstruction map if object has nonzero radius_z
    if (this->master_obj->radius_z > 0.0f) {
        this->addToObstructionMap(2);
    }

    // --- Tile type switch: compute height contribution from slope ---
    float slope_result = 0.0f;
    float slope_flag = 0.0f; // Offset flag for screen Y computation (0.0 or 1.0)

    switch (newTile->tile_type) {
    case 0: // flat
        slope_result = 0.0f;
        break;
    case 1:
        if (fracY + fracX < 1.0f) {
            slope_result = fracY;
        } else {
            slope_result = 1.0f - fracX;
        }
        break;
    case 2:
        if (fracY + fracX < 1.0f) {
            slope_result = fracX;
            slope_flag = 1.0f;
        } else {
            slope_result = 1.0f - fracY;
            slope_flag = 1.0f;
        }
        break;
    case 3:
        if (fracX <= fracY) {
            slope_result = 1.0f - fracY;
        } else {
            slope_result = 1.0f - fracX;
        }
        break;
    case 4:
        if (fracX <= fracY) {
            slope_result = fracX;
        } else {
            slope_result = fracY;
        }
        break;
    case 5:
        slope_result = 1.0f - fracX;
        break;
    case 6:
        slope_result = 1.0f - fracY;
        slope_flag = 1.0f;
        break;
    case 7:
        slope_result = fracY;
        break;
    case 8:
        slope_result = fracX;
        slope_flag = 1.0f;
        break;
    case 9:
        if (fracX - fracY < 0.0f) {
            slope_result = -(fracX - fracY);
        } else {
            slope_result = 0.0f;
        }
        break;
    case 10:
        slope_result = fracX - fracY;
        if (slope_result <= 0.0f) {
            slope_result = 0.0f;
        }
        slope_flag = 1.0f;
        break;
    case 11:
        if (fracY + fracX < 1.0f) {
            slope_result = 1.0f - (fracY + fracX);
        } else {
            slope_result = 0.0f;
        }
        break;
    case 12:
        if (fracY + fracX > 1.0f) {
            slope_result = (fracY + fracX) - 1.0f;
        } else {
            slope_result = 0.0f;
        }
        break;
    case 13:
        if (fracY + fracX >= 1.0f) {
            slope_result = fracY;
        } else {
            slope_result = 1.0f - fracX;
        }
        break;
    case 14:
        if (fracY + fracX >= 1.0f) {
            slope_result = fracX;
            slope_flag = 1.0f;
        } else {
            slope_result = 1.0f - fracY;
            slope_flag = 1.0f;
        }
        break;
    case 15:
        if (fracX <= fracY) {
            slope_result = fracY;
        } else {
            slope_result = fracX;
        }
        slope_flag = 1.0f;
        break;
    case 16:
        if (fracX <= fracY) {
            slope_result = 1.0f - fracX;
        } else {
            slope_result = 1.0f - fracY;
        }
        slope_flag = 1.0f;
        break;
    default:
        slope_result = 0.0f;
        break;
    }

    // Add tile elevation to slope contribution
    float computed_height = slope_result + (float)(int)newTile->height;

    // Apply height based on movement type
    unsigned char movType = this->master_obj->movement_type;
    if (movType == 0) {
        // Ground unit: always snap to terrain
        this->world_z = computed_height;
    } else if (movType == 1 && computed_height > this->world_z) {
        // Flying unit: only raise, never lower below terrain
        this->world_z = computed_height;
    }

    // Compute screen offsets for isometric rendering
    float frac_sum = fracY + fracX;
    float intermediate_xy = slope_flag + fracY - 0.5f - fracX;

    this->screen_x_offset = (short)(int)(frac_sum * (float)(int)map->tile_half_width);
    this->screen_y_offset = (short)(int)((intermediate_xy - this->world_z) * (float)(int)map->tile_half_height);

    // Shadow offsets based on movement type
    if (movType == 0) {
        // Ground: shadow matches screen position
        this->shadow_x_offset = this->screen_x_offset;
        this->shadow_y_offset = this->screen_y_offset;
    } else if (movType == 1) {
        // Flying: shadow at ground level (uses computed_height not world_z)
        this->shadow_x_offset = (short)(int)(frac_sum * (float)(int)map->tile_half_width);
        this->shadow_y_offset = (short)(int)((intermediate_xy - computed_height) * (float)(int)map->tile_half_height);
    }

    return computed_height;
}
void RGE_Static_Object::new_sprite(RGE_Sprite* param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4BD0
    if (param_1 == nullptr) {
        param_1 = this->master_obj->sprite;
    }
    RGE_Sprite* cur = this->sprite;
    if (cur != param_1 &&
        (cur != this->master_obj->death_sprite || this->master_obj->death_sprite == nullptr)) {
        this->old_sprite = cur;
        this->sprite_list->remove_sprite(cur);
        this->sprite = param_1;
        this->sprite_list->add_sprite(param_1, '<', 0, 0);
        this->facet = 0;
    }
}
void RGE_Static_Object::add_overlay_sprite(RGE_Sprite* param_1, uchar param_2) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4C20
    this->sprite_list->add_sprite(param_1, param_2, 0, 0);
}
void RGE_Static_Object::remove_overlay_sprite(RGE_Sprite* param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4C40
    this->sprite_list->remove_sprite(param_1);
}

void RGE_Static_Object::change_unique_id() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C1CF0
    this->owner->removeObject(this, (int)this->sleep_flag, (int)this->dopple_flag, this->player_object_node);

    long new_id = 0;
    if (this->master_obj->recyclable == 0) {
        new_id = this->owner->world->get_next_object_id();
    } else {
        new_id = this->owner->world->get_next_reusable_object_id();
    }

    this->id = new_id;
    this->player_object_node = this->owner->addObject(this, (int)this->sleep_flag, (int)this->dopple_flag);
}

void RGE_Static_Object::get_starting_attribute() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C1E20
    RGE_Master_Static_Object* master = this->master_obj;
    this->attribute_type_held = -1;
    this->attribute_amount_held = 0.0f;

    for (int i = 0; i < 3; i++) {
        if (master->attribute_flag[i] == 0 && master->attribute_type_held[i] != -1) {
            this->attribute_type_held = master->attribute_type_held[i];
            this->attribute_amount_held = master->attribute_amount_held[i];
        }
    }
}

void RGE_Static_Object::give_attribute_to_owner() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ give_attribute_to_owner
    // Iterates 3 attribute slots in master_obj, calling owner->add_attribute_num
    // for slots with attribute_flag == 1 or 2 and valid attribute type.
    for (int i = 0; i < 3; i++) {
        RGE_Master_Static_Object* master = this->master_obj;
        if (master->attribute_flag[i] != 0 && master->attribute_flag[i] < 3) {
            short attr_type = master->attribute_type_held[i];
            if (attr_type >= 0) {
                this->owner->add_attribute_num(attr_type, master->attribute_amount_held[i], 0);
            }
        }
    }
}

void RGE_Static_Object::take_attribute_from_owner() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ take_attribute_from_owner
    // Iterates 3 attribute slots in master_obj, calling owner->add_attribute_num
    // with negated amount for slots with attribute_flag == 2 and valid type.
    for (int i = 0; i < 3; i++) {
        RGE_Master_Static_Object* master = this->master_obj;
        if (master->attribute_flag[i] == 2) {
            short attr_type = master->attribute_type_held[i];
            if (attr_type >= 0) {
                this->owner->add_attribute_num(attr_type, -master->attribute_amount_held[i], 0);
            }
        }
    }
}

void RGE_Static_Object::change_ownership(RGE_Player* param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4C50
    // ASM-verified at stat_obj.cpp.asm @ 0x004C4C50

    // Check that new player has a matching master object prototype
    if (param_1->master_objects[this->master_obj->id] == nullptr) {
        return;
    }

    // Unselect if selected
    if ((this->selected & 1) != 0) {
        this->owner->unselect_one_object(this);
    }

    // Compute HP ratio before any changes
    float hp_ratio = this->hp / (float)(int)(short)this->master_obj->hp;

    // Take attributes from old owner
    this->take_attribute_from_owner();

    // Remove visibility from old owner's LOS
    if (this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
    }

    // Transfer between player object tracking
    this->owner->removeObject(this, this->sleep_flag, this->dopple_flag, this->player_object_node);
    RGE_Object_Node* newNode = param_1->addObject(this, this->sleep_flag, this->dopple_flag);

    // Get old and new master objects
    RGE_Master_Static_Object* oldMaster = this->master_obj;
    this->player_object_node = newNode;
    RGE_Master_Static_Object* newMaster = param_1->master_objects[oldMaster->id];

    // Sprite remapping: match old master's sprite variant to new master's equivalent
    RGE_Sprite* newSprite;
    RGE_Sprite* curSprite = this->sprite;
    if (curSprite != oldMaster->sprite) {
        if (curSprite == oldMaster->death_sprite) {
            newSprite = newMaster->death_sprite;
        } else if (curSprite == oldMaster->undead_sprite) {
            newSprite = newMaster->undead_sprite;
        } else {
            newSprite = newMaster->sprite;
        }
    } else {
        newSprite = newMaster->sprite;
    }

    // Set the new sprite if non-null
    if (newSprite != nullptr) {
        this->new_sprite(newSprite);
    }

    // Assign new owner and master object
    this->owner = param_1;
    this->master_obj = newMaster;

    // Scale HP proportionally: new_hp = new_max_hp * hp_ratio
    this->hp = (float)(int)(short)newMaster->hp * hp_ratio;

    // Add visibility for new owner's LOS
    if (this->object_state == 2) {
        this->explore_terrain(param_1, 0, -1);
    }

    // Give attributes to new owner
    this->give_attribute_to_owner();

    // Notify of ownership change (command 0x20B)
    this->notify(this->id, this->id, 0x20B, (int)param_1->id, 0, 0);
}
void RGE_Static_Object::modify(float param_1, uchar param_2) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4D80
    if (param_2 == 0) {
        this->hp = (float)(int)(short)(int)param_1;
    } else if (param_2 == 1 && this->tile != nullptr && this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
        this->explore_terrain(this->owner, 0, (int)param_1);
        return;
    }
}
void RGE_Static_Object::modify_delta(float param_1, uchar param_2) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4E00
    if (param_2 == 0) {
        this->hp = (float)(int)(short)(int)param_1;
    } else if (param_2 == 1 && this->tile != nullptr && this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
        this->explore_terrain(this->owner, 0, (int)param_1);
        return;
    }
}
void RGE_Static_Object::modify_percent(float param_1, uchar param_2) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4E90
    if (param_2 == 0) {
        this->hp = (float)(int)(short)(int)param_1;
    } else if (param_2 == 1 && this->tile != nullptr && this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
        this->explore_terrain(this->owner, 0, (int)param_1);
        return;
    }
}
void RGE_Static_Object::transform(RGE_Master_Static_Object* param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4F10
    // ASM-verified HP scaling: hp_ratio = this->hp / (float)(int)(short)old_master->hp
    // then this->hp = (float)(int)(short)new_master->hp * hp_ratio

    // Compute hp ratio BEFORE any changes (ASM: MOVSX + FILD + FDIVR)
    float hp_ratio = this->hp / (float)(int)(short)this->master_obj->hp;

    if (this->tile != nullptr) {
        this->unexplore_terrain(this->owner, 0, -1);  // vtable +0xDC
    }
    this->removeFromObstructionMap(2);
    this->master_obj = param_1;
    if (this->tile != nullptr) {
        this->explore_terrain(this->owner, 0, -1);  // vtable +0xD8
    }
    this->addToObstructionMap(2);
    this->new_sprite(param_1->sprite);  // vtable +0x38
    int new_hp_val = (int)(short)param_1->hp;
    this->object_state = 0;
    this->hp = (float)new_hp_val * hp_ratio;
    this->set_object_state(2);  // vtable +0x5C
}
void RGE_Static_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4FB0
    RGE_Sprite* mapped_sprite = nullptr;

    if (this->tile != nullptr && this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
        int los_value = (int)param_1->los;
        this->explore_terrain(this->owner, 0, los_value);
    }

    float old_master_hp = (float)(int)this->master_obj->hp;
    float old_hp = this->hp;
    this->hp = old_master_hp;

    if (this->object_state == 2) {
        this->check_damage_sprites();
    }

    RGE_Master_Static_Object* old_master = this->master_obj;
    RGE_Sprite* current_sprite = this->sprite;
    if (current_sprite == old_master->sprite) {
        mapped_sprite = param_1->sprite;
    } else if (current_sprite == old_master->death_sprite) {
        mapped_sprite = param_1->death_sprite;
    } else if (current_sprite == old_master->undead_sprite) {
        mapped_sprite = param_1->undead_sprite;
    }

    short new_master_hp_short = param_1->hp;
    this->master_obj = param_1;
    this->hp = (float)(int)new_master_hp_short * (old_hp / old_master_hp);

    if (this->object_state == 2) {
        this->check_damage_sprites();
    }

    this->master_obj = old_master;
    if (mapped_sprite != nullptr) {
        this->new_sprite(mapped_sprite);
    }
}
void RGE_Static_Object::set_object_state(uchar param_1) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C52F0
    // ASM-verified group commander play-status handoff at stat_obj.cpp.asm @ 0x004C55BF.
    if (this->object_state != param_1) {
        if (param_1 == 7 || this->object_state == 3) {
            CUSTOM_DEBUG_LOG_FMT(
                "RGE_Static_Object::set_object_state enter this=%p id=%ld old=%d new=%d sleep=%d tile=%p owner=%p master=%p",
                this,
                this->id,
                (int)this->object_state,
                (int)param_1,
                (int)this->sleep_flag,
                this->tile,
                this->owner,
                this->master_obj);
        }
        if (param_1 > 2 && this->object_state < 3) {
            this->take_attribute_from_owner();
            if (this->master_obj->create_doppleganger_on_death == 2) {
                this->create_doppleganger_when_dying();
            }
        }

        if (this->object_state < 4 && param_1 > 6) {
            CUSTOM_DEBUG_LOG("RGE_Static_Object::set_object_state: remove_visible_resource begin");
            this->remove_visible_resource();
            CUSTOM_DEBUG_LOG("RGE_Static_Object::set_object_state: remove_visible_resource end");
        }

        if (param_1 > 2 && this->object_state == 2 && this->tile != nullptr) {
            this->unexplore_terrain(this->owner, 0, -1);
            if (this->master_obj->los > 0.0f) {
                this->explore_terrain(this->owner, 1, -1);
            }
        }

        if (this->object_state < 7 && param_1 == 7 && this->tile != nullptr && this->master_obj->los > 0.0f) {
            CUSTOM_DEBUG_LOG("RGE_Static_Object::set_object_state: unexplore_terrain begin");
            this->unexplore_terrain(this->owner, 1, -1);
            CUSTOM_DEBUG_LOG("RGE_Static_Object::set_object_state: unexplore_terrain end");
        }

        this->object_state = param_1;
        if (param_1 == 7 || this->object_state == 3) {
            CUSTOM_DEBUG_LOG_FMT("RGE_Static_Object::set_object_state: object_state assigned=%d", (int)this->object_state);
        }

        if (param_1 == 3 && this->groupCommanderValue == this->id &&
            this->unitAIValue != nullptr && this->groupMembers.numberValue > 1) {
            int new_commander = -1;
            int index = 0;
            while (index < this->groupMembers.numberValue) {
                rge_static_ensure_group_capacity(this->groupMembers, index);
                if (this->groupMembers.value[index] != this->id) {
                    rge_static_ensure_group_capacity(this->groupMembers, index);
                    RGE_Static_Object* member = this->owner->world->object(this->groupMembers.value[index]);
                    if (member != nullptr && member->object_state < 3) {
                        UnitAIModule* member_unit_ai = member->unitAIValue;
                        if (member_unit_ai != nullptr) {
                            if (new_commander == -1) {
                                rge_static_ensure_group_capacity(this->groupMembers, index);
                                new_commander = this->groupMembers.value[index];
                            }
                            member->groupCommanderValue = new_commander;

                            rge_static_ensure_group_capacity(this->groupMembers, index);
                            if (this->groupMembers.value[index] == new_commander) {
                                rge_static_set_unit_ai_play_status(member_unit_ai, this->unitAIValue);
                            }
                        }
                    }
                }
                index = index + 1;
            }
        }

        if (this->sleep_flag != 0 && this->object_state != 2 && this->object_state != 6) {
            CUSTOM_DEBUG_LOG("RGE_Static_Object::set_object_state: rge_static_set_sleep_flag begin");
            rge_static_set_sleep_flag(this, 0);
            CUSTOM_DEBUG_LOG("RGE_Static_Object::set_object_state: rge_static_set_sleep_flag end");
        }
    }
}
void RGE_Static_Object::remove_visible_resource() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C50F0
    if (this->id < 0 || this->owner == nullptr || this->master_obj == nullptr) {
        return;
    }

    if (this->owner->world == nullptr || this->owner->world->map == nullptr ||
        this->owner->world->map->unified_vis_map == nullptr ||
        this->owner->world->map->unified_vis_map->UnifiedVisibleMap == nullptr) {
        return;
    }

    if (this->master_obj->create_doppleganger_on_death == 0 && this->master_obj->track_as_resource == 0) {
        return;
    }

    int map_y = (int)this->world_y;
    int map_x = (int)this->world_x;
    RGE_Unified_Visible_Map* unified_vis = this->owner->world->map->unified_vis_map;
    ulong unified_value = unified_vis->UnifiedVisibleMap[map_y * unified_vis->mapWidth + map_x];

    uint explored_bits = (uint)unified_value & 0xFFFF;
    uint visible_bits = (uint)unified_value >> 0x10;

    if (visible_bits != 0) {
        int player_offset = 0;
        do {
            if ((visible_bits & 1) == 1) {
                int player_index = player_offset / 4;
                RGE_Player* player = this->owner->world->players[player_index];
                if (player == nullptr) {
                    player_offset = player_offset + 4;
                    visible_bits = visible_bits >> 1;
                    explored_bits = explored_bits >> 1;
                    continue;
                }

                if (this->master_obj->track_as_resource != 0) {
                    if (player->VR_List != nullptr) {
                        player->VR_List->Remove_Resource(this->id, (int)(uint)this->master_obj->resource_group);
                    }
                }

                if (this->master_obj->create_doppleganger_on_death == 1 &&
                    (explored_bits & 1) == 0 &&
                    player_offset > 0) {
                    RGE_Master_Doppleganger_Object* doppel_master =
                        (RGE_Master_Doppleganger_Object*)player->master_objects[0xF3];
                    doppel_master->make_new_obj(player, this->world_x, this->world_y, this->world_z, this);
                }
            }

            player_offset = player_offset + 4;
            explored_bits = explored_bits >> 1;
            visible_bits = visible_bits >> 1;
        } while (visible_bits != 0);
    }

    if (this->master_obj->create_doppleganger_on_death == 2) {
        if (this->owner->doppleganger_creator != nullptr) {
            this->owner->doppleganger_creator->remove_doppleganger_check(this);
        }
    }
}
void RGE_Static_Object::create_doppleganger_when_dying() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5210
    if (this->id < 0 || this->owner == nullptr || this->master_obj == nullptr) {
        return;
    }

    if (this->master_obj->create_doppleganger_on_death != 2) {
        return;
    }

    if (this->owner->world == nullptr || this->owner->world->map == nullptr ||
        this->owner->world->map->unified_vis_map == nullptr ||
        this->owner->world->map->unified_vis_map->UnifiedVisibleMap == nullptr ||
        this->owner->doppleganger_creator == nullptr) {
        return;
    }

    int map_y = (int)this->world_y;
    int map_x = (int)this->world_x;
    RGE_Unified_Visible_Map* unified_vis = this->owner->world->map->unified_vis_map;
    ulong unified_value = unified_vis->UnifiedVisibleMap[map_y * unified_vis->mapWidth + map_x];

    uint explored_bits = (uint)unified_value & 0xFFFF;
    uint visible_bits = (uint)unified_value >> 0x10;

    if (visible_bits != 0) {
        int player_offset = 0;
        do {
            if ((visible_bits & 1) == 1 && (explored_bits & 1) == 0 && player_offset > 0) {
                int player_index = player_offset / 4;
                RGE_Player* player = this->owner->world->players[player_index];
                if (player != nullptr && player->master_objects != nullptr) {
                    RGE_Master_Doppleganger_Object* doppel_master =
                        (RGE_Master_Doppleganger_Object*)player->master_objects[0xF3];
                    if (doppel_master != nullptr) {
                        doppel_master->make_new_obj(player, this->world_x, this->world_y, this->world_z, this);
                    }
                }
            }

            player_offset = player_offset + 4;
            explored_bits = explored_bits >> 1;
            visible_bits = visible_bits >> 1;
        } while (visible_bits != 0);
    }

    map_y = (int)this->world_y;
    map_x = (int)this->world_x;
    ulong* unified_address = &unified_vis->UnifiedVisibleMap[map_y * unified_vis->mapWidth + map_x];
    this->owner->doppleganger_creator->add_doppleganger_check(this, unified_address);
}
void RGE_Static_Object::destroy_obj() {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C5080
    if (this->object_state < 7) {
        if (this->inside_obj != nullptr) {
            this->exit_obj();
        }
        if ((this->selected & 1) != 0 && this->owner != nullptr) {
            this->owner->unselect_one_object(this);
        }
        rge_static_set_sleep_flag(this, 0);
        this->set_object_state(7);
    }
}
void RGE_Static_Object::die_die_die() {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C50C0
    if ((this->selected & 1) != 0 && this->owner != nullptr) {
        this->owner->unselect_one_object(this);
    }
    rge_static_set_sleep_flag(this, 0);
    this->hp = 0.0f;
}
void RGE_Static_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5B90
    float dmg = this->calculateDamage(param_1, param_2, param_3, param_4, param_5);
    float result = this->hp - dmg;
    this->hp = result;
    if (result < 1.0f) {
        this->hp = 0.0f;
        rge_static_set_sleep_flag(this, 0);
    }
}
float RGE_Static_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* /*param_5*/) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5BE0
    float total = 0.0f;
    if (param_1 > 0) {
        short* ptr = &param_2->value;
        do {
            short val = *ptr;
            ptr = ptr + 2;  // stride of 4 bytes (2 shorts)
            param_1 = param_1 - 1;
            total = (float)(int)val * param_3 + total;
        } while (param_1 != 0);
    }
    return total;
}
void RGE_Static_Object::rotate(long param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5C10
    int facet_count = (int)this->sprite->facet_num;
    int newFacet = param_1 + (int)this->facet;
    while (newFacet < 0) {
        newFacet += facet_count;
    }
    while (newFacet >= facet_count) {
        newFacet -= facet_count;
    }
    this->facet = (uchar)newFacet;
}
uchar RGE_Static_Object::can_attack() { return 0; }
void RGE_Static_Object::set_attribute(short param_1, float param_2) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5C40
    this->attribute_type_held = param_1;
    this->attribute_amount_held = param_2;
}
void RGE_Static_Object::set_attribute_amount(float param_1, uchar param_2, uchar param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5C60
    if (param_2 == 0) {
        this->attribute_amount_held = param_1;
    } else {
        this->attribute_amount_held = param_1 + this->attribute_amount_held;
    }
    if (param_3 != 0) {
        float maxAmount = (float)(int)this->master_obj->attribute_max_amount;
        if (this->attribute_amount_held > maxAmount) {
            this->attribute_amount_held = maxAmount;
        }
    }
}
int RGE_Static_Object::heal(int param_1, int param_2) { return 0; }
uchar RGE_Static_Object::heal(float param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5CB0
    float newHp = param_1 + this->hp;
    this->hp = newHp;
    if (param_1 < 0.0f && newHp < 1.0f) {
        this->hp = 1.0f;
    }
    float maxHp = (float)(int)this->master_obj->hp;
    if (this->hp < maxHp) {
        return 0;
    }
    this->hp = maxHp;
    return 1;
}
int RGE_Static_Object::canRepair() { return 0; }
void RGE_Static_Object::notify_of_relation(long param_1, uchar param_2) {}
void RGE_Static_Object::do_command(RGE_Static_Object* /*param_1*/, float /*param_2*/, float /*param_3*/, float /*param_4*/) {}
void RGE_Static_Object::move_to(RGE_Static_Object* /*param_1*/, float /*param_2*/, float /*param_3*/, float /*param_4*/) {}
void RGE_Static_Object::work(RGE_Static_Object* /*param_1*/, float /*param_2*/, float /*param_3*/, float /*param_4*/) {}
void RGE_Static_Object::stop() {}
void RGE_Static_Object::set_attack(RGE_Static_Object* /*param_1*/) {}
void RGE_Static_Object::play_command_sound() {}
void RGE_Static_Object::play_move_sound() {}
int RGE_Static_Object::unitIsInGroup(int param_1) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C7770
    int count = this->groupMembers.numberValue;
    int index = 0;
    if (count > 0) {
        do {
            if (index >= this->groupMembers.maximumSizeValue) {
                break;
            }
            if (this->groupMembers.value[index] == param_1) {
                return 1;
            }
            index = index + 1;
        } while (index < count);
    }
    return 0;
}

int RGE_Static_Object::createGroup(int* param_1, int param_2, int param_3, float param_4) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C77B0
    if (param_1 == nullptr || param_2 == 0) {
        return 0;
    }

    this->groupMembers.numberValue = 0;
    if (param_2 > 0) {
        do {
            int unit_id = *param_1;
            if (unit_id >= 0) {
                int group_count = this->groupMembers.numberValue;
                int index = 0;
                bool duplicate = false;

                if (group_count > 0) {
                    do {
                        if (index >= this->groupMembers.maximumSizeValue) {
                            break;
                        }
                        if (this->groupMembers.value[index] == unit_id) {
                            duplicate = true;
                            break;
                        }
                        index = index + 1;
                    } while (index < group_count);
                }

                if (!duplicate) {
                    if ((this->groupMembers.maximumSizeValue - 1) < group_count) {
                        int new_capacity = group_count + 1;
                        int* new_values = static_cast<int*>(::operator new((size_t)new_capacity * sizeof(int), std::nothrow));
                        if (new_values != nullptr) {
                            int copy_index = 0;
                            while (copy_index < this->groupMembers.maximumSizeValue) {
                                if (new_capacity <= copy_index) {
                                    break;
                                }
                                new_values[copy_index] = this->groupMembers.value[copy_index];
                                copy_index = copy_index + 1;
                            }

                            ::operator delete(this->groupMembers.value);
                            this->groupMembers.value = new_values;
                            this->groupMembers.maximumSizeValue = new_capacity;
                        }
                    }

                    this->groupMembers.value[this->groupMembers.numberValue] = unit_id;
                    this->groupMembers.numberValue = this->groupMembers.numberValue + 1;
                }
            }

            param_1 = param_1 + 1;
            param_2 = param_2 - 1;
        } while (param_2 != 0);
    }

    this->groupRangeValue = param_4;
    this->groupCommanderValue = param_3;
    return 1;
}

int RGE_Static_Object::commanderCreateGroup(int* param_1, int param_2, int param_3, float param_4) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C78B0
    int* unit_ids = param_1;
    if (param_1 == nullptr || param_2 == 0) {
        return 0;
    }

    if (param_2 > 0) {
        int remaining = param_2;
        int* current = unit_ids;
        do {
            RGE_Static_Object* group_obj = this->owner->world->object(*current);
            if (group_obj != nullptr) {
                group_obj->createGroup(unit_ids, param_2, param_3, param_4);
            }
            current = current + 1;
            remaining = remaining - 1;
        } while (remaining != 0);
    }

    return 1;
}

int RGE_Static_Object::addToGroup(int param_1, float param_2) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C7920
    (void)param_2;
    if (0x18 < this->groupMembers.numberValue) {
        return 0;
    }

    int count = this->groupMembers.numberValue;
    int index = 0;
    if (count > 0) {
        do {
            if (this->groupMembers.maximumSizeValue <= index) {
                break;
            }
            if (this->groupMembers.value[index] == param_1) {
                return 1;
            }
            index = index + 1;
        } while (index < count);
    }

    if ((this->groupMembers.maximumSizeValue - 1) < count) {
        int new_capacity = count + 1;
        int* new_values = static_cast<int*>(::operator new((size_t)new_capacity * sizeof(int), std::nothrow));
        if (new_values != nullptr) {
            int copy_index = 0;
            while (copy_index < this->groupMembers.maximumSizeValue) {
                if (new_capacity <= copy_index) {
                    break;
                }
                new_values[copy_index] = this->groupMembers.value[copy_index];
                copy_index = copy_index + 1;
            }

            ::operator delete(this->groupMembers.value);
            this->groupMembers.value = new_values;
            this->groupMembers.maximumSizeValue = new_capacity;
        }
    }

    this->groupMembers.value[this->groupMembers.numberValue] = param_1;
    this->groupMembers.numberValue = this->groupMembers.numberValue + 1;
    return 1;
}

int RGE_Static_Object::commanderAddToGroup(int param_1, float param_2) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C79D0
    RGE_Static_Object* unit_obj = this->owner->world->object(param_1);
    if (unit_obj == nullptr) {
        return 0;
    }

    int member_count = this->groupMembers.numberValue;
    if (0x18 < member_count) {
        return 0;
    }

    int temp[25];
    int index = 0;
    if (member_count > 0) {
        do {
            if ((this->groupMembers.maximumSizeValue - 1) < index) {
                int new_capacity = index + 1;
                int* new_values = static_cast<int*>(::operator new((size_t)new_capacity * sizeof(int), std::nothrow));
                if (new_values != nullptr) {
                    int copy_index = 0;
                    while (copy_index < this->groupMembers.maximumSizeValue) {
                        if (new_capacity <= copy_index) {
                            break;
                        }
                        new_values[copy_index] = this->groupMembers.value[copy_index];
                        copy_index = copy_index + 1;
                    }

                    ::operator delete(this->groupMembers.value);
                    this->groupMembers.value = new_values;
                    this->groupMembers.maximumSizeValue = new_capacity;
                }
            }

            int group_unit_id = this->groupMembers.value[index];
            temp[index] = group_unit_id;
            if (group_unit_id != this->id) {
                if ((this->groupMembers.maximumSizeValue - 1) < index) {
                    int new_capacity = index + 1;
                    int* new_values = static_cast<int*>(::operator new((size_t)new_capacity * sizeof(int), std::nothrow));
                    if (new_values != nullptr) {
                        int copy_index = 0;
                        while (copy_index < this->groupMembers.maximumSizeValue) {
                            if (new_capacity <= copy_index) {
                                break;
                            }
                            new_values[copy_index] = this->groupMembers.value[copy_index];
                            copy_index = copy_index + 1;
                        }

                        ::operator delete(this->groupMembers.value);
                        this->groupMembers.value = new_values;
                        this->groupMembers.maximumSizeValue = new_capacity;
                    }
                }

                RGE_Static_Object* group_obj = this->owner->world->object(this->groupMembers.value[index]);
                if (group_obj != nullptr) {
                    group_obj->addToGroup(param_1, param_2);
                }
            }

            index = index + 1;
        } while (index < this->groupMembers.numberValue);
    }

    temp[index] = param_1;
    this->addToGroup(param_1, param_2);
    unit_obj->createGroup(temp, index + 1, this->id, param_2);
    return 1;
}

int RGE_Static_Object::removeFromGroup(int param_1) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C7B60
    int max_size = this->groupMembers.maximumSizeValue;
    int index = 0;
    if (max_size > 0) {
        int* values = this->groupMembers.value;
        do {
            if (*values == param_1) {
                break;
            }
            index = index + 1;
            values = values + 1;
        } while (index < max_size);
    }

    int result = 0;
    if (index < max_size) {
        if (index < (max_size - 1)) {
            do {
                int* values = this->groupMembers.value;
                int next_index = index + 1;
                values[index] = values[next_index];
                index = next_index;
            } while (index < (this->groupMembers.maximumSizeValue - 1));
        }

        int new_count = this->groupMembers.numberValue - 1;
        this->groupMembers.numberValue = new_count;
        if (new_count < 0) {
            this->groupMembers.numberValue = 0;
        }
        result = 1;
    }

    if (this->groupMembers.numberValue < 1) {
        this->groupCommanderValue = -1;
    }

    return result;
}

int RGE_Static_Object::commanderRemoveFromGroup(int param_1) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C7BD0
    if ((param_1 == this->id) && (this->id == this->groupCommanderValue)) {
        return this->commanderDestroyGroup();
    }

    int group_index = 0;
    if (this->groupMembers.numberValue > 0) {
        do {
            if ((this->groupMembers.maximumSizeValue - 1) < group_index) {
                int new_capacity = group_index + 1;
                int* new_values = static_cast<int*>(::operator new((size_t)new_capacity * sizeof(int), std::nothrow));
                if (new_values != nullptr) {
                    int copy_index = 0;
                    while (copy_index < this->groupMembers.maximumSizeValue) {
                        if (new_capacity <= copy_index) {
                            break;
                        }
                        new_values[copy_index] = this->groupMembers.value[copy_index];
                        copy_index = copy_index + 1;
                    }

                    ::operator delete(this->groupMembers.value);
                    this->groupMembers.value = new_values;
                    this->groupMembers.maximumSizeValue = new_capacity;
                }
            }

            RGE_Static_Object* member_obj = this->owner->world->object(this->groupMembers.value[group_index]);
            if ((member_obj != nullptr) && (member_obj->id != this->id)) {
                int max_size = member_obj->groupMembers.maximumSizeValue;
                int remove_index = 0;

                if (max_size > 0) {
                    int* member_values = member_obj->groupMembers.value;
                    do {
                        if (*member_values == param_1) {
                            break;
                        }
                        remove_index = remove_index + 1;
                        member_values = member_values + 1;
                    } while (remove_index < max_size);
                }

                if (remove_index < max_size) {
                    if (remove_index < (max_size - 1)) {
                        do {
                            int* member_values = member_obj->groupMembers.value;
                            int next_index = remove_index + 1;
                            member_values[remove_index] = member_values[next_index];
                            remove_index = next_index;
                        } while (remove_index < (member_obj->groupMembers.maximumSizeValue - 1));
                    }

                    int new_count = member_obj->groupMembers.numberValue - 1;
                    member_obj->groupMembers.numberValue = new_count;
                    if (new_count < 0) {
                        member_obj->groupMembers.numberValue = 0;
                    }
                }
            }

            group_index = group_index + 1;
        } while (group_index < this->groupMembers.numberValue);
    }

    this->removeFromGroup(param_1);
    return 1;
}

int RGE_Static_Object::destroyGroup() {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C7CE0
    this->groupMembers.numberValue = 0;
    this->groupCommanderValue = -1;
    return 1;
}

int RGE_Static_Object::commanderDestroyGroup() {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C7D00
    int group_index = 0;
    if (this->groupMembers.numberValue > 0) {
        do {
            if ((this->groupMembers.maximumSizeValue - 1) < group_index) {
                int new_capacity = group_index + 1;
                int* new_values = static_cast<int*>(::operator new((size_t)new_capacity * sizeof(int), std::nothrow));
                if (new_values != nullptr) {
                    int copy_index = 0;
                    while (copy_index < this->groupMembers.maximumSizeValue) {
                        if (new_capacity <= copy_index) {
                            break;
                        }
                        new_values[copy_index] = this->groupMembers.value[copy_index];
                        copy_index = copy_index + 1;
                    }

                    ::operator delete(this->groupMembers.value);
                    this->groupMembers.value = new_values;
                    this->groupMembers.maximumSizeValue = new_capacity;
                }
            }

            RGE_Static_Object* member_obj = this->owner->world->object(this->groupMembers.value[group_index]);
            if ((member_obj != nullptr) && (member_obj->id != this->id)) {
                member_obj->destroyGroup();
            }

            group_index = group_index + 1;
        } while (group_index < this->groupMembers.numberValue);
    }

    this->destroyGroup();
    return 1;
}

void RGE_Static_Object::addToPathingGroup(int param_1) {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C7DB0
    int index = 0;
    int count = this->pathingGroupMembers.numberValue;

    if (count > 0) {
        do {
            if (this->pathingGroupMembers.maximumSizeValue <= index) {
                break;
            }
            if (this->pathingGroupMembers.value[index] == param_1) {
                return;
            }
            index = index + 1;
        } while (index < count);
    }

    if ((this->pathingGroupMembers.maximumSizeValue - 1) < count) {
        int new_capacity = count + 1;
        int* new_values = static_cast<int*>(::operator new((size_t)new_capacity * sizeof(int), std::nothrow));
        if (new_values != nullptr) {
            int copy_index = 0;
            if (this->pathingGroupMembers.maximumSizeValue > 0) {
                do {
                    if (new_capacity <= copy_index) {
                        break;
                    }
                    new_values[copy_index] = this->pathingGroupMembers.value[copy_index];
                    copy_index = copy_index + 1;
                } while (copy_index < this->pathingGroupMembers.maximumSizeValue);
            }

            ::operator delete(this->pathingGroupMembers.value);
            this->pathingGroupMembers.value = new_values;
            this->pathingGroupMembers.maximumSizeValue = new_capacity;
        }
    }

    this->pathingGroupMembers.value[this->pathingGroupMembers.numberValue] = param_1;
    this->pathingGroupMembers.numberValue = this->pathingGroupMembers.numberValue + 1;
}
void RGE_Static_Object::removeAllFromPathingGroup() {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C7E50
    if (this->owner->computerPlayer() == 1) {
        this->pathingGroupMembers.numberValue = 0;
    }
}
void RGE_Static_Object::remove_shadows() {
    // Source of truth: stat_obj.cpp.decomp @ 0x004C7E70
    int world_x_int = (int)this->world_x;
    int world_y_int = (int)this->world_y;
    this->owner->world->map->request_redraw(world_x_int - 2, world_y_int - 2, world_x_int + 1, world_y_int + 1, 0);
}
uchar RGE_Static_Object::more_room() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C58C0
    return this->objects->number_of_objects < (short)(unsigned short)this->master_obj->obj_max;
}
void RGE_Static_Object::new_angle(float param_1) {}
RGE_Static_Object* RGE_Static_Object::spawn_death_obj() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C41D0
    short spawnId = this->master_obj->death_spawn_obj_id;
    if (spawnId >= 0) {
        RGE_Master_Static_Object* spawnMaster = this->owner->master_objects[spawnId];
        if (spawnMaster != nullptr) {
            return spawnMaster->make_new_obj(this->owner, this->world_x, this->world_y, this->world_z);
        }
    }
    return nullptr;
}
RGE_Master_Static_Object* RGE_Static_Object::get_command_master(RGE_Static_Object* /*param_1*/, float /*param_2*/, float /*param_3*/, float /*param_4*/) { return nullptr; }
void RGE_Static_Object::set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5D20
    if (this->worker_num < 0xFA) {
        this->worker_num = this->worker_num + 1;
    }
    rge_static_set_sleep_flag(this, 0);
}
void RGE_Static_Object::release_being_worked_on(RGE_Static_Object* /*param_1*/) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5D40
    if (this->worker_num != 0) {
        this->worker_num = this->worker_num - 1;
    }
    if ((this->worker_num == 0) &&
        ((this->object_state == 2 && 0.0f <= this->hp) || (this->object_state == 6))) {
        rge_static_set_sleep_flag(this, 1);
    }
}
uchar RGE_Static_Object::is_moving() { return 0; }
RGE_Static_Object* RGE_Static_Object::get_target_obj() { return nullptr; }
void RGE_Static_Object::enter_obj(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C58E0
    if (param_1->more_room() != 0) {
        if (this->inside_obj != nullptr) {
            this->inside_obj->exit_obj();
        }
        if (this->tile != nullptr) {
            this->unexplore_terrain(this->owner, 0, -1);
            this->tile->objects.remove_node(this, nullptr);
            this->tile = nullptr;
        }
        this->removeFromObstructionMap(2);
        param_1->objects->add_node(this);
        this->inside_obj = param_1;
        this->world_x = param_1->world_x;
        this->world_y = param_1->world_y;
    }
}
void RGE_Static_Object::exit_obj() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5960
    if (this->inside_obj != nullptr) {
        this->inside_obj->objects->remove_node(this, nullptr);
        this->inside_obj = nullptr;
    }
}
int RGE_Static_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C59B0
    if (param_1 != nullptr) {
        if (param_3 == -1) {
            param_3 = (int)(long)this->master_obj->los;
        }
        if (0 < param_3) {
            RGE_Visible_Map* visible = param_1->visible;
            uint isCurPlayer = (uint)(param_1->id == param_1->world->curr_player);
            if (param_2 == 0) {
                int world_x_int = (int)(long)this->world_x;
                int world_y_int = (int)(long)this->world_y;
                return visible->explore_terrain(world_x_int, world_y_int, param_3, 0, (int)isCurPlayer, (int)this->id);
            }
            if ((0.0f < this->master_obj->radius_x) && (0.0f < this->master_obj->radius_y)) {
                int x1 = (int)(long)(this->world_x - this->master_obj->radius_x);
                int y1 = (int)(long)(this->world_y - this->master_obj->radius_y);
                // ASM: stat_obj.cpp.asm @ 0x004C5A4F subtracts 10.0f before truncating max extents.
                int x2 = (int)(long)(this->world_x + this->master_obj->radius_x - 10.0f);
                int y2 = (int)(long)(this->world_y + this->master_obj->radius_y - 10.0f);
                return visible->explore_terrain_sq(x1, y1, x2, y2, (int)isCurPlayer, (int)this->id);
            }
        }
    }
    return 0;
}

void RGE_Static_Object::unexplore_terrain(RGE_Player* param_1, uchar param_2, int param_3) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C5AA0
    if (param_1 != nullptr) {
        if (param_3 == -1) {
            param_3 = (int)(long)this->master_obj->los;
        }
        if (0 < param_3) {
            RGE_Visible_Map* visible = param_1->visible;
            uint isCurPlayer = (uint)(param_1->id == param_1->world->curr_player);
            if (param_2 == 0) {
                int world_x_int = (int)(long)this->world_x;
                int world_y_int = (int)(long)this->world_y;
                visible->unexplore_terrain(world_x_int, world_y_int, param_3, 0, (int)isCurPlayer, (int)this->id);
                return;
            }
            if ((0.0f < this->master_obj->radius_x) && (0.0f < this->master_obj->radius_y)) {
                int x1 = (int)(long)(this->world_x - this->master_obj->radius_x);
                int y1 = (int)(long)(this->world_y - this->master_obj->radius_y);
                // ASM: stat_obj.cpp.asm @ 0x004C5B3F subtracts 10.0f before truncating max extents.
                int x2 = (int)(long)(this->world_x + this->master_obj->radius_x - 10.0f);
                int y2 = (int)(long)(this->world_y + this->master_obj->radius_y - 10.0f);
                visible->unexplore_terrain_sq(x1, y1, x2, y2, (int)isCurPlayer, (int)this->id);
            }
        }
    }
}

LOSTBL* RGE_Static_Object::get_los_table() {
    // Fully verified. Source of truth: stat_obj.cpp.asm @ 0x004C5980
    RGE_Player* pRVar1 = this->owner;
    if (pRVar1 == nullptr) {
        return nullptr;
    }
    int losValue = (int)(long)this->master_obj->los;
    return pRVar1->visible->get_los_table(losValue, 0);
}
int RGE_Static_Object::inAttackRange(RGE_Static_Object* /*param_1*/) { return 0; }
uchar RGE_Static_Object::underAttack() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C6B60
    return this->underAttackValue;
}
void RGE_Static_Object::setUnderAttack(uchar param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C6B70
    this->underAttackValue = param_1;
}
float RGE_Static_Object::calc_attack_modifier(RGE_Static_Object* /*param_1*/) { return 1.0f; }
float RGE_Static_Object::getSpeed() { return 0.0f; }
float RGE_Static_Object::getAngle() { return 0.0f; }
float RGE_Static_Object::maximumSpeed() { return 0.0f; }
float RGE_Static_Object::rateOfFire() { return 0.0f; }
float RGE_Static_Object::damageCapability(RGE_Static_Object* param_1) { return 0.0f; }
float RGE_Static_Object::damageCapability() { return 0.0f; }
float RGE_Static_Object::weaponRange() { return 0.0f; }
float RGE_Static_Object::minimumWeaponRange() { return 0.0f; }
int RGE_Static_Object::passableTile(float /*param_1*/, float /*param_2*/, int /*param_3*/) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x0041A500
    return 0;
}
uchar RGE_Static_Object::facetToNextWaypoint() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x0041A510
    return 0xFF;
}
int RGE_Static_Object::currentTargetID() { return -1; }
float RGE_Static_Object::currentTargetX() { return -1.0f; }
float RGE_Static_Object::currentTargetY() { return -1.0f; }
float RGE_Static_Object::currentTargetZ() { return -1.0f; }
void RGE_Static_Object::setWaitingToMove(uchar param_1) {}
uchar RGE_Static_Object::waitingToMove() { return 0; }
uchar RGE_Static_Object::actionState() { return 0; }
uchar RGE_Static_Object::keepGatheringWhenObjectIsOut(int param_1) { return 0; }
uchar RGE_Static_Object::produceWhenKilledBy(int param_1) { return 0; }
uchar RGE_Static_Object::useSameZoneDropsite() { return 0; }
void RGE_Static_Object::logDebug(char* param_1) {}
void RGE_Static_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {}
int RGE_Static_Object::attack(float param_1, float param_2, float param_3, int param_4) { return 0; }
int RGE_Static_Object::attack(int param_1, int param_2) { return 0; }
int RGE_Static_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) { return 0; }
int RGE_Static_Object::moveTo(int param_1, float param_2, int param_3) { return 0; }
int RGE_Static_Object::moveTo(int param_1, int param_2) { return 0; }
int RGE_Static_Object::moveAwayFrom(int param_1, int param_2) { return 0; }
int RGE_Static_Object::hunt(int param_1, int param_2) { return 0; }
int RGE_Static_Object::gather(int param_1, int param_2) { return 0; }
int RGE_Static_Object::convert(int param_1, int param_2) { return 0; }
int RGE_Static_Object::repair(int param_1, int param_2) { return 0; }
int RGE_Static_Object::build(int param_1, int param_2) { return 0; }
int RGE_Static_Object::trade(int param_1, int param_2) { return 0; }
int RGE_Static_Object::explore(int param_1, int param_2, int param_3) { return 0; }
int RGE_Static_Object::enter(int param_1, int param_2) { return 0; }
int RGE_Static_Object::unload(int param_1, float param_2, float param_3, float param_4) { return 0; }
int RGE_Static_Object::transport(float param_1, float param_2, float param_3, int param_4) { return 0; }
int RGE_Static_Object::stopAction() { return 0; }
int RGE_Static_Object::pause() { return 0; }
int RGE_Static_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) { return 0; }
int RGE_Static_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) { return 0; }
int RGE_Static_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) { return 0; }
int RGE_Static_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7) { return 0; }
int RGE_Static_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) { return 0; }
int RGE_Static_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) { return 0; }
int RGE_Static_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) { return 0; }
int RGE_Static_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) { return 0; }
int RGE_Static_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) { return 0; }
XYZBYTEPoint* RGE_Static_Object::userDefinedWaypoint(int param_1) { return nullptr; }
int RGE_Static_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) { return 0; }
void RGE_Static_Object::removeAllUserDefinedWaypoints(int param_1) {}
void RGE_Static_Object::removeUserDefinedWaypoint(int param_1) {}
int RGE_Static_Object::numberUserDefinedWaypoints() { return 0; }
Path* RGE_Static_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) { return nullptr; }
long RGE_Static_Object::get_action_checksum() { return 0; }
long RGE_Static_Object::get_waypoint_checksum() { return 0; }
int RGE_Static_Object::setup(int param_1, RGE_Game_World* param_2) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C1840
    int fd = param_1;

    this->type = 0x0A;

    uchar owner_index = 0;
    rge_read(fd, &owner_index, 1);
    this->owner = param_2->players[owner_index];

    short master_index = 0;
    rge_read(fd, &master_index, 2);
    this->master_obj = this->owner->master_objects[master_index];

    short sprite_index = 0;
    rge_read(fd, &sprite_index, 2);
    if (sprite_index < 0) {
        this->sprite = nullptr;
    } else {
        this->sprite = param_2->sprites[sprite_index];
    }
    this->old_sprite = nullptr;

    int inside_obj_id = 0;
    rge_read(fd, &inside_obj_id, 4);
    if (inside_obj_id == -1) {
        this->inside_obj = nullptr;
    } else {
        this->inside_obj = (RGE_Static_Object*)inside_obj_id;
    }

    rge_read(fd, &this->hp, 4);
    rge_read(fd, &this->object_state, 1);
    rge_read(fd, &this->sleep_flag, 1);
    if (save_game_version >= 7.09f) {
        rge_read(fd, &this->dopple_flag, 1);
    }
    rge_read(fd, &this->goto_sleep_flag, 1);
    rge_read(fd, &this->id, 4);
    rge_read(fd, &this->facet, 1);
    rge_read(fd, &this->world_x, 4);
    rge_read(fd, &this->world_y, 4);
    rge_read(fd, &this->world_z, 4);
    rge_read(fd, &this->screen_x_offset, 2);
    rge_read(fd, &this->screen_y_offset, 2);
    rge_read(fd, &this->shadow_x_offset, 2);
    rge_read(fd, &this->shadow_y_offset, 2);
    rge_read(fd, &this->selected_group, 1);
    rge_read(fd, &this->attribute_type_held, 2);
    rge_read(fd, &this->attribute_amount_held, 4);
    rge_read(fd, &this->worker_num, 1);
    rge_read(fd, &this->curr_damage_percent, 1);
    rge_read(fd, &this->underAttackValue, 1);
    this->tile = nullptr;

    rge_read(fd, &this->groupCommanderValue, 4);
    rge_read(fd, &this->groupRangeValue, 4);

    if (save_game_version == 6.991f) {
        int discarded = 0;
        rge_read(fd, &discarded, 4);
        rge_read(fd, &discarded, 4);
        rge_read(fd, &discarded, 4);
        rge_read(fd, &discarded, 4);
        rge_read(fd, &discarded, 4);
        rge_read(fd, &discarded, 4);
    }

    int group_member_count = 0;
    rge_read(fd, &group_member_count, 4);
    for (int index = 0; index < group_member_count; ++index) {
        int member_id = 0;
        rge_read(fd, &member_id, 4);
        rge_static_add_unique_member(this->groupMembers, member_id);
    }

    int pathing_member_count = 0;
    rge_read(fd, &pathing_member_count, 4);
    for (int index = 0; index < pathing_member_count; ++index) {
        int member_id = 0;
        rge_read(fd, &member_id, 4);
        rge_static_add_unique_member(this->pathingGroupMembers, member_id);
    }

    this->sprite_list = this->create_sprite_list();
    if (this->sprite_list != nullptr) {
        this->sprite_list->load(fd, param_2->sprites);
    }

    if (this->owner != nullptr && this->owner->world != nullptr) {
        this->owner->world->addObject(this);
    }

    RGE_Object_List* object_list = nullptr;
    if (this->sleep_flag == 0) {
        if (this->dopple_flag == 0) {
            object_list = this->owner->objects;
        } else {
            object_list = this->owner->doppleganger_objects;
        }
    } else {
        object_list = this->owner->sleeping_objects;
    }

    if (object_list != nullptr) {
        object_list->add_node(this);
    }

    this->objects = this->create_object_list();
    this->selected = 0;
    return 1;
}
int RGE_Static_Object::setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    // Source of truth intent: stat_obj.cpp.decomp setup(master, player, x, y, z)
    // initializes a live object instance (sprite/object lists + runtime state).
    if (param_1 == nullptr || param_2 == nullptr || param_2->world == nullptr) {
        return 0;
    }

    this->type = 0x0A;

    if (this->sprite_list == nullptr) {
        this->sprite_list = this->create_sprite_list();
    } else {
        this->sprite_list->delete_list();
    }
    if (this->objects == nullptr) {
        this->objects = this->create_object_list();
    }
    if (this->sprite_list == nullptr || this->objects == nullptr) {
        return 0;
    }

    if (param_1->recyclable == 0) {
        this->id = param_2->world->get_next_object_id();
    } else {
        this->id = param_2->world->get_next_reusable_object_id();
    }

    this->recycle_in_to_game(param_1, param_2, param_3, param_4, param_5);
    return 1;
}
RGE_Object_List* RGE_Static_Object::create_object_list() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C1D60
    RGE_Object_List* list = (RGE_Object_List*)::operator new(sizeof(RGE_Object_List), std::nothrow);
    if (list != nullptr) {
        return new(list) RGE_Object_List();
    }
    return nullptr;
}
RGE_Active_Sprite_List* RGE_Static_Object::create_sprite_list() {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C1DC0
    RGE_Active_Sprite_List* list = (RGE_Active_Sprite_List*)::operator new(sizeof(RGE_Active_Sprite_List), std::nothrow);
    if (list != nullptr) {
        return new(list) RGE_Active_Sprite_List(this);
    }
    return nullptr;
}

// Scale factor from world coordinates to obstruction map cells.
// ASM: DAT_00574768 used in addToObstructionMap/removeFromObstructionMap.
// ObstructionMap is 4x the tile resolution (1020 cells for 255 tiles).
static const float kObstructionMapScale = 4.0f;

int RGE_Static_Object::addToObstructionMap(int param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C6B80
    // ASM-verified at stat_obj.cpp.asm @ 0x004C6B80
    if (this->master_obj->radius_z <= 0.0f) {
        return 0;
    }
    if (this->inObstructionMapValue != 1) {
        int obMapMinX = (int)((this->world_x - this->master_obj->radius_x) * kObstructionMapScale);
        if (obMapMinX < 0) obMapMinX = 0;
        int obMapMinY = (int)((this->world_y - this->master_obj->radius_y) * kObstructionMapScale);
        if (obMapMinY < 0) obMapMinY = 0;
        int obMapMaxX = (int)((this->master_obj->radius_x + this->world_x) * kObstructionMapScale);
        int obMapMaxY = (int)((this->master_obj->radius_y + this->world_y) * kObstructionMapScale);

        for (int x = obMapMinX; x < obMapMaxX; x++) {
            for (int y = obMapMinY; y < obMapMaxY; y++) {
                if (param_1 != 1) {
                    pathSystem.incrementObstruction(x, y);
                }
                if (param_1 != 0) {
                    aiPathSystem.incrementObstruction(x, y);
                }
            }
        }
        this->lastInObstructionMapValue = this->inObstructionMapValue;
        this->inObstructionMapValue = 1;
        return 1;
    }
    return 0;
}

int RGE_Static_Object::removeFromObstructionMap(int param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C6C90
    // ASM-verified at stat_obj.cpp.asm @ 0x004C6C90
    if (this->master_obj->radius_z <= 0.0f) {
        return 0;
    }
    if (this->inObstructionMapValue != 0) {
        int obMapMinX = (int)((this->world_x - this->master_obj->radius_x) * kObstructionMapScale);
        if (obMapMinX < 0) obMapMinX = 0;
        int obMapMinY = (int)((this->world_y - this->master_obj->radius_y) * kObstructionMapScale);
        if (obMapMinY < 0) obMapMinY = 0;
        int obMapMaxX = (int)((this->master_obj->radius_x + this->world_x) * kObstructionMapScale);
        int obMapMaxY = (int)((this->master_obj->radius_y + this->world_y) * kObstructionMapScale);

        for (int x = obMapMinX; x < obMapMaxX; x++) {
            for (int y = obMapMinY; y < obMapMaxY; y++) {
                if (param_1 != 1) {
                    pathSystem.decrementObstruction(x, y);
                }
                if (param_1 != 0) {
                    aiPathSystem.decrementObstruction(x, y);
                }
            }
        }
        this->lastInObstructionMapValue = this->inObstructionMapValue;
        this->inObstructionMapValue = 0;
        return 1;
    }
    return 0;
}

RGE_Static_Object* RGE_Static_Object::get_object_pointer(long param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4250
    RGE_Static_Object* result = nullptr;
    if (param_1 >= 0) {
        result = this->owner->objects->find_by_id(param_1);
        if (result == nullptr) {
            result = this->owner->sleeping_objects->find_by_id(param_1);
            if (result == nullptr) {
                result = this->owner->doppleganger_objects->find_by_id(param_1);
                if (result == nullptr) {
                    RGE_Player* myOwner = this->owner;
                    unsigned char i = 0;
                    RGE_Game_World* world = myOwner->world;
                    if ((short)(unsigned short)i < world->player_num) {
                        do {
                            if ((unsigned short)i != myOwner->id) {
                                result = world->players[(int)i]->objects->find_by_id(param_1);
                                if (result != nullptr) return result;
                                result = this->owner->world->players[(int)i]->sleeping_objects->find_by_id(param_1);
                                if (result != nullptr) return result;
                                result = this->owner->world->players[(int)i]->doppleganger_objects->find_by_id(param_1);
                                if (result != nullptr) return result;
                            }
                            myOwner = this->owner;
                            i = i + 1;
                            world = myOwner->world;
                        } while ((short)(unsigned short)i < world->player_num);
                    }
                }
            }
        }
    }
    return result;
}

RGE_Sprite* RGE_Static_Object::get_sprite_pointer(short param_1) {
    // Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C4330
    if (param_1 >= 0) {
        RGE_Game_World* world = this->owner->world;
        if (param_1 < world->sprite_num) {
            return world->sprites[param_1];
        }
    }
    return nullptr;
}
