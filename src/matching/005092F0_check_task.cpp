#include "../../include/task_lst_context.h"

// VA: 005092F0 RGE_Task_List::check_task
// PDB source: task_lst.cpp, lines 252-297
//
// The owner-type switch keeps the shipped branch topology.  Case five shares
// the failure return with the preceding guards, as shown by the executable.

int RGE_Task_List::check_task(RGE_Task* task,
                               RGE_Action_Object* action_obj,
                               RGE_Static_Object* static_obj)
{
    if (task->holding_attr == 1) {
        if (static_obj->attribute_type_held == -1 ||
            static_obj->attribute_amount_held <= DAT_00576544)
            return 0;
    }

    switch (task->owner_type) {
    case 1:
        if (static_obj->owner != action_obj->owner)
            return 0;
        break;

    case 2:
        if (static_obj->owner != action_obj->owner) {
            if (static_obj->owner->id != 0) {
                if (!action_obj->owner->relation(static_obj->owner->id))
                    return 0;
                break;
            }
        }
        return 0;

    case 3:
        if (static_obj->owner->id == 0)
            break;
        return 0;

    case 4:
        if (static_obj->owner == action_obj->owner)
            return 1;
        if (static_obj->owner->id != 0) {
            if (action_obj->owner->isAlly(static_obj->owner->id)) {
                if (static_obj->owner->isAlly(action_obj->owner->id))
                    return 1;
            }
        }
        return 0;

    case 5:
        if (static_obj->owner == action_obj->owner)
            goto case5_failure;
        if (static_obj->owner->id != 0) {
            if (!action_obj->owner->relation(static_obj->owner->id))
                goto case5_failure;
        }
        if (static_obj->owner->id == 0 &&
            action_obj->master_obj->combat_level == 0)
            goto case5_failure;
        break;

    case5_failure:
        return 0;
    }

    return (int)(action_obj != static_obj);
}
