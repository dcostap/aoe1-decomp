// TODO: STUB - minimal RGE_Action derived implementations required by RGE_Action_List factories (Make).

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Make.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Sprite.h"
#include "../include/globals.h"

#include <string.h>

// Forward everything to RGE_Action by default; override setup/save where we must preserve file layout.
#define ACTION_FORWARDING(ClassName) \
    RGE_Action_List* ClassName::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); } \
    void ClassName::rehook() { RGE_Action::rehook(); } \
    short ClassName::type() { return RGE_Action::type(); } \
    void ClassName::first_in_stack(uchar param_1) { RGE_Action::first_in_stack(param_1); } \
    uchar ClassName::inside_obj_update() { return RGE_Action::inside_obj_update(); } \
    uchar ClassName::idle_update() { return RGE_Action::idle_update(); } \
    uchar ClassName::update() { return RGE_Action::update(); } \
    int ClassName::stop() { return RGE_Action::stop(); } \
    int ClassName::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); } \
    int ClassName::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); } \
    uchar ClassName::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); } \
    uchar ClassName::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); } \
    void ClassName::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); } \
    void ClassName::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); } \
    void ClassName::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); } \
    RGE_Static_Object* ClassName::get_target_obj() { return RGE_Action::get_target_obj(); } \
    RGE_Static_Object* ClassName::get_target_obj2() { return RGE_Action::get_target_obj2(); } \
    void ClassName::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); } \
    void ClassName::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); } \
    void ClassName::set_state(uchar param_1) { RGE_Action::set_state(param_1); }

// ============================================================================
// RGE_Action_Make
// ============================================================================

// Fully verified. Source of truth: act_make.cpp.decomp @ 0x004049B0
RGE_Action_Make::RGE_Action_Make(int param_1, RGE_Action_Object* param_2) {
    this->setup(param_1, param_2);
}

RGE_Action_Make::~RGE_Action_Make() = default; // TODO: STUB

int RGE_Action_Make::setup(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 0x15;
    return 1;
}

int RGE_Action_Make::setup(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x15;
    return 1;
}

void RGE_Action_Make::save(int param_1) { RGE_Action::save(param_1); } // TODO: STUB

ACTION_FORWARDING(RGE_Action_Make)

#undef ACTION_FORWARDING

