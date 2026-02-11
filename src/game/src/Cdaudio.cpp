// Decompiled: Cdaudio.cpp
// SourceMap: C:/msdev/work/age1_x1/Cdaudio.cpp

#include "../include/CCDAudio.h"

// Offset: 0x004237C0
CCDAudio::CCDAudio() {
    this->m_Wnd = nullptr;
    this->m_bOpened = 0;
}

// Offset: 0x004237D0
CCDAudio::~CCDAudio() {
    int playing = 0;
    this->IsPlaying(playing);
    if (playing != 0) {
        this->Stop();
    }
    this->Close();
}

// Offset: 0x00423800
ulong CCDAudio::Open(void* param_1) {
    ulong uVar1;
    MCI_OPEN_PARMSA mciOpenParms;
    MCI_SET_PARMS mciSetInfo;

    this->m_Wnd = param_1;
    if (this->m_bOpened != 0) {
        this->Close();
    }

    memset(&mciOpenParms, 0, sizeof(mciOpenParms));
    mciOpenParms.lpstrDeviceType = (LPCSTR)MCI_DEVTYPE_CD_AUDIO;
    uVar1 = mciSendCommandA(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID, (DWORD_PTR)&mciOpenParms);
    if (uVar1 == 0) {
        this->m_bOpened = 1;
        this->m_nDeviceID = mciOpenParms.wDeviceID;
        memset(&mciSetInfo, 0, sizeof(mciSetInfo));
        mciSetInfo.dwTimeFormat = MCI_FORMAT_TMSF;
        uVar1 = mciSendCommandA(mciOpenParms.wDeviceID, MCI_SET, MCI_SET_TIME_FORMAT, (DWORD_PTR)&mciSetInfo);
    }
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x00423880
ulong CCDAudio::Close() {
    ulong uVar1 = 0;
    if (this->m_bOpened != 0) {
        uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_CLOSE, MCI_WAIT, 0);
        this->DisplayErrorMsg(uVar1);
        if (uVar1 == 0) {
            this->m_bOpened = 0;
        }
    }
    return uVar1;
}

// Offset: 0x004238C0
ulong CCDAudio::Stop() {
    ulong uVar1;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_STOP, MCI_WAIT, 0);
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x004238E0
ulong CCDAudio::Play(uchar param_1) {
    ulong uVar1;
    this->m_mciPlayParms.dwCallback = (DWORD_PTR)this->m_Wnd;
    this->m_mciPlayParms.dwFrom = (DWORD)param_1;
    this->m_mciPlayParms.dwTo = (DWORD)(uchar)(param_1 + 1);
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_PLAY,
        MCI_FROM | MCI_TO | MCI_NOTIFY,
        (DWORD_PTR)&this->m_mciPlayParms);
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x00423930
ulong CCDAudio::Pause() {
    ulong uVar1;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_PAUSE, MCI_WAIT, 0);
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x00423950
ulong CCDAudio::ResumePlay() {
    ulong uVar1;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_PLAY, 0, (DWORD_PTR)&this->m_mciPlayParms);
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x00423980
ulong CCDAudio::Eject() {
    ulong uVar1;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_SET, MCI_SET_DOOR_OPEN, 0);
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x004239B0
ulong CCDAudio::GetNumberOfTracks(uchar& param_1) {
    ulong uVar1;
    MCI_STATUS_PARMS mciStatusInfo;
    memset(&mciStatusInfo, 0, sizeof(mciStatusInfo));
    mciStatusInfo.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT,
        (DWORD_PTR)&mciStatusInfo);
    param_1 = (uchar)mciStatusInfo.dwReturn;
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x004239F0
ulong CCDAudio::IsMediaPresent(int& param_1) {
    ulong uVar1;
    MCI_STATUS_PARMS mciStatusParms;
    memset(&mciStatusParms, 0, sizeof(mciStatusParms));
    mciStatusParms.dwItem = MCI_STATUS_MEDIA_PRESENT;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT,
        (DWORD_PTR)&mciStatusParms);
    param_1 = (mciStatusParms.dwReturn != 0) ? 1 : 0;
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x00423A40
ulong CCDAudio::IsPlaying(int& param_1) {
    ulong uVar1;
    MCI_STATUS_PARMS mciStatusParms;
    memset(&mciStatusParms, 0, sizeof(mciStatusParms));
    mciStatusParms.dwItem = MCI_STATUS_MODE;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT,
        (DWORD_PTR)&mciStatusParms);
    param_1 = (mciStatusParms.dwReturn == MCI_MODE_PLAY) ? 1 : 0;
    if (mciStatusParms.dwReturn == MCI_MODE_PLAY) {
        mciStatusParms.dwItem = MCI_STATUS_CURRENT_TRACK;
        uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_STATUS,
            MCI_STATUS_ITEM | MCI_WAIT,
            (DWORD_PTR)&mciStatusParms);
        param_1 = (int)mciStatusParms.dwReturn;
    }
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x00423AC0
ulong CCDAudio::GetLength(uchar& param_1, uchar& param_2) {
    ulong uVar1;
    MCI_STATUS_PARMS mciStatusParms;
    memset(&mciStatusParms, 0, sizeof(mciStatusParms));
    mciStatusParms.dwItem = MCI_STATUS_LENGTH;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT,
        (DWORD_PTR)&mciStatusParms);
    param_1 = (uchar)(mciStatusParms.dwReturn & 0xFF);
    param_2 = (uchar)((mciStatusParms.dwReturn >> 8) & 0xFF);
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x00423B10
ulong CCDAudio::GetTrackLength(uchar param_1, uchar& param_2, uchar& param_3) {
    ulong uVar1;
    MCI_STATUS_PARMS mciStatusParms;
    memset(&mciStatusParms, 0, sizeof(mciStatusParms));
    mciStatusParms.dwItem = MCI_STATUS_LENGTH;
    mciStatusParms.dwTrack = param_1;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_TRACK | MCI_WAIT,
        (DWORD_PTR)&mciStatusParms);
    param_2 = (uchar)(mciStatusParms.dwReturn & 0xFF);
    param_3 = (uchar)((mciStatusParms.dwReturn >> 8) & 0xFF);
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x00423B70
ulong CCDAudio::GetPosition(uchar& param_1, uchar& param_2, uchar& param_3) {
    ulong uVar1;
    MCI_STATUS_PARMS mciStatusParms;
    memset(&mciStatusParms, 0, sizeof(mciStatusParms));
    mciStatusParms.dwItem = MCI_STATUS_POSITION;
    uVar1 = mciSendCommandA(this->m_nDeviceID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT,
        (DWORD_PTR)&mciStatusParms);
    param_1 = (uchar)(mciStatusParms.dwReturn & 0xFF);
    param_2 = (uchar)((mciStatusParms.dwReturn >> 8) & 0xFF);
    param_3 = (uchar)((mciStatusParms.dwReturn >> 16) & 0xFF);
    uVar1 = this->DisplayErrorMsg(uVar1);
    return uVar1;
}

// Offset: 0x00423BD0
ulong CCDAudio::DisplayErrorMsg(ulong param_1) {
    char szErrorMsg[256];
    if (param_1 != 0) {
        int iVar2 = mciGetErrorStringA(param_1, szErrorMsg, 256);
        if (iVar2 == 0) {
            strncpy(szErrorMsg, "Unknown Error", sizeof(szErrorMsg));
        }
    }
    return param_1;
}
