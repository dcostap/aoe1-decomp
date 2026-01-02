#pragma once
#include "../common.h"

class CCDAudio {
public:
    int m_bOpened;                           // 0x4
    uint m_nDeviceID;                        // 0x8
    tagMCI_PLAY_PARMS m_mciPlayParms;        // 0xC

    CCDAudio();
    virtual ~CCDAudio();
    virtual ulong Open(void* param_1);
    virtual ulong Close();
    virtual ulong Stop();
    virtual ulong Play(uchar param_1);
    virtual ulong Pause();
    virtual ulong ResumePlay();
    virtual ulong Eject();
    virtual ulong GetNumberOfTracks(uchar* param_1);
    virtual ulong IsMediaPresent(int* param_1);
    virtual ulong IsPlaying(int* param_1);
    virtual ulong GetLength(uchar* param_1, uchar* param_2);
    virtual ulong GetTrackLength(uchar param_1, uchar* param_2, uchar* param_3);
    virtual ulong GetPosition(uchar* param_1, uchar* param_2, uchar* param_3);
    virtual ulong DisplayErrorMsg(ulong param_1);
};

static_assert(sizeof(CCDAudio) == 0x18, "CCDAudio Size Mismatch");
static_assert(offsetof(CCDAudio, m_mciPlayParms) == 0xC, "CCDAudio Offset Mismatch");

