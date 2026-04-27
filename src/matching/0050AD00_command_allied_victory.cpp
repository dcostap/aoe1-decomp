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
    void command_allied_victory(short player_id, unsigned char flag);
};

struct TDebuggingLog {
    void Log(const char* format, ...);
};

// 0062C4FC
extern "C" TDebuggingLog* L;

// 0054B730
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_allied_victory(short player_id, unsigned char flag)
{
    unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
    if (cmd) {
        *(short*)(cmd + 2) = player_id;
        
        int flag_int = (int)flag;
        unsigned short flag_short = (unsigned short)flag;
        *(unsigned short*)(cmd + 4) = flag_short;

        int player_id_int = (int)player_id;
        *(unsigned int*)(cmd + 8) = 0;

        cmd[0] = 0x67;
        cmd[1] = 5;
        
        L->Log("      >SEND CMD ALLIED VIC (PLR=%d,FLAG=%d)", player_id_int, flag_int);
        
        this->submit(cmd, 0x10);
    }
}
