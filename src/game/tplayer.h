#pragma once
#include "../common.h"

class TRIBE_Player : public RGE_Player {
public:
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
    virtual ~TRIBE_Player();
    virtual RGE_Static_Object* make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6);
    virtual void save(int param_1);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void scenario_save(int param_1);
    virtual void scenario_load(int param_1, long* param_2, float param_3);
    virtual void load(int param_1);
    virtual void load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5);
    virtual void tech_cost(short param_1, short* param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7);
    virtual void obj_cost(short param_1, char** param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7, short* param_8, float param_9);
    virtual RGE_Static_Object* find_obj(short param_1, RGE_Static_Object* param_2);
    virtual RGE_Static_Object* make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5);
    virtual void interface_tech_avail(Item_Avail** param_1, short* param_2, short param_3);
    virtual void interface_item_avail(Item_Avail** param_1, short* param_2, short param_3);
    virtual void interface_trade_avail(Trade_Avail** param_1, short* param_2);
    virtual uchar command_make_building(short param_1, float param_2, float param_3);
    virtual uchar command_make_wall(short param_1, long param_2, long param_3, long param_4, long param_5);
    virtual uchar command_building_make_tech(short param_1);
    virtual uchar command_building_cancel();
    virtual uchar command_delete_object(RGE_Static_Object* param_1);
    virtual uchar command_trade_attribute(long param_1);
    virtual uchar command_trade_attribute(int param_1, long param_2);
    virtual uchar command_attack_ground(float param_1, float param_2);
    virtual uchar command_give_attribute(int param_1, int param_2, float param_3, float param_4);
    virtual uchar command_building_make_obj(short param_1);
    virtual uchar command_make_repair(RGE_Static_Object* param_1);
    virtual uchar command_make_unload(float param_1, float param_2);
    virtual uchar check_obj_cost(short param_1, short* param_2, float param_3, int param_4);
    virtual uchar pay_obj_cost(short param_1, float param_2, int param_3);
    virtual void reimburse_obj_cost(short param_1);
    virtual uchar check_tech_cost(short param_1, short* param_2);
    virtual uchar pay_tech_cost(short param_1);
    virtual void tech_abling(long param_1, uchar param_2);
    virtual void rev_tech(long param_1);
    virtual void add_population_entry();
    virtual void random_start();
    virtual void objectCost(int param_1, int param_2, ResourceItem* param_3, int param_4);
    virtual int objectCostByType(int param_1);
    virtual void researchCost(int param_1, int param_2, ResourceItem* param_3, int param_4);
    virtual int objectAvailable(int param_1);
    virtual int researchAvailable(int param_1);
    virtual int researchEverAvailable(int param_1);
    virtual uchar researchState(int param_1);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int param_1);
    virtual void kickAI(int param_1);
    virtual int strategicNumber(int param_1);
    virtual void logMessage(char* param_1);
    virtual int sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5);
    virtual RGE_Object_Node* addObject(RGE_Static_Object* param_1, int param_2, int param_3);
    virtual void removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4);
    virtual void buildObject(int param_1, int param_2, float param_3, float param_4, int param_5);
    virtual void cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7);
    virtual void registerBuild(RGE_Static_Object* param_1, int param_2);
    virtual void trainUnit(int param_1, int param_2, int param_3);
    virtual void cancelTrain(int param_1, int param_2, int param_3, int param_4);
    virtual void registerTrain(int param_1, int param_2, int param_3, int param_4);
    virtual void research(int param_1, int param_2, int param_3);
    virtual void cancelResearch(int param_1, int param_2, int param_3, int param_4);
    virtual void registerResearch(int param_1, int param_2, int param_3);
    virtual void taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5);
    virtual void taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5);
    virtual void setDiplomaticStance(int param_1, int param_2);
    virtual void loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5);
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual void notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual int intelligentCivSelection(int param_1, int param_2, int param_3);
    virtual void intelligentBuildListAndRulesSelection(char* param_1, char* param_2, int param_3, int param_4, int param_5);
    virtual void setupEgyptian(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupGreek(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupBabylonian(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupAssyrian(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupMinoan(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupHittite(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupPhoenician(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupSumerian(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupPersian(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupShang(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupYamato(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupChoson(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupRoman(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupCarthaginian(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupPalmyran(int* param_1, int param_2, int param_3, int param_4);
    virtual void setupMacedonian(int* param_1, int param_2, int param_3, int param_4);
    virtual void logStatus(_iobuf* param_1, int param_2);
    virtual void trackUnitGather(int param_1, int param_2, int param_3);
    virtual void get_achievement(uchar param_1, char* param_2);
    virtual void load_victory(int param_1, long* param_2, uchar param_3);
    virtual void new_victory();
    virtual void add_attribute_num(short param_1, float param_2, uchar param_3);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3);
    virtual void scenario_postload(int param_1, long* param_2, float param_3);
};

static_assert(sizeof(TRIBE_Player) == 0x848, "TRIBE_Player Size Mismatch");
static_assert(offsetof(TRIBE_Player, artifact_held_time) == 0x844, "TRIBE_Player Offset Mismatch");

class TRIBE_Gaia : public TRIBE_Player {
public:
    float update_time;                       // 0x848
    long update_nature;                      // 0x84C
    long last_count;                         // 0x850
    long animal_max;                         // 0x854

    TRIBE_Gaia(int param_1, TRIBE_World* param_2, uchar param_3);
    virtual ~TRIBE_Gaia();
    TRIBE_Gaia(TRIBE_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5);
    virtual void save(int param_1);
    virtual void update();
    virtual void load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5);
    virtual void random_start();
};

static_assert(sizeof(TRIBE_Gaia) == 0x858, "TRIBE_Gaia Size Mismatch");
static_assert(offsetof(TRIBE_Gaia, animal_max) == 0x854, "TRIBE_Gaia Offset Mismatch");

