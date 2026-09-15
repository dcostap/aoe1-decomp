#ifndef AOE1_MUSIC_H
#define AOE1_MUSIC_H

#include <windows.h>
#include <mmsystem.h>
#include "sounddrv.h"

class TMusic_System {
public:
    char path[260];
    unsigned char music_type;
    unsigned char _pad_0[3];
    TSound_Driver* sound_system;
    void* instance;
    void* window;
    int device_open;
    unsigned int device_id;
    MCI_PLAY_PARMS play_info;
    unsigned char playing_track;
    char file_name[261];
    unsigned char _pad_1[2];
    int start_track;
    int end_track;
    int make_cur_track;
    unsigned long set_pos;
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
    unsigned long fade_time;
    int fading_track;
    long fade_volume;
    unsigned long last_fade_time;
    int mixer_open;
    HMIXER mixer_handle;
    MIXERLINEA mixer_line_info;
    MIXERLINECONTROLSA mixer_line_controls;
    MIXERCONTROLA mixer_volume_control;
    MIXERCONTROLDETAILS mixer_volume_details;
    MIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;
    void* midi_window;
    unsigned long last_check_time;

    TMusic_System(unsigned char music_type_in, void* instance_in, void* window_in,
        TSound_Driver* sound_system_in, char* path_in);
    ~TMusic_System();
    int open_device();
    void close_device();
protected:
    int open_mixer();
    void close_mixer();
public:
    int set_music_type(unsigned char music_type_in);
    void set_fade_out(int fade_out_in, unsigned long fade_time_in);
    void set_volume(long volume_in, int permanent);
    int play_track(int track_in, int loop_in, unsigned long set_pos_in);
    int play_file(char* file_name_in, int loop_in, unsigned long set_pos_in);
    int play_tracks(int start_track_in, int end_track_in, int loop_in,
        int make_cur_track_in, unsigned long set_pos_in);
protected:
    int play(int start_track_in, int end_track_in, char* file_name_in,
        int make_cur_track_in, unsigned long set_pos_in);
public:
    int pause_play();
    int resume_play();
    int stop_track();
protected:
    int stop_playing();
public:
    int fade_track();
protected:
    void start_fade();
    void do_fade();
    void end_fade();
public:
    unsigned int handle_messages(void* wnd, unsigned int msg, unsigned int wparam, long lparam);
protected:
    void after_end_track();
public:
    int get_play_info(unsigned char* music_type_in, int* track_from_in,
        int* track_to_in, int* cur_track_in, char* music_file_in,
        int* loop_in, unsigned long* pos_in);
};

#endif
