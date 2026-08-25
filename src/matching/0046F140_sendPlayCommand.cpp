// VA: 0046F140 RGE_Player::sendPlayCommand(int,int*,int,int,int)
// Exact MATCH. The grouped branch uses the canonical player context.

#ifndef PLAYER_GROUPED_TU
class AIPlay;
class AIPlayBook {
public:
    AIPlay* play(int id);
};
class RGE_Game_World {
public:
    char gap_00[0xA0];
    AIPlayBook* playbook;
};
class RGE_Player {
public:
    RGE_Game_World* world;
    short id;
    void command_destroy_group(int);
    void command_create_group(int, int*, int, float);
    void sendUnitAIOrder(int, int, int, int, int, float, float, float, float,
                         int, int, int);
    void sendPlayCommand(int, int*, int, int, int);
};
#endif

void RGE_Player::sendPlayCommand(int param_1, int* param_2, int param_3,
                                 int param_4, int param_5)
{
    this->command_destroy_group(param_1);
    AIPlay* play = this->world->playbook->play(param_5);
    if (play == 0) {
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d7, -1, -1,
                              -1.0f, -1.0f, -1.0f, -1.0f, 1, 0, 100);
        return;
    }
    if (param_3 != 0) {
        this->command_create_group(param_1, param_2, param_3, 2.0f);
        this->sendUnitAIOrder((int)this->id, param_1, 0x2d6, param_4,
                              param_5, -1.0f, -1.0f, -1.0f, -1.0f, 1, 0,
                              100);
    }
}
