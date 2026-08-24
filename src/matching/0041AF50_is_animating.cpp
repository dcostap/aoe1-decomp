#ifndef ASPRITE_FULL_TU
class RGE_Active_Sprite {
public:
    virtual unsigned char is_animating();
};
#endif

unsigned char RGE_Active_Sprite::is_animating() {
    return 0;
}
