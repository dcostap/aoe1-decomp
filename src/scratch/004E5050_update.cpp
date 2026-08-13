// VA: 004E5050 TribeMainDecisionAIModule::update
// PDB: taimdmd.cpp:258-784
// FLAGS: /nologo /c /O2 /Oy /GX
//
// Baseline reconstruction: named main-decision subobjects, real AIModule/RGE
// virtual surfaces, the TRIBE world/player ownership, and the ordered tribute
// and initial-diplomacy call/CFG structure from the executable.
//
// Attempt log:
// baseline: canonical named main-decision ownership, real module/player/game
// virtual surfaces, and the /GX ManagedArray lifetime inferred from the
// executable.  Initial reconstruction was 3136 bytes with a 0x148 frame.
// added the real scoped ManagedArray constructor/destructor and moved the
// one-time AI setup under the firstUpdate guard; frame reached 0x144.
// exposed the base StrategyAIModule virtual surface for both update sites and
// forced get_string onto the binary-proven +0x20 overload.
// folded swayableCount into ManagedArray::numberValue, which placed the array,
// neutralList, and tempString at the executable's +0x20/+0x30/+0x54 locals.
// restored tribute response common tails and the late positive-tribute stance
// behavior; final validation has exact aggregate call counts but four ordered
// call replacements, a 51-byte size surplus, and persistent entry/prologue
// and CFG drift.  Left in scratch after the ten-hypothesis budget.
// inverted the tribute amount branches and factored the guarded tribute-chat
// control flow from the original call order; one shared tail dropped six real
// calls, so it was replaced with two duplicated send tails.  The retained
// form restores all 102 ordered calls and is the best source-model lead, but
// leaves a 71-byte surplus and the broader entry/prologue CFG drift.
// behavior probe: the initial world guard, diplomacy loop, and four attribute
// commands now use inherited player (+0xF0), matching the original early block;
// code size grew to 3472 and strict diff to 3186, so no codegen gain was kept.
// layout probe: the original update has no [this+0x1256C] access and repeatedly
// reads the inherited player at +0xF0; replaced every update-time aiPlayer use
// with player.  Strict diff improved to 3173, size fell to 3468, and exact
// block coverage rose to 28.22%; kept as the best binary-supported source.
// control-flow probe: inlined the three stance calls with source order that
// makes VC5 evaluate kinds 1, 2, 0; this removed named-result spills.
// guarded-scope probes: put the diplomacy pointer behind player_num > 1 and
// used a do-while with its index initialized before the guard.  This matched
// the original loop topology and reached exact size with 34.52% block coverage.
// layout probe: computed tribute elapsed time before strategicNumber(0x7C),
// matching the original pre-call time calculation.  Best diff became 2742,
// shape 84.35%, exact blocks 42.03%, with 23 bytes of residual size drift.
// diagnostic probes for local declaration order and a 902 amount copy gave no
// gain or gave worse shape; restored distinct count and direct member source.

#include <stdlib.h>

typedef unsigned char uchar;

class AIModuleMessage;
class RGE_Static_Object;
class RGE_Game_World;
class TRIBE_World;
class TRIBE_Player;
class TribeMainDecisionAIModule;
class RGE_Scenario;
class RGE_Scenario_Header;
class TPanel;
class TSound_Driver;
class TCommunications_Handler;
class RGE_Player_Info;
class RGE_Sprite;
class RGE_Zone_Map;
class XYZBYTEPoint;
class RGE_Object_Node;
class RGE_Static_Object;
class RGE_Object_List;
class RGE_Master_Static_Object;
class RGE_Victory_Conditions;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
class RGE_Color_Table;
class Visible_Resource_Manager;
class RGE_Tile_List;
class TShape;
class RGE_Prog_Info;
class RGE_Scenario_File_Info;
class TDrawSystem;
class TDrawArea;
class TMusic_System;
class TDigital;
class TDebuggingLog;
class TRegistry;
class TMousePointer;
class RGE_Font;
class AIPlayBook;
class RGE_Sound;
class RGE_Map;
class RGE_Effects;
class RGE_Command;
class RGE_Scenario;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Base_Game;
class TRIBE_Game;

// The period inline utility has four scalar members and expands its resize
// operation at each indexed write in this function.
template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    ~ManagedArray() {
        if (this->value != 0) {
            operator delete(this->value);
        }
    }

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)operator new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_value[i] = this->value[i];
                }
                operator delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[0x40];
};

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* name);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* name);
    virtual int saveState(char* name);
    virtual int gleanState(int value);
    virtual int processMessage(AIModuleMessage* message);
    virtual int update(int value);
    virtual void setCallbackMessage(AIModuleMessage* message);
    virtual int filterOutMessage(AIModuleMessage* message);

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[0x40];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[0x40];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;

    void logCommonHistory(char* format, ...);
};

class MainDecisionAIModule : public AIModule {
public:
    TRIBE_Player* player;
    ManagedArray<int> objects;

    virtual ~MainDecisionAIModule();
    virtual void setLogHistory(int value);
    virtual int save(int value);
    virtual int addObject(RGE_Static_Object* object);
    virtual int removeObject(int object_id);
    virtual int objectGroupThatCanPerformAction(int action);
    virtual int canPerformAction(int action, int target);
};

class BuildAIModule : public AIModule {};
class ConstructionAIModule : public AIModule {};
class InformationAIModule : public AIModule {};
class ResourceAIModule : public AIModule {};
class StrategyAIModule : public AIModule {};
class TacticalAIModule : public AIModule {};
class TradeAIModule : public AIModule {};

class TribeBuildAIModule : public BuildAIModule {
public:
    char gap_F0[0x5BC - 0xF0];
    TribeMainDecisionAIModule* md;

    void initialize();
};

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    char bytes[0x318 - 0xF0];
};

class DiplomacyAIModule : public AIModule {
public:
    char bytes[0x150 - 0xF0];

    int stance(int player, int kind);
    void setStance(int player, int stance_value, int amount);
};

class EmotionalAIModule : public AIModule {
public:
    char bytes[0x1C0 - 0xF0];
};

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray<int> farmsTaskedThisUpdate;
    TribeMainDecisionAIModule* md;
    char bytes[0x10090 - 0x104];

    virtual int update(int value);
    int initialize();
};

class TribeResourceAIModule : public ResourceAIModule {
public:
    char bytes[0xF8 - 0xF0];
};

class TribeStrategyAIModule : public StrategyAIModule {
public:
    TribeMainDecisionAIModule* md;
    char bytes[0x5F8 - 0xF4];

    virtual int update(int value);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int value);
    virtual int isAlly(int value);
    virtual int isNeutral(int value);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int value, int stance_value);
    virtual void loadAIInformation(char* ai1, char* ai2, char* ai3, int value1, int value2);
    virtual void sendUnitAIOrder(int p1, int p2, int p3, int p4, int p5,
                                 float p6, float p7, float p8, float p9,
                                 int p10, int p11, int p12);
    virtual void processAIOrder(int p1, int p2, int p3, int p4, int p5,
                                float p6, float p7, float p8, float p9,
                                int p10, int p11, int p12);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(RGE_Static_Object* p1, RGE_Static_Object* p2, float p3, float p4);
    virtual void sendAddWaypointCommand(int p1, XYZBYTEPoint* p2, int p3);
    virtual void processAddWaypointCommand(int p1, XYZBYTEPoint* p2, int p3);
    virtual void sendPlayCommand(int p1, int* p2, int p3, int p4, int p5);
    virtual void sendPlayCommand(int p1, int p2, int p3);
    virtual int sendAICommand(int p1, int p2, int p3, int p4, int p5);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int p1, int p2, int p3);
    virtual RGE_Static_Object* make_scenario_obj(float p1, float p2, float p3, short p4, uchar p5, float p6);
    virtual void scenario_save(int file);
    virtual void scenario_load(int file, long* value, float version);
    virtual void scenario_postsave(int file);
    virtual void scenario_postload(int file, long* value, float version);
    virtual void load(int file);
    virtual void add_attribute_num(short value, float amount, uchar flags);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int file);
    virtual void save2(int file);
    virtual void save_info(int file);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long value, float p2, float p3, float p4, int p5);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int value, int* p2, int* p3);
    virtual uchar command_make_move(RGE_Static_Object* object, float x, float y);
    virtual uchar command_make_work(RGE_Static_Object* object, float x, float y);
    virtual uchar command_make_do(RGE_Static_Object* object, float x, float y);
    virtual uchar command_stop();
    virtual uchar command_place_object(short value, float x, float y, float z);
    virtual uchar command_add_attribute(int value, float amount);

    int computerPlayerValue;
    char gap_08[0x34];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x1D4];

    int computerPlayer();
    void __cdecl sendChatMessage(int target, int flags, char* format, ...);
};

class TRIBE_Player : public RGE_Player {
public:
    char bytes[0x848 - 0x220];
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
    RGE_Player** players;
    char bytes_44[0xB8];
    int currentUpdateComputerPlayer;
    char tail_100[4];
};

class TRIBE_World : public RGE_Game_World {
public:
    char bytes_104[0x19];
    uchar controllingComputerPlayer;
};

class RGE_Game_Options {
public:
    char bytes_00[0x9B];
    uchar difficultyValue;
    char bytes_9C[0x0C];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* p1, unsigned int p2, unsigned int p3, long p4);
    virtual void set_prog_mode(int value);
    virtual void set_game_mode(int value, int submode);
    virtual void set_player(short value);
    virtual int get_error_code();
    virtual char* get_string(int type, long id, char* buffer, int length);
    virtual char* get_string(long id, char* buffer, int length);
    virtual char* get_string(long id);
    virtual char* get_string2(int type, long id, long value, char* buffer,
                              int length);

    char bytes_04[0x8F4];
    RGE_Game_Options rge_game_options;

    int difficulty();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    uchar deathMatch();
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    char bytes[0x100C - 0xF4];

    virtual int update(int value);
    int strategicNumber(int value);
    void setStrategicNumber(int value, int setting);
};

class TradeAIModule_Layout : public TradeAIModule {
public:
    char bytes[0xF4 - 0xF0];
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
    TradeAIModule_Layout tradeAI;
    TRIBE_Player* aiPlayer;
    int firstUpdate;
    int veryFirstUpdate;
    int updateDelay;
    unsigned long lastDiplomacyUpdateTime;
    unsigned long lastTacticalUpdateTime;
    unsigned long lastTributeChatTime;
    unsigned long tributeChatTimeout;
    int waitingOnTribute;
    int tributeExpirationTimeout;
    int tributeAddressed;
    int tributeAmount;
    int decidedInitialDiplomacy;
    int requiredDiplomacyTributeAmount;
    int tributeGiven[9];

    virtual int update(int value);
    void setTributeChat();
};

extern "C" int __cdecl debug_rand(char* file, int line);
extern TRIBE_Game* rge_base_game;

int TribeMainDecisionAIModule::update(int param_1)
{
    int newEnemy;
    TRIBE_World* world;
    int numberNeutralCPs;
    int numberHumanPlayers;
    int amount;
    int neutralList[9];
    char tempString[256];

    if (this->player->world->game_state == 0 && this->firstUpdate == 1) {
        this->firstUpdate = 0;
        this->logCommonHistory("Initial Diplomacy Settings:");

        int playerIndex = 1;
        if (this->player->world->player_num > playerIndex) {
            DiplomacyAIModule* diplomacy = &this->diplomacyAI;
            do {
                this->logCommonHistory(
                    "  Player #%d: Dislike=%d, Like=%d, Ambivalence=%d.",
                    playerIndex,
                    diplomacy->stance(playerIndex, 0),
                    diplomacy->stance(playerIndex, 2),
                    diplomacy->stance(playerIndex, 1));
                playerIndex++;
            } while (playerIndex < this->player->world->player_num);
        }
    ((StrategyAIModule*)&this->strategyAI)->update(0);
    this->buildAI.initialize();
    this->informationAI.initialize();
    this->setTributeChat();

    TribeTacticalAIModule* tactical = &this->tacticalAI;
    if (tactical->strategicNumber(0x81) == 1 && tactical->strategicNumber(0x7D) == 0) {
        this->waitingOnTribute = 1;
        this->tributeAmount = 0;
    }

    amount = tactical->strategicNumber(0x8A);
    if (amount != 0) {
        this->player->command_add_attribute(0, (float)amount);
    }
    amount = tactical->strategicNumber(0x8B);
    if (amount != 0) {
        this->player->command_add_attribute(3, (float)amount);
    }
    amount = tactical->strategicNumber(0x8C);
    if (amount != 0) {
        this->player->command_add_attribute(2, (float)amount);
    }
    amount = tactical->strategicNumber(0x8D);
    if (amount != 0) {
        this->player->command_add_attribute(1, (float)amount);
    }

    }

    this->updateDelay++;
    if (this->updateDelay >= 0x14) {
        ((StrategyAIModule*)&this->strategyAI)->update(0);
        this->updateDelay = 0;
    }
    this->informationAI.update(0);

    if ((this->player->world->world_time - this->lastDiplomacyUpdateTime) / 1000 < 60) {
        // No diplomacy refresh is due yet.
    } else {
        this->diplomacyAI.update(0);
        this->lastDiplomacyUpdateTime = this->player->world->world_time;
    }

    TribeTacticalAIModule* tactical = &this->tacticalAI;
    unsigned long tributeLastTime = this->lastTributeChatTime;
    unsigned long tributeElapsed =
        (this->player->world->world_time - tributeLastTime) / 1000;
    int tributeSetting = tactical->strategicNumber(0x7C);
    if (tributeSetting > 0 && this->tributeAddressed == 0) {
        if (tributeElapsed < this->tributeChatTimeout ||
            tactical->strategicNumber(0x7D) <= 0) {
            if (this->waitingOnTribute == 1) {
                this->tributeExpirationTimeout -= this->player->world->world_time_delta;
                if (this->tributeExpirationTimeout <= 0) {
                    if (tactical->strategicNumber(0x82) == 1) {
                        int stanceValue = tactical->strategicNumber(0x80);
                        this->diplomacyAI.setStance(stanceValue, 0, 100);
                        stanceValue = tactical->strategicNumber(0x80);
                        this->diplomacyAI.setStance(stanceValue, 2, 0);
                        this->player->setDiplomaticStance(tactical->strategicNumber(0x80), 3);
                        rge_base_game->get_string((long)0x901, tempString, 0x100);
                        this->player->sendChatMessage(
                            tactical->strategicNumber(0x80), 0, tempString);
                        this->waitingOnTribute = 0;
                        this->tributeAddressed = 1;
                        this->lastTributeChatTime = this->player->world->world_time;
                    } else if (tactical->strategicNumber(0x81) == 1) {
                        rge_base_game->get_string((long)0x900, tempString, 0x100);
                        goto tribute_response_send;
                    }
                } else {
                    if (this->tributeAmount >= tactical->strategicNumber(0x7C)) {
                        if (tactical->strategicNumber(0x81) == 1) {
                            int stanceValue = tactical->strategicNumber(0x80);
                            this->diplomacyAI.setStance(stanceValue, 0, 0);
                            stanceValue = tactical->strategicNumber(0x80);
                            this->diplomacyAI.setStance(stanceValue, 2, 100);
                            this->player->setDiplomaticStance(tactical->strategicNumber(0x80), 0);
                            rge_base_game->get_string((long)0x8FF, tempString, 0x100);
                            goto tribute_response_send;
                        } else if (tactical->strategicNumber(0x82) == 1) {
                            rge_base_game->get_string((long)0x8FE, tempString, 0x100);
                            this->player->sendChatMessage(
                                tactical->strategicNumber(0x80), 0, tempString);
                            this->waitingOnTribute = 0;
                            this->lastTributeChatTime = this->player->world->world_time;
                            goto tribute_response_addressed;
                        }
                    }
                }
                goto tribute_response_done;

tribute_response_send:
                this->player->sendChatMessage(
                    tactical->strategicNumber(0x80), 0, tempString);
                this->waitingOnTribute = 0;
                this->lastTributeChatTime = this->player->world->world_time;

tribute_response_addressed:
                this->tributeAddressed = tactical->strategicNumber(0x84) == 0;

tribute_response_done:
                ;
            }
        } else {
            if (this->waitingOnTribute == 0) {
                this->waitingOnTribute = 1;
                this->tributeAmount = 0;
                this->tributeExpirationTimeout = tactical->strategicNumber(0x7F) * 1000;
            }
            this->lastTributeChatTime = this->player->world->world_time;
            int tribute = 0;
            if (tactical->strategicNumber(0x82) == 1) {
                if (this->tributeAmount > 0) {
                    rge_base_game->get_string((long)0x902, tempString, 0x100);
                    tribute = tactical->strategicNumber(0x7C) - this->tributeAmount;
                    goto tribute_chat_send_one;
                } else {
                    rge_base_game->get_string((long)0x903, tempString, 0x100);
                    tribute = tactical->strategicNumber(0x7C);
                    goto tribute_chat_send_two;
                }
            } else {
                if (tactical->strategicNumber(0x81) != 1) {
                    goto tribute_chat_done;
                }
                if (this->tributeAmount > 0) {
                    rge_base_game->get_string((long)0x904, tempString, 0x100);
                    tribute = tactical->strategicNumber(0x7C);
                    goto tribute_chat_send_one;
                } else {
                    rge_base_game->get_string((long)0x905, tempString, 0x100);
                    tribute = tactical->strategicNumber(0x7C) - this->tributeAmount;
                    goto tribute_chat_send_two;
                }
            }

tribute_chat_send_one:
            this->player->sendChatMessage(
                tactical->strategicNumber(0x80), 0, tempString, tribute);
            this->setTributeChat();
            goto tribute_chat_done;

tribute_chat_send_two:
            this->player->sendChatMessage(
                tactical->strategicNumber(0x80), 0, tempString, tribute);
            this->setTributeChat();

tribute_chat_done:
            ;
        }
    }

    if (this->decidedInitialDiplomacy == 0 && this->player->world->world_time > 10000) {
        this->decidedInitialDiplomacy = 1;
        world = (TRIBE_World*)this->player->world;
        newEnemy = 0;
        numberNeutralCPs = 0;
        numberHumanPlayers = 0;

        for (int playerIndex = 1; playerIndex < world->player_num; playerIndex++) {
            RGE_Player* player = world->players[playerIndex];
            if (player->computerPlayer() == 0) {
                numberHumanPlayers++;
            } else {
                newEnemy++;
                if (player->isAllNeutral() == 1) {
                    neutralList[playerIndex] = 1;
                    numberNeutralCPs++;
                } else {
                    neutralList[playerIndex] = 0;
                }
            }
        }

        if (world->controllingComputerPlayer == 0xFF) {
            if (newEnemy == 1) {
                world->controllingComputerPlayer = (uchar)this->player->id;
            } else {
                int selected = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x236) % newEnemy + 1;
                for (int playerIndex = 1; playerIndex < world->player_num; playerIndex++) {
                    RGE_Player* player = world->players[playerIndex];
                    if (player->computerPlayer() == 1) {
                        selected--;
                        if (selected == 0) {
                            world->controllingComputerPlayer = (uchar)player->id;
                        }
                    }
                }
            }
        }

        if (world->controllingComputerPlayer == (uchar)this->player->id) {
            newEnemy = (newEnemy - numberHumanPlayers) / 2;
            if (newEnemy < 0) {
                newEnemy = 0;
            }
            if (numberNeutralCPs < newEnemy) {
                newEnemy = numberNeutralCPs;
            }
            if (rge_base_game->deathMatch() == 1) {
                newEnemy = 0;
            }

            if (newEnemy <= numberNeutralCPs && numberNeutralCPs > 0) {
                ManagedArray<int> swayableCPs;
                numberNeutralCPs = 1;
                while (numberNeutralCPs < world->player_num) {
                    RGE_Player* player = world->players[numberNeutralCPs];
                    if (player->computerPlayer() != 0 && neutralList[numberNeutralCPs] != 0) {
                        int found = 0;
                        for (int i = 0; i < swayableCPs.numberValue; i++) {
                            if (swayableCPs.maximumSizeValue <= i) {
                                break;
                            }
                            if (swayableCPs.value[i] == numberNeutralCPs) {
                                found = 1;
                                break;
                            }
                        }
                        if (!found && swayableCPs.numberValue < newEnemy) {
                            swayableCPs[swayableCPs.numberValue] = numberNeutralCPs;
                            swayableCPs.numberValue++;
                        }
                    }
                    numberNeutralCPs++;
                }

                newEnemy = 2000;
                switch (rge_base_game->difficulty()) {
                case 0:
                    newEnemy = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x26E) % 500 + 0x578;
                    break;
                case 1:
                    newEnemy = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x26F) % 400 + 1000;
                    break;
                case 2:
                    newEnemy = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x270) % 300 + 700;
                    break;
                case 3:
                    newEnemy = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x271) % 200 + 0x1C2;
                    break;
                case 4:
                    newEnemy = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x272) % 100 + 300;
                    break;
                }

                numberNeutralCPs = 1;
                while (numberNeutralCPs < world->player_num) {
                    RGE_Player* player = world->players[numberNeutralCPs];
                    if (player->computerPlayer() != 0 && neutralList[numberNeutralCPs] != 0) {
                        int found = 0;
                        for (int i = 0; i < swayableCPs.numberValue; i++) {
                            if (swayableCPs.maximumSizeValue <= i) {
                                break;
                            }
                            if (swayableCPs.value[i] == numberNeutralCPs) {
                                found = 1;
                                break;
                            }
                        }
                        if (found) {
                            player->sendAICommand((int)this->player->id, 7, newEnemy, 0, 0);
                            newEnemy = newEnemy + newEnemy;
                        }

                        for (int otherIndex = 1; otherIndex < world->player_num; otherIndex++) {
                            if (numberNeutralCPs != otherIndex) {
                                RGE_Player* other = world->players[otherIndex];
                                if (other->computerPlayer() == 0) {
                                    int otherFound = 0;
                                    for (int i = 0; i < swayableCPs.numberValue; i++) {
                                        if (swayableCPs.maximumSizeValue <= i) {
                                            break;
                                        }
                                        if (swayableCPs.value[i] == numberNeutralCPs) {
                                            otherFound = 1;
                                            break;
                                        }
                                    }
                                    if (otherFound) {
                                        if (other->computerPlayer() == 1) {
                                        player->sendAICommand((int)this->player->id, 6, otherIndex, 2, 0);
                                        }
                                    } else {
                                        player->sendAICommand((int)this->player->id, 6, otherIndex, 0, 0);
                                    }
                                } else {
                                    player->sendAICommand((int)this->player->id, 6, otherIndex, 2, 0);
                                }
                            }
                        }
                    }
                    numberNeutralCPs++;
                }
            }
        }
    }

    if (tactical->strategicNumber(0xD9) == 1) {
        unsigned int timeout = (unsigned int)((tactical->strategicNumber(0x68) - 3) * 1000);
        if ((int)timeout < 0) {
            timeout = 0;
        }
        if (timeout < this->player->world->world_time) {
            tactical->setStrategicNumber(0xD9, 0);
            int newPlayer = -1;
            for (int playerIndex = 1; playerIndex < this->player->world->player_num; playerIndex++) {
                if (this->player->world->players[playerIndex]->computerPlayer() != 1) {
                    newPlayer = playerIndex;
                    break;
                }
            }
            if (newPlayer != -1) {
                if (this->player->isEnemy(newPlayer) == 0) {
                    this->player->sendAICommand((int)this->player->id, 6, newPlayer, 0, 0);
                }
                for (int playerIndex = 1; playerIndex < this->player->world->player_num; playerIndex++) {
                    if (playerIndex != this->player->id && playerIndex != newPlayer) {
                        RGE_Player* player = this->player->world->players[playerIndex];
                        if (player->isEnemy(newPlayer) == 1) {
                            this->player->sendAICommand((int)this->player->id, 6, playerIndex, 2, 0);
                            if (player->computerPlayer() == 1) {
                                player->sendAICommand((int)this->player->id, 6,
                                    (int)this->player->id, 2, 0);
                            }
                        } else if (player->isAlly(newPlayer) == 1) {
                            this->player->sendAICommand((int)this->player->id, 6, playerIndex, 0, 0);
                        }
                    }
                }
            }
        }
    }

    if (this->player->world->game_state == 0 &&
        this->player->world->currentUpdateComputerPlayer == this->player->id) {
        this->tacticalAI.update(0);
        this->lastTacticalUpdateTime = this->player->world->world_time;
    }

    return 1;
}
