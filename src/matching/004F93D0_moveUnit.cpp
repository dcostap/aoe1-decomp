// mirrored the matched stopUnit/groupGatherUnit sibling surface: direct virtual call through md->unit with owner-id at +0x4A

#ifndef TAITACMD_SHARED_CONTEXT
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    char gap_04[0x46];
    short id;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;

    int moveUnit(int param_1, float param_2, float param_3, int param_4);
};

#endif
int TribeTacticalAIModule::moveUnit(int param_1, float param_2, float param_3, int param_4) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, param_1, 0x2C6, -1, -1,
                            param_2, param_3, 1.0f, 1.0f, 1, 0, param_4);
    return 1;
}
