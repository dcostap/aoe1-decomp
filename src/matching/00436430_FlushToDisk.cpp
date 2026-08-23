class TDebuggingLog;
extern TDebuggingLog* L;

#ifndef DEBUGLOG_CANONICAL_TU
class TDebuggingLog {
public:
    char gap_00[0x14];
    int Flush;

protected:
    char* YesOrNo(int value);
public:
    void __cdecl Log(char* format, ...);
    void FlushToDisk(int value);
};
#endif

void TDebuggingLog::FlushToDisk(int value) {
    if (value != 0) {
        this->Flush = 1;
    } else {
        this->Flush = 0;
    }
    this->Log("Flush queue each message %s", this->YesOrNo(this->Flush));
}
