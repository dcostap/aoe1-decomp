#include "../com_obj_phase2_context.h"

RGE_Combat_Object::RGE_Combat_Object(int handle, RGE_Game_World* world, int do_setup)
    : RGE_Action_Object(handle, world, 0) {
    if (do_setup != 0) {
        setup(handle, world);
    }
}
