#ifndef AOE1_TCOMMAND_H
#define AOE1_TCOMMAND_H

#include "Command.h"

class RGE_Static_Object;
class TCommunications_Handler;
class TRIBE_Master_Building_Object;
class TRIBE_Player;
class TRIBE_World;

struct TRIBE_Command_Header {
    unsigned char command;
};

typedef char tribe_command_header_size_check[
    (sizeof(TRIBE_Command_Header) == 0x01) ? 1 : -1];

struct TRIBE_Command_Make {
    unsigned char command;
    int unit_id;
    unsigned char player_index;
    short train_id;
    int unique_id;
};

typedef char tribe_command_make_size_check[
    (sizeof(TRIBE_Command_Make) == 0x10) ? 1 : -1];

struct TRIBE_Command_Research {
    unsigned char command;
    int unit_id;
    unsigned char player_index;
    short tech_id;
    int unique_id;
};

typedef char tribe_command_research_size_check[
    (sizeof(TRIBE_Command_Research) == 0x10) ? 1 : -1];

struct TRIBE_Command_Build {
    unsigned char command;
    unsigned char count;
    unsigned char player_id;
    float x;
    float y;
    short obj_id;
    int unique_id;
    RGE_Obj_Info unit_ids[1];
};

typedef char tribe_command_build_size_check[
    (sizeof(TRIBE_Command_Build) == 0x18) ? 1 : -1];

struct TRIBE_Command_Build_Wall {
    unsigned char command;
    unsigned char count;
    unsigned char player_id;
    unsigned char x1;
    unsigned char y1;
    unsigned char x2;
    unsigned char y2;
    short obj_id;
    int unique_id;
    RGE_Obj_Info unit_ids[1];
};

typedef char tribe_command_build_wall_size_check[
    (sizeof(TRIBE_Command_Build_Wall) == 0x14) ? 1 : -1];

struct TRIBE_Command_Explore {
    unsigned char command;
    unsigned char unit_num;
    unsigned char unit_player_id;
    float target_x;
    float target_y;
    RGE_Obj_Info unit_ids[1];
};

typedef char tribe_command_explore_size_check[
    (sizeof(TRIBE_Command_Explore) == 0x10) ? 1 : -1];

struct TRIBE_Command_Game {
    unsigned char command;
    unsigned char game_command;
    short var1;
    short var2;
    float var3;
    short var4;
};

typedef char tribe_command_game_size_check[
    (sizeof(TRIBE_Command_Game) == 0x10) ? 1 : -1];

struct TRIBE_Command_Cancel_Build {
    unsigned char command;
    int unit_id;
};

typedef char tribe_command_cancel_build_size_check[
    (sizeof(TRIBE_Command_Cancel_Build) == 0x08) ? 1 : -1];

struct TRIBE_Command_Attack_Ground {
    unsigned char command;
    unsigned char unit_num;
    float location_x;
    float location_y;
    RGE_Obj_Info unit_ids[1];
};

typedef char tribe_command_attack_ground_size_check[
    (sizeof(TRIBE_Command_Attack_Ground) == 0x10) ? 1 : -1];

struct TRIBE_Command_Give_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char to_player_id;
    unsigned char attr_id;
    float attr_amount;
    float attr_cost;
};

typedef char tribe_command_give_attribute_size_check[
    (sizeof(TRIBE_Command_Give_Attribute) == 0x0C) ? 1 : -1];

struct TRIBE_Command_Trade_Attribute {
    unsigned char command;
    unsigned char unit_num;
    long attribute;
    RGE_Obj_Info unit_ids[1];
};

typedef char tribe_command_trade_attribute_size_check[
    (sizeof(TRIBE_Command_Trade_Attribute) == 0x0C) ? 1 : -1];

struct TRIBE_Command_Repair {
    unsigned char command;
    unsigned char unit_num;
    RGE_Obj_Info target;
    RGE_Obj_Info unit_ids[1];
};

typedef char tribe_command_repair_size_check[
    (sizeof(TRIBE_Command_Repair) == 0x0C) ? 1 : -1];

struct TRIBE_Command_Unload {
    unsigned char command;
    unsigned char unit_num;
    float location_x;
    float location_y;
    RGE_Obj_Info unit_ids[1];
};

typedef char tribe_command_unload_size_check[
    (sizeof(TRIBE_Command_Unload) == 0x10) ? 1 : -1];

struct TRIBE_Command_Queue {
    unsigned char command;
    int building_id;
    short train_id;
    short train_count;
};

typedef char tribe_command_queue_size_check[
    (sizeof(TRIBE_Command_Queue) == 0x0C) ? 1 : -1];

class TRIBE_Command : public RGE_Command {
public:
    TRIBE_Command(TRIBE_World*, TCommunications_Handler*);
    virtual ~TRIBE_Command();

private:
    virtual void do_command(void*);
    virtual void do_command_give_attribute(TRIBE_Command_Give_Attribute*);
    void do_command_tribe_create(RGE_Command_Create*);
    void do_command_make(TRIBE_Command_Make*);
    void do_command_research(TRIBE_Command_Research*);
    void do_command_build(TRIBE_Command_Build*);
    void do_command_build_wall(TRIBE_Command_Build_Wall*);
    void place_line_of_walls(TRIBE_Player*, TRIBE_Master_Building_Object*, int,
                             int, int, int, int, RGE_Static_Object**);
    void do_command_explore(TRIBE_Command_Explore*);
    void do_command_game(TRIBE_Command_Game*);
    void do_command_cancel_build(TRIBE_Command_Cancel_Build*);
    void do_command_attack_ground(TRIBE_Command_Attack_Ground*);
    void do_command_trade_attribute(TRIBE_Command_Trade_Attribute*);
    void do_command_repair(TRIBE_Command_Repair*);
    void do_command_unload(TRIBE_Command_Unload*);
    void do_command_queue(TRIBE_Command_Queue*);

public:
    virtual void command_give_attribute(int, int, int, float, float);
    void command_make(RGE_Static_Object*, short);
    void command_make(int, int, int, int);
    void command_research(RGE_Static_Object*, short);
    void command_research(int, int, int, int);
    void command_build(RGE_Static_Object**, short, short, float, float);
    void command_build(int, int*, int, int, float, float, int);
    void command_build_wall(RGE_Static_Object**, short, short, long, long,
                            long, long);
    void command_explore(int, int*, int, float, float);
    void command_allied_victory(short, unsigned char);
    void command_relation(short, short, short);
    void command_game_speed(float);
    void command_save_game();
    void command_inventory(short, short, float);
    void command_upgrade_town(short);
    void command_quick_build(short);
    void command_shared_los(short);
    void command_cancel_build(RGE_Static_Object*);
    void command_attack_ground(RGE_Static_Object**, short, float, float);
    void command_cheat(short, short);
    void command_trade_attribute(RGE_Static_Object**, short, long);
    void command_trade_attribute(int, int, long);
    void command_repair(RGE_Static_Object**, short, RGE_Static_Object*);
    void command_unload(RGE_Static_Object**, short, float, float);
    void command_queue(RGE_Static_Object*, short, short);
};

typedef char tribe_command_size_check[
    (sizeof(TRIBE_Command) == 0x18) ? 1 : -1];

#endif  // AOE1_TCOMMAND_H
