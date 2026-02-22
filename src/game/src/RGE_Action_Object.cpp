#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

#include <stdlib.h>

// Default constructor
RGE_Action_Object::RGE_Action_Object()
    : RGE_Moving_Object()
{
    this->lastActionValue = -1;
    this->lastActionStateValue = -1;
    this->waiting = '\0';
    this->actions = nullptr;
    this->command_flag = '\0';
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00405F90
RGE_Action_Object::RGE_Action_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Moving_Object(param_1, param_2, 0)
{
    this->lastActionValue = -1;
    this->lastActionStateValue = -1;
    this->waiting = '\0';
    this->actions = nullptr;
    this->command_flag = '\0';

    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Source of truth: act_obj.cpp.decomp @ 0x004061A0
RGE_Action_List* RGE_Action_Object::create_action_list() {
    RGE_Action_List* pList = (RGE_Action_List*)operator new(sizeof(RGE_Action_List));
    if (pList != nullptr) {
        // TODO: RGE_Action_List constructor takes the owning action object
        // For now, zero-initialize and set obj pointer
        memset(pList, 0, sizeof(RGE_Action_List));
        pList->obj = this;
        return pList;
    }
    return nullptr;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406120
int RGE_Action_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Moving_Object::setup(param_1, param_2);
    this->type = 0x28;

    rge_read(param_1, &this->waiting, 1);

    if (save_game_version < 6.5f) {
        this->command_flag = '\0';
    } else {
        rge_read(param_1, &this->command_flag, 1);
    }

    // create_action_list is virtual (vtable offset 0x218 in original)
    this->actions = this->create_action_list();
    if (this->actions != nullptr) {
        this->actions->load(param_1);
    }

    return 1;
}
