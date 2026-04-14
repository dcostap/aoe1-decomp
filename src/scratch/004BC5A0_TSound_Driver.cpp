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
