class RGE_Active_Animated_Sprite {
public:
    char gap_00[0x14];
    short frame;
    char gap_16[0x0A];
    short last_frame;
    char frame_changed;

    void setToFirstFrame();
};

void RGE_Active_Animated_Sprite::setToFirstFrame() {
    frame_changed = 1;
    last_frame = frame;
    frame = 0;
}
