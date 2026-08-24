#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char field_0;
    int driver_active();
};
#endif

#ifndef SOUNDDRV_CANONICAL_TU
int TSound_Driver::driver_active() { return this->field_0; }
#else
int TSound_Driver::driver_active() { return this->ready; }
#endif
