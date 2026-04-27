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
    void command_queue(RGE_Static_Object* building, short train_id, short count);
};

struct TDebuggingLog {
    void Log(const char* format, ...);
};

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_queue(RGE_Static_Object* building, short train_id, short count)
{
    unsigned char* cmd = (unsigned char*)calloc(1, 0x0C);
    if (cmd) {
        cmd[0] = 0x77;
        int building_id = building->id;
        *(short*)(cmd + 10) = count;
        *(int*)(cmd + 4) = building_id;
        *(short*)(cmd + 8) = train_id;
        L->Log("      >SEND CMD QUEUE (B=%d,T=%d,C=%d)", building->id, (int)train_id, (int)count);
        this->submit(cmd, 0x0C);
    }
}
