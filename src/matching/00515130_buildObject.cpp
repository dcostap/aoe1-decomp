#include <stdlib.h>

class TRIBE_Command {
public:
    void command_build(int param_1, int* param_2, int param_3, int param_4, float param_5, float param_6, int param_7);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    TRIBE_Command* commands;
};

class TRIBE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0xA];
    short id;

    void buildObject(int param_1, int param_2, float param_3, float param_4, int param_5);
};

void TRIBE_Player::buildObject(int param_1, int param_2, float param_3, float param_4, int param_5)
{
    int* objectId = (int*)calloc(1, 4);
    *objectId = param_1;
    this->world->commands->command_build(this->id, objectId, 1, param_2, param_3, param_4, param_5);
    free(objectId);
}
