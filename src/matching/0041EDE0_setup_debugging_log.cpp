extern int log_output;



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
