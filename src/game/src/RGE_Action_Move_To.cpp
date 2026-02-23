#include "../include/RGE_Action_Move_To.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Static_Object.h"
#include "../include/globals.h"

// NOTE: The original AoE1/X1 move-to action relies on large parts of the pathing/moving system
// that are not fully restored in this codebase yet. This implementation keeps save/load parity
// for the action's own fields and provides a minimal state machine so TRIBE tact actions can link.

RGE_Action_Move_To::RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2) {
    this->range = 0.4f;
    RGE_Action::setup(param_1, param_2);
    this->action_type = 1;
    rge_read(param_1, &this->range, 4);
}

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, RGE_Sprite* param_4) {
    this->range = 0.4f;
    RGE_Action::setup(param_1);
    this->action_type = 1;
    this->set_target_obj(param_2);
    if (param_2 != nullptr) {
        this->target_x = param_2->world_x;
        this->target_y = param_2->world_y;
        this->target_z = param_2->world_z;
    }
    this->range = (param_3 <= 0.0f) ? 0.4f : param_3;
    this->sprite = param_4;
}

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, float param_5, RGE_Sprite* param_6) {
    this->range = 0.4f;
    RGE_Action::setup(param_1);
    this->action_type = 1;
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->range = (param_5 <= 0.0f) ? 0.4f : param_5;
    this->sprite = param_6;
}

RGE_Action_Move_To::~RGE_Action_Move_To() {
    if (this->obj != nullptr) {
        this->obj->setWaitingToMove(0);
        this->obj->stop_moving();
    }
}

int RGE_Action_Move_To::setup(RGE_Action_Object* param_1) {
    this->range = 0.4f;
    return RGE_Action::setup(param_1);
}

int RGE_Action_Move_To::setup(int param_1, RGE_Action_Object* param_2) {
    this->range = 0.4f;
    int res = RGE_Action::setup(param_1, param_2);
    rge_read(param_1, &this->range, 4);
    return res;
}

RGE_Action_List* RGE_Action_Move_To::create_action_list(RGE_Action_Object* param_1) {
    return RGE_Action::create_action_list(param_1);
}

void RGE_Action_Move_To::rehook() {
    RGE_Action::rehook();
}

void RGE_Action_Move_To::save(int param_1) {
    RGE_Action::save(param_1);
    rge_write(param_1, &this->range, 4);
}

short RGE_Action_Move_To::type() {
    return this->action_type;
}

void RGE_Action_Move_To::first_in_stack(uchar param_1) {
    (void)param_1;
    this->set_state(3);
}

uchar RGE_Action_Move_To::inside_obj_update() {
    return RGE_Action::inside_obj_update();
}

uchar RGE_Action_Move_To::idle_update() {
    return RGE_Action::idle_update();
}

uchar RGE_Action_Move_To::update() {
    // Best-effort: consider the move completed immediately.
    this->set_state(1);
    return 1;
}

int RGE_Action_Move_To::stop() {
    this->set_state(1);
    return 1;
}

int RGE_Action_Move_To::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    this->set_target_obj(param_1);
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_state(3);
    return 1;
}

int RGE_Action_Move_To::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    return this->move_to(param_1, param_2, param_3, param_4);
}

uchar RGE_Action_Move_To::attack_response(RGE_Static_Object* param_1) {
    return RGE_Action::attack_response(param_1);
}

uchar RGE_Action_Move_To::relation_response(long param_1, uchar param_2) {
    return RGE_Action::relation_response(param_1, param_2);
}

void RGE_Action_Move_To::copy_obj(RGE_Master_Action_Object* param_1) {
    RGE_Action::copy_obj(param_1);
}

void RGE_Action_Move_To::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    RGE_Action::copy_obj_sprites(param_1, param_2, param_3);
}

void RGE_Action_Move_To::get_state_name(char* param_1) {
    RGE_Action::get_state_name(param_1);
}

RGE_Static_Object* RGE_Action_Move_To::get_target_obj() {
    return RGE_Action::get_target_obj();
}

RGE_Static_Object* RGE_Action_Move_To::get_target_obj2() {
    return RGE_Action::get_target_obj2();
}

void RGE_Action_Move_To::set_target_obj(RGE_Static_Object* param_1) {
    RGE_Action::set_target_obj(param_1);
}

void RGE_Action_Move_To::set_target_obj2(RGE_Static_Object* param_1) {
    RGE_Action::set_target_obj2(param_1);
}

void RGE_Action_Move_To::set_state(uchar param_1) {
    RGE_Action::set_state(param_1);
}

