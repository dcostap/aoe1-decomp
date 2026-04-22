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
    unsigned long GetNumberOfTracks(unsigned char& track_count);
};

unsigned long CCDAudio::GetNumberOfTracks(unsigned char& track_count) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusInfo;

    mciStatusInfo.dwItem = 3;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102, &mciStatusInfo);
    track_count = (unsigned char)mciStatusInfo.dwReturn;
    return DisplayErrorMsg(result);
}
