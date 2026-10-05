#ifndef AOE1_COMMAND_H
#define AOE1_COMMAND_H

#include "command_waypoint.h"

// Packet IDs. Macros keep the integer type and add no storage.
#define RGE_COMMAND_ID_ORDER             0
#define RGE_COMMAND_ID_STOP              1
#define RGE_COMMAND_ID_WORK              2
#define RGE_COMMAND_ID_MOVE              3
#define RGE_COMMAND_ID_CREATE            4
#define RGE_COMMAND_ID_ADD_ATTRIBUTE     5
#define RGE_COMMAND_ID_FORMATION         6
#define RGE_COMMAND_ID_GIVE_ATTRIBUTE    7
#define RGE_COMMAND_ID_CREATE_GROUP      8
#define RGE_COMMAND_ID_DESTROY_GROUP     9
#define RGE_COMMAND_ID_AI_ORDER          10
#define RGE_COMMAND_ID_RESIGN            11
#define RGE_COMMAND_ID_ADD_WAYPOINT      12
#define RGE_COMMAND_ID_PAUSE             13
#define RGE_COMMAND_ID_ADD_TO_GROUP      14
#define RGE_COMMAND_ID_REMOVE_FROM_GROUP 15
#define RGE_COMMAND_ID_GROUP_WAYPOINT    16
#define RGE_COMMAND_ID_GROUP_AI_ORDER    17

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

typedef char rge_command_order_size_check[(sizeof(RGE_Command_Order) == 0x14) ? 1 : -1];
typedef char rge_command_stop_size_check[(sizeof(RGE_Command_Stop) == 0x02) ? 1 : -1];
typedef char rge_command_pause_size_check[(sizeof(RGE_Command_Pause) == 0x02) ? 1 : -1];
typedef char rge_command_group_ai_order_size_check[(sizeof(RGE_Command_Group_AI_Order) == 0x24) ? 1 : -1];
typedef char rge_command_formation_size_check[(sizeof(RGE_Command_Formation) == 0x0C) ? 1 : -1];
typedef char rge_command_group_waypoint_size_check[(sizeof(RGE_Command_Group_Waypoint) == 0x04) ? 1 : -1];

class RGE_Command {
  protected:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* order);

  public:
    virtual ~RGE_Command();
    virtual void do_command(void* order);
    virtual void command_give_attribute(int player_id, int to_player_id, int attr_id, float attr_amount);

    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;

    RGE_Command(RGE_Game_World* gworld, TCommunications_Handler* com_handler);
    void reset_communications(TCommunications_Handler* com_hand_in);
    void do_commands();

  protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_group_waypoint(RGE_Command_Group_Waypoint* order);
    void do_command_add_attribute(RGE_Command_Add_Attribute* order);
    void do_command_formation(RGE_Command_Formation* fCommand);
    void do_command_ai_order(RGE_Command_AI_Order* aiOrder);
    void do_command_group_ai_order(RGE_Command_Group_AI_Order* aiOrder);
    void do_command_create(RGE_Command_Create* order);
    void do_command_create_group(RGE_Command_Create_Group* gCommand);
    void do_command_pause(RGE_Command_Pause* order);
    void do_command_add_waypoint(RGE_Command_Add_Waypoint* wOrder);
    void do_command_work(RGE_Command_Order* order);
    void do_command_move(RGE_Command_Order* order);
    void do_command_order(RGE_Command_Order* order);
    void do_command_stop(RGE_Command_Stop* order);
    void do_command_resign(RGE_Command_Resign* order);
    void do_command_destroy_group(RGE_Command_Destroy_Group* gCommand);
    void do_command_remove_from_group(RGE_Command_Remove_From_Group* gCommand);
    void do_command_add_to_group(RGE_Command_Add_To_Group* gCommand);
    unsigned char duplicate_check_command_order(RGE_Command_Order* order);
    unsigned char duplicate_check_command_stop(RGE_Command_Stop* order);
    unsigned char close_check_for_duplicate_orders(unsigned char* order);
    unsigned char check_for_duplicate_orders(unsigned char* order, long order_size);
    void submit(void* order, long order_size);

  public:
    void command_order(
        RGE_Static_Object** unit, short unit_count, RGE_Static_Object* target, float location_x, float location_y
    );
    void command_stop(RGE_Static_Object** unit, short unit_count);
    void command_stop(int playerID, int* unitID, int numUnits);
    void command_pause(int playerID, int* unitID, int numUnits);
    void command_work(
        RGE_Static_Object** unit, short unit_count, RGE_Static_Object* target, float location_x, float location_y
    );
    void command_work(
        int playerID, int* unitID, int numUnits, int targetID, int targetPlayerID, float xLoc, float yLoc
    );
    void command_move(
        RGE_Static_Object** unit, short unit_count, RGE_Static_Object* target, float location_x, float location_y
    );
    void command_move(
        int playerID, int* unitID, int numUnits, int targetID, int targetPlayerID, float xLoc, float yLoc
    );
    void command_create(short obj_catagory, short player_id, float location_x, float location_y, float location_z);
    void command_add_attribute(int player_id, int attr_id, float attr_amount);
    void command_formation(RGE_Static_Object** unit, int unitCount, int formationID);
    void command_create_group(int playerID, int groupCommander, int* units, int unitCount, float range);
    void command_add_to_group(int playerID, int groupCommander, int newUnit, float range);
    void command_add_to_group(int, int, int, int);
    void command_remove_from_group(int playerID, int commander, int unit);
    void command_destroy_group(int playerID, int groupCommander);
    void command_ai_order(
        int playerID, int issuer, int recipient, int orderType, int target, int targetOwner, float targetX,
        float targetY, float targetZ, float range, unsigned char immediate, unsigned char inFront,
        unsigned char priority
    );
    void command_group_ai_order(
        int playerID, int issuer, RGE_Static_Object** recipient, short recipient_count, int orderType, int target,
        int targetOwner, float targetX, float targetY, float targetZ, float range, unsigned char immediate,
        unsigned char inFront, unsigned char priority
    );
    void command_resign(int player_id, int comm_player_id, int dropped);
    void command_add_waypoint(int playerID, int recipient, unsigned char x, unsigned char y, unsigned char z);
    void command_add_waypoint(int playerID, int recipient, XYZBYTEPoint* waypoint, int numWaypoints);
    void command_group_waypoint(
        RGE_Static_Object** unit, short unit_count, unsigned char location_x, unsigned char location_y
    );
};

typedef char rge_command_size_check[(sizeof(RGE_Command) == 0x18) ? 1 : -1];

#endif
