#ifndef COMMAND_OWNER_CONTEXT_H
#define COMMAND_OWNER_CONTEXT_H

// Shared owner surface for the ordered Command.cpp methods.
struct RGE_Obj_Info;
struct RGE_Command_Order;
struct RGE_Command_Formation;
struct RGE_Command_Add_To_Group;
struct RGE_Command_Remove_From_Group;
struct RGE_Command_Stop;
class RGE_Static_Object;

struct RGE_Command_Add_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char attr_id;
    unsigned char gap_03;
    int attr_amount;
};

class RGE_Player {
public:
    virtual void set_game_status(); virtual void do_resign();
    virtual void changeToHumanPlayer(); virtual void changeToComputerPlayer();
    virtual void aiStatus(); virtual void isEnemy(); virtual void isAlly();
    virtual void isNeutral(); virtual void isAllNeutral();
    virtual void setDiplomaticStance(); virtual void loadAIInformation();
    virtual void sendUnitAIOrder(); virtual void processAIOrder();
    virtual void kickAI(); virtual void strategicNumber();
    virtual void sendGameOrder(); virtual void sendAddWaypointCommand();
    virtual void processAddWaypointCommand(); virtual void sendPlayCommand();
    virtual void sendPlayCommand2(); virtual void sendAICommand();
    virtual void objectCostByType(); virtual void trackUnitGather();
    virtual void save(); virtual void scenario_save(); virtual void scenario_load();
    virtual void scenario_postsave(); virtual void scenario_postload();
    virtual void load(); virtual void initialize();
    virtual void add_attribute_num(unsigned short attr_id, int attr_amount, int zero);

    char gap_04[0x46];
    unsigned short id;
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;

    RGE_Static_Object* object(int id);
};

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;
    RGE_Command_Stop* last_order;

protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_add_attribute(RGE_Command_Add_Attribute* command);
    void do_command_formation(RGE_Command_Formation* command);
    void do_command_add_to_group(RGE_Command_Add_To_Group* command);
    void do_command_remove_from_group(RGE_Command_Remove_From_Group* command);
    unsigned char duplicate_check_command_order(RGE_Command_Order* command);
    unsigned char duplicate_check_command_stop(RGE_Command_Stop* command);
    unsigned char close_check_for_duplicate_orders(unsigned char* command);
};

#endif

#ifndef COMMAND_CONTEXT_CORE_ONLY
#ifndef COMMAND_CONTEXT_H
#define COMMAND_CONTEXT_H

struct RGE_Obj_Info {
    int id;
};

struct RGE_Command_Formation {
    unsigned char command;
    unsigned char gap_01[3];
    int unitNum;
    int formationID;
    RGE_Obj_Info units[1];
};

struct RGE_Command_Add_To_Group {
    unsigned char command;
    unsigned char player_id;
    unsigned char gap_02[2];
    int groupCommander;
    int groupRange;
    int newUnit;
};

struct RGE_Command_Remove_From_Group {
    unsigned char command;
    unsigned char player_id;
    unsigned char gap_02[2];
    int groupCommander;
    int unit;
};

struct RGE_Command_Order {
    long unknown_00;
    long target_id;
    unsigned char unit_num;
    char gap_09[3];
    float pos_x;
    float pos_y;
    long units[1];
};

struct RGE_Command_Stop {
    char pad_00[1];
    unsigned char unit_num;
    int items[1];
};

#include "command_static_object_context.h"

#endif
#endif
