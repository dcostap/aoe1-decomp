// VA: 0045A910 RGE_Missile_Object::save
// PDB source: misl_obj.cpp

#include <stdlib.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

struct RGE_Combat_Object_save {
    char base[0x1C8];
    void save(int fd);
};

#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
struct RGE_Missile_Object {
    char base[0x1C8];
    void save(int fd);
};
#endif

void RGE_Missile_Object::save(int fd)
{
    ((RGE_Combat_Object_save*)this)->save(fd);
    rge_write(fd, (char*)this + 0x1C4, 4);
}
