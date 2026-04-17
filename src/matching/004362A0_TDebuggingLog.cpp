class TDebuggingLog {
public:
    void CloseLog(void);
    ~TDebuggingLog();
};

TDebuggingLog::~TDebuggingLog() {
    this->CloseLog();
}
