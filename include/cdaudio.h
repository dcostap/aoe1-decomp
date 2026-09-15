#ifndef AOE1_CDAUDIO_H
#define AOE1_CDAUDIO_H

#include <windows.h>
#include <mmsystem.h>

class CCDAudio {
public:
    void* m_Wnd;
    int m_bOpened;
    unsigned int m_nDeviceID;
    MCI_PLAY_PARMS m_mciPlayParms;

    CCDAudio();
    ~CCDAudio();
    unsigned long Open(void* Wnd);
    unsigned long Close();
    unsigned long Stop();
    unsigned long Play(unsigned char nTrack);
    unsigned long Pause();
    unsigned long ResumePlay();
    unsigned long Eject();
    unsigned long GetNumberOfTracks(unsigned char& nNumTracks);
    unsigned long IsMediaPresent(int& bPresent);
    unsigned long IsPlaying(int& bPlaying);
    unsigned long GetLength(unsigned char& nMinutes, unsigned char& nSeconds);
    unsigned long GetTrackLength(unsigned char nTrack, unsigned char& nMinutes, unsigned char& nSeconds);
    unsigned long GetPosition(unsigned char& nTrack, unsigned char& nMinutes, unsigned char& nSeconds);

private:
    unsigned long DisplayErrorMsg(unsigned long dwError);
};

typedef char cdaudio_size_check[(sizeof(CCDAudio) == 0x18) ? 1 : -1];

#endif
