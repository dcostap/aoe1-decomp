// VA: 004CA570 TRIBE_Combat_Object::save (124 B)
// PDB source: t_c_obj.cpp

#include <stdlib.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

struct RGE_Combat_Object_base {
    char base[0x1C4];
    void save(int fd);
};

// Master object: with RTTI: vt[-1], vt[0] then vt[1-4]=4 stubs, vt[5]=save=0x14
struct MasterObj {
    char base[4];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void save(int fd);
};

// Child object: vt[1]=save=4
struct ChildObj {
    char base[4];
    virtual void f0();
    virtual void save(int fd);
};

struct TRIBE_Combat_Object {
    char pad[0x1C4];
    unsigned char own_master;  // +0x1C4
    
    void save(int fd);
};

void TRIBE_Combat_Object::save(int fd)
{
    int flag;
    
    ((RGE_Combat_Object_base*)this)->save(fd);
    rge_write(fd, &own_master, 1);
    
    if (own_master) {
        ((MasterObj*)(*(int*)((char*)this + 8)))->save(fd);
    }
    
    if (*(int*)((char*)this + 0x74)) {
        flag = 1;
        rge_write(fd, &flag, 4);
        ((ChildObj*)(*(int*)((char*)this + 0x74)))->save(fd);
    } else {
        flag = 0;
        rge_write(fd, &flag, 4);
    }
}
