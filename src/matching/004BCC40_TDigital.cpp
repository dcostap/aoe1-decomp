char* strncpy(char* dest, const char* src, unsigned int count);

#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver;
class TDigital {
public:
    TSound_Driver* sound_system;
    char gap_04[0x06];
    char sound_file[0x0D];
    char gap_17[0x01];
    long resource_id;

    void init_vars(void);
    TDigital(TSound_Driver* driver, char* file, long resource_id);
};
#endif

TDigital::TDigital(TSound_Driver* driver, char* file, long resource_id) {
    this->init_vars();
    this->sound_system = driver;
    this->resource_id = resource_id;
    if (file != 0) {
        strncpy(this->sound_file, file, 0x0C);
        this->sound_file[0x0C] = 0;
    }
}
