#include "../include/act_make.h"
#include "../include/act_obj.h"
#include "../include/basegame.h"
#include "../include/m_ac_obj.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/stat_obj.h"
#include "../include/task.h"
#include "../include/world.h"

// PDB source: C:\\msdev\\work\\age1_x1\\ACT_make.cpp.
// Definitions follow the original source order.

// VA: 004049B0
RGE_Action_Make::RGE_Action_Make(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1)
{
    this->action_type = 0x15;
}

// VA: 00404A10
RGE_Action_Make::RGE_Action_Make(RGE_Action_Object* param_1,
                                 RGE_Task* param_2)
    : RGE_Action(param_1, 1)
{
    this->action_type = 0x15;
    this->task = param_2;
}

// VA: 00404A40
void RGE_Action_Make::first_in_stack(unsigned char)
{
    short attribute_type;

    this->set_state(6);
    attribute_type = this->task->attribute_type;
    if (attribute_type >= 0 &&
        this->obj->attribute_type_held != attribute_type) {
        this->obj->set_attribute(attribute_type, 0);
    }
}

// VA: 00404A70
void RGE_Action_Make::set_state(unsigned char param_1)
{
    this->state = param_1;
    this->timer = this->obj->owner->attributes[0x24];
}

// VA: 00404A90
unsigned char RGE_Action_Make::update()
{
    float work;
    float old_attribute_amount;

    switch (this->state) {
    case 6:
        if (this->timer <= 0.0) {
            if (this->obj->owner->attributes[0x24] > 0.0) {
                if (this->obj->attribute_amount_held <= 0.0) {
                    rge_base_game->notification(
                        0x7E, this->obj->owner->id, this->obj->id,
                        (int)this->obj->world_x, (int)this->obj->world_y);
                    this->obj->die_die_die();
                }
                return 0;
            }
        }

        work = ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate
             * this->obj->owner->world->world_time_delta_seconds;
        work *= this->task->work_val1;
        old_attribute_amount = this->obj->attribute_amount_held;

        if (this->task->work_flag) {
            this->obj->owner->add_attribute_num(
                this->task->attribute_type, work, 0);
        } else {
            this->obj->set_attribute_amount(work, 1, 1);
        }
        this->timer -= this->obj->attribute_amount_held -
                       old_attribute_amount;

        break;

    case 1:
        return 1;
    }
    return 0;
}
