#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Animated_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/globals.h"

#include <new>
#include <stdio.h>

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
