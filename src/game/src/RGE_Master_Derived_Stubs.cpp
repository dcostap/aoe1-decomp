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

// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
static int rge_ftol(float value) {
    int result;
    __asm {
        fld value
        fistp result
    }
    return result;
}

// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x004512C0
RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object() {}
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420
void RGE_Master_Doppleganger_Object::copy_obj(RGE_Master_Static_Object* param_1) { this->RGE_Master_Animated_Object::copy_obj(param_1); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
void RGE_Master_Doppleganger_Object::modify(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify(param_1, param_2); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
void RGE_Master_Doppleganger_Object::modify_delta(float param_1, uchar param_2) { this->RGE_Master_Static_Object::modify_delta(param_1, param_2); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
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
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
uchar RGE_Master_Doppleganger_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
uchar RGE_Master_Doppleganger_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
long RGE_Master_Doppleganger_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) { return this->RGE_Master_Static_Object::calc_base_damage_ability(param_1); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
void RGE_Master_Doppleganger_Object::play_command_sound() { this->RGE_Master_Static_Object::play_command_sound(); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
void RGE_Master_Doppleganger_Object::play_move_sound() { this->RGE_Master_Static_Object::play_move_sound(); }
// Fully verified. Source of truth: m_dg_obj.cpp.decomp @ 0x00451420 (virtual forwarding/helper coverage).
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
