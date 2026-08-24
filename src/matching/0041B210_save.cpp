// RGE_Active_Animated_Sprite::save (0041B210, 124 bytes, asprite.cpp)
// Attempt 1

#ifndef ASPRITE_FULL_TU
void rge_write(int param_1, void* param_2, int param_3);

class RGE_Active_Sprite {
public:
    void save(int param_1);
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    char gap_00[0x14];
    short frame;
    char gap_16[0x2];
    int animate_interval;
    int animate_last;
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;
    unsigned char animate_flag;

    void save(int param_1);
};
#endif

void RGE_Active_Animated_Sprite::save(int param_1) {
    RGE_Active_Sprite::save(param_1);
    rge_write(param_1, &this->frame, 2);
    rge_write(param_1, &this->animate_interval, 4);
    rge_write(param_1, &this->animate_last, 4);
    rge_write(param_1, &this->last_frame, 2);
    rge_write(param_1, &this->frame_changed, 1);
    rge_write(param_1, &this->frame_looped, 1);
    rge_write(param_1, &this->animate_flag, 1);
}
