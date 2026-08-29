
#include <stdio.h>
#include <string.h>

#include "../include/action.h"
#include "../include/rge_fio.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/task_lst.h"
#include "../include/sprite.h"
#include "../include/stat_obj.h"
#include "../include/player.h"
#include "../include/world.h"

RGE_Action::RGE_Action(int mode, RGE_Action_Object* object, int doSetup) {
    this->targetID = -1;
    this->target2ID = -1;
    if (doSetup != 0) {
        this->setup(mode, object);
    }
}

RGE_Action::RGE_Action(RGE_Action_Object* object, int do_setup) {
    this->targetID = -1;
    this->target2ID = -1;
    if (do_setup) {
        setup(object);
    }
}

RGE_Action::~RGE_Action() {
    RGE_Action_List* action_list;

    this->set_target_obj((RGE_Static_Object*)0);
    this->set_target_obj2((RGE_Static_Object*)0);
    action_list = this->sub_actions;
    if (action_list != 0) {
        delete action_list;
        this->sub_actions = 0;
    }
}

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
        // Action-master task data starts at +0xD8.
        RGE_Master_Action_Object* action_master =
            (RGE_Master_Action_Object*)this->obj->master_obj;
        RGE_Task_List* task_list = action_master->tasks;
        this->task = task_list->list[short_val];
    }

    rge_read(param_1, &this->subActionValue, 1);

    this->sub_actions->load(param_1);

    rge_read(param_1, &short_val, 2);
    this->sprite = ((RGE_Static_Object*)this->obj)->get_sprite_pointer(short_val);

    return 1;
}

int RGE_Action::setup(RGE_Action_Object* action_object) {
    this->action_type = 0;
    this->obj = action_object;
    this->state = 0;
    this->target_obj = 0;
    this->target_obj2 = 0;
    this->target_x = 0.0f;
    this->target_y = 0.0f;
    this->target_z = 0.0f;
    this->timer = 0.0f;
    this->task = 0;
    this->sub_actions = this->create_action_list(action_object);
    this->sprite = 0;
    this->subActionValue = 0;
    return 1;
}

RGE_Action_List* RGE_Action::create_action_list(RGE_Action_Object*) {
    return new RGE_Action_List(this->obj);
}

void RGE_Action::rehook(void) {
    if (this->target_obj != 0) {
        this->target_obj = ((RGE_Static_Object*)this->obj)->get_object_pointer((int)this->target_obj);
        if (this->target_obj != 0) {
            this->targetID = this->target_obj->id;
        }
    }
    if (this->target_obj2 != 0) {
        this->target_obj2 = ((RGE_Static_Object*)this->obj)->get_object_pointer((int)this->target_obj2);
        if (this->target_obj2 != 0) {
            this->target2ID = this->target_obj2->id;
        }
    }
    if (this->sub_actions != 0) {
        this->sub_actions->rehook();
    }
}

void RGE_Action::save(int param_1)
{
    // Two locals preserve the original 8-byte local window.
    int id_write;
    short short_write;

    rge_write(param_1, &this->action_type, 2);
    rge_write(param_1, &this->state, 1);

    if (!this->target_obj) {
        id_write = -1;
    } else {
        id_write = this->target_obj->id;
    }
    rge_write(param_1, &id_write, 4);

    if (!this->target_obj2) {
        id_write = -1;
    } else {
        id_write = this->target_obj2->id;
    }
    rge_write(param_1, &id_write, 4);

    rge_write(param_1, &this->targetID, 4);
    rge_write(param_1, &this->target2ID, 4);
    rge_write(param_1, &this->target_x, 4);
    rge_write(param_1, &this->target_y, 4);
    rge_write(param_1, &this->target_z, 4);
    rge_write(param_1, &this->timer, 4);

    if (!this->task) {
        short_write = -1;
    } else {
        short_write = this->task->id;
    }
    rge_write(param_1, &short_write, 2);

    rge_write(param_1, &this->subActionValue, 1);

    this->sub_actions->save(param_1);

    if (!this->sprite) {
        short_write = -1;
    } else {
        short_write = this->sprite->id;
    }
    rge_write(param_1, &short_write, 2);
}

short RGE_Action::type() {
    return this->action_type;
}

void RGE_Action::first_in_stack(unsigned char)
{
}

int RGE_Action::stop() {
    return 0;
}

int RGE_Action::move_to(RGE_Static_Object *, float, float, float) {
    return 0;
}

int RGE_Action::work(RGE_Static_Object *, float, float, float) {
    return 0;
}

unsigned char RGE_Action::attack_response(RGE_Static_Object *) {
    return 0;
}

unsigned char RGE_Action::relation_response(long, unsigned char) {
    return 0;
}

void RGE_Action::set_state(unsigned char param_1) {
    this->state = param_1;
}

unsigned char RGE_Action::inside_obj_update()
{
    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj((RGE_Static_Object*)0);
    }
    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7) {
        this->set_target_obj2((RGE_Static_Object*)0);
    }
    return 1;
}

unsigned char RGE_Action::idle_update()
{
    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj((RGE_Static_Object*)0);
    }
    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7) {
        this->set_target_obj2((RGE_Static_Object*)0);
    }
    return 1;
}

unsigned char RGE_Action::update()
{
    if (this->target_obj != 0 && this->target_obj->object_state >= 7)
        this->set_target_obj((RGE_Static_Object*)0);

    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7)
        this->set_target_obj2((RGE_Static_Object*)0);

    if (this->sub_actions->list != 0)
        return this->sub_actions->update();

    if (this->state != 1)
        return 0;

    return 1;
}

void RGE_Action::set_target_obj(RGE_Static_Object* param_1) {
    if (this->target_obj != 0 && this->target_obj != param_1) {
        RGE_Static_Object* previous = this->obj->owner->world->object(this->targetID);
        if (previous != 0) {
            previous->release_being_worked_on(this->obj);
        }
    }

    if (this->target_obj != param_1) {
        this->target_obj = param_1;
        if (param_1 != 0) {
            this->targetID = param_1->id;
            param_1->set_being_worked_on(this->obj, this->action_type, 0);
            return;
        }
        this->targetID = -1;
    }
}

void RGE_Action::set_target_obj2(RGE_Static_Object* target)
{
    if (this->target_obj2 && this->target_obj2 != target) {
        RGE_Game_World* world = this->obj->owner->world;
        RGE_Static_Object* old_target = world->object(this->target2ID);
        if (old_target) {
            old_target->release_being_worked_on(this->obj);
        }
    }

    if (this->target_obj2 != target) {
        this->target_obj2 = target;
        if (target) {
            this->target2ID = target->id;
            target->set_being_worked_on(this->obj, this->action_type, 0);
        } else {
            this->target2ID = -1;
        }
    }
}

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

void RGE_Action::copy_obj_sprites(RGE_Master_Action_Object *, RGE_Task *, RGE_Task *) {
}

void RGE_Action::get_state_name(char* buf)
{
    switch (this->state) {
    case 0:
        strcpy(buf, "None");
        return;
    case 1:
        strcpy(buf, "Done");
        return;
    case 2:
        strcpy(buf, "Wait");
        return;
    case 3:
        strcpy(buf, "Search");
        return;
    case 4:
        strcpy(buf, "Goto");
        return;
    case 5:
        strcpy(buf, "Goto2");
        return;
    case 6:
        strcpy(buf, "Work");
        return;
    case 7:
        strcpy(buf, "Work2");
        return;
    case 8:
        strcpy(buf, "Return");
        return;
    case 9:
        strcpy(buf, "Turn");
        return;
    case 10:
        strcpy(buf, "Delay");
        return;
    case 11:
        strcpy(buf, "Move");
        return;
    case 12:
        strcpy(buf, "Attack");
        return;
    case 13:
        strcpy(buf, "Failed");
        return;
    case 14:
        strcpy(buf, "Invalidated");
        return;
    case 15:
        strcpy(buf, "MoveNoSearch");
        return;
    default:
        strcpy(buf, "Unknown");
        return;
    }
}

float RGE_Action::targetX() const {
    return this->target_x;
}

float RGE_Action::targetY() const {
    return this->target_y;
}

float RGE_Action::targetZ() const {
    return this->target_z;
}

unsigned char RGE_Action::subAction() const {
    return this->subActionValue;
}

void RGE_Action::setSubAction(unsigned char param_1) {
    this->subActionValue = param_1;
}
