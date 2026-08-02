// VA: 00435900 RGE_Command::command_move
// PDB: Command.cpp lines 1586-1628
// Attempt log:
// - The original packet-copy/log/submit reconstruction had exact size but a shifted
//   register basin (arr in EBP, size in EDI instead of the original EDI/EBP).
// - A variadic TDebuggingLog::Log member declaration fixed the direct call identity.
// - The full proven RGE_Command virtual/data surface was restored; it did not move codegen.
// - Replacing the raw delta/do copy with the natural indexed loop `dst[i] = arr[i]` produced
//   the exact VC5 loop, prologue, stack-home reuse, and all following block offsets.
// - Typed master-object/name ownership, typed global L, and long submit size preserve the
//   exact bytes and make the local ABI/layout surface period-plausible.
#include <stdlib.h>

#define STR_SEND_CMD_MOVE2 ((const char*)0x00583C8C)
#define STR_X              ((const char*)0x00583B74)

class RGE_Game_World;
class RGE_Master_Static_Object { public: char pad_00[8]; const char* name; };
class RGE_Static_Object { public: char pad_00[8]; RGE_Master_Static_Object* master_obj; };
class RGE_Command_Give_Attribute;
class TCommunications_Handler;
class TDebuggingLog { public: void Log(const char* fmt, ...); };
extern TDebuggingLog* L;
class RGE_Command {
public:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* cmd);
    virtual ~RGE_Command();
    virtual void do_command(void* cmd);
    virtual void command_give_attribute(int player, int attr, int value, float amount);
    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;
    void command_move(int player, int* arr, int count, int param4, int unused, float x, float y);
    void submit(void* buf, long size);
};
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
void RGE_Command::command_move(int player, int* arr, int count, int param4, int unused, float x, float y)
{
    if (arr != 0 && count >= 1) {
        int size = count * 4 + 0x14;
        char* buf = (char*)calloc(1, size);
        int* dst = (int*)(buf + 0x14);
        if (buf != 0) {
            for (int i = 0; i < count; ++i) dst[i] = arr[i];
            buf[0] = 3; buf[8] = (char)count;
            *(int*)(buf + 4) = param4;
            *(float*)(buf + 0x0C) = x;
            *(float*)(buf + 0x10) = y;
            RGE_Static_Object* obj = this->world->object(arr[0]);
            const char* name; if (obj != 0) name = obj->master_obj->name; else name = STR_X;
            L->Log(STR_SEND_CMD_MOVE2, count, player, name);
            this->submit(buf, size);
        }
    }
}
