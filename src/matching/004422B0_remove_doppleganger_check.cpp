// 004422B0 RGE_Doppleganger_Creator::remove_doppleganger_check (dpl_obj.cpp:589-623)
// Attempt 1: natural C++ with class layout from type dump

#include <stdio.h>

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

int RGE_Doppleganger_Creator::remove_doppleganger_check(RGE_Static_Object* obj)
{
    if (DDlogf) {
        fprintf(DDlogf, "RDC (@%d)  p=%d  id=%d\n",
                owner->world->world_time, owner->id, obj->id);
    }

    if (active_size <= 0)
        return 0;

    for (int i = 0; i < active_size; i++) {
        if (Objects[i] == obj) {
            active_size--;
            if (i < active_size) {
                Objects[i] = Objects[active_size];
                Map_Addresses[i] = Map_Addresses[active_size];
                Last_Map_Value[i] = Last_Map_Value[active_size];
                Object_ids[i] = Object_ids[active_size];
            }
            Objects[active_size] = 0;
            Map_Addresses[active_size] = 0;
            Last_Map_Value[active_size] = 0;
            Object_ids[active_size] = 0;
            return 1;
        }
    }

    return 0;
}
