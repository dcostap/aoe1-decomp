// YesOrNo (00436810, 21 bytes, Debuglog.cpp)
// returns string based on param value
#include "game_globals.h"
#include "game_types.h"

class TDebuggingLog {
public:
    unsigned char _pad[1];
};

char* TDebuggingLog::YesOrNo(int param) {
    if (param == 0)
        return " has been deactivated.";
    return " is now ACTIVE.";
}
