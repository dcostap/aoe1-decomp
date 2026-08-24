#ifndef ASPRITE_FULL_TU
class RGE_Active_Animated_Sprite {
public:
    char gap_00[0x14];
    short frame;
    void set_frame(short value);
};
#endif

void RGE_Active_Animated_Sprite::set_frame(short value) {
    this->frame = value;
}
