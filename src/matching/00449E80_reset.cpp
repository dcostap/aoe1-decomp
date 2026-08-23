// 00449E80 RGE_Flic_Player::reset
// flics.cpp lines 216-218

#ifndef FLICS_SHARED_CONTEXT
class RGE_Flic_Player {
public:
    char gap_00[0x5C];
    char* oframe1;            // +0x5C in the object
    char* oframe2;            // +0x60 in the object
    void reset();
};
#endif

void RGE_Flic_Player::reset() {
#ifdef FLICS_SHARED_CONTEXT
    this->flichead.oframe2 = this->flichead.oframe1;
#else
    this->oframe2 = this->oframe1;
#endif
}
