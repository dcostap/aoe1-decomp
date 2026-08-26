#ifndef RGE_MS_OBJ_SHARED_CONTEXT
struct _iobuf;
class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(_iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value, int doSetup);

protected:
    int setup(_iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value);
};
#endif

RGE_Master_Static_Object::RGE_Master_Static_Object(_iobuf* file, RGE_Sprite** sprites, RGE_Sound** sounds, short value, int doSetup) {
    if (doSetup != 0) {
        this->setup(file, sprites, sounds, value);
    }
}
