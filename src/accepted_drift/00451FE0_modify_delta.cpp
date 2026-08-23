#ifndef RGE_MO_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual void modify_delta(float value, unsigned char attribute);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char gap_04[0xB4];
    float speed;

    void modify_delta(float value, unsigned char attribute);
};

class RGE_Sprite;

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;

    void modify_delta(float value, unsigned char attribute);
};
#endif

void RGE_Master_Moving_Object::modify_delta(float value, unsigned char attribute) {
    if (attribute != 6) {
        RGE_Master_Animated_Object::modify_delta(value, attribute);
        return;
    }
    float turn_speed = value;
    turn_speed += this->turn_speed;
    this->turn_speed = turn_speed;
}
