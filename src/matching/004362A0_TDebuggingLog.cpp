#ifndef DEBUGLOG_CANONICAL_TU
class TDebuggingLog {
public:
    void CloseLog(void);
    ~TDebuggingLog();
};
#endif

TDebuggingLog::~TDebuggingLog() {
    this->CloseLog();
}
