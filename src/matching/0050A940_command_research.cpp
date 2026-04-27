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

class TRIBE_Command : public RGE_Command {
public:
    void command_research(int player_id, int bldg_id, int tech_id, int param4);
};

struct TDebuggingLog {
    void Log(const char* format, ...);
};

// 0062C4FC
extern "C" TDebuggingLog* L;

// 0054B730
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_research(int player_id, int bldg_id, int tech_id, int param4)
{
    if (bldg_id >= 0) {
        unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
        if (cmd) {
            *(int*)(cmd + 4) = bldg_id;
            cmd[8] = (char)player_id;
            cmd[0] = 0x65;
            *(short*)(cmd + 10) = (short)tech_id;
            *(int*)(cmd + 12) = param4;
            
            L->Log("      >SEND CMD RESEARCH2 (PLR=%d,BLDG=%d,TECH=%d)", player_id, bldg_id, tech_id);
            
            this->submit(cmd, 0x10);
        }
    }
}
