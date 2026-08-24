#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::connect2()
{
    TRIBE_Building_Object* checks[4];

    if (object_info) {
        if (*(short*)((char*)object_info + 0x60) == 3) {
            check(checks);
            TRIBE_Building_Object* a = checks[0];
            TRIBE_Building_Object* c = checks[2];
            TRIBE_Building_Object* b = checks[1];
            TRIBE_Building_Object* d = checks[3];

            if (a && d) {
                if (!b && !c) {
                    rotate(1 - facet);
                    return;
                }
            }
            if (b && c) {
                if (!a && !d) {
                    rotate(-facet);
                    return;
                }
            }
            rotate(2 - facet);
            return;
        }
        facet = 0;
    }
}
