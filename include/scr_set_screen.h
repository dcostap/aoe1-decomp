#ifndef AOE1_SCR_SET_SCREEN_H
#define AOE1_SCR_SET_SCREEN_H

// Shared declaration for the settings screen used by scr_set.cpp and
// scr_mps.cpp. Include this file after TScreenPanel is complete.

class TScreenPanel;
class TTextPanel;
class TButtonPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TribeMPSetupScreen;

class TribeGameSettingsScreen : public TScreenPanel {
public:
    TTextPanel* title;
    int state;
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
    union {
        TButtonPanel* optionButton[4];
        struct {
            TButtonPanel* optionButton0;
            TButtonPanel* optionButton1;
            TButtonPanel* optionButton2;
            TButtonPanel* optionButton3;
        };
    };
    union {
        TTextPanel* optionText[4];
        struct {
            TTextPanel* optionText0;
            TTextPanel* optionText1;
            TTextPanel* optionText2;
            TTextPanel* optionText3;
        };
    };
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    TribeMPSetupScreen* chat_scr;
    int last_scenario_line;
    int scenario_line_offset;
    unsigned long last_send_shared;

    TribeGameSettingsScreen();
    virtual ~TribeGameSettingsScreen();
    virtual long handle_idle();
    virtual long handle_user_command(unsigned int, long);
protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void init_vars();
    void fillScenarios();
    void getSettings();
    void fillMissionText();
    void sendSettings();
    void activatePanels();
    void activateVictoryPanels();
};

typedef char scr_set_screen_size[(sizeof(TribeGameSettingsScreen) == 0x560) ? 1 : -1];

#endif
