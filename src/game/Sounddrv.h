#pragma once
#include "common.h"

class TDigital {
public:
    TSound_Driver* sound_system;             // 0x0
    TDigital* owner;                         // 0x4
    uchar loaded;                            // 0x8
    uchar failed;                            // 0x9
    char sound_file[13];                     // 0xA
    long resource_id;                        // 0x18
    long volume;                             // 0x1C
    ulong pitch;                             // 0x20
    long pan;                                // 0x24
    int loop;                                // 0x28
    uchar* wave_data;                        // 0x2C
    tWAVEFORMATEX* wave_info;                // 0x30
    IDirectSoundBuffer* sound_buffer;        // 0x34
    ulong data_size;                         // 0x38

    TDigital(TSound_Driver* param_1, char* param_2, long param_3);
    TDigital(TDigital* param_1);
    void exit();
    ~TDigital();
    void init_vars();
    void exit();
    int load(char* param_1, long param_2);
    void unload();
    int play();
    void stop();
    void set_loop(short param_1);
    void set_volume(long param_1);
    void set_pitch(ulong param_1);
    void set_pan(long param_1);
    int is_playing();
    int add_to_play_list();
};

static_assert(sizeof(TDigital) == 0x3C, "TDigital Size Mismatch");

class TSound_Driver {
public:
    uchar ready;                             // 0x0
    uchar mute;                              // 0x1
    void* main_wnd;                          // 0x4
    IDirectSound* direct_sound;              // 0x8
    IDirectSoundBuffer* primary_buffer;      // 0xC
    long dsrval;                             // 0x10
    long start_volume;                       // 0x14
    long volume;                             // 0x18
    char path[260];                          // 0x1C
    int mixer_open;                          // 0x120
    void* mixer_handle;                      // 0x124
    tagMIXERLINEA mixer_line_info;           // 0x128
    tagMIXERLINECONTROLSA mixer_line_controls; // 0x1D0
    tagMIXERCONTROLA mixer_volume_control;   // 0x1E8
    tMIXERCONTROLDETAILS mixer_volume_details; // 0x27C
    tMIXERCONTROLDETAILS_UNSIGNED mixer_volume_value; // 0x294
    TDigital* sound_play_list[256];          // 0x298
    int play_list_count;                     // 0x698

    TSound_Driver();
    TSound_Driver(void* param_1, char* param_2);
    void exit();
    ~TSound_Driver();
    void init_vars();
    int init(void* param_1, char* param_2);
    void exit();
    void set_path(char* param_1);
    int driver_active();
    long get_volume();
    void set_volume(long param_1, int param_2);
    int stream_file(char* param_1, int param_2, long param_3);
    int set_stream_volume(long param_1);
    int pause_stream();
    int resume_stream();
    int stop_stream();
    uint handle_messages(void* param_1, uint param_2, uint param_3, long param_4);
    int add_to_play_list(TDigital* param_1);
    void play_list();
    void reset_play_list();
    int open_mixer();
    void close_mixer();
};

static_assert(sizeof(TSound_Driver) == 0x69C, "TSound_Driver Size Mismatch");

