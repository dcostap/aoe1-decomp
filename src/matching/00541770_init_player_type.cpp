// RGE_Game_World::init_player_type
// VA: 00541770
// World.cpp:718-731
// 138 bytes
// FLAGS: /GX (EH frame for new expression)

#include "../../include/game_globals.h"

class RGE_Master_Player {
public:
    char gap_00[0x28];  // after vtable, sizeof = 0x2C

    RGE_Master_Player(int param_1);
    virtual void vf00(void);
    virtual void vf_init(int param_1, void* a, void* b);
};

class RGE_Game_World {
public:
    char gap_00[0x30];
    void* sprites;
    char gap_34[0x38 - 0x34];
    void* sounds;
    char gap_3C[0x48 - 0x3C];
    RGE_Master_Player** master_players;

    unsigned char init_player_type(int param_1, short param_2, unsigned char param_3);
};

unsigned char RGE_Game_World::init_player_type(int param_1, short param_2, unsigned char param_3) {
    if (param_3 == 0) {
        this->master_players[param_2] = new RGE_Master_Player(param_1);
        this->master_players[param_2]->vf_init(param_1, this->sounds, this->sprites);
    }
    return 1;
}
