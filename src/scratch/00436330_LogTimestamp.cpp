class TDebuggingLog {
public:
    int Timestamp;

    void LogTimestamp(int value);
    char* YesOrNo(int value);
};

extern void Log(TDebuggingLog* log, const char* format, const char* value);

void TDebuggingLog::LogTimestamp(int value) {
    int enabled;
    char* text;

    enabled = value != 0;
    this->Timestamp = enabled;
    text = this->YesOrNo(enabled);
    Log(this, "Timestamp milliseconds %s", text);
}
