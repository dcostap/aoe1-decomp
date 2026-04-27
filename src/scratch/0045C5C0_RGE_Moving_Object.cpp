// VA: 0045C5C0 RGE_Moving_Object ctor from game object (308B)
// move_obj.cpp

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
    
    RGE_Moving_Object(void* obj, int a2, int a3, int a4);
};

void __cdecl Path_ctor(void* path, int size);

RGE_Moving_Object::RGE_Moving_Object(void* obj, int a2, int a3, int a4) {
    Path_ctor((char*)this + 0xA4, 10);
    Path_ctor((char*)this + 0xD8, 10);
}
