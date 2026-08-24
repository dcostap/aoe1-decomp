#ifndef ASPRITE_FULL_TU
class RGE_Sprite;

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    RGE_Active_Sprite(RGE_Sprite* sprite);
};
#endif

RGE_Active_Sprite::RGE_Active_Sprite(RGE_Sprite* sprite) {
    this->sprite = sprite;
    this->type = 1;
    this->offset_x = 0;
    this->offset_y = 0;
}
