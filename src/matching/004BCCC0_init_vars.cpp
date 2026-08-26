#ifndef SOUNDDRV_CANONICAL_TU
typedef unsigned char uchar;

class TDigital {
public:
    void init_vars(void);
    void* sound_system;
    TDigital* owner;
    uchar loaded;
    uchar failed;
    char sound_file[13];
    uchar gap_17;
    long resource_id;
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    uchar* wave_data;
    void* wave_info;
    void* sound_buffer;
    unsigned long data_size;
};
#endif

void TDigital::init_vars(void) {
    this->sound_system = 0;
    this->owner = 0;
    this->loaded = 0;
    this->failed = 0;
    this->sound_file[0] = 0;
    this->wave_data = 0;
    this->wave_info = 0;
    this->sound_buffer = 0;
    this->data_size = 0;
    this->volume = 0;
    this->pitch = 0;
    this->pan = 0;
    this->loop = 0;
}
