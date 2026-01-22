#pragma once
#include "common.h"

struct TSound_Driver {
    uchar ready;
    uchar mute;
    unsigned char _pad_0[0x2]; // 0x0002 (Gap: 2)
    void* main_wnd;
    IDirectSound* direct_sound;
    IDirectSoundBuffer* primary_buffer;
    long dsrval;
    long start_volume;
    long volume;
    char path[260];
    int mixer_open;
    void* mixer_handle;
    tagMIXERLINEA mixer_line_info;
    tagMIXERLINECONTROLSA mixer_line_controls;
    tagMIXERCONTROLA mixer_volume_control;
    tMIXERCONTROLDETAILS mixer_volume_details;
    tMIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;
    TDigital* sound_play_list[256];
    int play_list_count;
};
static_assert(sizeof(TSound_Driver) == 0x69C, "Size mismatch");
