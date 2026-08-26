#ifndef ANI_OBJ_SHARED_CONTEXT
#include "../../include/ani_obj_context.h"
#endif

// BINARY NOTE: PDB owner is protected RGE_Animated_Object::setup in ani_obj.cpp,
// lines 67-75. The prior setup body is 0041A2C0-0041A302. This body is
// 0041A310-0041A342; the next function starts at 0041A350.
int RGE_Animated_Object::setup(int file, RGE_Game_World* world) {
    RGE_Static_Object::setup(file, world);
#ifdef ANI_OBJ_SHARED_CONTEXT
    this->type = 0x14;
#else
    this->field_4E = 0x14;
#endif
    rge_read(file, &this->speed, 4);
    return 1;
}
