#ifndef SOUNDDRV_CANONICAL_TU
class TDigital {
public:
    void init_vars(void);
    char gap_00[0x04];
    TDigital* owner;
    char gap_08[0x14];
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    TDigital(TDigital* owner);
};
#endif

TDigital::TDigital(TDigital* owner) {
    this->init_vars();
    this->owner = owner;
    this->volume = owner->volume;
    this->pitch = owner->pitch;
    this->pan = owner->pan;
    this->loop = owner->loop;
}
