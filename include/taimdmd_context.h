#ifndef AOE1_TAIMDMD_CONTEXT_H
#define AOE1_TAIMDMD_CONTEXT_H

// Canonical declarations for the original taimdmd.cpp source module.
//
// The PDB owner order is the constructor pair, destructor, the decision
// methods, and the update helpers in taimdmd.cpp.  The class inventory proves
// the 0x125CC derived object and the embedded module offsets below.  This
// header supplies one declaration surface for the complete grouped wrapper;
// owner files keep their standalone declarations when built alone.

typedef unsigned char uchar;

class AIModuleMessage;
class RGE_Static_Object;
class RGE_Game_World;
class RGE_Player;
class RGE_Object_List;
class RGE_Map;
class RGE_Master_Static_Object;
class TRIBE_Command;
class TRIBE_Player;
class TribeMainDecisionAIModule;
class DecisionModuleInfo;

void* operator new(unsigned int);
void operator delete(void*);

class StrategyAIModule {
public:
    virtual int update(int);
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    ~ManagedArray()
    {
        if (this->value != 0)
            operator delete(this->value);
    }

    T& operator[](int index)
    {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            T* newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < newSize; ++i)
                    newValue[i] = this->value[i];
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
    }
};

extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void __cdecl rge_read(int, void*, int);
extern "C" int __cdecl debug_rand(char*, int);
extern void rge_write(int, void*, int);
extern int startLoggingAI;
extern int rgeLog;
extern float g_time;
extern float g_cut1;
extern float g_cut2;

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
    virtual int filterOutMessage(AIModuleMessage*);

    char gap_04[0xEC];

    AIModule();
    AIModule(void*, int, void*);
    AIModule(char*, int, int, void*);
    void setPlayer(int, char*);
    void logCommonHistory(char*, ...);
};

typedef char taimdmd_aimodule_size[(sizeof(AIModule) == 0xF0) ? 1 : -1];

class MainDecisionAIModule : public AIModule {
public:
    union {
        RGE_Player* player;
        DecisionModuleInfo* info;
    };
    int* objects_value;
    int objects_numberValue;
    int objects_pad_FC;
    int objects_maximumSizeValue;

    virtual ~MainDecisionAIModule();
    virtual void setLogHistory(int);
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
    virtual int canPerformAction(int, int);

    MainDecisionAIModule(void*, int, void*);
    MainDecisionAIModule(int, TRIBE_Player*, int);
    RGE_Static_Object* object(int);
};

typedef char taimdmd_main_decision_size[
    (sizeof(MainDecisionAIModule) == 0x104) ? 1 : -1];

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    char bytes[0x5BC];

    TribeBuildAIModule(void*, int);
    TribeBuildAIModule(int, int);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
    void initialize();
    void skipNextBuildListItem();
    void removeBuiltItem(int);
    int insert(int, int, int);
    void* vf40();
    int addItem(RGE_Static_Object*, int);
};

typedef char taimdmd_build_size[(sizeof(TribeBuildAIModule) == 0x5C0) ? 1 : -1];

class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    char bytes[0x314];

    TribeConstructionAIModule(void*, int);
    TribeConstructionAIModule(int, int);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
    void setReferencePoint(int, int, float, float, float);
};

typedef char taimdmd_construction_size[
    (sizeof(TribeConstructionAIModule) == 0x318) ? 1 : -1];

class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char bytes[0x14C];

    DiplomacyAIModule(void*, int);
    DiplomacyAIModule(int, int);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
    int stance(int, int);
    void setStance(int, int, int);
    void changeStance(int, int, int);
    void setChangeable(int, uchar);
    void setRelation(int, int);
    void update(int);
};

typedef char taimdmd_diplomacy_size[(sizeof(DiplomacyAIModule) == 0x150) ? 1 : -1];

class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    char bytes[0x1BC];

    EmotionalAIModule(void*, int);
    EmotionalAIModule(int, int);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
    void setOverallState(int);
};

typedef char taimdmd_emotional_size[(sizeof(EmotionalAIModule) == 0x1C0) ? 1 : -1];

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char bytes[0x1008C];

    TribeInformationAIModule(void*, int);
    TribeInformationAIModule(int, int);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
    void addResourceType(int, int);
    int initialize();
    void addObject(RGE_Static_Object*);
    void removeObject(int);
    void lookAtMap();
    int update(int);
};

typedef char taimdmd_information_size[
    (sizeof(TribeInformationAIModule) == 0x10090) ? 1 : -1];

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char bytes[0xF4];

    TribeResourceAIModule(void*, int, int, int, int, int);
    TribeResourceAIModule(int, int);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
};

typedef char taimdmd_resource_size[(sizeof(TribeResourceAIModule) == 0xF8) ? 1 : -1];

class TribeStrategyAIModule {
public:
    virtual ~TribeStrategyAIModule();
    char bytes[0x5F4];

    TribeStrategyAIModule(void*, int);
    TribeStrategyAIModule(int, int);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
    int update(int);
};

typedef char taimdmd_strategy_size[(sizeof(TribeStrategyAIModule) == 0x5F8) ? 1 : -1];

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char bytes[0x1008];

    TribeTacticalAIModule(void*, int);
    TribeTacticalAIModule(int, int);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
    int strategicNumber(int);
    void setStrategicNumber(int, int);
    int processCoopAttack(int, int, int, int);
    void addObject(RGE_Static_Object*);
    void removeObject(int);
    int update(int);
    void target_method(int);
};

typedef char taimdmd_tactical_size[(sizeof(TribeTacticalAIModule) == 0x100C) ? 1 : -1];

class TradeAIModule {
public:
    virtual ~TradeAIModule();
    char bytes[0xF0];

    TradeAIModule(void*, int);
    TradeAIModule(int, int);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    void setPlayer(int, char*);
    void setLogHistory(int);
    int save(int);
    void setup(MainDecisionAIModule*);
};

typedef char taimdmd_trade_size[(sizeof(TradeAIModule) == 0xF4) ? 1 : -1];

class RGE_Map {
public:
    char gap_00[0x08];
    int xSizeValue;
    int ySizeValue;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    uchar temp_pause;
    uchar game_state;
    uchar game_end_condition;
    uchar gap_1F;
    char bytes_20[0x1C];
    short player_num;
    uchar gap_3E[2];
    class RGE_Player** players;
    char bytes_44[0x14];
    TRIBE_Command* commands;
    char bytes_5C[0x9C];
    int currentUpdateComputerPlayer;
    char tail_100[4];
    RGE_Map* mapValue;
};

class TRIBE_World : public RGE_Game_World {
public:
    char bytes_104[0x19];
    uchar controllingComputerPlayer;
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
    virtual void command_add_attribute(int, float);
    virtual int sendAICommand(int, int, int, int, int);

    int computerPlayerValue;
    char gap_08[0x20];
    RGE_Object_List* objects;
    char gap_2C[0x10];
    union { RGE_Game_World* world; RGE_Game_World* worldValue; };
    char gap_40[0x0A];
    short id;
    char gap_4C[4];
    float* attributes;

    int computerPlayer();
    void __cdecl sendChatMessage(int, int, char*, ...);
    int isEnemy(int) const;
};

class TRIBE_Player : public RGE_Player {
public:
    virtual uchar command_give_attribute(int, int, float, float);
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_id(long, float, float, uchar, uchar,
                                         RGE_Static_Object*);
};

class TRIBE_Command {
public:
    void command_allied_victory(short, uchar);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual char* get_string(int, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    int difficulty();
    int deathMatch();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int deathMatch();
};

extern RGE_Base_Game* rge_base_game;

class RGE_Victory_Conditions {
public:
    int get_victory_points();
};

struct DecisionScoreEntry {
    char gap_00[0x34];
    RGE_Victory_Conditions* victory;
};

struct DecisionScoreTable {
    char gap_00[0x3C];
    short count;
    char gap_3E[2];
    DecisionScoreEntry** entries;
};

class DecisionModuleInfo {
public:
    char gap_00[0x3C];
    DecisionScoreTable* table;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
    TribeTacticalAIModule tacticalAI;
    TradeAIModule tradeAI;
    union { TRIBE_Player* aiPlayer; TRIBE_Player* tribe_player; };
    union { int firstUpdate; int field_12570; };
    union { int veryFirstUpdate; int field_12574; };
    union { int updateDelay; char* name; };
    union { unsigned long lastDiplomacyUpdateTime; int field_1257C; };
    union { unsigned long lastTacticalUpdateTime; int field_12580; };
    union { unsigned long lastTributeChatTime; int field_12584; };
    union { unsigned long tributeChatTimeout; int field_12588; };
    union { int waitingOnTribute; int field_1258C; };
    union { int tributeExpirationTimeout; int field_12590; };
    union { int tributeAddressed; int field_12594; };
    union { int tributeAmount; int field_12598; };
    union { int decidedInitialDiplomacy; int field_1259C; };
    union { int requiredDiplomacyTributeAmount; int field_125A0; };
    union { int tributeGiven[9]; int array_125A4[9]; };

    TribeMainDecisionAIModule(void*, int, char*, void*, char*, char*, char*);
    TribeMainDecisionAIModule(int, char*, TRIBE_Player*, int);
    virtual ~TribeMainDecisionAIModule();
    virtual void setLogHistory(int);
    virtual int update(int);
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
    virtual int canPerformAction(int, int);
    void kick(int);
    int isMoveable(int);
    void updateBuildAIWithObjects();
    void tributeNotify(int, int, int);
    void revokeTributeAlliance();
    void setTributeChat();
    int processAICommand(int, int, int, int, int);
    int currentScore(int);
    void detask(int);
};

typedef char taimdmd_tribe_main_size[
    (sizeof(TribeMainDecisionAIModule) == 0x125C8) ? 1 : -1];

typedef char taimdmd_player_offset[
    (((char*)&((MainDecisionAIModule*)0)->player - (char*)0) == 0xF0) ? 1 : -1];

typedef char taimdmd_ai_player_offset[
    (((char*)&((TribeMainDecisionAIModule*)0)->aiPlayer - (char*)0) == 0x1256C) ? 1 : -1];

#endif
