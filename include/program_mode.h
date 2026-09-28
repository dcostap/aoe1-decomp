#ifndef AOE1_PROGRAM_MODE_H
#define AOE1_PROGRAM_MODE_H

// Keep these values fixed. RGE_Base_Game stores program mode as an int.
enum RGE_Program_Mode {
    ProgModeNone = 0,
    ProgModeVideo = 1,
    ProgModeMenu = 2,
    ProgModeMultiplayerWait = 3,
    ProgModeGame = 4,
    ProgModeGameOver = 5,
    ProgModeGameTempPaused = 6,
    ProgModeScenarioEditor = 7
};

#endif
