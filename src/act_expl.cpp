// PDB source module: C:\\msdev\\work\\age1_x1\\act_expl.cpp.
// Definitions follow the original source order.

#include "../include/act_expl.h"
#include "../include/act_list.h"
#include "../include/act_move.h"
#include "../include/act_obj.h"
#include "../include/m_mo_obj.h"
#include "../include/stat_obj.h"
#include "../include/task.h"

RGE_Action_Explore::RGE_Action_Explore(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    this->action_type = 4;
}

RGE_Action_Explore::RGE_Action_Explore(
    RGE_Action_Object* obj,
    RGE_Task* task,
    float x,
    float y,
    float z)
    : RGE_Action(obj, 1) {
    this->task = task;
    this->action_type = 4;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}

void RGE_Action_Explore::first_in_stack(unsigned char value) {
    if (*(int*)&this->target_x == 0xBF800000) {
        set_state(3);
        return;
    }
    set_state(0x0B);
}

void RGE_Action_Explore::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        {
            int id = this->obj->id;
            this->obj->notify(id, id, 0x202, (long)0x25D, (long)0, (long)0);
        }
        goto new_sprite;

    case 2:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 11:
        break;

    case 1:
    case 13:
    case 14:
    new_sprite:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    default:
        return;
    }

    RGE_Sprite* ms;
    if ((this->task != 0) && (this->task->move_sprite != 0))
        ms = this->task->move_sprite;
    else
        ms = ((RGE_Master_Moving_Object*)this->obj->master_obj)->move_sprite;

    {
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj, this->target_x, this->target_y, this->target_z, 0.0f, ms);

        if (action == 0) {
            this->set_state(0x0D);
            return;
        }

        action->setSubAction(1);
        this->sub_actions->add_action(action);
    }
}

unsigned char RGE_Action_Explore::update(void) {
    switch (this->state) {
    case 13: {
        int id = this->obj->id;
        this->obj->notify(id, id, 0x1F9, (long)0x25D, (long)0, (long)0);
        this->set_state(2);
        return 3;
    }

    case 11:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;

        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;

        case 3:
            this->set_state(13);
            goto return_zero;
        }
        goto return_zero;

    case 1:
        goto return_one;
    }

return_zero:
    return 0;

return_one:
    return 1;
}

int RGE_Action_Explore::work(
    RGE_Static_Object* param_1,
    float param_2,
    float param_3,
    float param_4) {
    if ((param_2 < 0.0f) || (param_3 < 0.0f)) {
        this->set_state(3);
        return 1;
    }
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_state(11);
    return 1;
}
