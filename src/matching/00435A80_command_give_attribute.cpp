#include <stdlib.h>

#ifndef COMMAND_TU_CONTEXT
class TDebuggingLog;

extern TDebuggingLog* L;
void Log(TDebuggingLog* log, const char* format, int param_1, int param_2, int param_3);

class RGE_Command {
public:
    void submit(void* data, int size);
    void command_give_attribute(int param_1, int param_2, int param_3, float param_4);
};
#endif

void RGE_Command::command_give_attribute(int param_1, int param_2, int param_3, float param_4) {
    unsigned char* cmd = (unsigned char*)calloc(1, 8);
    cmd[0] = 7;
    cmd[1] = (unsigned char)param_1;
    cmd[2] = (unsigned char)param_2;
    cmd[3] = (unsigned char)param_3;
    *(float*)(cmd + 4) = param_4;
    Log(L, "      >SEND CMD GIV ATTR (FRM=%d,TO=%d,ATT=%d)", param_1, param_2, param_3);
    submit(cmd, 8);
}
