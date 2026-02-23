#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action.h"
#include "../include/RGE_Action_Node.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/globals.h"

#include <new>
#include <stdlib.h>
#include <string.h>

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403EA0
RGE_Action_List::RGE_Action_List(RGE_Action_Object* param_1) {
    this->obj = param_1;
    this->list = nullptr;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403EC0
RGE_Action_List::~RGE_Action_List() {
    this->delete_list();
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403F40
void RGE_Action_List::rehook() {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->action != nullptr) {
            node->action->rehook();
        }
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403F60
void RGE_Action_List::save(int fd) {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->action != nullptr) {
            node->action->save(fd);
        }
    }

    short terminator = 0;
    rge_write(fd, &terminator, 2);
}

// Source of truth: act_list.cpp.decomp @ 0x00403FC0
RGE_Action* RGE_Action_List::create_action(int param_1, short param_2) {
    switch (param_2) {
    case 1: {
        RGE_Action_Move_To* action = new (std::nothrow) RGE_Action_Move_To(param_1, this->obj);
        return (RGE_Action*)action;
    }
    default:
        // Best-effort fallback: load as a generic action so load/update loops won't crash.
        RGE_Action* action = new (std::nothrow) RGE_Action();
        if (action != nullptr) {
            action->setup(param_1, this->obj);
            action->action_type = param_2;
        }
        return action;
    }
}

// Source of truth: act_list.cpp.decomp @ 0x00404200
RGE_Action* RGE_Action_List::create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    return nullptr;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004044A0
uchar RGE_Action_List::inside_obj_update() {
    if (this->list == nullptr) {
        return 1;
    }

    uchar head_result = this->list->action->inside_obj_update();
    for (RGE_Action_Node* node = this->list->next; node != nullptr; node = node->next) {
        node->action->idle_update();
    }
    if (head_result == 1) {
        this->remove_action();
    }
    return head_result;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004044F0
uchar RGE_Action_List::update() {
    if (this->list == nullptr) {
        return 1;
    }

    uchar head_result = this->list->action->update();
    if (this->list != nullptr) {
        for (RGE_Action_Node* node = this->list->next; node != nullptr; node = node->next) {
            node->action->idle_update();
        }
        if (head_result == 1) {
            this->remove_action();
        }
    }
    return head_result;
}

void RGE_Action_List::get_action_name(char* param_1) {
    if (param_1 == nullptr) {
        return;
    }
    if (this->list == nullptr) {
        strncpy(param_1, "None", 5);
        return;
    }
    // Best-effort fallback; TRIBE_Action_List overrides for TRIBE-specific actions.
    strncpy(param_1, "Action", 7);
}

void RGE_Action_List::copy_obj(RGE_Master_Action_Object* param_1) {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->action != nullptr) {
            node->action->copy_obj(param_1);
        }
    }
}

void RGE_Action_List::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->action != nullptr) {
            node->action->copy_obj_sprites(param_1, param_2, param_3);
        }
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404540
void RGE_Action_List::add_action(RGE_Action* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    if ((this->obj != nullptr) && (*((unsigned char*)this->obj + 0x48) < 3)) {
        RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
        node->action = param_1;
        node->next = this->list;
        this->list = node;
        param_1->first_in_stack(1);
        return;
    }

    delete param_1;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404590
void RGE_Action_List::add_action_at_end(RGE_Action* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    if ((this->obj != nullptr) && (*((unsigned char*)this->obj + 0x48) < 3)) {
        RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
        node->action = param_1;
        node->next = nullptr;

        if (this->list != nullptr) {
            RGE_Action_Node* tail = this->list;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = node;
        } else {
            this->list = node;
        }

        param_1->first_in_stack(1);
        return;
    }

    delete param_1;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404610
void RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    if ((this->obj == nullptr) || (2 < *((unsigned char*)this->obj + 0x48))) {
        delete param_1;
        return;
    }

    RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
    node->action = param_1;

    if (this->list != nullptr) {
        short new_type = param_1->type();
        short head_type = this->list->action->type();
        if (head_type == new_type) {
            RGE_Action_Node* iter = this->list;
            while (iter->next != nullptr) {
                short next_type = iter->next->action->type();
                if (next_type != new_type) {
                    break;
                }
                iter = iter->next;
            }
            node->next = iter->next;
            iter->next = node;
            param_1->first_in_stack(1);
            return;
        }
    }

    node->next = this->list;
    this->list = node;
    param_1->first_in_stack(1);
}

void RGE_Action_List::remove_action() {
    // Source of truth: act_list.cpp.decomp @ 0x00404710
    RGE_Action_Node* node = this->list;
    if (node != nullptr) {
        this->list = node->next;
        if (node->action != nullptr) {
            delete node->action;
        }
        free(node);
        if ((this->list != nullptr) && (*((unsigned char*)this->obj + 0x48) < 3)) {
            this->list->action->first_in_stack(0);
        }
    }
}

void RGE_Action_List::delete_list() {
    // Source of truth: act_list.cpp.decomp @ 0x00403FA0
    while (this->list != nullptr) {
        this->remove_action();
    }
}

int RGE_Action_List::action_stop() {
    // Source of truth: act_list.cpp.decomp @ 0x00404770
    if (this->list != nullptr) {
        return this->list->action->stop();
    }
    return 0;
}

int RGE_Action_List::action_work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    // Source of truth: act_list.cpp.decomp @ 0x004047C0
    if (this->list != nullptr) {
        return this->list->action->work(param_1, param_2, param_3, param_4);
    }
    return 0;
}

RGE_Action* RGE_Action_List::get_action() {
    // Source of truth: act_list.cpp.decomp @ 0x00404840
    if (this->list != nullptr) {
        return this->list->action;
    }
    return nullptr;
}

RGE_Task* RGE_Action_List::get_task() {
    // Source of truth: act_list.cpp.decomp @ 0x00404850
    if (this->list != nullptr) {
        return this->list->action->task;
    }
    return nullptr;
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
        if (action_type == 0) break;

        // create_action is virtual (vtable[0])
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
