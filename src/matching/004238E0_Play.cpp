// CCDAudio::Play (004238E0, 66 bytes, Cdaudio.cpp lines 166-179)
// Play(unsigned char track) — calls mciSendCommandA(MCI_PLAY) via IAT
//
// Attempt 1-2: natural source + nested call -> 87.9% (compiler pushes &parms/0Dh before loading track)
// Attempt 3-4: local track var + reordered assigns -> same
// Attempt 5: local devID variable (m_nDeviceID cached before call) + dwFrom/dwTo before dwCallback -> MATCH

extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

struct MCI_PLAY_PARMS {
    unsigned long dwCallback;
    unsigned long dwFrom;
    unsigned long dwTo;
};

class CCDAudio {
public:
    void* m_Wnd;
    int m_bOpened;
    unsigned int m_nDeviceID;
    MCI_PLAY_PARMS m_mciPlayParms;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long Play(unsigned char track);
};

unsigned long CCDAudio::Play(unsigned char track) {
    unsigned int devID;

    devID = m_nDeviceID;
    m_mciPlayParms.dwFrom = track;
    m_mciPlayParms.dwTo = (unsigned char)(track + 1);
    m_mciPlayParms.dwCallback = (unsigned long)m_Wnd;
    return DisplayErrorMsg(mciSendCommandA(devID, 0x806, 0x0D, &m_mciPlayParms));
}
