// RGE_Action_Object constructor
// VA: 00406010, size 112 bytes, EH-framed
// Source: action.cpp

#pragma pack(push, 1)
struct RGE_Action_Object {
    void** vtable;    // +0x00
    char gap_04[0x180];
    int someObjId;    // +0x184

    RGE_Action_Object();
    void sub_00403EC0();
    void sub_0045C700();
};

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

void RGE_Action_Object::sub_00403EC0() {
    ((void(__fastcall*)(void*,int))0x403EC0)(this, 0);
}

void RGE_Action_Object::sub_0045C700() {
    ((void(__fastcall*)(void*,int))0x45C700)(this, 0);
}

#pragma pack(pop)

RGE_Action_Object::RGE_Action_Object() {
    vtable = (void**)0x56E420;
    
    if (someObjId != 0) {
        sub_00403EC0();
        operator_delete((void*)someObjId);
        someObjId = 0;
    }
    
    sub_0045C700();
}
