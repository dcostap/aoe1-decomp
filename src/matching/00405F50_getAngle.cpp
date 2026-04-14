class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x98];
    float field_9C;
    float getAngle();
};

float RGE_Moving_Object::getAngle() { return this->field_9C; }
