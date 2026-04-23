class RGE_Active_Animated_Sprite {
public:
    char gap_00[0x14];
    short frame;
    char gap_16[0xA];
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;

    unsigned char frame_passed(short param_1);
};

unsigned char RGE_Active_Animated_Sprite::frame_passed(short param_1) {
    if (this->frame_changed != 0) {
        if (this->frame_looped != 0) {
            return 1;
        }
        if ((param_1 <= this->frame) && (this->last_frame < param_1)) {
            return 1;
        }
    }
    return 0;
}
