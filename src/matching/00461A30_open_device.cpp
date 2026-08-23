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
// The previous accepted drift was this local shift, zero-register reuse, and
// add-negative versus subtract lowering. Its review confirmed that all 11 calls
// preserve arguments and order. Track scans, device publication, MCI fields,
// mixer numerator/divisor and division fault point, volume stores, failure
// tails, and returns also match.
// Translation-unit recovery: music_context.h was codegen-neutral. A typed local
// window recovered the binary stack objects and all interior WinMM pointers.
// Fixed-size track-count fills recovered immediate stores and direct null tests.
// Updating start_volume before copying volume recovered the negative-bound ADD.
// Walkback proved that direct track-count assignment, a scalar volume temporary,
// and removal of the four-byte filename prefix each lose exact output.

#include <stdio.h>
#include <string.h>
#include "../../include/music_context.h"

static const char MUSIC_WAV_FORMAT[] = "%smusic%d.wav";
static const char MUSIC_MID_FORMAT[] = "%smusic%d.mid";
static const char READ_MODE[] = "r";
static const int MUSIC_MIN_VOLUME = -10000;

typedef MCIERROR (WINAPI *MCI_SEND_COMMAND_PROC)(MCIDEVICEID, UINT, DWORD, DWORD);

// BINARY NOTE: MCI receives the status tail starting at dwReturn.
struct MCI_STATUS_TAIL {
    unsigned long dwReturn;
    unsigned long dwItem;
    unsigned long dwTrack;
};

// BINARY NOTE: the filename starts four bytes into this 265-byte stack window.
struct Music_File_Name {
    unsigned long prefix;
    char text[261];
};

struct Music_Open_Locals {
    MCI_STATUS_TAIL status_info;
    MCI_SET_PARMS set_info;
    MCI_OPEN_PARMSA open_info;
    Music_File_Name file_name;
};

int TMusic_System::open_device()
{
    Music_Open_Locals locals;

    switch (this->music_type) {
    case 1: {
        MCI_SEND_COMMAND_PROC mci = mciSendCommandA;
        locals.open_info.lpstrElementName = MAKEINTRESOURCEA(0x204);
        if (mci(0, 0x803, 0x3102,
                (DWORD)&locals.open_info.wDeviceID) == 0) {
            this->device_open = 1;
            this->device_id = locals.open_info.lpstrDeviceType != 0
                                ? (unsigned int)locals.open_info.lpstrDeviceType : 0;
            locals.set_info.dwAudio = 10;
            mci(this->device_id, 0x80D, 0x402,
                (DWORD)&locals.set_info.dwTimeFormat);

            locals.status_info.dwTrack = 3;
            if (mci(this->device_id, 0x814, 0x102,
                    (DWORD)&locals.status_info.dwReturn) == 0) {
                this->track_count = locals.status_info.dwItem;
            }

            if (this->open_mixer() != 0) {
                this->start_volume =
                    (this->mixer_volume_value.dwValue * 10000) /
                    (unsigned int)(this->mixer_volume_control.Bounds.lMaximum -
                                   this->mixer_volume_control.Bounds.lMinimum);
                // Preserve the shipped ADD and member-store order.
                this->start_volume += MUSIC_MIN_VOLUME;
                this->volume = this->start_volume;
            }
            return 1;
        }
        break;
    }

    case 2: {
        FILE* scan_file;
        if (this->open_mixer() != 0) {
            this->start_volume =
                (this->mixer_volume_value.dwValue * 10000) /
                (unsigned int)(this->mixer_volume_control.Bounds.lMaximum -
                               this->mixer_volume_control.Bounds.lMinimum);
            // Preserve the shipped ADD and member-store order.
            this->start_volume += MUSIC_MIN_VOLUME;
            this->volume = this->start_volume;
        }

        // Preserve the shipped immediate store and direct fopen null test.
        memset(&this->track_count, 0, sizeof(this->track_count));
        do {
            sprintf(locals.file_name.text, MUSIC_MID_FORMAT, this->path,
                    this->track_count + 1);
            scan_file = fopen(locals.file_name.text, READ_MODE);
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
        // Preserve the shipped immediate store and direct fopen null test.
        memset(&this->track_count, 0, sizeof(this->track_count));
        do {
            sprintf(locals.file_name.text, MUSIC_WAV_FORMAT, this->path,
                    this->track_count + 1);
            scan_file = fopen(locals.file_name.text, READ_MODE);
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
