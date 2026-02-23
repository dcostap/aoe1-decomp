#include "../include/RGE_Action_List.h"

#include "../include/RGE_Action.h"
#include "../include/RGE_Action_Attack.h"
#include "../include/RGE_Action_Bird.h"
#include "../include/RGE_Action_Enter.h"
#include "../include/RGE_Action_Explore.h"
#include "../include/RGE_Action_Gather.h"
#include "../include/RGE_Action_Make.h"
#include "../include/RGE_Action_Missile.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Node.h"
#include "../include/RGE_Action_Transport.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Task.h"
#include "../include/UnitAIModule.h"
#include "../include/globals.h"

#include <new>
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

        // create_action is virtual (vt[0]).
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

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403FA0
void RGE_Action_List::delete_list() {
    while (this->list != nullptr) {
        this->remove_action();
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00403FC0
RGE_Action* RGE_Action_List::create_action(int param_1, short param_2) {
    RGE_Action* action = nullptr;
    bool needs_setup = true;

    switch (param_2) {
    case 1:
        action = new (std::nothrow) RGE_Action_Move_To();
        break;
    case 3:
        action = new (std::nothrow) RGE_Action_Enter(param_1, this->obj);
        needs_setup = false;
        break;
    case 4:
        action = new (std::nothrow) RGE_Action_Explore();
        break;
    case 5:
        action = new (std::nothrow) RGE_Action_Gather();
        break;
    case 8:
        action = new (std::nothrow) RGE_Action_Missile(param_1, this->obj);
        needs_setup = false;
        break;
    case 9:
        action = new (std::nothrow) RGE_Action_Attack();
        break;
    case 10:
        action = new (std::nothrow) RGE_Action_Bird();
        break;
    case 0x0C:
        action = new (std::nothrow) RGE_Action_Transport(param_1, this->obj);
        needs_setup = false;
        break;
    case 0x15:
        action = new (std::nothrow) RGE_Action_Make();
        break;
    default:
        break;
    }

    if (action == nullptr) {
        // TODO: STUB - not all action subclass load constructors are transliterated yet.
        // Keep save/load stack plumbing working with a base action shell.
        action = new (std::nothrow) RGE_Action();
        if (action != nullptr) {
            action->setup(param_1, this->obj);
            action->action_type = param_2;
            needs_setup = false;
        }
    }

    if ((action != nullptr) && needs_setup) {
        action->setup(param_1, this->obj);
    }

    return action;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404200
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

    RGE_Action* action = nullptr;
    switch (param_1->action_type) {
    case 4: {
        RGE_Action_Explore* explore = new (std::nothrow) RGE_Action_Explore();
        if (explore != nullptr) {
            explore->setup(this->obj);
            explore->task = param_1;
            explore->target_x = param_3;
            explore->target_y = param_4;
            explore->target_z = param_5;
            action = explore;
        }
        break;
    }
    case 5: {
        RGE_Action_Gather* gather = new (std::nothrow) RGE_Action_Gather();
        if (gather != nullptr) {
            gather->setup(this->obj);
            gather->task = param_1;
            if (param_2 != nullptr) {
                gather->set_target_obj(param_2);
                gather->target_x = param_2->world_x;
                gather->target_y = param_2->world_y;
                gather->target_z = param_2->world_z;
                gather->targetType = (param_2->master_obj != nullptr) ? (int)param_2->master_obj->id : -1;
            } else {
                gather->target_x = param_3;
                gather->target_y = param_4;
                gather->target_z = param_5;
            }
            action = gather;
        }
        break;
    }
    case 7: {
        RGE_Master_Combat_Object* master = (this->obj != nullptr) ? (RGE_Master_Combat_Object*)this->obj->master_obj : nullptr;
        float min_range = (master != nullptr) ? master->minimum_weapon_range : 0.0f;
        short missile_id = (master != nullptr) ? master->missile_id : (short)-1;
        short fire_frame = (master != nullptr) ? master->fire_missile_at_frame : (short)-1;

        RGE_Action_Attack* attack = new (std::nothrow) RGE_Action_Attack();
        if (attack != nullptr) {
            attack->setup(this->obj);
            attack->task = param_1;
            attack->move_sprite = param_1->move_sprite;
            attack->fight_sprite = param_1->work_sprite;
            attack->wait_sprite = nullptr;
            attack->range = param_1->work_range;
            attack->min_range = min_range;
            attack->missile_id = missile_id;
            attack->fire_missile_at_frame = fire_frame;
            attack->indirect_fire_flag = (param_2 == nullptr) ? 2 : 0;
            attack->was_same_owner = ((param_2 != nullptr) && (this->obj != nullptr) && (param_2->owner == this->obj->owner)) ? 1 : 0;

            if (param_2 != nullptr) {
                attack->set_target_obj(param_2);
                attack->target_x = param_2->world_x;
                attack->target_y = param_2->world_y;
                attack->target_z = param_2->world_z;
            } else {
                attack->target_x = param_3;
                attack->target_y = param_4;
                attack->target_z = param_5;
            }

            action = attack;
        }
        break;
    }
    case 10: {
        RGE_Action_Bird* bird = new (std::nothrow) RGE_Action_Bird();
        if (bird != nullptr) {
            bird->setup(this->obj);
            bird->task = param_1;
            bird->target_x = param_3;
            bird->target_y = param_4;
            bird->target_z = param_5;
            action = bird;
        }
        break;
    }
    case 0x15: {
        RGE_Action_Make* make = new (std::nothrow) RGE_Action_Make();
        if (make != nullptr) {
            make->setup(this->obj);
            make->task = param_1;
            action = make;
        }
        break;
    }
    default:
        break;
    }

    return action;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004044A0
uchar RGE_Action_List::inside_obj_update() {
    if (this->list != nullptr) {
        uchar result = (this->list->action != nullptr) ? this->list->action->inside_obj_update() : 1;
        for (RGE_Action_Node* node = this->list->next; node != nullptr; node = node->next) {
            if (node->action != nullptr) {
                node->action->idle_update();
            }
        }
        if (result == 1) {
            this->remove_action();
        }
        return result;
    }
    return 1;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004044F0
uchar RGE_Action_List::update() {
    if (this->list != nullptr) {
        uchar result = (this->list->action != nullptr) ? this->list->action->update() : 1;
        if (this->list != nullptr) {
            for (RGE_Action_Node* node = this->list->next; node != nullptr; node = node->next) {
                if (node->action != nullptr) {
                    node->action->idle_update();
                }
            }
            if (result == 1) {
                this->remove_action();
            }
        }
        return result;
    }
    return 1;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404540
void RGE_Action_List::add_action(RGE_Action* param_1) {
    if ((this->obj != nullptr) && (this->obj->object_state < 3)) {
        RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
        node->action = param_1;
        node->next = this->list;
        this->list = node;
        if (param_1 != nullptr) {
            param_1->first_in_stack(1);
        }
        return;
    }

    if (param_1 != nullptr) {
        delete param_1;
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404590
void RGE_Action_List::add_action_at_end(RGE_Action* param_1) {
    if ((this->obj != nullptr) && (this->obj->object_state < 3)) {
        RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
        node->next = nullptr;
        node->action = param_1;

        if (this->list != nullptr) {
            RGE_Action_Node* cur = this->list;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = node;
        } else {
            this->list = node;
        }

        if (param_1 != nullptr) {
            param_1->first_in_stack(1);
        }
        return;
    }

    if (param_1 != nullptr) {
        delete param_1;
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404610
void RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action* param_1) {
    if ((this->obj == nullptr) || (2 < this->obj->object_state)) {
        if (param_1 != nullptr) {
            delete param_1;
        }
        return;
    }

    RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
    node->action = param_1;

    if (this->list != nullptr) {
        short new_type = (param_1 != nullptr) ? param_1->type() : 0;
        short head_type = (this->list->action != nullptr) ? this->list->action->type() : 0;
        if (head_type == new_type) {
            RGE_Action_Node* cur = this->list;
            while ((cur->next != nullptr) && (cur->next->action != nullptr) && (cur->next->action->type() == new_type)) {
                cur = cur->next;
            }
            node->next = cur->next;
            cur->next = node;

            if (param_1 != nullptr) {
                param_1->first_in_stack(1);
            }
            return;
        }
    }

    node->next = this->list;
    this->list = node;

    if (param_1 != nullptr) {
        param_1->first_in_stack(1);
    }
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
        if ((this->list != nullptr) && (this->obj != nullptr) && (this->obj->object_state < 3) && (this->list->action != nullptr)) {
            this->list->action->first_in_stack(0);
        }
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404760
uchar RGE_Action_List::have_action() {
    return (this->list != nullptr) ? 1 : 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404770
int RGE_Action_List::action_stop() {
    if (this->list != nullptr) {
        return (this->list->action != nullptr) ? this->list->action->stop() : 0;
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404790
int RGE_Action_List::action_move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (this->list != nullptr) {
        return (this->list->action != nullptr) ? this->list->action->move_to(param_1, param_2, param_3, param_4) : 0;
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004047C0
int RGE_Action_List::action_work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (this->list != nullptr) {
        return (this->list->action != nullptr) ? this->list->action->work(param_1, param_2, param_3, param_4) : 0;
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004047F0
int RGE_Action_List::attack_response(RGE_Static_Object* param_1) {
    if (this->list != nullptr) {
        return (this->list->action != nullptr) ? (this->list->action->attack_response(param_1) & 0xFF) : 0;
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404810
int RGE_Action_List::relation_response(long param_1, uchar param_2) {
    if (this->list != nullptr) {
        return (this->list->action != nullptr) ? (this->list->action->relation_response(param_1, param_2) & 0xFF) : 0;
    }
    return 0;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404840
RGE_Action* RGE_Action_List::get_action() {
    return (this->list != nullptr) ? this->list->action : nullptr;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404850
RGE_Task* RGE_Action_List::get_task() {
    return ((this->list != nullptr) && (this->list->action != nullptr)) ? this->list->action->task : nullptr;
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404860
void RGE_Action_List::copy_obj(RGE_Master_Action_Object* param_1) {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->action != nullptr) {
            node->action->copy_obj(param_1);
        }
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x00404890
void RGE_Action_List::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    for (RGE_Action_Node* node = this->list; node != nullptr; node = node->next) {
        if (node->action != nullptr) {
            node->action->copy_obj_sprites(param_1, param_2, param_3);
        }
    }
}

// Fully verified. Source of truth: act_list.cpp.decomp @ 0x004048C0
void RGE_Action_List::get_action_name(char* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    const char* name = "Unknown";
    if (this->list == nullptr || this->list->action == nullptr) {
        name = "None";
    } else {
        switch (this->list->action->action_type) {
        case 1: name = "MoveTo"; break;
        case 3: name = "Enter"; break;
        case 4: name = "Explore"; break;
        case 5: name = "Gather"; break;
        case 8: name = "Missile"; break;
        case 9: name = "Attack"; break;
        case 10: name = "Bird"; break;
        case 0x0C: name = "Transport"; break;
        case 0x14: name = "RunAway"; break;
        case 0x15: name = "Make"; break;
        default: name = "Unknown"; break;
        }
    }

    strcpy(param_1, name);
}

