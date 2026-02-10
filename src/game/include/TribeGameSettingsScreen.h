#pragma once
#include "common.h"
#include "TScreenPanel.h"

class TribeMPSetupScreen;

class TribeGameSettingsScreen : public TScreenPanel {
public:
    // State enum for random map vs scenario mode
    enum State {
        StateRandom = 0,
        StateScenario = 1
    };

    // Constructor / destructor
    TribeGameSettingsScreen();

    // Non-virtual methods (from decomp)
    void init_vars();
    void getSettings();
    void sendSettings();
    void fillScenarios();
    void fillMissionText();
    void activatePanels();
    void activateVictoryPanels();

    // Virtuals actually overridden by TribeGameSettingsScreen (from decomp)
    virtual ~TribeGameSettingsScreen(); // vt[0]
    virtual long handle_idle(); // vt[19]
    virtual long handle_user_command(uint param_1, long param_2); // vt[25]
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt[45]

    TTextPanel* title;
    TribeGameSettingsScreen::State state;
    TTextPanel* mapSizeLabel;
    TDropDownPanel* mapSizeDrop;
    TTextPanel* mapTypeLabel;
    TDropDownPanel* mapTypeDrop;
    TTextPanel* victoryTypeLabel;
    TDropDownPanel* victoryTypeDrop;
    TTextPanel* victoryFixedText;
    TTextPanel* percentLabel;
    TTextPanel* scoreLabel;
    TDropDownPanel* scoreDrop;
    TTextPanel* timeLabel;
    TDropDownPanel* timeDrop;
    TTextPanel* difficultyLabel;
    TDropDownPanel* difficultyDrop;
    TTextPanel* ageLabel;
    TDropDownPanel* ageDrop;
    TTextPanel* resourcesLabel;
    TDropDownPanel* resourcesDrop;
    TTextPanel* pathingLabel;
    TDropDownPanel* pathingDrop;
    TTextPanel* limitLabel;
    TDropDownPanel* limitDrop;
    TTextPanel* scenarioTitle;
    TTextPanel* scenarioPlayersTitle;
    long scenarioListX;
    long scenarioListY;
    long scenarioListWidth;
    long scenarioListHeight;
    TListPanel* scenarioList;
    TScrollBarPanel* scenarioScrollbar;
    int scenarioCount;
    char** scenarioMission;
    int* scenarioFixed;
    int scenariosLoaded;
    TTextPanel* missionTitle;
    long missionTextX;
    long missionTextY;
    long missionTextWidth;
    long missionTextHeight;
    TTextPanel* missionText;
    TScrollBarPanel* missionScrollbar;
    TButtonPanel* optionButton[4];
    TTextPanel* optionText[4];
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    TribeMPSetupScreen* chat_scr;
    int last_scenario_line;
    int scenario_line_offset;
    unsigned long last_send_shared;
};
static_assert(sizeof(TribeGameSettingsScreen) == 0x560, "Size mismatch");
