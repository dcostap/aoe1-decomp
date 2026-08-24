// VA: 004610C0 RGE_Master_Player::RGE_Master_Player (rge_read ctor, 134 B)
// PDB source: mst_play.cpp

#ifndef MST_PLAY_SHARED_CONTEXT
#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

struct RGE_Master_Player {
    void* vtable;           // +0x00 = 0x570C08
    char name[20];          // +0x04
    short master_object_num;// +0x18
    void** master_objects;  // +0x1C
    short attribute_num;    // +0x20
    float* attributes;      // +0x24
    char culture;           // +0x28
    char type;              // +0x29
    short tribe_effect;     // +0x2A
    
    RGE_Master_Player(int fd);
};
#endif

RGE_Master_Player::RGE_Master_Player(int fd)
{
#ifndef MST_PLAY_SHARED_CONTEXT
    vtable = (void*)0x570C08;
#endif
    rge_read(fd, name, 20);
    rge_read(fd, &attribute_num, 2);
    rge_read(fd, &tribe_effect, 2);
    if (attribute_num > 0) {
        attributes = (float*)calloc(attribute_num, 4);
        rge_read(fd, attributes, attribute_num * 4);
    } else {
        attributes = 0;
    }
    rge_read(fd, &culture, 1);
}
