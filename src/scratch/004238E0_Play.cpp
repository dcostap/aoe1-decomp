// STATUS: active lead
// the literal donor-surface version still delayed the initial track load and compacted the store scheduling
// even the direct mutate-track form kept the same push-esi-first basin, so the remaining gap is still the startup family before the mciSendCommandA call

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
    unsigned long m_nDeviceID;
    MCI_PLAY_PARMS m_mciPlayParms;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long Play(unsigned char track);
};

unsigned long CCDAudio::Play(unsigned char track) {
    unsigned long result;

    m_mciPlayParms.dwCallback = (unsigned long)m_Wnd;
    m_mciPlayParms.dwFrom = track;
    track = (unsigned char)(track + 1);
    m_mciPlayParms.dwTo = track;
    result = mciSendCommandA(m_nDeviceID, 0x806, 0x0D, &m_mciPlayParms);
    result = DisplayErrorMsg(result);
    return result;
}
