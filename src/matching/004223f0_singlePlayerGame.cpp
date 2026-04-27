// singlePlayerGame (004223F0, 9 bytes, basegame.cpp)
#include "game_globals.h"
#include "game_types.h"

struct RGE_Game_Options {
    float versionValue;                // +0x0
    unsigned char scenarioGameValue;   // +0x4
    char scenarioNameValue[128];       // +0x5
    unsigned char singlePlayerGameValue;  // +0x85
};

class RGE_Base_Game {
public:
    void* vtable;
    unsigned char _pad[0x8F8];
    RGE_Game_Options rge_game_options;
};

int RGE_Base_Game::singlePlayerGame() {
    return rge_game_options.singlePlayerGameValue;
}
