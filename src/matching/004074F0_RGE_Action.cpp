#include "../../include/action_context.h"

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
