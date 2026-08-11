// VA: 004E6600 processAICommand (577B)
// taimdmd.cpp:1065-1170
//
// Attempt log:
// - baseline: reconstructed the command dispatcher with typed player/world,
//   diplomacy, tactical, information, object-list, and command ownership;
//   first checker result is recorded in target-session history.
// - control-flow probe: duplicated the difficulty-4 victory arms and used a
//   positive difficulty==4 guard; this restored the oracle's late branch order
//   and all 21 ordered calls.
// - ABI probe: restored the RGE_Player base / TRIBE_Player derived vslot
//   surface, binding computerPlayer to RGE_Player; emitted bytes were stable.
// - liveness probe: kept the typed player attribute in a natural local before
//   the virtual give-attribute call; this recovered the oracle's fld/fstp
//   argument schedule and produced an exact 577-byte match.

class RGE_Static_Object;
class RGE_Object_List;
class RGE_Game_World;
class TRIBE_Command;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual unsigned char command_give_attribute(int player, int attribute,
                                                  float amount);
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    int computerPlayerValue;
    char gap_08[0x20];
    RGE_Object_List* objects;
    char gap_2C[0x10];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[4];
    float* attributes;

    int computerPlayer();
};

class TRIBE_Player : public RGE_Player {
public:
    virtual unsigned char command_give_attribute(int player, int attribute,
                                                  float amount, float delta);
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
    char gap_44[0x14];
    TRIBE_Command* commands;
};

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_id(long master_id, float x, float y,
                                         unsigned char use_state,
                                         unsigned char state,
                                         RGE_Static_Object* object);
};

class TRIBE_Command {
public:
    void command_allied_victory(short player_id, unsigned char flag);
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
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

    void setChangeable(int player, unsigned char value);
    void setStance(int player, int type, int value);
    void setRelation(int player, int relation);
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

    void lookAtMap();
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

    int processCoopAttack(int player, int target, int value, int extra);
    void setStrategicNumber(int number, int value);
};

class TradeAIModule {
public:
    virtual ~TradeAIModule();
    char bytes[0xF0];
};

class RGE_Base_Game {
public:
    int difficulty();
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

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
    TRIBE_Player* aiPlayer;
    int firstUpdate;
    int veryFirstUpdate;
    int updateDelay;
    int lastDiplomacyUpdateTime;
    int lastTacticalUpdateTime;
    int lastTributeChatTime;
    int tributeChatTimeout;
    int waitingOnTribute;
    int tributeExpirationTimeout;
    int tributeAddressed;
    int tributeAmount;
    int decidedInitialDiplomacy;
    int requiredDiplomacyTributeAmount;
    int tributeGiven[9];

    int processAICommand(int player, int command, int value, int amount,
                         int extra);
};

int TribeMainDecisionAIModule::processAICommand(int player, int command,
                                                int value, int amount,
                                                int extra)
{
    switch (command) {
    case 0:
        this->informationAI.lookAtMap();
        return 1;

    case 1:
        if (player != this->player->id &&
            this->aiPlayer->objects->find_by_master_id(
                0x54, -1.0f, -1.0f, 0, 2, 0) != 0) {
            float current = this->aiPlayer->attributes[0x2E];
            this->aiPlayer->command_give_attribute(
                player, value, (float)amount,
                current);
            return 1;
        }
        break;

    case 2:
    case 3:
        if (player != this->player->id) {
            this->tacticalAI.processCoopAttack(player, value, amount, extra);
            return 1;
        }
        break;

    case 7:
        this->requiredDiplomacyTributeAmount = value;
        this->tacticalAI.setStrategicNumber(0xD9, 1);
        return 1;

    case 6: {
        this->diplomacyAI.setChangeable(value, 1);
        switch (amount) {
        case 0:
            this->diplomacyAI.setStance(value, 0, 100);
            this->diplomacyAI.setRelation(value, 3);
            break;

        case 1:
            this->diplomacyAI.setStance(value, 0, 0x31);
            this->diplomacyAI.setStance(value, 2, 0x31);
            this->diplomacyAI.setRelation(value, 1);
            break;

        case 2:
            this->diplomacyAI.setStance(value, 2, 100);
            this->diplomacyAI.setRelation(value, 0);
            if (rge_base_game->difficulty() == 4) {
                if (this->player->world->players[value]->computerPlayer() == 0) {
                    this->player->world->commands->command_allied_victory(
                        this->player->id, 1);
                    this->diplomacyAI.setChangeable(value, 0);
                    return 1;
                } else {
                    this->player->world->commands->command_allied_victory(
                        this->player->id, 0);
                    this->diplomacyAI.setChangeable(value, 0);
                    return 1;
                }
            } else {
                this->player->world->commands->command_allied_victory(
                    this->player->id, 1);
                this->diplomacyAI.setChangeable(value, 0);
                return 1;
            }

        default:
            break;
        }
        this->diplomacyAI.setChangeable(value, 0);
        break;
    }

    default:
        return 0;
    }

    return 1;
}
