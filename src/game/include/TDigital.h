#pragma once
#include "common.h"

struct TDigital {
    TSound_Driver* sound_system;
    TDigital* owner;
    uchar loaded;
    uchar failed;
    char sound_file[13];
    long resource_id;
    long volume;
    ulong pitch;
    long pan;
    int loop;
    uchar* wave_data;
    tWAVEFORMATEX* wave_info;
    IDirectSoundBuffer* sound_buffer;
    ulong data_size;

    TDigital(TSound_Driver* driver, char* file, long resId);
    TDigital(TDigital* owner);
    ~TDigital();
    void init_vars();
    void exit();
    int load(char* file, long resId);
    void unload();
    int play();
    void stop();
    void set_loop(short loop);
    void set_volume(long vol);
    void set_pitch(ulong pitch);
    void set_pan(long pan);
    int is_playing();
    int add_to_play_list();
};
static_assert(sizeof(TDigital) == 0x3C, "Size mismatch");
