#ifndef AOE1_TPLAYER_H
#define AOE1_TPLAYER_H

#include "player.h"

class TRIBE_World;
class TRIBE_Player_Tech;
class TribeMainDecisionAIModule;
class TRIBE_History_Info;
class ResourceItem;

extern unsigned long tribe_group_properties[0x28];
extern int tribe_group_properties_num;
extern unsigned int DAT_0086bc88;

struct Item_Avail {
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

struct Trade_Avail {
public:
    RGE_Player* player;             // +0x00
    RGE_Static_Object* dock;        // +0x04
    float inventory;                // +0x08
};

typedef char trade_avail_size_check[
    (sizeof(Trade_Avail) == 0x0C) ? 1 : -1];

class TRIBE_Player : public RGE_Player {
public:
    // Direct overrides are listed in inherited and new vtable-slot order.
    // Slots not listed here remain inherited from RGE_Player.
    virtual ~TRIBE_Player();                                      // vt[0]
    virtual void changeToHumanPlayer();                           // vt[3]
    virtual void changeToComputerPlayer();                        // vt[4]
    virtual char* aiStatus(int sNum);                             // vt[5]
    virtual void setDiplomaticStance(int playerNum, int rType);   // vt[10]
    virtual void loadAIInformation(char* bL, char* cP, char* rS,
                                   int mood, int mapType);         // vt[11]
    virtual void kickAI(int m);                                   // vt[14]
    virtual int strategicNumber(int sN);                          // vt[15]
    virtual int sendAICommand(int caller, int mType, int p1,
                              int p2, int p3);                    // vt[21]
    virtual int objectCostByType(int id);                         // vt[22]
    virtual void trackUnitGather(int unitID, int attributeID,
                                 int amount);                     // vt[23]
    virtual RGE_Static_Object* make_scenario_obj(
        float world_x, float world_y, float world_z, short master_id,
        unsigned char state, float new_angle);                    // vt[24]
    virtual void scenario_save(int outfile);                      // vt[25]
    virtual void scenario_load(int infile, long* player_id_hash,
                               float version);                    // vt[26]
    virtual void scenario_postload(int infile, long* player_id_hash,
                                   float version);                // vt[28]
    virtual void load(int infile);                                // vt[29]
    virtual void add_attribute_num(short attribute, float amount,
                                   unsigned char earned);         // vt[30]
    virtual void update();                                        // vt[31]
    virtual void update_dopplegangers();                          // vt[32]
    virtual void save(int outfile);                               // vt[33]
    virtual void random_start();                                  // vt[36]
    virtual RGE_Static_Object* make_new_object(
        long obj_id, float x, float y, float z,
        int build_all_the_way);                                  // vt[37]
    virtual void analyize_selected_objects();                     // vt[38]
    virtual int get_mouse_pointer_action_vars(int Obj_id, int& newFacet,
                                              int& text_id);      // vt[39]
    virtual RGE_Object_Node* addObject(RGE_Static_Object* obj,
                                       int sleepFlag,
                                       int dopple_flag);          // vt[55]
    virtual void removeObject(RGE_Static_Object* obj, int sleepFlag,
                              int dopple_flag,
                              RGE_Object_Node* node);             // vt[56]
    virtual void __cdecl logMessage(char* textIn, ...);           // vt[57]
    virtual void notify(int caller, int recipient, int mType,
                        long p1, long p2, long p3);               // vt[58]
    virtual void logStatus(FILE* out, int firstTime);             // vt[59]
    virtual void load_victory(int infile, long* player_id_hash,
                              unsigned char version_control);     // vt[60]
    virtual void new_victory();                                   // vt[61]
    virtual unsigned char command_give_attribute(
        int to_player_id, int attr_id, float attr_amount,
        float attr_cost);                                        // vt[62]
    virtual void buildObject(int bi, int oi, float x, float y,
                             int ui);                             // vt[63]
    virtual void cancelBuild(
        int reason, int blockerID, int blockerType, float x, float y,
        int uniqueID, int builderID);                             // vt[64]
    virtual void registerBuild(RGE_Static_Object* obj,
                               int uniqueID);                     // vt[65]
    virtual void trainUnit(int uType, int bID, int uniqueID);     // vt[66]
    virtual void cancelTrain(int reason, int uType, int location,
                             int uniqueID);                       // vt[67]
    virtual void registerTrain(int uType, int location, int uniqueID,
                               int gameID);                       // vt[68]
    virtual void research(int rType, int bID, int uniqueID);      // vt[69]
    virtual void cancelResearch(int reason, int rType, int location,
                                int uniqueID);                    // vt[70]
    virtual void registerResearch(int rType, int location,
                                  int uniqueID);                  // vt[71]
    virtual void taskTrader(int tID, int oID, int ownerID,
                            float x, float y);                    // vt[72]
    virtual void taskResourceGatherer(
        int gID, int oID, int ownerID, float x, float y);         // vt[73]
    virtual void notifyAI(int callerID, int recipientID, int mType,
                          long p1, long p2, long p3);             // vt[74]

    // Constructors and nonvirtual owners follow the tplayer.cpp source-owner
    // sequence. Their declarations do not add vtable entries.
    TRIBE_Player(int infile, TRIBE_World* gworld, unsigned char this_id);
    TRIBE_Player(TRIBE_World* gworld, RGE_Master_Player* prototype,
                 unsigned char this_id, char* new_name,
                 unsigned char m_player_id, unsigned char computerPlayer,
                 unsigned char flag, char* buildListName,
                 char* cityPlanName, char* ruleSetName);

    void load_master_object(int infile, short index, unsigned char type,
                            RGE_Sprite** sprites, RGE_Sound** sounds);
    void tech_cost(short tech_id, short& inv_1, short& inv_amt_1,
                   short& inv_2, short& inv_amt_2, short& inv_3,
                   short& inv_amt_3);
    void obj_cost(short obj_id, char** name, short& inv_1,
                  short& inv_amt_1, short& inv_2, short& inv_amt_2,
                  short& inv_3, short& inv_amt_3, float modifier);
    RGE_Static_Object* find_obj(short obj_id, RGE_Static_Object* after_obj);
    void interface_tech_avail(Item_Avail** list, short* list_num,
                              short obj_cat);
    void interface_item_avail(Item_Avail** list, short* list_num,
                              short obj_cat);
    void interface_trade_avail(Trade_Avail** list, short* list_num);
    unsigned char command_make_building(short obj_id, float x, float y);
    unsigned char command_make_wall(short obj_id, long x1, long y1,
                                    long x2, long y2);
    unsigned char command_building_make_tech(short tech_id);
    unsigned char command_building_cancel();
    unsigned char command_delete_object(RGE_Static_Object* obj);
    unsigned char command_trade_attribute(long attribute);
    unsigned char command_trade_attribute(int unitID, long attribute);
    unsigned char command_attack_ground(float x, float y);
    unsigned char command_building_make_obj(short obj_id);
    unsigned char command_make_repair(RGE_Static_Object* obj);
    unsigned char command_make_unload(float x, float y);
    unsigned char check_obj_cost(short obj_id, short* attribute_needed,
                                 float modifier, int ignore_pop);
    unsigned char pay_obj_cost(short obj_id, float modifier, int ignore_pop);
    void reimburse_obj_cost(short obj_id);
    unsigned char check_tech_cost(short tech_id, short* attribute_needed);
    unsigned char pay_tech_cost(short tech_id);
    void tech_abling(long tech_id, unsigned char able_flag);
    void rev_tech(long age);
    void add_population_entry();
    void objectCost(int id, int unused1, ResourceItem* ri, int unused2);
    void researchCost(int id, int unused1, ResourceItem* ri, int unused2);
    int objectAvailable(int id);
    int researchAvailable(int id);
    int researchEverAvailable(int id);
    unsigned char researchState(int id);
    int intelligentCivSelection(int mapType, int gameType, int mapSize);
    void intelligentBuildListAndRulesSelection(
        char* b, char* r, int mapType, int gameType, int mapSize);
    void setupEgyptian(int* b, int mapType, int gameType, int mapSize);
    void setupGreek(int* b, int mapType, int gameType, int mapSize);
    void setupBabylonian(int* b, int mapType, int gameType, int mapSize);
    void setupAssyrian(int* b, int mapType, int gameType, int mapSize);
    void setupMinoan(int* b, int mapType, int gameType, int mapSize);
    void setupHittite(int* b, int mapType, int gameType, int mapSize);
    void setupPhoenician(int* b, int mapType, int gameType, int mapSize);
    void setupSumerian(int* b, int mapType, int gameType, int mapSize);
    void setupPersian(int* b, int mapType, int gameType, int mapSize);
    void setupShang(int* b, int mapType, int gameType, int mapSize);
    void setupYamato(int* b, int mapType, int gameType, int mapSize);
    void setupChoson(int* b, int mapType, int gameType, int mapSize);
    void setupRoman(int* b, int mapType, int gameType, int mapSize);
    void setupCarthaginian(int* b, int mapType, int gameType, int mapSize);
    void setupPalmyran(int* b, int mapType, int gameType, int mapSize);
    void setupMacedonian(int* b, int mapType, int gameType, int mapSize);
    void get_achievement(unsigned char achievement, char* info);

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
    TRIBE_Gaia(int infile, TRIBE_World* gworld, unsigned char this_id);
    TRIBE_Gaia(TRIBE_World* gworld, RGE_Master_Player* prototype,
               unsigned char this_id, char* new_name,
               unsigned char m_player_id);

    virtual void update();
    virtual void save(int outfile);
    virtual void random_start();

    void load_master_object(int infile, short index, unsigned char type,
                            RGE_Sprite** sprites, RGE_Sound** sounds);

    float update_time;                         // +0x848
    long update_nature;                        // +0x84C
    long last_count;                           // +0x850
    long animal_max;                           // +0x854
};

typedef char tribe_gaia_size_check[
    (sizeof(TRIBE_Gaia) == 0x858) ? 1 : -1];

#endif
