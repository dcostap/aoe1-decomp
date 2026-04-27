// VA: 004B4120 | TribeSelectScenarioScreen::init_vars() | Scr_sels.cpp:140-161 | 103 bytes
//
// Attempt log:
// [1] First attempt.

#include "../../include/game_types.h"

class TScreenPanel {
public:
    char _gap_00[0x478];
};

class TribeSelectScenarioScreen : public TScreenPanel {
public:
    TTextPanel* title;              // +0x478
    TTextPanel* scenarioTitle;      // +0x47C
    TTextPanel* scenarioPlayersTitle; // +0x480
    char _gap_484[0x10];            // +0x484-0x493: scenarioListX/Y/Width/Height
    TListPanel* scenarioList;       // +0x494
    TScrollBarPanel* scenarioScrollbar; // +0x498
    int scenarioCount;              // +0x49C
    char** scenarioMission;         // +0x4A0
    int* scenarioFixed;            // +0x4A4
    int scenariosLoaded;            // +0x4A8
    TTextPanel* missionTitle;       // +0x4AC
    char _gap_4B0[0x10];            // +0x4B0-0x4BF: missionTextX/Y/Width/Height
    TTextPanel* missionText;        // +0x4C0
    TScrollBarPanel* missionScrollbar; // +0x4C4
    TButtonPanel* okButton;         // +0x4C8
    TButtonPanel* cancelButton;     // +0x4CC
    TButtonPanel* close_button;     // +0x4D0
    int last_scenario_line;         // +0x4D4

    void init_vars();
};

void TribeSelectScenarioScreen::init_vars() {
    last_scenario_line = -1;
    title = 0;
    scenarioTitle = 0;
    scenarioPlayersTitle = 0;
    scenarioList = 0;
    scenarioScrollbar = 0;
    scenarioCount = 0;
    scenarioMission = 0;
    scenarioFixed = 0;
    scenariosLoaded = 0;
    missionTitle = 0;
    missionText = 0;
    missionScrollbar = 0;
    okButton = 0;
    cancelButton = 0;
    close_button = 0;
}
