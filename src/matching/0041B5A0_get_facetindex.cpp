#ifndef ASPRITE_FULL_TU
class RGE_Sprite {
public:
    void get_facetindex(int facet, int frame, long* out_index);
};

class RGE_Active_Animated_Sprite {
public:
    RGE_Sprite* sprite;
    char gap_08[0x0C];
    short frame;

    virtual short get_facetindex(short facet);
};
#endif

short RGE_Active_Animated_Sprite::get_facetindex(short facet) {
    long facet_index;

    facet_index = 0;
    this->sprite->get_facetindex((int)facet, (int)this->frame, &facet_index);
    return (short)facet_index;
}
