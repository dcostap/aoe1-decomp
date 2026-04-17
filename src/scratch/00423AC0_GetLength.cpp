// STATUS: blocked
// BLOCKER: local status buffer size is right, but VC5 still emits byte-addressed loads from the returned item instead of the original ecx/cl/ch extraction shape
// NOTE: command/flags and output bytes are understood; remaining drift is stack-local/register shape only

extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

class CCDAudio {
public:
    char gap_00[0x08];
    unsigned int m_nDeviceID;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long GetLength(unsigned char& minutes, unsigned char& seconds);
};

unsigned long CCDAudio::GetLength(unsigned char& minutes, unsigned char& seconds) {
    unsigned long result;
    char mciStatusParms[16];

    *(unsigned long*)(mciStatusParms + 12) = 1;
    result = mciSendCommandA(m_nDeviceID, 0x814, 0x102, mciStatusParms + 4);
    minutes = *(unsigned char*)(mciStatusParms + 8);
    seconds = *(unsigned char*)(mciStatusParms + 9);
    return DisplayErrorMsg(result);
}
