#pragma once
#include "common.h"

struct CCDAudio {
    void* m_Wnd;
    int m_bOpened;
    uint m_nDeviceID;
    tagMCI_PLAY_PARMS m_mciPlayParms;
};
static_assert(sizeof(CCDAudio) == 0x18, "Size mismatch");
