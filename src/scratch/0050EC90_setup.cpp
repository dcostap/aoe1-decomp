// VA: 0050EC90 TRIBE_Master_Combat_Object::setup (file-read setup)
// PDB source: tm_co_ob.cpp
// Attempt log:
// - 160/257 bytes (push ecx/fscanf basin - same as other file-read setups)
// - Complex: loop reading 3 AttributeCost + fscanf for fields + data loop for max values
// - Left in scratch

#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
struct AttributeCost {
    short type;
    short amount;
    short flag;
};
#pragma pack(pop)

struct RGE_Master_Combat_Object_setup_file {
    char base[0x148];
    int setup(FILE* f, void** sprites, void** sounds, short a);
};

struct TRIBE_Master_Combat_Object {
    char base_000[0x148];
    AttributeCost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    short orig_pierce_armor;

    int setup(FILE* f, void** sprites, void** sounds, short a);
};

int TRIBE_Master_Combat_Object::setup(FILE* f, void** sprites, void** sounds, short a)
{
    ((RGE_Master_Combat_Object_setup_file*)this)->setup(f, sprites, sounds, a);
    
    *(unsigned char*)((char*)this + 4) = 0x46;
    
    // Read 3 Attribute_Cost entries
    int i;
    for (i = 0; i < 3; i++) {
        short t1, t2;
        fscanf(f, "%hd %hd", &t1, &t2);
        build_inventory[i].type = t1;
        build_inventory[i].amount = t2;
        build_inventory[i].flag = 0;
    }
    
    fscanf(f, "%hd %hd %hhd", &build_pts_required, &id_of_building_obj, &button_location);
    
    orig_pierce_armor = 0;
    
    return 1;
}
