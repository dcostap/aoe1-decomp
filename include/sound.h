#ifndef AOE1_SOUND_H
#define AOE1_SOUND_H

#include <stdio.h>

class TSound_Driver;
class TDigital;

class RGE_Sound_Info {
  public:
    char name[13];
    long resource_id;
    short percent;
    TDigital* digital_sound;
    unsigned char loaded;
    unsigned long time;
};

class RGE_Sound {
  public:
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info* sounds;
    unsigned long cache_time;
    short id;

    RGE_Sound(FILE* infile, short in_id);
    RGE_Sound(int infile, TSound_Driver* sound);
    RGE_Sound();
    ~RGE_Sound();

    void save(int outfile);
    void restart_sound(TSound_Driver* sound);
    void update(unsigned long curr_time);
    void set_cache_time(unsigned long new_cache_time);
    void play_at_update();
    void update_play();
    void play(int add_to_play_list);
    char* get_file_name();
    void stop();
    int is_playing();
};

typedef char sound_rge_sound_size_check[(sizeof(RGE_Sound) == 0x10) ? 1 : -1];
typedef char sound_rge_sound_info_size_check[(sizeof(RGE_Sound_Info) == 0x24) ? 1 : -1];

#endif
