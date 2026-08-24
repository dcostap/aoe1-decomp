#ifndef SOUNDDRV_CANONICAL_TU
struct BaseClass_004BC590 {
    BaseClass_004BC590();
};

class TSound_Driver : public BaseClass_004BC590 {
public:
    TSound_Driver();
};

TSound_Driver::TSound_Driver() : BaseClass_004BC590() {
}
#else
TSound_Driver::TSound_Driver() {
    this->init_vars();
}
#endif
