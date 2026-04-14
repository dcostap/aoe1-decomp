class RGE_Animated_Object {
public:
    virtual ~RGE_Animated_Object();
    char gap_0[0x84];
    float field_88;
    float getSpeed();
};

float RGE_Animated_Object::getSpeed() { return this->field_88; }
