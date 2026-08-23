#include "../../include/tscenaro_context.h"

#if 0
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char param_1);
    virtual void do_resign(int param_1);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int param_1);
    virtual int isEnemy(int param_1);
    virtual int isAlly(int param_1);
    virtual int isNeutral(int param_1);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int param_1, int param_2);
    virtual void loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5);
};

class RGE_Game_World {
public:
    char gap_0[0x40];
    RGE_Player** players;
};

class RGE_Scenario {
public:
    char gap_0[8];
    RGE_Game_World* world;
    char* Get_player_AI(int param_1, int param_2);
    char* Get_CityPlan(int param_1, int param_2);
    char* Get_BuildList(int param_1, int param_2);
};

class T_Scenario : public RGE_Scenario {
public:
    void InitializeAIInformation();
    void SetSPWhich(int v);
};
#endif

void T_Scenario::InitializeAIInformation() {
    int player;

    player = 0;
    do {
        this->world->players[player]->loadAIInformation(this->Get_BuildList(player, 1), this->Get_CityPlan(player, 1), this->Get_player_AI(player, 1), 4, -1);
        player++;
    } while (player < 16);
}
