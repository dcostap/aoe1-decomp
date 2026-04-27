// multiplayerGame (00422400, 9 bytes, basegame.cpp)
#include "game_globals.h"
#include "game_types.h"

struct RGE_Game_Options {
    float versionValue;
    unsigned char scenarioGameValue;
    char scenarioNameValue[128];
    unsigned char singlePlayerGameValue;
    unsigned char multiplayerGameValue;
};

class RGE_Base_Game {
public:
    void* vtable;
    unsigned char _pad[0x8F8];
    RGE_Game_Options rge_game_options;
};

int RGE_Base_Game::multiplayerGame() {
    return rge_game_options.multiplayerGameValue;
}
