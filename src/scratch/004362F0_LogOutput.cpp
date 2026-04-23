class TDebuggingLog {
public:
    char gap_00[0x0C];
    int LogToOutput;

    char* YesOrNo(int value);
    void LogOutput(int value);
};

extern void Log(TDebuggingLog* log, const char* format, const char* value);

void TDebuggingLog::LogOutput(int value) {
    int enabled;
    char* text;

    enabled = value != 0;
    this->LogToOutput = enabled;
    text = this->YesOrNo(value);
    Log(this, "Logging to OUTPUT %s", text);
}
