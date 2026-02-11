#pragma once
#include "common.h"

struct CCDAudio {
    void* m_Wnd;
    int m_bOpened;
    uint m_nDeviceID;
    tagMCI_PLAY_PARMS m_mciPlayParms;

    CCDAudio();
    ~CCDAudio();
    ulong Open(void* wnd);
    ulong Close();
    ulong Stop();
    ulong Play(uchar track);
    ulong Pause();
    ulong ResumePlay();
    ulong Eject();
    ulong GetNumberOfTracks(uchar& count);
    ulong IsMediaPresent(int& present);
    ulong IsPlaying(int& playing);
    ulong GetLength(uchar& minutes, uchar& seconds);
    ulong GetTrackLength(uchar track, uchar& minutes, uchar& seconds);
    ulong GetPosition(uchar& track, uchar& minutes, uchar& seconds);

private:
    ulong DisplayErrorMsg(ulong err);
};
static_assert(sizeof(CCDAudio) == 0x18, "Size mismatch");
