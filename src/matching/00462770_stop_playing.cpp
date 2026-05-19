// VA: 00462770 TMusic_System::stop_playing
// music.cpp:836-883

class TSound_Driver {
public:
    int stop_stream();
};

extern unsigned int (__stdcall *mciSendCommandA)(unsigned int, unsigned int, unsigned int, unsigned int);

class TMusic_System {
public:
    char gap_000[0x104];
    unsigned char music_type;  // +0x104
    char gap_105[3];
    TSound_Driver* sound_system; // +0x108
    char gap_10C[0x0C];
    unsigned int device_id; // +0x118
    char gap_11C[0x0C];
    unsigned char playing_track; // +0x128
    char gap_129[0x12F];
    int paused; // +0x258
    int auto_paused; // +0x25C

    int stop_playing();
};

int TMusic_System::stop_playing()
{
    if (playing_track == 0) {
        return 1;
    }

    switch (music_type) {
    case 1:
        mciSendCommandA(device_id, 0x808, 2, 0);
        playing_track = 0;
        break;
    case 2: {
        unsigned int (__stdcall *fn)(unsigned int, unsigned int, unsigned int, unsigned int) = mciSendCommandA;
        fn(device_id, 0x808, 2, 0);
        playing_track = 0;
        fn(device_id, 0x804, 2, 0);
        device_id = 0;
        break;
    }
    case 3:
        if (sound_system != 0) {
            sound_system->stop_stream();
        }
        break;
    }

    playing_track = 0;
    paused = 0;
    auto_paused = 0;
    return 1;
}
