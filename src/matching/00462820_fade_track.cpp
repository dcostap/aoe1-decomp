class TMusic_System {
public:
    char gap_00[0x128];
    unsigned char playing_track;
    unsigned char file_name_0;
    char gap_12A[0x106];
    int start_track;
    int end_track;
    char gap_238[0x08];
    int loop;
    char gap_244[0x28];
    int fading_track;

    void start_fade(void);
    int fade_track(void);
};

int TMusic_System::fade_track(void) {
    unsigned char playing_track = this->playing_track;

    this->loop = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->file_name_0 = 0;
    this->fading_track = 0;
    if (playing_track != 0) {
        this->start_fade();
    }
    return 1;
}
