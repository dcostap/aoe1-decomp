class RGE_Sprite;

class RGE_Active_Sprite {
public:
    virtual void destroy();
    void* sprite;
    char type;
    char gap_09[3];
    int offset_x;
    int offset_y;

    RGE_Active_Sprite(RGE_Sprite* param);
};

RGE_Active_Sprite::RGE_Active_Sprite(RGE_Sprite* param) {
    sprite = param;
    type = 1;
    offset_x = 0;
    offset_y = 0;
}
