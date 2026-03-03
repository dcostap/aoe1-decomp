#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Task_List.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/globals.h"

#include <new>
#include <stdio.h>

// TODO: PARITY [MODERATE]: Default ctor needs explicit offset/ASM mapping in m_ac_obj.cpp.decomp audit.
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
    this->tasks->copy(param_1->tasks);
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

    this->command_sound = (command_sound_idx >= 0) ? param_3[command_sound_idx] : nullptr;
    this->move_sound = (move_sound_idx >= 0) ? param_3[move_sound_idx] : nullptr;

    this->tasks = this->create_task_list();
    this->tasks->load(param_1, param_2, param_3);
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
    this->command_sound = (command_sound_idx >= 0) ? param_3[command_sound_idx] : nullptr;
    this->move_sound = (move_sound_idx >= 0) ? param_3[move_sound_idx] : nullptr;

    this->tasks = this->create_task_list();
    this->tasks->load(param_1, param_2, param_3);
    this->default_task = -1;
    for (short i = 0; i < this->tasks->list_num; ++i) {
        if (this->tasks->list[i]->is_default != 0) {
            this->default_task = i;
            break;
        }
    }
    return 1;
}



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


// Fully verified. Source of truth: m_ac_obj.cpp.decomp (helper implementation).
uchar RGE_Master_Action_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }


// Fully verified. Source of truth: m_ac_obj.cpp.decomp (helper implementation).
uchar RGE_Master_Action_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }


// Fully verified. Source of truth: m_ac_obj.cpp.decomp (helper implementation).
long RGE_Master_Action_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }


// Fully verified. Source of truth: m_ac_obj.cpp.decomp (helper implementation).
void RGE_Master_Action_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }


// Fully verified. Source of truth: m_ac_obj.cpp.decomp (helper implementation).
void RGE_Master_Action_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }


// TODO: PARITY [MODERATE]: draw() wrapper needs explicit offset mapping in m_ac_obj.cpp.decomp audit.
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

