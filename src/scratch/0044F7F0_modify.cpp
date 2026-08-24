#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Master_Static_Object {
public:
    virtual void modify(float value, unsigned char attribute);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char gap_04[0xB4];
    float speed;

    void modify(float value, unsigned char attribute);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;

    void modify(float value, unsigned char attribute);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_04[0x1C];
    float work_rate;

    void modify(float value, unsigned char attribute);
};
#endif

void RGE_Master_Action_Object::modify(float value, unsigned char attribute) {
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify(value, attribute);
        return;
    }
    this->work_rate = value;
}
