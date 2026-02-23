#include "../include/TRIBE_Action_Heal.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Task.h"
#include "../include/globals.h"

#include <new>

TRIBE_Action_Heal::TRIBE_Action_Heal(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x69;
}

TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->action_type = 0x69;
    this->task = param_2;
    this->set_target_obj(param_3);
    if (param_3 != nullptr) {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        this->target_z = param_3->world_z;
    }
}

TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->action_type = 0x69;
    this->task = param_2;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
}

TRIBE_Action_Heal::~TRIBE_Action_Heal() {}

int TRIBE_Action_Heal::setup(RGE_Action_Object* param_1) { int r = RGE_Action::setup(param_1); this->action_type = 0x69; return r; }
int TRIBE_Action_Heal::setup(int param_1, RGE_Action_Object* param_2) { int r = RGE_Action::setup(param_1, param_2); this->action_type = 0x69; return r; }
RGE_Action_List* TRIBE_Action_Heal::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void TRIBE_Action_Heal::rehook() { RGE_Action::rehook(); }
void TRIBE_Action_Heal::save(int param_1) { RGE_Action::save(param_1); }
short TRIBE_Action_Heal::type() { return this->action_type; }

void TRIBE_Action_Heal::first_in_stack(uchar param_1) {
    (void)param_1;
    this->set_state((this->target_obj != nullptr) ? 4 : 3);
}

uchar TRIBE_Action_Heal::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar TRIBE_Action_Heal::idle_update() { return RGE_Action::idle_update(); }

void TRIBE_Action_Heal::set_state(uchar param_1) {
    if (this->sub_actions != nullptr) {
        this->sub_actions->delete_list();
    }
    this->state = param_1;

    if (param_1 == 4) {
        if ((this->sub_actions != nullptr) && (this->task != nullptr) && (this->target_obj != nullptr)) {
            RGE_Action* move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, this->task->work_range, this->task->move_sprite);
            if (move != nullptr) {
                move->setSubAction(1);
                this->sub_actions->add_action(move);
                return;
            }
        }
        this->state = 0x0d;
    }
}

uchar TRIBE_Action_Heal::update() {
    if (this->state == 1) {
        return 1;
    }
    if (this->state == 4) {
        uchar r = (this->sub_actions != nullptr && this->sub_actions->list != nullptr) ? this->sub_actions->update() : 1;
        if (r == 1 || r == 2) {
            this->set_state(6);
        } else if (r == 3) {
            this->set_state(3);
        }
        return 0;
    }
    if (this->state == 6) {
        this->set_state(1);
        return 0;
    }
    if (this->state == 0x0d) {
        this->set_state(2);
        return 3;
    }
    return 0;
}

int TRIBE_Action_Heal::stop() { this->set_state(2); return 1; }
int TRIBE_Action_Heal::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int TRIBE_Action_Heal::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (param_1 != nullptr) {
        this->set_target_obj(param_1);
        this->set_state(4);
        return 1;
    }
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}
uchar TRIBE_Action_Heal::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar TRIBE_Action_Heal::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void TRIBE_Action_Heal::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void TRIBE_Action_Heal::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void TRIBE_Action_Heal::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* TRIBE_Action_Heal::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* TRIBE_Action_Heal::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void TRIBE_Action_Heal::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void TRIBE_Action_Heal::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

