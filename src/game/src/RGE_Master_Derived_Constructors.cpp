#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Master_Missile_Object.h"
#include "../include/RGE_Master_Doppleganger_Object.h"

#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Task_List.h"
#include "../include/globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void rge_skip_task_binary(int fd) {
    short s = 0;
    uchar b = 0;
    float f = 0.0f;

    rge_read(fd, &s, 2);  // id
    rge_read(fd, &b, 1);  // is_default
    rge_read(fd, &s, 2);  // action_type
    rge_read(fd, &s, 2);  // object_group
    rge_read(fd, &s, 2);  // object_id
    rge_read(fd, &s, 2);  // terrain_id
    rge_read(fd, &s, 2);  // attribute_type
    rge_read(fd, &s, 2);  // attribute_type2
    rge_read(fd, &s, 2);  // attribute_type3
    rge_read(fd, &s, 2);  // attribute_type4
    rge_read(fd, &f, 4);  // work_val1
    rge_read(fd, &f, 4);  // work_val2
    rge_read(fd, &f, 4);  // work_range
    rge_read(fd, &b, 1);  // search_flag
    rge_read(fd, &f, 4);  // search_wait_time
    rge_read(fd, &b, 1);  // combat_level
    rge_read(fd, &b, 1);  // combat_level_flag
    rge_read(fd, &s, 2);  // work_flag
    rge_read(fd, &s, 2);  // work_flag2
    rge_read(fd, &b, 1);  // owner_type
    rge_read(fd, &b, 1);  // holding_attr
    rge_read(fd, &b, 1);  // state_building
    rge_read(fd, &s, 2);  // move_sprite
    rge_read(fd, &s, 2);  // work_sprite
    rge_read(fd, &s, 2);  // work_sprite2
    rge_read(fd, &s, 2);  // carry_sprite
    rge_read(fd, &s, 2);  // work_sound
    rge_read(fd, &s, 2);  // work_sound2
}

static void rge_skip_task_list_binary(int fd) {
    short list_num = 0;
    rge_read(fd, &list_num, 2);
    if (list_num <= 0) {
        return;
    }

    for (short i = 0; i < list_num; ++i) {
        short task_type = 0;
        rge_read(fd, &task_type, 2);
        rge_skip_task_binary(fd);
    }
}

RGE_Master_Animated_Object::RGE_Master_Animated_Object()
    : RGE_Master_Static_Object() {
    this->master_type = 0x14;
    this->speed = 0.0f;
}

// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044F9C0
RGE_Master_Animated_Object::RGE_Master_Animated_Object(RGE_Master_Animated_Object* param_1, int param_2)
    // Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044F9C0
    : RGE_Master_Static_Object((RGE_Master_Static_Object*)param_1, 0) {
    this->master_type = 0x14;
    this->speed = 0.0f;
    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FA40
RGE_Master_Animated_Object::RGE_Master_Animated_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    // Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FA40
    : RGE_Master_Static_Object(param_1, param_2, param_3, 0) {
    this->master_type = 0x14;
    this->speed = 0.0f;
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FAB0
RGE_Master_Animated_Object::RGE_Master_Animated_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Static_Object(param_1, param_2, param_3, param_4, 0) {
    this->master_type = 0x14;
    this->speed = 0.0f;
    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}

// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FB30
int RGE_Master_Animated_Object::setup(RGE_Master_Animated_Object* param_1) {
    RGE_Master_Static_Object::setup((RGE_Master_Static_Object*)param_1);
    this->master_type = 0x14;
    this->speed = param_1->speed;
    return 1;
}

// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FB60
int RGE_Master_Animated_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    RGE_Master_Static_Object::setup(param_1, param_2, param_3);
    this->master_type = 0x14;
    rge_read(param_1, &this->speed, 4);
    return 1;
}

// Fully verified. Source of truth: m_an_obj.cpp.decomp @ 0x0044FBA0
int RGE_Master_Animated_Object::setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    RGE_Master_Static_Object::setup(param_1, param_2, param_3, param_4);
    this->master_type = 0x14;
    fscanf(param_1, " %f", &this->speed);
    return 1;
}

RGE_Master_Moving_Object::RGE_Master_Moving_Object()
    : RGE_Master_Animated_Object() {
    this->master_type = 0x1E;
    this->move_sprite = nullptr;
    this->run_sprite = nullptr;
    this->turn_speed = 0.0f;
    this->size_class = 0;
    this->obj_trail_id = 0;
    this->obj_trail_options = 0;
    this->obj_trail_spacing = 0.0f;
    this->move_algorithem = 0;
}

// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451A20
RGE_Master_Moving_Object::RGE_Master_Moving_Object(RGE_Master_Moving_Object* param_1, int param_2)
    : RGE_Master_Animated_Object((RGE_Master_Animated_Object*)param_1, 0) {
    this->master_type = 0x1E;
    this->move_sprite = nullptr;
    this->run_sprite = nullptr;
    this->turn_speed = 0.0f;
    this->size_class = 0;
    this->obj_trail_id = 0;
    this->obj_trail_options = 0;
    this->obj_trail_spacing = 0.0f;
    this->move_algorithem = 0;

    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451AA0
RGE_Master_Moving_Object::RGE_Master_Moving_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, 0) {
    this->master_type = 0x1E;
    this->move_sprite = nullptr;
    this->run_sprite = nullptr;
    this->turn_speed = 0.0f;
    this->size_class = 0;
    this->obj_trail_id = 0;
    this->obj_trail_options = 0;
    this->obj_trail_spacing = 0.0f;
    this->move_algorithem = 0;

    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451B10
RGE_Master_Moving_Object::RGE_Master_Moving_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, param_4, 0) {
    this->master_type = 0x1E;
    this->move_sprite = nullptr;
    this->run_sprite = nullptr;
    this->turn_speed = 0.0f;
    this->size_class = 0;
    this->obj_trail_id = 0;
    this->obj_trail_options = 0;
    this->obj_trail_spacing = 0.0f;
    this->move_algorithem = 0;

    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}

// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451B90
int RGE_Master_Moving_Object::setup(RGE_Master_Moving_Object* param_1) {
    RGE_Master_Animated_Object::setup((RGE_Master_Animated_Object*)param_1);
    this->master_type = 0x1E;
    this->move_sprite = param_1->move_sprite;
    this->run_sprite = param_1->run_sprite;
    this->turn_speed = param_1->turn_speed;
    this->size_class = param_1->size_class;
    this->obj_trail_id = param_1->obj_trail_id;
    this->obj_trail_options = param_1->obj_trail_options;
    this->obj_trail_spacing = param_1->obj_trail_spacing;
    this->move_algorithem = param_1->move_algorithem;
    return 1;
}

// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451C10
int RGE_Master_Moving_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    short move_sprite_idx = -1;
    short run_sprite_idx = -1;
    RGE_Master_Animated_Object::setup(param_1, param_2, param_3);
    this->master_type = 0x1E;
    rge_read(param_1, &move_sprite_idx, 2);
    rge_read(param_1, &run_sprite_idx, 2);
    rge_read(param_1, &this->turn_speed, 4);
    rge_read(param_1, &this->size_class, 1);
    rge_read(param_1, &this->obj_trail_id, 2);
    rge_read(param_1, &this->obj_trail_options, 1);
    rge_read(param_1, &this->obj_trail_spacing, 4);
    rge_read(param_1, &this->move_algorithem, 1);
    this->move_sprite = (move_sprite_idx < 0 || param_2 == nullptr) ? nullptr : param_2[move_sprite_idx];
    this->run_sprite = (run_sprite_idx < 0 || param_2 == nullptr) ? nullptr : param_2[run_sprite_idx];
    return 1;
}

// Fully verified. Source of truth: m_mo_obj.cpp.decomp @ 0x00451D10
int RGE_Master_Moving_Object::setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    short move_sprite_idx = -1;
    short run_sprite_idx = -1;
    short size_class = 0;
    short obj_trail_options = 0;
    short move_algorithem = 0;

    RGE_Master_Animated_Object::setup(param_1, param_2, param_3, param_4);
    this->master_type = 0x1E;
    fscanf(param_1, " %hd %hd %f %hd %hd %hd %f %hd",
        &move_sprite_idx,
        &run_sprite_idx,
        &this->turn_speed,
        &size_class,
        &this->obj_trail_id,
        &obj_trail_options,
        &this->obj_trail_spacing,
        &move_algorithem);

    this->size_class = (uchar)size_class;
    this->obj_trail_options = (uchar)obj_trail_options;
    this->move_algorithem = (uchar)move_algorithem;
    this->move_sprite = (move_sprite_idx < 0 || param_2 == nullptr) ? nullptr : param_2[move_sprite_idx];
    this->run_sprite = (run_sprite_idx < 0 || param_2 == nullptr) ? nullptr : param_2[run_sprite_idx];
    return 1;
}

RGE_Master_Action_Object::RGE_Master_Action_Object()
    : RGE_Master_Moving_Object() {
    this->master_type = 0x28;
    this->tasks = nullptr;
    this->default_task = -1;
    this->search_radius = 0.0f;
    this->work_rate = 0.0f;
    this->drop_site = 0;
    this->backup_drop_site = 0;
    this->task_by_group = 0;
    this->command_sound = nullptr;
    this->move_sound = nullptr;
    this->run_pattern = 0;
}

// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F070
RGE_Master_Action_Object::RGE_Master_Action_Object(RGE_Master_Action_Object* param_1, int param_2)
    : RGE_Master_Moving_Object((RGE_Master_Moving_Object*)param_1, 0) {
    this->master_type = 0x28;
    this->tasks = nullptr;
    this->default_task = -1;
    this->search_radius = 0.0f;
    this->work_rate = 0.0f;
    this->drop_site = 0;
    this->backup_drop_site = 0;
    this->task_by_group = 0;
    this->command_sound = nullptr;
    this->move_sound = nullptr;
    this->run_pattern = 0;

    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F0F0
RGE_Master_Action_Object::RGE_Master_Action_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Moving_Object(param_1, param_2, param_3, 0) {
    this->master_type = 0x28;
    this->tasks = nullptr;
    this->default_task = -1;
    this->search_radius = 0.0f;
    this->work_rate = 0.0f;
    this->drop_site = 0;
    this->backup_drop_site = 0;
    this->task_by_group = 0;
    this->command_sound = nullptr;
    this->move_sound = nullptr;
    this->run_pattern = 0;
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F160
RGE_Master_Action_Object::RGE_Master_Action_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Moving_Object(param_1, param_2, param_3, param_4, 0) {
    this->master_type = 0x28;
    this->tasks = nullptr;
    this->default_task = -1;
    this->search_radius = 0.0f;
    this->work_rate = 0.0f;
    this->drop_site = 0;
    this->backup_drop_site = 0;
    this->task_by_group = 0;
    this->command_sound = nullptr;
    this->move_sound = nullptr;
    this->run_pattern = 0;
    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}

// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F1E0
int RGE_Master_Action_Object::setup(RGE_Master_Action_Object* param_1) {
    RGE_Master_Moving_Object::setup((RGE_Master_Moving_Object*)param_1);
    this->master_type = 0x28;
    this->default_task = param_1->default_task;
    this->search_radius = param_1->search_radius;
    this->work_rate = param_1->work_rate;
    this->drop_site = param_1->drop_site;
    this->backup_drop_site = param_1->backup_drop_site;
    this->task_by_group = param_1->task_by_group;
    this->command_sound = param_1->command_sound;
    this->move_sound = param_1->move_sound;
    this->run_pattern = param_1->run_pattern;
    this->tasks = this->create_task_list();
    if (this->tasks == nullptr) {
        this->tasks = new RGE_Task_List();
    }
    if (this->tasks != nullptr && param_1->tasks != nullptr) {
        this->tasks->copy(param_1->tasks);
    }
    return 1;
}

// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F290
int RGE_Master_Action_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    short command_sound_idx = -1;
    short move_sound_idx = -1;

    RGE_Master_Moving_Object::setup(param_1, param_2, param_3);
    this->master_type = 0x28;
    rge_read(param_1, &this->default_task, 2);
    rge_read(param_1, &this->search_radius, 4);
    rge_read(param_1, &this->work_rate, 4);
    rge_read(param_1, &this->drop_site, 2);
    rge_read(param_1, &this->backup_drop_site, 2);
    rge_read(param_1, &this->task_by_group, 1);
    rge_read(param_1, &command_sound_idx, 2);
    if (save_game_version < 6.92f) {
        move_sound_idx = command_sound_idx;
    } else {
        rge_read(param_1, &move_sound_idx, 2);
    }
    rge_read(param_1, &this->run_pattern, 1);

    this->command_sound = (command_sound_idx >= 0 && param_3 != nullptr) ? param_3[command_sound_idx] : nullptr;
    this->move_sound = (move_sound_idx >= 0 && param_3 != nullptr) ? param_3[move_sound_idx] : nullptr;

    this->tasks = this->create_task_list();
    if (this->tasks == nullptr) {
        this->tasks = new RGE_Task_List();
    }
    if (this->tasks != nullptr) {
        this->tasks->load(param_1, param_2, param_3);
    }
    return 1;
}

// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F3C0
int RGE_Master_Action_Object::setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    short task_by_group = 0;
    short command_sound_idx = -1;
    short move_sound_idx = -1;
    short run_pattern = 0;

    RGE_Master_Moving_Object::setup(param_1, param_2, param_3, param_4);
    this->master_type = 0x28;
    fscanf(param_1, " %f %f %hd %hd %hd %hd %hd %hd",
        &this->search_radius,
        &this->work_rate,
        &this->drop_site,
        &this->backup_drop_site,
        &task_by_group,
        &command_sound_idx,
        &move_sound_idx,
        &run_pattern);
    this->task_by_group = (uchar)task_by_group;
    this->run_pattern = (uchar)run_pattern;
    this->command_sound = (command_sound_idx >= 0 && param_3 != nullptr) ? param_3[command_sound_idx] : nullptr;
    this->move_sound = (move_sound_idx >= 0 && param_3 != nullptr) ? param_3[move_sound_idx] : nullptr;

    this->tasks = this->create_task_list();
    if (this->tasks == nullptr) {
        this->tasks = new RGE_Task_List();
    }
    if (this->tasks != nullptr) {
        this->tasks->load(param_1, param_2, param_3);
        this->default_task = -1;
        for (short i = 0; i < this->tasks->list_num; ++i) {
            if (this->tasks->list != nullptr && this->tasks->list[i] != nullptr && this->tasks->list[i]->is_default != 0) {
                this->default_task = i;
                break;
            }
        }
    }
    return 1;
}


RGE_Master_Missile_Object::RGE_Master_Missile_Object()
    : RGE_Master_Combat_Object() {
    this->master_type = 0x3C;
    this->missile_type = 0;
    this->targetting_type = 0;
    this->missile_hit_info = 0;
    this->missile_die_info = 0;
    this->area_effect_specials = 0;
    this->ballistics_ratio = 0.0f;
}

// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x00451440
RGE_Master_Missile_Object::RGE_Master_Missile_Object(RGE_Master_Missile_Object* param_1, int param_2)
    : RGE_Master_Combat_Object((RGE_Master_Combat_Object*)param_1, 0) {
    this->master_type = 0x3C;
    this->missile_type = 0;
    this->targetting_type = 0;
    this->missile_hit_info = 0;
    this->missile_die_info = 0;
    this->area_effect_specials = 0;
    this->ballistics_ratio = 0.0f;
    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x004514C0
RGE_Master_Missile_Object::RGE_Master_Missile_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, 0) {
    this->master_type = 0x3C;
    this->missile_type = 0;
    this->targetting_type = 0;
    this->missile_hit_info = 0;
    this->missile_die_info = 0;
    this->area_effect_specials = 0;
    this->ballistics_ratio = 0.0f;

    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x00451530
RGE_Master_Missile_Object::RGE_Master_Missile_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, param_4, 0) {
    this->master_type = 0x3C;
    this->missile_type = 0;
    this->targetting_type = 0;
    this->missile_hit_info = 0;
    this->missile_die_info = 0;
    this->area_effect_specials = 0;
    this->ballistics_ratio = 0.0f;

    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}

// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x004515B0
int RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object* param_1) {
    RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object*)param_1);
    this->master_type = 0x3C;
    this->missile_type = param_1->missile_type;
    this->targetting_type = param_1->targetting_type;
    this->missile_hit_info = param_1->missile_hit_info;
    this->missile_die_info = param_1->missile_die_info;
    this->area_effect_specials = param_1->area_effect_specials;
    this->ballistics_ratio = param_1->ballistics_ratio;
    return 1;
}

// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x00451620
int RGE_Master_Missile_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    RGE_Master_Combat_Object::setup(param_1, param_2, param_3);
    this->master_type = 0x3C;
    rge_read(param_1, &this->missile_type, 1);
    rge_read(param_1, &this->targetting_type, 1);
    rge_read(param_1, &this->missile_hit_info, 1);
    rge_read(param_1, &this->missile_die_info, 1);
    rge_read(param_1, &this->area_effect_specials, 1);
    rge_read(param_1, &this->ballistics_ratio, 4);
    return 1;
}

// Fully verified. Source of truth: m_mi_obj.cpp.decomp @ 0x004516C0
int RGE_Master_Missile_Object::setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    short missile_type = 0;
    short targetting_type = 0;
    short missile_hit_info = 0;
    short missile_die_info = 0;
    short area_effect_specials = 0;

    RGE_Master_Combat_Object::setup(param_1, param_2, param_3, param_4);
    this->master_type = 0x3C;
    fscanf(param_1, " %hd %hd %hd %hd %hd %f",
        &missile_type,
        &targetting_type,
        &missile_hit_info,
        &missile_die_info,
        &area_effect_specials,
        &this->ballistics_ratio);
    this->missile_type = (uchar)missile_type;
    this->targetting_type = (uchar)targetting_type;
    this->missile_hit_info = (uchar)missile_hit_info;
    this->missile_die_info = (uchar)missile_die_info;
    this->area_effect_specials = (uchar)area_effect_specials;
    return 1;
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object()
    : RGE_Master_Animated_Object() {
    this->master_type = 0x19;
}

// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x004510C0
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object* param_1, int param_2)
    : RGE_Master_Animated_Object((RGE_Master_Animated_Object*)param_1, 0) {
    this->master_type = 0x19;
    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451140
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, 0) {
    this->master_type = 0x19;
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x004511B0
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, param_4, 0) {
    this->master_type = 0x19;
    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}
