#ifndef RGE_MAN_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    int setup(RGE_Master_Static_Object* other);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    unsigned char master_type;
    char gap_05[0xB3];
    int speed;

protected:
    int setup(RGE_Master_Animated_Object* other);
};
#endif

int RGE_Master_Animated_Object::setup(RGE_Master_Animated_Object* other) {
    RGE_Master_Static_Object::setup(other);
    this->master_type = 0x14;
    this->speed = other->speed;
    return 1;
}
