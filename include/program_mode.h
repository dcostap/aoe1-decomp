#ifndef AOE1_PROGRAM_MODE_H
#define AOE1_PROGRAM_MODE_H

#include "basegame.h"

// Keep these values fixed. RGE_Base_Game stores program mode as an int.
enum RGE_Program_Mode {
    ProgModeNone = RGE_PROGRAM_MODE_NONE,
    ProgModeVideo = RGE_PROGRAM_MODE_VIDEO,
    ProgModeMenu = RGE_PROGRAM_MODE_MENU,
    ProgModeMultiplayerWait = RGE_PROGRAM_MODE_MULTIPLAYER_WAIT,
    ProgModeGame = RGE_PROGRAM_MODE_GAME,
    ProgModeGameOver = RGE_PROGRAM_MODE_GAME_OVER,
    ProgModeGameTempPaused = RGE_PROGRAM_MODE_GAME_TEMP_PAUSED,
    ProgModeScenarioEditor = RGE_PROGRAM_MODE_SCENARIO_EDITOR
};

#endif
