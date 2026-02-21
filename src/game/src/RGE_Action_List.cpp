#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action.h"
#include "../include/RGE_Action_Node.h"
#include "../include/globals.h"
#include <stdlib.h>

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
