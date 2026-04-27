// target: VA 0042A0C0 TCommunications_Handler::CountWaitingMessages()
// first pass: mirror the 0x38-byte scan, conditional debug log, and count increment
// probe 1: wrapper helper for the log call bloated the prolog; switch to a direct absolute call shape
// blocker: current source still lands in the wrong prolog/basin (ecx-base + countdown loop shape), so I’m pausing at the cap and keeping this in scratch

class TDebuggingLog;
class RESENDER;

class TCommunications_Handler {
public:
    char gap_00[0x1520];
    RESENDER* Resend; // +0x1520

    int CountWaitingMessages();
};

int TCommunications_Handler::CountWaitingMessages() {
    int iVar2;
    int iVar4;
    unsigned int uVar3;
    char* entry;

    iVar2 = 0;
    iVar4 = 0;
    uVar3 = 0;
    entry = (char*)this->Resend;
    do {
        if (*(int*)(entry + 4) != 0) {
            ((void (__cdecl *)(
                TDebuggingLog*,
                const char*,
                int,
                int,
                int,
                int,
                int,
                int,
                int,
                int,
                int,
                int,
                int,
                int))0x00436610)(
                    *(TDebuggingLog**)0x62C4FC,
                    (const char*)0x581E74,
                    *(int*)(entry + 4),
                    iVar4,
                    *(signed char*)(*(char**)(entry + 8)),
                    *(int*)(entry + 0x0C),
                    *(int*)(entry + 0x14),
                    *(int*)(entry + 0x18),
                    *(int*)(entry + 0x1C),
                    *(int*)(entry + 0x20),
                    *(int*)(entry + 0x24),
                    *(int*)(entry + 0x28),
                    *(int*)(entry + 0x2C),
                    *(int*)(entry + 0x30));
            ++iVar2;
        }
        entry += 0x38;
        uVar3 = uVar3 + 0x38;
        iVar4 = iVar4 + 1;
    } while (uVar3 < 0x6D99);
    return iVar2;
}
