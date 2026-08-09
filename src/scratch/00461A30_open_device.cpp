// VA: 00461A30 TMusic_System::open_device (551B)
// PDB source: music.cpp lines 71-216
// Attempt log:
// Baseline: canonical same-TU TMusic_System/mixer layout, typed MCI parameter
// records, period stdio/multimedia surfaces, and natural switch/scan reconstruction.
// Probe 2: late shared failure tail and do-loop scans improved CFG but loop peeling
// retained four static sprintf/fopen sites.
// Probes 3-5: FILE scope, explicit scan labels, and comma-condition loops were
// codegen duplicates; all retained the peeled call duplication.
// Probe 6: a do-loop with an explicit file-dependent bottom condition recovered the
// original 11-call static set and 0x138 frame; remaining drift is stack-local offsets,
// branch polarity, and return-tail placement.
// Probes 7-9: a dead stack gap and typed OpenDeviceWork gap model were nonproductive;
// the latter either grew the frame or changed local placement.
// Probe 10: removing the buffer +4 diagnostic moved only fopen behavior and did not
// improve the 489-byte best; restored this binary-supported +4 source shape.
// Final bounded result: natural typed source retained in scratch. Best current metrics
// are 489 differing bytes, exact 11-call set, 0x138 frame, and the full WinMM/stdio
// behavior/layout reconstructed. Next lead is a focused local-stack declaration/order
// pass to move status/set/open/file homes by four bytes and reproduce late failure tails.
// Main-agent audit replaced raw string addresses with named SDK/global surfaces
// and retained the natural typed WinMM/file-device flow.

#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

extern const char MUSIC_WAV_FORMAT[];
extern const char MUSIC_MID_FORMAT[];
extern const char READ_MODE[];

typedef MCIERROR (WINAPI *MCI_SEND_COMMAND_PROC)(MCIDEVICEID, UINT, DWORD, DWORD);

class TMusic_System {
public:
    char path[260];
    unsigned char music_type;
    unsigned char _pad_0[3];
    void* sound_system;
    void* instance;
    void* window;
    int device_open;
    unsigned int device_id;
    char play_info[12];
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

    int open_device();
    int open_mixer();
};

int TMusic_System::open_device()
{
    MCI_STATUS_PARMS status_info;
    MCI_SET_PARMS set_info;
    MCI_OPEN_PARMSA open_info;
    char file_name[261];

    switch (this->music_type) {
    case 1: {
        MCI_SEND_COMMAND_PROC mci = mciSendCommandA;
        open_info.lpstrElementName = MAKEINTRESOURCEA(0x204);
        if (mci(0, 0x803, 0x3102,
                (DWORD)&open_info.wDeviceID) != 0) {
            goto failure;
        }

        this->device_open = 1;
        this->device_id = open_info.lpstrDeviceType != 0
                            ? (unsigned int)open_info.lpstrDeviceType : 0;
        set_info.dwAudio = 10;
        mci(this->device_id, 0x80D, 0x402,
            (DWORD)&set_info.dwTimeFormat);

        status_info.dwTrack = 3;
        if (mci(this->device_id, 0x814, 0x102,
                (DWORD)&status_info.dwReturn) == 0) {
            this->track_count = status_info.dwItem;
        }

        if (this->open_mixer() != 0) {
            int new_volume =
                (this->mixer_volume_value.dwValue * 10000) /
                (unsigned int)(this->mixer_volume_control.Bounds.lMaximum -
                               this->mixer_volume_control.Bounds.lMinimum) -
                10000;
            this->start_volume = new_volume;
            this->volume = new_volume;
        }
        return 1;
    }

    case 2:
        if (this->open_mixer() != 0) {
            int new_volume =
                (this->mixer_volume_value.dwValue * 10000) /
                (unsigned int)(this->mixer_volume_control.Bounds.lMaximum -
                               this->mixer_volume_control.Bounds.lMinimum) -
                10000;
            this->start_volume = new_volume;
            this->volume = new_volume;
        }

        this->track_count = 0;
        FILE* midi_file;
        do {
            sprintf(file_name + 4, MUSIC_MID_FORMAT, this->path,
                    this->track_count + 1);
            midi_file = fopen(file_name + 4, READ_MODE);
            if (midi_file != 0) {
                fclose(midi_file);
                ++this->track_count;
            }
        } while (midi_file != 0);
        this->device_open = 1;
        return 1;

    case 3:
        this->track_count = 0;
        FILE* wav_file;
        do {
            sprintf(file_name + 4, MUSIC_WAV_FORMAT, this->path,
                    this->track_count + 1);
            wav_file = fopen(file_name + 4, READ_MODE);
            if (wav_file != 0) {
                fclose(wav_file);
                ++this->track_count;
            }
        } while (wav_file != 0);
        this->volume = 0;
        this->device_open = 1;
        return 1;
    }

failure:
    return 0;
}
