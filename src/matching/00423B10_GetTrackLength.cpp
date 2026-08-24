#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::GetTrackLength(unsigned char track, unsigned char& minutes, unsigned char& seconds) {
    tagMCI_STATUS_PARMS mciStatusParms;
    unsigned int track_local;
    unsigned long result;
    unsigned short item;

    track_local = track & 0xFF;
    mciStatusParms.dwItem = 1;
    mciStatusParms.dwTrack = track_local;
    result = mciSendCommandA(this->m_nDeviceID, 0x814, 0x112, (DWORD)&mciStatusParms);
    item = (unsigned short)mciStatusParms.dwReturn;
    minutes = (unsigned char)item;
    seconds = (unsigned char)(item >> 8);
    return DisplayErrorMsg(result);
}
