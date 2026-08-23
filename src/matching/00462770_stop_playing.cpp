// VA: 00462770 TMusic_System::stop_playing
// music.cpp:836-883

#include "../../include/music_context.h"

typedef MCIERROR (WINAPI *MCI_SEND_COMMAND_PROC)(MCIDEVICEID, UINT, DWORD, DWORD);

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
        MCI_SEND_COMMAND_PROC fn = mciSendCommandA;
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
