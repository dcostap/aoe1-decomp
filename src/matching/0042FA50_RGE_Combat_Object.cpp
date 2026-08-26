#include "../com_obj_phase2_context.h"

RGE_Combat_Object::~RGE_Combat_Object() {
    if (id >= 0) {
        VisibleUnitManager->Update_Unit_Info(id, owner->id, (int)world_x, (int)world_y, master_obj->object_group, Unified_Map_Value, 0, VUR_Ptrs);
    }
}
