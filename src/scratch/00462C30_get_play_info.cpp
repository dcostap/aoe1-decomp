// VA: 00462C30 TMusic_System::get_play_info (309B)
// PDB source: music.cpp lines 1127-1171
// Attempt log:
// Baseline: canonical non-polymorphic TMusic_System layout, natural output initialization,
// strcpy copy, and typed MCI status record/API surface reconstructed from the same-TU binary.
// Probe 2: early playing-track return plus one common result/status join improved structural
// parity but VC5 folded the two static MCI arms into one call (69 differing bytes).
// Probe 3: scoped result locals retained both calls but left duplicated status stores (82 bytes).
// Probes 4-6: binary-proven shared-tail/goto and early-return variants did not remove the
// duplicated tail or restore the original jump placement; best remained the common-result basin.
// Probes 7-9: nested if and direct per-case forms either folded a call or returned to the
// 165-byte baseline; probe 10's typed status alias was codegen-identical to probe 2.
// Final bounded result: restored the clean natural baseline. Remaining gap is the VC5
// switch/call tail topology: original has two static MCI call sites with one shared status
// store/final tail, while natural common-result source folds the calls and duplicated-arm
// source duplicates the store. Canonical fields, ABI, copy semantics, and runtime call
// behavior are established; leave unresolved for a future focused control-flow pass.
// Main-agent audit confirmed canonical non-polymorphic music/MCI ownership and
// retained the natural typed output/status flow.

#include <string.h>

class tagMCI_STATUS_PARMS {
public:
    unsigned long dwCallback;
    unsigned long dwReturn;
    unsigned long dwItem;
    unsigned long dwTrack;
};

extern "C" __declspec(dllimport) unsigned int __stdcall mciSendCommandA(
    unsigned int, unsigned int, unsigned long, void*);

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

    int get_play_info(unsigned char* music_type_out,
                      int* start_track_out,
                      int* end_track_out,
                      int* current_track_out,
                      char* file_name_out,
                      int* loop_out,
                      unsigned long* set_pos_out);
};

int TMusic_System::get_play_info(unsigned char* music_type_out,
                                 int* start_track_out,
                                 int* end_track_out,
                                 int* current_track_out,
                                 char* file_name_out,
                                 int* loop_out,
                                 unsigned long* set_pos_out)
{
    tagMCI_STATUS_PARMS status_info;

    *music_type_out = this->music_type;
    *start_track_out = 0;
    *end_track_out = 0;
    *current_track_out = 0;
    *file_name_out = 0;
    *loop_out = 0;
    *set_pos_out = 0;

    if (this->device_open == 0) {
        return 0;
    }

    if (this->playing_track != 0) {
        *start_track_out = this->start_track;
        *end_track_out = this->end_track;
        *current_track_out = this->current_track;
        strcpy(file_name_out, this->file_name);
        *loop_out = this->loop;
        *set_pos_out = 0;

        switch (this->music_type) {
        case 1:
            status_info.dwTrack = 2;
            if (mciSendCommandA(this->device_id, 0x814, 0x102,
                                &status_info.dwReturn) == 0) {
                *set_pos_out = status_info.dwItem;
            }
            break;
        case 2:
            status_info.dwTrack = 2;
            if (mciSendCommandA(this->device_id, 0x814, 0x102,
                                &status_info.dwReturn) == 0) {
                *set_pos_out = status_info.dwItem;
            }
            break;
        }
    }

    return 1;
}
