#ifndef SOUNDDRV_CANONICAL_TU
class TDigital {
public:
    char gap_00[0x04];
    TDigital* owner;
    unsigned char loaded;

    void init_vars(void);
    void stop(void);
    void unload(void);
    void exit(void);
};
#endif

void TDigital::exit(void) {
    if (this->owner != 0) {
        this->owner->exit();
        this->init_vars();
        return;
    }
    if (this->loaded != 0) {
        this->stop();
        this->unload();
        this->init_vars();
    }
}
