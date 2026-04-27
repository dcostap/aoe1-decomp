// VA: 0045D150 angle_to_object
// move_obj.cpp lines 436-470, 160 bytes
// RGE_Moving_Object::angle_to_object(RGE_Game_Object*, float, float) -> float

#include <math.h>

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0x10];
    void* gameObj;      // +0x10
    char gap14[0x24];
    float _x;           // +0x38
    float _y;           // +0x3C
    char gap40[0x5C];
    float rotOffset;    // +0x9C
    
    float angle_to_object(void* target, float tx, float ty);
};

float RGE_Moving_Object::angle_to_object(void* target, float tx, float ty) {
    float dx, dy;
    float angle;
    
    if (!gameObj) return 0.0f;
    if (!(*(int*)((char*)gameObj + 0x70) & 2)) return 0.0f;
    if (*(short*)((char*)gameObj + 0x60) <= 0) return 0.0f;
    
    if (target) {
        dx = *(float*)((char*)target + 0x38) - _x;
        dy = *(float*)((char*)target + 0x3C) - _y;
    } else {
        dx = tx;
        dy = ty;
    }
    
    angle = (float)atan2((double)dx, (double)dy);
    
    if (angle < 0.0f) {
        angle += 6.283185f;
    }
    
    angle -= rotOffset;
    
    return angle;
}
