#include "../include/RGE_Object_List.h"

#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Animated_Object.h"
#include "../include/RGE_Doppleganger_Object.h"
#include "../include/RGE_Moving_Object.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Combat_Object.h"
#include "../include/RGE_Missile_Object.h"
#include "../include/TMousePointer.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"

#include <stdlib.h>
#include <new>

RGE_Object_List::RGE_Object_List() {
    // Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00462E80
    this->list = nullptr;
    this->number_of_objects = 0;
}

RGE_Object_Node* RGE_Object_List::add_node(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00462F30
    RGE_Object_Node* new_node = (RGE_Object_Node*)calloc(1, 0x10);
    RGE_Object_Node* old_head = this->list;
    new_node->prev = nullptr;
    new_node->next = old_head;
    if (this->list != nullptr) {
        this->list->prev = new_node;
    }
    new_node->node = param_1;
    this->number_of_objects = this->number_of_objects + 1;
    this->list = new_node;
    return new_node;
}

void RGE_Object_List::remove_node(RGE_Static_Object* param_1, RGE_Object_Node* param_2) {
    // Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00462F70
    RGE_Object_Node* node = this->list;
    if (node == nullptr) {
        return;
    }
    if (param_2 == nullptr) {
        // Search for the node containing param_1
        param_2 = node;
        while (param_2->node != param_1) {
            param_2 = param_2->next;
            if (param_2 == nullptr) {
                return;
            }
        }
    }
    // Unlink param_2 from the doubly-linked list
    if (param_2->prev == nullptr) {
        this->list = param_2->next;
    } else {
        param_2->prev->next = param_2->next;
    }
    if (param_2->next != nullptr) {
        param_2->next->prev = param_2->prev;
    }
    free(param_2);
    this->number_of_objects = this->number_of_objects + -1;
}

RGE_Static_Object* RGE_Object_List::find_by_id(long param_1) {
    // Fully verified. Source of truth: obj_list.cpp.asm @ 0x00463490
    RGE_Object_Node* cur = this->list;
    if (cur == nullptr) return nullptr;
    while (cur != nullptr) {
        RGE_Static_Object* obj = cur->node;
        if (obj != nullptr && obj->id == param_1) {
            return obj;
        }
        cur = cur->next;
    }
    return nullptr;
}

void RGE_Object_List::update() {
    // Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00463210
    int polled_objects = 0;
    int node_index = 0;
    CUSTOM_DEBUG_LOG_FMT("RGE_Object_List::update begin this=%p head=%p count=%d", this, this ? this->list : nullptr, (int)this->number_of_objects);
    RGE_Object_Node* node = this->list;
    while (node != nullptr) {
        RGE_Object_Node* next = node->next;
        if (node->node != nullptr) {
            if (node_index < 16) {
                void* obj_vft = *(void**)node->node;
                CUSTOM_DEBUG_LOG_FMT("RGE_Object_List::update node[%d] node=%p obj=%p vft=%p id=%ld state=%d", node_index, node, node->node, obj_vft, node->node->id, (int)node->node->object_state);
            }
            uchar update_result = node->node->update();
            if (node_index < 16) {
                CUSTOM_DEBUG_LOG_FMT("RGE_Object_List::update node[%d] update result=%d", node_index, (int)update_result);
            }
            if (update_result != '\0') {
                if (node_index < 16) {
                    CUSTOM_DEBUG_LOG_FMT("RGE_Object_List::update node[%d] recycle obj=%p", node_index, node->node);
                }
                node->node->recycle_out_of_game();
            }
            polled_objects = polled_objects + 1;
            if (polled_objects > 9) {
                polled_objects = 0;
                if (MouseSystem != nullptr) {
                    MouseSystem->Poll();
                }
            }
        }
        node_index = node_index + 1;
        node = next;
    }
    CUSTOM_DEBUG_LOG_FMT("RGE_Object_List::update end this=%p visited=%d", this, node_index);
}

void RGE_Object_List::load(uchar param_1, int param_2, RGE_Game_World* param_3) {
    // Source of truth: obj_list.cpp.decomp @ 0x00463930
    switch (param_1) {
    case 0x0A: {
        RGE_Static_Object* static_object =
            (RGE_Static_Object*)::operator new(sizeof(RGE_Static_Object), std::nothrow);
        if (static_object != nullptr) {
            new (static_object) RGE_Static_Object(param_2, param_3, 1);
            return;
        }
        break;
    }
    case 0x14: {
        RGE_Animated_Object* animated_object =
            (RGE_Animated_Object*)::operator new(sizeof(RGE_Animated_Object), std::nothrow);
        if (animated_object != nullptr) {
            new (animated_object) RGE_Animated_Object(param_2, param_3, 1);
            return;
        }
        break;
    }
    case 0x19: {
        RGE_Doppleganger_Object* dopple_object =
            (RGE_Doppleganger_Object*)::operator new(sizeof(RGE_Doppleganger_Object), std::nothrow);
        if (dopple_object != nullptr) {
            new (dopple_object) RGE_Doppleganger_Object(param_2, param_3, 1);
            return;
        }
        break;
    }
    case 0x1E: {
        RGE_Moving_Object* moving_object =
            (RGE_Moving_Object*)::operator new(sizeof(RGE_Moving_Object), std::nothrow);
        if (moving_object != nullptr) {
            new (moving_object) RGE_Moving_Object(param_2, param_3, 1);
            return;
        }
        break;
    }
    case 0x28: {
        RGE_Action_Object* action_object =
            (RGE_Action_Object*)::operator new(sizeof(RGE_Action_Object), std::nothrow);
        if (action_object != nullptr) {
            new (action_object) RGE_Action_Object(param_2, param_3, 1);
            return;
        }
        break;
    }
    case 0x32: {
        RGE_Combat_Object* combat_object =
            (RGE_Combat_Object*)::operator new(sizeof(RGE_Combat_Object), std::nothrow);
        if (combat_object != nullptr) {
            new (combat_object) RGE_Combat_Object(param_2, param_3, 1);
            return;
        }
        break;
    }
    case 0x3C: {
        RGE_Missile_Object* missile_object =
            (RGE_Missile_Object*)::operator new(sizeof(RGE_Missile_Object), std::nothrow);
        if (missile_object != nullptr) {
            new (missile_object) RGE_Missile_Object(param_2, param_3, 1);
            return;
        }
        break;
    }
    default:
        break;
    }
}
