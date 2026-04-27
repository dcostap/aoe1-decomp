// VA: 0050F090 TRIBE_Master_Combat_Object::make_new_obj
// PDB source: tm_co_ob.cpp
// Attempt log:
// - 80/122 bytes (EH frame missing, same basin as other constructors)
// - Correct body: operator_new(0x1C8) + TRIBE_Combat_Object ctor call
// - Left in scratch

#include <stdlib.h>

extern "C" {
    void* __cdecl operator_new(size_t size);
}

struct TRIBE_Combat_Object_ctor_wrapper {
    char gap[0x1C8];
    void ctor_init(void* master, void* player, float x, float y, float z, int flag);
};

struct TRIBE_Master_Combat_Object {
    char gap[0x164];
    void* make_new_obj(void* player, float x, float y, float z);
};

void* TRIBE_Master_Combat_Object::make_new_obj(void* player, float x, float y, float z)
{
    void* new_obj = operator_new(0x1C8);
    if (new_obj) {
        ((TRIBE_Combat_Object_ctor_wrapper*)new_obj)->ctor_init(this, player, x, y, z, 1);
        return new_obj;
    }
    return 0;
}
