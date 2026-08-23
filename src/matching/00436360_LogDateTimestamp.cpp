#ifndef DEBUGLOG_CANONICAL_TU
class TDebuggingLog {
public:
    int Timestamp;
    int DateTimestamp;

protected:
    char* YesOrNo(int value);
public:
    void __cdecl Log(char* format, ...);
    void LogDateTimestamp(int value);
};
#endif

void TDebuggingLog::LogDateTimestamp(int value) {
    if (value != 0) {
        this->DateTimestamp = 1;
    } else {
        this->DateTimestamp = 0;
    }
    this->Log("Date & Time stamp%s", this->YesOrNo(this->Timestamp));
}
