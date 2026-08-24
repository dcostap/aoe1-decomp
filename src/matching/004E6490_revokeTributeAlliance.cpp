// VA: 004E6490 revokeTributeAlliance (230B)
// taimdmd.cpp:1020-1043
//
// Baseline reconstruction: revoke the tribute target's diplomatic state,
// announce the change, and update the two tribute flags.  The duplicated
// player pointers are the period class's base `player` and derived
// `aiPlayer` members at +0xF0 and +0x1256C respectively.

#ifndef AOE1_TAIMDMD_CONTEXT_H
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int player);
    virtual int isAlly(int player);
    virtual int isNeutral(int player);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int player, int stance);

    void __cdecl sendChatMessage(int player, int mode, char* message, ...);
};

class TRIBE_Player : public RGE_Player {
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class MainDecisionAIModule : public AIModule {
public:
    TRIBE_Player* player; // +0xF0
    char gap_F4[0x10];
    virtual ~MainDecisionAIModule();
};

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    char bytes[0x5BC];
};

class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    char bytes[0x314];
};

class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char bytes[0x14C];
    void setStance(int player, int type, int value);
};

class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    char bytes[0x1BC];
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char bytes[0x1008C];
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char bytes[0xF4];
};

class TribeStrategyAIModule {
public:
    virtual ~TribeStrategyAIModule();
    char bytes[0x5F4];
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char bytes[0x1008];
    int strategicNumber(int number);
};

class TradeAIModule {
public:
    virtual ~TradeAIModule();
    char bytes[0xF0];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;                     // +0x104
    TribeConstructionAIModule constructionAI;       // +0x6C4
    DiplomacyAIModule diplomacyAI;                  // +0x9DC
    EmotionalAIModule emotionalAI;                  // +0xB2C
    TribeInformationAIModule informationAI;         // +0xCEC
    TribeResourceAIModule resourceAI;               // +0x10D7C
    TribeStrategyAIModule strategyAI;               // +0x10E74
    TribeTacticalAIModule tacticalAI;               // +0x1146C
    TradeAIModule tradeAI;                           // +0x12478
    TRIBE_Player* aiPlayer;                         // +0x1256C
    int firstUpdate;
    int veryFirstUpdate;
    int updateDelay;
    int lastDiplomacyUpdateTime;
    int lastTacticalUpdateTime;
    int lastTributeChatTime;
    int tributeChatTimeout;
    int waitingOnTribute;                            // +0x1258C
    int tributeExpirationTimeout;
    int tributeAddressed;                            // +0x12594

    void revokeTributeAlliance();
};
#endif

void TribeMainDecisionAIModule::revokeTributeAlliance()
{
    char tempString[256];
    TribeTacticalAIModule* tactical = &this->tacticalAI;

    if (this->player->isEnemy(tactical->strategicNumber(0x80)) == 0) {
        this->diplomacyAI.setStance(
            tactical->strategicNumber(0x80), 0, 0);
        this->diplomacyAI.setStance(
            tactical->strategicNumber(0x80), 2, 100);
        this->aiPlayer->setDiplomaticStance(
            tactical->strategicNumber(0x80), 3);
        rge_base_game->get_string(0x8FD, tempString, 0x100);
        this->player->sendChatMessage(
            tactical->strategicNumber(0x80), 0, tempString);
        this->waitingOnTribute = 0;
        this->tributeAddressed = 1;
    }
}
