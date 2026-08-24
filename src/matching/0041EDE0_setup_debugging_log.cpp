extern int log_output;

class TDebuggingLog {
public:
    char bytes[0x7B0];
    TDebuggingLog();
    void LogFile(int value);
    void LogOutput(int value);
    void LogTimestamp(int value);
};

class RGE_Base_Game {
public:
    virtual int setup_debugging_log();
    char gap0[0x1A0];
    TDebuggingLog* debugLog;
    int log_comm;
};

int RGE_Base_Game::setup_debugging_log()
{
    TDebuggingLog* log = new TDebuggingLog;
    debugLog = log;
    if (log == 0)
        return 0;

    log->LogFile(log_comm);
    debugLog->LogOutput(log_output);
    debugLog->LogTimestamp(1);
    return 1;
}
