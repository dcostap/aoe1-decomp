// first pass: delegate to the static-object setup, stamp the type byte, then read 4 bytes of speed
// if this misses, the remaining mismatch is likely only in the prolog/stack layout around the three incoming args

#ifndef RGE_MAN_OBJ_SHARED_CONTEXT
extern "C" void __cdecl rge_read(int handle, void* buffer, int count);
#endif

class RGE_Sprite;
class RGE_Sound;

#ifndef RGE_MAN_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    int setup(int handle, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    unsigned char master_type;
    char gap_05[0xB3];
    int speed;

protected:
    int setup(int handle, RGE_Sprite** sprites, RGE_Sound** sounds);
};
#endif

int RGE_Master_Animated_Object::setup(int handle, RGE_Sprite** sprites, RGE_Sound** sounds) {
    RGE_Master_Static_Object::setup(handle, sprites, sounds);
    this->master_type = 0x14;
    rge_read(handle, &this->speed, 4);
    return 1;
}
