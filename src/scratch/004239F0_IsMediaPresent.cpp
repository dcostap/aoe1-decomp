// STATUS: blocked
// BLOCKER: same status-parms temporary-layout issue as GetNumberOfTracks; current source bloats/shrinks around the local/result handling instead of matching the original compact frame
// NOTE: item test and error-handling semantics are clear; remaining drift is stack-local/codegen only

extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

class CCDAudio {
public:
    char gap_00[0x08];
    unsigned int m_nDeviceID;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long IsMediaPresent(int& present);
};

unsigned long CCDAudio::IsMediaPresent(int& present) {
    unsigned long dwCallback;
    unsigned long dwReturn;
    unsigned long dwItem;
    unsigned long dwTrack;
    unsigned long result;

    dwTrack = 5;
    result = mciSendCommandA(m_nDeviceID, 0x814, 0x102, &dwReturn);
    present = dwItem != 0;
    return DisplayErrorMsg(result);
}
