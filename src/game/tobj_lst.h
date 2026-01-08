#pragma once
#include "../common.h"

class TRIBE_Object_List       {
public:
    char _pad_0x4[0x8];


    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual void load(uchar param_1, int param_2, RGE_Game_World* param_3); // Ghidra: load

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void set_game_status();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void do_resign();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void changeToHumanPlayer();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void changeToComputerPlayer();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void aiStatus();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void isEnemy();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void isAlly();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void isNeutral();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void isAllNeutral();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void setDiplomaticStance();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void loadAIInformation();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void sendUnitAIOrder();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void processAIOrder();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void kickAI();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void strategicNumber();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void sendGameOrder();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void sendAddWaypointCommand();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void processAddWaypointCommand();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void sendPlayCommand();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void sendPlayCommand();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void sendAICommand();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void objectCostByType();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void trackUnitGather();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void make_scenario_obj();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void scenario_save();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void scenario_load();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void scenario_postsave();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void scenario_postload();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void add_attribute_num();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void update_dopplegangers();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void save2();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void save_info();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void random_start();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void make_new_object();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void analyize_selected_objects();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void get_mouse_pointer_action_vars();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void command_make_move();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void command_make_work();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void command_make_do();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void command_stop();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void command_place_object();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void command_add_attribute();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void command_give_attribute();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void command_formation();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void command_stand_ground();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void command_create_group();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void command_add_to_group();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void command_remove_from_group();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void command_destroy_group();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void command_resign();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void command_add_waypoint();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void addObject();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void removeObject();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void logMessage();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void logStatus();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void load_victory();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void new_victory();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void command_give_attribute();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void cancelBuild();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void registerBuild();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void trainUnit();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void cancelTrain();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void registerTrain();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void research();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void cancelResearch();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void registerResearch();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void taskTrader();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void taskResourceGatherer();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void notifyAI();

};

static_assert(sizeof(TRIBE_Object_List) == 0xC, "TRIBE_Object_List Size Mismatch");

