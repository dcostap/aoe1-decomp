class TDebuggingLog {
public:
    int Timestamp;
    int DateTimestamp;

    char* YesOrNo(int value);
    void LogDateTimestamp(int value);
};

extern void Log(TDebuggingLog* log, const char* format, const char* value);

void TDebuggingLog::LogDateTimestamp(int value) {
    if (value != 0) {
        this->DateTimestamp = 1;
    } else {
        this->DateTimestamp = 0;
    }
    Log(this, "Date & Time stamp%s", this->YesOrNo(this->Timestamp));
}
