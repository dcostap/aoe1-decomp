#ifndef FLICS_SHARED_CONTEXT
class RGE_Flic_Player {
public:
    virtual ~RGE_Flic_Player();
    char gap_0[0x14];
    int field_18;
    long time_delay();
};
#endif

long RGE_Flic_Player::time_delay() {
#ifdef FLICS_SHARED_CONTEXT
    return this->flichead.speed;
#else
    return this->field_18;
#endif
}
