#ifndef ASPRITE_FULL_TU
class RGE_Sprite;

class RGE_Active_Sprite {
public:
    RGE_Sprite* sprite;

    virtual short get_facetindex(short param_1);
};

class RGE_Sprite {
public:
    unsigned char get_facetindex(long param_1, long param_2, long* facet_index);
};
#endif

short RGE_Active_Sprite::get_facetindex(short param_1) {
    long facet_index = 0;
    this->sprite->get_facetindex((int)param_1, 0, &facet_index);
    return (short)facet_index;
}
