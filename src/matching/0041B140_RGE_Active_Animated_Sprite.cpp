void rge_read(int handle, void* buffer, int size);

class RGE_Sprite;

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    short frame;
    long animate_interval;
    long animate_last;
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;
    unsigned char animate_flag;

    RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2);
};

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2)
    : RGE_Active_Sprite(param_1, param_2) {
    this->type = 2;
    rge_read(param_1, &this->frame, 2);
    rge_read(param_1, &this->animate_interval, 4);
    rge_read(param_1, &this->animate_last, 4);
    rge_read(param_1, &this->last_frame, 2);
    rge_read(param_1, &this->frame_changed, 1);
    rge_read(param_1, &this->frame_looped, 1);
    rge_read(param_1, &this->animate_flag, 1);
}
