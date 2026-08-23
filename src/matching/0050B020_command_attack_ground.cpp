// VA: 0050B020 TRIBE_Command::command_attack_ground
// PDB: tcommand.cpp lines 1477-1519.
// Exact grouped finish uses the canonical packet, log, and inherited submit.

#include <windows.h>
#include <stdio.h>

#ifndef TCOMMAND_CONTEXT_H
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

    void submit(void* cmd, long size);
};

class RGE_Static_Object {
public:
    char gap_00[4];
    int id;
};

class TRIBE_Command : public RGE_Command {
public:
    void command_attack_ground(RGE_Static_Object** objs, short count, float x, float y);
};

struct TDebuggingLog {
    void __cdecl Log(char* format, ...);
};

extern TDebuggingLog* L;

class TRIBE_Command_Attack_Ground {
public:
    unsigned char command;
    unsigned char unit_num;
    char gap_02[2];
    float location_x;
    float location_y;
};
#endif

extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_attack_ground(RGE_Static_Object** objs, short count, float x, float y)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = obj_count * 4 + 12;
        TRIBE_Command_Attack_Ground* cmd =
            (TRIBE_Command_Attack_Ground*)calloc(1, size);
        int* dest = (int*)(cmd + 1);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    dest[i] = objs[i]->id;
                } else {
                    dest[i] = -1;
                }
            }
            cmd->command = 0x6B;
            cmd->unit_num = (unsigned char)count;
            cmd->location_x = x;
            cmd->location_y = y;

            L->Log(
                (char*)"      >SEND CMD ATTACK GROUND (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}
