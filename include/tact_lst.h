#ifndef AOE1_TACT_LST_H
#define AOE1_TACT_LST_H

// Canonical owner declarations for C:\\msdev\\work\\age1_x1\\tact_lst.cpp.
// Shared action, action-list, node, and task ownership comes from the
// canonical engine headers. This module owns only TRIBE_Action_List.

#include "action.h"
#include "act_list.h"
#include "task.h"

class TRIBE_Action_List : public RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*,
                                            float, float, float);
    virtual void get_action_name(char*);

    TRIBE_Action_List(RGE_Action_Object*);
};

typedef char tact_lst_action_list_size_check[
    (sizeof(TRIBE_Action_List) == 0x0C) ? 1 : -1];

#endif  // AOE1_TACT_LST_H
