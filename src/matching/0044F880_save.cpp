// VA: 0044F880 RGE_Master_Action_Object::save
// PDB source: m_ac_obj.cpp

#include <stdlib.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

struct SaveRefHelper {
    char base[4];
    void save(int fd);
};

struct RGE_Master_Moving_Object_save {
    char base[0xD8];
    void save(int fd);
};

#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
struct RGE_Master_Action_Object {
    char pad[0xD8];
    void save(int fd);
};
#endif

void RGE_Master_Action_Object::save(int fd)
{
    short temp0 = -1;
    short temp1 = -1;

    ((RGE_Master_Moving_Object_save*)this)->save(fd);

    if (*(int*)((char*)this + 0xF0)) {
        temp0 = *(short*)(*(int*)((char*)this + 0xF0) + 0xC);
    }
    if (*(int*)((char*)this + 0xF4)) {
        temp1 = *(short*)(*(int*)((char*)this + 0xF4) + 0xC);
    }

    rge_write(fd, (char*)this + 0xDC, 2);
    rge_write(fd, (char*)this + 0xE0, 4);
    rge_write(fd, (char*)this + 0xE4, 4);
    rge_write(fd, (char*)this + 0xE8, 2);
    rge_write(fd, (char*)this + 0xEA, 2);
    rge_write(fd, (char*)this + 0xEC, 1);
    rge_write(fd, &temp0, 2);
    rge_write(fd, &temp1, 2);
    rge_write(fd, (char*)this + 0xF8, 1);
    ((SaveRefHelper*)(*(int*)((char*)this + 0xD8)))->save(fd);
}
