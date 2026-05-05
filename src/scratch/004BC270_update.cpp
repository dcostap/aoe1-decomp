// VA: 004BC270 RGE_Sound::update

class TDigital {
public:
    void unload(void);
};

class RGE_Sound_Info {
public:
    char name[13];
    char pad_0[0x3];
    long resource_id;
    short percent;
    char pad_1[0x2];
    TDigital* digital_sound;
    unsigned char loaded;
    char pad_2[0x3];
    unsigned long time;
};

class RGE_Sound {
public:
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info* sounds;
    unsigned long cache_time;
    short id;

    void update(unsigned long now);
};

void RGE_Sound::update(unsigned long now) {
    short count = this->sound_num;
    if (count <= 0) {
        return;
    }
    if (this->cache_time == 0) {
        return;
    }
    int i = 0;
    if (count <= 0) {
        return;
    }
    int offset = 0;
    do {
                RGE_Sound_Info* entry = (RGE_Sound_Info*)((char*)this->sounds + offset);
                if (entry->loaded == 1 && (now - entry->time) > this->cache_time) {
                    entry->digital_sound->unload();
                    ((RGE_Sound_Info*)((char*)this->sounds + offset))->loaded = 2;
                }
                ++i;
                offset += 0x24;
    } while (i < this->sound_num);
}
