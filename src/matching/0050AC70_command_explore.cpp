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
    void command_explore(int player_id, int *obj_ids, int obj_count, float x, float y);
};

struct TDebuggingLog {
    void Log(const char* format, ...);
};

// 0062C4FC
extern "C" TDebuggingLog* L;

// 0054B730
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_explore(int player_id, int *obj_ids, int obj_count, float x, float y)
{
    if (obj_ids && obj_count >= 1) {
        int size = obj_count * 4 + 12;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 12);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                dest[i] = obj_ids[i];
            }
            cmd[0] = 0x68;
            cmd[1] = (unsigned char)obj_count;
            cmd[2] = (unsigned char)player_id;
            *(float*)(cmd + 4) = x;
            *(float*)(cmd + 8) = y;
            
            L->Log("      >SEND CMD EXPLORE (CNT=%d)", obj_count);
            
            this->submit(cmd, size);
        }
    }
}
