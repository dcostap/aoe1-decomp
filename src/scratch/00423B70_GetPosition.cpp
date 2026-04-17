// STATUS: blocked
// BLOCKER: VC5 keeps using byte-addressed loads for seconds/frames instead of the original ecx/cl/ch/shr extraction sequence from the status item
// NOTE: status command and output bytes are correct; remaining drift is register/source-shape only

extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

class CCDAudio {
public:
    char gap_00[0x08];
    unsigned int m_nDeviceID;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long GetPosition(unsigned char& minutes, unsigned char& seconds, unsigned char& frames);
};

unsigned long CCDAudio::GetPosition(unsigned char& minutes, unsigned char& seconds, unsigned char& frames) {
    unsigned long result;
    char mciStatusParms[16];

    *(unsigned long*)(mciStatusParms + 12) = 2;
    result = mciSendCommandA(m_nDeviceID, 0x814, 0x102, mciStatusParms + 4);
    minutes = *(unsigned char*)(mciStatusParms + 8);
    seconds = *(unsigned char*)(mciStatusParms + 9);
    frames = *(unsigned char*)(mciStatusParms + 10);
    return DisplayErrorMsg(result);
}
