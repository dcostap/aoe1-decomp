#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    virtual ~TSound_Driver();
    char gap_0[0x14];
    int field_18;
    int get_volume();
};
#endif

#ifndef SOUNDDRV_CANONICAL_TU
int TSound_Driver::get_volume() { return this->field_18; }
#else
long TSound_Driver::get_volume() { return this->volume; }
#endif
