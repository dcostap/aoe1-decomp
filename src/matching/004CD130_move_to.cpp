#ifndef AOE1_TACT_ART_TU_CONTEXT
#include "../../include/tact_art_context.h"
#endif

int TRIBE_Action_Artifact::move_to(RGE_Static_Object* obj, float x, float y, float z) {
    this->move_x = x;
    this->move_y = y;
    this->move_z = z;
    this->set_state(4);
    return 1;
}
