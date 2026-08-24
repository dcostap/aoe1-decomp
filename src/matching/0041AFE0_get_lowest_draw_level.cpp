#ifndef ASPRITE_FULL_TU
class RGE_Sprite;

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();

    RGE_Sprite* sprite;

    unsigned char get_lowest_draw_level();
};

class RGE_Sprite {
public:
    unsigned char get_lowest_draw_level();
};
#endif

unsigned char RGE_Active_Sprite::get_lowest_draw_level() {
    if (this->sprite != 0) {
        return this->sprite->get_lowest_draw_level();
    }
    return 0x14;
}
