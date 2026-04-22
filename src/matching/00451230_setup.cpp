class RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    int setup(RGE_Master_Animated_Object* object);
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    char field_04;
    char gap_05[0x60];
    char field_65;

    int setup(RGE_Master_Doppleganger_Object* object);
};

int RGE_Master_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object* object) {
    RGE_Master_Animated_Object::setup(object);
    this->field_04 = 0x19;
    this->field_65 = 3;
    return 1;
}
