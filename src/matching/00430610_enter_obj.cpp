class RGE_Static_Object;
class RGE_Player;
class Visible_Unit_Manager;

extern "C" Visible_Unit_Manager* VisibleUnitManager;

#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::enter_obj(RGE_Static_Object* obj) {
    RGE_Base_Object::enter_obj(obj);
    if (inside_obj != 0) {
        if (id >= 0) {
            VisibleUnitManager->Update_Unit_Info(id, owner->id, (int)world_x, (int)world_y, master_obj->object_group, Unified_Map_Value, 0, VUR_Ptrs);
            Unified_Map_Value = 0;
        }
    }
}
