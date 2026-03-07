#include "../include/TRIBE_Action.h"

#include "../include/TRIBE_Action_List.h"

#include <new>

// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D38E0, taction.cpp.asm @ 0x004D38E0
TRIBE_Action::TRIBE_Action(int param_1, RGE_Action_Object* param_2, int param_3)
    : RGE_Action(param_1, param_2, 0) {
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3980, taction.cpp.asm @ 0x004D3980
TRIBE_Action::TRIBE_Action(RGE_Action_Object* param_1, int param_2)
    : RGE_Action(param_1, 0) {
    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Marker reconciliation coverage.
TRIBE_Action::~TRIBE_Action() {}

// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D39E0
int TRIBE_Action::setup(int param_1, RGE_Action_Object* param_2) {
    return RGE_Action::setup(param_1, param_2);
}

// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A00
int TRIBE_Action::setup(RGE_Action_Object* param_1) {
    return RGE_Action::setup(param_1);
}

// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10
RGE_Action_List* TRIBE_Action::create_action_list(RGE_Action_Object* param_1) {
    (void)param_1;
    return new (std::nothrow) TRIBE_Action_List(this->obj);
}

// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
void TRIBE_Action::rehook() { RGE_Action::rehook(); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
void TRIBE_Action::save(int param_1) { RGE_Action::save(param_1); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
short TRIBE_Action::type() { return RGE_Action::type(); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
void TRIBE_Action::first_in_stack(uchar param_1) { RGE_Action::first_in_stack(param_1); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
uchar TRIBE_Action::inside_obj_update() { return RGE_Action::inside_obj_update(); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
uchar TRIBE_Action::idle_update() { return RGE_Action::idle_update(); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
uchar TRIBE_Action::update() { return RGE_Action::update(); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
int TRIBE_Action::stop() { return RGE_Action::stop(); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
int TRIBE_Action::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
int TRIBE_Action::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
uchar TRIBE_Action::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
uchar TRIBE_Action::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
void TRIBE_Action::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
void TRIBE_Action::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
void TRIBE_Action::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
RGE_Static_Object* TRIBE_Action::get_target_obj() { return RGE_Action::get_target_obj(); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
RGE_Static_Object* TRIBE_Action::get_target_obj2() { return RGE_Action::get_target_obj2(); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
void TRIBE_Action::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
void TRIBE_Action::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }
// Fully verified. Source of truth: taction.cpp.decomp @ 0x004D3A10 (virtual forwarding coverage).
void TRIBE_Action::set_state(uchar param_1) { RGE_Action::set_state(param_1); }


