#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver_td;

class TDigital_ctor {
public:
    TDigital_ctor* ctor(TSound_Driver_td* owner);
    void init_vars(void);
    char gap_00[0x04];
    TSound_Driver_td* parent;
    char gap_08[0x14];
    int volume;
    int pitch;
    int pan;
    int loop_flag;
};

TDigital_ctor* TDigital_ctor::ctor(TSound_Driver_td* owner) {
    this->init_vars();
    this->parent = owner;
    this->volume = *(int*)((char*)owner + 0x1C);
    this->pitch = *(int*)((char*)owner + 0x20);
    this->pan = *(int*)((char*)owner + 0x24);
    this->loop_flag = *(int*)((char*)owner + 0x28);
    return this;
}
#else
TDigital::TDigital(TDigital* owner) {
    this->init_vars();
    this->owner = owner;
    this->volume = owner->volume;
    this->pitch = owner->pitch;
    this->pan = owner->pan;
    this->loop = owner->loop;
}
#endif
