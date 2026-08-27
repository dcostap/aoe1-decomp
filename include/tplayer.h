#ifndef AOE1_TPLAYER_H
#define AOE1_TPLAYER_H

#include "player.h"

class TRIBE_World;
class TRIBE_Player_Tech;
class TribeMainDecisionAIModule;
class TRIBE_History_Info;
class ResourceItem;
class Trade_Avail;

class Item_Avail {
public:
    char* name;                  // +0x00
    short id;                    // +0x04
    short pict;                  // +0x06
    short inventory_item_1;      // +0x08
    float inventory_cost_1;      // +0x0C
    short inventory_item_2;      // +0x10
    float inventory_cost_2;      // +0x14
    short inventory_item_3;      // +0x18
    float inventory_cost_3;      // +0x1C
    long help_string_id;         // +0x20
    long help_page_id;           // +0x24
};

typedef char item_avail_size_check[
    (sizeof(Item_Avail) == 0x28) ? 1 : -1];

class TRIBE_Player : public RGE_Player {
public:
    // Direct overrides are listed in inherited and new vtable-slot order.
    // Slots not listed here remain inherited from RGE_Player.
    virtual ~TRIBE_Player();                                      // vt[0]
    virtual void changeToHumanPlayer();                           // vt[3]
    virtual void changeToComputerPlayer();                        // vt[4]
    virtual char* aiStatus(int);                                  // vt[5]
    virtual void setDiplomaticStance(int, int);                   // vt[10]
    virtual void loadAIInformation(char*, char*, char*, int, int); // vt[11]
    virtual void kickAI(int);                                     // vt[14]
    virtual int strategicNumber(int);                             // vt[15]
    virtual int sendAICommand(int, int, int, int, int);           // vt[21]
    virtual int objectCostByType(int);                            // vt[22]
    virtual void trackUnitGather(int, int, int);                  // vt[23]
    virtual RGE_Static_Object* make_scenario_obj(
        float, float, float, short, unsigned char, float);        // vt[24]
    virtual void scenario_save(int);                              // vt[25]
    virtual void scenario_load(int, long*, float);                // vt[26]
    virtual void scenario_postload(int, long*, float);             // vt[28]
    virtual void load(int);                                       // vt[29]
    virtual void add_attribute_num(short, float, unsigned char);  // vt[30]
    virtual void update();                                        // vt[31]
    virtual void update_dopplegangers();                          // vt[32]
    virtual void save(int);                                       // vt[33]
    virtual void random_start();                                  // vt[36]
    virtual RGE_Static_Object* make_new_object(
        long, float, float, float, int);                          // vt[37]
    virtual void analyize_selected_objects();                     // vt[38]
    virtual int get_mouse_pointer_action_vars(int, int&, int&);   // vt[39]
    virtual void __cdecl logMessage(char*, ...);                  // vt[57]
    virtual void notify(int, int, int, long, long, long);         // vt[58]
    virtual void logStatus(FILE*, int);                           // vt[59]
    virtual void load_victory(int, long*, unsigned char);         // vt[60]
    virtual void new_victory();                                   // vt[61]
    virtual unsigned char command_give_attribute(
        int, int, float, float);                                  // vt[62]
    virtual void buildObject(int, int, float, float, int);        // vt[63]
    virtual void cancelBuild(
        int, int, int, float, float, int, int);                   // vt[64]
    virtual void registerBuild(RGE_Static_Object*, int);          // vt[65]
    virtual void trainUnit(int, int, int);                        // vt[66]
    virtual void cancelTrain(int, int, int, int);                 // vt[67]
    virtual void registerTrain(int, int, int, int);               // vt[68]
    virtual void research(int, int, int);                         // vt[69]
    virtual void cancelResearch(int, int, int, int);              // vt[70]
    virtual void registerResearch(int, int, int);                 // vt[71]
    virtual void taskTrader(int, int, int, float, float);         // vt[72]
    virtual void taskResourceGatherer(
        int, int, int, float, float);                             // vt[73]
    virtual void notifyAI(int, int, int, long, long, long);        // vt[74]

    // Constructors and nonvirtual owners follow the tplayer.cpp source-owner
    // sequence. Their declarations do not add vtable entries.
    TRIBE_Player(int, TRIBE_World*, unsigned char);
    TRIBE_Player(TRIBE_World*, RGE_Master_Player*, unsigned char, char*,
                 unsigned char, unsigned char, unsigned char, char*, char*,
                 char*);

    void load_master_object(int, short, unsigned char, RGE_Sprite**,
                            RGE_Sound**);
    void tech_cost(short, short&, short&, short&, short&, short&, short&,
                   short&);
    void obj_cost(short, char**, short&, short&, short&, short&, short&,
                  short&, float);
    RGE_Static_Object* find_obj(short, RGE_Static_Object*);
    void interface_tech_avail(Item_Avail**, short*, short);
    void interface_item_avail(Item_Avail**, short*, short);
    void interface_trade_avail(Trade_Avail**, short*);
    unsigned char command_make_building(short, float, float);
    unsigned char command_make_wall(short, long, long, long, long);
    unsigned char command_building_make_tech(short);
    unsigned char command_building_cancel();
    unsigned char command_delete_object(RGE_Static_Object*);
    unsigned char command_trade_attribute(long);
    unsigned char command_trade_attribute(int, long);
    unsigned char command_attack_ground(float, float);
    unsigned char command_building_make_obj(short);
    unsigned char command_make_repair(RGE_Static_Object*);
    unsigned char command_make_unload(float, float);
    unsigned char check_obj_cost(short, short*, float, int);
    unsigned char pay_obj_cost(short, float, int);
    void reimburse_obj_cost(short);
    unsigned char check_tech_cost(short, short*);
    unsigned char pay_tech_cost(short);
    void tech_abling(long, unsigned char);
    void rev_tech(long);
    void add_population_entry();
    void objectCost(int, int, ResourceItem*, int);
    void researchCost(int, int, ResourceItem*, int);
    int objectAvailable(int);
    int researchAvailable(int);
    int researchEverAvailable(int);
    unsigned char researchState(int);
    int intelligentCivSelection(int, int, int);
    void intelligentBuildListAndRulesSelection(
        char*, char*, int, int, int);
    void setupEgyptian(int*, int, int, int);
    void setupGreek(int*, int, int, int);
    void setupBabylonian(int*, int, int, int);
    void setupAssyrian(int*, int, int, int);
    void setupMinoan(int*, int, int, int);
    void setupHittite(int*, int, int, int);
    void setupPhoenician(int*, int, int, int);
    void setupSumerian(int*, int, int, int);
    void setupPersian(int*, int, int, int);
    void setupShang(int*, int, int, int);
    void setupYamato(int*, int, int, int);
    void setupChoson(int*, int, int, int);
    void setupRoman(int*, int, int, int);
    void setupCarthaginian(int*, int, int, int);
    void setupPalmyran(int*, int, int, int);
    void setupMacedonian(int*, int, int, int);
    void get_achievement(unsigned char, char*);

    TRIBE_Player_Tech* tech_tree;                 // +0x220
    long fog_update;                              // +0x224
    long update_count;                            // +0x228
    long update_history_count;                    // +0x22C
    long updateCountNeedHelp;                     // +0x230
    float update_time;                             // +0x234
    TribeMainDecisionAIModule* playerAI;          // +0x238
    char aiStatusInformationValue[256];            // +0x23C
    char aiStatusInformationValue2[256];           // +0x33C
    char aiStatusInformationValue3[256];           // +0x43C
    char aiStatusInformationValue4[256];           // +0x53C
    char aiStatusInformationValue5[256];           // +0x63C
    char aiStatusInformationValue6[256];           // +0x73C
    TRIBE_History_Info* history;                  // +0x83C
    float ruin_held_time;                          // +0x840
    float artifact_held_time;                     // +0x844
};

typedef char tribe_player_size_check[
    (sizeof(TRIBE_Player) == 0x848) ? 1 : -1];

class TRIBE_Gaia : public TRIBE_Player {
public:
    TRIBE_Gaia(int, TRIBE_World*, unsigned char);
    TRIBE_Gaia(TRIBE_World*, RGE_Master_Player*, unsigned char, char*,
               unsigned char);

    virtual ~TRIBE_Gaia();
    virtual void update();
    virtual void save(int);
    virtual void random_start();

    void load_master_object(int, short, unsigned char, RGE_Sprite**,
                            RGE_Sound**);

    float update_time;                         // +0x848
    long update_nature;                        // +0x84C
    long last_count;                           // +0x850
    long animal_max;                           // +0x854
};

typedef char tribe_gaia_size_check[
    (sizeof(TRIBE_Gaia) == 0x858) ? 1 : -1];

#endif
