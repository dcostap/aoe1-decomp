// VA: 00461A30 TMusic_System::open_device (551B)
// PDB source: music.cpp lines 71-216
// Attempt log:
// Baseline: same-TU TMusic_System/mixer layout, typed MCI records, period
// multimedia and stdio surfaces, and a natural switch/scan reconstruction.
// The original call set is 11 calls with a 0x138 frame.
// Earlier loop forms (for, while-true, comma conditions, and scoped labels)
// caused VC5 loop peeling and four sprintf/fopen sites. A bottom-tested do-loop
// kept the call set but emitted a duplicate test.
// A do-loop with an explicit fopen success arm and failure break removed that
// duplicate test. It gives 467 differing bytes, exact calls, exact frame, and
// matching conditional and jump counts.
// A positive MCI-open arm with a shared post-switch failure return recovers the
// original late failure-tail layout. A negative goto form was two bytes worse.
// Named period string definitions and case-local MCI/FILE scopes are codegen
// neutral. The 261-byte filename buffer and typed MCI field pointers are kept.
// Local declaration order, pointer-truth spelling, and gap models did not move
// codegen. The original local homes are four bytes below the rebuilt homes.
// The remaining drift is this local shift, the zero-register initialization form,
// and three extra instructions. No policy-safe source lead remains.
// Accepted-drift review: all 11 MCI, mixer, sprintf, fopen, and fclose calls
// preserve arguments and order. Track scans, device publication, MCI fields,
// mixer numerator/divisor and division fault point, volume stores, failure
// tails, and returns match. Residual drift is a +4 private stack-buffer shift,
// zero-register reuse, and add-negative versus subtract lowering.

#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

static const char MUSIC_WAV_FORMAT[] = "%smusic%d.wav";
static const char MUSIC_MID_FORMAT[] = "%smusic%d.mid";
static const char READ_MODE[] = "r";

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
    char file_name[261];

    switch (this->music_type) {
    case 1: {
        MCI_STATUS_PARMS status_info;
        MCI_SET_PARMS set_info;
        MCI_OPEN_PARMSA open_info;
        MCI_SEND_COMMAND_PROC mci = mciSendCommandA;
        open_info.lpstrElementName = MAKEINTRESOURCEA(0x204);
        if (mci(0, 0x803, 0x3102,
                (DWORD)&open_info.wDeviceID) == 0) {
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
        break;
    }

    case 2: {
        FILE* scan_file;
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
        do {
            sprintf(file_name + 4, MUSIC_MID_FORMAT, this->path,
                    this->track_count + 1);
            scan_file = fopen(file_name + 4, READ_MODE);
            if (scan_file) {
                fclose(scan_file);
                ++this->track_count;
            } else {
                break;
            }
        } while (1);
        this->device_open = 1;
        return 1;
    }

    case 3: {
        FILE* scan_file;
        this->track_count = 0;
        do {
            sprintf(file_name + 4, MUSIC_WAV_FORMAT, this->path,
                    this->track_count + 1);
            scan_file = fopen(file_name + 4, READ_MODE);
            if (scan_file) {
                fclose(scan_file);
                ++this->track_count;
            } else {
                break;
            }
        } while (1);
        this->volume = 0;
        this->device_open = 1;
        return 1;
    }
    }
    return 0;
}
