// STATUS: blocked
// BLOCKER: local status-parms layout is understood, but VC5 keeps choosing a different stack-frame shape for the temporary/status storage and out-param writeback
// NOTE: command/flags/item usage match; remaining drift is stack-local placement/codegen only

extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

class CCDAudio {
public:
    char gap_00[0x08];
    unsigned int m_nDeviceID;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long GetNumberOfTracks(unsigned char& track_count);
};

unsigned long CCDAudio::GetNumberOfTracks(unsigned char& track_count) {
    unsigned long dwCallback;
    unsigned long dwReturn;
    unsigned long dwItem;
    unsigned long dwTrack;
    unsigned long result;

    dwTrack = 3;
    result = mciSendCommandA(m_nDeviceID, 0x814, 0x102, &dwReturn);
    track_count = (unsigned char)dwItem;
    return DisplayErrorMsg(result);
}
