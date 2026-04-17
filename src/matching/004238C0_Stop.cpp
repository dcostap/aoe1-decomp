extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, unsigned long param);

class CCDAudio {
public:
    char gap_00[0x08];
    unsigned int m_nDeviceID;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long Stop(void);
};

unsigned long CCDAudio::Stop(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x808, 2, 0));
}
