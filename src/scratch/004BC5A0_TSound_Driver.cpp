#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver_ctor {
public:
    TSound_Driver_ctor* ctor(int device, int config);
    void init_vars(void);
    void init_system(int device, int config);
};

TSound_Driver_ctor* TSound_Driver_ctor::ctor(int device, int config) {
    this->init_vars();
    this->init_system(device, config);
    return this;
}
#else
TSound_Driver::TSound_Driver(void* window, char* path) {
    this->init_vars();
    this->init(window, path);
}
#endif
