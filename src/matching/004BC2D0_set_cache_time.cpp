#ifndef SOUND_CANONICAL_TU
class RGE_Sound_Info;
class RGE_Sound {
public:
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info* sounds;
    unsigned long cache_time;
    short id;
    void set_cache_time(unsigned long v);
};
#endif

void RGE_Sound::set_cache_time(unsigned long v) { this->cache_time = v; }
