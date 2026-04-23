class TMusic_System {
public:
    char gap_00[0x129];
    char file_name_0;
    char gap_12A[0x106];
    int start_track;
    int end_track;
    char gap_238[0x08];
    int loop;
    char gap_244[0x28];
    int fading_track;

    int stop_playing(void);
    int stop_track(void);
};

int TMusic_System::stop_track(void) {
    this->loop = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->file_name_0 = 0;
    this->fading_track = 0;
    return this->stop_playing();
}
