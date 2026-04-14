class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    unsigned char frame_passed(int p0);
};

unsigned char RGE_Active_Sprite::frame_passed(int p0) { return 0; }
