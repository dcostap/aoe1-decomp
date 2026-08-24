#ifndef ASPRITE_FULL_TU
class RGE_Active_Sprite {
public:
    virtual unsigned char looped();
};
#endif

unsigned char RGE_Active_Sprite::looped() {
    return 0;
}
