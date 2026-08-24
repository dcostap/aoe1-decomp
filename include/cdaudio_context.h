#ifndef AOE1_CDAUDIO_CONTEXT_H
#define AOE1_CDAUDIO_CONTEXT_H

// Canonical Cdaudio.cpp declarations.  The class is 0x18 bytes in the shipped
// image; the MCI play record begins at offset 0x0C.
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
    unsigned long Open(void* wnd);
    unsigned long Close();
    unsigned long Stop();
    unsigned long Play(unsigned char track);
    unsigned long Pause();
    unsigned long ResumePlay();
    unsigned long Eject();
    unsigned long GetNumberOfTracks(unsigned char& track_count);
    unsigned long IsMediaPresent(int& present);
    unsigned long IsPlaying(int& playing);
    unsigned long GetLength(unsigned char& minutes, unsigned char& seconds);
    unsigned long GetTrackLength(unsigned char track, unsigned char& minutes,
                                 unsigned char& seconds);
    unsigned long GetPosition(unsigned char& minutes, unsigned char& seconds,
                              unsigned char& frames);

private:
    unsigned long DisplayErrorMsg(unsigned long error);
};

typedef char cdaudio_context_size_check[(sizeof(CCDAudio) == 0x18) ? 1 : -1];

#endif
