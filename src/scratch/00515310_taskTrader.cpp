#include <stdlib.h>

// STATUS: scratch. Standalone bytes match; the canonical full tplayer wrapper does not.

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Command {
public:
    void* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    void* com_hand;

    void command_work(int id, int* task, int one, int param_2, int param_3, float param_4, float param_5);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* commands;
};

class RGE_Player {
public:
    virtual void update();
    char gap_00[0x38];
    RGE_Game_World* world;
    char gap_40[0xA];
    short id;
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_4C[0x7C];

    virtual void taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5);
};
#endif

void TRIBE_Player::taskTrader(int param_1, int param_2, int param_3, float param_4, float param_5) {
    int* task = (int*)calloc(1, 4);
    *task = param_1;
    this->world->commands->command_work(this->id, task, 1, param_2, param_3, param_4, param_5);
    free(task);
}
