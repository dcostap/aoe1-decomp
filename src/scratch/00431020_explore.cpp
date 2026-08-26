// VA: 00431020, RGE_Combat_Object::explore, 298 bytes
// Source: com_obj.cpp lines 1046-1091
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

#include "../com_obj_phase2_context.h"

int RGE_Combat_Object::explore(int param_1, int param_2, int param_3)
{
    if (param_3 == 0) {
        if (actions->have_action() == 1) {
            RGE_Action* action = (RGE_Action*)actions->get_action();
            if (action->type() == 4)
                goto done;
        }
    }

    if (actions->have_action() == 1) {
        RGE_Action* action = (RGE_Action*)actions->get_action();
        if (action->type() == 4) {
            action = (RGE_Action*)actions->get_action();
            action->work(this, (float)param_1, (float)param_2, 0);
            goto done;
        }
    }

    {
        RGE_Action_Explore* explore_action = new RGE_Action_Explore(this, 0, (float)param_1, (float)param_2, *(float*)&field_40);
        if (explore_action == 0)
            return 0;

        actions->delete_list();
        this->set_action(explore_action);
    }

done:
    return 1;
}
