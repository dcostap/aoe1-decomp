extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

struct tagMCI_STATUS_PARMS {
    unsigned long dwCallback;
    unsigned long dwReturn;
    unsigned long dwItem;
    unsigned long dwTrack;
};

class CCDAudio {
public:
    char gap_00[0x08];
    unsigned int m_nDeviceID;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long GetPosition(unsigned char& minutes, unsigned char& seconds, unsigned char& frames);
};

unsigned long CCDAudio::GetPosition(unsigned char& minutes, unsigned char& seconds, unsigned char& frames) {
    tagMCI_STATUS_PARMS mciStatusParms;
    unsigned long result;
    unsigned long item;
    unsigned short time;

    mciStatusParms.dwItem = 2;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102, &mciStatusParms);
    item = mciStatusParms.dwReturn;
    time = (unsigned short)item;
    minutes = (unsigned char)time;
    seconds = (unsigned char)(time >> 8);
    frames = (unsigned char)(item >> 16);
    return DisplayErrorMsg(result);
}
