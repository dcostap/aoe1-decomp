#ifndef AOE1_SCR_MPS_H
#define AOE1_SCR_MPS_H

// This header owns only the multiplayer setup, wait, and disconnect screens.
// The canonical screen base is the only included foreign owner.
#include "Pnl_scr.h"

class TTextPanel;
class TButtonPanel;
class TDropDownPanel;
class TEditPanel;
class TScrollBarPanel;
class T_Scenario;

class TribeMPSetupScreen : public TScreenPanel {
protected:
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
    long scenarioCheckSum[8];
    unsigned long last_send_shared;
    int resend_game_options;

public:
    TribeMPSetupScreen();
    virtual ~TribeMPSetupScreen();

protected:
    void init_vars();
    int startGame();
    void calcRandomPositions();
    void showNetInfo();
    void cancelScreen(int);
    void fillChat(int);
    void kickPlayer(int);
    void handleKickedPlayer(int);
    void activateVictoryPanels();
    void setupTabOrder();
    void setupSinglePlayerPlayers();
    void fillNumberPlayers();
    void fillPlayerColors();

public:
    virtual long handle_idle();
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    void fillPlayers();
    void updateSummary();
    char* get_string(int);
    char* get_string(int, char*, int);
    void setup_popup_help();
    void OKDialog(char*, int, int, int);
    void ErrorDialog(int, int, int, int);
    void popupOKDialog(int, int, int, int);
    void popupOKDialog(char*, int, int, int);
};

typedef char scr_mps_setup_screen_size_check[
    (sizeof(TribeMPSetupScreen) == 0x890) ? 1 : -1];

class TRIBE_Screen_Wait : public TScreenPanel {
public:
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;
    TTextPanel* scenarioName;
    TTextPanel* settingText[20];

    TRIBE_Screen_Wait();
    virtual ~TRIBE_Screen_Wait();
    void set_text(char*);
    void set_text(long);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_idle();
};

typedef char scr_mps_wait_screen_size_check[
    (sizeof(TRIBE_Screen_Wait) == 0x4D8) ? 1 : -1];

class TRIBE_Screen_Disconnect : public TScreenPanel {
public:
    int mode;
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    TRIBE_Screen_Disconnect(int);
    virtual ~TRIBE_Screen_Disconnect();
    void set_text(char*);
    void set_text(long);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_idle();
};

typedef char scr_mps_disconnect_screen_size_check[
    (sizeof(TRIBE_Screen_Disconnect) == 0x488) ? 1 : -1];

#endif
