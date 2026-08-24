#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::Pause(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x809, 2, 0));
}
