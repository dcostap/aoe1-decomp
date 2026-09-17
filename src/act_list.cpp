
#include "../include/act_list.h"
#include "../include/act_atak.h"
#include "../include/act_bird.h"
#include "../include/act_expl.h"
#include "../include/act_gath.h"
#include "../include/act_make.h"
#include "../include/act_misl.h"
#include "../include/act_move.h"
#include "../include/act_obj.h"
#include "../include/m_co_obj.h"
#include "../include/rge_fio.h"
#include "../include/task.h"
#include "../include/unit_ai_module.h"

#include <stdlib.h>
#include <string.h>

RGE_Action_List::RGE_Action_List(RGE_Action_Object* obj_in) {
    this->obj = obj_in;
    this->list = 0;
}

RGE_Action_List::~RGE_Action_List() {
    delete_list();
}

void RGE_Action_List::load(int infile) {
    RGE_Action* action;
    RGE_Action_Node* node;
    RGE_Action_Node* tail;
    short action_type;

    if (this->list != 0) {
        this->delete_list();
    }

    tail = 0;
    while (true) {
        rge_read(infile, &action_type, 2);
        if (action_type == 0) {
            break;
        }

        action = this->create_action(infile, action_type);
        node = static_cast<RGE_Action_Node*>(calloc(1, sizeof(RGE_Action_Node)));
        node->action = action;
        node->next = 0;
        if (tail != 0) {
            tail->next = node;
        } else {
            this->list = node;
        }
        tail = node;
    }
}

void RGE_Action_List::rehook() {
    RGE_Action_Node* node;

    node = this->list;
    while (node != 0) {
        node->action->rehook();
        node = node->next;
    }
}

void RGE_Action_List::save(int outfile) {
    RGE_Action_Node* node;
    int zero;

    node = this->list;
    while (node != 0) {
        node->action->save(outfile);
        node = node->next;
    }
    zero = 0;
    rge_write(outfile, &zero, 2);
}

void RGE_Action_List::delete_list() {
    while (this->list != 0) {
        this->remove_action();
    }
}

RGE_Action* RGE_Action_List::create_action(int infile, short action_type) {
    switch (action_type) {
    case 9:
        return new RGE_Action_Attack(infile, this->obj);
    case 10:
        return new RGE_Action_Bird(infile, this->obj);
    case 4:
        return new RGE_Action_Explore(infile, this->obj);
    case 5:
        return new RGE_Action_Gather(infile, this->obj);
    case 8:
        return new RGE_Action_Missile(infile, this->obj);
    case 1:
        return new RGE_Action_Move_To(infile, this->obj);
    case 21:
        return new RGE_Action_Make(infile, this->obj);
    default:
        return 0;
    }
}

RGE_Action* RGE_Action_List::create_task_action(
    RGE_Task* task, RGE_Static_Object* target_obj, float target_x, float target_y, float target_z) {
    RGE_Action_Bird* bird_action;
    RGE_Action_Attack* attack_action;
    RGE_Action_Explore* explore_action;
    RGE_Action_Gather* gather_action;
    RGE_Action_Make* make_action;

    switch (task->action_type) {
    case 10:
        bird_action = new RGE_Action_Bird(this->obj, task, target_x, target_y, target_z);
        if (bird_action == 0) {
            return 0;
        }
        return bird_action;

    case 7:
        if (this->obj->unitAI() != 0) {
            this->obj->unitAI()->setCurrentAction(600);
            if (target_obj != 0) {
                this->obj->unitAI()->setCurrentTarget(target_obj->id, target_obj->world_x, target_obj->world_y,
                                                      target_obj->world_z);
            } else {
                this->obj->unitAI()->setCurrentTarget(-1, target_x, target_y, target_z);
            }
        }

        if (target_obj != 0) {
            attack_action = new RGE_Action_Attack(this->obj, target_obj, task->move_sprite, task->work_sprite, 0,
                                                  task->work_range, static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj) ->minimum_weapon_range,
                                                  static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj) ->missile_id,
                                                  static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj) ->fire_missile_at_frame);
        } else {
            attack_action = new RGE_Action_Attack(this->obj, target_x, target_y, target_z, task->move_sprite,
                                                  task->work_sprite, 0, task->work_range, static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                                                  ->minimum_weapon_range, static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj) ->missile_id,
                                                  static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj) ->fire_missile_at_frame);
        }
        if (attack_action == 0) {
            return 0;
        }
        return attack_action;

    case 4:
        explore_action = new RGE_Action_Explore(this->obj, task, target_x, target_y, target_z);
        if (explore_action == 0) {
            return 0;
        }
        return explore_action;

    case 5:
        if (target_obj != 0) {
            gather_action = new RGE_Action_Gather(this->obj, task, target_obj);
        } else {
            gather_action = new RGE_Action_Gather(this->obj, task, target_x, target_y, target_z);
        }
        if (gather_action == 0) {
            return 0;
        }
        return gather_action;

    case 21:
        make_action = new RGE_Action_Make(this->obj, task);
        if (make_action == 0) {
            return 0;
        }
        return make_action;

    default:
        return 0;
    }
}

unsigned char RGE_Action_List::inside_obj_update() {
    RGE_Action_Node* node;
    unsigned char result;

    if (this->list == 0) {
        return 1;
    }

    result = this->list->action->inside_obj_update();
    node = this->list->next;
    while (node != 0) {
        node->action->idle_update();
        node = node->next;
    }

    if (result == 1) {
        this->remove_action();
    }
    return result;
}

unsigned char RGE_Action_List::update() {
    RGE_Action_Node* node;
    unsigned char result;

    if (this->list == 0) {
        return 1;
    }

    result = this->list->action->update();
    if (this->list != 0) {
        node = this->list->next;
        while (node != 0) {
            node->action->idle_update();
            node = node->next;
        }

        if (result != 1) {
            return result;
        }
        this->remove_action();
    }

    return result;
}

void RGE_Action_List::add_action(RGE_Action* action) {
    RGE_Action_Node* node;

    if (this->obj->object_state > 2) {
        if (action != 0) {
            delete action;
        }
        return;
    }

    node = static_cast<RGE_Action_Node*>(calloc(1, sizeof(RGE_Action_Node)));
    node->action = action;
    node->next = this->list;
    this->list = node;
    action->first_in_stack(1);
}

void RGE_Action_List::add_action_at_end(RGE_Action* action) {
    RGE_Action_Node* node;
    RGE_Action_Node* current;

    if (this->obj->object_state > 2) {
        if (action != 0) {
            delete action;
        }
        return;
    }

    node = static_cast<RGE_Action_Node*>(calloc(1, sizeof(RGE_Action_Node)));
    node->next = 0;
    node->action = action;

    current = this->list;
    if (current != 0) {
        while (current != 0) {
            if (current->next == 0) {
                current->next = node;
                action->first_in_stack(1);
                return;
            }
            current = current->next;
        }

        action->first_in_stack(1);
        return;
    }

    this->list = node;
    action->first_in_stack(1);
}

void RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action* action) {
    RGE_Action_Node* node;
    RGE_Action_Node* current;

    if (this->obj->object_state > 2) {
        if (action != 0) {
            delete action;
        }
        return;
    }

    node = static_cast<RGE_Action_Node*>(calloc(1, sizeof(RGE_Action_Node)));
    node->action = action;

    if (this->list != 0 &&
        this->list->action->type() == action->type()) {
        current = this->list;
        while (current != 0) {
            if (current->next == 0 ||
                current->next->action->type() != action->type()) {
                node->next = current->next;
                current->next = node;
                break;
            }
            current = current->next;
        }
    } else {
        node->next = this->list;
        this->list = node;
    }

    action->first_in_stack(1);
}

void RGE_Action_List::remove_action() {
    RGE_Action_Node* node;

    node = this->list;
    if (node != 0) {
        this->list = node->next;
        if (node->action != 0) {
            delete node->action;
        }
        free(node);
        if (this->list != 0 && this->obj->object_state < 3) {
            this->list->action->first_in_stack(0);
        }
    }
}

unsigned char RGE_Action_List::have_action() {
    if (this->list != 0) {
        return 1;
    }
    return 0;
}

int RGE_Action_List::action_stop() {
    if (this->list != 0) {
        return this->list->action->stop();
    }
    return 0;
}

int RGE_Action_List::action_move_to(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (this->list != 0) {
        return this->list->action->move_to(obj_in, x, y, z);
    }
    return 0;
}

int RGE_Action_List::action_work(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (this->list != 0) {
        return this->list->action->work(obj_in, x, y, z);
    }
    return 0;
}

int RGE_Action_List::attack_response(RGE_Static_Object* attacker) {
    if (this->list != 0) {
        return this->list->action->attack_response(attacker) & 0xff;
    }
    return 0;
}

int RGE_Action_List::relation_response(long player_id, unsigned char relation) {
    if (this->list != 0) {
        return this->list->action->relation_response(player_id, relation) & 0xff;
    }
    return 0;
}

RGE_Action* RGE_Action_List::get_action() {
    if (this->list != 0) {
        return this->list->action;
    }
    return 0;
}

RGE_Task* RGE_Action_List::get_task() {
    if (this->list != 0) {
        return this->list->action->task;
    }
    return 0;
}

void RGE_Action_List::copy_obj(RGE_Master_Action_Object* source) {
    RGE_Action_Node* node = this->list;
    while (node != 0) {
        node->action->copy_obj(source);
        node = node->next;
    }
}

void RGE_Action_List::copy_obj_sprites(
    RGE_Master_Action_Object* source, RGE_Task* task, RGE_Task* new_task) {
    RGE_Action_Node* node = this->list;
    while (node != 0) {
        node->action->copy_obj_sprites(source, task, new_task);
        node = node->next;
    }
}

void RGE_Action_List::get_action_name(char* action_name) {
    const char* name;

    if (this->list == 0) {
        name = "None";
        strcpy(action_name, name);
        return;
    }

    switch (this->list->action->action_type) {
    case 1:
        name = "MoveTo";
        strcpy(action_name, name);
        return;
    case 4:
        name = "Explore";
        strcpy(action_name, name);
        return;
    case 5:
        name = "Gather";
        strcpy(action_name, name);
        return;
    case 8:
        name = "Missile";
        strcpy(action_name, name);
        return;
    case 9:
        name = "Attack";
        strcpy(action_name, name);
        return;
    case 10:
        name = "Bird";
        strcpy(action_name, name);
        return;
    case 20:
        name = "RunAway";
        strcpy(action_name, name);
        return;
    case 21:
        name = "Make";
        strcpy(action_name, name);
        return;
    default:
        name = "Unknown";
        break;
    }

    strcpy(action_name, name);
}
