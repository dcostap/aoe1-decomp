// 00461C60 TMusic_System::close_device
// Source: music.cpp lines 221-290
// Attempt log:
// Baseline: canonical field ownership and a natural switch over music_type
// reproduce the complete 190-byte function under the default VC5 flags.

extern unsigned int (__stdcall *mciSendCommandA)(unsigned int, unsigned int,
                                                  unsigned int, unsigned int);

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;
    char gap_105[3];
    char gap_108[0x0C];
    int device_open;
    unsigned int device_id;
    char gap_11C[0x12C];
    int track_count;
    int notify_waiting;
    long start_volume;

    int stop_track();
    void set_volume(long volume, int save_flag);
    void close_mixer();
    void close_device();
};

void TMusic_System::close_device()
{
    if (this->device_open != 0) {
        this->stop_track();

        switch (this->music_type) {
        case 1:
            if (this->start_volume != 1) {
                this->set_volume(this->start_volume, 0);
                this->start_volume = 1;
            }
            this->close_mixer();
            mciSendCommandA(this->device_id, 0x804, 2, 0);
            this->device_id = 0;
            this->device_open = 0;
            this->track_count = 0;
            break;

        case 2:
            if (this->start_volume != 1) {
                this->set_volume(this->start_volume, 0);
                this->start_volume = 1;
            }
            this->close_mixer();
            this->device_open = 0;
            this->track_count = 0;
            break;

        case 3:
            this->track_count = 0;
            this->device_open = 0;
            break;
        }
    }
}
