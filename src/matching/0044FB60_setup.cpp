// first pass: delegate to the static-object setup, stamp the type byte, then read 4 bytes of speed
// if this misses, the remaining mismatch is likely only in the prolog/stack layout around the three incoming args

extern "C" void __cdecl rge_read(int handle, void* buffer, int count);

class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    int setup(int handle, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    unsigned char field_04;
    char gap_05[0xB3];
    int speed;

    int setup(int handle, RGE_Sprite** sprites, RGE_Sound** sounds);
};

int RGE_Master_Animated_Object::setup(int handle, RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Static_Object::setup(handle, sprites, sounds);
    this->field_04 = 0x14;
    rge_read(handle, &this->speed, 4);
    return 1;
}
