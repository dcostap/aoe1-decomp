#ifndef ASPRITE_FULL_TU
class RGE_Active_Sprite {
public:
    virtual unsigned char frame_passed(short param_1);
};
#endif

unsigned char RGE_Active_Sprite::frame_passed(short param_1) {
    return 0;
}
