#pragma once
#include "common.h"

enum State : unsigned int {
    StateScenario = 0,
    StateRandom = 1,
};

class TribeGameSettingsScreen : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    State state;                             // 0x47C
    TTextPanel* mapSizeLabel;                // 0x480
    TDropDownPanel* mapSizeDrop;             // 0x484
    TTextPanel* mapTypeLabel;                // 0x488
    TDropDownPanel* mapTypeDrop;             // 0x48C
    TTextPanel* victoryTypeLabel;            // 0x490
    TDropDownPanel* victoryTypeDrop;         // 0x494
    TTextPanel* victoryFixedText;            // 0x498
    TTextPanel* percentLabel;                // 0x49C
    TTextPanel* scoreLabel;                  // 0x4A0
    TDropDownPanel* scoreDrop;               // 0x4A4
    TTextPanel* timeLabel;                   // 0x4A8
    TDropDownPanel* timeDrop;                // 0x4AC
    TTextPanel* difficultyLabel;             // 0x4B0
    TDropDownPanel* difficultyDrop;          // 0x4B4
    TTextPanel* ageLabel;                    // 0x4B8
    TDropDownPanel* ageDrop;                 // 0x4BC
    TTextPanel* resourcesLabel;              // 0x4C0
    TDropDownPanel* resourcesDrop;           // 0x4C4
    TTextPanel* pathingLabel;                // 0x4C8
    TDropDownPanel* pathingDrop;             // 0x4CC
    TTextPanel* limitLabel;                  // 0x4D0
    TDropDownPanel* limitDrop;               // 0x4D4
    TTextPanel* scenarioTitle;               // 0x4D8
    TTextPanel* scenarioPlayersTitle;        // 0x4DC
    long scenarioListX;                      // 0x4E0
    long scenarioListY;                      // 0x4E4
    long scenarioListWidth;                  // 0x4E8
    long scenarioListHeight;                 // 0x4EC
    TListPanel* scenarioList;                // 0x4F0
    TScrollBarPanel* scenarioScrollbar;      // 0x4F4
    int scenarioCount;                       // 0x4F8
    char** scenarioMission;                  // 0x4FC
    int* scenarioFixed;                      // 0x500
    int scenariosLoaded;                     // 0x504
    TTextPanel* missionTitle;                // 0x508
    long missionTextX;                       // 0x50C
    long missionTextY;                       // 0x510
    long missionTextWidth;                   // 0x514
    long missionTextHeight;                  // 0x518
    TTextPanel* missionText;                 // 0x51C
    TScrollBarPanel* missionScrollbar;       // 0x520
    TButtonPanel* optionButton[4];           // 0x524
    TTextPanel* optionText[4];               // 0x534
    TButtonPanel* okButton;                  // 0x544
    TButtonPanel* cancelButton;              // 0x548
    TButtonPanel* help_button;               // 0x54C
    TribeMPSetupScreen* chat_scr;            // 0x550
    int last_scenario_line;                  // 0x554
    int scenario_line_offset;                // 0x558
    ulong last_send_shared;                  // 0x55C

    virtual long handle_idle();                             // vt0[19]+0x4C=0x4B5BB0
    virtual long handle_user_command(uint param_1, long param_2); // vt0[25]+0x64=0x4B5C70
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x4B5CB0
    TribeGameSettingsScreen();
    void init_vars();
    ~TribeGameSettingsScreen();
    void fillScenarios();
    void fillMissionText();
    void getSettings();
    void sendSettings();
    void activatePanels();
    void activateVictoryPanels();
};

static_assert(sizeof(TribeGameSettingsScreen) == 0x560, "TribeGameSettingsScreen Size Mismatch");

