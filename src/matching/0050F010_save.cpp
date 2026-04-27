// VA: 0050F010 TRIBE_Master_Combat_Object::save
// PDB source: tm_co_ob.cpp

#include <stdlib.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

// Range: RGE_Master_Combat_Object = 0x148 bytes
struct RGE_Master_Combat_Object_save {
    char base[0x148];
    void save(int fd);
};

struct TRIBE_Master_Combat_Object {
    char base_000[0x148];
    unsigned char build_inventory[18];  // +0x148: 3 x 6-byte Attribute_Cost
    short build_pts_required;           // +0x15A
    short id_of_building_obj;           // +0x15C
    unsigned char button_location;      // +0x15E
    short orig_pierce_armor;            // +0x160

    void save(int fd);
};

void TRIBE_Master_Combat_Object::save(int fd)
{
    ((RGE_Master_Combat_Object_save*)this)->save(fd);
    
    int i;
    for (i = 0; i < 3; i++)
        rge_write(fd, build_inventory + i * 6, 6);
    
    rge_write(fd, &build_pts_required, 2);
    rge_write(fd, &id_of_building_obj, 2);
    rge_write(fd, &button_location, 1);
    rge_write(fd, &orig_pierce_armor, 2);
}
