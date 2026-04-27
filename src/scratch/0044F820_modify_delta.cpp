class RGE_Master_Moving_Object {
public:
    virtual void modify_delta(float value, unsigned char attribute);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_04[0xE0];
    float work_rate;

    void modify_delta(float value, unsigned char attribute);
};

void RGE_Master_Action_Object::modify_delta(float value, unsigned char attribute) {
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify_delta(value, attribute);
        return;
    }
    this->work_rate = value + this->work_rate;
}
