#include "../include/act_make.h"
#include "../include/act_obj.h"
#include "../include/basegame.h"
#include "../include/m_ac_obj.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/stat_obj.h"
#include "../include/task.h"
#include "../include/world.h"


RGE_Action_Make::RGE_Action_Make(int infile, RGE_Action_Object* obj_in)
    : RGE_Action(infile, obj_in, 1) {
    this->action_type = 0x15;
}

RGE_Action_Make::RGE_Action_Make(RGE_Action_Object* obj_in, RGE_Task* task_in)
    : RGE_Action(obj_in, 1) {
    this->action_type = 0x15;
    this->task = task_in;
}

void RGE_Action_Make::first_in_stack(unsigned char first_time) {
    short attribute_type;

    this->set_state(6);
    attribute_type = this->task->attribute_type;
    if (attribute_type >= 0 &&
        this->obj->attribute_type_held != attribute_type) {
        this->obj->set_attribute(attribute_type, 0);
    }
}

void RGE_Action_Make::set_state(unsigned char new_state) {
    this->state = new_state;
    this->timer = this->obj->owner->attributes[0x24];
}

unsigned char RGE_Action_Make::update() {
    switch (this->state) {
    case 1:
        goto success;
    case 6:
        break;
    default:
        goto failure;
    }
    {
        float work;
        float pre_attribute;
        if (this->timer <= 0.0) {
            if (this->obj->owner->attributes[0x24] > 0.0) {
                if (this->obj->attribute_amount_held <= 0.0) {
                    rge_base_game->notification(0x7E, this->obj->owner->id, this->obj->id,
                                                (int)this->obj->world_x, (int)this->obj->world_y);
                    this->obj->die_die_die();
                }
                goto failure;
            }
        }

        work = ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate
             * this->obj->owner->world->world_time_delta_seconds;
        work *= this->task->work_val1;
        pre_attribute = this->obj->attribute_amount_held;

        if (this->task->work_flag) {
            this->obj->owner->add_attribute_num(this->task->attribute_type, work, 0);
        } else {
            this->obj->set_attribute_amount(work, 1, 1);
        }
        this->timer -= this->obj->attribute_amount_held - pre_attribute;
    }

failure:
    return 0;

success:
    return 1;
}
