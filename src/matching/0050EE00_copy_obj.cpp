// VA: 0050EE00 TRIBE_Master_Combat_Object::copy_obj
// PDB source: tm_co_ob.cpp

#include <stdlib.h>

#ifndef TM_CO_OB_SHARED_CONTEXT
#pragma pack(push, 1)
struct AttributeCost {
    short type;     // 0
    short amount;   // 2
    short flag;     // 4
};
#pragma pack(pop)

struct RGE_Master_Combat_Object_copy {
    char base[0x148];
    void copy_obj(void* src);
};

struct TRIBE_Master_Combat_Object {
    char base_000[0x148];
    AttributeCost build_inventory[3];  // +0x148
    short build_pts_required;           // +0x15A
    short id_of_building_obj;           // +0x15C
    unsigned char button_location;      // +0x15E
    short orig_pierce_armor;            // +0x160

    void copy_obj(void* src);
};
#endif

#ifdef TM_CO_OB_SHARED_CONTEXT
void TRIBE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* src)
#else
void TRIBE_Master_Combat_Object::copy_obj(void* src)
#endif
{
    ((RGE_Master_Combat_Object_copy*)this)->copy_obj(src);
    
    TRIBE_Master_Combat_Object* s = (TRIBE_Master_Combat_Object*)src;
    
    int i;
    for (i = 0; i < 3; i++)
        build_inventory[i] = s->build_inventory[i];
    
    build_pts_required = s->build_pts_required;
    id_of_building_obj = s->id_of_building_obj;
    button_location = s->button_location;
    orig_pierce_armor = s->orig_pierce_armor;
}
