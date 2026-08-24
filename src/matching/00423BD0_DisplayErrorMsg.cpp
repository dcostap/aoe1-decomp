#include "../../include/cdaudio_context.h"
#include <string.h>

unsigned long CCDAudio::DisplayErrorMsg(unsigned long error) {
    char szErrorMsg[256];

    if (error != 0) {
        if (mciGetErrorStringA(error, szErrorMsg, 0x100) == 0) {
            strcpy(szErrorMsg, "Unknown Error");
        }
    }
    return error;
}
