#ifndef FLICS_SHARED_CONTEXT
class RGE_Flic_Player {
public:
    virtual ~RGE_Flic_Player();
    char gap_0[0xA];
    short field_E;
    short frames();
};
#endif

short RGE_Flic_Player::frames() {
#ifdef FLICS_SHARED_CONTEXT
    return this->flichead.frames;
#else
    return this->field_E;
#endif
}
