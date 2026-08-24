#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::Open(void* wnd) {
    unsigned long result;
    MCI_SET_PARMS mciSetInfo;
    MCI_OPEN_PARMS mciOpenParms;

    this->m_Wnd = wnd;
    if (this->m_bOpened != 0) {
        Close();
    }
    mciOpenParms.lpstrDeviceType = MAKEINTRESOURCEA(MCI_DEVTYPE_CD_AUDIO);
    result = mciSendCommandA(0, 0x803, 0x3102, (DWORD)&mciOpenParms);
    if (result == 0) {
        this->m_bOpened = 1;
        this->m_nDeviceID = mciOpenParms.wDeviceID;
        mciSetInfo.dwTimeFormat = 10;
        result = mciSendCommandA(mciOpenParms.wDeviceID, 0x80D, 0x402, (DWORD)&mciSetInfo);
    }
    return DisplayErrorMsg(result);
}
