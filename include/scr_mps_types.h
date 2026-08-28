#ifndef AOE1_SCR_MPS_TYPES_H
#define AOE1_SCR_MPS_TYPES_H

// Shared screen declarations used by tribegam.cpp.
// Provider layouts come from the scr_mps.cpp PDB type records.
#include "Pnl_scr.h"

class TTextPanel;
class TButtonPanel;
class TDropDownPanel;
class TEditPanel;
class TScrollBarPanel;
class TListPanel;
class RGE_Scenario;
class T_Scenario;

class TribeMPSetupScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* playerTitle;
    TTextPanel* civTitle;
    TTextPanel* settingsTitle;
    TTextPanel* colorTitle;
    TTextPanel* teamTitle;
    TTextPanel* playerNameText[8];
    TTextPanel* playerCivText[8];
    TTextPanel* scenarioPlayerText[8];
    TTextPanel* playerCDText[8];
    TTextPanel* playerVersionText[8];
    TTextPanel* playerColorText[8];
    TTextPanel* playerTeamText[8];
    TButtonPanel* playerColor[8];
    TButtonPanel* playerTeam[8];
    TDropDownPanel* playerNameDrop[8];
    TDropDownPanel* playerCivDrop[8];
    TDropDownPanel* scenarioPlayerDrop[8];
    TEditPanel* chatInput;
    TTextPanel* chatTitle;
    TTextPanel* chatBox;
    TScrollBarPanel* chatScrollbar;
    TButtonPanel* gameSettingsButton;
    TTextPanel* scenarioName;
    TTextPanel* victoryFixedText;
    TTextPanel* settingText[20];
    TTextPanel* settingValue[20];
    TTextPanel* mapSizeLabel;
    TDropDownPanel* mapSizeDrop;
    TTextPanel* mapTypeLabel;
    TDropDownPanel* mapTypeDrop;
    TTextPanel* numberPlayersTitle;
    TDropDownPanel* numberPlayersDrop;
    TTextPanel* numberPlayersText;
    TButtonPanel* hiddenMapButton;
    TTextPanel* hiddenMapText;
    TTextPanel* victoryTypeLabel;
    TDropDownPanel* victoryTypeDrop;
    TTextPanel* victoryAmountLabel;
    TEditPanel* victoryAmountInput;
    TButtonPanel* startButton;
    TButtonPanel* readyButtons[2];
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    TButtonPanel* ready_button;
    TButtonPanel* close_button;
    TTextPanel* ready_button_label;
    int cancelMode;
    int playerToKick;
    int scenarioPlayerCount;
    int myCivilization;
    int myScenarioPlayer;
    int myPlayerColor;
    int myPlayerTeam;
    long myScenarioChecksum;
    char saveScenarioName[256];
    int saveRandomGame;
    long saveScenarioChecksum;
    T_Scenario* scenarioInfo;
    int settingsFixed;
    int numberAnyPlayers;
    int sent_cd_status;
    TButtonPanel* netInfoButton;
    int i_am_ready;
    unsigned char defaultColor[8];
    int scenarioCheckSum[8];
    unsigned long last_send_shared;
    int resend_game_options;
    virtual ~TribeMPSetupScreen();
    TribeMPSetupScreen();
};

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;
    int listFilled;
    TTextPanel* title;
    TTextPanel* listTitle;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* joinButton;
    TButtonPanel* createButton;
    TButtonPanel* cancelButton;
    TButtonPanel* refreshButton;
    TButtonPanel* close_button;
    int game_count;
    int waitingToStart;
    unsigned long joinTime;
    TribeJoinScreen();
};

typedef char tribe_mp_setup_screen_size_check[
    (sizeof(TribeMPSetupScreen) == 0x890) ? 1 : -1];

typedef char tribe_join_screen_size_check[
    (sizeof(TribeJoinScreen) == 0x4B0) ? 1 : -1];

class TRIBE_Screen_Wait : public TScreenPanel {
public:
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;
    TTextPanel* scenarioName;
    TTextPanel* settingText[20];

    virtual ~TRIBE_Screen_Wait();
    TRIBE_Screen_Wait();
    void set_text(char* text);
    void set_text(long string_id);
};

typedef char tribe_screen_wait_size_check[
    (sizeof(TRIBE_Screen_Wait) == 0x4D8) ? 1 : -1];

#endif
