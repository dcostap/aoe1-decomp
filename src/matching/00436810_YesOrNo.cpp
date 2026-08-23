// YesOrNo (00436810, 21 bytes, Debuglog.cpp)
// returns string based on param value
#ifndef DEBUGLOG_CANONICAL_TU
class TDebuggingLog {
public:
    unsigned char _pad[1];
protected:
    char* YesOrNo(int param);
};
#endif

char* TDebuggingLog::YesOrNo(int param) {
    if (param != 0)
        return " is now ACTIVE.";
    return " has been deactivated.";
}
