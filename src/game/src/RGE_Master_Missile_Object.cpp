#include "../include/RGE_Master_Missile_Object.h"
#include "../include/RGE_Missile_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Task_List.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/globals.h"

#include <new>
#include <stdio.h>

static int rge_ftol(float value) {
    // Fully verified. Source of truth: m_mi_obj.cpp.decomp (helper implementation).
    int result;
    __asm {
        fld value
        fistp result
    }
    return result;
}

// TODO: PARITY [MODERATE]: Default ctor needs explicit offset/ASM mapping in m_mi_obj.cpp.decomp audit.
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


// TODO: PARITY [MODERATE]: make_new_obj() marker placement should be normalized above signature in m_mi_obj.cpp.decomp audit.
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


// Fully verified. Source of truth: m_mi_obj.cpp.decomp (helper implementation).
uchar RGE_Master_Missile_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }


// Fully verified. Source of truth: m_mi_obj.cpp.decomp (helper implementation).
uchar RGE_Master_Missile_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }


// Fully verified. Source of truth: m_mi_obj.cpp.decomp (helper implementation).
long RGE_Master_Missile_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }


// Fully verified. Source of truth: m_mi_obj.cpp.decomp (helper implementation).
void RGE_Master_Missile_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }


// Fully verified. Source of truth: m_mi_obj.cpp.decomp (helper implementation).
void RGE_Master_Missile_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }


// Fully verified. Source of truth: m_mi_obj.cpp.decomp (helper implementation).
void RGE_Master_Missile_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }


// Fully verified. Source of truth: m_mi_obj.cpp.decomp (helper implementation).
RGE_Task_List* RGE_Master_Missile_Object::create_task_list() { return new RGE_Task_List(); }

