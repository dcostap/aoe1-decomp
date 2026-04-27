#include <windows.h>
#include <stdio.h>

class RGE_Game_World;
class TCommunications_Handler;

class RGE_Command {
public:
    virtual void vfunc0() = 0;
    virtual ~RGE_Command() {}
    virtual void vfunc8() = 0;
    virtual void vfuncC() = 0;

    RGE_Game_World* world;
    void* last_order;
    int last_order_size;
    unsigned int last_order_time;
    TCommunications_Handler* com_hand;

    void submit(void* cmd, int size);
};

class RGE_Static_Object {
public:
    char gap_00[4];
    int id;
};

class TRIBE_Command : public RGE_Command {
public:
    void command_trade_attribute(RGE_Static_Object** objs, short count, long attribute);
};

struct TDebuggingLog {
    void Log(const char* format, ...);
};

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_trade_attribute(RGE_Static_Object** objs, short count, long attribute)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = obj_count * 4 + 8;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 8);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    dest[i] = objs[i]->id;
                } else {
                    dest[i] = -1;
                }
            }
            cmd[0] = 0x6D;
            cmd[1] = (unsigned char)count;
            *(long*)(cmd + 4) = attribute;

            L->Log("      >SEND CMD TRADE ATTR (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}
