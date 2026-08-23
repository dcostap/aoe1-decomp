#ifndef MUSIC_CONTEXT_H
#define MUSIC_CONTEXT_H

#include <windows.h>
#include <mmsystem.h>

class TSound_Driver {
public:
    int set_stream_volume(long volume);
    int stream_file(char* file_name, int loop, long position);
    int pause_stream();
    int resume_stream();
    int stop_stream();
};

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

    TMusic_System(unsigned char type, void* instance, void* window,
                  TSound_Driver* sound_system, char* path);
    ~TMusic_System();
    int open_device();
    void close_device();
    int open_mixer();
    void close_mixer();
    int set_music_type(unsigned char type);
    void set_fade_out(int fade_out, int fade_time);
    void set_volume(long volume, int save);
    int play_track(int track, int loop, unsigned long position);
    int play_file(const char* file_name, int loop, unsigned long position);
    int play_tracks(int first, int last, int loop, int current,
                    unsigned long position);
    int play(int first, int last, char* file_name, int current,
             unsigned long position);
    int pause_play();
    int resume_play();
    int stop_track();
    int stop_playing();
    int fade_track();
    void start_fade();
    void do_fade();
    void end_fade();
    unsigned int handle_messages(void* window, unsigned int message,
                                 unsigned int value, long data);
    void after_end_track();
    int get_play_info(unsigned char* music_type, int* first_track,
                      int* last_track, int* current_track, char* file_name,
                      int* loop, unsigned long* position);
};

#endif
