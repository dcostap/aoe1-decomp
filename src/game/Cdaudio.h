#pragma once
#include "../common.h"

class CCDAudio       {
public:
    void* m_Wnd;                             // 0x0
    int m_bOpened;                           // 0x4
    uint m_nDeviceID;                        // 0x8
    tagMCI_PLAY_PARMS m_mciPlayParms;        // 0xC

    CCDAudio();

    // --- Non-Virtual Destructor ---
    ~CCDAudio() noexcept(false);
    // --- Non-Virtual Members ---
    ulong Open(void* param_1);
    ulong Close();
    ulong Stop();
    ulong Play(uchar param_1);
    ulong Pause();
    ulong ResumePlay();
    ulong Eject();
    ulong GetNumberOfTracks(uchar* param_1);
    ulong IsMediaPresent(int* param_1);
    ulong IsPlaying(int* param_1);
    ulong GetLength(uchar* param_1, uchar* param_2);
    ulong GetTrackLength(uchar param_1, uchar* param_2, uchar* param_3);
    ulong GetPosition(uchar* param_1, uchar* param_2, uchar* param_3);
    ulong DisplayErrorMsg(ulong param_1);
};

static_assert(sizeof(CCDAudio) == 0x18, "CCDAudio Size Mismatch");
static_assert(offsetof(CCDAudio, m_mciPlayParms) == 0xC, "CCDAudio Offset Mismatch");

