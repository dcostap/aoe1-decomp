// VA: 0050AFD0 TRIBE_Command::command_cancel_build
// PDB: tcommand.cpp lines 1450-1471.
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
    void command_cancel_build(RGE_Static_Object* obj);
};

struct TDebuggingLog {
    void __cdecl Log(char* format, ...);
};

extern TDebuggingLog* L;

class TRIBE_Command_Cancel_Build {
public:
    unsigned char command;
    char gap_01[3];
    int unit_id;
};
#endif

extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_cancel_build(RGE_Static_Object* obj)
{
    TRIBE_Command_Cancel_Build* cmd =
        (TRIBE_Command_Cancel_Build*)calloc(1, 8);
    if (cmd) {
        cmd->command = 0x6A;
        cmd->unit_id = obj->id;
        L->Log((char*)"      >SEND CMD CANCELBLD");
        this->submit(cmd, 8);
    }
}
