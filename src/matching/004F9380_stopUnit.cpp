// probe 4: natural virtual-call surface with the nested md->unit object layout

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

    int stopUnit(int param_1, int param_2);
};

#endif
int TribeTacticalAIModule::stopUnit(int param_1, int param_2) {
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, param_1, 0x2C2, -1, -1,
        -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, param_2);
    return 1;
}
