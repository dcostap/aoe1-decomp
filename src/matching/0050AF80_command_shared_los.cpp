#include <stdlib.h>

class TDebuggingLog;
extern void __cdecl Log(TDebuggingLog* log, char* text);

class TRIBE_Command {
public:
    void* vtable_ptr;
    void* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    void* com_hand;

    void submit(void* order, long size);
    void command_shared_los(short param_1);
};

extern TDebuggingLog* g_debug_log;

void TRIBE_Command::command_shared_los(short param_1) {
    void* order;

    order = calloc(1, 0x10);
    if (order != 0) {
        *(unsigned char*)order = 0x67;
        *(short*)((char*)order + 2) = param_1;
        *((unsigned char*)order + 1) = 7;
        Log(g_debug_log, (char*)"      >SEND CMD SHAREDLOS");
        this->submit(order, 0x10);
    }
}
