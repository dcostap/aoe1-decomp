#include "../../include/cdaudio_context.h"

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
