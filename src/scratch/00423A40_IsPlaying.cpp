// STATUS: blocked
// BLOCKER: status temp placement is still 4 bytes late, so both mciSendCommandA setup blocks miss the original stack offsets
// NOTE: predicate and second status query are understood; remaining drift is local-layout/codegen only

extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

class CCDAudio {
public:
    char gap_00[0x08];
    unsigned int m_nDeviceID;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long IsPlaying(int& playing);
};

unsigned long CCDAudio::IsPlaying(int& playing) {
    unsigned long result;
    char mciStatusParms[16];

    *(unsigned long*)(mciStatusParms + 12) = 4;
    result = mciSendCommandA(m_nDeviceID, 0x814, 0x102, mciStatusParms + 4);
    playing = *(unsigned long*)(mciStatusParms + 8) == 0x20E;
    if (playing != 0) {
        *(unsigned long*)(mciStatusParms + 12) = 8;
        result = mciSendCommandA(m_nDeviceID, 0x814, 0x102, mciStatusParms + 4);
        playing = *(unsigned long*)(mciStatusParms + 8);
    }
    return DisplayErrorMsg(result);
}
