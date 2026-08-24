#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::IsMediaPresent(int& present) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusParms;

    mciStatusParms.dwItem = 5;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102, (DWORD)&mciStatusParms);
    present = mciStatusParms.dwReturn != 0;
    return DisplayErrorMsg(result);
}
