#include <stdlib.h>

#ifndef COMMAND_TU_CONTEXT
class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

extern TDebuggingLog* L;

class RGE_Command {
public:
    void submit(void* param_1, long param_2);
    void command_add_attribute(int param_1, int param_2, float param_3);
};
#endif

void RGE_Command::command_add_attribute(int param_1, int param_2, float param_3) {
    unsigned char* cmd = (unsigned char*)calloc(1, 8);
    cmd[0] = 5;
    cmd[1] = (unsigned char)param_1;
    cmd[2] = (unsigned char)param_2;
    *(float*)(cmd + 4) = param_3;
    L->Log("      >SEND CMD ADD ATTR (PLR=%d,ATT=%d)", param_1, param_2);
    this->submit(cmd, 8);
}
