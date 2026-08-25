// difficulty (00422640, 9 bytes, basegame.cpp)
// simple getter returning rge_game_options.difficultyValue
#include "game_globals.h"
#include "game_types.h"

// --- local stubs ---
struct RGE_Game_Options {
    float versionValue;                // +0x0
    unsigned char scenarioGameValue;   // +0x4
    char scenarioNameValue[128];       // +0x5
    unsigned char singlePlayerGameValue;  // +0x85
    unsigned char multiplayerGameValue;   // +0x86
    unsigned char mapXSizeValue;       // +0x87
    unsigned char mapYSizeValue;       // +0x88
    unsigned char mapZSizeValue;       // +0x89
    unsigned char allowCheatCodesValue;   // +0x8A
    unsigned char mpPathFindingValue;     // +0x8B
    unsigned char cheatNotificationValue; // +0x8C
    unsigned char fullVisibilityValue;    // +0x8D
    unsigned char fogOfWarValue;          // +0x8E
    unsigned char coloredChatValue;       // +0x8F
    unsigned char numberPlayersValue;     // +0x90
    unsigned char gameDeveloperModeValue; // +0x91
    unsigned char playerCDAndVersionValue[9]; // +0x92
    unsigned char difficultyValue;        // +0x9B
    // ... rest omitted
};

class RGE_Base_Game {
public:
    void* vtable;                     // +0x0
    unsigned char _pad[0x8F8];
    RGE_Game_Options rge_game_options; // +0x8F8
};

int RGE_Base_Game::difficulty() {
    return rge_game_options.difficultyValue;
}
