#include <stdio.h>

#ifndef RGE_MAN_OBJ_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Sound;
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    unsigned char master_type;
    char gap_05[0xB3];
    float speed;

protected:
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
};
#endif

int RGE_Master_Animated_Object::setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count) {
    RGE_Master_Static_Object::setup(file, sprites, sounds, count);
    this->master_type = 0x14;
    fscanf(file, "%f", &this->speed);
    return 1;
}
