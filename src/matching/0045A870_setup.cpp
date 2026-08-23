// VA: 0045A870 RGE_Missile_Object::setup (5-param variant)
// PDB source: misl_obj.cpp

#include <stdlib.h>

struct RGE_Combat_Object_setup_5 {
    char base[0x1C8];
    int setup(void* param1, void* param2, float param3, float param4, float param5);
};

#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
struct RGE_Missile_Object {
    char base[0x1C8];
    int setup(void* param1, void* param2, float param3, float param4, float param5);
};
#endif

int RGE_Missile_Object::setup(void* param1, void* param2, float param3, float param4, float param5)
{
    ((RGE_Combat_Object_setup_5*)this)->setup(param1, param2, param3, param4, param5);
    *(unsigned char*)((char*)this + 0x4E) = 0x3C;
    return 1;
}
