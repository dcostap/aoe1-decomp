#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::IsPlaying(int& playing) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusParms;

    mciStatusParms.dwItem = 4;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102, (DWORD)&mciStatusParms);
    playing = mciStatusParms.dwReturn == 0x20E;
    if (playing != 0) {
        mciStatusParms.dwItem = 8;
        result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102, (DWORD)&mciStatusParms);
        playing = mciStatusParms.dwReturn;
    }
    return DisplayErrorMsg(result);
}
