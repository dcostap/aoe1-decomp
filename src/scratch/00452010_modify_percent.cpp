class RGE_Master_Animated_Object {
public:
    virtual void modify_percent(float value, unsigned char attribute);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_04[0xC0];
    float turn_speed;

    void modify_percent(float value, unsigned char attribute);
};

void RGE_Master_Moving_Object::modify_percent(float value, unsigned char attribute) {
    if (attribute != 6) {
        RGE_Master_Animated_Object::modify_percent(value, attribute);
        return;
    }
    this->turn_speed = value * this->turn_speed;
}
