// VA: 0041B560 frame_passed (44B, asprite.cpp)
// The two return labels preserve the shipped branch layout.

#ifndef ASPRITE_FULL_TU
class RGE_Active_Animated_Sprite {
public:
    virtual ~RGE_Active_Animated_Sprite();
    char gap_04[0x10];
    short frame;
    char gap_16[0x0A];
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;

    virtual unsigned char frame_passed(short param_1);
};
#endif

unsigned char RGE_Active_Animated_Sprite::frame_passed(short param_1) {
    if (this->frame_changed == 0) goto ret0;
    if (this->frame_looped != 0) goto ret1;
    if (this->frame < param_1) goto ret0;
    if (this->last_frame < param_1) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
