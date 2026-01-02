#pragma once
#include "../common.h"

class TMusic_System {
public:
    uchar music_type;                        // 0x104
    TSound_Driver* sound_system;             // 0x108
    void* instance;                          // 0x10C
    void* window;                            // 0x110
    int device_open;                         // 0x114
    uint device_id;                          // 0x118
    tagMCI_PLAY_PARMS play_info;             // 0x11C
    uchar playing_track;                     // 0x128
    char file_name[261];                     // 0x129
    int start_track;                         // 0x230
    int end_track;                           // 0x234
    int make_cur_track;                      // 0x238
    ulong set_pos;                           // 0x23C
    int loop;                                // 0x240
    int current_track;                       // 0x244
    int track_count;                         // 0x248
    int notify_waiting;                      // 0x24C
    long start_volume;                       // 0x250
    long volume;                             // 0x254
    int paused;                              // 0x258
    int auto_paused;                         // 0x25C
    int inactivated;                         // 0x260
    int fade_out;                            // 0x264
    ulong fade_time;                         // 0x268
    int fading_track;                        // 0x26C
    long fade_volume;                        // 0x270
    ulong last_fade_time;                    // 0x274
    int mixer_open;                          // 0x278
    void* mixer_handle;                      // 0x27C
    tagMIXERLINEA mixer_line_info;           // 0x280
    tagMIXERLINECONTROLSA mixer_line_controls; // 0x328
    tagMIXERCONTROLA mixer_volume_control;   // 0x340
    tMIXERCONTROLDETAILS mixer_volume_details; // 0x3D4
    tMIXERCONTROLDETAILS_UNSIGNED mixer_volume_value; // 0x3EC
    void* midi_window;                       // 0x3F0
    ulong last_check_time;                   // 0x3F4

    TMusic_System(uchar param_1, void* param_2, void* param_3, TSound_Driver* param_4, char* param_5);
    virtual ~TMusic_System();
    virtual int open_device();
    virtual void close_device();
    virtual int open_mixer();
    virtual void close_mixer();
    virtual int set_music_type(uchar param_1);
    virtual void set_fade_out(int param_1, ulong param_2);
    virtual void set_volume(long param_1, int param_2);
    virtual int play_track(int param_1, int param_2, ulong param_3);
    virtual int play_file(char* param_1, int param_2, ulong param_3);
    virtual int play_tracks(int param_1, int param_2, int param_3, int param_4, ulong param_5);
    virtual int play(int param_1, int param_2, char* param_3, int param_4, ulong param_5);
    virtual int pause_play();
    virtual int resume_play();
    virtual int stop_track();
    virtual int stop_playing();
    virtual int fade_track();
    virtual void start_fade();
    virtual void do_fade();
    virtual void end_fade();
    virtual uint handle_messages(void* param_1, uint param_2, uint param_3, long param_4);
    virtual void after_end_track();
    virtual int get_play_info(uchar* param_1, int* param_2, int* param_3, int* param_4, char* param_5, int* param_6, ulong* param_7);
};

static_assert(sizeof(TMusic_System) == 0x3F8, "TMusic_System Size Mismatch");
static_assert(offsetof(TMusic_System, last_check_time) == 0x3F4, "TMusic_System Offset Mismatch");

