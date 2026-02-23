#include "../include/TRIBE_Action.h"

#include "../include/TRIBE_Action_List.h"

#include <new>

// Source of truth: taction.cpp.decomp @ 0x004D38E0
TRIBE_Action::TRIBE_Action(int param_1, RGE_Action_Object* param_2, int param_3) {
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    } else {
        this->action_type = 0;
        this->obj = param_2;
        this->state = 0;
        this->target_obj = nullptr;
        this->target_obj2 = nullptr;
        this->targetID = -1;
        this->target2ID = -1;
        this->target_x = 0.0f;
        this->target_y = 0.0f;
        this->target_z = 0.0f;
        this->timer = 0.0f;
        this->task = nullptr;
        this->sub_actions = nullptr;
        this->sprite = nullptr;
        this->subActionValue = 0;
    }
}

// Source of truth: taction.cpp.decomp @ 0x004D3980
TRIBE_Action::TRIBE_Action(RGE_Action_Object* param_1, int param_2) {
    if (param_2 != 0) {
        this->setup(param_1);
    } else {
        this->action_type = 0;
        this->obj = param_1;
        this->state = 0;
        this->target_obj = nullptr;
        this->target_obj2 = nullptr;
        this->targetID = -1;
        this->target2ID = -1;
        this->target_x = 0.0f;
        this->target_y = 0.0f;
        this->target_z = 0.0f;
        this->timer = 0.0f;
        this->task = nullptr;
        this->sub_actions = nullptr;
        this->sprite = nullptr;
        this->subActionValue = 0;
    }
}

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

void TRIBE_Action::rehook() { RGE_Action::rehook(); }
void TRIBE_Action::save(int param_1) { RGE_Action::save(param_1); }
short TRIBE_Action::type() { return RGE_Action::type(); }
void TRIBE_Action::first_in_stack(uchar param_1) { RGE_Action::first_in_stack(param_1); }
uchar TRIBE_Action::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar TRIBE_Action::idle_update() { return RGE_Action::idle_update(); }
uchar TRIBE_Action::update() { return RGE_Action::update(); }
int TRIBE_Action::stop() { return RGE_Action::stop(); }
int TRIBE_Action::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int TRIBE_Action::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
uchar TRIBE_Action::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar TRIBE_Action::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void TRIBE_Action::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void TRIBE_Action::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void TRIBE_Action::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* TRIBE_Action::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* TRIBE_Action::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void TRIBE_Action::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void TRIBE_Action::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }
void TRIBE_Action::set_state(uchar param_1) { RGE_Action::set_state(param_1); }

