// BINARY NOTE: Attribute 0x0D changes work_rate. Other attributes use the
// inherited action-object path.

#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Master_Moving_Object {
public:
    virtual void modify_delta(float value, unsigned char attribute);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_04[0xE0];
    float work_rate; // +0xE4

    void modify_delta(float value, unsigned char attribute);
};
#endif

void RGE_Master_Action_Object::modify_delta(float value, unsigned char attribute) {
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify_delta(value, attribute);
    } else {
        this->work_rate = value + this->work_rate;
    }
}
