// VA: 00542480 | RGE_Game_World::setup_gaia() | World.cpp:1156-1159 | 104 bytes
// /GX per-function rsp at config/flags/00542480_setup_gaia.rsp.

#include "../../include/game_types.h"

class RGE_Player {
public:
    char _gap_00[0x220];
    RGE_Player(RGE_Game_World* world, void* masterPlayerInfo, int isGaia,
               const char* name, int flag, int isActive);
};

class RGE_Game_World {
public:
    char _gap_00[0x40];
    void** players;               // +0x40
    char _gap_44[0x04];
    void** master_players;        // +0x48

    void setup_gaia();
};

void RGE_Game_World::setup_gaia() {
    RGE_Player* p = new RGE_Player(this, *master_players, 0, "GAIA", 0, 1);
    if (p == 0) {
        p = 0;
    }
    *players = p;
}
