#pragma once
#include "../common.h"

class TRIBE_Command : public RGE_Command       {
public:
    char _pad_0x4[0x14];

    TRIBE_Command(TRIBE_World* param_1, TCommunications_Handler* param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 WARNING: Function body missing in analysis
    // virtual void do_command_give_attribute();

    // [Slot 01] Offset 0x04 (Override)
    virtual  ~TRIBE_Command() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 02] Offset 0x08 (Override)
    virtual void do_command(void* param_1); // Ghidra: do_command

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void command_give_attribute();

    // [Slot 04] Offset 0x10 (Override)
    virtual void do_command_give_attribute(TRIBE_Command_Give_Attribute* param_1); // Ghidra: do_command_give_attribute

    // [Slot 05] Offset 0x14 (Override)
    virtual void command_give_attribute(int param_1, int param_2, int param_3, float param_4, float param_5); // Ghidra: command_give_attribute

    // --- Non-Virtual Members ---
    void do_command_tribe_create(RGE_Command_Create* param_1);
    void do_command_make(TRIBE_Command_Make* param_1);
    void do_command_research(TRIBE_Command_Research* param_1);
    void do_command_build(TRIBE_Command_Build* param_1);
    void do_command_build_wall(TRIBE_Command_Build_Wall* param_1);
    void place_line_of_walls(TRIBE_Player* param_1, TRIBE_Master_Building_Object* param_2, int param_3, int param_4, int param_5, int param_6, int param_7, RGE_Static_Object** param_8);
    void do_command_explore(TRIBE_Command_Explore* param_1);
    void do_command_game(TRIBE_Command_Game* param_1);
    void do_command_cancel_build(TRIBE_Command_Cancel_Build* param_1);
    void do_command_attack_ground(TRIBE_Command_Attack_Ground* param_1);
    void do_command_trade_attribute(TRIBE_Command_Trade_Attribute* param_1);
    void do_command_repair(TRIBE_Command_Repair* param_1);
    void do_command_unload(TRIBE_Command_Unload* param_1);
    void do_command_queue(TRIBE_Command_Queue* param_1);
    void command_make(RGE_Static_Object* param_1, short param_2);
    void command_make(int param_1, int param_2, int param_3, int param_4);
    void command_research(RGE_Static_Object* param_1, short param_2);
    void command_research(int param_1, int param_2, int param_3, int param_4);
    void command_build(RGE_Static_Object** param_1, short param_2, short param_3, float param_4, float param_5);
    void command_build(int param_1, int* param_2, int param_3, int param_4, float param_5, float param_6, int param_7);
    void command_build_wall(RGE_Static_Object** param_1, short param_2, short param_3, long param_4, long param_5, long param_6, long param_7);
    void command_explore(int param_1, int* param_2, int param_3, float param_4, float param_5);
    void command_allied_victory(short param_1, uchar param_2);
    void command_relation(short param_1, short param_2, short param_3);
    void command_game_speed(float param_1);
    void command_save_game();
    void command_inventory(short param_1, short param_2, float param_3);
    void command_upgrade_town(short param_1);
    void command_quick_build(short param_1);
    void command_shared_los(short param_1);
    void command_cancel_build(RGE_Static_Object* param_1);
    void command_attack_ground(RGE_Static_Object** param_1, short param_2, float param_3, float param_4);
    void command_cheat(short param_1, short param_2);
    void command_trade_attribute(RGE_Static_Object** param_1, short param_2, long param_3);
    void command_trade_attribute(int param_1, int param_2, long param_3);
    void command_repair(RGE_Static_Object** param_1, short param_2, RGE_Static_Object* param_3);
    void command_unload(RGE_Static_Object** param_1, short param_2, float param_3, float param_4);
    void command_queue(RGE_Static_Object* param_1, short param_2, short param_3);
};

static_assert(sizeof(TRIBE_Command) == 0x18, "TRIBE_Command Size Mismatch");

