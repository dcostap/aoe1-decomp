#pragma once
#include "common.h"

class RGE_Command {
public:
    // Virtuals (best-effort)
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* param_1); // vt[0] (0x0)
    virtual ~RGE_Command(); // vt[1] (0x4)
    virtual void do_command(void* param_1); // vt[2] (0x8)
    virtual void command_give_attribute(int param_1, int param_2, int param_3, float param_4); // vt[3] (0xC)

    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;
};
static_assert(sizeof(RGE_Command) == 0x18, "Size mismatch");
