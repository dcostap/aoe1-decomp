extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

struct MCI_OPEN_PARMS {
    unsigned long dwCallback;
    unsigned int wDeviceID;
    unsigned long lpstrDeviceType;
    unsigned long lpstrElementName;
    unsigned long lpstrAlias;
    unsigned long unused;
};

struct MCI_SET_PARMS {
    unsigned long dwCallback;
    unsigned long dwTimeFormat;
};

class CCDAudio {
public:
    void* m_Wnd;
    int m_bOpened;
    unsigned int m_nDeviceID;

    unsigned long Close(void);
    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long Open(void* wnd);
};

unsigned long CCDAudio::Open(void* wnd) {
    unsigned long result;
    MCI_SET_PARMS mciSetInfo;
    MCI_OPEN_PARMS mciOpenParms;

    this->m_Wnd = wnd;
    if (this->m_bOpened != 0) {
        Close();
    }
    mciOpenParms.lpstrElementName = 0x204;
    result = mciSendCommandA(0, 0x803, 0x3102, &mciOpenParms.wDeviceID);
    if (result == 0) {
        this->m_bOpened = 1;
        this->m_nDeviceID = (unsigned int)mciOpenParms.lpstrDeviceType;
        mciSetInfo.dwTimeFormat = 10;
        result = mciSendCommandA((unsigned int)mciOpenParms.lpstrDeviceType, 0x80D, 0x402, &mciSetInfo);
    }
    return DisplayErrorMsg(result);
}
