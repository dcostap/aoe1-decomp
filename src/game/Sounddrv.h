#pragma once
#include "../common.h"

class TDigital {
public:
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
    virtual ~TDigital();
    virtual void init_vars();
    virtual void exit();
    virtual int load(char* param_1, long param_2);
    virtual void unload();
    virtual int play();
    virtual void stop();
    virtual void set_loop(short param_1);
    virtual void set_volume(long param_1);
    virtual void set_pitch(ulong param_1);
    virtual void set_pan(long param_1);
    virtual int is_playing();
    virtual int add_to_play_list();
};

static_assert(sizeof(TDigital) == 0x3C, "TDigital Size Mismatch");
static_assert(offsetof(TDigital, data_size) == 0x38, "TDigital Offset Mismatch");

class TSound_Driver {
public:
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
    virtual ~TSound_Driver();
    virtual void init_vars();
    virtual int init(void* param_1, char* param_2);
    virtual void exit();
    virtual void set_path(char* param_1);
    virtual int driver_active();
    virtual long get_volume();
    virtual void set_volume(long param_1, int param_2);
    virtual int stream_file(char* param_1, int param_2, long param_3);
    virtual int set_stream_volume(long param_1);
    virtual int pause_stream();
    virtual int resume_stream();
    virtual int stop_stream();
    virtual uint handle_messages(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int add_to_play_list(TDigital* param_1);
    virtual void play_list();
    virtual void reset_play_list();
    virtual int open_mixer();
    virtual void close_mixer();
};

static_assert(sizeof(TSound_Driver) == 0x69C, "TSound_Driver Size Mismatch");
static_assert(offsetof(TSound_Driver, play_list_count) == 0x698, "TSound_Driver Offset Mismatch");

