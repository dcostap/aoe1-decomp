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
};
static_assert(sizeof(TDigital) == 0x3C, "Size mismatch");
