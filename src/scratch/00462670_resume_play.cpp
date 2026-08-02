// VA: 00462670 TMusic_System::resume_play (207B)
// Source: music.cpp lines 779-820
// Attempt log:
// Baseline: canonical TMusic_System offsets and natural resume dispatch.
// Probe 2: switch preserved the decrement dispatch but merged the identical MCI arms.
// Probe 3: nested if/else followed the decompiler shape but moved the dispatch farther away.
// Probe 4: duplicate switch-arm predicates restored both MCI calls but changed the zero-test basin.
// Probe 5: spelling the outer guard as truthiness was tested after an unchanged explicit comparison.
// Probe 6: retain the negative early-return guard while keeping duplicated MCI checks.
// Probe 7: materialize the device-open guard value before the remaining state checks.
// Probe 8: use unary negation for the three early state checks.
// Probe 9: split the three early returns so each field has an independent test.
// Probe 10: split guards worsened CFG/size; restored the combined negative guard and duplicate MCI arms.

class tagMCI_PLAY_PARMS {
public:
    unsigned long dwCallback;
    unsigned long dwFrom;
    unsigned long dwTo;
};

class TSound_Driver {
public:
    int resume_stream();
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
    tagMCI_PLAY_PARMS play_info;
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

    void end_fade();
    int resume_play();
};

extern "C" __declspec(dllimport) unsigned int __stdcall mciSendCommandA(
    unsigned int, unsigned int, unsigned long, void*);

int TMusic_System::resume_play()
{
    if (this->device_open == 0 || this->playing_track == 0 || this->paused == 0) {
        return 0;
    }

    this->paused = 0;
    this->auto_paused = 0;

    if (this->fading_track != 0) {
        this->end_fade();
        return 1;
    }

    switch (this->music_type) {
    case 1:
        if (mciSendCommandA(this->device_id, 0x806, 0, &this->play_info) == 0) {
            this->notify_waiting++;
        }
        break;
    case 2:
        if (mciSendCommandA(this->device_id, 0x806, 0, &this->play_info) == 0) {
            this->notify_waiting++;
        }
        break;
    case 3:
        if (this->sound_system != 0) {
            this->sound_system->resume_stream();
            return 1;
        }
        break;
    }
    return 1;
}
