#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::GetLength(unsigned char& minutes, unsigned char& seconds) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusParms;
    unsigned short item;

    mciStatusParms.dwItem = 1;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102, (DWORD)&mciStatusParms);
    item = (unsigned short)mciStatusParms.dwReturn;
    minutes = (unsigned char)item;
    seconds = (unsigned char)(item >> 8);
    return DisplayErrorMsg(result);
}
