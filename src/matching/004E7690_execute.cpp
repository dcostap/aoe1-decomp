// VA: 004E7690 VictoryConditionRuleSystem::execute
// Attempt log:
// - baseline reconstruction from the binary switch, named VictoryConditionRuleSystem
//   strategic-number storage, and the player -> main-decision -> tactical-AI ownership chain.

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class MainDecisionAIModule : public AIModule {
public:
    void* player;
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
    void setStrategicNumber(int index, int value);
};

class TradeAIModule {
public:
    virtual ~TradeAIModule();
    char bytes[0xF0];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;                 // +0x104
    TribeConstructionAIModule constructionAI;   // +0x6C4
    DiplomacyAIModule diplomacyAI;              // +0x9DC
    EmotionalAIModule emotionalAI;              // +0xB2C
    TribeInformationAIModule informationAI;    // +0xCEC
    TribeResourceAIModule resourceAI;           // +0x10D7C
    TribeStrategyAIModule strategyAI;           // +0x10E74
    TribeTacticalAIModule tacticalAI;           // +0x1146C
    TradeAIModule tradeAI;                      // +0x12478
    void* aiPlayer;                             // +0x1256C
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
    virtual ~TribeMainDecisionAIModule();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_004[0x234];
    TribeMainDecisionAIModule* playerAI;        // +0x238
    virtual ~TRIBE_Player();
};

class VictoryConditionRuleSystem {
public:
    virtual ~VictoryConditionRuleSystem();
    int sn[0xE2];
    int execute(TRIBE_Player* player, int state, int command);
};

int VictoryConditionRuleSystem::execute(TRIBE_Player* player, int state, int command)
{
    if (state < 0 || state >= 0xD) {
        return 0;
    }

    switch (command) {
    case 1:
        player->playerAI->tacticalAI.setStrategicNumber(0, this->sn[0]);
        player->playerAI->tacticalAI.setStrategicNumber(1, this->sn[1]);
        player->playerAI->tacticalAI.setStrategicNumber(2, this->sn[2]);
        player->playerAI->tacticalAI.setStrategicNumber(3, this->sn[3]);
        player->playerAI->tacticalAI.setStrategicNumber(4, this->sn[4]);
        player->playerAI->tacticalAI.setStrategicNumber(5, this->sn[5]);
        player->playerAI->tacticalAI.setStrategicNumber(0x23, this->sn[0x23]);
        player->playerAI->tacticalAI.setStrategicNumber(100, this->sn[100]);
        player->playerAI->tacticalAI.setStrategicNumber(0xe1, this->sn[0xe1]);
        player->playerAI->tacticalAI.setStrategicNumber(0x75, this->sn[0x75]);
        player->playerAI->tacticalAI.setStrategicNumber(0x76, this->sn[0x76]);
        player->playerAI->tacticalAI.setStrategicNumber(0x77, this->sn[0x77]);
        player->playerAI->tacticalAI.setStrategicNumber(0x78, this->sn[0x78]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9c, this->sn[0x9c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9f, this->sn[0x9f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9e, this->sn[0x9e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9d, this->sn[0x9d]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa0, this->sn[0xa0]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8e, this->sn[0x8e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x94, this->sn[0x94]);
        player->playerAI->tacticalAI.setStrategicNumber(0x95, this->sn[0x95]);
        player->playerAI->tacticalAI.setStrategicNumber(0xcb, this->sn[0xcb]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa3, this->sn[0xa3]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa4, this->sn[0xa4]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa6, this->sn[0xa6]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa5, this->sn[0xa5]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa7, this->sn[0xa7]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb3, this->sn[0xb3]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb4, this->sn[0xb4]);
        player->playerAI->tacticalAI.setStrategicNumber(0xcd, this->sn[0xcd]);
        player->playerAI->tacticalAI.setStrategicNumber(0xcf, this->sn[0xcf]);
        player->playerAI->tacticalAI.setStrategicNumber(0xce, this->sn[0xce]);
        player->playerAI->tacticalAI.setStrategicNumber(0xdc, this->sn[0xdc]);
        player->playerAI->tacticalAI.setStrategicNumber(0xde, this->sn[0xde]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd0, this->sn[0xd0]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd1, this->sn[0xd1]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd2, this->sn[0xd2]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd3, this->sn[0xd3]);
        player->playerAI->tacticalAI.setStrategicNumber(0xdf, this->sn[0xdf]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd4, this->sn[0xd4]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd5, this->sn[0xd5]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd6, this->sn[0xd6]);
        player->playerAI->tacticalAI.setStrategicNumber(0xe0, this->sn[0xe0]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa9, this->sn[0xa9]);
        player->playerAI->tacticalAI.setStrategicNumber(0xaa, this->sn[0xaa]);
        player->playerAI->tacticalAI.setStrategicNumber(0xab, this->sn[0xab]);
        player->playerAI->tacticalAI.setStrategicNumber(0xac, this->sn[0xac]);
        player->playerAI->tacticalAI.setStrategicNumber(0xad, this->sn[0xad]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbe, this->sn[0xbe]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbf, this->sn[0xbf]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc0, this->sn[0xc0]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc1, this->sn[0xc1]);
        player->playerAI->tacticalAI.setStrategicNumber(0xae, this->sn[0xae]);
        player->playerAI->tacticalAI.setStrategicNumber(0xcc, this->sn[0xcc]);
        break;
    case 2:
        player->playerAI->tacticalAI.setStrategicNumber(0x10, this->sn[0x10]);
        player->playerAI->tacticalAI.setStrategicNumber(0x1a, this->sn[0x1a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x24, this->sn[0x24]);
        player->playerAI->tacticalAI.setStrategicNumber(0x25, this->sn[0x25]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5d, this->sn[0x5d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5e, this->sn[0x5e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x62, this->sn[0x62]);
        player->playerAI->tacticalAI.setStrategicNumber(0x79, this->sn[0x79]);
        player->playerAI->tacticalAI.setStrategicNumber(0x83, this->sn[0x83]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8f, this->sn[0x8f]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa2, this->sn[0xa2]);
        break;
    case 0xc:
        player->playerAI->tacticalAI.setStrategicNumber(0x12, this->sn[0x12]);
        break;
    case 0xd:
        player->playerAI->tacticalAI.setStrategicNumber(0x13, this->sn[0x13]);
        break;
    case 0xe:
        player->playerAI->tacticalAI.setStrategicNumber(0x14, this->sn[0x14]);
        break;
    case 0x10:
        player->playerAI->tacticalAI.setStrategicNumber(0x16, this->sn[0x16]);
        player->playerAI->tacticalAI.setStrategicNumber(0x48, this->sn[0x48]);
        player->playerAI->tacticalAI.setStrategicNumber(0x39, this->sn[0x39]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5c, this->sn[0x5c]);
        break;
    case 0x11:
        player->playerAI->tacticalAI.setStrategicNumber(0x17, this->sn[0x17]);
        break;
    case 0x12:
        player->playerAI->tacticalAI.setStrategicNumber(0x18, this->sn[0x18]);
        break;
    case 0x15:
        player->playerAI->tacticalAI.setStrategicNumber(0x19, this->sn[0x19]);
        player->playerAI->tacticalAI.setStrategicNumber(0x1c, this->sn[0x1c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x26, this->sn[0x26]);
        player->playerAI->tacticalAI.setStrategicNumber(0x27, this->sn[0x27]);
        break;
    case 0x16:
        player->playerAI->tacticalAI.setStrategicNumber(0x1d, this->sn[0x1d]);
        break;
    case 0x17:
        player->playerAI->tacticalAI.setStrategicNumber(0x20, this->sn[0x20]);
        player->playerAI->tacticalAI.setStrategicNumber(0x91, this->sn[0x91]);
        break;
    case 0x18:
        player->playerAI->tacticalAI.setStrategicNumber(0x22, this->sn[0x22]);
        break;
    case 0x19:
        player->playerAI->tacticalAI.setStrategicNumber(0x28, this->sn[0x28]);
        player->playerAI->tacticalAI.setStrategicNumber(0x4b, this->sn[0x4b]);
        break;
    case 0x1a:
        player->playerAI->tacticalAI.setStrategicNumber(0x29, this->sn[0x29]);
        break;
    case 0x1b:
        player->playerAI->tacticalAI.setStrategicNumber(0x2b, this->sn[0x2b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x2c, this->sn[0x2c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x2a, this->sn[0x2a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x2d, this->sn[0x2d]);
        break;
    case 0x1c:
        player->playerAI->tacticalAI.setStrategicNumber(0x1e, this->sn[0x1e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x1f, this->sn[0x1f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5b, this->sn[0x5b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5f, this->sn[0x5f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x60, this->sn[0x60]);
        player->playerAI->tacticalAI.setStrategicNumber(0x61, this->sn[0x61]);
        break;
    case 0x1d:
        player->playerAI->tacticalAI.setStrategicNumber(0x2e, this->sn[0x2e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x66, this->sn[0x66]);
        player->playerAI->tacticalAI.setStrategicNumber(0x2f, this->sn[0x2f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x67, this->sn[0x67]);
        player->playerAI->tacticalAI.setStrategicNumber(0x68, this->sn[0x68]);
        player->playerAI->tacticalAI.setStrategicNumber(0x86, this->sn[0x86]);
        break;
    case 0x1e:
        player->playerAI->tacticalAI.setStrategicNumber(0x30, this->sn[0x30]);
        break;
    case 0x1f:
        player->playerAI->tacticalAI.setStrategicNumber(0x31, this->sn[0x31]);
        player->playerAI->tacticalAI.setStrategicNumber(0x87, this->sn[0x87]);
        player->playerAI->tacticalAI.setStrategicNumber(0x88, this->sn[0x88]);
        player->playerAI->tacticalAI.setStrategicNumber(200, this->sn[200]);
        break;
    case 0x20:
        player->playerAI->tacticalAI.setStrategicNumber(0x32, this->sn[0x32]);
        player->playerAI->tacticalAI.setStrategicNumber(0x33, this->sn[0x33]);
        player->playerAI->tacticalAI.setStrategicNumber(0x34, this->sn[0x34]);
        player->playerAI->tacticalAI.setStrategicNumber(0x35, this->sn[0x35]);
        player->playerAI->tacticalAI.setStrategicNumber(0x36, this->sn[0x36]);
        player->playerAI->tacticalAI.setStrategicNumber(0x37, this->sn[0x37]);
        player->playerAI->tacticalAI.setStrategicNumber(0x38, this->sn[0x38]);
        player->playerAI->tacticalAI.setStrategicNumber(0x46, this->sn[0x46]);
        break;
    case 0x21:
        player->playerAI->tacticalAI.setStrategicNumber(0x3a, this->sn[0x3a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x3b, this->sn[0x3b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x3c, this->sn[0x3c]);
        break;
    case 0x22:
        player->playerAI->tacticalAI.setStrategicNumber(0x3d, this->sn[0x3d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x3e, this->sn[0x3e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x3f, this->sn[0x3f]);
        break;
    case 0x23:
        player->playerAI->tacticalAI.setStrategicNumber(0x40, this->sn[0x40]);
        player->playerAI->tacticalAI.setStrategicNumber(0x41, this->sn[0x41]);
        player->playerAI->tacticalAI.setStrategicNumber(0x42, this->sn[0x42]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd8, this->sn[0xd8]);
        break;
    case 0x24:
        player->playerAI->tacticalAI.setStrategicNumber(0x43, this->sn[0x43]);
        player->playerAI->tacticalAI.setStrategicNumber(0x44, this->sn[0x44]);
        player->playerAI->tacticalAI.setStrategicNumber(0x45, this->sn[0x45]);
        break;
    case 0x25:
        player->playerAI->tacticalAI.setStrategicNumber(0x47, this->sn[0x47]);
        break;
    case 0x26:
        player->playerAI->tacticalAI.setStrategicNumber(0x49, this->sn[0x49]);
        player->playerAI->tacticalAI.setStrategicNumber(0x4a, this->sn[0x4a]);
        break;
    case 0x27:
        player->playerAI->tacticalAI.setStrategicNumber(0x4c, this->sn[0x4c]);
        break;
    case 0x28:
        player->playerAI->tacticalAI.setStrategicNumber(0x4d, this->sn[0x4d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x4e, this->sn[0x4e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x4f, this->sn[0x4f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x50, this->sn[0x50]);
        player->playerAI->tacticalAI.setStrategicNumber(0x51, this->sn[0x51]);
        player->playerAI->tacticalAI.setStrategicNumber(0x52, this->sn[0x52]);
        player->playerAI->tacticalAI.setStrategicNumber(0x53, this->sn[0x53]);
        player->playerAI->tacticalAI.setStrategicNumber(0x59, this->sn[0x59]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5a, this->sn[0x5a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6a, this->sn[0x6a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6b, this->sn[0x6b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6c, this->sn[0x6c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6d, this->sn[0x6d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6e, this->sn[0x6e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6f, this->sn[0x6f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7a, this->sn[0x7a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7b, this->sn[0x7b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x90, this->sn[0x90]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb8, this->sn[0xb8]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb9, this->sn[0xb9]);
        break;
    case 0x29:
        player->playerAI->tacticalAI.setStrategicNumber(0x54, this->sn[0x54]);
        player->playerAI->tacticalAI.setStrategicNumber(0x55, this->sn[0x55]);
        player->playerAI->tacticalAI.setStrategicNumber(0x89, this->sn[0x89]);
        break;
    case 0x2a:
        player->playerAI->tacticalAI.setStrategicNumber(0x56, this->sn[0x56]);
        player->playerAI->tacticalAI.setStrategicNumber(0x57, this->sn[0x57]);
        player->playerAI->tacticalAI.setStrategicNumber(0xca, this->sn[0xca]);
        player->playerAI->tacticalAI.setStrategicNumber(0x96, this->sn[0x96]);
        player->playerAI->tacticalAI.setStrategicNumber(0x97, this->sn[0x97]);
        player->playerAI->tacticalAI.setStrategicNumber(0x98, this->sn[0x98]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa1, this->sn[0xa1]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa8, this->sn[0xa8]);
        break;
    case 0x2b:
        player->playerAI->tacticalAI.setStrategicNumber(0x58, this->sn[0x58]);
        player->playerAI->tacticalAI.setStrategicNumber(0x65, this->sn[0x65]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9b, this->sn[0x9b]);
        player->playerAI->tacticalAI.setStrategicNumber(0xaf, this->sn[0xaf]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb0, this->sn[0xb0]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb1, this->sn[0xb1]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb5, this->sn[0xb5]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb6, this->sn[0xb6]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb7, this->sn[0xb7]);
        player->playerAI->tacticalAI.setStrategicNumber(0xba, this->sn[0xba]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbb, this->sn[0xbb]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc2, this->sn[0xc2]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc4, this->sn[0xc4]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc5, this->sn[0xc5]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbc, this->sn[0xbc]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc3, this->sn[0xc3]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbd, this->sn[0xbd]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc6, this->sn[0xc6]);
        player->playerAI->tacticalAI.setStrategicNumber(199, this->sn[199]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd7, this->sn[0xd7]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd9, this->sn[0xd9]);
        player->playerAI->tacticalAI.setStrategicNumber(0xda, this->sn[0xda]);
        player->playerAI->tacticalAI.setStrategicNumber(0xdb, this->sn[0xdb]);
        player->playerAI->tacticalAI.setStrategicNumber(0xdd, this->sn[0xdd]);
        break;
    case 0x2c:
        player->playerAI->tacticalAI.setStrategicNumber(99, this->sn[99]);
        break;
    case 0x2d:
        player->playerAI->tacticalAI.setStrategicNumber(0x69, this->sn[0x69]);
        break;
    case 0x2e:
        player->playerAI->tacticalAI.setStrategicNumber(0x70, this->sn[0x70]);
        break;
    case 0x2f:
        player->playerAI->tacticalAI.setStrategicNumber(0x71, this->sn[0x71]);
        player->playerAI->tacticalAI.setStrategicNumber(0x72, this->sn[0x72]);
        player->playerAI->tacticalAI.setStrategicNumber(0x73, this->sn[0x73]);
        player->playerAI->tacticalAI.setStrategicNumber(0x74, this->sn[0x74]);
        player->playerAI->tacticalAI.setStrategicNumber(0x92, this->sn[0x92]);
        player->playerAI->tacticalAI.setStrategicNumber(0x93, this->sn[0x93]);
        break;
    case 0x30:
        player->playerAI->tacticalAI.setStrategicNumber(0x7c, this->sn[0x7c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7d, this->sn[0x7d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7e, this->sn[0x7e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7f, this->sn[0x7f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x80, this->sn[0x80]);
        player->playerAI->tacticalAI.setStrategicNumber(0x81, this->sn[0x81]);
        player->playerAI->tacticalAI.setStrategicNumber(0x82, this->sn[0x82]);
        player->playerAI->tacticalAI.setStrategicNumber(0x84, this->sn[0x84]);
        player->playerAI->tacticalAI.setStrategicNumber(0x85, this->sn[0x85]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb2, this->sn[0xb2]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc9, this->sn[0xc9]);
        break;
    case 0x31:
        player->playerAI->tacticalAI.setStrategicNumber(0x8a, this->sn[0x8a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8b, this->sn[0x8b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8c, this->sn[0x8c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8d, this->sn[0x8d]);
        break;
    default:
        return 0;
    }

    return 1;
}
