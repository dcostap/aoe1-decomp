#include "../../include/cdaudio_context.h"

unsigned long CCDAudio::Stop(void) {
    return DisplayErrorMsg(mciSendCommandA(m_nDeviceID, 0x808, 2, 0));
}
