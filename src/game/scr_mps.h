#pragma once
#include "../common.h"

class TribeMPSetupScreen : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TTextPanel* playerTitle;                 // 0x47C
    TTextPanel* civTitle;                    // 0x480
    TTextPanel* settingsTitle;               // 0x484
    TTextPanel* colorTitle;                  // 0x488
    TTextPanel* teamTitle;                   // 0x48C
    TTextPanel* playerNameText[8];           // 0x490
    TTextPanel* playerCivText[8];            // 0x4B0
    TTextPanel* scenarioPlayerText[8];       // 0x4D0
    TTextPanel* playerCDText[8];             // 0x4F0
    TTextPanel* playerVersionText[8];        // 0x510
    TTextPanel* playerColorText[8];          // 0x530
    TTextPanel* playerTeamText[8];           // 0x550
    TButtonPanel* playerColor[8];            // 0x570
    TButtonPanel* playerTeam[8];             // 0x590
    TDropDownPanel* playerNameDrop[8];       // 0x5B0
    TDropDownPanel* playerCivDrop[8];        // 0x5D0
    TDropDownPanel* scenarioPlayerDrop[8];   // 0x5F0
    TEditPanel* chatInput;                   // 0x610
    TTextPanel* chatTitle;                   // 0x614
    TTextPanel* chatBox;                     // 0x618
    TScrollBarPanel* chatScrollbar;          // 0x61C
    TButtonPanel* gameSettingsButton;        // 0x620
    TTextPanel* scenarioName;                // 0x624
    TTextPanel* victoryFixedText;            // 0x628
    TTextPanel* settingText[20];             // 0x62C
    TTextPanel* settingValue[20];            // 0x67C
    TTextPanel* mapSizeLabel;                // 0x6CC
    TDropDownPanel* mapSizeDrop;             // 0x6D0
    TTextPanel* mapTypeLabel;                // 0x6D4
    TDropDownPanel* mapTypeDrop;             // 0x6D8
    TTextPanel* numberPlayersTitle;          // 0x6DC
    TDropDownPanel* numberPlayersDrop;       // 0x6E0
    TTextPanel* numberPlayersText;           // 0x6E4
    TButtonPanel* hiddenMapButton;           // 0x6E8
    TTextPanel* hiddenMapText;               // 0x6EC
    TTextPanel* victoryTypeLabel;            // 0x6F0
    TDropDownPanel* victoryTypeDrop;         // 0x6F4
    TTextPanel* victoryAmountLabel;          // 0x6F8
    TEditPanel* victoryAmountInput;          // 0x6FC
    TButtonPanel* startButton;               // 0x700
    TButtonPanel* readyButtons[2];           // 0x704
    TButtonPanel* cancelButton;              // 0x70C
    TButtonPanel* help_button;               // 0x710
    TButtonPanel* ready_button;              // 0x714
    TButtonPanel* close_button;              // 0x718
    TTextPanel* ready_button_label;          // 0x71C
    int cancelMode;                          // 0x720
    int playerToKick;                        // 0x724
    int scenarioPlayerCount;                 // 0x728
    int myCivilization;                      // 0x72C
    int myScenarioPlayer;                    // 0x730
    int myPlayerColor;                       // 0x734
    int myPlayerTeam;                        // 0x738
    long myScenarioChecksum;                 // 0x73C
    char saveScenarioName[256];              // 0x740
    int saveRandomGame;                      // 0x840
    long saveScenarioChecksum;               // 0x844
    T_Scenario* scenarioInfo;                // 0x848
    int settingsFixed;                       // 0x84C
    int numberAnyPlayers;                    // 0x850
    int sent_cd_status;                      // 0x854
    TButtonPanel* netInfoButton;             // 0x858
    int i_am_ready;                          // 0x85C
    uchar defaultColor[8];                   // 0x860
    long scenarioCheckSum[8];                // 0x868
    ulong last_send_shared;                  // 0x888
    int resend_game_options;                 // 0x88C

    TribeMPSetupScreen();
    virtual void init_vars();
    virtual ~TribeMPSetupScreen();
    virtual long handle_idle();
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual int startGame();
    virtual void calcRandomPositions();
    virtual void showNetInfo();
    virtual void cancelScreen(int param_1);
    virtual long handle_user_command(uint param_1, long param_2);
    virtual long handle_timer_command(uint param_1, long param_2);
    virtual void fillPlayers();
    virtual void fillChat(int param_1);
    virtual void updateSummary();
    virtual void kickPlayer(int param_1);
    virtual void handleKickedPlayer(int param_1);
    virtual void activateVictoryPanels();
    virtual void setupTabOrder();
    virtual void setupSinglePlayerPlayers();
    virtual void fillNumberPlayers();
    virtual void fillPlayerColors();
};

static_assert(sizeof(TribeMPSetupScreen) == 0x890, "TribeMPSetupScreen Size Mismatch");
static_assert(offsetof(TribeMPSetupScreen, resend_game_options) == 0x88C, "TribeMPSetupScreen Offset Mismatch");

class TRIBE_Screen_Wait : public TScreenPanel {
public:
    TTextPanel* message;                     // 0x478
    TButtonPanel* cancel_button;             // 0x47C
    TButtonPanel* close_button;              // 0x480
    TTextPanel* scenarioName;                // 0x484
    TTextPanel* settingText[20];             // 0x488

    TRIBE_Screen_Wait();
    virtual ~TRIBE_Screen_Wait();
    virtual void set_text(char* param_1);
    virtual void set_text(long param_1);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual long handle_idle();
};

static_assert(sizeof(TRIBE_Screen_Wait) == 0x4D8, "TRIBE_Screen_Wait Size Mismatch");
static_assert(offsetof(TRIBE_Screen_Wait, settingText) == 0x488, "TRIBE_Screen_Wait Offset Mismatch");

class TRIBE_Screen_Disconnect : public TScreenPanel {
public:
    int mode;                                // 0x478
    TTextPanel* message;                     // 0x47C
    TButtonPanel* cancel_button;             // 0x480
    TButtonPanel* close_button;              // 0x484

    TRIBE_Screen_Disconnect(int param_1);
    virtual ~TRIBE_Screen_Disconnect();
    virtual void set_text(char* param_1);
    virtual void set_text(long param_1);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual long handle_idle();
};

static_assert(sizeof(TRIBE_Screen_Disconnect) == 0x488, "TRIBE_Screen_Disconnect Size Mismatch");
static_assert(offsetof(TRIBE_Screen_Disconnect, close_button) == 0x484, "TRIBE_Screen_Disconnect Offset Mismatch");

