#ifndef AOE1_TCOMMAND_H
#define AOE1_TCOMMAND_H

#include "Command.h"

#define TRIBE_COMMAND_ID_MAKE            0x64
#define TRIBE_COMMAND_ID_RESEARCH        0x65
#define TRIBE_COMMAND_ID_BUILD           0x66
#define TRIBE_COMMAND_ID_GAME            0x67
#define TRIBE_COMMAND_ID_EXPLORE         0x68
#define TRIBE_COMMAND_ID_BUILD_WALL      0x69
#define TRIBE_COMMAND_ID_CANCEL_BUILD    0x6A
#define TRIBE_COMMAND_ID_ATTACK_GROUND   0x6B
#define TRIBE_COMMAND_ID_GIVE_ATTRIBUTE  0x6C
#define TRIBE_COMMAND_ID_TRADE_ATTRIBUTE 0x6D
#define TRIBE_COMMAND_ID_REPAIR          0x6E
#define TRIBE_COMMAND_ID_UNLOAD          0x6F
#define TRIBE_COMMAND_ID_QUEUE           0x77

// Game subcommands carried by TRIBE_COMMAND_ID_GAME.
#define TRIBE_GAME_COMMAND_ID_RELATION       0
#define TRIBE_GAME_COMMAND_ID_GAME_SPEED     1
#define TRIBE_GAME_COMMAND_ID_INVENTORY      2
#define TRIBE_GAME_COMMAND_ID_UPGRADE_TOWN   3
#define TRIBE_GAME_COMMAND_ID_QUICK_BUILD    4
#define TRIBE_GAME_COMMAND_ID_ALLIED_VICTORY 5
#define TRIBE_GAME_COMMAND_ID_CHEAT          6
#define TRIBE_GAME_COMMAND_ID_SHARED_LOS     7
#define TRIBE_GAME_COMMAND_ID_SAVE_GAME      8

class RGE_Static_Object;
class TCommunications_Handler;
class TRIBE_Master_Building_Object;
class TRIBE_Player;
class TRIBE_World;

struct TRIBE_Command_Header {
    unsigned char command;
};

typedef char tribe_command_header_size_check[(sizeof(TRIBE_Command_Header) == 0x01) ? 1 : -1];

struct TRIBE_Command_Make {
    unsigned char command;
    int unit_id;
    unsigned char unit_player_id;
    short obj_id;
    int unique_id;
};

typedef char tribe_command_make_size_check[(sizeof(TRIBE_Command_Make) == 0x10) ? 1 : -1];

struct TRIBE_Command_Research {
    unsigned char command;
    int unit_id;
    unsigned char unit_player_id;
    short tech_id;
    int unique_id;
};

typedef char tribe_command_research_size_check[(sizeof(TRIBE_Command_Research) == 0x10) ? 1 : -1];

struct TRIBE_Command_Build {
    unsigned char command;
    unsigned char unit_num;
    unsigned char unit_player_id;
    float location_x;
    float location_y;
    short obj_id;
    int unique_id;
};

typedef char tribe_command_build_size_check[(sizeof(TRIBE_Command_Build) == 0x14) ? 1 : -1];

struct TRIBE_Command_Build_Wall {
    unsigned char command;
    unsigned char unit_num;
    unsigned char unit_player_id;
    unsigned char x1;
    unsigned char y1;
    unsigned char x2;
    unsigned char y2;
    short obj_id;
    int unique_id;
};

typedef char tribe_command_build_wall_size_check[(sizeof(TRIBE_Command_Build_Wall) == 0x10) ? 1 : -1];

struct TRIBE_Command_Explore {
    unsigned char command;
    unsigned char numUnits;
    unsigned char unit_player_id;
    float targetXPosition;
    float targetYPosition;
};

typedef char tribe_command_explore_size_check[(sizeof(TRIBE_Command_Explore) == 0x0C) ? 1 : -1];

struct TRIBE_Command_Game {
    unsigned char command;
    unsigned char game_command;
    short var1;
    short var2;
    float var3;
    short var4;
};

typedef char tribe_command_game_size_check[(sizeof(TRIBE_Command_Game) == 0x10) ? 1 : -1];

struct TRIBE_Command_Cancel_Build {
    unsigned char command;
    int unit_id;
};

typedef char tribe_command_cancel_build_size_check[(sizeof(TRIBE_Command_Cancel_Build) == 0x08) ? 1 : -1];

struct TRIBE_Command_Attack_Ground {
    unsigned char command;
    unsigned char unit_num;
    float location_x;
    float location_y;
};

typedef char tribe_command_attack_ground_size_check[(sizeof(TRIBE_Command_Attack_Ground) == 0x0C) ? 1 : -1];

struct TRIBE_Command_Give_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char to_player_id;
    unsigned char attr_id;
    float attr_amount;
    float attr_cost;
};

typedef char tribe_command_give_attribute_size_check[(sizeof(TRIBE_Command_Give_Attribute) == 0x0C) ? 1 : -1];

struct TRIBE_Command_Trade_Attribute {
    unsigned char command;
    unsigned char unit_num;
    long attribute;
};

typedef char tribe_command_trade_attribute_size_check[(sizeof(TRIBE_Command_Trade_Attribute) == 0x08) ? 1 : -1];

struct TRIBE_Command_Repair {
    unsigned char command;
    unsigned char unit_num;
    RGE_Obj_Info target;
};

typedef char tribe_command_repair_size_check[(sizeof(TRIBE_Command_Repair) == 0x08) ? 1 : -1];

struct TRIBE_Command_Unload {
    unsigned char command;
    unsigned char unit_num;
    float location_x;
    float location_y;
};

typedef char tribe_command_unload_size_check[(sizeof(TRIBE_Command_Unload) == 0x0C) ? 1 : -1];

struct TRIBE_Command_Queue {
    unsigned char command;
    long bldg_id;
    short train_id;
    short train_count;
};

typedef char tribe_command_queue_size_check[(sizeof(TRIBE_Command_Queue) == 0x0C) ? 1 : -1];

class TRIBE_Command : public RGE_Command {
  public:
    TRIBE_Command(TRIBE_World* world, TCommunications_Handler* com_hand);

  private:
    virtual void do_command(void* order);
    virtual void do_command_give_attribute(TRIBE_Command_Give_Attribute* order);
    void do_command_tribe_create(RGE_Command_Create* order);
    void do_command_make(TRIBE_Command_Make* order);
    void do_command_research(TRIBE_Command_Research* order);
    void do_command_build(TRIBE_Command_Build* order);
    void do_command_build_wall(TRIBE_Command_Build_Wall* order);
    void place_line_of_walls(
        TRIBE_Player* player, TRIBE_Master_Building_Object* master_obj, int unique_id, int x1, int y1, int x2, int y2,
        RGE_Static_Object** first_wall
    );
    void do_command_explore(TRIBE_Command_Explore* order);
    void do_command_game(TRIBE_Command_Game* order);
    void do_command_cancel_build(TRIBE_Command_Cancel_Build* order);
    void do_command_attack_ground(TRIBE_Command_Attack_Ground* order);
    void do_command_trade_attribute(TRIBE_Command_Trade_Attribute* order);
    void do_command_repair(TRIBE_Command_Repair* order);
    void do_command_unload(TRIBE_Command_Unload* order);
    void do_command_queue(TRIBE_Command_Queue* order);

  public:
    virtual void command_give_attribute(
        int player_id, int to_player_id, int attr_id, float attr_amount, float attr_cost
    );
    void command_make(RGE_Static_Object* unit, short obj_id);
    void command_make(int playerID, int buildingID, int objID, int uniqueID);
    void command_research(RGE_Static_Object* unit, short tech_id);
    void command_research(int playerID, int buildingID, int techID, int uniqueID);
    void command_build(RGE_Static_Object** unit, short list_num, short obj_id, float location_x, float location_y);
    void command_build(int playerID, int* unitID, int numUnits, int objectID, float xLoc, float yLoc, int uniqueID);
    void command_build_wall(RGE_Static_Object** unit, short list_num, short obj_id, long x1, long y1, long x2, long y2);
    void command_explore(int playerID, int* unitID, int numUnits, float x, float y);
    void command_allied_victory(short player, unsigned char flag);
    void command_relation(short player, short target_player, short relation);
    void command_game_speed(float gamespeed);
    void command_save_game();
    void command_inventory(short player, short inventory, float amount);
    void command_upgrade_town(short player);
    void command_quick_build(short quick_build);
    void command_shared_los(short player);
    void command_cancel_build(RGE_Static_Object* unit);
    void command_attack_ground(RGE_Static_Object** unit, short list_num, float x, float y);
    void command_cheat(short player, short cheat_code);
    void command_trade_attribute(RGE_Static_Object** unit, short list_num, long attribute);
    void command_trade_attribute(int unitID, int playerID, long attribute);
    void command_repair(RGE_Static_Object** unit, short unit_count, RGE_Static_Object* target);
    void command_unload(RGE_Static_Object** unit, short list_num, float x, float y);
    void command_queue(RGE_Static_Object* bldg_obj, short train_id, short train_count);
};

typedef char tribe_command_size_check[(sizeof(TRIBE_Command) == 0x18) ? 1 : -1];

#endif // AOE1_TCOMMAND_H
