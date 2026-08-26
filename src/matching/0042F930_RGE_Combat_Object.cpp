#include "../com_obj_phase2_context.h"

RGE_Combat_Object::RGE_Combat_Object(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z, int do_setup)
    : RGE_Action_Object(master_obj, player, x, y, z, 0) {
    if (do_setup != 0) {
        setup(master_obj, player, x, y, z);
    }
}
