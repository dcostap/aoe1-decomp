#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Master_Missile_Object.h"
#include "../include/RGE_Master_Doppleganger_Object.h"
#include "../include/RGE_Doppleganger_Object.h"
#include "../include/RGE_Animated_Object.h"
#include "../include/RGE_Moving_Object.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Combat_Object.h"
#include "../include/RGE_Missile_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Task.h"
#include "../include/globals.h"

#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Task_List.h"
#include <new>
#include <stdlib.h>

static int rge_ftol(float value) {
    int result;
    __asm {
        fld value
        fistp result
    }
    return result;
}

// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FBF0
RGE_Master_Animated_Object::~RGE_Master_Animated_Object() {}
// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FD40
void RGE_Master_Animated_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    RGE_Master_Static_Object::copy_obj(param_1);
    this->speed = ((RGE_Master_Animated_Object*)param_1)->speed;
}
// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FD60
void RGE_Master_Animated_Object::modify(float param_1, uchar param_2) {
    if (param_2 != '\x05') {
        RGE_Master_Static_Object::modify(param_1, param_2);
        return;
    }
    this->speed = param_1;
}
// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FD90
void RGE_Master_Animated_Object::modify_delta(float param_1, uchar param_2) {
    if (param_2 != '\x05') {
        RGE_Master_Static_Object::modify_delta(param_1, param_2);
        return;
    }
    this->speed = this->speed + param_1;
}
// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FDC0
void RGE_Master_Animated_Object::modify_percent(float param_1, uchar param_2) {
    if (param_2 != '\x05') {
        RGE_Master_Static_Object::modify_percent(param_1, param_2);
        return;
    }
    this->speed = this->speed * param_1;
}
// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FDF0
void RGE_Master_Animated_Object::save(int param_1) {
    RGE_Master_Static_Object::save(param_1);
    rge_write(param_1, &this->speed, 4);
}
// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FC00
RGE_Static_Object* RGE_Master_Animated_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    if (this->recyclable != 0) {
        RGE_Static_Object* recycled = param_1->world->recycle_object_in_to_game(this->master_type);
        if (recycled != nullptr) {
            recycled->recycle_in_to_game(this, param_1, param_2, param_3, param_4);
            return recycled;
        }
    }

    RGE_Animated_Object* obj = (RGE_Animated_Object*)::operator new(sizeof(RGE_Animated_Object), std::nothrow);
    if (obj != nullptr) {
        obj = new (obj) RGE_Animated_Object(this, param_1, param_2, param_3, param_4, 1);
        return obj;
    }
    return nullptr;
}
// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FCD0
RGE_Master_Static_Object* RGE_Master_Animated_Object::make_new_master() {
    RGE_Master_Animated_Object* master =
        (RGE_Master_Animated_Object*)::operator new(sizeof(RGE_Master_Animated_Object), std::nothrow);
    if (master != nullptr) {
        master = new (master) RGE_Master_Animated_Object(this, 1);
        return master;
    }
    return nullptr;
}
uchar RGE_Master_Animated_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Animated_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Animated_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Animated_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Animated_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Animated_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }

// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451DE0
RGE_Master_Moving_Object::~RGE_Master_Moving_Object() {}
// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451F30
void RGE_Master_Moving_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    RGE_Master_Animated_Object::copy_obj(param_1);
    RGE_Master_Moving_Object* src = (RGE_Master_Moving_Object*)param_1;
    this->move_sprite = src->move_sprite;
    this->run_sprite = src->run_sprite;
    this->turn_speed = src->turn_speed;
    this->size_class = src->size_class;
    this->obj_trail_id = src->obj_trail_id;
    this->obj_trail_options = src->obj_trail_options;
    this->obj_trail_spacing = src->obj_trail_spacing;
    this->move_algorithem = src->move_algorithem;
}
// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451FB0
void RGE_Master_Moving_Object::modify(float param_1, uchar param_2) {
    if (param_2 != '\x06') {
        RGE_Master_Animated_Object::modify(param_1, param_2);
        return;
    }
    this->turn_speed = param_1;
}
// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451FE0
void RGE_Master_Moving_Object::modify_delta(float param_1, uchar param_2) {
    if (param_2 != '\x06') {
        RGE_Master_Animated_Object::modify_delta(param_1, param_2);
        return;
    }
    this->turn_speed = this->turn_speed + param_1;
}
// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00452010
void RGE_Master_Moving_Object::modify_percent(float param_1, uchar param_2) {
    if (param_2 != '\x06') {
        RGE_Master_Animated_Object::modify_percent(param_1, param_2);
        return;
    }
    this->turn_speed = this->turn_speed * param_1;
}
// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00452040
void RGE_Master_Moving_Object::save(int param_1) {
    short move_sprite_id = -1;
    short run_sprite_id = -1;
    if (this->move_sprite != nullptr) {
        move_sprite_id = this->move_sprite->id;
    }
    if (this->run_sprite != nullptr) {
        run_sprite_id = this->run_sprite->id;
    }

    RGE_Master_Animated_Object::save(param_1);
    rge_write(param_1, &move_sprite_id, 2);
    rge_write(param_1, &run_sprite_id, 2);
    rge_write(param_1, &this->turn_speed, 4);
    rge_write(param_1, &this->size_class, 1);
    rge_write(param_1, &this->obj_trail_id, 2);
    rge_write(param_1, &this->obj_trail_options, 1);
    rge_write(param_1, &this->obj_trail_spacing, 4);
    rge_write(param_1, &this->move_algorithem, 1);
}
// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451DF0
RGE_Static_Object* RGE_Master_Moving_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    if (this->recyclable != 0) {
        RGE_Static_Object* recycled = param_1->world->recycle_object_in_to_game(this->master_type);
        if (recycled != nullptr) {
            recycled->recycle_in_to_game(this, param_1, param_2, param_3, param_4);
            return recycled;
        }
    }

    RGE_Moving_Object* obj = (RGE_Moving_Object*)::operator new(sizeof(RGE_Moving_Object), std::nothrow);
    if (obj != nullptr) {
        obj = new (obj) RGE_Moving_Object(this, param_1, param_2, param_3, param_4, 1);
        return obj;
    }
    return nullptr;
}
// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451EC0
RGE_Master_Static_Object* RGE_Master_Moving_Object::make_new_master() {
    RGE_Master_Moving_Object* master =
        (RGE_Master_Moving_Object*)::operator new(sizeof(RGE_Master_Moving_Object), std::nothrow);
    if (master != nullptr) {
        master = new (master) RGE_Master_Moving_Object(this, 1);
        return master;
    }
    return nullptr;
}
uchar RGE_Master_Moving_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Moving_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Moving_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Moving_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Moving_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Moving_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }

// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F4D0
RGE_Master_Action_Object::~RGE_Master_Action_Object() {
    if (this->tasks != nullptr) {
        delete this->tasks;
        this->tasks = nullptr;
    }
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F760
void RGE_Master_Action_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    RGE_Master_Moving_Object::copy_obj(param_1);
    RGE_Master_Action_Object* src = (RGE_Master_Action_Object*)param_1;
    this->default_task = src->default_task;
    this->search_radius = src->search_radius;
    this->work_rate = src->work_rate;
    this->drop_site = src->drop_site;
    this->backup_drop_site = src->backup_drop_site;
    this->task_by_group = src->task_by_group;
    this->command_sound = src->command_sound;
    this->move_sound = src->move_sound;
    this->tasks->copy(src->tasks);
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F7F0
void RGE_Master_Action_Object::modify(float param_1, uchar param_2) {
    if (param_2 != '\r') {
        RGE_Master_Moving_Object::modify(param_1, param_2);
        return;
    }
    this->work_rate = param_1;
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F820
void RGE_Master_Action_Object::modify_delta(float param_1, uchar param_2) {
    if (param_2 != '\r') {
        RGE_Master_Moving_Object::modify_delta(param_1, param_2);
        return;
    }
    this->work_rate = this->work_rate + param_1;
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F850
void RGE_Master_Action_Object::modify_percent(float param_1, uchar param_2) {
    if (param_2 != '\r') {
        RGE_Master_Moving_Object::modify_percent(param_1, param_2);
        return;
    }
    this->work_rate = this->work_rate * param_1;
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F880
void RGE_Master_Action_Object::save(int param_1) {
    short command_sound_num = -1;
    short move_sound_num = -1;

    RGE_Master_Moving_Object::save(param_1);
    if (this->command_sound != nullptr) {
        command_sound_num = this->command_sound->id;
    }
    if (this->move_sound != nullptr) {
        move_sound_num = this->move_sound->id;
    }

    rge_write(param_1, &this->default_task, 2);
    rge_write(param_1, &this->search_radius, 4);
    rge_write(param_1, &this->work_rate, 4);
    rge_write(param_1, &this->drop_site, 2);
    rge_write(param_1, &this->backup_drop_site, 2);
    rge_write(param_1, &this->task_by_group, 1);
    rge_write(param_1, &command_sound_num, 2);
    rge_write(param_1, &move_sound_num, 2);
    rge_write(param_1, &this->run_pattern, 1);
    this->tasks->save(param_1);
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F5A0
RGE_Static_Object* RGE_Master_Action_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    if (this->master_type != 0) {
        RGE_Static_Object* recycled = param_1->world->recycle_object_in_to_game(this->master_type);
        if (recycled != nullptr) {
            recycled->recycle_in_to_game(this, param_1, param_2, param_3, param_4);
            return recycled;
        }
    }

    RGE_Action_Object* obj = (RGE_Action_Object*)::operator new(sizeof(RGE_Action_Object), std::nothrow);
    if (obj != nullptr) {
        obj = new (obj) RGE_Action_Object(this, param_1, param_2, param_3, param_4, 1);
        return obj;
    }
    return nullptr;
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F670
RGE_Master_Static_Object* RGE_Master_Action_Object::make_new_master() {
    RGE_Master_Action_Object* master =
        (RGE_Master_Action_Object*)::operator new(sizeof(RGE_Master_Action_Object), std::nothrow);
    if (master != nullptr) {
        master = new (master) RGE_Master_Action_Object(this, 1);
        return master;
    }
    return nullptr;
}
uchar RGE_Master_Action_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Action_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Action_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Action_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Action_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Action_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F540
RGE_Task_List* RGE_Master_Action_Object::create_task_list() { return new RGE_Task_List(); }
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F6E0
RGE_Task* RGE_Master_Action_Object::get_task(short param_1) {
    if (param_1 != -1 && param_1 < this->tasks->list_num) {
        return this->tasks->list[param_1];
    }
    return nullptr;
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F710
RGE_Task* RGE_Master_Action_Object::getTaskByTaskID(int param_1) const {
    if (param_1 != -1) {
        int i = 0;
        int list_num = (int)this->tasks->list_num;
        while (i < list_num) {
            if (this->tasks->list[i]->action_type == param_1) {
                return this->tasks->list[i];
            }
            ++i;
        }
    }
    return nullptr;
}


// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x00451760
RGE_Master_Missile_Object::~RGE_Master_Missile_Object() {}
// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x004518B0
void RGE_Master_Missile_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    RGE_Master_Combat_Object::copy_obj(param_1);
    RGE_Master_Missile_Object* src = (RGE_Master_Missile_Object*)param_1;
    this->missile_type = src->missile_type;
    this->targetting_type = src->targetting_type;
    this->missile_hit_info = src->missile_hit_info;
    this->missile_die_info = src->missile_die_info;
    this->area_effect_specials = src->area_effect_specials;
    this->ballistics_ratio = src->ballistics_ratio;
}
// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x00451910
void RGE_Master_Missile_Object::modify(float param_1, uchar param_2) {
    if (param_2 == '\x13') {
        this->targetting_type = (uchar)rge_ftol(param_1);
    }
    RGE_Master_Combat_Object::modify(param_1, param_2);
}
// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x00451940
void RGE_Master_Missile_Object::modify_delta(float param_1, uchar param_2) {
    if (param_2 == '\x13') {
        this->targetting_type = (uchar)rge_ftol(param_1);
    }
    RGE_Master_Combat_Object::modify_delta(param_1, param_2);
}
// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x00451970
void RGE_Master_Missile_Object::modify_percent(float param_1, uchar param_2) {
    if (param_2 == '\x13') {
        this->targetting_type = (uchar)rge_ftol(param_1);
    }
    RGE_Master_Combat_Object::modify_percent(param_1, param_2);
}
// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x004519A0
void RGE_Master_Missile_Object::save(int param_1) {
    RGE_Master_Combat_Object::save(param_1);
    rge_write(param_1, &this->missile_type, 1);
    rge_write(param_1, &this->targetting_type, 1);
    rge_write(param_1, &this->missile_hit_info, 1);
    rge_write(param_1, &this->missile_die_info, 1);
    rge_write(param_1, &this->area_effect_specials, 1);
    rge_write(param_1, &this->ballistics_ratio, 4);
}
RGE_Static_Object* RGE_Master_Missile_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    // Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x00451770
    if (this->master_type != 0) {
        RGE_Static_Object* recycled = param_1->world->recycle_object_in_to_game(this->master_type);
        if (recycled != nullptr) {
            recycled->recycle_in_to_game(this, param_1, param_2, param_3, param_4);
            return recycled;
        }
    }

    RGE_Missile_Object* obj = (RGE_Missile_Object*)::operator new(sizeof(RGE_Missile_Object), std::nothrow);
    if (obj != nullptr) {
        obj = new (obj) RGE_Missile_Object((RGE_Master_Combat_Object*)this, param_1, param_2, param_3, param_4, 1);
        return obj;
    }
    return nullptr;
}
// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x00451840
RGE_Master_Static_Object* RGE_Master_Missile_Object::make_new_master() {
    RGE_Master_Missile_Object* master =
        (RGE_Master_Missile_Object*)::operator new(sizeof(RGE_Master_Missile_Object), std::nothrow);
    if (master != nullptr) {
        master = new (master) RGE_Master_Missile_Object(this, 1);
        return master;
    }
    return nullptr;
}
uchar RGE_Master_Missile_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Missile_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Missile_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Missile_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Missile_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Missile_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
RGE_Task_List* RGE_Master_Missile_Object::create_task_list() { return new RGE_Task_List(); }

// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x004512C0
RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object() {}
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420
void RGE_Master_Doppleganger_Object::copy_obj(RGE_Master_Static_Object* param_1) { this->RGE_Master_Animated_Object::copy_obj(param_1); }
void RGE_Master_Doppleganger_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
void RGE_Master_Doppleganger_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
void RGE_Master_Doppleganger_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451430
void RGE_Master_Doppleganger_Object::save(int param_1) { this->RGE_Master_Animated_Object::save(param_1); }
// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FC00
RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    return this->RGE_Master_Animated_Object::make_new_obj(param_1, param_2, param_3, param_4);
}
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x004513B0
RGE_Master_Static_Object* RGE_Master_Doppleganger_Object::make_new_master() {
    RGE_Master_Doppleganger_Object* obj =
        (RGE_Master_Doppleganger_Object*)::operator new(sizeof(RGE_Master_Doppleganger_Object), std::nothrow);
    if (obj != nullptr) {
        obj = new (obj) RGE_Master_Doppleganger_Object(this, 1);
        return obj;
    }
    return nullptr;
}
uchar RGE_Master_Doppleganger_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Doppleganger_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Doppleganger_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Doppleganger_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Doppleganger_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Doppleganger_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451230
int RGE_Master_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object* param_1) {
    this->RGE_Master_Animated_Object::setup((RGE_Master_Animated_Object*)param_1);
    this->master_type = 0x19;
    return 1;
}
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451250
int RGE_Master_Doppleganger_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    this->RGE_Master_Animated_Object::setup(param_1, param_2, param_3);
    this->master_type = 0x19;
    return 1;
}
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451280
int RGE_Master_Doppleganger_Object::setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    this->RGE_Master_Animated_Object::setup(param_1, param_2, param_3, param_4);
    this->master_type = 0x19;
    this->recyclable = 1;
    return 1;
}
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x004512D0
RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(
    RGE_Player* param_1, float param_2, float param_3, float param_4, RGE_Static_Object* param_5) {
    if (this->recyclable != 0) {
        RGE_Static_Object* recycled = param_1->world->recycle_object_in_to_game(this->master_type);
        if (recycled != nullptr) {
            ((RGE_Doppleganger_Object*)recycled)
                ->recycle_in_to_game(this, param_1, param_2, param_3, param_4, param_5);
            return recycled;
        }
    }

    RGE_Doppleganger_Object* obj =
        (RGE_Doppleganger_Object*)::operator new(sizeof(RGE_Doppleganger_Object), std::nothrow);
    if (obj != nullptr) {
        obj = new(obj) RGE_Doppleganger_Object(this, param_1, param_2, param_3, param_4, 1, param_5);
        return obj;
    }
    return nullptr;
}
