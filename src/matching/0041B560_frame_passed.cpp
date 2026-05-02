// VA: 0041B560 frame_passed (44B, asprite.cpp)
// Match exact label order: ret1 is fallthrough, ret0 is jump target

class RGE_Active_Animated_Sprite {
public:
    char gap_00[0x14];
    short frame;              // +0x14
    char gap_16[0x0A];
    short last_frame;         // +0x20
    unsigned char frame_changed; // +0x22
    unsigned char frame_looped;  // +0x23

    int frame_passed(short param_1);
};

int RGE_Active_Animated_Sprite::frame_passed(short param_1) {
    if (this->frame_changed == 0) goto ret0;
    if (this->frame_looped != 0) goto ret1;
    if (this->frame < param_1) goto ret0;
    if (this->last_frame < param_1) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
