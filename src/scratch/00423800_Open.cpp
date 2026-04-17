// STATUS: blocked
// BLOCKER: VC5 keeps collapsing the overlapping open/set temporaries into a 0x14 stack frame instead of the original 0x20 layout
// NOTE: behavior and call set are correct; remaining mismatch is local lifetime/layout only

extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

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

    m_Wnd = wnd;
    if (m_bOpened != 0) {
        Close();
    }
    {
        unsigned long mciOpenParms[3];

        mciOpenParms[2] = 0x204;
        result = mciSendCommandA(0, 0x803, 0x3102, &mciOpenParms[0]);
        if (result == 0) {
            m_bOpened = 1;
            m_nDeviceID = mciOpenParms[1];
            {
                unsigned long mciSetInfo[2];

                mciSetInfo[1] = 10;
                result = mciSendCommandA(mciOpenParms[1], 0x80D, 0x402, &mciSetInfo[0]);
            }
        }
    }
    return DisplayErrorMsg(result);
}
