// TRIBE_Game::set_player
// VA: 00522810
// tribegam.cpp:898-913
// MATCH: 0.0000% diff, 2 relocations masked

#include "../../include/game_globals.h"

class RGE_Base_Game {
public:
    void set_player(short player);
};

struct TribePlayerInfo {
    char gap_00[0x7C];
    short playerNum;  // +0x7C
};

class TRIBE_Screen_Game {
public:
    void player_changed(int oldPlayer, int newPlayer);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_00[0x3F4];
    TribePlayerInfo* tribeInfo;    // +0x3F4
    char gap_3F8[0xC24 - 0x3F8];
    TRIBE_Screen_Game* gameScreen; // +0xC24

    void set_player(short player);
};

void TRIBE_Game::set_player(short player) {
    short oldPlayer;
    if (this->tribeInfo) {
        oldPlayer = this->tribeInfo->playerNum;
    } else {
        oldPlayer = 0;
    }

    RGE_Base_Game::set_player(player);

    if (this->tribeInfo && this->gameScreen) {
        this->gameScreen->player_changed(oldPlayer, this->tribeInfo->playerNum);
    }
}
