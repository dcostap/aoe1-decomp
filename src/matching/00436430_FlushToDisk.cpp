class TDebuggingLog;
extern TDebuggingLog* L;
extern void Log(TDebuggingLog* log, const char* format, const char* value);

class TDebuggingLog {
public:
    char gap_00[0x14];
    int Flush;

    const char* YesOrNo(int value);
    void FlushToDisk(int value);
};

void TDebuggingLog::FlushToDisk(int value) {
    if (value != 0) {
        this->Flush = 1;
    } else {
        this->Flush = 0;
    }
    Log(this, "Flush queue each message %s", this->YesOrNo(this->Flush));
}
