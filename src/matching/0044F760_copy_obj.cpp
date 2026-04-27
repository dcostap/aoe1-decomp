// VA: 0044F760 RGE_Master_Action_Object::copy_obj
// PDB source: m_ac_obj.cpp

#include <stdlib.h>

struct RGE_Master_Moving_Object_copy {
    char base[0xD8];
    void copy_obj(void* src);
};

struct CopyRefHelper {
    char base[4];
    void copy_obj(void* src);
};

struct RGE_Master_Action_Object {
    char pad[0xD8];
    void copy_obj(void* src);
};

void RGE_Master_Action_Object::copy_obj(void* src)
{
    ((RGE_Master_Moving_Object_copy*)this)->copy_obj(src);
    *(short*)((char*)this + 0xDC) = *(short*)((char*)src + 0xDC);
    *(int*)((char*)this + 0xE0) = *(int*)((char*)src + 0xE0);
    *(int*)((char*)this + 0xE4) = *(int*)((char*)src + 0xE4);
    *(short*)((char*)this + 0xE8) = *(short*)((char*)src + 0xE8);
    *(short*)((char*)this + 0xEA) = *(short*)((char*)src + 0xEA);
    *(unsigned char*)((char*)this + 0xEC) = *(unsigned char*)((char*)src + 0xEC);
    *(int*)((char*)this + 0xF0) = *(int*)((char*)src + 0xF0);
    *(int*)((char*)this + 0xF4) = *(int*)((char*)src + 0xF4);
    ((CopyRefHelper*)(*(int*)((char*)this + 0xD8)))->copy_obj((void*)*(int*)((char*)src + 0xD8));
}
