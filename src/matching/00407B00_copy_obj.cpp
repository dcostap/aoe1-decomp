// RGE_Action::copy_obj
// VA: 00407B00
// The task-list lookup and sprite-owner surfaces are the binary-proven layout.

#include "../../include/action_context.h"

void RGE_Action::copy_obj(RGE_Master_Action_Object* param_1)
{
    RGE_Task_List* task_list;
    RGE_Task** task_array;
    RGE_Sprite* new_sprite = 0;
    int i;

    if (this->task != 0 && (task_list = param_1->tasks) != 0) {
        task_array = task_list->list;
        i = task_list->list_num - 1;

        while (i >= 0) {
            if (task_array[i]->action_type == this->task->action_type) {
                break;
            }
            --i;
        }

        if (i >= 0) {
            if (this->obj->sprite == task_array[i]->move_sprite) {
                new_sprite = task_array[i]->move_sprite;
            } else if (this->obj->sprite == task_array[i]->work_sprite) {
                new_sprite = task_array[i]->work_sprite;
            } else if (this->obj->sprite == task_array[i]->work_sprite2) {
                new_sprite = task_array[i]->work_sprite2;
            } else if (this->obj->sprite == task_array[i]->carry_sprite) {
                new_sprite = task_array[i]->carry_sprite;
            }

            if (new_sprite != 0) {
                this->obj->new_sprite(new_sprite);
            }

            this->copy_obj_sprites(param_1, this->task, task_array[i]);
            this->sub_actions->copy_obj_sprites(param_1, this->task, task_array[i]);
            this->task = task_array[i];
            return;
        }
    } else {
        this->copy_obj_sprites(param_1, 0, 0);
        this->sub_actions->copy_obj_sprites(param_1, 0, 0);
    }
}
