// VA: 004E6250 tributeNotify (568B)
// taimdmd.cpp:949-1015
//
// Attempt log:
// - baseline reconstruction: restored the three-argument tribute notification,
//   tactical strategic-number checks, diplomacy updates, player commands, chat,
//   and the alliance propagation loop from the executable evidence.
// - behavior probe: named the shared amount / 100 quotient and corrected the
//   RGE_Player world and id offsets; size and frame then matched the oracle.
// - liveness probe: an explicit diplomacy subobject local was codegen-neutral;
//   kept direct member calls as the natural source form.
// - ABI probe: modeled RGE_Player::isNeutral(int), restoring the sender push
//   before vslot +0x20 and reducing the mismatch to one compare byte.
// - control-flow probe: reversed the first sender/strategic-number comparison;
//   this restored the final cmp encoding and produced an exact 568-byte match.

#ifndef AOE1_TAIMDMD_CONTEXT_H
class TribeTacticalAIModule {
public:
    char gap_00[0x1008];

    int strategicNumber(int number);
    void setStrategicNumber(int number, int value);
};

class DiplomacyAIModule {
public:
    char gap_00[0x14C];

    void changeStance(int player, int type, int value);
};

class RGE_Game_World;

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
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int player);
    virtual int strategicNumber(int number);
    virtual void sendGameOrder(void*, void*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int player, int command, int value, int arg,
                              int extra);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;

    void __cdecl sendChatMessage(int player, int mode, char* message, ...);
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
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

extern RGE_Base_Game* rge_base_game;

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
    char gap_F4[0x8E8];
    DiplomacyAIModule diplomacyAI;
    char gap_B28[0x10944];
    TribeTacticalAIModule tacticalAI;
    char gap_12474[0x118];
    int waitingOnTribute;
    int tributeExpirationTimeout;
    int tributeAddressed;
    int tributeAmount;
    int decidedInitialDiplomacy;
    int requiredDiplomacyTributeAmount;
    int tributeGiven[9];

    void tributeNotify(int player, int notification, int amount);
};
#endif

void TribeMainDecisionAIModule::tributeNotify(int player, int notification,
                                               int amount)
{
    char tempString[256];

    if (this->waitingOnTribute == 1 &&
        player == this->tacticalAI.strategicNumber(0x80) &&
        notification == 3) {
        this->tributeAmount += amount;
        return;
    }

    TribeTacticalAIModule* tactical = &this->tacticalAI;
    if (player != tactical->strategicNumber(0x80)) {
        int tribute = amount / 100;
        this->diplomacyAI.changeStance(player, 2, tribute);
        this->diplomacyAI.changeStance(player, 0, -tribute);
        this->tributeGiven[player] += amount;

        if (this->player->isNeutral(player) == 1 &&
            tactical->strategicNumber(0xD9) == 1 &&
            this->tributeGiven[player] >= this->requiredDiplomacyTributeAmount) {
            this->player->sendAICommand(this->player->id, 6, player, 2, 0);
            rge_base_game->get_string(0x907, tempString, 0x100);
            this->player->sendChatMessage(player, 0, tempString);

            RGE_Player* newAlly = this->player->world->players[player];
            for (int i = 1; i < this->player->world->player_num; ++i) {
                if (i != this->player->id && i != player) {
                    if (newAlly->isAlly(i) == 1) {
                        this->player->sendAICommand(
                            this->player->id, 6, i, 2, 0);
                    }
                    else if (newAlly->isEnemy(i) == 1) {
                        this->player->sendAICommand(
                            this->player->id, 6, i, 0, 0);
                    }
                }
            }

            tactical->setStrategicNumber(0xD9, 0);
        }
        else if (this->player->isEnemy(player) == 1) {
            rge_base_game->get_string(0x906, tempString, 0x100);
            this->player->sendChatMessage(player, 0, tempString);
        }
    }
}
