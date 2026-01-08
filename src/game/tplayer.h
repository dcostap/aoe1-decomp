#pragma once
#include "../common.h"
#include "TRIBE_Player_Tech.h"
#include "player.h"
#include "sprite.h"
#include "taimdmd.h"
#include "t_histry.h"
#include "tworld.h"
#include "mst_play.h"
#include "stat_obj.h"
#include "Sound.h"
#include "airesitm.h"

class TRIBE_Player : public RGE_Player       {
public:
    char _pad_0x4[0x21C];
    TRIBE_Player_Tech* tech_tree;            // 0x220
    long fog_update;                         // 0x224
    long update_count;                       // 0x228
    long update_history_count;               // 0x22C
    long updateCountNeedHelp;                // 0x230
    float update_time;                       // 0x234
    TribeMainDecisionAIModule* playerAI;     // 0x238
    char aiStatusInformationValue[256];      // 0x23C
    char aiStatusInformationValue2[256];     // 0x33C
    char aiStatusInformationValue3[256];     // 0x43C
    char aiStatusInformationValue4[256];     // 0x53C
    char aiStatusInformationValue5[256];     // 0x63C
    char aiStatusInformationValue6[256];     // 0x73C
    TRIBE_History_Info* history;             // 0x83C
    float ruin_held_time;                    // 0x840
    float artifact_held_time;                // 0x844

    TRIBE_Player(int param_1, TRIBE_World* param_2, uchar param_3);
    TRIBE_Player(TRIBE_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5, uchar param_6, uchar param_7, char* param_8, char* param_9, char* param_10);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Player() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void set_game_status();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void do_resign();

    // [Slot 03] Offset 0x0C (Override)
    virtual void changeToHumanPlayer(); // Ghidra: changeToHumanPlayer

    // [Slot 04] Offset 0x10 (Override)
    virtual void changeToComputerPlayer(); // Ghidra: changeToComputerPlayer

    // [Slot 05] Offset 0x14 (Override)
    virtual char* aiStatus(int param_1); // Ghidra: aiStatus

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void isEnemy();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void isAlly();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void isNeutral();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void isAllNeutral();

    // [Slot 10] Offset 0x28 (Override)
    virtual void setDiplomaticStance(int param_1, int param_2); // Ghidra: setDiplomaticStance

    // [Slot 11] Offset 0x2C (Override)
    virtual void loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5); // Ghidra: loadAIInformation

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void sendUnitAIOrder();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void processAIOrder();

    // [Slot 14] Offset 0x38 (Override)
    virtual void kickAI(int param_1); // Ghidra: kickAI

    // [Slot 15] Offset 0x3C (Override)
    virtual int strategicNumber(int param_1); // Ghidra: strategicNumber

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void sendGameOrder();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void sendAddWaypointCommand();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void processAddWaypointCommand();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void sendPlayCommand();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void sendPlayCommand();

    // [Slot 21] Offset 0x54 (Override)
    virtual int sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5); // Ghidra: sendAICommand

    // [Slot 22] Offset 0x58 (Override)
    virtual int objectCostByType(int param_1); // Ghidra: objectCostByType

    // [Slot 23] Offset 0x5C (Override)
    virtual void trackUnitGather(int param_1, int param_2, int param_3); // Ghidra: trackUnitGather

    // [Slot 24] Offset 0x60 (Override)
    virtual RGE_Static_Object* make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6); // Ghidra: make_scenario_obj

    // [Slot 25] Offset 0x64 (Override)
    virtual void scenario_save(int param_1); // Ghidra: scenario_save

    // [Slot 26] Offset 0x68 (Override)
    virtual void scenario_load(int param_1, long* param_2, float param_3); // Ghidra: scenario_load

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void scenario_postsave();

    // [Slot 28] Offset 0x70 (Override)
    virtual void scenario_postload(int param_1, long* param_2, float param_3); // Ghidra: scenario_postload

    // [Slot 29] Offset 0x74 (Override)
    virtual void load(int param_1); // Ghidra: load

    // [Slot 30] Offset 0x78 (Override)
    virtual void add_attribute_num(short param_1, float param_2, uchar param_3); // Ghidra: add_attribute_num

    // [Slot 31] Offset 0x7C (Override)
    virtual void update(); // Ghidra: update

    // [Slot 32] Offset 0x80 (Override)
    virtual void update_dopplegangers(); // Ghidra: update_dopplegangers

    // [Slot 33] Offset 0x84 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void save2();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void save_info();

    // [Slot 36] Offset 0x90 (Override)
    virtual void random_start(); // Ghidra: random_start

    // [Slot 37] Offset 0x94 (Override)
    virtual RGE_Static_Object* make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5); // Ghidra: make_new_object

    // [Slot 38] Offset 0x98 (Override)
    virtual void analyize_selected_objects(); // Ghidra: analyize_selected_objects

    // [Slot 39] Offset 0x9C (Override)
    virtual int get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3); // Ghidra: get_mouse_pointer_action_vars

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void command_make_move();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void command_make_work();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void command_make_do();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void command_stop();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void command_place_object();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void command_add_attribute();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void command_give_attribute();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void command_formation();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void command_stand_ground();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void command_create_group();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void command_add_to_group();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void command_remove_from_group();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void command_destroy_group();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void command_resign();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void command_add_waypoint();

    // [Slot 55] Offset 0xDC (Override)
    virtual RGE_Object_Node* addObject(RGE_Static_Object* param_1, int param_2, int param_3); // Ghidra: addObject

    // [Slot 56] Offset 0xE0 (Override)
    virtual void removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4); // Ghidra: removeObject

    // [Slot 57] Offset 0xE4 (Override)
    virtual void logMessage(char* param_1); // Ghidra: logMessage

    // [Slot 58] Offset 0xE8 (Override)
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // Ghidra: notify

    // [Slot 59] Offset 0xEC (Override)
    virtual void logStatus(_iobuf* param_1, int param_2); // Ghidra: logStatus

    // [Slot 60] Offset 0xF0 (Override)
    virtual void load_victory(int param_1, long* param_2, uchar param_3); // Ghidra: load_victory

    // [Slot 61] Offset 0xF4 (Override)
    virtual void new_victory(); // Ghidra: new_victory

    // [Slot 62] Offset 0xF8 (Override)
    virtual uchar command_give_attribute(int param_1, int param_2, float param_3, float param_4); // Ghidra: command_give_attribute

    // [Slot 63] Offset 0xFC (Override)
    virtual void buildObject(int param_1, int param_2, float param_3, float param_4, int param_5); // Ghidra: buildObject

    // [Slot 64] Offset 0x100 (Override)
    virtual void cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7); // Ghidra: cancelBuild

    // [Slot 65] Offset 0x104 (Override)
    virtual void registerBuild(RGE_Static_Object* param_1, int param_2); // Ghidra: registerBuild

    // [Slot 66] Offset 0x108 (Override)
    virtual void trainUnit(int param_1, int param_2, int param_3); // Ghidra: trainUnit

    // [Slot 67] Offset 0x10C (Override)
    virtual void cancelTrain(int param_1, int param_2, int param_3, int param_4); // Ghidra: cancelTrain

    // [Slot 68] Offset 0x110 (Override)
    virtual void registerTrain(int param_1, int param_2, int param_3, int param_4); // Ghidra: registerTrain

    // [Slot 69] Offset 0x114 (Override)
    virtual void research(int param_1, int param_2, int param_3); // Ghidra: research

    // [Slot 70] Offset 0x118 (Override)
    virtual void cancelResearch(int param_1, int param_2, int param_3, int param_4); // Ghidra: cancelResearch

    // [Slot 71] Offset 0x11C (Override)
    virtual void registerResearch(int param_1, int param_2, int param_3); // Ghidra: registerResearch

    // [Slot 72] Offset 0x120 (Override)
    virtual void taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5); // Ghidra: taskTrader

    // [Slot 73] Offset 0x124 (Override)
    virtual void taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5); // Ghidra: taskResourceGatherer

    // [Slot 74] Offset 0x128 (Override)
    virtual void notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // Ghidra: notifyAI

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void set_game_status();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void do_resign();

    // [Slot 79] Offset 0x13C (Override)
    virtual void changeToHumanPlayer(); // Ghidra: changeToHumanPlayer

    // [Slot 80] Offset 0x140 (Override)
    virtual void changeToComputerPlayer(); // Ghidra: changeToComputerPlayer

    // [Slot 81] Offset 0x144 (Override)
    virtual char* aiStatus(int param_1); // Ghidra: aiStatus

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void isEnemy();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void isAlly();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void isNeutral();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void isAllNeutral();

    // [Slot 86] Offset 0x158 (Override)
    virtual void setDiplomaticStance(int param_1, int param_2); // Ghidra: setDiplomaticStance

    // [Slot 87] Offset 0x15C (Override)
    virtual void loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5); // Ghidra: loadAIInformation

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void sendUnitAIOrder();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void processAIOrder();

    // [Slot 90] Offset 0x168 (Override)
    virtual void kickAI(int param_1); // Ghidra: kickAI

    // [Slot 91] Offset 0x16C (Override)
    virtual int strategicNumber(int param_1); // Ghidra: strategicNumber

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void sendGameOrder();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void sendAddWaypointCommand();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void processAddWaypointCommand();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void sendPlayCommand();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void sendPlayCommand();

    // [Slot 97] Offset 0x184 (Override)
    virtual int sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5); // Ghidra: sendAICommand

    // [Slot 98] Offset 0x188 (Override)
    virtual int objectCostByType(int param_1); // Ghidra: objectCostByType

    // [Slot 99] Offset 0x18C (Override)
    virtual void trackUnitGather(int param_1, int param_2, int param_3); // Ghidra: trackUnitGather

    // [Slot 100] Offset 0x190 (Override)
    virtual RGE_Static_Object* make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6); // Ghidra: make_scenario_obj

    // [Slot 101] Offset 0x194 (Override)
    virtual void scenario_save(int param_1); // Ghidra: scenario_save

    // [Slot 102] Offset 0x198 (Override)
    virtual void scenario_load(int param_1, long* param_2, float param_3); // Ghidra: scenario_load

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void scenario_postsave();

    // [Slot 104] Offset 0x1A0 (Override)
    virtual void scenario_postload(int param_1, long* param_2, float param_3); // Ghidra: scenario_postload

    // [Slot 105] Offset 0x1A4 (Override)
    virtual void load(int param_1); // Ghidra: load

    // [Slot 106] Offset 0x1A8 (Override)
    virtual void add_attribute_num(short param_1, float param_2, uchar param_3); // Ghidra: add_attribute_num

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 108] Offset 0x1B0 (Override)
    virtual void update_dopplegangers(); // Ghidra: update_dopplegangers

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void save2();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void save_info();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void random_start();

    // [Slot 113] Offset 0x1C4 (Override)
    virtual RGE_Static_Object* make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5); // Ghidra: make_new_object

    // [Slot 114] Offset 0x1C8 (Override)
    virtual void analyize_selected_objects(); // Ghidra: analyize_selected_objects

    // [Slot 115] Offset 0x1CC (Override)
    virtual int get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3); // Ghidra: get_mouse_pointer_action_vars

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void command_make_move();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void command_make_work();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void command_make_do();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void command_stop();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void command_place_object();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void command_add_attribute();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void command_give_attribute();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void command_formation();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void command_stand_ground();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void command_create_group();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void command_add_to_group();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void command_remove_from_group();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void command_destroy_group();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void command_resign();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void command_add_waypoint();

    // [Slot 131] Offset 0x20C (Override)
    virtual RGE_Object_Node* addObject(RGE_Static_Object* param_1, int param_2, int param_3); // Ghidra: addObject

    // [Slot 132] Offset 0x210 (Override)
    virtual void removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4); // Ghidra: removeObject

    // [Slot 133] Offset 0x214 (Override)
    virtual void logMessage(char* param_1); // Ghidra: logMessage

    // [Slot 134] Offset 0x218 (Override)
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // Ghidra: notify

    // [Slot 135] Offset 0x21C (Override)
    virtual void logStatus(_iobuf* param_1, int param_2); // Ghidra: logStatus

    // [Slot 136] Offset 0x220 (Override)
    virtual void load_victory(int param_1, long* param_2, uchar param_3); // Ghidra: load_victory

    // [Slot 137] Offset 0x224 (Override)
    virtual void new_victory(); // Ghidra: new_victory

    // [Slot 138] Offset 0x228 (Override)
    virtual uchar command_give_attribute(int param_1, int param_2, float param_3, float param_4); // Ghidra: command_give_attribute

    // [Slot 139] Offset 0x22C (Override)
    virtual void buildObject(int param_1, int param_2, float param_3, float param_4, int param_5); // Ghidra: buildObject

    // [Slot 140] Offset 0x230 (Override)
    virtual void cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7); // Ghidra: cancelBuild

    // [Slot 141] Offset 0x234 (Override)
    virtual void registerBuild(RGE_Static_Object* param_1, int param_2); // Ghidra: registerBuild

    // [Slot 142] Offset 0x238 (Override)
    virtual void trainUnit(int param_1, int param_2, int param_3); // Ghidra: trainUnit

    // [Slot 143] Offset 0x23C (Override)
    virtual void cancelTrain(int param_1, int param_2, int param_3, int param_4); // Ghidra: cancelTrain

    // [Slot 144] Offset 0x240 (Override)
    virtual void registerTrain(int param_1, int param_2, int param_3, int param_4); // Ghidra: registerTrain

    // [Slot 145] Offset 0x244 (Override)
    virtual void research(int param_1, int param_2, int param_3); // Ghidra: research

    // [Slot 146] Offset 0x248 (Override)
    virtual void cancelResearch(int param_1, int param_2, int param_3, int param_4); // Ghidra: cancelResearch

    // [Slot 147] Offset 0x24C (Override)
    virtual void registerResearch(int param_1, int param_2, int param_3); // Ghidra: registerResearch

    // [Slot 148] Offset 0x250 (Override)
    virtual void taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5); // Ghidra: taskTrader

    // [Slot 149] Offset 0x254 (Override)
    virtual void taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5); // Ghidra: taskResourceGatherer

    // [Slot 150] Offset 0x258 (Override)
    virtual void notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // Ghidra: notifyAI

    // --- Non-Virtual Members ---
    void load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5);
    void tech_cost(short param_1, short* param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7);
    void obj_cost(short param_1, char** param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7, short* param_8, float param_9);
    RGE_Static_Object* find_obj(short param_1, RGE_Static_Object* param_2);
    void interface_tech_avail(Item_Avail** param_1, short* param_2, short param_3);
    void interface_item_avail(Item_Avail** param_1, short* param_2, short param_3);
    void interface_trade_avail(Trade_Avail** param_1, short* param_2);
    uchar command_make_building(short param_1, float param_2, float param_3);
    uchar command_make_wall(short param_1, long param_2, long param_3, long param_4, long param_5);
    uchar command_building_make_tech(short param_1);
    uchar command_building_cancel();
    uchar command_delete_object(RGE_Static_Object* param_1);
    uchar command_trade_attribute(long param_1);
    uchar command_trade_attribute(int param_1, long param_2);
    uchar command_attack_ground(float param_1, float param_2);
    uchar command_building_make_obj(short param_1);
    uchar command_make_repair(RGE_Static_Object* param_1);
    uchar command_make_unload(float param_1, float param_2);
    uchar check_obj_cost(short param_1, short* param_2, float param_3, int param_4);
    uchar pay_obj_cost(short param_1, float param_2, int param_3);
    void reimburse_obj_cost(short param_1);
    uchar check_tech_cost(short param_1, short* param_2);
    uchar pay_tech_cost(short param_1);
    void tech_abling(long param_1, uchar param_2);
    void rev_tech(long param_1);
    void add_population_entry();
    void objectCost(int param_1, int param_2, ResourceItem* param_3, int param_4);
    void researchCost(int param_1, int param_2, ResourceItem* param_3, int param_4);
    int objectAvailable(int param_1);
    int researchAvailable(int param_1);
    int researchEverAvailable(int param_1);
    uchar researchState(int param_1);
    int intelligentCivSelection(int param_1, int param_2, int param_3);
    void intelligentBuildListAndRulesSelection(char* param_1, char* param_2, int param_3, int param_4, int param_5);
    void setupEgyptian(int* param_1, int param_2, int param_3, int param_4);
    void setupGreek(int* param_1, int param_2, int param_3, int param_4);
    void setupBabylonian(int* param_1, int param_2, int param_3, int param_4);
    void setupAssyrian(int* param_1, int param_2, int param_3, int param_4);
    void setupMinoan(int* param_1, int param_2, int param_3, int param_4);
    void setupHittite(int* param_1, int param_2, int param_3, int param_4);
    void setupPhoenician(int* param_1, int param_2, int param_3, int param_4);
    void setupSumerian(int* param_1, int param_2, int param_3, int param_4);
    void setupPersian(int* param_1, int param_2, int param_3, int param_4);
    void setupShang(int* param_1, int param_2, int param_3, int param_4);
    void setupYamato(int* param_1, int param_2, int param_3, int param_4);
    void setupChoson(int* param_1, int param_2, int param_3, int param_4);
    void setupRoman(int* param_1, int param_2, int param_3, int param_4);
    void setupCarthaginian(int* param_1, int param_2, int param_3, int param_4);
    void setupPalmyran(int* param_1, int param_2, int param_3, int param_4);
    void setupMacedonian(int* param_1, int param_2, int param_3, int param_4);
    void get_achievement(uchar param_1, char* param_2);
};

static_assert(sizeof(TRIBE_Player) == 0x848, "TRIBE_Player Size Mismatch");
static_assert(offsetof(TRIBE_Player, artifact_held_time) == 0x844, "TRIBE_Player Offset Mismatch");

class TRIBE_Gaia : public TRIBE_Player       {
public:
    char _pad_0x4[0x844];
    float update_time;                       // 0x848
    long update_nature;                      // 0x84C
    long last_count;                         // 0x850
    long animal_max;                         // 0x854

    TRIBE_Gaia(int param_1, TRIBE_World* param_2, uchar param_3);
    TRIBE_Gaia(TRIBE_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Gaia() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void set_game_status();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void do_resign();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void changeToHumanPlayer();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void changeToComputerPlayer();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void aiStatus();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void isEnemy();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void isAlly();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void isNeutral();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void isAllNeutral();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void setDiplomaticStance();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void loadAIInformation();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void sendUnitAIOrder();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void processAIOrder();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void kickAI();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void strategicNumber();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void sendGameOrder();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void sendAddWaypointCommand();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void processAddWaypointCommand();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void sendPlayCommand();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void sendPlayCommand();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void sendAICommand();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void objectCostByType();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void trackUnitGather();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void make_scenario_obj();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void scenario_save();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void scenario_load();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void scenario_postsave();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void scenario_postload();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void add_attribute_num();

    // [Slot 31] Offset 0x7C (Override)
    virtual void update(); // Ghidra: update

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void update_dopplegangers();

    // [Slot 33] Offset 0x84 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void save2();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void save_info();

    // [Slot 36] Offset 0x90 (Override)
    virtual void random_start(); // Ghidra: random_start

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void make_new_object();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void analyize_selected_objects();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void get_mouse_pointer_action_vars();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void command_make_move();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void command_make_work();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void command_make_do();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void command_stop();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void command_place_object();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void command_add_attribute();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void command_give_attribute();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void command_formation();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void command_stand_ground();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void command_create_group();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void command_add_to_group();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void command_remove_from_group();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void command_destroy_group();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void command_resign();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void command_add_waypoint();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void addObject();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void removeObject();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void logMessage();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void logStatus();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void load_victory();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void new_victory();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void command_give_attribute();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void cancelBuild();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void registerBuild();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void trainUnit();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void cancelTrain();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void registerTrain();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void research();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void cancelResearch();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void registerResearch();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void taskTrader();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void taskResourceGatherer();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void notifyAI();

    // --- Non-Virtual Members ---
    void load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5);
};

static_assert(sizeof(TRIBE_Gaia) == 0x858, "TRIBE_Gaia Size Mismatch");
static_assert(offsetof(TRIBE_Gaia, animal_max) == 0x854, "TRIBE_Gaia Offset Mismatch");

