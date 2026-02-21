#pragma once
#include "common.h"

class RGE_Game_World;
class TCommunications_Handler;
class RGE_Command_Give_Attribute;
class RGE_Command_Add_Attribute;
class RGE_Command_Create;
struct RGE_Command_Add_Waypoint;
struct RGE_Command_Group_Waypoint;
struct RGE_Command_AI_Order;
struct RGE_Command_Group_AI_Order;
struct RGE_Command_Resign;
struct RGE_Command_Stop;
struct RGE_Command_Pause;
struct RGE_Command_Order;
struct RGE_Command_Formation;
struct RGE_Command_Create_Group;
struct RGE_Command_Destroy_Group;
struct RGE_Command_Add_To_Group;
struct RGE_Command_Remove_From_Group;
struct RGE_Obj_Info;

class RGE_Command {
public:
    RGE_Command(RGE_Game_World* param_1, TCommunications_Handler* param_2);
    void reset_communications(TCommunications_Handler* param_1);
    void do_commands();

    // Virtuals (best-effort)
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* param_1); // vt[0] (0x0)
    virtual ~RGE_Command(); // vt[1] (0x4)
    virtual void do_command(void* param_1); // vt[2] (0x8)
    virtual void command_give_attribute(int param_1, int param_2, int param_3, float param_4); // vt[3] (0xC)
    RGE_Static_Object* get_obj(RGE_Obj_Info param_1);
    void submit(void* param_1, long param_2);
    void do_command_order(RGE_Command_Order* param_1);
    void do_command_stop(RGE_Command_Stop* param_1);
    void do_command_pause(RGE_Command_Pause* param_1);
    void do_command_work(RGE_Command_Order* param_1);
    void do_command_move(RGE_Command_Order* param_1);
    void do_command_formation(RGE_Command_Formation* param_1);
    void do_command_create_group(RGE_Command_Create_Group* param_1);
    void do_command_destroy_group(RGE_Command_Destroy_Group* param_1);
    void do_command_add_to_group(RGE_Command_Add_To_Group* param_1);
    void do_command_remove_from_group(RGE_Command_Remove_From_Group* param_1);
    void do_command_add_waypoint(RGE_Command_Add_Waypoint* param_1);
    void do_command_group_waypoint(RGE_Command_Group_Waypoint* param_1);
    void do_command_ai_order(RGE_Command_AI_Order* param_1);
    void do_command_group_ai_order(RGE_Command_Group_AI_Order* param_1);
    void do_command_resign(RGE_Command_Resign* param_1);
    void do_command_create(RGE_Command_Create* param_1);
    void command_order(RGE_Static_Object** param_1, short param_2, RGE_Static_Object* param_3, float param_4, float param_5);
    void command_stop(RGE_Static_Object** param_1, short param_2);
    void command_stop(int param_1, int* param_2, int param_3);
    void command_pause(int param_1, int* param_2, int param_3);
    void command_work(RGE_Static_Object** param_1, short param_2, RGE_Static_Object* param_3, float param_4, float param_5);
    void command_work(int param_1, int* param_2, int param_3, int param_4, int param_5, float param_6, float param_7);
    void command_move(RGE_Static_Object** param_1, short param_2, RGE_Static_Object* param_3, float param_4, float param_5);
    void command_move(int param_1, int* param_2, int param_3, int param_4, int param_5, float param_6, float param_7);
    void command_create(short param_1, short param_2, float param_3, float param_4, float param_5);
    void do_command_add_attribute(RGE_Command_Add_Attribute* param_1);
    void command_add_attribute(int param_1, int param_2, float param_3);
    void command_formation(RGE_Static_Object** param_1, int param_2, int param_3);
    void command_create_group(int param_1, int param_2, int* param_3, int param_4, float param_5);
    void command_add_to_group(int param_1, int param_2, int param_3, float param_4);
    void command_remove_from_group(int param_1, int param_2, int param_3);
    void command_destroy_group(int param_1, int param_2);
    void command_ai_order(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, float param_7, float param_8, float param_9, float param_10, uchar param_11, uchar param_12, uchar param_13);
    void command_group_ai_order(int param_1, int param_2, RGE_Static_Object** param_3, short param_4, int param_5, int param_6, int param_7, float param_8, float param_9, float param_10, float param_11, uchar param_12, uchar param_13, uchar param_14);
    void command_resign(int param_1, int param_2, int param_3);
    void command_add_waypoint(int param_1, int param_2, XYZBYTEPoint* param_3, int param_4);
    void command_add_waypoint(int param_1, int param_2, uchar param_3, uchar param_4, uchar param_5);
    void command_group_waypoint(RGE_Static_Object** param_1, short param_2, uchar param_3, uchar param_4);

    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;
};
static_assert(sizeof(RGE_Command) == 0x18, "Size mismatch");
