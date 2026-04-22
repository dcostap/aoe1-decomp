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
    unsigned long IsMediaPresent(int& present);
};

unsigned long CCDAudio::IsMediaPresent(int& present) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusParms;

    mciStatusParms.dwItem = 5;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102, &mciStatusParms);
    present = mciStatusParms.dwReturn != 0;
    return DisplayErrorMsg(result);
}
