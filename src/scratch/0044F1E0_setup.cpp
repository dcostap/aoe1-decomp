// VA: 0044F1E0 RGE_Master_Action_Object::setup (copy-from-master variant)
// PDB source: m_ac_obj.cpp
// tried: original function-pointer vtable call used __fastcall and inserted xor edx,edx before call.
// fixed by using a padded virtual helper surface for vtable slot +0x38 (thiscall, no EDX setup).

#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
struct RGE_Master_Moving_Object_copy_setup {
    char base[0xD8];
    void copy_setup(void* src);
};

struct CopyRefHelper {
    char base[4];
    void copy_obj(void* src);
};

class VTable38Helper {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void* make_task_list(); // slot +0x38
};

struct RGE_Master_Action_Object {
    char pad[0xD8];
    int setup(RGE_Master_Action_Object* src);
};
#endif

int RGE_Master_Action_Object::setup(RGE_Master_Action_Object* src) {
    ((RGE_Master_Moving_Object_copy_setup*)this)->copy_setup((void*)src);
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
    void* val = ((VTable38Helper*)this)->make_task_list();
    *(int*)((char*)this + 0xD8) = (int)val;
    ((CopyRefHelper*)val)->copy_obj((void*)*(int*)((char*)src + 0xD8));
    return 1;
}
