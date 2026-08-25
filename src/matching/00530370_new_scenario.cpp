// 00530370 TRIBE_World::new_scenario
// PDB source: tworld.cpp

#ifndef TWORLD_PHASE2_CONTEXT
struct RGE_Player_Info;

class RGE_Player {
public:
    char gap_00[0x50];
    float* fields_50;
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_count;
    char gap_3E[2];
    RGE_Player** players;

    unsigned char new_scenario(RGE_Player_Info& info, int flags);
};

class TRIBE_World : public RGE_Game_World {
public:
    unsigned char new_scenario(RGE_Player_Info& info, int flags);
};
#endif

unsigned char TRIBE_World::new_scenario(RGE_Player_Info& info, int flags) {
    unsigned char result = RGE_Game_World::new_scenario(info, flags);
    int i = 1;
    if (this->player_count > 1) {
        do {
            ++i;
            this->players[i - 1]->fields_50[0] = 200.0f;
            this->players[i - 1]->fields_50[1] = 200.0f;
            this->players[i - 1]->fields_50[3] = 0;
            this->players[i - 1]->fields_50[2] = 100.0f;
        } while (i < this->player_count);
    }
    return result;
}
