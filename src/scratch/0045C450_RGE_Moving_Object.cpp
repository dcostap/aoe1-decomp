// VA: 0045C450 RGE_Moving_Object ctor (333B)
// move_obj.cpp lines 96-112

class RGE_Animated_Object {
public:
    virtual ~RGE_Animated_Object();
    char gap0[0x10];
    void* gameObj;
    char gap14[0x24];
    float x, y;
    char gap40[0x5C];
    float rotOffset;
    char gapA0[4];
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    char fields[0x1E0 - 0xA4];
    
    RGE_Moving_Object(int a1, int a2, int a3, int a4);
};

void __cdecl Path_ctor(void* path, int size);

RGE_Moving_Object::RGE_Moving_Object(int a1, int a2, int a3, int a4) {
    Path_ctor((char*)this + 0xA4, 10);
    Path_ctor((char*)this + 0xD8, 10);
    *(int*)((char*)this + 0x148) = 2;
    *(int*)((char*)this + 0x14C) = -1;
    *(int*)((char*)this + 0x150) = -1;
    *(char*)((char*)this + 0x154) = 1;
    *(char*)((char*)this + 0x155) = 1;
    *(char*)((char*)this + 0x156) = 1;
    *(int*)((char*)this + 0x168) = 0;
    *(int*)((char*)this + 0x16C) = 0;
    *(int*)((char*)this + 0x170) = 0;
    *(char*)((char*)this + 0x174) = 0;
    *(int*)((char*)this + 0x10C) = 0;
    *(int*)((char*)this + 0x110) = 0;
    *(int*)((char*)this + 0x114) = 0;
    *(int*)((char*)this + 0x12C) = 0;
    *(char*)((char*)this + 0x17C) = -1;
    *(char*)((char*)this + 0x17D) = -1;
}
