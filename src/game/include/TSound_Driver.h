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

    TSound_Driver();
    TSound_Driver(void* wnd, char* path);
    ~TSound_Driver();
    void init_vars();
    int init(void* wnd, char* path);
    void exit();
    void set_path(char* path);
    int driver_active();
    long get_volume();
    void set_volume(long vol, int save);
    int stream_file(char* filename, int loop, long volume);
    int set_stream_volume(long vol);
    int pause_stream();
    int resume_stream();
    int stop_stream();
    uint handle_messages(void* hwnd, uint msg, uint wParam, long lParam);
    int add_to_play_list(TDigital* digital);
    void play_list();
    void reset_play_list();
    int open_mixer();
    void close_mixer();
};
static_assert(sizeof(TSound_Driver) == 0x69C, "Size mismatch");
