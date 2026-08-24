#ifndef AOE1_TPLAYER_CONTEXT_H
#define AOE1_TPLAYER_CONTEXT_H

// Canonical declarations for the tplayer.cpp PDB module.
//
// The source module starts at tplayer.cpp line 232.  The class members below
// use the reviewed offsets used by the grouped AI and civilization owners.
// Keep this header local to tplayer.cpp until the shared game ABI is complete.

typedef unsigned char uchar;

typedef unsigned long ulong;

class RGE_Player;
class RGE_Game_World;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Visible_Map;
class RGE_Master_Player;
class RGE_Object_List;
class RGE_Static_Object_Type;
class TRIBE_Building_Object;
class RGE_Sprite;
class RGE_Sound;
struct ObjNode;
class RGE_Progress_Info { public: char gap_00[0x6C]; float field_6c; float field_70; };
class SomeV { public: virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); };
class SelectedObject { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C(); virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C(); virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C(); virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C(); virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C(); virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C(); virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC(); };
class TRIBE_Command {
public:
    void* command_obj;
    void command_build(RGE_Static_Object**, short, short, float, float);
    void command_build(int, int*, int, int, float, float, int);
    void command_build_wall(RGE_Static_Object**, short, short, long, long, long, long);
    void command_cancel_build(RGE_Static_Object*);
    void command_cancel_build(void*);
    void command_trade_attribute(RGE_Static_Object**, short, long);
    void command_attack_ground(RGE_Static_Object**, short, float, float);
    void command_work(int, int*, int, int, int, float, float);
    void command_relation(short, short, short);
    void command_repair(void*, int, int);
    unsigned char command_give_attribute(int, int, int, float, float);
};
class TRIBE_Command_Unload { public: void command_unload(RGE_Static_Object**, short, float, float); };
class WallHelper { public: virtual void clear_wall_data(); };
class PlayerVtbl7 { public: virtual int func1C(int); };
class RepairVtbl { public: virtual int func2C(); virtual int funcBC(void*, int, int); };
class PlayerCommandHolder { public: TRIBE_Command* command; };
class RGE_World { public: TRIBE_Command* commands; };
struct InnerType2 { char gap_00[4]; unsigned char field_04; };
struct InnerType1 { char gap_00[8]; InnerType2* field_08; };
struct Inner_00513D60 { void target(int, int); void target(int); };
struct Inner_005146E0 { void target(int); };
struct Inner_00514F90 { void target(int); };
struct TechIdSource { char gap_00[0x5C]; float tech_a; float tech_b; float tech_c; };
struct TechPlayerEntry { char gap_00[4]; short state; short gap_06; };
struct TechTree { TechPlayerEntry* tech_player_tree; };
struct QueueHost { void enqueue(InnerType1*, int); };
class CommandBuildingHost {
public:
    unsigned char command_building_make_tech(int);
    unsigned char command_building_make_obj(int);
    char gap_00[0x3C]; char* field_3C; char gap_40[0xF0]; InnerType1* field_130;
};
struct Trade_Avail { RGE_Player* player; RGE_Static_Object* dock; float inventory; };
struct ObjectCost { short type; short amount; unsigned char paid; unsigned char gap_05; };
struct CostInfo { short res_id; short amount; unsigned char flag; char pad; };
struct ObjInfo { char gap_00[4]; unsigned char kind; char gap_05[0x143]; CostInfo cost[3]; };
struct RightClickEntry { int key; int action_1; int var_1; int action_0; int var_0; int action_2; int var_2; int action_3; int var_3; int action_4; int var_4; };
class ObjectType {
public:
    virtual ~ObjectType();
    unsigned char status; char gap_005[0x143]; ObjectCost costs[3];
    unsigned char first_paid;
};
class ResourceItem { public: void incrementValue(int, int); };
struct VirtualTarget { virtual void vf00()=0; virtual void vf04()=0; virtual void vf08()=0; virtual void vf0C()=0; virtual void vf10()=0; virtual void vf14()=0; virtual void vf18()=0; virtual void vfn(int,int)=0; };
class TRIBE_Master_Fish_Object { public: TRIBE_Master_Fish_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class TRIBE_Master_Projectile_Object { public: TRIBE_Master_Projectile_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class TRIBE_Master_Tree_Object { public: TRIBE_Master_Tree_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class TCommunications_Handler { public: int IsHost(); int checkSomething(); int ComputerPlayerGameStart(); };
class TMousePointer { public: void Poll(); };
class TChat { public: void setInChatGroup(int, int); };
class AI_Manager { public: void method16(void*); };
class AI_Flags { public: char gap_00[0x1D]; unsigned char field_1D; };
class UnitAIModule {};
class TacticalAIGroup { public: int id(); int type(); };
struct _iobuf;

extern "C" void __cdecl logCommonHistory(void* target, const char* message);

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    void logCommonHistory(char* format, ...);
};

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual int load(char*, RGE_Player*);
    char* buildListName();
    int buildListLength();
    int numberItemsIntoBuildList();
    char* lastBuildItemRequested();
    char* currentBuildItemRequested();
    char* nextBuildItemRequested();
    int addItem(void*, int);
    void cancelBuildItem(int, int, int, float, float, int, int);
    char gap_04[0x5BC];
};

class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void load(char*, int, int, int, int, int);
    char* constructionPlanName();
    char gap_04[0x314];
};

class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char gap_04[0x14C];
    void setStance(int, int, int);
    void setChangeable(int, uchar);
    int stance(int, int);
    void changeStance(int, int, int);
};

class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    char gap_04[0x1BC];
    void setOverallState(int);
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0x1008C];
    void loadLearnInfo(char*);
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int*, int*);
    int fullyExploredZone(int);
    int closestUnexploredTile(int,long,long,long*,long*);
    int addImportantObject(long);
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char gap_04[0xF4];
    char* resourceName(int);
};

class TribeStrategyAIModule {
public:
    virtual ~TribeStrategyAIModule();
    char gap_04[0x5F4];
    int loadRules(char*);
    void setDifficultyLevel(int);
    int rule(int);
    void setRule(int, int);
    char* ruleSetName();
};

class TribeTacticalAIModule {
public:
    int attackEnabledValue;
    int lastUpdateAreaTimeValue;
    int averageUpdateAreaTimeValue;
    int neededResource(int) const;
    int desiredNumberGatherers() const;
    int numberGatherers() const;
    int desiredNumberCivilianExplorers() const;
    int numberCivilianExplorers() const;
    int numberCivilians() const;
    int numberSoldiers() const;
    void trackUnitGather(int, int, int);
    char* updateAreaName(); int strategicNumber(int); int resourceDifference(int);
    int neededResourceAmount(int); int numberBoats(); int numberSoldiers(); int numberCivilians();
    int desiredGathererCount(int); int actualGathererCount(int);
    TacticalAIGroup* groupUnitIsIn(int); int removeGroup(int); int taskExplorer(int,long,long); void detask(int);
    void notify(int,int,int,long,long,long);
};

class MainDecisionAIModule : public AIModule {
public:
    char gap_base[0x14];
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    TribeMainDecisionAIModule(int, char*, void*, int);
    TribeMainDecisionAIModule(void*, int, char*, void*, char*, char*, char*);
    virtual void update(int);
    void method16(void*);
    void removeObjectCallback(int);
    void tributeNotify(int,long,long);
    void updateBuildAIWithObjects();
    TribeTacticalAIModule tacticalAI;
};

class RGE_Map {
public:
    void* vtable_ptr;
    void* tiles;
    int map_width;
    int map_height;
};

class RGE_Scenario {
public:
    void* vtable_ptr;
    char gap_04[0x100C];
    char* learn_info;
};

class TRIBE_World;
class TRIBE_Player;
class TRIBE_Effects { public: void do_tech_effect(short, TRIBE_Player*); };
class T_Scenario {
public:
    char* learn_info;
    int GetScenarioOption(int);
    void set_player_tech(TRIBE_Player*);
};
class TRIBE_Player_Other { public: void save(int); };
class ScenarioObject { public: virtual void save(int); };

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x10];
    short player_num;
    short player_count;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
    RGE_Sprite** pad_30;
    RGE_Sound** pad_38;
    TRIBE_Command* commands;
    float delta_time;
    int currentUpdateComputerPlayer;
    short curr_player;
    float update_period;
    char gap_60[0xA4];
    void update_mutual_allies(void);
    void selectNextComputerPlayer(int);
    virtual unsigned char data_load_world(void*);
    RGE_Static_Object* object(int);
};

class RGE_Object_List {
public:
    virtual void vf00();
    RGE_Static_Object* object;
    ObjNode* head;
    ObjNode* list;
    RGE_Object_List();
    void* operator[](int);
    void load_list(int, RGE_Game_World*);
    RGE_Static_Object* find_by_master_id(long, float, float, uchar, uchar, RGE_Static_Object*);
};

class TRIBE_Object_List : public RGE_Object_List {
public:
    virtual void vf00();
};

class Visible_Resource_Manager {
public:
    Visible_Resource_Manager(RGE_Player*, int);
    Visible_Resource_Manager(int, void*);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C();
    virtual void get_string(int, char*, int);
    int difficulty();
    uchar deathMatch();
    int fullVisibility();
    int fullTechTree();
    int game_mode;
    int prog_mode;
    int multiplayerGame();
    int randomGame();
    int playerID(int);
};

struct NodeObj2 { char pad[0x14]; short id; };
struct NodeObj { char pad0[8]; NodeObj2* type; char pad1[0x3C]; char state; };
struct Node { NodeObj* obj; Node* next; };
struct ObjNode { RGE_Static_Object* obj; RGE_Static_Object* object; RGE_Static_Object* node; ObjNode* next; };
typedef ObjNode RGE_Object_Node;
struct List { int count; Node* head; };
struct Stats {
    float cur; char pad04[0x20]; float progress; float add; float visible;
    char pad30[0x1C]; float a4c; float a50; char pad54[4]; float explored;
    char pad5c[0x28]; float mult; char pad88[0x28]; float diff; float b4;
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int mapSize();
    int mapType();
    int victoryType();
    uchar deathMatch();
    RGE_Static_Object** selected_table; int selected_count;
    RGE_Static_Object** normal_table; int normal_count;
};

// Use the reviewed process-wide game pointer declaration.
#include "rge_base_game_global.h"

class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    RGE_Victory_Conditions(RGE_Player*, int, long*, unsigned char);
    char gap_04[0x1C];
    int get_victory_points_group(unsigned char);
    int get_victory_points_id(unsigned char);
    int get_victory_points();
    int get_attribute_id(unsigned char);
};

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:
    TRIBE_Victory_Conditions(RGE_Player*, int, long*, unsigned char);
    TRIBE_Victory_Conditions(RGE_Player*);
};

class RGE_Resource {
public:
    float food;
    float wood;
    float stone;
    float gold;
    char gap_10[0x1C];
    float pop;
};

class RGE_Visible_Map {
public:
    RGE_Visible_Map(RGE_Map*, RGE_Player*);
    RGE_Visible_Map(int, RGE_Game_World*);
    float percentExplored();
    unsigned char get_visible(int, int);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
    unsigned char master_type;
    void make_available(char);
    uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar, uchar, uchar, uchar, uchar);
    RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    unsigned char type;
    char* name;
    short pict;
    unsigned char available;
    unsigned char flag52;
    short hp;
    short right_click_table;
    short interface_group;
    long get_help_message();
    long get_help_page();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void action_ge7();
    virtual void action_3to6();
    virtual void action_range(float);
    virtual void vf43();
    virtual void vd8(RGE_Player*, int, int);
    virtual void vdc(RGE_Player*, int, int);
    UnitAIModule* unitAI();
    int id;
    int obj_id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x34];
    float attribute_amount_held;
    float hp;
    RGE_Static_Object_Type* type;
    unsigned char field_35;
    unsigned char object_state;
    void* group;
    int field_10;
    void* field_18;
    float world_x;
    float world_y;
    float world_z;
    float range;
    RGE_Master_Static_Object* special_master;
    int special_owner;
};

class RGE_Static_Object_Type {
public:
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0C(); virtual void v10(); virtual void v14();
    virtual RGE_Static_Object* make_scenario_obj(RGE_Player*, float, float, float);
    unsigned char object_group;
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    unsigned char build(float);
};

class Tech_Player_Tree {
public:
    float research_done;
    short state;
    char gap_06[2];
};

class Tech_Tree {
public:
    char* name;
    short pre_reqs[4];
    short pre_reqs_required;
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    char gap_1D;
    short research;
    short effect;
    short track;
    short icon;
    unsigned char button_location;
    char gap_27;
    short build_obj_id;
    short string_id;
    short string_id2;
    char gap_2E[2];
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

class TRIBE_Tech {
public:
    void save(int);
    Tech_Tree* tech_tree;
    short tech_tree_num;
    char gap_06[2];
    TRIBE_World* world;
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;
    TRIBE_Effects* effects;
    T_Scenario* scenario;
    void check_destructables(short, long, float, float, int);
    int controllingComputerPlayer;
};

struct Item_Avail {
public:
    char* name;
    short id;
    short pict;
    short inv1;
    short pad_0A;
    float cost1;
    short inv2;
    short pad_12;
    float cost2;
    short inv3;
    short pad_1A;
    float cost3;
    long help_msg;
    long help_page;
    short inventory_item_1;
    float inventory_cost_1;
    short inventory_item_2;
    float inventory_cost_2;
    short inventory_item_3;
    float inventory_cost_3;
    long help_string_id;
    long help_page_id;
};

class ObjectInfo {
public:
    char pad0[4]; unsigned char type; char pad5[3]; char* name;
    char pad0c[0x13C];
    short cost1_type; short cost1_amount; unsigned char cost1_used;
    char pad14d; short cost2_type; short cost2_amount; unsigned char cost2_used;
    char pad153; short cost3_type; short cost3_amount; unsigned char cost3_used;
    unsigned char flag52;
};

class TRIBE_Player_Tech {
public:
    virtual ~TRIBE_Player_Tech();
    TRIBE_Player_Tech(TRIBE_Tech*, RGE_Player*, unsigned char);
    unsigned char check_for_new_tech();
    TRIBE_Player_Tech(int, void*, RGE_Player*, int);
    Tech_Player_Tree* tech_player_tree;
    TechPlayerEntry* tech_player_tree_entries;
    short tech_player_tree_num;
    char gap_06[2];
    TRIBE_Tech* base_tech;
    RGE_Player* owner;

    void tech_cost(short, short*, short*, short*, short*, short*, short*);
    long get_help_message(short);
    long get_help_page(short);
    void do_tech(short); unsigned char rev_tech(short); void disable(short); void enable(short);
};

class TRIBE_History_Info {
public:
    TRIBE_History_Info(int);
    virtual ~TRIBE_History_Info();
    void add_history_entry(int, int);
    void add_history_entry(unsigned char, int);
};
class TRIBE_Population_Source { public: char gap_00[0x2C]; float population_value; };

class RGE_Player {
public:
    virtual ~RGE_Player();
    RGE_Player(int, RGE_Game_World*, unsigned char);
    RGE_Player(RGE_Game_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char);
    virtual void set_game_status(uchar);
    virtual void update();
    virtual void* addObject(void*, int, int);
    virtual void update_dopplegangers();
    virtual void scenario_save(int);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void add_attribute_num(short, float, unsigned char);
    void save(int);
    void removeObject(RGE_Static_Object*, int, int, void*);
    virtual void load_master_object(int, short, unsigned char, RGE_Sprite**, RGE_Sound**);
    virtual void load(int);
    uchar get_selected_objects_to_command(void**, short*, int, int, int, int);
    uchar get_selected_objects_to_command(RGE_Static_Object***, short*, int, int, int, int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postload(int, long*, float);
    RGE_Static_Object* make_new_object(long, float, float, float, int);
    void set_relation(int, char);
    void set_map_loc(short, short);
    void set_view_loc(float, float);

    char gap_04[0x1E];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Static_Object_Type** object_types;
    RGE_Object_List* objects;
    RGE_Object_List* object_list;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    union {
        RGE_Victory_Conditions* victory_conditions;
        RGE_Victory_Conditions* victory;
    };
    union {
        RGE_Visible_Map* visible;
        RGE_Visible_Map* visible_map;
    };
    RGE_Game_World* world;
    void* doppleganger_creator;
    void* VR_List;
    TRIBE_Command* tribe_command;
    char* name;
    uchar type;
    int computerPlayerValue;
    short objectCount;
    short master_count;
    RGE_Master_Static_Object** masters;
    char* playerData;
    int startTech;
    uchar gap_49;
    short id;
    char gap_4C[4];
    union {
        RGE_Resource* res;
        float* attributes;
    };
    char gap_54[0xAC];
    int allied_LOS_Enable;
    char gap_104[1];
    uchar civ_id;
    char gap_106[0x2A];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned int sel_object_properties;
    short sel_count;
    char gap_19E[0x82];
};

class TRIBE_Player : public RGE_Player {
public:
    virtual ~TRIBE_Player();
    char* aiStatus(int);
    void __cdecl logMessage(char*, ...);
    char aiStatusInformationValue5[0x100];
    char aiStatusInformationValue6[0x100];
    char aiStatusInformationValue[0x100];
    char aiStatusInformationValue2[0x100];
    char aiStatusInformationValue3[0x100];
    char aiStatusInformationValue4[0x100];
    TRIBE_Player(int, TRIBE_World*, unsigned char);
    TRIBE_Player(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char,
                 unsigned char, unsigned char, char*, char*, char*);
    TRIBE_Player(RGE_Game_World*, RGE_Master_Player*, unsigned char, char*, unsigned char,
                 unsigned char, unsigned char, char*, char*, char*);
    char player_type;
    short civ;
    int fog_update;
    int update_count;
    int update_history_count;
    int updateCountNeedHelp;
    int update_time;
    short count;
    char* field_50;
    TRIBE_Player_Tech* tech_tree;
    TRIBE_Player_Tech* techTree;
    char gap_224[0x14];
    union {
        TribeMainDecisionAIModule* playerAI;
        void* ai;
    };
    TRIBE_History_Info* history;
    List* list;
    RGE_Visible_Map* visibleMap;
    Stats* stats;
    unsigned char byte_48;
    TRIBE_Tech* tech;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    ScenarioObject* scenario_object;
    TRIBE_Player_Other* other;
    short master_object_count;
    TRIBE_Object_List* list_28;
    TRIBE_Object_List* list_2c;
    RGE_Object_List* list_30;
    RGE_Visible_Map* visible_map;
    Visible_Resource_Manager* visible_resources;
    int field_840;
    int field_844;
    float ruin_held_time;
    float artifact_held_time;
    float* resources;
    RGE_Progress_Info* progress_info;
    void* info;
    int mutual_allies_loaded;
    int mouse_actions[68];
    int current_action_flags;
    short current_target;
    AI_Flags* field_3C;
    float view_x;
    float view_y;
    void* obj_table;
    float* resource_cost_table;
    RGE_Player* rge_player;
    short diplomacy_value;
    TRIBE_Command* command;
    TRIBE_World* world;
    short destructable_type;

    void interface_tech_avail(Item_Avail**, short*, short);
    RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
    uchar check_obj_cost(short, short*, float, int);
    void obj_cost(short, char**, short*, short*, short*, short*, short*, short*, float);
    void obj_cost(short, char**, short&, short&, short&, short&, short&, short&, float);
    RGE_Static_Object* find_obj(short, RGE_Static_Object*);
    void interface_trade_avail(Trade_Avail**, short*);
    ObjectInfo** objectInfo;
    unsigned char get_selected_objects_to_command(RGE_Static_Object***, short*, int, int, int, int);
    unsigned char command_make_building(short, float, float);
    unsigned char command_make_wall(short, long, long, long, long);
    unsigned char command_building_cancel(void);
    PlayerCommandHolder* holder;
    unsigned char command_delete_object(RGE_Static_Object*);
    unsigned char command_trade_attribute(long);
    unsigned char command_attack_ground(float, float);
    uchar command_make_repair(RGE_Static_Object*);
    unsigned char command_make_unload(float, float);
    unsigned char pay_obj_cost(short, float, int);
    void objectCost(int, int, ResourceItem*, int);
    int objectCostByType(int);
    int researchAvailable(int);
    void researchState(int);
    Inner_00514F90* inner_;
    void kickAI(int);
    void researchCost(int, int, ResourceItem*, int);
    void reimburse_obj_cost(short);
    Inner_00513D60* ptr_;
    void check_tech_cost(int, int);
    TRIBE_Population_Source* population_source;
    void add_population_entry(void);
    TechIdSource* source;
    void rev_tech(long);
    void notifyAI(int,int,int,long,long,long);
    int intelligentCivSelection(int, int, int);
    int get_mouse_pointer_action_vars(int, int&, int&);
    unsigned char command_give_attribute(int, int, float, float);
    void interface_item_avail(Item_Avail**, short*, short);
    RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void random_start();
    void loadAIInformation(char*, char*, char*, int, int);
    void intelligentBuildListAndRulesSelection(char*, char*, int, int, int);
    virtual void logStatus(_iobuf*, int);
    virtual void trackUnitGather(int, int, int);
    void get_achievement(unsigned char, char*);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void analyize_selected_objects();
    void removeObject(RGE_Static_Object*, int, int, void*);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void update();
    void* addObject(void*, int, int);
    void buildObject(int, int, float, float, int);
    void cancelBuild(int, int, int, float, float, int, int);
    void taskTrader(int, int, int, float, float);
    void taskResourceGatherer(int, int, int, float, float);
    void setDiplomaticStance(int, int);
    virtual void update_dopplegangers();
    virtual void scenario_save(int);
    void save(int);
    virtual void load_master_object(int, short, unsigned char, RGE_Sprite**, RGE_Sound**);
    virtual void load(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postload(int, long*, float);

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
};

class TRIBE_Gaia : public TRIBE_Player {
public:
    void* vtable;
    unsigned char field_48;
    int update_time; int update_nature; int last_count; int animal_max;
    int field_848; int field_84C; int field_850; int field_854;
    TRIBE_Gaia(int, TRIBE_World*, unsigned char);
    TRIBE_Gaia(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char, unsigned char, char*, char*, char*);
    TRIBE_Gaia(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char);
    virtual ~TRIBE_Gaia();
    void random_start();
    void save(int);
    void update();
    void load_master_object(int, short, unsigned char, RGE_Sprite**, RGE_Sound**);
    void scenario_postload(int, long*, float);
};

struct BuildListPacket_00515E00 {
    int weights[125];
    int mostBuiltUnit;
};

extern "C" int __cdecl debug_rand(char*, int);
extern "C" void __cdecl debug_srand(char*, int, int);

#define S_TPLAYER_CPP ((char*)0x0058AC44)
#define S_RANDOM_GAME_SPECIALIZED ((char*)0x0058AF78)
#define S_SETTING_AI_PERSONALITY ((char*)0x0058B130)
#define S_SELECTED_BEST_BUILD_LIST ((char*)0x0058B148)
#define S_I_AM_THE_CIV ((char*)0x0058B16C)

#define debug_random_on (*(int*)0x0062C4D4)
#define saved_debug2 (*(int*)0x0086BC94)
#define base_game rge_base_game
#define tribe_game ((TRIBE_Game*)rge_base_game)

extern int computerPlayerSetup;
extern int DAT_00886c1c;
extern int DAT_00886c20;
extern int DAT_00886c24;
extern int DAT_00886c28;
extern int DAT_00886c2c;
extern int DAT_00886c30;
extern int DAT_00886c34;
extern int DAT_00886c38;
extern int DAT_00886c3c;
extern int DAT_00886c40;
extern int DAT_00886c44;
extern int DAT_00886c48;
extern int allowAIToCheat;


#endif
