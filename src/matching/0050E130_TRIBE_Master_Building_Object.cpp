// VA: 0050E130 TRIBE_Master_Building_Object::TRIBE_Master_Building_Object (EH-framed)
// PDB source: tm_b_obj.cpp
#include "..\..\include\tm_b_obj_context.h"

#ifndef TM_B_OBJ_SHARED_CONTEXT
class TRIBE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();
    TRIBE_Master_Combat_Object(void* file, void* sprites, void* sounds, short id, int flag);
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    TRIBE_Master_Building_Object(void* file, void* sprites, void* sounds, short id, int flag);
    int setup(void* file, void* sprites, void* sounds, short id);
};
#endif

#ifdef TM_B_OBJ_SHARED_CONTEXT
TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id, int flag)
#else
TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(void* file, void* sprites, void* sounds, short id, int flag)
#endif
    : TRIBE_Master_Combat_Object(file, sprites, sounds, id, 0)
{
    *(void**)this = (void*)0x576700;
    if (flag != 0) {
        this->setup(file, sprites, sounds, id);
    }
}
