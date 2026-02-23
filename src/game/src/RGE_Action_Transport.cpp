#include "../include/RGE_Action_Transport.h"

#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Static_Object.h"

// TODO: STUB - minimal Transport action shell. Full parity requires act_tran.cpp.decomp transliteration.

RGE_Action_Transport::RGE_Action_Transport(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x0c;
}

RGE_Action_Transport::RGE_Action_Transport(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->action_type = 0x0c;
    this->task = param_2;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
}

RGE_Action_Transport::~RGE_Action_Transport() {}

int RGE_Action_Transport::setup(RGE_Action_Object* param_1) { return RGE_Action::setup(param_1); }
int RGE_Action_Transport::setup(int param_1, RGE_Action_Object* param_2) { return RGE_Action::setup(param_1, param_2); }
RGE_Action_List* RGE_Action_Transport::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void RGE_Action_Transport::rehook() { RGE_Action::rehook(); }
void RGE_Action_Transport::save(int param_1) { RGE_Action::save(param_1); }
short RGE_Action_Transport::type() { return this->action_type; }
void RGE_Action_Transport::first_in_stack(uchar param_1) { (void)param_1; }
uchar RGE_Action_Transport::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Transport::idle_update() { return RGE_Action::idle_update(); }
uchar RGE_Action_Transport::update() { this->set_state(1); return 1; }
int RGE_Action_Transport::stop() { this->set_state(1); return 1; }
int RGE_Action_Transport::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int RGE_Action_Transport::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
uchar RGE_Action_Transport::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Transport::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Transport::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Transport::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void RGE_Action_Transport::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Transport::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Transport::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Transport::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Transport::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }
void RGE_Action_Transport::set_state(uchar param_1) { RGE_Action::set_state(param_1); }

int RGE_Action_Transport::next_to_drop_off_terrain() {
    return 0;
}

