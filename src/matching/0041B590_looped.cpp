#ifndef ASPRITE_FULL_TU
class RGE_Active_Animated_Sprite {
public:
    virtual ~RGE_Active_Animated_Sprite();
    char gap_0[0x1F];
    unsigned char field_23;
    unsigned char looped();
};
#endif

#ifdef ASPRITE_FULL_TU
unsigned char RGE_Active_Animated_Sprite::looped() { return this->frame_looped; }
#else
unsigned char RGE_Active_Animated_Sprite::looped() { return this->field_23; }
#endif
