// VA: 0041B560 frame_passed (44B, asprite.cpp)

class RGE_Active_Animated_Sprite {
public:
    char gap_00[0x14];
    short frame;              // +0x14
    char gap_16[0x0A];
    short last_frame;         // +0x20
    unsigned char frame_changed; // +0x22
    unsigned char frame_looped;  // +0x23

    unsigned char frame_passed(short param_1);
};

unsigned char RGE_Active_Animated_Sprite::frame_passed(short param_1) {
    if (this->frame_changed == 0) return 0;
    if (this->frame_looped != 0) return 1;
    if (param_1 <= this->frame && this->last_frame < param_1) return 1;
    return 0;
}
