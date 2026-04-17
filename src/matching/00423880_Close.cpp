extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, unsigned long param);

class CCDAudio {
public:
    int m_Wnd;
    int m_bOpened;
    unsigned int m_nDeviceID;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long Close(void);
};

unsigned long CCDAudio::Close(void) {
    unsigned long error;

    error = 0;
    if (m_bOpened != 0) {
        error = mciSendCommandA(m_nDeviceID, 0x804, 2, 0);
        DisplayErrorMsg(error);
        if (error == 0) {
            m_bOpened = 0;
        }
    }
    return error;
}
