// STATUS: blocked
// BLOCKER: VC5 still misses the original split local layout for the status buffer plus track selector, so the function underbuilds and the copyout path drifts
// NOTE: behavior is understood; remaining mismatch is stack-temp placement only

extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

class CCDAudio {
public:
    char gap_00[0x08];
    unsigned int m_nDeviceID;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long GetTrackLength(unsigned int track, unsigned char& minutes, unsigned char& seconds);
};

unsigned long CCDAudio::GetTrackLength(unsigned int track, unsigned char& minutes, unsigned char& seconds) {
    char mciStatusParms[16];
    unsigned long item;
    unsigned int track_local;
    unsigned long result;

    track_local = track & 0xFF;
    *(unsigned long*)(mciStatusParms + 12) = 1;
    result = mciSendCommandA(m_nDeviceID, 0x814, 0x112, mciStatusParms + 4);
    item = *(unsigned long*)(mciStatusParms + 8);
    minutes = (unsigned char)item;
    seconds = (unsigned char)(item >> 8);
    return DisplayErrorMsg(result);
}
