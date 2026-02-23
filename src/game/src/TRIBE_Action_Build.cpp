#include "../include/TRIBE_Action_Build.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Task.h"

#include <new>

TRIBE_Action_Build::TRIBE_Action_Build(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x65;
}

TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->action_type = 0x65;
    this->task = param_2;
    this->set_target_obj(param_3);
    if (param_3 != nullptr) {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        this->target_z = param_3->world_z;
    }
}

TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->action_type = 0x65;
    this->task = param_2;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
}

TRIBE_Action_Build::~TRIBE_Action_Build() {}

int TRIBE_Action_Build::setup(RGE_Action_Object* param_1) {
    int res = RGE_Action::setup(param_1);
    this->action_type = 0x65;
    return res;
}

int TRIBE_Action_Build::setup(int param_1, RGE_Action_Object* param_2) {
    int res = RGE_Action::setup(param_1, param_2);
    this->action_type = 0x65;
    return res;
}

RGE_Action_List* TRIBE_Action_Build::create_action_list(RGE_Action_Object* param_1) {
    return RGE_Action::create_action_list(param_1);
}

void TRIBE_Action_Build::rehook() {
    RGE_Action::rehook();
}

void TRIBE_Action_Build::save(int param_1) {
    RGE_Action::save(param_1);
}

short TRIBE_Action_Build::type() {
    return this->action_type;
}

void TRIBE_Action_Build::first_in_stack(uchar param_1) {
    if (param_1 == 0) {
        this->set_state(3);
        return;
    }
    this->set_state((this->target_obj != nullptr) ? 4 : 3);
}

uchar TRIBE_Action_Build::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar TRIBE_Action_Build::idle_update() { return RGE_Action::idle_update(); }

void TRIBE_Action_Build::set_state(uchar param_1) {
    if (this->sub_actions != nullptr) {
        this->sub_actions->delete_list();
    }

    this->state = param_1;

    switch (param_1) {
    case 2:
        this->set_target_obj(nullptr);
        this->set_target_obj2(nullptr);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;
    case 4: {
        if ((this->sub_actions != nullptr) && (this->task != nullptr) && (this->target_obj != nullptr)) {
            RGE_Action* move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, this->task->work_range, this->task->move_sprite);
            if (move != nullptr) {
                move->setSubAction(1);
                this->sub_actions->add_action(move);
                return;
            }
        }
        this->state = 0x0d;
        return;
    }
    case 0x0b: {
        if ((this->sub_actions != nullptr) && (this->task != nullptr)) {
            RGE_Action* move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.0f, this->task->move_sprite);
            if (move != nullptr) {
                move->setSubAction(1);
                this->sub_actions->add_action(move);
                return;
            }
        }
        this->state = 0x0d;
        return;
    }
    default:
        return;
    }
}

uchar TRIBE_Action_Build::update() {
    switch (this->state) {
    case 1:
        return 1;
    case 4:
    case 0x0b:
        if ((this->sub_actions != nullptr) && (this->sub_actions->list != nullptr)) {
            uchar r = this->sub_actions->update();
            if (r == 1 || r == 2) {
                this->set_state(6);
            } else if (r == 3) {
                this->set_state(3);
            } else if (r == 4 || r == 5) {
                this->set_target_obj(nullptr);
                this->set_state(0x0b);
            }
        } else {
            this->set_state(6);
        }
        return 0;
    case 6:
        this->set_state(7);
        return 0;
    case 7:
        this->set_state(1);
        return 0;
    case 0x0d:
        this->set_state(2);
        return 3;
    default:
        return 0;
    }
}

int TRIBE_Action_Build::stop() {
    this->set_state(2);
    return 1;
}

int TRIBE_Action_Build::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_1;
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_target_obj(nullptr);
    this->set_state(0x0b);
    return 1;
}

int TRIBE_Action_Build::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (param_1 != nullptr) {
        this->set_target_obj(param_1);
        this->set_state(4);
        return 1;
    }
    return this->move_to(param_1, param_2, param_3, param_4);
}

uchar TRIBE_Action_Build::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar TRIBE_Action_Build::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void TRIBE_Action_Build::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void TRIBE_Action_Build::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void TRIBE_Action_Build::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* TRIBE_Action_Build::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* TRIBE_Action_Build::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void TRIBE_Action_Build::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void TRIBE_Action_Build::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

