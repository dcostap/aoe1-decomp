// VA: 00460DB0 boundAngle (243B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0x1E0 - 4];
    
    float boundAngle(float angle);
};

float RGE_Moving_Object::boundAngle(float angle) {
    return angle;
}
