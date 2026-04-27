// target: VA 0042B200 TCommunications_Handler::GetNextSequence(unsigned long)
// first pass: mirror the last-sequence check, byte increment/log path, and pause-state clamp
// probe 1: direct global names still leave VC5 in the wrong data-ref/store basin; the first-branch byte store is the remaining mismatch
// probe 2: tried raw address casts and a helper log call; it fixed behavior but not the exact byte/store shape
// blocker: exact match likely needs the living shared global declarations/definitions for DAT_0062cf2c/DAT_0062cf30, not more local re-spelling

class TDebuggingLog;
extern unsigned char byte_62CF2C;
extern unsigned long dword_62CF30;
extern void __cdecl TDebuggingLog_Log(TDebuggingLog* log, const char* msg, int value);

class TCommunications_Handler {
public:
    char gap_00[0x1558];
    int pause_state; // +0x1558

    unsigned char GetNextSequence(unsigned long value);
};


unsigned char TCommunications_Handler::GetNextSequence(unsigned long value) {
    unsigned char seq;

    if (value != dword_62CF30) {
        dword_62CF30 = value;
        byte_62CF2C = 1;
        seq = 1;
        return seq;
    }

    seq = byte_62CF2C;
    ++seq;
    byte_62CF2C = seq;
    if (seq == 0xFF) {
        TDebuggingLog_Log(*(TDebuggingLog**)0x62C4FC, (const char*)0x582490, seq);
        return 0;
    }

    if (this->pause_state == 4 && seq > 100) {
        byte_62CF2C = 100;
        seq = 100;
    }

    return seq;
}
