#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::ResumePlay(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x806, 0, (DWORD)&m_mciPlayParms));
}
