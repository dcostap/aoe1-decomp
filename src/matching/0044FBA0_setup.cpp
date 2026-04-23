class RGE_Sprite;
class RGE_Sound;
#include <stdio.h>

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    unsigned char type;
    char gap_05[0xB3];
    float speed;

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
};

int RGE_Master_Animated_Object::setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count) {
    RGE_Master_Static_Object::setup(file, sprites, sounds, count);
    this->type = 0x14;
    fscanf(file, "%f", &this->speed);
    return 1;
}
