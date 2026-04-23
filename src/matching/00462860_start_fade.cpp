// tried the straightforward fade-start form; VC5 still wants the exact field order and imported-timer call basin
// remaining gap is field-name/order shaping around the timer stores
extern unsigned long debug_timeGetTime(char* file, int line);

class TMusic_System {
public:
    char gap_00[0x254];
    unsigned long volume;
    char gap_258[0x14];
    unsigned long fading_track;
    unsigned long fade_volume;
    unsigned long last_fade_time;

    void start_fade(void);
};

void TMusic_System::start_fade(void) {
    if (this->fading_track == 0) {
        this->fade_volume = this->volume;
        this->last_fade_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 0x38C);
        this->fading_track = 1;
    }
}
