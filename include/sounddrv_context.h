#ifndef AOE1_SOUNDDRV_CONTEXT_H
#define AOE1_SOUNDDRV_CONTEXT_H

#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>

typedef unsigned char uchar;

struct WAVHEADER {
    unsigned char szRIFF[4];
    unsigned long dwFormatLength;
    unsigned char szWAVE[4];
    unsigned char szFMT[4];
    unsigned long dwWaveFormatLength;
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned char szDATA[4];
    unsigned long dwDataLength;
};

class TDigital;

class TSound_Driver {
public:
    unsigned char ready;
    unsigned char mute;
    unsigned char gap_02[2];
    void* main_wnd;
    LPDIRECTSOUND direct_sound;
    LPDIRECTSOUNDBUFFER primary_buffer;
    long dsrval;
    long start_volume;
    long volume;
    char path[260];
    int mixer_open;
    HMIXER mixer_handle;
    MIXERLINEA mixer_line_info;
    MIXERLINECONTROLSA mixer_line_controls;
    MIXERCONTROLA mixer_volume_control;
    MIXERCONTROLDETAILS mixer_volume_details;
    MIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;
    TDigital* sound_play_list[256];
    int play_list_count;

    TSound_Driver();
    TSound_Driver(void* window, char* path);
    ~TSound_Driver();
    void init_vars();
    int init(void* window, char* path);
    void exit();
    void set_path(char* path);
    int driver_active();
    long get_volume();
    void set_volume(long volume, int update_driver);
    int stream_file(char* file, int mode, long resource_id);
    int set_stream_volume(long volume);
    int pause_stream();
    int resume_stream();
    int stop_stream();
    unsigned int handle_messages(void* a, unsigned int b, unsigned int c, long d);
    int add_to_play_list(TDigital* digital);
    void play_list();
    void reset_play_list();
    int open_mixer();
    void close_mixer();
};

class TDigital {
public:
    TSound_Driver* sound_system;
    TDigital* owner;
    unsigned char loaded;
    unsigned char failed;
    char sound_file[13];
    unsigned char gap_17;
    long resource_id;
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    unsigned char* wave_data;
    WAVEFORMATEX* wave_info;
    LPDIRECTSOUNDBUFFER sound_buffer;
    unsigned long data_size;

    TDigital(TSound_Driver* driver, char* file, long resource_id);
    TDigital(TDigital* owner);
    ~TDigital();
    void init_vars();
    void exit();
    int load(char* name, long resource_id);
    void unload();
    int play();
    void stop();
    void set_loop(short value);
    void set_volume(long value);
    void set_pitch(unsigned long value);
    void set_pan(long value);
    int is_playing();
    int add_to_play_list();
};

#endif
