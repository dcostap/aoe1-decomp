// VA: 00451530 RGE_Master_Missile_Object::RGE_Master_Missile_Object
// PDB source: m_mi_obj.cpp

#include <stdio.h>
#include <stdlib.h>

struct RGE_Master_Missile_Object;

// Base ctor as member function on a sized struct
struct RGE_Master_Combat_Object_6 {
    char fields[0x148];
    void ctor(void* a, void* b, void* c, short d, int e);
};

struct RGE_Master_Missile_Object {
    char gap_000[0x154];
    int setup(FILE* param_1, void** param_2, void** param_3, short param_4);
    RGE_Master_Missile_Object(FILE* param_1, void** param_2, void** param_3, short param_4, int do_setup);
};

RGE_Master_Missile_Object::RGE_Master_Missile_Object(FILE* param_1, void** param_2, void** param_3, short param_4, int do_setup)
{
    ((RGE_Master_Combat_Object_6*)this)->ctor(param_1, param_2, param_3, param_4, 0);
    *(int*)this = 0x570560;
    if (do_setup) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}
