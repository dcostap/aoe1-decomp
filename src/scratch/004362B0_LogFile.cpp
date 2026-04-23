class TDebuggingLog {
public:
    char gap_00[0x08];
    int LogToFile;

    char* YesOrNo(int value);
    void LogFile(int value);
};

extern void Log(TDebuggingLog* log, const char* format, const char* value);

void TDebuggingLog::LogFile(int value) {
    int enabled;
    char* text;

    enabled = value != 0;
    this->LogToFile = enabled;
    text = this->YesOrNo(value);
    Log(this, "Logging to File %s", text);
}
