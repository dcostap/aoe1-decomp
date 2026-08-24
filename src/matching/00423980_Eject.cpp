#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::Eject(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x80D, 0x100, 0));
}
