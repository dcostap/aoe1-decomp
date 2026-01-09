#pragma once
#include "common.h"

class TRIBE_Gaia : public TRIBE_Player {
public:
    float update_time;                       // 0x848
    long update_nature;                      // 0x84C
    long last_count;                         // 0x850
    long animal_max;                         // 0x854

    virtual void update();                                  // vt0[31]+0x7C=0x519CA0
    virtual void save(int param_1);                         // vt0[33]+0x84=0x519C40
    virtual void random_start();                            // vt0[36]+0x90=0x519D40
    TRIBE_Gaia(int param_1, TRIBE_World* param_2, uchar param_3);
    ~TRIBE_Gaia();
    TRIBE_Gaia(TRIBE_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5);
    void load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5);
};

static_assert(sizeof(TRIBE_Gaia) == 0x858, "TRIBE_Gaia Size Mismatch");

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

    virtual void changeToHumanPlayer();                     // vt0[3]+0xC=0x514700 | vt0[79]+0x13C=0x514700
    virtual void changeToComputerPlayer();                  // vt0[4]+0x10=0x514710 | vt0[80]+0x140=0x514710
    virtual char* aiStatus(int param_1);                    // vt0[5]+0x14=0x514720 | vt0[81]+0x144=0x514720
    virtual void setDiplomaticStance(int param_1, int param_2); // vt0[10]+0x28=0x5153B0 | vt0[86]+0x158=0x5153B0
    virtual void loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5); // vt0[11]+0x2C=0x5153D0 | vt0[87]+0x15C=0x5153D0
    virtual void kickAI(int param_1);                       // vt0[14]+0x38=0x514F90 | vt0[90]+0x168=0x514F90
    virtual int strategicNumber(int param_1);               // vt0[15]+0x3C=0x514FB0 | vt0[91]+0x16C=0x514FB0
    virtual int sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5); // vt0[21]+0x54=0x515040 | vt0[97]+0x184=0x515040
    virtual int objectCostByType(int param_1);              // vt0[22]+0x58=0x514590 | vt0[98]+0x188=0x514590
    virtual void trackUnitGather(int param_1, int param_2, int param_3); // vt0[23]+0x5C=0x5192F0 | vt0[99]+0x18C=0x5192F0
    virtual RGE_Static_Object* make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6); // vt0[24]+0x60=0x5121A0 | vt0[100]+0x190=0x5121A0
    virtual void scenario_save(int param_1);                // vt0[25]+0x64=0x512630 | vt0[101]+0x194=0x512630
    virtual void scenario_load(int param_1, long* param_2, float param_3); // vt0[26]+0x68=0x512690 | vt0[102]+0x198=0x512690
    virtual void scenario_postload(int param_1, long* param_2, float param_3); // vt0[28]+0x70=0x519D50 | vt0[104]+0x1A0=0x519D50
    virtual void load(int param_1);                         // vt0[29]+0x74=0x5128A0 | vt0[105]+0x1A4=0x5128A0
    virtual void add_attribute_num(short param_1, float param_2, uchar param_3); // vt0[30]+0x78=0x519570 | vt0[106]+0x1A8=0x519570
    virtual void update();                                  // vt0[31]+0x7C=0x5123B0
    virtual void update_dopplegangers();                    // vt0[32]+0x80=0x512620 | vt0[108]+0x1B0=0x512620
    virtual void save(int param_1);                         // vt0[33]+0x84=0x512250
    virtual void random_start();                            // vt0[36]+0x90=0x514010
    virtual RGE_Static_Object* make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5); // vt0[37]+0x94=0x512F60 | vt0[113]+0x1C4=0x512F60
    virtual void analyize_selected_objects();               // vt0[38]+0x98=0x5195D0 | vt0[114]+0x1C8=0x5195D0
    virtual int get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3); // vt0[39]+0x9C=0x5196E0 | vt0[115]+0x1CC=0x5196E0
    virtual RGE_Object_Node* addObject(RGE_Static_Object* param_1, int param_2, int param_3); // vt0[55]+0xDC=0x515070 | vt0[131]+0x20C=0x515070
    virtual void removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4); // vt0[56]+0xE0=0x5150E0 | vt0[132]+0x210=0x5150E0
    virtual void logMessage(char* param_1);                 // vt0[57]+0xE4=0x514FE0 | vt0[133]+0x214=0x514FE0
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt0[58]+0xE8=0x5159D0 | vt0[134]+0x218=0x5159D0
    virtual void logStatus(_iobuf* param_1, int param_2);   // vt0[59]+0xEC=0x518F00 | vt0[135]+0x21C=0x518F00
    virtual void load_victory(int param_1, long* param_2, uchar param_3); // vt0[60]+0xF0=0x519490 | vt0[136]+0x220=0x519490
    virtual void new_victory();                             // vt0[61]+0xF4=0x519500 | vt0[137]+0x224=0x519500
    virtual uchar command_give_attribute(int param_1, int param_2, float param_3, float param_4); // vt0[62]+0xF8=0x5138D0 | vt0[138]+0x228=0x5138D0
    virtual void buildObject(int param_1, int param_2, float param_3, float param_4, int param_5); // vt0[63]+0xFC=0x515130 | vt0[139]+0x22C=0x515130
    virtual void cancelBuild(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7); // vt0[64]+0x100=0x515180 | vt0[140]+0x230=0x515180
    virtual void registerBuild(RGE_Static_Object* param_1, int param_2); // vt0[65]+0x104=0x5151C0 | vt0[141]+0x234=0x5151C0
    virtual void trainUnit(int param_1, int param_2, int param_3); // vt0[66]+0x108=0x5151F0 | vt0[142]+0x238=0x5151F0
    virtual void cancelTrain(int param_1, int param_2, int param_3, int param_4); // vt0[67]+0x10C=0x515220 | vt0[143]+0x23C=0x515220
    virtual void registerTrain(int param_1, int param_2, int param_3, int param_4); // vt0[68]+0x110=0x515250 | vt0[144]+0x240=0x515250
    virtual void research(int param_1, int param_2, int param_3); // vt0[69]+0x114=0x515280 | vt0[145]+0x244=0x515280
    virtual void cancelResearch(int param_1, int param_2, int param_3, int param_4); // vt0[70]+0x118=0x5152B0 | vt0[146]+0x248=0x5152B0
    virtual void registerResearch(int param_1, int param_2, int param_3); // vt0[71]+0x11C=0x5152E0 | vt0[147]+0x24C=0x5152E0
    virtual void taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5); // vt0[72]+0x120=0x515310 | vt0[148]+0x250=0x515310
    virtual void taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5); // vt0[73]+0x124=0x515360 | vt0[149]+0x254=0x515360
    virtual void notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt0[74]+0x128=0x515BB0 | vt0[150]+0x258=0x515BB0
    TRIBE_Player(int param_1, TRIBE_World* param_2, uchar param_3);
    TRIBE_Player(TRIBE_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5, uchar param_6, uchar param_7, char* param_8, char* param_9, char* param_10);
    ~TRIBE_Player();
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

