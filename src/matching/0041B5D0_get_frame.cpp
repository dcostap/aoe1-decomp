#ifndef ASPRITE_FULL_TU
class RGE_Sprite {
public:
    int get_frame(short* a, short* b, short* c, short* d, long e, int frame);
};

class RGE_Active_Animated_Sprite {
public:
    RGE_Sprite* sprite;
    char gap_08[0x0C];
    short frame;

    virtual unsigned char get_frame(short* a, short* b, short* c, short* d, long e);
};
#endif

unsigned char RGE_Active_Animated_Sprite::get_frame(short* a, short* b, short* c, short* d, long e) {
    return (unsigned char)this->sprite->get_frame(a, b, c, d, e, (int)this->frame);
}
