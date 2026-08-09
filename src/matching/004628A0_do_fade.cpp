// Baseline reconstruction: canonical TMusic_System fields and the natural
// time-based fade update shown by the original call/field topology.
// Probe 2: <= -10000 recovered the original signed guard compare.
// Probe 3: failure-first control flow recovered the late set-volume block and all call sites.
// Probe 4: named fade-step locals added a stack slot and were rolled back.
// Probe 7: threshold-expression lab found the literal 250.0f/10000.0f spelling exact.
// Exact source retained: the threshold uses ordinary float literals; the -10000.0f
// fade multiplier is anchored to the existing typed rdata constant.

extern unsigned long debug_timeGetTime(char* file, int line);
extern float DAT_00570c20;

class TMusic_System {
public:
    char path[260];
    unsigned char music_type;
    unsigned char pad_105[3];
    void* sound_system;
    void* instance;
    void* window;
    int device_open;
    unsigned int device_id;
    char play_info[12];
    unsigned char playing_track;
    char file_name[261];
    unsigned char pad_22E[2];
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

    int stop_playing();
    void set_volume(long volume, int save_flag);
    void end_fade();
    void do_fade();
};

void TMusic_System::do_fade() {
    if (this->paused == 0) {
        float time = (float)(debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 0x39E) - this->last_fade_time);

        if (this->fade_volume <= -10000 && this->playing_track != 0) {
            this->stop_playing();
        }

        this->fade_volume = this->fade_volume + (long)(time / (float)this->fade_time * DAT_00570c20);
        if (this->fade_volume <= -10000 - (long)(250.0f / (float)this->fade_time * 10000.0f)) {
            if (this->playing_track != 0) {
                this->stop_playing();
            }
            if (this->fading_track != 0) {
                this->end_fade();
                return;
            }
        } else {
            this->set_volume(this->fade_volume, 0);
            this->last_fade_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 0x3B8);
        }
    }
}
