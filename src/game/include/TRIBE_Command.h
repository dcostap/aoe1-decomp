#pragma once
#include "common.h"
#include "RGE_Command.h"

class TRIBE_Command_Give_Attribute;

class TRIBE_Command : public RGE_Command {
public:
    TRIBE_Command(RGE_Game_World* world, TCommunications_Handler* comm);

    // Virtuals (best-effort)
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* param_1); // vt[0] (0x0)
    virtual ~TRIBE_Command(); // vt[1] (0x4)
    virtual void do_command(void* param_1); // vt[2] (0x8)
    virtual void command_give_attribute(int param_1, int param_2, int param_3, float param_4); // vt[3] (0xC)
    virtual void do_command_give_attribute_tribe(TRIBE_Command_Give_Attribute* param_1); // vt[4] (0x10)
    virtual void command_give_attribute(int param_1, int param_2, int param_3, float param_4, float param_5); // vt[5] (0x14)

};
static_assert(sizeof(TRIBE_Command) == 0x18, "Size mismatch");
