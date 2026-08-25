// VA: 00431340, RGE_Combat_Object::unload, 254 bytes
// Source: com_obj.cpp lines 1178-1215
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stddef.h>

typedef unsigned char uchar;

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_unload.h"
#endif

int RGE_Combat_Object::unload(int param_1, float param_2, float param_3, float param_4)
{
    if (actions->have_action() == 1) {
        RGE_Action* action = (RGE_Action*)actions->get_action();
        if (action->type() == 0x0C) {
            // Call get_action() again. The original does this.
            RGE_Action* action2 = (RGE_Action*)actions->get_action();
            action2->work((RGE_Static_Object*)this, world_x, world_y, world_z);
            return 1;
        }
    }

    RGE_Action_Transport* transport = new RGE_Action_Transport(this, 0, world_x, world_y, world_z);
    if (transport == 0) {
        return 0;
    }

    actions->delete_list();
    this->set_only_action(transport);
    transport->work((RGE_Static_Object*)this, param_2, param_3, param_4);
    return 1;
}
