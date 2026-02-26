#pragma once
#include "common.h"
#include "RGE_Command.h"

class TRIBE_Command_Give_Attribute;
class TRIBE_Command_Trade_Attribute;
struct TRIBE_Command_Make;
struct TRIBE_Command_Research;
struct TRIBE_Command_Build;
struct TRIBE_Command_Game;
struct TRIBE_Command_Explore;
struct TRIBE_Command_Build_Wall;
struct TRIBE_Command_Cancel_Build;
struct TRIBE_Command_Attack_Ground;
struct TRIBE_Command_Repair;
struct TRIBE_Command_Queue;
struct TRIBE_Command_Unload;
class RGE_Static_Object;
class TRIBE_Player;
class TRIBE_Master_Building_Object;

class TRIBE_Command : public RGE_Command {
public:
    TRIBE_Command(RGE_Game_World* world, TCommunications_Handler* comm);

    // Virtuals (best-effort)
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* param_1); // vt[0] (0x0)
    virtual ~TRIBE_Command(); // vt[1] (0x4)
    virtual void do_command(void* param_1); // vt[2] (0x8)
    using RGE_Command::command_give_attribute; // vt[3] stays bound to RGE_Command::command_give_attribute
    virtual void do_command_give_attribute(TRIBE_Command_Give_Attribute* param_1); // vt[4] (0x10)
    virtual void command_give_attribute(int param_1, int param_2, int param_3, float param_4, float param_5); // vt[5] (0x14)
    void do_command_tribe_create(RGE_Command_Create* param_1);
    void do_command_make(TRIBE_Command_Make* param_1);
    void do_command_research(TRIBE_Command_Research* param_1);
    void do_command_build(TRIBE_Command_Build* param_1);
    void do_command_game(TRIBE_Command_Game* param_1);
    void do_command_explore(TRIBE_Command_Explore* param_1);
    void do_command_build_wall(TRIBE_Command_Build_Wall* param_1);
    void place_line_of_walls(TRIBE_Player* param_1, TRIBE_Master_Building_Object* param_2, int param_3, int param_4, int param_5, int param_6, int param_7, RGE_Static_Object** param_8);
    void do_command_cancel_build(TRIBE_Command_Cancel_Build* param_1);
    void do_command_attack_ground(TRIBE_Command_Attack_Ground* param_1);
    void do_command_unload(TRIBE_Command_Unload* param_1);
    void do_command_repair(TRIBE_Command_Repair* param_1);
    void do_command_queue(TRIBE_Command_Queue* param_1);
    void do_command_trade_attribute(TRIBE_Command_Trade_Attribute* param_1);

    void command_make(RGE_Static_Object* param_1, short param_2);
    void command_make(int param_1, int param_2, int param_3, int param_4);
    void command_research(RGE_Static_Object* param_1, short param_2);
    void command_research(int param_1, int param_2, int param_3, int param_4);
    void command_build(RGE_Static_Object** param_1, short param_2, short param_3, float param_4, float param_5);
    void command_build(int param_1, int* param_2, int param_3, int param_4, float param_5, float param_6, int param_7);
    void command_build_wall(RGE_Static_Object** param_1, short param_2, short param_3, long param_4, long param_5, long param_6, long param_7);
    void command_explore(int param_1, int* param_2, int param_3, float param_4, float param_5);
    void command_game_speed(float param_1);
    void command_save_game();
    void command_cancel_build(RGE_Static_Object* param_1);
    void command_attack_ground(RGE_Static_Object** param_1, short param_2, float param_3, float param_4);

    void command_trade_attribute(RGE_Static_Object** param_1, short param_2, long param_3);
    void command_trade_attribute(int param_1, int param_2, long param_3);
    void command_repair(RGE_Static_Object** param_1, short param_2, RGE_Static_Object* param_3);
    void command_unload(RGE_Static_Object** param_1, short param_2, float param_3, float param_4);
    void command_queue(RGE_Static_Object* param_1, short param_2, short param_3);

};
static_assert(sizeof(TRIBE_Command) == 0x18, "Size mismatch");
