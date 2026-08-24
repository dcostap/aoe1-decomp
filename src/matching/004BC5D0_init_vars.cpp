#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char ready;
    unsigned char mute;
    char gap_02[0x02];
    void* main_wnd;
    void* direct_sound;
    void* primary_buffer;
    int dsrval;
    int start_volume;
    int volume;
    unsigned char path[0x104];
    int mixer_open;
    void* mixer_handle;
    char gap_128[0x570];
    int play_list_count;

    void init_vars(void);
};
#endif

void TSound_Driver::init_vars(void) {
    this->start_volume = 1;
    this->ready = 0;
    this->main_wnd = 0;
    this->direct_sound = 0;
    this->primary_buffer = 0;
    this->dsrval = 0;
    this->mute = 0;
    this->play_list_count = 0;
    this->volume = 0;
    this->mixer_open = 0;
    this->mixer_handle = 0;
    this->path[0] = 0;
}
