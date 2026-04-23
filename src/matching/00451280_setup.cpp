struct _iobuf;
class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Animated_Object {
public:
    virtual void vf00(void);
    int setup(_iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value);
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    unsigned char field_04;
    char gap_05[0x9F];
    unsigned char field_A4;

    int setup(_iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value);
};

int RGE_Master_Doppleganger_Object::setup(_iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value) {
    RGE_Master_Animated_Object::setup(file, sprites, sounds, value);
    this->field_04 = 0x19;
    this->field_A4 = 1;
    return 1;
}
