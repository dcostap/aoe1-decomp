// attempt 1: calloc(0xC,1) with if (buf && (buf+8)); 80 bytes (missing redundant test)
// attempt 2: <stdlib.h> for calloc decl; same 80 bytes
// attempt 3: int* p = buf+8 as named temp; same 80 bytes
// attempt 4: nested if (buf) if (p); same 80 bytes
// attempt 5: nested if with explicit != NULL; same 80 bytes
// attempt 6: fixed calloc(1, 0xC) arg order; same 80 bytes
// Original has redundant 'test eax,eax; je' after 'lea eax,[esi+8]' that VC5 /O2 always eliminates
// Left in scratch: benign 3-byte codegen drift, behavior fully correct

#include <stdlib.h>

extern void* L;

class TDebuggingLog {
public:
    void Log(const char* msg);
};

class RGE_Command {
public:
    void submit(void* data, int size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_trade_attribute(int param_1, int param_2, long param_3);
};

void TRIBE_Command::command_trade_attribute(int param_1, int param_2, long param_3) {
    unsigned char* buf = (unsigned char*)calloc(1, 0xC);
    if (buf != NULL) {
        if ((void*)(buf + 8) != NULL) {
            *(int*)(buf + 8) = param_1;
            buf[0] = 0x6D;
            buf[1] = 1;
            *(long*)(buf + 4) = param_3;
            ((TDebuggingLog*)L)->Log((const char*)0x588EF0);
            submit(buf, 0xC);
        }
    }
}
