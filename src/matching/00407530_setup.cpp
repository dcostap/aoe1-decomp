// RGE_Action::setup
// VA: 00407530
// PDB: action.cpp:73-121
// No EH framing
// The task-list and direct sprite surfaces are the binary-proven owners.

#include "../../include/action_context.h"
#include "../../include/game_globals.h"

void rge_read(int handle, void* buf, int size);

int RGE_Action::setup(int param_1, RGE_Action_Object* param_2)
{
    short short_val;
    int int_val;

    this->action_type = 0;
    this->obj = param_2;
    this->sub_actions = (RGE_Action_List*)this->create_action_list(param_2);

    rge_read(param_1, &this->state, 1);

    rge_read(param_1, &int_val, 4);
    if (int_val == -1) {
        this->target_obj = 0;
    } else {
        this->target_obj = (RGE_Static_Object*)int_val;
    }

    rge_read(param_1, &int_val, 4);
    if (int_val == -1) {
        this->target_obj2 = 0;
    } else {
        this->target_obj2 = (RGE_Static_Object*)int_val;
    }

    rge_read(param_1, &this->targetID, 4);
    rge_read(param_1, &this->target2ID, 4);
    rge_read(param_1, &this->target_x, 4);
    rge_read(param_1, &this->target_y, 4);
    rge_read(param_1, &this->target_z, 4);
    rge_read(param_1, &this->timer, 4);

    rge_read(param_1, &short_val, 2);
    if (short_val == -1) {
        this->task = 0;
    } else {
        RGE_Task_List* task_list = this->obj->master_obj->tasks;
        this->task = task_list->list[short_val];
    }

    rge_read(param_1, &this->subActionValue, 1);

    this->sub_actions->load(param_1);

    rge_read(param_1, &short_val, 2);
    this->sprite = ((RGE_Static_Object*)this->obj)->get_sprite_pointer(short_val);

    return 1;
}
