// playerTeam (00422660, 16 bytes, basegame.cpp)
// returns rge_game_options.playerTeamValue[player]
#include "game_globals.h"
#include "game_types.h"

struct RGE_Game_Options {
    float versionValue;
    unsigned char scenarioGameValue;
    char scenarioNameValue[128];
    unsigned char singlePlayerGameValue;
    unsigned char multiplayerGameValue;
    unsigned char mapXSizeValue;
    unsigned char mapYSizeValue;
    unsigned char mapZSizeValue;
    unsigned char allowCheatCodesValue;
    unsigned char mpPathFindingValue;
    unsigned char cheatNotificationValue;
    unsigned char fullVisibilityValue;
    unsigned char fogOfWarValue;
    unsigned char coloredChatValue;
    unsigned char numberPlayersValue;
    unsigned char gameDeveloperModeValue;
    unsigned char playerCDAndVersionValue[9];
    unsigned char difficultyValue;
    unsigned char playerTeamValue[9];
};

class RGE_Base_Game {
public:
    void* vtable;
    unsigned char _pad[0x8F8];
    RGE_Game_Options rge_game_options;
};

int RGE_Base_Game::playerTeam(int player) {
    return rge_game_options.playerTeamValue[player];
}
