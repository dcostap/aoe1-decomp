// ACCEPTED_DRIFT: localized tail scheduling/register drift only. Rebuilt prepares the log pushes before loading the count byte, then performs the same target-id load, packet command/target/count stores, log call, submit call, and stack cleanup; the earlier loop and allocation path match exactly.
// started from command_unload's matching donor-file context; moving obj_count/size before the guard fixed the prolog and list-copy loop.
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
    void command_repair(RGE_Static_Object** objs, short count, RGE_Static_Object* target);
};

struct TDebuggingLog {
    void Log(const char* format, ...);
};

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_repair(RGE_Static_Object** objs, short count, RGE_Static_Object* target)
{
    int obj_count = (int)count;
    int size = obj_count * 4 + 8;
    if (objs && count >= 1) {
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
            unsigned char count_byte = (unsigned char)count;
            int target_id = target->id;
            cmd[0] = 0x6E;
            *(int*)(cmd + 4) = target_id;
            cmd[1] = count_byte;

            L->Log("      >SEND CMD REPAIR (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}
