#include "../include/RGE_Action_Enter.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Task.h"
#include "../include/XYPoint.h"

#include <new>

namespace {
// Source of truth: stat_obj.cpp.decomp @ 0x004C5860
static uchar rge_static_object_is_dying(RGE_Static_Object* obj) {
    if ((obj != nullptr) && (2 < obj->object_state) && (obj->object_state != 6)) {
        return 1;
    }
    return 0;
}

static RGE_Action* rge_action_object_get_action(RGE_Static_Object* obj) {
    // enter action only dereferences this when target->actionState() == 0x0B (action object expected).
    if (obj == nullptr) {
        return nullptr;
    }
    RGE_Action_Object* action_obj = (RGE_Action_Object*)obj;
    if (action_obj->actions == nullptr) {
        return nullptr;
    }
    return action_obj->actions->get_action();
}
}

// Fully verified. Source of truth: act_entr.cpp.decomp @ 0x004023C0
RGE_Action_Enter::RGE_Action_Enter(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 3;
}

// Fully verified. Source of truth: act_entr.cpp.decomp @ 0x00402410
RGE_Action_Enter::RGE_Action_Enter(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->action_type = 3;
    this->task = param_2;
    this->set_target_obj(param_3);
    if (param_3 != nullptr) {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        this->target_z = param_3->world_z;

        const uchar action_state = param_3->actionState();
        if (action_state == 2) {
            const uchar has_more_room = param_3->more_room();
            const int is_computer = (this->obj != nullptr && this->obj->owner != nullptr) ? this->obj->owner->computerPlayer() : 0;
            if ((is_computer == 1) || ((has_more_room != 0) && (is_computer == 0))) {
                goto compute_tile;
            }
        } else if (action_state == 0x0B) {
            RGE_Action* cur = rge_action_object_get_action(param_3);
            if ((cur != nullptr) && (cur->target2ID == 0)) {
                goto compute_tile;
            }
        }

        if (action_state == 0x0B) {
            RGE_Action* cur = rge_action_object_get_action(param_3);
            if (cur != nullptr) {
                this->target_x = cur->target_x;
                this->target_y = cur->target_y;
            }
        }
        return;

    compute_tile: {
        XYPoint start;
        start.x = (int)param_1->world_x;
        start.y = (int)param_1->world_y;

        XYPoint dest;
        dest.x = (int)param_3->world_x;
        dest.y = (int)param_3->world_y;

        XYPoint rVal;
        rVal.x = 0;
        rVal.y = 0;

        int ok = param_1->firstTileAlongLine(&start, &dest, &rVal, 2, 2, 1);
        if (ok == 1) {
            this->target_x = (float)rVal.x + 0.5f;
            this->target_y = (float)rVal.y + 0.5f;
            param_3->moveTo((float)rVal.x, (float)rVal.y, param_3->world_z, 0.5f, 1);
        } else {
            this->target_x = param_3->world_x;
            this->target_y = param_3->world_y;
            param_3->moveTo(param_1->world_x, param_1->world_y, param_3->world_z, 0.5f, 1);
        }
        return;
    }
    }
}

RGE_Action_Enter::~RGE_Action_Enter() {}

int RGE_Action_Enter::setup(RGE_Action_Object* param_1) { return RGE_Action::setup(param_1); }
int RGE_Action_Enter::setup(int param_1, RGE_Action_Object* param_2) { return RGE_Action::setup(param_1, param_2); }
RGE_Action_List* RGE_Action_Enter::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void RGE_Action_Enter::rehook() { RGE_Action::rehook(); }
void RGE_Action_Enter::save(int param_1) { RGE_Action::save(param_1); }
short RGE_Action_Enter::type() { return this->action_type; }

// Fully verified. Source of truth: act_entr.cpp.decomp @ 0x00402600
void RGE_Action_Enter::first_in_stack(uchar /*param_1*/) {
    this->set_state(4);
}

uchar RGE_Action_Enter::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Enter::idle_update() { return RGE_Action::idle_update(); }

// Fully verified. Source of truth: act_entr.cpp.decomp @ 0x00402740
uchar RGE_Action_Enter::update() {
    RGE_Game_World* world = this->obj->owner->world;

    if ((this->targetID != -1) && (world->object(this->targetID) == nullptr)) {
        goto missing_target;
    }

    if ((this->target2ID != -1) && (world->object(this->target2ID) == nullptr)) {
        this->set_target_obj2(nullptr);
    }

    if (this->target_obj != nullptr) {
        if (this->target_obj->object_state >= 3) {
            goto missing_target;
        }

        if (this->obj->owner->isAlly((int)this->target_obj->owner->id) == 0) {
            goto missing_target;
        }
    }

    switch (this->state) {
    case 1:
        return 1;

    case 2: {
        this->timer = this->timer - this->obj->owner->world->world_time_delta_seconds;
        if (this->timer <= 0.0f) {
            float dist = this->obj->distance_to_object(this->target_obj);
            if (this->task->work_range < dist - 1.0f) {
                uchar target_action_state = this->target_obj->actionState();
                if (target_action_state != 2) {
                    if (target_action_state == 0x0B) {
                        RGE_Action* cur = rge_action_object_get_action(this->target_obj);
                        if (cur != nullptr) {
                            this->target_x = cur->target_x;
                            this->target_y = cur->target_y;
                        }
                    }
                    this->set_state(4);
                    return 0;
                }

                XYPoint start;
                start.x = (int)this->obj->world_x;
                start.y = (int)this->obj->world_y;

                XYPoint dest;
                dest.x = (int)this->target_obj->world_x;
                dest.y = (int)this->target_obj->world_y;

                XYPoint rVal;
                rVal.x = 0;
                rVal.y = 0;

                int ok = this->obj->firstTileAlongLine(&start, &dest, &rVal, 2, 2, 1);
                if (ok == 1) {
                    float x = (float)rVal.x + 0.5f;
                    float y = (float)rVal.y + 0.5f;
                    if ((this->target_x == x) && (this->target_y == y)) {
                        this->target_x = this->target_obj->world_x;
                        this->target_y = this->target_obj->world_y;
                        this->set_state(4);
                        return 0;
                    }
                    this->target_x = x;
                    this->target_y = y;
                    this->target_obj->moveTo((float)rVal.x, (float)rVal.y, this->target_obj->world_z, 0.0f, 1);
                    this->set_state(4);
                    return 0;
                }

                this->target_x = this->target_obj->world_x;
                this->target_y = this->target_obj->world_y;
                this->target_obj->moveTo(this->obj->world_x, this->obj->world_y, this->target_obj->world_z, 0.5f, 1);
                this->set_state(4);
                return 0;
            }

            this->obj->enter_obj(this->target_obj);
            goto entered;
        }
        return 0;
    }

    case 4: {
        if ((this->target_obj != nullptr) && (rge_static_object_is_dying(this->target_obj) == 0)) {
            uchar sub = this->sub_actions->update();
            switch (sub) {
            case 1:
            case 2: {
                float dist = this->obj->distance_to_object(this->target_obj);
                if (this->task->work_range < dist - 1.0f) {
                    this->set_state(2);
                    return 0;
                }
                this->obj->enter_obj(this->target_obj);
                goto entered;
            }

            case 3:
                this->set_state(2);
                return 0;

            case 4:
            case 5:
            default:
                break;
            }
        }

        this->set_target_obj(nullptr);
        this->set_state(0x0D);
        return 0;
    }

    case 0x0D: {
        int id = (int)this->obj->id;
        this->obj->notify(id, id, 0x1F9, 0x269, 0, 0);
        return 3;
    }
    }

    return 0;

entered:
    if ((char)this->subActionValue == '\0') {
        int id = (int)this->obj->id;
        this->obj->notify(id, id, 0x1FA, 0x269, 0, 0);
    }
    this->set_state(1);
    return 2;

missing_target:
    this->set_state(1);
    this->set_target_obj(nullptr);
    int id = (int)this->obj->id;
    this->obj->notify(id, id, 0x1FB, 0x269, 0, 0);
    return 4;
}

int RGE_Action_Enter::stop() { return RGE_Action::stop(); }
int RGE_Action_Enter::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int RGE_Action_Enter::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
uchar RGE_Action_Enter::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Enter::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Enter::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Enter::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void RGE_Action_Enter::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Enter::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Enter::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Enter::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Enter::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: act_entr.cpp.decomp @ 0x00402610
void RGE_Action_Enter::set_state(uchar param_1) {
    this->sub_actions->delete_list();

    this->state = param_1;

    switch (param_1) {
    case 2:
        this->timer = 1.0f;
        // fall through
    case 1:
    case 0x0D:
    case 0x0E:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    case 4:
        break;

    default:
        return;
    }

    RGE_Action_Move_To* move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z,
                                                                       this->task->work_range, this->task->move_sprite);
    if (move_to == nullptr) {
        this->set_state(0x0D);
        return;
    }

    this->sub_actions->add_action(move_to);
    move_to->setSubAction(1);
}

