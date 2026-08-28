// PDB source module: C:\\msdev\\work\\age1_x1\\act_list.cpp.
// Definitions follow the original source order.

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

RGE_Action_List::RGE_Action_List(RGE_Action_Object* object) {
    this->obj = object;
    this->list = 0;
}

RGE_Action_List::~RGE_Action_List() {
    delete_list();
}

void RGE_Action_List::load(int file) {
    RGE_Action* action;
    RGE_Action_Node* node;
    RGE_Action_Node* tail;
    short action_type;

    if (this->list != 0) {
        this->delete_list();
    }

    tail = 0;
    while (true) {
        rge_read(file, &action_type, 2);
        if (action_type == 0) {
            break;
        }

        action = this->create_action(file, action_type);
        node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
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

void RGE_Action_List::save(int file) {
    RGE_Action_Node* node;
    int zero;

    node = this->list;
    while (node != 0) {
        node->action->save(file);
        node = node->next;
    }
    zero = 0;
    rge_write(file, &zero, 2);
}

void RGE_Action_List::delete_list() {
    while (this->list != 0) {
        this->remove_action();
    }
}

RGE_Action* RGE_Action_List::create_action(int file, short type) {
    switch (type) {
    case 9:
        return new RGE_Action_Attack(file, this->obj);
    case 10:
        return new RGE_Action_Bird(file, this->obj);
    case 4:
        return new RGE_Action_Explore(file, this->obj);
    case 5:
        return new RGE_Action_Gather(file, this->obj);
    case 8:
        return new RGE_Action_Missile(file, this->obj);
    case 1:
        return new RGE_Action_Move_To(file, this->obj);
    case 21:
        return new RGE_Action_Make(file, this->obj);
    default:
        return 0;
    }
}

RGE_Action* RGE_Action_List::create_task_action(
    RGE_Task* task, RGE_Static_Object* target, float x, float y, float z) {
    RGE_Action* action;
    RGE_Action_Bird* bird_action;
    RGE_Action_Attack* attack_action;
    RGE_Action_Explore* explore_action;
    RGE_Action_Gather* gather_action;
    RGE_Action_Make* make_action;
    RGE_Master_Combat_Object* master;

    switch (task->action_type) {
    case 10:
        bird_action = new RGE_Action_Bird(this->obj, task, x, y, z);
        if (bird_action == 0) {
            goto fail;
        }
        action = bird_action;
        goto done;

    case 7:
        if (this->obj->unitAI() != 0) {
            this->obj->unitAI()->setCurrentAction(600);
            if (target != 0) {
                this->obj->unitAI()->setCurrentTarget(
                    target->id, target->world_x, target->world_y, target->world_z);
            } else {
                this->obj->unitAI()->setCurrentTarget(-1, x, y, z);
            }
        }

        master = (RGE_Master_Combat_Object*)this->obj->master_obj;
        if (target != 0) {
            attack_action = new RGE_Action_Attack(
                this->obj, target, task->work_sprite, task->move_sprite, 0,
                task->work_range, master->minimum_weapon_range,
                master->missile_id, master->fire_missile_at_frame);
        } else {
            attack_action = new RGE_Action_Attack(
                this->obj, x, y, z, task->work_sprite, task->move_sprite, 0,
                task->work_range, master->minimum_weapon_range,
                master->missile_id, master->fire_missile_at_frame);
        }
        if (attack_action == 0) {
            goto fail;
        }
        action = attack_action;
        goto done;

    case 4:
        explore_action = new RGE_Action_Explore(this->obj, task, x, y, z);
        if (explore_action == 0) {
            goto fail;
        }
        action = explore_action;
        goto done;

    case 5:
        if (target != 0) {
            gather_action = new RGE_Action_Gather(this->obj, task, target);
        } else {
            gather_action = new RGE_Action_Gather(this->obj, task, x, y, z);
        }
        if (gather_action == 0) {
            goto fail;
        }
        action = gather_action;
        goto done;

    case 21:
        make_action = new RGE_Action_Make(this->obj, task);
        if (make_action == 0) {
            goto fail;
        }
        action = make_action;
        goto done;

    default:
        goto fail;
    }

fail:
    action = 0;
done:
    return action;
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

    node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
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

    node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
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

    if (this->obj->object_state > 2) {
        if (action != 0) {
            delete action;
        }
        return;
    }

    node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
    node->action = action;

    if (this->list != 0) {
        short action_type;
        action_type = action->type();
        if (this->list->action->type() == action_type) {
            RGE_Action_Node* current = this->list;
            if (current != 0) {
                while (true) {
                    if (current->next == 0) {
                        break;
                    }
                    action_type = action->type();
                    if (current->next->action->type() != action_type) {
                        break;
                    }
                    current = current->next;
                    if (current == 0) {
                        action->first_in_stack(1);
                        return;
                    }
                }
                node->next = current->next;
                current->next = node;
                action->first_in_stack(1);
                return;
            }
            goto notify;
        }
    }

    node->next = this->list;
    this->list = node;

notify:
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

int RGE_Action_List::action_move_to(
    RGE_Static_Object* object, float x, float y, float z) {
    if (this->list != 0) {
        return this->list->action->move_to(object, x, y, z);
    }
    return 0;
}

int RGE_Action_List::action_work(
    RGE_Static_Object* object, float x, float y, float z) {
    if (this->list != 0) {
        return this->list->action->work(object, x, y, z);
    }
    return 0;
}

int RGE_Action_List::attack_response(RGE_Static_Object* object) {
    if (this->list != 0) {
        return this->list->action->attack_response(object) & 0xff;
    }
    return 0;
}

int RGE_Action_List::relation_response(long value, unsigned char relation) {
    if (this->list != 0) {
        return this->list->action->relation_response(value, relation) & 0xff;
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

void RGE_Action_List::copy_obj(RGE_Master_Action_Object* object) {
    RGE_Action_Node* node = this->list;
    while (node != 0) {
        node->action->copy_obj(object);
        node = node->next;
    }
}

void RGE_Action_List::copy_obj_sprites(
    RGE_Master_Action_Object* object, RGE_Task* source, RGE_Task* dest) {
    RGE_Action_Node* node = this->list;
    while (node != 0) {
        node->action->copy_obj_sprites(object, source, dest);
        node = node->next;
    }
}

void RGE_Action_List::get_action_name(char* dest) {
    const char* name;

    if (this->list == 0) {
        name = "None";
        strcpy(dest, name);
        return;
    }

    switch (this->list->action->action_type) {
    case 1:
        name = "MoveTo";
        strcpy(dest, name);
        return;
    case 4:
        name = "Explore";
        strcpy(dest, name);
        return;
    case 5:
        name = "Gather";
        strcpy(dest, name);
        return;
    case 8:
        name = "Missile";
        strcpy(dest, name);
        return;
    case 9:
        name = "Attack";
        strcpy(dest, name);
        return;
    case 10:
        name = "Bird";
        strcpy(dest, name);
        return;
    case 20:
        name = "RunAway";
        strcpy(dest, name);
        return;
    case 21:
        name = "Make";
        strcpy(dest, name);
        return;
    default:
        name = "Unknown";
        break;
    }

    strcpy(dest, name);
}
