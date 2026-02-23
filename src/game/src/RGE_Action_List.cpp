#include "../include/RGE_Action_List.h"

#include "../include/RGE_Action.h"
#include "../include/RGE_Action_Node.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Task.h"
#include "../include/UnitAIModule.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>

namespace {
static void action_list_set_current_action(UnitAIModule* unit_ai, int action_value) {
    if (unit_ai == nullptr) {
        return;
    }
    unit_ai->lastActionValue = unit_ai->currentActionValue;
    unit_ai->currentActionValue = action_value;
}

static void action_list_set_current_target(UnitAIModule* unit_ai, long target_id, int target_type, float x, float y, float z) {
    if (unit_ai == nullptr) {
        return;
    }
    unit_ai->lastTargetValue = unit_ai->currentTargetValue;
    unit_ai->lastTargetTypeValue = unit_ai->currentTargetTypeValue;
    unit_ai->currentTargetValue = (int)target_id;
    unit_ai->currentTargetTypeValue = target_type;
    unit_ai->currentTargetXValue = x;
    unit_ai->currentTargetYValue = y;
    unit_ai->currentTargetZValue = z;
}
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403EA0
RGE_Action_List::RGE_Action_List(RGE_Action_Object* param_1) {
    this->obj = param_1;
    this->list = nullptr;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403EC0
RGE_Action_List::~RGE_Action_List() {
    this->delete_list();
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403ED0
void RGE_Action_List::load(int fd) {
    if (this->list != nullptr) {
        this->delete_list();
    }

    RGE_Action_Node* tail = nullptr;
    while (true) {
        short action_type = 0;
        rge_read(fd, &action_type, 2);
        if (action_type == 0) {
            break;
        }

        RGE_Action* action = this->create_action(fd, action_type);
        RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
        node->action = action;
        node->next = nullptr;

        if (tail == nullptr) {
            this->list = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403F40
void RGE_Action_List::rehook() {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        node->action->rehook();
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403F60
void RGE_Action_List::save(int param_1) {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        node->action->save(param_1);
    }
    short action_type = 0;
    rge_write(param_1, &action_type, 2);
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403FA0
void RGE_Action_List::delete_list() {
    while (this->list != nullptr) {
        this->remove_action();
    }
}

// Source of truth: act_list.cpp.decomp @ 0x00403FC0
RGE_Action* RGE_Action_List::create_action(int param_1, short param_2) {
    // TODO: STUB - specific action subclass constructors are not transliterated yet.
    // Keep load/save stack plumbing working with a base action shell.
    RGE_Action* action = new RGE_Action();
    if (action != nullptr) {
        action->setup(param_1, this->obj);
        action->action_type = param_2;
    }
    return action;
}

// Source of truth: act_list.cpp.decomp @ 0x00404200
RGE_Action* RGE_Action_List::create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    if (param_1 == nullptr) {
        return nullptr;
    }

    UnitAIModule* unit_ai = (this->obj != nullptr) ? this->obj->unitAIValue : nullptr;
    if (param_1->action_type == 7 && unit_ai != nullptr) {
        action_list_set_current_action(unit_ai, 600);
        if (param_2 == nullptr) {
            action_list_set_current_target(unit_ai, -1, -1, param_3, param_4, param_5);
        } else {
            int target_type = (param_2->master_obj != nullptr) ? (int)param_2->master_obj->object_group : -1;
            action_list_set_current_target(unit_ai, param_2->id, target_type, param_2->world_x, param_2->world_y, param_2->world_z);
        }
    }

    // TODO: STUB - specific action subclass constructors are not transliterated yet.
    RGE_Action* action = new RGE_Action();
    if (action == nullptr) {
        return nullptr;
    }

    action->setup(this->obj);
    action->task = param_1;
    action->action_type = param_1->action_type;
    if (param_2 != nullptr) {
        action->set_target_obj(param_2);
    } else {
        action->target_x = param_3;
        action->target_y = param_4;
        action->target_z = param_5;
    }
    return action;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004044A0
uchar RGE_Action_List::inside_obj_update() {
    if (this->list != nullptr) {
        uchar ret = this->list->action->inside_obj_update();
        for (RGE_Action_Node* node = this->list->next; node != nullptr; node = node->next) {
            node->action->idle_update();
        }
        if (ret == 1) {
            this->remove_action();
        }
        return ret;
    }
    return 1;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004044F0
uchar RGE_Action_List::update() {
    if (this->list != nullptr) {
        uchar ret = this->list->action->update();
        if (this->list != nullptr) {
            for (RGE_Action_Node* node = this->list->next; node != nullptr; node = node->next) {
                node->action->idle_update();
            }
            if (ret == 1) {
                this->remove_action();
            }
        }
        return ret;
    }
    return 1;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404540
void RGE_Action_List::add_action(RGE_Action* param_1) {
    if ((unsigned char)this->obj->object_state < 3) {
        RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
        node->action = param_1;
        node->next = this->list;
        this->list = node;
        param_1->first_in_stack(1);
    } else if (param_1 != nullptr) {
        delete param_1;
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404590
void RGE_Action_List::add_action_at_end(RGE_Action* param_1) {
    if ((unsigned char)this->obj->object_state < 3) {
        RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
        node->next = nullptr;
        node->action = param_1;

        RGE_Action_Node* curr = this->list;
        if (curr != nullptr) {
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = node;
            param_1->first_in_stack(1);
            return;
        }

        this->list = node;
        param_1->first_in_stack(1);
    } else if (param_1 != nullptr) {
        delete param_1;
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404610
void RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action* param_1) {
    if ((unsigned char)this->obj->object_state > 2) {
        if (param_1 != nullptr) {
            delete param_1;
        }
        return;
    }

    RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
    node->action = param_1;
    node->next = nullptr;

    if (this->list != nullptr) {
        short new_type = param_1->type();
        short list_type = this->list->action->type();
        if (list_type == new_type) {
            RGE_Action_Node* cur = this->list;
            while (cur->next != nullptr) {
                short next_type = cur->next->action->type();
                if (next_type != new_type) {
                    break;
                }
                cur = cur->next;
            }
            node->next = cur->next;
            cur->next = node;
            param_1->first_in_stack(1);
            return;
        }
    }

    node->next = this->list;
    this->list = node;
    param_1->first_in_stack(1);
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404710
void RGE_Action_List::remove_action() {
    RGE_Action_Node* node = this->list;
    if (node != nullptr) {
        this->list = node->next;
        if (node->action != nullptr) {
            delete node->action;
        }
        free(node);
        if ((this->list != nullptr) && ((unsigned char)this->obj->object_state < 3)) {
            this->list->action->first_in_stack(0);
        }
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404760
uchar RGE_Action_List::have_action() {
    return this->list != nullptr;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404770
int RGE_Action_List::action_stop() {
    if (this->list != nullptr) {
        return this->list->action->stop();
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404790
int RGE_Action_List::action_move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (this->list != nullptr) {
        return this->list->action->move_to(param_1, param_2, param_3, param_4);
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004047C0
int RGE_Action_List::action_work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (this->list != nullptr) {
        return this->list->action->work(param_1, param_2, param_3, param_4);
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004047F0
int RGE_Action_List::attack_response(RGE_Static_Object* param_1) {
    if (this->list != nullptr) {
        return this->list->action->attack_response(param_1) & 0xFF;
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404810
int RGE_Action_List::relation_response(long param_1, uchar param_2) {
    if (this->list != nullptr) {
        return this->list->action->relation_response(param_1, param_2) & 0xFF;
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404840
RGE_Action* RGE_Action_List::get_action() {
    if (this->list != nullptr) {
        return this->list->action;
    }
    return nullptr;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404850
RGE_Task* RGE_Action_List::get_task() {
    if (this->list != nullptr) {
        return this->list->action->task;
    }
    return nullptr;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404860
void RGE_Action_List::copy_obj(RGE_Master_Action_Object* param_1) {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        node->action->copy_obj(param_1);
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404890
void RGE_Action_List::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        node->action->copy_obj_sprites(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004048C0
void RGE_Action_List::get_action_name(char* param_1) {
    const char* action_name = "None";
    if (this->list == nullptr) {
        strcpy(param_1, action_name);
        return;
    }

    switch (this->list->action->action_type) {
    case 1:
        action_name = "MoveTo";
        break;
    case 4:
        action_name = "Explore";
        break;
    case 5:
        action_name = "Gather";
        break;
    case 8:
        action_name = "Missile";
        break;
    case 9:
        action_name = "Attack";
        break;
    case 10:
        action_name = "Bird";
        break;
    case 0x14:
        action_name = "RunAway";
        break;
    case 0x15:
        action_name = "Make";
        break;
    default:
        action_name = "Unknown";
        break;
    }

    strcpy(param_1, action_name);
}
