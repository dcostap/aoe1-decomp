#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Moving_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Sprite.h"
#include "../include/globals.h"

#include <new>
#include <stdio.h>

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
