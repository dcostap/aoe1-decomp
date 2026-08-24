#ifndef ASPRITE_FULL_TU
class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Animated_Sprite();
};
#endif

RGE_Active_Animated_Sprite::~RGE_Active_Animated_Sprite() {
}
