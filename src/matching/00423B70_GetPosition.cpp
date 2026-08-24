#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::GetPosition(unsigned char& minutes, unsigned char& seconds, unsigned char& frames) {
    tagMCI_STATUS_PARMS mciStatusParms;
    unsigned long result;
    unsigned long item;
    unsigned short time;

    mciStatusParms.dwItem = 2;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102, (DWORD)&mciStatusParms);
    item = mciStatusParms.dwReturn;
    time = (unsigned short)item;
    minutes = (unsigned char)time;
    seconds = (unsigned char)(time >> 8);
    frames = (unsigned char)(item >> 16);
    return DisplayErrorMsg(result);
}
