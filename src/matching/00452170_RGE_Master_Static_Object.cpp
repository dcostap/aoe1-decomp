class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(int value, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    int setup(int value, RGE_Sprite** sprites, RGE_Sound** sounds);
};

RGE_Master_Static_Object::RGE_Master_Static_Object(int value, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup) {
    if (do_setup) {
        setup(value, sprites, sounds);
    }
}
