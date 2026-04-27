// ACCEPTED_DRIFT: packet-fill/log scheduling drift only. Rebuilt performs the log call before storing the player/header bytes, but the packet pointer has not escaped; before submit the same subtype/player/target/relation/float fields are present and calls/stack cleanup are equivalent.
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
    void command_relation(short player_id, short target_player_id, short relation);
};

struct TDebuggingLog {
    void Log(const char* format, ...);
};

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_relation(short player_id, short target_player_id, short relation)
{
    TRIBE_Command* self = this;
    unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
    if (cmd) {
        short rel_s = relation;
        short player_s = player_id;
        short target_s = target_player_id;
        int rel_i = (int)rel_s;
        *(short*)(cmd + 4) = target_s;
        *(float*)(cmd + 8) = (float)rel_i;
        *(short*)(cmd + 12) = rel_s;
        L->Log("      >SEND CMD RELATION (PLR=%d,TAR=%d,REL=%d)", (int)player_s, (int)target_s, rel_i);
        *(short*)(cmd + 2) = player_s;
        cmd[0] = 0x67;
        cmd[1] = 0;
        self->submit(cmd, 0x10);
    }
}
