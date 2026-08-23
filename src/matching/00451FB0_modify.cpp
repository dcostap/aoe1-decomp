#ifndef RGE_MO_OBJ_SHARED_CONTEXT
class RGE_Master_Animated_Object {
public:
    virtual void modify(float value, unsigned char attribute);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_04[0xC0];
    float turn_speed;

    void modify(float value, unsigned char attribute);
};
#endif

void RGE_Master_Moving_Object::modify(float value, unsigned char attribute) {
    if (attribute != 6) {
        RGE_Master_Animated_Object::modify(value, attribute);
        return;
    }
    this->turn_speed = value;
}
