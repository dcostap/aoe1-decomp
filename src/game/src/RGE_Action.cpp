#include "../include/RGE_Action.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Task_List.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Static_Object.h"
#include "../include/globals.h"

#include <string.h>
#include <new>

namespace {
static RGE_Action_List* action_alloc_list(RGE_Action_Object* obj) {
    return new (std::nothrow) RGE_Action_List(obj);
}
}

RGE_Action::RGE_Action() {
    this->action_type = 0;
    this->obj = nullptr;
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

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407460
RGE_Action::RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3) {
    this->targetID = -1;
    this->target2ID = -1;
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x004074C0
RGE_Action::RGE_Action(RGE_Action_Object* param_1, int param_2) {
    this->targetID = -1;
    this->target2ID = -1;
    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x004074F0
RGE_Action::~RGE_Action() {
    this->set_target_obj(nullptr);
    this->set_target_obj2(nullptr);
    if (this->sub_actions != nullptr) {
        this->sub_actions->delete_list();
        operator delete(this->sub_actions);
        this->sub_actions = nullptr;
    }
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407530
int RGE_Action::setup(int param_1, RGE_Action_Object* param_2) {
    this->action_type = 0;
    this->obj = param_2;
    this->sub_actions = this->create_action_list(param_2);

    int target_obj_id = -1;
    int target_obj2_id = -1;
    short task_id = -1;
    short sprite_id = -1;

    rge_read(param_1, &this->state, 1);
    rge_read(param_1, &target_obj_id, 4);
    this->target_obj = (target_obj_id == -1) ? nullptr : (RGE_Static_Object*)(long)target_obj_id;
    rge_read(param_1, &target_obj2_id, 4);
    this->target_obj2 = (target_obj2_id == -1) ? nullptr : (RGE_Static_Object*)(long)target_obj2_id;
    rge_read(param_1, &this->targetID, 4);
    rge_read(param_1, &this->target2ID, 4);
    rge_read(param_1, &this->target_x, 4);
    rge_read(param_1, &this->target_y, 4);
    rge_read(param_1, &this->target_z, 4);
    rge_read(param_1, &this->timer, 4);
    rge_read(param_1, &task_id, 2);
    rge_read(param_1, &this->subActionValue, 1);
    this->sub_actions->load(param_1);

    rge_read(param_1, &sprite_id, 2);
    this->sprite = nullptr;
    if (this->obj != nullptr) {
        this->sprite = ((RGE_Static_Object*)this->obj)->get_sprite_pointer(sprite_id);
    }

    this->task = nullptr;
    if ((this->obj != nullptr) && (this->obj->master_obj != nullptr) && (task_id >= 0)) {
        RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->obj->master_obj;
        if ((master->tasks != nullptr) && (task_id < master->tasks->list_num)) {
            this->task = master->tasks->list[task_id];
        }
    }

    return 1;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407680
int RGE_Action::setup(RGE_Action_Object* param_1) {
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
    this->sub_actions = this->create_action_list(param_1);
    this->sprite = nullptr;
    this->subActionValue = 0;
    return 1;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x004076D0
RGE_Action_List* RGE_Action::create_action_list(RGE_Action_Object* param_1) {
    (void)param_1;
    return action_alloc_list(this->obj);
}

void RGE_Action::rehook() {
    if ((this->obj != nullptr) && (this->target_obj != nullptr)) {
        RGE_Static_Object* hooked = ((RGE_Static_Object*)this->obj)->get_object_pointer((long)this->target_obj);
        this->target_obj = hooked;
        if (hooked != nullptr) {
            this->targetID = hooked->id;
        }
    }
    if ((this->obj != nullptr) && (this->target_obj2 != nullptr)) {
        RGE_Static_Object* hooked = ((RGE_Static_Object*)this->obj)->get_object_pointer((long)this->target_obj2);
        this->target_obj2 = hooked;
        if (hooked != nullptr) {
            this->target2ID = hooked->id;
        }
    }
    if (this->sub_actions != nullptr) {
        this->sub_actions->rehook();
    }
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407790
void RGE_Action::save(int param_1) {
    int target_obj_id = (this->target_obj != nullptr) ? this->target_obj->id : -1;
    int target_obj2_id = (this->target_obj2 != nullptr) ? this->target_obj2->id : -1;
    short task_id = (this->task != nullptr) ? this->task->id : -1;
    short sprite_id = (this->sprite != nullptr) ? this->sprite->id : -1;
    short sub_action_terminator = 0;

    rge_write(param_1, &this->action_type, 2);
    rge_write(param_1, &this->state, 1);
    rge_write(param_1, &target_obj_id, 4);
    rge_write(param_1, &target_obj2_id, 4);
    rge_write(param_1, &this->targetID, 4);
    rge_write(param_1, &this->target2ID, 4);
    rge_write(param_1, &this->target_x, 4);
    rge_write(param_1, &this->target_y, 4);
    rge_write(param_1, &this->target_z, 4);
    rge_write(param_1, &this->timer, 4);
    rge_write(param_1, &task_id, 2);
    rge_write(param_1, &this->subActionValue, 1);
    if (this->sub_actions != nullptr) {
        this->sub_actions->save(param_1);
    } else {
        rge_write(param_1, &sub_action_terminator, 2);
    }
    rge_write(param_1, &sprite_id, 2);
}

short RGE_Action::type() {
    return this->action_type;
}

void RGE_Action::first_in_stack(uchar param_1) {
    (void)param_1;
}

uchar RGE_Action::inside_obj_update() {
    if ((this->target_obj != nullptr) && (this->target_obj->object_state > 6)) {
        this->set_target_obj(nullptr);
    }
    if ((this->target_obj2 != nullptr) && (this->target_obj2->object_state > 6)) {
        this->set_target_obj2(nullptr);
    }
    return 1;
}

uchar RGE_Action::idle_update() {
    if ((this->target_obj != nullptr) && (this->target_obj->object_state > 6)) {
        this->set_target_obj(nullptr);
    }
    if ((this->target_obj2 != nullptr) && (this->target_obj2->object_state > 6)) {
        this->set_target_obj2(nullptr);
    }
    return 1;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x004079D0
uchar RGE_Action::update() {
    if ((this->target_obj != nullptr) && (this->target_obj->object_state > 6)) {
        this->set_target_obj(nullptr);
    }
    if ((this->target_obj2 != nullptr) && (this->target_obj2->object_state > 6)) {
        this->set_target_obj2(nullptr);
    }
    if ((this->sub_actions != nullptr) && (this->sub_actions->list != nullptr)) {
        return this->sub_actions->update();
    }
    return (this->state == 1) ? 1 : 0;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x004078F0
int RGE_Action::stop() {
    return 0;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407900
int RGE_Action::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407910
int RGE_Action::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407920
uchar RGE_Action::attack_response(RGE_Static_Object* param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407930
uchar RGE_Action::relation_response(long param_1, uchar param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407B00
void RGE_Action::copy_obj(RGE_Master_Action_Object* param_1) {
    RGE_Sprite* new_sprite = nullptr;
    if ((this->task == nullptr) || (param_1->tasks == nullptr)) {
        this->copy_obj_sprites(param_1, nullptr, nullptr);
        this->sub_actions->copy_obj_sprites(param_1, nullptr, nullptr);
        return;
    }

    RGE_Task** task_list = param_1->tasks->list;
    int index = param_1->tasks->list_num - 1;
    short action_type = this->task->action_type;
    while (index >= 0) {
        if (task_list[index]->action_type == action_type) {
            break;
        }
        index--;
    }

    if (index < 0) {
        return;
    }

    RGE_Task* matched_task = task_list[index];
    if (this->obj->sprite == matched_task->move_sprite) {
        new_sprite = matched_task->move_sprite;
    } else if (this->obj->sprite == matched_task->work_sprite) {
        new_sprite = matched_task->work_sprite;
    } else if (this->obj->sprite == matched_task->work_sprite2) {
        new_sprite = matched_task->work_sprite2;
    } else if (this->obj->sprite == matched_task->carry_sprite) {
        new_sprite = matched_task->carry_sprite;
    }

    if (new_sprite != nullptr) {
        this->obj->new_sprite(new_sprite);
    }

    this->copy_obj_sprites(param_1, this->task, matched_task);
    this->sub_actions->copy_obj_sprites(param_1, this->task, matched_task);
    this->task = matched_task;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407C00
void RGE_Action::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
}

void RGE_Action::get_state_name(char* param_1) {
    if (param_1 == nullptr) {
        return;
    }
    switch (this->state) {
    case 0: strncpy(param_1, "None", 5); break;
    case 1: strncpy(param_1, "Done", 5); break;
    case 2: strncpy(param_1, "Wait", 5); break;
    case 3: strncpy(param_1, "Search", 7); break;
    case 4: strncpy(param_1, "Goto", 5); break;
    case 5: strncpy(param_1, "Goto2", 6); break;
    case 6: strncpy(param_1, "Work", 5); break;
    case 7: strncpy(param_1, "Work2", 6); break;
    case 8: strncpy(param_1, "Return", 7); break;
    case 9: strncpy(param_1, "Turn", 5); break;
    case 10: strncpy(param_1, "Delay", 6); break;
    case 11: strncpy(param_1, "Move", 5); break;
    case 12: strncpy(param_1, "Attack", 7); break;
    case 13: strncpy(param_1, "Failed", 7); break;
    case 14: strncpy(param_1, "Invalidated", 11); break;
    case 15: strncpy(param_1, "MoveNoSearch", 13); break;
    default: strncpy(param_1, "Unknown", 8); break;
    }
}

RGE_Static_Object* RGE_Action::get_target_obj() {
    return this->target_obj;
}

RGE_Static_Object* RGE_Action::get_target_obj2() {
    return this->target_obj2;
}

void RGE_Action::set_target_obj(RGE_Static_Object* param_1) {
    this->target_obj = param_1;
    this->targetID = (param_1 != nullptr) ? param_1->id : -1;
}

void RGE_Action::set_target_obj2(RGE_Static_Object* param_1) {
    this->target_obj2 = param_1;
    this->target2ID = (param_1 != nullptr) ? param_1->id : -1;
}

void RGE_Action::set_state(uchar param_1) {
    this->state = param_1;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407D60
uchar RGE_Action::subAction() const {
    return this->subActionValue;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407D70
void RGE_Action::setSubAction(uchar param_1) {
    this->subActionValue = param_1;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407D30
float RGE_Action::targetX() const {
    return this->target_x;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407D40
float RGE_Action::targetY() const {
    return this->target_y;
}

// Fully verified. Source of truth: action.cpp.decomp @ 0x00407D50
float RGE_Action::targetZ() const {
    return this->target_z;
}
