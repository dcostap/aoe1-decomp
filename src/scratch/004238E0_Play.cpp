// STATUS: blocked
// BLOCKER: VC5 keeps hoisting callback/param loads into a different order around the play-parms stores, so the small prologue never matches the original eax/ecx/al sequence
// NOTE: behavior is understood; remaining drift is source-shape/register scheduling only

extern "C" __declspec(dllimport) unsigned long __stdcall mciSendCommandA(unsigned int device_id, unsigned int message, unsigned long flags, void* param);

struct MCI_PLAY_PARMS {
    unsigned long dwCallback;
    unsigned long dwFrom;
    unsigned long dwTo;
};

class CCDAudio {
public:
    int m_Wnd;
    int m_bOpened;
    unsigned int m_nDeviceID;
    MCI_PLAY_PARMS m_mciPlayParms;

    unsigned long DisplayErrorMsg(unsigned long error);
    unsigned long Play(unsigned int track);
};

unsigned long CCDAudio::Play(unsigned int track) {
    unsigned int from;

    from = track;
    m_mciPlayParms.dwCallback = (unsigned long)m_Wnd;
    m_mciPlayParms.dwFrom = from & 0xFF;
    m_mciPlayParms.dwTo = (track + 1) & 0xFF;
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x806, 0x0D, &m_mciPlayParms));
}
