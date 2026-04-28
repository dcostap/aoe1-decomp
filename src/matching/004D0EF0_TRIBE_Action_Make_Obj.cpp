// 004D0EF0 TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj
// Size: 119 bytes
// FLAGS: /GX (EH frame)

#include <stdio.h>

class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    char gap_04[4];
    RGE_Action_Object* obj;  // +0x08
    char gap_0C[0x34];
    short obj_id;            // +0x40
    char gap_42[0x06];
    int unique_id;           // +0x48
};

class RGE_Action_Object {
public:
    char gap_00[4];
    void* field_04;          // +0x04
    char gap_08[4];
    void* field_0C;          // +0x0C
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    virtual ~TRIBE_Action_Make_Obj();
    char gap_4C[0x300];
};

TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj() {
    void* obj_field_0C = *(void**)((char*)this->obj + 0x0C);
    int field_3C_4 = *(int*)(*(int*)((char*)obj_field_0C + 0x3C) + 4);
    int obj_field_4 = (int)this->obj->field_04;
    (*(void(__cdecl*)(void*, const char*, int, int, int, int))(
        *(int*)(*(int*)obj_field_0C + 0xE4)))(
        obj_field_0C, (const char*)0x587634, field_3C_4, (int)this->obj_id, obj_field_4, this->unique_id);
}
