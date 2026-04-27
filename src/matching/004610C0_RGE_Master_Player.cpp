// VA: 004610C0 RGE_Master_Player::RGE_Master_Player (rge_read ctor, 134 B)
// PDB source: mst_play.cpp

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

struct RGE_Master_Player {
    void* vtable;           // +0x00 = 0x570C08
    char name[20];          // +0x04
    short master_object_num;// +0x18
    void** master_objects;  // +0x1C
    short tribe_effect;     // +0x20 (attribute_num in some contexts)
    float* attributes;      // +0x24
    char culture;           // +0x28
    char type;              // +0x29
    short attribute_num;    // +0x2A
    
    RGE_Master_Player(int fd);
};

RGE_Master_Player::RGE_Master_Player(int fd)
{
    vtable = (void*)0x570C08;
    rge_read(fd, name, 20);
    rge_read(fd, &tribe_effect, 2);
    rge_read(fd, &attribute_num, 2);
    if (tribe_effect > 0) {
        attributes = (float*)calloc(tribe_effect, 4);
        rge_read(fd, attributes, tribe_effect * 4);
    } else {
        attributes = 0;
    }
    rge_read(fd, &culture, 1);
}
