class RGE_Active_Animated_Sprite {
public:
    virtual ~RGE_Active_Animated_Sprite();
    char gap_0[0x10];
    short field_14;
    short what_frame();
};

short RGE_Active_Animated_Sprite::what_frame() { return this->field_14; }
