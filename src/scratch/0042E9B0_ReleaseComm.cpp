// attempt 1: wrong virtual call shape, wrong copy pattern, 87 bytes
// attempt 2: fixed offsets, still wrong virtual call, log call, copy
// attempt 3: windows.h include, vtbl cast; virtual call shape matches but body 0x60 vs 0x47 (too long)
// attempt 4: left in scratch after 4 attempts
// Remaining: VC5 generates much longer body (log call uses wrong arg order, copy uses 3 dword movs with wrong offsets)
// Original uses: lea eax,[esi+0x1318]; add esp,0xC; add esi,0x12DC; 4 explicit movs with ecx/edx

#include <windows.h>

void* debugging_log_global;
void* com_global;

void logCommonHistory(void* logObj, const char* format, int param);

class TCommunications_Handler {
public:
    char gap_00[0x12DC];
    int nullGUID[4];
    char gap_12EC[0x24];
    int serviceGUID[4];

    long ReleaseComm();
};

long TCommunications_Handler::ReleaseComm() {
    if (com_global) {
        int* vtbl = *(int**)com_global;
        ((void(*)(void*))vtbl[2])(com_global);
        logCommonHistory(debugging_log_global, "1.Release COMM links=%d", *(int*)com_global);
        nullGUID[0] = serviceGUID[0];
        nullGUID[1] = serviceGUID[1];
        nullGUID[2] = serviceGUID[2];
        nullGUID[3] = serviceGUID[3];
        com_global = 0;
    }
    return 0;
}
