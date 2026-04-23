class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    int setup(RGE_Master_Static_Object* other);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    unsigned char field_04;
    char gap_05[0xB3];
    int speed;

    int setup(RGE_Master_Animated_Object* other);
};

int RGE_Master_Animated_Object::setup(RGE_Master_Animated_Object* other) {
    RGE_Master_Static_Object::setup(other);
    this->field_04 = 0x14;
    this->speed = other->speed;
    return 1;
}
