class TDigital;

class RGE_Sound_Info {
public:
    char name[13];
    unsigned char _pad_0[0x3];
    long resource_id;
    short percent;
    unsigned char _pad_1[0x2];
    TDigital* digital_sound;
    unsigned char loaded;
    unsigned char _pad_2[0x3];
    unsigned long time;
};

class RGE_Sound {
public:
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info* sounds;
    unsigned long cache_time;
    short id;

    void stop();
};

class TDigital {
public:
    int is_playing();
    void stop();
};

void RGE_Sound::stop() {
    int i;

    if (this->sound_num > 0) {
        for (i = 0; i < this->sound_num; i++) {
            if ((this->sounds[i].digital_sound != 0) && this->sounds[i].digital_sound->is_playing()) {
                this->sounds[i].digital_sound->stop();
            }
        }
    }
}
