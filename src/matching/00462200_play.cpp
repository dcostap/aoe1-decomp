// VA: 00462200 TMusic_System::play (952B)
// PDB source: music.cpp lines 523-728
// Attempt log:
// Baseline reconstruction: restored the protected five-argument play ABI, the
// typed WinMM/stdio surfaces, the three music-type branches, and the common
// playing-state tail from the executable packet.
// Consolidated internal failure exits through the shared playing-state tail;
// this reduced the return/CFG mismatch and is retained in the reconstruction.
// Added the type-1 MCI play-error mciGetErrorStringA path; this recovered the
// original 15-call multiset and the ordered call prefix.
// Reversed the bounded-track comparison to parameter-left `from > count`,
// matching the original compare algebra and improving the early block island.
// Ten bounded probes left the best build at 908/952 bytes, 15/15 ordered calls,
// 80.92% shape, and 511 positional diff bytes. Remaining drift is structural:
// VC5 keeps the filename pointer and switch selector in opposite registers,
// places the proven stack records/buffers four bytes higher, and merges the
// two identical Unknown-Error copies. No raw-address or inline-asm experiment
// was retained; target remains scratch pending a later source/context pass.
// Resumed lease: a direct-return structural edit was not compiled and was
// restored; the pinned clean reconstruction remains the validated candidate.
// Follow-up structural pass: made the type-2 error copy conditional, used direct
// failure returns for the early guards, and used a positive start>0 seek gate.
// These recover the original CFG, exact size, and 97.48% resync similarity;
// current positional drift is 24 bytes. The remaining bytes are the uniform
// four-byte local stack-window offset for MCI/format buffers. Direct switch and
// inlined error-result variants were codegen duplicates and are retained clean.
// Exact-finish retrospective:
// First exact checkpoint: probe 018, 0 bytes different, 952 bytes, 15 ordered calls.
// Last clean nonexact source: probe 017, 2 bytes different.
// Decisive change: type-1 seek setup now writes seek_info.dwCallback=0 and
// seek_info.dwTo=start. Both stores are required for the original lowering.
// Walkback: removing either store broke exactness. The grouped reversion was
// probe 017 and also broke exactness. The two stores are an inseparable group.
// Required changes: full MCI record pointers, real MCI output fields, direct
// local buffer expressions, positive seek gates, and matching seek assignments.
// Incidental changes: declaration scope and function-pointer scope changed
// without emitted-code effect after the ABI corrections. No flags changed.
// Evidence: exact bytes prove the MCI record ABI and field ownership.

#include <stdio.h>
#include <string.h>
#include "../../include/music_context.h"

extern const char MUSIC_WAV_FORMAT[];
extern const char MUSIC_MID_FORMAT[];
extern const char MUSIC_NAME_FORMAT[];
extern const char MUSIC_MID_SUFFIX[];
extern const char s_Unknow_Error[];

extern "C" int __cdecl open(const char*, int);
extern "C" int __cdecl close(int);

typedef MCIERROR (WINAPI *MCI_SEND_COMMAND_PROC)(
    unsigned int, unsigned int, unsigned long, unsigned long);

int TMusic_System::play(int from, int to, char* name, int current, unsigned long start)
{
    MCI_SEND_COMMAND_PROC mci;
    char track_name[261];
    char error_message[256];
    MCI_SEEK_PARMS seek_info;
    MCI_OPEN_PARMSA open_info;

    if (!this->device_open) {
        return 0;
    }

    if (this->playing_track != 0) {
        this->stop_playing();
    }

    if (!name || !*name) {
        int count = this->track_count;
        if (!count) {
            return 0;
        }
        if (from > count) {
            return 0;
        }
        if (!from) {
            return 0;
        }
        if (current) {
            this->current_track = current;
        } else {
            this->current_track = from;
        }
    }

    switch (this->music_type) {
    case 1: {
        MCIERROR result;
        mci = mciSendCommandA;
        this->play_info.dwCallback = (unsigned long)this->window;
        unsigned int flags = 1;

        if (start > 0) {
            seek_info.dwCallback = 0;
            seek_info.dwTo = start;
            mci(this->device_id, 0x807, 10,
                (unsigned long)&seek_info);
        } else {
            flags = 5;
            this->play_info.dwFrom = (unsigned char)this->current_track;
        }

        if (from < this->track_count && to < this->track_count) {
            flags |= 8;
            this->play_info.dwTo = (unsigned char)(to + 1);
        }

        result = mci(this->device_id, 0x806, flags,
                     (unsigned long)&this->play_info);
        if (!result) {
            this->playing_track = 1;
            ++this->notify_waiting;
        } else {
            if (!mciGetErrorStringA(result, error_message, 0x100)) {
                strcpy(error_message, s_Unknow_Error);
            }
        }
        break;
    }

    case 2: {
        MCIERROR result;
        if (!name || !*name) {
            sprintf(track_name, MUSIC_MID_FORMAT,
                    this->path, this->current_track);
        } else {
            sprintf(track_name, MUSIC_NAME_FORMAT,
                    this->path, name);
            if (strchr(track_name, '.') == 0) {
                strcat(track_name, MUSIC_MID_SUFFIX);
            }
        }

        int file_handle = open(track_name, 0);
        if (file_handle != -1) {
            close(file_handle);

            mci = mciSendCommandA;
            open_info.lpstrDeviceType = MAKEINTRESOURCEA(0x20B);
            open_info.lpstrElementName = track_name;
            result = mci(0, 0x803, 0x3200,
                         (unsigned long)&open_info);
            if (result) {
                if (!mciGetErrorStringA(result, error_message, 0x100)) {
                    strcpy(error_message, s_Unknow_Error);
                }
            }
            if (result) {
                goto finish;
            }

            this->device_id = (unsigned int)open_info.wDeviceID;
            if (start > 0) {
                seek_info.dwCallback = 0;
                seek_info.dwTo = start;
                mci((unsigned int)open_info.wDeviceID, 0x807, 8,
                    (unsigned long)&seek_info);
            }

            this->play_info.dwCallback = (unsigned long)this->window;
            result = mci(this->device_id, 0x806, 1,
                         (unsigned long)&this->play_info);
            if (!result) {
                this->playing_track = 1;
                ++this->notify_waiting;
            }
        }
        break;
    }

    case 3:
        if (this->sound_system) {
            if (!name || !*name) {
                sprintf(track_name, MUSIC_WAV_FORMAT,
                        this->path, this->current_track);
            } else {
                sprintf(track_name, MUSIC_NAME_FORMAT,
                        this->path, name);
            }

            if (!this->sound_system->stream_file(track_name, 0,
                                                 this->volume)) {
                return 0;
            }
            this->playing_track = 1;
        }
        break;
    }

finish:
    if (this->playing_track) {
        this->paused = 0;
        this->auto_paused = 0;
        this->inactivated = 0;
        return 1;
    }
    return 0;
}
