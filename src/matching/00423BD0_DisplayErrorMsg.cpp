#include <string.h>

extern "C" __declspec(dllimport) int __stdcall mciGetErrorStringA(unsigned long error, char* buffer, unsigned int length);

class CCDAudio {
public:
    unsigned long DisplayErrorMsg(unsigned long error);
};

unsigned long CCDAudio::DisplayErrorMsg(unsigned long error) {
    char szErrorMsg[256];

    if (error != 0) {
        if (mciGetErrorStringA(error, szErrorMsg, 0x100) == 0) {
            strcpy(szErrorMsg, "Unknown Error");
        }
    }
    return error;
}
