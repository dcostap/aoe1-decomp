// VA: 00541240
// RGE_Game_World::data_load_players_type(short, short, FILE*)
// Source: World.cpp lines 524-535

// attempt 1: natural new expression -> 80 bytes (no EH), needed /GX
// attempt 2: /GX rsp -> 103 bytes, 1 diff: size push (1 vs 0x2C, class had no size)
// attempt 3: added char gap_00[0x2C] for correct sizeof -> EXACT MATCH (103/103, 0.0000%)
// FLAGS: /GX (needed for EH prolog in new-expression path)

#include <cstdio>

class RGE_Master_Player {
public:
    char gap_00[0x2C];  // sizeof = 0x2C

    // 00460FD0
    RGE_Master_Player(FILE* file);
};

class RGE_Game_World {
public:
    char gap_00[0x48];
    RGE_Master_Player** master_players;  // +0x48

    void data_load_players_type(short player_id, short flag, FILE* file);
};

void RGE_Game_World::data_load_players_type(short player_id, short flag, FILE* file) {
    if (flag == 0) {
        this->master_players[player_id] = new RGE_Master_Player(file);
    }
}
