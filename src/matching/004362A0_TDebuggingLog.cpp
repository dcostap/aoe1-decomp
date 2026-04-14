class Base_TDebuggingLog {
public:
    virtual ~Base_TDebuggingLog();
};

class TDebuggingLog : public Base_TDebuggingLog {
};

extern "C" void probe_TDebuggingLog(TDebuggingLog* p);
#pragma alloc_text(".xtra", probe_TDebuggingLog)
extern "C" void probe_TDebuggingLog(TDebuggingLog* p) {
    p->TDebuggingLog::~TDebuggingLog();
}
