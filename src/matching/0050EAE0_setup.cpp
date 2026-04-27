// VA: 0050EAE0 TRIBE_Master_Combat_Object::setup (copy-setup)
// PDB source: tm_co_ob.cpp

#include <stdlib.h>

#pragma pack(push, 1)
struct AttributeCost {
    short type;
    short amount;
    short flag;
};
#pragma pack(pop)

struct RGE_Master_Combat_Object_copy_setup {
    char base[0x148];
    int setup(void* src);
};

struct TRIBE_Master_Combat_Object {
    char base_000[0x148];
    AttributeCost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    short orig_pierce_armor;
    
    int setup(TRIBE_Master_Combat_Object* src);
};

int TRIBE_Master_Combat_Object::setup(TRIBE_Master_Combat_Object* src)
{
    ((RGE_Master_Combat_Object_copy_setup*)this)->setup(src);
    
    *(unsigned char*)((char*)this + 4) = 0x46;
    
    int i;
    for (i = 0; i < 3; i++)
        build_inventory[i] = src->build_inventory[i];
    
    build_pts_required = src->build_pts_required;
    id_of_building_obj = src->id_of_building_obj;
    button_location = src->button_location;
    orig_pierce_armor = src->orig_pierce_armor;
    
    return 1;
}
