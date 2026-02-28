#include "../include/RGE_Action_Explore.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Task.h"

#include <new>

// Fully verified. Source of truth: act_expl.cpp.decomp @ 0x00402B40
RGE_Action_Explore::RGE_Action_Explore(int param_1, RGE_Action_Object* param_2) {
    this->setup(param_1, param_2);
}

// Fully verified. Source of truth: act_expl.cpp.decomp @ 0x00402BA0
RGE_Action_Explore::RGE_Action_Explore(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5)
    : RGE_Action(param_1, 1) {
    this->action_type = 4;
    this->task = param_2;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
}

RGE_Action_Explore::~RGE_Action_Explore() = default;

int RGE_Action_Explore::setup(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 4;
    return 1;
}

int RGE_Action_Explore::setup(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 4;
    return 1;
}

RGE_Action_List* RGE_Action_Explore::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void RGE_Action_Explore::rehook() { RGE_Action::rehook(); }
void RGE_Action_Explore::save(int param_1) { RGE_Action::save(param_1); }
short RGE_Action_Explore::type() { return RGE_Action::type(); }
uchar RGE_Action_Explore::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Explore::idle_update() { return RGE_Action::idle_update(); }
int RGE_Action_Explore::stop() { return RGE_Action::stop(); }
int RGE_Action_Explore::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
uchar RGE_Action_Explore::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Explore::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Explore::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Explore::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void RGE_Action_Explore::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Explore::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Explore::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Explore::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Explore::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: act_expl.cpp.decomp @ 0x00402BE0
void RGE_Action_Explore::first_in_stack(uchar /*param_1*/) {
    if (this->target_x == -1.0f) {
        this->set_state(3);
        return;
    }
    this->set_state(0x0B);
}

// Fully verified. Source of truth: act_expl.cpp.decomp @ 0x00402C00
void RGE_Action_Explore::set_state(uchar param_1) {
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 2: {
        if ((this->obj != nullptr) && (this->obj->master_obj != nullptr)) {
            this->obj->new_sprite(this->obj->master_obj->sprite);
        }
        this->set_target_obj(nullptr);
        this->set_target_obj2(nullptr);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;
    }

    case 3: {
        int id = (this->obj != nullptr) ? (int)this->obj->id : 0;
        if (this->obj != nullptr) {
            this->obj->notify(id, id, 0x202, 0x25D, 0, 0);
        }
        // fallthrough
    }

    case 1:
    case 0x0D:
    case 0x0E:
        if ((this->obj != nullptr) && (this->obj->master_obj != nullptr)) {
            this->obj->new_sprite(this->obj->master_obj->sprite);
        }
        return;

    default:
        return;

    case 0x0B:
        break;
    }

    RGE_Sprite* move_sprite = (this->task != nullptr) ? this->task->move_sprite : nullptr;
    if (move_sprite == nullptr) {
        RGE_Master_Moving_Object* master = (this->obj != nullptr) ? (RGE_Master_Moving_Object*)this->obj->master_obj : nullptr;
        move_sprite = (master != nullptr) ? master->move_sprite : nullptr;
    }

    RGE_Action_Move_To* move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.0f, move_sprite);
    if (move_to == nullptr) {
        this->set_state(0x0D);
        return;
    }

    move_to->subActionValue = 1;
    this->sub_actions->add_action(move_to);
}

// Fully verified. Source of truth: act_expl.cpp.decomp @ 0x00402D90
uchar RGE_Action_Explore::update() {
    char cur_state = (char)this->state;
    if (cur_state == 1) {
        return 1;
    }

    if (cur_state == 0x0B) {
        uchar result = this->sub_actions->update();
        switch (result) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        case 3:
            this->set_state(0x0D);
            break;
        case 4:
            this->set_target_obj(nullptr);
            this->set_state(0x0B);
            return 0;
        }
    } else if (cur_state == 0x0D) {
        int id = (this->obj != nullptr) ? (int)this->obj->id : 0;
        if (this->obj != nullptr) {
            this->obj->notify(id, id, 0x1F9, 0x25D, 0, 0);
        }
        this->set_state(2);
        return 3;
    }

    return 0;
}

// Fully verified. Source of truth: act_expl.cpp.decomp @ 0x00402E40
int RGE_Action_Explore::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_1;
    if ((0.0f <= param_2) && (0.0f <= param_3)) {
        this->target_x = param_2;
        this->target_y = param_3;
        this->target_z = param_4;
        this->set_state(0x0B);
        return 1;
    }
    this->set_state(3);
    return 1;
}

