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
    unsigned long GetTrackLength(unsigned int track, unsigned char& minutes, unsigned char& seconds);
};

unsigned long CCDAudio::GetTrackLength(unsigned int track, unsigned char& minutes, unsigned char& seconds) {
    tagMCI_STATUS_PARMS mciStatusParms;
    unsigned int track_local;
    unsigned long result;
    unsigned short item;

    track_local = track & 0xFF;
    mciStatusParms.dwItem = 1;
    mciStatusParms.dwTrack = track_local;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x112, &mciStatusParms);
    item = (unsigned short)mciStatusParms.dwReturn;
    minutes = (unsigned char)item;
    seconds = (unsigned char)(item >> 8);
    return DisplayErrorMsg(result);
}
