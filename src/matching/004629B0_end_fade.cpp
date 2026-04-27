// first pass: direct fade-stop call plus the packet's OR-guard around the play helper
// if this is sticky, the remaining work is likely just the exact field names / call shape for play
class TSound_Driver;

class TMusic_System {
public:
    char pad_00[0x129];
    char file_name[261];
    char pad_22E[0x2];
    int start_track;
    int end_track;
    int make_cur_track;
    unsigned long set_pos;
    char pad_240[0x14];
    long volume;
    char pad_258[0x14];
    int fading_track;

    void set_volume(long param_1, int param_2);
    int play(int a, int b, char* c, int d, unsigned long e);
    void end_fade(void);
};

void TMusic_System::end_fade(void) {
    this->fading_track = 0;
    this->set_volume(this->volume, 0);
    if ((this->start_track > 0 && this->end_track > 0) || this->file_name[0] != 0) {
        this->play(this->start_track, this->end_track, this->file_name, this->make_cur_track, this->set_pos);
    }
}
