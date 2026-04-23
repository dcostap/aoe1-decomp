class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    int setup(int count, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    unsigned char field_04;

    int setup(int count, RGE_Sprite** sprites, RGE_Sound** sounds);
};

int RGE_Master_Doppleganger_Object::setup(int count, RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Animated_Object::setup(count, sprites, sounds);
    this->field_04 = 0x19;
    return 1;
}
