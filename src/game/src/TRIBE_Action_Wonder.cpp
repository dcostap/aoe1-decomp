#include "../include/TRIBE_Action_Wonder.h"

#include "../include/RGE_Action_Object.h"

TRIBE_Action_Wonder::TRIBE_Action_Wonder(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x78;
}

TRIBE_Action_Wonder::TRIBE_Action_Wonder(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 0x78;
    this->timer = 0.0f;
}

TRIBE_Action_Wonder::~TRIBE_Action_Wonder() {
    // TODO: STUB - full parity requires tact_wnd.cpp.decomp destructor logic (victory-state bookkeeping).
}

int TRIBE_Action_Wonder::setup(RGE_Action_Object* param_1) { int r = RGE_Action::setup(param_1); this->action_type = 0x78; return r; }
int TRIBE_Action_Wonder::setup(int param_1, RGE_Action_Object* param_2) { int r = RGE_Action::setup(param_1, param_2); this->action_type = 0x78; return r; }
RGE_Action_List* TRIBE_Action_Wonder::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void TRIBE_Action_Wonder::rehook() { RGE_Action::rehook(); }
void TRIBE_Action_Wonder::save(int param_1) { RGE_Action::save(param_1); }
short TRIBE_Action_Wonder::type() { return this->action_type; }
void TRIBE_Action_Wonder::first_in_stack(uchar param_1) { (void)param_1; }
uchar TRIBE_Action_Wonder::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar TRIBE_Action_Wonder::idle_update() { return RGE_Action::idle_update(); }

uchar TRIBE_Action_Wonder::update() {
    // TODO: STUB - Wonder action implements victory countdown/state machine in tact_wnd.cpp.decomp.
    if (this->state == 1) return 1;
    return 0;
}

int TRIBE_Action_Wonder::stop() { this->set_state(2); return 1; }
int TRIBE_Action_Wonder::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int TRIBE_Action_Wonder::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
uchar TRIBE_Action_Wonder::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar TRIBE_Action_Wonder::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void TRIBE_Action_Wonder::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void TRIBE_Action_Wonder::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void TRIBE_Action_Wonder::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* TRIBE_Action_Wonder::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* TRIBE_Action_Wonder::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void TRIBE_Action_Wonder::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void TRIBE_Action_Wonder::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }
void TRIBE_Action_Wonder::set_state(uchar param_1) { RGE_Action::set_state(param_1); }

