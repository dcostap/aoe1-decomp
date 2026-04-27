// VA: 0050EB60 TRIBE_Master_Combat_Object::setup (file-read via rge_read)
// PDB source: tm_co_ob.cpp
// Attempt log:
// - 256/293 bytes (37 short)
// - Missing: float-comparison dead-code block + scheduling differences
// - Correct logic: rge_read loop + field reads + 2 max-search loops over data array
// - Left in scratch

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

#pragma pack(push, 1)
struct AttributeCost {
    short type;
    short amount;
    short flag;
};
#pragma pack(pop)

struct RGE_Master_Combat_Object_setup_rge {
    char base[0x148];
    int setup(int f, void** sprites, void** sounds);
};

struct TRIBE_Master_Combat_Object {
    char base_000[0x148];
    AttributeCost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    short orig_pierce_armor;

    int setup(int f, void** sprites, void** sounds);
};

int TRIBE_Master_Combat_Object::setup(int f, void** sprites, void** sounds)
{
    ((RGE_Master_Combat_Object_setup_rge*)this)->setup(f, sprites, sounds);
    
    *(unsigned char*)((char*)this + 4) = 0x46;
    
    int i;
    for (i = 0; i < 3; i++)
        rge_read(f, (char*)build_inventory + i * 6, 6);
    
    rge_read(f, &build_pts_required, 2);
    rge_read(f, &id_of_building_obj, 2);
    rge_read(f, &button_location, 1);
    
    orig_pierce_armor = 0;
    
    int count = *(short*)((char*)this + 0x102);
    if (count > 0) {
        int* data = *(int**)((char*)this + 0x104);
        int j;
        for (j = 0; j < count; j++) {
            if (*(short*)((char*)data + j * 4) == 3) {
                short val = *(short*)((char*)data + j * 4 + 2);
                if (val > orig_pierce_armor)
                    orig_pierce_armor = val;
            }
        }
    }
    
    *(short*)((char*)this + 0x13C) = *(unsigned char*)((char*)this + 0x100);
    
    if (count > 0) {
        int* data = *(int**)((char*)this + 0x104);
        int j;
        for (j = 0; j < count; j++) {
            if (*(short*)((char*)data + j * 4) != 3) {
                short val = *(short*)((char*)data + j * 4 + 2);
                if (val > *(short*)((char*)this + 0x13C))
                    *(short*)((char*)this + 0x13C) = val;
            }
        }
    }
    
    return 1;
}
