// attempt 1: EH-framed missile-object ctor with base combat ctor, vptr set, optional setup, and fixed flag byte
// blocker watch: if this sticks, the first probes are the base-ctor surface and whether VC5 wants the local object kept as a natural derived class or a flatter ctor stub
#include "..\..\include\game_types.h"

class RGE_Game_World;

#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3);
};

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    float max_range;

    RGE_Missile_Object(int param_1, RGE_Game_World* param_2, int param_3);
    int setup(int param_1, RGE_Game_World* param_2);
};
#endif

RGE_Missile_Object::RGE_Missile_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Combat_Object(param_1, param_2, 0) {
    *(void**)this = (void*)0x5706F0;
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
    *((unsigned char*)this + 0x4E) = 0x3C;
}
