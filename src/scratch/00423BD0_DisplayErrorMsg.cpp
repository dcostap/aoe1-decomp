// STATUS: blocked
// BLOCKER: need the exact inline fallback copy for the "Unknown Error" literal without introducing helper calls or a different copy loop
// NOTE: control flow is understood; remaining work is precise source shape for the fallback string copy

extern "C" __declspec(dllimport) int __stdcall mciGetErrorStringA(unsigned long error, char* buffer, unsigned int length);

class CCDAudio {
public:
    unsigned long DisplayErrorMsg(unsigned long error);
};

unsigned long CCDAudio::DisplayErrorMsg(unsigned long error) {
    char szErrorMsg[256];

    if (error != 0) {
        if (mciGetErrorStringA(error, szErrorMsg, 0x100) == 0) {
            memcpy(szErrorMsg, "Unknown Error", sizeof("Unknown Error"));
        }
    }
    return error;
}
