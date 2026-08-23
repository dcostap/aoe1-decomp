// 00449DF0 RGE_Flic_Player::resolution
// flics.cpp lines 175-180

#ifndef FLICS_SHARED_CONTEXT
class RGE_Flic_Player {
public:
    char gap_00[0x10];
    short width;              // flichead.width at +0x10
    short height;             // flichead.height at +0x12
    long resolution();
};
#endif

long RGE_Flic_Player::resolution() {
#ifdef FLICS_SHARED_CONTEXT
    // BINARY NOTE: The adjacent FLIC packet shorts are read as one typed span.
    // VC5 emits width first, then height, as in the shipped owner.
    short* fields = &this->flichead.height;
    long height = fields[0];
    long width = fields[-1];
    return (width << 16) | height;
#else
    return ((long)this->width << 16) | (short)this->height;
#endif
}
