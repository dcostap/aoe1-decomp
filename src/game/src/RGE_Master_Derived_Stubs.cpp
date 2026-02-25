#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Master_Missile_Object.h"
#include "../include/RGE_Master_Doppleganger_Object.h"
#include "../include/RGE_Doppleganger_Object.h"
#include "../include/RGE_Combat_Object.h"
#include "../include/RGE_Missile_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"

#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Task_List.h"
#include <new>

RGE_Master_Animated_Object::~RGE_Master_Animated_Object() {}
void RGE_Master_Animated_Object::copy_obj(RGE_Master_Static_Object* param_1) { if (param_1) this->RGE_Master_Static_Object::setup(param_1); }
void RGE_Master_Animated_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
void RGE_Master_Animated_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
void RGE_Master_Animated_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
void RGE_Master_Animated_Object::save(int param_1) { this->RGE_Master_Static_Object::save(param_1); }
RGE_Static_Object* RGE_Master_Animated_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) { return this->RGE_Master_Static_Object::make_new_obj(param_1, param_2, param_3, param_4); }
RGE_Master_Static_Object* RGE_Master_Animated_Object::make_new_master() { return this->RGE_Master_Static_Object::make_new_master(); }
uchar RGE_Master_Animated_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Animated_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Animated_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Animated_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Animated_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Animated_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }

RGE_Master_Moving_Object::~RGE_Master_Moving_Object() {}
void RGE_Master_Moving_Object::copy_obj(RGE_Master_Static_Object* param_1) { if (param_1) this->RGE_Master_Static_Object::setup(param_1); }
void RGE_Master_Moving_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
void RGE_Master_Moving_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
void RGE_Master_Moving_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
void RGE_Master_Moving_Object::save(int param_1) { this->RGE_Master_Static_Object::save(param_1); }
RGE_Static_Object* RGE_Master_Moving_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) { return this->RGE_Master_Static_Object::make_new_obj(param_1, param_2, param_3, param_4); }
RGE_Master_Static_Object* RGE_Master_Moving_Object::make_new_master() { return this->RGE_Master_Static_Object::make_new_master(); }
uchar RGE_Master_Moving_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Moving_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Moving_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Moving_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Moving_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Moving_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }

RGE_Master_Action_Object::~RGE_Master_Action_Object() {}
void RGE_Master_Action_Object::copy_obj(RGE_Master_Static_Object* param_1) { if (param_1) this->RGE_Master_Static_Object::setup(param_1); }
void RGE_Master_Action_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
void RGE_Master_Action_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
void RGE_Master_Action_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
void RGE_Master_Action_Object::save(int param_1) { this->RGE_Master_Static_Object::save(param_1); }
RGE_Static_Object* RGE_Master_Action_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) { return this->RGE_Master_Static_Object::make_new_obj(param_1, param_2, param_3, param_4); }
RGE_Master_Static_Object* RGE_Master_Action_Object::make_new_master() { return this->RGE_Master_Static_Object::make_new_master(); }
uchar RGE_Master_Action_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Action_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Action_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Action_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Action_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Action_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
RGE_Task_List* RGE_Master_Action_Object::create_task_list() { return new RGE_Task_List(); }

RGE_Master_Combat_Object::~RGE_Master_Combat_Object() {}
void RGE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* param_1) { if (param_1) this->RGE_Master_Static_Object::setup(param_1); }
void RGE_Master_Combat_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
void RGE_Master_Combat_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
void RGE_Master_Combat_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
void RGE_Master_Combat_Object::save(int param_1) { this->RGE_Master_Static_Object::save(param_1); }
RGE_Static_Object* RGE_Master_Combat_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    // Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x004506D0
    if (this->master_type != 0) {
        RGE_Static_Object* recycled = param_1->world->recycle_object_in_to_game(this->master_type);
        if (recycled != nullptr) {
            recycled->recycle_in_to_game(this, param_1, param_2, param_3, param_4);
            return recycled;
        }
    }

    RGE_Combat_Object* obj = (RGE_Combat_Object*)::operator new(sizeof(RGE_Combat_Object), std::nothrow);
    if (obj != nullptr) {
        obj = new (obj) RGE_Combat_Object(this, param_1, param_2, param_3, param_4, 1);
        return obj;
    }
    return nullptr;
}
RGE_Master_Static_Object* RGE_Master_Combat_Object::make_new_master() { return this->RGE_Master_Static_Object::make_new_master(); }
uchar RGE_Master_Combat_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Combat_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Combat_Object::calc_base_damage_ability() { return 0; }
void RGE_Master_Combat_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Combat_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Combat_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
RGE_Task_List* RGE_Master_Combat_Object::create_task_list() { return new RGE_Task_List(); }

RGE_Master_Missile_Object::~RGE_Master_Missile_Object() {}
void RGE_Master_Missile_Object::copy_obj(RGE_Master_Static_Object* param_1) { if (param_1) this->RGE_Master_Static_Object::setup(param_1); }
void RGE_Master_Missile_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
void RGE_Master_Missile_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
void RGE_Master_Missile_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
void RGE_Master_Missile_Object::save(int param_1) { this->RGE_Master_Static_Object::save(param_1); }
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
RGE_Master_Static_Object* RGE_Master_Missile_Object::make_new_master() { return this->RGE_Master_Static_Object::make_new_master(); }
uchar RGE_Master_Missile_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Missile_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Missile_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Missile_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Missile_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Missile_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
RGE_Task_List* RGE_Master_Missile_Object::create_task_list() { return new RGE_Task_List(); }

RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object() {}
void RGE_Master_Doppleganger_Object::copy_obj(RGE_Master_Static_Object* param_1) { if (param_1) this->RGE_Master_Static_Object::setup(param_1); }
void RGE_Master_Doppleganger_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
void RGE_Master_Doppleganger_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
void RGE_Master_Doppleganger_Object::modify_percent(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_percent(param_1, param_2); }
void RGE_Master_Doppleganger_Object::save(int param_1) { this->RGE_Master_Static_Object::save(param_1); }
RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) { return this->RGE_Master_Static_Object::make_new_obj(param_1, param_2, param_3, param_4); }
RGE_Master_Static_Object* RGE_Master_Doppleganger_Object::make_new_master() { return this->RGE_Master_Static_Object::make_new_master(); }
uchar RGE_Master_Doppleganger_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
uchar RGE_Master_Doppleganger_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
long RGE_Master_Doppleganger_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
void RGE_Master_Doppleganger_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
void RGE_Master_Doppleganger_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
void RGE_Master_Doppleganger_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
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
