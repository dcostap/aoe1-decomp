#include "../include/RGE_Action_Move_To.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Player.h"
#include "../include/XYZBYTEPoint.h"
#include "../include/globals.h"

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x0040582E
// ASM shows a switch jump-table shim (MOV EDI, EDI), not a standalone callable function body.
// Fully verified. Source of truth: act_move.cpp.decomp @ 0x00405BCA
// ASM shows a switch jump-table shim (MOV EDI, EDI), not a standalone callable function body.

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x00405510
RGE_Action_Move_To::RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 1;
    rge_read(param_1, &this->range, 4);
}

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x004055A0
RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, float param_5, RGE_Sprite* param_6) {
    RGE_Action::setup(param_1);
    this->action_type = 1;

    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->range = param_5;
    this->sprite = param_6;

    if (param_5 <= 0.0f) {
        this->range = 0.4f;
    }

    if (param_6 == nullptr) {
        RGE_Master_Moving_Object* master = (this->obj != nullptr) ? (RGE_Master_Moving_Object*)this->obj->master_obj : nullptr;
        if ((master != nullptr) && (master->move_sprite != nullptr)) {
            this->sprite = master->move_sprite;
        } else if (master != nullptr) {
            this->sprite = master->sprite;
        }
    }
}

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x00405620
RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, RGE_Sprite* param_4) {
    RGE_Action::setup(param_1);
    this->action_type = 1;

    this->set_target_obj(param_2);
    if (param_2 != nullptr) {
        this->target_x = param_2->world_x;
        this->target_y = param_2->world_y;
        this->target_z = param_2->world_z;
    }

    this->range = param_3;
    this->sprite = param_4;

    if (param_3 <= 0.0f) {
        this->range = 0.4f;
    }

    if (param_4 == nullptr) {
        RGE_Master_Moving_Object* master = (this->obj != nullptr) ? (RGE_Master_Moving_Object*)this->obj->master_obj : nullptr;
        if ((master != nullptr) && (master->move_sprite != nullptr)) {
            this->sprite = master->move_sprite;
        } else if (master != nullptr) {
            this->sprite = master->sprite;
        }
    }
}

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x004056E0
RGE_Action_Move_To::~RGE_Action_Move_To() {
    if (this->obj != nullptr) {
        this->obj->removeAllUserDefinedWaypoints(0);
        this->obj->stop_moving();
    }
}

int RGE_Action_Move_To::setup(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 1;
    this->range = 0.4f;
    return 1;
}

int RGE_Action_Move_To::setup(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 1;
    rge_read(param_1, &this->range, 4);
    return 1;
}

RGE_Action_List* RGE_Action_Move_To::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void RGE_Action_Move_To::rehook() { RGE_Action::rehook(); }
short RGE_Action_Move_To::type() { return RGE_Action::type(); }
uchar RGE_Action_Move_To::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Move_To::idle_update() { return RGE_Action::idle_update(); }
int RGE_Action_Move_To::stop() { return RGE_Action::stop(); }
int RGE_Action_Move_To::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int RGE_Action_Move_To::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
uchar RGE_Action_Move_To::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Move_To::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Move_To::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Move_To::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void RGE_Action_Move_To::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Move_To::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Move_To::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Move_To::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Move_To::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x00405750
void RGE_Action_Move_To::save(int param_1) {
    RGE_Action::save(param_1);
    rge_write(param_1, &this->range, 4);
}

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x00405780
void RGE_Action_Move_To::first_in_stack(uchar /*param_1*/) {
    if ((this->target_obj != nullptr) && (this->obj != nullptr)) {
        if (this->obj->inRange(this->target_obj, this->range) != 0) {
            this->set_state(1);
            return;
        }
    }

    float max_speed = (this->obj != nullptr) ? this->obj->maximumSpeed() : 0.0f;
    if (max_speed == 0.0f) {
        this->set_state(0x0D);
    } else {
        this->set_state(3);
    }
}

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x004057E0
void RGE_Action_Move_To::set_state(uchar param_1) {
    this->state = param_1;
    switch (param_1) {
    case 1:
    case 0x0D:
    case 0x0E:
        if ((char)this->subActionValue == '\0') {
            if ((this->obj != nullptr) && (this->obj->master_obj != nullptr)) {
                this->obj->new_sprite(this->obj->master_obj->sprite);
            }
        }
        break;
    case 4:
        if (this->obj != nullptr) {
            this->obj->new_sprite(this->sprite);
        }
        return;
    }
}

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x00405850
uchar RGE_Action_Move_To::update() {
    if (this->obj == nullptr) {
        return 0;
    }

    RGE_Game_World* world = (this->obj->owner != nullptr) ? this->obj->owner->world : nullptr;
    int missing_id = -1;

    if ((this->targetID != -1) && (world != nullptr) && (world->object(this->targetID) == nullptr)) {
        missing_id = this->targetID;
        this->set_target_obj(nullptr);
        goto missing_target;
    }

    if ((this->target2ID != -1) && (world != nullptr) && (world->object(this->target2ID) == nullptr)) {
        this->set_target_obj2(nullptr);
    }

    if ((this->target_obj != nullptr) && (this->target_obj->object_state > 6)) {
        missing_id = this->targetID;
        this->set_target_obj(nullptr);
        goto missing_target;
    }

    switch (this->state) {
    case 1:
        return 1;

    case 3: {
        if ((this->target_obj != nullptr) && (this->obj->inRange(this->target_obj, this->range) != 0)) {
            this->set_state(1);
            if ((char)this->subActionValue == '\0') {
                int id = (int)this->obj->id;
                this->obj->notify(id, id, 0x1FA, 0x262, 0, 0);
            }
            this->obj->setWaitingToMove(0);
            this->obj->pathingGroupMembers.numberValue = 0;
            return 2;
        }

        if (this->target_obj != nullptr) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }

        this->obj->setGoal(this->target_x, this->target_y, 1.0f);

        XYZBYTEPoint wp;
        wp.x = (uchar)(int)this->target_x;
        wp.y = (uchar)(int)this->target_y;
        wp.z = (uchar)(int)this->target_z;

        if ((char)this->obj->storePathInExceptionPath == '\0') {
            this->obj->addUserDefinedWaypoint(&wp, 0);
            this->obj->setFinalUserDefinedWaypoint();
        }

        this->obj->setActionRange(this->range);
        if (this->target_obj == nullptr) {
            this->obj->setTargetID(-1);
            this->obj->setTargetRadius(0.0f, 0.0f);
        } else {
            this->obj->setTargetID((int)this->target_obj->id);
            RGE_Master_Static_Object* master = this->target_obj->master_obj;
            float rx = (master != nullptr) ? master->radius_x : 0.0f;
            float ry = (master != nullptr) ? master->radius_y : 0.0f;
            this->obj->setTargetRadius(rx, ry);
        }

        if (this->obj->findPath() == RGE_Moving_Object::PathFound) {
            this->set_state(4);
            return 0;
        }
        return 0;
    }

    case 4: {
        if (this->target_obj != nullptr) {
            float dx = this->target_x - this->target_obj->world_x;
            float dy = this->target_y - this->target_obj->world_y;
            if ((((dx < -1.0f) || (dx > 1.0f)) || (dy < -1.0f)) || (dy > 1.0f)) {
                goto target_moved;
            }
        }

        int move_result = this->obj->doMove();
        if (move_result == 0) {
            this->set_state(1);
            goto move_failed;
        }

        if (move_result == 2) {
            if (this->target_obj != nullptr) {
                float dx = this->target_x - this->target_obj->world_x;
                float dy = this->target_y - this->target_obj->world_y;
                if (((dx < -1.0f) || (dx > 1.0f)) || ((dy < -1.0f) || (dy > 1.0f))) {
                    goto target_moved;
                }
            }

            if ((char)this->subActionValue == '\0') {
                int id = (int)this->obj->id;
                this->obj->notify(id, id, 0x1FA, 0x262, 0, 0);
            }
            this->set_state(1);
            return 2;
        }
        return 0;
    }

    case 0x0D:
    move_failed:
        if ((char)this->subActionValue == '\0') {
            int id = (int)this->obj->id;
            this->obj->notify(id, id, 0x1F9, 0x262, 0, 0);
        }
        return 3;
    }

    return 0;

missing_target:
    if (this->state == 1) {
        return 5;
    }
    this->obj->notify((int)this->obj->id, (int)this->obj->id, 0x1FB, 0x262, missing_id, 0);
    return 4;

target_moved:
    this->obj->notify((int)this->obj->id, (int)this->obj->id, 0x1FC, 0, 0, 0);
    this->set_state(3);
    this->update();
    this->update();
    return 0;
}

// Fully verified. Source of truth: act_move.cpp.decomp @ 0x00405BF0
uchar RGE_Action_Move_To::is_in_range() {
    if (this->obj == nullptr) {
        return 0;
    }

    if (this->range <= 0.0f) {
        if (this->target_obj != nullptr) {
            if (this->obj->inRange(this->target_obj, 0.25f) != 0) {
                return 1;
            }
        }
    } else {
        float dist = 0.0f;
        if (this->target_obj != nullptr) {
            dist = this->obj->distance_to_object(this->target_obj);
        } else {
            dist = this->obj->distance_to_position(this->target_x, this->target_y, this->target_z);
        }

        if (dist <= this->range) {
            return 1;
        }
    }

    return 0;
}

