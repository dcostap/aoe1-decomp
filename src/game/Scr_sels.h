#pragma once
#include "../common.h"

class TribeSelectScenarioScreen : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TTextPanel* scenarioTitle;               // 0x47C
    TTextPanel* scenarioPlayersTitle;        // 0x480
    long scenarioListX;                      // 0x484
    long scenarioListY;                      // 0x488
    long scenarioListWidth;                  // 0x48C
    long scenarioListHeight;                 // 0x490
    TListPanel* scenarioList;                // 0x494
    TScrollBarPanel* scenarioScrollbar;      // 0x498
    int scenarioCount;                       // 0x49C
    char** scenarioMission;                  // 0x4A0
    int* scenarioFixed;                      // 0x4A4
    int scenariosLoaded;                     // 0x4A8
    TTextPanel* missionTitle;                // 0x4AC
    long missionTextX;                       // 0x4B0
    long missionTextY;                       // 0x4B4
    long missionTextWidth;                   // 0x4B8
    long missionTextHeight;                  // 0x4BC
    TTextPanel* missionText;                 // 0x4C0
    TScrollBarPanel* missionScrollbar;       // 0x4C4
    TButtonPanel* okButton;                  // 0x4C8
    TButtonPanel* cancelButton;              // 0x4CC
    TButtonPanel* close_button;              // 0x4D0
    int last_scenario_line;                  // 0x4D4

    TribeSelectScenarioScreen();
    virtual void init_vars();
    virtual ~TribeSelectScenarioScreen();
    virtual long handle_idle();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void fillScenarios();
    virtual void fillMissionText();
    virtual void getSettings();
    virtual void sendSettings();
    virtual void activatePanels();
};

static_assert(sizeof(TribeSelectScenarioScreen) == 0x4D8, "TribeSelectScenarioScreen Size Mismatch");
static_assert(offsetof(TribeSelectScenarioScreen, last_scenario_line) == 0x4D4, "TribeSelectScenarioScreen Offset Mismatch");

