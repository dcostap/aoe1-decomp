// 00544250 RGE_Game_World::scenario_make_player
// Source: World.cpp lines 2469-2479. 132 bytes. __thiscall, ret 14h.
// Has EH registration — needs /GX flag.
//
// MATCHED. Exact 132-byte match confirmed via local check_function.py.
// Probe 3: virtual ~RGE_Player() fixes sizeof from 0x21C to 0x220 (vptr).
// /GX needed for EH prologue/epilogue (fs:[0] save/restore with handler).

class RGE_Master_Player {
public:
    // placeholder
};

class RGE_Game_World;

class RGE_Player {
public:
    char gap_00[0x21C];     // sizeof(RGE_Player) = 0x220 (4 vptr + 0x21C gap)
    virtual ~RGE_Player();
    RGE_Player(RGE_Game_World* world, RGE_Master_Player* master, unsigned char idx,
        char* str, unsigned char p4, int flag);
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;              // +0x40
    char gap_44[4];                    // 0x44-0x47
    RGE_Master_Player** master_players; // +0x48

    void scenario_make_player(short param_1, unsigned char param_2,
        unsigned char param_3, unsigned char param_4, char* param_5);
};

void RGE_Game_World::scenario_make_player(short param_1, unsigned char param_2,
    unsigned char param_3, unsigned char param_4, char* param_5) {
    if (param_3 != 0)
        return;

    this->players[param_1] = new RGE_Player(
        this,
        this->master_players[param_4],
        (unsigned char)param_1,
        param_5,
        param_4,
        1
    );
}
