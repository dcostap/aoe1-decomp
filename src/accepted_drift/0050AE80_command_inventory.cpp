// ACCEPTED_DRIFT: packet-fill register/scheduling drift only. Rebuilt loads/stores amount before the two shorts while original stores inventory/amount/player in source order; all packet fields are set before the same log and submit calls.
// tried natural typed packet-fill form; logic is identical but VC5 load/store order is sticky.
// tried full donor-file RGE_Command/TDebuggingLog surface again while keeping raw packet writes.
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
    void command_inventory(short player_id, short inventory_id, float amount);
};

struct TDebuggingLog { void Log(const char* format, ...); };
extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_inventory(short player_id, short inventory_id, float amount)
{
    unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
    if (cmd) {
        short inv = inventory_id;
        short player = player_id;
        *(short*)(cmd + 4) = inv;
        *(float*)(cmd + 8) = amount;
        *(short*)(cmd + 2) = player;
        cmd[0] = 0x67;
        cmd[1] = 2;
        L->Log("      >SEND CMD INV (PLR=%d,INV=%d)", (int)player_id, (int)inventory_id);
        this->submit(cmd, 0x10);
    }
}
