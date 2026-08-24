#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::GetNumberOfTracks(unsigned char& track_count) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusInfo;

    mciStatusInfo.dwItem = 3;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102, (DWORD)&mciStatusInfo);
    track_count = (unsigned char)mciStatusInfo.dwReturn;
    return DisplayErrorMsg(result);
}
