struct _iobuf;
class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Static_Object {
public:
    virtual void vf00(void);
    RGE_Master_Static_Object(_iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value, int doSetup);
    int setup(_iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value);
};

RGE_Master_Static_Object::RGE_Master_Static_Object(_iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value, int doSetup) {
    if (doSetup != 0) {
        this->setup(file, sprites, sounds, value);
    }
}
