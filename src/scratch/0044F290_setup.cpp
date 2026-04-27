// VA: 0044F290 RGE_Master_Action_Object::setup (rge_read variant)
// PDB source: m_ac_obj.cpp
// Attempt log:
// First-pass skeleton/partial — needs proper implementation
// - 302 bytes, rge_read-based setup with version check + indexed lookups + virtual call
// - Complex due to __thiscall sized-struct for helper + virtual call convention
// - Left in scratch

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

struct RGE_Master_Moving_Object_rsetup {
    char base[0xD8];
    int rsetup(int fd, void** sprites, void** sounds, short a);
};

struct RGE_Master_Action_Object {
    char pad[0xD8];
    int rsetup(int fd, void** sprites, void** sounds, short a);
};

int RGE_Master_Action_Object::rsetup(int fd, void** sprites, void** sounds, short a)
{
    ((RGE_Master_Moving_Object_rsetup*)this)->rsetup(fd, sprites, sounds, a);
    *(unsigned char*)((char*)this + 4) = 0x28;
    return 1;
}
