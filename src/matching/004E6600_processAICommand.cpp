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

#ifndef AOE1_TAIMDMD_CONTEXT_H
class RGE_Static_Object;
class RGE_Object_List;
class RGE_Game_World;
class TRIBE_Command;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float,
                                 float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                                float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                   unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual void command_formation(int);
    virtual void command_stand_ground();
    virtual void command_create_group();
    virtual void command_add_to_group();
    virtual void command_remove_from_group();
    virtual void command_destroy_group();
    virtual void command_resign();
    virtual void command_add_waypoint();
    virtual void addObject(RGE_Static_Object*);
    virtual void removeObject(int);
    virtual void logMessage();
    virtual void notify();
    virtual void logStatus();
    virtual void load_victory();
    virtual void new_victory();
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
#endif

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
