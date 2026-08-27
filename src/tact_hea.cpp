// Authentic PDB-ordered source module for C:\\msdev\\work\\age1_x1\\tact_hea.cpp.
// The seven normal owners follow the original source-line and address order.

#include "../include/tact_hea.h"

// The owner header stays small. These canonical class surfaces belong to this
// translation unit because the bodies dereference their members and call them.
#include "../include/act_move.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/move_obj.h"
#include "../include/t_c_obj.h"
#include "../include/t_b_obj.h"
#include "../include/task.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/sound.h"

// 004CE930 TRIBE_Action_Heal::TRIBE_Action_Heal(int, RGE_Action_Object*)
TRIBE_Action_Heal::TRIBE_Action_Heal(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1) {
    this->action_type = 0x69;
}

// 004CE990 TRIBE_Action_Heal::TRIBE_Action_Heal(
//     RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)
TRIBE_Action_Heal::TRIBE_Action_Heal(
    RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(obj, 1) {
    this->task = task;
    this->action_type = 0x69;
    set_target_obj(target);
    target_x = target->world_x;
    target_y = target->world_y;
    target_z = target->world_z;
}

// 004CEA10 TRIBE_Action_Heal::TRIBE_Action_Heal(
//     RGE_Action_Object*, RGE_Task*, float, float, float)
TRIBE_Action_Heal::TRIBE_Action_Heal(
    RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z)
    : RGE_Action(obj, 1) {
    this->task = task;
    this->action_type = 0x69;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}

// 004CEA50 TRIBE_Action_Heal::first_in_stack(unsigned char)
void TRIBE_Action_Heal::first_in_stack(unsigned char) {
    if (this->target_obj != 0) {
        short kind = this->target_obj->master_obj->object_group;
        if (kind == 0x15 || kind == 2 || kind == 0x14 || kind == 0x16) {
            return;
        }
        this->set_state(4);
        return;
    }
    this->set_state(3);
}

// 004CEA90 TRIBE_Action_Heal::set_state(unsigned char)
void TRIBE_Action_Heal::set_state(unsigned char state) {
    this->sub_actions->delete_list();
    this->state = state;

    switch (state) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x202, 0x25B, 0, 0);
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    case 2:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    case 11: {
        RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            0.0f,
            this->task->move_sprite);
        if (move_to == 0) {
            this->set_state(0x0D);
            return;
        }
        move_to->setSubAction(1);
        this->sub_actions->add_action(move_to);
        return;
    }

    case 4: {
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            0.4f,
            this->task->move_sprite);
        if (move_to == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;
    }

    case 6:
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        this->obj->new_sprite(this->task->move_sprite);
        return;

    case 7:
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0)
            this->task->work_sound->play(1);
        return;

    default:
        return;
    }
}

// 004CECF0 TRIBE_Action_Heal::update()
extern float DAT_005750e0;
extern double DAT_005750e8;

unsigned char TRIBE_Action_Heal::update() {
    float work;

    if (this->targetID != -1 &&
        this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        this->set_state(3);
        return 0;
    }

    if (this->target2ID != -1 &&
        this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state != 2) {
        this->set_target_obj(0);
        this->set_state(3);
        return 0;
    }

    if (this->target_obj != 0 &&
        this->obj->owner->isAlly(this->target_obj->owner->id) == 0) {
        this->set_state(1);
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1FB, 0x25B, 0, 0);
        return 4;
    }

    switch (this->state) {
    case 0x0B:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        case 3:
            this->set_state(0x0D);
            return 0;
        case 4:
            this->set_target_obj(0);
            this->set_state(0x0B);
            return 0;
        }
        break;

    case 4:
        switch (this->sub_actions->update()) {
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(0x0B);
            return 0;
        case 3:
            this->set_state(0x0D);
            return 0;
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        }
        break;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0.0f, 0.0f) != 0) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }

        if (this->target_obj->world_x != this->target_x ||
            this->target_y != this->target_obj->world_y) {
            float distance = this->obj->distance_to_object(this->target_obj);
            if (this->task->work_range < distance && DAT_005750e8 < distance) {
                this->set_state(3);
                return 0;
            }
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            return 0;
        }

        work = this->task->work_val1 *
               ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate;
        work *= this->obj->owner->world->world_time_delta_seconds;
        if (this->obj->owner->attributes[0x38] > DAT_005750e0) {
            work *= this->obj->owner->attributes[0x38];
        }

        unsigned char result = this->target_obj->heal(work);
        if (result == 1) {
            this->set_state(3);
            return 0;
        }
        if (result == 2) {
            this->obj->notify(this->obj->id, this->obj->id,
                              0x1FB, 0x25B, 0, 0);
            this->set_state(2);
            return 0;
        }
        break;
    }

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1F9, 0x25B, 0, 0);
        this->set_state(2);
        return 3;
    }

    return 0;
}

// 004CF030 TRIBE_Action_Heal::work(
//     RGE_Static_Object*, float, float, float)
int TRIBE_Action_Heal::work(RGE_Static_Object* target, float, float, float) {
    if (target != 0) {
        if (target == this->target_obj) {
            unsigned char state = this->state;
            if (state == 4 || state == 6 || state == 7)
                return 1;
        }
        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->first_in_stack(1);
        return 1;
    }
    return 0;
}
