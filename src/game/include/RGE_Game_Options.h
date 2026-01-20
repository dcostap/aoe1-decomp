#pragma once
#include "common.h"

struct RGE_Game_Options {
    float versionValue;
    uchar scenarioGameValue;
    char scenarioNameValue[128];
    uchar singlePlayerGameValue;
    uchar multiplayerGameValue;
    uchar mapXSizeValue;
    uchar mapYSizeValue;
    uchar mapZSizeValue;
    uchar allowCheatCodesValue;
    uchar mpPathFindingValue;
    uchar cheatNotificationValue;
    uchar fullVisibilityValue;
    uchar fogOfWarValue;
    uchar coloredChatValue;
    uchar numberPlayersValue;
    uchar gameDeveloperModeValue;
    uchar playerCDAndVersionValue[9];
    uchar difficultyValue;
    uchar playerTeamValue[9];
};
static_assert(sizeof(RGE_Game_Options) == 0xA8, "Size mismatch");
