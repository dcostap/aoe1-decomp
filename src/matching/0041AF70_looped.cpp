class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    unsigned char looped();
};

unsigned char RGE_Active_Sprite::looped() { return 0; }
