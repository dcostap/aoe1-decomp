#ifndef AOE1_COMMAND_H
#define AOE1_COMMAND_H

#include "command_waypoint.h"

class RGE_Game_World;
class RGE_Static_Object;
class TCommunications_Handler;

struct RGE_Obj_Info {
    int id;
};

struct RGE_Command_Header {
    unsigned char command;
};

struct RGE_Command_Order {
    unsigned char command;
    RGE_Obj_Info target;
    unsigned char unit_num;
    float location_x;
    float location_y;
};

struct RGE_Command_Stop {
    unsigned char command;
    unsigned char unit_num;
};

struct RGE_Command_Pause {
    unsigned char command;
    unsigned char unit_num;
};

struct RGE_Command_Give_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char to_player_id;
    unsigned char attr_id;
    float amount;
};

struct RGE_Command_Add_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char attr_id;
    float amount;
};

struct RGE_Command_Create {
    unsigned char command;
    short obj_catagory;
    unsigned char player_id;
    float location_x;
    float location_y;
    float location_z;
};

struct RGE_Command_Add_Waypoint {
    unsigned char command;
    unsigned char player_id;
    int recipient;
    unsigned char numberWaypoints;
    XYZBYTEPoint waypoint[5];
};

struct RGE_Command_AI_Order {
    unsigned char command;
    unsigned char player_id;
    unsigned char issuer;
    int recipient;
    short orderType;
    unsigned char orderPriority;
    int target;
    unsigned char targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
    unsigned char immediate;
    unsigned char inFront;
};

struct RGE_Command_Group_AI_Order {
    unsigned char command;
    unsigned char player_id;
    unsigned char issuer;
    unsigned char recipient_count;
    short orderType;
    unsigned char orderPriority;
    int target;
    unsigned char targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
    unsigned char immediate;
    unsigned char inFront;
};

struct RGE_Command_Resign {
    unsigned char command;
    unsigned char player_id;
    unsigned char comm_player_id;
    unsigned char dropped;
};

struct RGE_Command_Create_Group {
    unsigned char command;
    unsigned char player_id;
    int groupCommander;
    float groupRange;
    int unitsToGroup[25];
    unsigned char numberUnitsToGroup;
};

struct RGE_Command_Add_To_Group {
    unsigned char command;
    unsigned char player_id;
    int groupCommander;
    float group_range;
    int newUnit;
};

struct RGE_Command_Remove_From_Group {
    unsigned char command;
    unsigned char player_id;
    int groupCommander;
    int unit;
};

struct RGE_Command_Destroy_Group {
    unsigned char command;
    unsigned char player_id;
    int groupCommander;
};

struct RGE_Command_Formation {
    unsigned char command;
    int unitNum;
    int formationID;
};

struct RGE_Command_Group_Waypoint {
    unsigned char command;
    unsigned char unit_num;
    unsigned char x;
    unsigned char y;
};

typedef char rge_command_order_size_check[
    (sizeof(RGE_Command_Order) == 0x14) ? 1 : -1];
typedef char rge_command_stop_size_check[
    (sizeof(RGE_Command_Stop) == 0x02) ? 1 : -1];
typedef char rge_command_pause_size_check[
    (sizeof(RGE_Command_Pause) == 0x02) ? 1 : -1];
typedef char rge_command_group_ai_order_size_check[
    (sizeof(RGE_Command_Group_AI_Order) == 0x24) ? 1 : -1];
typedef char rge_command_formation_size_check[
    (sizeof(RGE_Command_Formation) == 0x0C) ? 1 : -1];
typedef char rge_command_group_waypoint_size_check[
    (sizeof(RGE_Command_Group_Waypoint) == 0x04) ? 1 : -1];

class RGE_Command {
protected:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute*);

public:
    virtual ~RGE_Command();
    virtual void do_command(void*);
    virtual void command_give_attribute(int, int, int, float);

    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;

    RGE_Command(RGE_Game_World*, TCommunications_Handler*);
    void reset_communications(TCommunications_Handler*);
    void do_commands();

protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info);
    void do_command_group_waypoint(RGE_Command_Group_Waypoint*);
    void do_command_add_attribute(RGE_Command_Add_Attribute*);
    void do_command_formation(RGE_Command_Formation*);
    void do_command_ai_order(RGE_Command_AI_Order*);
    void do_command_group_ai_order(RGE_Command_Group_AI_Order*);
    void do_command_create(RGE_Command_Create*);
    void do_command_create_group(RGE_Command_Create_Group*);
    void do_command_pause(RGE_Command_Pause*);
    void do_command_add_waypoint(RGE_Command_Add_Waypoint*);
    void do_command_work(RGE_Command_Order*);
    void do_command_move(RGE_Command_Order*);
    void do_command_order(RGE_Command_Order*);
    void do_command_stop(RGE_Command_Stop*);
    void do_command_resign(RGE_Command_Resign*);
    void do_command_destroy_group(RGE_Command_Destroy_Group*);
    void do_command_remove_from_group(RGE_Command_Remove_From_Group*);
    void do_command_add_to_group(RGE_Command_Add_To_Group*);
    unsigned char duplicate_check_command_order(RGE_Command_Order*);
    unsigned char duplicate_check_command_stop(RGE_Command_Stop*);
    unsigned char close_check_for_duplicate_orders(unsigned char*);
    unsigned char check_for_duplicate_orders(unsigned char*, long);
    void submit(void*, long);

public:
    void command_order(RGE_Static_Object**, short, RGE_Static_Object*, float,
                       float);
    void command_stop(RGE_Static_Object**, short);
    void command_stop(int, int*, int);
    void command_pause(int, int*, int);
    void command_work(RGE_Static_Object**, short, RGE_Static_Object*, float,
                      float);
    void command_work(int, int*, int, int, int, float, float);
    void command_move(RGE_Static_Object**, short, RGE_Static_Object*, float,
                      float);
    void command_move(int, int*, int, int, int, float, float);
    void command_create(short, short, float, float, float);
    void command_add_attribute(int, int, float);
    void command_formation(RGE_Static_Object**, int, int);
    void command_create_group(int, int, int*, int, float);
    void command_add_to_group(int, int, int, float);
    void command_add_to_group(int, int, int, int);
    void command_remove_from_group(int, int, int);
    void command_destroy_group(int, int);
    void command_ai_order(int, int, int, int, int, int, float, float, float,
                          float, unsigned char, unsigned char,
                          unsigned char);
    void command_group_ai_order(int, int, RGE_Static_Object**, short, int, int,
                                int, float, float, float, float,
                                unsigned char, unsigned char, unsigned char);
    void command_resign(int, int, int);
    void command_add_waypoint(int, int, unsigned char, unsigned char,
                              unsigned char);
    void command_add_waypoint(int, int, XYZBYTEPoint*, int);
    void command_group_waypoint(RGE_Static_Object**, short, unsigned char,
                                unsigned char);
};

typedef char rge_command_size_check[
    (sizeof(RGE_Command) == 0x18) ? 1 : -1];

#endif
