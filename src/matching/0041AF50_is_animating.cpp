class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    unsigned char is_animating();
};

unsigned char RGE_Active_Sprite::is_animating() { return 0; }
