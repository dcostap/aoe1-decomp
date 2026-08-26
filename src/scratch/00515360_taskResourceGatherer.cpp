#include <stdlib.h>

// STATUS: scratch. Standalone bytes match; the canonical full tplayer wrapper does not.

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Command {
public:
    virtual ~RGE_Command();
    void command_work(int param_1, int* param_2, int param_3, int param_4, int param_5, float param_6, float param_7);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void*);
    char gap_04[0x54];
    RGE_Command* commands;
};

class RGE_Player {
public:
    virtual void update();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0xA];
    short id;
};

class TRIBE_Player : public RGE_Player {
public:
    virtual void taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5);
};
#endif

void TRIBE_Player::taskResourceGatherer(int param_1, int param_2, int param_3, float param_4, float param_5) {
    int* piVar1 = (int*)calloc(1, 4);
    *piVar1 = param_1;
    this->world->commands->command_work((int)this->id, piVar1, 1, param_2, param_3, param_4, param_5);
    free(piVar1);
}
