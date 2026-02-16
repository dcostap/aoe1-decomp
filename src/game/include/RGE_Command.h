#pragma once
#include "common.h"

class RGE_Game_World;
class TCommunications_Handler;
class RGE_Command_Give_Attribute;
class RGE_Command_Add_Attribute;
class RGE_Command_Create;
struct RGE_Obj_Info;

class RGE_Command {
public:
    RGE_Command(RGE_Game_World* param_1, TCommunications_Handler* param_2);
    void reset_communications(TCommunications_Handler* param_1);

    // Virtuals (best-effort)
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* param_1); // vt[0] (0x0)
    virtual ~RGE_Command(); // vt[1] (0x4)
    virtual void do_command(void* param_1); // vt[2] (0x8)
    virtual void command_give_attribute(int param_1, int param_2, int param_3, float param_4); // vt[3] (0xC)
    RGE_Static_Object* get_obj(RGE_Obj_Info param_1);
    void submit(void* param_1, long param_2);
    void do_command_create(RGE_Command_Create* param_1);
    void command_create(short param_1, short param_2, float param_3, float param_4, float param_5);
    void do_command_add_attribute(RGE_Command_Add_Attribute* param_1);
    void command_add_attribute(int param_1, int param_2, float param_3);

    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;
};
static_assert(sizeof(RGE_Command) == 0x18, "Size mismatch");
