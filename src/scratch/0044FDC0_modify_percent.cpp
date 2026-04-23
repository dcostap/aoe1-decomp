class RGE_Master_Static_Object {
public:
    virtual void modify_percent(float value, unsigned char attribute);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char gap_04[0xB4];
    float speed;

    void modify_percent(float value, unsigned char attribute);
};

void RGE_Master_Animated_Object::modify_percent(float value, unsigned char attribute) {
    if (attribute != 5) {
        RGE_Master_Static_Object::modify_percent(value, attribute);
        return;
    }
    this->speed = value * this->speed;
}
