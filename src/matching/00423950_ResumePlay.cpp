extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

class CCDAudio {
public:
    char gap_00[0x08];
    unsigned int m_nDeviceID;
    char m_mciPlayParms[0x14];

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long ResumePlay(void);
};

unsigned long CCDAudio::ResumePlay(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x806, 0, m_mciPlayParms));
}
