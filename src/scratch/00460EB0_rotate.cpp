// VA: 00460EB0 rotate
// move_obj.cpp lines 3157-3167, 143 bytes
// RGE_Moving_Object::rotate(int)

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0x10];
    void* gameObj;              // +0x10
    char gap14[0x88];
    float rotOffset;            // +0x9C
    char gapA0[4];
    
    void rotate(int angleDeg);
};

void RGE_Moving_Object::rotate(int angleDeg) {
    void* obj;
    float rotation;
    float val;
    void** vtable;
    
    obj = gameObj;
    rotation = (float)angleDeg * 0.017453292f;
    rotation = rotation / (float)*(short*)((char*)obj + 0x60);
    rotation = rotation + rotOffset;
    
    val = rotation;
    if (val < 0.0f) {
        do {
            val += 6.283185f;
        } while (val < 0.0f);
        rotation = val;
    }
    if (rotation >= 0.017453292f) {
        do {
            rotation -= 6.283185f;
        } while (rotation >= 0.017453292f);
    }
    
    vtable = *(void***)this;
    ((void (__stdcall*)(void*, float))vtable[0x2D])(this, rotation);
}
