// first pass: direct count-gated unload loop over the RGE_Sound_Info array
// tried the flatter/smaller pointer shapes too; the remaining gap stays in the prolog/register basin, not the loop logic
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
    short count;
    int offset;
    unsigned long current_time;

    if (this->sound_num <= 0) {
        return;
    }
    if (this->cache_time == 0) {
        return;
    }

    count = 0;
    offset = 0;
    current_time = now;
    do {
        RGE_Sound_Info* entry = (RGE_Sound_Info*)((char*)this->sounds + offset);
        if (entry->loaded == 1) {
            if ((current_time - entry->time) > this->cache_time) {
                entry->digital_sound->unload();
                entry->loaded = 2;
            }
        }
        ++count;
        offset += 0x24;
    } while (count < this->sound_num);
}
