#ifndef ASPRITE_FULL_TU
class RGE_Sprite {
public:
    char gap_00[0x70];
    unsigned char flags;
};

class RGE_Active_Animated_Sprite {
public:
    virtual ~RGE_Active_Animated_Sprite();
    RGE_Sprite* sprite;
    char gap_08[0x1C];
    unsigned char animate_flag;

    virtual unsigned char is_animating();
};
#endif

unsigned char RGE_Active_Animated_Sprite::is_animating() {
    if (this->animate_flag == 0 || (this->sprite->flags & 1) == 0) {
        return 0;
    }
    return 1;
}
