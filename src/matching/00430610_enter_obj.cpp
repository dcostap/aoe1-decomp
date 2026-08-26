// BINARY NOTE: The first call is the inherited RGE_Static_Object::enter_obj
// body at 004C58E0.  The old RGE_Base_Object static shim added caller cleanup
// and escaped the 00430610 boundary.
// Exact-finish walkback: the shim rebuilt 108 bytes with an 81-byte mismatch;
// the qualified inherited call rebuilt 105 exact bytes.

class RGE_Static_Object;
class RGE_Player;
class Visible_Unit_Manager;

extern "C" Visible_Unit_Manager* VisibleUnitManager;

#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::enter_obj(RGE_Static_Object* obj) {
    RGE_Static_Object::enter_obj(obj);
    if (inside_obj != 0) {
        if (id >= 0) {
            VisibleUnitManager->Update_Unit_Info(id, owner->id, (int)world_x, (int)world_y, master_obj->object_group, Unified_Map_Value, 0, VUR_Ptrs);
            Unified_Map_Value = 0;
        }
    }
}
