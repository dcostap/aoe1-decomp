#include "../include/cdaudio.h"
#include <string.h>

CCDAudio::CCDAudio() {
    m_Wnd = 0;
    m_bOpened = 0;
}

CCDAudio::~CCDAudio(void) {
    int playing;

    IsPlaying(playing);
    if (playing != 0) {
        Stop();
    }
    Close();
}

unsigned long CCDAudio::Open(void* wnd) {
    unsigned long result;
    MCI_SET_PARMS mciSetInfo;
    MCI_OPEN_PARMS mciOpenParms;

    this->m_Wnd = wnd;
    if (this->m_bOpened != 0) {
        Close();
    }
    mciOpenParms.lpstrDeviceType = MAKEINTRESOURCEA(MCI_DEVTYPE_CD_AUDIO);
    result = mciSendCommandA(0, 0x803, 0x3102, (DWORD)&mciOpenParms);
    if (result == 0) {
        this->m_bOpened = 1;
        this->m_nDeviceID = mciOpenParms.wDeviceID;
        mciSetInfo.dwTimeFormat = 10;
        result = mciSendCommandA(mciOpenParms.wDeviceID, 0x80D, 0x402,
                                 (DWORD)&mciSetInfo);
    }
    return DisplayErrorMsg(result);
}

unsigned long CCDAudio::Close(void) {
    unsigned long error;

    error = 0;
    if (m_bOpened != 0) {
        error = mciSendCommandA(m_nDeviceID, 0x804, 2, 0);
        DisplayErrorMsg(error);
        if (error == 0) {
            m_bOpened = 0;
        }
    }
    return error;
}

unsigned long CCDAudio::Stop(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x808, 2, 0));
}

unsigned long CCDAudio::Play(unsigned char track) {
    unsigned int devID;

    devID = m_nDeviceID;
    m_mciPlayParms.dwFrom = track;
    m_mciPlayParms.dwTo = (unsigned char)(track + 1);
    m_mciPlayParms.dwCallback = (unsigned long)m_Wnd;
    return DisplayErrorMsg(
        mciSendCommandA(devID, 0x806, 0x0D, (DWORD)&m_mciPlayParms));
}

unsigned long CCDAudio::Pause(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x809, 2, 0));
}

unsigned long CCDAudio::ResumePlay(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x806, 0,
                                            (DWORD)&m_mciPlayParms));
}

unsigned long CCDAudio::Eject(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x80D, 0x100, 0));
}

unsigned long CCDAudio::GetNumberOfTracks(unsigned char& track_count) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusInfo;

    mciStatusInfo.dwItem = 3;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102,
                             (DWORD)&mciStatusInfo);
    track_count = (unsigned char)mciStatusInfo.dwReturn;
    return DisplayErrorMsg(result);
}

unsigned long CCDAudio::IsMediaPresent(int& present) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusParms;

    mciStatusParms.dwItem = 5;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102,
                             (DWORD)&mciStatusParms);
    present = mciStatusParms.dwReturn != 0;
    return DisplayErrorMsg(result);
}

unsigned long CCDAudio::IsPlaying(int& playing) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusParms;

    mciStatusParms.dwItem = 4;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102,
                             (DWORD)&mciStatusParms);
    playing = mciStatusParms.dwReturn == 0x20E;
    if (playing != 0) {
        mciStatusParms.dwItem = 8;
        result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102,
                                 (DWORD)&mciStatusParms);
        playing = mciStatusParms.dwReturn;
    }
    return DisplayErrorMsg(result);
}

unsigned long CCDAudio::GetLength(unsigned char& minutes,
                                  unsigned char& seconds) {
    unsigned long result;
    tagMCI_STATUS_PARMS mciStatusParms;
    unsigned short item;

    mciStatusParms.dwItem = 1;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102,
                             (DWORD)&mciStatusParms);
    item = (unsigned short)mciStatusParms.dwReturn;
    minutes = (unsigned char)item;
    seconds = (unsigned char)(item >> 8);
    return DisplayErrorMsg(result);
}

unsigned long CCDAudio::GetTrackLength(unsigned char track,
                                       unsigned char& minutes,
                                       unsigned char& seconds) {
    tagMCI_STATUS_PARMS mciStatusParms;
    unsigned int track_local;
    unsigned long result;
    unsigned short item;

    track_local = track & 0xFF;
    mciStatusParms.dwItem = 1;
    mciStatusParms.dwTrack = track_local;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x112,
                             (DWORD)&mciStatusParms);
    item = (unsigned short)mciStatusParms.dwReturn;
    minutes = (unsigned char)item;
    seconds = (unsigned char)(item >> 8);
    return DisplayErrorMsg(result);
}

unsigned long CCDAudio::GetPosition(unsigned char& minutes,
                                    unsigned char& seconds,
                                    unsigned char& frames) {
    tagMCI_STATUS_PARMS mciStatusParms;
    unsigned long result;
    unsigned long item;
    unsigned short time;

    mciStatusParms.dwItem = 2;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x102,
                             (DWORD)&mciStatusParms);
    item = mciStatusParms.dwReturn;
    time = (unsigned short)item;
    minutes = (unsigned char)time;
    seconds = (unsigned char)(time >> 8);
    frames = (unsigned char)(item >> 16);
    return DisplayErrorMsg(result);
}

unsigned long CCDAudio::DisplayErrorMsg(unsigned long error) {
    char szErrorMsg[256];

    if (error != 0) {
        if (mciGetErrorStringA(error, szErrorMsg, 0x100) == 0) {
            strcpy(szErrorMsg, "Unknown Error");
        }
    }
    return error;
}
