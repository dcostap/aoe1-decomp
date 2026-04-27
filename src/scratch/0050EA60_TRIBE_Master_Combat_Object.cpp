// VA: 0050EA60 TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object (constructor)
// PDB source: tm_co_ob.cpp
// Attempt log:
// - 80/119 bytes (EH frame missing, same basin as other constructors)
// - Correct body: base ctor, vtable write, conditional setup call
// - Left in scratch

#include <stdio.h>
#include <stdlib.h>

struct RGE_Master_Combat_Object_ctor {
    char base[0x148];
    void ctor_init(FILE* f, void** sprites, void** sounds, short a, int b);
};

struct TRIBE_Master_Combat_Object {
    char base_000[0x148];
    unsigned char build_inventory[18];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    short orig_pierce_armor;
    int setup(FILE* f, void** sprites, void** sounds, short a);
    TRIBE_Master_Combat_Object(FILE* f, void** sprites, void** sounds, short a, int b);
};

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(FILE* f, void** sprites, void** sounds, short a, int b)
{
    ((RGE_Master_Combat_Object_ctor*)this)->ctor_init(f, sprites, sounds, a, 0);
    *(int*)this = 0x576740;
    if (b) {
        setup(f, sprites, sounds, a);
    }
}
