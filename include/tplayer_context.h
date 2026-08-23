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
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char gap_04[0xF4];
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
    int neededResource(int) const;
    int desiredNumberGatherers() const;
    int numberGatherers() const;
    int desiredNumberCivilianExplorers() const;
    int numberCivilianExplorers() const;
    int numberCivilians() const;
    int numberSoldiers() const;
    void trackUnitGather(int, int, int);
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
    void updateBuildAIWithObjects();
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

class TRIBE_Tech;
class TRIBE_World;

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x10];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
    char gap_60[0xA4];
    void update_mutual_allies(void);
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
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int mapSize();
    int mapType();
    int victoryType();
    uchar deathMatch();
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
    float percentExplored();
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x34];
    float attribute_amount_held;
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
    Tech_Tree* tech_tree;
    short tech_tree_num;
    char gap_06[2];
    TRIBE_World* world;
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;
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
};

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    char gap_06[2];
    TRIBE_Tech* base_tech;
    RGE_Player* owner;

    void tech_cost(short, short*, short*, short*, short*, short*, short*);
    long get_help_message(short);
    long get_help_page(short);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
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

    char gap_04[0x1E];
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    union {
        RGE_Victory_Conditions* victory_conditions;
        RGE_Victory_Conditions* victory;
    };
    union {
        void* visible;
        RGE_Visible_Map* visible_map;
    };
    RGE_Game_World* world;
    void* doppleganger_creator;
    char* name;
    uchar type;
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
    TRIBE_Player_Tech* tech_tree;
    char gap_224[0x14];
    union {
        TribeMainDecisionAIModule* playerAI;
        void* ai;
    };

    void interface_tech_avail(Item_Avail**, short*, short);
    void loadAIInformation(char*, char*, char*, int, int);
    void intelligentBuildListAndRulesSelection(char*, char*, int, int, int);
    virtual void logStatus(_iobuf*, int);
    virtual void trackUnitGather(int, int, int);
    void get_achievement(unsigned char, char*);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void analyize_selected_objects();

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

struct BuildListPacket_00515E00 {
    int weights[125];
    int mostBuiltUnit;
};

extern "C" int __cdecl debug_rand(char*, int);
extern "C" void __cdecl debug_srand(char*, int, int);
extern "C" void* __cdecl strcpy(void*, const void*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl sprintf(char*, const char*, ...);

#define S_TPLAYER_CPP ((char*)0x0058AC44)
#define S_RANDOM_GAME_SPECIALIZED ((char*)0x0058AF78)
#define S_SETTING_AI_PERSONALITY ((char*)0x0058B130)
#define S_SELECTED_BEST_BUILD_LIST ((char*)0x0058B148)
#define S_I_AM_THE_CIV ((char*)0x0058B16C)

#define debug_random_on (*(int*)0x0062C4D4)
#define saved_debug2 (*(int*)0x0086BC94)
#define rge_base_game ((TRIBE_Game*)rge_base_game)
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
