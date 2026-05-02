// VA: 0044F1E0 RGE_Master_Action_Object::setup (copy-from-master variant)
// PDB source: m_ac_obj.cpp
// 18.9349% diff, 169/169 bytes - register allocation diff at vtable call

#include <stdlib.h>

struct RGE_Master_Moving_Object_copy_setup {
    char base[0xD8];
    void copy_setup(void* src);
};

struct CopyRefHelper {
    char base[4];
    void copy_obj(void* src);
};

typedef void* (__fastcall* CreateTaskListFn)(void* self, int dummy);

struct RGE_Master_Action_Object {
    char pad[0xD8];
    int setup(void* src);
};

int RGE_Master_Action_Object::setup(void* src) {
    ((RGE_Master_Moving_Object_copy_setup*)this)->copy_setup(src);
    *(unsigned char*)((char*)this + 4) = 0x28;
    *(short*)((char*)this + 0xDC) = *(short*)((char*)src + 0xDC);
    *(int*)((char*)this + 0xE0) = *(int*)((char*)src + 0xE0);
    *(int*)((char*)this + 0xE4) = *(int*)((char*)src + 0xE4);
    *(short*)((char*)this + 0xE8) = *(short*)((char*)src + 0xE8);
    *(short*)((char*)this + 0xEA) = *(short*)((char*)src + 0xEA);
    *(unsigned char*)((char*)this + 0xEC) = *(unsigned char*)((char*)src + 0xEC);
    *(int*)((char*)this + 0xF0) = *(int*)((char*)src + 0xF0);
    *(int*)((char*)this + 0xF4) = *(int*)((char*)src + 0xF4);
    *(unsigned char*)((char*)this + 0xF8) = *(unsigned char*)((char*)src + 0xF8);
    void** vtable = *(void***)this;
    void* val = ((CreateTaskListFn)vtable[0x38/4])(this, 0);
    *(int*)((char*)this + 0xD8) = (int)val;
    ((CopyRefHelper*)(*(int*)((char*)this + 0xD8)))->copy_obj((void*)*(int*)((char*)src + 0xD8));
    return 1;
}
