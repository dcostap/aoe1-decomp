#pragma once
#include "common.h"

struct TMusic_System {
    char path[260];
    uchar music_type;
    TSound_Driver* sound_system;
    void* instance;
    void* window;
    int device_open;
    uint device_id;
    tagMCI_PLAY_PARMS play_info;
    uchar playing_track;
    char file_name[261];
    int start_track;
    int end_track;
    int make_cur_track;
    ulong set_pos;
    int loop;
    int current_track;
    int track_count;
    int notify_waiting;
    long start_volume;
    long volume;
    int paused;
    int auto_paused;
    int inactivated;
    int fade_out;
    ulong fade_time;
    int fading_track;
    long fade_volume;
    ulong last_fade_time;
    int mixer_open;
    void* mixer_handle;
    tagMIXERLINEA mixer_line_info;
    tagMIXERLINECONTROLSA mixer_line_controls;
    tagMIXERCONTROLA mixer_volume_control;
    tMIXERCONTROLDETAILS mixer_volume_details;
    tMIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;
    void* midi_window;
    ulong last_check_time;
};
static_assert(sizeof(TMusic_System) == 0x3F8, "Size mismatch");
