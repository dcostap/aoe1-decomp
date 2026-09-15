
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

RGE_Action::RGE_Action(int infile, RGE_Action_Object* obj_in, int do_setup) {
    this->targetID = -1;
    this->target2ID = -1;
    if (do_setup != 0) {
        this->setup(infile, obj_in);
    }
}

RGE_Action::RGE_Action(RGE_Action_Object* obj_in, int do_setup) {
    this->targetID = -1;
    this->target2ID = -1;
    if (do_setup) {
        setup(obj_in);
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

int RGE_Action::setup(int infile, RGE_Action_Object* obj_in) {
    short short_val;
    int long_val;

    this->action_type = 0;
    this->obj = obj_in;
    this->sub_actions = (RGE_Action_List*)this->create_action_list(obj_in);

    rge_read(infile, &this->state, 1);

    rge_read(infile, &long_val, 4);
    if (long_val == -1) {
        this->target_obj = 0;
    } else {
        this->target_obj = (RGE_Static_Object*)long_val;
    }

    rge_read(infile, &long_val, 4);
    if (long_val == -1) {
        this->target_obj2 = 0;
    } else {
        this->target_obj2 = (RGE_Static_Object*)long_val;
    }

    rge_read(infile, &this->targetID, 4);
    rge_read(infile, &this->target2ID, 4);
    rge_read(infile, &this->target_x, 4);
    rge_read(infile, &this->target_y, 4);
    rge_read(infile, &this->target_z, 4);
    rge_read(infile, &this->timer, 4);

    rge_read(infile, &short_val, 2);
    if (short_val == -1) {
        this->task = 0;
    } else {
        // Action-master task data starts at +0xD8.
        RGE_Master_Action_Object* action_master =
            (RGE_Master_Action_Object*)this->obj->master_obj;
        RGE_Task_List* task_list = action_master->tasks;
        this->task = task_list->list[short_val];
    }

    rge_read(infile, &this->subActionValue, 1);

    this->sub_actions->load(infile);

    rge_read(infile, &short_val, 2);
    this->sprite = ((RGE_Static_Object*)this->obj)->get_sprite_pointer(short_val);

    return 1;
}

int RGE_Action::setup(RGE_Action_Object* obj_in) {
    this->action_type = 0;
    this->obj = obj_in;
    this->state = 0;
    this->target_obj = 0;
    this->target_obj2 = 0;
    this->target_x = 0.0f;
    this->target_y = 0.0f;
    this->target_z = 0.0f;
    this->timer = 0.0f;
    this->task = 0;
    this->sub_actions = this->create_action_list(obj_in);
    this->sprite = 0;
    this->subActionValue = 0;
    return 1;
}

RGE_Action_List* RGE_Action::create_action_list(RGE_Action_Object* obj_in) {
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

void RGE_Action::save(int outfile) {
    // Two locals preserve the original 8-byte local window.
    int long_val;
    short short_val;

    rge_write(outfile, &this->action_type, 2);
    rge_write(outfile, &this->state, 1);

    if (!this->target_obj) {
        long_val = -1;
    } else {
        long_val = this->target_obj->id;
    }
    rge_write(outfile, &long_val, 4);

    if (!this->target_obj2) {
        long_val = -1;
    } else {
        long_val = this->target_obj2->id;
    }
    rge_write(outfile, &long_val, 4);

    rge_write(outfile, &this->targetID, 4);
    rge_write(outfile, &this->target2ID, 4);
    rge_write(outfile, &this->target_x, 4);
    rge_write(outfile, &this->target_y, 4);
    rge_write(outfile, &this->target_z, 4);
    rge_write(outfile, &this->timer, 4);

    if (!this->task) {
        short_val = -1;
    } else {
        short_val = this->task->id;
    }
    rge_write(outfile, &short_val, 2);

    rge_write(outfile, &this->subActionValue, 1);

    this->sub_actions->save(outfile);

    if (!this->sprite) {
        short_val = -1;
    } else {
        short_val = this->sprite->id;
    }
    rge_write(outfile, &short_val, 2);
}

short RGE_Action::type() {
    return this->action_type;
}

void RGE_Action::first_in_stack(unsigned char first_time) {
}

int RGE_Action::stop() {
    return 0;
}

int RGE_Action::move_to(RGE_Static_Object* obj_in, float x, float y, float z) {
    return 0;
}

int RGE_Action::work(RGE_Static_Object* obj_in, float x, float y, float z) {
    return 0;
}

unsigned char RGE_Action::attack_response(RGE_Static_Object* obj_in) {
    return 0;
}

unsigned char RGE_Action::relation_response(long player_id, unsigned char relation) {
    return 0;
}

void RGE_Action::set_state(unsigned char new_state) {
    this->state = new_state;
}

unsigned char RGE_Action::inside_obj_update() {
    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj((RGE_Static_Object*)0);
    }
    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7) {
        this->set_target_obj2((RGE_Static_Object*)0);
    }
    return 1;
}

unsigned char RGE_Action::idle_update() {
    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj((RGE_Static_Object*)0);
    }
    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7) {
        this->set_target_obj2((RGE_Static_Object*)0);
    }
    return 1;
}

unsigned char RGE_Action::update() {
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

void RGE_Action::set_target_obj(RGE_Static_Object* new_obj) {
    if (this->target_obj != 0 && this->target_obj != new_obj) {
        RGE_Static_Object* previous = this->obj->owner->world->object(this->targetID);
        if (previous != 0) {
            previous->release_being_worked_on(this->obj);
        }
    }

    if (this->target_obj != new_obj) {
        this->target_obj = new_obj;
        if (new_obj != 0) {
            this->targetID = new_obj->id;
            new_obj->set_being_worked_on(this->obj, this->action_type, 0);
            return;
        }
        this->targetID = -1;
    }
}

void RGE_Action::set_target_obj2(RGE_Static_Object* new_obj) {
    if (this->target_obj2 && this->target_obj2 != new_obj) {
        RGE_Game_World* world = this->obj->owner->world;
        RGE_Static_Object* old_target = world->object(this->target2ID);
        if (old_target) {
            old_target->release_being_worked_on(this->obj);
        }
    }

    if (this->target_obj2 != new_obj) {
        this->target_obj2 = new_obj;
        if (new_obj) {
            this->target2ID = new_obj->id;
            new_obj->set_being_worked_on(this->obj, this->action_type, 0);
        } else {
            this->target2ID = -1;
        }
    }
}

void RGE_Action::copy_obj(RGE_Master_Action_Object* source) {
    RGE_Task_List* task_list;
    RGE_Task** task_array;
    RGE_Sprite* new_sprite = 0;
    int i;

    if (this->task != 0 && (task_list = source->tasks) != 0) {
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

            this->copy_obj_sprites(source, this->task, task_array[i]);
            this->sub_actions->copy_obj_sprites(source, this->task, task_array[i]);
            this->task = task_array[i];
            return;
        }
    } else {
        this->copy_obj_sprites(source, 0, 0);
        this->sub_actions->copy_obj_sprites(source, 0, 0);
    }
}

void RGE_Action::copy_obj_sprites(RGE_Master_Action_Object* source, RGE_Task* task, RGE_Task* new_task) {
}

void RGE_Action::get_state_name(char* state_name) {
    switch (this->state) {
    case 0:
        strcpy(state_name, "None");
        return;
    case 1:
        strcpy(state_name, "Done");
        return;
    case 2:
        strcpy(state_name, "Wait");
        return;
    case 3:
        strcpy(state_name, "Search");
        return;
    case 4:
        strcpy(state_name, "Goto");
        return;
    case 5:
        strcpy(state_name, "Goto2");
        return;
    case 6:
        strcpy(state_name, "Work");
        return;
    case 7:
        strcpy(state_name, "Work2");
        return;
    case 8:
        strcpy(state_name, "Return");
        return;
    case 9:
        strcpy(state_name, "Turn");
        return;
    case 10:
        strcpy(state_name, "Delay");
        return;
    case 11:
        strcpy(state_name, "Move");
        return;
    case 12:
        strcpy(state_name, "Attack");
        return;
    case 13:
        strcpy(state_name, "Failed");
        return;
    case 14:
        strcpy(state_name, "Invalidated");
        return;
    case 15:
        strcpy(state_name, "MoveNoSearch");
        return;
    default:
        strcpy(state_name, "Unknown");
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

void RGE_Action::setSubAction(unsigned char v) {
    this->subActionValue = v;
}
